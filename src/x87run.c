#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "debug.h"
#include "stack.h"
#include "x86emu.h"
#include "x86run.h"
#include "x86emu_private.h"
#include "x86run_private.h"
#include "x87emu_private.h"
#include "x86primop.h"
#include "x86trace.h"
#include "x86run.h"

#define PI		3.14159265358979323846
#define L2E		1.4426950408889634
#define L2T		3.3219280948873623
#define LN2		0.69314718055994531
#define LG2		0.3010299956639812

int usefloat = 0;

void RunD8(x86emu_t *emu)
{
    uint8_t nextop;
    reg32_t *op1, *op2;
    reg32_t ea1, ea2;
    int32_t tmp32s;
    float f;
    double d;
    long double ld;
    nextop = Fetch8(emu);
    switch(nextop) {
        case 0xC0:
        case 0xC1:
        case 0xC2:
        case 0xC3:
        case 0xC4:
        case 0xC5:
        case 0xC6:
        case 0xC7:  /* FADD */
            if(usefloat)
                ST0.f += ST(nextop&7).f;
            else
                ST0.d += ST(nextop&7).d;
            break;
        case 0xC8:
        case 0xC9:
        case 0xCA:
        case 0xCB:
        case 0xCC:
        case 0xCD:
        case 0xCE:
        case 0xCF:  /* FMUL */
            if(usefloat)
                ST0.f *= ST(nextop&7).f;
            else
                ST0.d *= ST(nextop&7).d;
            break;
        case 0xD0:
        case 0xD1:
        case 0xD2:
        case 0xD3:
        case 0xD4:
        case 0xD5:
        case 0xD6:
        case 0xD7:  /* FCOM */
            if(usefloat)
                fpu_fcom_f(emu, ST(nextop&7).f);
            else
                fpu_fcom(emu, ST(nextop&7).d);
            break;
        case 0xD8:
        case 0xD9:
        case 0xDA:
        case 0xDB:
        case 0xDC:
        case 0xDD:
        case 0xDE:
        case 0xDF:  /* FCOMP */
            if(usefloat)
                fpu_fcom_f(emu, ST(nextop&7).f);
            else
                fpu_fcom(emu, ST(nextop&7).d);
            fpu_do_pop(emu);
            break;
        case 0xE0:
        case 0xE1:
        case 0xE2:
        case 0xE3:
        case 0xE4:
        case 0xE5:
        case 0xE6:
        case 0xE7:  /* FSUB */
            if(usefloat)
                ST0.f -= ST(nextop&7).f;
            else
                ST0.d -= ST(nextop&7).d;
            break;
        case 0xE8:
        case 0xE9:
        case 0xEA:
        case 0xEB:
        case 0xEC:
        case 0xED:
        case 0xEE:
        case 0xEF:  /* FSUBR */
            if(usefloat)
                ST0.f = ST(nextop&7).f - ST0.f;
            else
                ST0.d = ST(nextop&7).d - ST0.d;
            break;
        case 0xF0:
        case 0xF1:
        case 0xF2:
        case 0xF3:
        case 0xF4:
        case 0xF5:
        case 0xF6:
        case 0xF7:  /* FDIV */
            if(usefloat)
                ST0.f /= ST(nextop&7).f;
            else
                ST0.d /= ST(nextop&7).d;
            break;
        case 0xF8:
        case 0xF9:
        case 0xFA:
        case 0xFB:
        case 0xFC:
        case 0xFD:
        case 0xFE:
        case 0xFF:  /* FDIVR */
            if(usefloat)
                ST0.f = ST(nextop&7).f / ST0.f;
            else
                ST0.d = ST(nextop&7).d / ST0.d;
            break;
        default:
        switch((nextop>>3)&7) {
            case 0:         /* FADD ST0, float */
                GetEd(emu, &op2, nextop);
                *(uint32_t*)&f = op2->dword[0];
                if(usefloat)
                    ST0.f += f;
                else
                    ST0.d += f;
                break;
            case 1:         /* FMUL ST0, float */
                GetEd(emu, &op2, nextop);
                *(uint32_t*)&f = op2->dword[0];
                if(usefloat)
                    ST0.f *= f;
                else
                    ST0.d *= f;
                break;
            case 2:      /* FCOM ST0, float */
                GetEd(emu, &op2, nextop);
                *(uint32_t*)&f = op2->dword[0];
                if(usefloat)
                    fpu_fcom_f(emu, f);
                else
                    fpu_fcom(emu, f);
                break;
            case 3:     /* FCOMP */
                GetEd(emu, &op2, nextop);
                *(uint32_t*)&f = op2->dword[0];
                if(usefloat)
                    fpu_fcom_f(emu, f);
                else
                    fpu_fcom(emu, f);
                fpu_do_pop(emu);
                break;
            case 4:         /* FSUB ST0, float */
                GetEd(emu, &op2, nextop);
                *(uint32_t*)&f = op2->dword[0];
                if(usefloat)
                    ST0.f -= f;
                else
                    ST0.d -= f;
                break;
            case 5:         /* FSUBR ST0, float */
                GetEd(emu, &op2, nextop);
                *(uint32_t*)&f = op2->dword[0];
                if(usefloat)
                    ST0.f = f - ST0.f;
                else
                    ST0.d = f - ST0.d;
                break;
            case 6:         /* FDIV ST0, float */
                GetEd(emu, &op2, nextop);
                *(uint32_t*)&f = op2->dword[0];
                if(usefloat)
                    ST0.f /= f;
                else
                    ST0.d /= f;
                break;
            case 7:         /* FDIVR ST0, float */
                GetEd(emu, &op2, nextop);
                *(uint32_t*)&f = op2->dword[0];
                if(usefloat)
                    ST0.f = f / ST0.f;
                else
                    ST0.d = f / ST0.d;
                break;
            default:
                UnimpOpcode(emu);
        }
    }
}

