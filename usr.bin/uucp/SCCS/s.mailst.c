h04192
s 00005/00070/00034
d D 5.7 88/04/05 12:07:09 rick 7 6
c use library popen. set IFS before calling popen
e
s 00002/00002/00102
d D 5.6 85/10/09 16:09:52 bloom 6 5
c close paren needed (from rick@seismo)
e
s 00072/00000/00032
d D 5.5 85/06/20 09:59:08 bloom 5 4
c fixes and rearrangement from rick adams
e
s 00001/00001/00031
d D 5.4 85/04/10 15:20:05 ralph 4 3
c more changes from rick adams.
e
s 00013/00017/00019
d D 5.3 85/01/22 14:09:30 ralph 3 2
c bug fixes and changes from Rick Adams
e
s 00001/00002/00035
d D 5.2 83/07/19 11:33:14 gray 2 1
c security fixes
e
s 00037/00000/00000
d D 5.1 83/07/02 17:57:17 sam 1 0
c date and time created 83/07/02 17:57:17 by sam
e
u
U
t
T
I 1
#ifndef lint
D 7
static char sccsid[] = "%W% (Berkeley) %G%";
E 7
I 7
static char sccsid[] = "%W%	(Berkeley) %G%";
E 7
#endif

I 5
#include <signal.h>
E 5
#include "uucp.h"
I 5
#ifdef USG
#include <fcntl.h>
#endif USG
E 5

I 5
/*LINTLIBRARY*/

E 5
D 3
/*******
 *	mailst(user, str, file)
 *
E 3
I 3
/*
E 3
 *	mailst  -  this routine will fork and execute
 *	a mail command sending string (str) to user (user).
 *	If file is non-null, the file is also sent.
 *	(this is used for mail returned to sender.)
 */

mailst(user, str, file)
char *user, *str, *file;
{
	register FILE *fp, *fi;
I 7
	FILE *popen();
E 7
D 2
	extern FILE *popen(), *pclose();
E 2
D 3
	char cmd[100], buf[BUFSIZ];
	register int nc;
E 3
I 3
	char buf[BUFSIZ];
	register int c;
E 3

D 3
	sprintf(cmd, "mail %s", user);
D 2
	if ((fp = popen(cmd, "w")) == NULL)
E 2
I 2
	if ((fp = rpopen(cmd, "w")) == NULL)
E 2
		return;
	fprintf(fp, "%s", str);

	if (*file != '\0' && (fi = fopen(subfile(file), "r")) != NULL) {
		while ((nc = fread(buf, sizeof (char), BUFSIZ, fi)) > 0)
			fwrite(buf, sizeof (char), nc, fp);
		fclose(fi);
E 3
I 3
D 4
	sprintf(buf, "%s %s", MAIL, user);
E 4
I 4
D 7
	sprintf(buf, "%s '%s'", MAIL, user);
E 4
	if ((fp = rpopen(buf, "w")) != NULL) {
E 7
I 7
	sprintf(buf, "IFS=\" \t\n\";%s '%s'", MAIL, user);
	if ((fp = popen(buf, "w")) != NULL) {
E 7
		fprintf(fp, "From: uucp\nTo: %s\nSubject: %s\n\n", user, str);
		if (file && *file != '\0' && (fi = fopen(subfile(file), "r")) != NULL) {
			while ((c = getc(fi)) != EOF)
				putc(c, fp);
			putc('\n', fp);
			fclose(fi);
		}
D 7
		rpclose(fp);
E 7
I 7
		pclose(fp);
E 7
E 3
	}
I 5
D 7
}

/*
 * 'reverting' version of popen
 * which runs process with permissions of real gid/uid
 * rather than the effective gid/uid.
 */
#define	tst(a,b)	(*mode == 'r'? (b) : (a))
#define	RDR	0
#define	WTR	1
static	int	popen_pid[20];

FILE *
D 6
rpopen(cmd,mode)
E 6
I 6
rpopen(cmd, mode)
E 6
char	*cmd;
char	*mode;
{
	int p[2];
	register myside, hisside, pid;

	if(pipe(p) < 0)
		return NULL;
	myside = tst(p[WTR], p[RDR]);
	hisside = tst(p[RDR], p[WTR]);
	if((pid = fork()) == 0) {
		/* myside and hisside reverse roles in child */
		close(myside);
#ifdef USG
D 6
		close(tst(0, 1);
E 6
I 6
		close(tst(0, 1));
E 6
		fcntl(hisside, F_DUPFD, tst(0, 1));
#else !USG
		dup2(hisside, tst(0, 1));
#endif !USG
		close(hisside);
		/* revert permissions */
		setgid(getgid());
		setuid(getuid());
		execl("/bin/sh", "sh", "-c", cmd, (char *)0);
		_exit(1);
	}
	if(pid == -1)
		return NULL;
	popen_pid[myside] = pid;
	close(hisside);
	return(fdopen(myside, mode));
}

rpclose(ptr)
FILE *ptr;
{
	register f, r, (*hstat)(), (*istat)(), (*qstat)();
	int status;

	f = fileno(ptr);
	fclose(ptr);
	istat = signal(SIGINT, SIG_IGN);
	qstat = signal(SIGQUIT, SIG_IGN);
	hstat = signal(SIGHUP, SIG_IGN);
	while((r = wait(&status)) != popen_pid[f] && r != -1)
		;
	if(r == -1)
		status = -1;
	signal(SIGINT, istat);
	signal(SIGQUIT, qstat);
	signal(SIGHUP, hstat);
	return status;
E 7
E 5
D 3

	pclose(fp);
	return;
E 3
}
E 1
