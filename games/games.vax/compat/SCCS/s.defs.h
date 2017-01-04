h38775
s 00000/00000/00014
d D 4.1 82/05/12 11:13:46 rrh 2 1
c sync to release 4.1
e
s 00014/00000/00000
d D 1.1 82/05/12 11:03:14 rrh 1 0
c date and time created 82/05/12 11:03:14 by rrh
e
u
U
t
T
I 1
/*
 * 	%M%	%I%	%E%
 */
#define	EMTS	0210
#define	TRAPS	0211
#define	SETD	0170011
extern unsigned int sigvals[];
extern unsigned long psl;
extern unsigned short regs[];
extern unsigned short *pc;
extern unsigned short wordspace[];
extern unsigned char bytespace[];
extern unsigned char *memsiz;
extern int incompat;
E 1
