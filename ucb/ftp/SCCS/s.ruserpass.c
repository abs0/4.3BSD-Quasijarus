h30915
s 00010/00005/00237
d D 1.5 88/06/29 20:34:29 bostic 5 4
c install approved copyright notice
e
s 00009/00004/00233
d D 1.4 88/03/14 17:21:48 bostic 4 3
c add Berkeley specific headers
e
s 00012/00010/00225
d D 1.3 86/03/07 12:33:00 minshall 3 2
c Clean up for lint; change some stderr to stdout; bug fix
c (in ruserpass.c, routine rnetrc()).
e
s 00004/00004/00231
d D 1.2 86/02/03 15:23:48 minshall 2 1
c Change "ftprc" to "netrc" (to keep compatibility).
e
s 00235/00000/00000
d D 1.1 86/02/03 15:22:28 minshall 1 0
c date and time created 86/02/03 15:22:28 by minshall
e
u
U
t
T
I 1
/*
 * Copyright (c) 1985 Regents of the University of California.
D 4
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 4
I 4
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 5
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 5
I 5
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
E 5
E 4
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 4
#endif not lint

E 4
I 4
#endif /* not lint */
E 4

struct macel {
	char mac_name[9];	/* macro name */
	char *mac_start;	/* start of macro in macbuf */
	char *mac_end;		/* end of macro in macbuf */
};

extern int macnum, proxy;			/* number of defined macros */
extern struct macel macros[16], *macpt;
extern char macbuf[4096];

#include <stdio.h>
#include <utmp.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

char	*renvlook(), *malloc(), *index(), *getenv(), *getpass(), *getlogin();
I 3
char	*strcpy();
E 3
struct	utmp *getutmp();
static	FILE *cfile;

ruserpass(host, aname, apass, aacct)
	char *host, **aname, **apass, **aacct;
{

	/* renv(host, aname, apass, aacct);
	if (*aname == 0 || *apass == 0) */
		return(rnetrc(host, aname, apass, aacct));
}

#define	DEFAULT	1
#define	LOGIN	2
#define	PASSWD	3
#define	ACCOUNT 4
#define MACDEF  5
#define	ID	10
#define	MACHINE	11

static char tokval[100];

static struct toktab {
	char *tokstr;
	int tval;
} toktab[]= {
	"default",	DEFAULT,
	"login",	LOGIN,
	"password",	PASSWD,
	"account",	ACCOUNT,
	"machine",	MACHINE,
	"macdef",	MACDEF,
	0,		0
};

