h08657
s 00011/00005/00045
d D 5.4 88/02/18 17:03:55 bostic 8 7
c written by Kurt Shoens; added Berkeley specific header
e
s 00003/00010/00047
d D 5.3 87/05/18 12:28:48 edward 7 6
c major rework: made faster, cleaned up, obsolete code removed,
c the whole thing should be chucked and written from scratch
e
s 00001/00001/00056
d D 5.2 85/06/21 17:10:32 mckusick 6 5
c botched copyright
e
s 00008/00001/00049
d D 5.1 85/06/06 10:33:52 dist 5 4
c Add copyright
e
s 00010/00125/00040
d D 2.3 84/07/19 15:43:01 ralph 4 3
c use flock for mailbox locking
e
s 00003/00004/00162
d D 2.2 83/08/11 22:16:04 sam 3 2
c standardize sccs keyword lines
e
s 00000/00000/00166
d D 2.1 81/07/01 11:08:57 kurt 2 1
c Release to Heidi Stettner
e
s 00166/00000/00000
d D 1.1 80/10/08 09:50:02 kas 1 0
c date and time created 80/10/08 09:50:02 by kas
e
u
U
f b 
t
T
I 5
/*
 * Copyright (c) 1980 Regents of the University of California.
D 8
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 8
I 8
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 8
 */

E 5
I 1
D 3
#
E 3
I 3
D 8
#ifndef lint
D 6
static char sccsid[] = "%W% (Berkeley) %G%";
E 6
I 6
static char *sccsid = "%W% (Berkeley) %G%";
E 6
D 5
#endif
E 5
I 5
#endif not lint
E 8
I 8
#ifdef notdef
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* notdef */
E 8

E 5
I 4
#include <pwd.h>
E 4
E 3

D 3

E 3
/*
D 4
 * Getname / getuserid for those with no
E 4
I 4
 * Getname / getuserid for those with
E 4
 * hashed passwd data base).
D 4
 * Do not compile this module in if you DO have hashed
 * passwd's -- this is slower.
E 4
 *
D 4
 * Also provided here is a getpw routine which can share
 * the open file.  This is used for the Version 6 getenv
 * implementation.
E 4
 */
D 3

static char *SccsId = "%W% %G%";
E 3

#include "rcv.h"

D 4
static FILE *pwfile =	NULL;		/* Pw file held open */
static char *pwname = 	"/etc/passwd";	/* Name of passwd file */

E 4
/*
 * Search the passwd file for a uid.  Return name through ref parameter
 * if found, indicating success with 0 return.  Return -1 on error.
D 7
 * If -1 is passed as the user id, close the passwd file.
E 7
 */

getname(uid, namebuf)
	char namebuf[];
{
D 4
	register char *cp, *cp2;
	char linebuf[BUFSIZ];
E 4
I 4
	struct passwd *pw;
E 4

D 7
	if (uid == -1) {
D 4
		if (pwfile != NULL)
			fclose(pwfile);
		pwfile = NULL;
E 4
		return(0);
	}
E 7
D 4
	if (pwfile == NULL && (pwfile = fopen(pwname, "r")) == NULL)
E 4
I 4
	if ((pw = getpwuid(uid)) == NULL)
E 4
D 7
		return(-1);
E 7
I 7
		return -1;
E 7
D 4
	rewind(pwfile);
	while (fgets(linebuf, BUFSIZ, pwfile) != NULL)
		if (pweval(linebuf) == uid) {
			for (cp = linebuf, cp2 = namebuf; *cp != ':';
			    *cp2++ = *cp++)
				;
			*cp2 = '\0';
			return(0);
		}
	return(-1);
E 4
I 4
	strcpy(namebuf, pw->pw_name);
	return 0;
E 4
}

/*
D 4
 * Read the users password file line into the passed line
 * buffer.
 */

getpw(uid, linebuf)
	char linebuf[];
{
	register char *cp, *cp2;

	if (uid == -1) {
		if (pwfile != NULL)
			fclose(pwfile);
		pwfile = NULL;
		return(0);
	}
	if (pwfile == NULL && (pwfile = fopen(pwname, "r")) == NULL)
		return(-1);
	rewind(pwfile);
	while (fgets(linebuf, BUFSIZ, pwfile) != NULL)
		if (pweval(linebuf) == uid) {
			if (linebuf[0] != '\0')
				linebuf[strlen(linebuf)-1] = '\0';
			return(0);
		}
	return(-1);
}

/*
 * Look for passwd line belonging to 'name'
 */

getpwnam(name, linebuf)
	char name[], linebuf[];
{
	register char *cp, *cp2;

	if (name == NOSTR) {
		if (pwfile != NULL)
			fclose(pwfile);
		pwfile = NULL;
		return(0);
	}
	if (pwfile == NULL && (pwfile = fopen(pwname, "r")) == NULL) {
		perror(pwname);
		return(-1);
	}
	rewind(pwfile);
	while (fgets(linebuf, BUFSIZ, pwfile) != NULL) {
		cp = linebuf;
		cp2 = name;
		while (*cp2++ == *cp++)
			;
		if (*--cp == ':' && *--cp2 == 0)
			return(0);
	}
	return(-1);
}

/*
E 4
 * Convert the passed name to a user id and return it.  Return -1
D 7
 * on error.  Iff the name passed is -1 (yech) close the pwfile.
E 7
I 7
 * on error.
E 7
 */

getuserid(name)
	char name[];
{
D 4
	register char *cp, *cp2;
	char linebuf[BUFSIZ];
E 4
I 4
	struct passwd *pw;
E 4

D 7
	if (name == (char *) -1) {
D 4
		if (pwfile != NULL)
			fclose(pwfile);
		pwfile = NULL;
E 4
		return(0);
	}
E 7
D 4
	if (pwfile == NULL && (pwfile = fopen(pwname, "r")) == NULL)
		return(-1);
	rewind(pwfile);
	while (fgets(linebuf, BUFSIZ, pwfile) != NULL) {
		for (cp = name, cp2 = linebuf; *cp++ == *cp2++;)
			;
		if (*--cp == '\0' && *--cp2 == ':')
			return(pweval(linebuf));
	}
	return(-1);
}

/*
 * Evaluate the user id of the passed passwd line and return it.
 */

static
pweval(line)
	char line[];
{
	register char *cp;
	register int i;
	register int uid;

	for (cp = line, i = 0; i < 2; i += (*cp++ == ':'))
		;
	uid = atoi(cp);

#ifdef UIDGID
	while (*cp && *cp != ':')
		cp++;
	cp++;
	uid |= atoi(cp) << 8;
#endif

	return(uid);
E 4
I 4
	if ((pw = getpwnam(name)) == NULL)
D 7
		return 0;
E 7
I 7
		return -1;
E 7
	return pw->pw_uid;
E 4
}
E 1
