h53365
s 00004/00004/00118
d D 7.5 03/04/13 15:19:11 msokolov 13 12
c 8-bit ex
e
s 00008/00002/00114
d D 7.4 85/05/31 15:57:56 dist 12 10
c Add copyright
e
s 00008/00002/00113
d D 5.1.1.1 85/05/31 11:51:51 dist 11 6
c Add copyright
e
s 00001/00001/00115
d D 7.3 81/08/02 08:55:38 mark 10 9
c fix for portability on systems with big uids.  THIS CHANGES TEMP
c FILE FORMAT SO EXPRESERVE/RECOVER MUST BE UPDATED AT SAME TIME.
e
s 00014/00014/00102
d D 7.2 81/07/26 20:04:35 mark 9 8
c fixes for 3b
e
s 00017/00016/00099
d D 7.1 81/07/08 22:31:31 mark 8 7
c release 3.7 - a few bug fixes and a few new features.
e
s 00000/00000/00115
d D 6.1 80/10/19 01:21:31 mark 7 6
c preliminary release 3.6 10/18/80
e
s 00000/00000/00115
d D 5.1 80/08/20 16:11:54 mark 6 5
c Release 3.5, August 20, 1980
e
s 00002/00001/00113
d D 4.2 80/08/01 20:41:27 mark 5 4
c Bill added more buffers, and I put in sccs.
e
s 00000/00000/00114
d D 4.1 80/08/01 00:15:50 mark 4 3
c release 3.4, June 24, 1980
e
s 00000/00000/00114
d D 3.1 80/07/31 23:39:47 mark 3 2
c release 3.3, Feb 2, 1980
e
s 00028/00008/00086
d D 2.1 80/07/31 23:19:40 mark 2 1
c release 3.2, Jan 4, 1980
e
s 00094/00000/00000
d D 1.1 80/07/31 23:00:29 mark 1 0
c date and time created 80/07/31 23:00:29 by mark
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
D 11
/* Copyright (c) 1980 Regents of the University of California */
/* sccs id:	%W% %G%  */
E 11
I 11
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */

E 11
E 8
I 8
D 12
/* Copyright (c) 1981 Regents of the University of California */
/* sccs id:	%W%	%G%  */
E 12
I 12
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */

E 12
E 8
E 5
/*
 * The editor uses a temporary file for files being edited, in a structure
 * similar to that of ed.  The first block of the file is used for a header
 * block which guides recovery after editor/system crashes.
 * Lines are represented in core by a pointer into the temporary file which
D 2
 * is packed into 16 bits.  15 of these bits index the temporary file,
 * the 16'th is used by global commands.  The parameters below control
 * how much the 15 bits are shifted left before they index the temp file.
E 2
I 2
 * is packed into 16 bits (32 on VMUNIX).  All but the low bit index the temp
 * file; the last is used by global commands.  The parameters below control
 * how much the other bits are shifted left before they index the temp file.
E 2
 * Larger shifts give more slop in the temp file but allow larger files
 * to be edited.
 *
 * The editor does not garbage collect the temporary file.  When a new
 * file is edited, the temporary file is rather discarded and a new one
 * created for the new file.  Garbage collection would be rather complicated
 * in ex because of the general undo, and in any case would require more
 * work when throwing lines away because marks would have be carefully
 * checked before reallocating temporary file space.  Said another way,
 * each time you create a new line in the temporary file you get a unique
 * number back, and this is a property used by marks.
 *
 * The following temp file parameters allow 256k bytes in the temporary
 * file.  By changing to the numbers in comments you can get 512k.
D 2
 * By typedefing line to long (32 bit) integers you could get much more
 * space in the temp file with (then) no waste.  This would double core
 * requirements and would probably require some editor debugging.
E 2
I 2
 * For VMUNIX you get more than you could ever want.
 * VMUNIX uses long (32 bit) integers giving much more
 * space in the temp file and no waste.  This doubles core
 * requirements but allows files of essentially unlimited size to be edited.
E 2
 */
I 2
#ifndef VMUNIX
E 2
#define	BLKMSK	0777		/* 01777 */
#define	BNDRY	8		/* 16 */
#define	INCRMT	0200		/* 0100 */
#define	LBTMSK	0770		/* 0760 */
#define	NMBLKS	506		/* 1018 */
#define	OFFBTS	7		/* 6 */
#define	OFFMSK	0177		/* 077 */
#define	SHFT	2		/* 3 */
I 2
#else
#define	BLKMSK	077777
#define	BNDRY	2
#define	INCRMT	02000
#define	LBTMSK	01776
#define	NMBLKS	077770
#define	OFFBTS	10
#define	OFFMSK	01777
#define	SHFT	0
#endif
E 2

