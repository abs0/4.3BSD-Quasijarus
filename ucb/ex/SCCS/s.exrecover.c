h23549
s 00031/00031/00757
d D 7.10 03/04/13 15:19:43 msokolov 18 17
c 8-bit ex
e
s 00002/00002/00786
d D 7.9 85/06/07 18:26:09 bloom 17 16
c fix sccsid and copyright for xstr
e
s 00016/00002/00772
d D 7.8 85/05/31 15:20:05 dist 16 15
c Add copyright
e
s 00017/00000/00757
d D 7.7 85/03/19 19:27:56 mckusick 15 14
c eliminate use of stdio as it uses malloc while exrecover uses sbrk
e
s 00001/00001/00756
d D 7.6 83/07/03 22:54:05 sam 14 12
c 
e
s 00001/00002/00755
d R 7.6 83/07/03 22:39:57 sam 13 12
c no more local/uparm.h
e
s 00019/00024/00738
d D 7.5 83/06/10 10:08:45 ralph 12 11
c updating sccs files due to restoring an older SCCS directory
e
s 00001/00001/00761
d D 7.4 81/10/16 08:31:13 mark 11 10
c last minute fixes before release of 3.7
e
s 00002/00001/00760
d D 7.3 81/10/16 08:26:53 mark 10 9
c stuff to make loader work on 3b
e
s 00004/00005/00757
d D 7.2 81/07/09 23:08:40 mark 9 8
c fixed stuff broken by mjm
e
s 00011/00012/00751
d D 7.1 81/07/08 22:36:25 mark 8 7
c release 3.7 - a few bug fixes and a few new features.
e
s 00000/00000/00763
d D 6.1 80/10/19 01:23:11 mark 7 6
c preliminary release 3.6 10/18/80
e
s 00000/00000/00763
d D 5.1 80/08/20 16:16:58 mark 6 5
c Release 3.5, August 20, 1980
e
s 00002/00001/00761
d D 4.2 80/08/01 20:44:44 mark 5 4
c Bill added more buffers, and I put in sccs.
e
s 00005/00000/00757
d D 4.1 80/08/01 00:20:35 mark 4 3
c release 3.4, June 24, 1980
e
s 00000/00000/00757
d D 3.1 80/07/31 23:45:58 mark 3 2
c release 3.3, Feb 2, 1980
e
s 00004/00004/00753
d D 2.1 80/07/31 23:22:26 mark 2 1
c release 3.2, Jan 4, 1980
e
s 00757/00000/00000
d D 1.1 80/07/31 23:01:08 mark 1 0
c date and time created 80/07/31 23:01:08 by mark
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
D 16
/* Copyright (c) 1981 Regents of the University of California */
static char *sccsid = "%W%	%G%";
E 16
I 16
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
D 17
char copyright[] =
E 17
I 17
char *copyright =
E 17
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
D 17
static char sccsid[] = "%W% (Berkeley) %G%";
E 17
I 17
static char *sccsid = "%W% (Berkeley) %G%";
E 17
#endif not lint

E 16
#include <stdio.h>	/* mjm: BUFSIZ: stdio = 512, VMUNIX = 1024 */
#undef	BUFSIZ		/* mjm: BUFSIZ different */
#undef	EOF		/* mjm: EOF and NULL effectively the same */
#undef	NULL
I 9

E 9
E 8
E 5
#include "ex.h"
#include "ex_temp.h"
#include "ex_tty.h"
D 14
#include "local/uparm.h"
E 14
I 9
D 12
#include "sys/dir.h"
E 12
I 12
#include <sys/dir.h>
I 14
#include "uparm.h"
E 14
E 12
E 9

D 8
#undef	BUFSIZ
#undef	EOF
#undef	NULL
E 8
I 8
D 9
/* #undef	BUFSIZ		mjm: move to before ex.h */
/* #undef	EOF		mjm: move to before ex.h */
/* #undef	NULL		mjm: move to before ex.h */
E 9
I 9
D 10
char xstr[1];	/* make loader happy */
E 10
I 10
D 18
char xstr[1];		/* make loader happy */
E 18
I 18
u_char xstr[1];		/* make loader happy */
E 18
short tfile = -1;	/* ditto */
E 10
E 9
E 8

