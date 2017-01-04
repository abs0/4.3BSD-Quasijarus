h45310
s 00003/00001/00024
d D 7.1 88/05/21 18:36:12 karels 3 2
c bring up to revision 7 for tahoe release
e
s 00005/00006/00020
d D 1.2 86/01/05 18:42:39 sam 2 1
c 1st working version
e
s 00026/00000/00000
d D 1.1 85/07/24 15:35:42 sam 1 0
c date and time created 85/07/24 15:35:42 by sam
e
u
U
t
T
I 2
D 3
/*	%M%	%I%	%E%	*/
E 3
I 3
/*
 *	%W% (Berkeley) %G%
 */
E 3
E 2
I 1

D 2
/*	psl.h	4.4	84/01/31	*/

E 2
/*
D 2
 * TAHOE program status longword
E 2
I 2
 * TAHOE processor status longword.
E 2
 */
D 2

E 2
#define	PSL_C		0x00000001	/* carry bit */
#define	PSL_V		0x00000002	/* overflow bit */
#define	PSL_Z		0x00000004	/* zero bit */
#define	PSL_N		0x00000008	/* negative bit */
#define	PSL_ALLCC	0x0000000f	/* all cc bits - unlikely */
#define	PSL_T		0x00000010	/* trace enable bit */
#define	PSL_IV		0x00000020	/* integer overflow enable bit */
#define	PSL_FU		0x00000040	/* float underflow enable 	*/
#define PSL_DBL		0x00000080	/* f.p. prescision indicator	*/
#define	PSL_SFE		0x00000100	/* system-forced-exception */
#define	PSL_IPL		0x001f0000	/* interrupt priority level */
I 2
#define	PSL_PRVMOD	0x00000000	/* previous mode (kernel mode) */
E 2
#define	PSL_CURMOD	0x01000000	/* current mode (all on is user) */
#define	PSL_IS		0x04000000	/* interrupt stack */
#define	PSL_TP		0x40000000	/* trace pending */

D 2
#define	PSL_MBZ		0xbae0ffc0	/* must be zero bits */
E 2
I 2
#define	PSL_MBZ		0xbae0fe00	/* must be zero bits */
E 2

#define	PSL_USERSET	(PSL_CURMOD)
D 2
#define	PSL_USERCLR	(PSL_IS|PSL_IPL|PSL_MBZ)
E 2
I 2
#define	PSL_USERCLR	(PSL_IS|PSL_IPL|PSL_MBZ|PSL_SFE|PSL_DBL|PSL_FU)
E 2
E 1
