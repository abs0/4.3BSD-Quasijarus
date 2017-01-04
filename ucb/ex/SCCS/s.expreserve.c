h26345
s 00019/00018/00382
d D 7.14 03/04/13 15:19:41 msokolov 22 21
c 8-bit ex
e
s 00001/00000/00399
d D 7.13 86/01/22 11:23:32 bloom 21 20
c add file name (LOST) to the mailed message properly
e
s 00002/00002/00397
d D 7.12 85/06/07 18:25:51 bloom 20 19
c fix sccsid and copyright for xstr
e
s 00016/00002/00383
d D 7.11 85/05/31 15:19:18 dist 19 18
c Add copyright
e
s 00001/00000/00384
d D 7.10 84/12/05 09:56:46 ralph 18 17
c do setuid(getuid)) before popen to close security hole.
e
s 00039/00017/00345
d D 7.9 84/02/14 21:35:19 rrh 17 16
c add subject line, better description of what happened 
c and how to recover; fix English
e
s 00001/00001/00361
d D 7.8 83/08/14 22:43:56 mckusick 16 15
c close those security holes! (kre)
e
s 00006/00010/00356
d D 7.7 83/07/03 22:53:48 sam 15 13
c 
e
s 00006/00010/00356
d R 7.7 83/07/02 23:27:29 sam 14 13
c purge local/uparm.h; fix from sun for expreserve
e
s 00009/00010/00357
d D 7.6 83/06/10 10:08:19 ralph 13 12
c updating sccs files due to restoring an older SCCS directory
e
s 00001/00001/00366
d D 7.5 81/08/02 08:55:46 mark 12 11
c fix for portability on systems with big uids.  THIS CHANGES TEMP
c FILE FORMAT SO EXPRESERVE/RECOVER MUST BE UPDATED AT SAME TIME.
e
s 00000/00000/00367
d D 7.4 81/07/26 20:05:27 mark 11 10
c fixes for 3b
e
s 00002/00000/00365
d D 7.3 81/07/11 02:02:41 mark 10 9
c fixed non VMUNIX botch in HBLKS
e
s 00008/00007/00357
d D 7.2 81/07/09 23:08:35 mark 9 8
c fixed stuff broken by mjm
e
s 00007/00007/00357
d D 7.1 81/07/08 22:36:18 mark 8 7
c release 3.7 - a few bug fixes and a few new features.
e
s 00009/00004/00355
d D 6.1 80/10/19 01:23:07 mark 7 6
c preliminary release 3.6 10/18/80
e
s 00000/00000/00359
d D 5.1 80/08/20 16:16:43 mark 6 5
c Release 3.5, August 20, 1980
e
s 00002/00001/00357
d D 4.2 80/08/01 20:44:38 mark 5 4
c Bill added more buffers, and I put in sccs.
e
s 00000/00000/00358
d D 4.1 80/08/01 00:20:24 mark 4 3
c release 3.4, June 24, 1980
e
s 00000/00000/00358
d D 3.1 80/07/31 23:45:41 mark 3 2
c release 3.3, Feb 2, 1980
e
s 00015/00001/00343
d D 2.1 80/07/31 23:22:16 mark 2 1
c release 3.2, Jan 4, 1980
e
s 00344/00000/00000
d D 1.1 80/07/31 23:01:06 mark 1 0
c date and time created 80/07/31 23:01:06 by mark
e
u
U
t
T
I 1
D 5
/* Copyright (c) 1979 Regents of the University of California */
E 5
I 5
D 8
/* Copyright (c) 1980 Regents of the University of California */
static char *sccsid = "%W% %G%";
E 8
I 8
D 19
/* Copyright (c) 1981 Regents of the University of California */
static char *sccsid = "%W%	%G%";
E 19
I 19
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
D 20
char copyright[] =
E 20
I 20
char *copyright =
E 20
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
D 20
static char sccsid[] = "%W% (Berkeley) %G%";
E 20
I 20
static char *sccsid = "%W% (Berkeley) %G%";
E 20
#endif not lint

