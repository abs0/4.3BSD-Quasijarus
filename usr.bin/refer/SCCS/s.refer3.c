h64700
s 00001/00001/00037
d D 4.2 85/08/26 19:13:36 mckusick 2 1
c fix syntax errors
e
s 00038/00000/00000
d D 4.1 83/05/06 23:30:09 tut 1 0
c date and time created 83/05/06 23:30:09 by tut
e
u
U
t
T
I 1
#ifndef lint
static char *sccsid = "%W% (Berkeley) %G%";
#endif

#include "refer..c"
#define move(x, y) close(y); dup(x); close(x);

corout(in, out, rprog, arg, outlen)
char *in, *out, *rprog;
{
	int pipev[2], fr1, fr2, fw1, fw2, n;
	int status;

	pipe(pipev); 
	fr1 = pipev[0]; 
	fw1 = pipev[1];
	pipe(pipev); 
	fr2 = pipev[0]; 
	fw2 = pipev[1];
	if (fork() == 0)
	{
		close(fw1); 
		close(fr2);
		move(fr1, 0);
		move(fw2, 1);
		execl(rprog, "deliv", arg, 0);
D 2
		err("Can't run %s", (void) rprog);
E 2
I 2
		err("Can't run %s", rprog);
E 2
	}
	close(fw2); 
	close(fr1);
	write(fw1, in , strlen(in));
	close(fw1);
	wait(&status);
	n = read(fr2, out, outlen);
	out[n] = 0;
	close(fr2);
	return(n);
}
E 1