void Run66D9(x86emu_t *emu)
{
    uint8_t nextop;
    reg32_t *op1, *op2;
    reg32_t ea1, ea2;
    float f;
    double d;
    long double ld;
    int64_t ll;
    ++R_EIP;    // eat the "D9"
    nextop = Fetch8(emu);
    switch (nextop) {
        case 0xC0:
        case 0xC1:
        case 0xC2:
        case 0xC3:
        case 0xC4:
        case 0xC5:
        case 0xC6:
        case 0xC7:
        case 0xC8:
        case 0xC9:
        case 0xCA:
        case 0xCB:
        case 0xCC:
        case 0xCD:
        case 0xCE:
        case 0xCF:
        case 0xD0:
        case 0xE0:
        case 0xE5:
        case 0xE8:
        case 0xE9:
        case 0xEA:
        case 0xEB:
        case 0xEC:
        case 0xED:
        case 0xEE:
        case 0xFC:
        case 0xE1:
        case 0xE4:
        case 0xF0:
        case 0xF1:
        case 0xF2:
        case 0xF3:
        case 0xF4:
        case 0xF5:
        case 0xF6:
        case 0xF7:
        case 0xF8:
        case 0xF9:
        case 0xFA:
        case 0xFB:
        case 0xFD:
        case 0xFE:
        case 0xFF:
            UnimpOpcode(emu);
            break;
        default:
        switch((nextop>>3)&7) {
            case 4:     /* FLDENV m */
                // warning, incomplete
                GetEw(emu, &op1,nextop);
                fpu_loadenv(emu, (char*)&op1->dword[0], 1);
                break;
            case 6:     /* FNSTENV m */
                // warning, incomplete
                GetEw(emu, &op1,nextop);
                fpu_savenv(emu, (char*)&op1->dword[0], 1);
                break;
            default:
                UnimpOpcode(emu);
        }
    }
}