D 8
#include <stdio.h>
E 8
I 8
D 9
/* #include <stdio.h>		mjm: move to before ex.h */
E 8
#include <sys/dir.h>
E 9
I 9
/*
E 9
D 8

/*
 * Ex recovery program
 *	exrecover dir name
 *	exrecover -r
E 8
 *
 * This program searches through the specified directory and then
 * the directory usrpath(preserve) looking for an instance of the specified
 * file from a crashed editor or a crashed system.
 * If this file is found, it is unscrambled and written to
 * the standard output.
 *
 * If this program terminates without a "broken pipe" diagnostic
 * (i.e. the editor doesn't die right away) then the buffer we are
 * writing from is removed when we finish.  This is potentially a mistake
 * as there is not enough handshaking to guarantee that the file has actually
 * been recovered, but should suffice for most cases.
 */

/*
 * For lint's sake...
 */
#ifndef lint
#define	ignorl(a)	a
#endif

/*
 * This directory definition also appears (obviously) in expreserve.c.
 * Change both if you change either.
 */
D 18
char	mydir[] =	usrpath(preserve);
E 18
I 18
u_char	mydir[] =	usrpath(preserve);
E 18

/*
 * Limit on the number of printed entries
 * when an, e.g. ``ex -r'' command is given.
 */
#define	NENTRY	50

char	*ctime();
D 18
char	nb[BUFSIZ];
E 18
I 18
u_char	nb[BUFSIZ];
E 18
int	vercnt;			/* Count number of versions of file found */

main(argc, argv)
	int argc;
D 18
	char *argv[];
E 18
I 18
	u_char *argv[];
