h23443
s 00001/00001/00205
d D 5.7 88/04/24 16:51:07 bostic 7 6
c fix for ANSI C
e
s 00015/00005/00191
d D 5.6 88/04/05 12:20:00 rick 6 5
c use syslog for errors
e
s 00083/00143/00113
d D 5.5 85/10/09 16:18:42 bloom 5 4
c still more changes from rick@seismo
e
s 00008/00008/00248
d D 5.4 85/06/23 13:11:25 bloom 4 3
c fixes from rick adams
e
s 00005/00004/00251
d D 5.3 85/04/10 15:21:11 ralph 3 2
c more changes from rick adams.
e
s 00078/00067/00177
d D 5.2 85/01/22 14:11:23 ralph 2 1
c bug fixes and changes from Rick Adams
e
s 00244/00000/00000
d D 5.1 83/07/02 17:57:39 sam 1 0
c date and time created 83/07/02 17:57:39 by sam
e
u
U
t
T
I 1
#ifndef lint
D 6
static char sccsid[] = "%W% (Berkeley) %G%";
E 6
I 6
static char sccsid[] = "%W%	(Berkeley) %G%";
E 6
#endif

#include "uucp.h"
D 3
#include <sys/types.h>
E 3
#include <sys/stat.h>
I 5
#include <errno.h>
E 5

D 2

E 2
D 4
extern time_t	time();

E 4
D 5
/* File mode for lock files */
#define	LCKMODE	0444
E 5
I 5
#define	LCKMODE	0444	/* File mode for lock files */
#define MAXLOCKS 16	/* Maximum number of lock files */
E 5

I 5
char *Lockfile[MAXLOCKS];
char *LockDirectory = LOCKDIR;
int Nlocks = 0;
I 7
extern int errno;
E 7

E 5
I 4
/*LINTLIBRARY*/

E 4
D 2
/*******
 *	ulockf(file, atime)
 *	char *file;
 *	time_t atime;
 *
E 2
I 2
/*
E 2
D 4
 *	ulockf  -  this routine will create a lock file (file).
E 4
I 4
D 5
 *	this routine will create a lock file (file).
E 4
 *	If one already exists, the create time is checked for
 *	older than the age time (atime).
 *	If it is older, an attempt will be made to unlink it
 *	and create a new one.
E 5
I 5
 *	This routine will attempt to create a lock file (file).
 *	It makes sure that the lock file is valid if it already exists.
E 5
 *
D 4
 *	return codes:  0  |  FAIL
E 4
I 4
 *	return codes:  SUCCESS  |  FAIL
E 4
 */
D 5

