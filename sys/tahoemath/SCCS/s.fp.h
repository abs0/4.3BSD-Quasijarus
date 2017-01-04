h10915
s 00017/00017/00001
d D 1.2 86/01/03 23:47:17 sam 2 1
c massive cleanups; use SYS.h macros to allow profiling; moved to 
c tahoemath directory; revamp comments for cpp
e
s 00018/00000/00000
d D 1.1 85/07/31 17:07:56 sam 1 0
c date and time created 85/07/31 17:07:56 by sam
e
u
U
t
T
I 2
/*	%M%	%I%	%E%	*/
E 2
I 1

D 2
#define		EXPMASK		0x7f800000
#define		SIGNBIT		0x80000000
#define		ONE_EXP		0x40800000
#define		TWO_EXP		0x40000000
#define		EXPSHIFT	23
#define		HID_POS		24
#define		HID_R0R1	24+32
#define		CLEARHID	0xff7fffff
#define		EXPSIGN		0x40000000
#define		MAX_EXP_DIF	55
#define		SMAX_EXP_DIF	23
#define		BIAS		0x80
#define		BIASP1		0x81
#define		BIASM1		0x7f
#define		HUGE0		0x7fffffff
#define		HUGE1		0xffffffff
 
E 2
I 2
#define	EXPMASK		0x7f800000
#define	SIGNBIT		0x80000000
#define	ONE_EXP		0x40800000
#define	TWO_EXP		0x40000000
#define	EXPSHIFT	23
#define	HID_POS		24
#define	HID_R0R1	24+32
#define	CLEARHID	0xff7fffff
#define	EXPSIGN		0x40000000
#define	MAX_EXP_DIF	55
#define	SMAX_EXP_DIF	23
#define	BIAS		0x80
#define	BIASP1		0x81
#define	BIASM1		0x7f
#define	HUGE0		0x7fffffff
#define	HUGE1		0xffffffff
E 2
E 1
