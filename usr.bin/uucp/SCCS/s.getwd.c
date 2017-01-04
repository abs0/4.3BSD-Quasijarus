h32611
s 00007/00076/00027
d D 5.4 85/06/19 19:38:18 bloom 4 3
c changes and fixes from rick adams
e
s 00020/00014/00083
d D 5.3 85/01/22 14:09:03 ralph 3 2
c bug fixes and changes from Rick Adams
e
s 00001/00001/00096
d D 5.2 84/08/30 16:15:24 ralph 2 1
c added network device NET
e
s 00097/00000/00000
d D 5.1 83/07/02 17:57:06 sam 1 0
c date and time created 83/07/02 17:57:06 by sam
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

D 3
/*******
 *	gwd(wkdir)	get working directory
E 3
I 3
/*
 *	get working directory
E 3
 *
D 3
 *	return codes  0 | FAIL
E 3
I 3
D 4
 *	return codes  SUCCESS | FAIL
E 4
I 4
 *	return codes  0 = FAIL
 *		      wkdir = SUCCES
E 4
E 3
 */

D 4
gwd(wkdir)
E 4
I 4
char *
getwd(wkdir)
E 4
register char *wkdir;
{
	register FILE *fp;
	extern FILE *rpopen();
	extern int rpclose();
	register char *c;

I 3
D 4
#ifdef BSD4_2
	if (getwd(wkdir) == 0)
		return FAIL;
#else !BSD4_2
# ifdef VMS
	getwd(wkdir);	/* Call Eunice C library version instead */
#else !VMS
E 4
E 3
	*wkdir = '\0';
D 3
	/* PATH added to rpopen.  Suggested by Henry Spencer (utzoo!henry) */
	if ((fp = rpopen("PATH=/bin:/usr/bin;pwd 2>&-", "r")) == NULL)
		return(FAIL);
D 2
	if (fgets(wkdir, 100, fp) == NULL) {
E 2
I 2
	if (fgets(wkdir, MAXFULLNAME, fp) == NULL) {
E 2
		pclose(fp);
		return(FAIL);
E 3
I 3
	if ((fp = rpopen("PATH=/bin:/usr/bin:/usr/ucb;pwd 2>&-", "r")) == NULL)
D 4
		return FAIL;
E 4
I 4
		return 0;
E 4
	if (fgets(wkdir, 100, fp) == NULL) {
		rpclose(fp);
D 4
		return FAIL;
E 4
I 4
		return 0;
E 4
E 3
	}
	if (*(c = wkdir + strlen(wkdir) - 1) == '\n')
		*c = '\0';
	rpclose(fp);
D 3
	return(0);
E 3
I 3
D 4
# endif !VMS
#endif !BSD4_2
	return SUCCESS;
E 3
}

/*
D 3
 * rti!trt: gwd uses 'reverting' version of popen
E 3
I 3
 * gwd uses 'reverting' version of popen
E 3
 * which runs process with permissions of real gid/uid
 * rather than the effective gid/uid.
D 3
 * Bug noted by we13!rjk  (Randy King).
E 3
 */
D 3
/* @(#)popen.c	4.1 (Berkeley) 12/21/80 */
E 3
#include <signal.h>
#define	tst(a,b)	(*mode == 'r'? (b) : (a))
#define	RDR	0
#define	WTR	1
static	int	popen_pid[20];

FILE *
rpopen(cmd,mode)
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
		dup2(hisside, tst(0, 1));
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
D 3
	return(status);
E 3
I 3
	return status;
E 4
I 4
	return wkdir;
E 4
E 3
}
E 1
