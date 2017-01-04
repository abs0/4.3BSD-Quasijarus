h58374
s 00010/00003/00246
d D 5.5 88/04/05 12:02:11 rick 5 4
c use syslog for errors
e
s 00008/00010/00241
d D 5.4 85/06/19 17:39:31 bloom 4 3
c fixes from rick adams
e
s 00013/00006/00238
d D 5.3 85/04/10 15:18:01 ralph 3 2
c more changes from rick adams.
e
s 00026/00048/00218
d D 5.2 85/01/22 12:28:53 ralph 2 1
c bug fixes & changes from Rick Adams
e
s 00266/00000/00000
d D 5.1 83/07/02 17:56:24 sam 1 0
c date and time created 83/07/02 17:56:24 by sam
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

D 2
/*
 * Doug Kingston, 30 July 82 to fix handling of the "userpath" structures.
 * (brl-bmd) 
 * rti!trt: the code here is bizarre.  There must be a zillion holes.
 * chkpth should not be called for implied Spool requests .
 * But explicit requests (foo!/usr/spoo/uucp/*) should use chkpth.
 */
E 2
#include "uucp.h"
D 3
#include <sys/types.h>
E 3
#include <sys/stat.h>

D 2

E 2
struct userpath {
	char *us_lname;
	char *us_mname;
	char us_callback;
	char **us_path;
	struct userpath *unext;
};
I 5

E 5
struct userpath *Uhead = NULL;
struct userpath *Mchdef = NULL, *Logdef = NULL;
int Uptfirst = 1;

D 2

E 2
D 4
/*******
 *	chkpth(logname, mchname, path)
 *	char *path, *logname, *mchname;
 *
 *	chkpth  -  this routine will check the path table for the
E 4
I 4
/*LINTLIBRARY*/

/*
 *	this routine will check the path table for the
E 4
 *	machine or log name (non-null parameter) to see if the
D 4
 *	input path (path)
 *	starts with an acceptable prefix.
E 4
I 4
 *	input path (path) starts with an acceptable prefix.
E 4
 *
 *	return codes:  0  |  FAIL
 */

chkpth(logname, mchname, path)
char *path, *logname, *mchname;
{
	register struct userpath *u;
	extern char *lastpart();
	register char **p, *s;

	/* Allow only rooted pathnames.  Security wish.  rti!trt */
D 3
	if (*path != '/')
E 3
I 3
	if (*path != '/') {
		DEBUG(4, "filename doesn't begin with /\n", CNULL);
E 3
D 2
		return(FAIL);
E 2
I 2
		return FAIL;
I 3
	}
E 3
E 2

	if (Uptfirst) {
		rdpth();
D 2
		ASSERT(Uhead != NULL, "INIT USERFILE, No entrys!", "", 0);
E 2
I 2
D 5
		ASSERT(Uhead != NULL, "INIT USERFILE, No entrys!", CNULL, 0);
E 5
I 5
		if (Uhead == NULL) {
			syslog(LOG_ERR, "USERFILE empty!");
			cleanup(FAIL);
		}
E 5
E 2
		Uptfirst = 0;
	}
	for (u = Uhead; u != NULL; ) {
		if (*logname != '\0' && strcmp(logname, u->us_lname) == SAME)
			break;
D 4
		if (*mchname != '\0' && strncmp(mchname, u->us_mname, 7) == SAME)
E 4
I 4
		if (*mchname != '\0' && strncmp(mchname, u->us_mname, MAXBASENAME) == SAME)
E 4
			break;
		u = u->unext;
	}
	if (u == NULL) {
		if (*logname == '\0')
			u = Mchdef;
		else
			u = Logdef;
		if (u == NULL)
D 2
			return(FAIL);
E 2
I 2
			return FAIL;
E 2
	}
D 2
	/* found user name */
	p = u->us_path;
E 2

	/*  check for /../ in path name  */
	for (s = path; *s != '\0'; s++) {
D 3
		if (prefix("/../",s))
E 3
I 3
		if (prefix("/../",s)) {
			DEBUG(4, "filename has /../ in it\n", CNULL);
E 3
D 2
			return(FAIL);
E 2
I 2
			return FAIL;
I 3
		}
E 3
E 2
	}

	/* Check for access permission */
	for (p = u->us_path; *p != NULL; p++)
		if (prefix(*p, path))
D 2
			return(0);
E 2
I 2
			return SUCCESS;
I 3
	DEBUG(4, "filename not in list\n", CNULL);
E 3
E 2

	/* path name not valid */
D 2
	return(FAIL);
E 2
I 2
	return FAIL;
E 2
}


/***
 *	rdpth()
 *
 *	rdpth  -  this routine will read the USERFILE and
 *	construct the userpath structure pointed to by (u);
 *
D 2
 *	return codes:  0  |  FAIL
 *
 * 5/3/81 - changed to enforce the uucp-wide convention that system
 *	    names be 7 chars or less in length
E 2
 */