E 19
E 8
E 5
#include <stdio.h>
#include <ctype.h>
D 13
#include <sys/types.h>
E 13
I 13
#include <sys/param.h>
E 13
#include <sys/stat.h>
#include <sys/dir.h>
#include <pwd.h>
D 15
#include "local/uparm.h"
I 8
				/* mjm: "/tmp" --> TMP */
E 15
I 15
#include "uparm.h"

E 15
D 9
#define TMP	"/3b/tmp"
E 9
I 9
#define TMP	"/tmp"
E 9
E 8

I 2
#ifdef VMUNIX
#define	HBLKS	2
I 10
#else
#define HBLKS	1
E 10
D 8
#else
#define	HBLKS	1
E 8
#endif

I 9
D 22
char xstr[1];			/* make loader happy */
E 22
I 22
u_char xstr[1];			/* make loader happy */
E 22

E 9
E 2
/*
 * Expreserve - preserve a file in usrpath(preserve)
 * Bill Joy UCB November 13, 1977
 *
 * This routine is very naive - it doesn't remove anything from
D 9
 * usrpath(preserve)... this may mean that we will be unable to preserve
 * stuff there... the danger in doing anything with usrpath(preserve)
E 9
I 9
D 15
 * usrpath(preserve)... this may mean that we  * stuff there... the danger in doing anything with usrpath(preserve)
E 15
I 15
 * usrpath(preserve)... this may mean that we leave
 * stuff there... the danger in doing anything with usrpath(preserve)
E 15
E 9
 * is that the clock may be screwed up and we may get confused.
 *
 * We are called in two ways - first from the editor with no argumentss
 * and the standard input open on the temp file. Second with an argument
 * to preserve the entire contents of /tmp (root only).
 *
 * BUG: should do something about preserving Rx... (register contents)
 *      temporaries.
 */

I 2
#ifndef VMUNIX
E 2
#define	LBLKS	125
I 2
#else
#define	LBLKS	900
#endif
E 2
#define	FNSIZE	128

struct 	header {
	time_t	Time;			/* Time temp file last updated */
D 12
	short	Uid;			/* This users identity */
E 12
I 12
	int	Uid;			/* This users identity */
E 12
I 2
#ifndef VMUNIX
E 2
	short	Flines;			/* Number of lines in file */
I 2
#else
	int	Flines;
#endif
E 2
D 22
	char	Savedfile[FNSIZE];	/* The current file name */
E 22
I 22
	u_char	Savedfile[FNSIZE];	/* The current file name */
E 22
	short	Blocks[LBLKS];		/* Blocks where line pointers stashed */
} H;

#ifdef	lint
#define	ignore(a)	Ignore(a)
#define	ignorl(a)	Ignorl(a)
#else
#define	ignore(a)	a
#define	ignorl(a)	a
#endif

struct	passwd *getpwuid();
off_t	lseek();
FILE	*popen();

#define eq(a, b) strcmp(a, b) == 0

main(argc)
	int argc;
{
D 13
	register FILE *tf;
	struct direct dirent;
E 13
I 13
	register DIR *tf;
	struct direct *dirent;
E 13
	struct stat stbuf;

	/*
	 * If only one argument, then preserve the standard input.
	 */
	if (argc == 1) {
D 22
		if (copyout((char *) 0))
E 22
I 22
		if (copyout((u_char *) 0))
E 22
			exit(1);
		exit(0);
	}

	/*
	 * If not super user, then can only preserve standard input.
	 */
	if (getuid()) {
		fprintf(stderr, "NOT super user\n");
		exit(1);
	}

	/*
	 * ... else preserve all the stuff in /tmp, removing
	 * it as we go.
	 */
D 9
	if (chdir("/tmp") < 0) {
		perror("/tmp");
E 9
D 8
		exit(1);
	}
E 8
I 8
	if (chdir(TMP) < 0) {
		perror(TMP);
I 9
		exit(1);
	}
E 9
E 8

D 13
	tf = fopen(".", "r");
E 13
I 13
	tf = opendir(".");
E 13
	if (tf == NULL) {
D 9
		perror("/tmp");
		exit(1);
E 9
D 8
	}
E 8
I 8
		perror(TMP);
I 9
		exit(1);
	}