void RunD9(x86emu_t *emu)
{
    uint8_t nextop;
    reg32_t *op1, *op2;
    reg32_t ea1, ea2;
    float f;
    double d;
    long double ld;
    int64_t ll;
    nextop = Fetch8(emu);
    switch (nextop) {
        case 0xC0:
        case 0xC1:
        case 0xC2:
        case 0xC3:
        case 0xC4:
        case 0xC5:
        case 0xC6:
        case 0xC7:  /* FLD STx */
            ll = ST(nextop&7).ll;
            fpu_do_push(emu);
            ST0.ll = ll;
            break;
        case 0xC8:
        case 0xC9:
        case 0xCA:
        case 0xCB:
        case 0xCC:
        case 0xCD:
        case 0xCE:
        case 0xCF:  /* FXCH STx */
            ll = ST(nextop&7).ll;
            ST(nextop&7).ll = ST0.ll;
            ST0.ll = ll;
            break;

        case 0xD0:  /* FNOP */
            break;

        case 0xE0:  /* FCHS */
            if(usefloat)
                ST0.f = -ST0.f;
            else
                ST0.d = -ST0.d;
            break;
        case 0xE1:  /* FABS */
            if(usefloat)
                ST0.f = fabs(ST0.f);
            else
                ST0.d = fabs(ST0.d);
            break;
        
        case 0xE5:  /* FXAM */
            if(usefloat)
                fpu_fxam_f(emu);
            else
                fpu_fxam(emu);
            break;

        case 0xE8:  /* FLD1 */
            fpu_do_push(emu);
            if(usefloat)
                ST0.f = 1.0f;
            else
                ST0.d = 1.0;
            break;
        case 0xE9:  /* FLDL2T */
            fpu_do_push(emu);
            if(usefloat)
                ST0.f = L2T;
            else
                ST0.d = L2T;
            break;
        case 0xEA:  /* FLDL2E */
            fpu_do_push(emu);
            if(usefloat)
                ST0.f = L2E;
            else
                ST0.d = L2E;
            break;
        case 0xEB:  /* FLDPI */
            fpu_do_push(emu);
            if(usefloat)
                ST0.f = PI;
            else
                ST0.d = PI;
            break;
        case 0xEC:  /* FLDLG2 */
            fpu_do_push(emu);
            if(usefloat)
                ST0.f = LG2;
            else
                ST0.d = LG2;
            break;
        case 0xED:  /* FLDLN2 */
            fpu_do_push(emu);
            if(usefloat)
                ST0.f = LN2;
            else
                ST0.d = LN2;
            break;
        case 0xEE:  /* FLDZ */
            fpu_do_push(emu);
            if(usefloat)
                ST0.f = 0.0f;
            else
                ST0.d = 0.0;
            break;
        
        case 0xF2:  /* FTAN */
            if(usefloat)
                ST0.f = tanf(ST0.f);
            else
                ST0.d = tan(ST0.d);
            fpu_do_push(emu);
            if(usefloat)
                ST0.f = 1.0f;
            else
                ST0.d = 1.0;
            break;
        case 0xF3:  /* FPATAN */
            if(usefloat)
                ST(1).f = atan2(ST(1).f, ST0.f);
            else
                ST(1).d = atan2(ST(1).d, ST0.d);
            fpu_do_pop(emu);
            break;

        case 0xFA:  /* FSQRT */
            if(usefloat)
                ST0.f = sqrt(ST0.f);
            else
                ST0.d = sqrt(ST0.d);
            break;
        case 0xFB:  /* FSINCOS */
            if(usefloat) {
                f = ST0.f;
                ST0.f = sin(f);
                fpu_do_push(emu);
                ST0.f = cos(f);
            } else {
                d = ST0.d;
                ST0.d = sin(d);
                fpu_do_push(emu);
                ST0.d = cos(d);
            }
            break;
        case 0xFC:  /* FRNDINT */
            if(usefloat)
                ST0.f = fpu_round_f(emu, ST0.f);
            else
                ST0.d = fpu_round(emu, ST0.d);
            break;

        case 0xFE:  /* FSIN */
            if(usefloat)
                ST0.f = sin(ST0.f);
            else
                ST0.f = sin(ST0.f);
            break;
        case 0xFF:  /* FCOS */
            if(usefloat)
                ST0.f = cos(ST0.f);
            else
                ST0.d = cos(ST0.d);
            break;


        case 0xE4:
        case 0xF0:
        case 0xF1:
        case 0xF4:
        case 0xF5:
        case 0xF6:
        case 0xF7:
        case 0xF8:
        case 0xF9:
        case 0xFD:
            UnimpOpcode(emu);
            break;
        default:
        switch((nextop>>3)&7) {
            case 0:     /* FLD ST0, Ed float */
                GetEd(emu, &op2, nextop);
                *(uint32_t*)&f = op2->dword[0];
                fpu_do_push(emu);
                if(usefloat)
                    ST0.f = f;
                else
                    ST0.d = f;
                break;
            case 2:     /* FST Ed, ST0 */
                GetEd(emu, &op1, nextop);
                if(usefloat)
                    f = ST0.f;
                else
                    f = ST0.d;
                op1->dword[0] = *(uint32_t*)&f;
                break;
            case 3:     /* FSTP Ed, ST0 float with partial alias on mod=3=>ST1 */
                GetEd(emu, &op1, nextop);
                if(usefloat)
                    f = ST0.f;
                else                
                    f = ST0.d;
                op1->dword[0] = *(uint32_t*)&f;
                fpu_do_pop(emu);
                break;
            case 4:     /* FLDENV m */
                // warning, incomplete
                GetEd(emu, &op1,nextop);
                fpu_loadenv(emu, (char*)&op1->dword[0], 0);
                break;
            case 5:     /* FLDCW Ew */
                GetEw(emu, &op1, nextop);
                emu->cw = op1->word[0];
                // do something with cw?
                emu->round = (fpu_round_t)((emu->cw >> 10) & 3);
                break;
            case 6:     /* FNSTENV m */
                // warning, incomplete
                GetEd(emu, &op1,nextop);
                fpu_savenv(emu, (char*)&op1->dword[0], 0);
                op1->dword[0] = emu->cw;
                op1->dword[1] = emu->sw.x16;
                // tagword: 2bits*8
                // intruction pointer: 48bits
                // data (operand) pointer: 48bits
                // last opcode: 11bits save: 16bits restaured (1st and 2nd opcode only)
                break;
            case 7: /* FNSTCW Ew */
                GetEw(emu, &op1, nextop);
                op1->word[0] = emu->cw;
                break;
            default:
                UnimpOpcode(emu);
        }
    }
}

void RunDA(x86emu_t *emu)
{
    uint8_t nextop;
    reg32_t *op1, *op2;
    reg32_t ea1, ea2;
    int32_t tmp32s;
    float f;
    double d;
    long double ld;
    nextop = Fetch8(emu);
    switch(nextop) {

    case 0xC0:      /* FCMOVB ST(0), ST(i) */
    case 0xC1:
    case 0xC2:
    case 0xC3:
    case 0xC4:
    case 0xC5:
    case 0xC6:
    case 0xC7:
        CHECK_FLAGS(emu);
        if(ACCESS_FLAG(F_CF))
            ST0.ll = ST(nextop&7).ll;
        break;
    case 0xC8:      /* FCMOVE ST(0), ST(i) */
    case 0xC9:
    case 0xCA:
    case 0xCB:
    case 0xCC:
    case 0xCD:
    case 0xCE:
    case 0xCF:
        CHECK_FLAGS(emu);
        if(ACCESS_FLAG(F_ZF))
            ST0.ll = ST(nextop&7).ll;
        break;
    case 0xD0:      /* FCMOVBE ST(0), ST(i) */
    case 0xD1:
    case 0xD2:
    case 0xD3:
    case 0xD4:
    case 0xD5:
    case 0xD6:
    case 0xD7:
        CHECK_FLAGS(emu);
        if(ACCESS_FLAG(F_CF) || ACCESS_FLAG(F_ZF))
            ST0.ll = ST(nextop&7).ll;
        break;
    case 0xD8:      /* FCMOVU ST(0), ST(i) */
    case 0xD9:
    case 0xDA:
    case 0xDB:
    case 0xDC:
    case 0xDD:
    case 0xDE:
    case 0xDF:
        CHECK_FLAGS(emu);
        if(ACCESS_FLAG(F_PF))
            ST0.ll = ST(nextop&7).ll;
        break;
    
    case 0xE9:      /* FUCOMPP */
        if(usefloat)
            fpu_fcom_f(emu, ST1.f);
        else
            fpu_fcom(emu, ST1.d);   // bad, should handle QNaN and IA interrupt
        fpu_do_pop(emu);
        fpu_do_pop(emu);
        break;

/*    case 0xE4:
    case 0xF0:
    case 0xF1:
    case 0xF4:
    case 0xF5:
    case 0xF6:
    case 0xF7:
    case 0xF8:
    case 0xF9:
    case 0xFD:
        UnimpOpcode(emu);
        break;*/
    default:
        switch((nextop>>3)&7) {
            case 1:     /* FIMUL ST0, Ed int */
                GetEd(emu, &op2, nextop);
                fpu_do_push(emu);
                if(usefloat)
                    ST0.f *= op2->sword[0];
                else
                    ST0.d *= op2->sword[0];
                break;
            default:
                UnimpOpcode(emu);
        }
    }
}

