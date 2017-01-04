h63163
s 00005/00000/00137
d D 1.11 87/04/07 17:48:55 mckusick 11 10
c port to tahoe
e
s 00004/00003/00133
d D 1.10 83/01/10 18:57:23 mckusick 10 9
c ifdef VAX => ifdef ADDR32
e
s 00007/00000/00129
d D 1.9 81/06/17 00:01:33 mckusic 9 8
c add seekptr struct for TELL and SEEK
e
s 00002/00002/00127
d D 1.8 81/06/14 23:58:35 mckusic 8 7
c make fblk an unsigned to prevent illegal negative numbers
e
s 00000/00006/00129
d D 1.7 81/06/10 00:45:18 mckusic 7 6
c move the text of error messages from ERROR to the functions
c which generate them.
e
s 00003/00003/00132
d D 1.6 81/04/01 22:16:34 mckusic 6 5
c mods for dynamically allocating display save area before formal calls
e
s 00011/00002/00124
d D 1.5 81/03/07 16:06:34 mckusic 5 4
c merge in onyx changes
e
s 00009/00008/00117
d D 1.4 81/01/24 19:06:56 mckusic 4 3
c add another unit flag for pseudo EOLN at EOF
e
s 00001/00000/00124
d D 1.3 81/01/16 13:26:43 mckusic 3 2
c update random number generator
e
s 00007/00000/00117
d D 1.2 81/01/16 12:59:19 mckusic 2 1
c add extension to catch runtime errors
e
s 00117/00000/00000
d D 1.1 80/10/30 00:36:37 mckusick 1 0
c date and time created 80/10/30 00:36:37 by mckusick
e
u
U
t
T
I 1
/* Copyright (c) 1979 Regents of the University of California */

/* sccsid[] = "%Z%%M% %I% %G%"; */

#include <stdio.h>
I 5
#include "whoami.h"
E 5

#define PXPFILE		"pmon.out"
#define	BITSPERBYTE	8
#define	BITSPERLONG	(BITSPERBYTE * sizeof(long))
I 5
#define LG2BITSBYTE	03
#define MSKBITSBYTE	07
#define LG2BITSLONG	05
#define MSKBITSLONG	037
E 5
#define HZ		60
D 5
#define	TRUE		1
#define	FALSE		0
E 5
#define	MAXLVL		20
I 2
#define MAXERRS		75
E 2
#define NAMSIZ		76
#define MAXFILES	32
#define PREDEF		2
I 5
D 10
#ifdef VAX
E 10
I 10
#ifdef ADDR32
I 11
#ifndef tahoe
E 11
E 10
E 5
#define STDLVL		((struct iorec *)(0x7ffffff1))
#define GLVL		((struct iorec *)(0x7ffffff0))
I 11
#else tahoe
#define STDLVL		((struct iorec *)(0xbffffff1))
#define GLVL		((struct iorec *)(0xbffffff0))
#endif tahoe
E 11
I 5
D 10
#else
E 10
I 10
#endif ADDR32
#ifdef ADDR16
E 10
#define STDLVL		((struct iorec *)(0xfff1))
#define GLVL		((struct iorec *)(0xfff0))
D 10
#endif VAX
E 10
I 10
#endif ADDR16
E 10
E 5
#define FILNIL		((struct iorec *)(0))
#define INPUT		((struct iorec *)(&input))
#define OUTPUT		((struct iorec *)(&output))
#define ERR		((struct iorec *)(&_err))
I 5
typedef enum {FALSE, TRUE} bool;
E 5

/*
 * runtime display structure
 */
struct display {
	char	*ap;
	char	*fp;
};

/*
 * formal routine structure
 */
struct formalrtn {
D 6
	long		(*entryaddr)();
	long		cbn;
	struct display	disp[2*MAXLVL];
E 6
I 6
	long		(*fentryaddr)();	/* formal entry point */
	long		fbn;			/* block number of function */
	struct display	fdisp[ MAXLVL ];	/* saved at first passing */
E 6
};

