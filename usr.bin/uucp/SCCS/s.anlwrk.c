h47988
s 00004/00004/00326
d D 5.7 88/04/05 12:01:55 rick 7 6
c use syslog for errors
e
s 00067/00099/00263
d D 5.6 88/02/24 19:46:08 rick 6 5
c totally rewrite directory scanning code for 50-1 speedup
e
s 00010/00002/00352
d D 5.5 85/06/19 17:25:53 bloom 5 4
c fixes from rick adams
e
s 00058/00089/00296
d D 5.4 85/04/10 15:17:39 ralph 4 3
c more changes from rick adams.
e
s 00063/00065/00322
d D 5.3 85/01/22 12:28:32 ralph 3 2
c bug fixes & changes from Rick Adams
e
s 00001/00001/00386
d D 5.2 83/07/02 18:05:21 sam 2 1
c include fixes
e
s 00387/00000/00000
d D 5.1 83/07/02 17:56:17 sam 1 0
c date and time created 83/07/02 17:56:17 by sam
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

#include "uucp.h"
D 4
#include <sys/types.h>
E 4
#include <sys/stat.h>
I 3
#include "uust.h"
E 3
#ifdef	NDIR
#include "ndir.h"
#else
D 2
#include <dir.h>
E 2
I 2
#include <sys/dir.h>
E 2
#endif
I 4
#include <ctype.h>
E 4

D 4
/* Re-written to be reasonable
 * Mon Nov 15 17:19:52 EST 1982
 * Alan S. Watt (ittvax!swatt)
 *
 * Tom Truscott (rti!trt):
 * Priority ordering cleaned up.  New 'pcompar' subroutine.
 * 'stat' removed (speeds things up).
 * Possible infinite loop in gtwvec defended against.
 * Feb 23, 1983
 *
 * Changes:
 *
 *  1)	The check for work is much faster; the first filename
 *	that matches the prefix causes a "yes" return.
 *
 *  2)	The filename is not "stat" ed , so
 *	there is no massive delay while the list of potential
 *	names is built.
 *
 *  3)	Requesting work for a new system is now detected so
 *	internal variables are re-initialized properly.  In
 *	particular, the stream pointer for the current work
 *	file is properly closed so work for a system which
 *	hangs up will not be sent to the next system called.
 *
 * Fri Dec  3 09:31:45 EST 1982
 *
 *  5)	As new work files are requested, a check is made
 *	every TLIMIT seconds (5 minutes at present) to see
 *	if new files have entered the spool area.  Since
 *	work file names are now cached up to LLEN, this can
 *	represent a very long transmission time before new
 *	work enters the list to be processed.  If people want
 *	to use the "grade" character to specify a higher
 *	priority, the list must be re-built and re-sorted for
 *	higher priority stuff to have an immediate effect.
 */


E 4
D 3
#define LLEN 20
#define MAXRQST 250
E 3
D 6
#define TLIMIT	(5*60L)
E 6
I 6
#define TLIMIT	(15*60L)
E 6
#define NITEMS(X)	(sizeof (X) / sizeof ((X)[0]))

D 3
/* These are all used only locally
 */
static	int Nfiles = 0;
static	char Filent[LLEN][NAMESIZE];
E 3
I 3
int Nfiles = 0;
char Filent[LLEN][NAMESIZE];
I 4
long fseek(), ftell();
extern int TransferSucceeded;
E 4
E 3

I 5
/*LINTLIBRARY*/

E 5
D 4
/*******
 *	anlwrk(file, wvec)	create a vector of command arguments
 *	char *file, **wvec;
E 4
I 4
/*
 *	create a vector of command arguments
E 4
 *
 *	return codes:
 *		0  -  no more work in this file
 *		positive number  -  number of arguments
 */