void RunDB(x86emu_t *emu)
{
    uint8_t nextop;
    reg32_t *op1, *op2;
    reg32_t ea1, ea2;
    int32_t tmp32s;
    float f;
    double d;
    long double ld;
    nextop = Fetch8(emu);
    switch(nextop) {
    case 0xC0:      /* FCMOVNB ST(0), ST(i) */
    case 0xC1:
    case 0xC2:
    case 0xC3:
    case 0xC4:
    case 0xC5:
    case 0xC6:
    case 0xC7:
        CHECK_FLAGS(emu);
        if(!ACCESS_FLAG(F_CF))
            ST0.ll = ST(nextop&7).ll;
        break;
    case 0xC8:      /* FCMOVNE ST(0), ST(i) */
    case 0xC9:
    case 0xCA:
    case 0xCB:
    case 0xCC:
    case 0xCD:
    case 0xCE:
    case 0xCF:
        CHECK_FLAGS(emu);
        if(!ACCESS_FLAG(F_ZF))
            ST0.ll = ST(nextop&7).ll;
        break;
    case 0xD0:      /* FCMOVNBE ST(0), ST(i) */
    case 0xD1:
    case 0xD2:
    case 0xD3:
    case 0xD4:
    case 0xD5:
    case 0xD6:
    case 0xD7:
        CHECK_FLAGS(emu);
        if(!(ACCESS_FLAG(F_CF) || ACCESS_FLAG(F_ZF)))
            ST0.ll = ST(nextop&7).ll;
        break;
    case 0xD8:      /* FCMOVNU ST(0), ST(i) */
    case 0xD9:
    case 0xDA:
    case 0xDB:
    case 0xDC:
    case 0xDD:
    case 0xDE:
    case 0xDF:
        CHECK_FLAGS(emu);
        if(!ACCESS_FLAG(F_PF))
            ST0.ll = ST(nextop&7).ll;
        break;

    case 0xE2:      /* FNCLEX */
        //Clears the floating-point exception flags (PE, UE, OE, ZE, DE, and IE), 
        // the exception summary status flag (ES), the stack fault flag (SF), and the busy flag (B) in the FPU status word
        emu->sw.f.F87_PE = 0;
        emu->sw.f.F87_UE = 0;
        emu->sw.f.F87_OE = 0;
        emu->sw.f.F87_ZE = 0;
        emu->sw.f.F87_DE = 0;
        emu->sw.f.F87_IE = 0;
        emu->sw.f.F87_ES = 0;
        emu->sw.f.F87_SF = 0;
        emu->sw.f.F87_B = 0;
        break;
    case 0xE3:      /* FNINIT */
        reset_fpu(emu);
        break;
    case 0xE8:  /* FUCOMI ST0, STx */
    case 0xE9:
    case 0xEA:
    case 0xEB:
    case 0xEC:
    case 0xED:
    case 0xEE:
    case 0xEF:
        if(usefloat)
            fpu_fcomi_f(emu, ST(nextop&7).f);
        else
            fpu_fcomi(emu, ST(nextop&7).d);   // bad, should handle QNaN and IA interrupt
        break;

    case 0xF0:  /* FCOMI ST0, STx */
    case 0xF1:
    case 0xF2:
    case 0xF3:
    case 0xF4:
    case 0xF5:
    case 0xF6:
    case 0xF7:
        if(usefloat)
            fpu_fcomi_f(emu, ST(nextop&7).f);
        else
            fpu_fcomi(emu, ST(nextop&7).d);
        break;
    default:
        switch((nextop>>3)&7) {
            case 0: /* FILD ST0, Gd */
                GetEd(emu, &op2, nextop);
                fpu_do_push(emu);
                if(usefloat)
                    ST0.f = op2->sdword[0];
                else
                    ST0.d = op2->sdword[0];
                break;
            case 2: /* FIST Ed, ST0 */
                GetEd(emu, &op2, nextop);
                if(usefloat)
                    tmp32s = ST0.f;
                else
                    tmp32s = ST0.d; // TODO: Handling of FPU Exception and rounding
                if(tmp32s==0x7fffffff && isgreater(ST0.d, (double)(int32_t)0x7fffffff))
                    tmp32s = 0x80000000;
                op2->sdword[0] = tmp32s;
                break;
            case 3: /* FISTP Ed, ST0 */
                GetEd(emu, &op2, nextop);
                if(usefloat)
                    tmp32s = ST0.f;
                else
                    tmp32s = ST0.d; // TODO: Handling of FPU Exception and rounding
                if(tmp32s==0x7fffffff && isgreater(ST0.d, (double)(int32_t)0x7fffffff))
                    tmp32s = 0x80000000;
                fpu_do_pop(emu);
                op2->sdword[0] = tmp32s;
                break;
            case 5: /* FLD ST0, Gt */
                GetEd(emu, &op2, nextop);
                fpu_do_push(emu);
                memcpy(&STld(0).ld, op2, 10);
                LD2D(&STld(0), &ST(0).d);
                if(usefloat)
                    ST0.f = ST0.d;
                STld(0).ref = ST0.ll;
                break;
            case 7: /* FSTP tbyte */
                GetEd(emu, &op1, nextop);
                if(ST0.ll!=STld(0).ref) {
                    if(usefloat) {
                        d = ST0.f;
                        D2LD(&d, op1);
                    } else
                        D2LD(&ST0.d, op1);
                } else
                    memcpy(op1, &STld(0).ld, 10);
                fpu_do_pop(emu);
                break;
            default:
                UnimpOpcode(emu);
        }
    }
}