E 9
E 8
D 13
	while (fread((char *) &dirent, sizeof dirent, 1, tf) == 1) {
		if (dirent.d_ino == 0)
			continue;
E 13
I 13
	while ((dirent = readdir(tf)) != NULL) {
E 13
D 15
		/*
		 * Ex temporaries must begin with Ex;
		 * we check that the 10th character of the name is null
		 * so we won't have to worry about non-null terminated names
		 * later on.
		 */
D 13
		if (dirent.d_name[0] != 'E' || dirent.d_name[1] != 'x' || dirent.d_name[10])
E 13
I 13
		if (dirent->d_name[0] != 'E' || dirent->d_name[1] != 'x' || dirent->d_name[10])
E 15
I 15
		/* Ex temporaries must begin with Ex. */
		if (dirent->d_name[0] != 'E' || dirent->d_name[1] != 'x')
E 15
E 13
			continue;
D 13
		if (stat(dirent.d_name, &stbuf))
E 13
I 13
		if (stat(dirent->d_name, &stbuf))
E 13
			continue;
		if ((stbuf.st_mode & S_IFMT) != S_IFREG)
			continue;
		/*
		 * Save the bastard.
		 */
D 13
		ignore(copyout(dirent.d_name));
E 13
I 13
		ignore(copyout(dirent->d_name));
E 13
	}
I 13
	closedir(tf);
E 13
	exit(0);
}

D 22
char	pattern[] =	usrpath(preserve/Exaa`XXXXX);
E 22
I 22
u_char	pattern[] =	usrpath(preserve/Exaa`XXXXX);
E 22

/*
 * Copy file name into usrpath(preserve)/...
D 22
 * If name is (char *) 0, then do the standard input.
E 22
I 22
 * If name is (u_char *) 0, then do the standard input.
E 22
 * We make some checks on the input to make sure it is
 * really an editor temporary, generate a name for the
 * file (this is the slowest thing since we must stat
 * to find a unique name), and finally copy the file.
 */
copyout(name)
D 22
	char *name;
E 22
I 22
	u_char *name;