/* LOCAL only */
int
anlwrk(file, wvec)
register char *file, **wvec;
{
D 4
	static char str[MAXRQST];
E 4
I 4
D 5
	static char str[MAXRQST], nstr[MAXRQST];
E 5
I 5
	static char str[MAXRQST], nstr[MAXRQST], lastfile[MAXFULLNAME] = "";
E 5
E 4
	static FILE *fp = NULL;
I 4
	static long nextread, nextwrite;
E 4

D 3
	/* If called with a null string, force a shutdown
E 3
I 3
	/*
	 * If called with a null string, force a shutdown
E 3
	 * of the current work file.
D 3
	 * John Levine, ima.247, related change in cntl.c
E 3
	 */
	if (file[0] == '\0') {
		if (fp != NULL)
			fclose (fp);
		fp = NULL;
D 3
		return(0);
E 3
I 3
		return 0;
E 3
	}
	if (fp == NULL) {
I 5
		if (strncmp(file, lastfile, MAXFULLNAME) == 0) { 
			DEBUG(5,"Workfilename repeated: %s\n", file);
			return 0;
		}
		strncpy(lastfile, file, MAXFULLNAME);
E 5
D 4
		fp = fopen(subfile(file), "r");
E 4
I 4
		fp = fopen(subfile(file), "r+w");
E 4
		if (fp == NULL) {
I 4
			char *bnp, rqstr[MAXFULLNAME];
			bnp = rindex(file, '/');
			sprintf(rqstr, "%s/%s", CORRUPT, bnp ? bnp + 1 : file);
			xmv(file, rqstr);
D 5
			logent(file, "CMD FILE UNREADABLE");
E 5
I 5
D 6
			logent(subfile(file), "CMD FILE UNREADABLE");
E 6
I 6
D 7
			assert("CMD FILE UNREADABLE", subfile(file), 0);
E 7
I 7
			syslog(LOG_WARNING, "fopen(%s) failed: %m",
				subfile(file));
E 7
E 6
E 5
E 4
D 3
			unlink(subfile(file));	/* Try to zap the thing. rti!trt */
			return(0);
E 3
I 3
			unlink(subfile(file));
			return 0;
E 3
		}
I 3
		Usrf = 0;
I 4
		nstr[0] = '\0';
		nextread = nextwrite = 0L;
E 4
E 3
	}

D 4
	/* This is what deletes the current work file when EOF
	 * is reached.  As this is called from gtwvec, which is
	 * in turn called externally, it is not possible to save
	 * "C." files in case of error, except for line errors,
	 * which shuts down the whole system.
	 */
	if (fgets(str, MAXRQST, fp) == NULL) {
		fclose(fp);
		unlink(subfile(file));
I 3
		USRF(USR_COMP);
		US_RRS(file, Usrf);
		Usrf = 0;
E 3
		file[0] = '\0';
		fp = NULL;
D 3
		return(0);
E 3
I 3
		return 0;
E 4
I 4
	if (nstr[0] != '\0' && TransferSucceeded) {
		fseek(fp, nextwrite, 0);
		fputs(nstr, fp);
		fseek(fp, nextread, 0);
E 4
E 3
	}
I 4

	do {
		nextwrite = ftell(fp);
		if (fgets(str, MAXRQST, fp) == NULL) {
			fclose(fp);
			if (TransferSucceeded)
				unlink(subfile(file));
			USRF(USR_COMP);
			US_RRS(file, Usrf);
			Usrf = 0;
			file[0] = '\0';
I 5
			nstr[0] = '\0';
E 5
			fp = NULL;
			return 0;
		}
	} while (!isupper(str[0]));

	nextread = ftell(fp);
	strncpy(nstr, str, MAXRQST);
	nstr[0] = tolower(nstr[0]);
E 4
D 3
	return(getargs(str, wvec));
E 3
I 3
	return getargs(str, wvec, 20);
E 3
}


D 4
/***
 *	bldflst - build list of work files for given system
 *	 Nfiles, Filent are global
E 4
I 4
/*
 *	build list of work files for given system
E 4
 *
 *	return value - 1 if work was found, else 0
 *
D 4
 * Jul 26 19:17 1982 (ittvax!swatt). fixed this obnoxious
 * routine to NOT read all the way through the damned directory
 * "stat"'ing every file in sight just to get 10 names!!!
 *
 * It still reads through the directory from the beginning until
 * the list is filled, but this is only once every LLEN names.
E 4
 */

/* LOCAL only */
int
bldflst (reqst, dir, pre)
char *reqst;
register char *dir, *pre;
{
	static DIR  *dirp = NULL;
D 6
	register nfound;
D 3
	char filename[NAMESIZE];	/* @@@ NB: this needs new dir stuff */
E 3
I 3
	char filename[NAMESIZE];
E 3
	int plen = strlen (pre);
I 3
	int flen;
E 6
I 6
	register struct direct *dentp;
	register int i;
	int plen = strlen(pre);
E 6
	extern char MaxGrade;
E 3

	if (dirp == NULL) {
D 3
		if ((dirp = opendir(subdir(dir,pre[0]), "r")) == NULL)
			return(0);
E 3
I 3
		if ((dirp = opendir(subdir(dir,pre[0]))) == NULL) {
			DEBUG(1,"opendir(%s) FAILS\n",subdir(dir,pre[0]));
			return 0;
		}
E 3
D 6
	}
	else
E 6
I 6
	} else
E 6
		rewinddir(dirp);
D 6
	for (nfound = 0, Nfiles = 0; gnamef(dirp, filename);) {
E 6
I 6

	Nfiles = 0;
	while ((dentp = readdir(dirp)) != NULL && Nfiles < LLEN) {
E 6
		/* Check for two systems with the same prefix.
		 * Magic number "5" is 1 for "grade" character plus
		 * 4 for sequence number.  The point here is to not
		 * send work for a system which has as a prefix the
		 * name of the system called for.
		 * Special case: prefix "X." does not do this check
		 * so uuxqt can use bldflst.
		 */
D 3
		if (!prefix(pre, filename)
		 || (plen != 2 && strlen(filename)-plen != 5))
E 3
I 3
D 6
		flen = strlen(filename);
		if (!prefix(pre, filename) || (plen != 2 && flen-plen != 5)) {
			DEBUG(99,"bldflst rejects %s\n",filename);
E 6
I 6
		if (!prefix(pre, dentp->d_name) ||
			(plen != 2 && (dentp->d_namlen-plen) != 5)) {
			DEBUG(99,"bldflst rejects %s\n",dentp->d_name);
E 6
E 3
			continue;
I 3
		}
D 6
		if (filename[flen-5] > MaxGrade ) {
			DEBUG(8,"bldflst rejects %s, grade too low\n",filename);
E 6
I 6
		if (dentp->d_name[dentp->d_namlen-5] > MaxGrade) {
			DEBUG(8, "bldflst rejects %s, grade too low\n",
				dentp->d_name);
E 6
			continue;
		}
E 3
D 6
		nfound++;
E 6
		if (*reqst == 'c')
D 3
			return (1);
E 3
I 3
			return 1;
E 3
D 6
		entflst(filename);
	}
D 3
	return (nfound? 1: 0);
E 3
I 3
	return  nfound? 1: 0;
E 3
}
E 6

D 4
/***
 *	entflst - put new name if list is not full
 *		  or new name is less than the MAX
E 4
I 4
D 6
/*
 *	put new name if list is not full  or new name is less than the MAX
E 4
 *		  now in the list.
D 4
 *	Nfiles, Filent[] are modified.
 *	return value - none
E 4
 *
 */
E 6
I 6
		/* locate position for the new file and make room for it */
		for (i = Nfiles; i > 0; i--) {
			if (pcompar(dentp->d_name, Filent[i-1]) <= 0)
				break;
			if (i <LLEN)
				strcpy(Filent[i], Filent[i-1]);
		}
E 6

D 6
/* LOCAL only */
int
entflst(file)
D 3
char *file;
E 3
I 3
register char *file;
E 3
{
	register int i;
E 6
I 6
		/* add new file (if there is room), and increase Nfiles if need be */
		if (i < LLEN) {
			DEBUG(99,"bldflst accepts %s",dentp->d_name);
			DEBUG(99," as Filent[%d]\n", i);
			strcpy(Filent[i], dentp->d_name);
			if (Nfiles < LLEN)
				Nfiles++;
		} else
			DEBUG(99,"Filent full, %s rejected by bldflst\n", dentp->d_name);
		
E 6
D 3
	register char *p;
E 3

D 3
	/* If there is room in the table, just add it. */
	if (Nfiles < LLEN) {
		strcpy(Filent[Nfiles++], file);
		return;
E 3
I 3
D 6
	/* locate position for the new file and make room for it */
	for (i = Nfiles; i > 0; i--) {
D 4
		if (pcompar(file, Filent[i-1]) >= 0)
E 4
I 4
		if (pcompar(file, Filent[i-1]) <= 0)
E 4
			break;
		if (i <LLEN)
			strcpy(Filent[i], Filent[i-1]);
E 6
E 3
	}
I 6
	if (Debug >99)
		for(i=0;i<Nfiles;i++)
			fprintf(stderr,"Filent[%d]=%s\n",i,Filent[i]);
E 6

D 3
	/* Find lowest priority file in table  */
	p = Filent[0];
	for (i = 1; i < Nfiles; i++)
		if (pcompar(Filent[i], p) < 0)
			p = Filent[i];

	/*
	 * If new candidate is of higher priority
	 * that the lowest priority file in the table,
	 * replace the table entry.
	 */
	if (pcompar(p, file) < 0)
		strcpy(p, file);
E 3
I 3
D 6
	/* add new file (if there is room), and increase Nfiles if need be */
	if (i < LLEN) {
		strcpy(Filent[i], file);
		if (Nfiles < LLEN)
			Nfiles++;
	}
E 6
I 6
	return Nfiles > 0;
E 6
E 3
}

/*
  Compare priority of filenames p1 and p2.  Return:
 *	< 0	if p1 "has lower priority than" p2.
 *	= 0	if p1 "has priority equal to" p2.
 *	> 0	if p1 "has greater priority than" p2.
 * Priority:
 *	lower grade wins.
 *	lower sequence number wins (unless wrap-around is suspected).
 *
 */
/* LOCAL only */
D 7
int
E 7
pcompar(p1, p2)
register char *p1, *p2;
{
	register int rc;

D 7
	/* assert: strlen(p1) and strlen(p2) are >= 5 */
E 7
I 7
	/* strlen(p1) and strlen(p2) are >= 5 */
E 7
	p1 += strlen(p1)-5;
	p2 += strlen(p2)-5;
	/* check 'grade' */
	if (rc = *p2++ - *p1++)
D 3
		return(rc);
E 3
I 3
		return rc;
E 3
	/* check for  sequence wrap-around */
	if (rc = *p2++ - *p1++)
		if (rc < -10 || rc > 10)
D 3
			return(-rc);
E 3
I 3
			return -rc;
E 3
		else
D 3
			return(rc);
E 3
I 3
			return rc;
E 3
	/* check remaining digits */
D 3
	return(strcmp(p2, p1));
E 3
I 3
	return strcmp(p2, p1);
E 3
}

D 4
/***
 *	gtwrkf - get next work file
 *	 Nfiles, Filent[] are modified.
E 4
I 4
/*
D 6
 *	get next work file
E 4
 *
 *	return value:
 *
 *		0  - No file gotten
 *		1  - File successfully gotten.
 *
 */

/* LOCAL only */
gtwrkf(dir, file)
char *file, *dir;
{
D 3
	register char *p;
	register int i;

	if (Nfiles == 0)
		return(0);
	/* Find highest priority file in table */
	p = Filent[0];
	for (i = 1; i < Nfiles; i++) 
		if (pcompar(Filent[i], p) > 0)
			p = Filent[i];
	sprintf(file, "%s/%s", dir, p);
	strcpy(p, Filent[--Nfiles]);
	return(1);
E 3
I 3
D 4
	if (Nfiles <= 0)
E 4
I 4
	register int i;

	if (Nfiles-- <= 0) {
		Nfiles = 0;
E 4
		return 0;
D 4
	sprintf(file, "%s/%s", dir, Filent[--Nfiles]);
E 4
I 4
	}
	sprintf(file, "%s/%s", dir, Filent[0]);
	for (i=0; i<Nfiles;i++)
		strcpy(Filent[i], Filent[i+1]);
E 4
	return 1;
E 3
}

D 4
/***
D 3
 *	gtwvec(file, dir, wkpre, wrkvec)	get work vector 
E 3
I 3
 *	gtwvec(file, dir, wkpre, wrkvec)	get work vector
E 3
 *	char *file, *dir, *wkpre, **wrkvec;
E 4
I 4
/*
E 6
 *	get work vector
E 4
 *
 *	return codes:
 *		positive number  -  number of arguments
 *		0 -  no arguments - fail
 */

/* EXTERNALLY CALLED */
int
gtwvec(file, dir, wkpre, wrkvec)
char *dir, *wkpre, **wrkvec;
register char *file;
{
	register int nargs, n;

D 3
	n = 0;		/* Break possible infinite loop.  rti!trt */
E 3
I 3
	n = 0;
E 3
	while ((nargs = anlwrk(file, wrkvec)) == 0) {
		if (++n > 3 || !iswrk(file, "get", dir, wkpre))
D 3
			return(0);
E 3
I 3
			return 0;
E 3
	}
D 3
	return(nargs);
E 3
I 3
	return nargs;
E 3
}

D 4
/***
 *	iswrk(file, reqst, dir, pre)
 *	char *file, *reqst, *dir, *pre;
 *
E 4
I 4
/*
E 4
 *	iswrk  -  this routine will check the work list (list).
 *	If it is empty or the present work is exhausted, it
 *	will call bldflst to generate a new list.
 *	The "reqst" field will be the string "chk" or "get" to
 *	check for work, or get the next work file respectively.
 *
 *	return codes:
 *		0  -  no more work (or some error)
 *		1  -  there is work
 *
 */

/* EXTERNALLY CALLED */
int
iswrk(file, reqst, dir, pre)
register char *file, *reqst, *dir, *pre;
{
	static char *lastpre = 0;
D 6
	register ret;
E 6
I 6
	register ret = 0;
	int i;
E 6

	/* Starting new system; re-init */
D 6
	if (lastpre == 0 || strcmp(lastpre,pre) != 0) {
		anlwrk ("", (char **)0);	/* Force close of work file */
E 6
I 6
	if (lastpre == 0 || strcmp(lastpre, pre) != SAME) {
		/* Force close of work file */
		anlwrk("", (char **)0);
E 6

		/* Save last worked-on prefix */
		if (lastpre != 0)
D 6
			free (lastpre);
E 6
I 6
			free(lastpre);
E 6
		lastpre = malloc((unsigned)(strlen(pre)+1));
D 6
		strcpy (lastpre, pre);
E 6
I 6
		strcpy(lastpre, pre);
E 6

D 6
		/* Set the external indexes properly
		 */
E 6
I 6
		/* Set the external indexes properly */
E 6
		Nfiles = 0;
	}

D 6
	/* If the list is empty or new files have entered
E 6
I 6
	/*
	 * If the list is empty or new files have entered
E 6
	 * the spool area, call "bldflst" to read
D 6
	 * some file names into it.  Because names can
	 * be put in the list that later turn out to
	 * be unusable (from "gtwrkf"), this operation
	 * continues until either "bldflst" can't find
	 * any new files, or "gtwrkf" signals success.
E 6
I 6
	 * some file names into it. 
E 6
	 */
D 6
	for (;;) {
		ret = 0;
D 3
		if (Nfiles == 0 || newspool((time_t)TLIMIT))
E 3
I 3
D 4
		if (Nfiles == 0 || newspool((time_t)TLIMIT)) {
E 4
I 4
		if (Nfiles <= 0 || newspool((time_t)TLIMIT)) {
E 4
E 3
			ret = bldflst (reqst, dir, pre);
I 3
			DEBUG(99,"bldflst returns %d\n",ret);
		}
E 6
I 6
	if (Nfiles <= 0 || newspool((time_t)TLIMIT)) {
		ret = bldflst(reqst, dir, pre);
		DEBUG(99, "bldflst returns %d\n", ret);
	}
E 6
E 3

D 6
		/* If they only wanted to check, return
		 * boolean list not empty.  NB: the list
		 * will be forcibly emptied as soon as
		 * a new system name is mentioned.
		 */
		if (*reqst == 'c')
D 3
			return (ret);
E 3
I 3
			return ret;
E 6
I 6
	/* If they only wanted to check, return
	 * boolean list not empty.  NB: the list
	 * will be forcibly emptied as soon as
	 * a new system name is mentioned.
	 */
	if (*reqst == 'c')
		return ret;
E 6
E 3

D 4
		if (Nfiles == 0)
E 4
I 4
D 6
		if (Nfiles <= 0)
E 4
D 3
			return(0);
E 3
I 3
			return 0;
E 3

		if (gtwrkf(dir, file))
D 3
			return (1);
E 3
I 3
			return 1;
E 6
I 6
	if (Nfiles-- <= 0) {
		/* Didn't find any files in the spool area */
		Nfiles = 0;
		return 0;
E 6
E 3
	}
I 6
	/* Found some files, return the first one */
	sprintf(file, "%s/%s", dir, Filent[0]);
	for (i = 0; i < Nfiles; i++)
		strcpy(Filent[i], Filent[i+1]);
	return 1;
E 6
}

/* Return non-zero if there is new work in the spool
 * area since last check.  Assumes that if the sequence
 * file has been modified, there is new work. This is
 * not absolutely correct, but should be close enough.
 * Only checks every <limit> seconds at most.  Called
 * from "iswrk()" when a new work file is requested.
 */
/* LOCAL only */
int
newspool(limit)
time_t	limit;
{
	static time_t lastcheck = 0, lastmod = 0;
	time_t check;
	struct stat mod;
	register int ret = 0;

	/* (void) */ time (&check);
	if (check - lastcheck > limit || lastcheck - check > limit) {
		mod.st_mtime = 0;
		/* (void) */ stat (SEQFILE, &mod);
		if (mod.st_mtime != lastmod)
			ret = 1;
		lastmod = mod.st_mtime;
	}
	lastcheck = check;
D 3
	return (ret);
E 3
I 3
	return ret;
E 3
}
E 1