void RunDC(x86emu_t *emu)
{
    uint8_t nextop;
    reg32_t *op1, *op2;
    reg32_t ea1, ea2;
    int32_t tmp32s;
    float f;
    double d;
    long double ld;
    nextop = Fetch8(emu);
    switch(nextop) {
        case 0xC0:
        case 0xC1:
        case 0xC2:
        case 0xC3:
        case 0xC4:
        case 0xC5:
        case 0xC6:
        case 0xC7:  /* FADD */
            if(usefloat)
                ST(nextop&7).f += ST0.f;
            else
                ST(nextop&7).d += ST0.d;
            break;
        case 0xC8:
        case 0xC9:
        case 0xCA:
        case 0xCB:
        case 0xCC:
        case 0xCD:
        case 0xCE:
        case 0xCF:  /* FMUL */
            if(usefloat)
                ST(nextop&7).f *= ST0.f;
            else
                ST(nextop&7).d *= ST0.d;
            break;
        case 0xD0:
        case 0xD1:
        case 0xD2:
        case 0xD3:
        case 0xD4:
        case 0xD5:
        case 0xD6:
        case 0xD7:  /* FCOM */
            if(usefloat)
                fpu_fcom_f(emu, ST(nextop&7).f);
            else
                fpu_fcom(emu, ST(nextop&7).d);  // TODO: is this ok or should it be reversed
            break;
        case 0xD8:
        case 0xD9:
        case 0xDA:
        case 0xDB:
        case 0xDC:
        case 0xDD:
        case 0xDE:
        case 0xDF:  /* FCOMP */
            if(usefloat)
                fpu_fcom_f(emu, ST(nextop&7).f);
            else
                fpu_fcom(emu, ST(nextop&7).d);  // TODO: is this ok or should the test be reversed
            fpu_do_pop(emu);
            break;
        case 0xE0:
        case 0xE1:
        case 0xE2:
        case 0xE3:
        case 0xE4:
        case 0xE5:
        case 0xE6:
        case 0xE7:  /* FSUBR */
            if(usefloat)
                ST(nextop&7).f = ST0.f -ST(nextop&7).f;
            else
                ST(nextop&7).d = ST0.d -ST(nextop&7).d;
            break;
        case 0xE8:
        case 0xE9:
        case 0xEA:
        case 0xEB:
        case 0xEC:
        case 0xED:
        case 0xEE:
        case 0xEF:  /* FSUB */
            if(usefloat)
                ST(nextop&7).f -= ST0.f;
            else
                ST(nextop&7).d -= ST0.d;
            break;
        case 0xF0:
        case 0xF1:
        case 0xF2:
        case 0xF3:
        case 0xF4:
        case 0xF5:
        case 0xF6:
        case 0xF7:  /* FDIVR */
            if(usefloat)
                ST(nextop&7).f = ST0.f / ST(nextop&7).f;
            else
                ST(nextop&7).d = ST0.d / ST(nextop&7).d;
            break;
        case 0xF8:
        case 0xF9:
        case 0xFA:
        case 0xFB:
        case 0xFC:
        case 0xFD:
        case 0xFE:
        case 0xFF:  /* FDIV */
            if(usefloat)
                ST(nextop&7).f /=  ST0.f;
            else
                ST(nextop&7).d /=  ST0.d;
            break;
        default:
        switch((nextop>>3)&7) {
        case 0:         /* FADD ST0, double */
            GetEd(emu, &op2, nextop);
            memcpy(&d, &op2->dword[0], 8);
            if(usefloat)
                ST0.f += d;
            else
                ST0.d += d;
            break;
        case 1:         /* FMUL ST0, double */
            GetEd(emu, &op2, nextop);
            memcpy(&d, &op2->dword[0], 8);
            if(usefloat)
                ST0.f *= d;
            else
                ST0.d *= d;
            break;
        case 2:      /* FCOM ST0, double */
            GetEd(emu, &op2, nextop);
            memcpy(&d, &op2->dword[0], 8);
            if(usefloat)
                fpu_fcom_f(emu, d);
            else
                fpu_fcom(emu, d);
            break;
        case 3:     /* FCOMP ST0, double */
            GetEd(emu, &op2, nextop);
            memcpy(&d, &op2->dword[0], 8);
            if(usefloat)
                fpu_fcom_f(emu, d);
            else
                fpu_fcom(emu, d);
            fpu_do_pop(emu);
            break;
        case 4:         /* FSUB ST0, double */
            GetEd(emu, &op2, nextop);
            memcpy(&d, &op2->dword[0], 8);
            if(usefloat)
                ST0.f -= d;
            else
                ST0.d -= d;
            break;
        case 5:         /* FSUBR ST0, double */
            GetEd(emu, &op2, nextop);
            memcpy(&d, &op2->dword[0], 8);
            if(usefloat)
                ST0.f = d - ST0.f;
            else
                ST0.d = d - ST0.d;
            break;
        case 6:         /* FDIV ST0, double */
            GetEd(emu, &op2, nextop);
            memcpy(&d, &op2->dword[0], 8);
            if(usefloat)
                ST0.f /= d;
            else
                ST0.d /= d;
            break;
        case 7:         /* FDIVR ST0, double */
            GetEd(emu, &op2, nextop);
            memcpy(&d, &op2->dword[0], 8);
            if(usefloat)
                ST0.f = d / ST0.f;
            else
                ST0.d = d / ST0.d;
            break;
        default:
            UnimpOpcode(emu);
        }
    }
}

