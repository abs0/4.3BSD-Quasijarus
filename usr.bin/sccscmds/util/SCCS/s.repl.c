h36881
s 00001/00001/00011
d D 1.2 87/02/15 16:08:48 lepreau 2 1
c fix sccsid to use keywords and modern initialization syntax
e
s 00012/00000/00000
d D 1.1 87/02/15 16:03:35 lepreau 1 0
c date and time created 87/02/15 16:03:35 by lepreau
e
u
U
t
T
I 1
D 2
static char Sccsid[] "@(#)repl	3.1";
E 2
I 2
static char Sccsid[] = "%W%	%G%";
E 2
/*
	Replace each occurrence of `old' with `new' in `str'.
	Return `str'.
*/

repl(str,old,new)
char *str;
char old,new;
{
	return(trnslat(str, &old, &new, str));
}
E 1
