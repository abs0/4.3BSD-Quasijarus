h20840
s 00010/00005/00074
d D 4.7 88/06/27 18:25:31 bostic 7 6
c install approved copyright notice
e
s 00011/00012/00068
d D 4.6 88/04/19 11:16:10 bostic 6 5
c allow a single '-' to be specified
e
s 00009/00003/00071
d D 4.5 87/11/24 15:57:15 bostic 5 4
c Berkeley code, fix copyright
e
s 00033/00020/00041
d D 4.4 87/09/04 18:57:13 bostic 4 3
c fix opterr usage; bug report 4.3BSD/lib/86; reformat
e
s 00002/00002/00059
d D 4.3 86/03/09 19:33:24 donn 3 2
c added LIBC_SCCS condition for sccs ids
e
s 00003/00003/00058
d D 4.2 85/10/23 19:15:34 mckusick 2 1
c fix from keith@seismo.CSS.GOV
e
s 00061/00000/00000
d D 4.1 85/05/30 13:54:43 mckusick 1 0
c date and time created 85/05/30 13:54:43 by mckusick
e
u
U
t
T
I 1
/*
D 5
 * Copyright (c) 1985 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 5
I 5
 * Copyright (c) 1987 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 7
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific written prior permission. This software
 * is provided ``as is'' without express or implied warranty.
E 7
I 7
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
E 7
E 5
 */

D 3
#ifndef lint
E 3
I 3
#if defined(LIBC_SCCS) && !defined(lint)
E 3
static char sccsid[] = "%W% (Berkeley) %G%";
D 3
#endif not lint
E 3
I 3
D 6
#endif LIBC_SCCS and not lint
E 6
I 6
#endif /* LIBC_SCCS and not lint */
E 6
E 3

#include <stdio.h>

/*
 * get option letter from argument vector
 */
D 2
int	opterr = 1,		/* useless, never set or used */
E 2
I 2
int	opterr = 1,		/* if error message should be printed */
E 2
	optind = 1,		/* index into parent argv vector */
	optopt;			/* character checked for validity */
char	*optarg;		/* argument associated with option */

D 6
#define BADCH	(int)'?'
#define EMSG	""
D 2
#define tell(s)	fputs(*nargv,stderr);fputs(s,stderr); \
		fputc(optopt,stderr);fputc('\n',stderr);return(BADCH);
E 2
I 2
D 4
#define tell(s)	if (opterr) {fputs(*nargv,stderr);fputs(s,stderr); \
		fputc(optopt,stderr);fputc('\n',stderr);return(BADCH);}
E 4
I 4
#define tell(s)	{ \
E 6
I 6
#define	BADCH	(int)'?'
#define	EMSG	""
#define	tell(s)	{ \
E 6
	if (opterr) { \
		fputs(*nargv, stderr); \
		fputs(s, stderr); \
		fputc(optopt, stderr); \
		fputc((int)'\n', stderr); \
	} \
	return(BADCH); \
}
E 4
E 2

D 4
getopt(nargc,nargv,ostr)
int	nargc;
char	**nargv,
	*ostr;
E 4
I 4
getopt(nargc, nargv, ostr)
D 6
	int	nargc;
	char	**nargv, *ostr;
E 6
I 6
	int nargc;
	char **nargv, *ostr;
E 6
E 4
{
D 4
	static char	*place = EMSG;	/* option letter processing */
	register char	*oli;		/* option letter list index */
E 4
I 4
D 6
	static char	*place = EMSG;		/* option letter processing */
	register char	*oli;			/* option letter list index */
E 4
	char	*index();
E 6
I 6
	static char *place = EMSG;		/* option letter processing */
	register char *oli;			/* option letter list index */
	char *index();
E 6

D 4
	if(!*place) {			/* update scanning pointer */
		if(optind >= nargc || *(place = nargv[optind]) != '-' || !*++place) return(EOF);
		if (*place == '-') {	/* found "--" */
E 4
I 4
	if (!*place) {				/* update scanning pointer */
D 6
		if (optind >= nargc || *(place = nargv[optind]) != '-' ||
		    !*++place)
E 6
I 6
		if (optind >= nargc || *(place = nargv[optind]) != '-')
E 6
			return(EOF);
D 6
		if (*place == '-') {		/* found "--" */
E 6
I 6
		if (place[1] && *++place == '-') {	/* found "--" */
E 6
E 4
			++optind;
			return(EOF);
		}
D 4
	}				/* option letter okay? */
	if ((optopt = (int)*place++) == (int)':' || !(oli = index(ostr,optopt))) {
		if(!*place) ++optind;
E 4
I 4
	}					/* option letter okay? */
	if ((optopt = (int)*place++) == (int)':' ||
	    !(oli = index(ostr, optopt))) {
		if (!*place)
			++optind;
E 4
		tell(": illegal option -- ");
	}
D 4
	if (*++oli != ':') {		/* don't need argument */
E 4
I 4
	if (*++oli != ':') {			/* don't need argument */
E 4
		optarg = NULL;
D 4
		if (!*place) ++optind;
E 4
I 4
		if (!*place)
			++optind;
E 4
	}
D 4
	else {				/* need an argument */
		if (*place) optarg = place;	/* no white space */
E 4
I 4
	else {					/* need an argument */
		if (*place)			/* no white space */
			optarg = place;
E 4
		else if (nargc <= ++optind) {	/* no arg */
			place = EMSG;
			tell(": option requires an argument -- ");
		}
D 4
	 	else optarg = nargv[optind];	/* white space */
E 4
I 4
	 	else				/* white space */
			optarg = nargv[optind];
E 4
		place = EMSG;
		++optind;
	}
D 4
	return(optopt);			/* dump back option letter */
E 4
I 4
	return(optopt);				/* dump back option letter */
E 4
}
E 1