void RunDD(x86emu_t *emu)
{
    uint8_t nextop;
    reg32_t *op1, *op2;
    reg32_t ea1, ea2;
    float f;
    double d;
    long double ld;
    nextop = Fetch8(emu);
    switch(nextop) {
    
    case 0xD0:  /* FST ST0, STx */
    case 0xD1:
    case 0xD2:
    case 0xD3:
    case 0xD4:
    case 0xD5:
    case 0xD6:
    case 0xD7:
        ST(nextop&7).ll = ST0.ll;
        break;
    case 0xD8:  /* FSTP ST0, STx */
    case 0xD9:
    case 0xDA:
    case 0xDB:
    case 0xDC:
    case 0xDD:
    case 0xDE:
    case 0xDF:
        ST(nextop&7).ll = ST0.ll;
        fpu_do_pop(emu);
        break;
    case 0xE0:  /* FUCOM ST0, STx */
    case 0xE1:
    case 0xE2:
    case 0xE3:
    case 0xE4:
    case 0xE5:
    case 0xE6:
    case 0xE7:
        if(usefloat)
            fpu_fcom_f(emu, ST(nextop&7).f);
        else
            fpu_fcom(emu, ST(nextop&7).d);   // bad, should handle QNaN and IA interrupt
        break;
    case 0xE8:  /* FUCOMP ST0, STx */
    case 0xE9:
    case 0xEA:
    case 0xEB:
    case 0xEC:
    case 0xED:
    case 0xEE:
    case 0xEF:
        if(usefloat)
            fpu_fcom_f(emu, ST(nextop&7).f);
        else
            fpu_fcom(emu, ST(nextop&7).d);   // bad, should handle QNaN and IA interrupt
        fpu_do_pop(emu);
        break;

    default:
        switch((nextop>>3)&7) {
            case 0: /* FLD double */
                GetEd(emu, &op1, nextop);
                fpu_do_push(emu);
                ST0.ll = *(int64_t*)&op1->dword[0];
                if(usefloat)
                    ST0.f = ST0.d;
                break;
            case 2: /* FST double */
                GetEd(emu, &op1, nextop);
                if(usefloat)
                    *(double*)&op1->dword[0] = ST0.f;
                else
                    *(int64_t*)&op1->dword[0] = ST0.ll;
                break;
            case 3: /* FSTP double */
                GetEd(emu, &op1, nextop);
                if(usefloat)
                    *(double*)&op1->dword[0] = ST0.f;
                else
                    *(int64_t*)&op1->dword[0] = ST0.ll;
                fpu_do_pop(emu);
                break;
            case 4: /* FRSTOR m108byte */
                GetEd(emu, &op1, nextop);
                fpu_loadenv(emu, (char*)&op1->dword[0], 0);
                // get the STx
                {
                    char* p =(char*)&op1->dword[0];
                    p += 28;
                    for (int i=0; i<8; ++i) {
                        if(usefloat) {
                            d = ST(i).f;
                            LD2D(p, &d);
                        } else
                            LD2D(p, &ST(i).d);
                        p+=10;
                    }
                }
                break;
            case 6: /* FNSAVE m108byte */
                GetEd(emu, &op1, nextop);
                // ENV first...
                // warning, incomplete
                fpu_savenv(emu, (char*)op1, 0);
                // save the STx
                {
                    char* p =(char*)op1;
                    p += 28;
                    for (int i=0; i<8; ++i) {
                        if(usefloat) {
                            D2LD(&d, p);
                            ST(i).f = d;
                        } else
                            D2LD(&ST(i).d, p);
                        p+=10;
                    }
                }
                reset_fpu(emu);
                break;
            default:
                UnimpOpcode(emu);
        }
    }
}

