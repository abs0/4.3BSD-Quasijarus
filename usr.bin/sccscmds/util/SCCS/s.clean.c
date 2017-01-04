h36326
s 00001/00001/00009
d D 1.2 87/02/15 16:08:37 lepreau 2 1
c fix sccsid to use keywords and modern initialization syntax
e
s 00010/00000/00000
d D 1.1 87/02/15 16:03:29 lepreau 1 0
c date and time created 87/02/15 16:03:29 by lepreau
e
u
U
t
T
I 1
D 2
static char Sccsid[] "@(#)clean	2.1";
E 2
I 2
static char Sccsid[] = "%W%	%G%";
E 2
/*
	Default clean_up routine for fatal and setsig.
	User defined clean_up routines are used for removing
	temporary files, etc.
*/

clean_up()
{
}
E 1