E 22
{
	int i;
	static int reenter;
D 22
	char buf[BUFSIZ];
E 22
I 22
	u_char buf[BUFSIZ];
E 22

	/*
	 * The first time we put in the digits of our
	 * process number at the end of the pattern.
	 */
	if (reenter == 0) {
		mkdigits(pattern);
		reenter++;
	}

	/*
	 * If a file name was given, make it the standard
	 * input if possible.
	 */
	if (name != 0) {
		ignore(close(0));
		/*
		 * Need read/write access for arcane reasons
		 * (see below).
		 */
		if (open(name, 2) < 0)
			return (-1);
	}

	/*
	 * Get the header block.
	 */
	ignorl(lseek(0, 0l, 0));
D 22
	if (read(0, (char *) &H, sizeof H) != sizeof H) {
E 22
I 22
	if (read(0, (u_char *) &H, sizeof H) != sizeof H) {
E 22
format:
		if (name == 0)
D 7
			fprintf(stderr, "Buffer format error\n");
E 7
I 7
			fprintf(stderr, "Buffer format error\t");
E 7
		return (-1);
	}

	/*
	 * Consistency checsks so we don't copy out garbage.
	 */
	if (H.Flines < 0) {
#ifdef DEBUG
		fprintf(stderr, "Negative number of lines\n");
#endif
		goto format;
	}
D 2
	if (H.Blocks[0] != 1 || H.Blocks[1] != 2) {
E 2
I 2
	if (H.Blocks[0] != HBLKS || H.Blocks[1] != HBLKS+1) {
E 2
#ifdef DEBUG
		fprintf(stderr, "Blocks %d %d\n", H.Blocks[0], H.Blocks[1]);
#endif
		goto format;
	}
	if (name == 0 && H.Uid != getuid()) {
#ifdef DEBUG
		fprintf(stderr, "Wrong user-id\n");
#endif
		goto format;
	}
	if (lseek(0, 0l, 0)) {
#ifdef DEBUG
		fprintf(stderr, "Negative number of lines\n");
#endif
		goto format;
	}

	/*
	 * If no name was assigned to the file, then give it the name
	 * LOST, by putting this in the header.
	 */
	if (H.Savedfile[0] == 0) {
		strcpy(H.Savedfile, "LOST");
D 22
		ignore(write(0, (char *) &H, sizeof H));
E 22
I 22
		ignore(write(0, (u_char *) &H, sizeof H));
E 22
		H.Savedfile[0] = 0;
		lseek(0, 0l, 0);
	}

	/*
	 * File is good.  Get a name and create a file for the copy.
	 */
	mknext(pattern);
	ignore(close(1));
	if (creat(pattern, 0600) < 0) {
		if (name == 0)
			perror(pattern);
		return (1);
	}

	/*
	 * Make the target be owned by the owner of the file.
	 */
	ignore(chown(pattern, H.Uid, 0));

	/*
	 * Copy the file.
	 */
	for (;;) {
		i = read(0, buf, BUFSIZ);
		if (i < 0) {
			if (name)
				perror("Buffer read error");
			ignore(unlink(pattern));
			return (-1);
		}
		if (i == 0) {
			if (name)
				ignore(unlink(name));
D 17
			notify(H.Uid, H.Savedfile, (int) name);
E 17
I 17
			notify(H.Uid, H.Savedfile, (int) name, H.Time);
E 17
			return (0);
		}
		if (write(1, buf, i) != i) {
			if (name == 0)
				perror(pattern);
			unlink(pattern);
			return (-1);
		}
	}
}

/*
 * Blast the last 5 characters of cp to be the process number.
 */
mkdigits(cp)
D 22
	char *cp;
E 22
I 22
	u_char *cp;
E 22
{
	register int i, j;

	for (i = getpid(), j = 5, cp += strlen(cp); j > 0; i /= 10, j--)
		*--cp = i % 10 | '0';
}

/*
 * Make the name in cp be unique by clobbering up to
 * three alphabetic characters into a sequence of the form 'aab', 'aac', etc.
 * Mktemp gets weird names too quickly to be useful here.
 */
mknext(cp)
D 22
	char *cp;
E 22
I 22
	u_char *cp;
E 22
{
D 22
	char *dcp;
E 22
I 22
	u_char *dcp;
E 22
	struct stat stb;

	dcp = cp + strlen(cp) - 1;
	while (isdigit(*dcp))
		dcp--;
whoops:
	if (dcp[0] == 'z') {
		dcp[0] = 'a';
		if (dcp[-1] == 'z') {
			dcp[-1] = 'a';
			if (dcp[-2] == 'z')
D 7
				fprintf(stderr, "Can't find a name\n");
E 7
I 7
				fprintf(stderr, "Can't find a name\t");
E 7
			dcp[-2]++;
		} else
			dcp[-1]++;
	} else
		dcp[0]++;
	if (stat(cp, &stb) == 0)
		goto whoops;
}

/*
 * Notify user uid that his file fname has been saved.
 */
D 17
notify(uid, fname, flag)
E 17
I 17
notify(uid, fname, flag, time)
E 17
	int uid;
D 22
	char *fname;
E 22
I 22
	u_char *fname;
E 22
I 17
	time_t	time;
E 17
{
	struct passwd *pp = getpwuid(uid);
	register FILE *mf;
D 17
	char cmd[BUFSIZ];
E 17
I 17
D 22
	char	cmd[BUFSIZ];
	char	hostname[128];
	char	croak[128];
	char	*timestamp, *ctime();
E 22
I 22
	u_char	cmd[BUFSIZ];
	u_char	hostname[128];
	u_char	croak[128];
	u_char	*timestamp;
	char	*ctime();
E 22
E 17

	if (pp == NULL)
		return;
I 17
	gethostname(hostname, sizeof(hostname));
D 22
	timestamp = ctime(&time);
E 22
I 22
	timestamp = (u_char *) ctime(&time);
E 22
	timestamp[16] = 0;	/* blast from seconds on */
E 17
D 16
	sprintf(cmd, "mail %s", pp->pw_name);
E 16
I 16
	sprintf(cmd, "/bin/mail %s", pp->pw_name);
I 18
	setuid(getuid());
E 18
E 16
	mf = popen(cmd, "w");
	if (mf == NULL)
		return;
	setbuf(mf, cmd);
I 17
	/*
	 *	flag says how the editor croaked:
	 * "the editor was killed" is perhaps still not an ideal
	 * error message.  Usually, either it was forcably terminated
	 * or the phone was hung up, but we don't know which.
	 */
	sprintf(croak, flag
		? "the system went down"
		: "the editor was killed");
E 17
	if (fname[0] == 0) {
I 21
		fname = "LOST";
E 21
		fprintf(mf,
D 17
"A copy of an editor buffer of yours was saved when %s.\n",
D 7
		flag ? "the system went down" : "your phone was hung up");
E 7
I 7
		flag ? "the system went down" : "the editor was killed");
E 17
I 17
"Subject: editor saved ``LOST''\n");
E 17
E 7
		fprintf(mf,
D 17
"No name was associated with this buffer so it has been named \"LOST\".\n");
	} else
E 17
I 17
"You were editing a file without a name\n");
E 17
		fprintf(mf,
D 17
"A copy of an editor buffer of your file \"%s\"\nwas saved when %s.\n", fname,
D 7
		flag ? "the system went down" : "your phone was hung up");
