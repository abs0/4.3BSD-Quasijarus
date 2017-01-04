h24016
s 00000/00000/00017
d D 4.1 82/05/12 11:13:39 rrh 2 1
c sync to release 4.1
e
s 00017/00000/00000
d D 1.1 82/05/12 11:03:11 rrh 1 0
c date and time created 82/05/12 11:03:11 by rrh
e
u
U
t
T
I 1
static char sccsid[] = "	%M%	%I%	%E%	";

bcopy(from, to, count)
	char *from, *to;
	int count;
{

	asm("	movc3	12(ap),*4(ap),*8(ap)");
}

seteuid(n)
{
}

setegid(n)
{
}
E 1
