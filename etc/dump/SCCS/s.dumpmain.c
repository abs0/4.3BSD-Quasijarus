h59553
s 00003/00001/00359
d D 5.6 87/02/23 18:06:31 mckusick 25 24
c convert SBLOCK to SBOFF; generalize dev_bsize
e
s 00011/00001/00349
d D 5.5 86/10/21 15:52:33 mckusick 24 23
c place all the dump information in the new dump header
e
s 00001/00000/00349
d D 5.4 86/05/28 11:11:43 mckusick 23 22
c finally no longer need setuid root except for rmthost()
e
s 00001/00001/00348
d D 5.3 86/05/23 11:18:14 mckusick 22 21
c put back that newline!
e
s 00010/00004/00339
d D 5.2 86/01/09 21:28:37 mckusick 21 20
c speedup and cleanup by Chris Torek
e
s 00010/00001/00333
d D 5.1 85/06/05 08:45:48 dist 20 18
c Add copyright
e
s 00002/00000/00334
d R 1.19 85/04/16 14:10:26 mckusick 19 18
c assume infinite length tape when outputting to a pipe
e
s 00004/00001/00330
d D 1.18 85/03/24 18:06:47 mckusick 18 17
c use HIGHDENSITYTREC for 6250 BPI dumps
e
s 00001/00001/00330
d D 1.17 84/10/05 15:56:05 mckusick 17 16
c maintain consistent dump tapes on active systems (decvax!watmath!srradia)
e
s 00002/00002/00329
d D 1.16 84/03/28 19:04:17 mckusick 16 15
c correct estimate of number of cartridge tapes needed to dump
e
s 00000/00001/00331
d D 1.15 83/08/19 19:45:57 sam 15 14
c extraneous divide in dump size calculation (from bruce jerrick)
e
s 00002/00001/00330
d D 1.14 83/06/09 12:50:35 mckusick 14 13
c print out correct previous incremental number
e
s 00001/00005/00330
d D 1.13 83/05/19 19:26:35 mckusick 13 12
c introduce true locking on /etc/dumpdates; 
c get rid of -J option that converts from /etc/ddates to /etc/dumpdates
e
s 00014/00003/00321
d D 1.12 83/05/08 19:11:19 mckusick 12 11
c add ability to dump to standard output
e
s 00055/00007/00269
d D 1.11 83/02/11 12:58:20 sam 11 10
c merge from sun
e
s 00003/00002/00273
d D 1.10 82/10/11 17:58:26 mckusick 10 9
c output clean-up
e
s 00001/00001/00274
d D 1.9 82/10/07 18:40:50 mckusick 9 8
c format fix
e
s 00014/00014/00261
d D 1.8 82/05/20 16:30:33 sam 8 7
c back to the depths
e
s 00025/00001/00250
d D 1.7 82/05/20 15:11:05 sam 7 6
c convert to calder
e
s 00001/00001/00250
d D 1.6 82/01/06 23:01:32 mckusic 6 5
c incorporate fs.h -r1.10, and param.h -r1.8 reorganization
e
s 00029/00017/00222
d D 1.5 82/01/05 01:37:16 mckusic 5 4
c parameterize BSIZE, FSIZE, and FRAG into fs_bsize, fs_fsize, and fs_frag
e
s 00001/00001/00238
d D 1.4 81/11/07 14:53:12 mckusic 4 3
c dump to "standard" (ie 1K file system) dump tapes
e
s 00001/00000/00238
d D 1.3 81/10/25 17:36:38 mckusic 3 2
c shut type clash warning
e
s 00005/00001/00233
d D 1.2 80/10/16 10:12:33 root 2 1
c Option 'w' tells only what to dump; 'W' tells most recent dump(s)
e
s 00234/00000/00000
d D 1.1 80/10/13 17:30:26 root 1 0
c date and time created 80/10/13 17:30:26 by root
e
u
U
t
T
I 1
D 20
static	char *sccsid = "%W% (Berkeley) %G%";
E 20
I 20
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 20
#include "dump.h"

