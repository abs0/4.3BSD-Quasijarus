h21631
s 00001/00001/00180
d D 5.6 04/03/06 21:35:11 msokolov 20 19
c count pnexus controllers
e
s 00010/00005/00171
d D 5.5 88/06/18 13:43:07 bostic 19 18
c install approved copyright notice
e
s 00002/00002/00174
d D 5.4 88/05/24 17:46:07 karels 18 17
c I think this works: don't do #define's for connected-to things
c that aren't connected to anything (they must be a main bus)
e
s 00009/00003/00167
d D 5.3 88/04/29 13:43:29 bostic 17 16
c add Berkeley specific header; original conception by Michael Toy
e
s 00001/00001/00169
d D 5.2 88/04/26 13:33:56 bostic 16 15
c int format, unsigned arg in fprintf
e
s 00007/00001/00163
d D 5.1 85/05/08 11:57:41 dist 15 14
c Add copyright
e
s 00003/00001/00161
d D 1.14 83/08/11 22:54:12 sam 14 13
c standardize sccs keyword lines
e
s 00003/00002/00159
d D 1.13 82/12/09 21:34:15 sam 13 12
c somehow the -p option went away
e
s 00013/00012/00148
d D 1.12 82/10/25 00:59:06 root 12 11
c lint and cleanup
e
s 00003/00003/00157
d D 1.11 82/10/24 23:14:07 root 11 10
c fixups
e
s 00003/00003/00157
d D 1.10 82/10/24 22:53:35 root 10 9
c get rid of bool, TRUE and FALSE
e
s 00118/00138/00042
d D 1.9 82/10/24 22:48:30 root 9 8
c cleanup and from sun
e
s 00005/00000/00175
d D 1.8 82/07/21 22:36:29 kre 8 7
c use number specified after pseudo-dev (if any) as value
c for #define in .h file (rather than always just 1).
e
s 00007/00000/00168
d D 1.7 82/03/28 19:34:08 sam 7 6
c fix problem with holes in unit numbering
e
s 00001/00001/00167
d D 1.6 81/04/08 18:31:04 root 6 5
c fix problem where if a device was deleted
c the count for the connecting device would not be decremented
c in the header file, because the program would never get around
c to ``dealing with'' the connecting device... this caused grief
c when deleting devices from the generic system to get a local
e
s 00008/00000/00160
d D 1.5 81/02/26 12:48:00 wnj 5 4
c stamp for sending to dec... still bugs in mkioconf.c
e
s 00001/00002/00159
d D 1.4 81/02/26 01:44:40 wnj 4 3
c put away mikes stuff
e
s 00130/00055/00031
d D 1.3 81/02/25 22:17:10 toy 3 2
c Made it work
e
s 00000/00000/00086
d D 1.2 81/02/24 15:53:00 toy 2 1
c Save version for first working set
e
s 00086/00000/00000
d D 1.1 81/02/24 15:51:17 toy 1 0
c date and time created 81/02/24 15:51:17 by toy
e
u
U
t
T
I 15
/*
 * Copyright (c) 1980 Regents of the University of California.
D 17
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 17
I 17
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 19
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 19
I 19
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
E 19
E 17
 */

E 15
I 9
D 14
/*	%M%	%I%	%E%	*/
E 14
I 14
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 15
#endif
E 15
I 15
D 17
#endif not lint
E 17
I 17
#endif /* not lint */
E 17
E 15
E 14

E 9
I 1
/*
D 3
 * %M%	%I%	%E%
 * Make header files for EVERYTHING
E 3
I 3
D 9
 *	%M%	%I%	%E%
E 9
 * Make all the .h files for the optional entries
E 3
 */

#include <stdio.h>
#include <ctype.h>
#include "config.h"
I 8
#include "y.tab.h"
E 8
D 3
#include "y.tab.h"
E 3

I 3
D 9
/*
 * This macro reads a line of the form
 *	#define STRING <number>
 * and assigns STRING to wd and <number> to count
 */
#define rdln(f, wd, count) {\
	register char *iwd;\
	if ((wd = get_word(f)) != NULL && wd != EOF)\
	    if ((wd = get_word(f)) != NULL && wd != EOF) {\
		iwd = ns(wd);\
		if ((wd = get_word(f)) != NULL && wd != EOF) {\
		    count = atoi(wd);\
		    wd = get_word(f);\
		    wd = iwd;\
		}\
	    }\
	}