/*
 * The editor uses three buffers into the temporary file (ed uses two
 * and is very similar).  These are two read buffers and one write buffer.
D 2
 * Basically, the editor deals with the file as a sequence of 512 character
 * blocks (BUFSIZ).  Each block contains some number of lines (and lines
E 2
I 2
 * Basically, the editor deals with the file as a sequence of BUFSIZ character
 * blocks.  Each block contains some number of lines (and lines
E 2
 * can run across block boundaries.
 *
 * New lines are written into the last block in the temporary file
 * which is in core as obuf.  When a line is needed which isn't in obuf,
 * then it is brought into an input buffer.  As there are two, the choice
 * is to take the buffer into which the last read (of the two) didn't go.
 * Thus this is a 2 buffer LRU replacement strategy.  Measurement
 * shows that this saves roughly 25% of the buffer reads over a one
 * input buffer strategy.  Since the editor (on our VAX over 1 week)
 * spends (spent) roughly 30% of its time in the system read routine,
 * this can be a big help.
 */
D 8
bool	hitin2;			/* Last read hit was ibuff2 not ibuff */
bool	ichang2;		/* Have actually changed ibuff2 */
bool	ichanged;		/* Have actually changed ibuff */
short	iblock;			/* Temp file block number of ibuff (or -1) */
short	iblock2;		/* Temp file block number of ibuff2 (or -1) */
short	ninbuf;			/* Number useful chars left in input buffer */
short	nleft;			/* Number usable chars left in output buffer */
short	oblock;			/* Temp file block number of obuff (or -1) */
E 8
I 8
D 9
extern bool	hitin2;		/* Last read hit was ibuff2 not ibuff */
extern bool	ichang2;	/* Have actually changed ibuff2 */
extern bool	ichanged;	/* Have actually changed ibuff */
extern short	iblock;		/* Temp file block number of ibuff (or -1) */
extern short	iblock2;	/* Temp file block number of ibuff2 (or -1) */
extern short	ninbuf;		/* Number useful chars left in input buffer */
extern short	nleft;		/* Number usable chars left in output buffer */
extern short	oblock;		/* Temp file block number of obuff (or -1) */
E 9
I 9
var bool	hitin2;		/* Last read hit was ibuff2 not ibuff */
var bool	ichang2;	/* Have actually changed ibuff2 */
var bool	ichanged;	/* Have actually changed ibuff */
var short	iblock;		/* Temp file block number of ibuff (or -1) */
var short	iblock2;	/* Temp file block number of ibuff2 (or -1) */
var short	ninbuf;		/* Number useful chars left in input buffer */
var short	nleft;		/* Number usable chars left in output buffer */
var short	oblock;		/* Temp file block number of obuff (or -1) */
E 9
E 8
I 2
#ifndef VMUNIX
E 2
D 8
short	tline;			/* Current temp file ptr */
E 8
I 8
D 9
extern short	tline;		/* Current temp file ptr */
E 9
I 9
var short	tline;		/* Current temp file ptr */
E 9
E 8
I 2
#else
D 8
int	tline;
E 8
I 8
D 9
extern int	tline;
E 9
I 9
var int	tline;
E 9
E 8
#endif
E 2

D 8
char	ibuff[BUFSIZ];
char	ibuff2[BUFSIZ];
char	obuff[BUFSIZ];
E 8
I 8
D 9
extern char	ibuff[BUFSIZ];
extern char	ibuff2[BUFSIZ];
extern char	obuff[BUFSIZ];
E 9
I 9
D 13
var char	ibuff[BUFSIZ];
var char	ibuff2[BUFSIZ];
var char	obuff[BUFSIZ];
E 13
I 13
var u_char	ibuff[BUFSIZ];
var u_char	ibuff2[BUFSIZ];
var u_char	obuff[BUFSIZ];
E 13
E 9
E 8

/*
 * Structure of the descriptor block which resides
 * in the first block of the temporary file and is
 * the guiding light for crash recovery.
 *
 * As the Blocks field below implies, there are temporary file blocks
 * devoted to (some) image of the incore array of pointers into the temp
 * file.  Thus, to recover from a crash we use these indices to get the
 * line pointers back, and then use the line pointers to get the text back.
 * Except for possible lost lines due to sandbagged I/O, the entire
 * file (at the time of the last editor "sync") can be recovered from
 * the temp file.
 */

/* This definition also appears in expreserve.c... beware */
struct 	header {
	time_t	Time;			/* Time temp file last updated */
D 10
	short	Uid;
E 10
I 10
	int	Uid;
E 10
I 2
#ifndef VMUNIX
E 2
	short	Flines;			/* Number of lines in file */
I 2
#else
	int	Flines;
#endif
E 2
D 13
	char	Savedfile[FNSIZE];	/* The current file name */
E 13
I 13
	u_char	Savedfile[FNSIZE];	/* The current file name */
E 13
	short	Blocks[LBLKS];		/* Blocks where line pointers stashed */
D 8
} H;
E 8
I 8
}; 
D 9
extern struct 	header H;
E 9
I 9
var struct 	header H;
E 9
E 8

#define	uid		H.Uid
#define	flines		H.Flines
#define	savedfile	H.Savedfile
#define	blocks		H.Blocks
E 1
