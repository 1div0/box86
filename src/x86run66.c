#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "debug.h"
#include "stack.h"
#include "x86emu.h"
#include "x86run.h"
#include "x86emu_private.h"
#include "x86run_private.h"
#include "x86primop.h"
#include "x86trace.h"


void Run66(x86emu_t *emu)
{
    uint8_t opcode = Fetch8(emu);
    uint8_t nextop;
    reg32_t *op1, *op2, *op3, *op4;
    reg32_t ea1, ea2, ea3, ea4;
    uint8_t tmp8u;
    int8_t tmp8s;
    uint16_t tmp16u;
    int16_t tmp16s;
    uint32_t tmp32u;
    int32_t tmp32s;
    uint64_t tmp64u;
    int64_t tmp64s;
    switch(opcode) {

    #define GO(B, OP)                       \
    case B+1:                               \
        nextop = Fetch8(emu);               \
        GetEw(emu, &op1, &ea1, nextop);     \
        GetG(emu, &op2, nextop);            \
        op1->word[0] = OP##16(emu, op1->word[0], op2->word[0]); \
        break;                              \
    case B+3:                               \
        nextop = Fetch8(emu);               \
        GetEw(emu, &op2, &ea2, nextop);     \
        GetG(emu, &op1, nextop);            \
        op1->word[0] = OP##16(emu, op1->word[0], op2->word[0]); \
        break;                              \
    case B+5:                               \
        R_AX = OP##16(emu, R_AX, Fetch16(emu)); \
        break;

    GO(0x00, add)                   /* ADD 0x01 ~> 0x05 */
    GO(0x08, or)                    /*  OR 0x09 ~> 0x0D */
    GO(0x10, adc)                   /* ADC 0x11 ~> 0x15 */
    GO(0x18, sbb)                   /* SBB 0x19 ~> 0x1D */
    GO(0x20, and)                   /* AND 0x21 ~> 0x25 */
    GO(0x28, sub)                   /* SUB 0x29 ~> 0x2D */
    GO(0x30, xor)                   /* XOR 0x31 ~> 0x35 */
    GO(0x38, cmp)                   /* CMP 0x39 ~> 0x3D */
    #undef GO
    

    case 0x40:
    case 0x41:
    case 0x42:
    case 0x43:
    case 0x44:
    case 0x45:
    case 0x46:
    case 0x47:                              /* INC Reg */
        tmp8u = opcode&7;
        emu->regs[tmp8u].word[0] = inc16(emu, emu->regs[tmp8u].word[0]);
        break;
    case 0x48:
    case 0x49:
    case 0x4A:
    case 0x4B:
    case 0x4C:
    case 0x4D:
    case 0x4E:
    case 0x4F:                              /* DEC Reg */
        tmp8u = opcode&7;
        emu->regs[tmp8u].word[0] = dec16(emu, emu->regs[tmp8u].word[0]);
        break;

    case 0x81:                              /* GRP3 Ew,Iw */
    case 0x83:                              /* GRP3 Ew,Ib */
        nextop = Fetch8(emu);
        GetEd(emu, &op1, &ea1, nextop);
        if(opcode==0x81) 
            tmp16u = Fetch16(emu);
        else {
            tmp16s = Fetch8s(emu);
            tmp16u = *(uint16_t*)&tmp16s;
        }
        switch((nextop>>3)&7) {
            case 0: op1->word[0] = add16(emu, op1->word[0], tmp16u); break;
            case 1: op1->word[0] =  or16(emu, op1->word[0], tmp16u); break;
            case 2: op1->word[0] = adc16(emu, op1->word[0], tmp16u); break;
            case 3: op1->word[0] = sbb16(emu, op1->word[0], tmp16u); break;
            case 4: op1->word[0] = and16(emu, op1->word[0], tmp16u); break;
            case 5: op1->word[0] = sub16(emu, op1->word[0], tmp16u); break;
            case 6: op1->word[0] = xor16(emu, op1->word[0], tmp16u); break;
            case 7: op1->word[0] = cmp16(emu, op1->word[0], tmp16u); break;
        }
        break;

    case 0x85:                              /* TEST Ew,Gw */
        nextop = Fetch8(emu);
        GetEw(emu, &op1, &ea1, nextop);
        GetG(emu, &op2, nextop);
        test16(emu, op1->word[0], op2->word[0]);
        break;

    case 0x89:                              /* MOV Ew,Gw */
        nextop = Fetch8(emu);
        GetEw(emu, &op1, &ea2, nextop);
        GetG(emu, &op2, nextop);
        op1->word[0] = op2->word[0];
        break;

    case 0x8B:                              /* MOV Gw,Ew */
        nextop = Fetch8(emu);
        GetEw(emu, &op2, &ea2, nextop);
        GetG(emu, &op1, nextop);
        op1->word[0] = op2->word[0];
        break;
    
    case 0x90:                              /* NOP */
        break;

    case 0xA1:                              /* MOV AX,Ow */
        R_AX = *(uint16_t*)Fetch32(emu);
        break;
    case 0xA3:                              /* MOV Od,AX */
        *(uint16_t*)Fetch32(emu) = R_AX;
        break;

    case 0xB8:                              /* MOV EAX,Id */
    case 0xB9:                              /* MOV ECX,Id */
    case 0xBA:                              /* MOV EDX,Id */
    case 0xBB:                              /* MOV EBX,Id */
    case 0xBC:                              /*    ...     */
    case 0xBD:
    case 0xBE:
    case 0xBF:
        emu->regs[opcode-0xB8].word[0] = Fetch16(emu);
        break;

    case 0xC7:                              /* MOV Ew,Iw */
        nextop = Fetch8(emu);
        GetEw(emu, &op1, &ea2, nextop);
        op1->word[0] = Fetch16(emu);
        break;
    default:
        UnimpOpcode(emu);
    }
}
