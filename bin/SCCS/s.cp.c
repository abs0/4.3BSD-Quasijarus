h23800
s 00004/00001/00241
d D 4.14 86/12/02 10:02:26 bostic 16 15
c made I/O buffer long-word aligned for Power 6/32.
e
s 00014/00002/00228
d D 4.13 85/10/11 17:58:40 mckusick 15 14
c add copyright
e
s 00008/00002/00222
d D 4.12 85/10/09 11:09:38 bloom 14 13
c now allows recursive copies of non-writable directories (chris@maryland)
e
s 00014/00007/00210
d D 4.11 85/06/08 01:45:37 lepreau 13 11
c overload -p to also mean preserve modes/ignore umask
e
s 00000/00000/00217
d R 4.11 85/06/08 01:42:20 lepreau 12 11
c overload -p to also mean preserve modes/ignore umask
e
s 00033/00005/00184
d D 4.10 85/06/08 00:47:18 lepreau 11 10
c add -p to preserve file and dir mtimes (& atimes prior to access)
e
s 00019/00012/00170
d D 4.9 85/06/07 01:47:19 serge 10 9
c allow "cp -r dir non-existent-dir"
e
s 00001/00001/00181
d D 4.8 83/07/01 23:57:18 wnj 9 8
c include problems
e
s 00021/00009/00161
d D 4.7 83/06/20 20:50:22 sam 8 7
c missing close's (from bill@dagobah.UUCP)
e
s 00003/00033/00167
d D 4.6 82/12/21 22:05:38 sam 7 5
c replace mkdir with sys call
e
s 00040/00042/00158
d R 4.6 82/12/21 16:18:38 sam 6 5
c use mkdir sys call and buffer writes according to st_blksize
e
s 00003/00003/00197
d D 4.5 82/05/07 16:16:36 mckusick 5 4
c update to new fs
e
s 00003/00001/00197
d D 4.4 82/04/28 16:45:14 mckusick 4 3
c close directories after use
e
s 00004/00004/00194
d D 4.3 82/03/31 11:29:55 root 3 2
c get rid of lstat
e
s 00158/00083/00040
d D 4.2 82/03/31 11:21:47 wnj 2 1
c cp -r
e
s 00123/00000/00000
d D 4.1 80/10/01 17:25:52 bill 1 0
c date and time created 80/10/01 17:25:52 by bill
e
u
U
t
T
I 15
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 15
I 1
D 2
static char *sccsid = "%W% (Berkeley) %G%";
E 2
I 2
#ifndef lint
D 11
static char *sccsid = "%W% %E%";
E 11
I 11
D 13
static char *sccsid = "%W% %G%";
E 13
I 13
D 15
static char *sccsid = "%W% (Berkeley) %G%";
E 13
E 11
#endif
E 15
I 15
char copyright[] =
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 15

E 2
/*
D 2
 * cp oldfile newfile
E 2
I 2
 * cp
E 2
 */
D 2

#define	BSIZE	1024
E 2
#include <stdio.h>
D 5
#include <sys/types.h>
E 5
I 5
#include <sys/param.h>
E 5
#include <sys/stat.h>
D 2
struct	stat	stbuf1, stbuf2;
char	iobuf[BSIZE];
int	iflag = 0;	/* interactive flag. If this flag is set,
			 * the user is queried before files are
			 * destroyed by cp.
			 */
E 2
I 2
D 5
#include <ndir.h>
E 5
I 5
D 9
#include <dir.h>
E 9
I 9
#include <sys/dir.h>
I 11
#include <sys/time.h>
E 11
E 9
E 5
E 2

I 2
D 5
#define	BSIZE	1024
E 5
I 5
D 10
#define	BSIZE	8192
E 5

E 10
int	iflag;
int	rflag;
D 11
char	*rindex(), *sprintf();
E 11
I 11
int	pflag;
char	*rindex();
E 11

E 2
main(argc, argv)
D 2
char *argv[];
E 2
I 2
	int argc;
	char **argv;
