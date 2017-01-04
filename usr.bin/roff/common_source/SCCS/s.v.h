h51083
s 00001/00001/00003
d D 4.4 2012/02/16 07:22:28 msokolov 4 3
c put full A.D. year in \n(Yr
e
s 00001/00001/00003
d D 4.3 02/05/28 20:57:17 msokolov 3 2
c Y2K: make \n(yr really two digits as the manual says and add \n(cn for century
e
s 00002/00003/00002
d D 4.2 83/08/11 21:26:46 sam 2 1
c standardize sccs keyword lines
e
s 00005/00000/00000
d D 4.1 82/06/07 15:44:59 rrh 1 0
c date and time created 82/06/07 15:44:59 by rrh
e
u
U
t
T
I 1
D 2
/*
 *	%W% %G%
 */
E 2
I 2
/*	%M%	%I%	%E%	*/

E 2
D 3
struct v {int pn,nl,yr,hp,ct,dn,mo,dy,dw,ln,dl,st,sb,cd;
E 3
I 3
D 4
struct v {int pn,nl,yr,hp,ct,dn,mo,dy,dw,ln,dl,st,sb,cd,cn;
E 4
I 4
struct v {int pn,nl,yr,hp,ct,dn,mo,dy,dw,ln,dl,st,sb,cd,cn,Yr;
E 4
E 3
	int vxx[NN-NNAMES];} v ;
E 1
