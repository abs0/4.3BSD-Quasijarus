h52004
s 00026/00026/01062
d D 7.18 03/04/13 15:18:55 msokolov 37 35
c 8-bit ex
e
s 00000/00024/01064
d D 7.17.1.1 88/08/08 18:29:45 mckusick 36 35
c delete decryption for the foreign sites (4.3BSD Tahoe)
e
s 00025/00023/01063
d D 7.17 88/01/02 23:03:14 bostic 35 34
c look for real magic number; don't check first two bytes for high order
c bits; don't pass "line" as an argument, it breaks ANSI C
e
s 00004/00000/01082
d D 7.16 87/11/02 11:06:04 bostic 34 33
c file mode for vms; bug report 4.3BSD/ucb/134
e
s 00158/00000/00924
d D 7.15 87/06/28 23:12:43 conrad 33 31
c Installed Bill Jolitz's flock() code
e
s 00158/00000/00924
d R 7.15 87/06/28 23:07:30 conrad 32 31
c 
e
s 00002/00005/00922
d D 7.14 87/05/12 10:07:54 bostic 31 30
c duplicate line in gscan; bug report 4.3BSD/ucb/94
e
s 00050/00031/00877
d D 7.13 87/03/09 12:47:08 conrad 30 29
c make ex/vi work on vms
e
s 00001/00001/00907
d D 7.12 86/08/28 18:02:32 karels 29 27
c only fsync on writes, not reads
e
s 00000/00024/00884
d D 7.11.1.1 86/08/12 15:52:18 mckusick 28 27
c delete decryption for the foreign sites
e
s 00001/00001/00907
d D 7.11 85/06/07 18:19:17 bloom 27 26
c fix sccsid and copyright for xstr
e
s 00010/00002/00898
d D 7.10 85/05/31 13:54:50 dist 26 24
c Add copyright
e
s 00010/00002/00798
d D 5.6.1.1 85/05/31 12:03:51 dist 25 13
c Add copyright
e
s 00019/00003/00881
d D 7.9 85/03/27 11:54:35 bloom 24 23
c use optimal size for i/o
e
s 00007/00006/00877
d D 7.8 85/01/23 14:25:28 ralph 23 22
c minor speedup
e
s 00020/00008/00863
d D 7.7 84/04/17 10:11:37 peter 22 21
c only look for modelines if the binary ``modeline'' option is set;
c modelines are in the first or last five lines of a file, and look like:
c 	[ \t]ex:command:	or	[ \t]vi:command:
c and mark has mumbled something about their not working all the time.
e
s 00001/00000/00870
d D 7.6 83/07/30 13:27:50 sam 21 20
c force system i/o when finished with edited file
e
s 00000/00007/00870
d D 7.5 83/06/10 12:08:54 ralph 20 19
c fixed Not Edited and not Modified when errors occur.
e
s 00002/00001/00875
d D 7.4 81/10/31 14:49:47 mark 19 18
c fixed C/70 bug with peekc being saved in a char
e
s 00002/00002/00874
d D 7.3 81/09/03 11:44:18 mark 18 17
c updates for Unix/370 and ins/del line on vt100
e
s 00006/00000/00870
d D 7.2 81/07/11 01:47:42 mark 17 16
c fixed 10 bit problem with magic number for c/70
e
s 00045/00007/00825
d D 7.1 81/07/08 22:29:44 mark 16 15
c release 3.7 - a few bug fixes and a few new features.
e
s 00015/00004/00817
d D 6.2 80/10/23 16:21:45 mark 15 14
c fixed various bugs prior to 3.6 release
e
s 00030/00009/00791
d D 6.1 80/10/19 01:20:56 mark 14 13
c preliminary release 3.6 10/18/80
e
s 00001/00001/00799
d D 5.6 80/09/17 22:11:07 mark 13 11
c fixed parenthesis error with :r on readonly file
e
s 00001/00001/00799
d R 5.6 80/09/17 16:28:35 mark 12 11
c fixed readonly bug
e
s 00010/00001/00790
d D 5.5 80/09/07 12:31:41 mark 11 10
c added fix to unset automatic set of READONLY when done
e
s 00001/00001/00790
d D 5.4 80/09/05 23:07:26 mark 10 9
c made it use access so other peoples 644 files set readonly too.
e
s 00003/00001/00788
d D 5.3 80/09/05 22:51:08 mark 9 8
c made it flush after [Read only]
e
s 00004/00000/00785
d D 5.2 80/09/05 19:52:10 mark 8 7
c files with no write bits make vi read only and say so
e
s 00000/00000/00785
d D 5.1 80/08/20 16:10:01 mark 7 6
c Release 3.5, August 20, 1980
e
s 00008/00000/00777
d D 4.3 80/08/20 00:24:24 mark 6 5
c made CRYPT an #ifdef
e
s 00005/00001/00772
d D 4.2 80/08/01 20:40:08 mark 5 4
c Bill added more buffers, and I put in sccs.
e
s 00039/00319/00734
d D 4.1 80/08/01 00:12:16 mark 4 3
c release 3.4, June 24, 1980
e
s 00011/00005/01042
d D 3.1 80/07/31 23:37:52 mark 3 2
c release 3.3, Feb 2, 1980
e
s 00010/00002/01037
d D 2.1 80/07/31 23:18:30 mark 2 1
c release 3.2, Jan 4, 1980
e
s 01039/00000/00000
d D 1.1 80/07/31 23:00:15 mark 1 0
c date and time created 80/07/31 23:00:15 by mark
e
u
U
f b 
t
T
I 1
D 5
/* Copyright (c) 1979 Regents of the University of California */
E 5
I 5
D 16
D 25
/* Copyright (c) 1980 Regents of the University of California */
static char *sccsid = "%W% %G%";
E 25
I 25
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 25
E 16
I 16
D 26
/* Copyright (c) 1981 Regents of the University of California */
static char *sccsid = "%W%	%G%";
E 26
I 26
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
D 27
static char sccsid[] = "%W% (Berkeley) %G%";
E 27
I 27
static char *sccsid = "%W% (Berkeley) %G%";
E 27
#endif not lint

E 26
E 16
E 5
#include "ex.h"
#include "ex_argv.h"
#include "ex_temp.h"
#include "ex_tty.h"
#include "ex_vis.h"
I 33
D 35
#ifdef	FLOCKFILE
E 35
#include <sys/file.h>
D 35
#endif	FLOCKFILE
E 35
I 35
#include <sys/exec.h>
E 35
E 33