void Run66DD(x86emu_t *emu)
{
    uint8_t nextop;
    reg32_t *op1, *op2;
    reg32_t ea1, ea2;
    float f;
    double d;
    long double ld;
    ++R_EIP;
    nextop = Fetch8(emu);
    switch(nextop) {
    
    case 0xE0:
    case 0xE1:
    case 0xE2:
    case 0xE3:
    case 0xE4:
    case 0xE5:
    case 0xE6:
    case 0xE7:
    case 0xE8:
    case 0xE9:
    case 0xEA:
    case 0xEB:
    case 0xEC:
    case 0xED:
    case 0xEE:
    case 0xEF:
        UnimpOpcode(emu);
        break;

    default:
        switch((nextop>>3)&7) {
            case 4: /* FRSTOR m94byte */
                GetEw(emu, &op1, nextop);
                fpu_loadenv(emu, (char*)&op1->dword[0], 1);
                // get the STx
                {
                    char* p =(char*)&op1->dword[0];
                    p += 14;
                    for (int i=0; i<8; ++i) {
                        if(usefloat) {
                            d = ST(i).f;
                            LD2D(p, &d);
                        } else
                            LD2D(p, &ST(i).d);
                        p+=10;
                    }
                }
                break;
            case 6: /* FNSAVE m94byte */
                GetEw(emu, &op1, nextop);
                // ENV first...
                fpu_savenv(emu, (char*)op1, 1);
                // save the STx
                {
                    char* p =(char*)op1;
                    p += 14;
                    for (int i=0; i<8; ++i) {
                        if(usefloat) {
                            D2LD(&d, p);
                            ST(i).f = d;
                        } else
                            D2LD(&ST(i).d, p);
                        p+=10;
                    }
                }
                reset_fpu(emu);
                break;
            default:
                UnimpOpcode(emu);
        }
    }
}

void RunDE(x86emu_t *emu)
{
    uint8_t nextop;
    reg32_t *op1, *op2;
    reg32_t ea1, ea2;
    float f;
    double d;
    long double ld;
    nextop = Fetch8(emu);
    switch (nextop) {
    case 0xC1:  /* FADDP ST1, ST0 */
        if(usefloat) {
            f = ST0.f;
            fpu_do_pop(emu);
            ST0.f += f;
        } else {
            d = ST0.d;
            fpu_do_pop(emu);
            ST0.d += d;
        }
        break;
    case 0xC0:  /* FADDP STx, ST0 */
    case 0xC2:
    case 0xC3:
    case 0xC4:
    case 0xC5:
    case 0xC6:
    case 0xC7:
        if(usefloat)
            ST(nextop&7).f += ST0.f;
        else
            ST(nextop&7).d += ST0.d;
        fpu_do_pop(emu);
        break;
    case 0xC9:  /* FMULP ST1, ST0 */
        if(usefloat)
            ST1.f *= ST0.f;
        else
            ST1.d *= ST0.d;
        fpu_do_pop(emu);
        break;
    case 0xC8:  /* FMULP STx, ST0 */
    case 0xCA:
    case 0xCB:
    case 0xCC:
    case 0xCD:
    case 0xCE:
    case 0xCF:
        if(usefloat)
            ST(nextop&7).f *= ST0.f;
        else
            ST(nextop&7).d *= ST0.d;
        fpu_do_pop(emu);
        break;
    case 0xD9:  /* FCOMPP */
        if(usefloat)
            fpu_fcom_f(emu, ST1.f);
        else
            fpu_fcom(emu, ST1.d);
        fpu_do_pop(emu);
        fpu_do_pop(emu);
        break;

    case 0xE1:  /* FSUBRP ST1, ST0 */
        if(usefloat) {
            f = ST0.f;
            fpu_do_pop(emu);
            ST0.f = f - ST0.f;
        } else {
            d = ST0.d;
            fpu_do_pop(emu);
            ST0.d = d - ST0.d;
        }
        break;
    case 0xE0:  /* FSUBRP STx, ST0 */
    case 0xE2:
    case 0xE3:
    case 0xE4:
    case 0xE5:
    case 0xE6:
    case 0xE7:
        if(usefloat)
            ST(nextop&7).f = ST0.f - ST(nextop&7).f;
        else
            ST(nextop&7).d = ST0.d - ST(nextop&7).d;
        fpu_do_pop(emu);
        break;
   case 0xE9:  /* FSUBP ST1, ST0 */
        if(usefloat)
            ST1.f -= ST0.f;
        else
            ST1.d -= ST0.d;
        fpu_do_pop(emu);
        break;
    case 0xE8:  /* FSUBP STx, ST0 */
    case 0xEA:
    case 0xEB:
    case 0xEC:
    case 0xED:
    case 0xEE:
    case 0xEF:
        if(usefloat)
            ST(nextop&7).f -= ST0.f;
        else
            ST(nextop&7).d -= ST0.d;
        fpu_do_pop(emu);
        break;
    case 0xF1:  /* FDIVRP ST1, ST0 */
        if(usefloat) {
            f = ST0.f;
            fpu_do_pop(emu);
            ST0.f = f / ST0.f;
        } else {
            d = ST0.d;
            fpu_do_pop(emu);
            ST0.d = d / ST0.d;
        }
        break;
    case 0xF0:  /* FDIVRP STx, ST0 */
    case 0xF2:
    case 0xF3:
    case 0xF4:
    case 0xF5:
    case 0xF6:
    case 0xF7:
        if(usefloat)
            ST(nextop&7).f = ST0.f / ST(nextop&7).f;
        else
            ST(nextop&7).d = ST0.d / ST(nextop&7).d;
        fpu_do_pop(emu);
        break;
    case 0xF9:  /* FDIVP ST1, ST0 */
        if(usefloat) {
            f = ST0.f;
            fpu_do_pop(emu);
            ST0.f /= f;
        } else {
            d = ST0.d;
            fpu_do_pop(emu);
            ST0.d /= d;
        }
        break;
    case 0xF8:  /* FDIVP STx, ST0 */
    case 0xFA:
    case 0xFB:
    case 0xFC:
    case 0xFD:
    case 0xFE:
    case 0xFF:
        if(usefloat)
            ST(nextop&7).f /= ST0.f;
        else
            ST(nextop&7).d /= ST0.d;
        fpu_do_pop(emu);
        break;
    default:
        switch((nextop>>3)&7) {
        default:
            UnimpOpcode(emu);
        }
    }
}

