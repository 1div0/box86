#if defined(GO) && defined(GOM) && defined(GO2) && defined(DATA) && defined(END)
// a64l
// abort
// abs
// accept   // Weak
// access   // Weak
// acct
// addmntent    // Weak
// addseverity
// adjtime  // Weak
// adjtimex // Weak
// __adjtimex
// advance  // Weak
// __aeabi_assert
// __aeabi_atexit
// __aeabi_errno_addr
// __aeabi_localeconv
// __aeabi_MB_CUR_MAX
// __aeabi_memclr
// __aeabi_memclr4
// __aeabi_memclr8
// __aeabi_memcpy
// __aeabi_memcpy4
// __aeabi_memcpy8
// __aeabi_memmove
// __aeabi_memmove4
// __aeabi_memmove8
// __aeabi_memset
// __aeabi_memset4
// __aeabi_memset8
DATAV(__after_morecore_hook, 4)
// alarm
// alphasort
// alphasort64
DATA(argp_err_exit_status, 4)
// argp_error   // Weak
// argp_failure // Weak
// argp_help    // Weak
// argp_parse   // Weak
// argp_program_bug_address // type B
// argp_program_version // type B
// argp_program_version_hook    // type B
// argp_state_help  // Weak
// argp_usage   // Weak
// argz_add // Weak
// argz_add_sep // Weak
// argz_append  // Weak
// __argz_count
// argz_count   // Weak
// argz_create  // Weak
// argz_create_sep  // Weak
// argz_delete
// argz_extract // Weak
// argz_insert  // Weak
// __argz_next
// argz_next    // Weak
// argz_replace // Weak
// __argz_stringify
// argz_stringify   // Weak
GO(asctime, pFp)
GOW(asctime_r, pFpp)
// asprintf // Weak
// __asprintf
// __asprintf_chk
// __assert
// __assert_fail
// __assert_perror_fail
// atof
// atoi
// atol
// atoll
// authdes_create
// authdes_getucred
// authdes_pk_create
// _authenticate
// authnone_create
// authunix_create
// authunix_create_default
// backtrace    // Weak
// __backtrace
// __backtrace_symbols
// backtrace_symbols    // Weak
// __backtrace_symbols_fd
// backtrace_symbols_fd // Weak
// basename
// bcmp // Weak
// bcopy
// bdflush
// bind // Weak
// bindresvport
// bindtextdomain   // Weak
// bind_textdomain_codeset  // Weak
// brk  // Weak
// __bsd_getpgrp
// bsd_signal   // Weak
// bsearch
GOW(btowc, iFi)
// bzero    // Weak
// __bzero
GOW(calloc, pFuu)
// callrpc
// canonicalize_file_name   // Weak
// capget
// capset
// catclose
// catgets
// catopen
// cbc_crypt
// cfgetispeed
// cfgetospeed
// cfmakeraw
// cfree    // Weak
// cfsetispeed
// cfsetospeed
// cfsetspeed
// chdir    // Weak
DATA(__check_rhosts_file, 4)
// chflags
// __chk_fail
// chmod    // Weak
// chown    // Weak
// chroot
// clearenv // Weak
GO(clearerr, vFp)
// clearerr_unlocked
// clnt_broadcast
// clnt_create
// clnt_pcreateerror
// clnt_perrno
// clnt_perror
// clntraw_create
// clnt_spcreateerror
// clnt_sperrno
// clnt_sperror
// clnttcp_create
// clntudp_bufcreate
// clntudp_create
// clntunix_create
GO(clock, uFv)
// clone    // Weak
// __clone
// close    // Weak
// __close  // Weak
// closedir // Weak
// closelog
// __cmsg_nxthdr
// confstr
// __confstr_chk
// connect  // Weak
// __connect    // Weak
// copysign // Weak
// copysignf    // Weak
// copysignl    // Weak
// creat    // Weak
// creat64
// create_module    // Weak
// ctermid
GO(ctime, pFp)
GO(ctime_r, pFpp)
// __ctype_b_loc
// __ctype_get_mb_cur_max   // Weak
// __ctype_tolower_loc
// __ctype_toupper_loc
// __curbrk // type B
// cuserid
GOM(__cxa_atexit, iFEp)
GOM(atexit, iFEp)           // just in case
// __cxa_finalize
// __cyg_profile_func_enter
// __cyg_profile_func_exit
// daemon
DATAV(daylight, 4)
// __daylight   // type B
// dcgettext    // Weak
// __dcgettext
// dcngettext   // Weak
// __default_morecore
// __default_rt_sa_restorer_v1
// __default_rt_sa_restorer_v2
// __default_sa_restorer_v1
// __default_sa_restorer_v2
// delete_module
// des_setparity
// dgettext // Weak
// __dgettext
//GO(difftime, dFuu)  // return a double. The double is in ST(0)!
// dirfd
// dirname
// div
// _dl_addr
// dl_iterate_phdr  // Weak
// _dl_mcount_wrapper
// _dl_mcount_wrapper_check
// _dl_open_hook    // type B
// _dl_starting_up // Weak
// _dl_sym
// _dl_vsym
// dngettext    // Weak
// dprintf
// __dprintf_chk
// drand48
// drand48_r
// dup  // Weak
// dup2 // Weak
// __dup2
// dup3
// duplocale    // Weak
// __duplocale
// dysize
// eaccess  // Weak
// ecb_crypt
// ecvt
// ecvt_r
// endaliasent
// endfsent
// endgrent
// endhostent
// endmntent    // Weak
// __endmntent
// endnetent
// endnetgrent
// endprotoent
// endpwent
// endrpcent
// endservent
// endspent
// endttyent
// endusershell
// endutent // Weak
// endutxent
DATAV(environ, 4)
DATAV(_environ, 4)
// __environ    // type B
// envz_add
// envz_entry
// envz_get
// envz_merge
// envz_remove
// envz_strip
// epoll_create
// epoll_create1
// epoll_ctl
// epoll_pwait
// epoll_wait
// erand48
// erand48_r    // Weak
// err
// errno    // type B
// __errno_location
// error    // Weak
// error_at_line    // Weak
// error_message_count  // type B
// error_one_per_line   // type B
// error_print_progname // type B
// errx
// ether_aton
// ether_aton_r
// ether_hostton
// ether_line
// ether_ntoa
// ether_ntoa_r
// ether_ntohost
// euidaccess   // Weak
// eventfd
// eventfd_read
// eventfd_write
// execl
// execle
// execlp
// execv
// execve   // Weak
// execvp
// exit
// _exit
// _Exit    // Weak
// faccessat
// fattach
// __fbufsize
// fchdir   // Weak
// fchflags
// fchmod   // Weak
// fchmodat
// fchown   // Weak
// fchownat
// fclose
// fcloseall    // Weak
// fcntl    // Weak
// __fcntl  // Weak
// fcvt
// fcvt_r
// fdatasync
// fdetach
// fdopen
// fdopendir    // Weak
GOW(feof, iFp)
// feof_unlocked
GOW(ferror, iFp)
// ferror_unlocked
// fexecve
// fflush   // Weak
// fflush_unlocked
// ffs
// __ffs
// ffsl // Weak
// ffsll
// fgetc    // Weak
// fgetc_unlocked   // Weak
// fgetgrent
// fgetgrent_r  // Weak
// fgetpos
// fgetpos64
// fgetpwent
// fgetpwent_r  // Weak
// fgets    // Weak
// __fgets_chk
// fgetspent
// fgetspent_r  // Weak
// fgets_unlocked
// __fgets_unlocked_chk
// fgetwc   // Weak
// fgetwc_unlocked  // Weak
// fgetws
// __fgetws_chk
// fgetws_unlocked
// __fgetws_unlocked_chk
// fgetxattr
GO(fileno, iFp)
// fileno_unlocked  // Weak
// finite   // Weak
// __finite
// finitef  // Weak
// __finitef
// finitel  // Weak
// __finitel
// __flbf
// flistxattr
// flock    // Weak
// flockfile    // Weak
// _flushlbf    // Weak
// fmemopen
// fmtmsg
// fnmatch
// fopen
// fopen64  // Weak
// fopencookie
// fork // Weak
// __fork
// __fortify_fail
// fpathconf    // Weak
// __fpending
// fprintf
// __fprintf_chk
// __fpu_control    // type B
// __fpurge
// fputc
// fputc_unlocked
// fputs    // Weak
// fputs_unlocked
// fputwc
// fputwc_unlocked
// fputws
// fputws_unlocked
GOW(fread, uFpuup)
// __freadable
// __fread_chk
// __freading
// fread_unlocked
// __fread_unlocked_chk
GO(free, vFp)
// freeaddrinfo
DATAV(__free_hook, 4)
// freeifaddrs
GOW(freelocale, vFp)
GO(__freelocale, vFp)
// fremovexattr
// freopen
// freopen64
// frexp    // Weak
// frexpf   // Weak
// frexpl   // Weak
// fscanf
// fseek
// fseeko
// fseeko64
// __fsetlocking
// fsetpos
// fsetpos64
// fsetxattr
// fstatfs  // Weak
// fstatfs64    // Weak
// fstatvfs
// fstatvfs64   // Weak
// fsync    // Weak
// ftell    // Weak
// ftello
// ftello64
// ftime
// ftok
// ftruncate    // Weak
// ftruncate64  // Weak
// ftrylockfile // Weak
// fts_children
// fts_close
// fts_open
// fts_read
// fts_set
// ftw
// ftw64
// funlockfile  // Weak
// futimens
// futimes  // Weak
// futimesat
// fwide
// fwprintf // Weak
// __fwprintf_chk
// __fwritable
GOW(fwrite, uFpuup)
// fwrite_unlocked
// __fwriting
// fwscanf
// __fxstat
// __fxstat64
// __fxstatat
// __fxstatat64
// __gai_sigqueue
// gai_strerror
// __gconv_get_alias_db
// __gconv_get_cache
// __gconv_get_modules_db
// gcvt
// getaddrinfo
// getaliasbyname
// getaliasbyname_r
// getaliasent
// getaliasent_r
// get_avphys_pages // Weak
// getc // Weak
// getchar
// getchar_unlocked
// getcontext
// getc_unlocked    // Weak
// get_current_dir_name
// getcwd   // Weak
// __getcwd_chk
GO(getdate, pFp)
// getdate_err  // type B
// getdate_r    // Weak
// getdelim // Weak
// __getdelim   // Weak
// getdirentries
// getdirentries64
// getdomainname
// __getdomainname_chk
// getdtablesize    // Weak
// getegid  // Weak
// getenv
// geteuid  // Weak
// getfsent
// getfsfile
// getfsspec
// getgid   // Weak
// getgrent
// getgrent_r
// getgrgid
// getgrgid_r
// getgrnam
// getgrnam_r
// getgrouplist
// getgroups    // Weak
// __getgroups_chk
// gethostbyaddr
// gethostbyaddr_r
// gethostbyname
// gethostbyname2
// gethostbyname2_r
// gethostbyname_r
// gethostent
// gethostent_r
// gethostid
// gethostname  // Weak
// __gethostname_chk
// getifaddrs
// getipv4sourcefilter
// getitimer    // Weak
// get_kernel_syms  // Weak
// getline  // Weak
// getloadavg
// getlogin
// getlogin_r
// __getlogin_r_chk
// getmntent
// __getmntent_r
// getmntent_r  // Weak
// getmsg
// get_myaddress
// getnameinfo
// getnetbyaddr
// getnetbyaddr_r
// getnetbyname
// getnetbyname_r
// getnetent
// getnetent_r
// getnetgrent
// getnetgrent_r    // Weak
// getnetname
// get_nprocs   // Weak
// get_nprocs_conf  // Weak
// getopt
// getopt_long
// getopt_long_only
// getpagesize  // Weak
// __getpagesize
// getpass
// getpeername  // Weak
// getpgid  // Weak
// __getpgid
// getpgrp
// get_phys_pages   // Weak
// getpid
// __getpid
// getpmsg
// getppid  // Weak
// getpriority
// getprotobyname
// getprotobyname_r
// getprotobynumber
// getprotobynumber_r
// getprotoent
// getprotoent_r
// getpt    // Weak
// getpublickey
// getpw    // Weak
// getpwent
// getpwent_r
// getpwnam
// getpwnam_r
// getpwuid
// getpwuid_r
// getresgid    // Weak
// getresuid    // Weak
// getrlimit
// getrlimit64
// getrpcbyname
// getrpcbyname_r
// getrpcbynumber
// getrpcbynumber_r
// getrpcent
// getrpcent_r
// getrpcport
// getrusage    // Weak
// gets // Weak
// __gets_chk
// getsecretkey
// getservbyname
// getservbyname_r
// getservbyport
// getservbyport_r
// getservent
// getservent_r
// getsid
// getsockname  // Weak
// getsockopt   // Weak
// getsourcefilter
// getspent
// getspent_r
// getspnam
// getspnam_r
// getsubopt
// gettext  // Weak
// gettimeofday // Weak
// __gettimeofday
// getttyent
// getttynam
// getuid   // Weak
// getusershell
// getutent // Weak
// getutent_r   // Weak
// getutid  // Weak
// getutid_r    // Weak
// getutline    // Weak
// getutline_r  // Weak
// getutmp
// getutmpx
// getutxent
// getutxid
// getutxline
// getw
// getwc    // Weak
// getwchar
// getwchar_unlocked
// getwc_unlocked   // Weak
// getwd
// __getwd_chk
// getxattr
// glob
// glob64
// globfree
// globfree64
// glob_pattern_p   // Weak
GO(gmtime, pFp)
// __gmtime_r
GOW(gmtime_r, pFpp)
// gnu_dev_major
// gnu_dev_makedev
// gnu_dev_minor
// gnu_get_libc_release // Weak
// gnu_get_libc_version // Weak
// __gnu_mcount_nc
// __gnu_Unwind_Find_exidx
// grantpt
// group_member // Weak
// gsignal  // Weak
// gtty
// hasmntopt    // Weak
// hcreate
// hcreate_r
// hdestroy // Weak
// hdestroy_r
DATA(h_errlist, 4)
// h_errno  // type B
// __h_errno_location
// herror
// h_nerr   // type R
// host2netname
// hsearch
// hsearch_r
// hstrerror
// htonl
// htons
// iconv
// iconv_close
// iconv_open
// if_freenameindex
// if_indextoname
// if_nameindex
// if_nametoindex
// imaxabs  // Weak
// imaxdiv  // Weak
// in6addr_any  // type R
// in6addr_loopback // type R
// inb  // Weak
// index    // Weak
// inet6_opt_append
// inet6_opt_find
// inet6_opt_finish
// inet6_opt_get_val
// inet6_opt_init
// inet6_option_alloc
// inet6_option_append
// inet6_option_find
// inet6_option_init
// inet6_option_next
// inet6_option_space
// inet6_opt_next
// inet6_opt_set_val
// inet6_rth_add
// inet6_rth_getaddr
// inet6_rth_init
// inet6_rth_reverse
// inet6_rth_segments
// inet6_rth_space
// inet_addr
// inet_aton    // Weak
// inet_lnaof
// inet_makeaddr
// inet_netof
// inet_network
// inet_nsap_addr
// inet_nsap_ntoa
// inet_ntoa
// inet_ntop
// inet_pton
// initgroups
// init_module
// initstate    // Weak
// initstate_r  // Weak
// inl  // Weak
// innetgr
// inotify_add_watch
// inotify_init
// inotify_init1
// inotify_rm_watch
// insque
// __internal_endnetgrent
// __internal_getnetgrent_r
// __internal_setnetgrent
// inw  // Weak
DATA(_IO_2_1_stderr_, 4)
DATA(_IO_2_1_stdin_, 4)
DATA(_IO_2_1_stdout_, 4)
// _IO_adjust_column
// _IO_adjust_wcolumn
// ioctl    // Weak
// _IO_default_doallocate
// _IO_default_finish
// _IO_default_pbackfail
// _IO_default_uflow
// _IO_default_xsgetn
// _IO_default_xsputn
// _IO_doallocbuf
// _IO_do_write
// _IO_fclose
// _IO_fdopen
// _IO_feof
// _IO_ferror
// _IO_fflush
// _IO_fgetpos
// _IO_fgetpos64
// _IO_fgets
// _IO_file_attach
// _IO_file_close
// _IO_file_close_it
// _IO_file_doallocate
// _IO_file_finish
// _IO_file_fopen
// _IO_file_init
DATA(_IO_file_jumps, 4)
// _IO_file_open
// _IO_file_overflow
// _IO_file_read
// _IO_file_seek
// _IO_file_seekoff
// _IO_file_setbuf
// _IO_file_stat
// _IO_file_sync
// _IO_file_underflow
// _IO_file_write
// _IO_file_xsputn
// _IO_flockfile
// _IO_flush_all
// _IO_flush_all_linebuffered
// _IO_fopen
// _IO_fprintf  // Weak
// _IO_fputs
// _IO_fread
// _IO_free_backup_area
// _IO_free_wbackup_area
// _IO_fsetpos
// _IO_fsetpos64
// _IO_ftell
// _IO_ftrylockfile
// _IO_funlockfile
// _IO_fwrite
// _IO_getc
// _IO_getline
// _IO_getline_info
// _IO_gets
// _IO_init
// _IO_init_marker
// _IO_init_wmarker
// _IO_iter_begin
// _IO_iter_end
// _IO_iter_file
// _IO_iter_next
// _IO_least_wmarker
// _IO_link_in
DATA(_IO_list_all, 4)
// _IO_list_lock
// _IO_list_resetlock
// _IO_list_unlock
// _IO_marker_delta
// _IO_marker_difference
// _IO_padn
// _IO_peekc_locked
// ioperm   // Weak
// iopl // Weak
// _IO_popen
// _IO_printf
// _IO_proc_close
// _IO_proc_open
// _IO_putc
// _IO_puts
// _IO_remove_marker
// _IO_seekmark
// _IO_seekoff
// _IO_seekpos
// _IO_seekwmark
// _IO_setb
// _IO_setbuffer
// _IO_setvbuf
// _IO_sgetn
// _IO_sprintf
// _IO_sputbackc
// _IO_sputbackwc
// _IO_sscanf
// _IO_str_init_readonly
// _IO_str_init_static
// _IO_str_overflow
// _IO_str_pbackfail
// _IO_str_seekoff
// _IO_str_underflow
// _IO_sungetc
// _IO_sungetwc
// _IO_switch_to_get_mode
// _IO_switch_to_main_wget_area
// _IO_switch_to_wbackup_area
// _IO_switch_to_wget_mode
// _IO_ungetc
// _IO_un_link
// _IO_unsave_markers
// _IO_unsave_wmarkers
// _IO_vfprintf
// _IO_vfscanf
// _IO_vsprintf
// _IO_wdefault_doallocate
// _IO_wdefault_finish
// _IO_wdefault_pbackfail
// _IO_wdefault_uflow
// _IO_wdefault_xsgetn
// _IO_wdefault_xsputn
// _IO_wdoallocbuf
// _IO_wdo_write
DATA(_IO_wfile_jumps, 4)
// _IO_wfile_overflow
// _IO_wfile_seekoff
// _IO_wfile_sync
// _IO_wfile_underflow
// _IO_wfile_xsputn
// _IO_wmarker_delta
// _IO_wsetb
// iruserok
// iruserok_af
// isalnum
// __isalnum_l
// isalnum_l    // Weak
// isalpha
// __isalpha_l
// isalpha_l    // Weak
// isascii
// __isascii_l  // Weak
// isastream
// isatty   // Weak
// isblank
// __isblank_l
// isblank_l    // Weak
// iscntrl
// __iscntrl_l
// iscntrl_l    // Weak
// isctype  // Weak
// __isctype
// isdigit
// __isdigit_l
// isdigit_l    // Weak
// isfdtype
// isgraph
// __isgraph_l
// isgraph_l    // Weak
// isinf    // Weak
// __isinf
// isinff   // Weak
// __isinff
// isinfl   // Weak
// __isinfl
// islower
// __islower_l
// islower_l    // Weak
// isnan    // Weak
// __isnan
// isnanf   // Weak
// __isnanf
// isnanl   // Weak
// __isnanl
// __isoc99_fscanf
// __isoc99_fwscanf
// __isoc99_scanf
// __isoc99_sscanf
// __isoc99_swscanf
// __isoc99_vfscanf
// __isoc99_vfwscanf
// __isoc99_vscanf
// __isoc99_vsscanf
// __isoc99_vswscanf
// __isoc99_vwscanf
// __isoc99_wscanf
// isprint
// __isprint_l
// isprint_l    // Weak
// ispunct
// __ispunct_l
// ispunct_l    // Weak
// isspace
// __isspace_l
// isspace_l    // Weak
// isupper
// __isupper_l
// isupper_l    // Weak
// iswalnum // Weak
// __iswalnum_l
// iswalnum_l   // Weak
// iswalpha // Weak
// __iswalpha_l
// iswalpha_l   // Weak
// iswblank // Weak
// __iswblank_l
// iswblank_l   // Weak
// iswcntrl // Weak
// __iswcntrl_l
// iswcntrl_l   // Weak
// iswctype // Weak
// __iswctype
// __iswctype_l
// iswctype_l   // Weak
// iswdigit // Weak
// __iswdigit_l
// iswdigit_l   // Weak
// iswgraph // Weak
// __iswgraph_l
// iswgraph_l   // Weak
// iswlower // Weak
// __iswlower_l
// iswlower_l   // Weak
// iswprint // Weak
// __iswprint_l
// iswprint_l   // Weak
// iswpunct // Weak
// __iswpunct_l
// iswpunct_l   // Weak
// iswspace // Weak
// __iswspace_l
// iswspace_l   // Weak
// iswupper // Weak
// __iswupper_l
// iswupper_l   // Weak
// iswxdigit    // Weak
// __iswxdigit_l
// iswxdigit_l  // Weak
// isxdigit
// __isxdigit_l
// isxdigit_l   // Weak
// _itoa_lower_digits   // type R
// __ivaliduser
// jrand48
// jrand48_r    // Weak
// key_decryptsession
// key_decryptsession_pk
// __key_decryptsession_pk_LOCAL    // type B
// key_encryptsession
// key_encryptsession_pk
// __key_encryptsession_pk_LOCAL    // type B
// key_gendes
// __key_gendes_LOCAL   // type B
// key_get_conv
// key_secretkey_is_set
// key_setnet
// key_setsecret
// kill // Weak
// killpg
// klogctl
// l64a
// labs
// lchmod
// lchown   // Weak
// lckpwdf  // Weak
// lcong48
// lcong48_r    // Weak
// ldexp    // Weak
// ldexpf   // Weak
// ldexpl   // Weak
// ldiv
// lfind
// lgetxattr
// __libc_allocate_rtsig
// __libc_allocate_rtsig_private
// __libc_calloc
// __libc_clntudp_bufcreate
// __libc_current_sigrtmax
// __libc_current_sigrtmax_private
// __libc_current_sigrtmin
// __libc_current_sigrtmin_private
// __libc_dlclose
// __libc_dl_error_tsd
// __libc_dlopen_mode
// __libc_dlsym
// __libc_fatal
// __libc_fork
// __libc_free
// __libc_freeres
// __libc_init_first
// _libc_intl_domainname    // type R
// __libc_longjmp
// __libc_mallinfo
// __libc_malloc
// __libc_mallopt
// __libc_memalign
// __libc_pthread_init
// __libc_pvalloc
// __libc_pwrite
// __libc_realloc
// __libc_sa_len
// __libc_siglongjmp
GOM(__libc_start_main, iFEpippppp)
// __libc_system
// __libc_thread_freeres
// __libc_valloc
// link // Weak
// linkat
// listen   // Weak
// listxattr
// llabs
// lldiv
// llistxattr
// llseek   // Weak
// loc1 // type B
// loc2 // type B
// localeconv
GO(localtime, pFp)
GOW(localtime_r, pFpp)
// lockf
// lockf64
// locs // type B
// longjmp  // Weak
// _longjmp // Weak
// lrand48
// lrand48_r
// lremovexattr
// lsearch
// lseek    // Weak
// __lseek  // Weak
// lseek64  // Weak
// lsetxattr
// lutimes
// __lxstat
// __lxstat64
// madvise
// makecontext
// mallinfo // Weak
GO(malloc, pFu)
// malloc_get_state // Weak
DATAV(__malloc_hook, 4)
DATAV(__malloc_initialize_hook, 4)
// malloc_set_state // Weak
// malloc_stats // Weak
// malloc_trim  // Weak
// malloc_usable_size   // Weak
// mallopt  // Weak
// mallwatch    // type B
// mblen
// mbrlen   // Weak
// __mbrlen
// mbrtowc  // Weak
// __mbrtowc
// mbsinit  // Weak
// mbsnrtowcs   // Weak
// __mbsnrtowcs_chk
// mbsrtowcs    // Weak
// __mbsrtowcs_chk
// mbstowcs
// __mbstowcs_chk
// mbtowc
// mcheck
// mcheck_check_all
// mcheck_pedantic
// _mcleanup
// mcount   // Weak
// _mcount
// memalign // Weak
DATAV(__memalign_hook, 4)
// memccpy  // Weak
// memchr
// memcmp
GO(memcpy, pFppu)
GO(__memcpy_chk, pFppuu)
// memfrob
// memmem
GO(memmove, pFppu)
GO(__memmove_chk, pFppuu)
// mempcpy
// __mempcpy
// __mempcpy_chk
// __mempcpy_small
// memrchr  // Weak
GO(memset, pFpiu)
// __memset_chk
// mincore
// mkdir    // Weak
// mkdirat
// mkdtemp
// mkfifo
// mkfifoat
// mkostemp
// mkostemp64
// mkstemp
// mkstemp64
// mktemp
GO(mktime, uFp)
// mlock
// mlockall
// mmap // Weak
// mmap64   // Weak
// modf // Weak
// modff    // Weak
// modfl    // Weak
// moncontrol   // Weak
// monstartup   // Weak
// __monstartup
DATA(__morecore, 4)
// mount    // Weak
// mprobe
// mprotect // Weak
// mrand48
// mrand48_r
// mremap   // Weak
// msgctl
// msgget   // Weak
// msgrcv   // Weak
// msgsnd   // Weak
// msync    // Weak
// mtrace
// munlock
// munlockall
// munmap   // Weak
// muntrace
GOW(nanosleep, iFpp)
// __nanosleep  // Weak
// netname2host
// netname2user
GOW(newlocale, pFipp)
GO(__newlocale, pFipp)
// nfsservctl
// nftw
// nftw64
// ngettext // Weak
// nice
// _nl_default_dirname  // type R
// _nl_domain_bindings  // type B
// nl_langinfo
// __nl_langinfo_l
// nl_langinfo_l    // Weak
// _nl_msg_cat_cntr // type B
// nrand48
// nrand48_r    // Weak
// __nss_configure_lookup
// __nss_database_lookup
// __nss_disable_nscd
// _nss_files_parse_grent
// _nss_files_parse_pwent
// _nss_files_parse_spent
// __nss_group_lookup
// __nss_group_lookup2
// __nss_hostname_digits_dots
// __nss_hosts_lookup
// __nss_hosts_lookup2
// __nss_lookup_function
// __nss_next
// __nss_next2
// __nss_passwd_lookup
// __nss_passwd_lookup2
// __nss_services_lookup2
// ntohl    // Weak
// ntohs    // Weak
// ntp_adjtime  // Weak
// ntp_gettime
// _null_auth   // type B
// _obstack_allocated_p
DATA(obstack_alloc_failed_handler, 4)
// _obstack_begin
// _obstack_begin_1
DATA(obstack_exit_failure, 4)
// _obstack_free
// obstack_free
// _obstack_memory_used
// _obstack_newchunk
// obstack_printf   // Weak
// __obstack_printf_chk
// obstack_vprintf  // Weak
// __obstack_vprintf_chk
// on_exit  // Weak
GO(open, iFpiuuuu) // Weak  // open use vararg, cheating here putting arbitrary number of stuff in the stack
// __open   // Weak
// __open_2
// open64   // Weak
// __open64 // Weak
// __open64_2
// openat   // Weak
// __openat_2
// openat64 // Weak
// __openat64_2
// __open_catalog
// opendir  // Weak
// openlog
// open_memstream
// open_wmemstream
// optarg   // type B
DATA(opterr, 4)
DATA(optind, 4)
DATA(optopt, 4)
// outb // Weak
// outl // Weak
// outw // Weak
// __overflow
// parse_printf_format
// passwd2des
// pathconf // Weak
// pause    // Weak
// pclose
// perror
// personality  // Weak
// pipe // Weak
// __pipe
// pipe2    // Weak
// pivot_root
// pmap_getmaps
// pmap_getport
// pmap_rmtcall
// pmap_set
// pmap_unset
// poll // Weak
// __poll
// popen
// posix_fadvise
// posix_fadvise64
// posix_fallocate
// posix_fallocate64
// posix_madvise
// posix_memalign   // Weak
// posix_openpt // Weak
// posix_spawn
// posix_spawnattr_destroy
// posix_spawnattr_getflags
// posix_spawnattr_getpgroup
// posix_spawnattr_getschedparam
// posix_spawnattr_getschedpolicy
// posix_spawnattr_getsigdefault
// posix_spawnattr_getsigmask
// posix_spawnattr_init
// posix_spawnattr_setflags
// posix_spawnattr_setpgroup
// posix_spawnattr_setschedparam
// posix_spawnattr_setschedpolicy
// posix_spawnattr_setsigdefault
// posix_spawnattr_setsigmask
// posix_spawn_file_actions_addclose
// posix_spawn_file_actions_adddup2
// posix_spawn_file_actions_addopen
// posix_spawn_file_actions_destroy
// posix_spawn_file_actions_init
// posix_spawnp
// ppoll
// prctl    // Weak
// pread    // Weak
// pread64  // Weak
// __pread64    // Weak
// __pread64_chk
// __pread_chk
GO2(printf, iFopV, vfprintf)
GO2(__printf_chk, iFvopV, vfprintf)
// __printf_fp
// printf_size
// printf_size_info
// profil   // Weak
// __profile_frequency
DATA(__progname, 4)
DATA(__progname_full, 4)
DATAV(program_invocation_name, 4)
DATAV(program_invocation_short_name, 4)
// pselect  // Weak
// psignal
// pthread_attr_destroy
// pthread_attr_getdetachstate
// pthread_attr_getinheritsched
// pthread_attr_getschedparam
// pthread_attr_getschedpolicy
// pthread_attr_getscope
// pthread_attr_init
// pthread_attr_setdetachstate
// pthread_attr_setinheritsched
// pthread_attr_setschedparam
// pthread_attr_setschedpolicy
// pthread_attr_setscope
// pthread_condattr_destroy
// pthread_condattr_init
// pthread_cond_broadcast
// pthread_cond_destroy
// pthread_cond_init
// pthread_cond_signal
// pthread_cond_timedwait
// pthread_cond_wait
// pthread_equal
// pthread_exit
// pthread_getschedparam
// pthread_mutex_destroy
// pthread_mutex_init
// pthread_mutex_lock
// pthread_mutex_unlock
// pthread_self
// pthread_setcancelstate   // Weak
// pthread_setcanceltype
// pthread_setschedparam
// ptrace
// ptsname
// ptsname_r    // Weak
// __ptsname_r_chk
// putc // Weak
GO(putchar, iFi)
// putchar_unlocked
// putc_unlocked
// putenv
// putgrent
// putmsg
// putpmsg
// putpwent
GOW(puts, iFp)
// putspent
// pututline    // Weak
// pututxline
// putw
// putwc
// putwchar
// putwchar_unlocked
// putwc_unlocked
// pvalloc  // Weak
// pwrite   // Weak
// pwrite64 // Weak
// __pwrite64   // Weak
// qecvt
// qecvt_r
// qfcvt
// qfcvt_r
// qgcvt
// qsort
// qsort_r
// query_module // Weak
// quotactl
// raise
// rand
// random   // Weak
// random_r // Weak
// rand_r
// rawmemchr    // Weak
// __rawmemchr
// rcmd
// rcmd_af
// __rcmd_errstr    // type B
// read // Weak
// __read   // Weak
// readahead    // Weak
// __read_chk
// readdir  // Weak
// readdir64
// readdir64_r
// readdir_r    // Weak
// readlink // Weak
// readlinkat
// __readlinkat_chk
// __readlink_chk
// readv    // Weak
// realloc
DATAV(__realloc_hook, 4)
// realpath
// __realpath_chk
// reboot
// re_comp  // Weak
// re_compile_fastmap   // Weak
// re_compile_pattern   // Weak
// recv // Weak
// __recv_chk
// recvfrom // Weak
// __recvfrom_chk
// recvmsg  // Weak
// re_exec  // Weak
// regcomp  // Weak
// regerror // Weak
// regexec
// regfree  // Weak
// __register_atfork
// register_printf_function // Weak
// registerrpc
// remap_file_pages // Weak
// re_match // Weak
// re_match_2   // Weak
// remove
// removexattr
// remque
// rename
// renameat
// _res // type B
// re_search    // Weak
// re_search_2  // Weak
// re_set_registers // Weak
// re_set_syntax    // Weak
// _res_hconf   // type B
// __res_iclose
// __res_init
// __res_maybe_init
// __res_nclose
// __res_ninit
DATA(__resp, 4)
// __res_randomid
// __res_state
// re_syntax_options    // type B
// revoke
// rewind
// rewinddir
// rexec
// rexec_af
// rexecoptions // type B
// rindex   // Weak
// rmdir    // Weak
// rpc_createerr    // type B
// _rpc_dtablesize
// __rpc_thread_createerr
// __rpc_thread_svc_fdset
// __rpc_thread_svc_max_pollfd
// __rpc_thread_svc_pollfd
// rpmatch
// rresvport
// rresvport_af
// rtime
// ruserok
// ruserok_af
// ruserpass
// sbrk // Weak
// __sbrk
// scalbn   // Weak
// scalbnf  // Weak
// scalbnl  // Weak
// scandir
// scandir64
// scanf
// __sched_cpualloc
// __sched_cpucount
// __sched_cpufree
// sched_getaffinity
// sched_getcpu
// __sched_getparam
// sched_getparam   // Weak
// __sched_get_priority_max
// sched_get_priority_max   // Weak
// __sched_get_priority_min
// sched_get_priority_min   // Weak
// __sched_getscheduler
// sched_getscheduler   // Weak
// sched_rr_get_interval    // Weak
// sched_setaffinity
// sched_setparam   // Weak
// __sched_setscheduler
// sched_setscheduler   // Weak
// __sched_yield
// sched_yield  // Weak
// __secure_getenv
// seed48
// seed48_r // Weak
// seekdir
// select   // Weak
// __select
// semctl
// semget   // Weak
// semop    // Weak
// semtimedop
// send // Weak
// __send   // Weak
// sendfile
// sendfile64
// sendmsg  // Weak
// sendto   // Weak
// setaliasent
// setbuf
// setbuffer    // Weak
// setcontext
// setdomainname
// setegid
// setenv   // Weak
// _seterr_reply
// seteuid
// setfsent
// setfsgid
// setfsuid
// setgid   // Weak
// setgrent
// setgroups
// sethostent
// sethostid
// sethostname
// setipv4sourcefilter
// setitimer    // Weak
// setjmp
// _setjmp
// setlinebuf
// setlocale
// setlogin
// setlogmask
// setmntent    // Weak
// __setmntent
// setnetent
// setnetgrent
// setpgid  // Weak
// __setpgid
// setpgrp
// setpriority
// setprotoent
// setpwent
// setregid // Weak
// setresgid    // Weak
// setresuid    // Weak
// setreuid // Weak
// setrlimit
// setrlimit64
// setrpcent
// setservent
// setsid   // Weak
// setsockopt   // Weak
// setsourcefilter
// setspent
// setstate // Weak
// setstate_r   // Weak
// settimeofday // Weak
// setttyent
// setuid   // Weak
// setusershell
// setutent // Weak
// setutxent
// setvbuf  // Weak
// setxattr
// sgetspent
// sgetspent_r  // Weak
// shmat    // Weak
// shmctl
// shmdt    // Weak
// shmget   // Weak
// shutdown // Weak
GOM(sigaction, iFEipp)    // Weak
GOM(__sigaction, iFEipp)  // Weak
// sigaddset
// __sigaddset
// sigaltstack  // Weak
// sigandset
// sigblock // Weak
// sigdelset
// __sigdelset
// sigemptyset
// sigfillset
// siggetmask
// sighold
// sigignore
// siginterrupt
// sigisemptyset
// sigismember
// __sigismember
// siglongjmp   // Weak
GOM(signal, pFip)   // Weak
// signalfd
// __signbit
// __signbitf
// sigorset
// sigpause // Weak
// __sigpause
// sigpending
// sigprocmask  // Weak
// sigqueue // Weak
// sigrelse
// sigreturn    // Weak
// sigset
// __sigsetjmp
// sigsetmask   // Weak
// sigstack
// sigsuspend   // Weak
// __sigsuspend
// sigtimedwait // Weak
// sigvec   // Weak
// sigwait  // Weak
// sigwaitinfo  // Weak
// sleep    // Weak
// snprintf // Weak
// __snprintf_chk
// sockatmark
// socket   // Weak
// socketpair   // Weak
// splice
// sprintf
// __sprintf_chk
// sprofil  // Weak
// srand    // Weak
// srand48
// srand48_r    // Weak
// srandom  // Weak
// srandom_r    // Weak
// sscanf
// ssignal  // Weak
// sstk
GOM(__stack_chk_fail, vFE)
// statfs   // Weak
// __statfs
// statfs64 // Weak
// statvfs
// statvfs64    // Weak
DATA(stderr, 4)
DATA(stdin, 4)
DATA(stdout, 4)
// step // Weak
// stime
// stpcpy
// __stpcpy
// __stpcpy_chk
// __stpcpy_small
// stpncpy  // Weak
// __stpncpy
// __stpncpy_chk
// strcasecmp   // Weak
// __strcasecmp
// __strcasecmp_l
// strcasecmp_l // Weak
// strcasestr   // Weak
// __strcasestr
GO(strcat, pFpp)
// __strcat_chk
// strchr
// strchrnul    // Weak
GO(strcmp, iFpp)
// strcoll
// __strcoll_l
// strcoll_l    // Weak
// strcpy
// __strcpy_chk
// __strcpy_small
// strcspn
// __strcspn_c1
// __strcspn_c2
// __strcspn_c3
// strdup   // Weak
// __strdup
GO(strerror, pFv)
// strerror_l
// __strerror_r
// strerror_r   // Weak
// strfmon
// __strfmon_l
// strfmon_l    // Weak
// strfry
GO(strftime, uFpupp)
// __strftime_l
// strftime_l   // Weak
GO(strlen, uFp)
// strncasecmp  // Weak
// __strncasecmp_l
// strncasecmp_l    // Weak
GO(strncat, pFppu)
// __strncat_chk
// strncmp
// strncpy
// __strncpy_chk
// strndup  // Weak
// __strndup
// strnlen
// strpbrk
// __strpbrk_c2
// __strpbrk_c3
GO(strptime, pFppp)
// strptime_l   // Weak
// strrchr
// strsep   // Weak
// __strsep_1c
// __strsep_2c
// __strsep_3c
// __strsep_g
// strsignal
// strspn
// __strspn_c1
// __strspn_c2
// __strspn_c3
// strstr
// strtod
// __strtod_internal
// __strtod_l
GOW(strtod_l, dFppu)
// strtof
// __strtof_internal
// __strtof_l
GOW(strtof_l, fFppu)
// strtoimax
// strtok
// __strtok_r
// strtok_r // Weak
// __strtok_r_1c
GO(strtol, iFppi)
// strtold
// __strtold_internal
// __strtold_l
GOW(strtold_l, DFppu)
// __strtol_internal
// strtoll
// __strtol_l
// strtol_l // Weak
// __strtoll_internal
// __strtoll_l
// strtoll_l    // Weak
// strtoq   // Weak
// strtoul
// __strtoul_internal
// strtoull
// __strtoul_l
// strtoul_l    // Weak
// __strtoull_internal
// __strtoull_l
// strtoull_l   // Weak
// strtoumax
// strtouq  // Weak
// strverscmp   // Weak
// __strverscmp
// strxfrm
// __strxfrm_l
// strxfrm_l    // Weak
// stty
// svcauthdes_stats // type B
// svcerr_auth
// svcerr_decode
// svcerr_noproc
// svcerr_noprog
// svcerr_progvers
// svcerr_systemerr
// svcerr_weakauth
// svc_exit
// svcfd_create
// svc_fdset    // type B
// svc_getreq
// svc_getreq_common
// svc_getreq_poll
// svc_getreqset
// svc_max_pollfd   // type B
// svc_pollfd   // type B
// svcraw_create
// svc_register
// svc_run
// svc_sendreply
// svctcp_create
// svcudp_bufcreate
// svcudp_create
// svcudp_enablecache
// svcunix_create
// svcunixfd_create
// svc_unregister
// swab
// swapcontext
// swapoff  // Weak
// swapon   // Weak
// swprintf
// __swprintf_chk
// swscanf
// symlink  // Weak
// symlinkat
// sync
// sync_file_range
GOM(syscall, uFE)
// sysconf  // Weak
// __sysconf
// sysctl   // Weak
// __sysctl
DATA(_sys_errlist, 4)
DATA(sys_errlist, 4)
// sysinfo
// syslog
// __syslog_chk
// _sys_nerr    // type R
// sys_nerr // type R
DATA(sys_sigabbrev, 4)
DATA(_sys_siglist, 4)
DATA(sys_siglist, 4)
// system   // Weak
GOM(__sysv_signal, pFip)
GOM(sysv_signal, pFip)  // Weak
// tcdrain  // Weak
// tcflow
// tcflush
// tcgetattr    // Weak
// tcgetpgrp
// tcgetsid
// tcsendbreak
// tcsetattr
// tcsetpgrp
// tdelete  // Weak
// tdestroy // Weak
// tee
// telldir
// tempnam
// textdomain   // Weak
// tfind    // Weak
GO(time, uFp)
// timegm
// timelocal    // Weak
// timerfd_create
// timerfd_gettime
// timerfd_settime
// times    // Weak
DATAV(timezone, 4)
// __timezone   // type B
// tmpfile
// tmpfile64
// tmpnam
// tmpnam_r
// toascii
// __toascii_l  // Weak
// tolower
// _tolower
// __tolower_l
// tolower_l    // Weak
// toupper
// _toupper
// __toupper_l
// toupper_l    // Weak
// towctrans    // Weak
// __towctrans
// __towctrans_l
// towctrans_l  // Weak
// towlower
// __towlower_l
// towlower_l   // Weak
// towupper
// __towupper_l
// towupper_l   // Weak
// tr_break
// truncate // Weak
// truncate64
// tsearch  // Weak
// ttyname
// ttyname_r    // Weak
// __ttyname_r_chk
// ttyslot
// twalk    // Weak
DATAV(tzname, 4)
DATA(__tzname, 4)
GOW(tzset, vFv)
// ualarm
// __uflow
// ulckpwdf // Weak
// ulimit   // Weak
// umask    // Weak
// umount   // Weak
// umount2  // Weak
// uname    // Weak
// __underflow
// ungetc   // Weak
// ungetwc
// unlink   // Weak
// unlinkat
// unlockpt
// unsetenv // Weak
// unshare
// updwtmp  // Weak
// updwtmpx
// uselib
GOW(uselocale, pFp)
GO(__uselocale, pFp)
// user2netname
// usleep
// ustat
// utime
// utimensat
// utimes   // Weak
// utmpname // Weak
// utmpxname
// valloc   // Weak
// vasprintf    // Weak
// __vasprintf_chk
// vdprintf // Weak
// __vdprintf_chk
// verr
// verrx
// versionsort
// versionsort64
// vfork    // Weak
// __vfork
// vfprintf
// __vfprintf_chk
// vfscanf  // Weak
// __vfscanf
// vfwprintf    // Weak
// __vfwprintf_chk
// vfwscanf // Weak
// vhangup
// vlimit
// vmsplice
// vprintf
// __vprintf_chk
// vscanf   // Weak
// vsnprintf    // Weak
// __vsnprintf  // Weak
// __vsnprintf_chk
// vsprintf // Weak
// __vsprintf_chk
// vsscanf  // Weak
// __vsscanf    // Weak
// vswprintf    // Weak
// __vswprintf_chk
// vswscanf
// vsyslog
// __vsyslog_chk
// vtimes
// vwarn
// vwarnx
// vwprintf
// __vwprintf_chk
// vwscanf
// wait // Weak
// __wait   // Weak
// wait3    // Weak
// wait4    // Weak
// waitid   // Weak
// waitpid  // Weak
// __waitpid    // Weak
// warn
// warnx
// wcpcpy   // Weak
// __wcpcpy_chk
// wcpncpy  // Weak
// __wcpncpy_chk
// wcrtomb  // Weak
// __wcrtomb_chk
// wcscasecmp   // Weak
// __wcscasecmp_l
// wcscasecmp_l // Weak
// wcscat   // Weak
// __wcscat_chk
// wcschr
// wcschrnul    // Weak
// wcscmp
// wcscoll  // Weak
// __wcscoll_l
// wcscoll_l    // Weak
// wcscpy
// __wcscpy_chk
// wcscspn
// wcsdup
GO(wcsftime, uFpupp)
GO(__wcsftime_l, uFpuppu)
// wcsftime_l   // Weak
// wcslen   // Weak
// wcsncasecmp  // Weak
// __wcsncasecmp_l
// wcsncasecmp_l    // Weak
// wcsncat
// __wcsncat_chk
// wcsncmp
// wcsncpy  // Weak
// __wcsncpy_chk
// wcsnlen  // Weak
// wcsnrtombs   // Weak
// __wcsnrtombs_chk
// wcspbrk
// wcsrchr
// wcsrtombs    // Weak
// __wcsrtombs_chk
// wcsspn
// wcsstr
// wcstod
// __wcstod_internal
// __wcstod_l
// wcstod_l // Weak
// wcstof
// __wcstof_internal
// __wcstof_l
// wcstof_l // Weak
// wcstoimax
// wcstok
// wcstol
// wcstold
// __wcstold_internal
// __wcstold_l
// wcstold_l    // Weak
// __wcstol_internal
// wcstoll
// __wcstol_l
// wcstol_l // Weak
// __wcstoll_internal
// __wcstoll_l
// wcstoll_l    // Weak
// wcstombs
// __wcstombs_chk
// wcstoq   // Weak
// wcstoul
// __wcstoul_internal
// wcstoull
// __wcstoul_l
// wcstoul_l    // Weak
// __wcstoull_internal
// __wcstoull_l
// wcstoull_l   // Weak
// wcstoumax
// wcstouq  // Weak
// wcswcs   // Weak
// wcswidth
// wcsxfrm
// __wcsxfrm_l
// wcsxfrm_l    // Weak
GO(wctob, iFi)
GO(wctomb, iFpi)
// __wctomb_chk
// wctrans  // Weak
// __wctrans_l
// wctrans_l    // Weak
// wctype   // Weak
GO(__wctype_l, uFpp)
GOW(wctype_l, uFpp)
// wcwidth
// wmemchr
// wmemcmp
// wmemcpy  // Weak
GO(__wmemcpy_chk, pFppuu)
// wmemmove // Weak
// __wmemmove_chk
// wmempcpy // Weak
// __wmempcpy_chk
// wmemset
// __wmemset_chk
// wordexp
// wordfree
// __woverflow
// wprintf
// __wprintf_chk
// write    // Weak
// __write  // Weak
// writev   // Weak
// wscanf
// __wuflow
// __wunderflow
// xdecrypt
// xdr_accepted_reply
// xdr_array
// xdr_authdes_cred
// xdr_authdes_verf
// xdr_authunix_parms
// xdr_bool
// xdr_bytes
// xdr_callhdr
// xdr_callmsg
// xdr_char
// xdr_cryptkeyarg
// xdr_cryptkeyarg2
// xdr_cryptkeyres
// xdr_des_block
// xdr_double
// xdr_enum
// xdr_float
// xdr_free
// xdr_getcredres
// xdr_hyper
// xdr_int
// xdr_int16_t
// xdr_int32_t
// xdr_int64_t
// xdr_int8_t
// xdr_keybuf
// xdr_key_netstarg
// xdr_key_netstres
// xdr_keystatus
// xdr_long
// xdr_longlong_t
// xdrmem_create
// xdr_netnamestr
// xdr_netobj
// xdr_opaque
// xdr_opaque_auth
// xdr_pmap
// xdr_pmaplist
// xdr_pointer
// xdr_quad_t
// xdrrec_create
// xdrrec_endofrecord
// xdrrec_eof
// xdrrec_skiprecord
// xdr_reference
// xdr_rejected_reply
// xdr_replymsg
// xdr_rmtcall_args
// xdr_rmtcallres
// xdr_short
// xdr_sizeof
// xdrstdio_create
// xdr_string
// xdr_u_char
// xdr_u_hyper
// xdr_u_int
// xdr_uint16_t
// xdr_uint32_t
// xdr_uint64_t
// xdr_uint8_t
// xdr_u_long
// xdr_u_longlong_t
// xdr_union
// xdr_unixcred
// xdr_u_quad_t
// xdr_u_short
// xdr_vector
// xdr_void
// xdr_wrapstring
// xencrypt
// __xmknod
// __xmknodat
// __xpg_basename
// __xpg_sigpause   // Weak
// __xpg_strerror_r
// xprt_register
// xprt_unregister
// __xstat
// __xstat64

// forcing a custom __gmon_start__ that does nothing
GOM(__gmon_start__, vFE)

END()

#else
#error Mmmm...
#endif