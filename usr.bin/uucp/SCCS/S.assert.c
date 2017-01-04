h14586
s 00008/00008/00043
d D 5.5 85/06/19 17:31:01 bloom 6 5
c lint fixes from rick adams
e
s 00000/00001/00051
d D 5.4 85/04/10 15:17:57 ralph 5 4
c more changes from rick adams.
e
s 00012/00007/00040
d D 5.3 85/01/22 13:58:35 ralph 4 2
c bug fixes and changes from Rick Adams
e
s 00016/00005/00042
d R 5.3 85/01/22 12:28:46 ralph 3 2
c bug fixes & changes from Rick Adams
e
s 00001/00001/00046
d D 5.2 83/07/02 18:24:28 sam 2 1
c include fixes
e
s 00047/00000/00000
d D 5.1 83/07/02 17:56:20 sam 1 0
c date and time created 83/07/02 17:56:20 by sam
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
D 2
#include <time.h>
E 2
I 2
#include <sys/time.h>
E 2
D 5
#include <sys/types.h>
E 5
#include <errno.h>

D 6
/*******
 *	assert - print out assetion error
 *
 *	return code - none
E 6
I 6
/*LINTLIBRARY*/

/*
 *	print out assetion error
E 6
 */

assert(s1, s2, i1)
char *s1, *s2;
{
	register FILE *errlog;
	register struct tm *tp;
	extern struct tm *localtime();
D 6
	extern time_t time();
E 6
	time_t clock;
	int pid;

D 4
	if (Debug)
		errlog = stderr;
	else {
E 4
I 4
	errlog = NULL;
	if (!Debug) {
E 4
		int savemask;
		savemask = umask(LOGMASK);
		errlog = fopen(ERRLOG, "a");
		umask(savemask);
	}
	if (errlog == NULL)
D 4
		return;
E 4
I 4
		errlog = stderr;
E 4

	pid = getpid();
	fprintf(errlog, "ASSERT ERROR (%.9s)  ", Progname);
	fprintf(errlog, "pid: %d  ", pid);
D 6
	time(&clock);
E 6
I 6
	(void) time(&clock);
E 6
	tp = localtime(&clock);
D 4
	fprintf(errlog, "(%d/%d-%d:%02d) ", tp->tm_mon + 1,
E 4
I 4
#ifdef USG
	fprintf(errlog, "(%d/%d-%2.2d:%2.2d) ", tp->tm_mon + 1,
E 4
		tp->tm_mday, tp->tm_hour, tp->tm_min);
D 4
	fprintf(errlog, "%s %s (%d)\n", s1, s2, i1);
	fclose(errlog);
E 4
I 4
D 6
#else
E 6
I 6
#endif
#ifndef USG
E 6
	fprintf(errlog, "(%d/%d-%02d:%02d) ", tp->tm_mon + 1,
		tp->tm_mday, tp->tm_hour, tp->tm_min);
#endif
	fprintf(errlog, "%s %s (%d)\n", s1 ? s1 : "", s2 ? s2 : "", i1);
	if (errlog != stderr)
D 6
		fclose(errlog);
E 6
I 6
		(void) fclose(errlog);
E 6
E 4
	return;
}
E 1
