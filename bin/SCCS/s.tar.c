h57958
s 00013/00000/01414
d D 5.12 88/05/23 19:32:17 bostic 38 37
c add 's' flag, to strip off leading slashes
e
s 00003/00003/01411
d D 5.11 87/12/21 12:39:01 bostic 37 36
c make ANSI C compatible
e
s 00012/00013/01402
d D 5.10 87/10/22 09:58:41 bostic 36 35
c ANSI C; sprintf now returns an int.
e
s 00001/00001/01414
d D 5.9 87/04/10 07:44:36 bostic 35 34
c another long foul-up
e
s 00002/00004/01413
d D 5.8 86/11/17 14:09:43 bostic 34 33
c when a directory appears twice on a tape; bug report 4.3BSD/bin/19
e
s 00069/00052/01348
d D 5.7 86/04/26 04:34:38 lepreau 33 32
c handle file args with 't' option; missing arg to fprintf in guy's delta; lint.
e
s 00014/00010/01386
d D 5.6 86/04/26 01:02:09 lepreau 32 31
c restore stick bits on directories; fix up comments on dodirtimes().
e
s 00119/00081/01277
d D 5.5 86/04/12 18:54:05 mckusick 31 30
c more consistant error codes; choose block size more carefully (from guy@sun)
e
s 00016/00002/01342
d D 5.4 85/10/22 19:35:24 bloom 30 29
c careful about that unlink (from Keith Muller muller@sdcsvax)
e
s 00003/00002/01341
d D 5.3 85/08/13 11:18:48 mckusick 29 28
c force Bflag when using stdin; gracefully handle EOF on input
e
s 00145/00130/01198
d D 5.2 85/06/07 11:46:48 lepreau 28 26
c preserve mtimes of extracted dirs; fix bug in vfile printing;
c some cleanup and linting; remove chgreel() at kjd's request
e
s 00145/00130/01198
d R 5.2 85/06/07 11:35:05 lepreau 27 26
c preserve mtimes of extracted dirs; a bit of cleanup and linting;
e
s 00014/00002/01314
d D 5.1 85/06/06 11:13:36 dist 26 25
c Add copyright
e
s 00093/00024/01223
d D 4.23 85/06/05 21:10:48 kjd 25 24
c Tape Blocking via stat, vfile output and linebuffering output 
c F flag now skips RCS files, Force i/o blocking to 20 over non tape devices
e
s 00047/00092/01200
d D 4.22 85/06/03 14:20:12 kjd 24 22
c remove RCS header from BRL, remove code that page aligns buffers 
c malloc does page alignments.
e
s 00003/00004/01288
d R 4.22 85/06/03 14:07:52 kjd 23 22
c remove RCS header's from BRL, remove code which page aligns 
c buffers malloc does the page alignments.
e
s 00178/00182/01114
d D 4.21 85/05/30 16:28:01 kjd 22 20
c Exact copy recived from BRL, This is a more efficient version
e
s 00144/00040/01256
d R 4.21 85/04/18 17:42:51 kjd 21 20
c 
e
s 00172/00043/01124
d D 4.20 85/04/02 08:47:02 ralph 20 19
c use optimal block size (from stat), handle multiple volumes.
e
s 00016/00004/01151
d D 4.19 83/09/22 08:29:40 mckusick 19 18
c check that chdir worked before trying to read directory (genji@topaz)
e
s 00001/00001/01154
d D 4.18 83/09/12 10:42:15 karels 18 17
c set directory modes correctly (from shannon)
e
s 00060/00058/01095
d D 4.17 83/06/30 14:58:11 sam 17 16
c from sun, important: eliminate need to backspace when x'ng multiple tar file
e
s 00013/00008/01140
d D 4.16 83/06/10 23:13:17 sam 16 15
c modernize to new time and utimes stuff
e
s 00179/00097/00969
d D 4.15 83/04/30 18:20:10 sam 15 14
c many bug fixes from shannon (the last instance of these fixes 
c got lost somewhere); also addition of i flag for ignoring directory checksum 
c errors and F flag for feathering (multiple F's force .o's and a.out also to 
c be ignored as well)
e
s 00016/00003/01050
d D 4.14 83/01/05 22:57:47 sam 14 13
c adjust to revised getwd
e
s 00007/00040/01046
d D 4.13 82/12/19 12:13:53 sam 13 12
c handle symbolic links properly and use mkdir sys call
e
s 00027/00010/01059
d D 4.12 82/12/09 23:37:49 sam 12 11
c handle follow/don't follow symbolic links
e
s 00029/00002/01040
d D 4.11 82/10/20 22:52:53 mckusick 11 10
c add -B option to loop over reads until buffer is full to pipeline over network
e
s 00005/00001/01037
d D 4.10 82/09/11 19:20:45 mckusick 10 9
c sam's changes of stat to lstat
e
s 00001/00001/01037
d D 4.9 82/05/07 16:48:05 mckusick 9 8
c update to new fs
e
s 00001/00001/01037
d D 4.8 82/03/31 21:56:09 mckusic 8 7
c change <sys/types.h> to <sys/param.h> for benefit of <ndir.h>
e
s 00291/00209/00747
d D 4.7 82/03/17 15:28:59 root 7 6
c symbolic links added
e
s 00017/00019/00939
d D 4.6 82/02/21 15:16:59 mckusic 6 5
c convert to new directory access routines
e
s 00001/00001/00957
d D 4.5 81/04/02 22:20:40 wnj 5 4
c sccs id restored
e
s 00023/00040/00935
d D 4.4 81/04/02 22:19:56 wnj 4 3
c can update block tapes!
e
s 00001/00001/00974
d D 4.3 81/03/22 21:12:45 wnj 3 2
c max blocking 20 again
e
s 00006/00007/00969
d D 4.2 80/12/18 01:02:33 wnj 2 1
c fix to preservation of ownerships
e
s 00976/00000/00000
d D 4.1 80/10/01 17:28:49 bill 1 0
c date and time created 80/10/01 17:28:49 by bill
e
u
U
t
T
I 26
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 26
I 1
D 4
static char *sccsid = "%W% (Berkeley) %G%";
E 4
I 4
D 5
static char *sccsid = "@(#)tar.c	4.3 (Berkeley) 03/31/81";
E 5
I 5
D 15
static	char *sccsid = "%W% (Berkeley) %E%";
E 15
I 15
#ifndef lint
D 26
static	char *sccsid = "%W% (Berkeley) %G%";
#endif
E 26
I 26
char copyright[] =
D 33
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
E 33
I 33
"@(#) Copyright (c) 1980 Regents of the University of California.\n\
E 33
 All rights reserved.\n";
D 37
#endif not lint
E 37
I 37
#endif /* not lint */
E 37

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 37
#endif not lint
E 37
I 37
#endif /* not lint */
E 37
E 26
E 15
I 7

/*
D 22
 * Tape Archival Program
E 22
I 22
D 24
 *			T A R . C 
 *
 * $Revision: 1.4 $
 *
 * $Log:	tar.c,v $
 * Revision 1.4  84/11/14  00:08:15  root
 * New more efficient version.  Minimizes the number of bcopys
 * and maximizes block buffering.  Page aligns block buffers.
 * 
 * Revision 1.3  84/02/23  20:24:42  dpk
 * Added missing close(infile) to prevent running out of fd's
 * 
 * Revision 1.2  84/02/23  20:17:02  dpk
 * Added distinctive RCS header
 * 
E 22
 */
I 22
#ifndef lint
static char RCSid[] = "@(#)$Header: tar.c,v 1.4 84/11/14 00:08:15 root Exp $";
#endif
E 22
I 20

I 22

/*
E 24
 * Tape Archival Program
 */
E 22
E 20
E 7
E 5
E 4
#include <stdio.h>
D 8
#include <sys/types.h>
E 8
I 8
#include <sys/param.h>
E 8
#include <sys/stat.h>
D 6
#include <sys/dir.h>
E 6
I 6
D 9
#include <ndir.h>
E 9
I 9
D 15
#include <dir.h>
E 15
I 15
#include <sys/dir.h>
E 15
I 10
#include <sys/ioctl.h>
E 10
E 9
E 6
I 4
#include <sys/mtio.h>
I 16
#include <sys/time.h>
E 16
E 4
#include <signal.h>
I 15
#include <errno.h>
I 31
#include <fcntl.h>
E 31
E 15

D 7
char	*sprintf();
char	*strcat();
daddr_t	bsrch();
E 7
#define TBLOCK	512
D 3
#define NBLOCK	40
E 3
I 3
#define NBLOCK	20
E 3
#define NAMSIZ	100
I 25
D 31
#define FILEBLOCK 20
E 31
E 25
I 7

I 22
#define	writetape(b)	writetbuf(b, 1)
#define	min(a,b)  ((a) < (b) ? (a) : (b))
#define	max(a,b)  ((a) > (b) ? (a) : (b))

E 22
E 7
union hblock {
	char dummy[TBLOCK];
	struct header {
		char name[NAMSIZ];
		char mode[8];
		char uid[8];
		char gid[8];
		char size[12];
		char mtime[12];
		char chksum[8];
		char linkflag;
		char linkname[NAMSIZ];
	} dbuf;
D 7
} dblock, tbuf[NBLOCK];
E 7
I 7
};
E 7

struct linkbuf {
	ino_t	inum;
	dev_t	devnum;
	int	count;
	char	pathname[NAMSIZ];
	struct	linkbuf *nextp;
D 7
} *ihead;
E 7
I 7
};
E 7

D 7
struct stat stbuf;
E 7
I 7
union	hblock dblock;
D 17
union	hblock tbuf[NBLOCK];
E 17
I 17
union	hblock *tbuf;
E 17
struct	linkbuf *ihead;
struct	stat stbuf;
E 7

D 7
int	rflag, xflag, vflag, tflag, mt, cflag, mflag, fflag, oflag, pflag;
int	term, chksum, wflag, recno, first, linkerrok;
E 7
I 7
int	rflag;
I 38
int	sflag;
E 38
int	xflag;
int	vflag;
int	tflag;
int	cflag;
int	mflag;
int	fflag;
I 15
int	iflag;
E 15
int	oflag;
int	pflag;
int	wflag;
int	hflag;
I 11
int	Bflag;
I 15
int	Fflag;
I 20
D 22
int	Mflag;
E 22
E 20
E 15
E 11

I 20
D 22
int	superuser;
E 22
E 20
int	mt;
I 25
D 31
int	mtdev = 1;
E 31
E 25
int	term;
int	chksum;
int	recno;
D 25
int	first;
E 25
I 25
D 28
int	first = 0;
E 25
int	linkerrok;
E 28
I 28
int	first;
int	prtlinkerr;
E 28
E 7
int	freemem = 1;
D 4
int	nblock = 1;
E 4
I 4
D 25
int	nblock = NBLOCK;
E 25
I 25
int	nblock = 0;
E 25
I 7
int	onintr();
int	onquit();
int	onhup();
I 28
#ifdef notdef
E 28
int	onterm();
I 28
#endif
E 28
E 7
E 4

daddr_t	low;
daddr_t	high;
I 7
daddr_t	bsrch();
E 7

I 24
FILE	*vfile = stdout;
E 24
FILE	*tfile;
char	tname[] = "/tmp/tarXXXXXX";
D 7


E 7
char	*usefile;
D 7
char	magtape[]	= "/dev/rmt8";

E 7
I 7
char	magtape[] = "/dev/rmt8";
E 7
char	*malloc();
I 33
long	time();
off_t	lseek();
char	*mktemp();
E 33
I 7
D 36
char	*sprintf();
E 36
char	*strcat();
I 31
char	*strcpy();
E 31
I 15
char	*rindex();
E 15
I 14
char	*getcwd();
E 14
I 13
char	*getwd();
I 28
char	*getmem();
E 28
E 13
E 7