int	notify = 0;	/* notify operator flag */
int	blockswritten = 0;	/* number of blocks written on current tape */
int	tapeno = 0;	/* current tape number */
D 11
int	density = 160;	/* density in 0.1" units */
E 11
I 11
int	density = 0;	/* density in bytes/0.1" */
int	ntrec = NTREC;	/* # tape blocks in each tape record */
int	cartridge = 0;	/* Assume non-cartridge tape */
I 25
long	dev_bsize = 1;	/* recalculated below */
E 25
E 11
I 7
#ifdef RDUMP
char	*host;
#endif
I 21
int	anydskipped;	/* set true in mark() if any directories are skipped */
			/* this lets us avoid map pass 2 in some cases */
E 21
E 7

main(argc, argv)
	int	argc;
	char	*argv[];
{
	char		*arg;
D 5
	register	i;
E 5
I 5
D 18
	int		i;
E 18
I 18
	int		bflag = 0, i;
E 18
E 5
	float		fetapes;
	register	struct	fstab	*dt;

	time(&(spcl.c_date));

D 11
	tsize = 2300L*12L*10L;
E 11
I 11
	tsize = 0;	/* Default later, based on 'c' option for cart tapes */
E 11
	tape = TAPE;
	disk = DISK;
	increm = NINCREM;
I 13
	temp = TEMP;
E 13
D 5

E 5
I 5
	if (TP_BSIZE / DEV_BSIZE == 0 || TP_BSIZE % DEV_BSIZE != 0) {
		msg("TP_BSIZE must be a multiple of DEV_BSIZE\n");
		dumpabort();
	}
E 5
	incno = '9';
	uflag = 0;
	arg = "u";
I 7
D 8
#ifdef RDUMP
	if (argc < 2) {
		printf("usage: rdump machine ");
		Exit(X_ABORT);
	}
	host = argv[1];
	argv++, argc--;
	if (rmthost(host) == 0)
		Exit(X_ABORT);
#endif
E 8
E 7
	if(argc > 1) {
		argv++;
		argc--;
		arg = *argv;
		if (*arg == '-')
			argc++;
	}
	while(*arg)
	switch (*arg++) {
I 2
	case 'w':
		lastdump('w');		/* tell us only what has to be done */
		exit(0);
		break;
E 2
	case 'W':			/* what to do */
D 2
		lastdump();
E 2
I 2
		lastdump('W');		/* tell us the current state of what has been done */
E 2
D 13
		exit(0);		/* do nothing else */
		break;

	case 'J':			/* update old to new */
		o_nconvert();
E 13
		exit(0);		/* do nothing else */
		break;

	case 'f':			/* output file */
		if(argc > 1) {
			argv++;
			argc--;
			tape = *argv;
		}
		break;

	case 'd':			/* density, in bits per inch */
		if (argc > 1) {
			argv++;
			argc--;
			density = atoi(*argv) / 10;
I 18
			if (density >= 625 && !bflag)
				ntrec = HIGHDENSITYTREC;
E 18
		}
		break;

	case 's':			/* tape size, feet */
		if(argc > 1) {
			argv++;
			argc--;
			tsize = atol(*argv);
			tsize *= 12L*10L;
		}
		break;

I 11
	case 'b':			/* blocks per tape write */
		if(argc > 1) {
			argv++;
			argc--;
I 18
			bflag++;
E 18
			ntrec = atol(*argv);
		}
		break;

	case 'c':			/* Tape is cart. not 9-track */
		cartridge++;
		break;

E 11
	case '0':			/* dump level */
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		incno = arg[-1];
		break;

	case 'u':			/* update /etc/dumpdates */
		uflag++;
		break;

	case 'n':			/* notify operators */
		notify++;
		break;

	default:
D 12
		printf("bad key '%c%'\n", arg[-1]);
E 12
I 12
		fprintf(stderr, "bad key '%c%'\n", arg[-1]);
E 12
		Exit(X_ABORT);
	}
	if(argc > 1) {
		argv++;
		argc--;
		disk = *argv;
	}
I 12
	if (strcmp(tape, "-") == 0) {
		pipeout++;
		tape = "standard output";
	}
E 12
I 11

	/*
	 * Determine how to default tape size and density
	 *
	 *         	density				tape size
	 * 9-track	1600 bpi (160 bytes/.1")	2300 ft.
	 * 9-track	6250 bpi (625 bytes/.1")	2300 ft.
D 16
	 * cartridge	8000 bpi (100 bytes/.1")	4000 ft. (450*9 - slop)
E 16
I 16
 	 * cartridge	8000 bpi (100 bytes/.1")	1700 ft. (450*4 - slop)
E 16
	 */
	if (density == 0)
		density = cartridge ? 100 : 160;
	if (tsize == 0)
D 16
		tsize = cartridge ? 4000L*120L : 2300L*120L;
E 16
I 16
 		tsize = cartridge ? 1700L*120L : 2300L*120L;
E 16

E 11
D 8

E 8
I 8
#ifdef RDUMP
	{ char *index();
	  host = tape;
	  tape = index(host, ':');
	  if (tape == 0) {
D 22
		msg("need keyletter ``f'' and device ``host:tape''");
E 22
I 22
		msg("need keyletter ``f'' and device ``host:tape''\n");
E 22
		exit(1);
	  }
	  *tape++ = 0;
	  if (rmthost(host) == 0)
		exit(X_ABORT);
	}
I 23
	setuid(getuid());	/* rmthost() is the only reason to be setuid */
E 23
#endif
E 8
	if (signal(SIGHUP, sighup) == SIG_IGN)
		signal(SIGHUP, SIG_IGN);
	if (signal(SIGTRAP, sigtrap) == SIG_IGN)
		signal(SIGTRAP, SIG_IGN);
	if (signal(SIGFPE, sigfpe) == SIG_IGN)
		signal(SIGFPE, SIG_IGN);
	if (signal(SIGBUS, sigbus) == SIG_IGN)
		signal(SIGBUS, SIG_IGN);
	if (signal(SIGSEGV, sigsegv) == SIG_IGN)
		signal(SIGSEGV, SIG_IGN);
	if (signal(SIGTERM, sigterm) == SIG_IGN)
		signal(SIGTERM, SIG_IGN);
	

	if (signal(SIGINT, interrupt) == SIG_IGN)
		signal(SIGINT, SIG_IGN);

	set_operators();	/* /etc/group snarfed */
	getfstab();		/* /etc/fstab snarfed */
	/*
	 *	disk can be either the full special file name,
	 *	the suffix of the special file name,
	 *	the special name missing the leading '/',
	 *	the file system name with or without the leading '/'.
	 */
	dt = fstabsearch(disk);
D 24
	if (dt != 0)
E 24
I 24
	if (dt != 0) {
E 24
		disk = rawname(dt->fs_spec);
I 24
		strncpy(spcl.c_dev, dt->fs_spec, NAMELEN);
		strncpy(spcl.c_filesys, dt->fs_file, NAMELEN);
	} else {
		strncpy(spcl.c_dev, disk, NAMELEN);
		strncpy(spcl.c_filesys, "an unlisted file system", NAMELEN);
	}
	strcpy(spcl.c_label, "none");
	gethostname(spcl.c_host, NAMELEN);
	spcl.c_level = incno - '0';
	spcl.c_type = TS_TAPE;
E 24
	getitime();		/* /etc/dumpdates snarfed */

	msg("Date of this level %c dump: %s\n", incno, prdate(spcl.c_date));
D 14
	msg("Date of last level %c dump: %s\n", incno, prdate(spcl.c_ddate));
E 14
I 14
 	msg("Date of last level %c dump: %s\n",
		lastincno, prdate(spcl.c_ddate));
E 14
	msg("Dumping %s ", disk);
	if (dt != 0)
		msgtail("(%s) ", dt->fs_file);
I 7
D 8
#ifdef RDUMP
E 8
D 9
	msgtail("to %s", tape);
E 9
I 9
D 10
	msgtail("to %s\n", tape);
E 10
E 9
I 8
#ifdef RDUMP
E 8
D 10
	msgtail(" on host %s\n", host);
E 10
I 10
	msgtail("to %s on host %s\n", tape, host);
#else
	msgtail("to %s\n", tape);
E 10
D 8
#else
E 7
	msgtail("to %s\n", tape);
E 8
I 7
#endif
E 7

	fi = open(disk, 0);
	if (fi < 0) {
		msg("Cannot open %s\n", disk);
		Exit(X_ABORT);
	}
D 5
	CLR(clrmap);
	CLR(dirmap);
	CLR(nodmap);
E 5
	esize = 0;
I 5
	sblock = (struct fs *)buf;
	sync();
D 6
	bread(SBLOCK, sblock, MAXBSIZE);
E 6
I 6
D 25
	bread(SBLOCK, sblock, SBSIZE);
E 25
I 25
	bread(SBOFF, sblock, SBSIZE);
E 25
E 6
	if (sblock->fs_magic != FS_MAGIC) {
		msg("bad sblock magic number\n");
		dumpabort();
	}
I 25
	dev_bsize = sblock->fs_fsize / fsbtodb(sblock, 1);
E 25
	msiz = roundup(howmany(sblock->fs_ipg * sblock->fs_ncg, NBBY),
		TP_BSIZE);
	clrmap = (char *)calloc(msiz, sizeof(char));
	dirmap = (char *)calloc(msiz, sizeof(char));
	nodmap = (char *)calloc(msiz, sizeof(char));
E 5

I 21
	anydskipped = 0;
E 21
	msg("mapping (Pass I) [regular files]\n");
D 5
	pass(mark, (short *)NULL);		/* mark updates esize */
E 5
I 5
	pass(mark, (char *)NULL);		/* mark updates esize */
E 5

D 21
	do {
E 21
I 21
	if (anydskipped) {
		do {
			msg("mapping (Pass II) [directories]\n");
			nadded = 0;
			pass(add, dirmap);
		} while(nadded);
	} else				/* keep the operators happy */
E 21
		msg("mapping (Pass II) [directories]\n");
D 21
		nadded = 0;
		pass(add, dirmap);
	} while(nadded);
E 21

	bmapest(clrmap);
	bmapest(nodmap);

D 11
	fetapes =
E 11
I 11
	if (cartridge) {
		/* Estimate number of tapes, assuming streaming stops at
		   the end of each block written, and not in mid-block.
		   Assume no erroneous blocks; this can be compensated for
		   with an artificially low tape size. */
		fetapes = 
E 11
D 5
		(	 esize		/* blocks */
D 4
			*BSIZE		/* bytes / block */
E 4
I 4
			*FSIZE		/* bytes / block */
E 4
			*(1.0/density)	/* 0.1" / byte */
E 5
I 5
		(	  esize		/* blocks */
I 11
			* TP_BSIZE	/* bytes/block */
			* (1.0/density)	/* 0.1" / byte */
		  +
			  esize		/* blocks */
			* (1.0/ntrec)	/* streaming-stops per block */
			* 15.48		/* 0.1" / streaming-stop */
		) * (1.0 / tsize );	/* tape / 0.1" */
	} else {
		/* Estimate number of tapes, for old fashioned 9-track tape */
		int tenthsperirg = (density == 625) ? 3 : 7;
		fetapes =
		(	  esize		/* blocks */
E 11
			* TP_BSIZE	/* bytes / block */
			* (1.0/density)	/* 0.1" / byte */
E 5
		  +
D 5
			 esize		/* blocks */
			*(1.0/NTREC)	/* IRG's / block */
			*7		/* 0.1" / IRG */
E 5
I 5
			  esize		/* blocks */
D 11
			* (1.0/NTREC)	/* IRG's / block */
E 11
I 11
			* (1.0/ntrec)	/* IRG's / block */
			* tenthsperirg	/* 0.1" / IRG */
E 11
D 15
			* 7		/* 0.1" / IRG */
E 15
E 5
D 11
		) * (1.0 / tsize )	/* tape / 0.1" */
	;
E 11
I 11
		) * (1.0 / tsize );	/* tape / 0.1" */
	}
E 11
	etapes = fetapes;		/* truncating assignment */
	etapes++;
D 5
	/*
	 *	esize is typically about 5% too low; we frob it here
	 */
	esize += ((5*esize)/100);
E 5
I 5
	/* count the nodemap on each additional tape */
	for (i = 1; i < etapes; i++)
		bmapest(nodmap);
	esize += i + 10;	/* headers + 10 trailer blocks */
E 5
	msg("estimated %ld tape blocks on %3.2f tape(s).\n", esize, fetapes);

I 11
	alloctape();			/* Allocate tape buffer */

E 11
	otape();			/* bitmap is the first to tape write */
	time(&(tstart_writing));
	bitmap(clrmap, TS_CLRI);

	msg("dumping (Pass III) [directories]\n");
D 17
	pass(dump, dirmap);
E 17
I 17
 	pass(dirdump, dirmap);
E 17

	msg("dumping (Pass IV) [regular files]\n");
	pass(dump, nodmap);

	spcl.c_type = TS_END;
D 5
	for(i=0; i<NTREC; i++)
E 5
I 5
D 7
	for(i = 0; i < NTREC; i++)
E 7
I 7
#ifndef RDUMP
D 11
	for(i=0; i<NTREC; i++)
E 11
I 11
	for(i=0; i<ntrec; i++)
E 11
E 7
E 5
		spclrec();
I 7
#endif
E 7
	msg("DUMP: %ld tape blocks on %d tape(s)\n",spcl.c_tapea,spcl.c_volume);
	msg("DUMP IS DONE\n");

	putitime();
I 7
#ifndef RDUMP
E 7
D 12
	close(to);
E 12
I 12
	if (!pipeout) {
		close(to);
		rewind();
	}
E 12
I 7
#else
	tflush(1);
D 12
#endif
E 12
E 7
	rewind();
I 12
#endif
E 12
	broadcast("DUMP IS DONE!\7\7\n");
	Exit(X_FINOK);
}

