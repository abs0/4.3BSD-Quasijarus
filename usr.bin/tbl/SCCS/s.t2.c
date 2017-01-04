h41092
s 00003/00001/00022
d D 4.2 83/08/11 21:13:36 sam 2 1
c standardize sccs keyword lines
e
s 00023/00000/00000
d D 4.1 83/02/12 19:06:19 shannon 1 0
c date and time created 83/02/12 19:06:19 by shannon
e
u
U
t
T
I 1
D 2
/*	%M%	%I%	%E%	*/
E 2
I 2
#ifndef lint
static char sccsid[] = "%W% %G%";
#endif
E 2

 /* t2.c:  subroutine sequencing for one table */
# include "t..c"
tableput()
{
saveline();
savefill();
ifdivert();
cleanfc();
getcomm();
getspec();
gettbl();
getstop();
checkuse();
choochar();
maktab();
runout();
release();
rstofill();
endoff();
restline();
}
E 1