main(argc, argv)
int	argc;
char	*argv[];
{
	char *cp;
D 7
	int onintr(), onquit(), onhup(), onterm();
E 7

	if (argc < 2)
		usage();

I 20
D 22
	/* determine if the super user is running this program */
	superuser = !getuid();

E 22
E 20
	tfile = NULL;
	usefile =  magtape;
	argv[argc] = 0;
	argv++;
	for (cp = *argv++; *cp; cp++) 
		switch(*cp) {
I 7

E 7
		case 'f':
I 15
			if (*argv == 0) {
				fprintf(stderr,
			"tar: tapefile must be specified with 'f' option\n");
				usage();
			}
E 15
			usefile = *argv++;
			fflag++;
D 4
			if (nblock == 1)
				nblock = 0;
E 4
			break;
I 7

E 7
		case 'c':
			cflag++;
			rflag++;
			break;
I 7

E 7
		case 'o':
			oflag++;
			break;
I 7

E 7
		case 'p':
			pflag++;
			break;
I 7
		
E 7
		case 'u':
			mktemp(tname);
			if ((tfile = fopen(tname, "w")) == NULL) {
D 7
				fprintf(stderr, "Tar: cannot create temporary file (%s)\n", tname);
E 7
I 7
				fprintf(stderr,
D 28
				 "Tar: cannot create temporary file (%s)\n",
E 28
I 28
				 "tar: cannot create temporary file (%s)\n",
E 28
				 tname);
E 7
				done(1);
			}
			fprintf(tfile, "!!!!!/!/!/!/!/!/!/! 000\n");
D 7
			/* FALL THROUGH */
E 7
I 7
			/*FALL THRU*/

E 7
		case 'r':
			rflag++;
D 4
noupdate:
			if (nblock != 1 && cflag == 0) {
				fprintf(stderr, "Tar: Blocked tapes cannot be updated (yet)\n");
				done(1);
			}
E 4
			break;
I 7

I 38
		case 's':
			sflag++;
			break;

E 38
E 7
		case 'v':
			vflag++;
			break;
I 7

E 7
		case 'w':
			wflag++;
			break;
I 7

E 7
		case 'x':
			xflag++;
			break;
I 7

E 7
		case 't':
			tflag++;
			break;
I 7

E 7
		case 'm':
			mflag++;
			break;
I 7

I 20
D 22
		case 'M':
			Mflag++;
			break;

E 22
E 20
E 7
		case '-':
			break;
I 7

E 7
		case '0':
		case '1':
		case '4':
		case '5':
I 22
		case '7':
E 22
D 20
		case '7':
E 20
		case '8':
I 20
D 22
		case '9':
E 22
E 20
			magtape[8] = *cp;
			usefile = magtape;
			break;
I 7

E 7
		case 'b':
D 17
			nblock = atoi(*argv++);
			if (nblock > NBLOCK || nblock <= 0) {
D 7
				fprintf(stderr, "Invalid blocksize. (Max %d)\n", NBLOCK);
E 7
I 7
				fprintf(stderr, "Invalid blocksize. (Max %d)\n",
					NBLOCK);
E 17
I 17
			if (*argv == 0) {
				fprintf(stderr,
			"tar: blocksize must be specified with 'b' option\n");
				usage();
			}
			nblock = atoi(*argv);
			if (nblock <= 0) {
				fprintf(stderr,
				    "tar: invalid blocksize \"%s\"\n", *argv);
E 17
E 7
				done(1);
			}
I 17
			argv++;
E 17
D 4
			if (rflag && !cflag)
				goto noupdate;
E 4
			break;
I 7

E 7
		case 'l':
D 28
			linkerrok++;
E 28
I 28
			prtlinkerr++;
E 28
			break;
I 7

		case 'h':
			hflag++;
			break;

I 15
		case 'i':
			iflag++;
			break;

E 15
I 11
		case 'B':
			Bflag++;
			break;

I 15
		case 'F':
			Fflag++;
			break;

E 15
E 11
E 7
		default:
			fprintf(stderr, "tar: %c: unknown option\n", *cp);
			usage();
		}

I 7
	if (!rflag && !xflag && !tflag)
		usage();
I 22
D 24
#ifndef vax
E 22
I 17
	tbuf = (union hblock *)malloc(nblock*TBLOCK);
I 22
#else
	/*
	 *  The following is for 4.2BSD and related systems to force
	 *  the buffer to be page aligned.  The kernel will avoid
	 *  bcopy()'s on disk IO this way by manipulating the page tables.
	 */
	{
		int pagesize = getpagesize();

		tbuf = (union hblock *)malloc((nblock*TBLOCK)+pagesize);
		tbuf = (union hblock *)(((int)tbuf+pagesize)&~(pagesize-1));
	}
#endif vax
E 22
	if (tbuf == NULL) {
		fprintf(stderr, "tar: blocksize %d too big, can't get memory\n",
		    nblock);
		done(1);
	}
E 24
E 17
E 7
	if (rflag) {
D 7
		if (cflag && tfile != NULL) {
E 7
I 7
		if (cflag && tfile != NULL)
E 7
			usage();
D 7
			done(1);
		}
E 7
		if (signal(SIGINT, SIG_IGN) != SIG_IGN)
D 33
			signal(SIGINT, onintr);
E 33
I 33
			(void) signal(SIGINT, onintr);
E 33
		if (signal(SIGHUP, SIG_IGN) != SIG_IGN)
D 33
			signal(SIGHUP, onhup);
E 33
I 33
			(void) signal(SIGHUP, onhup);
E 33
		if (signal(SIGQUIT, SIG_IGN) != SIG_IGN)
D 33
			signal(SIGQUIT, onquit);
E 33
I 33
			(void) signal(SIGQUIT, onquit);
E 33
D 7
/*
E 7
I 7
#ifdef notdef
E 7
		if (signal(SIGTERM, SIG_IGN) != SIG_IGN)
D 33
			signal(SIGTERM, onterm);
E 33
I 33
			(void) signal(SIGTERM, onterm);
E 33
D 7
*/
E 7
I 7
#endif
E 7
D 31
		if (strcmp(usefile, "-") == 0) {
			if (cflag == 0) {
D 7
				fprintf(stderr, "Can only create standard output archives\n");
E 7
I 7
				fprintf(stderr,
D 17
				 "Can only create standard output archives\n");
E 17
I 17
			 "tar: can only create standard output archives\n");
E 17
E 7
				done(1);
			}
I 24
			vfile = stderr;
			setlinebuf(vfile);
E 24
			mt = dup(1);
D 25
			nblock = 1;
E 25
D 7
		}
		else if ((mt = open(usefile, 2)) < 0) {
E 7
I 7
		} else if ((mt = open(usefile, 2)) < 0) {
E 7
			if (cflag == 0 || (mt =  creat(usefile, 0666)) < 0) {
D 7
				fprintf(stderr, "tar: cannot open %s\n", usefile);
E 7
I 7
				fprintf(stderr,
					"tar: cannot open %s\n", usefile);
E 7
				done(1);
			}
		}
E 31
I 31
		mt = openmt(usefile, 1);
E 31
D 4
		if (cflag == 0 && nblock == 0)
			nblock = 1;
E 4
		dorep(argv);
I 7
		done(0);
E 7
	}
D 7
	else if (xflag)  {
		if (strcmp(usefile, "-") == 0) {
			mt = dup(0);
			nblock = 1;
		}
		else if ((mt = open(usefile, 0)) < 0) {
			fprintf(stderr, "tar: cannot open %s\n", usefile);
			done(1);
		}
		doxtract(argv);
E 7
I 7
D 31
	if (strcmp(usefile, "-") == 0) {
		mt = dup(0);
I 29
		Bflag++;
E 29
D 25
		nblock = 1;
E 25
	} else if ((mt = open(usefile, 0)) < 0) {
		fprintf(stderr, "tar: cannot open %s\n", usefile);
		done(1);
E 7
	}
E 31
I 31
	mt = openmt(usefile, 0);
E 31
D 7
	else if (tflag) {
		if (strcmp(usefile, "-") == 0) {
			mt = dup(0);
			nblock = 1;
		}
		else if ((mt = open(usefile, 0)) < 0) {
			fprintf(stderr, "tar: cannot open %s\n", usefile);
			done(1);
		}
		dotable();
	}
E 7
I 7
	if (xflag)
		doxtract(argv);
E 7
	else
D 7
		usage();
E 7
I 7
D 33
		dotable();
E 33
I 33
		dotable(argv);
E 33
E 7
	done(0);
}

usage()
{
D 7
	fprintf(stderr, "tar: usage  tar -{txru}[cvfblm] [tapefile] [blocksize] file1 file2...\n");
E 7
I 7
	fprintf(stderr,
D 11
"tar: usage  tar -{txru}[cvfblmh] [tapefile] [blocksize] file1 file2...\n");
E 11
I 11
D 17
"tar: usage  tar -{txruB}[cvfblmh] [tapefile] [blocksize] file1 file2...\n");
E 17
I 17
D 20
"tar: usage: tar -{txru}[cvfblmhopwBi] [tapefile] [blocksize] file1 file2...\n");
E 20
I 20
D 22
"tar: usage: tar -{txru}[cvfblmhopwBFMi] [tapefile] [blocksize] file1 file2...\n");
E 22
I 22
"tar: usage: tar -{txru}[cvfblmhopwBi] [tapefile] [blocksize] file1 file2...\n");
E 22
E 20
E 17
E 11
E 7
	done(1);
}

I 31
int
openmt(tape, writing)
	char *tape;
	int writing;
{
D 33
	register char *rmtape;
	extern char *rmterr;
E 33

	if (strcmp(tape, "-") == 0) {
		/*
		 * Read from standard input or write to standard output.
		 */
		if (writing) {
			if (cflag == 0) {
				fprintf(stderr,
			 "tar: can only create standard output archives\n");
				done(1);
			}
			vfile = stderr;
			setlinebuf(vfile);
			mt = dup(1);
		} else {
			mt = dup(0);
			Bflag++;
		}
	} else {
		/*
		 * Use file or tape on local machine.
		 */
		if (writing) {
			if (cflag)
D 33
				mt = open(tape, O_RDWR|O_CREAT|O_TRUNC,
				    0666);
E 33
I 33
				mt = open(tape, O_RDWR|O_CREAT|O_TRUNC, 0666);
E 33
			else
				mt = open(tape, O_RDWR);
		} else
			mt = open(tape, O_RDONLY);
		if (mt < 0) {
			fprintf(stderr, "tar: ");
			perror(tape);
			done(1);
		}
	}
	return(mt);
}

E 31
dorep(argv)
D 7
char	*argv[];
E 7
I 7
	char *argv[];