/*
D 4
 * File input/output, unix escapes, source, filtering preserve and recover
E 4
I 4
 * File input/output, source, preserve and recover
E 4
 */

/*
 * Following remember where . was in the previous file for return
 * on file switching.
 */
D 2
short	altdot;
short	oldadot;
E 2
I 2
int	altdot;
int	oldadot;
E 2
bool	wasalt;
I 4
short	isalt;
E 4

long	cntch;			/* Count of characters on unit io */
I 2
#ifndef VMUNIX
E 2
short	cntln;			/* Count of lines " */
I 2
#else
int	cntln;
#endif
E 2
long	cntnull;		/* Count of nulls " */
long	cntodd;			/* Count of non-ascii characters " */

I 33
#ifdef	FLOCKFILE
E 33
/*
I 33
 * The alternate, saved and current file are locked the extent of the
 * time that they are active. If the saved file is exchanged
 * with the alternate file, the file descriptors are exchanged
 * and the lock is not released.
 */
int	io_savedfile, io_altfile, io_curr ;
int	lock_savedfile, lock_altfile, lock_curr ;
#endif	FLOCKFILE

/*
E 33
 * Parse file name for command encoded by comm.
 * If comm is E then command is doomed and we are
 * parsing just so user won't have to retype the name.
 */
