h08263
s 00012/00003/00035
d D 4.3 86/05/15 17:59:01 bloom 3 2
c updates from John Kunze
e
s 00018/00010/00020
d D 4.2 83/04/25 23:59:29 mckusick 2 1
c 
e
s 00030/00000/00000
d D 4.1 83/02/24 12:56:25 mckusick 1 0
c date and time created 83/02/24 12:56:25 by mckusick
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W%	(Berkeley)	%G%";
#endif not lint

#include "signal.h"
#include "stdio.h"
#include "lrnref.h"

I 3
extern char learnrc[];

E 3
wrapup(n)
int n;
{
I 3
	FILE *fp;
E 3
D 2
	/* this routine does not use 'system' because it wants
	 interrupts turned off */
	int retval, pid, pidw;
E 2
I 2
/* this routine does not use 'system' because it wants interrupts turned off */
E 2

	signal(SIGINT, SIG_IGN);
	chdir("..");
D 2
	if ( (pid=fork()) ==0) {
E 2
I 2
	if (fork() == 0) {
E 2
		signal(SIGHUP, SIG_IGN);
D 2
		execl("/bin/rm", "rm", "-r", dir, 0);
		execl("/usr/bin/rm", "rm", "-r", dir, 0);
		fprintf(stderr, "Can't find 'rm' command.\n");
E 2
I 2
D 3
#if vax
E 3
I 3
#if BSD4_2
E 3
		if (fork() == 0) {
			close(1);
			open("/dev/tty", 1);
			execl("/bin/stty", "stty", "new", 0);
		}
#endif
		execl("/bin/rm", "rm", "-rf", dir, 0);
		execl("/usr/bin/rm", "rm", "-rf", dir, 0);
		perror("bin/rm");
		fprintf(stderr, "Wrapup:  can't find 'rm' command.\n");
E 2
		exit(0);
	}
D 2
	printf("Bye.\n"); /* not only does this reassure user but 
			it stalls for time while deleting directory */
E 2
I 2
D 3
	if (!n && todo)
		printf("To take up where you left off type \"learn %s %s\".\n", sname, todo);
E 3
I 3
	if (n == -1)
		unlink(learnrc);
	else if (!n && todo) {
		if ((fp=fopen(learnrc, "w")) == NULL)
			exit(0);
		fprintf(fp, "%s %s %d\n", sname, todo, speed);
		fclose(fp);
	}
E 3
	printf("Bye.\n");	/* not only does this reassure user but it
				stalls for time while deleting directory */
E 2
	fflush(stdout);
D 2
	/* printf("Wantd %d got %d val %d\n",pid, pidw, retval); */
E 2
I 2
	wait(0);
E 2
	exit(n);
}
E 1
