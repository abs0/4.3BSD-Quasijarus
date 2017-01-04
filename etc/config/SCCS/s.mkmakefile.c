h60547
s 00002/00003/00678
d D 5.22 04/01/04 10:45:31 msokolov 58 57
c VAX do_systemspec: take out emulate.o, it's now listed regularly in files.vax
e
s 00010/00005/00671
d D 5.21 88/06/18 13:43:12 bostic 57 56
c install approved copyright notice
e
s 00009/00003/00667
d D 5.20 88/04/29 13:43:35 bostic 56 55
c add Berkeley specific header; original conception by Michael Toy
e
s 00002/00002/00668
d D 5.19 87/10/22 11:09:51 bostic 55 54
c ANSI C; sprintf now returns an int.
e
s 00001/00001/00669
d D 5.18 87/09/04 17:49:29 mckusick 54 53
c add symbols.sort to the dependency list (4.3BSD/etc/89)
e
s 00001/00001/00669
d D 5.17 87/07/03 10:44:07 karels 53 52
c dependency on INLINE is nice, but not when it includes options
e
s 00001/00001/00669
d D 5.16 87/06/15 12:13:00 karels 52 51
c consistent format for .o rules
e
s 00007/00003/00663
d D 5.15 87/05/08 10:57:59 sam 51 50
c vax's require emulate.o in dependency list (from jim mckie)
e
s 00004/00001/00662
d D 5.14 87/05/04 11:18:00 karels 50 49
c what he really meant was this...
e
s 00001/00001/00662
d D 5.13 87/05/03 13:45:36 sam 49 48
c fix swap file reference in CFILES (from mel@rockeffeller.arpa)
e
s 00031/00027/00632
d D 5.12 87/04/06 11:28:54 bostic 48 47
c fix to add swap files to CFILES
e
s 00001/00001/00658
d D 5.11 87/04/06 10:10:37 bostic 47 46
c fprintf format/argument mismatch
e
s 00024/00005/00635
d D 5.10 86/10/13 15:35:38 sam 46 45
c replace ancient sun support with tahoe support
e
s 00003/00002/00637
d D 5.9 86/05/06 18:52:10 bloom 45 44
c add emulate.o to the files for vmunix
e
s 00001/00001/00638
d D 5.8 86/05/03 12:45:20 bloom 44 43
c need to separate inline command from arguments in dependency list
e
s 00002/00000/00637
d D 5.7 86/04/18 14:25:27 karels 43 42
c add makeoptions (for uVaxII and other such needs)
e
s 00028/00025/00609
d D 5.6 86/02/18 17:16:34 sam 42 41
c parameterize maxusers definition checking; make inline a Makefile macro
e
s 00005/00003/00629
d D 5.5 85/10/14 10:57:56 karels 41 40
c fix ordering problem of duplicate files with different dependencies
e
s 00004/00000/00628
d D 5.4 85/09/18 22:16:53 karels 40 39
c allow .o's in files.*
e
s 00004/00002/00624
d D 5.3 85/09/18 21:59:38 karels 39 38
c oops
e
s 00044/00019/00582
d D 5.2 85/09/17 22:48:43 karels 38 37
c rename Makefile; allow files to be included multiple times
c to allow dependency disjunction; files may depend on options as well
c as devices, eliminating the need for corresponding pseudo-devices
e
s 00007/00001/00594
d D 5.1 85/05/08 11:57:58 dist 37 36
c Add copyright
e
s 00006/00037/00589
d D 1.34 84/12/07 10:06:15 bloom 36 35
c Change to header file includes for kernel
e
s 00006/00005/00620
d D 1.33 84/08/20 21:59:55 mckusick 35 34
c now using /sys/vax/inline/inline instead of /sys/vax/asm to inline expand
e
s 00004/00001/00621
d D 1.32 84/08/01 17:46:39 mckusick 34 33
c add provision for .s files to be profiled
e
s 00009/00009/00613
d D 1.31 84/05/12 22:16:11 sam 33 32
c convert from asm.sed script to asm program
e
s 00003/00001/00619
d D 1.30 83/08/11 22:54:33 sam 32 31
c standardize sccs keyword lines
e
s 00003/00001/00617
d D 1.29 83/06/29 17:59:05 sam 31 30
c this should not be wired in, but I'm lazy
e
s 00043/00015/00575
d D 1.28 83/06/16 18:17:59 sam 30 29
c allow files to be marked config-dependent to get ${PARAMS}
e
s 00084/00058/00506
d D 1.27 83/05/18 00:19:50 sam 29 28
c dynamically create swap configuration files
e
s 00048/00006/00516
d D 1.26 83/04/24 23:28:40 mckusick 28 26
c allow local files to be configured in
e
s 00022/00021/00501
d R 1.26 83/02/21 23:37:25 sam 27 26
c kludge; put MAXUSERS in IDENT so machdep can have it for SYSPTSIZE
e
s 00014/00000/00508
d D 1.25 83/02/09 15:03:12 sam 26 25
c from sun
e
s 00004/00004/00504
d D 1.24 83/01/14 14:28:11 mckusick 25 24
c fix-up for making GPROF'ed system.
e
s 00001/00001/00507
d D 1.23 82/12/18 18:45:48 sam 24 23
c wrong path to crt0.ex
e
s 00011/00006/00497
d D 1.22 82/12/09 21:34:31 sam 23 22
c somehow the -p option went away
e
s 00033/00031/00470
d D 1.21 82/10/25 00:59:26 root 22 21
c lint and cleanup
e
s 00001/00001/00500
d D 1.20 82/10/24 22:53:42 root 21 20
c get rid of bool, TRUE and FALSE
e
s 00007/00007/00494
d D 1.19 82/10/24 22:18:40 root 20 19
c print on stdout, not stderr
e
s 00401/00339/00100
d D 1.18 82/10/24 21:57:33 root 19 18
c new version from sun
e
s 00042/00002/00397
d D 1.17 82/10/11 12:08:55 sam 18 17
c -p option to create profiling kernel
e
s 00004/00001/00395
d D 1.16 82/07/21 22:29:30 kre 17 16
c print options that have values with their values
e
s 00004/00004/00392
d D 1.15 82/07/13 22:02:59 kre 16 15
c mods to reflect motion of sys source & config files
e
s 00001/00001/00395
d D 1.14 82/06/14 23:58:18 mckusick 15 14
c get rid of special purpose touch
e
s 00001/00001/00395
d D 1.13 82/04/01 07:42:56 root 14 13
c fix per wnj
e
s 00002/00001/00394
d D 1.12 81/10/12 12:50:26 ecc 13 12
c fix broken header production
e
s 00036/00019/00359
d D 1.11 81/10/08 00:05:41 ecc 12 11
c allow list (conjunction) of required devs after optional files
e
s 00003/00001/00375
d D 1.10 81/05/18 01:02:26 root 11 10
c hz not needed; always 60
e
s 00003/00003/00373
d D 1.9 81/04/03 01:17:14 root 10 8
c Fixed a stupidity
e
s 00002/00002/00374
d R 1.9 81/04/03 01:15:12 root 9 8
c FIxed a stupidity
e
s 00008/00001/00368
d D 1.8 81/04/03 01:11:51 root 8 7
c Added version counting stuff
e
s 00001/00000/00368
d D 1.7 81/03/31 16:43:21 toy 7 6
c 
e
s 00016/00011/00352
d D 1.6 81/03/31 16:38:49 toy 6 5
c 
e
s 00001/00001/00362
d D 1.5 81/03/06 21:58:39 toy 5 4
c 
e
s 00037/00003/00326
d D 1.4 81/03/06 21:37:10 toy 4 3
c Bill's changes + some of mine
e
s 00014/00011/00315
d D 1.3 81/02/26 12:48:10 wnj 3 2
c stamp for sending to dec... still bugs in mkioconf.c
e
s 00025/00008/00301
d D 1.2 81/02/26 01:44:47 wnj 2 1
c put away mikes stuff
e
s 00309/00000/00000
d D 1.1 81/02/24 21:06:50 toy 1 0
c date and time created 81/02/24 21:06:50 by toy
e
u
U
t
T
I 37
/*
 * Copyright (c) 1980 Regents of the University of California.
D 56
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 56
I 56
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 57
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 57
I 57
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
E 57
E 56
 */

E 37
I 19
D 32
/*	%M%	%I%	%E%	*/
E 32
I 32
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 37
#endif
E 37
I 37
D 56
#endif not lint
E 56
I 56
#endif /* not lint */
E 56
E 37
E 32