rdpth()
{
	char buf[100 + 1], *pbuf[50 + 1];
	register struct userpath *u;
	register char *pc, **cp;
	FILE *uf;

	if ((uf = fopen(USERFILE, "r")) == NULL) {
		/* can not open file */
		return;
	}

	while (cfgets(buf, sizeof(buf), uf) != NULL) {
		int nargs, i;

D 2
		if ((u = (struct userpath *)malloc(sizeof (struct userpath))) == NULL) {
E 2
I 2
		u = (struct userpath *)malloc(sizeof (struct userpath));
		if (u == NULL) {
E 2
			DEBUG (1, "*** Userpath malloc failed\n", 0);
			fclose (uf);
			return;
		}
		if ((pc = calloc((unsigned)strlen(buf) + 1, sizeof (char)))
			== NULL) {
			/* can not allocate space */
			DEBUG (1, "Userpath calloc 1 failed\n", 0);
			fclose(uf);
			return;
		}

		strcpy(pc, buf);
D 2
		nargs = getargs(pc, pbuf);
E 2
I 2
		nargs = getargs(pc, pbuf, 50);
E 2
		u->us_lname = pbuf[0];
		pc = index(u->us_lname, ',');
		if (pc != NULL)
			*pc++ = '\0';
		else
			pc = u->us_lname + strlen(u->us_lname);
		u->us_mname = pc;
D 4
		if (strlen(u->us_mname) > 7)
			u->us_mname[7] = '\0';
E 4
I 4
		if (strlen(u->us_mname) > MAXBASENAME)
			u->us_mname[MAXBASENAME] = '\0';
E 4
		if (*u->us_lname == '\0' && Logdef == NULL)
			Logdef = u;
D 2
		/* rti!trt: commented following else so
		 * chkpth("","",file) works okay.
		 * I don't understand this, though.
		 */
		/*else*/ if (*u->us_mname == '\0' && Mchdef == NULL)
E 2
I 2
		if (*u->us_mname == '\0' && Mchdef == NULL)
E 2
			Mchdef = u;
		i = 1;
		if (strcmp(pbuf[1], "c") == SAME) {
			u->us_callback = 1;
			i++;
		}
		else
			u->us_callback = 0;
D 2
		if ((cp = u->us_path =
		  (char **)calloc((unsigned)(nargs-i+1), sizeof(char *))) == NULL) {
E 2
I 2
		cp = (char **)calloc((unsigned)(nargs-i+1), sizeof(char *));
		if (cp == NULL) {
E 2
			/*  can not allocate space */
			DEBUG (1, "Userpath calloc 2 failed!\n", 0);
			fclose(uf);
			return;
		}
I 2
		u->us_path = cp;
E 2

		while (i < nargs)
			*cp++ = pbuf[i++];
		*cp = NULL;
		u->unext = Uhead;
		Uhead = u;
	}

	fclose(uf);
	return;
}

/***
 *	callback(name)	check for callback
 *	char *name;
 *
 *	return codes:
 *		0  -  no call back
 *		1  -  call back
 */

callback(name)
register char *name;
{
	register struct userpath *u;

	if (Uptfirst) {
		rdpth();
D 2
		ASSERT(Uhead != NULL, "INIT USERFILE, No Users!", "", 0);
E 2
I 2
D 5
		ASSERT(Uhead != NULL, "INIT USERFILE, No Users!", CNULL, 0);
E 5
I 5
		if (Uhead == NULL) {
			syslog(LOG_ERR, "USERFILE empty!");
			cleanup(FAIL);
		}
E 5
E 2
		Uptfirst = 0;
	}

	for (u = Uhead; u != NULL; ) {
		if (strcmp(u->us_lname, name) == SAME)
			/* found user name */
D 2
			return(u->us_callback);
E 2
I 2
			return u->us_callback;
E 2
		u = u->unext;
	}

	/* userid not found */
D 2
	return(0);
E 2
I 2
	return 0;
E 2
}


/***
 *	chkperm(file, mopt)	check write permission of file
 *	char *mopt;		none NULL - create directories
 *
 *	if mopt != NULL and permissions are ok,
 *	a side effect of this routine is to make
 *	directories up to the last part of the
 *	filename (if they do not exist).
 *
D 2
 *	return 0 | FAIL
E 2
I 2
 *	return SUCCESS | FAIL
E 2
 */

chkperm(file, mopt)
char *file, *mopt;
{
	struct stat s;
	int ret;
	char dir[MAXFULLNAME];
	extern char *lastpart();

	if (stat(subfile(file), &s) == 0) {
D 2
		/* Forbid scribbling on a not-generally-writable file */
		/* rti!trt */
E 2
D 3
		if ((s.st_mode & ANYWRITE) == 0)
E 3
I 3
		if ((s.st_mode & ANYWRITE) == 0) {
			DEBUG(4,"file is not writable: mode %o\n", s.st_mode);
E 3
D 2
			return(FAIL);
		return(0);
E 2
I 2
			return FAIL;
I 3
		}
E 3
		return SUCCESS;
E 2
	}

	strcpy(dir, file);
	*lastpart(dir) = '\0';
D 3
	if ((ret = stat(subfile(dir), &s)) == -1
	  && mopt == NULL)
E 3
I 3
	if ((ret = stat(subfile(dir), &s)) == -1 && mopt == NULL) {
		DEBUG(4, "can't stat directory %s\n", subfile(dir));
E 3
D 2
		return(FAIL);
E 2
I 2
		return FAIL;
I 3
	}
E 3
E 2

	if (ret != -1) {
		if ((s.st_mode & ANYWRITE) == 0)
D 2
			return(FAIL);
E 2
I 2
			return FAIL;
E 2
		else
D 2
			return(0);
E 2
I 2
			return SUCCESS;
E 2
	}

	/*  make directories  */
D 2
	return(mkdirs(file));
E 2
I 2
	return mkdirs(file);
E 2
}

/*
 * Check for sufficient privilege to request debugging.
D 2
 * Suggested by seismo!stewart, John Stewart.
E 2
 */
D 2
chkdebug(uid)
int uid;
E 2
I 2
chkdebug()
E 2
{
D 2
	if (uid > PRIV_UIDS) {
		fprintf(stderr, "Sorry, uid must be <= %d for debugging\n",
			PRIV_UIDS);
E 2
I 2
	if (access(SYSFILE, 04) < 0) {
		fprintf(stderr, "Sorry, you must be able to read L.sys for debugging\n");
E 2
		cleanup(1);
		exit(1);	/* Just in case */
	}
}
E 1
