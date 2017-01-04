h23178
s 00017/00000/00000
d D 4.1 83/05/06 23:47:06 tut 1 0
c date and time created 83/05/06 23:47:06 by tut
e
u
U
t
T
I 1
#ifndef lint
static char *sccsid = "%W% (Berkeley) %G%";
#endif

char refdir[50];

savedir()
{
	if (refdir[0]==0)
		corout ("", refdir, "/bin/pwd", "", 50);
	trimnl(refdir);
}

restodir()
{
	chdir(refdir);
}
E 1