E 19
I 1
/*
D 19
 * %M%	%I%	%E%
 *	Functions in this file build the makefile from the files list
 *	and the information in the config table
E 19
I 19
 * Build the makefile for the system, from
 * the information in the files files and the
 * additional files for the machine being compiled to.
E 19
 */

#include <stdio.h>
I 2
#include <ctype.h>
E 2
#include "y.tab.h"
#include "config.h"

D 19
#define next_word(fp, wd)\
    { register char *word = get_word(fp);\
	if (word == EOF) return EOF; \
	else wd = word; }
E 19
I 19
#define next_word(fp, wd) \
	{ register char *word = get_word(fp); \
D 22
	  if (word == EOF) \
		return (EOF); \
E 22
I 22
	  if (word == (char *)EOF) \
		return; \
E 22
	  else \
		wd = word; \
	}
E 19

D 19
static struct file_list *fcur;
E 19
I 19
static	struct file_list *fcur;
I 28
char *tail();
E 28
E 19

/*
D 19
 * fl_lookup
 *	look up a file name
E 19
I 19
D 41
 * Lookup a file, by make.
E 41
I 41
 * Lookup a file, by name.
E 41
E 19
 */
D 19

struct file_list *fl_lookup(file)
register char *file;
E 19
I 19
struct file_list *
fl_lookup(file)
	register char *file;
