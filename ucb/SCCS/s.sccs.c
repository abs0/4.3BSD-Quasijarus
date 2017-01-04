h33940
s 00002/00001/01603
d D 5.9 01/05/27 20:52:38 msokolov 86 85
c help => sccshelp
c add nprt ("nice prt") macro for prt -n -a -i
e
s 00001/00000/01603
d D 5.8 99/09/07 12:26:57 msokolov 85 84
c add bump command to bump SCCS files (get -e/delta)
e
s 00001/00001/01602
d D 5.7 99/01/07 21:40:10 msokolov 84 83
c SCCS is not "local" any more. /usr/local => /usr/bin
e
s 00010/00005/01593
d D 5.6 88/06/29 21:51:02 bostic 83 82
c install approved copyright notice
e
s 00010/00004/01588
d D 5.5 88/05/05 18:16:25 bostic 82 81
c written by Eric Allman; add Berkeley header
e
s 00001/00002/01591
d D 5.4 88/01/03 01:11:10 bostic 81 80
c fix external declarations for ANSI C
e
s 00043/00007/01550
d D 5.3 87/04/26 13:57:12 bostic 80 79
c bug report 4.2BSD/ucb/83
e
s 00005/00005/01552
d D 5.2 87/02/12 11:43:46 mckusick 79 78
c must change name of `dirfd' as it has become a macro
e
s 00013/00001/01544
d D 5.1 85/05/31 09:32:21 dist 78 77
c Add copyright
e
s 00005/00002/01540
d D 1.71 83/07/02 01:00:28 sam 77 76
c include fixes
e
s 00034/00003/01508
d D 1.70 83/04/30 17:50:26 sam 76 75
c make unedit an "atomic" operation to avoid dregs
e
s 00001/00001/01510
d D 1.69 83/01/13 18:22:38 eric 75 74
c change PROJECT environment variable to PROJECTDIR
e
s 00078/00029/01433
d D 1.68 83/01/03 18:03:38 rrh 74 73
c Guarded strcat,  strcpy and strncat; complain (but do nothing)
c if one does string manipulation out of the buffer.  Paramaterize the
c size of all character buffers, which was bumped from 100 to BUFSIZ.
e
s 00004/00003/01458
d D 1.67 83/01/03 17:24:07 rrh 73 72
c create is now called enter; new "create" first calls enter, then
c gets the file out; this is effectively an "admin -ifoo foo", "mv foo ,foo",
c "get foo"
e
s 00003/00002/01458
d D 1.66 83/01/03 16:07:37 rrh 72 71
c fix bug with "sccs clean"; it no longer removes files checked out
e
s 00000/00000/01460
d D 1.65 82/05/11 22:50:41 mckusick 71 68
i 70 69
c update to new fs
e
s 00011/00033/01415
d D 1.61.1.2 82/05/11 22:45:23 mckusick 70 69
c merge in updates to new fs
e
s 00000/00000/01448
d D 1.61.1.1 82/05/11 22:32:15 mckusick 69 65
c branch-place-holder
e
s 00001/00000/01481
d D 1.64 81/05/27 00:33:05 eric 68 67
c print names in create
e
s 00029/00001/01452
d D 1.63 81/05/27 00:22:11 eric 67 66
c add ``create'' command
e
s 00006/00001/01447
d D 1.62 81/04/13 20:44:52 eric 66 65
c know about USER environment
e
s 00004/00000/01444
d D 1.61 81/02/05 18:29:14 eric 65 64
c allow space in -d and -p
e
s 00002/00000/01442
d D 1.60 81/01/25 11:45:17 eric 64 63
c add "branch" command
e
s 00030/00008/01412
d D 1.59 81/01/15 13:00:37 eric 63 62
c fixed botch in getpfent when -i/-x flags are used
e
s 00052/00016/01368
d D 1.58 81/01/14 22:53:46 eric 62 61
c put in PROJECT magic
e
s 00014/00000/01370
d D 1.57 81/01/14 22:22:21 eric 61 60
c add frotz for PROJECT environment
e
s 00001/00001/01369
d D 1.56 81/01/14 22:11:20 eric 60 59
c sped up deledit by using delta -n, get -g
e
s 00001/00000/01369
d D 1.55 81/01/14 22:08:32 eric 59 58
c added "print" command
e
s 00002/00000/01367
d D 1.54 81/01/14 15:50:10 eric 58 57
c added "prs" and "val" to the tables
e
s 00002/00000/01365
d D 1.53 80/12/17 10:59:17 eric 57 55
c fix type botch in username
e
s 00034/00001/01364
d D 1.52.1.1 80/12/06 19:25:16 eric 56 55
c experimental "diffs" to give sh script
e
s 00026/00008/01339
d D 1.52 80/12/05 12:37:22 eric 55 54
c allow parameters to "diff"
e
s 00001/00003/01346
d D 1.51 80/12/05 11:10:13 eric 54 53
c fix bug in clean (only removed files BEING edited!!)
e
s 00004/00000/01345
d D 1.50 80/12/02 11:00:14 eric 53 52
c add PROGPATH for Cory
e
s 00086/00040/01259
d D 1.49 80/12/02 09:57:53 eric 52 51
c add -u[user] option to info/check/tell (not clean!)
e
s 00079/00016/01220
d D 1.48 80/11/20 11:14:03 eric 51 50
c add '-b' flag to info, tell, clean, & check
e
s 00004/00004/01232
d D 1.47 80/11/20 10:06:56 eric 50 49
c fix bug in flag exclusion
e
s 00006/00007/01230
d D 1.46 80/11/05 10:51:54 eric 49 48
c sneak (somewhat) through lint
e
s 00041/00035/01196
d D 1.45 80/11/05 10:34:05 eric 48 47
c change way of doing keyletter supression to be more flexible
e
s 00009/00002/01222
d D 1.44 80/11/02 15:21:07 eric 47 46
c added "tell" command
e
s 00004/00000/01220
d D 1.43 80/10/25 21:37:45 eric 46 44
c look for binaries in correct place on IngVax
e
s 00008/00001/01219
d R 1.43 80/10/25 21:35:29 eric 45 44
c look in correct place for binaries on IngVax
e
s 00001/00001/01219
d D 1.42 80/10/17 22:49:54 eric 44 43
c fixed "fix" so -r would be passed to rmdel
e
s 00003/00003/01217
d D 1.41 80/10/17 11:25:02 eric 43 42
c fixed bug in diffs where it got ever more files
e
s 00002/00000/01218
d D 1.40 80/10/17 11:14:11 eric 42 41
c print g-file name on diffs command
e
s 00049/00008/01169
d D 1.39 80/10/15 03:22:24 eric 41 40
c cleanup & add comments
e
s 00015/00002/01162
d D 1.38 80/10/15 02:53:54 eric 40 39
c made all major configuration possible from -D flags
e
s 00030/00003/01134
d D 1.37 80/10/15 02:38:09 eric 39 38
c put in tail() stuff
e
s 00112/00008/01025
d D 1.36 80/10/15 01:57:49 eric 38 37
c Added "diffs" command
e
s 00040/00019/00993
d D 1.35 80/10/15 00:34:19 eric 37 36
c clean up ^L's for prettiness
e
s 00023/00015/00989
d D 1.34 80/10/15 00:22:04 eric 36 35
c allowed shell files; added sccsdiff command
e
s 00002/00002/01002
d D 1.33 80/10/09 22:25:18 eric 35 34
c added -l flag capability to get & edit
e
s 00104/00113/00900
d D 1.32 80/10/09 22:05:51 eric 34 33
c pass flags selectively to things like "delget"
e
s 00002/00002/01011
d D 1.31 80/10/09 11:10:09 eric 33 32
c added -t flag as default to delget & deledit
e
s 00085/00018/00928
d D 1.30 80/10/09 11:06:33 eric 32 31
c check exit codes in macros, fix, etc.
e
s 00020/00013/00926
d D 1.29 80/10/08 10:36:33 eric 31 30
c cleanup; add SCCSPATH; add copyright notice
e
s 00010/00003/00929
d D 1.28 80/10/03 21:34:00 eric 30 29
c make -d work for clean/info/check etc.
e
s 00080/00017/00852
d D 1.27 80/10/03 11:48:12 eric 29 28
c cleaned up some to facilitate future expansion
e
s 00097/00002/00772
d D 1.26 80/09/02 09:02:59 eric 28 27
c fixed determination of user on CSVAX-type machines;
c added leading comment block; removed "del" & "delt"
e
s 00020/00010/00754
d D 1.25 80/08/30 18:07:18 eric 27 26
c added "check" command
e
s 00047/00028/00717
d D 1.24 80/08/09 19:29:23 eric 26 24
c add -d -- makefile finally works
e
s 00039/00025/00720
d D 1.23.1.1 80/08/09 16:57:15 eric 25 24
c another try at makefile()
e
s 00122/00023/00623
d D 1.23 80/08/09 14:43:05 eric 24 23
c improved pathname creation
e
s 00020/00007/00626
d D 1.22 80/08/09 12:36:42 eric 23 22
c cleaned up get on unedit
e
s 00001/00000/00632
d D 1.21 80/08/09 12:25:33 eric 22 21
c have "unedit" do a get of the removed files
e
s 00005/00005/00627
d D 1.20 80/08/02 12:28:07 eric 21 20
c changed strcpyn->strncpy, strcmpn->strncmp
e
s 00005/00005/00627
d D 1.19 80/07/28 10:28:11 eric 20 19
c fix spelling error: editted => edited
e
s 00001/00001/00631
d D 1.18 80/07/25 18:41:39 eric 19 18
c changed "deled" to "deledit" for wnj
e
s 00190/00002/00442
d D 1.17 80/07/24 13:23:51 eric 18 17
c added "unedit" option
e
s 00008/00003/00436
d D 1.16 80/07/24 10:03:34 eric 17 16
c expanded "info" option
e
s 00043/00006/00396
d D 1.15 80/07/24 09:51:44 eric 16 15
c added "delget", "edit", "deled", and flag option to CMACRO
e
s 00005/00000/00397
d D 1.14 80/07/07 14:26:05 eric 15 14
c cleaned up "info" option slightly
e
s 00021/00010/00376
d D 1.13 80/07/04 15:37:57 eric 14 12
c added "info" command
e
s 00017/00007/00379
d R 1.13 80/07/04 15:32:55 eric 13 12
c added "edinfo" command
e
s 00050/00022/00336
d D 1.12 80/06/09 23:05:41 eric 12 11
c arranged so that links such as "get" and "prt" will work
e
s 00065/00003/00293
d D 1.11 80/06/09 22:40:32 eric 11 10
c added "clean" entry
e
s 00050/00024/00246
d D 1.10 80/06/04 16:34:19 eric 10 9
c added "fix" command
e
s 00018/00009/00252
d D 1.9 80/05/23 12:31:38 eric 9 8
c made pathnames for sccs programs more flexible (for csvax)
e
s 00025/00005/00236
d D 1.8 80/05/22 20:53:30 eric 8 7
c added "del" macro
e
s 00094/00035/00147
d D 1.7 80/05/22 20:24:38 eric 7 6
c cleanup to allow macros, etc. (no functional changes)
e
s 00002/00034/00180
d D 1.6 80/05/19 19:12:04 eric 6 5
c remove ADMINFILE kludge
e
s 00007/00000/00207
d D 1.5 80/05/13 11:32:24 eric 5 4
c defaulted no ADMINFILE to mean everyone
e
s 00053/00005/00154
d D 1.4 80/05/13 11:18:42 eric 4 3
c Added 'admin' protection & ADMINFILE stuff
e
s 00002/00000/00157
d D 1.3 80/05/13 00:27:33 eric 3 2
c added SccsId
e
s 00009/00015/00148
d D 1.2 80/05/13 00:23:29 eric 2 1
c changed path to SCCS/s.
c added chghist & help
c generalized argument chomping
e
s 00163/00000/00000
d D 1.1 80/05/10 15:43:23 eric 1 0
e
u
U
f i 
t
T
I 78
/*
 * Copyright (c) 1980 Regents of the University of California.
D 82
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 82
I 82
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 83
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 83
I 83
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
E 83
E 82
 */

E 78
I 77
#ifndef lint
I 78
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
D 82
#endif not lint
E 82
I 82
#endif /* not lint */
E 82

#ifndef lint
E 78
static char sccsid[] = "%W% (Berkeley) %G%";
D 78
#endif
E 78
I 78
D 82
#endif not lint
E 82
I 82
#endif /* not lint */
E 82
E 78

E 77
I 1
# include <stdio.h>
D 70
# include <sys/types.h>
E 70
I 70
# include <sys/param.h>
E 70
# include <sys/stat.h>
I 11
D 70
# include <sys/dir.h>
E 70
I 70
D 77
# include <dir.h>
E 77
I 77
# include <sys/dir.h>
E 77
E 70
I 38
# include <errno.h>
# include <signal.h>
E 38
E 11
# include <sysexits.h>
I 9
D 70
# include <whoami.h>
E 70
I 62
# include <pwd.h>
E 62
E 9

I 28
/*
**  SCCS.C -- human-oriented front end to the SCCS system.
**
**	Without trying to add any functionality to speak of, this
**	program tries to make SCCS a little more accessible to human
**	types.  The main thing it does is automatically put the
**	string "SCCS/s." on the front of names.  Also, it has a
**	couple of things that are designed to shorten frequent
**	combinations, e.g., "delget" which expands to a "delta"
**	and a "get".
**
**	This program can also function as a setuid front end.
**	To do this, you should copy the source, renaming it to
**	whatever you want, e.g., "syssccs".  Change any defaults
**	in the program (e.g., syssccs might default -d to
**	"/usr/src/sys").  Then recompile and put the result
**	as setuid to whomever you want.  In this mode, sccs
**	knows to not run setuid for certain programs in order
**	to preserve security, and so forth.
**
**	Usage:
**		sccs [flags] command [args]
**
**	Flags:
**		-d<dir>		<dir> represents a directory to search
**				out of.  It should be a full pathname
**				for general usage.  E.g., if <dir> is
**				"/usr/src/sys", then a reference to the
**				file "dev/bio.c" becomes a reference to
**				"/usr/src/sys/dev/bio.c".
**		-p<path>	prepends <path> to the final component
**				of the pathname.  By default, this is
**				"SCCS".  For example, in the -d example
**				above, the path then gets modified to
**				"/usr/src/sys/dev/SCCS/s.bio.c".  In
**				more common usage (without the -d flag),
**				"prog.c" would get modified to
**				"SCCS/s.prog.c".  In both cases, the
**				"s." gets automatically prepended.
**		-r		run as the real user.
**
**	Commands:
**		admin,
**		get,
**		delta,
**		rmdel,
D 80
**		chghist,
E 80
I 80
**		cdc,
E 80
**		etc.		Straight out of SCCS; only difference
**				is that pathnames get modified as
**				described above.
I 80
**		enter		Front end doing "sccs admin -i<name> <name>"
**		create		Macro for "enter" followed by "get".
E 80
**		edit		Macro for "get -e".
**		unedit		Removes a file being edited, knowing
**				about p-files, etc.
**		delget		Macro for "delta" followed by "get".
**		deledit		Macro for "delta" followed by "get -e".
D 80
**		info		Tell what files being edited.
E 80
I 80
**		branch		Macro for "get -b -e", followed by "delta
**				-s -n", followd by "get -e -t -g".
**		diffs		"diff" the specified version of files
**				and the checked-out version.
**		print		Macro for "prs -e" followed by "get -p -m".
**		tell		List what files are being edited.
**		info		Print information about files being edited.
E 80
**		clean		Remove all files that can be
**				regenerated from SCCS files.
D 29
**		status		Like info, but return exit status, for
E 29
I 29
**		check		Like info, but return exit status, for
E 29
**				use in makefiles.
**		fix		Remove a top delta & reedit, but save
**				the previous changes in that delta.
**
**	Compilation Flags:
**		UIDUSER -- determine who the user is by looking at the
**			uid rather than the login name -- for machines
**			where SCCS gets the user in this way.
I 29
D 31
**		SRCDIR -- if defined, forces the -d flag to take on
E 31
I 31
**		SCCSDIR -- if defined, forces the -d flag to take on
E 31
**			this value.  This is so that the setuid
**			aspects of this program cannot be abused.
I 31
**			This flag also disables the -p flag.
**		SCCSPATH -- the default for the -p flag.
I 40
**		MYNAME -- the title this program should print when it
**			gives error messages.
E 40
E 31
E 29
**
**	Compilation Instructions:
**		cc -O -n -s sccs.c
I 40
**		The flags listed above can be -D defined to simplify
**			recompilation for variant versions.
E 40
**
**	Author:
**		Eric Allman, UCB/INGRES
I 31
**		Copyright 1980 Regents of the University of California
E 31
*/

I 37
D 77
static char SccsId[] = "%W% %G%";
E 77

E 37
I 31
/*******************  Configuration Information  ********************/

I 40
D 70
/* special defines for local berkeley systems */
# include <whoami.h>

E 40
E 31
# ifdef CSVAX
# define UIDUSER
D 31
# endif
E 31
I 31
# define PROGPATH(name)	"/usr/local/name"
# endif CSVAX
E 31

I 46
# ifdef INGVAX
# define PROGPATH(name)	"/usr/local/name"
# endif INGVAX

I 53
# ifdef CORY
# define PROGPATH(name)	"/usr/eecs/bin/name"
# endif CORY

E 53
E 46
I 40
/* end of berkeley systems defines */

E 70
# ifndef SCCSPATH
E 40
I 31
D 37
# define SCCSPATH	"SCCS"
E 37
I 37
# define SCCSPATH	"SCCS"	/* pathname in which to find s-files */
E 37
D 40
/* put #define SCCSDIR here */
E 40
I 40
# endif NOT SCCSPATH
E 40

D 40
char	MyName[] = "sccs";	/* name used in messages */
E 40
I 40
# ifndef MYNAME
# define MYNAME		"sccs"	/* name used for printing errors */
# endif NOT MYNAME
E 40

D 37
/****************  End of Configuration Information  ****************/
E 37
I 37
# ifndef PROGPATH
D 70
# define PROGPATH(name)	"/usr/sccs/name"	/* place to find binaries */
E 70
I 70
D 84
# define PROGPATH(name)	"/usr/local/name"	/* place to find binaries */
E 84
I 84
# define PROGPATH(name)	"/usr/bin/name"	/* place to find binaries */
E 84
E 70
# endif PROGPATH
E 37

E 31
E 28
I 3
D 11
static char SccsId[] = "%Z%%M% %I% delta %G% %U% get %H% %T%";
E 11
I 11
D 37
static char SccsId[] = "%W% %G%";
E 11

E 37
I 37
/****************  End of Configuration Information  ****************/

E 37
I 4
D 41
# define bitset(bit, word)	((bit) & (word))

E 41
typedef char	bool;
I 7
# define TRUE	1
# define FALSE	0
E 7

I 41
# define bitset(bit, word)	((bool) ((bit) & (word)))

E 41
I 28
D 62
# ifdef UIDUSER
# include <pwd.h>
# endif UIDUSER

E 62
I 29
D 31
char	MyName[] = "sccs";

E 31
E 29
E 28
E 4
E 3
struct sccsprog
{
	char	*sccsname;	/* name of SCCS routine */
D 7
	short	sccsflags;	/* see below */
E 7
I 7
	short	sccsoper;	/* opcode, see below */
	short	sccsflags;	/* flags, see below */
I 34
D 48
	char	*sccsklets;	/* valid key-letters on macros */
E 48
E 34
E 7
	char	*sccspath;	/* pathname of binary implementing */
};

I 7
/* values for sccsoper */
# define PROG		0	/* call a program */
I 8
# define CMACRO		1	/* command substitution macro */
I 10
# define FIX		2	/* fix a delta */
I 11
# define CLEAN		3	/* clean out recreatable files */
I 18
# define UNEDIT		4	/* unedit a file */
I 36
# define SHELL		5	/* call a shell file (like PROG) */
I 38
# define DIFFS		6	/* diff between sccs & file out */
I 55
# define DODIFF		7	/* internal call to diff program */
I 67
D 73
# define CREATE		8	/* create new files */
E 73
I 73
# define ENTER		8	/* enter new files */
E 73
E 67
E 55
E 38
E 36
E 18
E 11
E 10
E 8

E 7
D 4
/* bits for sccspath */
E 4
I 4
/* bits for sccsflags */
E 4
D 7
# define F_NOSDOT	0001	/* no s. on front of args */
I 4
# define F_PROT		0002	/* protected (e.g., admin) */
E 7
I 7
# define NO_SDOT	0001	/* no s. on front of args */
# define REALUSER	0002	/* protected (e.g., admin) */
E 7
E 4

I 27
/* modes for the "clean", "info", "check" ops */
# define CLEANC		0	/* clean command */
# define INFOC		1	/* info command */
# define CHECKC		2	/* check command */
I 47
# define TELLC		3	/* give list of files being edited */
E 47

E 27
I 9
D 31
# ifdef CSVAX
# define PROGPATH(name)	"/usr/local/name"
# endif CSVAX

E 31
D 37
# ifndef PROGPATH
# define PROGPATH(name)	"/usr/sccs/name"
# endif PROGPATH
E 37
I 37
/*
**  Description of commands known to this program.
**	First argument puts the command into a class.  Second arg is
**	info regarding treatment of this command.  Third arg is a
**	list of flags this command accepts from macros, etc.  Fourth
**	arg is the pathname of the implementing program, or the
**	macro definition, or the arg to a sub-algorithm.
*/
E 37

E 9
struct sccsprog SccsProg[] =
{
D 4
	"admin",	0,			"/usr/sccs/admin",
E 4
I 4
D 7
	"admin",	F_PROT,			"/usr/sccs/admin",
E 4
I 2
	"chghist",	0,			"/usr/sccs/rmdel",
E 2
	"comb",		0,			"/usr/sccs/comb",
	"delta",	0,			"/usr/sccs/delta",
	"get",		0,			"/usr/sccs/get",
I 2
	"help",		F_NOSDOT,		"/usr/sccs/help",
E 2
	"prt",		0,			"/usr/sccs/prt",
D 4
	"rmdel",	0,			"/usr/sccs/rmdel",
E 4
I 4
	"rmdel",	F_PROT,			"/usr/sccs/rmdel",
E 4
	"what",		F_NOSDOT,		"/usr/sccs/what",
	NULL,		0,			NULL
E 7
I 7
D 9
	"admin",	PROG,	REALUSER,		"/usr/sccs/admin",
	"chghist",	PROG,	0,			"/usr/sccs/rmdel",
	"comb",		PROG,	0,			"/usr/sccs/comb",
	"delta",	PROG,	0,			"/usr/sccs/delta",
	"get",		PROG,	0,			"/usr/sccs/get",
	"help",		PROG,	NO_SDOT,		"/usr/sccs/help",
	"prt",		PROG,	0,			"/usr/sccs/prt",
	"rmdel",	PROG,	REALUSER,		"/usr/sccs/rmdel",
	"what",		PROG,	NO_SDOT,		"/usr/sccs/what",
E 9
I 9
D 34
	"admin",	PROG,	REALUSER,		PROGPATH(admin),
	"chghist",	PROG,	0,			PROGPATH(rmdel),
	"comb",		PROG,	0,			PROGPATH(comb),
	"delta",	PROG,	0,			PROGPATH(delta),
	"get",		PROG,	0,			PROGPATH(get),
	"help",		PROG,	NO_SDOT,		PROGPATH(help),
	"prt",		PROG,	0,			PROGPATH(prt),
	"rmdel",	PROG,	REALUSER,		PROGPATH(rmdel),
	"what",		PROG,	NO_SDOT,		PROGPATH(what),
I 16
	"edit",		CMACRO,	0,			"get -e",
D 33
	"delget",	CMACRO,	0,			"delta/get",
D 19
	"deled",	CMACRO,	0,			"delta/get -e",
E 19
I 19
	"deledit",	CMACRO,	0,			"delta/get -e",
E 33
I 33
	"delget",	CMACRO,	0,			"delta/get -t",
	"deledit",	CMACRO,	0,			"delta/get -e -t",
E 33
E 19
E 16
E 9
I 8
D 28
	"del",		CMACRO,	0,			"delta/get",
I 10
	"delt",		CMACRO,	0,			"delta/get",
E 28
	"fix",		FIX,	0,			NULL,
I 11
D 14
	"clean",	CLEAN,	REALUSER,		NULL,
E 14
I 14
D 27
	"clean",	CLEAN,	REALUSER,		(char *) TRUE,
	"info",		CLEAN,	REALUSER,		(char *) FALSE,
E 27
I 27
	"clean",	CLEAN,	REALUSER,		(char *) CLEANC,
	"info",		CLEAN,	REALUSER,		(char *) INFOC,
	"check",	CLEAN,	REALUSER,		(char *) CHECKC,
E 27
I 18
	"unedit",	UNEDIT,	0,			NULL,
E 18
E 14
E 11
E 10
E 8
	NULL,		-1,	0,			NULL
E 34
I 34
D 48
	"admin",	PROG,	REALUSER,	"",		PROGPATH(admin),
	"chghist",	PROG,	0,		"",		PROGPATH(rmdel),
	"comb",		PROG,	0,		"",		PROGPATH(comb),
	"delta",	PROG,	0,		"mysrp",	PROGPATH(delta),
D 35
	"get",		PROG,	0,		"ixbeskc",	PROGPATH(get),
E 35
I 35
	"get",		PROG,	0,		"ixbeskcl",	PROGPATH(get),
E 35
	"help",		PROG,	NO_SDOT,	"",		PROGPATH(help),
	"prt",		PROG,	0,		"",		PROGPATH(prt),
D 44
	"rmdel",	PROG,	REALUSER,	"",		PROGPATH(rmdel),
E 44
I 44
	"rmdel",	PROG,	REALUSER,	"r",		PROGPATH(rmdel),
E 44
	"what",		PROG,	NO_SDOT,	"",		PROGPATH(what),
I 36
	"sccsdiff",	SHELL,	REALUSER,	"",		PROGPATH(sccsdiff),
E 36
D 35
	"edit",		CMACRO,	NO_SDOT,	"ixbsc",	"get -e",
E 35
I 35
	"edit",		CMACRO,	NO_SDOT,	"ixbscl",	"get -e",
E 35
	"delget",	CMACRO,	NO_SDOT,	"",		"delta/get -t",
	"deledit",	CMACRO,	NO_SDOT,	"",		"delta/get -e -t",
	"fix",		FIX,	NO_SDOT,	"",		NULL,
	"clean",	CLEAN,	REALUSER,	"",		(char *) CLEANC,
	"info",		CLEAN,	REALUSER,	"",		(char *) INFOC,
	"check",	CLEAN,	REALUSER,	"",		(char *) CHECKC,
I 47
	"tell",		CLEAN,	REALUSER,	"",		(char *) TELLC,
E 47
	"unedit",	UNEDIT,	NO_SDOT,	"",		NULL,
I 38
	"diffs",	DIFFS,	NO_SDOT|REALUSER, "",		NULL,
E 38
	NULL,		-1,	0,		"",		NULL
E 48
I 48
D 52
	"admin",	PROG,	REALUSER,	PROGPATH(admin),
	"chghist",	PROG,	0,		PROGPATH(rmdel),
	"comb",		PROG,	0,		PROGPATH(comb),
	"delta",	PROG,	0,		PROGPATH(delta),
	"get",		PROG,	0,		PROGPATH(get),
	"help",		PROG,	NO_SDOT,	PROGPATH(help),
	"prt",		PROG,	0,		PROGPATH(prt),
	"rmdel",	PROG,	REALUSER,	PROGPATH(rmdel),
	"what",		PROG,	NO_SDOT,	PROGPATH(what),
	"sccsdiff",	SHELL,	REALUSER,	PROGPATH(sccsdiff),
	"edit",		CMACRO,	NO_SDOT,	"get -e",
D 50
	"delget",	CMACRO,	NO_SDOT,	"delta:mysrp/get:ixbeskecl -t",
	"deledit",	CMACRO,	NO_SDOT,	"delta:mysrp/get:ixbeskecl -e -t",
E 50
I 50
	"delget",	CMACRO,	NO_SDOT,	"delta:mysrp/get:ixbeskcl -t",
	"deledit",	CMACRO,	NO_SDOT,	"delta:mysrp/get:ixbskcl -e -t",
E 50
	"fix",		FIX,	NO_SDOT,	NULL,
	"clean",	CLEAN,	REALUSER,	(char *) CLEANC,
	"info",		CLEAN,	REALUSER,	(char *) INFOC,
	"check",	CLEAN,	REALUSER,	(char *) CHECKC,
	"tell",		CLEAN,	REALUSER,	(char *) TELLC,
	"unedit",	UNEDIT,	NO_SDOT,	NULL,
	"diffs",	DIFFS,	NO_SDOT|REALUSER, NULL,
	NULL,		-1,	0,		NULL
E 52
I 52
	"admin",	PROG,	REALUSER,		PROGPATH(admin),
D 80
	"chghist",	PROG,	0,			PROGPATH(rmdel),
E 80
I 80
	"cdc",		PROG,	0,			PROGPATH(rmdel),
E 80
	"comb",		PROG,	0,			PROGPATH(comb),
	"delta",	PROG,	0,			PROGPATH(delta),
	"get",		PROG,	0,			PROGPATH(get),
D 86
	"help",		PROG,	NO_SDOT,		PROGPATH(help),
E 86
I 86
	"help",		PROG,	NO_SDOT,		PROGPATH(sccshelp),
E 86
I 58
	"prs",		PROG,	0,			PROGPATH(prs),
E 58
	"prt",		PROG,	0,			PROGPATH(prt),
	"rmdel",	PROG,	REALUSER,		PROGPATH(rmdel),
I 58
	"val",		PROG,	0,			PROGPATH(val),
E 58
	"what",		PROG,	NO_SDOT,		PROGPATH(what),
	"sccsdiff",	SHELL,	REALUSER,		PROGPATH(sccsdiff),
	"edit",		CMACRO,	NO_SDOT,		"get -e",
	"delget",	CMACRO,	NO_SDOT,		"delta:mysrp/get:ixbeskcl -t",
D 60
	"deledit",	CMACRO,	NO_SDOT,		"delta:mysrp/get:ixbskcl -e -t",
E 60
I 60
	"deledit",	CMACRO,	NO_SDOT,		"delta:mysrp -n/get:ixbskcl -e -t -g",
I 85
	"bump",		CMACRO,	NO_SDOT,		"get:rixbskcl -e -t/delta:mysr",
E 85
E 60
	"fix",		FIX,	NO_SDOT,		NULL,
	"clean",	CLEAN,	REALUSER|NO_SDOT,	(char *) CLEANC,
	"info",		CLEAN,	REALUSER|NO_SDOT,	(char *) INFOC,
	"check",	CLEAN,	REALUSER|NO_SDOT,	(char *) CHECKC,
	"tell",		CLEAN,	REALUSER|NO_SDOT,	(char *) TELLC,
	"unedit",	UNEDIT,	NO_SDOT,		NULL,
	"diffs",	DIFFS,	NO_SDOT|REALUSER,	NULL,
I 55
	"-diff",	DODIFF,	NO_SDOT|REALUSER,	PROGPATH(bdiff),
I 86
	"nprt",		CMACRO,	NO_SDOT,		"prt -n -a -i",
E 86
I 59
D 80
	"print",	CMACRO,	0,			"prt -e/get -p -m -s",
E 80
I 80
	"print",	CMACRO,	0,			"prs -e/get -p -m -s",
E 80
I 64
	"branch",	CMACRO,	NO_SDOT,
		"get:ixrc -e -b/delta: -s -n -ybranch-place-holder/get:pl -e -t -g",
I 67
D 73
	"create",	CREATE,	NO_SDOT,		NULL,
E 73
I 73
	"enter",	ENTER,	NO_SDOT,		NULL,
	"create",	CMACRO,	NO_SDOT,		"enter/get:ixbeskcl -t",
E 73
E 67
E 64
E 59
E 55
	NULL,		-1,	0,			NULL
E 52
E 48
E 34
E 7
};

I 37
/* one line from a p-file */
E 37
I 18
struct pfile
{
	char	*p_osid;	/* old SID */
	char	*p_nsid;	/* new SID */
	char	*p_user;	/* user who did edit */
	char	*p_date;	/* date of get */
	char	*p_time;	/* time of get */
I 63
	char	*p_aux;		/* extra info at end */
E 63
};

E 18
D 2
char	*SccsPath = "sccs/s.";
E 2
I 2
D 4
char	*SccsPath = "SCCS/s.";
E 4
I 4
D 31
char	*SccsPath = "SCCS";	/* pathname of SCCS files */
I 29
# ifdef SRCDIR
char	*SccsDir = SRCDIR;	/* directory to begin search from */
E 31
I 31
char	*SccsPath = SCCSPATH;	/* pathname of SCCS files */
# ifdef SCCSDIR
char	*SccsDir = SCCSDIR;	/* directory to begin search from */
E 31
# else
E 29
I 26
D 31
char	*SccsDir = "";		/* directory to begin search from */
E 31
I 31
char	*SccsDir = "";
E 31
I 29
# endif
I 40
char	MyName[] = MYNAME;	/* name used in messages */
E 40
I 38
int	OutFile = -1;		/* override output file for commands */
E 38
E 29
E 26
D 6
bool	IsAdmin;		/* if set, this person is an administrator */
E 6
bool	RealUser;		/* if set, running as real user */
I 16
# ifdef DEBUG
bool	Debug;			/* turn on tracing */
# endif
I 61
# ifndef V6
extern char	*getenv();
# endif V6
I 74

I 80
extern char	*sys_siglist[];

E 80
char *gstrcat(), *strcat();
char *gstrncat(), *strncat();
char *gstrcpy(), *strcpy();
#define	FBUFSIZ	BUFSIZ
#define	PFILELG	120
E 74
E 61
E 16
E 4
E 2
D 37

E 37
I 37

E 37
main(argc, argv)
	int argc;
	char **argv;
{
	register char *p;
I 12
	extern struct sccsprog *lookup();
I 32
	register int i;
I 61
D 62

E 62
# ifndef V6
# ifndef SCCSDIR
I 62
	register struct passwd *pw;
	extern struct passwd *getpwnam();
D 74
	char buf[100];
E 74
I 74
	char buf[FBUFSIZ];
E 74

E 62
	/* pull "SccsDir" out of the environment (possibly) */
D 75
	p = getenv("PROJECT");
E 75
I 75
	p = getenv("PROJECTDIR");
E 75
D 62
	if (p[0] == '/')
		SccsDir = p;
	else
		fprintf(stderr, "PROJECT must be a full pathname\n");
E 62
I 62
	if (p != NULL && p[0] != '\0')
	{
		if (p[0] == '/')
			SccsDir = p;
		else
		{
			pw = getpwnam(p);
			if (pw == NULL)
			{
				usrerr("user %s does not exist", p);
				exit(EX_USAGE);
			}
D 74
			strcpy(buf, pw->pw_dir);
			strcat(buf, "/src");
E 74
I 74
			gstrcpy(buf, pw->pw_dir, sizeof(buf));
			gstrcat(buf, "/src", sizeof(buf));
E 74
			if (access(buf, 0) < 0)
			{
D 74
				strcpy(buf, pw->pw_dir);
				strcat(buf, "/source");
E 74
I 74
				gstrcpy(buf, pw->pw_dir, sizeof(buf));
				gstrcat(buf, "/source", sizeof(buf));
E 74
				if (access(buf, 0) < 0)
				{
					usrerr("project %s has no source!", p);
					exit(EX_USAGE);
				}
			}
			SccsDir = buf;
		}
	}
E 62
# endif SCCSDIR
# endif V6
E 61
E 32
E 12
D 7
	register char **av;
	char *newargv[1000];
	extern char *makefile();
	register struct sccsprog *cmd;
I 4
	char buf[200];
D 6
	int uid;
	auto int xuid;
E 6
	register FILE *fp;
E 7
E 4

	/*
	**  Detect and decode flags intended for this program.
	*/

D 7
	while (--argc > 0)
E 7
I 7
	if (argc < 2)
E 7
	{
D 7
		p = *++argv;
E 7
I 7
D 29
		fprintf(stderr, "Usage: sccs [flags] command [flags]\n");
E 29
I 29
		fprintf(stderr, "Usage: %s [flags] command [flags]\n", MyName);
E 29
		exit(EX_USAGE);
	}
	argv[argc] = NULL;

D 12
	while ((p = *++argv) != NULL)
E 12
I 12
	if (lookup(argv[0]) == NULL)
E 12
	{
E 7
D 12
		if (*p != '-')
			break;
		switch (*++p)
E 12
I 12
		while ((p = *++argv) != NULL)
E 12
		{
D 12
		  case 'r':		/* run as real user */
			setuid(getuid());
I 4
			RealUser++;
E 4
			break;
E 12
I 12
			if (*p != '-')
				break;
			switch (*++p)
			{
			  case 'r':		/* run as real user */
				setuid(getuid());
				RealUser++;
				break;
E 12

I 29
D 31
# ifndef SRCDIR
E 31
I 31
# ifndef SCCSDIR
E 31
E 29
D 12
		  case 'p':		/* path of sccs files */
			SccsPath = ++p;
			break;
E 12
I 12
			  case 'p':		/* path of sccs files */
				SccsPath = ++p;
I 65
				if (SccsPath[0] == '\0' && argv[1] != NULL)
					SccsPath = *++argv;
E 65
				break;
E 12

I 26
			  case 'd':		/* directory to search from */
				SccsDir = ++p;
I 65
				if (SccsDir[0] == '\0' && argv[1] != NULL)
					SccsDir = *++argv;
E 65
				break;
I 29
# endif
E 29

E 26
I 16
# ifdef DEBUG
			  case 'T':		/* trace */
				Debug++;
				break;
# endif

E 16
D 12
		  default:
			fprintf(stderr, "Sccs: unknown option -%s\n", p);
			break;
E 12
I 12
			  default:
D 29
				fprintf(stderr, "Sccs: unknown option -%s\n", p);
E 29
I 29
				usrerr("unknown option -%s", p);
E 29
				break;
			}
E 12
		}
I 12
		if (SccsPath[0] == '\0')
			SccsPath = ".";
E 12
	}
I 5
D 12
	if (SccsPath[0] == '\0')
		SccsPath = ".";
E 12
E 5

D 7
	/*
I 4
	**  See if this user is an administrator.
	*/
E 7
I 7
D 8
	command(argv);
E 8
I 8
D 32
	command(argv, FALSE);
E 8
	exit(EX_OK);
E 32
I 32
D 34
	i = command(argv, FALSE);
E 34
I 34
D 48
	i = command(argv, FALSE, FALSE, "");
E 48
I 48
	i = command(argv, FALSE, "");
E 48
E 34
	exit(i);
E 32
}
I 32
D 37
/*
E 37
I 37

/*
E 37
**  COMMAND -- look up and perform a command
**
**	This routine is the guts of this program.  Given an
**	argument vector, it looks up the "command" (argv[0])
**	in the configuration table and does the necessary stuff.
**
**	Parameters:
**		argv -- an argument vector to process.
**		forkflag -- if set, fork before executing the command.
I 34
**		editflag -- if set, only include flags listed in the
**			sccsklets field of the command descriptor.
**		arg0 -- a space-seperated list of arguments to insert
**			before argv.
E 34
**
**	Returns:
**		zero -- command executed ok.
**		else -- error status.
**
**	Side Effects:
**		none.
*/
E 32
E 7

I 7
D 8
command(argv)
E 8
I 8
D 34
command(argv, forkflag)
E 34
I 34
D 48
command(argv, forkflag, editflag, arg0)
E 48
I 48
command(argv, forkflag, arg0)
E 48
E 34
E 8
	char **argv;
I 8
	bool forkflag;
I 34
D 48
	bool editflag;
E 48
	char *arg0;
E 34
E 8
{
	register struct sccsprog *cmd;
	register char *p;
I 8
D 36
	register char *q;
E 36
D 67
	char buf[40];
E 67
I 67
D 74
	char buf[100];
E 74
I 74
	char buf[FBUFSIZ];
E 74
E 67
I 12
	extern struct sccsprog *lookup();
I 16
D 23
	char *nav[7];
E 23
I 23
D 34
	char *nav[200];
E 23
	char **avp;
E 34
I 34
	char *nav[1000];
	char **np;
D 36
	char **ap;
E 36
I 36
	register char **ap;
E 36
E 34
I 23
	register int i;
I 36
	register char *q;
E 36
	extern bool unedit();
I 32
	int rval = 0;
I 34
	extern char *index();
	extern char *makefile();
I 48
	char *editchs;
E 48
I 39
	extern char *tail();
E 39
E 34
E 32
E 23
E 16
E 12
E 8

I 16
# ifdef DEBUG
	if (Debug)
	{
D 34
		printf("command:\n");
		for (avp = argv; *avp != NULL; avp++)
			printf("    \"%s\"\n", *avp);
E 34
I 34
		printf("command:\n\t\"%s\"\n", arg0);
		for (np = argv; *np != NULL; np++)
			printf("\t\"%s\"\n", *np);
E 34
	}
# endif

E 16
E 7
D 6
	uid = getuid();
# ifdef V6
	uid &= 0377;
# endif V6
	strcpy(buf, SccsPath);
	strcat(buf, "/ADMINFILE");
	fp = fopen(buf, "r");
	if (fp != NULL)
	{
		while (fgets(buf, sizeof buf, fp) != NULL)
		{
			if (buf[0] == 'A')
			{
				if (sscanf(&buf[1], "%d", &xuid) > 0 &&
				    xuid == uid)
					IsAdmin++;
			}
		}
		fclose(fp);
	}
I 5
	else
	{
		/* no ADMINFILE -- take some defaults */
		IsAdmin++;
	}
E 5

E 6
	/*
I 34
	**  Copy arguments.
D 41
	**	Phase one -- from arg0 & if necessary argv[0].
E 41
I 41
	**	Copy from arg0 & if necessary at most one arg
	**	from argv[0].
E 41
	*/

D 36
	np = nav;
E 36
I 36
	np = ap = &nav[1];
E 36
D 48
	for (p = arg0, q = buf; *p != '\0' && *p != '/'; )
E 48
I 48
	editchs = NULL;
D 50
	for (p = arg0, q = buf; *p != '\0' && *p != '/' && *p != ':'; )
E 50
I 50
	for (p = arg0, q = buf; *p != '\0' && *p != '/'; )
E 50
E 48
	{
		*np++ = q;
		while (*p == ' ')
			p++;
D 48
		while (*p != ' ' && *p != '\0' && *p != '/')
E 48
I 48
		while (*p != ' ' && *p != '\0' && *p != '/' && *p != ':')
E 48
			*q++ = *p++;
		*q++ = '\0';
I 48
		if (*p == ':')
		{
			editchs = q;
D 50
			while (*++p != '\0' && *p != '/')
E 50
I 50
			while (*++p != '\0' && *p != '/' && *p != ' ')
E 50
				*q++ = *p;
			*q++ = '\0';
		}
E 48
	}
	*np = NULL;
D 36
	if (nav[0] == NULL)
E 36
I 36
	if (*ap == NULL)
E 36
		*np++ = *argv++;

	/*
E 34
E 4
	**  Look up command.
D 7
	**	At this point, p and argv point to the command name.
E 7
I 7
D 34
	**	At this point, argv points to the command name.
E 34
I 34
D 36
	**	At this point, nav[0] is the command name.
E 36
I 36
	**	At this point, *ap is the command name.
E 36
E 34
E 7
	*/

I 7
D 16
	p = *argv;
E 7
D 12
	for (cmd = SccsProg; cmd->sccsname != NULL; cmd++)
E 12
I 12
	cmd = lookup(p);
E 16
I 16
D 18
	cmd = lookup(*argv);
E 18
I 18
D 34
	cmd = lookup(argv[0]);
E 34
I 34
D 36
	cmd = lookup(nav[0]);
E 36
I 36
	cmd = lookup(*ap);
E 36
E 34
E 18
E 16
	if (cmd == NULL)
E 12
	{
D 12
		if (strcmp(cmd->sccsname, p) == 0)
			break;
	}
	if (cmd->sccsname == NULL)
	{
E 12
D 16
		fprintf(stderr, "Sccs: Unknown command \"%s\"\n", p);
E 16
I 16
D 18
		fprintf(stderr, "Sccs: Unknown command \"%s\"\n", *argv);
E 18
I 18
D 29
		fprintf(stderr, "Sccs: Unknown command \"%s\"\n", argv[0]);
E 29
I 29
D 36
		usrerr("Unknown command \"%s\"", argv[0]);
E 36
I 36
		usrerr("Unknown command \"%s\"", *ap);
E 36
E 29
E 18
E 16
D 32
		exit(EX_USAGE);
E 32
I 32
		return (EX_USAGE);
E 32
	}

	/*
I 34
	**  Copy remaining arguments doing editing as appropriate.
	*/

	for (; *argv != NULL; argv++)
	{
		p = *argv;
		if (*p == '-')
		{
D 48
			if (p[1] == '\0' || !editflag || cmd->sccsklets == NULL ||
			    index(cmd->sccsklets, p[1]) != NULL)
E 48
I 48
			if (p[1] == '\0' || editchs == NULL || index(editchs, p[1]) != NULL)
E 48
				*np++ = p;
		}
		else
		{
			if (!bitset(NO_SDOT, cmd->sccsflags))
				p = makefile(p);
			if (p != NULL)
				*np++ = p;
		}
	}
	*np = NULL;

	/*
E 34
I 4
D 7
	**  Set protection as appropriate.
E 7
I 7
	**  Interpret operation associated with this command.
E 7
	*/

D 6
	if (bitset(F_PROT, cmd->sccsflags) && !IsAdmin && !RealUser)
	{
		fprintf(stderr, "Sccs: not authorized to use %s\n", p);
		exit(EX_USAGE);
	}
E 6
I 6
D 7
	if (bitset(F_PROT, cmd->sccsflags))
		setuid(getuid());
E 7
I 7
	switch (cmd->sccsoper)
	{
I 36
	  case SHELL:		/* call a shell file */
		*ap = cmd->sccspath;
		*--ap = "sh";
		rval = callprog("/bin/sh", cmd->sccsflags, ap, forkflag);
		break;

E 36
	  case PROG:		/* call an sccs prog */
D 8
		callprog(cmd->sccspath, cmd->sccsflags, argv, FALSE);
		fprintf(stderr, "Sccs internal error: callprog\n");
E 8
I 8
D 32
		callprog(cmd->sccspath, cmd->sccsflags, argv, forkflag);
E 32
I 32
D 34
		rval = callprog(cmd->sccspath, cmd->sccsflags, argv, forkflag);
E 34
I 34
D 36
		rval = callprog(cmd->sccspath, cmd->sccsflags, nav, forkflag);
E 36
I 36
		rval = callprog(cmd->sccspath, cmd->sccsflags, ap, forkflag);
E 36
E 34
E 32
		break;

	  case CMACRO:		/* command macro */
I 41
		/* step through & execute each part of the macro */
E 41
		for (p = cmd->sccspath; *p != '\0'; p++)
		{
I 16
D 34
			avp = nav;
			*avp++ = buf;
E 16
			for (q = buf; *p != '/' && *p != '\0'; p++, q++)
D 16
				*q = *p;
E 16
I 16
			{
				if (*p == ' ')
				{
					*q = '\0';
					*avp++ = &q[1];
				}
				else
					*q = *p;
			}
E 16
			*q = '\0';
D 16
			argv[0] = buf;
			command(argv, *p != '\0');
E 16
I 16
			*avp = NULL;
D 32
			xcommand(&argv[1], *p != '\0', nav[0], nav[1], nav[2],
				 nav[3], nav[4], nav[5], nav[6]);
E 32
I 32
			rval = xcommand(&argv[1], *p != '\0', nav[0], nav[1],
					nav[2], nav[3], nav[4], nav[5], nav[6]);
E 34
I 34
			q = p;
			while (*p != '\0' && *p != '/')
				p++;
D 36
			rval = command(&nav[1], *p != '\0', TRUE, q);
E 36
I 36
D 48
			rval = command(&ap[1], *p != '\0', TRUE, q);
E 48
I 48
			rval = command(&ap[1], *p != '\0', q);
E 48
E 36
E 34
			if (rval != 0)
				break;
E 32
E 16
		}
D 29
		fprintf(stderr, "Sccs internal error: CMACRO\n");
E 29
I 29
D 32
		syserr("internal error: CMACRO");
E 29
E 8
		exit(EX_SOFTWARE);
E 32
I 32
		break;
E 32
E 7
E 6

I 10
	  case FIX:		/* fix a delta */
D 11
		if (strncmp(argv[1], "-r", 2) != 0)
E 11
I 11
D 21
		if (strcmpn(argv[1], "-r", 2) != 0)
E 21
I 21
D 34
		if (strncmp(argv[1], "-r", 2) != 0)
E 34
I 34
D 36
		if (strncmp(nav[1], "-r", 2) != 0)
E 36
I 36
D 80
		if (strncmp(ap[1], "-r", 2) != 0)
E 80
I 80
		if (ap[1]==0 || strncmp(ap[1], "-r", 2)!=0)
E 80
E 36
E 34
E 21
E 11
		{
D 29
			fprintf(stderr, "Sccs: -r flag needed for fix command\n");
E 29
I 29
			usrerr("-r flag needed for fix command");
I 32
			rval = EX_USAGE;
E 32
E 29
			break;
		}
I 41

		/* get the version with all changes */
E 41
D 32
		xcommand(&argv[1], TRUE, "get", "-k", NULL);
		xcommand(&argv[1], TRUE, "rmdel", NULL);
		xcommand(&argv[2], FALSE, "get", "-e", "-g", NULL);
D 29
		fprintf(stderr, "Sccs internal error: FIX\n");
E 29
I 29
		syserr("FIX");
E 29
		exit(EX_SOFTWARE);
E 32
I 32
D 34
		rval = xcommand(&argv[1], TRUE, "get", "-k", NULL);
E 34
I 34
D 36
		rval = command(&nav[1], TRUE, TRUE, "get -k");
E 36
I 36
D 48
		rval = command(&ap[1], TRUE, TRUE, "get -k");
E 48
I 48
		rval = command(&ap[1], TRUE, "get -k");
E 48
I 41

		/* now remove that version from the s-file */
E 41
E 36
E 34
		if (rval == 0)
D 34
			rval = xcommand(&argv[1], TRUE, "rmdel", NULL);
E 34
I 34
D 36
			rval = command(&nav[1], TRUE, TRUE, "rmdel");
E 36
I 36
D 48
			rval = command(&ap[1], TRUE, TRUE, "rmdel");
E 48
I 48
			rval = command(&ap[1], TRUE, "rmdel:r");
E 48
I 41

		/* and edit the old version (but don't clobber new vers) */
E 41
E 36
E 34
		if (rval == 0)
D 34
			rval = xcommand(&argv[2], FALSE, "get", "-e", "-g", NULL);
E 34
I 34
D 36
			rval = command(&nav[2], FALSE, TRUE, "get -e -g");
E 36
I 36
D 48
			rval = command(&ap[2], FALSE, TRUE, "get -e -g");
E 48
I 48
			rval = command(&ap[2], FALSE, "get -e -g");
E 48
E 36
E 34
		break;
E 32

I 11
	  case CLEAN:
D 14
		clean();
E 14
I 14
D 27
		clean((bool) cmd->sccspath);
E 27
I 27
D 32
		clean((int) cmd->sccspath);
E 32
I 32
D 51
		rval = clean((int) cmd->sccspath);
E 51
I 51
		rval = clean((int) cmd->sccspath, ap);
E 51
E 32
E 27
E 14
		break;

I 18
	  case UNEDIT:
I 23
D 34
		i = 0;
E 23
		for (avp = &argv[1]; *avp != NULL; avp++)
E 34
I 34
D 36
		for (argv = np = &nav[1]; *argv != NULL; argv++)
E 36
I 36
		for (argv = np = &ap[1]; *argv != NULL; argv++)
E 36
E 34
D 23
			unedit(*avp);
I 22
		xcommand(&argv[1], FALSE, "get", NULL);
E 23
I 23
		{
D 34
			if (unedit(*avp))
				nav[i++] = *avp;
E 34
I 34
			if (unedit(*argv))
				*np++ = *argv;
E 34
		}
D 34
		nav[i] = NULL;
E 34
I 34
		*np = NULL;
I 41

		/* get all the files that we unedited successfully */
E 41
E 34
D 49
		if (i > 0)
E 49
I 49
		if (np > &ap[1])
E 49
D 32
			xcommand(nav, FALSE, "get", NULL);
E 32
I 32
D 34
			rval = xcommand(nav, FALSE, "get", NULL);
E 34
I 34
D 36
			rval = command(&nav[1], FALSE, FALSE, "get");
E 36
I 36
D 48
			rval = command(&ap[1], FALSE, FALSE, "get");
E 48
I 48
			rval = command(&ap[1], FALSE, "get");
E 48
E 36
E 34
E 32
E 23
E 22
		break;

I 38
	  case DIFFS:		/* diff between s-file & edit file */
		/* find the end of the flag arguments */
		for (np = &ap[1]; *np != NULL && **np == '-'; np++)
			continue;
		argv = np;

		/* for each file, do the diff */
I 43
		p = argv[1];
E 43
		while (*np != NULL)
		{
I 41
			/* messy, but we need a null terminated argv */
E 41
			*argv = *np++;
D 43
			p = *np;
			*np = NULL;
E 43
I 43
			argv[1] = NULL;
E 43
D 39
			i = dodiff(ap, *argv);
E 39
I 39
			i = dodiff(ap, tail(*argv));
E 39
			if (rval == 0)
				rval = i;
D 43
			*np = p;
E 43
I 43
			argv[1] = p;
E 43
		}
		break;

I 55
	  case DODIFF:		/* internal diff call */
		setuid(getuid());
		for (np = ap; *np != NULL; np++)
		{
			if ((*np)[0] == '-' && (*np)[1] == 'C')
				(*np)[1] = 'c';
		}

		/* insert "-" argument */
		np[1] = NULL;
		np[0] = np[-1];
		np[-1] = "-";

		/* execute the diff program of choice */
# ifndef V6
		execvp("diff", ap);
# endif
		execv(cmd->sccspath, argv);
		syserr("cannot exec %s", cmd->sccspath);
		exit(EX_OSERR);
I 67

D 73
	  case CREATE:		/* create new sccs files */
E 73
I 73
	  case ENTER:		/* enter new sccs files */
E 73
		/* skip over flag arguments */
		for (np = &ap[1]; *np != NULL && **np == '-'; np++)
			continue;
		argv = np;

		/* do an admin for each file */
		p = argv[1];
		while (*np != NULL)
		{
I 68
			printf("\n%s:\n", *np);
E 68
D 74
			sprintf(buf, "-i%s", *np);
E 74
I 74
			strcpy(buf, "-i");
			gstrcat(buf, *np, sizeof(buf));
E 74
			ap[0] = buf;
			argv[0] = tail(*np);
			argv[1] = NULL;
			rval = command(ap, TRUE, "admin");
			argv[1] = p;
			if (rval == 0)
			{
D 74
				sprintf(buf, ",%s", tail(*np));
E 74
I 74
				strcpy(buf, ",");
				gstrcat(buf, tail(*np), sizeof(buf));
E 74
				if (link(*np, buf) >= 0)
					unlink(*np);
			}
			np++;
		}
		break;
E 67

E 55
E 38
E 18
E 11
E 10
I 7
	  default:
D 29
		fprintf(stderr, "Sccs internal error: oper %d\n", cmd->sccsoper);
E 29
I 29
		syserr("oper %d", cmd->sccsoper);
E 29
		exit(EX_SOFTWARE);
	}
I 32
# ifdef DEBUG
	if (Debug)
		printf("command: rval=%d\n", rval);
# endif
	return (rval);
E 32
}
I 12
D 37
/*
E 37
I 37

/*
E 37
**  LOOKUP -- look up an SCCS command name.
**
**	Parameters:
**		name -- the name of the command to look up.
**
**	Returns:
**		ptr to command descriptor for this command.
**		NULL if no such entry.
**
**	Side Effects:
**		none.
*/
E 12

I 12
struct sccsprog *
lookup(name)
	char *name;
{
	register struct sccsprog *cmd;
E 12
I 10

I 12
	for (cmd = SccsProg; cmd->sccsname != NULL; cmd++)
	{
		if (strcmp(cmd->sccsname, name) == 0)
			return (cmd);
	}
	return (NULL);
}
I 32
D 37
/*
E 37
I 37

/*
E 37
D 34
**  XCOMMAND -- special version of command
**
**	This routine prepends an argv to another argv and calls
**	command.  It is used mostly for macros, etc.
**
**	Parameters:
**		argv -- the normal argv.
**		forkflag -- passed to command.
**		arg0 -- the argv to prepend.
**
**	Returns:
**		see 'command'.
**
**	Side Effects:
**		none.
*/
E 32

D 32

E 32
E 12
xcommand(argv, forkflag, arg0)
	char **argv;
	bool forkflag;
	char *arg0;
{
	register char **av;
	char *newargv[1000];
	register char **np;

	np = newargv;
	for (av = &arg0; *av != NULL; av++)
		*np++ = *av;
	for (av = argv; *av != NULL; av++)
		*np++ = *av;
	*np = NULL;
D 32
	command(newargv, forkflag);
E 32
I 32
	return (command(newargv, forkflag));
E 32
}
I 32
/*
E 34
**  CALLPROG -- call a program
**
D 34
**	Used to call the SCCS programs.  Arguments in argv will be
**	modified to be prepended by "SCCS/s." as appropriate.
E 34
I 34
**	Used to call the SCCS programs.
E 34
**
**	Parameters:
**		progpath -- pathname of the program to call.
**		flags -- status flags from the command descriptors.
**		argv -- an argument vector to pass to the program.
**		forkflag -- if true, fork before calling, else just
**			exec.
**
**	Returns:
**		The exit status of the program.
**		Nothing if forkflag == FALSE.
**
**	Side Effects:
**		Can exit if forkflag == FALSE.
*/
E 32

E 10
callprog(progpath, flags, argv, forkflag)
	char *progpath;
	short flags;
	char **argv;
	bool forkflag;
{
D 34
	register char *p;
	register char **av;
D 10
	char *newargv[1000];
E 10
	extern char *makefile();
E 34
	register int i;
I 80
	register int wpid;
E 80
I 8
	auto int st;
I 80
	register int sigcode;
	register int coredumped;
	register char *sigmsg;
	auto char sigmsgbuf[10+1];	/* "Signal 127" + terminating '\0' */
E 80
I 24
D 34
	register char **nav;
E 34
E 24
E 8

I 34
# ifdef DEBUG
	if (Debug)
	{
		printf("callprog:\n");
		for (i = 0; argv[i] != NULL; i++)
			printf("\t\"%s\"\n", argv[i]);
	}
# endif

E 34
	if (*argv == NULL)
		return (-1);

E 7
	/*
E 4
D 10
	**  Build new argument vector.
E 10
I 10
	**  Fork if appropriate.
E 10
D 2
	**	This is in three phases.
	**	1.  Copy program name.
	**	2.  Copy program flags with no translation.
	**	3.  Copy program files, with possible translation.
E 2
	*/

D 2
	/*  1: copy program name  */
E 2
D 10
	av = newargv;
D 7
	*av++ = p;
E 7
I 7
	*av++ = *argv;
E 7

D 2
	/*  2: copy program flags, no translation  */
	while (--argc > 0 && *(p = *++argv) == '-')
		*av++ = p;

	/*  3: copy program filename arguments  */
	while (argc-- > 0)
E 2
I 2
	/* copy program filename arguments and flags */
D 7
	while (--argc > 0)
E 7
I 7
	while ((p = *++argv) != NULL)
E 7
E 2
	{
D 2
		if ((cmd->sccsflags & F_NOSDOT) == 0)
			*av++ = makefile(*argv++);
E 2
I 2
D 7
		p = *++argv;
D 4
		if ((cmd->sccsflags & F_NOSDOT) == 0 && *p != '-')
E 4
I 4
		if (!bitset(F_NOSDOT, cmd->sccsflags) && *p != '-')
E 7
I 7
		if (!bitset(NO_SDOT, flags) && *p != '-')
E 7
E 4
			*av++ = makefile(p);
E 2
		else
D 2
			*av++ = *argv++;
E 2
I 2
			*av++ = p;
E 2
	}
	
	/* terminate argument vector */
	*av = NULL;

	/*
	**  Call real SCCS program.
	*/

E 10
D 7
	execv(cmd->sccspath, newargv);
E 7
I 7
	if (forkflag)
	{
I 16
# ifdef DEBUG
		if (Debug)
			printf("Forking\n");
# endif
E 16
		i = fork();
		if (i < 0)
		{
D 29
			fprintf(stderr, "Sccs: cannot fork");
E 29
I 29
			syserr("cannot fork");
E 29
			exit(EX_OSERR);
		}
		else if (i > 0)
D 8
			return (i);
E 8
I 8
		{
D 80
			wait(&st);
I 32
			if ((st & 0377) == 0)
E 80
I 80
			while ((wpid = wait(&st)) != -1 && wpid != i)
				;
			if ((sigcode = st & 0377) == 0)
E 80
				st = (st >> 8) & 0377;
I 80
			else
			{
				coredumped = sigcode & 0200;
				sigcode &= 0177;
				if (sigcode != SIGINT && sigcode != SIGPIPE)
				{
					if (sigcode < NSIG)
						sigmsg = sys_siglist[sigcode];
					else
					{
						sprintf(sigmsgbuf, "Signal %d",
						    sigcode);
						sigmsg = sigmsgbuf;
					}
					fprintf(stderr, "sccs: %s: %s%s", argv[0],
					    sigmsg,
					    coredumped ? " - core dumped": "");
				}
				st = EX_SOFTWARE;
			}
E 80
I 38
			if (OutFile >= 0)
			{
				close(OutFile);
				OutFile = -1;
			}
E 38
E 32
			return (st);
		}
E 8
	}
I 38
	else if (OutFile >= 0)
	{
		syserr("callprog: setting stdout w/o forking");
		exit(EX_SOFTWARE);
	}
E 38

D 38
	/*
I 10
D 34
	**  Build new argument vector.
	*/

	/* copy program filename arguments and flags */
I 24
	nav = &argv[1];
E 24
	av = argv;
	while ((p = *++av) != NULL)
	{
		if (!bitset(NO_SDOT, flags) && *p != '-')
D 24
			*av = makefile(p);
E 24
I 24
			*nav = makefile(p);
		else
			*nav = p;
		if (*nav != NULL)
			nav++;
E 24
	}
I 24
	*nav = NULL;
E 24

	/*
E 34
E 10
	**  Set protection as appropriate.
	*/

E 38
I 38
	/* set protection as appropriate */
E 38
	if (bitset(REALUSER, flags))
		setuid(getuid());
D 10

E 10
I 10
D 38
	
E 10
	/*
D 10
	**  Call the program.
E 10
I 10
	**  Call real SCCS program.
E 10
	*/
E 38

I 38
	/* change standard input & output if needed */
	if (OutFile >= 0)
	{
		close(1);
		dup(OutFile);
		close(OutFile);
	}
	
	/* call real SCCS program */
E 38
D 10
	execv(progpath, newargv);
E 10
I 10
	execv(progpath, argv);
E 10
E 7
D 29
	fprintf(stderr, "Sccs: cannot execute ");
D 7
	perror(cmd->sccspath);
E 7
I 7
	perror(progpath);
E 29
I 29
	syserr("cannot execute %s", progpath);
E 29
E 7
	exit(EX_UNAVAILABLE);
I 49
	/*NOTREACHED*/
E 49
}
I 24
D 37
/*
E 37
I 37

/*
E 37
**  MAKEFILE -- make filename of SCCS file
**
**	If the name passed is already the name of an SCCS file,
**	just return it.  Otherwise, munge the name into the name
**	of the actual SCCS file.
**
**	There are cases when it is not clear what you want to
**	do.  For example, if SccsPath is an absolute pathname
**	and the name given is also an absolute pathname, we go
**	for SccsPath (& only use the last component of the name
**	passed) -- this is important for security reasons (if
**	sccs is being used as a setuid front end), but not
**	particularly intuitive.
**
**	Parameters:
**		name -- the file name to be munged.
**
**	Returns:
**		The pathname of the sccs file.
**		NULL on error.
**
**	Side Effects:
**		none.
*/
E 24

D 24

E 24
char *
makefile(name)
	char *name;
{
	register char *p;
D 49
	register char c;
E 49
D 74
	char buf[512];
E 74
I 74
	char buf[3*FBUFSIZ];
E 74
D 25
D 49
	struct stat stbuf;
E 49
E 25
	extern char *malloc();
I 24
	extern char *rindex();
D 25
	extern bool safepath();
I 26
	extern bool isdir();
	register char *q;
E 26
E 25
I 25
	extern bool isdir();
	register char *q;
E 25
E 24

I 24
	p = rindex(name, '/');
	if (p == NULL)
		p = name;
	else
		p++;

E 24
	/*
D 24
	**  See if this filename should be used as-is.
	**	There are three conditions where this can occur.
	**	1. The name already begins with "s.".
	**	2. The name has a "/" in it somewhere.
	**	3. The name references a directory.
E 24
I 24
D 25
	**  Check to see that the path is "safe", i.e., that we
	**  are not letting some nasty person use the setuid part
	**  of this program to look at or munge some presumably
	**  hidden files.
E 25
I 25
	**  See if the name can be used as-is.
E 25
E 24
	*/

D 11
	if (strncmp(name, "s.", 2) == 0)
E 11
I 11
D 21
	if (strcmpn(name, "s.", 2) == 0)
E 21
I 21
D 24
	if (strncmp(name, "s.", 2) == 0)
E 21
E 11
		return (name);
	for (p = name; (c = *p) != '\0'; p++)
E 24
I 24
D 25
D 26
	if (SccsPath[0] == '/' && !safepath(name))
E 26
I 26
	if (SccsDir[0] == '/' && !safepath(name))
E 26
		return (NULL);
E 25
I 25
	if (SccsPath[0] != '/' || name[0] == '/' || strncmp(name, "./", 2) == 0)
	{
		if (strncmp(p, "s.", 2) == 0)
			return (name);
		if (isdir(name))
			return (name);
	}
E 25

	/*
D 25
D 26
	**  Create the eventual pathname.
E 26
I 26
	**  Create the base pathname.
E 26
E 25
I 25
	**  Create the actual pathname.
E 25
	*/

I 41
	/* first the directory part */
E 41
D 25
D 26
	if (SccsPath[0] == '/')
E 26
I 26
	if (SccsDir[0] != '\0' && name[0] != '/' && strncmp(name, "./", 2) != 0)
E 26
E 25
I 25
	if (name[0] != '/')
E 25
E 24
	{
D 24
		if (c == '/')
E 24
I 24
D 26
		strcpy(buf, SccsPath);
E 26
I 26
D 74
		strcpy(buf, SccsDir);
E 26
		strcat(buf, "/");
E 74
I 74
		gstrcpy(buf, SccsDir, sizeof(buf));
		gstrcat(buf, "/", sizeof(buf));
E 74
	}
	else
D 74
		strcpy(buf, "");
E 74
I 74
		gstrcpy(buf, "", sizeof(buf));
E 74
I 41
	
	/* then the head of the pathname */
E 41
D 25
D 26
	if (strncmp(p, "s.", 2) != 0)
E 26
I 26
D 74
	strncat(buf, name, p - name);
E 74
I 74
	gstrncat(buf, name, p - name, sizeof(buf));
E 74
	q = &buf[strlen(buf)];
I 41

	/* now copy the final part of the name, in case useful */
E 41
D 74
	strcpy(q, p);
E 74
I 74
	gstrcpy(q, p, sizeof(buf));
E 74
I 41

	/* so is it useful? */
E 41
	if (strncmp(p, "s.", 2) != 0 && !isdir(buf))
E 26
E 25
I 25
	strncat(buf, name, p - name);
	q = &buf[strlen(buf)];
	strcpy(q, p);
	if (strncmp(p, "s.", 2) != 0 && !isdir(buf))
E 25
	{
I 41
		/* sorry, no; copy the SCCS pathname & the "s." */
E 41
D 25
D 26
		strncat(buf, name, p - name);
		if (SccsPath[0] != '/')
E 25
I 25
		strcpy(q, "");
		if (SccsPath[0] != '/' && name[0] == '/')
E 25
		{
			strcat(buf, SccsPath);
			strcat(buf, "/");
		}
		strcat(buf, "s.");
E 26
I 26
D 74
		strcpy(q, SccsPath);
		strcat(buf, "/s.");
E 74
I 74
		gstrcpy(q, SccsPath, sizeof(buf));
		gstrcat(buf, "/s.", sizeof(buf));
E 74
I 41

		/* and now the end of the name */
E 41
E 26
D 74
		strcat(buf, p);
E 74
I 74
		gstrcat(buf, p, sizeof(buf));
E 74
	}
I 26

I 41
	/* if i haven't changed it, why did I do all this? */
E 41
	if (strcmp(buf, name) == 0)
		p = name;
E 26
D 25
	else
	{
I 41
		/* but if I have, squirrel it away */
E 41
D 26
		if (SccsPath[0] != '/')
E 24
			return (name);
I 24
		strcat(buf, name);
E 26
I 26
		p = malloc(strlen(buf) + 1);
		if (p == NULL)
		{
			perror("Sccs: no mem");
			exit(EX_OSERR);
		}
		strcpy(p, buf);
E 26
E 24
	}
I 41

E 41
I 26
	return (p);
}
D 37
/*
E 37
I 37

/*
E 37
**  ISDIR -- return true if the argument is a directory.
**
**	Parameters:
**		name -- the pathname of the file to check.
**
**	Returns:
**		TRUE if 'name' is a directory, FALSE otherwise.
**
**	Side Effects:
**		none.
*/
E 26
E 25
D 24
	if (stat(name, &stbuf) >= 0 && (stbuf.st_mode & S_IFMT) == S_IFDIR)
		return (name);
E 24

D 24
	/*
	**  Prepend the path of the sccs file.
	*/
E 24
I 24
D 25
D 26
	if (stat(buf, &stbuf) >= 0 && (stbuf.st_mode & S_IFMT) == S_IFDIR)
	{
		if (SccsPath[0] != '/')
			return (name);
	}
E 26
I 26
bool
isdir(name)
	char *name;
{
	struct stat stbuf;
E 26
E 24

E 25
D 24
	strcpy(buf, SccsPath);
I 4
	strcat(buf, "/s.");
E 4
	strcat(buf, name);
E 24
D 26
	p = malloc(strlen(buf) + 1);
	if (p == NULL)
	{
		perror("Sccs: no mem");
		exit(EX_OSERR);
	}
	strcpy(p, buf);
	return (p);
E 26
I 26
	return (stat(name, &stbuf) >= 0 && (stbuf.st_mode & S_IFMT) == S_IFDIR);
E 26
I 25
}
/*
**  ISDIR -- return true if the argument is a directory.
**
**	Parameters:
**		name -- the pathname of the file to check.
**
**	Returns:
**		TRUE if 'name' is a directory, FALSE otherwise.
**
**	Side Effects:
**		none.
*/

bool
isdir(name)
	char *name;
{
	struct stat stbuf;

	return (stat(name, &stbuf) >= 0 && (stbuf.st_mode & S_IFMT) == S_IFDIR);
E 25
}
I 11
D 37
/*
E 37
I 37

/*
E 37
I 24
**  SAFEPATH -- determine whether a pathname is "safe"
**
**	"Safe" pathnames only allow you to get deeper into the
**	directory structure, i.e., full pathnames and ".." are
**	not allowed.
**
**	Parameters:
**		p -- the name to check.
**
**	Returns:
**		TRUE -- if the path is safe.
**		FALSE -- if the path is not safe.
**
**	Side Effects:
**		Prints a message if the path is not safe.
*/

bool
safepath(p)
	register char *p;
{
	extern char *index();

	if (*p != '/')
	{
		while (strncmp(p, "../", 3) != 0 && strcmp(p, "..") != 0)
		{
			p = index(p, '/');
			if (p == NULL)
				return (TRUE);
			p++;
		}
	}

	printf("You may not use full pathnames or \"..\"\n");
	return (FALSE);
}
D 37
/*
E 37
I 37

/*
E 37
E 24
**  CLEAN -- clean out recreatable files
**
**	Any file for which an "s." file exists but no "p." file
**	exists in the current directory is purged.
**
**	Parameters:
D 14
**		none.
E 14
I 14
D 27
**		really -- if TRUE, remove everything.
**			else, just report status.
E 27
I 27
D 51
**		tells whether this came from a "clean", "info", or
**		"check" command.
E 51
I 51
**		mode -- tells whether this came from a "clean", "info", or
**			"check" command.
**		argv -- the rest of the argument vector.
E 51
E 27
E 14
**
**	Returns:
**		none.
**
**	Side Effects:
D 27
**		removes files in the current directory.
E 27
I 27
**		Removes files in the current directory.
**		Prints information regarding files being edited.
**		Exits if a "check" command.
E 27
*/

D 14
clean()
E 14
I 14
D 27
clean(really)
	bool really;
E 27
I 27
D 51
clean(mode)
E 51
I 51
clean(mode, argv)
E 51
	int mode;
I 51
	char **argv;
E 51
E 27
E 14
{
D 70
	struct direct dir;
E 70
I 70
	struct direct *dir;
E 70
D 49
	struct stat stbuf;
E 49
D 74
	char buf[100];
E 74
I 74
	char buf[FBUFSIZ];
E 74
I 62
	char *bufend;
E 62
I 17
D 51
	char pline[120];
E 51
E 17
D 14
	FILE *dirfd;
E 14
I 14
D 70
	register FILE *dirfd;
E 70
I 70
D 79
	register DIR *dirfd;
E 79
I 79
	register DIR *dirp;
E 79
E 70
	register char *basefile;
I 15
	bool gotedit;
I 51
	bool gotpfent;
E 51
I 17
	FILE *pfp;
I 51
	bool nobranch = FALSE;
	extern struct pfile *getpfent();
	register struct pfile *pf;
	register char **ap;
I 52
	extern char *username();
	char *usernm = NULL;
I 62
	char *subdir = NULL;
	char *cmdname;
E 62
E 52
E 51
E 17
E 15
E 14

I 41
	/*
I 51
	**  Process the argv
	*/

D 62
	for (ap = argv; *ap != NULL; ap++)
E 62
I 62
	cmdname = *argv;
	for (ap = argv; *++ap != NULL; )
E 62
	{
D 52
		if (strcmp(*ap, "-b") == 0)
			nobranch = TRUE;
E 52
I 52
		if (**ap == '-')
		{
			/* we have a flag */
			switch ((*ap)[1])
			{
			  case 'b':
				nobranch = TRUE;
				break;

			  case 'u':
				if ((*ap)[2] != '\0')
					usernm = &(*ap)[2];
				else if (ap[1] != NULL && ap[1][0] != '-')
					usernm = *++ap;
				else
					usernm = username();
				break;
			}
		}
I 62
		else
		{
			if (subdir != NULL)
				usrerr("too many args");
			else
				subdir = *ap;
		}
E 62
E 52
	}

	/*
E 51
	**  Find and open the SCCS directory.
	*/

E 41
D 30
	dirfd = fopen(SccsPath, "r");
E 30
I 30
D 74
	strcpy(buf, SccsDir);
E 74
I 74
	gstrcpy(buf, SccsDir, sizeof(buf));
E 74
	if (buf[0] != '\0')
D 74
		strcat(buf, "/");
E 74
I 74
		gstrcat(buf, "/", sizeof(buf));
E 74
I 62
	if (subdir != NULL)
	{
D 74
		strcat(buf, subdir);
		strcat(buf, "/");
E 74
I 74
		gstrcat(buf, subdir, sizeof(buf));
		gstrcat(buf, "/", sizeof(buf));
E 74
	}
E 62
D 74
	strcat(buf, SccsPath);
E 74
I 74
	gstrcat(buf, SccsPath, sizeof(buf));
E 74
I 62
	bufend = &buf[strlen(buf)];
E 62
I 41

E 41
D 70
	dirfd = fopen(buf, "r");
E 70
I 70
D 79
	dirfd = opendir(buf);
E 70
E 30
	if (dirfd == NULL)
E 79
I 79
	dirp = opendir(buf);
	if (dirp == NULL)
E 79
	{
D 29
		fprintf(stderr, "Sccs: cannot open %s\n", SccsPath);
E 29
I 29
D 30
		usrerr("cannot open %s", SccsPath);
E 30
I 30
		usrerr("cannot open %s", buf);
E 30
E 29
D 32
		return;
E 32
I 32
		return (EX_NOINPUT);
E 32
	}

	/*
	**  Scan the SCCS directory looking for s. files.
I 41
	**	gotedit tells whether we have tried to clean any
	**		files that are being edited.
E 41
	*/

I 15
	gotedit = FALSE;
E 15
D 49
	while (fread(&dir, sizeof dir, 1, dirfd) != NULL)
E 49
I 49
D 70
	while (fread((char *)&dir, sizeof dir, 1, dirfd) != NULL)
E 49
	{
D 21
		if (dir.d_ino == 0 || strcmpn(dir.d_name, "s.", 2) != 0)
E 21
I 21
		if (dir.d_ino == 0 || strncmp(dir.d_name, "s.", 2) != 0)
E 70
I 70
D 79
	while (dir = readdir(dirfd)) {
E 79
I 79
	while (dir = readdir(dirp)) {
E 79
		if (strncmp(dir->d_name, "s.", 2) != 0)
E 70
E 21
			continue;
		
		/* got an s. file -- see if the p. file exists */
D 30
		strcpy(buf, SccsPath);
E 30
I 30
D 62
		strcpy(buf, SccsDir);
		if (buf[0] != '\0')
			strcat(buf, "/");
		strcat(buf, SccsPath);
E 30
		strcat(buf, "/p.");
D 14
		buf[strlen(buf) + sizeof dir.d_name - 2] = '\0';
		strcatn(buf, &dir.d_name[2], sizeof dir.d_name - 2);
E 14
I 14
		basefile = &buf[strlen(buf)];
E 62
I 62
D 74
		strcpy(bufend, "/p.");
E 74
I 74
		gstrcpy(bufend, "/p.", sizeof(buf));
E 74
		basefile = bufend + 3;
E 62
D 17
		basefile[sizeof dir.d_name - 2] = '\0';
E 17
D 21
		strcpyn(basefile, &dir.d_name[2], sizeof dir.d_name - 2);
E 21
I 21
D 70
		strncpy(basefile, &dir.d_name[2], sizeof dir.d_name - 2);
E 21
E 14
D 17
		if (stat(buf, &stbuf) >= 0)
E 17
I 17
		basefile[sizeof dir.d_name - 2] = '\0';
E 70
I 70
D 74
		strcpy(basefile, &dir->d_name[2]);
E 74
I 74
		gstrcpy(basefile, &dir->d_name[2], sizeof(buf));
E 74
E 70
I 51

		/*
		**  open and scan the p-file.
		**	'gotpfent' tells if we have found a valid p-file
		**		entry.
		*/

E 51
		pfp = fopen(buf, "r");
I 51
		gotpfent = FALSE;
E 51
		if (pfp != NULL)
E 17
I 14
		{
I 41
			/* the file exists -- report it's contents */
E 41
D 17
			printf("%s: being editted\n", basefile);
E 17
I 17
D 47
			while (fgets(pline, sizeof pline, pfp) != NULL)
D 20
				printf("%12s: being editted: %s", basefile, pline);
E 20
I 20
				printf("%12s: being edited: %s", basefile, pline);
E 47
I 47
D 51
			if (mode == TELLC)
				printf("%s\n", basefile);
			else
E 51
I 51
			while ((pf = getpfent(pfp)) != NULL)
E 51
			{
D 51
				while (fgets(pline, sizeof pline, pfp) != NULL)
					printf("%12s: being edited: %s", basefile, pline);
E 51
I 51
				if (nobranch && isbranch(pf->p_nsid))
					continue;
I 52
				if (usernm != NULL && strcmp(usernm, pf->p_user) != 0 && mode != CLEANC)
					continue;
E 52
				gotedit = TRUE;
				gotpfent = TRUE;
				if (mode == TELLC)
				{
					printf("%s\n", basefile);
					break;
				}
D 63
				printf("%12s: being edited: %s %s %s %s %s\n",
				       basefile, pf->p_osid, pf->p_nsid,
				       pf->p_user, pf->p_date, pf->p_time);
E 63
I 63
				printf("%12s: being edited: ", basefile);
				putpfent(pf, stdout);
E 63
E 51
			}
E 47
E 20
			fclose(pfp);
E 17
I 15
D 51
			gotedit = TRUE;
E 15
E 14
			continue;
E 51
I 14
		}
I 51
D 54
		if (!gotpfent)
			continue;
E 54
E 51
E 14
		
		/* the s. file exists and no p. file exists -- unlink the g-file */
D 14
		buf[sizeof dir.d_name - 2] = '\0';
		strcpyn(buf, &dir.d_name[2], sizeof dir.d_name - 2);
		unlink(buf);
E 14
I 14
D 27
		if (really)
E 27
I 27
D 54
		if (mode == CLEANC)
E 54
I 54
		if (mode == CLEANC && !gotpfent)
E 54
E 27
		{
D 21
			strcpyn(buf, &dir.d_name[2], sizeof dir.d_name - 2);
E 21
I 21
D 70
			strncpy(buf, &dir.d_name[2], sizeof dir.d_name - 2);
E 21
			buf[sizeof dir.d_name - 2] = '\0';
E 70
I 70
D 72
			strcpy(buf, &dir->d_name[2]);
E 70
			unlink(buf);
E 72
I 72
D 74
			char	unlinkbuf[100];
			strcpy(unlinkbuf, &dir->d_name[2]);
E 74
I 74
			char	unlinkbuf[FBUFSIZ];
			gstrcpy(unlinkbuf, &dir->d_name[2], sizeof(unlinkbuf));
E 74
			unlink(unlinkbuf);
E 72
		}
E 14
	}

I 41
	/* cleanup & report results */
E 41
D 70
	fclose(dirfd);
E 70
I 70
D 79
	closedir(dirfd);
E 79
I 79
	closedir(dirp);
E 79
E 70
I 15
D 27
	if (!gotedit && !really)
E 27
I 27
	if (!gotedit && mode == INFOC)
E 27
D 20
		printf("Nothing being editted\n");
E 20
I 20
D 52
		printf("Nothing being edited\n");
E 52
I 52
	{
		printf("Nothing being edited");
		if (nobranch)
			printf(" (on trunk)");
		if (usernm == NULL)
			printf("\n");
		else
			printf(" by %s\n", usernm);
	}
E 52
I 27
	if (mode == CHECKC)
		exit(gotedit);
I 32
	return (EX_OK);
E 32
E 27
E 20
I 18
}
D 37
/*
E 37
I 37

/*
I 51
**  ISBRANCH -- is the SID a branch?
**
**	Parameters:
**		sid -- the sid to check.
**
**	Returns:
**		TRUE if the sid represents a branch.
**		FALSE otherwise.
**
**	Side Effects:
**		none.
*/

isbranch(sid)
	char *sid;
{
	register char *p;
	int dots;

	dots = 0;
	for (p = sid; *p != '\0'; p++)
	{
		if (*p == '.')
			dots++;
		if (dots > 1)
			return (TRUE);
	}
	return (FALSE);
}

/*
E 51
E 37
**  UNEDIT -- unedit a file
**
**	Checks to see that the current user is actually editting
**	the file and arranges that s/he is not editting it.
**
**	Parameters:
D 20
**		fn -- the name of the file to be uneditted.
E 20
I 20
**		fn -- the name of the file to be unedited.
E 20
**
**	Returns:
D 23
**		none.
E 23
I 23
**		TRUE -- if the file was successfully unedited.
**		FALSE -- if the file was not unedited for some
**			reason.
E 23
**
**	Side Effects:
**		fn is removed
**		entries are removed from pfile.
*/

I 23
bool
E 23
unedit(fn)
	char *fn;
{
	register FILE *pfp;
D 76
	char *pfn;
E 76
I 76
	char *cp, *pfn;
E 76
	static char tfn[] = "/tmp/sccsXXXXX";
	FILE *tfp;
D 49
	register char *p;
E 49
	register char *q;
	bool delete = FALSE;
	bool others = FALSE;
	char *myname;
D 52
	extern char *getlogin();
E 52
I 52
	extern char *username();
E 52
	struct pfile *pent;
D 51
	extern struct pfile *getpfile();
E 51
I 51
	extern struct pfile *getpfent();
E 51
D 74
	char buf[120];
E 74
I 74
	char buf[PFILELG];
E 74
I 34
D 81
	extern char *makefile();
E 81
I 81
	extern char *makefile(), *rindex(), *tail();
E 81
E 34
I 28
D 52
# ifdef UIDUSER
	struct passwd *pw;
	extern struct passwd *getpwuid();
# endif UIDUSER
E 52
E 28

	/* make "s." filename & find the trailing component */
	pfn = makefile(fn);
D 24
	q = &pfn[strlen(pfn) - 1];
	while (q > pfn && *q != '/')
		q--;
	if (q <= pfn && (q[0] != 's' || q[1] != '.'))
E 24
I 24
	if (pfn == NULL)
		return (FALSE);
	q = rindex(pfn, '/');
	if (q == NULL)
		q = &pfn[-1];
	if (q[1] != 's' || q[2] != '.')
E 24
	{
D 29
		fprintf(stderr, "Sccs: bad file name \"%s\"\n", fn);
E 29
I 29
		usrerr("bad file name \"%s\"", fn);
E 29
D 23
		return;
E 23
I 23
		return (FALSE);
E 23
	}

D 41
	/* turn "s." into "p." */
E 41
I 41
	/* turn "s." into "p." & try to open it */
E 41
	*++q = 'p';

	pfp = fopen(pfn, "r");
	if (pfp == NULL)
	{
D 20
		printf("%12s: not being editted\n", fn);
E 20
I 20
		printf("%12s: not being edited\n", fn);
E 20
D 23
		return;
E 23
I 23
		return (FALSE);
E 23
	}

D 41
	/*
	**  Copy p-file to temp file, doing deletions as needed.
	*/

E 41
I 41
	/* create temp file for editing p-file */
E 41
	mktemp(tfn);
	tfp = fopen(tfn, "w");
	if (tfp == NULL)
	{
D 29
		fprintf(stderr, "Sccs: cannot create \"%s\"\n", tfn);
E 29
I 29
		usrerr("cannot create \"%s\"", tfn);
E 29
		exit(EX_OSERR);
	}

I 41
	/* figure out who I am */
E 41
I 28
D 52
# ifdef UIDUSER
	pw = getpwuid(getuid());
	if (pw == NULL)
	{
D 29
		fprintf(stderr, "Sccs: who are you?\n");
E 29
I 29
		syserr("who are you? (uid=%d)", getuid());
E 29
		exit(EX_OSERR);
	}
	myname = pw->pw_name;
# else
E 28
	myname = getlogin();
I 28
# endif UIDUSER
E 52
I 52
	myname = username();
E 52
I 41

	/*
	**  Copy p-file to temp file, doing deletions as needed.
	*/

E 41
E 28
D 51
	while ((pent = getpfile(pfp)) != NULL)
E 51
I 51
	while ((pent = getpfent(pfp)) != NULL)
E 51
	{
		if (strcmp(pent->p_user, myname) == 0)
		{
			/* a match */
			delete++;
		}
		else
		{
I 41
			/* output it again */
E 41
D 63
			fprintf(tfp, "%s %s %s %s %s\n", pent->p_osid,
			    pent->p_nsid, pent->p_user, pent->p_date,
			    pent->p_time);
E 63
I 63
			putpfent(pent, tfp);
E 63
			others++;
		}
	}

I 76
	/*
	 * Before changing anything, make sure we can remove
	 * the file in question (assuming it exists).
	 */
	if (delete) {
		extern int errno;

		cp = tail(fn);
		errno = 0;
		if (access(cp, 0) < 0 && errno != ENOENT)
			goto bad;
		if (errno == 0)
			/*
			 * This is wrong, but the rest of the program
			 * has built in assumptions about "." as well,
			 * so why make unedit a special case?
			 */
			if (access(".", 2) < 0) {
	bad:
				printf("%12s: can't remove\n", cp);
				fclose(tfp);
				fclose(pfp);
				unlink(tfn);
				return (FALSE);
			}
	}
E 76
	/* do final cleanup */
	if (others)
	{
I 41
		/* copy it back (perhaps it should be linked?) */
E 41
		if (freopen(tfn, "r", tfp) == NULL)
		{
D 29
			fprintf(stderr, "Sccs: cannot reopen \"%s\"\n", tfn);
E 29
I 29
			syserr("cannot reopen \"%s\"", tfn);
E 29
			exit(EX_OSERR);
		}
		if (freopen(pfn, "w", pfp) == NULL)
		{
D 29
			fprintf(stderr, "Sccs: cannot create \"%s\"\n", pfn);
E 29
I 29
			usrerr("cannot create \"%s\"", pfn);
E 29
D 23
			return;
E 23
I 23
			return (FALSE);
E 23
		}
		while (fgets(buf, sizeof buf, tfp) != NULL)
			fputs(buf, pfp);
	}
	else
	{
I 41
		/* it's empty -- remove it */
E 41
		unlink(pfn);
	}
	fclose(tfp);
	fclose(pfp);
	unlink(tfn);

I 41
	/* actually remove the g-file */
E 41
	if (delete)
	{
D 39
		unlink(fn);
		printf("%12s: removed\n", fn);
E 39
I 39
D 76
		unlink(tail(fn));
		printf("%12s: removed\n", tail(fn));
E 76
I 76
		/*
		 * Since we've checked above, we can
		 * use the return from unlink to
		 * determine if the file existed or not.
		 */
		if (unlink(cp) >= 0)
			printf("%12s: removed\n", cp);
E 76
E 39
I 23
		return (TRUE);
E 23
	}
	else
	{
D 20
		printf("%12s: not being editted by you\n", fn);
E 20
I 20
		printf("%12s: not being edited by you\n", fn);
I 23
		return (FALSE);
E 23
E 20
	}
I 38
}

/*
**  DODIFF -- diff an s-file against a g-file
**
**	Parameters:
**		getv -- argv for the 'get' command.
**		gfile -- name of the g-file to diff against.
**
**	Returns:
**		Result of get.
**
**	Side Effects:
**		none.
*/

dodiff(getv, gfile)
	char **getv;
	char *gfile;
{
	int pipev[2];
	int rval;
	register int i;
	register int pid;
	auto int st;
	extern int errno;
	int (*osig)();
I 56
	register char *p;
	register char **ap;
	bool makescript = FALSE;
E 56

I 42
D 56
	printf("\n------- %s -------\n", gfile);
E 56
I 56
	for (ap = getv; *ap != NULL; ap++)
	{
		p = *ap;
		if (p[0] == '-')
		{
			switch (p[1])
			{
			  case 'E':
				p[1] = 'e';
				makescript = TRUE;
				break;
			}
		}
	}

	if (makescript)
	{
		printf("sccs edit %s\n", gfile);
		printf("ed - %s << 'xxEOFxx'\n", gfile);
	}
	else
		printf("\n------- %s -------\n", gfile);
E 56
I 55
	fflush(stdout);
E 55

E 42
I 41
	/* create context for diff to run in */
E 41
	if (pipe(pipev) < 0)
	{
		syserr("dodiff: pipe failed");
		exit(EX_OSERR);
	}
	if ((pid = fork()) < 0)
	{
		syserr("dodiff: fork failed");
		exit(EX_OSERR);
	}
	else if (pid > 0)
	{
		/* in parent; run get */
		OutFile = pipev[1];
		close(pipev[0]);
D 48
		rval = command(&getv[1], TRUE, FALSE, "get -s -k -p");
E 48
I 48
D 55
		rval = command(&getv[1], TRUE, "get -s -k -p");
E 55
I 55
		rval = command(&getv[1], TRUE, "get:rcixt -s -k -p");
E 55
E 48
		osig = signal(SIGINT, SIG_IGN);
		while (((i = wait(&st)) >= 0 && i != pid) || errno == EINTR)
			errno = 0;
		signal(SIGINT, osig);
		/* ignore result of diff */
	}
	else
	{
		/* in child, run diff */
		if (close(pipev[1]) < 0 || close(0) < 0 ||
		    dup(pipev[0]) != 0 || close(pipev[0]) < 0)
		{
			syserr("dodiff: magic failed");
			exit(EX_OSERR);
		}
D 55
		execl(PROGPATH(bdiff), "bdiff", "-", gfile, NULL);
# ifndef V6
		execlp("bdiff", "bdiff", "-", gfile, NULL);
		execlp("diff", "diff", "-", gfile, NULL);
# endif NOT V6
		syserr("bdiff: cannot execute");
		exit(EX_OSERR);
E 55
I 55
		command(&getv[1], FALSE, "-diff:elsfhbC");
E 55
	}
I 56

	if (makescript)
	{
		printf("w\n");
		printf("q\n");
		printf("'xxEOFxx'\n");
		printf("sccs delta %s\n", gfile);
	}

E 56
	return (rval);
I 39
}

/*
**  TAIL -- return tail of filename.
**
**	Parameters:
**		fn -- the filename.
**
**	Returns:
**		a pointer to the tail of the filename; e.g., given
**		"cmd/ls.c", "ls.c" is returned.
**
**	Side Effects:
**		none.
*/

char *
tail(fn)
	register char *fn;
{
	register char *p;

	for (p = fn; *p != 0; p++)
		if (*p == '/' && p[1] != '\0' && p[1] != '/')
			fn = &p[1];
	return (fn);
E 39
E 38
}
D 37
/*
E 37
I 37

/*
E 37
D 51
**  GETPFILE -- get an entry from the p-file
E 51
I 51
**  GETPFENT -- get an entry from the p-file
E 51
**
**	Parameters:
**		pfp -- p-file file pointer
**
**	Returns:
**		pointer to p-file struct for next entry
**		NULL on EOF or error
**
**	Side Effects:
**		Each call wipes out results of previous call.
*/

struct pfile *
D 51
getpfile(pfp)
E 51
I 51
getpfent(pfp)
E 51
	FILE *pfp;
{
	static struct pfile ent;
D 74
	static char buf[120];
E 74
I 74
	static char buf[PFILELG];
E 74
	register char *p;
	extern char *nextfield();

	if (fgets(buf, sizeof buf, pfp) == NULL)
		return (NULL);

	ent.p_osid = p = buf;
	ent.p_nsid = p = nextfield(p);
	ent.p_user = p = nextfield(p);
	ent.p_date = p = nextfield(p);
	ent.p_time = p = nextfield(p);
D 63
	if (p == NULL || nextfield(p) != NULL)
		return (NULL);
E 63
I 63
	ent.p_aux = p = nextfield(p);
E 63

	return (&ent);
}


char *
nextfield(p)
	register char *p;
{
	if (p == NULL || *p == '\0')
		return (NULL);
	while (*p != ' ' && *p != '\n' && *p != '\0')
		p++;
	if (*p == '\n' || *p == '\0')
	{
		*p = '\0';
		return (NULL);
	}
	*p++ = '\0';
	return (p);
I 63
}
/*
**  PUTPFENT -- output a p-file entry to a file
**
**	Parameters:
**		pf -- the p-file entry
**		f -- the file to put it on.
**
**	Returns:
**		none.
**
**	Side Effects:
**		pf is written onto file f.
*/

putpfent(pf, f)
	register struct pfile *pf;
	register FILE *f;
{
	fprintf(f, "%s %s %s %s %s", pf->p_osid, pf->p_nsid,
		pf->p_user, pf->p_date, pf->p_time);
	if (pf->p_aux != NULL)
		fprintf(f, " %s", pf->p_aux);
	else
		fprintf(f, "\n");
E 63
I 29
}
D 37
/*
E 37
I 37

/*
E 37
**  USRERR -- issue user-level error
**
**	Parameters:
**		f -- format string.
**		p1-p3 -- parameters to a printf.
**
**	Returns:
**		-1
**
**	Side Effects:
**		none.
*/

I 49
/*VARARGS1*/
E 49
usrerr(f, p1, p2, p3)
	char *f;
{
	fprintf(stderr, "\n%s: ", MyName);
	fprintf(stderr, f, p1, p2, p3);
	fprintf(stderr, "\n");

	return (-1);
}
D 37
/*
E 37
I 37

/*
E 37
**  SYSERR -- print system-generated error.
**
**	Parameters:
**		f -- format string to a printf.
**		p1, p2, p3 -- parameters to f.
**
**	Returns:
**		never.
**
**	Side Effects:
**		none.
*/

I 49
/*VARARGS1*/
E 49
syserr(f, p1, p2, p3)
	char *f;
{
	extern int errno;

	fprintf(stderr, "\n%s SYSERR: ", MyName);
	fprintf(stderr, f, p1, p2, p3);
	fprintf(stderr, "\n");
	if (errno == 0)
		exit(EX_SOFTWARE);
	else
	{
D 49
		perror(0);
E 49
I 49
		perror(NULL);
E 49
		exit(EX_OSERR);
	}
I 52
}
/*
**  USERNAME -- return name of the current user
**
**	Parameters:
**		none
**
**	Returns:
**		name of current user
**
**	Side Effects:
**		none
*/

char *
username()
{
# ifdef UIDUSER
	extern struct passwd *getpwuid();
	register struct passwd *pw;

	pw = getpwuid(getuid());
	if (pw == NULL)
	{
		syserr("who are you? (uid=%d)", getuid());
		exit(EX_OSERR);
	}
	return (pw->pw_name);
# else
I 57
	extern char *getlogin();
I 66
D 81
	extern char *getenv();
E 81
	register char *p;
E 66

E 57
D 66
	return (getlogin());
E 66
I 66
	p = getenv("USER");
	if (p == NULL || p[0] == '\0')
		p = getlogin();
	return (p);
E 66
# endif UIDUSER
I 74
}

/*
**	Guarded string manipulation routines; the last argument
**	is the length of the buffer into which the strcpy or strcat
**	is to be done.
*/
char *gstrcat(to, from, length)
	char	*to, *from;
	int	length;
{
	if (strlen(from) + strlen(to) >= length) {
		gstrbotch(to, from);
	}
	return(strcat(to, from));
}

char *gstrncat(to, from, n, length)
	char	*to, *from;
	int	n;
	int	length;
{
	if (n + strlen(to) >= length) {
		gstrbotch(to, from);
	}
	return(strncat(to, from, n));
}

char *gstrcpy(to, from, length)
	char	*to, *from;
	int	length;
{
	if (strlen(from) >= length) {
		gstrbotch(from, (char *)0);
	}
	return(strcpy(to, from));
}
gstrbotch(str1, str2)
	char	*str1, *str2;
{
	usrerr("Filename(s) too long: %s %s", str1, str2);
E 74
E 52
E 29
E 18
E 15
}
E 11
D 7

E 7
E 1
