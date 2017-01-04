h08276
s 00007/00008/00141
d D 5.5 88/04/05 12:19:27 rick 5 4
c use syslog for erors, fix anceint bug with packets > 128 (free speedup in the process), remove unused pkmove (bcopy doe sthe same thing)
e
s 00005/00006/00144
d D 5.4 85/06/23 13:07:32 bloom 4 3
c fixes from rick adams
e
s 00002/00007/00148
d D 5.3 85/04/10 15:20:53 ralph 3 2
c more changes from rick adams.
e
s 00042/00016/00113
d D 5.2 85/01/22 14:11:11 ralph 2 1
c bug fixes and changes from Rick Adams
e
s 00129/00000/00000
d D 5.1 83/07/02 17:57:37 sam 1 0
c date and time created 83/07/02 17:57:37 by sam
e
u
U
t
T
I 1
#ifndef lint
D 5
static char sccsid[] = "%W% (Berkeley) %G%";
E 5
I 5
static char sccsid[] = "%W%	(Berkeley) %G%";
E 5
#endif

#include "uucp.h"
D 3
#include <sys/types.h>
E 3

D 4
extern	time_t	time();

D 2
#define STATNAME(f, n) sprintf(f, "%s/%s.%.7s", Spool, "STST", n)
E 2
I 2
#define STATNAME(f, n) sprintf(f, "%s/%s/%.7s", Spool, "STST", n)
E 4
I 4
#define STATNAME(f, n) sprintf(f, "%s/%s/%s", Spool, "STST", n)
E 4
E 2
#define S_SIZE 100

I 4
/*LINTLIBRARY*/

E 4
D 3
/*******
 *	systat(name, type, text)	make system status entry
 *	char *name, *text;
 *	int type.
 *
E 3
I 3
/*
 *	make system status entry
E 3
 *	return codes:  none
 */
D 3

E 3
systat(name, type, text)
char *name, *text;
int type;
{
	char filename[MAXFULLNAME], line[S_SIZE];
D 2
	int count;
E 2
I 2
	int count, oldtype;
E 2
	register FILE *fp;
D 2
	time_t prestime;
E 2
I 2
	time_t prestime, rtry;
E 2

	if (type == 0)
		return;
	line[0] = '\0';
	time(&prestime);
	count = 0;
	STATNAME(filename, name);

	fp = fopen(filename, "r");
	if (fp != NULL) {
		fgets(line, S_SIZE, fp);
D 2
		sscanf(&line[2], "%d", &count);
E 2
I 2
		sscanf(line, "%d %d", &oldtype, &count);
E 2
		if (count <= 0)
			count = 0;
		fclose(fp);
I 2
		/* If merely 'wrong time', don't change existing STST */
		if (type == SS_WRONGTIME && oldtype != SS_INPROGRESS)
			return;
E 2
	}

D 2
	if (type == SS_FAIL)
E 2
I 2
	rtry = Retrytime;
	/* if failures repeat, don't try so often,
	 * to forstall a 'MAX RECALLS' situation.
	 */
	if (type == SS_FAIL) {
E 2
		count++;
I 2
		if (count > 5) {
			rtry = rtry * (count-5);
			if (rtry > ONEDAY/2)
				rtry = ONEDAY/2;
		}
	}
E 2

I 2

#ifdef VMS
	unlink(filename);
#endif VMS
E 2
	fp = fopen(filename, "w");
D 2
	ASSERT(fp != NULL, "SYSTAT OPEN FAIL", "", 0);
/*	chmod(filename, 0666); rm-ed by rti!trt */
	fprintf(fp, "%d %d %ld %ld %s %s\n", type, count, prestime, Retrytime, text, name);
E 2
I 2
D 5
	ASSERT(fp != NULL, "SYSTAT OPEN FAIL", filename, 0);
E 5
I 5
	if (fp == NULL) {
		syslog(LOG_ERR, "fopen(%s) failed: %m", filename);
		cleanup(FAIL);
	}
E 5
	fprintf(fp, "%d %d %ld %ld %s %s\n", type, count, prestime, rtry, text, name);
E 2
	fclose(fp);
D 5
	return;
E 5
}

D 5
/***
 *	rmstat(name)	remove system status entry
 *	char *name;
E 5
I 5
/*
 *	remove system status entry
E 5
 *
 *	return codes:  none
 */
D 5

E 5
rmstat(name)
char *name;
{
	char filename[MAXFULLNAME];

	STATNAME(filename, name);
	unlink(filename);
}

D 4
/***
 *	callok(name)	check system status for call
 *	char *name;
E 4
I 4
/*
 *	check system status for call
E 4
 *
 *	return codes  0 - ok | >0 system status
 */
D 5

E 5
callok(name)
char *name;
{
	char filename[MAXFULLNAME], line[S_SIZE];
	register FILE *fp;
D 2
	time_t lasttime, prestime;
	long retrytime;
E 2
I 2
	time_t lasttime, prestime, retrytime;
	long t1, t2;
E 2
	int count, type;

	STATNAME(filename, name);
	fp = fopen(filename, "r");
	if (fp == NULL)
		return(SS_OK);

	if (fgets(line, S_SIZE, fp) == NULL) {
		/*  no data  */
		fclose(fp);
		unlink(filename);
		return(SS_OK);
	}

	fclose(fp);
	time(&prestime);
D 2
	sscanf(line, "%d%d%ld%ld", &type, &count, &lasttime, &retrytime);
E 2
I 2
	sscanf(line, "%d%d%ld%ld", &type, &count, &t1, &t2);
	lasttime = t1;
	retrytime = t2;
E 2

	switch(type) {
	case SS_BADSEQ:
	case SS_CALLBACK:
	case SS_NODEVICE:
	case SS_INPROGRESS:	/*let LCK take care of it */
		return(SS_OK);

	case SS_FAIL:
		if (count > MAXRECALLS) {
			logent("MAX RECALLS", "NO CALL");
			DEBUG(4, "MAX RECALL COUNT %d\n", count);
D 2
			return(type);
E 2
I 2
			if (Debug) {
				logent("debugging", "continuing anyway");
				return SS_OK;
			}
			return type;
E 2
		}

		if (prestime - lasttime < retrytime) {
			logent("RETRY TIME NOT REACHED", "NO CALL");
D 2
			DEBUG(4, "RETRY TIME (%d) NOT REACHED\n", (long)  RETRYTIME);
			return(type);
E 2
I 2
			DEBUG(4, "RETRY TIME (%ld) NOT REACHED\n", retrytime);
			if (Debug) {
				logent("debugging", "continuing anyway");
				return SS_OK;
			}
			return type;
E 2
		}

D 2
		return(SS_OK);
E 2
I 2
		return SS_OK;
E 2
	default:
D 2
		return(SS_OK);
E 2
I 2
		return SS_OK;
E 2
	}
}
E 1