E 5
D 3
ulockf(file, atime)
register char *file;
E 3
I 3
ulockf(hfile, atime)
char *hfile;
E 3
time_t atime;
{
D 5
	struct stat stbuf;
	time_t ptime;
	register int ret;
	static int pid = -1;
E 5
I 5
	register char *p;
	register int i;
E 5
	static char tempfile[NAMESIZE];
I 3
	char file[NAMESIZE];
I 5
	static int pid = -1;
D 7
	extern int errno;
E 7
E 5
E 3

	if (pid < 0) {
		pid = getpid();
D 2
		sprintf(tempfile, "LTMP.%d", pid);
E 2
I 2
D 5
		sprintf(tempfile, "%s/LTMP.%d", LOCKDIR, pid);
E 5
I 5
		sprintf(tempfile, "%s/LTMP.%d", LockDirectory, pid);
E 5
E 2
	}
I 3
D 5
	sprintf(file, "%s/%s", LOCKDIR, hfile);
E 3
	if (onelock(pid, tempfile, file) == -1) {
		/* lock file exists */
E 5
I 5
	sprintf(file, "%s/LCK..%s", LockDirectory, hfile);
	i = 0;
	while (onelock(pid, tempfile, file) == -1) { /* lock file exists */
#if !defined(BSD4_2) && !defined(USG)
		struct stat stbuf;
		time_t ptime;
E 5
		/* get status to check age of the lock file */
D 5
		ret = stat(file, &stbuf);
		if (ret != -1) {
			time(&ptime);
			if ((ptime - stbuf.st_ctime) < atime) {
				/* file not old enough to delete */
D 2
				return(FAIL);
E 2
I 2
				return FAIL;
E 2
			}
I 2
			ret = unlink(file);
			logent(file, "DEAD LOCK");
			sleep(5);	/* rti!trt: avoid a race */
			ret = onelock(pid, tempfile, file);
E 5
I 5
		if (stat(file, &stbuf) == 0) {
			(void) time(&ptime);
			if ((ptime - stbuf.st_ctime) < atime)
				return FAIL; /* file not old enough to delete */
E 5
E 2
		}
D 2
		ret = unlink(file);
		ret = onelock(pid, tempfile, file);
E 2
D 5
		if (ret != 0)
D 2
			return(FAIL);
E 2
I 2
			return FAIL;
E 5
I 5
#else	BSD4_2 || USG
		register int fd;
		fd = open(file, 0);
		if (fd >= 0) {
			int upid, ret;
			ret = read(fd, &upid, sizeof upid);
			close(fd);
			if (ret == sizeof upid && (kill(upid, 0) == 0
				|| errno != ESRCH))
				return FAIL; /* process is still running */
		}
#endif BSD4_2 || USG
D 6
		assert("DEAD LOCK", file, errno);
E 6
I 6
		syslog(LOG_WARNING, "%s: dead lock %s", Rmtname, file);
E 6
		logent(file, "DEAD LOCK");
		(void) unlink(file);
		sleep(5);	/* avoid a possible race */
D 6
		ASSERT(i++ < 5, "CAN'T GET LOCKFILE", tempfile, errno);
E 6
I 6
		if (i++ >= 5) {
			syslog(LOG_ERR, "%s: can't get lockfile %s: %m",
				Rmtname, tempfile);
			cleanup(FAIL);
		}
E 6
E 5
E 2
	}
D 5
	stlock(file);
D 2
	return(0);
E 2
I 2
	return SUCCESS;
E 2
}
E 5

D 5

#define MAXLOCKS 10	/* maximum number of lock files */
char *Lockfile[MAXLOCKS];
int Nlocks = 0;

/***
 *	stlock(name)	put name in list of lock files
 *	char *name;
 *
 *	return codes:  none
 */

stlock(name)
register char *name;
{
	register char *p;
	register int i;

E 5
	for (i = 0; i < Nlocks; i++) {
		if (Lockfile[i] == NULL)
			break;
	}
D 2
	ASSERT(i < MAXLOCKS, "TOO MANY LOCKS", "", i);
E 2
I 2
D 6
	ASSERT(i < MAXLOCKS, "TOO MANY LOCKS", CNULL, i);
E 6
I 6
	if (i >= MAXLOCKS) {
		syslog(LOG_ERR, "Too many locks");
		cleanup(FAIL);
	}
E 6
E 2
	if (i >= Nlocks)
		i = Nlocks++;
D 5
	p = calloc((unsigned)(strlen(name)+1), sizeof (char));
	ASSERT(p != NULL, "CAN NOT ALLOCATE FOR", name, 0);
	strcpy(p, name);
E 5
I 5
	p = malloc((unsigned)(strlen(file)+1));
D 6
	ASSERT(p != NULL, "CAN NOT ALLOCATE FOR", file, 0);
E 6
I 6
	if (p == NULL) {
		syslog(LOG_ERR, "malloc failed: %m");
		cleanup(FAIL);
	}
E 6
	strcpy(p, file);
E 5
	Lockfile[i] = p;
I 5

	return SUCCESS;
E 5
D 4
	return;
E 4
}

D 5

E 5
D 2
/***
 *	rmlock(name)	remove all lock files in list
 *	char *name;	or name
E 2
I 2
/*
D 5
 *	remove all lock files in list *	or name
E 2
 *
 *	return codes: none
E 5
I 5
 *	remove all lock files in list or name
E 5
 */
D 5

E 5
rmlock(name)
register char *name;
{
	register int i;
I 5
	char file[MAXFULLNAME];
E 5

I 5
	if (name != NULL) {
		sprintf(file, "%s/LCK..%s", LockDirectory, name);
		name = file;
	}
E 5
	for (i = 0; i < Nlocks; i++) {
		if (Lockfile[i] == NULL)
			continue;
D 2
		if (name == NULL
		|| strcmp(name, Lockfile[i]) == SAME) {
E 2
I 2
		if (name == NULL || strcmp(name, Lockfile[i]) == SAME) {
E 2
			unlink(Lockfile[i]);
			free(Lockfile[i]);
			Lockfile[i] = NULL;
		}
	}
D 2
	return;
E 2
}

D 2

E 2
/*
D 2
 *  this stuff from pjw 
 *  /usr/pjw/bin/recover - Check pids to remove unnecessary locks.
E 2
D 5
 *	isalock(name) returns 0 if the name is a lock.
 *	unlock(name)  unlocks name if it is a lock.
 *	onelock(pid,tempfile,name) makes lock a name
 *	on behalf of pid.  Tempfile must be in the same
E 5
I 5
 *	makes lock a name on behalf of pid. Tempfile must be in the same
E 5
 *	file system as name.
D 5
 *	lock(pid,tempfile,names) either locks all the
 *	names or none of them.
E 5
 */
D 2
isalock(name) char *name;
E 2
I 2
D 5
isalock(name)
char *name;
E 2
{
	struct stat xstat;
D 2
	if(stat(name,&xstat)<0) return(0);
	if(xstat.st_size!=sizeof(int)) return(0);
	return(1);
E 2
I 2
	if (stat(name,&xstat) < 0)
		return 0;
	if (xstat.st_size != sizeof(int))
		return 0;
	return 1;
E 2
}
D 2
unlock(name) char *name;
E 2
I 2
unlock(name)
char *name;
E 2
{
D 2
	if(isalock(name)) return(unlink(name));
	else return(-1);
E 2
I 2
	if (isalock(name))
		return unlink(name);
	else
		return -1;
E 2
}
E 5
D 2
onelock(pid,tempfile,name) char *tempfile,*name;
{	register int fd;
	fd=creat(tempfile,LCKMODE);
	if(fd<0) return(-1);
	write(fd,(char *) &pid,sizeof(int));
E 2
I 2
D 4
onelock(pid,tempfile,name)
E 4
I 4
onelock(pid, tempfile, name)
int pid;
E 4
D 5
char *tempfile,*name;
E 5
I 5
char *tempfile, *name;
E 5
{
D 5
	register int fd;
E 5
I 5
	register int fd, ret;
E 5
#ifdef VMS
	fd = creat(name, LCKMODE, "1version");
#else !VMS
	fd = creat(tempfile, LCKMODE);
#endif !VMS
D 4
	if (fd<0)
E 4
I 4
D 5
	if (fd < 0)
E 5
I 5
	if (fd < 0) {
		DEBUG(1,"Can't creat temp file %s ", tempfile);
		DEBUG(1,"-- errno %d", errno);
E 5
E 4
		return FAIL;
D 4
	write(fd, (char *) &pid, sizeof(int));
E 4
I 4
D 5
	write(fd, (char *)&pid, sizeof(int));
E 4
E 2
	close(fd);
D 2
	if(link(tempfile,name)<0)
	{	unlink(tempfile);
		return(-1);
E 2
I 2
#ifndef	VMS
E 5
I 5
	}
	ret = write(fd, (char *)&pid, sizeof(int));
	(void) close(fd);

	if (ret != sizeof(int)) {
		DEBUG(1,"Temp file write failed -- errno %d\n", errno);
#ifdef VMS
		(void) unlink(name);
#else !VMS
		(void) unlink(tempfile);
#endif !VMS
		return FAIL;
	}
#ifndef VMS
E 5
	if (link(tempfile, name) < 0) {
D 5
		unlink(tempfile);
E 5
I 5
		(void) unlink(tempfile);
E 5
		return FAIL;
E 2
	}
	unlink(tempfile);
D 2
	return(0);
E 2
I 2
D 5
#endif
E 5
I 5
#endif	!VMS
E 5
	return SUCCESS;
E 2
}
D 2
lock(pid,tempfile,names) char *tempfile;
E 2
I 2

D 5

lock(pid, tempfile, names)
char *tempfile;
E 2
register char **names;
D 2
{	register int i,j;
	for(i=0;names[i]!=0;i++)
	{	if(onelock(pid,tempfile,names[i])==0) continue;
		for(j=0;j<i;j++) unlink(names[j]);
		return(-1);
E 2
I 2
{
	register int i, j;

	for(i=0; names[i] != 0; i++) {
		if (onelock(pid, tempfile, names[i]) == 0)
			continue;
		for(j=0; j < i ;j++)
			unlink(names[j]);
		return FAIL;
E 2
	}
D 2
	return(0);
E 2
I 2
	return SUCCESS;
E 2
}

#define LOCKPRE "LCK."

E 5
I 5
#if !defined(BSD4_2) && !defined(USG)
E 5
D 2
/***
 *	delock(s)	remove a lock file
 *	char *s;
 *
 *	return codes:  0  |  FAIL
E 2
I 2
/*
D 5
 *	remove a lock file
E 2
 */
D 2

E 2
delock(s)
char *s;
{
D 2
	char ln[30];
E 2
I 2
	char ln[NAMESIZE];
E 2

D 2
	sprintf(ln, "%s.%s", LOCKPRE, s);
E 2
I 2
	sprintf(ln, "%s/%s.%s", LOCKDIR, LOCKPRE, s);
E 2
	rmlock(ln);
}

D 2

/***
 *	mlock(sys)	create system lock
 *	char *sys;
E 2
I 2
/*
 *	create system lock
E 2
 *
D 2
 *	return codes:  0  |  FAIL
E 2
I 2
 *	return codes:  SUCCESS  |  FAIL
E 2
 */
D 2

E 2
mlock(sys)
char *sys;
{
D 2
	char lname[30];
	sprintf(lname, "%s.%s", LOCKPRE, sys);
	return(ulockf(lname, (time_t) SLCKTIME ) < 0 ? FAIL : 0);
E 2
I 2
	char lname[NAMESIZE];

D 3
	sprintf(lname, "%s/%s.%s", LOCKDIR, LOCKPRE, sys);
E 3
I 3
	sprintf(lname, "%s.%s", LOCKPRE, sys);
E 3
	return ulockf(lname, (time_t) SLCKTIME ) < 0 ? FAIL : SUCCESS;
E 2
}

D 2

E 2
/***
E 5
D 2
 *	ultouch()	update 'change' time for lock files
E 2
I 2
 *	update 'change' time for lock files
E 2
 *
D 2
 *	-- mod by rti!trt --
E 2
 *	Only update ctime, not mtime or atime.
 *	The 'chmod' method permits cu(I)-like programs
 *	to determine how long uucp has been on the line.
 *	The old "change access, mod, and change time" method
 *	can be had by defining OLDTOUCH
 *
 *	return code - none
 */

ultouch()
{
D 5
	time_t time();
E 5
	static time_t lasttouch = 0;
	register int i;
	struct ut {
		time_t actime;
		time_t modtime;
	} ut;

D 5
	ut.actime = time(&ut.modtime);
E 5
I 5
#ifdef USG
	time(&Now.time);
	t1.millitm = 0;
#else !USG
	ftime(&Now);
#endif !USG
	ut.actime = ut.modtime = Now.time;
E 5
	/* Do not waste time touching locking files too often */
	/* (But, defend against backward time changes) */
	if (ut.actime >= lasttouch && ut.actime < lasttouch+60)
		return;
	lasttouch = ut.actime;
	DEBUG(4, "ultouch\n", 0);

	for (i = 0; i < Nlocks; i++) {
		if (Lockfile[i] == NULL)
			continue;
#ifdef	OLDTOUCH
		utime(Lockfile[i], &ut);
D 2
#else
E 2
I 2
#else 	!OLDTOUCH
E 2
		chmod(Lockfile[i], LCKMODE);
D 2
#endif
E 2
I 2
#endif !OLDTOUCH
D 5
	/*
	 * set 'nologinflag' if the file /etc/nologin exists.
	 * This permits graceful shutdown of uucp.
	 */
	if (nologinflag == 0 && access(NOLOGIN, 0) == 0)
		nologinflag = 1;
E 5
E 2
	}
}
I 5
#endif !BSD4_2 && ! USG
E 5
E 1