E 3

E 9
D 3

E 3
headers()
{
D 3
    register struct device *ip;
    register struct file_list *tp;
E 3
I 3
D 9
    register struct file_list *fl;
E 9
I 9
	register struct file_list *fl;
E 9

D 9
    for (fl = ftab; fl != NULL; fl = fl->f_next)
	if (fl->f_needs != NULL)
	    do_count(fl->f_needs, fl->f_needs, TRUE);
E 9
I 9
	for (fl = ftab; fl != 0; fl = fl->f_next)
		if (fl->f_needs != 0)
D 10
			do_count(fl->f_needs, fl->f_needs, TRUE);
E 10
I 10
			do_count(fl->f_needs, fl->f_needs, 1);
E 10
E 9
}

/*
D 9
 * do_count:
 *	Count all the devices of a certain type and recurse to count
 *	whatever the device is connected to
E 9
I 9
 * count all the devices of a certain type and recurse to count
 * whatever the device is connected to
E 9
 */
D 9

E 9
do_count(dev, hname, search)
D 9
register char *dev, *hname;
bool search;
E 9
I 9
	register char *dev, *hname;
D 11
	bool search;
E 11
I 11
	int search;
E 11
E 9
{
D 9
    register struct device *dp, *mp;
E 3
    register int count;
E 9
I 9
	register struct device *dp, *mp;
	register int count;
E 9

D 3
    for (tp = ftab; tp != NULL; tp = tp->f_next)
E 3
I 3
D 9
    for (count = 0,dp = dtab; dp != NULL; dp = dp->d_next)
	if (dp->d_unit != -1 && eq(dp->d_name, dev))
	{
I 8
	    if (dp->d_type == PSEUDO_DEVICE) {
		count = dp->d_slave != UNKNOWN ? dp->d_slave : 1;
		break;
	    }
E 8
	    count++;
I 7
	    /*
	     * Allow holes in unit numbering,
	     * assumption is unit numbering starts
	     * at zero.
	     */
	    if (dp->d_unit + 1 > count)
	    	count = dp->d_unit + 1;
E 7
	    if (search)
	    {
		mp = dp->d_conn;
		if (mp != NULL && mp != -1 && mp->d_conn != -1)
		{
		    do_count(mp->d_name, hname, FALSE);
		    search = FALSE;
E 9
I 9
	for (count = 0,dp = dtab; dp != 0; dp = dp->d_next)
		if (dp->d_unit != -1 && eq(dp->d_name, dev)) {
			if (dp->d_type == PSEUDO_DEVICE) {
D 13
				count = dp->d_slave != UNKNOWN ? dp->d_slave : 1;
E 13
I 13
				count =
				    dp->d_slave != UNKNOWN ? dp->d_slave : 1;
E 13
				break;
			}
			count++;
			/*
			 * Allow holes in unit numbering,
			 * assumption is unit numbering starts
			 * at zero.
			 */
			if (dp->d_unit + 1 > count)
				count = dp->d_unit + 1;
			if (search) {
				mp = dp->d_conn;
D 12
				if (mp != 0 && mp != -1 && mp->d_conn != -1) {
E 12
I 12
D 18
				if (mp != 0 && mp != (struct device *)-1 &&
				    mp->d_conn != (struct device *)-1) {
E 18
I 18
				if (mp != 0 && mp != TO_NEXUS &&
D 20
				    mp->d_conn != 0 && mp->d_conn != TO_NEXUS) {
E 20
I 20
				    !isadapter(mp->d_name)) {
E 20
E 18
E 12
D 10
					do_count(mp->d_name, hname, FALSE);
					search = FALSE;
E 10
I 10
					do_count(mp->d_name, hname, 0);
					search = 0;
E 10
				}
			}
E 9
		}
D 9
	    }
	}
    do_header(dev, hname, count);
E 9
I 9
	do_header(dev, hname, count);
E 9
}

do_header(dev, hname, count)
D 9
char *dev, *hname;
int count;
E 9
I 9
	char *dev, *hname;
	int count;
E 9
{
D 9
    char *file, *name, *inw, *toheader(), *tomacro();
    struct file_list *fl, *fl_head;
    FILE *inf, *outf;
    int inc, oldcount;
E 9
I 9
	char *file, *name, *inw, *toheader(), *tomacro();
	struct file_list *fl, *fl_head;
	FILE *inf, *outf;
	int inc, oldcount;
E 9

D 9
    file = toheader(hname);
    name = tomacro(dev);
    inf = fopen(file, "r");
    oldcount = -1;
    if (inf == NULL)
E 3
    {
E 9
I 9
	file = toheader(hname);
	name = tomacro(dev);
	inf = fopen(file, "r");
	oldcount = -1;
	if (inf == 0) {
		outf = fopen(file, "w");
		if (outf == 0) {
			perror(file);
			exit(1);
		}
		fprintf(outf, "#define %s %d\n", name, count);
D 12
		fclose(outf);
E 12
I 12
		(void) fclose(outf);
E 12
		return;
	}
	fl_head = 0;
	for (;;) {
		char *cp;
D 12
		if ((inw = get_word(inf)) == 0 || inw == EOF)
E 12
I 12
		if ((inw = get_word(inf)) == 0 || inw == (char *)EOF)
E 12
			break;
D 12
		if ((inw = get_word(inf)) == 0 || inw == EOF)
E 12
I 12
		if ((inw = get_word(inf)) == 0 || inw == (char *)EOF)
E 12
			break;
		inw = ns(inw);
		cp = get_word(inf);
D 12
		if (cp == 0 || cp == EOF)
E 12
I 12
		if (cp == 0 || cp == (char *)EOF)
E 12
			break;
		inc = atoi(cp);
		if (eq(inw, name)) {
			oldcount = inc;
			inc = count;
		}
		cp = get_word(inf);
D 12
		if (cp == 0 || cp == EOF)
E 12
I 12
D 13
		if (cp == 0 || cp == (char *)EOF)
E 13
I 13
		if (cp == (char *)EOF)
E 13
E 12
			break;
		fl = (struct file_list *) malloc(sizeof *fl);
		fl->f_fn = inw;
		fl->f_type = inc;
		fl->f_next = fl_head;
		fl_head = fl;
	}
D 12
	fclose(inf);
E 12
I 12
	(void) fclose(inf);
E 12
	if (count == oldcount) {
		for (fl = fl_head; fl != 0; fl = fl->f_next)
D 12
			free(fl);
E 12
I 12
			free((char *)fl);
E 12
		return;
	}
	if (oldcount == -1) {
		fl = (struct file_list *) malloc(sizeof *fl);
		fl->f_fn = name;
		fl->f_type = count;
		fl->f_next = fl_head;
		fl_head = fl;
	}
E 9
D 3
	if (tp->f_needs == NULL)
	    continue;
	count = 0;
	for (ip = dtab; ip != NULL; ip = ip->d_next)
E 3
I 3
	outf = fopen(file, "w");
I 5
D 9
	if (outf == NULL) {
	    perror(file);
	    exit(1);
E 9
I 9
	if (outf == 0) {
		perror(file);
		exit(1);
E 9
	}
E 5
D 9
	fprintf(outf, "#define %s %d\n", name, count);
	fclose(outf);
	return;
    }
    fl_head = NULL;
    while(1)
    {
	rdln(inf, inw, inc);
	if (inw == EOF)
	    break;
	if (eq(inw, name))
E 3
	{
D 3
	    if (eq(tp->f_needs, ip->d_name))
		count++;
E 3
I 3
	    oldcount = inc;
	    inc = count;
E 9
I 9
	for (fl = fl_head; fl != 0; fl = fl->f_next) {
D 16
		fprintf(outf, "#define %s %d\n",
E 16
I 16
		fprintf(outf, "#define %s %u\n",
E 16
		    fl->f_fn, count ? fl->f_type : 0);
D 12
		free(fl);
E 12
I 12
		free((char *)fl);
E 12
E 9
E 3
	}
D 3
	do_header(tp->f_needs, count);
E 3
I 3
D 9
	fl = (struct file_list *) malloc(sizeof *fl);
	fl->f_fn = inw;
	fl->f_type = inc;
	fl->f_next = fl_head;
	fl_head = fl;
E 3
    }
I 3
    fclose(inf);
    if (count == oldcount)
    {
	for (fl = fl_head; fl != NULL; fl = fl->f_next)
	    free(fl);
	return;
    }
    if (oldcount == -1)
    {
	fl = (struct file_list *) malloc(sizeof *fl);
	fl->f_fn = name;
	fl->f_type = count;
	fl->f_next = fl_head;
	fl_head = fl;
    }
    outf = fopen(file, "w");
I 5
    if (outf == NULL) {
	perror(file);
	exit(1);
    }
E 5
    for (fl = fl_head; fl != NULL; fl = fl->f_next)
    {
D 6
	fprintf(outf, "#define %s %d\n", fl->f_fn, fl->f_type);
E 6
I 6
	fprintf(outf, "#define %s %d\n", fl->f_fn, count ? fl->f_type : 0);
E 6
	free(fl);
    }
    fclose(outf);
E 9
I 9
D 12
	fclose(outf);
E 12
I 12
	(void) fclose(outf);
E 12
E 9
E 3
}

/*
D 3
 * tomacro
 *	Convert a two character name to a NXX
E 3
I 3
D 9
 * toheader:
 *	Convert a dev name to a .h file nae
E 9
I 9
 * convert a dev name to a .h file name
E 9
E 3
 */
D 9

D 3
tomacro(nm)
register char *nm;
E 3
I 3
char *toheader(dev)
char *dev;
E 9
I 9
char *
toheader(dev)
	char *dev;
E 9
E 3
{
D 3
    static char ret[80];
    register char *cp;
E 3
I 3
D 9
    static char hbuf[80];
E 9
I 9
	static char hbuf[80];
E 9
E 3

D 3
    cp = ret;
    *cp++ = 'N';
    while(*nm)
	*cp++ = toupper(*nm++);
    *cp++ = '\0';
    return ret;
E 3
I 3
D 4
    strcpy(hbuf, PREFIX);
    strcat(hbuf, dev);
E 4
I 4
D 9
    strcpy(hbuf, path(dev));
E 4
    strcat(hbuf, ".h");
    return hbuf;
E 9
I 9
D 12
	strcpy(hbuf, path(dev));
	strcat(hbuf, ".h");
E 12
I 12
	(void) strcpy(hbuf, path(dev));
	(void) strcat(hbuf, ".h");
E 12
D 11
	return (hbuf)
E 11
I 11
	return (hbuf);
E 11
E 9
E 3
}

/*
D 3
 * do_header:
 *	See if a header file needs to be changed
E 3
I 3
D 9
 * tomacro:
 *	Convert a dev name to a macro name
E 9
I 9
 * convert a dev name to a macro name
E 9
E 3
 */
D 9

E 9
D 3
do_header(dev, count)
char *dev;
int count;
E 3
I 3
char *tomacro(dev)
D 9
register char *dev;
E 9
I 9
	register char *dev;
E 9
E 3
{
D 3
    register FILE *f;
    char file[80];
    register char *w;
    register int oldcount;
E 3
I 3
D 9
    static char mbuf[20];
    register char *cp;
E 9
I 9
	static char mbuf[20];
	register char *cp;
E 9
E 3

D 3
    strcpy(file, "_unix/");
    strcat(file, dev);
    strcat(file, ".h");
    oldcount = -1;
    if ((f = fopen(file, "r")) != NULL)
    {
	/*
	 * Throw out the #define and the NXX
	 */
	if ((w = get_word(f)) != EOF && w != NULL)
	    if ((w = get_word(f)) == EOF && w != NULL)
		oldcount = atoi(get_word(f));
	fclose(f);
    }
    if (oldcount != count)
    {
	f = fopen(file, "w");
	fprintf(f, "#define %s %d\n", tomacro(dev), count);
	fclose(f);
    }
E 3
I 3
D 9
    cp = mbuf;
    *cp++ = 'N';
    while(*dev)
	*cp++ = toupper(*dev++);
    *cp++ = '\0';
    return mbuf;
E 9
I 9
	cp = mbuf;
	*cp++ = 'N';
	while (*dev)
		*cp++ = toupper(*dev++);
	*cp++ = 0;
D 11
	return (mbuf)
E 11
I 11
	return (mbuf);
E 11
E 9
E 3
}
E 1