I 2
D 7
struct errentry {
	long (*entryaddr)();
};


E 7
E 2
/*
 * program variables
 */
extern struct display	_disply[MAXLVL];/* runtime display */
extern int		_argc;		/* number of passed args */
extern char		**_argv;	/* values of passed args */
extern long		_stlim;		/* statement limit */
extern long		_stcnt;		/* statement count */
I 3
extern long		_seed;		/* random number seed */
E 3
extern char		*_maxptr;	/* maximum valid pointer */
extern char		*_minptr;	/* minimum valid pointer */
extern long		_pcpcount[];	/* pxp buffer */
I 2
D 7
extern struct errentry	_entry[MAXERRS];/* error entry catches */
E 7
E 2

/*
 * file structures
 */
struct iorechd {
	char		*fileptr;	/* ptr to file window */
	long		lcount;		/* number of lines printed */
	long		llimit;		/* maximum number of text lines */
	FILE		*fbuf;		/* FILE ptr */
	struct iorec	*fchain;	/* chain to next file */
	struct iorec	*flev;		/* ptr to associated file variable */
	char		*pfname;	/* ptr to name of file */
	short		funit;		/* file status flags */
D 8
	short		fblk;		/* index into active file table */
E 8
I 8
	unsigned short	fblk;		/* index into active file table */
E 8
	long		fsize;		/* size of elements in the file */
	char		fname[NAMSIZ];	/* name of associated UNIX file */
};

struct iorec {
	char		*fileptr;	/* ptr to file window */
	long		lcount;		/* number of lines printed */
	long		llimit;		/* maximum number of text lines */
	FILE		*fbuf;		/* FILE ptr */
	struct iorec	*fchain;	/* chain to next file */
	struct iorec	*flev;		/* ptr to associated file variable */
	char		*pfname;	/* ptr to name of file */
	short		funit;		/* file status flags */
D 8
	short		fblk;		/* index into active file table */
E 8
I 8
	unsigned short	fblk;		/* index into active file table */
E 8
	long		fsize;		/* size of elements in the file */
	char		fname[NAMSIZ];	/* name of associated UNIX file */
	char		buf[BUFSIZ];	/* I/O buffer */
	char		window[1];	/* file window element */
};

/*
 * unit flags
 */
D 4
#define	FDEF	0x80	/* 1 => reserved file name */
#define	FTEXT	0x40	/* 1 => text file, process EOLN */
#define	FWRITE	0x20	/* 1 => open for writing */
#define	FREAD	0x10	/* 1 => open for reading */
#define	TEMP	0x08	/* 1 => temporary file */
#define	SYNC	0x04	/* 1 => window is out of sync */
#define	EOLN	0x02	/* 1 => at end of line */
#define	EOFF	0x01	/* 1 => at end of file */
E 4
I 4
#define SPEOLN	0x100	/* 1 => pseudo EOLN char read at EOF */
#define	FDEF	0x080	/* 1 => reserved file name */
#define	FTEXT	0x040	/* 1 => text file, process EOLN */
#define	FWRITE	0x020	/* 1 => open for writing */
#define	FREAD	0x010	/* 1 => open for reading */
#define	TEMP	0x008	/* 1 => temporary file */
#define	SYNC	0x004	/* 1 => window is out of sync */
#define	EOLN	0x002	/* 1 => at end of line */
#define	EOFF	0x001	/* 1 => at end of file */
E 4

/*
 * file routines
 */
extern struct iorec	*GETNAME();
extern char		*MKTEMP();
extern char		*PALLOC();

/*
 * file record variables
 */
extern struct iorechd	_fchain;	/* head of active file chain */
extern struct iorec	*_actfile[];	/* table of active files */
extern long		_filefre;	/* last used entry in _actfile */

/*
 * standard files
 */
extern struct iorechd	input;
extern struct iorechd	output;
extern struct iorechd	_err;
I 9

/*
 * seek pointer struct for TELL, SEEK extensions
 */
struct seekptr {
	long	cnt;
};
E 9
E 1
