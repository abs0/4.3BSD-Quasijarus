h03230
s 00005/00002/00036
d D 7.1 88/05/21 18:36:16 karels 3 2
c bring up to revision 7 for tahoe release
e
s 00006/00000/00032
d D 1.2 87/01/13 10:58:07 karels 2 1
c mv machine dependend from sys_process.c
e
s 00032/00000/00000
d D 1.1 86/01/05 18:46:22 sam 1 0
c date and time created 86/01/05 18:46:22 by sam
e
u
U
t
T
I 1
D 3
/*	%M%	%I%	%E%	*/
/*	reg.h	4.2	81/02/19	*/
E 3
I 3
/*
 *	%W% (Berkeley) %G%
 *	from reg.h	4.2	81/02/19
 */

E 3
/*
 * Location of the users' stored
 * registers relative to PSL of 'trap' and 'syscall'.
 * Usage is u.u_ar0[XX].
 */

#define	PS	(-1)
#define	PC	(-2)
/*		(-3)	*/
/*		(-4)	*/
#define	RACL	(-5)
#define	RACH	(-6)
/*		(-7)	*/
/*		(-8)	*/
#define	SP	(-9)
#define	R13	(-10)
#define	FP	(-10)
#define	R12	(-13)
#define	R11	(-14)
#define	R10	(-15)
#define	R9	(-16)
#define	R8	(-17)
#define	R7	(-18)
#define	R6	(-19)
#define	R5	(-20)
#define	R4	(-21)
#define	R3	(-22)
#define	R2	(-23)
#define	R1	(-24)
#define	R0	(-25)
I 2

#ifdef IPCREG
#define	NIPCREG 18
int ipcreg[NIPCREG] =
	{R0,R1,R2,R3,R4,R5,R6,R7,R8,R9,R10,R11,R12,FP,SP,PC,RACH,RACL};
#endif
E 2
E 1
