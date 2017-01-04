h16902
s 00005/00002/00113
d D 5.7 88/04/05 12:27:55 rick 7 6
c use syslog for errors
e
s 00003/00002/00112
d D 5.6 88/02/24 20:06:30 rick 6 5
c fix null dereferencing
e
s 00007/00005/00107
d D 5.5 85/10/09 17:10:31 bloom 5 4
c still more fixes from rick@seismo
e
s 00006/00006/00106
d D 5.4 85/06/23 14:00:36 bloom 4 3
c fixes from rick adams
e
s 00084/00015/00028
d D 5.3 85/04/10 15:24:01 ralph 3 2
c more changes from rick adams.
e
s 00005/00005/00038
d D 5.2 85/01/22 14:14:15 ralph 2 1
c bug fixes and changes from Rick Adams
e
s 00043/00000/00000
d D 5.1 83/07/02 17:58:10 sam 1 0
c date and time created 83/07/02 17:58:10 by sam
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
I 3
#include <stdio.h>
#include <ctype.h>
E 3

D 4
#define SNAMESIZE 7
E 4
I 4
/*LINTLIBRARY*/
E 4

I 5
char PhoneNumber[MAXPH];

E 5
D 3
/*******
 *	versys(name)	verify system names n1 and n2
 *	char *name;
E 3
I 3
/*
 *	verify system names n1 and n2
 *	return codes:  SUCCESS  |  FAIL
E 3
 *
D 3
 *	return codes:  0  |  FAIL
E 3
I 3
 *	NOTE:
 *		the old calling sequence was versys(name) but is
 *	now versys(&name) so that we can perform aliasing!!!!
 *	See accompanying changes in uucp.c and uux.c
 *		-- Ray Essick, April 27, 1984
E 3
 */
D 3

versys(name)
register char *name;
E 3
I 3
versys(nameptr)
register char **nameptr;
E 3
{
	register FILE *fp;
D 3
	char line[1000];
	char s1[SNAMESIZE + 1];
	char myname[SNAMESIZE + 1];
E 3
I 3
	char line[BUFSIZ];
	char *name;
E 3

D 3
	sprintf(myname, "%.7s", Myname);
	sprintf(s1, "%.7s", name);
	if (strcmp(s1, myname) == 0)
E 3
I 3
	DEBUG (11, "Before Alias: %s\n", *nameptr);
D 4
	uualias(nameptr);			/* alias expansion */
E 4
I 4
	uualias (nameptr);			/* alias expansion */
E 4
	DEBUG (11, "After Alias: %s\n", *nameptr);
	name = *nameptr;			/* dereference */

D 4
	if (strncmp(name, Myname, 7) == 0)
E 4
I 4
D 6
	if (strncmp(name, Myname, MAXBASENAME) == 0)
E 6
I 6
	if (name[0] == '\0' || strncmp(name, Myname, MAXBASENAME) == 0)
E 6
E 4
E 3
D 2
		return(0);
E 2
I 2
		return SUCCESS;
E 2

	fp = fopen(SYSFILE, "r");
D 2
	ASSERT(fp != NULL, "CAN'T OPEN", SYSFILE, 0);
E 2
I 2
D 7
	ASSERT(fp != NULL, CANTOPEN, SYSFILE, 0);
E 7
I 7
	if (fp == NULL) {
		syslog(LOG_ERR, "fopen(%s) failed: %m", SYSFILE);
		cleanup(FAIL);
	}
E 7
I 5
	PhoneNumber[0] = '\0';
E 5
E 2
	while (cfgets(line, sizeof(line), fp) != NULL) {
		char *targs[100];

D 2
		getargs(line, targs);
E 2
I 2
		getargs(line, targs, 100);
E 2
D 3
		targs[0][7] = '\0';
		if (strcmp(s1, targs[0]) == SAME) {
E 3
I 3
D 4
		if (strncmp(name, targs[0], 7) == SAME) {
E 4
I 4
		if (strncmp(name, targs[0], MAXBASENAME) == SAME) {
E 4
E 3
			fclose(fp);
I 5
D 6
			strncpy(PhoneNumber, targs[F_PHONE], MAXPH);
E 6
I 6
			if (targs[F_PHONE])
				strncpy(PhoneNumber, targs[F_PHONE], MAXPH);
E 6
E 5
D 2
			return(0);
E 2
I 2
			return SUCCESS;
E 2
		}
	}
	fclose(fp);
D 2
	return(FAIL);
E 2
I 2
	return FAIL;
I 3
}

/*
 *	Works (sort of) like rhost(3) on 4.1[abc] Bsd systems.
 *
 *	Looks for the host in the L.aliases file and returns the
 *	"standard" name by modifying the pointer. The returned
 *	value is saved with malloc(3) so it isn't zapped by
 *	subsequent calls.
 *
 *	Returns:
 *		FAIL		No L.aliases file
 *		SUCCESS		Anything else
 */

D 4
uualias(hostptr)
E 4
I 4
D 5
uualias (hostptr)
E 5
I 5
uualias(hostptr)
E 5
E 4
char  **hostptr;			  /* we change it */
{
D 5
	FILE * Aliases;			  /* list of aliases */
E 5
I 5
	FILE *Aliases;			  /* list of aliases */
E 5
	char buf[BUFSIZ];
	int atend;
	char *p, *q;
	char *koshername;		 /* "official" name */

	if ((Aliases = fopen(ALIASFILE, "r")) == NULL) {
		DEBUG(11, "No %s file\n", ALIASFILE);
		return FAIL;			  /* no alias file */
	}

	DEBUG (11, "Alias expansion for %s\n", *hostptr);
D 5
	while (fgets(buf, sizeof (buf), Aliases)) {
		if (buf[0] == '#')		  /* comment line */
			continue;
E 5
I 5
	while (cfgets(buf, sizeof (buf), Aliases)) {
E 5
		p = &buf[0];
		atend = 0;
		DEBUG(11, "Alias line: %s\n", buf);

		while (!atend) {
			while (isspace(*p) && *p != '\n')
				p++;			  /* skip white space */
			q = p;
			while (!isspace(*q) && *q != '\n')
				q++;			  /* find end */
			if (*q == '\n')
				atend++;		  /* last entry */
			*q = '\0';
			DEBUG(11, "Compare against: %s\n", p);
			if (strcmp(*hostptr, p) == 0)/* match? */ {
D 4
				koshername = malloc(strlen(buf) + 1);
E 4
I 4
				koshername = malloc((unsigned)strlen(buf) + 1);
E 4
				strcpy(koshername, buf); /* save it */
				fclose(Aliases);
				DEBUG(4, "Alias: %s to ", *hostptr);
				DEBUG(4, "%s\n", koshername);
				*hostptr = koshername;	  /* correct one */
				return SUCCESS;		  /* all is well */
			}
			p = q + 1;			  /* try next entry */
		}

	}
	fclose(Aliases);
	DEBUG(11, "Alias doesn't match %s, remains unchanged\n", *hostptr);
	return SUCCESS;				  /* unchanged host */
E 3
E 2
}
E 1