E 7
I 7
		/*
		 * "the editor was killed" is perhaps still not an ideal
		 * error message.  Usually, either it was forcably terminated
		 * or the phone was hung up, but we don't know which.
		 */
		flag ? "the system went down" : "the editor was killed");
E 17
I 17
"at <%s> on the machine ``%s'' when %s.\n", timestamp, hostname, croak);
		fprintf(mf,
"Since the file had no name, it has been named \"LOST\".\n");
	} else {
		fprintf(mf,
"Subject: editor saved ``%s''\n", fname);
		fprintf(mf,
"You were editing the file \"%s\"\n", fname);
		fprintf(mf,
"at <%s> on the machine ``%s''\n", timestamp, hostname);
		fprintf(mf,
"when %s.\n", croak);
	}
E 17
E 7
	fprintf(mf,
D 17
"This buffer can be retrieved using the \"recover\" command of the editor.\n");
E 17
I 17
"\nYou can retrieve most of your changes to this file\n");
E 17
	fprintf(mf,
D 17
"An easy way to do this is to give the command \"ex -r %s\".\n",fname);
E 17
I 17
"using the \"recover\" command of the editor.\n");
E 17
	fprintf(mf,
D 17
"This works for \"edit\" and \"vi\" also.\n");
E 17
I 17
"An easy way to do this is to give the command \"vi -r %s\".\n", fname);
	fprintf(mf,
"This method also works using \"ex\" and \"edit\".\n");
E 17
	pclose(mf);
}

/*
 *	people making love
 *	never exactly the same
 *	just like a snowflake 
 */

#ifdef lint
Ignore(a)
	int a;
{

	a = a;
}

Ignorl(a)
	long a;
{

	a = a;
}
#endif
E 1