filename(comm)
	int comm;
{
	register int c = comm, d;
	register int i;
I 33
#ifdef	FLOCKFILE
	int lock ;
E 33

I 33
	lock = 0 ;
#endif	FLOCKFILE

E 33
D 30
	d = getchar();
E 30
I 30
	d = ex_getchar();
E 30
	if (endcmd(d)) {
		if (savedfile[0] == 0 && comm != 'f')
			error("No file|No current filename");
		CP(file, savedfile);
I 33
#ifdef	FLOCKFILE
		if (io_curr && io_curr != io_savedfile) close(io_curr) ;
		lock = lock_curr = lock_savedfile ;
		io_curr = io_savedfile ;
#endif	FLOCKFILE
E 33
D 4
		wasalt = 0;
E 4
I 4
		wasalt = (isalt > 0) ? isalt-1 : 0;
		isalt = 0;
E 4
		oldadot = altdot;
I 4
		if (c == 'e' || c == 'E')
			altdot = lineDOT();
E 4
		if (d == EOF)
			ungetchar(d);
	} else {
		ungetchar(d);
		getone();
		eol();
		if (savedfile[0] == 0 && c != 'E' && c != 'e') {
			c = 'e';
			edited = 0;
		}
		wasalt = strcmp(file, altfile) == 0;
		oldadot = altdot;
		switch (c) {

		case 'f':
			edited = 0;
			/* fall into ... */

		case 'e':
			if (savedfile[0]) {
I 33
#ifdef	FLOCKFILE
				if (strcmp(file,savedfile) == 0) break ;
#endif	FLOCKFILE
E 33
				altdot = lineDOT();
				CP(altfile, savedfile);
I 33
#ifdef	FLOCKFILE
				if (io_altfile) close (io_altfile) ;
				io_altfile = io_savedfile ;
				lock_altfile = lock_savedfile ;
				io_savedfile = 0 ;
#endif	FLOCKFILE
E 33
			}
			CP(savedfile, file);
I 33
#ifdef	FLOCKFILE
			io_savedfile = io_curr ;
			lock_savedfile = lock_curr ;
			io_curr = 0 ;		lock = lock_curr = 0 ;
#endif	FLOCKFILE
E 33
			break;

		default:
			if (file[0]) {
I 33
#ifdef	FLOCKFILE
				if (wasalt) break ;
#endif
E 33
				if (c != 'E')
					altdot = lineDOT();
				CP(altfile, file);
I 33
#ifdef	FLOCKFILE
				if (io_altfile
				&& io_altfile != io_curr) close (io_altfile) ;
				io_altfile = io_curr ;
				lock_altfile = lock_curr ;
				io_curr = 0 ;		lock = lock_curr = 0 ;
#endif	FLOCKFILE
E 33
			}
			break;
		}
	}
	if (hush && comm != 'f' || comm == 'E')
		return;
	if (file[0] != 0) {
		lprintf("\"%s\"", file);
		if (comm == 'f') {
I 4
			if (value(READONLY))
D 30
				printf(" [Read only]");
E 30
I 30
				ex_printf(" [Read only]");
E 30
E 4
			if (!edited)
D 30
				printf(" [Not edited]");
E 30
I 30
				ex_printf(" [Not edited]");
E 30
			if (tchng)
D 30
				printf(" [Modified]");
E 30
I 30
				ex_printf(" [Modified]");
I 33
#ifdef	FLOCKFILE
			if (lock == LOCK_SH)
				ex_printf(" [Shared lock]") ;
			else if (lock == LOCK_EX)
				ex_printf(" [Exclusive lock]") ;
#endif	FLOCKFILE
E 33
E 30
		}
		flush();
	} else
D 30
		printf("No file ");
E 30
I 30
		ex_printf("No file ");
E 30
	if (comm == 'f') {
		if (!(i = lineDOL()))
			i++;
D 30
		printf(" line %d of %d --%ld%%--", lineDOT(), lineDOL(),
E 30
I 30
		ex_printf(" line %d of %d --%ld%%--", lineDOT(), lineDOL(),
E 30
		    (long) 100 * lineDOT() / i);
	}
}

/*
 * Get the argument words for a command into genbuf
 * expanding # and %.
 */
getargs()
{
	register int c;
D 37
	register char *cp, *fp;
	static char fpatbuf[32];	/* hence limit on :next +/pat */
E 37
I 37
	register u_char *cp, *fp;
	static u_char fpatbuf[32];	/* hence limit on :next +/pat */
E 37

	pastwh();
	if (peekchar() == '+') {
		for (cp = fpatbuf;;) {
D 30
			c = *cp++ = getchar();
E 30
I 30
			c = *cp++ = ex_getchar();
E 30
			if (cp >= &fpatbuf[sizeof(fpatbuf)])
				error("Pattern too long");
			if (c == '\\' && isspace(peekchar()))
D 30
				c = getchar();
E 30
I 30
				c = ex_getchar();
E 30
			if (c == EOF || isspace(c)) {
				ungetchar(c);
				*--cp = 0;
				firstpat = &fpatbuf[1];
				break;
			}
		}
	}
	if (skipend())
		return (0);
	CP(genbuf, "echo "); cp = &genbuf[5];
	for (;;) {
D 30
		c = getchar();
E 30
I 30
		c = ex_getchar();
E 30
		if (endcmd(c)) {
			ungetchar(c);
			break;
		}
		switch (c) {

		case '\\':
D 4
			if (any(peekchar(), "#%"))
E 4
I 4
			if (any(peekchar(), "#%|"))
E 4
D 30
				c = getchar();
E 30
I 30
				c = ex_getchar();
E 30
			/* fall into... */

		default:
			if (cp > &genbuf[LBSIZE - 2])
flong:
				error("Argument buffer overflow");
			*cp++ = c;
			break;

		case '#':
			fp = altfile;
			if (*fp == 0)
				error("No alternate filename@to substitute for #");
			goto filexp;

		case '%':
			fp = savedfile;
			if (*fp == 0)
				error("No current filename@to substitute for %%");
filexp:
			while (*fp) {
				if (cp > &genbuf[LBSIZE - 2])
					goto flong;
				*cp++ = *fp++;
			}
			break;
		}
	}
	*cp = 0;
	return (1);
}

/*
 * Glob the argument words in genbuf, or if no globbing
 * is implied, just split them up directly.
 */
glob(gp)
	struct glob *gp;
{
	int pvec[2];
D 37
	register char **argv = gp->argv;
	register char *cp = gp->argspac;
E 37
I 37
	register u_char **argv = gp->argv;
	register u_char *cp = gp->argspac;
E 37
	register int c;
D 37
	char ch;
E 37
I 37
	u_char ch;
E 37
	int nleft = NCARGS;

	gp->argc0 = 0;
	if (gscan() == 0) {
D 37
		register char *v = genbuf + 5;		/* strlen("echo ") */
E 37
I 37
		register u_char *v = genbuf + 5;		/* strlen("echo ") */
E 37

		for (;;) {
			while (isspace(*v))
				v++;
			if (!*v)
				break;
			*argv++ = cp;
			while (*v && !isspace(*v))
				*cp++ = *v++;
			*cp++ = 0;
			gp->argc0++;
		}
		*argv = 0;
		return;
	}
	if (pipe(pvec) < 0)
		error("Can't make pipe to glob");
D 30
	pid = fork();
E 30
I 30
	pid = vfork();
E 30
	io = pvec[0];
	if (pid < 0) {
		close(pvec[1]);
		error("Can't fork to do glob");
	}
	if (pid == 0) {
		int oerrno;

		close(1);
		dup(pvec[1]);
		close(pvec[0]);
I 3
		close(2);	/* so errors don't mess up the screen */
D 30
		open("/dev/null", 1);
E 30
I 30
		ignore(open("/dev/null", 1));
E 30
E 3
		execl(svalue(SHELL), "sh", "-c", genbuf, 0);
D 30
		oerrno = errno; close(1); dup(2); errno = oerrno;
E 30
I 30
		oerrno = errno;
		close(1);
		dup(2);
		errno = oerrno;
E 30
		filioerr(svalue(SHELL));
	}
	close(pvec[1]);
	do {
		*argv = cp;
		for (;;) {
			if (read(io, &ch, 1) != 1) {
				close(io);
				c = -1;
			} else
D 37
				c = ch & TRIM;
E 37
I 37
				c = ch & TRIM7;
E 37
			if (c <= 0 || isspace(c))
				break;
			*cp++ = c;
			if (--nleft <= 0)
				error("Arg list too long");
		}
		if (cp != *argv) {
			--nleft;
			*cp++ = 0;
			gp->argc0++;
			if (gp->argc0 >= NARGS)
				error("Arg list too long");
			argv++;
		}
	} while (c >= 0);
	waitfor();
	if (gp->argc0 == 0)
D 3
		error(NOSTR);
E 3
I 3
		error("No match");
E 3
}

/*
 * Scan genbuf for shell metacharacters.
 * Set is union of v7 shell and csh metas.
 */
gscan()
{
I 30
D 31
#ifndef	vms
E 31
I 31
#ifndef	vms			/* Never have meta-characters in vms */
E 31
E 30
D 37
	register char *cp;
E 37
I 37
	register u_char *cp;
E 37

	for (cp = genbuf; *cp; cp++)
		if (any(*cp, "~{[*?$`'\"\\"))
I 30
D 31
		if (any(*cp, "~{[*?$`'\"\\"))
E 31
E 30
			return (1);
D 31
	return (0);
I 30
#else
	return 0;	/* Never have meta-characters in vms */
E 31
#endif
I 31
	return (0);
E 31
E 30
}

/*
 * Parse one filename into file.
 */
I 18
struct glob G;
E 18
getone()
{
D 37
	register char *str;
E 37
I 37
	register u_char *str;
E 37
D 18
	struct glob G;
E 18

	if (getargs() == 0)
		error("Missing filename");
	glob(&G);
	if (G.argc0 > 1)
		error("Ambiguous|Too many file names");
	str = G.argv[G.argc0 - 1];
	if (strlen(str) > FNSIZE - 4)
		error("Filename too long");
D 30
samef:
E 30
	CP(file, str);
}

/*
 * Read a file from the world.
 * C is command, 'e' if this really an edit (or a recover).
 */
rop(c)
	int c;
{
	register int i;
	struct stat stbuf;
D 35
	short magic;
E 35
I 35
	struct exec head;
E 35
I 11
	static int ovro;	/* old value(READONLY) */
	static int denied;	/* 1 if READONLY was set due to file permissions */
I 33
#ifdef	FLOCKFILE
D 35
	int *lp, *iop ;
E 35
I 35
	int *lp, *iop;
E 35
#endif	FLOCKFILE
E 33
E 11

	io = open(file, 0);
	if (io < 0) {
D 14
		if (c == 'e' && errno == ENOENT)
E 14
I 14
		if (c == 'e' && errno == ENOENT) {
E 14
			edited++;
I 14
			/*
			 * If the user just did "ex foo" he is probably
			 * creating a new file.  Don't be an error, since
			 * this is ugly, and it screws up the + option.
			 */
			if (!seenprompt) {
D 30
				printf(" [New file]");
E 30
I 30
				ex_printf(" [New file]");
E 30
				noonl();
				return;
			}
		}
E 14
		syserror();
	}
	if (fstat(io, &stbuf))
		syserror();
	switch (stbuf.st_mode & S_IFMT) {

	case S_IFBLK:
		error(" Block special file");

	case S_IFCHR:
		if (isatty(io))
			error(" Teletype");
		if (samei(&stbuf, "/dev/null"))
			break;
		error(" Character special file");

	case S_IFDIR:
		error(" Directory");

	case S_IFREG:
I 6
D 28
D 36
#ifdef CRYPT
E 6
I 4
		if (xflag)
			break;
I 6
#endif
E 36
E 28
E 6
E 4
D 35
		i = read(io, (char *) &magic, sizeof(magic));
		lseek(io, 0l, 0);
		if (i != sizeof(magic))
E 35
I 35
D 37
		i = read(io, (char *)&head, sizeof(head));
E 37
I 37
		i = read(io, (u_char *)&head, sizeof(head));
E 37
		(void)lseek(io, 0L, L_SET);
		if (i != sizeof(head))
E 35
			break;
I 30
#ifndef vms
E 30
D 35
		switch (magic) {
E 35
I 35
		switch ((int)head.a_magic) {
E 35

D 15
		case 0405:
		case 0407:
		case 0410:
		case 0411:
E 15
I 15
D 16
		case 0405:	/* Interdata? overlay */
E 16
I 16
		case 0405:	/* data overlay on exec */
E 16
D 35
		case 0407:	/* unshared */
		case 0410:	/* shared text */
E 35
I 35
		case OMAGIC:	/* unshared */
		case NMAGIC:	/* shared text */
E 35
		case 0411:	/* separate I/D */
D 35
		case 0413:	/* VM/Unix demand paged */
E 35
I 35
		case ZMAGIC:	/* VM/Unix demand paged */
E 35
		case 0430:	/* PDP-11 Overlay shared */
		case 0431:	/* PDP-11 Overlay sep I/D */
E 15
			error(" Executable");

I 15
		/*
		 * We do not forbid the editing of portable archives
		 * because it is reasonable to edit them, especially
		 * if they are archives of text files.  This is
		 * especially useful if you archive source files together
		 * and copy them to another system with ~%take, since
		 * the files sometimes show up munged and must be fixed.
		 */
E 15
		case 0177545:
		case 0177555:
			error(" Archive");
I 35
		case 070707:
			error(" Cpio file");
E 35

		default:
I 17
D 35
#ifdef mbb
			/* C/70 has a 10 bit byte */
			if (magic & 03401600)
#else
			/* Everybody else has an 8 bit byte */
E 17
			if (magic & 0100200)
I 17
#endif
E 17
				error(" Non-ascii file");
E 35
I 35
			{
D 37
				char *bp = (char *)&head;
E 37
I 37
				u_char *bp = (u_char *)&head;
E 37
				if ((u_char)bp[0] == (u_char)'\037' &&
				    (u_char)bp[1] == (u_char)'\235')
					error(" Compressed file");
				if (!strncmp(bp, "!<arch>\n__.SYMDEF", 17)
				    || !strncmp(bp, "!<arch>\n", 8))
					error(" Archive");
			}
E 35
			break;
		}
I 30
#endif
E 30
	}
I 8
D 10
	if ((stbuf.st_mode & 0222) == 0)
E 10
I 10
D 11
	if ((stbuf.st_mode & 0222) == 0 || access(file, 2) < 0)
E 11
I 11
D 14
	if (value(READONLY) && denied) {
		value(READONLY) = ovro;
		denied = 0;
E 14
I 14
	if (c != 'r') {
		if (value(READONLY) && denied) {
			value(READONLY) = ovro;
			denied = 0;
		}
		if ((stbuf.st_mode & 0222) == 0 || access(file, 2) < 0) {
			ovro = value(READONLY);
			denied = 1;
			value(READONLY) = 1;
		}
E 14
	}
D 13
	if (c != 'r' && (stbuf.st_mode & 0222) == 0 || access(file, 2) < 0) {
E 13
I 13
D 14
	if (c != 'r' && ((stbuf.st_mode & 0222) == 0 || access(file, 2) < 0)) {
E 13
		ovro = value(READONLY);
		denied = 1;
E 11
E 10
		value(READONLY) = 1;
I 11
	}
E 14
E 11
D 9
	if (value(READONLY))
E 9
I 9
	if (value(READONLY)) {
E 9
D 30
		printf(" [Read only]");
E 30
I 30
		ex_printf(" [Read only]");
E 30
I 9
		flush();
	}
I 33
#ifdef	FLOCKFILE
	/*
	 * Attempt to lock the file. We use an sharable lock if reading
	 * the file, and an exclusive lock if editting a file.
	 * The lock will be released when the file is no longer being
	 * referenced. At any time, the editor can have as many as
	 * three files locked, and with different lock statuses.
	 */
	/*
	 * if this is either the saved or alternate file or current file,
	 * point to the appropriate descriptor and file lock status.
	 */
	if (strcmp (file,savedfile) == 0) {
		if (!io_savedfile) io_savedfile = dup(io) ;
		lp = &lock_savedfile ;	iop = &io_savedfile ;
	} else if (strcmp (file,altfile) == 0) {
		if (!io_altfile) io_altfile = dup(io) ;
		lp = &lock_altfile ;	iop = &io_altfile ;
	} else {
		/* throw away current lock, accquire new current lock */
		if (io_curr) close (io_curr) ;
		io_curr = dup(io) ;
		lp = &lock_curr ;	iop = &io_curr ;
		lock_curr = 0 ;
	}
	if (c == 'r' || value(READONLY) || *lp == 0) {
		/* if we have a lock already, don't bother */
		if (!*lp) {
			/* try for a shared lock */
			if (flock(*iop, LOCK_SH|LOCK_NB) < 0
			&& errno == EWOULDBLOCK) {
				ex_printf (
			" [FILE BEING MODIFIED BY ANOTHER PROCESS]") ;
				flush();
				goto fail_lock ;
			} else *lp = LOCK_SH ;
		}
	}
	if ( c != 'r'  && !value(READONLY) && *lp != LOCK_EX) {
		/* if we are editting the file, upgrade to an exclusive lock. */
		if (flock(*iop, LOCK_EX|LOCK_NB) < 0 && errno == EWOULDBLOCK) {
			ex_printf (" [File open by another process]") ;
			flush();
		} else *lp = LOCK_EX ;
	}
fail_lock:
#endif	FLOCKFILE
E 33
E 9
E 8
	if (c == 'r')
		setdot();
	else
		setall();
D 3
	if (inopen && c == 'r')
E 3
I 3
	if (FIXUNDO && inopen && c == 'r')
E 3
		undap1 = undap2 = dot + 1;
	rop2();
	rop3(c);
}

rop2()
{
I 16
	line *first, *last, *a;
I 24
	struct stat statb;
E 24
E 16

	deletenone();
	clrstats();
I 16
	first = addr2 + 1;
I 24
	if (fstat(io, &statb) < 0)
		bsize = LBSIZE;
	else {
		bsize = statb.st_blksize;
		if (bsize <= 0)
			bsize = LBSIZE;
	}
E 24
E 16
	ignore(append(getfile, addr2));
I 16
	last = dot;
D 22
	for (a=first; a<=last; a++) {
		if (a==first+5 && last-first > 10)
			a = last - 4;
		getline(*a);
		checkmodeline(linebuf);
E 22
I 22
	/*
	 *	if the modeline variable is set,
	 *	check the first and last five lines of the file
	 *	for a mode line.
	 */
	if (value(MODELINE)) {
		for (a=first; a<=last; a++) {
			if (a==first+5 && last-first > 10)
				a = last - 4;
			getline(*a);
			checkmodeline(linebuf);
		}
E 22
	}
E 16
}

rop3(c)
	int c;
{

	if (iostats() == 0 && c == 'e')
		edited++;
	if (c == 'e') {
		if (wasalt || firstpat) {
			register line *addr = zero + oldadot;

			if (addr > dol)
				addr = dol;
			if (firstpat) {
D 37
				globp = (*firstpat) ? firstpat : "$";
E 37
I 37
				globp = (*firstpat) ? firstpat : (u_char*)"$";
E 37
				commands(1,1);
				firstpat = 0;
			} else if (addr >= one) {
				if (inopen)
					dot = addr;
				markpr(addr);
			} else
				goto other;
		} else
other:
			if (dol > zero) {
				if (inopen)
					dot = one;
				markpr(one);
			}
D 3
		undkind = UNDNONE;
E 3
I 3
		if(FIXUNDO)
			undkind = UNDNONE;
E 3
		if (inopen) {
			vcline = 0;
			vreplace(0, LINES, lineDOL());
		}
	}
D 20
	if (laste) {
I 5
#ifdef VMUNIX
		tlaste();
#endif
E 5
		laste = 0;
		sync();
	}
E 20
}

/*
 * Are these two really the same inode?
 */
samei(sp, cp)
	struct stat *sp;
D 37
	char *cp;
E 37
I 37
	u_char *cp;
E 37
{
	struct stat stb;

	if (stat(cp, &stb) < 0 || sp->st_dev != stb.st_dev)
		return (0);
	return (sp->st_ino == stb.st_ino);
}

/* Returns from edited() */
#define	EDF	0		/* Edited file */
#define	NOTEDF	-1		/* Not edited file */
#define	PARTBUF	1		/* Write of partial buffer to Edited file */

/*
 * Write a file.
 */
wop(dofname)
bool dofname;	/* if 1 call filename, else use savedfile */
{
	register int c, exclam, nonexist;
	line *saddr1, *saddr2;
	struct stat stbuf;
I 33
#ifdef	FLOCKFILE
	int *lp, *iop ;
#endif	FLOCKFILE
E 33

	c = 0;
	exclam = 0;
	if (dofname) {
		if (peekchar() == '!')
			exclam++, ignchar();
		ignore(skipwh());
		while (peekchar() == '>')
			ignchar(), c++, ignore(skipwh());
		if (c != 0 && c != 2)
			error("Write forms are 'w' and 'w>>'");
		filename('w');
	} else {
I 3
		if (savedfile[0] == 0)
			error("No file|No current filename");
E 3
		saddr1=addr1;
		saddr2=addr2;
		addr1=one;
		addr2=dol;
		CP(file, savedfile);
		if (inopen) {
			vclrech(0);
			splitw++;
		}
		lprintf("\"%s\"", file);
	}
	nonexist = stat(file, &stbuf);
I 33
#ifdef	FLOCKFILE
	/*
	 * if this is either the saved or alternate file or current file,
	 * point to the appropriate descriptor and file lock status.
	 */
	if (strcmp (file,savedfile) == 0) {
		lp = &lock_savedfile ;	iop = &io_savedfile ;
	} else if (strcmp (file,altfile) == 0) {
		lp = &lock_altfile ;	iop = &io_altfile ;
	} else {
		lp = &lock_curr ;	iop = &io_curr ;
	}
	if (!*iop && !nonexist){
		*lp = 0 ;
		if ((*iop = open(file, 1)) < 0) *iop = 0 ;
	}
#endif	FLOCKFILE
E 33
	switch (c) {

	case 0:
D 4
		if (!exclam && !value(WRITEANY)) switch (edfile()) {
E 4
I 4
		if (!exclam && (!value(WRITEANY) || value(READONLY)))
		switch (edfile()) {
E 4
		
		case NOTEDF:
			if (nonexist)
				break;
			if ((stbuf.st_mode & S_IFMT) == S_IFCHR) {
				if (samei(&stbuf, "/dev/null"))
					break;
				if (samei(&stbuf, "/dev/tty"))
					break;
			}
			io = open(file, 1);
			if (io < 0)
				syserror();
			if (!isatty(io))
				serror(" File exists| File exists - use \"w! %s\" to overwrite", file);
			close(io);
			break;

I 4
		case EDF:
			if (value(READONLY))
				error(" File is read only");
			break;

E 4
		case PARTBUF:
I 4
			if (value(READONLY))
				error(" File is read only");
E 4
			error(" Use \"w!\" to write partial buffer");
		}
cre:
I 2
/*
E 2
		synctmp();
I 2
*/
I 33
#ifdef	FLOCKFILE
	if (*iop && !*lp != LOCK_EX && !exclam) {
		/*
		 * upgrade to a exclusive lock. if can't get, someone else 
		 * has the exclusive lock. bitch to the user.
		 */
		if (flock(*iop, LOCK_EX|LOCK_NB) < 0 && errno == EWOULDBLOCK)
	error (" File being modified by another process - use \"w!\" to write");
		 else *lp = LOCK_EX ;
	}
#endif	FLOCKFILE
E 33
E 2
#ifdef V6
		io = creat(file, 0644);
#else
		io = creat(file, 0666);
I 34
#ifdef vms	/* to retain file protection modes on newer version of file */
		if (!nonexist)
			chmod(file, stbuf.st_mode & 0777);
#endif
E 34
#endif
		if (io < 0)
			syserror();
I 14
		writing = 1;
E 14
		if (hush == 0)
			if (nonexist)
D 30
				printf(" [New file]");
E 30
I 30
				ex_printf(" [New file]");
E 30
			else if (value(WRITEANY) && edfile() != EDF)
D 30
				printf(" [Existing file]");
E 30
I 30
				ex_printf(" [Existing file]");
I 33
#ifdef	FLOCKFILE
		if (!*iop)
			*iop = dup(io) ;
#endif	FLOCKFILE
E 33
E 30
		break;

	case 2:
		io = open(file, 1);
		if (io < 0) {
			if (exclam || value(WRITEANY))
				goto cre;
			syserror();
		}
		lseek(io, 0l, 2);
I 33
#ifdef	FLOCKFILE
		if (!*iop) *iop = dup(io) ;
		if (*lp != LOCK_EX && !exclam) {
			/*
		 	 * upgrade to a exclusive lock. if can't get,
			 * someone else has the exclusive lock.
			 * bitch to the user.
		 	 */
			if (flock(*iop, LOCK_SH|LOCK_NB) < 0
			&& errno == EWOULDBLOCK)
				error (
" File being modified by another process - use \"w!>>\" to write");
		 	else *lp = LOCK_EX ;
		}
#endif	FLOCKFILE
E 33
		break;
	}
I 33
#ifdef	FLOCKFILE
	if (flock(*iop, LOCK_EX|LOCK_NB) >= 0)
		*lp = LOCK_EX ;
#endif	FLOCKFILE
E 33
D 16
	putfile();
E 16
I 16
	putfile(0);
I 30
#ifndef	vms
E 30
I 29
	(void) fsync(io);
I 30
#endif
E 30
E 29
E 16
	ignore(iostats());
	if (c != 2 && addr1 == one && addr2 == dol) {
		if (eq(file, savedfile))
			edited = 1;
D 30
		sync();
E 30
I 30
		ex_sync();
E 30
	}
	if (!dofname) {
		addr1 = saddr1;
		addr2 = saddr2;
	}
I 14
	writing = 0;
E 14
}

/*
 * Is file the edited file?
 * Work here is that it is not considered edited
 * if this is a partial buffer, and distinguish
 * all cases.
 */
edfile()
{

	if (!edited || !eq(file, savedfile))
		return (NOTEDF);
	return (addr1 == one && addr2 == dol ? EDF : PARTBUF);
}

/*
D 4
 * First part of a shell escape,
 * parse the line, expanding # and % and ! and printing if implied.
 */
unix0(warn)
	bool warn;
{
	register char *up, *fp;
	register short c;
	char printub, puxb[UXBSIZE + sizeof (int)];

	printub = 0;
	CP(puxb, uxb);
	c = getchar();
	if (c == '\n' || c == EOF)
		error("Incomplete shell escape command@- use 'shell' to get a shell");
	up = uxb;
	do {
		switch (c) {

		case '\\':
			if (any(peekchar(), "%#!"))
				c = getchar();
		default:
			if (up >= &uxb[UXBSIZE]) {
tunix:
				uxb[0] = 0;
				error("Command too long");
			}
			*up++ = c;
			break;

		case '!':
			fp = puxb;
			if (*fp == 0) {
				uxb[0] = 0;
				error("No previous command@to substitute for !");
			}
			printub++;
			while (*fp) {
				if (up >= &uxb[UXBSIZE])
					goto tunix;
				*up++ = *fp++;
			}
			break;

		case '#':
			fp = altfile;
			if (*fp == 0) {
				uxb[0] = 0;
				error("No alternate filename@to substitute for #");
			}
			goto uexp;

		case '%':
			fp = savedfile;
			if (*fp == 0) {
				uxb[0] = 0;
				error("No filename@to substitute for %%");
			}
uexp:
			printub++;
			while (*fp) {
				if (up >= &uxb[UXBSIZE])
					goto tunix;
				*up++ = *fp++ | QUOTE;
			}
			break;
		}
		c = getchar();
	} while (c == '|' || !endcmd(c));
	if (c == EOF)
		ungetchar(c);
	*up = 0;
	if (!inopen)
		resetflav();
	if (warn)
		ckaw();
	if (warn && hush == 0 && chng && xchng != chng && value(WARN) && dol > zero) {
		xchng = chng;
		vnfl();
		printf(mesg("[No write]|[No write since last change]"));
		noonl();
		flush();
	} else
		warn = 0;
	if (printub) {
		if (uxb[0] == 0)
			error("No previous command@to repeat");
		if (inopen) {
			splitw++;
			vclean();
			vgoto(WECHO, 0);
		}
		if (warn)
			vnfl();
		if (hush == 0)
			lprintf("!%s", uxb);
D 3
		if (inopen) {
E 3
I 3
		if (inopen && Outchar != termchar) {
E 3
			vclreol();
			vgoto(WECHO, 0);
		} else
			putnl();
		flush();
	}
}

/*
 * Do the real work for execution of a shell escape.
 * Mode is like the number passed to open system calls
 * and indicates filtering.  If input is implied, newstdin
 * must have been setup already.
 */
unixex(opt, up, newstdin, mode)
	char *opt, *up;
	int newstdin, mode;
{
	int pvec[2], f;

	signal(SIGINT, SIG_IGN);
	if (inopen)
		f = setty(normf);
	if ((mode & 1) && pipe(pvec) < 0) {
		/* Newstdin should be io so it will be closed */
		if (inopen)
			setty(f);
		error("Can't make pipe for filter");
	}
#ifndef VFORK
	pid = fork();
#else
	pid = vfork();
#endif
	if (pid < 0) {
		if (mode & 1) {
			close(pvec[0]);
			close(pvec[1]);
		}
		setrupt();
		error("No more processes");
	}
	if (pid == 0) {
		if (mode & 2) {
			close(0);
			dup(newstdin);
			close(newstdin);
		}
		if (mode & 1) {
			close(pvec[0]);
			close(1);
			dup(pvec[1]);
			if (inopen) {
				close(2);
				dup(1);
			}
			close(pvec[1]);
		}
		if (io)
			close(io);
		if (tfile)
			close(tfile);
I 2
#ifndef VMUNIX
E 2
		close(erfile);
I 2
#endif
E 2
		signal(SIGHUP, oldhup);
		signal(SIGQUIT, oldquit);
		if (ruptible)
			signal(SIGINT, SIG_DFL);
		execl(svalue(SHELL), "sh", opt, up, (char *) 0);
		printf("No %s!\n", svalue(SHELL));
		error(NOSTR);
	}
	if (mode & 1) {
		io = pvec[0];
		close(pvec[1]);
	}
	if (newstdin)
		close(newstdin);
	return (f);
}

/*
 * Wait for the command to complete.
 * F is for restoration of tty mode if from open/visual.
 * C flags suppression of printing.
 */
unixwt(c, f)
	bool c;
	int f;
{

	waitfor();
	if (inopen)
		setty(f);
	setrupt();
	if (!inopen && c && hush == 0) {
		printf("!\n");
		flush();
		termreset();
		gettmode();
	}
}

/*
 * Setup a pipeline for the filtration implied by mode
 * which is like a open number.  If input is required to
 * the filter, then a child editor is created to write it.
 * If output is catch it from io which is created by unixex.
 */
filter(mode)
	register int mode;
{
	static int pvec[2];
	register int f;
	register int lines = lineDOL();

	mode++;
	if (mode & 2) {
		signal(SIGINT, SIG_IGN);
		if (pipe(pvec) < 0)
			error("Can't make pipe");
		pid = fork();
		io = pvec[0];
		if (pid < 0) {
			setrupt();
			close(pvec[1]);
			error("No more processes");
		}
		if (pid == 0) {
			setrupt();
			io = pvec[1];
			close(pvec[0]);
			putfile();
			exit(0);
		}
		close(pvec[1]);
		io = pvec[0];
		setrupt();
	}
	f = unixex("-c", uxb, (mode & 2) ? pvec[0] : 0, mode);
	if (mode == 3) {
		delete(0);
		addr2 = addr1 - 1;
	}
	if (mode & 1) {
D 3
		undap1 = undap2 = addr2+1;
E 3
I 3
		if(FIXUNDO)
			undap1 = undap2 = addr2+1;
E 3
		ignore(append(getfile, addr2));
	}
	close(io);
	io = -1;
	unixwt(!inopen, f);
	netchHAD(lines);
}

/*
 * Set up to do a recover, getting io to be a pipe from
 * the recover process.
 */
recover()
{
	static int pvec[2];

	if (pipe(pvec) < 0)
		error(" Can't make pipe for recovery");
	pid = fork();
	io = pvec[0];
	if (pid < 0) {
		close(pvec[1]);
		error(" Can't fork to execute recovery");
	}
	if (pid == 0) {
		close(2);
		dup(1);
		close(1);
		dup(pvec[1]);
	        close(pvec[1]);
		execl(EXRECOVER, "exrecover", svalue(DIRECTORY), file, (char *) 0);
		close(1);
		dup(2);
		error(" No recovery routine");
	}
	close(pvec[1]);
}

/*
 * Wait for the process (pid an external) to complete.
 */
waitfor()
{

	do
		rpid = wait(&status);
	while (rpid != pid && rpid != -1);
	status = (status >> 8) & 0377;
}

/*
 * The end of a recover operation.  If the process
 * exits non-zero, force not edited; otherwise force
 * a write.
 */
revocer()
{

	waitfor();
	if (pid == rpid && status != 0)
		edited = 0;
	else
		change();
}

/*
E 4
 * Extract the next line from the io stream.
 */
D 18
static	char *nextip;
E 18
I 18
D 37
char *nextip;
E 37
I 37
u_char *nextip;
E 37
E 18

getfile()
{
	register short c;
D 37
	register char *lp, *fp;

E 37
I 37
	register u_char *lp, *fp;

E 37
	lp = linebuf;
	fp = nextip;
	do {
		if (--ninbuf < 0) {
D 24
			ninbuf = read(io, genbuf, LBSIZE) - 1;
E 24
I 24
D 30
			ninbuf = read(io, genbuf, bsize) - 1;
E 30
I 30
			ninbuf = read(io, genbuf, (int) bsize) - 1;
E 30
E 24
			if (ninbuf < 0) {
				if (lp != linebuf) {
I 4
					lp++;
E 4
D 30
					printf(" [Incomplete last line]");
E 30
I 30
					ex_printf(" [Incomplete last line]");
E 30
					break;
				}
				return (EOF);
			}
I 6
D 28
D 36
#ifdef CRYPT
E 6
D 23
			fp = genbuf;
I 4
			while(fp < &genbuf[ninbuf]) {
				if (*fp++ & 0200) {
					if (kflag)
E 23
I 23
			if (kflag) {
				fp = genbuf;
				while(fp < &genbuf[ninbuf]) {
					if (*fp++ & 0200) {
E 23
						crblock(perm, genbuf, ninbuf+1,
D 23
cntch);
					break;
E 23
I 23
	cntch);
						break;
					}
E 23
				}
			}
I 6
#endif
E 36
E 28
E 6
			fp = genbuf;
			cntch += ninbuf+1;
E 4
		}
		if (lp >= &linebuf[LBSIZE]) {
			error(" Line too long");
		}
		c = *fp++;
		if (c == 0) {
			cntnull++;
			continue;
		}
D 37
		if (c & QUOTE) {
E 37
I 37
		if (!value(EIGHTBIT) && !isascii(c)) {
E 37
			cntodd++;
D 37
			c &= TRIM;
E 37
I 37
			c &= TRIM7;
E 37
			if (c == 0)
				continue;
		}
		*lp++ = c;
	} while (c != '\n');
D 4
	cntch += lp - linebuf;
E 4
	*--lp = 0;
	nextip = fp;
	cntln++;
	return (0);
}

/*
 * Write a range onto the io stream.
 */
I 30
/* ARGSUSED */
E 30
D 16
putfile()
E 16
I 16
putfile(isfilter)
int isfilter;
E 16
{
	line *a1;
D 37
	register char *fp, *lp;
E 37
I 37
	register u_char *fp, *lp;
E 37
	register int nib;
I 24
	struct stat statb;
E 24

	a1 = addr1;
	clrstats();
	cntln = addr2 - a1 + 1;
	if (cntln == 0)
		return;
D 24
	nib = BUFSIZ;
E 24
I 24
	if (fstat(io, &statb) < 0)
		bsize = LBSIZE;
	else {
		bsize = statb.st_blksize;
		if (bsize <= 0)
			bsize = LBSIZE;
	}
	nib = bsize;
E 24
	fp = genbuf;
	do {
		getline(*a1++);
		lp = linebuf;
		for (;;) {
			if (--nib < 0) {
				nib = fp - genbuf;
I 6
D 28
D 36
#ifdef CRYPT
E 6
I 4
D 16
                		if(kflag)
E 16
I 16
                		if(kflag && !isfilter)
E 16
                                        crblock(perm, genbuf, nib, cntch);
I 6
#endif
E 36
E 28
E 6
E 4
				if (write(io, genbuf, nib) != nib) {
					wrerror();
				}
				cntch += nib;
D 24
				nib = BUFSIZ - 1;
E 24
I 24
				nib = bsize - 1;
E 24
				fp = genbuf;
			}
			if ((*fp++ = *lp++) == 0) {
				fp[-1] = '\n';
				break;
			}
		}
	} while (a1 <= addr2);
	nib = fp - genbuf;
I 6
D 28
D 36
#ifdef CRYPT
E 6
I 4
D 16
	if(kflag)
E 16
I 16
	if(kflag && !isfilter)
E 16
		crblock(perm, genbuf, nib, cntch);
I 6
#endif
E 36
E 28
E 6
E 4
	if (write(io, genbuf, nib) != nib) {
		wrerror();
	}
	cntch += nib;
}

/*
 * A write error has occurred;  if the file being written was
 * the edited file then we consider it to have changed since it is
 * now likely scrambled.
 */
wrerror()
{

	if (eq(file, savedfile) && edited)
		change();
	syserror();
}

/*
 * Source command, handles nested sources.
 * Traps errors since it mungs unit 0 during the source.
 */
D 4
static	short slevel;
E 4
I 4
short slevel;
short ttyindes;
E 4

source(fil, okfail)
D 37
	char *fil;
E 37
I 37
	u_char *fil;
E 37
	bool okfail;
{
	jmp_buf osetexit;
	register int saveinp, ointty, oerrno;
I 14
D 19
	char savepeekc, *saveglobp;
E 19
I 19
D 37
	char *saveglobp;
E 37
I 37
	u_char *saveglobp;
E 37
	short savepeekc;
E 19
E 14
D 4
	int oprompt;
E 4

	signal(SIGINT, SIG_IGN);
	saveinp = dup(0);
I 14
	savepeekc = peekc;
	saveglobp = globp;
	peekc = 0; globp = 0;
E 14
	if (saveinp < 0)
		error("Too many nested sources");
I 4
	if (slevel <= 0)
		ttyindes = saveinp;
E 4
	close(0);
	if (open(fil, 0) < 0) {
		oerrno = errno;
		setrupt();
		dup(saveinp);
		close(saveinp);
		errno = oerrno;
		if (!okfail)
			filioerr(fil);
		return;
	}
	slevel++;
	ointty = intty;
	intty = isatty(0);
	oprompt = value(PROMPT);
	value(PROMPT) &= intty;
	getexit(osetexit);
	setrupt();
	if (setexit() == 0)
		commands(1, 1);
	else if (slevel > 1) {
		close(0);
		dup(saveinp);
		close(saveinp);
		slevel--;
		resexit(osetexit);
		reset();
	}
	intty = ointty;
	value(PROMPT) = oprompt;
	close(0);
	dup(saveinp);
	close(saveinp);
I 14
	globp = saveglobp;
	peekc = savepeekc;
E 14
	slevel--;
	resexit(osetexit);
}

/*
 * Clear io statistics before a read or write.
 */
clrstats()
{

	ninbuf = 0;
	cntch = 0;
	cntln = 0;
	cntnull = 0;
	cntodd = 0;
}

/*
 * Io is finished, close the unit and print statistics.
 */
iostats()
{

I 21
D 29
	(void) fsync(io);
E 29
E 21
	close(io);
	io = -1;
	if (hush == 0) {
		if (value(TERSE))
D 30
			printf(" %d/%D", cntln, cntch);
E 30
I 30
			ex_printf(" %d/%D", cntln, cntch);
E 30
		else
D 30
			printf(" %d line%s, %D character%s", cntln, plural((long) cntln),
E 30
I 30
			ex_printf(" %d line%s, %D character%s", cntln, plural((long) cntln),
E 30
			    cntch, plural(cntch));
		if (cntnull || cntodd) {
D 30
			printf(" (");
E 30
I 30
			ex_printf(" (");
E 30
			if (cntnull) {
D 30
				printf("%D null", cntnull);
E 30
I 30
				ex_printf("%D null", cntnull);
E 30
				if (cntodd)
D 30
					printf(", ");
E 30
I 30
					ex_printf(", ");
E 30
			}
			if (cntodd)
D 30
				printf("%D non-ASCII", cntodd);
			putchar(')');
E 30
I 30
				ex_printf("%D non-ASCII", cntodd);
			ex_putchar(')');
E 30
		}
		noonl();
		flush();
	}
	return (cntnull != 0 || cntodd != 0);
I 16
}

D 30
#if USG | USG3TTY
/* It's so wonderful how we all speak the same language... */
E 30
I 30
#ifdef USG
E 30
# define index strchr
# define rindex strrchr
#endif
I 30
#ifdef USG3TTY
# define index strchr
# define rindex strrchr
#endif
#ifdef vms
# define index strchr
# define rindex strrchr
#endif
E 30

D 35
checkmodeline(line)
char *line;
E 35
I 35
checkmodeline(l)
D 37
char *l;
E 37
I 37
u_char *l;
E 37
E 35
{
D 37
	char *beg, *end;
	char cmdbuf[1024];
E 37
I 37
	u_char *beg, *end;
	u_char cmdbuf[1024];
E 37
D 30
	char *index(), *rindex();
E 30
I 30
	char *index(), *rindex(), *strncpy();
E 30

D 35
	beg = index(line, ':');
E 35
I 35
D 37
	beg = index(l, ':');
E 37
I 37
	beg = (u_char*)index(l, ':');
E 37
E 35
	if (beg == NULL)
		return;
D 22
	if (beg[-2] != 'e' && beg[-2] != 'v') return;
	if (beg[-1] != 'x' && beg[-1] != 'i') return;

E 22
I 22
D 35
	if (&beg[-3] < line)
E 35
I 35
	if (&beg[-3] < l)
E 35
		return;
	if (!(  ( (beg[-3] == ' ' || beg[-3] == '\t')
	        && beg[-2] == 'e'
		&& beg[-1] == 'x')
	     || ( (beg[-3] == ' ' || beg[-3] == '\t')
	        && beg[-2] == 'v'
		&& beg[-1] == 'i'))) return;
E 22
	strncpy(cmdbuf, beg+1, sizeof cmdbuf);
D 37
	end = rindex(cmdbuf, ':');
E 37
I 37
	end = (u_char*)rindex(cmdbuf, ':');
E 37
	if (end == NULL)
		return;
	*end = 0;
	globp = cmdbuf;
	commands(1, 1);
E 16
}
E 1
