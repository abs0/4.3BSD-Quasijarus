h13789
s 00007/00002/00106
d D 5.5 88/02/24 20:01:36 rick 5 4
c build XEQTDIR at runtime instead of compiletime
e
s 00005/00002/00103
d D 5.4 85/06/23 13:04:08 bloom 4 3
c fixes from rick adams
e
s 00008/00008/00097
d D 5.3 85/04/10 15:20:49 ralph 3 2
c more changes from rick adams.
e
s 00005/00015/00100
d D 5.2 85/01/22 14:11:00 ralph 2 1
c bug fixes and changes from Rick Adams
e
s 00115/00000/00000
d D 5.1 83/07/02 17:57:33 sam 1 0
c date and time created 83/07/02 17:57:33 by sam
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
I 4

/*LINTLIBRARY*/

E 4
D 2
#ifdef	UUDIR
E 2
/*
 * By Tom Truscott, March 1983
D 2
 * THIS VERSION OF SYSKLUDGE IS FOR USE ONLY
 * WITH THE 'UUDIR' VERSION OF UUCP.
E 2
 *
D 2
 * There once was a separate 'uudir' package to retrofit
 * versions of uucp, but that is no longer recommended.
 *
E 2
 * Prefix table.
 * If a prefix is "abc", for example,
 * then any file Spool/abc... is mapped to Spool/abc/abc... .
 * The first prefix found is used, so D.foo should preceed D. in table.
 *
 * Each prefix must be a subdirectory of Spool, owned by uucp!
 * Remember: use cron to uuclean these directories daily,
D 3
 * and check them manual every now and then.  Beware complacency!
E 3
I 3
 * and check them manually every now and then.  Beware complacency!
E 3
 */

D 4
static char *prefix[] = {
E 4
I 4
static char *dprefix[] = {
E 4
	DLocalX,	/* Outbound 'xqt' request files */
	DLocal,		/* Outbound data files */
	"D.",		/* Other "D." files (remember the "."!) */
	"C.",		/* "C." subdirectory */
	"X.",		/* "X." subdirectory */
	"TM.",		/* Temporaries for inbound files */
	0
};

/*
 * filename mapping kludges to put uucp work files in other directories.
 */

#define	BUFLEN	50
D 2
/* assert(strlen(Spool)+1+14+1+14 <= BUFLEN) */
E 2

static	char fn1[BUFLEN], fn2[BUFLEN];	/* remapped filename areas */
static	int	inspool;		/* true iff working dir is Spool */

/*
 * return (possibly) remapped string s
 */
char *
D 2
SubFile(as)
E 2
I 2
subfile(as)
E 2
char *as;
{
	register char *s, **p;
	register int n;
	static char *tptr = NULL;

	/* Alternate buffers so "link(subfile(a), subfile(b))" works */
	if (tptr != fn1)
		tptr = fn1;
	else
		tptr = fn2;

	s = as;
	tptr[0] = '\0';

	/* if s begins with Spool/, copy that to tptr and advance s */
	if (strncmp(s, Spool, n = strlen(Spool)) == 0 && s[n] == '/') {
		if (!inspool) {
			strcpy(tptr, Spool);
			strcat(tptr, "/");
		}
		s += n + 1;
	}
	else
		if (!inspool)
D 3
			return(as);
E 3
I 3
			return as;
E 3

	/* look for first prefix which matches, and make subdirectory */
D 4
	for (p = &prefix[0]; *p; p++) {
E 4
I 4
	for (p = &dprefix[0]; *p; p++) {
E 4
		if (strncmp(s, *p, n = strlen(*p))==0 && s[n] && s[n] != '/') {
			strcat(tptr, *p);
			strcat(tptr, "/");
			strcat(tptr, s);
D 3
			return(tptr);
E 3
I 3
			return tptr;
E 3
		}
	}
D 3
	return(as);
E 3
I 3
	return as;
E 3
}

/*
 * save away filename
 */
D 2
SubChDir(s)
E 2
I 2
subchdir(s)
E 2
register char *s;
{
	inspool = (strcmp(s, Spool) == 0);
D 3
	return(chdir(s));
E 3
I 3
	return chdir(s);
E 3
}

/*
 * return possibly corrected directory for searching
 */
I 5
static char xdir[BUFSIZ];
E 5
char *
D 2
SubDir(d, pre)
E 2
I 2
subdir(d, pre)
E 2
register char *d, pre;
{
	if (strcmp(d, Spool) == 0)
		if (pre == CMDPRE)
D 2
			return("/usr/spool/uucp/C.");
E 2
I 2
D 3
			return(CMDSDIR);
E 3
I 3
			return CMDSDIR;
E 3
E 2
D 5
		else if (pre == XQTPRE)
D 2
			return("/usr/spool/uucp/X.");
E 2
I 2
D 3
			return(XEQTDIR);
E 2
	return(d);
E 3
I 3
			return XEQTDIR;
E 5
I 5
		else if (pre == XQTPRE) {
			if (xdir[0] == '\0')
				sprintf(xdir,"%s/X.",Spool);
			return xdir;

		}
E 5
	return d;
E 3
}
D 2
#else
static int subdir_here;		/* quiet 'ranlib' command */
#endif
E 2
E 1