int	sighup(){	msg("SIGHUP()  try rewriting\n"); sigAbort();}
int	sigtrap(){	msg("SIGTRAP()  try rewriting\n"); sigAbort();}
int	sigfpe(){	msg("SIGFPE()  try rewriting\n"); sigAbort();}
int	sigbus(){	msg("SIGBUS()  try rewriting\n"); sigAbort();}
int	sigsegv(){	msg("SIGSEGV()  ABORTING!\n"); abort();}
int	sigalrm(){	msg("SIGALRM()  try rewriting\n"); sigAbort();}
int	sigterm(){	msg("SIGTERM()  try rewriting\n"); sigAbort();}

sigAbort()
{
I 12
	if (pipeout) {
		msg("Unknown signal, cannot recover\n");
		dumpabort();
	}
E 12
	msg("Rewriting attempted as response to unknown signal.\n");
	fflush(stderr);
	fflush(stdout);
	close_rewind();
	exit(X_REWRITE);
}

char *rawname(cp)
	char *cp;
{
	static char rawbuf[32];
I 3
	char *rindex();
E 3
	char *dp = rindex(cp, '/');

	if (dp == 0)
		return (0);
	*dp = 0;
	strcpy(rawbuf, cp);
	*dp = '/';
	strcat(rawbuf, "/r");
	strcat(rawbuf, dp+1);
	return (rawbuf);
}
E 1