E 18
{
D 18
	register char *cp;
E 18
I 18
	register u_char *cp;
E 18
	register int b, i;

	/*
	 * Initialize as though the editor had just started.
	 */
	fendcore = (line *) sbrk(0);
	dot = zero = dol = fendcore;
	one = zero + 1;
	endcore = fendcore - 2;
	iblock = oblock = -1;

	/*
	 * If given only a -r argument, then list the saved files.
	 */
	if (argc == 2 && eq(argv[1], "-r")) {
		listfiles(mydir);
		exit(0);
	}
	if (argc != 3)
		error(" Wrong number of arguments to exrecover", 0);

	CP(file, argv[2]);

	/*
	 * Search for this file.
	 */
	findtmp(argv[1]);

	/*
	 * Got (one of the versions of) it, write it back to the editor.
	 */
	cp = ctime(&H.Time);
	cp[19] = 0;
	fprintf(stderr, " [Dated: %s", cp);
	fprintf(stderr, vercnt > 1 ? ", newest of %d saved]" : "]", vercnt);
	H.Flines++;

	/*
	 * Allocate space for the line pointers from the temp file.
	 */
	if ((int) sbrk((int) (H.Flines * sizeof (line))) == -1)
		/*
		 * Good grief.
		 */
		error(" Not enough core for lines", 0);
#ifdef DEBUG
	fprintf(stderr, "%d lines\n", H.Flines);
#endif

	/*
	 * Now go get the blocks of seek pointers which are scattered
	 * throughout the temp file, reconstructing the incore
	 * line pointers at point of crash.
	 */
	b = 0;
	while (H.Flines > 0) {
		ignorl(lseek(tfile, (long) blocks[b] * BUFSIZ, 0));
		i = H.Flines < BUFSIZ / sizeof (line) ?
			H.Flines * sizeof (line) : BUFSIZ;
D 18
		if (read(tfile, (char *) dot, i) != i) {
E 18
I 18
		if (read(tfile, (u_char *) dot, i) != i) {
E 18
			perror(nb);
			exit(1);
		}
		dot += i / sizeof (line);
		H.Flines -= i / sizeof (line);
		b++;
	}
	dot--; dol = dot;

	/*
	 * Sigh... due to sandbagging some lines may really not be there.
	 * Find and discard such.  This shouldn't happen much.
	 */
	scrapbad();

	/*
	 * Now if there were any lines in the recovered file
	 * write them to the standard output.
	 */
	if (dol > zero) {
		addr1 = one; addr2 = dol; io = 1;
D 8
		putfile();
E 8
I 8
		putfile(0);
E 8
	}

	/*
	 * Trash the saved buffer.
	 * Hopefully the system won't crash before the editor
	 * syncs the new recovered buffer; i.e. for an instant here
	 * you may lose if the system crashes because this file
	 * is gone, but the editor hasn't completed reading the recovered
	 * file from the pipe from us to it.
	 *
	 * This doesn't work if we are coming from an non-absolute path
	 * name since we may have chdir'ed but what the hay, noone really
	 * ever edits with temporaries in "." anyways.
	 */
	if (nb[0] == '/')
		ignore(unlink(nb));

	/*
	 * Adieu.
	 */
	exit(0);
}

/*
 * Print an error message (notably not in error
 * message file).  If terminal is in RAW mode, then
 * we should be writing output for "vi", so don't print
 * a newline which would screw up the screen.
 */
/*VARARGS2*/
error(str, inf)
D 18
	char *str;
E 18
I 18
	u_char *str;
E 18
	int inf;
{

	fprintf(stderr, str, inf);
I 4
#ifndef USG3TTY
E 4
	gtty(2, &tty);
	if ((tty.sg_flags & RAW) == 0)
I 4
#else
	ioctl(2, TCGETA, &tty);
	if (tty.c_lflag & ICANON)
#endif
E 4
		fprintf(stderr, "\n");
	exit(1);
}

/*
 * Here we save the information about files, when
 * you ask us what files we have saved for you.
 * We buffer file name, number of lines, and the time
 * at which the file was saved.
 */
struct svfile {
D 18
	char	sf_name[FNSIZE + 1];
E 18
I 18
	u_char	sf_name[FNSIZE + 1];
E 18
	int	sf_lines;
D 12
	char	sf_entry[DIRSIZ + 1];
E 12
I 12
D 18
	char	sf_entry[MAXNAMLEN + 1];
E 18
I 18
	u_char	sf_entry[MAXNAMLEN + 1];
E 18
E 12
	time_t	sf_time;
};

listfiles(dirname)
D 18
	char *dirname;
E 18
I 18
	u_char *dirname;
E 18
{
D 12
	register FILE *dir;
	struct direct dirent;
E 12
I 12
	register DIR *dir;
	struct direct *dirent;
E 12
	int ecount, qucmp();
	register int f;
D 18
	char *cp;
E 18
I 18
	u_char *cp;
E 18
	struct svfile *fp, svbuf[NENTRY];

	/*
	 * Open usrpath(preserve), and go there to make things quick.
	 */
D 12
	dir = fopen(dirname, "r");
E 12
I 12
	dir = opendir(dirname);
E 12
	if (dir == NULL) {
		perror(dirname);
		return;
	}
	if (chdir(dirname) < 0) {
		perror(dirname);
		return;
	}

	/*
	 * Look at the candidate files in usrpath(preserve).
	 */
	fp = &svbuf[0];
	ecount = 0;
D 12
	while (fread((char *) &dirent, sizeof dirent, 1, dir) == 1) {
		if (dirent.d_ino == 0)
E 12
I 12
	while ((dirent = readdir(dir)) != NULL) {
		if (dirent->d_name[0] != 'E')
E 12
			continue;
D 12
		if (dirent.d_name[0] != 'E')
			continue;
E 12
#ifdef DEBUG
D 12
		fprintf(stderr, "considering %s\n", dirent.d_name);
E 12
I 12
		fprintf(stderr, "considering %s\n", dirent->d_name);
E 12
#endif
		/*
		 * Name begins with E; open it and
		 * make sure the uid in the header is our uid.
		 * If not, then don't bother with this file, it can't
		 * be ours.
		 */
D 12
		f = open(dirent.d_name, 0);
E 12
I 12
		f = open(dirent->d_name, 0);
E 12
		if (f < 0) {
#ifdef DEBUG
			fprintf(stderr, "open failed\n");
#endif
			continue;
		}
D 18
		if (read(f, (char *) &H, sizeof H) != sizeof H) {
E 18
I 18
		if (read(f, (u_char *) &H, sizeof H) != sizeof H) {
E 18
#ifdef DEBUG
			fprintf(stderr, "culdnt read hedr\n");
#endif
			ignore(close(f));
			continue;
		}
		ignore(close(f));
		if (getuid() != H.Uid) {
#ifdef DEBUG
			fprintf(stderr, "uid wrong\n");
#endif
			continue;
		}

		/*
		 * Saved the day!
		 */
D 12
		enter(fp++, dirent.d_name, ecount);
E 12
I 12
		enter(fp++, dirent->d_name, ecount);
E 12
		ecount++;
#ifdef DEBUG
D 12
		fprintf(stderr, "entered file %s\n", dirent.d_name);
E 12
I 12
		fprintf(stderr, "entered file %s\n", dirent->d_name);
E 12
#endif
	}
D 12
	ignore(fclose(dir));
E 12
I 12
	ignore(closedir(dir));
E 12

	/*
	 * If any files were saved, then sort them and print
	 * them out.
	 */
	if (ecount == 0) {
		fprintf(stderr, "No files saved.\n");
		return;
	}
	qsort(&svbuf[0], ecount, sizeof svbuf[0], qucmp);
	for (fp = &svbuf[0]; fp < &svbuf[ecount]; fp++) {
		cp = ctime(&fp->sf_time);
		cp[10] = 0;
		fprintf(stderr, "On %s at ", cp);
 		cp[16] = 0;
		fprintf(stderr, &cp[11]);
		fprintf(stderr, " saved %d lines of file \"%s\"\n",
		    fp->sf_lines, fp->sf_name);
	}
}

/*
 * Enter a new file into the saved file information.
 */
enter(fp, fname, count)
	struct svfile *fp;
D 18
	char *fname;
E 18
I 18
	u_char *fname;
E 18
{
D 18
	register char *cp, *cp2;
E 18
I 18
	register u_char *cp, *cp2;
E 18
	register struct svfile *f, *fl;
	time_t curtime, itol();

	f = 0;
	if (count >= NENTRY) {
		/*
		 * My god, a huge number of saved files.
		 * Would you work on a system that crashed this
		 * often?  Hope not.  So lets trash the oldest
		 * as the most useless.
		 *
		 * (I wonder if this code has ever run?)
		 */
		fl = fp - count + NENTRY - 1;
		curtime = fl->sf_time;
		for (f = fl; --f > fp-count; )
			if (f->sf_time < curtime)
				curtime = f->sf_time;
		for (f = fl; --f > fp-count; )
			if (f->sf_time == curtime)
				break;
		fp = f;
	}

	/*
	 * Gotcha.
	 */
	fp->sf_time = H.Time;
	fp->sf_lines = H.Flines;
	for (cp2 = fp->sf_name, cp = savedfile; *cp;)
		*cp2++ = *cp++;
	for (cp2 = fp->sf_entry, cp = fname; *cp && cp-fname < 14;)
		*cp2++ = *cp++;
	*cp2++ = 0;
}

/*
 * Do the qsort compare to sort the entries first by file name,
 * then by modify time.
 */
qucmp(p1, p2)
	struct svfile *p1, *p2;
{
	register int t;

	if (t = strcmp(p1->sf_name, p2->sf_name))
		return(t);
	if (p1->sf_time > p2->sf_time)
		return(-1);
	return(p1->sf_time < p2->sf_time);
}

/*
 * Scratch for search.
 */
D 18
char	bestnb[BUFSIZ];		/* Name of the best one */
E 18
I 18
u_char	bestnb[BUFSIZ];		/* Name of the best one */
E 18
long	besttime;		/* Time at which the best file was saved */
int	bestfd;			/* Keep best file open so it dont vanish */

/*
 * Look for a file, both in the users directory option value
 * (i.e. usually /tmp) and in usrpath(preserve).
 * Want to find the newest so we search on and on.
 */
findtmp(dir)
D 18
	char *dir;
E 18
I 18
	u_char *dir;
E 18
{

	/*
	 * No name or file so far.
	 */
	bestnb[0] = 0;
	bestfd = -1;

	/*
	 * Search usrpath(preserve) and, if we can get there, /tmp
	 * (actually the users "directory" option).
	 */
	searchdir(dir);
	if (chdir(mydir) == 0)
		searchdir(mydir);
	if (bestfd != -1) {
		/*
		 * Gotcha.
		 * Put the file (which is already open) in the file
		 * used by the temp file routines, and save its
		 * name for later unlinking.
		 */
		tfile = bestfd;
		CP(nb, bestnb);
		ignorl(lseek(tfile, 0l, 0));

		/*
		 * Gotta be able to read the header or fall through
		 * to lossage.
		 */
D 18
		if (read(tfile, (char *) &H, sizeof H) == sizeof H)
E 18
I 18
		if (read(tfile, (u_char *) &H, sizeof H) == sizeof H)
E 18
			return;
	}

	/*
	 * Extreme lossage...
	 */
	error(" File not found", 0);
}

/*
 * Search for the file in directory dirname.
 *
 * Don't chdir here, because the users directory
 * may be ".", and we would move away before we searched it.
 * Note that we actually chdir elsewhere (because it is too slow
 * to look around in usrpath(preserve) without chdir'ing there) so we
 * can't win, because we don't know the name of '.' and if the path
 * name of the file we want to unlink is relative, rather than absolute
 * we won't be able to find it again.
 */
searchdir(dirname)
D 18
	char *dirname;
E 18
I 18
	u_char *dirname;
E 18
{
D 12
	struct direct dirent;
	register FILE *dir;
E 12
I 12
	struct direct *dirent;
	register DIR *dir;
E 12
D 18
	char dbuf[BUFSIZ];
E 18
I 18
	u_char dbuf[BUFSIZ];
E 18

D 12
	dir = fopen(dirname, "r");
E 12
I 12
	dir = opendir(dirname);
E 12
	if (dir == NULL)
		return;
D 11
	setbuf(dir, dbuf);
E 11
I 11
D 12
	/* setbuf(dir, dbuf); this breaks UNIX/370. */
E 11
	while (fread((char *) &dirent, sizeof dirent, 1, dir) == 1) {
		if (dirent.d_ino == 0)
E 12
I 12
	while ((dirent = readdir(dir)) != NULL) {
		if (dirent->d_name[0] != 'E')
E 12
			continue;
D 12
		if (dirent.d_name[0] != 'E' || dirent.d_name[DIRSIZ - 1] != 0)
			continue;
E 12
		/*
		 * Got a file in the directory starting with E...
		 * Save a consed up name for the file to unlink
		 * later, and check that this is really a file
		 * we are looking for.
		 */
D 12
		ignore(strcat(strcat(strcpy(nb, dirname), "/"), dirent.d_name));
E 12
I 12
		ignore(strcat(strcat(strcpy(nb, dirname), "/"), dirent->d_name));
E 12
		if (yeah(nb)) {
			/*
			 * Well, it is the file we are looking for.
			 * Is it more recent than any version we found before?
			 */
			if (H.Time > besttime) {
				/*
				 * A winner.
				 */
				ignore(close(bestfd));
				bestfd = dup(tfile);
				besttime = H.Time;
				CP(bestnb, nb);
			}
			/*
			 * Count versions so user can be told there are
			 * ``yet more pages to be turned''.
			 */
			vercnt++;
		}
		ignore(close(tfile));
	}
D 12
	ignore(fclose(dir));
E 12
I 12
	ignore(closedir(dir));
E 12
}

/*
 * Given a candidate file to be recovered, see
 * if its really an editor temporary and of this
 * user and the file specified.
 */
yeah(name)
D 18
	char *name;
E 18
I 18
	u_char *name;
E 18
{

	tfile = open(name, 2);
	if (tfile < 0)
		return (0);
D 18
	if (read(tfile, (char *) &H, sizeof H) != sizeof H) {
E 18
I 18
	if (read(tfile, (u_char *) &H, sizeof H) != sizeof H) {
E 18
nope:
		ignore(close(tfile));
		return (0);
	}
	if (!eq(savedfile, file))
		goto nope;
	if (getuid() != H.Uid)
		goto nope;
	/*
	 * This is old and stupid code, which
	 * puts a word LOST in the header block, so that lost lines
	 * can be made to point at it.
	 */
D 2
	ignorl(lseek(tfile, 504l, 0));
E 2
I 2
	ignorl(lseek(tfile, (long)(BUFSIZ*HBLKS-8), 0));
E 2
	ignore(write(tfile, "LOST", 5));
	return (1);
}

preserve()
{

}

/*
 * Find the true end of the scratch file, and ``LOSE''
 * lines which point into thin air.  This lossage occurs
 * due to the sandbagging of i/o which can cause blocks to
 * be written in a non-obvious order, different from the order
 * in which the editor tried to write them.
 *
 * Lines which are lost are replaced with the text LOST so
 * they are easy to find.  We work hard at pretty formatting here
 * as lines tend to be lost in blocks.
 *
 * This only seems to happen on very heavily loaded systems, and
 * not very often.
 */
scrapbad()
{
	register line *ip;
	struct stat stbuf;
	off_t size, maxt;
	int bno, cnt, bad, was;
D 18
	char bk[BUFSIZ];
E 18
I 18
	u_char bk[BUFSIZ];
E 18

	ignore(fstat(tfile, &stbuf));
	size = stbuf.st_size;
D 2
	maxt = (size >> SHFT) | 7;
E 2
I 2
	maxt = (size >> SHFT) | (BNDRY-1);
E 2
	bno = (maxt >> OFFBTS) & BLKMSK;
#ifdef DEBUG
	fprintf(stderr, "size %ld, maxt %o, bno %d\n", size, maxt, bno);
#endif

	/*
	 * Look for a null separating two lines in the temp file;
	 * if last line was split across blocks, then it is lost
	 * if the last block is.
	 */
	while (bno > 0) {
		ignorl(lseek(tfile, (long) BUFSIZ * bno, 0));
D 18
		cnt = read(tfile, (char *) bk, BUFSIZ);
E 18
I 18
		cnt = read(tfile, (u_char *) bk, BUFSIZ);
E 18
		while (cnt > 0)
			if (bk[--cnt] == 0)
				goto null;
		bno--;
	}
null:

	/*
	 * Magically calculate the largest valid pointer in the temp file,
	 * consing it up from the block number and the count.
	 */
	maxt = ((bno << OFFBTS) | (cnt >> SHFT)) & ~1;
#ifdef DEBUG
	fprintf(stderr, "bno %d, cnt %d, maxt %o\n", bno, cnt, maxt);
#endif

	/*
	 * Now cycle through the line pointers,
	 * trashing the Lusers.
	 */
	was = bad = 0;
	for (ip = one; ip <= dol; ip++)
		if (*ip > maxt) {
#ifdef DEBUG
			fprintf(stderr, "%d bad, %o > %o\n", ip - zero, *ip, maxt);
#endif
			if (was == 0)
				was = ip - zero;
D 2
			*ip = 504 >> SHFT;
E 2
I 2
			*ip = ((HBLKS*BUFSIZ)-8) >> SHFT;
E 2
		} else if (was) {
			if (bad == 0)
				fprintf(stderr, " [Lost line(s):");
			fprintf(stderr, " %d", was);
			if ((ip - 1) - zero > was)
				fprintf(stderr, "-%d", (ip - 1) - zero);
			bad++;
			was = 0;
		}
	if (was != 0) {
		if (bad == 0)
			fprintf(stderr, " [Lost line(s):");
		fprintf(stderr, " %d", was);
		if (dol - zero != was)
			fprintf(stderr, "-%d", dol - zero);
		bad++;
	}
	if (bad)
		fprintf(stderr, "]");
}

/*
 * Aw shucks, if we only had a (void) cast.
 */
#ifdef lint
Ignorl(a)
	long a;
{

	a = a;
}

Ignore(a)
D 18
	char *a;
E 18
I 18
	u_char *a;
E 18
{

	a = a;
}

Ignorf(a)
	int (*a)();
{

	a = a;
}

ignorl(a)
	long a;
{

	a = a;
}
#endif

int	cntch, cntln, cntodd, cntnull;
/*
 * Following routines stolen mercilessly from ex.
 */
putfile()
{
	line *a1;
D 18
	register char *fp, *lp;
E 18
I 18
	register u_char *fp, *lp;
E 18
	register int nib;

	a1 = addr1;
	clrstats();
	cntln = addr2 - a1 + 1;
	if (cntln == 0)
		return;
	nib = BUFSIZ;
	fp = genbuf;
	do {
		getline(*a1++);
		lp = linebuf;
		for (;;) {
			if (--nib < 0) {
				nib = fp - genbuf;
				if (write(io, genbuf, nib) != nib)
					wrerror();
				cntch += nib;
				nib = 511;
				fp = genbuf;
			}
			if ((*fp++ = *lp++) == 0) {
				fp[-1] = '\n';
				break;
			}
		}
	} while (a1 <= addr2);
	nib = fp - genbuf;
	if (write(io, genbuf, nib) != nib)
		wrerror();
	cntch += nib;
}

wrerror()
{

	syserror();
}

clrstats()
{

	ninbuf = 0;
	cntch = 0;
	cntln = 0;
	cntnull = 0;
	cntodd = 0;
}

#define	READ	0
#define	WRITE	1

getline(tl)
	line tl;
{
D 18
	register char *bp, *lp;
E 18
I 18
	register u_char *bp, *lp;
E 18
	register int nl;

	lp = linebuf;
	bp = getblock(tl, READ);
	nl = nleft;
	tl &= ~OFFMSK;
	while (*lp++ = *bp++)
		if (--nl == 0) {
			bp = getblock(tl += INCRMT, READ);
			nl = nleft;
		}
}

int	read();
int	write();

D 18
char *
E 18
I 18
u_char *
E 18
getblock(atl, iof)
	line atl;
	int iof;
{
	register int bno, off;
	
	bno = (atl >> OFFBTS) & BLKMSK;
	off = (atl << SHFT) & LBTMSK;
	if (bno >= NMBLKS)
		error(" Tmp file too large");
	nleft = BUFSIZ - off;
	if (bno == iblock) {
		ichanged |= iof;
		return (ibuff + off);
	}
	if (bno == oblock)
		return (obuff + off);
	if (iof == READ) {
		if (ichanged)
			blkio(iblock, ibuff, write);
		ichanged = 0;
		iblock = bno;
		blkio(bno, ibuff, read);
		return (ibuff + off);
	}
	if (oblock >= 0)
		blkio(oblock, obuff, write);
	oblock = bno;
	return (obuff + off);
}

blkio(b, buf, iofcn)
	short b;
D 18
	char *buf;
E 18
I 18
	u_char *buf;
E 18
	int (*iofcn)();
{

	lseek(tfile, (long) (unsigned) b * BUFSIZ, 0);
D 2
	if ((*iofcn)(tfile, buf, BUFSIZ) != 512)
E 2
I 2
	if ((*iofcn)(tfile, buf, BUFSIZ) != BUFSIZ)
E 2
		syserror();
}

syserror()
{
	extern int sys_nerr;
	extern char *sys_errlist[];

	dirtcnt = 0;
	write(2, " ", 1);
	if (errno >= 0 && errno <= sys_nerr)
		error(sys_errlist[errno]);
	else
		error("System error %d", errno);
	exit(1);
}
I 15

/*
 * Must avoid stdio because expreserve uses sbrk to do memory
 * allocation and stdio uses malloc.
 */
fprintf(fp, fmt, a1, a2, a3, a4, a5)
	FILE *fp;
D 18
	char *fmt;
	char *a1, *a2, *a3, *a4, *a5;
E 18
I 18
	u_char *fmt;
	u_char *a1, *a2, *a3, *a4, *a5;
E 18
{
D 18
	char buf[BUFSIZ];
E 18
I 18
	u_char buf[BUFSIZ];
E 18

	if (fp != stderr)
		return;
	sprintf(buf, fmt, a1, a2, a3, a4, a5);
	write(2, buf, strlen(buf));
}
E 15
E 1
