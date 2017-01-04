h59985
s 00010/00005/01463
d D 5.8 88/06/29 20:19:38 bostic 31 30
c install approved copyright notice
e
s 00001/00001/01467
d D 5.7 88/04/18 22:02:11 bostic 30 29
c rdist doesn't propagate sticky bits; bug report 4.3BSD/ucb/41
e
s 00009/00003/01459
d D 5.6 88/02/01 11:34:52 bostic 29 28
c add new Berkeley headers
e
s 00001/00001/01461
d D 5.5 87/04/06 12:10:59 bostic 28 27
c printf precision long type
e
s 00004/00002/01458
d D 5.4 87/01/07 19:06:47 sklower 27 26
c fix bug in reporting anonymous groups and uids
e
s 00003/00003/01457
d D 5.3 86/06/07 03:53:00 lepreau 26 25
c Be consistent about not printing hostname on each msg type (execpt on errors)
e
s 00115/00032/01345
d D 5.2 86/03/20 15:45:52 sklower 25 24
c 1.) Don't abort when chown fails on suns
c 2.) Don't abort when uid's not in pw file, just use number
c 3.) Make effort to link when renaming targets.
e
s 00008/00002/01369
d D 5.1 85/06/06 08:53:16 dist 24 23
c Add copyright
e
s 00001/00001/01370
d D 4.23 85/02/14 10:04:07 ralph 23 22
c fix error message when recv() can't write new file.
e
s 00009/00008/01362
d D 4.22 84/12/07 11:54:08 ralph 22 21
c allow symbolic links to replace existing file.
e
s 00082/00101/01288
d D 4.21 84/12/06 14:59:59 ralph 21 20
c added FILE variable for special commands, allow symbolic links to non-existing file
e
s 00001/00000/01388
d D 4.20 84/09/21 10:49:58 ralph 20 19
c fix security hole.
e
s 00011/00011/01377
d D 4.19 84/07/02 10:11:39 ralph 19 18
c fix to symbolic link comparisons.
e
s 00253/00109/01135
d D 4.18 84/06/28 11:45:18 ralph 18 17
c handle symbolic and hard links.
e
s 00004/00004/01240
d D 4.17 84/05/03 11:41:21 ralph 17 16
c added regular expressions for exception pattern matching.
e
s 00005/00005/01239
d D 4.16 84/03/14 11:46:59 ralph 16 15
c fix multiple connections to same (down) host and loss of connection.
e
s 00033/00024/01211
d D 4.15 84/02/09 16:07:07 ralph 15 14
c read entire distfile and sort entries by host.
e
s 00001/00001/01234
d D 4.14 84/01/04 09:37:12 ralph 14 13
c minor fix for directory protection warning.
e
s 00009/00001/01226
d D 4.13 84/01/03 10:36:05 ralph 13 12
c if directory modes don't match, print a warning.
e
s 00008/00014/01219
d D 4.12 83/12/19 14:45:14 ralph 12 11
c making lint happier
e
s 00002/00002/01231
d D 4.11 83/12/09 15:55:02 ralph 11 10
c fix argument type to clean().
e
s 00007/00004/01226
d D 4.10 83/12/01 09:59:21 ralph 10 9
c fix double error message if chog returns an error.
e
s 00002/00001/01228
d D 4.9 83/11/29 16:52:08 ralph 9 8
c added version number for protocol changes.
e
s 00201/00162/01028
d D 4.8 83/11/29 16:00:49 ralph 8 7
c bug fixes and added `special' command.
e
s 00252/00249/00938
d D 4.7 83/11/01 14:29:45 ralph 7 6
c fixes for -r and -w.
e
s 00110/00070/01077
d D 4.6 83/10/26 11:42:50 ralph 6 5
c added -b option for binary compare. Fixed -r w/ except.
e
s 00310/00004/00837
d D 4.5 83/10/20 12:15:12 ralph 5 4
c added -r option to remove extra files.
e
s 00038/00026/00803
d D 4.4 83/10/12 16:39:19 ralph 4 3
c fixed install flags, file comparisons, mail addresses, added -c.
e
s 00180/00132/00649
d D 4.3 83/10/10 16:16:18 ralph 3 2
c stable version that works.
e
s 00148/00094/00633
d D 4.2 83/09/27 14:39:11 ralph 2 1
c First stable version.
e
s 00727/00000/00000
d D 4.1 83/09/07 13:20:32 ralph 1 0
c date and time created 83/09/07 13:20:32 by ralph
e
u
U
t
T
I 24
/*
 * Copyright (c) 1983 Regents of the University of California.
D 29
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 29
I 29
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 31
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 31
I 31
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
E 31
E 29
 */

E 24
I 1
#ifndef lint
D 24
static	char *sccsid = "%W% (Berkeley) %E%";
#endif
E 24
I 24
static char sccsid[] = "%W% (Berkeley) %G%";
D 29
#endif not lint
E 29
I 29
#endif /* not lint */
E 29
E 24

#include "defs.h"

D 6
#define	ga() 	(void) write(rem, "", 1)
E 6
I 6
D 8
#define	ga() 	(void) write(rem, "\0\n", 2)
E 8
I 8
#define	ack() 	(void) write(rem, "\0\n", 2)
#define	err() 	(void) write(rem, "\1\n", 2)
E 8
E 6

I 18
struct	linkbuf *ihead;		/* list of files with more than one link */
E 18
D 2
char	buf[BUFSIZ];		/* gerneral purpose buffer */
E 2
I 2
char	buf[BUFSIZ];		/* general purpose buffer */
E 2
char	target[BUFSIZ];		/* target/source directory name */
char	*tp;			/* pointer to end of target name */
I 25
char	*Tdest;			/* pointer to last T dest*/
E 25
int	catname;		/* cat name to target name */
I 3
char	*stp[32];		/* stack of saved tp's for directories */
D 7
int	sumask;			/* saved umask for creating files */
E 7
I 7
int	oumask;			/* old umask for creating files */
E 7
E 3

I 2
D 7
static struct passwd *p = NULL;
static struct group *g = NULL;

E 7
extern	FILE *lfp;		/* log file for mailing changes */

I 15
int	cleanup();
I 18
struct	linkbuf *savelink();
E 18

E 15
I 3
D 8
extern char *exptilde();

E 8
E 3
E 2
/*
 * Server routine to read requests and process them.
 * Commands are:
 *	Tname	- Transmit file if out of date
 *	Vname	- Verify if file out of date or not
 *	Qname	- Query if file exists. Return mtime & size if it does.
 */
server()
{
	char cmdbuf[BUFSIZ];
	register char *cp;
D 7
	register struct block *bp, *last = NULL;
E 7
I 7
D 12
	register struct block *bp = NULL;
E 7
D 3
	register int n;
E 3
D 6
	static struct block cmdblk = { EXCEPT };
E 6
I 5
	int opts;
E 12
E 5

I 15
	signal(SIGHUP, cleanup);
	signal(SIGINT, cleanup);
	signal(SIGQUIT, cleanup);
	signal(SIGTERM, cleanup);
	signal(SIGPIPE, cleanup);

	rem = 0;
E 15
D 3
	(void) umask(0);
E 3
I 3
D 7
	sumask = umask(0);
E 7
I 7
	oumask = umask(0);
E 7
E 3
D 8
	ga();
E 8
I 8
D 9
	ack();
E 9
I 9
	(void) sprintf(buf, "V%d\n", VERSION);
	(void) write(rem, buf, strlen(buf));
E 9
E 8

	for (;;) {
		cp = cmdbuf;
		if (read(rem, cp, 1) <= 0)
			return;
		if (*cp++ == '\n') {
D 7
			error("expected control record\n");
E 7
I 7
			error("server: expected control record\n");
E 7
			continue;
		}
		do {
			if (read(rem, cp, 1) != 1)
D 15
				lostconn();
E 15
I 15
				cleanup();
E 15
D 2
		} while (*cp++ != '\n');
E 2
I 2
		} while (*cp++ != '\n' && cp < &cmdbuf[BUFSIZ]);
E 2
		*--cp = '\0';
		cp = cmdbuf;
		switch (*cp++) {
D 7
		case 'X':  /* add name to list of files to exclude */
			if (*cp == '\0')
				continue;
D 6
			bp = ALLOC(block);
			if (bp == NULL)
				fatal("ran out of memory\n");
			bp->b_type = NAME;
			bp->b_next = bp->b_args = NULL;
D 3
			bp->b_name = cp = (char *) malloc(strlen(cp) + 1);
E 3
I 3
			bp->b_name = cp = malloc(strlen(cp) + 1);
E 3
			if (cp == NULL)
				fatal("ran out of memory\n");
			strcpy(cp, &cmdbuf[1]);
			if (last == NULL) {
				except = &cmdblk;
				cmdblk.b_args = last = bp;
			} else {
E 6
I 6
			if (*cp == '~') {
				exptilde(buf, cp);
				cp = buf;
			}
			bp = makeblock(EXCEPT);
			bp->b_args = expand(makeblock(NAME, cp), 0);
			if (last == NULL)
				except = last = bp;
			else {
E 6
				last->b_next = bp;
				last = bp;
			}
			continue;

E 7
		case 'T':  /* init target file/directory name */
I 2
			catname = 1;	/* target should be directory */
			goto dotarget;

		case 't':  /* init target file/directory name */
E 2
			catname = 0;
D 2
			shexpand(target, cp);
E 2
I 2
		dotarget:
D 3
			exptilde(target, cp);
E 3
I 3
D 7
			(void) exptilde(target, cp);
E 7
I 7
			if (exptilde(target, cp) == NULL)
				continue;
E 7
E 3
E 2
			tp = target;
			while (*tp)
				tp++;
I 7
D 8
			ga();
E 8
I 8
			ack();
E 8
E 7
			continue;

D 7
		case 'S':  /* Send. Transfer file if out of date. */
D 3
			tp = NULL;
			sendf(cp, 0);
E 3
I 3
			sendf(cp, NULL, 0);
E 3
			continue;

		case 'V':  /* Verify. See if file is out of date. */
D 3
			tp = NULL;
			sendf(cp, 1);
E 3
I 3
			sendf(cp, NULL, VERIFY);
E 3
			continue;

E 7
D 18
		case 'R':  /* Receive. Transfer file. */
			recvf(cp, 0);
E 18
I 18
		case 'R':  /* Transfer a regular file. */
			recvf(cp, S_IFREG);
E 18
			continue;

D 18
		case 'D':  /* Directory. Transfer file. */
			recvf(cp, 1);
E 18
I 18
		case 'D':  /* Transfer a directory. */
			recvf(cp, S_IFDIR);
E 18
			continue;

I 18
		case 'K':  /* Transfer symbolic link. */
			recvf(cp, S_IFLNK);
			continue;

		case 'k':  /* Transfer hard link. */
			hardlink(cp);
			continue;

E 18
		case 'E':  /* End. (of directory) */
			*tp = '\0';
D 2
			cp = rindex(target, '/');
			if (cp == NULL || --catname < 0) {
E 2
I 2
D 7
			if (--catname < 0) {
E 2
				error("too many 'E's\n");
E 7
I 7
			if (catname <= 0) {
				error("server: too many 'E's\n");
E 7
				continue;
			}
D 2
			*cp = '\0';
			tp = cp;
E 2
I 2
D 3
			cp = rindex(target, '/');
			if (cp == NULL)
				tp = NULL;
			else {
				*cp = '\0';
				tp = cp;
			}
E 3
I 3
D 7
			tp = stp[catname];
E 7
I 7
			tp = stp[--catname];
E 7
			*tp = '\0';
E 3
E 2
D 8
			ga();
E 8
I 8
			ack();
E 8
			continue;

I 5
		case 'C':  /* Clean. Cleanup a directory */
D 7
			if (*cp < '0' || *cp > '7') {
				error("bad options\n");
E 7
I 7
D 8
			opts = 0;
			while (*cp >= '0' && *cp <= '7')
				opts = (opts << 3) | (*cp++ - '0');
			if (*cp++ != ' ')
				error("server: options not delimited\n");
			else
				clean(cp, opts, 1);
E 8
I 8
			clean(cp);
E 8
			continue;

		case 'Q':  /* Query. Does the file/directory exist? */
			query(cp);
			continue;

I 8
		case 'S':  /* Special. Execute commands */
			dospecial(cp);
			continue;

E 8
#ifdef notdef
		/*
		 * These entries are reserved but not currently used.
		 * The intent is to allow remote hosts to have master copies.
		 * Currently, only the host rdist runs on can have masters.
		 */
		case 'X':  /* start a new list of files to exclude */
			except = bp = NULL;
		case 'x':  /* add name to list of files to exclude */
			if (*cp == '\0') {
D 8
				ga();
E 8
I 8
				ack();
E 8
E 7
				continue;
			}
D 7
			opts = *cp++ - '0';
			if (*cp++ != ' ') {
				error("options not delimited\n");
				continue;
E 7
I 7
			if (*cp == '~') {
				if (exptilde(buf, cp) == NULL)
					continue;
				cp = buf;
E 7
			}
D 7
			clean(cp, opts, 1);
E 7
I 7
			if (bp == NULL)
D 8
				except = bp = expand(makeblock(NAME, cp), 0);
E 8
I 8
				except = bp = expand(makeblock(NAME, cp), E_VARS);
E 8
			else
D 8
				bp->b_next = expand(makeblock(NAME, cp), 0);
E 8
I 8
				bp->b_next = expand(makeblock(NAME, cp), E_VARS);
E 8
			while (bp->b_next != NULL)
				bp = bp->b_next;
D 8
			ga();
E 8
I 8
			ack();
E 8
E 7
			continue;

E 5
D 3
		case 'Q':  /* Query. Does file exist? */
			query(cp);
E 3
I 3
D 7
		case 'Q':  /* Query. Does directory exist? */
			query(cp, 1);
E 7
I 7
D 8
		case 'S':  /* Send. Transfer file if out of date. */
E 8
I 8
		case 'I':  /* Install. Transfer file if out of date. */
E 8
			opts = 0;
			while (*cp >= '0' && *cp <= '7')
				opts = (opts << 3) | (*cp++ - '0');
			if (*cp++ != ' ') {
				error("server: options not delimited\n");
				return;
			}
D 8
			sendf(cp, opts);
E 8
I 8
			install(cp, opts);
E 8
E 7
E 3
			continue;

I 3
D 7
		case 'q':  /* query. Does file exist? */
			query(cp, 0);
			continue;

E 7
E 3
		case 'L':  /* Log. save message in log file */
D 3
			query(cp);
E 3
I 3
			log(lfp, cp);
E 3
			continue;
I 7
#endif
E 7

I 2
		case '\1':
D 15
			errs++;
E 15
I 15
			nerrs++;
E 15
			continue;

		case '\2':
			return;

E 2
		default:
D 7
			error("unknown command type %s\n", cp);
E 7
I 7
			error("server: unknown command '%s'\n", cp);
E 7
		case '\0':
			continue;
		}
	}
}

/*
D 7
 * Transfer the file or directory 'name'.
E 7
I 7
 * Update the file(s) if they are different.
 * destdir = 1 if destination should be a directory
 * (i.e., more than one source is being copied to the same destination).
E 7
 */
D 3
sendf(name, verify)
	char *name;
	int verify;
E 3
I 3
D 4
sendf(lname, rname, options)
E 4
I 4
D 7
sendf(lname, rname, opts)
E 4
	char *lname, *rname;
D 4
	int options;
E 4
I 4
	int opts;
E 7
I 7
install(src, dest, destdir, opts)
	char *src, *dest;
	int destdir, opts;
E 7
E 4
E 3
{
D 3
	register char *last;
E 3
I 3
D 7
	register char *cp;
E 3
D 2
	struct passwd *p;
	struct group *g;
E 2
	struct stat stb;
D 2
	int sizerr, f;
E 2
I 2
	int sizerr, f, u;
E 2
	off_t i;
E 7
I 7
	char *rname;
I 25
	char destcopy[BUFSIZ];
E 25
E 7

D 7
	if (debug)
D 3
		printf("sendf(%s, %d)\n", name, verify);
E 3
I 3
		printf("sendf(%s, %s, %x)\n", lname,
D 4
			rname != NULL ? rname : "NULL", options);
E 4
I 4
			rname != NULL ? rname : "NULL", opts);
E 7
I 7
	if (dest == NULL) {
		opts &= ~WHOLE; /* WHOLE mode only useful if renaming */
		dest = src;
	}
E 7
E 4
E 3

I 7
	if (nflag || debug) {
		printf("%s%s%s%s%s %s %s\n", opts & VERIFY ? "verify":"install",
			opts & WHOLE ? " -w" : "",
			opts & YOUNGER ? " -y" : "",
			opts & COMPARE ? " -b" : "",
D 8
			opts & REMOVE ? " -r" : "", src, dest);
E 8
I 8
			opts & REMOVE ? " -R" : "", src, dest);
E 8
		if (nflag)
			return;
	}

	rname = exptilde(target, src);
	if (rname == NULL)
		return;
	tp = target;
	while (*tp)
		tp++;
E 7
D 3
	if (exclude(name))
E 3
I 3
D 6
	if (exclude(lname))
E 3
		return;

E 6
I 2
	/*
D 3
	 * first time sendf() is called?
E 3
I 3
D 7
	 * First time sendf() is called?
E 7
I 7
	 * If we are renaming a directory and we want to preserve
D 8
	 * the directory heirarchy (-w), we must strip off the first
E 8
I 8
	 * the directory heirarchy (-w), we must strip off the leading
E 8
	 * directory name and preserve the rest.
E 7
E 3
	 */
D 3
	if (tp == NULL) {
		exptilde(target, name);
		tp = name = target;
E 3
I 3
D 7
	if (rname == NULL) {
		rname = exptilde(target, lname);
		if (rname == NULL)
			return;
		tp = lname = target;
E 3
		while (*tp)
			tp++;
I 3
		/*
		 * If we are renaming a directory and we want to preserve
		 * the directory heirarchy (-w), we must strip off the first
		 * directory name and preserve the rest.
		 */
D 4
		if (options & STRIP) {
			options &= ~STRIP;
E 4
I 4
		if (opts & STRIP) {
			opts &= ~STRIP;
E 7
I 7
	if (opts & WHOLE) {
D 8
		if (!destdir) {
E 7
E 4
			rname = index(rname, '/');
			if (rname == NULL)
D 7
				rname = tp;
			else
E 7
I 7
				rname = tp; /* doesn't matter what rname is */
			else {
				destdir++; /* cat rname to dest */
E 7
				rname++;
D 4
		} else if (!(options & WHOLE)) {
E 4
I 4
D 7
		} else if (!(opts & WHOLE)) {
E 4
			rname = rindex(lname, '/');
			if (rname == NULL)
				rname = lname;
			else
				rname++;
E 7
I 7
			}
E 7
		}
E 8
I 8
		while (*rname == '/')
			rname++;
		destdir = 1;
E 8
I 7
	} else {
		rname = rindex(target, '/');
		if (rname == NULL)
			rname = target;
		else
			rname++;
E 7
E 3
	}
I 6
D 7
	if (exclude(lname))
E 7
I 7
	if (debug)
		printf("target = %s, rname = %s\n", target, rname);
	/*
	 * Pass the destination file/directory name to remote.
	 */
	(void) sprintf(buf, "%c%s\n", destdir ? 'T' : 't', dest);
	if (debug)
		printf("buf = %s", buf);
	(void) write(rem, buf, strlen(buf));
	if (response() < 0)
E 7
		return;
E 6
E 2
D 3
	if (access(name, 4) < 0 || stat(name, &stb) < 0) {
		error("%s: %s\n", name, sys_errlist[errno]);
E 3
I 3
D 7
	if (access(lname, 4) < 0 || stat(lname, &stb) < 0) {
		error("%s: %s\n", lname, sys_errlist[errno]);
E 7
I 7

I 25
	if (destdir) {
		strcpy(destcopy, dest);
		Tdest = destcopy;
	}
E 25
	sendf(rname, opts);
I 25
	Tdest = 0;
E 25
}

I 25
#define protoname() (pw ? pw->pw_name : user)
#define protogroup() (gr ? gr->gr_name : group)
E 25
/*
 * Transfer the file or directory in target[].
 * rname is the name of the file on the remote host.
 */
sendf(rname, opts)
	char *rname;
	int opts;
{
D 12
	register char *cp;
E 12
I 8
D 15
	register struct block *c;
E 15
I 15
	register struct subcmd *sc;
E 15
E 8
	struct stat stb;
D 18
	int sizerr, f, u;
E 18
I 18
	int sizerr, f, u, len;
E 18
	off_t i;
I 18
	DIR *d;
	struct direct *dp;
	char *otp, *cp;
E 18
I 8
D 15
	extern struct block *special;
E 15
I 15
D 17
	extern struct subcmd *special;
E 17
I 17
	extern struct subcmd *subcmds;
I 25
	static char user[15], group[15];
E 25
E 17
E 15
E 8

	if (debug)
		printf("sendf(%s, %x)\n", rname, opts);

D 8
	if (exclude(target))
E 8
I 8
D 17
	if (inlist(except, target))
E 17
I 17
	if (except(target))
E 17
E 8
E 7
E 3
		return;
I 7
D 8
	if (access(target, 4) < 0 || stat(target, &stb) < 0) {
E 8
I 8
D 18
	if (access(target, 4) < 0 || lstat(target, &stb) < 0) {
E 18
I 18
D 21
	if (access(target, 4) < 0 ||
	    (opts & FOLLOW ? stat(target, &stb) : lstat(target, &stb)) < 0) {
E 21
I 21
	if ((opts & FOLLOW ? stat(target, &stb) : lstat(target, &stb)) < 0) {
E 21
E 18
E 8
		error("%s: %s\n", target, sys_errlist[errno]);
		return;
E 7
	}
D 3
	last = rindex(name, '/');
	if (last == NULL)
		last = name;
	else
		last++;
D 2
	if (!update(last, &stb))
E 2
I 2
	if ((u = update(last, &stb)) == 0)
E 3
I 3
D 4
	if ((u = update(lname, rname, options, &stb)) == 0)
E 4
I 4
D 7
	if ((u = update(lname, rname, opts, &stb)) == 0)
E 7
I 7
D 8
	if (opts & REMOVE) {
		opts &= ~REMOVE;
		if (ISDIR(stb.st_mode))
			rmchk(rname, opts);
	}
E 8
D 18
	if ((u = update(rname, opts, &stb)) == 0)
E 18
I 18
	if ((u = update(rname, opts, &stb)) == 0) {
		if ((stb.st_mode & S_IFMT) == S_IFREG && stb.st_nlink > 1)
			(void) savelink(&stb);
E 18
E 7
E 4
E 3
E 2
		return;
I 18
	}
E 18

D 2
	setpwent();
	if ((p = getpwuid(stb.st_uid)) == NULL) {
		error("no password entry for uid %d\n", stb.st_uid);
		return;
	}
	endpwent();
	setgrent();
	if ((g = getgrgid(stb.st_gid)) == NULL) {
		error("no name for group %d\n", stb.st_gid);
		return;
	}
	endgrent();
E 2
I 2
D 7
	if (p == NULL || p->pw_uid != stb.st_uid)
		if ((p = getpwuid(stb.st_uid)) == NULL) {
D 6
			error("no password entry for uid %d\n", stb.st_uid);
E 6
I 6
			error("%s: no password entry for uid %d\n",
				lname, stb.st_uid);
E 7
I 7
	if (pw == NULL || pw->pw_uid != stb.st_uid)
		if ((pw = getpwuid(stb.st_uid)) == NULL) {
D 25
			error("%s: no password entry for uid %d\n", target,
				stb.st_uid);
E 7
E 6
			return;
E 25
I 25
D 27
			log(lfp, "%s: no password entry for uid \n", target);
E 27
I 27
			log(lfp, "%s: no password entry for uid %d \n",
				target, stb.st_uid);
E 27
			pw = NULL;
			sprintf(user, ":%d", stb.st_uid);
E 25
		}
D 7
	if (g == NULL || g->gr_gid != stb.st_gid)
		if ((g = getgrgid(stb.st_gid)) == NULL) {
D 6
			error("no name for group %d\n", stb.st_gid);
E 6
I 6
			error("%s: no name for group %d\n",
				lname, stb.st_gid);
E 7
I 7
	if (gr == NULL || gr->gr_gid != stb.st_gid)
		if ((gr = getgrgid(stb.st_gid)) == NULL) {
D 25
			error("%s: no name for group %d\n", target, stb.st_gid);
E 7
E 6
			return;
E 25
I 25
D 27
			log(lfp, "%s: no name for group %d\n", target);
E 27
I 27
			log(lfp, "%s: no name for group %d\n",
				target, stb.st_gid);
E 27
			gr = NULL;
			sprintf(group, ":%d", stb.st_gid);
E 25
		}
I 6
	if (u == 1) {
I 8
		if (opts & VERIFY) {
			log(lfp, "need to install: %s\n", target);
			goto dospecial;
		}
E 8
D 7
		log(lfp, "installing: %s\n", lname);
E 7
I 7
		log(lfp, "installing: %s\n", target);
E 7
D 8
		if (opts & VERIFY)
			return;
		opts &= ~COMPARE;
E 8
I 8
		opts &= ~(COMPARE|REMOVE);
E 8
	}
E 6
E 2

	switch (stb.st_mode & S_IFMT) {
D 18
	case S_IFREG:
		break;
E 18
I 18
	case S_IFDIR:
		if ((d = opendir(target)) == NULL) {
			error("%s: %s\n", target, sys_errlist[errno]);
			return;
		}
		(void) sprintf(buf, "D%o %04o 0 0 %s %s %s\n", opts,
D 25
			stb.st_mode & 07777, pw->pw_name, gr->gr_name, rname);
E 25
I 25
			stb.st_mode & 07777, protoname(), protogroup(), rname);
E 25
		if (debug)
I 19
			printf("buf = %s", buf);
E 19
		(void) write(rem, buf, strlen(buf));
		if (response() < 0) {
			closedir(d);
			return;
		}
E 18

I 8
D 18
	case S_IFLNK:
		error("%s: cannot install soft links - use 'special'\n", target);
		return;
E 18
I 18
		if (opts & REMOVE)
			rmchk(opts);
E 18

E 8
D 18
	case S_IFDIR:
D 3
		rsendf(name, verify, &stb, p->pw_name, g->gr_name);
E 3
I 3
D 4
		rsendf(lname, rname, options, &stb, p->pw_name, g->gr_name);
E 4
I 4
D 7
		rsendf(lname, rname, opts, &stb, p->pw_name, g->gr_name);
E 7
I 7
		rsendf(rname, opts, &stb, pw->pw_name, gr->gr_name);
E 18
I 18
		otp = tp;
		len = tp - target;
		while (dp = readdir(d)) {
			if (!strcmp(dp->d_name, ".") ||
			    !strcmp(dp->d_name, ".."))
				continue;
			if (len + 1 + strlen(dp->d_name) >= BUFSIZ - 1) {
				error("%s/%s: Name too long\n", target,
					dp->d_name);
				continue;
			}
			tp = otp;
			*tp++ = '/';
			cp = dp->d_name;
			while (*tp++ = *cp++)
				;
			tp--;
			sendf(dp->d_name, opts);
		}
		closedir(d);
		(void) write(rem, "E\n", 2);
		(void) response();
		tp = otp;
		*tp = '\0';
E 18
E 7
E 4
E 3
		return;

I 18
	case S_IFLNK:
		if (u != 1)
			opts |= COMPARE;
I 25
		if (stb.st_nlink > 1) {
			struct linkbuf *lp;

			if ((lp = savelink(&stb)) != NULL) {
				/* install link */
				if (*lp->target == 0)
				(void) sprintf(buf, "k%o %s %s\n", opts,
					lp->pathname, rname);
				else
				(void) sprintf(buf, "k%o %s/%s %s\n", opts,
					lp->target, lp->pathname, rname);
				if (debug)
					printf("buf = %s", buf);
				(void) write(rem, buf, strlen(buf));
				(void) response();
				return;
			}
		}
E 25
D 21
		(void) sprintf(buf, "K%o %o %D %D %s %s %s\n", opts,
E 21
I 21
		(void) sprintf(buf, "K%o %o %ld %ld %s %s %s\n", opts,
E 21
			stb.st_mode & 07777, stb.st_size, stb.st_mtime,
D 25
			pw->pw_name, gr->gr_name, rname);
E 25
I 25
			protoname(), protogroup(), rname);
E 25
		if (debug)
			printf("buf = %s", buf);
		(void) write(rem, buf, strlen(buf));
		if (response() < 0)
			return;
		sizerr = (readlink(target, buf, BUFSIZ) != stb.st_size);
		(void) write(rem, buf, stb.st_size);
		if (debug)
D 28
			printf("readlink = %.*s\n", stb.st_size, buf);
E 28
I 28
			printf("readlink = %.*s\n", (int)stb.st_size, buf);
E 28
		goto done;

	case S_IFREG:
		break;

E 18
	default:
D 3
		error("%s: not a plain file\n", name);
E 3
I 3
D 7
		error("%s: not a plain file\n", lname);
E 7
I 7
D 18
		error("%s: not a plain file\n", target);
E 18
I 18
		error("%s: not a file or directory\n", target);
E 18
E 7
E 3
		return;
	}

D 2
	if ((f = open(name, 0)) < 0) {
		error("%s: %s\n", name, sys_errlist[errno]);
		return;
	}
	log("updating: %s\n", name);
E 2
I 2
D 3
	log(lfp, "%s: %s\n", u == 2 ? "updating" : "installing", name);
E 3
I 3
D 6
	log(lfp, "%s: %s\n", u == 2 ? "updating" : "installing", lname);
E 6
I 6
	if (u == 2) {
I 8
		if (opts & VERIFY) {
			log(lfp, "need to update: %s\n", target);
			goto dospecial;
		}
E 8
D 7
		log(lfp, "updating: %s\n", lname);
E 7
I 7
		log(lfp, "updating: %s\n", target);
E 7
D 8
		if (opts & VERIFY)
			return;
E 8
	}
I 8
D 18
	if (stb.st_nlink != 1)
		log(lfp, "%s: Warning: more than one hard link\n", target);
E 18
E 8
E 6
E 3
E 2

I 18
	if (stb.st_nlink > 1) {
		struct linkbuf *lp;

		if ((lp = savelink(&stb)) != NULL) {
			/* install link */
I 25
			if (*lp->target == 0)
E 25
			(void) sprintf(buf, "k%o %s %s\n", opts,
				lp->pathname, rname);
I 25
			else
			(void) sprintf(buf, "k%o %s/%s %s\n", opts,
				lp->target, lp->pathname, rname);
E 25
			if (debug)
				printf("buf = %s", buf);
			(void) write(rem, buf, strlen(buf));
			(void) response();
			return;
		}
	}

E 18
D 3
	if (verify || vflag)
E 3
I 3
D 4
	if ((options & VERIFY) || vflag)
E 4
I 4
D 6
	if (opts & VERIFY)
E 4
E 3
		return;

E 6
I 2
D 3
	if ((f = open(name, 0)) < 0) {
		error("%s: %s\n", name, sys_errlist[errno]);
E 3
I 3
D 7
	if ((f = open(lname, 0)) < 0) {
		error("%s: %s\n", lname, sys_errlist[errno]);
E 7
I 7
	if ((f = open(target, 0)) < 0) {
		error("%s: %s\n", target, sys_errlist[errno]);
E 7
E 3
		return;
	}
E 2
D 4
	(void) sprintf(buf, "R%04o %D %D %s %s %s\n", stb.st_mode & 07777,
D 3
		stb.st_size, stb.st_mtime, p->pw_name, g->gr_name, last);
E 3
I 3
		stb.st_size, stb.st_mtime, p->pw_name, g->gr_name, rname);
E 4
I 4
D 6
	(void) sprintf(buf, "R%1o %04o %D %D %s %s %s\n", opts,
E 6
I 6
D 18
	(void) sprintf(buf, "R%o %04o %D %D %s %s %s\n", opts,
E 18
I 18
D 21
	(void) sprintf(buf, "R%o %o %D %D %s %s %s\n", opts,
E 21
I 21
	(void) sprintf(buf, "R%o %o %ld %ld %s %s %s\n", opts,
E 21
E 18
E 6
		stb.st_mode & 07777, stb.st_size, stb.st_mtime,
D 7
		p->pw_name, g->gr_name, rname);
E 7
I 7
D 25
		pw->pw_name, gr->gr_name, rname);
E 25
I 25
		protoname(), protogroup(), rname);
E 25
E 7
E 4
E 3
	if (debug)
		printf("buf = %s", buf);
	(void) write(rem, buf, strlen(buf));
	if (response() < 0) {
		(void) close(f);
		return;
	}
	sizerr = 0;
	for (i = 0; i < stb.st_size; i += BUFSIZ) {
		int amt = BUFSIZ;
		if (i + amt > stb.st_size)
			amt = stb.st_size - i;
		if (sizerr == 0 && read(f, buf, amt) != amt)
			sizerr = 1;
		(void) write(rem, buf, amt);
	}
	(void) close(f);
I 18
done:
E 18
D 8
	if (sizerr)
E 8
I 8
	if (sizerr) {
E 8
D 3
		error("%s: file changed size\n", name);
E 3
I 3
D 7
		error("%s: file changed size\n", lname);
E 7
I 7
		error("%s: file changed size\n", target);
E 7
E 3
D 8
	else
		ga();
	(void) response();
E 8
I 8
		err();
	} else
		ack();
D 18
	if (response() == 0 && (opts & COMPARE))
E 18
I 18
	f = response();
	if (f < 0 || f == 0 && (opts & COMPARE))
E 18
		return;
dospecial:
D 15
	for (c = special; c != NULL; c = c->b_next) {
		if (c->b_type != SPECIAL)
E 15
I 15
D 17
	for (sc = special; sc != NULL; sc = sc->sc_next) {
E 17
I 17
	for (sc = subcmds; sc != NULL; sc = sc->sc_next) {
E 17
		if (sc->sc_type != SPECIAL)
E 15
			continue;
D 15
		if (!inlist(c->b_args, target))
E 15
I 15
D 21
		if (!inlist(sc->sc_args, target))
E 21
I 21
		if (sc->sc_args != NULL && !inlist(sc->sc_args, target))
E 21
E 15
			continue;
D 15
		log(lfp, "special \"%s\"\n", c->b_name);
E 15
I 15
		log(lfp, "special \"%s\"\n", sc->sc_name);
E 15
		if (opts & VERIFY)
			continue;
D 15
		(void) sprintf(buf, "S%s\n", c->b_name);
E 15
I 15
D 21
		(void) sprintf(buf, "S%s\n", sc->sc_name);
E 21
I 21
		(void) sprintf(buf, "SFILE=%s;%s\n", target, sc->sc_name);
E 21
E 15
		if (debug)
			printf("buf = %s", buf);
		(void) write(rem, buf, strlen(buf));
		while (response() > 0)
			;
	}
E 8
}

D 3
rsendf(name, verify, st, owner, group)
	char *name;
	int verify;
E 3
I 3
D 4
rsendf(lname, rname, options, st, owner, group)
E 4
I 4
D 7
rsendf(lname, rname, opts, st, owner, group)
E 4
	char *lname, *rname;
E 7
I 7
D 18
rsendf(rname, opts, st, owner, group)
	char *rname;
E 7
D 4
	int options;
E 4
I 4
	int opts;
E 4
E 3
	struct stat *st;
	char *owner, *group;
E 18
I 18
struct linkbuf *
savelink(stp)
	struct stat *stp;
E 18
{
D 18
	DIR *d;
	struct direct *dp;
D 3
	register char *last;
	char *otp;
E 3
I 3
	char *otp, *cp;
E 3
I 2
	int len;
E 18
I 18
	struct linkbuf *lp;
	int found = 0;
E 18
E 2

D 18
	if (debug)
D 3
		printf("rsendf(%s, %d, %x, %s, %s)\n", name, verify, st,
			owner, group);
E 3
I 3
D 7
		printf("rsendf(%s, %s, %x, %x, %s, %s)\n", lname, rname,
D 4
			options, st, owner, group);
E 4
I 4
			opts, st, owner, group);
E 7
I 7
		printf("rsendf(%s, %x, %x, %s, %s)\n", rname, opts, st,
			owner, group);
E 7
E 4
E 3

D 3
	if ((d = opendir(name)) == NULL) {
		error("%s: %s\n", name, sys_errlist[errno]);
E 3
I 3
D 7
	if ((d = opendir(lname)) == NULL) {
		error("%s: %s\n", lname, sys_errlist[errno]);
E 7
I 7
	if ((d = opendir(target)) == NULL) {
		error("%s: %s\n", target, sys_errlist[errno]);
E 7
E 3
		return;
	}
D 3
	last = rindex(name, '/');
	if (last == NULL)
		last = name;
	else
		last++;
E 3
D 4
	(void) sprintf(buf, "D%04o 0 0 %s %s %s\n", st->st_mode & 07777,
D 3
		owner, group, last);
E 3
I 3
		owner, group, rname);
E 4
I 4
D 6
	(void) sprintf(buf, "D%1o %04o 0 0 %s %s %s\n", opts,
E 6
I 6
	(void) sprintf(buf, "D%o %04o 0 0 %s %s %s\n", opts,
E 6
D 8
		st->st_mode & 07777, owner, group, rname);
E 8
I 8
		st->st_mode & 0777, owner, group, rname);
E 8
E 4
E 3
	if (debug)
		printf("buf = %s", buf);
	(void) write(rem, buf, strlen(buf));
	if (response() < 0) {
		closedir(d);
		return;
	}
I 8

	if (opts & REMOVE)
		rmchk(opts);

E 8
D 2
	/*
	 * first time rsendf() is called?
	 */
	if (tp == NULL) {
		tp = target;
		last = name;
		while (*tp++ = *last++)
			;
		tp--;
	}
E 2
	otp = tp;
I 2
	len = tp - target;
E 2
	while (dp = readdir(d)) {
D 2
		if (dp->d_ino == 0)
			continue;
E 2
		if (!strcmp(dp->d_name, ".") || !strcmp(dp->d_name, ".."))
			continue;
D 2
		if (strlen(name) + 1 + strlen(dp->d_name) >= BUFSIZ - 1) {
E 2
I 2
		if (len + 1 + strlen(dp->d_name) >= BUFSIZ - 1) {
E 2
D 3
			error("%s/%s: Name too long\n", name, dp->d_name);
E 3
I 3
			error("%s/%s: Name too long\n", target, dp->d_name);
E 3
			continue;
E 18
I 18
	for (lp = ihead; lp != NULL; lp = lp->nextp)
		if (lp->inum == stp->st_ino && lp->devnum == stp->st_dev) {
			lp->count--;
			return(lp);
E 18
		}
D 18
		tp = otp;
		*tp++ = '/';
D 3
		last = dp->d_name;
		while (*tp++ = *last++)
E 3
I 3
		cp = dp->d_name;
		while (*tp++ = *cp++)
E 3
			;
		tp--;
D 3
		sendf(target, verify);
E 3
I 3
D 4
		sendf(target, dp->d_name, options);
E 4
I 4
D 7
		sendf(target, dp->d_name, opts);
E 7
I 7
		sendf(dp->d_name, opts);
E 18
I 18
	lp = (struct linkbuf *) malloc(sizeof(*lp));
	if (lp == NULL)
		log(lfp, "out of memory, link information lost\n");
	else {
		lp->nextp = ihead;
		ihead = lp;
		lp->inum = stp->st_ino;
		lp->devnum = stp->st_dev;
		lp->count = stp->st_nlink - 1;
		strcpy(lp->pathname, target);
I 25
		if (Tdest)
			strcpy(lp->target, Tdest);
		else
			*lp->target = 0;
E 25
E 18
E 7
E 4
E 3
	}
D 18
	closedir(d);
	(void) write(rem, "E\n", 2);
	(void) response();
	tp = otp;
	*tp = '\0';
E 18
I 18
	return(NULL);
E 18
}

/*
 * Check to see if file needs to be updated on the remote machine.
I 2
D 7
 * Returns 0 if no update, 1 if remote doesn't exist, and 2 if out of date.
E 7
I 7
 * Returns 0 if no update, 1 if remote doesn't exist, 2 if out of date
 * and 3 if comparing binaries to determine if out of date.
E 7
E 2
 */
D 3
update(name, st)
	char *name;
E 3
I 3
D 4
update(lname, rname, options, st)
E 4
I 4
D 7
update(lname, rname, opts, st)
E 4
	char *lname, *rname;
E 7
I 7
D 18
update(rname, opts, st)
E 18
I 18
update(rname, opts, stp)
E 18
	char *rname;
E 7
D 4
	int options;
E 4
I 4
	int opts;
E 4
E 3
D 18
	struct stat *st;
E 18
I 18
	struct stat *stp;
E 18
{
D 7
	register char *cp;
E 7
I 7
	register char *cp, *s;
E 7
	register off_t size;
	register time_t mtime;

	if (debug) 
D 3
		printf("update(%s, %x)\n", name, st);
E 3
I 3
D 4
		printf("update(%s, %s, %x, %x)\n", lname, rname, options, st);
E 4
I 4
D 7
		printf("update(%s, %s, %x, %x)\n", lname, rname, opts, st);
E 7
I 7
D 18
		printf("update(%s, %x, %x)\n", rname, opts, st);
E 18
I 18
		printf("update(%s, %x, %x)\n", rname, opts, stp);
E 18
E 7
E 4
E 3

	/*
	 * Check to see if the file exists on the remote machine.
	 */
D 3
	(void) sprintf(buf, "Q%s\n", name);
E 3
I 3
D 5
	(void) sprintf(buf, "%c%s\n",
		(st->st_mode & S_IFMT) == S_IFDIR ? 'Q' : 'q', rname);
E 5
I 5
D 7
	(void) sprintf(buf, "%c%s\n", ISDIR(st->st_mode) ? 'Q' : 'q', rname);
E 7
I 7
	(void) sprintf(buf, "Q%s\n", rname);
E 7
E 5
E 3
	if (debug)
		printf("buf = %s", buf);
	(void) write(rem, buf, strlen(buf));
I 25
again:
E 25
D 7
	cp = buf;
E 7
I 7
	cp = s = buf;
E 7
	do {
		if (read(rem, cp, 1) != 1)
D 15
			lostconn();
E 15
I 15
D 16
			cleanup();
E 16
I 16
			lostconn();
E 16
E 15
D 2
	} while (*cp++ != '\n');
E 2
I 2
	} while (*cp++ != '\n' && cp < &buf[BUFSIZ]);
E 2
D 3
	*--cp = '\0';
	cp = buf;
	if (debug)
		printf("resp = %s\n", cp);
E 3

D 3
	switch (*cp++) {
E 3
I 3
D 7
	switch (buf[0]) {
E 7
I 7
	switch (*s++) {
E 7
E 3
	case 'Y':
		break;

D 2
	case 'N':  /* file doesn't exist so update it */
E 2
I 2
	case 'N':  /* file doesn't exist so install it */
E 2
		return(1);

	case '\1':
D 2
		error("%s\n", cp);
E 2
I 2
D 15
		errs++;
E 15
I 15
		nerrs++;
E 15
D 3
		if (*cp != '\0') {
E 3
I 3
D 7
		if (cp > &buf[2]) {
E 7
I 7
		if (*s != '\n') {
E 7
E 3
			if (!iamremote) {
				fflush(stdout);
D 3
				(void) write(2, cp, strlen(cp));
E 3
I 3
D 7
				(void) write(2, cp, cp - buf);
E 7
I 7
				(void) write(2, s, cp - s);
E 7
E 3
			}
			if (lfp != NULL)
D 3
				(void) fwrite(cp, 1, strlen(cp), lfp);
E 3
I 3
D 7
				(void) fwrite(cp, 1, cp - buf, lfp);
E 7
I 7
				(void) fwrite(s, 1, cp - s, lfp);
E 7
E 3
		}
E 2
		return(0);

I 25
	case '\3':
		*--cp = '\0';
		if (lfp != NULL) 
			log(lfp, "update: note: %s\n", s);
		goto again;

E 25
	default:
D 3
		error("unexpected response '%c' to query\n", *--cp);
E 3
I 3
D 7
		error("unexpected response '%c' to query\n", buf[0]);
E 7
I 7
D 19
		printf("buf = ");
		fwrite(buf, 1, cp - s, stdout);
		error("update: unexpected response '%c'\n", buf[0]);
E 19
I 19
		*--cp = '\0';
D 25
		error("update: unexpected response '%s'\n", buf);
E 25
I 25
		error("update: unexpected response '%s'\n", s);
E 25
E 19
E 7
E 3
		return(0);
	}

D 3
	if (*cp == '\0') {
		if ((st->st_mode & S_IFMT) == S_IFDIR)
D 2
			return(1);
		error("file -> directory\n");
		return(0);
E 2
I 2
			return(2);
		return(1);
E 2
	}
E 3
I 3
D 7
	cp = &buf[1];
	if (*cp == '\n')
E 7
I 7
	if (*s == '\n')
E 7
		return(2);
E 3

I 6
	if (opts & COMPARE)
		return(3);

E 6
	size = 0;
D 7
	while (isdigit(*cp))
		size = size * 10 + (*cp++ - '0');
	if (*cp++ != ' ') {
		error("size not delimited\n");
E 7
I 7
	while (isdigit(*s))
		size = size * 10 + (*s++ - '0');
	if (*s++ != ' ') {
		error("update: size not delimited\n");
E 7
		return(0);
	}
	mtime = 0;
D 7
	while (isdigit(*cp))
		mtime = mtime * 10 + (*cp++ - '0');
D 3
	if (*cp != '\0') {
E 3
I 3
	if (*cp != '\n') {
E 3
		error("mtime not delimited\n");
E 7
I 7
	while (isdigit(*s))
		mtime = mtime * 10 + (*s++ - '0');
	if (*s != '\n') {
		error("update: mtime not delimited\n");
E 7
		return(0);
	}
	/*
	 * File needs to be updated?
	 */
D 3
	if (st->st_mtime == mtime && st->st_size == size ||
D 2
	    yflag && st->st_mtime < mtime) {
E 2
I 2
	    yflag && st->st_mtime < mtime)
E 3
I 3
D 4
	if (yflag || (options & YOUNGER)) {
E 4
I 4
	if (opts & YOUNGER) {
E 4
D 18
		if (st->st_mtime == mtime)
E 18
I 18
		if (stp->st_mtime == mtime)
E 18
			return(0);
D 18
		if (st->st_mtime < mtime) {
E 18
I 18
		if (stp->st_mtime < mtime) {
E 18
D 5
			log(lfp, "Warning: %s older than remote copy\n", lname);
E 5
I 5
D 7
			log(lfp, "Warning: %s: remote copy is newer\n", lname);
E 7
I 7
			log(lfp, "Warning: %s: remote copy is newer\n", target);
E 7
E 5
			return(0);
		}
D 18
	} else if (st->st_mtime == mtime && st->st_size == size)
E 18
I 18
	} else if (stp->st_mtime == mtime && stp->st_size == size)
E 18
E 3
E 2
		return(0);
D 2
	}
	return(1);
E 2
I 2
	return(2);
E 2
}

/*
 * Query. Check to see if file exists. Return one of the following:
 *	N\n		- doesn't exist
 *	Ysize mtime\n	- exists and its a regular file (size & mtime of file)
D 18
 *	Y\n		- exists and its a directory
E 18
I 18
 *	Y\n		- exists and its a directory or symbolic link
E 18
 *	^Aerror message\n
 */
D 3
query(name)
E 3
I 3
D 7
query(name, isdir)
E 7
I 7
query(name)
E 7
E 3
	char *name;
I 6
D 7
	int isdir;
E 7
E 6
{
	struct stat stb;

	if (catname)
		(void) sprintf(tp, "/%s", name);
I 3

D 7
again:
E 7
E 3
D 18
	if (stat(target, &stb) < 0) {
E 18
I 18
	if (lstat(target, &stb) < 0) {
E 18
D 21
		(void) write(rem, "N\n", 2);
E 21
I 21
		if (errno == ENOENT)
			(void) write(rem, "N\n", 2);
		else
			error("%s:%s: %s\n", host, target, sys_errlist[errno]);
E 21
		*tp = '\0';
		return;
	}

	switch (stb.st_mode & S_IFMT) {
	case S_IFREG:
D 21
		(void) sprintf(buf, "Y%D %D\n", stb.st_size, stb.st_mtime);
E 21
I 21
		(void) sprintf(buf, "Y%ld %ld\n", stb.st_size, stb.st_mtime);
E 21
		(void) write(rem, buf, strlen(buf));
		break;

I 18
	case S_IFLNK:
E 18
	case S_IFDIR:
I 3
D 7
		/*
		 * If file -> directory, need to cat name to target and stat.
		 */
		if (!isdir && !catname) {
			isdir = 1;
			(void) sprintf(tp, "/%s", name);
			goto again;
		}
E 7
E 3
		(void) write(rem, "Y\n", 2);
		break;

	default:
D 18
		error("%s: not a plain file\n", name);
E 18
I 18
		error("%s: not a file or directory\n", name);
E 18
		break;
	}
	*tp = '\0';
}

D 18
recvf(cmd, isdir)
E 18
I 18
recvf(cmd, type)
E 18
	char *cmd;
D 18
	int isdir;
E 18
I 18
	int type;
E 18
{
	register char *cp;
D 3
	int f, mode, wrerr, exists, olderrno;
E 3
I 3
D 4
	int f, mode, wrerr, olderrno;
E 4
I 4
D 6
	int f, mode, opts, wrerr, olderrno;
E 6
I 6
D 12
	int f, mode, opts, wrerr, olderrno, u;
E 12
I 12
	int f, mode, opts, wrerr, olderrno;
E 12
E 6
E 4
E 3
	off_t i, size;
	time_t mtime;
	struct stat stb;
	struct timeval tvp[2];
D 21
	char *owner, *group, *dir;
E 21
I 21
	char *owner, *group;
E 21
	char new[BUFSIZ];
I 2
	extern char *tmpname;
E 2

I 4
D 6
	
E 6
	cp = cmd;
D 6
	if (*cp < '0' || *cp > '7') {
		error("bad options\n");
		return;
	}
	opts = *cp++ - '0';
E 6
I 6
	opts = 0;
	while (*cp >= '0' && *cp <= '7')
		opts = (opts << 3) | (*cp++ - '0');
E 6
	if (*cp++ != ' ') {
D 7
		error("options not delimited\n");
E 7
I 7
		error("recvf: options not delimited\n");
E 7
		return;
	}
E 4
	mode = 0;
D 4
	for (cp = cmd; cp < cmd+4; cp++) {
E 4
I 4
D 6
	while (cp < cmd+6) {
E 4
		if (*cp < '0' || *cp > '7') {
			error("bad mode\n");
			return;
		}
E 6
I 6
	while (*cp >= '0' && *cp <= '7')
E 6
D 4
		mode = (mode << 3) | (*cp - '0');
E 4
I 4
		mode = (mode << 3) | (*cp++ - '0');
E 4
D 6
	}
E 6
	if (*cp++ != ' ') {
D 7
		error("mode not delimited\n");
E 7
I 7
		error("recvf: mode not delimited\n");
E 7
		return;
	}
	size = 0;
	while (isdigit(*cp))
		size = size * 10 + (*cp++ - '0');
	if (*cp++ != ' ') {
D 7
		error("size not delimited\n");
E 7
I 7
		error("recvf: size not delimited\n");
E 7
		return;
	}
	mtime = 0;
	while (isdigit(*cp))
		mtime = mtime * 10 + (*cp++ - '0');
	if (*cp++ != ' ') {
D 7
		error("mtime not delimited\n");
E 7
I 7
		error("recvf: mtime not delimited\n");
E 7
		return;
	}
	owner = cp;
	while (*cp && *cp != ' ')
		cp++;
	if (*cp != ' ') {
D 7
		error("owner name not delimited\n");
E 7
I 7
		error("recvf: owner name not delimited\n");
E 7
		return;
	}
	*cp++ = '\0';
	group = cp;
	while (*cp && *cp != ' ')
		cp++;
	if (*cp != ' ') {
D 7
		error("group name not delimited\n");
E 7
I 7
		error("recvf: group name not delimited\n");
E 7
		return;
	}
	*cp++ = '\0';

I 2
D 10
	new[0] = '\0';
E 10
E 2
D 18
	if (isdir) {
E 18
I 18
	if (type == S_IFDIR) {
E 18
I 3
		if (catname >= sizeof(stp)) {
D 18
			error("%s: too many directory levels\n", target);
E 18
I 18
			error("%s:%s: too many directory levels\n",
				host, target);
E 18
			return;
		}
		stp[catname] = tp;
E 3
		if (catname++) {
			*tp++ = '/';
			while (*tp++ = *cp++)
				;
			tp--;
		}
I 2
D 4
		if (vflag) {
E 4
I 4
		if (opts & VERIFY) {
E 4
D 8
			ga();
E 8
I 8
			ack();
E 8
			return;
		}
E 2
D 18
		if (stat(target, &stb) == 0) {
E 18
I 18
		if (lstat(target, &stb) == 0) {
E 18
D 5
			if ((stb.st_mode & S_IFMT) != S_IFDIR) {
E 5
I 5
D 8
			if (!ISDIR(stb.st_mode)) {
E 5
				errno = ENOTDIR;
				goto bad;
			}
		} else {
D 3
			/*
			 * Check parent directory for write permission.
			 */
			cp = rindex(target, '/');
			if (cp == NULL)
				dir = ".";
			else if (cp == target) {
				dir = "/";
				cp = NULL;
			} else {
				dir = target;
				*cp = '\0';
			}
D 2
			f = access(dir, 2);
E 2
I 2
			if (access(dir, 2) < 0)
				goto bad2;
E 2
			if (cp != NULL)
				*cp = '/';
E 3
I 3
			if (chkparent(target) < 0)
				goto bad;
E 3
D 2
			if (f < 0)
				goto bad;
E 2
			if (mkdir(target, mode) < 0)
				goto bad;
I 2
			if (chog(target, owner, group, mode) < 0)
E 8
I 8
			if (ISDIR(stb.st_mode)) {
D 13
				ack();
E 13
I 13
D 14
				if (stb.st_mode & 0777 == mode) {
E 14
I 14
D 21
				if ((stb.st_mode & 0777) == mode) {
E 21
I 21
				if ((stb.st_mode & 07777) == mode) {
E 21
E 14
					ack();
					return;
				}
				buf[0] = '\0';
				(void) sprintf(buf + 1,
D 21
					"%s:%s: Warning: mode %o != %o\n",
					host, target, stb.st_mode & 0777, mode);
E 21
I 21
D 26
					"%s:%s: Warning: remote mode %o != local mode %o\n",
					host, target, stb.st_mode & 07777, mode);
E 26
I 26
					"%s: Warning: remote mode %o != local mode %o\n",
					target, stb.st_mode & 07777, mode);
E 26
E 21
				(void) write(rem, buf, strlen(buf + 1) + 1);
E 13
E 8
				return;
I 8
			}
D 18
			error("%s: %s\n", target, sys_errlist[ENOTDIR]);
E 18
I 18
D 21
			error("%s:%s: %s\n", host,target,sys_errlist[ENOTDIR]);
E 18
		} else if (chkparent(target) < 0 || mkdir(target, mode) < 0)
D 18
			error("%s: %s\n", target, sys_errlist[errno]);
E 18
I 18
			error("%s:%s: %s\n", host, target, sys_errlist[errno]);
E 18
		else if (chog(target, owner, group, mode) == 0) {
			ack();
E 21
I 21
			errno = ENOTDIR;
		} else if (errno == ENOENT && (mkdir(target, mode) == 0 ||
		    chkparent(target) == 0 && mkdir(target, mode) == 0)) {
			if (chog(target, owner, group, mode) == 0)
				ack();
E 21
			return;
E 8
E 2
		}
I 21
		error("%s:%s: %s\n", host, target, sys_errlist[errno]);
E 21
D 2
		if (chog(target, owner, group) < 0)
			return;
E 2
D 8
		ga();
E 8
I 8
		tp = stp[--catname];
		*tp = '\0';
E 8
		return;
	}

I 10
D 21
	new[0] = '\0';
E 21
E 10
	if (catname)
		(void) sprintf(tp, "/%s", cp);
D 12
	if (stat(target, &stb) == 0) {
D 7
		switch (stb.st_mode & S_IFMT) {
		case S_IFREG:
			break;

		case S_IFDIR:
			if (!catname) {
				(void) sprintf(tp, "/%s", cp);
				break;
			}

		default:
E 7
I 7
		if ((stb.st_mode & S_IFMT) != S_IFREG) {
E 7
			error("%s: not a regular file\n", target);
			return;
		}
D 6
	}
E 6
I 6
		u = 2;
	} else
		u = 1;
E 12
I 12
D 18
	if (stat(target, &stb) == 0 && (stb.st_mode & S_IFMT) != S_IFREG) {
		error("%s: not a regular file\n", target);
E 18
I 18
D 21
	if (lstat(target, &stb) == 0 && (f = stb.st_mode & S_IFMT) != S_IFREG &&
	    f != S_IFLNK) {
		error("%s:%s: not a regular file\n", host, target);
E 18
		return;
	}
E 12
E 6
D 3
	/*
	 * Check parent directory for write permission.
	 */
E 3
I 3
	if (chkparent(target) < 0)
		goto bad;
E 21
E 3
	cp = rindex(target, '/');
	if (cp == NULL)
D 21
		dir = ".";
	else if (cp == target) {
D 7
		dir = "/";
E 7
I 7
		dir = "";
E 7
		cp = NULL;
	} else {
		dir = target;
E 21
I 21
		strcpy(new, tmpname);
	else if (cp == target)
		(void) sprintf(new, "/%s", tmpname);
	else {
E 21
		*cp = '\0';
D 21
	}
D 2
	(void) sprintf(new, "%s/rdistXXXXXX", dir);
	mktemp(new);
	f = access(dir, 2);
E 2
I 2
D 3
	if (access(dir, 2) < 0) {
bad2:
		error("%s: %s\n", dir, sys_errlist[errno]);
		if (cp != NULL)
			*cp = '/';
		return;
	}
E 3
	(void) sprintf(new, "%s/%s", dir, tmpname);
E 2
	if (cp != NULL)
E 21
I 21
		(void) sprintf(new, "%s/%s", target, tmpname);
E 21
		*cp = '/';
I 21
	}
E 21
I 18

	if (type == S_IFLNK) {
		int j;

		ack();
		cp = buf;
		for (i = 0; i < size; i += j) {
			if ((j = read(rem, cp, size - i)) <= 0)
				cleanup();
			cp += j;
		}
		*cp = '\0';
D 21
		umask(~mode & 0777);
		j = symlink(buf, new);
		umask(0);
		(void) response();
		if (j < 0)
			goto bad1;
E 21
I 21
		if (response() < 0) {
			err();
			return;
		}
D 22
		if (symlink(buf, new) < 0)
			goto badn;
E 22
I 22
		if (symlink(buf, new) < 0) {
			if (errno != ENOENT || chkparent(new) < 0 ||
			    symlink(buf, new) < 0)
				goto badn;
		}
E 22
E 21
		mode &= 0777;
		if (opts & COMPARE) {
			char tbuf[BUFSIZ];

D 22
			if ((i = readlink(target, tbuf, BUFSIZ)) < 0)
D 21
				goto bad;
E 21
I 21
				goto badt;
E 21
D 19
			if (i != size || strncmp(buf, tbuf, size) != 0) {
				if (opts & VERIFY)
					goto differ;
			} else {
E 19
I 19
			if (i == size && strncmp(buf, tbuf, size) == 0) {
E 22
I 22
			if ((i = readlink(target, tbuf, BUFSIZ)) >= 0 &&
			    i == size && strncmp(buf, tbuf, size) == 0) {
E 22
E 19
				(void) unlink(new);
				ack();
				return;
			}
I 19
			if (opts & VERIFY)
				goto differ;
E 19
		}
		goto fixup;
	}

E 18
D 2
	if (f < 0)
		goto bad;
E 2
D 21
	if ((f = creat(new, mode)) < 0)
		goto bad1;
E 21
I 21
	if ((f = creat(new, mode)) < 0) {
		if (errno != ENOENT || chkparent(new) < 0 ||
		    (f = creat(new, mode)) < 0)
D 22
			goto badt;
E 22
I 22
			goto badn;
E 22
	}

E 21
D 2
	if (chog(new, owner, group) < 0)
E 2
I 2
D 8
	if (chog(new, owner, group, mode) < 0) {
		(void) close(f);
		(void) unlink(new);
E 2
		return;
I 2
	}
E 2
	ga();
E 8
I 8
	ack();
E 8
D 18

E 18
	wrerr = 0;
	for (i = 0; i < size; i += BUFSIZ) {
		int amt = BUFSIZ;
D 3
		char *cp = buf;
E 3

I 3
		cp = buf;
E 3
		if (i + amt > size)
			amt = size - i;
		do {
			int j = read(rem, cp, amt);

D 2
			if (j <= 0)
E 2
I 2
			if (j <= 0) {
				(void) close(f);
				(void) unlink(new);
E 2
				cleanup();
I 2
			}
E 2
			amt -= j;
			cp += j;
		} while (amt > 0);
		amt = BUFSIZ;
		if (i + amt > size)
			amt = size - i;
		if (wrerr == 0 && write(f, buf, amt) != amt) {
			olderrno = errno;
			wrerr++;
		}
	}
I 6
	(void) close(f);
E 6
D 21
	(void) response();
E 21
I 21
	if (response() < 0) {
		err();
		(void) unlink(new);
		return;
	}
E 21
	if (wrerr) {
D 18
		error("%s: %s\n", cp, sys_errlist[olderrno]);
E 18
I 18
D 23
		error("%s:%s: %s\n", host, cp, sys_errlist[olderrno]);
E 23
I 23
		error("%s:%s: %s\n", host, new, sys_errlist[olderrno]);
E 23
E 18
I 2
D 6
		(void) close(f);
E 6
		(void) unlink(new);
E 2
		return;
	}
I 6
	if (opts & COMPARE) {
		FILE *f1, *f2;
		int c;
E 6

I 6
		if ((f1 = fopen(target, "r")) == NULL)
D 21
			goto bad;
E 21
I 21
			goto badt;
E 21
D 25
		if ((f2 = fopen(new, "r")) == NULL)
D 21
			goto bad1;
E 21
I 21
			goto badn;
E 25
I 25
		if ((f2 = fopen(new, "r")) == NULL) {
		badn:
			error("%s:%s: %s\n", host, new, sys_errlist[errno]);
			(void) unlink(new);
			return;
		}
E 25
E 21
		while ((c = getc(f1)) == getc(f2))
			if (c == EOF) {
				(void) fclose(f1);
				(void) fclose(f2);
				(void) unlink(new);
D 8
				ga();
E 8
I 8
				ack();
E 8
				return;
			}
		(void) fclose(f1);
		(void) fclose(f2);
		if (opts & VERIFY) {
I 18
		differ:
E 18
			(void) unlink(new);
			buf[0] = '\0';
D 8
			sprintf(buf + 1, "updating %s:%s\n", host, target);
E 8
I 8
D 12
			sprintf(buf + 1, "need to update %s:%s\n", host, target);
E 12
I 12
D 21
			(void) sprintf(buf + 1, "need to update %s:%s\n",
				host, target);
E 21
I 21
			(void) sprintf(buf + 1, "need to update: %s\n",target);
E 21
E 12
E 8
			(void) write(rem, buf, strlen(buf + 1) + 1);
			return;
		}
	}

E 6
	/*
	 * Set last modified time
	 */
D 6
	(void) fstat(f, &stb);
	(void) close(f);
	tvp[0].tv_sec = stb.st_atime;
E 6
I 6
D 18
	tvp[0].tv_sec = stb.st_atime;	/* old accessed time from target */
E 18
I 18
	tvp[0].tv_sec = stb.st_atime;	/* old atime from target */
E 18
E 6
	tvp[0].tv_usec = 0;
	tvp[1].tv_sec = mtime;
	tvp[1].tv_usec = 0;
D 8
	if (utimes(new, tvp) < 0) {
E 8
I 8
D 10
	if (utimes(new, tvp) < 0 || chog(new, owner, group, mode) < 0) {
E 10
I 10
	if (utimes(new, tvp) < 0) {
E 10
E 8
D 21
bad1:
E 21
I 21
D 25
badn:
E 21
D 18
		error("%s: %s\n", new, sys_errlist[errno]);
E 18
I 18
		error("%s:%s: %s\n", host, new, sys_errlist[errno]);
E 18
I 2
D 10
		if (new[0])
			(void) unlink(new);
E 10
I 10
		(void) unlink(new);
		return;
E 25
I 25
		note("%s:utimes failed %s: %s\n", host, new, sys_errlist[errno]);
E 25
	}
I 18
D 22
fixup:
E 22
E 18
	if (chog(new, owner, group, mode) < 0) {
		(void) unlink(new);
E 10
E 2
		return;
	}
D 22
	
E 22
I 22
fixup:
E 22
	if (rename(new, target) < 0) {
D 21
bad:
E 21
I 21
badt:
E 21
D 18
		error("%s: %s\n", target, sys_errlist[errno]);
E 18
I 18
		error("%s:%s: %s\n", host, target, sys_errlist[errno]);
E 18
I 2
D 21
		if (new[0])
			(void) unlink(new);
E 21
I 21
		(void) unlink(new);
E 21
E 2
		return;
	}
D 6
	ga();
E 6
I 6
	if (opts & COMPARE) {
		buf[0] = '\0';
D 12
		sprintf(buf + 1, "updated %s:%s\n", host, target);
E 12
I 12
D 19
		(void) sprintf(buf + 1, "updated %s:%s\n", host, target);
E 19
I 19
D 26
		(void) sprintf(buf + 1, "%s: updated %s\n", host, target);
E 26
I 26
		(void) sprintf(buf + 1, "updated %s\n", target);
E 26
E 19
E 12
		(void) write(rem, buf, strlen(buf + 1) + 1);
	} else
D 8
		ga();
E 8
I 8
		ack();
E 8
E 6
}

/*
I 18
 * Creat a hard link to existing file.
 */
hardlink(cmd)
	char *cmd;
{
	register char *cp;
	struct stat stb;
	char *oldname;
	int opts, exists = 0;

	cp = cmd;
	opts = 0;
	while (*cp >= '0' && *cp <= '7')
		opts = (opts << 3) | (*cp++ - '0');
	if (*cp++ != ' ') {
		error("hardlink: options not delimited\n");
		return;
	}
	oldname = cp;
	while (*cp && *cp != ' ')
		cp++;
	if (*cp != ' ') {
		error("hardlink: oldname name not delimited\n");
		return;
	}
	*cp++ = '\0';

D 25
	if (catname)
E 25
I 25
	if (catname) {
E 25
		(void) sprintf(tp, "/%s", cp);
I 25
	}
E 25
	if (lstat(target, &stb) == 0) {
D 25
		if ((stb.st_mode & S_IFMT) != S_IFREG) {
E 25
I 25
		int mode = stb.st_mode & S_IFMT;
		if (mode != S_IFREG && mode != S_IFLNK) {
E 25
			error("%s:%s: not a regular file\n", host, target);
			return;
		}
		exists = 1;
	}
D 25
	if (chkparent(target) < 0 ||
	    exists && unlink(target) < 0 ||
	    link(oldname, target) < 0) {
		error("%s:%s: %s\n", host, target, sys_errlist[errno]);
E 25
I 25
	if (chkparent(target) < 0 ) {
		error("%s:%s: %s (no parent)\n",
			host, target, sys_errlist[errno]);
E 25
		return;
	}
I 25
	if (exists && (unlink(target) < 0)) {
		error("%s:%s: %s (unlink)\n",
			host, target, sys_errlist[errno]);
		return;
	}
	if (link(oldname, target) < 0) {
		error("%s:can't link %s to %s\n",
			host, target, oldname);
		return;
	}
E 25
	ack();
}

/*
E 18
I 3
D 21
 * Check parent directory for write permission and create if it doesn't
 * exist.
E 21
I 21
 * Check to see if parent directory exists and create one if not.
E 21
 */
chkparent(name)
	char *name;
{
D 21
	register char *cp, *dir;
	extern int userid, groupid;
E 21
I 21
	register char *cp;
	struct stat stb;
E 21

	cp = rindex(name, '/');
D 21
	if (cp == NULL)
		dir = ".";
	else if (cp == name) {
		dir = "/";
		cp = NULL;
	} else {
		dir = name;
		*cp = '\0';
	}
	if (access(dir, 2) == 0) {
		if (cp != NULL)
			*cp = '/';
E 21
I 21
	if (cp == NULL || cp == name)
E 21
		return(0);
D 21
	}
	if (errno == ENOENT) {
		if (rindex(dir, '/') != NULL && chkparent(dir) < 0)
			goto bad;
		if (!strcmp(dir, ".") || !strcmp(dir, "/"))
			goto bad;
D 7
		if (mkdir(dir, 0777 & ~sumask) < 0)
E 7
I 7
		if (mkdir(dir, 0777 & ~oumask) < 0)
E 7
			goto bad;
		if (chown(dir, userid, groupid) < 0) {
			(void) unlink(dir);
			goto bad;
		}
		if (cp != NULL)
E 21
I 21
	*cp = '\0';
	if (lstat(name, &stb) < 0) {
		if (errno == ENOENT && chkparent(name) >= 0 &&
		    mkdir(name, 0777 & ~oumask) >= 0) {
E 21
			*cp = '/';
I 21
			return(0);
		}
	} else if (ISDIR(stb.st_mode)) {
		*cp = '/';
E 21
		return(0);
	}
D 21

bad:
	if (cp != NULL)
		*cp = '/';
E 21
I 21
	*cp = '/';
E 21
	return(-1);
}

/*
E 3
D 8
 * Change owner and group of file.
E 8
I 8
 * Change owner, group and mode of file.
E 8
 */
D 2
chog(file, owner, group)
E 2
I 2
chog(file, owner, group, mode)
E 2
	char *file, *owner, *group;
I 2
	int mode;
E 2
{
D 2
	extern int userid, usergid;
	extern char *user;
	struct passwd *p;
	struct group *g;
E 2
I 2
D 21
	extern int userid, groupid;
	extern char user[];
E 21
E 2
	register int i;
	int uid, gid;
I 21
	extern char user[];
	extern int userid;
E 21

	uid = userid;
	if (userid == 0) {
D 2
		p = getpwnam(owner);
		if (p == NULL) {
			error("%s: unknown login name\n", owner);
			return(-1);
		}
		uid = p->pw_uid;
E 2
I 2
D 7
		if (p == NULL || strcmp(owner, p->pw_name) != 0) {
			if ((p = getpwnam(owner)) == NULL) {
E 7
I 7
D 25
		if (pw == NULL || strcmp(owner, pw->pw_name) != 0) {
E 25
I 25
		if (*owner == ':') {
			uid = atoi(owner + 1);
		} else if (pw == NULL || strcmp(owner, pw->pw_name) != 0) {
E 25
			if ((pw = getpwnam(owner)) == NULL) {
E 7
				if (mode & 04000) {
D 18
					error("%s: unknown login name\n", owner);
E 18
I 18
D 25
					error("%s:%s: unknown login name\n",
E 25
I 25
					note("%s:%s: unknown login name, clearing setuid",
E 25
						host, owner);
E 18
D 25
					return(-1);
E 25
I 25
					mode &= ~04000;
					uid = 0;
E 25
				}
			} else
D 7
				uid = p->pw_uid;
E 7
I 7
				uid = pw->pw_uid;
E 7
		} else
D 7
			uid = p->pw_uid;
E 7
I 7
			uid = pw->pw_uid;
I 25
		if (*group == ':') {
			gid = atoi(group + 1);
			goto ok;
		}
E 25
E 7
E 2
D 8
	}
E 8
I 8
	} else if ((mode & 04000) && strcmp(user, owner) != 0)
		mode &= ~04000;
E 8
D 2
	setgrent();
	g = getgrnam(group);
	if (g == NULL) {
		error("%s: unknown group\n", group);
		return(-1);
	}
	gid = g->gr_gid;
	if (userid && usergid != gid) {
		for (i = 0; g->gr_mem[i]; i++)
E 2
I 2
D 21
	gid = groupid;
E 21
I 21
	gid = -1;
E 21
D 7
	if (g == NULL || strcmp(group, g->gr_name) != 0) {
		if ((g = getgrnam(group)) == NULL) {
E 7
I 7
	if (gr == NULL || strcmp(group, gr->gr_name) != 0) {
D 25
		if ((gr = getgrnam(group)) == NULL) {
E 25
I 25
		if ((*group == ':' && (getgrgid(gid = atoi(group + 1)) == NULL))
		   || ((gr = getgrnam(group)) == NULL)) {
E 25
E 7
			if (mode & 02000) {
D 18
				error("%s: unknown group\n", group);
E 18
I 18
D 25
				error("%s:%s: unknown group\n", host, group);
E 18
				return(-1);
E 25
I 25
				note("%s:%s: unknown group", host, group);
				mode &= ~02000;
E 25
			}
		} else
D 7
			gid = g->gr_gid;
E 7
I 7
			gid = gr->gr_gid;
E 7
	} else
D 7
		gid = g->gr_gid;
E 7
I 7
		gid = gr->gr_gid;
E 7
D 21
	if (userid && groupid != gid) {
E 21
I 21
	if (userid && gid >= 0) {
E 21
D 7
		for (i = 0; g->gr_mem[i] != NULL; i++)
E 2
			if (!(strcmp(user, g->gr_mem[i])))
E 7
I 7
D 25
		for (i = 0; gr->gr_mem[i] != NULL; i++)
E 25
I 25
		if (gr) for (i = 0; gr->gr_mem[i] != NULL; i++)
E 25
			if (!(strcmp(user, gr->gr_mem[i])))
E 7
				goto ok;
I 8
		mode &= ~02000;
E 8
D 2
		error("You are not a member of the %s group\n", group);
		return(-1);
E 2
I 2
D 21
		gid = groupid;
E 21
I 21
		gid = -1;
E 21
E 2
	}
ok:
D 21
	if (chown(file, uid, gid) < 0) {
E 21
I 21
	if (userid)
		setreuid(userid, 0);
	if (chown(file, uid, gid) < 0 ||
D 30
	    (mode & 06000) && chmod(file, mode) < 0) {
E 30
I 30
	    (mode & 07000) && chmod(file, mode) < 0) {
E 30
D 25
		if (userid)
			setreuid(0, userid);
E 21
D 18
		error("%s: %s\n", file, sys_errlist[errno]);
E 18
I 18
		error("%s:%s: %s\n", host, file, sys_errlist[errno]);
E 18
		return(-1);
E 25
I 25
		note("%s: chown or chmod failed: file %s:  %s",
			     host, file, sys_errlist[errno]);
E 25
	}
I 8
D 21
	/*
	 * Restore set-user-id or set-group-id bit if appropriate.
	 */
	if ((mode & 06000) && chmod(file, mode) < 0) {
D 18
		error("%s: %s\n", file, sys_errlist[errno]);
E 18
I 18
		error("%s:%s: %s\n", host, file, sys_errlist[errno]);
E 18
		return(-1);
	}
E 21
I 21
	if (userid)
		setreuid(0, userid);
E 21
E 8
	return(0);
I 5
}

/*
 * Check for files on the machine being updated that are not on the master
 * machine and remove them.
 */
D 7
rmchk(lname, rname, opts)
	char *lname, *rname;
E 7
I 7
D 8
rmchk(rname, opts)
	char *rname;
E 8
I 8
rmchk(opts)
E 8
E 7
	int opts;
{
D 7
	register char *cp;
E 7
I 7
	register char *cp, *s;
E 7
	struct stat stb;

	if (debug)
D 7
		printf("rmchk(%s, %s, %x)\n", lname,
			rname != NULL ? rname : "NULL", opts);
E 7
I 7
D 8
		printf("rmchk(%s, %x)\n", rname, opts);
E 8
I 8
		printf("rmchk()\n");
E 8
E 7

D 6
	if (exclude(lname))
		return;

E 6
	/*
D 7
	 * First time rmchk() is called?
	 */
	if (rname == NULL) {
		rname = exptilde(target, lname);
		if (rname == NULL)
			return;
		tp = lname = target;
		while (*tp)
			tp++;
		/*
		 * If we are renaming a directory and we want to preserve
		 * the directory heirarchy (-w), we must strip off the first
		 * directory name and preserve the rest.
		 */
		if (opts & STRIP) {
			opts &= ~STRIP;
			rname = index(rname, '/');
			if (rname == NULL)
				rname = tp;
			else
				rname++;
		} else if (!(opts & WHOLE)) {
			rname = rindex(lname, '/');
			if (rname == NULL)
				rname = lname;
			else
				rname++;
		}
	}
D 6
	if (debug)
		printf("lname = %s, rname = %s\n", lname, rname);
E 6
I 6
	if (exclude(lname))
		return;
E 6
	if (access(lname, 4) < 0 || stat(lname, &stb) < 0) {
		error("%s: %s\n", lname, sys_errlist[errno]);
		return;
	}
	if (!ISDIR(stb.st_mode))
		return;
I 6

E 6
	/*
E 7
	 * Tell the remote to clean the files from the last directory sent.
	 */
D 8
	(void) sprintf(buf, "C%o %s\n", opts & VERIFY, rname);
E 8
I 8
	(void) sprintf(buf, "C%o\n", opts & VERIFY);
E 8
	if (debug)
		printf("buf = %s", buf);
	(void) write(rem, buf, strlen(buf));
	if (response() < 0)
		return;
D 7
	catname = 0;
E 7
I 7
D 8
	stp[0] = tp;
	catname = 1;
E 8
E 7
	for (;;) {
D 7
		cp = buf;
E 7
I 7
		cp = s = buf;
E 7
		do {
			if (read(rem, cp, 1) != 1)
D 15
				lostconn();
E 15
I 15
D 16
				cleanup();
E 16
I 16
				lostconn();
E 16
E 15
		} while (*cp++ != '\n' && cp < &buf[BUFSIZ]);

D 6
		if (debug) {
			printf("readbuf = ");
			fwrite(buf, 1, cp - buf, stdout);
		}
E 6
D 7
		switch (buf[0]) {
E 7
I 7
		switch (*s++) {
E 7
D 8
		case 'Q': /* its a directory on the remote end */
		case 'q': /* its a regular file on the remote end */
E 8
I 8
		case 'Q': /* Query if file should be removed */
E 8
I 6
			/*
			 * Return the following codes to remove query.
D 8
			 * N\n -- file does not exisit, remove.
			 * Y\n -- file exists and is a directory.
			 * y\n -- file exists and is a regular file.
E 8
I 8
			 * N\n -- file exists - DON'T remove.
			 * Y\n -- file doesn't exist - REMOVE.
E 8
			 */
E 6
			*--cp = '\0';
D 7
			(void) sprintf(tp, "/%s", buf + 1);
E 7
I 7
			(void) sprintf(tp, "/%s", s);
E 7
			if (debug)
				printf("check %s\n", target);
I 6
D 7
			if (exclude(target)) {
E 7
I 7
D 8
			if (exclude(target))
E 7
				(void) write(rem, "y\n", 2);
D 7
				break;
			}
E 6
			if (stat(target, &stb) < 0)
E 7
I 7
			else if (stat(target, &stb) < 0)
E 8
I 8
D 17
			if (inlist(except, target))
E 17
I 17
			if (except(target))
E 17
E 8
E 7
				(void) write(rem, "N\n", 2);
D 8
			else if (buf[0] == 'Q' && ISDIR(stb.st_mode)) {
				if (catname >= sizeof(stp)) {
					error("%s: too many directory levels\n", target);
					break;
				}
E 8
I 8
D 18
			else if (stat(target, &stb) < 0)
E 18
I 18
			else if (lstat(target, &stb) < 0)
E 18
E 8
				(void) write(rem, "Y\n", 2);
D 8
				if (response() < 0)
					break;
				stp[catname++] = tp;
				while (*tp)
					tp++;
			} else
				(void) write(rem, "y\n", 2);
E 8
I 8
			else
				(void) write(rem, "N\n", 2);
E 8
			break;

D 8
		case 'E':
			if (catname < 0)
				fatal("too many 'E's\n");
			ga();
D 7
			if (catname == 0)
				return;
E 7
			tp = stp[--catname];
			*tp = '\0';
I 7
			if (catname == 0)
				return;
E 7
			break;

E 8
		case '\0':
			*--cp = '\0';
D 6
			if (buf[1])
E 6
I 6
D 7
			if (buf[1] != '\0')
E 6
				log(lfp, "%s\n", buf + 1);
E 7
I 7
			if (*s != '\0')
				log(lfp, "%s\n", s);
E 7
			break;

I 8
		case 'E':
			*tp = '\0';
			ack();
			return;

E 8
		case '\1':
		case '\2':
D 15
			errs++;
E 15
I 15
			nerrs++;
E 15
D 7
			if (buf[1] != '\n') {
E 7
I 7
			if (*s != '\n') {
E 7
				if (!iamremote) {
					fflush(stdout);
D 7
					(void) write(2, buf + 1, cp - buf + 1);
E 7
I 7
					(void) write(2, s, cp - s);
E 7
				}
				if (lfp != NULL)
D 7
					(void) fwrite(buf + 1, 1, cp - buf + 1, lfp);
E 7
I 7
					(void) fwrite(s, 1, cp - s, lfp);
E 7
			}
			if (buf[0] == '\2')
D 16
				cleanup();
E 16
I 16
				lostconn();
E 16
			break;

		default:
D 7
			error("unknown response type %s\n", buf[0]);
E 7
I 7
D 8
			error("rmchk: unexpected response '%c'\n", buf[0]);
E 8
I 8
			error("rmchk: unexpected response '%s'\n", buf);
			err();
E 8
E 7
		}
	}
}

/*
D 6
 * Check the directory for extraneous files and remove them.
E 6
I 6
D 8
 * Check the directory initialized by the 'T' command to server()
E 8
I 8
 * Check the current directory (initialized by the 'T' command to server())
E 8
 * for extraneous files and remove them.
E 6
 */
D 7
clean(lname, opts, first)
	char *lname;
E 7
I 7
D 8
clean(name, opts, first)
	char *name;
E 7
	int opts, first;
E 8
I 8
D 11
clean(opts)
E 11
I 11
clean(cp)
	register char *cp;
E 11
E 8
{
	DIR *d;
D 8
	struct direct *dp;
E 8
I 8
	register struct direct *dp;
E 8
D 11
	register char *cp;
E 11
	struct stat stb;
D 8
	char *ootp, *otp;
	int len;
E 8
I 8
	char *otp;
	int len, opts;
E 8

D 8
	if (first) {
		ootp = tp;
		if (catname) {
			*tp++ = '/';
D 7
			cp = lname;
E 7
I 7
			cp = name;
E 7
			while (*tp++ = *cp++)
				;
			tp--;
		}
		if (stat(target, &stb) < 0) {
D 7
			if (errno == ENOENT) {
E 7
I 7
			if (errno != ENOENT) {
E 7
				ga();
				goto done;
			}
D 7
		bad:
E 7
			error("%s: %s\n", target, sys_errlist[errno]);
D 7
			tp = otp;
E 7
I 7
			tp = ootp;
E 7
			*tp = '\0';
			return;
		}
		/*
		 * This should be a directory because its a directory on the
		 * master machine. If not, let install complain about it.
		 */
		if (!ISDIR(stb.st_mode)) {
			ga();
			goto done;
		}
E 8
I 8
	opts = 0;
	while (*cp >= '0' && *cp <= '7')
		opts = (opts << 3) | (*cp++ - '0');
	if (*cp != '\0') {
		error("clean: options not delimited\n");
		return;
E 8
	}
I 6
D 8

E 8
E 6
D 7
	if (access(target, 6) < 0 || (d = opendir(target)) == NULL)
		goto bad;
E 7
I 7
D 21
	if (access(target, 6) < 0 || (d = opendir(target)) == NULL) {
E 21
I 21
	if ((d = opendir(target)) == NULL) {
E 21
D 18
		error("%s: %s\n", target, sys_errlist[errno]);
E 18
I 18
		error("%s:%s: %s\n", host, target, sys_errlist[errno]);
E 18
D 8
		if (first) {
			tp = ootp;
			*tp = '\0';
		}
E 8
		return;
	}
E 7
D 8
	ga();
E 8
I 8
	ack();
E 8

	otp = tp;
	len = tp - target;
	while (dp = readdir(d)) {
		if (!strcmp(dp->d_name, ".") || !strcmp(dp->d_name, ".."))
			continue;
		if (len + 1 + strlen(dp->d_name) >= BUFSIZ - 1) {
D 18
			error("%s/%s: Name too long\n", target, dp->d_name);
E 18
I 18
			error("%s:%s/%s: Name too long\n",
				host, target, dp->d_name);
E 18
			continue;
		}
		tp = otp;
		*tp++ = '/';
		cp = dp->d_name;;
		while (*tp++ = *cp++)
			;
		tp--;
D 18
		if (stat(target, &stb) < 0) {
			error("%s: %s\n", target, sys_errlist[errno]);
E 18
I 18
		if (lstat(target, &stb) < 0) {
			error("%s:%s: %s\n", host, target, sys_errlist[errno]);
E 18
			continue;
		}
D 8
		(void) sprintf(buf, "%c%s\n", ISDIR(stb.st_mode) ? 'Q' : 'q',
			dp->d_name);
E 8
I 8
		(void) sprintf(buf, "Q%s\n", dp->d_name);
E 8
		(void) write(rem, buf, strlen(buf));
		cp = buf;
		do {
			if (read(rem, cp, 1) != 1)
D 15
				lostconn();
E 15
I 15
				cleanup();
E 15
		} while (*cp++ != '\n' && cp < &buf[BUFSIZ]);
		*--cp = '\0';
		cp = buf;
D 8
		if (*cp != 'N') {
			if (*cp == 'Y' && ISDIR(stb.st_mode))
				clean(dp->d_name, opts, 0);
E 8
I 8
		if (*cp != 'Y')
E 8
			continue;
D 8
		}
E 8
D 7
		if (!(opts & VERIFY))
E 7
I 7
		if (opts & VERIFY) {
			cp = buf;
			*cp++ = '\0';
D 8
			(void) sprintf(cp, "removing %s\n", target);
E 8
I 8
D 21
			(void) sprintf(cp, "need to remove %s\n", target);
E 21
I 21
			(void) sprintf(cp, "need to remove: %s\n", target);
E 21
E 8
			(void) write(rem, buf, strlen(cp) + 1);
		} else
E 7
			remove(&stb);
	}
	closedir(d);
D 8
done:
E 8
D 7
	tp = (first) ? ootp : otp;
	*tp = '\0';
E 7
	(void) write(rem, "E\n", 2);
	(void) response();
I 7
D 8
	tp = (first) ? ootp : otp;
E 8
I 8
	tp = otp;
E 8
	*tp = '\0';
E 7
}

I 7
/*
 * Remove a file or directory (recursively) and send back an acknowledge
 * or an error message.
 */
E 7
D 18
remove(st)
	struct stat *st;
E 18
I 18
remove(stp)
	struct stat *stp;
E 18
{
	DIR *d;
	struct direct *dp;
	register char *cp;
	struct stat stb;
	char *otp;
	int len;

D 18
	switch (st->st_mode & S_IFMT) {
E 18
I 18
	switch (stp->st_mode & S_IFMT) {
E 18
	case S_IFREG:
I 18
	case S_IFLNK:
E 18
		if (unlink(target) < 0)
			goto bad;
		goto removed;

	case S_IFDIR:
		break;

	default:
D 18
		error("%s: not a plain file\n", target);
E 18
I 18
		error("%s:%s: not a plain file\n", host, target);
E 18
		return;
	}

D 21
	if (access(target, 6) < 0 || (d = opendir(target)) == NULL)
E 21
I 21
	if ((d = opendir(target)) == NULL)
E 21
		goto bad;

	otp = tp;
	len = tp - target;
	while (dp = readdir(d)) {
		if (!strcmp(dp->d_name, ".") || !strcmp(dp->d_name, ".."))
			continue;
		if (len + 1 + strlen(dp->d_name) >= BUFSIZ - 1) {
D 18
			error("%s/%s: Name too long\n", target, dp->d_name);
E 18
I 18
			error("%s:%s/%s: Name too long\n",
				host, target, dp->d_name);
E 18
			continue;
		}
		tp = otp;
		*tp++ = '/';
		cp = dp->d_name;;
		while (*tp++ = *cp++)
			;
		tp--;
D 18
		if (stat(target, &stb) < 0) {
			error("%s: %s\n", target, sys_errlist[errno]);
E 18
I 18
		if (lstat(target, &stb) < 0) {
			error("%s:%s: %s\n", host, target, sys_errlist[errno]);
E 18
			continue;
		}
		remove(&stb);
	}
	closedir(d);
	tp = otp;
	*tp = '\0';
	if (rmdir(target) < 0) {
bad:
D 18
		error("%s: %s\n", target, sys_errlist[errno]);
E 18
I 18
		error("%s:%s: %s\n", host, target, sys_errlist[errno]);
E 18
		return;
	}
removed:
	cp = buf;
	*cp++ = '\0';
	(void) sprintf(cp, "removed %s\n", target);
	(void) write(rem, buf, strlen(cp) + 1);
E 5
}

I 8
/*
 * Execute a shell command to handle special cases.
 */
dospecial(cmd)
	char *cmd;
{
	int fd[2], status, pid, i;
	register char *cp, *s;
	char sbuf[BUFSIZ];
I 21
	extern int userid, groupid;
E 21

	if (pipe(fd) < 0) {
		error("%s\n", sys_errlist[errno]);
		return;
	}
	if ((pid = fork()) == 0) {
		/*
		 * Return everything the shell commands print.
		 */
		(void) close(0);
		(void) close(1);
		(void) close(2);
		(void) open("/dev/null", 0);
		(void) dup(fd[1]);
		(void) dup(fd[1]);
		(void) close(fd[0]);
		(void) close(fd[1]);
I 21
		setgid(groupid);
E 21
I 20
		setuid(userid);
E 20
		execl("/bin/sh", "sh", "-c", cmd, 0);
		_exit(127);
	}
	(void) close(fd[1]);
	s = sbuf;
	*s++ = '\0';
	while ((i = read(fd[0], buf, sizeof(buf))) > 0) {
		cp = buf;
		do {
			*s++ = *cp++;
			if (cp[-1] != '\n') {
				if (s < &sbuf[sizeof(sbuf)-1])
					continue;
				*s++ = '\n';
			}
			/*
			 * Throw away blank lines.
			 */
			if (s == &sbuf[2]) {
				s--;
				continue;
			}
			(void) write(rem, sbuf, s - sbuf);
			s = &sbuf[1];
		} while (--i);
	}
	if (s > &sbuf[1]) {
		*s++ = '\n';
		(void) write(rem, sbuf, s - sbuf);
	}
	while ((i = wait(&status)) != pid && i != -1)
		;
	if (i == -1)
		status = -1;
I 21
	(void) close(fd[0]);
E 21
	if (status)
		error("shell returned %d\n", status);
	else
		ack();
}

E 8
D 2
extern FILE *lfp;	/* log file for mailing changes */

E 2
D 3
/*VARARGS*/
E 3
I 3
/*VARARGS2*/
E 3
D 2
log(fmt, a1, a2, a3)
E 2
I 2
log(fp, fmt, a1, a2, a3)
	FILE *fp;
E 2
	char *fmt;
	int a1, a2, a3;
{
	/* Print changes locally if not quiet mode */
	if (!qflag)
		printf(fmt, a1, a2, a3);

	/* Save changes (for mailing) if really updating files */
D 2
	if (!vflag)
		fprintf(lfp, fmt, a1, a2, a3);
E 2
I 2
D 4
	if (!vflag && fp != NULL)
E 4
I 4
	if (!(options & VERIFY) && fp != NULL)
E 4
		fprintf(fp, fmt, a1, a2, a3);
E 2
}

D 3
/*VARARGS*/
E 3
I 3
/*VARARGS1*/
E 3
error(fmt, a1, a2, a3)
	char *fmt;
	int a1, a2, a3;
{
D 15
	errs++;
E 15
I 15
	nerrs++;
E 15
	strcpy(buf, "\1rdist: ");
	(void) sprintf(buf+8, fmt, a1, a2, a3);
D 8
	(void) write(rem, buf, strlen(buf));
E 8
D 3
	if (buf[1] != '\0') {
D 2
		if (!iamremote)
E 2
I 2
		if (!iamremote) {
			fflush(stdout);
E 2
			(void) write(2, buf+1, strlen(buf+1));
I 2
		}
E 2
		if (lfp != NULL)
			(void) fwrite(buf+1, 1, strlen(buf+1), lfp);
E 3
I 3
	if (!iamremote) {
		fflush(stdout);
		(void) write(2, buf+1, strlen(buf+1));
E 3
D 8
	}
E 8
I 8
	} else
		(void) write(rem, buf, strlen(buf));
E 8
I 3
	if (lfp != NULL)
		(void) fwrite(buf+1, 1, strlen(buf+1), lfp);
E 3
}

D 3
/*VARARGS*/
E 3
I 3
/*VARARGS1*/
E 3
fatal(fmt, a1, a2,a3)
	char *fmt;
	int a1, a2, a3;
{
D 15
	errs++;
E 15
I 15
	nerrs++;
E 15
	strcpy(buf, "\2rdist: ");
	(void) sprintf(buf+8, fmt, a1, a2, a3);
D 8
	(void) write(rem, buf, strlen(buf));
E 8
D 3
	if (buf[1] != '\0') {
D 2
		if (!iamremote)
E 2
I 2
		if (!iamremote) {
			fflush(stdout);
E 2
			(void) write(2, buf+1, strlen(buf+1));
I 2
		}
E 2
		if (lfp != NULL)
			(void) fwrite(buf+1, 1, strlen(buf+1), lfp);
E 3
I 3
	if (!iamremote) {
		fflush(stdout);
		(void) write(2, buf+1, strlen(buf+1));
E 3
D 8
	}
E 8
I 8
	} else
		(void) write(rem, buf, strlen(buf));
E 8
I 3
	if (lfp != NULL)
		(void) fwrite(buf+1, 1, strlen(buf+1), lfp);
E 3
	cleanup();
}

response()
{
D 3
	char resp, c, *cp = buf;
E 3
I 3
D 6
	char resp, *cp = buf;
E 6
I 6
	char *cp, *s;
I 19
	char resp[BUFSIZ];
E 19
E 6
E 3

	if (debug)
		printf("response()\n");

D 6
	if (read(rem, &resp, 1) != 1)
		lostconn();
E 6
I 6
D 19
	cp = s = buf;
E 19
I 19
	cp = s = resp;
E 19
	do {
		if (read(rem, cp, 1) != 1)
D 15
			lostconn();
E 15
I 15
D 16
			cleanup();
E 16
I 16
			lostconn();
E 16
E 15
D 19
	} while (*cp++ != '\n' && cp < &buf[BUFSIZ]);
E 19
I 19
	} while (*cp++ != '\n' && cp < &resp[BUFSIZ]);
E 19
E 6

D 6
	switch (resp) {
E 6
I 6
	switch (*s++) {
E 6
	case '\0':
I 6
		*--cp = '\0';
D 8
		if (*s != '\0')
E 8
I 8
		if (*s != '\0') {
E 8
			log(lfp, "%s\n", s);
I 8
			return(1);
		}
E 8
E 6
		return(0);
I 25
	case '\3':
		*--cp = '\0';
		log(lfp, "Note: %s\n",s);
		return(response());
E 25

	default:
D 6
		*cp++ = resp;
E 6
I 6
		s--;
E 6
		/* fall into... */
	case '\1':
	case '\2':
D 15
		errs++;
E 15
I 15
		nerrs++;
E 15
D 6
		do {
			if (read(rem, cp, 1) != 1)
				lostconn();
D 2
		} while (cp < &buf[BUFSIZ] && *cp++ != '\n');
		if (buf[1] != '\0') {
			if (!iamremote)
E 2
I 2
		} while (*cp++ != '\n' && cp < &buf[BUFSIZ]);
		if (buf[0] != '\n') {
E 6
I 6
		if (*s != '\n') {
E 6
			if (!iamremote) {
				fflush(stdout);
E 2
D 6
				(void) write(2, buf, cp - buf);
E 6
I 6
				(void) write(2, s, cp - s);
E 6
I 2
			}
E 2
			if (lfp != NULL)
D 6
				(void) fwrite(buf, 1, cp - buf, lfp);
E 6
I 6
				(void) fwrite(s, 1, cp - s, lfp);
E 6
		}
D 6
		if (resp == '\1')
E 6
I 6
D 7
		if (buf[0] == '\1')
E 6
			return(-1);
		cleanup();
E 7
I 7
D 19
		if (buf[0] == '\2')
E 19
I 19
		if (resp[0] == '\2')
E 19
D 16
			cleanup();
E 16
I 16
			lostconn();
E 16
		return(-1);
E 7
	}
D 7
	/*NOTREACHED*/
E 7
}

D 15
lostconn()
E 15
I 15
/*
 * Remove temporary files and do any cleanup operations before exiting.
 */
cleanup()
E 15
{
D 6
	if (!iamremote)
E 6
I 6
D 15
	if (!iamremote) {
		fflush(stdout);
E 6
		fprintf(stderr, "rdist: lost connection\n");
I 6
	}
E 6
	cleanup();
E 15
I 15
	(void) unlink(tmpfile);
	exit(1);
I 25
}

note(fmt, a1, a2, a3)
{
	static char buf[BUFSIZ];
	sprintf(buf, fmt, a1, a2, a3);
	comment(buf);
}

comment(s)
char *s;
{
	char c = '\3';
	write(rem, &c, 1);
	write(rem, s, strlen(s));
	c = '\n';
	write(rem, &c, 1);
E 25
E 15
}
E 1