void RunDF(x86emu_t *emu)
{
    uint8_t nextop;
    reg32_t *op1, *op2;
    reg32_t ea1, ea2;
    int64_t tmp64s;
    int16_t tmp16s;
    int32_t tmp32s;
    float f;
    double d;
    long double ld;
    nextop = Fetch8(emu);
    switch (nextop) {
    case 0xE0:  /* FNSTSW AX */
        emu->sw.f.F87_TOP = emu->top&7;
        R_AX = emu->sw.x16;
        break;

    case 0xE8:  /* FUCOMIP ST0, STx */
    case 0xE9:
    case 0xEA:
    case 0xEB:
    case 0xEC:
    case 0xED:
    case 0xEE:
    case 0xEF:
        if(usefloat)
            fpu_fcomi_f(emu, ST(nextop&7).f);
        else
            fpu_fcomi(emu, ST(nextop&7).d);   // bad, should handle QNaN and IA interrupt
        fpu_do_pop(emu);
        break;

    case 0xF0:  /* FCOMIP ST0, STx */
    case 0xF1:
    case 0xF2:
    case 0xF3:
    case 0xF4:
    case 0xF5:
    case 0xF6:
    case 0xF7:
        if(usefloat)
            fpu_fcomi_f(emu, ST(nextop&7).f);
        else
            fpu_fcomi(emu, ST(nextop&7).d);
        fpu_do_pop(emu);
        break;
    default:
        switch((nextop>>3)&7) {
        case 0: /* FILD ST0, Gw */
            GetEw(emu, &op2, nextop);
            tmp16s = (int16_t)op2->word[0];
            fpu_do_push(emu);
            if(usefloat)
                ST0.f = tmp16s;
            else
                ST0.d = tmp16s;
            break;
        case 1: /* FISTTP Ew, ST0 */
            GetEw(emu, &op2, nextop);
            if(usefloat)
                tmp16s = ST0.f;
            else
                tmp16s = ST0.d;
            op2->word[0] = (uint16_t)tmp16s;
            fpu_do_pop(emu);
            break;
        case 2: /* FIST Ew, ST0 */
            GetEw(emu, &op2, nextop);
            if(usefloat)
                tmp32s = ST0.f;
            else
                tmp32s = ST0.d; // Converting directly to short don't work correctly => it doesn't "saturate"
            if((tmp32s<-32768) || (tmp32s>32767))
                tmp16s=0x8000;
            else
                tmp16s = tmp32s;
            op2->word[0] = (uint16_t)tmp16s;
            break;
        case 3: /* FISTP Ew, ST0 */
            GetEw(emu, &op2, nextop);
            if(usefloat)
                tmp32s = ST0.f;
            else
                tmp32s = ST0.d; // Converting directly to short don't work correctly => it doesn't "saturate"
            if(tmp32s<-32768)
                tmp16s=-32768;
            else if(tmp32s>32767)
                tmp16s=32767;
            else
                tmp16s = tmp32s;
            op2->word[0] = (uint16_t)tmp16s;
            fpu_do_pop(emu);
            break;
        case 4: /* FBLD ST0, tbytes */
            GetEd(emu, &op2, nextop);
            fpu_do_push(emu);
            fpu_fbld(emu, (uint8_t*)op2);
            break;
        case 5: /* FILD ST0, Gq */
            GetEd(emu, &op2, nextop);
            tmp64s = *(int64_t*)&op2->dword[0];
            fpu_do_push(emu);
            if(usefloat)
                ST0.f = tmp64s;
            else
                ST0.d = tmp64s;
            STll(0).ll = tmp64s;
            STll(0).ref = ST0.ll;
            break;
        case 6: /* FBSTP tbytes, ST0 */
            GetEd(emu, &op2, nextop);
            fpu_fbst(emu, (uint8_t*)op2);
            fpu_do_pop(emu);
            break;
        case 7: /* FISTP i64 */
            GetEd(emu, &op1, nextop);
            if(STll(0).ref==ST(0).ll) {
                tmp64s = STll(0).ll;
            } else {
                if(isgreater(ST0.d, (double)(int64_t)0x7fffffffffffffffLL) || isless(ST0.d, (double)(int64_t)0x8000000000000000LL))
                    tmp64s = 0x8000000000000000LL;
                else
                    if(usefloat)
                        tmp64s = ST0.f;
                    else
                        tmp64s = ST0.d;
            }
            *(int64_t*)&op1->dword[0] = tmp64s;
            fpu_do_pop(emu);
            break;
        default:
            UnimpOpcode(emu);
        }
    }
}