E 19
{
D 19
    register struct file_list *fp;
E 19
I 19
	register struct file_list *fp;
E 19

D 19
    for (fp = ftab ; fp != NULL; fp = fp->f_next)
    {
	if (eq(fp->f_fn, file))
	    return fp;
    }
    return NULL;
E 19
I 19
D 22
	for (fp = ftab ; fp != NULL; fp = fp->f_next) {
E 22
I 22
	for (fp = ftab ; fp != 0; fp = fp->f_next) {
E 22
		if (eq(fp->f_fn, file))
			return (fp);
	}
	return (0);
E 19
}

/*
I 28
 * Lookup a file, by final component name.
 */
struct file_list *
fltail_lookup(file)
	register char *file;
{
	register struct file_list *fp;

	for (fp = ftab ; fp != 0; fp = fp->f_next) {
		if (eq(tail(fp->f_fn), tail(file)))
			return (fp);
	}
	return (0);
}

/*
E 28
D 19
 * new_fent
 *	Make a new file list entry
E 19
I 19
 * Make a new file list entry
E 19
 */
D 19

struct file_list *new_fent()
E 19
I 19
struct file_list *
new_fent()
E 19
{
D 19
    register struct file_list *fp;
E 19
I 19
	register struct file_list *fp;
E 19

D 19
    fp = (struct file_list *) malloc(sizeof *fp);
    fp->f_needs = fp->f_next = NULL;
    if (fcur == NULL)
	fcur = ftab = fp;
    else
	fcur->f_next = fp;
    fcur = fp;
    return fp;
E 19
I 19
	fp = (struct file_list *) malloc(sizeof *fp);
D 22
	fp->f_needs = fp->f_next = NULL;
	if (fcur == NULL)
E 22
I 22
	fp->f_needs = 0;
	fp->f_next = 0;
I 30
	fp->f_flags = 0;
	fp->f_type = 0;
E 30
	if (fcur == 0)
E 22
		fcur = ftab = fp;
	else
		fcur->f_next = fp;
	fcur = fp;
	return (fp);
E 19
}

I 18
D 19
char	*COPTS;			/* pointer to ${COPTS} macro for gprof */
E 19
I 19
char	*COPTS;
I 42
static	struct users {
	int	u_default;
	int	u_min;
	int	u_max;
} users[] = {
	{ 24, 8, 1024 },		/* MACHINE_VAX */
I 46
	{ 4, 2, 128 },			/* MACHINE_TAHOE */
E 46
};
#define	NUSERS	(sizeof (users) / sizeof (users[0]))
E 42

E 19
E 18
/*
D 19
 * makefile:
 *	Build the makefile from the skeleton
E 19
I 19
 * Build the makefile from the skeleton
E 19
 */
D 19

E 19
makefile()
{
D 19
    FILE *ifp, *ofp;
D 3
    char line[80];
E 3
I 3
    char line[BUFSIZ];
I 4
    struct cputype *cp;
I 6
    struct opt *op;
E 19
I 19
	FILE *ifp, *ofp;
	char line[BUFSIZ];
	struct opt *op;
I 42
	struct users *up;
E 42
E 19
E 6
E 4
E 3

D 19
    read_files();			/* Read in the "files" file */
D 2
    ifp = fopen(path(makefile), "r");
    ofp = fopen(path(Makefile), "w");
E 2
I 2
D 3
    ifp = fopen("../unix/makefile", "r");
E 3
I 3
    ifp = fopen("../conf/makefile", "r");
I 4
    if (ifp == NULL) {
	perror("../conf/makefile");
	exit(1);
    }
E 4
E 3
    ofp = fopen(path("makefile"), "w");
D 4
    fprintf(ofp, "IDENT=-D%s -D%s\n", raise(ident), cpu_type);
E 4
I 4
    if (ofp == NULL) {
	perror(path("makefile"));
	exit(1);
    }
    fprintf(ofp, "IDENT=-D%s", raise(ident));
I 18
    if (profiling)
	fprintf(ofp, " -DGPROF");
E 18
    if (cputype == NULL) {
	printf("cpu type must be specified\n");
	exit(1);
    }
    for (cp = cputype; cp; cp = cp->cpu_next)
	fprintf(ofp, " -D%s", cp->cpu_name);
I 6
    for (op = opt; op; op = op->op_next)
D 17
	  fprintf(ofp, " -D%s", op->op_name);
E 17
I 17
	  if (op->op_value)
		fprintf(ofp, " -D%s=\"%s\"", op->op_name, op->op_value);
	  else
		fprintf(ofp, " -D%s", op->op_name);
E 17
E 6
    fprintf(ofp, "\n");
    if (hz == 0) {
I 11
#ifdef notdef
E 11
	printf("hz not specified; 50hz assumed\n");
D 11
	hz = 50;
E 11
I 11
#endif
	hz = 60;
E 11
    }
    if (hadtz == 0)
	printf("timezone not specified; gmt assumed\n");
    if (maxusers == 0) {
	printf("maxusers not specified; 24 assumed\n");
	maxusers = 24;
    } else if (maxusers < 8) {
	printf("minimum of 8 maxusers assumed\n");
	maxusers = 8;
D 6
    } else if (maxusers > 100) {
	printf("maxusers truncated to 100\n");
E 6
I 6
    } else if (maxusers > 128) {
	printf("maxusers truncated to 128\n");
E 6
	maxusers = 128;
    }
    fprintf(ofp, "PARAM=-DHZ=%d -DTIMEZONE=%d -DDST=%d -DMAXUSERS=%d\n",
	hz, timezone, dst, maxusers);
E 4
E 2
D 3
    while(fgets(line, 80, ifp) != NULL)
E 3
I 3
    while(fgets(line, BUFSIZ, ifp) != NULL)
E 3
    {
	if (*line != '%')
	{
I 18
	    register char *cp;
E 19
I 19
	read_files();
D 38
	strcpy(line, "../conf/makefile.");
E 38
I 38
	strcpy(line, "../conf/Makefile.");
E 38
D 22
	strcat(line, machinename);
E 22
I 22
	(void) strcat(line, machinename);
E 22
	ifp = fopen(line, "r");
D 22
	if (ifp == NULL) {
E 22
I 22
	if (ifp == 0) {
E 22
		perror(line);
		exit(1);
	}
D 38
	ofp = fopen(path("makefile"), "w");
E 38
I 38
	ofp = fopen(path("Makefile"), "w");
E 38
D 22
	if (ofp == NULL) {
E 22
I 22
	if (ofp == 0) {
E 22
D 38
		perror(path("makefile"));
E 38
I 38
		perror(path("Makefile"));
E 38
		exit(1);
	}
	fprintf(ofp, "IDENT=-D%s", raise(ident));
	if (profiling)
		fprintf(ofp, " -DGPROF");
	if (cputype == 0) {
		printf("cpu type must be specified\n");
		exit(1);
	}
	{ struct cputype *cp;
	  for (cp = cputype; cp; cp = cp->cpu_next)
		fprintf(ofp, " -D%s", cp->cpu_name);
	}
	for (op = opt; op; op = op->op_next)
		if (op->op_value)
			fprintf(ofp, " -D%s=\"%s\"", op->op_name, op->op_value);
		else
			fprintf(ofp, " -D%s", op->op_name);
	fprintf(ofp, "\n");
	if (hadtz == 0)
		printf("timezone not specified; gmt assumed\n");
I 26
D 42
#ifdef vax
E 42
I 42
	if ((unsigned)machine > NUSERS) {
		printf("maxusers config info isn't present, using vax\n");
		up = &users[MACHINE_VAX-1];
	} else
		up = &users[machine-1];
E 42
E 26
	if (maxusers == 0) {
D 42
		printf("maxusers not specified; 24 assumed\n");
		maxusers = 24;
	} else if (maxusers < 8) {
		printf("minimum of 8 maxusers assumed\n");
		maxusers = 8;
D 38
	} else if (maxusers > 128) {
		printf("maxusers truncated to 128\n");
		maxusers = 128;
	}
E 38
I 38
	} else if (maxusers > 1024)
		printf("warning: maxusers > 1024 (%d)\n", maxusers);
E 38
I 26
#endif
E 42
I 42
		printf("maxusers not specified; %d assumed\n", up->u_default);
		maxusers = up->u_default;
	} else if (maxusers < up->u_min) {
		printf("minimum of %d maxusers assumed\n", up->u_min);
		maxusers = up->u_min;
	} else if (maxusers > up->u_max)
		printf("warning: maxusers > %d (%d)\n", up->u_max, maxusers);
E 42
D 36
#ifdef sun
	if (maxusers == 0) {
		printf("maxusers not specified; 8 assumed\n");
		maxusers = 8;
	} else if (maxusers < 2) {
		printf("minimum of 2 maxusers assumed\n");
		maxusers = 2;
	} else if (maxusers > 32) {
		printf("maxusers truncated to 32\n");
		maxusers = 32;
	}
#endif
E 36
E 26
	fprintf(ofp, "PARAM=-DTIMEZONE=%d -DDST=%d -DMAXUSERS=%d\n",
	    timezone, dst, maxusers);
I 43
	for (op = mkopt; op; op = op->op_next)
		fprintf(ofp, "%s=%s\n", op->op_name, op->op_value);
E 43
D 22
	while (fgets(line, BUFSIZ, ifp) != NULL) {
E 22
I 22
	while (fgets(line, BUFSIZ, ifp) != 0) {
E 22
		if (*line == '%')
			goto percent;
		if (profiling && strncmp(line, "COPTS=", 6) == 0) {
			register char *cp;
E 19

D 19
	    if (profiling && strncmp(line, "COPTS=", 6) == 0) {
		fprintf(ofp, "CRT0.EX=/usr/src/libc/csu/crt0.ex\n");
		cp = index(line, '\n');
		if (cp)
			*cp = '\0';
		cp = line + 6;
		while (*cp && (*cp == ' ' || *cp == '\t'))
			cp++;
		COPTS = malloc(strlen(cp) + 1);
		if (COPTS == 0) {
			fprintf(stderr, "config: out of memory\n");
			exit(1);
E 19
I 19
D 24
			fprintf(ofp, "CRT0.EX=/usr/src/libc/csu/crt0.ex\n");
E 24
I 24
D 25
			fprintf(ofp, "CRT0.EX=/usr/src/lib/libc/csu/crt0.ex\n");
E 25
I 25
D 31
			fprintf(ofp, "GPROF.EX=/usr/src/lib/libc/csu/gmon.ex\n");
E 31
I 31
			fprintf(ofp, 
			    "GPROF.EX=/usr/src/lib/libc/%s/csu/gmon.ex\n",
			    machinename);
E 31
E 25
E 24
			cp = index(line, '\n');
			if (cp)
				*cp = 0;
			cp = line + 6;
			while (*cp && (*cp == ' ' || *cp == '\t'))
				cp++;
D 22
			COPTS = malloc(strlen(cp) + 1);
E 22
I 22
			COPTS = malloc((unsigned)(strlen(cp) + 1));
E 22
			if (COPTS == 0) {
D 20
				fprintf(stderr, "config: out of memory\n");
E 20
I 20
				printf("config: out of memory\n");
E 20
				exit(1);
			}
			strcpy(COPTS, cp);
			fprintf(ofp, "%s -pg\n", line);
			continue;
E 19
		}
D 19
		strcpy(COPTS, cp);
		fprintf(ofp, "%s -pg\n", line);
E 19
I 19
		fprintf(ofp, "%s", line);
E 19
		continue;
D 19
	    }
E 18
	    fprintf(ofp, "%s", line);
	    continue;
E 19
I 19
	percent:
		if (eq(line, "%OBJS\n"))
			do_objs(ofp);
		else if (eq(line, "%CFILES\n"))
			do_cfiles(ofp);
		else if (eq(line, "%RULES\n"))
			do_rules(ofp);
		else if (eq(line, "%LOAD\n"))
			do_load(ofp);
		else
			fprintf(stderr,
			    "Unknown %% construct in generic makefile: %s",
			    line);
D 22
		fclose(ifp);
		fclose(ofp);
E 22
I 22
D 23
		(void) fclose(ifp);
		(void) fclose(ofp);
E 23
E 22
E 19
	}
I 23
	(void) fclose(ifp);
	(void) fclose(ofp);
E 23
D 19
	else if (eq(line, "%OBJS\n"))
	    do_objs(ofp);
	else if (eq(line, "%CFILES\n"))
	    do_cfiles(ofp);
	else if (eq(line, "%RULES\n"))
	    do_rules(ofp);
	else if (eq(line, "%LOAD\n"))
	    do_load(ofp);
	else
D 3
	    fprintf(stderr, "Unknown %% thingy in generic makefile %s", line);
E 3
I 3
	    fprintf(stderr, "Unknown %% construct in generic makefile: %s", line);
E 3
    }
    fclose(ifp);
    fclose(ofp);
E 19
}

/*
D 19
 * files:
 *	Read in the "files" file.
 *	Store it in the ftab linked list
E 19
I 19
 * Read in the information about files used in making the system.
 * Store it in the ftab linked list.
E 19
 */
D 19

E 19
read_files()
{
D 19
    FILE *fp;
    register struct file_list *tp;
    register struct device *dp;
    register char *wd, *this;
D 12
    int type;
E 12
I 12
    int type, nreqs, dev;
E 19
I 19
	FILE *fp;
D 41
	register struct file_list *tp;
E 41
I 41
	register struct file_list *tp, *pf;
E 41
	register struct device *dp;
I 38
	register struct opt *op;
E 38
	char *wd, *this, *needs, *devorprof;
	char fname[32];
D 30
	int nreqs;
	int first = 1;
E 30
I 30
D 38
	int nreqs, first = 1, configdep;
E 38
I 38
	int nreqs, first = 1, configdep, isdup;
E 38
E 30
E 19
E 12

D 2
    fp = fopen(path(files), "r");
E 2
I 2
D 3
    fp = fopen("../unix/files", "r");
E 2

E 3
I 3
D 19
    fp = fopen("../conf/files", "r");
    if (fp == NULL) {
	perror("../conf/files");
	exit(1);
    }
E 3
    ftab = NULL;
    while((wd = get_word(fp)) != EOF)
    {
E 19
I 19
D 22
	ftab = NULL;
	strcpy(fname, "files");
E 22
I 22
	ftab = 0;
	(void) strcpy(fname, "files");
E 22
openit:
	fp = fopen(fname, "r");
D 22
	if (fp == NULL) {
E 22
I 22
	if (fp == 0) {
E 22
D 23
		perror("../conf/files");
E 23
I 23
		perror(fname);
E 23
		exit(1);
	}
next:
D 30
	/* filename	[ standard | optional dev* ] [ device-driver ] */
E 30
I 30
	/*
	 * filename	[ standard | optional ] [ config-dependent ]
	 *	[ dev* | profiling-routine ] [ device-driver]
	 */
E 30
	wd = get_word(fp);
D 22
	if (wd == EOF) {
		fclose(fp);
E 22
I 22
	if (wd == (char *)EOF) {
		(void) fclose(fp);
E 22
D 28
		if (first) {
E 28
I 28
		if (first == 1) {
E 28
D 22
			sprintf(fname, "files.%s", machinename);
E 22
I 22
			(void) sprintf(fname, "files.%s", machinename);
E 22
D 28
			first = 0;
E 28
I 28
			first++;
E 28
			goto openit;
		}
I 28
		if (first == 2) {
			(void) sprintf(fname, "files.%s", raise(ident));
			first++;
			fp = fopen(fname, "r");
			if (fp != 0)
				goto next;
		}
E 28
		return;
	}
E 19
D 22
	if (wd == NULL)
E 22
I 22
	if (wd == 0)
E 22
D 19
	    continue;
E 19
I 19
		goto next;
E 19
	this = ns(wd);
D 19
	/*
D 5
	 * Read standard/optional
E 5
I 5
D 12
	 * Readad standard/optional
E 12
I 12
	 * Read standard/optional
E 12
E 5
	 */
E 19
	next_word(fp, wd);
D 19
	if (wd == NULL)
	{
	    fprintf(stderr, "Huh, no type for %s in files.\n", this);
	    exit(10);
E 19
I 19
D 22
	if (wd == NULL) {
E 22
I 22
	if (wd == 0) {
E 22
D 20
		fprintf(stderr, "%s: No type for %s.\n",
E 20
I 20
		printf("%s: No type for %s.\n",
E 20
		    fname, this);
		exit(1);
E 19
	}
D 19
	if ((tp = fl_lookup(wd)) == NULL)
	    tp = new_fent();
	else
	    free(tp->f_fn);
E 19
I 19
D 38
	if (fl_lookup(this)) {
D 20
		fprintf(stderr, "%s: Duplicate file %s.\n",
E 20
I 20
		printf("%s: Duplicate file %s.\n",
E 20
		    fname, this);
		exit(1);
	}
E 38
I 38
D 41
	if ((tp = fl_lookup(this)) && (tp->f_type != INVISIBLE || tp->f_flags))
E 41
I 41
	if ((pf = fl_lookup(this)) && (pf->f_type != INVISIBLE || pf->f_flags))
E 41
		isdup = 1;
	else
		isdup = 0;
E 38
I 28
	tp = 0;
	if (first == 3 && (tp = fltail_lookup(this)) != 0)
		printf("%s: Local file %s overrides %s.\n",
		    fname, this, tp->f_fn);
E 28
	nreqs = 0;
	devorprof = "";
I 30
	configdep = 0;
E 30
	needs = 0;
	if (eq(wd, "standard"))
		goto checkdev;
	if (!eq(wd, "optional")) {
D 20
		fprintf(stderr, "%s: %s must be optional or standard",
E 20
I 20
D 23
		printf("%s: %s must be optional or standard",
E 23
I 23
D 30
		printf("%s: %s must be optional or standard\n",
E 23
E 20
		    fname, this);
E 30
I 30
		printf("%s: %s must be optional or standard\n", fname, this);
E 30
		exit(1);
	}
nextopt:
	next_word(fp, wd);
D 22
	if (wd == NULL)
E 22
I 22
	if (wd == 0)
E 22
		goto doneopt;
I 30
	if (eq(wd, "config-dependent")) {
		configdep++;
		goto nextopt;
	}
E 30
	devorprof = wd;
D 23
	if (eq(wd, "device-driver") || eq(wd, "profiling-routine"))
E 23
I 23
	if (eq(wd, "device-driver") || eq(wd, "profiling-routine")) {
		next_word(fp, wd);
E 23
		goto save;
I 23
	}
E 23
	nreqs++;
D 38
	if (needs == 0)
E 38
I 38
	if (needs == 0 && nreqs == 1)
E 38
		needs = ns(wd);
I 38
	if (isdup)
		goto invis;
E 38
D 22
	for (dp = dtab; dp != NULL; dp = dp->d_next)
E 22
I 22
	for (dp = dtab; dp != 0; dp = dp->d_next)
E 22
		if (eq(dp->d_name, wd))
			goto nextopt;
I 38
	for (op = opt; op != 0; op = op->op_next)
		if (op->op_value == 0 && opteq(op->op_name, wd)) {
			if (nreqs == 1) {
				free(needs);
				needs = 0;
			}
			goto nextopt;
		}
invis:
E 38
D 22
	while ((wd = get_word(fp)) != NULL)
E 22
I 22
	while ((wd = get_word(fp)) != 0)
E 22
		;
D 28
	tp = new_fent();
E 28
I 28
D 38
	if (tp == 0)
		tp = new_fent();
E 38
I 38
D 39
	tp = new_fent();
E 39
I 39
	if (tp == 0)
		tp = new_fent();
E 39
E 38
E 28
E 19
	tp->f_fn = this;
D 12
	type = 0;
E 12
I 12
D 19
	nreqs = dev = type = 0;
E 12
	if (eq(wd, "optional"))
	{
D 12
	    next_word(fp, wd);
	    if (wd == NULL)
E 12
I 12
	    for (;;) 
E 12
	    {
E 19
I 19
	tp->f_type = INVISIBLE;
	tp->f_needs = needs;
I 38
	tp->f_flags = isdup;
E 38
	goto next;
I 30

E 30
doneopt:
	if (nreqs == 0) {
D 20
		fprintf(stderr, "%s: what is %s optional on?\n",
E 20
I 20
		printf("%s: what is %s optional on?\n",
E 20
		    fname, this);
		exit(1);
	}
I 30

E 30
checkdev:
	if (wd) {
E 19
D 12
		fprintf(stderr, "Needed a dev for optional(%s)\n", this);
		exit(11);
	    }
	    tp->f_needs = ns(wd);
	    for (dp = dtab ; dp != NULL; dp = dp->d_next)
	    {
		if (eq(dp->d_name, wd))
E 12
I 12
		next_word(fp, wd);
D 19
		if (wd == NULL || (dev = eq(wd, "device-driver")))
		{
		    if (nreqs == 0)
		    {
			fprintf(stderr, "Needed a dev for optional(%s)\n",
				this);
			exit(11);
		    }
		    else
			break;
E 19
I 19
D 22
		if (wd != NULL) {
E 22
I 22
D 30
		if (wd != 0) {
E 30
I 30
		if (wd) {
			if (eq(wd, "config-dependent")) {
				configdep++;
				goto checkdev;
			}
E 30
E 22
			devorprof = wd;
			next_word(fp, wd);
E 19
		}
D 19
		nreqs++;
D 13
		/* tp->f_needs = ns(wd); */
E 13
I 13
		if (tp->f_needs == NULL)
			tp->f_needs = ns(wd);
E 13
		for (dp = dtab ; dp != NULL; dp = dp->d_next)
		{
		    if (eq(dp->d_name, wd))
			break;
		}
		if (dp == NULL)
		{
		    type = INVISIBLE;
		    while ((wd = get_word(fp)) != NULL)
			;
E 12
		    break;
I 12
		}
E 12
	    }
E 19
D 12
	    if (dp == NULL)
		type = INVISIBLE;
E 12
	}
I 30

E 30
D 12
	next_word(fp, wd);
	if (type == 0 && wd != NULL)
	    type = DEVICE;
	else if (type == 0)
	    type = NORMAL;
E 12
I 12
D 19
	if (dev == 0 && wd != NULL)
	{
	    next_word(fp, wd);
D 18
	    dev = (wd != NULL && eq(wd, "device-driver"));
E 18
I 18
	    if (wd != NULL && eq(wd, "profiling-routine"))
		type = PROFILING;
	    else
	        dev = (wd != NULL && eq(wd, "device-driver"));
E 19
I 19
save:
D 22
	if (wd != NULL) {
E 22
I 22
D 30
	if (wd != 0) {
E 30
I 30
	if (wd) {
E 30
E 22
D 20
		fprintf(stderr, "%s: syntax error describing %s\n",
E 20
I 20
		printf("%s: syntax error describing %s\n",
E 20
		    fname, this);
		exit(1);
E 19
E 18
	}
I 23
	if (eq(devorprof, "profiling-routine") && profiling == 0)
		goto next;
E 23
D 19
	if (type == 0)
	    type = dev ? DEVICE : NORMAL;
E 12
	tp->f_type = type;
    }
    fclose(fp);
E 19
I 19
D 28
	tp = new_fent();
E 28
I 28
D 38
	if (tp == 0)
		tp = new_fent();
E 38
I 38
D 39
	tp = new_fent();
E 39
I 39
	if (tp == 0)
		tp = new_fent();
E 39
E 38
E 28
	tp->f_fn = this;
	if (eq(devorprof, "device-driver"))
D 30
		tp->f_type = DEVICE;
E 30
I 30
		tp->f_type = DRIVER;
E 30
	else if (eq(devorprof, "profiling-routine"))
		tp->f_type = PROFILING;
	else
		tp->f_type = NORMAL;
I 30
	tp->f_flags = 0;
	if (configdep)
		tp->f_flags |= CONFIGDEP;
E 30
	tp->f_needs = needs;
I 41
	if (pf && pf->f_type == INVISIBLE)
		pf->f_flags = 1;		/* mark as duplicate */
E 41
	goto next;
E 19
}

I 38
opteq(cp, dp)
	char *cp, *dp;
{
	char c, d;

	for (; ; cp++, dp++) {
		if (*cp != *dp) {
			c = isupper(*cp) ? tolower(*cp) : *cp;
			d = isupper(*dp) ? tolower(*dp) : *dp;
			if (c != d)
				return (0);
		}
		if (*cp == 0)
			return (1);
	}
}

E 38
D 19
/*
 * do_objs
 *	Spew forth the OBJS definition
 */

E 19
do_objs(fp)
D 19
FILE *fp;
E 19
I 19
	FILE *fp;
E 19
{
D 19
    register struct file_list *tp;
    register int lpos, len;
D 2
    register char *cp, och;
E 2
I 2
    register char *cp, och, *sp;
I 7
    char *tail();
E 19
I 19
D 28
	register struct file_list *tp;
E 28
I 28
	register struct file_list *tp, *fl;
E 28
	register int lpos, len;
	register char *cp, och, *sp;
D 28
	char *tail();
E 28
I 28
	char swapname[32];
E 28
E 19
E 7
E 2

D 19
    fprintf(fp, "OBJS=");
    lpos = 6;
    for (tp = ftab; tp != NULL; tp = tp->f_next)
    {
	if (tp->f_type == INVISIBLE)
	    continue;
D 2
	cp = tp->f_fn + (len = strlen(tp->f_fn)) - 1;
E 2
I 2
D 6
	sp = rindex(tp->f_fn, '/') + 1;
E 6
I 6
	sp = tail(tp->f_fn);
E 6
	cp = sp + (len = strlen(sp)) - 1;
E 2
	och = *cp;
	*cp = 'o';
	if (len + lpos > 72)
	{
	    lpos = 8;
	    fprintf(fp, "\\\n\t");
E 19
I 19
	fprintf(fp, "OBJS=");
	lpos = 6;
D 22
	for (tp = ftab; tp != NULL; tp = tp->f_next) {
E 22
I 22
	for (tp = ftab; tp != 0; tp = tp->f_next) {
E 22
		if (tp->f_type == INVISIBLE)
			continue;
		sp = tail(tp->f_fn);
I 28
D 29
		for (fl = conf_list; fl != 0; fl = fl->f_next) {
			(void) sprintf(swapname, "swap%s.c", fl->f_fn);
E 29
I 29
		for (fl = conf_list; fl; fl = fl->f_next) {
			if (fl->f_type != SWAPSPEC)
				continue;
D 55
			sprintf(swapname, "swap%s.c", fl->f_fn);
E 55
I 55
			(void) sprintf(swapname, "swap%s.c", fl->f_fn);
E 55
E 29
			if (eq(sp, swapname))
				goto cont;
		}
E 28
		cp = sp + (len = strlen(sp)) - 1;
		och = *cp;
		*cp = 'o';
		if (len + lpos > 72) {
			lpos = 8;
			fprintf(fp, "\\\n\t");
		}
		fprintf(fp, "%s ", sp);
		lpos += len + 1;
		*cp = och;
I 28
D 29
cont:;
E 29
I 29
cont:
		;
E 29
E 28
E 19
	}
D 2
	fprintf(fp, "%s ", tp->f_fn);
E 2
I 2
D 19
	fprintf(fp, "%s ", sp);
E 2
	lpos += len + 1;
	*cp = och;
    }
    if (lpos != 8)
	putc('\n', fp);
E 19
I 19
	if (lpos != 8)
		putc('\n', fp);
E 19
}

D 19
/*
 * do_cfiles
 *	Spew forth the CFILES definition
 */

E 19
do_cfiles(fp)
D 19
FILE *fp;
E 19
I 19
	FILE *fp;
E 19
{
D 19
    register struct file_list *tp;
    register int lpos, len;
E 19
I 19
D 48
	register struct file_list *tp;
E 48
I 48
	register struct file_list *tp, *fl;
E 48
	register int lpos, len;
I 48
	char swapname[32];
E 48
E 19

D 19
    fprintf(fp, "CFILES=");
    lpos = 8;
    for (tp = ftab; tp != NULL; tp = tp->f_next)
    {
	if (tp->f_type == INVISIBLE)
	    continue;
I 6
	if (tp->f_fn[strlen(tp->f_fn)-1] != 'c')
	    continue;
E 6
D 2
	if ((len = strlen(tp->f_fn)) + lpos > 72)
E 2
I 2
	if ((len = 3 + strlen(tp->f_fn)) + lpos > 72)
E 2
	{
	    lpos = 8;
	    fprintf(fp, "\\\n\t");
E 19
I 19
D 48
	fprintf(fp, "CFILES=");
E 48
I 48
	fputs("CFILES=", fp);
E 48
	lpos = 8;
D 22
	for (tp = ftab; tp != NULL; tp = tp->f_next) {
E 22
I 22
D 48
	for (tp = ftab; tp != 0; tp = tp->f_next) {
E 22
		if (tp->f_type == INVISIBLE)
			continue;
		if (tp->f_fn[strlen(tp->f_fn)-1] != 'c')
			continue;
		if ((len = 3 + strlen(tp->f_fn)) + lpos > 72) {
			lpos = 8;
			fprintf(fp, "\\\n\t");
E 48
I 48
	for (tp = ftab; tp; tp = tp->f_next)
		if (tp->f_type != INVISIBLE) {
			len = strlen(tp->f_fn);
			if (tp->f_fn[len - 1] != 'c')
				continue;
			if ((len = 3 + len) + lpos > 72) {
				lpos = 8;
				fputs("\\\n\t", fp);
			}
			fprintf(fp, "../%s ", tp->f_fn);
			lpos += len + 1;
E 48
		}
D 48
		fprintf(fp, "../%s ", tp->f_fn);
		lpos += len + 1;
E 19
	}
E 48
I 48
	for (fl = conf_list; fl; fl = fl->f_next)
		if (fl->f_type == SYSTEMSPEC) {
D 55
			sprintf(swapname, "swap%s.c", fl->f_fn);
E 55
I 55
			(void) sprintf(swapname, "swap%s.c", fl->f_fn);
E 55
			if ((len = 3 + strlen(swapname)) + lpos > 72) {
				lpos = 8;
				fputs("\\\n\t", fp);
			}
D 49
			fprintf(fp, "../%s ", swapname);
E 49
I 49
D 50
			fprintf(fp, "../%s/%s ", machinename, swapname);
E 50
I 50
			if (eq(fl->f_fn, "generic"))
				fprintf(fp, "../%s/%s ", machinename, swapname);
			else
				fprintf(fp, "%s ", swapname);
E 50
E 49
			lpos += len + 1;
		}
E 48
D 2
	fprintf(fp, "%s ", tp->f_fn);
E 2
I 2
D 19
	fprintf(fp, "../%s ", tp->f_fn);
E 2
	lpos += len + 1;
    }
    if (lpos != 8)
	putc('\n', fp);
E 19
I 19
	if (lpos != 8)
		putc('\n', fp);
E 19
}

D 19
/*
 * tail:
 *	Return tail end of a filename
 */

char *tail(fn)
char *fn;
E 19
I 19
char *
tail(fn)
	char *fn;
E 19
{
D 19
    register char *cp;
E 19
I 19
	register char *cp;
E 19

D 19
    cp = rindex(fn, '/');
    return cp+1;
E 19
I 19
	cp = rindex(fn, '/');
I 28
	if (cp == 0)
		return (fn);
E 28
	return (cp+1);
E 19
}

/*
D 19
 * do_rules:
 *	Spit out the rules for making each file
E 19
I 19
 * Create the makerules for each file
 * which is part of the system.
 * Devices are processed with the special c2 option -i
 * which avoids any problem areas with i/o addressing
 * (e.g. for the VAX); assembler files are processed by as.
E 19
 */
D 19

E 19
do_rules(f)
D 19
FILE *f;
E 19
I 19
	FILE *f;
E 19
{
D 19
    register char *cp, *np, och, *tp;
    register struct file_list *ftp;
E 19
I 19
	register char *cp, *np, och, *tp;
	register struct file_list *ftp;
I 30
	char *extras;
E 30
E 19

D 19
    for (ftp = ftab; ftp != NULL; ftp = ftp->f_next)
    {
E 19
I 19
D 22
for (ftp = ftab; ftp != NULL; ftp = ftp->f_next) {
E 22
I 22
for (ftp = ftab; ftp != 0; ftp = ftp->f_next) {
E 22
E 19
	if (ftp->f_type == INVISIBLE)
D 19
	    continue;
E 19
I 19
		continue;
E 19
	cp = (np = ftp->f_fn) + strlen(ftp->f_fn) - 1;
	och = *cp;
	*cp = '\0';
I 40
	if (och == 'o') {
D 52
		fprintf(f, "%so:\n\t-cp ../%so .\n", tail(np), np);
E 52
I 52
		fprintf(f, "%so:\n\t-cp ../%so .\n\n", tail(np), np);
E 52
		continue;
	}
E 40
	fprintf(f, "%so: ../%s%c\n", tail(np), np, och);
	tp = tail(np);
D 19
	if (och == 's')
	    fprintf(f, "\t${AS} -o %so ../%ss\n\n", tp, np);
	else if (ftp->f_type == NORMAL)
	{
	    fprintf(f, "\t${CC} -I. -c -S ${COPTS} ../%sc\n", np);
D 16
	    fprintf(f, "\t${C2} %ss | sed -f ../sys/asm.sed | ${AS} -o %so\n",
E 16
I 16
	    fprintf(f, "\t${C2} %ss | sed -f ../conf/asm.sed | ${AS} -o %so\n",
E 16
		    tp, tp);
	    fprintf(f, "\trm -f %ss\n\n", tp);
E 19
I 19
	if (och == 's') {
D 34
		fprintf(f, "\t${AS} -o %so ../%ss\n\n", tp, np);
E 34
I 34
		fprintf(f, "\t-ln -s ../%ss %sc\n", np, tp);
D 36
		fprintf(f, "\t${CC} -I. -E ${COPTS} %sc | ${AS} -o %so\n",
E 36
I 36
		fprintf(f, "\t${CC} -E ${COPTS} %sc | ${AS} -o %so\n",
E 36
			tp, tp);
		fprintf(f, "\trm -f %sc\n\n", tp);
E 34
		continue;
E 19
	}
I 30
	if (ftp->f_flags & CONFIGDEP)
		extras = "${PARAM} ";
	else
		extras = "";
E 30
D 19
	else if (ftp->f_type == DEVICE)
	{
	    fprintf(f, "\t${CC} -I. -c -S ${COPTS} ../%sc\n", np);
D 16
	    fprintf(f,"\t${C2} -i %ss | sed -f ../sys/asm.sed | ${AS} -o %so\n",
E 16
I 16
	    fprintf(f,"\t${C2} -i %ss | sed -f ../conf/asm.sed | ${AS} -o %so\n",
E 16
		    tp, tp);
	    fprintf(f, "\trm -f %ss\n\n", tp);
	}
D 18
	else
E 18
I 18
	else if (ftp->f_type == PROFILING) {
E 19
I 19
	switch (ftp->f_type) {

	case NORMAL:
		switch (machine) {

		case MACHINE_VAX:
I 46
		case MACHINE_TAHOE:
E 46
D 30
			fprintf(f, "\t${CC} -I. -c -S ${COPTS} ../%sc\n", np);
E 30
I 30
D 36
			fprintf(f, "\t${CC} -I. -c -S ${COPTS} %s../%sc\n",
E 36
I 36
			fprintf(f, "\t${CC} -c -S ${COPTS} %s../%sc\n",
E 36
				extras, np);
E 30
D 33
			fprintf(f, "\t${C2} %ss | sed -f ../%s/asm.sed |",
E 33
I 33
D 35
			fprintf(f, "\t${C2} %ss | ../%s/asm |",
E 35
I 35
D 42
			fprintf(f, "\t${C2} %ss | ../%s/inline/inline |",
E 35
E 33
			    tp, machinename);
			fprintf(f, " ${AS} -o %so\n", tp);
E 42
I 42
			fprintf(f, "\t${C2} %ss | ${INLINE} | ${AS} -o %so\n",
			    tp, tp);
E 42
			fprintf(f, "\trm -f %ss\n\n", tp);
			break;
D 42

E 42
D 36
		case MACHINE_SUN:
D 30
			fprintf(f, "\t${CC} -I. -c -O ${COPTS} ../%sc\n\n", np);
E 30
I 30
			fprintf(f, "\t${CC} -I. -c -O ${COPTS} %s../%sc\n\n",
				extras, np);
E 30
			break;
E 36
		}
		break;

D 30
	case DEVICE:
E 30
I 30
	case DRIVER:
E 30
		switch (machine) {

		case MACHINE_VAX:
I 46
		case MACHINE_TAHOE:
E 46
D 30
			fprintf(f, "\t${CC} -I. -c -S ${COPTS} ../%sc\n", np);
E 30
I 30
D 36
			fprintf(f, "\t${CC} -I. -c -S ${COPTS} %s../%sc\n",
E 36
I 36
			fprintf(f, "\t${CC} -c -S ${COPTS} %s../%sc\n",
E 36
				extras, np);
E 30
D 33
			fprintf(f,"\t${C2} -i %ss | sed -f ../%s/asm.sed |",
E 33
I 33
D 35
			fprintf(f,"\t${C2} -i %ss | ../%s/asm |",
E 35
I 35
D 42
			fprintf(f,"\t${C2} -i %ss | ../%s/inline/inline |",
E 35
E 33
			    tp, machinename);
			fprintf(f, " ${AS} -o %so\n", tp);
E 42
I 42
			fprintf(f,"\t${C2} -i %ss | ${INLINE} | ${AS} -o %so\n",
			    tp, tp);
E 42
			fprintf(f, "\trm -f %ss\n\n", tp);
			break;
D 42

E 42
D 36
		case MACHINE_SUN:
D 30
			fprintf(f, "\t${CC} -I. -c -O ${COPTS} ../%sc\n\n", np);
E 30
I 30
			fprintf(f, "\t${CC} -I. -c -O ${COPTS} %s../%sc\n\n",
				extras, np);
E 36
E 30
		}
		break;

	case PROFILING:
E 19
		if (!profiling)
			continue;
		if (COPTS == 0) {
			fprintf(stderr,
D 19
				"config: COPTS undefined in generic makefile");
E 19
I 19
			    "config: COPTS undefined in generic makefile");
E 19
			COPTS = "";
		}
D 19
		fprintf(f,
		  "\t${CC} -I. -c -S %s ../%sc\n", COPTS, np);
		fprintf(f, "\tex - %ss < ${CRT0.EX}\n", tp);
		fprintf(f,
E 19
I 19
		switch (machine) {

I 46
		case MACHINE_TAHOE:
			fprintf(f, "\t${CC} -c -S %s %s../%sc\n",
				COPTS, extras, np);
			fprintf(f, "\tex - %ss < ${GPROF.EX}\n", tp);
			fprintf(f,"\t${C2} %ss | ${INLINE} | ${AS} -o %so\n",
			    tp, tp);
			fprintf(f, "\trm -f %ss\n\n", tp);
			break;

E 46
		case MACHINE_VAX:
D 30
			fprintf(f, "\t${CC} -I. -c -S %s ../%sc\n", COPTS, np);
E 30
I 30
D 36
			fprintf(f, "\t${CC} -I. -c -S %s %s../%sc\n",
E 36
I 36
			fprintf(f, "\t${CC} -c -S %s %s../%sc\n",
E 36
				COPTS, extras, np);
E 30
D 25
			fprintf(f, "\tex - %ss < ${CRT0.EX}\n", tp);
E 25
I 25
			fprintf(f, "\tex - %ss < ${GPROF.EX}\n", tp);
E 25
D 33
			fprintf(f,
E 19
D 23
		  "\t/lib/cpp %ss | sed -f ../conf/asm.sed | ${AS} -o %so\n",
E 23
I 23
D 25
		  "\t/lib/cpp %ss | sed -f ../vax/asm.sed | ${AS} -o %so\n",
E 23
D 19
			tp, tp);
		fprintf(f, "\trm -f %ss\n\n", tp);
	} else
E 18
	    fprintf(stderr, "Don't know rules for %s", np);
E 19
I 19
			  tp, tp);
E 25
I 25
			    "\tsed -f ../vax/asm.sed %ss | ${AS} -o %so\n",
			    tp, tp);
E 33
I 33
D 35
			fprintf(f, "\t../%s/asm %ss | ${AS} -o %so\n",
E 35
I 35
D 42
			fprintf(f, "\t../%s/inline/inline %ss | ${AS} -o %so\n",
E 35
			    machinename, tp, tp);
E 42
I 42
			fprintf(f, "\t${INLINE} %ss | ${AS} -o %so\n", tp, tp);
E 42
E 33
E 25
			fprintf(f, "\trm -f %ss\n\n", tp);
			break;
D 42

E 42
D 36
		case MACHINE_SUN:
			fprintf(stderr,
			    "config: don't know how to profile kernel on sun\n");
			break;
E 36
		}
I 23
		break;
E 23

	default:
D 20
		fprintf(stderr, "Don't know rules for %s", np);
E 20
I 20
D 30
		printf("Don't know rules for %s", np);
E 30
I 30
		printf("Don't know rules for %s\n", np);
E 30
E 20
		break;
	}
E 19
	*cp = och;
D 19
    }
E 19
}
I 19
}
E 19

/*
 * Create the load strings
 */
D 19

E 19
do_load(f)
D 19
register FILE *f;
E 19
I 19
	register FILE *f;
E 19
{
D 19
    register struct file_list *fl;
I 8
    register bool first = TRUE;
E 19
I 19
	register struct file_list *fl;
D 21
	bool first = 1;
E 21
I 21
D 48
	int first = 1;
E 48
I 48
	register int first;
E 48
I 28
D 29
	char swapname[32];
E 29
I 29
	struct file_list *do_systemspec();
E 29
E 28
E 21
E 19
E 8

D 6
    fprintf(f, "all:");
E 6
D 19
    for (fl = conf_list; fl != NULL; fl = fl->f_next)
D 6
	fprintf(f, " %s", fl->f_needs);
    putc('\n', f);
    for (fl = conf_list; fl != NULL; fl = fl->f_next)
E 6
    {
D 3
	fprintf(f, "\n%s: makefile locore.o ${OBJS} swap%s.o\n",
E 3
I 3
D 4
	fprintf(f, "\n%s: makefile locore.o ${OBJS} ioconf.o swap%s.o\n",
E 4
I 4
D 6
	fprintf(f, "\n%s: makefile locore.o ${OBJS} ioconf.o param.o swap%s.o\n",
E 6
I 6
D 14
	fprintf(f, "%s: makefile locore.o ${OBJS} ioconf.o param.o swap%s.o\n",
E 14
I 14
D 15
	fprintf(f, "%s: touch makefile locore.o ${OBJS} ioconf.o param.o swap%s.o\n",
E 15
I 15
	fprintf(f, "%s: makefile locore.o ${OBJS} ioconf.o param.o swap%s.o\n",
E 15
E 14
E 6
E 4
E 3
		fl->f_needs, fl->f_fn);
D 10
	fprintf(f, "\t@echo loading %s\n\t@rm -f %s\n\t",
E 10
I 10
	fprintf(f, "\t@echo loading %s\n\t@rm -f %s\n",
E 10
		fl->f_needs, fl->f_needs);
I 8
	if (first)
	{
		first = FALSE;
		fprintf(f, "\t@sh ../conf/newvers.sh\n");
D 10
		fprintf(f, "\t@cc $(COPTS) -c vers.c\n");
E 10
I 10
		fprintf(f, "\t@cc $(CFLAGS) -c vers.c\n");
E 19
I 19
D 22
	for (fl = conf_list; fl != NULL; fl = fl->f_next) {
E 22
I 22
D 29
	for (fl = conf_list; fl != 0; fl = fl->f_next) {
E 22
		fprintf(f, "%s: makefile locore.o ${OBJS} param.o",
		    fl->f_needs);
		fprintf(f, " ioconf.o swap%s.o\n", fl->f_fn);
		fprintf(f, "\t@echo loading %s\n\t@rm -f %s\n",
		    fl->f_needs, fl->f_needs);
		if (first) {
			first = 0;
			fprintf(f, "\t@sh ../conf/newvers.sh\n");
			fprintf(f, "\t@${CC} $(CFLAGS) -c vers.c\n");
E 29
I 29
D 48
	fl = conf_list;
	while (fl) {
		if (fl->f_type != SYSTEMSPEC) {
			fl = fl->f_next;
			continue;
E 29
		}
D 29
		switch (machine) {
E 29
I 29
		fl = do_systemspec(f, fl, first);
		if (first)
			first = 0;
	}
	fprintf(f, "all:");
	for (fl = conf_list; fl != 0; fl = fl->f_next)
E 48
I 48
	for (first = 1, fl = conf_list; fl; first = 0)
		fl = fl->f_type == SYSTEMSPEC ?
			do_systemspec(f, fl, first) : fl->f_next;
	fputs("all:", f);
	for (fl = conf_list; fl; fl = fl->f_next)
E 48
		if (fl->f_type == SYSTEMSPEC)
			fprintf(f, " %s", fl->f_needs);
D 48
	fprintf(f, "\n");
E 48
I 48
	putc('\n', f);
E 48
}
E 29

D 29
		case MACHINE_VAX:
			fprintf(f, "\t@${LD} -n -o %s -e start -x -T 80000000 ",
				fl->f_needs);
			fprintf(f, "locore.o ${OBJS} vers.o ioconf.o param.o ");
			fprintf(f, "swap%s.o\n", fl->f_fn);
			break;
E 29
I 29
struct file_list *
do_systemspec(f, fl, first)
	FILE *f;
	register struct file_list *fl;
	int first;
{
E 29

D 29
		case MACHINE_SUN:
			fprintf(f, "\t@${LD} -o %s -e start -x -T 4000 ",
				fl->f_needs);
			fprintf(f, "locore.o ${OBJS} vers.o ioconf.o param.o ");
			fprintf(f, "swap%s.o\n", fl->f_fn);
			break;
		}
		fprintf(f, "\t@echo rearranging symbols\n");
		fprintf(f, "\t@-symorder ../%s/symbols.sort %s\n",
		    machinename, fl->f_needs);
		fprintf(f, "\t@size %s\n", fl->f_needs);
		fprintf(f, "\t@chmod 755 %s\n\n", fl->f_needs);
E 29
I 29
D 33
	fprintf(f, "%s: makefile locore.o ${OBJS} param.o", fl->f_needs);
	fprintf(f, " ioconf.o swap%s.o\n", fl->f_fn);
E 33
I 33
D 38
	fprintf(f, "%s: makefile", fl->f_needs);
E 38
I 38
D 54
	fprintf(f, "%s: Makefile", fl->f_needs);
E 54
I 54
	fprintf(f, "%s: Makefile ../machine/symbols.sort", fl->f_needs);
E 54
E 38
D 46
	if (machine == MACHINE_VAX)
D 35
		fprintf(f, " ../%s/asm", machinename);
E 35
I 35
D 42
		fprintf(f, " ../%s/inline/inline", machinename);
E 42
I 42
D 44
		fprintf(f, " ${INLINE}", machinename);
E 44
I 44
		fprintf(f, " ${INLINECMD}", machinename);
E 44
E 42
E 35
D 45
	fprintf(f, " locore.o ${OBJS} param.o ioconf.o swap%s.o\n", fl->f_fn);
E 45
I 45
	fprintf(f, " locore.o emulate.o ${OBJS} param.o ioconf.o swap%s.o\n",
	    fl->f_fn);
E 46
I 46
D 51
	if (machine == MACHINE_VAX || machine == MACHINE_TAHOE)
D 47
		fprintf(f, " ${INLINE}", machinename);
E 47
I 47
		fprintf(f, " ${INLINE}");
E 47
	fprintf(f, " locore.o ${OBJS} param.o ioconf.o swap%s.o\n", fl->f_fn);
E 51
I 51
	if (machine == MACHINE_VAX)
D 53
		fprintf(f, " ${INLINE} locore.o emulate.o");
E 53
I 53
D 58
		fprintf(f, " ${INLINECMD} locore.o emulate.o");
E 58
I 58
		fprintf(f, " ${INLINECMD} locore.o");
E 58
E 53
	else if (machine == MACHINE_TAHOE)
		fprintf(f, " ${INLINE} locore.o");
	else
		fprintf(f, " locore.o");
	fprintf(f, " ${OBJS} param.o ioconf.o swap%s.o\n", fl->f_fn);
E 51
E 46
E 45
E 33
	fprintf(f, "\t@echo loading %s\n\t@rm -f %s\n",
	    fl->f_needs, fl->f_needs);
	if (first) {
		fprintf(f, "\t@sh ../conf/newvers.sh\n");
		fprintf(f, "\t@${CC} $(CFLAGS) -c vers.c\n");
E 29
E 19
E 10
	}
E 8
D 19
	fprintf(f,
D 3
	    "@ld -n -o %s -e start -x -T 80000000 locore.o ${OBJS} swap%s.o\n",
E 3
I 3
D 4
	    "@ld -n -o %s -e start -x -T 80000000 locore.o ${OBJS} ioconf.o swap%s.o\n",
E 4
I 4
D 8
	    "@ld -n -o %s -e start -x -T 80000000 locore.o ${OBJS} ioconf.o param.o swap%s.o\n",
E 8
I 8
D 10
	    "@ld -n -o %s -e start -x -T 80000000 locore.o ${OBJS} vers.o ioconf.o param.o swap%s.o\n",
E 10
I 10
	    "\t@ld -n -o %s -e start -x -T 80000000 locore.o ${OBJS} vers.o ioconf.o param.o swap%s.o\n",
E 10
E 8
E 4
E 3
	    fl->f_needs, fl->f_fn);
	fprintf(f, "\t@echo rearranging symbols\n");
D 3
	fprintf(f, "\t@-symorder ../conf/symbols.sort %s\n", fl->f_needs);
E 3
I 3
D 16
	fprintf(f, "\t@-symorder ../sys/symbols.sort %s\n", fl->f_needs);
E 16
I 16
	fprintf(f, "\t@-symorder ../conf/symbols.sort %s\n", fl->f_needs);
E 16
E 3
	fprintf(f, "\t@size %s\n", fl->f_needs);
D 6
	fprintf(f, "\t@chmod 755 %s\n", fl->f_needs);
E 6
I 6
	fprintf(f, "\t@chmod 755 %s\n\n", fl->f_needs);
E 6
    }
    for (fl = conf_list; fl != NULL; fl = fl->f_next)
    {
D 3
	fprintf(f, "\nswap%s.o: ../conf/swap%s.c\n", fl->f_fn, fl->f_fn);
	fprintf(f, "\t${CC} -I. -c -S ${COPTS} ../conf/swap%s.c\n", fl->f_fn);
E 3
I 3
D 6
	fprintf(f, "\nswap%s.o: ../dev/swap%s.c\n", fl->f_fn, fl->f_fn);
E 6
I 6
	fprintf(f, "swap%s.o: ../dev/swap%s.c\n", fl->f_fn, fl->f_fn);
E 6
	fprintf(f, "\t${CC} -I. -c -S ${COPTS} ../dev/swap%s.c\n", fl->f_fn);
E 3
	fprintf(f,
D 16
	    "\t${C2} swap%s.s | sed -f ../sys/asm.sed | ${AS} -o swap%s.o\n",
E 16
I 16
	    "\t${C2} swap%s.s | sed -f ../conf/asm.sed | ${AS} -o swap%s.o\n",
E 16
	    fl->f_fn, fl->f_fn);
D 6
	fprintf(f, "\trm -f swap%s.s\n", fl->f_fn);
E 6
I 6
	fprintf(f, "\trm -f swap%s.s\n\n", fl->f_fn);
E 6
    }
I 6
    fprintf(f, "all:");
    for (fl = conf_list; fl != NULL; fl = fl->f_next)
	fprintf(f, " %s", fl->f_needs);
    putc('\n', f);
E 19
I 19
D 22
	for (fl = conf_list; fl != NULL; fl = fl->f_next) {
E 22
I 22
D 29
	for (fl = conf_list; fl != 0; fl = fl->f_next) {
I 28
		(void) sprintf(swapname, "swap%s.c", fl->f_fn);
		if (fltail_lookup(swapname) != 0)
			continue;
E 28
E 22
		fprintf(f, "swap%s.o: ../%s/swap%s.c\n",
		    fl->f_fn, machinename, fl->f_fn);
		switch (machine) {
E 29
I 29
	switch (machine) {
E 29

D 29
		case MACHINE_VAX:
			fprintf(f, "\t${CC} -I. -c -S ${COPTS}");
			fprintf(f, " ../%s/swap%s.c\n", machinename, fl->f_fn);
			fprintf(f, "\t${C2} swap%s.s | sed -f ../%s/asm.sed",
			    fl->f_fn, machinename);
			fprintf(f, " | ${AS} -o swap%s.o\n",
			    fl->f_fn);
			fprintf(f, "\trm -f swap%s.s\n\n", fl->f_fn);
			break;
E 29
I 29
	case MACHINE_VAX:
		fprintf(f, "\t@${LD} -n -o %s -e start -x -T 80000000 ",
			fl->f_needs);
I 46
D 58
		fprintf(f,
		    "locore.o emulate.o ${OBJS} vers.o ioconf.o param.o ");
E 58
I 58
		fprintf(f, "locore.o ${OBJS} vers.o ioconf.o param.o ");
E 58
E 46
		break;
I 46

	case MACHINE_TAHOE:
		fprintf(f, "\t@${LD} -n -o %s -e start -x -T C0000800 ",
			fl->f_needs);
		fprintf(f, "locore.o ${OBJS} vers.o ioconf.o param.o ");
		break;
E 46
E 29
D 42

E 42
D 29
		case MACHINE_SUN:
			fprintf(f, "\t${CC} -I. -c -O ${COPTS} ");
			fprintf(f, "../%s/swap%s.c\n\n", machinename, fl->f_fn);
			break;
		}
E 29
I 29
D 36
	case MACHINE_SUN:
		fprintf(f, "\t@${LD} -o %s -e start -x -T 4000 ",
			fl->f_needs);
		break;
E 36
E 29
	}
D 29
	fprintf(f, "all:");
D 22
	for (fl = conf_list; fl != NULL; fl = fl->f_next)
E 22
I 22
	for (fl = conf_list; fl != 0; fl = fl->f_next)
E 22
		fprintf(f, " %s", fl->f_needs);
	fprintf(f, "\n");
E 29
I 29
D 45
	fprintf(f, "locore.o ${OBJS} vers.o ioconf.o param.o ");
E 45
I 45
D 46
	fprintf(f, "locore.o emulate.o ${OBJS} vers.o ioconf.o param.o ");
E 46
E 45
	fprintf(f, "swap%s.o\n", fl->f_fn);
	fprintf(f, "\t@echo rearranging symbols\n");
	fprintf(f, "\t@-symorder ../%s/symbols.sort %s\n",
	    machinename, fl->f_needs);
	fprintf(f, "\t@size %s\n", fl->f_needs);
	fprintf(f, "\t@chmod 755 %s\n\n", fl->f_needs);
	do_swapspec(f, fl->f_fn);
	for (fl = fl->f_next; fl->f_type == SWAPSPEC; fl = fl->f_next)
		;
	return (fl);
}

do_swapspec(f, name)
	FILE *f;
	register char *name;
{

	if (!eq(name, "generic")) {
		fprintf(f, "swap%s.o: swap%s.c\n", name, name);
D 36
		fprintf(f, "\t${CC} -I. -c -O ${COPTS} swap%s.c\n\n", name);
E 36
I 36
		fprintf(f, "\t${CC} -c -O ${COPTS} swap%s.c\n\n", name);
E 36
		return;
	}
	fprintf(f, "swapgeneric.o: ../%s/swapgeneric.c\n", machinename);
	switch (machine) {

	case MACHINE_VAX:
I 46
	case MACHINE_TAHOE:
E 46
D 36
		fprintf(f, "\t${CC} -I. -c -S ${COPTS} ");
E 36
I 36
		fprintf(f, "\t${CC} -c -S ${COPTS} ");
E 36
		fprintf(f, "../%s/swapgeneric.c\n", machinename);
D 33
		fprintf(f, "\t${C2} swapgeneric.s | sed -f ../%s/asm.sed",
		    machinename);
E 33
I 33
D 35
		fprintf(f, "\t${C2} swapgeneric.s | ../%s/asm", machinename);
E 35
I 35
D 42
		fprintf(f, "\t${C2} swapgeneric.s | ");
		fprintf(f, "../%s/inline/inline", machinename);
E 42
I 42
		fprintf(f, "\t${C2} swapgeneric.s | ${INLINE}");
E 42
E 35
E 33
		fprintf(f, " | ${AS} -o swapgeneric.o\n");
		fprintf(f, "\trm -f swapgeneric.s\n\n");
		break;
D 42

E 42
D 36
	case MACHINE_SUN:
		fprintf(f, "\t${CC} -I. -c -O ${COPTS} ");
		fprintf(f, "../%s/swapgeneric.c\n\n", machinename);
		break;
E 36
	}
E 29
E 19
E 6
I 2
}

I 22
char *
E 22
raise(str)
D 19
register char *str;
E 19
I 19
	register char *str;
E 19
{
D 19
    register char *cp = str;
E 19
I 19
	register char *cp = str;
E 19

D 19
    while(*str)
    {
	if (islower(*str))
	    *str = toupper(*str);
	str++;
    }
    return cp;
E 19
I 19
	while (*str) {
		if (islower(*str))
			*str = toupper(*str);
		str++;
	}
	return (cp);
E 19
E 2
}
E 1