E 7
{
	register char *cp, *cp2;
D 12
	char wdir[60];
E 12
I 12
	char wdir[MAXPATHLEN], tempdir[MAXPATHLEN], *parent;
E 12

	if (!cflag) {
		getdir();
		do {
			passtape();
			if (term)
				done(0);
			getdir();
		} while (!endtape());
I 17
		backtape();
E 17
		if (tfile != NULL) {
			char buf[200];

D 4
			strcat(buf, "sort +0 -1 +1nr ");
			strcat(buf, tname);
			strcat(buf, " -o ");
			strcat(buf, tname);
			sprintf(buf, "sort +0 -1 +1nr %s -o %s; awk '$1 != prev {print; prev=$1}' %s >%sX;mv %sX %s",
E 4
I 4
D 7
			sprintf(buf, "sort +0 -1 +1nr %s -o %s; awk '$1 != prev {print; prev=$1}' %s >%sX; mv %sX %s",
E 7
I 7
D 36
			sprintf(buf,
E 36
I 36
			(void)sprintf(buf,
E 36
"sort +0 -1 +1nr %s -o %s; awk '$1 != prev {print; prev=$1}' %s >%sX; mv %sX %s",
E 7
E 4
				tname, tname, tname, tname, tname, tname);
			fflush(tfile);
			system(buf);
			freopen(tname, "r", tfile);
			fstat(fileno(tfile), &stbuf);
			high = stbuf.st_size;
		}
	}

D 13
	getwdir(wdir);
E 13
I 13
D 14
	(void) getwd(wdir);
E 14
I 14
	(void) getcwd(wdir);
E 14
E 13
	while (*argv && ! term) {
		cp2 = *argv;
		if (!strcmp(cp2, "-C") && argv[1]) {
			argv++;
D 31
			if (chdir(*argv) < 0)
E 31
I 31
			if (chdir(*argv) < 0) {
				fprintf(stderr, "tar: can't change directories to ");
E 31
				perror(*argv);
D 31
			else
E 31
I 31
			} else
E 31
D 13
				getwdir(wdir);
E 13
I 13
D 14
				(void) getwd(wdir);
E 14
I 14
				(void) getcwd(wdir);
E 14
E 13
			argv++;
			continue;
		}
I 12
		parent = wdir;
E 12
		for (cp = *argv; *cp; cp++)
			if (*cp == '/')
				cp2 = cp;
		if (cp2 != *argv) {
			*cp2 = '\0';
D 12
			chdir(*argv);
E 12
I 12
			if (chdir(*argv) < 0) {
I 31
				fprintf(stderr, "tar: can't change directories to ");
E 31
				perror(*argv);
				continue;
			}
D 13
			getwdir(tempdir);
			parent = tempdir;
E 13
I 13
D 14
			parent = getwd(tempdir);
E 14
I 14
			parent = getcwd(tempdir);
E 14
E 13
E 12
			*cp2 = '/';
			cp2++;
		}
D 12
		putfile(*argv++, cp2);
E 12
I 12
		putfile(*argv++, cp2, parent);
E 12
D 19
		chdir(wdir);
E 19
I 19
		if (chdir(wdir) < 0) {
D 20
			fprintf(stderr, "cannot change back?: ");
E 20
I 20
D 22
			fprintf(stderr, "tar: cannot chdir back?: ");
E 22
I 22
D 28
			fprintf(stderr, "cannot change back?: ");
E 28
I 28
			fprintf(stderr, "tar: cannot change back?: ");
E 28
E 22
E 20
			perror(wdir);
		}
E 19
	}
	putempty();
	putempty();
	flushtape();
D 7
	if (linkerrok == 1)
		for (; ihead != NULL; ihead = ihead->nextp)
			if (ihead->count != 0)
				fprintf(stderr, "Missing links to %s\n", ihead->pathname);
E 7
I 7
D 28
	if (linkerrok == 0)
E 28
I 28
	if (prtlinkerr == 0)
E 28
		return;
	for (; ihead != NULL; ihead = ihead->nextp) {
		if (ihead->count == 0)
			continue;
D 17
		fprintf(stderr, "Missing links to %s\n", ihead->pathname);
E 17
I 17
		fprintf(stderr, "tar: missing links to %s\n", ihead->pathname);
E 17
	}
E 7
}

endtape()
{
D 7
	if (dblock.dbuf.name[0] == '\0') {
		backtape();
		return(1);
	}
	else
		return(0);
E 7
I 7
D 17
	if (dblock.dbuf.name[0] != '\0')
		return (0);
	backtape();
	return (1);
E 17
I 17
D 20
	return (dblock.dbuf.name[0] == '\0');
E 20
I 20
D 22
	if (dblock.dbuf.name[0] != '\0')
		return (0);
	backtape();
	return (1);
E 22
I 22
	return (dblock.dbuf.name[0] == '\0');
E 22
E 20
E 17
E 7
}

getdir()
{
	register struct stat *sp;
	int i;

I 15
top:
E 15
D 7
	readtape( (char *) &dblock);
E 7
I 7
	readtape((char *)&dblock);
E 7
	if (dblock.dbuf.name[0] == '\0')
		return;
	sp = &stbuf;
	sscanf(dblock.dbuf.mode, "%o", &i);
	sp->st_mode = i;
	sscanf(dblock.dbuf.uid, "%o", &i);
	sp->st_uid = i;
	sscanf(dblock.dbuf.gid, "%o", &i);
	sp->st_gid = i;
	sscanf(dblock.dbuf.size, "%lo", &sp->st_size);
	sscanf(dblock.dbuf.mtime, "%lo", &sp->st_mtime);
	sscanf(dblock.dbuf.chksum, "%o", &chksum);
D 15
	if (chksum != checksum()) {
		fprintf(stderr, "directory checksum error\n");
E 15
I 15
	if (chksum != (i = checksum())) {
D 17
		fprintf(stderr, "directory checksum error (%d != %d)\n",
E 17
I 17
		fprintf(stderr, "tar: directory checksum error (%d != %d)\n",
E 17
		    chksum, i);
		if (iflag)
			goto top;
E 15
		done(2);
I 38
	}
	/* strip off leading "/" if present */
	if (sflag && dblock.dbuf.name[0] == '/') {
		register char *cp1, *cp2;
		for (cp1 = cp2 = dblock.dbuf.name; *cp2 && *cp2 == '/'; ++cp2);
		if (!*cp2)
			goto top;
		while (*cp1++ = *cp2++);
E 38
	}
	if (tfile != NULL)
		fprintf(tfile, "%s %s\n", dblock.dbuf.name, dblock.dbuf.mtime);
}

passtape()
{
	long blocks;
D 20
	char buf[TBLOCK];
E 20
I 20
D 22
	int i;
E 22
I 22
	char *bufp;
E 22
E 20

	if (dblock.dbuf.linkflag == '1')
		return;
	blocks = stbuf.st_size;
	blocks += TBLOCK-1;
	blocks /= TBLOCK;

D 20
	while (blocks-- > 0)
		readtape(buf);
E 20
I 20
D 22
	while (blocks > 0) {
		readtape(NULL);
		i = nblock - recno;
		if (blocks < i)
			i = blocks;
		recno += i;
		blocks -= i;
	}
E 22
I 22
	while (blocks-- > 0)
D 33
		readtbuf(&bufp, TBLOCK);
E 33
I 33
		(void) readtbuf(&bufp, TBLOCK);
E 33
E 22
E 20
}

D 12
putfile(longname, shortname)
E 12
I 12
putfile(longname, shortname, parent)
E 12
D 7
char *longname;
char *shortname;
E 7
I 7
	char *longname;
	char *shortname;
I 12
	char *parent;
E 12
E 7
{
D 15
	int infile;
E 15
I 15
D 20
	int infile = 0;
E 15
	long blocks;
E 20
I 20
D 22
	int infile;
	long blocks, size;
E 22
I 22
	int infile = 0;
	long blocks;
E 22
E 20
	char buf[TBLOCK];
I 22
D 24
#ifdef vax
E 24
D 28
	char *origbuf;
E 28
D 24
#endif
E 24
	char *bigbuf;
E 22
D 28
	register char *cp, *cp2;
E 28
I 28
	register char *cp;
E 28
D 6
	struct direct dbuf;
E 6
I 6
	struct direct *dp;
	DIR *dirp;
E 6
D 20
	int i, j;
E 20
I 20
D 22
	int i;
E 22
I 22
D 28
	int i, j;
E 28
I 28
D 33
	int i;
E 33
I 33
	register int i;
	long l;
E 33
E 28
E 22
E 20
I 12
	char newparent[NAMSIZ+64];
I 15
D 37
	extern int errno;
E 37
I 22
	int	maxread;
	int	hint;		/* amount to write to get "in sync" */
E 22
E 15
E 12

D 15
	infile = open(shortname, 0);
	if (infile < 0) {
		fprintf(stderr, "tar: %s: cannot open file\n", longname);
		return;
	}
E 15
D 7

	fstat(infile, &stbuf);

E 7
I 7
D 10
	stat(shortname, &stbuf);
E 10
I 10
D 12
	lstat(shortname, &stbuf);
E 12
I 12
	if (!hflag)
D 15
		lstat(shortname, &stbuf);
	else if (stat(shortname, &stbuf) < 0) {
		perror(longname);
		close(infile);
E 15
I 15
		i = lstat(shortname, &stbuf);
	else
		i = stat(shortname, &stbuf);
	if (i < 0) {
D 31
		switch (errno) {
		case EACCES:
			fprintf(stderr, "tar: %s: cannot open file\n", longname);
			break;
		case ENOENT:
			fprintf(stderr, "tar: %s: no such file or directory\n",
			    longname);
			break;
		default:
			fprintf(stderr, "tar: %s: cannot stat file\n", longname);
			break;
		}
E 31
I 31
		fprintf(stderr, "tar: ");
		perror(longname);
E 31
E 15
		return;
	}
E 12
E 10
E 7
D 15
	if (tfile != NULL && checkupdate(longname) == 0) {
		close(infile);
E 15
I 15
	if (tfile != NULL && checkupdate(longname) == 0)
E 15
		return;
D 15
	}
	if (checkw('r', longname) == 0) {
		close(infile);
E 15
I 15
	if (checkw('r', longname) == 0)
E 15
		return;
D 15
	}
E 15
I 15
	if (Fflag && checkf(shortname, stbuf.st_mode, Fflag) == 0)
		return;
E 15

D 15
	if ((stbuf.st_mode & S_IFMT) == S_IFDIR) {
E 15
I 15
	switch (stbuf.st_mode & S_IFMT) {
	case S_IFDIR:
E 15
D 7
		for (i = 0, cp = buf; *cp++ = longname[i++];);
E 7
I 7
		for (i = 0, cp = buf; *cp++ = longname[i++];)
			;
E 7
		*--cp = '/';
		*++cp = 0  ;
D 6
		i = 0;
E 6
		if (!oflag) {
D 7
		    if( (cp - buf) >= NAMSIZ) {
			fprintf(stderr, "%s: file name too long\n", longname);
			close(infile);
			return;
		    }
		    stbuf.st_size = 0;
		    tomodes(&stbuf);
		    strcpy(dblock.dbuf.name,buf);
		    sprintf(dblock.dbuf.chksum, "%6o", checksum());
		    writetape( (char *) &dblock);
E 7
I 7
			if ((cp - buf) >= NAMSIZ) {
D 17
				fprintf(stderr, "%s: file name too long\n",
					longname);
E 17
I 17
				fprintf(stderr, "tar: %s: file name too long\n",
				    longname);
E 17
D 15
				close(infile);
E 15
				return;
			}
			stbuf.st_size = 0;
			tomodes(&stbuf);
			strcpy(dblock.dbuf.name,buf);
D 36
			sprintf(dblock.dbuf.chksum, "%6o", checksum());
E 36
I 36
			(void)sprintf(dblock.dbuf.chksum, "%6o", checksum());
E 36
D 33
			writetape((char *)&dblock);
E 33
I 33
			(void) writetape((char *)&dblock);
E 33
E 7
		}
I 12
D 36
		sprintf(newparent, "%s/%s", parent, shortname);
E 36
I 36
		(void)sprintf(newparent, "%s/%s", parent, shortname);
E 36
E 12
D 19
		chdir(shortname);
E 19
I 19
		if (chdir(shortname) < 0) {
I 20
D 22
			fprintf(stderr, "tar: ");
E 22
E 20
			perror(shortname);
			return;
		}
E 19
D 6
		while (read(infile, (char *)&dbuf, sizeof(dbuf)) > 0 && !term) {
			if (dbuf.d_ino == 0) {
				i++;
E 6
I 6
D 15
		close(infile);
E 15
		if ((dirp = opendir(".")) == NULL) {
D 17
			fprintf(stderr, "%s: directory read error\n", longname);
E 17
I 17
			fprintf(stderr, "tar: %s: directory read error\n",
			    longname);
E 17
I 12
D 19
			chdir(parent);
E 19
I 19
			if (chdir(parent) < 0) {
D 20
				fprintf(stderr, "cannot change back?: ");
E 20
I 20
D 22
				fprintf(stderr, "tar: cannot chdir back?: ");
E 22
I 22
D 28
				fprintf(stderr, "cannot change back?: ");
E 28
I 28
				fprintf(stderr, "tar: cannot change back?: ");
E 28
E 22
E 20
				perror(parent);
			}
E 19
E 12
			return;
		}
		while ((dp = readdir(dirp)) != NULL && !term) {
D 34
			if (dp->d_ino == 0)
E 6
				continue;
E 34
D 6
			}
			if (strcmp(".", dbuf.d_name) == 0 || strcmp("..", dbuf.d_name) == 0) {
				i++;
E 6
I 6
D 7
			if (!strcmp(".", dp->d_name) || !strcmp("..", dp->d_name))
E 7
I 7
			if (!strcmp(".", dp->d_name) ||
			    !strcmp("..", dp->d_name))
E 7
E 6
				continue;
D 6
			}
			cp2 = cp;
			for (j=0; j < DIRSIZ; j++)
				*cp2++ = dbuf.d_name[j];
			*cp2 = '\0';
			close(infile);
E 6
I 6
			strcpy(cp, dp->d_name);
D 33
			i = telldir(dirp);
E 33
I 33
			l = telldir(dirp);
E 33
			closedir(dirp);
E 6
D 12
			putfile(buf, cp);
E 12
I 12
			putfile(buf, cp, newparent);
E 12
D 6
			infile = open(".", 0);
			i++;
			lseek(infile, (long) (sizeof(dbuf) * i), 0);
E 6
I 6
			dirp = opendir(".");
D 33
			seekdir(dirp, i);
E 33
I 33
			seekdir(dirp, l);
E 33
E 6
		}
D 6
		close(infile);
E 6
I 6
		closedir(dirp);
E 6
D 12
		chdir("..");
E 12
I 12
D 19
		chdir(parent);
E 19
I 19
		if (chdir(parent) < 0) {
D 20
			fprintf(stderr, "cannot change back?: ");
E 20
I 20
D 22
			fprintf(stderr, "tar: cannot chdir back?: ");
E 22
I 22
D 28
			fprintf(stderr, "cannot change back?: ");
E 28
I 28
			fprintf(stderr, "tar: cannot change back?: ");
E 28
E 22
E 20
			perror(parent);
		}
E 19
E 12
D 15
		return;
	}
D 7
	if ((stbuf.st_mode & S_IFMT) != S_IFREG) {
		fprintf(stderr, "tar: %s is not a file. Not dumped\n", longname);
E 7
I 7
	i = stbuf.st_mode & S_IFMT;
	if (i != S_IFREG && i != S_IFLNK) {
		fprintf(stderr, "tar: %s is not a file. Not dumped\n",
			longname);
E 7
		return;
	}
D 7

E 7
	tomodes(&stbuf);
D 7

	cp2 = longname;
	for (cp = dblock.dbuf.name, i=0; (*cp++ = *cp2++) && i < NAMSIZ; i++);
E 7
I 7
	cp2 = longname; cp = dblock.dbuf.name; i = 0;
	while ((*cp++ = *cp2++) && i < NAMSIZ)
		i++;
E 7
	if (i >= NAMSIZ) {
		fprintf(stderr, "%s: file name too long\n", longname);
		close(infile);
		return;
	}
D 7

E 7
I 7
	if ((stbuf.st_mode & S_IFMT) == S_IFLNK) {
E 15
I 15
		break;

	case S_IFLNK:
		tomodes(&stbuf);
		if (strlen(longname) >= NAMSIZ) {
D 17
			fprintf(stderr, "%s: file name too long\n", longname);
E 17
I 17
			fprintf(stderr, "tar: %s: file name too long\n",
			    longname);
E 17
			return;
		}
		strcpy(dblock.dbuf.name, longname);
E 15
		if (stbuf.st_size + 1 >= NAMSIZ) {
D 17
			fprintf(stderr, "%s: symbolic link too long\n",
				longname);
E 17
I 17
			fprintf(stderr, "tar: %s: symbolic link too long\n",
			    longname);
E 17
D 15
			close(infile);
E 15
			return;
		}
D 12
		i = readlink(longname, dblock.dbuf.linkname, NAMSIZ - 1);
E 12
I 12
		i = readlink(shortname, dblock.dbuf.linkname, NAMSIZ - 1);
E 12
		if (i < 0) {
I 31
			fprintf(stderr, "tar: can't read symbolic link ");
E 31
I 20
D 22
			fprintf(stderr, "tar: ");
E 22
E 20
D 12
			perror("readlink");
E 12
I 12
			perror(longname);
E 12
D 15
			close(infile);
E 15
			return;
		}
		dblock.dbuf.linkname[i] = '\0';
		dblock.dbuf.linkflag = '2';
D 28
		if (vflag) {
D 24
			fprintf(stderr, "a %s ", longname);
			fprintf(stderr, "symbolic link to %s\n",
E 24
I 24
			fprintf(vfile, "a %s ", longname);
			fprintf(vfile, "symbolic link to %s\n",
E 24
D 17
				dblock.dbuf.linkname);
E 17
I 17
			    dblock.dbuf.linkname);
E 17
		}
E 28
I 28
		if (vflag)
			fprintf(vfile, "a %s symbolic link to %s\n",
			    longname, dblock.dbuf.linkname);
E 28
D 35
		sprintf(dblock.dbuf.size, "%11lo", 0);
E 35
I 35
D 36
		sprintf(dblock.dbuf.size, "%11lo", 0L);
E 35
		sprintf(dblock.dbuf.chksum, "%6o", checksum());
E 36
I 36
		(void)sprintf(dblock.dbuf.size, "%11lo", 0L);
		(void)sprintf(dblock.dbuf.chksum, "%6o", checksum());
E 36
D 33
		writetape((char *)&dblock);
E 33
I 33
		(void) writetape((char *)&dblock);
E 33
D 15
		close(infile);
		return;
	}
E 7
	if (stbuf.st_nlink > 1) {
		struct linkbuf *lp;
		int found = 0;
E 15
I 15
		break;
E 15

D 7
		for (lp = ihead; lp != NULL; lp = lp->nextp) {
			if (lp->inum == stbuf.st_ino && lp->devnum == stbuf.st_dev) {
E 7
I 7
D 15
		for (lp = ihead; lp != NULL; lp = lp->nextp)
			if (lp->inum == stbuf.st_ino &&
			    lp->devnum == stbuf.st_dev) {
E 7
				found++;
				break;
			}
D 7
		}
E 7
		if (found) {
			strcpy(dblock.dbuf.linkname, lp->pathname);
			dblock.dbuf.linkflag = '1';
			sprintf(dblock.dbuf.chksum, "%6o", checksum());
			writetape( (char *) &dblock);
			if (vflag) {
				fprintf(stderr, "a %s ", longname);
				fprintf(stderr, "link to %s\n", lp->pathname);
			}
			lp->count--;
			close(infile);
E 15
I 15
	case S_IFREG:
		if ((infile = open(shortname, 0)) < 0) {
D 31
			fprintf(stderr, "tar: %s: cannot open file\n", longname);
E 31
I 31
			fprintf(stderr, "tar: ");
			perror(longname);
E 31
E 15
			return;
		}
D 7
		else {
			lp = (struct linkbuf *) malloc(sizeof(*lp));
			if (lp == NULL) {
				if (freemem) {
					fprintf(stderr, "Out of memory. Link information lost\n");
					freemem = 0;
				}
E 7
I 7
D 15
		lp = (struct linkbuf *) malloc(sizeof(*lp));
		if (lp == NULL) {
			if (freemem) {
				fprintf(stderr,
				  "Out of memory. Link information lost\n");
				freemem = 0;
E 15
I 15
		tomodes(&stbuf);
		if (strlen(longname) >= NAMSIZ) {
D 17
			fprintf(stderr, "%s: file name too long\n", longname);
E 17
I 17
			fprintf(stderr, "tar: %s: file name too long\n",
			    longname);
I 22
			close(infile);
E 22
E 17
			return;
		}
		strcpy(dblock.dbuf.name, longname);
		if (stbuf.st_nlink > 1) {
			struct linkbuf *lp;
			int found = 0;

			for (lp = ihead; lp != NULL; lp = lp->nextp)
				if (lp->inum == stbuf.st_ino &&
				    lp->devnum == stbuf.st_dev) {
					found++;
					break;
				}
			if (found) {
				strcpy(dblock.dbuf.linkname, lp->pathname);
				dblock.dbuf.linkflag = '1';
D 36
				sprintf(dblock.dbuf.chksum, "%6o", checksum());
E 36
I 36
				(void)sprintf(dblock.dbuf.chksum, "%6o", checksum());
E 36
D 20
				writetape( (char *) &dblock);
E 20
I 20
D 22
				writetape((char *)&dblock);
E 22
I 22
D 33
				writetape( (char *) &dblock);
E 33
I 33
				(void) writetape( (char *) &dblock);
E 33
E 22
E 20
D 28
				if (vflag) {
D 24
					fprintf(stderr, "a %s ", longname);
D 17
					fprintf(stderr, "link to %s\n", lp->pathname);
E 17
I 17
					fprintf(stderr, "link to %s\n",
E 24
I 24
					fprintf(vfile, "a %s ", longname);
					fprintf(vfile, "link to %s\n",
E 24
					    lp->pathname);
E 17
				}
E 28
I 28
				if (vflag)
					fprintf(vfile, "a %s link to %s\n",
					    longname, lp->pathname);
E 28
				lp->count--;
				close(infile);
				return;
E 15
E 7
			}
D 7
			else {
				lp->nextp = ihead;
				ihead = lp;
				lp->inum = stbuf.st_ino;
				lp->devnum = stbuf.st_dev;
				lp->count = stbuf.st_nlink - 1;
				strcpy(lp->pathname, longname);
			}
E 7
I 7
D 15
		} else {
			lp->nextp = ihead;
			ihead = lp;
			lp->inum = stbuf.st_ino;
			lp->devnum = stbuf.st_dev;
			lp->count = stbuf.st_nlink - 1;
			strcpy(lp->pathname, longname);
E 15
I 15
D 28
			lp = (struct linkbuf *) malloc(sizeof(*lp));
			if (lp == NULL) {
				if (freemem) {
					fprintf(stderr,
D 17
					  "Out of memory. Link information lost\n");
E 17
I 17
				"tar: out of memory, link information lost\n");
E 17
					freemem = 0;
				}
			} else {
E 28
I 28
			lp = (struct linkbuf *) getmem(sizeof(*lp));
			if (lp != NULL) {
E 28
				lp->nextp = ihead;
				ihead = lp;
				lp->inum = stbuf.st_ino;
				lp->devnum = stbuf.st_dev;
				lp->count = stbuf.st_nlink - 1;
				strcpy(lp->pathname, longname);
			}
E 15
E 7
		}
D 15
	}
D 7

E 7
	blocks = (stbuf.st_size + (TBLOCK-1)) / TBLOCK;
	if (vflag) {
		fprintf(stderr, "a %s ", longname);
		fprintf(stderr, "%ld blocks\n", blocks);
	}
	sprintf(dblock.dbuf.chksum, "%6o", checksum());
D 7
	writetape( (char *) &dblock);
E 7
I 7
	writetape((char *)&dblock);
E 15
I 15
D 20
		blocks = (stbuf.st_size + (TBLOCK-1)) / TBLOCK;
E 20
I 20
D 22
		blocks = ((size = stbuf.st_size) + (TBLOCK-1)) / TBLOCK;
E 22
I 22
		blocks = (stbuf.st_size + (TBLOCK-1)) / TBLOCK;
E 22
E 20
D 28
		if (vflag) {
D 24
			fprintf(stderr, "a %s ", longname);
			fprintf(stderr, "%ld blocks\n", blocks);
E 24
I 24
			fprintf(vfile, "a %s ", longname);
			fprintf(vfile, "%ld blocks\n", blocks);
E 24
		}
E 28
I 28
		if (vflag)
			fprintf(vfile, "a %s %ld blocks\n", longname, blocks);
E 28
D 36
		sprintf(dblock.dbuf.chksum, "%6o", checksum());
E 36
I 36
		(void)sprintf(dblock.dbuf.chksum, "%6o", checksum());
E 36
D 22
		writetape((char *)&dblock);
E 22
I 22
		hint = writetape((char *)&dblock);
		maxread = max(stbuf.st_blksize, (nblock * TBLOCK));
D 24
#ifndef vax
E 24
D 33
		if ((bigbuf = malloc(maxread)) == 0) {
E 33
I 33
		if ((bigbuf = malloc((unsigned)maxread)) == 0) {
E 33
			maxread = TBLOCK;
			bigbuf = buf;
		}
D 24
#else
		/*
		 *  The following is for 4.2BSD and related systems to force
		 *  the buffer to be page aligned.  The kernel will avoid
		 *  bcopy()'s on disk IO this way by manipulating the page tables.
		 */
		{
			int pagesize = getpagesize();
E 24
E 22
E 15
E 7

D 15
	while ((i = read(infile, buf, TBLOCK)) > 0 && blocks > 0) {
		writetape(buf);
		blocks--;
E 15
I 15
D 20
		while ((i = read(infile, buf, TBLOCK)) > 0 && blocks > 0) {
			writetape(buf);
			blocks--;
E 20
I 20
D 22
		while (blocks > 0) {
			i = nblock - recno;
			if (blocks < i)
				i = blocks;
			if (read(infile, (char *)&tbuf[recno], i*TBLOCK) <= 0)
				break;
			if ((recno += i) >= nblock)
				flushtape();
			blocks -= i;
E 22
I 22
D 24
			if ((origbuf = malloc(maxread+pagesize)) == 0) {
				maxread = TBLOCK;
				bigbuf = buf;
			} else {
				bigbuf = (char *)(((int)origbuf+pagesize)&~(pagesize-1));
			}
E 22
E 20
		}
D 20
		close(infile);
		if (blocks != 0 || i != 0)
E 20
I 20
D 22
		if (blocks != 0 || fstat(infile, &stbuf) < 0 ||
		    size != stbuf.st_size)
E 22
I 22
#endif vax

E 24
		while ((i = read(infile, bigbuf, min((hint*TBLOCK), maxread))) > 0
		  && blocks > 0) {
		  	register int nblks;

			nblks = ((i-1)/TBLOCK)+1;
		  	if (nblks > blocks)
		  		nblks = blocks;
			hint = writetbuf(bigbuf, nblks);
			blocks -= nblks;
		}
		close(infile);
		if (bigbuf != buf)
D 24
#ifndef vax
E 24
			free(bigbuf);
D 24
#else
			free(origbuf);
#endif
E 24
D 31
		if (blocks != 0 || i != 0)
E 31
I 31
		if (i < 0) {
D 33
			fprintf("tar: Read error on ");
E 33
I 33
			fprintf(stderr, "tar: Read error on ");
E 33
			perror(longname);
		} else if (blocks != 0 || i != 0)
E 31
E 22
E 20
D 17
			fprintf(stderr, "%s: file changed size\n", longname);
E 17
I 17
			fprintf(stderr, "tar: %s: file changed size\n",
			    longname);
I 20
D 22
		close(infile);
E 22
E 20
E 17
		while (--blocks >=  0)
			putempty();
		break;

	default:
		fprintf(stderr, "tar: %s is not a file. Not dumped\n",
D 17
			longname);
E 17
I 17
		    longname);
E 17
		break;
E 15
	}
D 15
	close(infile);
	if (blocks != 0 || i != 0)
		fprintf(stderr, "%s: file changed size\n", longname);
D 7
	while (blocks-- >  0)
E 7
I 7
	while (--blocks >=  0)
E 7
		putempty();
E 15
}

D 7


E 7
doxtract(argv)
D 7
char	*argv[];
E 7
I 7
	char *argv[];
E 7
{
I 37
	extern int errno;
E 37
	long blocks, bytes;
D 20
	char buf[TBLOCK];
E 20
D 33
	char **cp;
	int ofile;
E 33
I 33
	int ofile, i;
E 33

	for (;;) {
D 33
		getdir();
		if (endtape())
			break;
D 7

E 7
		if (*argv == 0)
			goto gotit;
D 7

E 7
		for (cp = argv; *cp; cp++)
			if (prefix(*cp, dblock.dbuf.name))
				goto gotit;
		passtape();
		continue;

gotit:
E 33
I 33
		if ((i = wantit(argv)) == 0)
			continue;
		if (i == -1)
			break;		/* end of tape */
E 33
		if (checkw('x', dblock.dbuf.name) == 0) {
			passtape();
			continue;
		}
I 15
		if (Fflag) {
			char *s;

			if ((s = rindex(dblock.dbuf.name, '/')) == 0)
				s = dblock.dbuf.name;
			else
				s++;
			if (checkf(s, stbuf.st_mode, Fflag) == 0) {
				passtape();
				continue;
			}
		}
E 15
D 7

		if(checkdir(dblock.dbuf.name))
E 7
I 7
D 28
		if (checkdir(dblock.dbuf.name))
E 28
I 28
		if (checkdir(dblock.dbuf.name)) {	/* have a directory */
			if (mflag == 0)
				dodirtimes(&dblock);
E 28
E 7
			continue;
I 7
D 28
		if (dblock.dbuf.linkflag == '2') {
E 28
I 28
		}
		if (dblock.dbuf.linkflag == '2') {	/* symlink */
E 28
D 30
			unlink(dblock.dbuf.name);
E 30
I 30
			/*
			 * only unlink non directories or empty
			 * directories
			 */
			if (rmdir(dblock.dbuf.name) < 0) {
				if (errno == ENOTDIR)
					unlink(dblock.dbuf.name);
			}
E 30
			if (symlink(dblock.dbuf.linkname, dblock.dbuf.name)<0) {
D 17
				fprintf(stderr, "%s: symbolic link failed\n",
					dblock.dbuf.name);
E 17
I 17
D 31
				fprintf(stderr, "tar: %s: symbolic link failed\n",
E 31
I 31
				fprintf(stderr, "tar: %s: symbolic link failed: ",
E 31
				    dblock.dbuf.name);
I 31
				perror("");
E 31
E 17
				continue;
			}
			if (vflag)
D 24
				fprintf(stderr, "x %s symbolic link to %s\n",
E 24
I 24
				fprintf(vfile, "x %s symbolic link to %s\n",
E 24
D 17
				  dblock.dbuf.name, dblock.dbuf.linkname);
E 17
I 17
				    dblock.dbuf.name, dblock.dbuf.linkname);
I 25
#ifdef notdef
			/* ignore alien orders */
			chown(dblock.dbuf.name, stbuf.st_uid, stbuf.st_gid);
D 28
			if (mflag == 0) {
				struct timeval tv[2];

				tv[0].tv_sec = time(0);
				tv[0].tv_usec = 0;
				tv[1].tv_sec = stbuf.st_mtime;
				tv[1].tv_usec = 0;
				utimes(dblock.dbuf.name, tv);
			}
E 28
I 28
			if (mflag == 0)
				setimes(dblock.dbuf.name, stbuf.st_mtime);
E 28
			if (pflag)
				chmod(dblock.dbuf.name, stbuf.st_mode & 07777);
#endif
E 25
E 17
I 10
D 24
#ifdef notdef
			/* ignore alien orders */
E 10
D 20
			chown(dblock.dbuf.name, stbuf.st_uid, stbuf.st_gid);
E 20
I 20
D 22
			if (superuser)
				chown(dblock.dbuf.name, stbuf.st_uid, stbuf.st_gid);
E 22
I 22
			chown(dblock.dbuf.name, stbuf.st_uid, stbuf.st_gid);
E 22
E 20
			if (mflag == 0) {
D 16
				time_t timep[2];
E 16
I 16
				struct timeval tv[2];
E 16
E 7

I 7
D 16
				timep[0] = time(0);
				timep[1] = stbuf.st_mtime;
				utime(dblock.dbuf.name, timep);
E 16
I 16
				tv[0].tv_sec = time(0);
				tv[0].tv_usec = 0;
				tv[1].tv_sec = stbuf.st_mtime;
				tv[1].tv_usec = 0;
				utimes(dblock.dbuf.name, tv);
E 16
			}
			if (pflag)
				chmod(dblock.dbuf.name, stbuf.st_mode & 07777);
I 10
#endif
E 24
E 10
			continue;
		}
E 7
D 28
		if (dblock.dbuf.linkflag == '1') {
E 28
I 28
		if (dblock.dbuf.linkflag == '1') {	/* regular link */
E 28
D 30
			unlink(dblock.dbuf.name);
E 30
I 30
			/*
			 * only unlink non directories or empty
			 * directories
			 */
			if (rmdir(dblock.dbuf.name) < 0) {
				if (errno == ENOTDIR)
					unlink(dblock.dbuf.name);
			}
E 30
			if (link(dblock.dbuf.linkname, dblock.dbuf.name) < 0) {
D 7
				fprintf(stderr, "%s: cannot link\n", dblock.dbuf.name);
E 7
I 7
D 17
				fprintf(stderr, "%s: cannot link\n",
					dblock.dbuf.name);
E 17
I 17
D 31
				fprintf(stderr, "tar: %s: cannot link\n",
				    dblock.dbuf.name);
E 31
I 31
				fprintf(stderr, "tar: can't link %s to %s: ",
				    dblock.dbuf.name, dblock.dbuf.linkname);
				perror("");
E 31
E 17
E 7
				continue;
			}
			if (vflag)
D 4
				fprintf(stderr, "%s linked to %s\n", dblock.dbuf.name, dblock.dbuf.linkname);
E 4
I 4
D 24
				fprintf(stderr, "%s linked to %s\n",
E 24
I 24
D 25
				fprintf(vfile, "%s linked to %s\n",
E 25
I 25
D 28
				fprintf(vfile, "%s linked to %s",
E 28
I 28
				fprintf(vfile, "%s linked to %s\n",
E 28
E 25
E 24
D 17
					dblock.dbuf.name, dblock.dbuf.linkname);
E 17
I 17
				    dblock.dbuf.name, dblock.dbuf.linkname);
E 17
E 4
			continue;
		}
D 7
		if ((ofile = creat(dblock.dbuf.name, stbuf.st_mode & 07777)) < 0) {
			fprintf(stderr, "tar: %s - cannot create\n", dblock.dbuf.name);
E 7
I 7
		if ((ofile = creat(dblock.dbuf.name,stbuf.st_mode&0xfff)) < 0) {
D 31
			fprintf(stderr, "tar: %s - cannot create\n",
E 31
I 31
			fprintf(stderr, "tar: can't create %s: ",
E 31
D 17
				dblock.dbuf.name);
E 17
I 17
			    dblock.dbuf.name);
I 31
			perror("");
E 31
E 17
E 7
			passtape();
			continue;
		}
I 2
D 20
		chown(dblock.dbuf.name, stbuf.st_uid, stbuf.st_gid);
E 20
I 20
D 22
		if (superuser)
			chown(dblock.dbuf.name, stbuf.st_uid, stbuf.st_gid);
E 22
I 22
		chown(dblock.dbuf.name, stbuf.st_uid, stbuf.st_gid);
E 22
E 20
E 2
D 7

E 7
		blocks = ((bytes = stbuf.st_size) + TBLOCK-1)/TBLOCK;
		if (vflag)
D 4
			fprintf(stderr, "x %s, %ld bytes, %ld tape blocks\n", dblock.dbuf.name, bytes, blocks);
E 4
I 4
D 24
			fprintf(stderr, "x %s, %ld bytes, %ld tape blocks\n",
E 24
I 24
D 25
			fprintf(vfile, "x %s, %ld bytes, %ld tape blocks\n",
E 25
I 25
D 28
			fprintf(vfile, "x %s, %ld bytes, %ld tape blocks",
E 28
I 28
			fprintf(vfile, "x %s, %ld bytes, %ld tape blocks\n",
E 28
E 25
E 24
D 17
				dblock.dbuf.name, bytes, blocks);
E 17
I 17
			    dblock.dbuf.name, bytes, blocks);
E 17
E 4
D 7
		while (blocks-- > 0) {
E 7
I 7
D 20
		for (; blocks-- > 0; bytes -= TBLOCK) {
E 7
			readtape(buf);
			if (bytes > TBLOCK) {
				if (write(ofile, buf, TBLOCK) < 0) {
D 7
					fprintf(stderr, "tar: %s: HELP - extract write error\n", dblock.dbuf.name);
E 7
I 7
					fprintf(stderr,
					"tar: %s: HELP - extract write error\n",
D 17
					 dblock.dbuf.name);
E 17
I 17
					    dblock.dbuf.name);
E 17
E 7
					done(2);
				}
D 7
			} else
				if (write(ofile, buf, (int) bytes) < 0) {
					fprintf(stderr, "tar: %s: HELP - extract write error\n", dblock.dbuf.name);
					done(2);
				}
			bytes -= TBLOCK;
E 7
I 7
				continue;
E 20
I 20
D 22
		while (bytes > 0) {
			int b, r;

			readtape(NULL);
			b = (r = nblock - recno) * TBLOCK;
			if (bytes < b) {
				b = bytes;
				r = (b + TBLOCK-1)/TBLOCK;
E 20
			}
D 20
			if (write(ofile, buf, (int) bytes) < 0) {
E 20
I 20
			if (write(ofile, (char *)&tbuf[recno], b) != b) {
E 22
I 22
		for (; blocks > 0;) {
			register int nread;
			char	*bufp;
			register int nwant;
			
			nwant = NBLOCK*TBLOCK;
			if (nwant > (blocks*TBLOCK))
				nwant = (blocks*TBLOCK);
			nread = readtbuf(&bufp, nwant);
D 28
			if (bytes > nread) {
				if (write(ofile, bufp, nread) < 0) {
					fprintf(stderr,
					"tar: %s: HELP - extract write error\n",
					    dblock.dbuf.name);
					done(2);
				}
			} else if (write(ofile, bufp, (int) bytes) < 0) {
E 28
I 28
			if (write(ofile, bufp, (int)min(nread, bytes)) < 0) {
E 28
E 22
E 20
				fprintf(stderr,
D 17
					"tar: %s: HELP - extract write error\n",
					dblock.dbuf.name);
E 17
I 17
D 31
				    "tar: %s: HELP - extract write error\n",
E 31
I 31
D 34
				    "tar: %s: HELP - extract write error",
E 34
I 34
				    "tar: %s: HELP - extract write error: ",
E 34
E 31
				    dblock.dbuf.name);
I 31
				perror("");
E 31
E 17
				done(2);
			}
I 20
D 22
			bytes -= b;
			recno += r;
E 22
I 22
			bytes -= nread;
			blocks -= (((nread-1)/TBLOCK)+1);
I 25
D 28
			fprintf(stderr,"\n");
E 28
E 25
E 22
E 20
E 7
		}
		close(ofile);
D 28
		if (mflag == 0) {
D 16
			time_t timep[2];
E 16
I 16
			struct timeval tv[2];
E 16

D 16
			timep[0] = time(NULL);
			timep[1] = stbuf.st_mtime;
			utime(dblock.dbuf.name, timep);
E 16
I 16
			tv[0].tv_sec = time(0);
			tv[0].tv_usec = 0;
			tv[1].tv_sec = stbuf.st_mtime;
			tv[1].tv_usec = 0;
			utimes(dblock.dbuf.name, tv);
E 16
		}
E 28
I 28
		if (mflag == 0)
			setimes(dblock.dbuf.name, stbuf.st_mtime);
E 28
D 2
		if(pflag) {
		    chown(dblock.dbuf.name, stbuf.st_uid, stbuf.st_gid);
E 2
I 2
		if (pflag)
E 2
D 7
		    chmod(dblock.dbuf.name, stbuf.st_mode & 07777);
E 7
I 7
			chmod(dblock.dbuf.name, stbuf.st_mode & 07777);
E 7
D 2
		}
E 2
	}
I 28
	if (mflag == 0) {
		dblock.dbuf.name[0] = '\0';	/* process the whole stack */
		dodirtimes(&dblock);
	}
E 28
}

D 33
dotable()
E 33
I 33
dotable(argv)
	char *argv[];
E 33
{
I 33
	register int i;

E 33
	for (;;) {
D 33
		getdir();
		if (endtape())
			break;
E 33
I 33
		if ((i = wantit(argv)) == 0)
			continue;
		if (i == -1)
			break;		/* end of tape */
E 33
		if (vflag)
			longt(&stbuf);
		printf("%s", dblock.dbuf.name);
		if (dblock.dbuf.linkflag == '1')
			printf(" linked to %s", dblock.dbuf.linkname);
I 7
		if (dblock.dbuf.linkflag == '2')
			printf(" symbolic link to %s", dblock.dbuf.linkname);
E 7
		printf("\n");
		passtape();
	}
}

putempty()
{
	char buf[TBLOCK];
D 17
	char *cp;
E 17

D 17
	for (cp = buf; cp < &buf[TBLOCK]; )
		*cp++ = '\0';
E 17
I 17
	bzero(buf, sizeof (buf));
E 17
D 33
	writetape(buf);
E 33
I 33
	(void) writetape(buf);
E 33
}

longt(st)
D 7
register struct stat *st;
E 7
I 7
	register struct stat *st;
E 7
{
	register char *cp;
	char *ctime();

	pmode(st);
	printf("%3d/%1d", st->st_uid, st->st_gid);
D 33
	printf("%7D", st->st_size);
E 33
I 33
	printf("%7ld", st->st_size);
E 33
	cp = ctime(&st->st_mtime);
	printf(" %-12.12s %-4.4s ", cp+4, cp+20);
}

#define	SUID	04000
#define	SGID	02000
#define	ROWN	0400
#define	WOWN	0200
#define	XOWN	0100
#define	RGRP	040
#define	WGRP	020
#define	XGRP	010
#define	ROTH	04
#define	WOTH	02
#define	XOTH	01
#define	STXT	01000
int	m1[] = { 1, ROWN, 'r', '-' };
int	m2[] = { 1, WOWN, 'w', '-' };
int	m3[] = { 2, SUID, 's', XOWN, 'x', '-' };
int	m4[] = { 1, RGRP, 'r', '-' };
int	m5[] = { 1, WGRP, 'w', '-' };
int	m6[] = { 2, SGID, 's', XGRP, 'x', '-' };
int	m7[] = { 1, ROTH, 'r', '-' };
int	m8[] = { 1, WOTH, 'w', '-' };
int	m9[] = { 2, STXT, 't', XOTH, 'x', '-' };

int	*m[] = { m1, m2, m3, m4, m5, m6, m7, m8, m9};

pmode(st)
D 7
register struct stat *st;
E 7
I 7
	register struct stat *st;
E 7
{
	register int **mp;

	for (mp = &m[0]; mp < &m[9];)
D 31
		select(*mp++, st);
E 31
I 31
		selectbits(*mp++, st);
E 31
}

D 31
select(pairp, st)
E 31
I 31
selectbits(pairp, st)
E 31
D 7
int *pairp;
struct stat *st;
E 7
I 7
	int *pairp;
	struct stat *st;
E 7
{
	register int n, *ap;

	ap = pairp;
	n = *ap++;
	while (--n>=0 && (st->st_mode&*ap++)==0)
		ap++;
D 33
	printf("%c", *ap);
E 33
I 33
	putchar(*ap);
E 33
}

I 28
/*
D 32
 * Make all directories needed by `name'.  If `name' is a
 * directory itself on the tar tape (indicated by a trailing '/'),
E 32
I 32
 * Make all directories needed by `name'.  If `name' is itself
 * a directory on the tar tape (indicated by a trailing '/'),
E 32
 * return 1; else 0.
 */
E 28
checkdir(name)
D 7
register char *name;
E 7
I 7
	register char *name;
E 7
{
	register char *cp;
D 7
	int i;
E 7
I 7

I 15
	/*
D 28
	 * Quick check for existance of directory.
E 28
I 28
	 * Quick check for existence of directory.
E 28
	 */
	if ((cp = rindex(name, '/')) == 0)
		return (0);
	*cp = '\0';
D 28
	if (access(name, 0) >= 0) {
E 28
I 28
	if (access(name, 0) == 0) {	/* already exists */
E 28
		*cp = '/';
D 28
		return (cp[1] == '\0');
E 28
I 28
		return (cp[1] == '\0');	/* return (lastchar == '/') */
E 28
	}
	*cp = '/';

	/*
	 * No luck, try to make all directories in path.
	 */
E 15
E 7
	for (cp = name; *cp; cp++) {
D 7
		if (*cp == '/') {
			*cp = '\0';
			if (access(name, 01) < 0) {
				register int pid, rp;
E 7
I 7
		if (*cp != '/')
			continue;
		*cp = '\0';
D 15
		if (access(name, 1) < 0) {
E 15
I 15
		if (access(name, 0) < 0) {
E 15
D 13
			register int pid, rp;
			int i;
E 7

D 7
				if ((pid = fork()) == 0) {
					execl("/bin/mkdir", "mkdir", name, 0);
					execl("/usr/bin/mkdir", "mkdir", name, 0);
					fprintf(stderr, "tar: cannot find mkdir!\n");
					done(0);
				}
				while ((rp = wait(&i)) >= 0 && rp != pid)
					;
D 2
				if(pflag) {
				    chown(name, stbuf.st_uid, stbuf.st_gid);
				    chmod(dblock.dbuf.name, stbuf.st_mode & 0777);
				}
E 2
I 2
				chown(name, stbuf.st_uid, stbuf.st_gid);
				if (pflag)
					chmod(dblock.dbuf.name,
					    stbuf.st_mode & 0777);
E 7
I 7
			if ((pid = fork()) == 0) {
				execl("/bin/mkdir", "mkdir", name, 0);
				execl("/usr/bin/mkdir", "mkdir", name, 0);
				fprintf(stderr, "tar: cannot find mkdir!\n");
E 13
I 13
			if (mkdir(name, 0777) < 0) {
				perror(name);
E 13
D 15
				done(0);
E 15
I 15
				*cp = '/';
				return (0);
E 15
E 7
E 2
			}
D 7
			*cp = '/';
E 7
I 7
D 13
			while ((rp = wait(&i)) >= 0 && rp != pid)
				;
E 13
D 20
			chown(name, stbuf.st_uid, stbuf.st_gid);
E 20
I 20
D 22
			if (superuser)
				chown(name, stbuf.st_uid, stbuf.st_gid);
E 22
I 22
			chown(name, stbuf.st_uid, stbuf.st_gid);
E 22
E 20
D 18
			if (pflag)
E 18
I 18
D 32
			if (pflag && cp[1] == '\0')
E 18
D 13
				chmod(dblock.dbuf.name, stbuf.st_mode & 0777);
E 13
I 13
				chmod(name, stbuf.st_mode & 0777);
E 32
I 32
			if (pflag && cp[1] == '\0')	/* dir on the tape */
				chmod(name, stbuf.st_mode & 07777);
E 32
E 13
E 7
		}
I 7
		*cp = '/';
E 7
	}
D 7
	return(cp[-1]=='/');
E 7
I 7
	return (cp[-1]=='/');
E 7
}

onintr()
{
D 33
	signal(SIGINT, SIG_IGN);
E 33
I 33
	(void) signal(SIGINT, SIG_IGN);
E 33
	term++;
}

onquit()
{
D 33
	signal(SIGQUIT, SIG_IGN);
E 33
I 33
	(void) signal(SIGQUIT, SIG_IGN);
E 33
	term++;
}

onhup()
{
D 33
	signal(SIGHUP, SIG_IGN);
E 33
I 33
	(void) signal(SIGHUP, SIG_IGN);
E 33
	term++;
}

I 28
#ifdef notdef
E 28
onterm()
{
D 33
	signal(SIGTERM, SIG_IGN);
E 33
I 33
	(void) signal(SIGTERM, SIG_IGN);
E 33
	term++;
}
I 28
#endif
E 28

tomodes(sp)
register struct stat *sp;
{
	register char *cp;

	for (cp = dblock.dummy; cp < &dblock.dummy[TBLOCK]; cp++)
		*cp = '\0';
D 36
	sprintf(dblock.dbuf.mode, "%6o ", sp->st_mode & 07777);
	sprintf(dblock.dbuf.uid, "%6o ", sp->st_uid);
	sprintf(dblock.dbuf.gid, "%6o ", sp->st_gid);
	sprintf(dblock.dbuf.size, "%11lo ", sp->st_size);
	sprintf(dblock.dbuf.mtime, "%11lo ", sp->st_mtime);
E 36
I 36
	(void)sprintf(dblock.dbuf.mode, "%6o ", sp->st_mode & 07777);
	(void)sprintf(dblock.dbuf.uid, "%6o ", sp->st_uid);
	(void)sprintf(dblock.dbuf.gid, "%6o ", sp->st_gid);
	(void)sprintf(dblock.dbuf.size, "%11lo ", sp->st_size);
	(void)sprintf(dblock.dbuf.mtime, "%11lo ", sp->st_mtime);
E 36
}

checksum()
{
	register i;
	register char *cp;

D 7
	for (cp = dblock.dbuf.chksum; cp < &dblock.dbuf.chksum[sizeof(dblock.dbuf.chksum)]; cp++)
E 7
I 7
	for (cp = dblock.dbuf.chksum;
	     cp < &dblock.dbuf.chksum[sizeof(dblock.dbuf.chksum)]; cp++)
E 7
		*cp = ' ';
	i = 0;
	for (cp = dblock.dummy; cp < &dblock.dummy[TBLOCK]; cp++)
		i += *cp;
D 7
	return(i);
E 7
I 7
	return (i);
E 7
}

checkw(c, name)
D 7
char *name;
E 7
I 7
	char *name;
E 7
{
D 7
	if (wflag) {
		printf("%c ", c);
		if (vflag)
			longt(&stbuf);
		printf("%s: ", name);
		if (response() == 'y'){
			return(1);
		}
		return(0);
	}
	return(1);
E 7
I 7
	if (!wflag)
		return (1);
	printf("%c ", c);
	if (vflag)
		longt(&stbuf);
	printf("%s: ", name);
	return (response() == 'y');
E 7
}

response()
{
	char c;

	c = getchar();
	if (c != '\n')
D 7
		while (getchar() != '\n');
	else c = 'n';
	return(c);
E 7
I 7
		while (getchar() != '\n')
			;
	else
		c = 'n';
	return (c);
I 15
}

checkf(name, mode, howmuch)
	char *name;
	int mode, howmuch;
{
	int l;

D 24
	if ((mode & S_IFMT) == S_IFDIR)
		return (strcmp(name, "SCCS") != 0);
E 24
I 24
	if ((mode & S_IFMT) == S_IFDIR){
		if ((strcmp(name, "SCCS")==0) || (strcmp(name, "RCS")==0)) 
			return(0); 
		return(1);
	}
E 24
	if ((l = strlen(name)) < 3)
		return (1);
	if (howmuch > 1 && name[l-2] == '.' && name[l-1] == 'o')
		return (0);
	if (strcmp(name, "core") == 0 ||
	    strcmp(name, "errs") == 0 ||
	    (howmuch > 1 && strcmp(name, "a.out") == 0))
		return (0);
	/* SHOULD CHECK IF IT IS EXECUTABLE */
	return (1);
E 15
E 7
}

I 28
/* Is the current file a new file, or the newest one of the same name? */
E 28
checkupdate(arg)
D 7
char	*arg;
E 7
I 7
	char *arg;
E 7
{
	char name[100];
D 7
	long	mtime;
E 7
I 7
	long mtime;
E 7
	daddr_t seekp;
	daddr_t	lookup();

	rewind(tfile);
	for (;;) {
		if ((seekp = lookup(arg)) < 0)
D 7
			return(1);
E 7
I 7
			return (1);
E 7
		fseek(tfile, seekp, 0);
		fscanf(tfile, "%s %lo", name, &mtime);
D 7
		if (stbuf.st_mtime > mtime)
			return(1);
		else
			return(0);
E 7
I 7
		return (stbuf.st_mtime > mtime);
E 7
	}
}

done(n)
{
D 20
	unlink(tname);
E 20
I 20
D 22
	if (tfile != NULL)
		unlink(tname);
E 22
I 22
	unlink(tname);
E 22
E 20
	exit(n);
}

I 33
/* 
 * Do we want the next entry on the tape, i.e. is it selected?  If
 * not, skip over the entire entry.  Return -1 if reached end of tape.
 */
wantit(argv)
	char *argv[];
{
	register char **cp;

	getdir();
	if (endtape())
		return (-1);
	if (*argv == 0)
		return (1);
	for (cp = argv; *cp; cp++)
		if (prefix(*cp, dblock.dbuf.name))
			return (1);
	passtape();
	return (0);
}

E 33
I 28
/*
 * Does s2 begin with the string s1, on a directory boundary?
 */
E 28
prefix(s1, s2)
D 7
register char *s1, *s2;
E 7
I 7
	register char *s1, *s2;
E 7
{
	while (*s1)
		if (*s1++ != *s2++)
D 7
			return(0);
E 7
I 7
			return (0);
E 7
	if (*s2)
D 7
		return(*s2 == '/');
	return(1);
E 7
I 7
		return (*s2 == '/');
	return (1);
E 7
D 13
}

getwdir(s)
D 7
char *s;
E 7
I 7
	char *s;
E 7
{
D 7
	int i;
	int	pipdes[2];
E 7
I 7
	int i, pipdes[2];
E 7

	pipe(pipdes);
	if ((i = fork()) == 0) {
		close(1);
		dup(pipdes[1]);
		execl("/bin/pwd", "pwd", 0);
		execl("/usr/bin/pwd", "pwd", 0);
		fprintf(stderr, "pwd failed!\n");
		printf("/\n");
		exit(1);
	}
	while (wait((int *)NULL) != -1)
D 12
			;
E 12
I 12
			;
	read(pipdes[0], s, 50);
E 12
	read(pipdes[0], s, 50);
D 7
	while(*s != '\n')
E 7
I 7
	while (*s != '\n')
E 7
		s++;
	*s = '\0';
	close(pipdes[0]);
	close(pipdes[1]);
E 13
}

#define	N	200
int	njab;
I 7

E 7
daddr_t
lookup(s)
D 7
char *s;
E 7
I 7
	char *s;
E 7
{
	register i;
	daddr_t a;

	for(i=0; s[i]; i++)
D 7
		if(s[i] == ' ')
E 7
I 7
		if (s[i] == ' ')
E 7
			break;
	a = bsrch(s, i, low, high);
D 7
	return(a);
E 7
I 7
	return (a);
E 7
}

daddr_t
bsrch(s, n, l, h)
D 7
daddr_t l, h;
char *s;
E 7
I 7
	daddr_t l, h;
	char *s;
E 7
{
	register i, j;
	char b[N];
	daddr_t m, m1;

	njab = 0;

loop:
D 7
	if(l >= h)
		return(-1L);
E 7
I 7
	if (l >= h)
D 28
		return (-1L);
E 28
I 28
		return ((daddr_t) -1);
E 28
E 7
	m = l + (h-l)/2 - N/2;
D 7
	if(m < l)
E 7
I 7
	if (m < l)
E 7
		m = l;
	fseek(tfile, m, 0);
	fread(b, 1, N, tfile);
	njab++;
	for(i=0; i<N; i++) {
D 7
		if(b[i] == '\n')
E 7
I 7
		if (b[i] == '\n')
E 7
			break;
		m++;
	}
D 7
	if(m >= h)
		return(-1L);
E 7
I 7
	if (m >= h)
D 28
		return (-1L);
E 28
I 28
		return ((daddr_t) -1);
E 28
E 7
	m1 = m;
	j = i;
	for(i++; i<N; i++) {
		m1++;
D 7
		if(b[i] == '\n')
E 7
I 7
		if (b[i] == '\n')
E 7
			break;
	}
	i = cmp(b+j, s, n);
D 7
	if(i < 0) {
E 7
I 7
	if (i < 0) {
E 7
		h = m;
		goto loop;
	}
D 7
	if(i > 0) {
E 7
I 7
	if (i > 0) {
E 7
		l = m1;
		goto loop;
	}
D 7
	return(m);
E 7
I 7
	return (m);
E 7
}

cmp(b, s, n)
D 7
char *b, *s;
E 7
I 7
	char *b, *s;
E 7
{
	register i;

D 7
	if(b[0] != '\n')
E 7
I 7
	if (b[0] != '\n')
E 7
D 20
		exit(2);
E 20
I 20
D 22
		done(2);
E 22
I 22
		exit(2);
E 22
E 20
	for(i=0; i<n; i++) {
D 7
		if(b[i+1] > s[i])
			return(-1);
		if(b[i+1] < s[i])
			return(1);
E 7
I 7
		if (b[i+1] > s[i])
			return (-1);
		if (b[i+1] < s[i])
			return (1);
E 7
	}
D 7
	return(b[i+1] == ' '? 0 : -1);
E 7
I 7
	return (b[i+1] == ' '? 0 : -1);
E 7
}

D 22
readtape(buffer)
E 22
I 22
D 28
readtape (buffer)
E 28
I 28
readtape(buffer)
E 28
E 22
D 7
char *buffer;
E 7
I 7
	char *buffer;
E 7
{
I 22
	char *bufp;
D 28
	int nread;
E 28

I 24
D 28
	if (first==0) getbuf();
E 24
	readtbuf (&bufp, TBLOCK);
E 28
I 28
	if (first == 0)
		getbuf();
D 33
	readtbuf(&bufp, TBLOCK);
E 33
I 33
	(void) readtbuf(&bufp, TBLOCK);
E 33
E 28
	bcopy(bufp, buffer, TBLOCK);
	return(TBLOCK);
}

readtbuf(bufpp, size)
	char **bufpp;
	int size;
{
E 22
D 4
	int i, j;
E 4
I 4
	register int i;
E 4

	if (recno >= nblock || first == 0) {
D 4
		if (first == 0 && nblock == 0)
			j =  fflag ? NBLOCK : 1; /* orignally, NBLOCK;  */
		else
			j = nblock;
		if ((i = read(mt, tbuf, TBLOCK*j)) < 0) {
E 4
I 4
D 11
		if ((i = read(mt, tbuf, TBLOCK*nblock)) < 0) {
E 11
I 11
D 31
		if ((i = bread(mt, tbuf, TBLOCK*nblock)) < 0) {
E 11
E 4
D 17
			fprintf(stderr, "Tar: tape read error\n");
E 17
I 17
			fprintf(stderr, "tar: tape read error\n");
E 17
			done(3);
		}
E 31
I 31
D 33
		if ((i = bread(mt, tbuf, TBLOCK*nblock)) < 0)
E 33
I 33
		if ((i = bread(mt, (char *)tbuf, TBLOCK*nblock)) < 0)
E 33
			mterr("read", i, 3);
E 31
		if (first == 0) {
			if ((i % TBLOCK) != 0) {
D 17
				fprintf(stderr, "Tar: tape blocksize error\n");
E 17
I 17
				fprintf(stderr, "tar: tape blocksize error\n");
E 17
				done(3);
			}
			i /= TBLOCK;
D 4
			if (rflag && i != 1) {
				fprintf(stderr, "Tar: Cannot update blocked tapes (yet)\n");
				done(4);
			}
			if (i != nblock && (i != 1 || nblock == 0)) {
E 4
I 4
			if (i != nblock) {
E 4
D 17
				fprintf(stderr, "Tar: blocksize = %d\n", i);
E 17
I 17
				fprintf(stderr, "tar: blocksize = %d\n", i);
E 17
				nblock = i;
			}
I 25
			first = 1;
E 25
		}
		recno = 0;
	}
D 25
	first = 1;
E 25
D 17
	copy(buffer, &tbuf[recno++]);
E 17
I 17
D 20
	bcopy((char *)&tbuf[recno++], buffer, TBLOCK);
E 20
I 20
D 22
	if (buffer != NULL)
		bcopy((char *)&tbuf[recno++], buffer, TBLOCK);
E 20
E 17
D 7
	return(TBLOCK);
E 7
I 7
	return (TBLOCK);
E 22
I 22
	if (size > ((nblock-recno)*TBLOCK))
		size = (nblock-recno)*TBLOCK;
	*bufpp = (char *)&tbuf[recno];
	recno += (size/TBLOCK);
	return (size);
E 22
E 7
}

D 22
writetape(buffer)
D 7
char *buffer;
E 7
I 7
	char *buffer;
E 22
I 22
writetbuf(buffer, n)
	register char *buffer;
	register int n;
E 22
E 7
{
I 31
	int i;
E 31
I 24
D 25
	if (first==0) getbuf();
E 24
	first = 1;
E 25
I 25
D 28
	int	i;
	if (first==0) {
E 28
I 28

	if (first == 0) {
E 28
		getbuf();
		first = 1;
	}
E 25
D 4
	if (nblock == 0)
		nblock = 1;
E 4
	if (recno >= nblock) {
D 20
		if (write(mt, tbuf, TBLOCK*nblock) < 0) {
E 20
I 20
D 22
		if (bwrite(mt, tbuf, TBLOCK*nblock) < 0) {
E 22
I 22
D 25
		if (write(mt, tbuf, TBLOCK*nblock) < 0) {
E 22
E 20
D 17
			fprintf(stderr, "Tar: tape write error\n");
E 17
I 17
			fprintf(stderr, "tar: tape write error\n");
E 25
I 25
D 28
		if ( write(mt, tbuf, TBLOCK*nblock) < 0) {
			perror("tar");
E 28
I 28
D 31
		if (write(mt, tbuf, TBLOCK*nblock) < 0) {
			fprintf(stderr,"tar: tape write error\n");
E 28
E 25
E 17
			done(2);
		}
E 31
I 31
D 33
		i = write(mt, tbuf, TBLOCK*nblock);
E 33
I 33
		i = write(mt, (char *)tbuf, TBLOCK*nblock);
E 33
		if (i != TBLOCK*nblock)
			mterr("write", i, 2);
E 31
		recno = 0;
	}
D 17
	copy(&tbuf[recno++], buffer);
E 17
I 17
D 22
	bcopy(buffer, (char *)&tbuf[recno++], TBLOCK);
E 17
	if (recno >= nblock) {
D 20
		if (write(mt, tbuf, TBLOCK*nblock) < 0) {
E 20
I 20
		if (bwrite(mt, tbuf, TBLOCK*nblock) < 0) {
E 22
I 22

	/*
	 *  Special case:  We have an empty tape buffer, and the
	 *  users data size is >= the tape block size:  Avoid
	 *  the bcopy and dma direct to tape.  BIG WIN.  Add the
	 *  residual to the tape buffer.
	 */
	while (recno == 0 && n >= nblock) {
D 31
		if (write(mt, buffer, TBLOCK*nblock) < 0) {
E 22
E 20
D 17
			fprintf(stderr, "Tar: tape write error\n");
E 17
I 17
D 25
			fprintf(stderr, "tar: tape write error\n");
E 25
I 25
D 28
			perror("tar");
E 28
I 28
			fprintf(stderr,"tar: tape write error\n");
E 28
E 25
E 17
			done(2);
		}
E 31
I 31
		i = write(mt, buffer, TBLOCK*nblock);
		if (i != TBLOCK*nblock)
			mterr("write", i, 2);
E 31
D 22
		recno = 0;
E 22
I 22
		n -= nblock;
		buffer += (nblock * TBLOCK);
E 22
	}
D 7
	return(TBLOCK);
E 7
I 7
D 22
	return (TBLOCK);
E 22
I 22
		
	while (n-- > 0) {
		bcopy(buffer, (char *)&tbuf[recno++], TBLOCK);
		buffer += TBLOCK;
		if (recno >= nblock) {
D 31
			if (write(mt, tbuf, TBLOCK*nblock) < 0) {
D 25
				fprintf(stderr, "tar: tape write error\n");
				done(2);
E 25
I 25
					fprintf(stderr,"tar: tape write error\n");
					done(2);
E 25
			}
E 31
I 31
D 33
			i = write(mt, tbuf, TBLOCK*nblock);
E 33
I 33
			i = write(mt, (char *)tbuf, TBLOCK*nblock);
E 33
			if (i != TBLOCK*nblock)
				mterr("write", i, 2);
E 31
			recno = 0;
		}
	}

	/* Tell the user how much to write to get in sync */
	return (nblock - recno);
E 22
E 7
}

backtape()
{
I 31
	static int mtdev = 1;
E 31
D 4
	lseek(mt, (long) -TBLOCK, 1);
	if (recno >= nblock) {
		recno = nblock - 1;
		if (read(mt, tbuf, TBLOCK*nblock) < 0) {
			fprintf(stderr, "Tar: tape read error after seek\n");
E 4
I 4
D 25
	static int mtdev = 1;
E 25
	static struct mtop mtop = {MTBSR, 1};
D 28
	struct mtget mtget;
E 28
D 31

E 31
I 31
	struct mtget mtget;
	
	if (mtdev == 1)
D 33
		mtdev = ioctl(mt, MTIOCGET, &mtget);
E 33
I 33
		mtdev = ioctl(mt, MTIOCGET, (char *)&mtget);
E 33
E 31
D 25
	if (mtdev == 1)
		mtdev = ioctl(mt, MTIOCGET, &mtget);
E 25
	if (mtdev == 0) {
D 33
		if (ioctl(mt, MTIOCTOP, &mtop) < 0) {
E 33
I 33
		if (ioctl(mt, MTIOCTOP, (char *)&mtop) < 0) {
E 33
D 17
			fprintf(stderr, "Tar: tape backspace error\n");
E 17
I 17
D 31
			fprintf(stderr, "tar: tape backspace error\n");
E 31
I 31
			fprintf(stderr, "tar: tape backspace error: ");
			perror("");
E 31
E 17
E 4
			done(4);
		}
D 4
		lseek(mt, (long) -TBLOCK, 1);
	}
E 4
I 4
	} else
D 28
		lseek(mt, (long) -TBLOCK*nblock, 1);
E 28
I 28
		lseek(mt, (daddr_t) -TBLOCK*nblock, 1);
E 28
	recno--;
E 4
}

flushtape()
{
D 20
	write(mt, tbuf, TBLOCK*nblock);
E 20
I 20
D 22
	if (bwrite(mt, tbuf, TBLOCK*nblock) < 0) {
		fprintf(stderr, "tar: tape write error\n");
		done(2);
	}
	recno = 0;
E 22
I 22
D 31
	write(mt, tbuf, TBLOCK*nblock);
E 31
I 31
	int i;

D 33
	i = write(mt, tbuf, TBLOCK*nblock);
E 33
I 33
	i = write(mt, (char *)tbuf, TBLOCK*nblock);
E 33
	if (i != TBLOCK*nblock)
		mterr("write", i, 2);
E 31
E 22
E 20
D 17
}

copy(to, from)
D 7
register char *to, *from;
E 7
I 7
	register char *to, *from;
E 7
{
	register i;

	i = TBLOCK;
	do {
		*to++ = *from++;
	} while (--i);
E 17
I 11
}

I 31
mterr(operation, i, exitcode)
	char *operation;
	int i;
{
	fprintf(stderr, "tar: tape %s error: ", operation);
	if (i < 0)
		perror("");
	else
		fprintf(stderr, "unexpected EOF\n");
	done(exitcode);
}

E 31
bread(fd, buf, size)
	int fd;
	char *buf;
	int size;
{
	int count;
I 25
D 28
	int i;
E 28
E 25
	static int lastread = 0;
I 20
D 22
	int i;
	int tsize = size;
E 22
E 20

D 20
	if (!Bflag)
		return (read(fd, buf, size));
E 20
I 20
D 22
	if (!Bflag) {
		if (Mflag)
			return (read(fd, buf, size));
		while (size) {
			i = read(fd, buf, size);
			if (i <= 0) {
				/*
				 * Error on read, probably an EOF,
				 * ask the user about it.
				 */
				fd = chgreel(0, fd);
				if (fd == -1)
					return (i);
			} else {
				size -= i;
				buf += i;
			}
		}
		return (tsize);
	}

E 22
I 22
D 25
	if (!Bflag)
		return (read(fd, buf, size));
E 25
I 25
D 28
	if (!Bflag) {
			return (read(fd, buf, size)); 
	}
E 28
I 28
	if (!Bflag)
		return (read(fd, buf, size)); 
E 28

D 28

E 28
E 25
E 22
E 20
	for (count = 0; count < size; count += lastread) {
D 29
		if (lastread < 0) {
E 29
I 29
		lastread = read(fd, buf, size - count);
		if (lastread <= 0) {
E 29
			if (count > 0)
				return (count);
			return (lastread);
		}
D 29
		lastread = read(fd, buf, size - count);
E 29
		buf += lastread;
	}
	return (count);
I 14
}

char *
getcwd(buf)
	char *buf;
{
D 25

E 25
	if (getwd(buf) == NULL) {
		fprintf(stderr, "tar: %s\n", buf);
D 20
		exit(1);
E 20
I 20
D 22
		done(1);
E 22
I 22
		exit(1);
E 22
E 20
	}
	return (buf);
I 24
}

getbuf()
{
D 25
#ifdef nodef
E 25
I 25
D 28
	struct mtget mtget;
E 28
	
E 25
D 28
	if ( mtdev == 1) {
E 28
I 28
D 31
	if (mtdev == 1) {
E 31
I 31
	if (nblock == 0) {
E 31
E 28
		fstat(mt, &stbuf);
		if ((stbuf.st_mode & S_IFMT) == S_IFCHR)
D 31
			mtdev = 0;
		else
			mtdev = -1;
	}
D 25
	if (first==0 && nblock==0) {
E 25
I 25
D 28
	if (nblock==0) {
E 28
I 28
	if (nblock == 0) {
E 28
E 25
		if (mtdev == 0)
			nblock = FILEBLOCK;
E 31
I 31
			nblock = NBLOCK;
E 31
		else {
D 31
			fstat(mt, &stbuf);
			nblock = stbuf.st_blocks / TBLOCK;
E 31
I 31
			nblock = stbuf.st_blksize / TBLOCK;
			if (nblock == 0)
				nblock = NBLOCK;
E 31
		}
	}
D 25
	if (nblock ==0) nblock = FILEBLOCK;
#endif nodef
E 25
I 25
D 28
	if (nblock == 0) nblock = FILEBLOCK;
E 28
I 28
D 31
	if (nblock == 0)
		nblock = FILEBLOCK;
E 31
E 28
E 25
D 33
	tbuf = (union hblock *)malloc(nblock*TBLOCK);
E 33
I 33
	tbuf = (union hblock *)malloc((unsigned)nblock*TBLOCK);
E 33
	if (tbuf == NULL) {
		fprintf(stderr, "tar: blocksize %d too big, can't get memory\n",
		    nblock);
		done(1);
	}
I 25
}

I 28
/*
D 32
 * We are really keeping a directory stack, but since all the
 * elements of it share a common prefix, we can make do with one
 * string.  We keep only the current directory path, with an associated
 * array of mtime's, one for each '/' in the path.  A negative mtime
 * means no mtime.  The mtime's are offset by one (first index 1, not
 * 0) because calling this with the null string causes mtime[0] to be set.
E 32
I 32
 * Save this directory and its mtime on the stack, popping and setting
 * the mtimes of any stacked dirs which aren't parents of this one.
 * A null directory causes the entire stack to be unwound and set.
E 32
 *
I 32
 * Since all the elements of the directory "stack" share a common
 * prefix, we can make do with one string.  We keep only the current
 * directory path, with an associated array of mtime's, one for each
 * '/' in the path.  A negative mtime means no mtime.  The mtime's are
 * offset by one (first index 1, not 0) because calling this with a null
 * directory causes mtime[0] to be set.
 * 
E 32
 * This stack algorithm is not guaranteed to work for tapes created
 * with the 'r' option, but the vast majority of tapes with
 * directories are not.  This avoids saving every directory record on
 * the tape and setting all the times at the end.
 */
char dirstack[NAMSIZ];
#define NTIM (NAMSIZ/2+1)		/* a/b/c/d/... */
time_t mtime[NTIM];
E 28

D 28
chgreel(x, fl)
	int x, fl;
E 28
I 28
dodirtimes(hp)
	union hblock *hp;
E 28
{
D 28
	register int f;
	char str[BUFSIZ];
	char *pstr;
	FILE *devtty;
	struct stat statb;
E 28
I 28
	register char *p = dirstack;
	register char *q = hp->dbuf.name;
	register int ndir = 0;
	char *savp;
	int savndir;
E 28

D 28
	perror("tar");
	fprintf(stderr, "Can't %s\n", x ? "write output": "read input");
	fstat(fl, &statb);
	if ((statb.st_mode & S_IFMT) != S_IFCHR)
		done(2);
E 28
I 28
	/* Find common prefix */
D 34
	while (*p == *q) {
E 34
I 34
	while (*p == *q && *p) {
E 34
		if (*p++ == '/')
			++ndir;
		q++;
	}
E 28

D 28
	close(fl);
	devtty = fopen("/dev/tty", "r");
	for (;;) {
		fprintf(stderr, "tar: If you want to go on, type \"yes\" or a new\npathname of a device/file name when you are ready\n");
		if (fgets(str, sizeof (str), devtty) == NULL)
			break;
		str[strlen(str) - 1] = '\0';
E 28
I 28
	savp = p;
	savndir = ndir;
	while (*p) {
		/*
		 * Not a child: unwind the stack, setting the times.
		 * The order we do this doesn't matter, so we go "forward."
		 */
		if (*p++ == '/')
			if (mtime[++ndir] >= 0) {
				*--p = '\0';	/* zap the slash */
				setimes(dirstack, mtime[ndir]);
				*p++ = '/';
			}
	}
	p = savp;
	ndir = savndir;
E 28

D 28
		switch (*str) {
		case '\0':
		case 'N':
		case 'n':
			goto done;
E 28
I 28
	/* Push this one on the "stack" */
	while (*p = *q++)	/* append the rest of the new dir */
		if (*p++ == '/')
			mtime[++ndir] = -1;
	mtime[ndir] = stbuf.st_mtime;	/* overwrite the last one */
}
E 28

D 28
		case 'Y':
		case 'y':
		case '\n':
			pstr = usefile;
			break;
E 28
I 28
setimes(path, mt)
	char *path;
	time_t mt;
{
	struct timeval tv[2];
E 28

D 28
		default:
			pstr = str;
		}
		if ((f = open(pstr, x ? 1 : 0)) >= 0) {
			fclose(devtty);
			return (f);
		}
		fprintf(stderr, "tar: open of %s failed\n", pstr);
E 28
I 28
	tv[0].tv_sec = time((time_t *) 0);
	tv[1].tv_sec = mt;
	tv[0].tv_usec = tv[1].tv_usec = 0;
D 31
	if (utimes(path, tv) < 0)
		fprintf(stderr, "tar: can't set time on %s\n", path);
E 31
I 31
	if (utimes(path, tv) < 0) {
		fprintf(stderr, "tar: can't set time on %s: ", path);
		perror("");
	}
E 31
}

char *
getmem(size)
{
	char *p = malloc((unsigned) size);

	if (p == NULL && freemem) {
		fprintf(stderr,
		    "tar: out of memory, link and directory modtime info lost\n");
		freemem = 0;
E 28
	}
D 28
done:
	fclose(devtty);
	return (-1);
E 28
I 28
	return (p);
E 28
E 25
E 24
I 20
D 22
}

bwrite(mt, buf, count)
	int mt, count;
	char *buf;
{
	register int i;
	int tc = count;

	while (count) {
		i = write(mt, buf, count);
		if (i <= 0) {
			if (Mflag)
				return (i);
			mt = chgreel(1, mt);
			if (mt == -1)
				done(2);
		} else {
			count -= i;
			buf += i;
		}
	}
	return (tc);
}

chgreel(x, fl)
	int x, fl;
{
	register int f;
	char str[BUFSIZ];
	char *pstr;
	FILE *devtty;
	struct stat statb;

	perror("tar");
	fprintf(stderr, "Can't %s\n", x ? "write output": "read input");
	fstat(fl, &statb);
	if ((statb.st_mode & S_IFMT) != S_IFCHR)
		done(2);

	close(fl);
	devtty = fopen("/dev/tty", "r");
	for (;;) {
		fprintf(stderr, "tar: If you want to go on, type \"yes\" or a new pathname of a device/file name when you are ready\n");
		if (fgets(str, sizeof (str), devtty) == NULL)
			break;
		str[strlen(str) - 1] = '\0';

		switch (*str) {
		case '\0':
		case 'N':
		case 'n':
			goto done;

		case 'Y':
		case 'y':
		case '\n':
			pstr = usefile;
			break;

		default:
			pstr = str;
		}
		if ((f = open(pstr, x ? 1 : 0)) >= 0) {
			fclose(devtty);
			return (f);
		}
		fprintf(stderr, "tar: open of %s failed\n", pstr);
	}
done:
	fclose(devtty);
	return (-1);
E 22
E 20
E 14
E 11
}
E 1
