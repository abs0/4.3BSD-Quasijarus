h12771
s 00002/00002/00038
d D 4.2 83/05/19 09:38:28 ralph 3 1
c fixed perror message and getlogin assignment.
e
s 00001/00001/00039
d R 4.2 83/05/19 09:36:28 ralph 2 1
c fixed perror message.
e
s 00040/00000/00000
d D 4.1 83/03/30 12:08:42 sam 1 0
c date and time created 83/03/30 12:08:42 by sam
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% %G%";
#endif

#include "xmail.h"
#include "pwd.h"
#include "sys/types.h"
MINT *a[42], *x, *b, *one, *c64, *t45, *z, *q, *r, *two, *t15;
char buf[256];
char maildir[] = { "/usr/spool/secretmail"};
main()
{
	int uid, i;
	FILE *fd;
	char *myname, fname[128];
	uid = getuid();
D 3
	myname = getlogin();
E 3
I 3
	myname = (char *) getlogin();
E 3
	if(myname == NULL)
		myname = getpwuid(uid)->pw_name;
	sprintf(fname, "%s/%s.key", maildir, myname);
	comminit();
	setup(getpass("Gimme key: "));
	mkb();
	mkx();
#ifdef debug
	omout(b);
	omout(x);
#endif
	mka();
	i = creat(fname, 0644);
	if(i<0)
D 3
	{	perror("fname");
E 3
I 3
	{	perror(fname);
E 3
		exit(1);
	}
	close(i);
	fd = fopen(fname, "w");
	for(i=0; i<42; i++)
		nout(a[i], fd);
	exit(0);
}
E 1
