h62641
s 00020/00013/00044
d D 5.2 85/01/22 14:10:54 ralph 2 1
c bug fixes and changes from Rick Adams
e
s 00057/00000/00000
d D 5.1 83/07/02 17:57:32 sam 1 0
c date and time created 83/07/02 17:57:32 by sam
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif

#include "uucp.h"
#include <signal.h>

D 2

E 2
/*******
 *	shio(cmd, fi, fo, user)	execute shell of command with
 *	char *cmd, *fi, *fo;	fi and fo as standard input/output
 *	char *user;		user name
 *
 *	return codes:
 *		0  - ok
 *		non zero -  failed  -  status from child
 */

shio(cmd, fi, fo, user)
char *cmd, *fi, *fo, *user;
{
	int status, f;
	int uid, pid, ret;
	char path[MAXFULLNAME];
I 2
	extern int errno;
E 2

	if (fi == NULL)
D 2
		fi = "/dev/null";
E 2
I 2
		fi = DEVNULL;
E 2
	if (fo == NULL)
D 2
		fo = "/dev/null";
E 2
I 2
		fo = DEVNULL;
E 2

	DEBUG(3, "shio - %s\n", cmd);
I 2
#ifdef SIGCHLD
	signal(SIGCHLD, SIG_IGN);
#endif SIGCHLD
E 2
	if ((pid = fork()) == 0) {
		signal(SIGINT, SIG_IGN);
		signal(SIGHUP, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
		signal(SIGKILL, SIG_IGN);
		close(Ifn);
		close(Ofn);
		close(0);
D 2
		if (user == NULL
		|| (gninfo(user, &uid, path) != 0)
		|| setuid(uid))
E 2
I 2
		if (user == NULL || (gninfo(user, &uid, path) != 0)
			|| setuid(uid))
E 2
			setuid(getuid());
		f = open(subfile(fi), 0);
D 2
		if (f != 0)
			exit(f);
E 2
I 2
		if (f != 0) {
			logent(fi, "CAN'T READ");
			exit(-errno);
		}
E 2
		close(1);
		f = creat(subfile(fo), 0666);
D 2
		if (f != 1)
			exit(f);
E 2
I 2
		if (f != 1) {
			logent(fo, "CAN'T WRITE");
			exit(-errno);
		}
E 2
		execl(SHELL, "sh", "-c", cmd, (char *)0);
D 2
		exit(100);
E 2
I 2
		exit(100+errno);
E 2
	}
D 2
	while ((ret = wait(&status)) != pid && ret != -1);
E 2
I 2
	while ((ret = wait(&status)) != pid && ret != -1)
		;
E 2
	DEBUG(3, "status %d\n", status);
D 2
	return(status);
E 2
I 2
	return status;
E 2
}
E 1