static
rnetrc(host, aname, apass, aacct)
	char *host, **aname, **apass, **aacct;
{
D 3
	char *hdir, buf[BUFSIZ], *tmp, c;
	int t, i;
E 3
I 3
	char *hdir, buf[BUFSIZ], *tmp;
	int t, i, c;
E 3
	struct stat stb;
	extern int errno;

	hdir = getenv("HOME");
	if (hdir == NULL)
		hdir = ".";
D 2
	sprintf(buf, "%s/.ftprc", hdir);
E 2
I 2
D 3
	sprintf(buf, "%s/.netrc", hdir);
E 3
I 3
	(void) sprintf(buf, "%s/.netrc", hdir);
E 3
E 2
	cfile = fopen(buf, "r");
	if (cfile == NULL) {
		if (errno != ENOENT)
			perror(buf);
		return(0);
	}
next:
	while ((t = token())) switch(t) {

	case DEFAULT:
		(void) token();
		continue;

	case MACHINE:
		if (token() != ID || strcmp(host, tokval))
			continue;
		while ((t = token()) && t != MACHINE) switch(t) {

		case LOGIN:
			if (token())
				if (*aname == 0) { 
D 3
					*aname = malloc(strlen(tokval) + 1);
					strcpy(*aname, tokval);
E 3
I 3
					*aname = malloc((unsigned) strlen(tokval) + 1);
					(void) strcpy(*aname, tokval);
E 3
				} else {
					if (strcmp(*aname, tokval))
						goto next;
				}
			break;
		case PASSWD:
			if (fstat(fileno(cfile), &stb) >= 0
			    && (stb.st_mode & 077) != 0) {
D 2
	fprintf(stderr, "Error - .ftprc file not correct mode.\n");
E 2
I 2
	fprintf(stderr, "Error - .netrc file not correct mode.\n");
E 2
	fprintf(stderr, "Remove password or correct mode.\n");
				return(-1);
			}
			if (token() && *apass == 0) {
D 3
				*apass = malloc(strlen(tokval) + 1);
				strcpy(*apass, tokval);
E 3
I 3
				*apass = malloc((unsigned) strlen(tokval) + 1);
				(void) strcpy(*apass, tokval);
E 3
			}
			break;
		case ACCOUNT:
			if (fstat(fileno(cfile), &stb) >= 0
			    && (stb.st_mode & 077) != 0) {
D 2
	fprintf(stderr, "Error - .ftprc file not correct mode.\n");
E 2
I 2
	fprintf(stderr, "Error - .netrc file not correct mode.\n");
E 2
	fprintf(stderr, "Remove account or correct mode.\n");
				return(-1);
			}
			if (token() && *aacct == 0) {
D 3
				*aacct = malloc(strlen(tokval) + 1);
				strcpy(*aacct, tokval);
E 3
I 3
				*aacct = malloc((unsigned) strlen(tokval) + 1);
				(void) strcpy(*aacct, tokval);
E 3
			}
			break;
		case MACDEF:
			if (proxy) {
				return(0);
			}
			while ((c=getc(cfile)) != EOF && c == ' ' || c == '\t');
			if (c == EOF || c == '\n') {
				printf("Missing macdef name argument.\n");
				return(-1);
			}
			if (macnum == 16) {
				printf("Limit of 16 macros have already been defined\n");
				return(-1);
			}
			tmp = macros[macnum].mac_name;
			*tmp++ = c;
			for (i=0; i < 8 && (c=getc(cfile)) != EOF &&
			    !isspace(c); ++i) {
				*tmp++ = c;
			}
			if (c == EOF) {
				printf("Macro definition missing null line terminator.\n");
				return(-1);
			}
			*tmp = '\0';
			if (c != '\n') {
				while ((c=getc(cfile)) != EOF && c != '\n');
			}
			if (c == EOF) {
				printf("Macro definition missing null line terminator.\n");
				return(-1);
			}
			if (macnum == 0) {
				macros[macnum].mac_start = macbuf;
			}
			else {
				macros[macnum].mac_start = macros[macnum-1].mac_end + 1;
			}
			tmp = macros[macnum].mac_start;
			while (tmp != macbuf + 4096) {
				if ((c=getc(cfile)) == EOF) {
				printf("Macro definition missing null line terminator.\n");
					return(-1);
				}
				*tmp = c;
				if (*tmp == '\n') {
					if (*(tmp-1) == '\0') {
					   macros[macnum++].mac_end = tmp - 1;
					   break;
					}
					*tmp = '\0';
				}
				tmp++;
			}
			if (tmp == macbuf + 4096) {
				printf("4K macro buffer exceeded\n");
				return(-1);
			}
			break;
		default:
D 2
	fprintf(stderr, "Unknown .ftprc keyword %s\n", tokval);
E 2
I 2
	fprintf(stderr, "Unknown .netrc keyword %s\n", tokval);
E 2
			break;
		}
		goto done;
	}
done:
D 3
	fclose(cfile);
E 3
I 3
	(void) fclose(cfile);
	return(0);
E 3
}

static
token()
{
	char *cp;
	int c;
	struct toktab *t;

	if (feof(cfile))
		return (0);
	while ((c = getc(cfile)) != EOF &&
	    (c == '\n' || c == '\t' || c == ' ' || c == ','))
		continue;
	if (c == EOF)
		return (0);
	cp = tokval;
	if (c == '"') {
		while ((c = getc(cfile)) != EOF && c != '"') {
			if (c == '\\')
				c = getc(cfile);
			*cp++ = c;
		}
	} else {
		*cp++ = c;
		while ((c = getc(cfile)) != EOF
		    && c != '\n' && c != '\t' && c != ' ' && c != ',') {
			if (c == '\\')
				c = getc(cfile);
			*cp++ = c;
		}
	}
	*cp = 0;
	if (tokval[0] == 0)
		return (0);
	for (t = toktab; t->tokstr; t++)
		if (!strcmp(t->tokstr, tokval))
			return (t->tval);
	return (ID);
}
E 1
