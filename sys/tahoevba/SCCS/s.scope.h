h39032
s 00003/00001/00021
d D 7.1 88/05/21 18:47:55 karels 4 3
c bring up to revision 7 for tahoe release
e
s 00010/00005/00012
d D 1.3 86/01/12 21:46:13 sam 3 2
c fix some includes and make scope points globally controlled
e
s 00002/00002/00015
d D 1.2 86/01/05 18:37:35 sam 2 1
c 1st working version (mostly)
e
s 00017/00000/00000
d D 1.1 85/07/21 20:36:04 sam 1 0
c date and time created 85/07/21 20:36:04 by sam
e
u
U
t
T
I 1
D 4
/*	%M%	%I%	%E%	*/
E 4
I 4
/*
 *	%W% (Berkeley) %G%
 */
E 4

D 3
/*  Some I/O addresses used to generate pulses for scopes */
E 3
I 3
#ifdef DOSCOPE
/*  some i/o addresses used to generate pulses for scopes */
E 3
#define	OUT1	0xffffb034
#define	OUT2	0xffffb018
#define	OUT3	0xffffb020
#define	OUT4	0xffffb004
#define	OUT5	0xffffb024
#define	OUT6	0xffffb00c
#define	OUT7	0xffffb02c

D 2
#define	IOaddr(off)	(char *)(&vmem[(off) & 0x0fffff])
E 2
I 2
#define	IOaddr(off)	(caddr_t)(&vmem[(off) & 0x0fffff])
E 2

D 3
extern char vmem[];
int	iospace_mapped;
D 2
#define	scope_out(x)	if(iospace_mapped) movob (0, IOaddr(OUT/**/x))
E 2
I 2
#define	scope_out(x)	if(iospace_mapped) movob(IOaddr(OUT/**/x),0)
E 2
#define	scope_in(x)	if(iospace_mapped) dummy =  *IOaddr(IN/**/x)
E 3
I 3
extern	char vmem[];
extern	int cold;
#define	scope_out(x)	if (!cold) movob(IOaddr(OUT/**/x),0)
#define	scope_in(x)	if( !cold) dummy =  *IOaddr(IN/**/x)
#else
#define	scope_out(x)
#define	scope_in(x)
#endif
E 3
E 1