E 2
{
D 2
	register i, r;
E 2
I 2
	struct stat stb;
	int rc, i;
E 2

D 2
	/* get the flag(s) */
E 2
I 2
	argc--, argv++;
	while (argc > 0 && **argv == '-') {
		(*argv)++;
		while (**argv) switch (*(*argv)++) {
E 2

D 2
	if (argc < 2)
		goto usage;
	if (*argv[1] == '-') {
		argc--;
		while (*++argv[1] != '\0')
			switch (*argv[1]) {
E 2
I 2
		case 'i':
			iflag++; break;
E 2

I 10
		case 'R':
E 10
D 2
			/* interactive mode */
			case 'i':
				iflag++;
				break;
E 2
I 2
		case 'r':
			rflag++; break;
E 2

I 11
D 13
		case 'p':	/* preserve mtimes and atimes */
			pflag++; break;
E 13
I 13
		case 'p':	/* preserve mtimes, atimes, and modes */
			pflag++;
			(void) umask(0);
			break;
E 13

E 11
D 2
			/* don't live with bad options */
			default:
				goto usage;
			}
		argv++;
E 2
I 2
		default:
			goto usage;
		}
		argc--; argv++;
E 2
	}
D 2
	if (argc < 3) 
E 2
I 2
	if (argc < 2) 
E 2
		goto usage;
D 2
	if (argc > 3) {
		if (stat(argv[argc-1], &stbuf2) < 0)
E 2
I 2
D 10
	if (argc > 2 || rflag) {
E 10
I 10
	if (argc > 2) {
E 10
D 3
		if (lstat(argv[argc-1], &stb) < 0)
E 3
I 3
		if (stat(argv[argc-1], &stb) < 0)
E 3
E 2
			goto usage;
D 2
		if ((stbuf2.st_mode&S_IFMT) != S_IFDIR) 
E 2
I 2
		if ((stb.st_mode&S_IFMT) != S_IFDIR) 
E 2
			goto usage;
	}
D 2
	r = 0;
	for(i=1; i<argc-1;i++)
		r |= copy(argv[i], argv[argc-1]);
	exit(r);
E 2
I 2
	rc = 0;
	for (i = 0; i < argc-1; i++)
		rc |= copy(argv[i], argv[argc-1]);
	exit(rc);
E 2
usage:
D 2
	fprintf(stderr, "Usage: cp: f1 f2; or cp f1 ... fn d2\n");
E 2
I 2
	fprintf(stderr,
D 11
	    "Usage: cp f1 f2; or cp [ -r ] f1 ... fn d2\n");
E 11
I 11
D 13
	    "Usage: cp [-ip] f1 f2; or: cp [-irp] f1 ... fn d2");
E 13
I 13
	    "Usage: cp [-ip] f1 f2; or: cp [-irp] f1 ... fn d2\n");
E 13
E 11
E 2
	exit(1);
}

I 16
			/* I/O buffer; guarantee long-word alignment */
static char	buf[MAXBSIZE];

E 16
copy(from, to)
D 2
char *from, *to;
E 2
I 2
	char *from, *to;
E 2
{
D 13
	int fold, fnew, n;
E 13
I 13
	int fold, fnew, n, exists;
E 13
D 2
	register char *p1, *p2, *bp;
	int mode;
	char c,i;
	if ((fold = open(from, 0)) < 0) {
		fprintf(stderr, "cp: cannot open %s\n", from);
		return(1);
E 2
I 2
D 10
	char *last, destname[BSIZE], buf[BSIZE];
E 10
I 10
D 16
	char *last, destname[MAXPATHLEN + 1], buf[MAXBSIZE];
E 16
I 16
	char *last, destname[MAXPATHLEN + 1];
E 16
E 10
	struct stat stfrom, stto;

	fold = open(from, 0);
	if (fold < 0) {
D 8
		fprintf(stderr, "cp: "); perror(from);
E 8
I 8
		Perror(from);
E 8
		return (1);
E 2
	}
D 2
	fstat(fold, &stbuf1);
	mode = stbuf1.st_mode;
	/* is target a directory? */
	if (stat(to, &stbuf2) >=0 &&
	   (stbuf2.st_mode&S_IFMT) == S_IFDIR) {
		p1 = from;
		p2 = to;
		bp = iobuf;
		while(*bp++ = *p2++)
			;
		bp[-1] = '/';
		p2 = bp;
		while(*bp = *p1++)
			if (*bp++ == '/')
				bp = p2;
		to = iobuf;
E 2
I 2
	if (fstat(fold, &stfrom) < 0) {
D 8
		fprintf(stderr, "cp: "); perror(from);
E 8
I 8
		Perror(from);
		(void) close(fold);
E 8
		return (1);
E 2
	}
D 2
	if (stat(to, &stbuf2) >= 0) {
		if (stbuf1.st_dev == stbuf2.st_dev &&
		   stbuf1.st_ino == stbuf2.st_ino) {
			fprintf(stderr, "cp: cannot copy file to itself.\n");
E 2
I 2
D 3
	if (lstat(to, &stto) >= 0 &&
E 3
I 3
	if (stat(to, &stto) >= 0 &&
E 3
	   (stto.st_mode&S_IFMT) == S_IFDIR) {
		last = rindex(from, '/');
		if (last) last++; else last = from;
D 10
		if (strlen(to) + strlen(last) >= BSIZE - 1) {
E 10
I 10
		if (strlen(to) + strlen(last) >= sizeof destname - 1) {
E 10
			fprintf(stderr, "cp: %s/%s: Name too long", to, last);
I 8
			(void) close(fold);
E 8
E 2
			return(1);
D 2
		} else if (iflag) {
E 2
I 2
		}
		(void) sprintf(destname, "%s/%s", to, last);
		to = destname;
	}
	if (rflag && (stfrom.st_mode&S_IFMT) == S_IFDIR) {
I 14
		int fixmode = 0;	/* cleanup mode after rcopy */

E 14
		(void) close(fold);
D 3
		if (lstat(to, &stto) < 0) {
E 3
I 3
		if (stat(to, &stto) < 0) {
E 3
D 7
			if (mkdir(to, (int)stfrom.st_mode) < 0)
E 7
I 7
D 10
			if (mkdir(to, (int)stfrom.st_mode) < 0) {
E 10
I 10
D 14
			if (mkdir(to, stfrom.st_mode & 07777) < 0) {
E 14
I 14
			if (mkdir(to, (stfrom.st_mode & 07777) | 0700) < 0) {
E 14
E 10
D 8
				fprintf(stderr, "cp: "); perror(to);
E 8
I 8
				Perror(to);
E 8
E 7
				return (1);
I 7
			}
I 14
			fixmode = 1;
E 14
E 7
		} else if ((stto.st_mode&S_IFMT) != S_IFDIR) {
			fprintf(stderr, "cp: %s: Not a directory.\n", to);
			return (1);
D 13
		}
E 13
I 13
		} else if (pflag)
I 14
			fixmode = 1;
		n = rcopy(from, to);
		if (fixmode)
E 14
			(void) chmod(to, stfrom.st_mode & 07777);
E 13
D 14
		return (rcopy(from, to));
E 14
I 14
		return (n);
E 14
	}
I 10

	if ((stfrom.st_mode&S_IFMT) == S_IFDIR)
		fprintf(stderr,
			"cp: %s: Is a directory (copying as plain file).\n",
				from);

E 10
D 3
	if (lstat(to, &stto) >= 0) {
E 3
I 3
D 13
	if (stat(to, &stto) >= 0) {
E 13
I 13
	exists = stat(to, &stto) == 0;
	if (exists) {
E 13
E 3
		if (stfrom.st_dev == stto.st_dev &&
		   stfrom.st_ino == stto.st_ino) {
D 10
			fprintf(stderr, "cp: Cannot copy file to itself.\n");
E 10
I 10
			fprintf(stderr,
				"cp: %s and %s are identical (not copied).\n",
					from, to);
E 10
I 8
			(void) close(fold);
E 8
			return (1);
		}
D 10
		if (iflag) {
E 10
I 10
		if (iflag && isatty(fileno(stdin))) {
E 10
			int i, c;

E 2
			fprintf (stderr, "overwrite %s? ", to);
			i = c = getchar();
			while (c != '\n' && c != EOF)
				c = getchar();
D 8
			if (i != 'y')
E 8
I 8
			if (i != 'y') {
				(void) close(fold);
E 8
				return(1);
I 8
			}
E 8
		}
	}
D 2
	if ((fnew = creat(to, mode)) < 0) {
		fprintf(stderr, "cp: cannot create %s\n", to);
		close(fold);
		return(1);
E 2
I 2
D 10
	fnew = creat(to, (int)stfrom.st_mode);
E 10
I 10
	fnew = creat(to, stfrom.st_mode & 07777);
E 10
	if (fnew < 0) {
D 8
		fprintf(stderr, "cp: ");
		perror(to);
E 8
I 8
		Perror(to);
E 8
		(void) close(fold); return(1);
E 2
	}
I 13
	if (exists && pflag)
		(void) fchmod(fnew, stfrom.st_mode & 07777);
			
E 13
D 2
	while(n = read(fold,  iobuf,  BSIZE)) {
E 2
I 2
	for (;;) {
D 10
		n = read(fold, buf, BSIZE);
E 10
I 10
		n = read(fold, buf, sizeof buf);
E 10
		if (n == 0)
			break;
E 2
		if (n < 0) {
D 2
			perror("cp: read");
			close(fold);
			close(fnew);
			return(1);
		} else
			if (write(fnew, iobuf, n) != n) {
				perror("cp: write");
				close(fold);
				close(fnew);
				return(1);
E 2
I 2
D 8
			fprintf(stderr, "cp: "); perror(from);
E 8
I 8
			Perror(from);
E 8
			(void) close(fold); (void) close(fnew); return (1);
		}
		if (write(fnew, buf, n) != n) {
D 8
			fprintf(stderr, "cp: "); perror(to);
E 8
I 8
			Perror(to);
E 8
			(void) close(fold); (void) close(fnew); return (1);
		}
	}
D 11
	(void) close(fold); (void) close(fnew); return (0);
E 11
I 11
	(void) close(fold); (void) close(fnew); 
	if (pflag)
		return (setimes(to, &stfrom));
	return (0);
E 11
}

rcopy(from, to)
	char *from, *to;
{
	DIR *fold = opendir(from);
	struct direct *dp;
I 11
	struct stat statb;
E 11
	int errs = 0;
D 10
	char fromname[BUFSIZ];
E 10
I 10
	char fromname[MAXPATHLEN + 1];
E 10

D 11
	if (fold == 0) {
E 11
I 11
	if (fold == 0 || (pflag && fstat(fold->dd_fd, &statb) < 0)) {
E 11
D 8
		perror(from);
E 8
I 8
		Perror(from);
E 8
		return (1);
	}
	for (;;) {
		dp = readdir(fold);
D 4
		if (dp == 0)
E 4
I 4
		if (dp == 0) {
			closedir(fold);
I 11
			if (pflag)
				return (setimes(to, &statb) + errs);
E 11
E 4
			return (errs);
I 4
		}
E 4
		if (dp->d_ino == 0)
			continue;
		if (!strcmp(dp->d_name, ".") || !strcmp(dp->d_name, ".."))
			continue;
D 10
		if (strlen(from) + 1 + strlen(dp->d_name) >= BUFSIZ - 1) {
E 10
I 10
		if (strlen(from)+1+strlen(dp->d_name) >= sizeof fromname - 1) {
E 10
			fprintf(stderr, "cp: %s/%s: Name too long.\n",
			    from, dp->d_name);
			errs++;
			continue;
		}
		(void) sprintf(fromname, "%s/%s", from, dp->d_name);
		errs += copy(fromname, to);
	}
I 11
}

int
setimes(path, statp)
	char *path;
	struct stat *statp;
{
	struct timeval tv[2];
	
	tv[0].tv_sec = statp->st_atime;
	tv[1].tv_sec = statp->st_mtime;
	tv[0].tv_usec = tv[1].tv_usec = 0;
	if (utimes(path, tv) < 0) {
		Perror(path);
		return (1);
	}
	return (0);
E 11
I 8
}

Perror(s)
	char *s;
{

	fprintf(stderr, "cp: ");
	perror(s);
E 8
D 7
}

mkdir(name, mode)
	char *name;
	int mode;
{
	char *argv[4];
	int pid, rc;

	argv[0] = "mkdir";
	argv[1] = name;
	argv[2] = 0;
	pid = fork();
	if (pid < 0) {
		perror("cp");
		return (1);
	}
	if (pid) {
		while (wait(&rc) != pid)
			continue;
		if (rc == 0)
			if (chmod(name, mode) < 0) {
				perror(name);
				rc = 1;
E 2
			}
I 2
		return (rc);
E 2
	}
D 2
	close(fold);
	close(fnew);
	return(0);
E 2
I 2
	execv("/bin/mkdir", argv);
	execv("/usr/bin/mkdir", argv);
	perror("mkdir");
	_exit(1);
	/*NOTREACHED*/
E 7
E 2
}
E 1
