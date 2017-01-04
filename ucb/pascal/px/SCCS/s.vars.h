h02925
s 00005/00000/00256
d D 5.2 86/11/05 19:08:46 mckusick 15 14
c update for tahoe
e
s 00007/00003/00249
d D 5.1 85/06/05 14:00:48 dist 14 13
c Add copyright
e
s 00000/00000/00252
d D 2.1 84/02/08 20:29:23 aoki 13 12
c synchronize to version 2
e
s 00003/00042/00249
d D 1.12 83/01/22 01:20:30 mckusick 12 11
c certain info moves out of vars.h into objfmt.h
e
s 00001/00001/00290
d D 1.11 83/01/10 20:23:44 mckusick 11 10
c HZ goes from 60 to 100
e
s 00004/00003/00287
d D 1.10 83/01/10 20:17:43 mckusick 10 9
c ifdef VAX => ifdef ADDR32
e
s 00000/00003/00290
d D 1.9 82/02/03 00:00:50 mckusic 9 8
c get rid of panics, so that all signals and errors pass through ERROR()
e
s 00001/00000/00292
d D 1.8 82/02/02 14:22:39 linton 8 7
c added PDX constant
e
s 00003/00003/00289
d D 1.7 81/04/01 23:01:35 mckusic 7 6
c mods for dynamically allocated display save area for formal calls
e
s 00011/00006/00281
d D 1.6 81/03/06 23:02:02 mckusic 6 5
c add onyx code
e
s 00005/00001/00282
d D 1.5 81/01/26 17:02:18 mckusic 5 4
c change RV8, LRV8, and IND8 to use `struct' instead of `double' assignment
e
s 00001/00000/00282
d D 1.4 81/01/16 17:41:23 mckusic 4 3
c add runtime checking field to stack
e
s 00003/00001/00279
d D 1.3 81/01/16 12:55:00 mckusic 3 2
c add runtst and seed
e
s 00042/00048/00238
d D 1.2 81/01/10 18:25:16 mckusic 2 1
c add "ap" and "fp" notion, fix SUCC and PRED
e
s 00286/00000/00000
d D 1.1 81/01/07 16:56:19 mckusick 1 0
c date and time created 81/01/07 16:56:19 by mckusick
e
u
U
t
T
I 1
D 14
/* Copyright (c) 1979 Regents of the University of California */

/* static char sccsid[] = "%Z%%M% %I% %G%"; */
E 14
I 14
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 14

#include <stdio.h>

/*
 * px - Berkeley Pascal interpreter
 *
 * Version 4.0, January 1981
 *
 * Original version by Ken Thompson
 *
 * Substantial revisions by Bill Joy and Chuck Haley
 * November-December 1976
 *
 * Rewritten for VAX 11/780 by Kirk McKusick
 * Fall 1978
 *
 * Rewritten in ``C'' using libpc by Kirk McKusick
 * Winter 1981
 *
 * Px is described in detail in the "PX 4.0 Implementation Notes"
 * The source code for px is in several major pieces:
 *
 *	int.c		C main program which reads in interpreter code
 *	interp.c	Driver including main interpreter loop and
 *			the interpreter instructions grouped by their
 *			positions in the interpreter table.
D 9
 *	except.c	Handlers for interpreter specific errors not
 *			included in libpc.
E 9
 *	utilities.c	Interpreter exit, backtrace, and runtime statistics.
 *
 * In addition there are several headers defining mappings for panic
 * names into codes, and a definition of the interpreter transfer
 * table. These are made by the script make.ed1 in this directory and 
 * the routine opc.c from ${PASCALDIR}. (see the makefile for details)
 */
#define PXPFILE		"pmon.out"
#define	BITSPERBYTE	8
#define	BITSPERLONG	(BITSPERBYTE * sizeof(long))
D 11
#define HZ		60
E 11
I 11
#define HZ		100
E 11
D 6
#define	TRUE		1
#define	FALSE		0
E 6
D 12
#define	MAXLVL		20
E 12
#define NAMSIZ		76
#define MAXFILES	32
#define PREDEF		2
I 6
D 10
#ifdef VAX
E 10
I 10
#ifdef ADDR32
I 15
#ifndef tahoe
E 15
E 10
E 6
#define STDLVL		((struct iorec *)(0x7ffffff1))
#define GLVL		((struct iorec *)(0x7ffffff0))
I 15
#else tahoe
#define STDLVL		((struct iorec *)(0xbffffff1))
#define GLVL		((struct iorec *)(0xbffffff0))
#endif tahoe
E 15
I 6
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
E 6
#define FILNIL		((struct iorec *)(0))
#define INPUT		((struct iorec *)(&input))
#define OUTPUT		((struct iorec *)(&output))
#define ERR		((struct iorec *)(&_err))
#define	PX	0	/* normal run of px */
#define	PIX	1	/* load and go */
#define	PIPE	2	/* bootstrap via a pipe */
I 8
#define	PDX	3	/* invoked by the debugger "pdx" */
E 8
#define releq 0
D 2
#define relne 1
#define rellt 2
#define relgt 3
#define relle 4
#define relge 5
E 2
I 2
#define relne 2
#define rellt 4
#define relgt 6
#define relle 8
#define relge 10
I 6
typedef enum {FALSE, TRUE} bool;
E 6
E 2

/*
 * interrupt and allocation routines
 */
extern long createtime;
extern char *PALLOC();
extern char *malloc();
I 6
extern long time();
E 6
extern intr();
extern memsize();
D 9
extern except();
E 9
extern syserr();
extern liberr();

/*
D 5
 * stack routines
E 5
I 5
 * stack routines and structures
E 5
 */
I 5
struct sze8 {
	char element[8];
};
E 5
extern short pop2();
extern long pop4();
extern double pop8();
I 5
extern struct sze8 popsze8();
E 5
extern char *pushsp();

/*
 * emulated pc types
 */
union progcntr {
	char *cp;
	unsigned char *ucp;
	short *sp;
	unsigned short *usp;
	long *lp;
D 6
	double *dp;
E 6
I 6
	double *dbp;
E 6
	struct hdr *hdrp;
};

/*
 * THE RUNTIME DISPLAY
 *
 * The entries in the display point to the active static block marks.
 * The first entry in the display is for the global variables,
 * then the procedure or function at level one, etc.
 * Each display entry points to a stack frame as shown:
 *
 *		base of stack frame
 *		  ---------------
 *		  |		|
 *		  | block mark  |
 *		  |		|
D 2
 *		  ---------------  <-- display entry points here
 *		  |             |
E 2
I 2
 *		  ---------------  <-- display entry "stp" points here
 *		  |             |  <-- display entry "locvars" points here
E 2
 *		  |   local	|
 *		  |  variables  |
 *		  |		|
 *		  ---------------
 *		  |		|
 *		  |  expression |
 *		  |  temporary  |
 *		  |  storage	|
 *		  |		|
 *		  - - - - - - - -
 *
 * The information in the block mark is thus at positive offsets from
D 2
 * the display pointer entries while the local variables are at negative
 * offsets. The block mark actually consists of two parts. The first
 * part is created at CALL and the second at entry, i.e. BEGIN. Thus:
E 2
I 2
 * the display.stp pointer entries while the local variables are at negative
 * offsets from display.locvars. The block mark actually consists of
 * two parts. The first part is created at CALL and the second at entry,
 * i.e. BEGIN. Thus:
E 2
 *
 *		-------------------------
 *		|			|
 *		|  Saved lino		|
 *		|  Saved lc		|
 *		|  Saved dp		|
 *		|			|
 *		-------------------------
 *		|			|
 *		|  Saved (dp)		|
 *		|			|
D 2
 *		|  Current section name	|
 *		|   and entry line ptr	|
E 2
I 2
 *		|  Pointer to current 	|
 *		|   routine header info	|
E 2
 *		|			|
D 2
 *		|  Saved file name and	|
 *		|   file buffer ptr	|
E 2
I 2
 *		|  Saved value of	|
 *		|   "curfile"		|
E 2
 *		|			|
 *		|  Empty tos value	|
 *		|			|
 *		-------------------------
 */

/*
D 12
 * runtime display structure
 */
struct disp {
	char *locvars;		/* pointer to local variables */
	struct stack *stp;	/* pointer to local stack frame */
};

struct stack {
	char *tos;		/* pointer to top of stack frame */
	struct iorec *file;	/* pointer to active file name */
	struct hdr {
		long framesze;	/* number of bytes of local vars */
		long nargs;	/* number of bytes of arguments */
I 4
D 6
		short tests;	/* TRUE => perform runtime tests */
E 6
I 6
		bool tests;	/* TRUE => perform runtime tests */
E 6
E 4
		short offset;	/* offset of procedure in source file */
		char name[1];	/* name of active procedure */
	} *entry;
	struct disp odisp;	/* previous display value for this level */
	struct disp *dp;	/* pointer to active display entry */
	union progcntr pc;	/* previous location counter */
	long lino;		/* previous line number */
};

I 2
union disply {
	struct disp frame[MAXLVL];
	char *raw[2*MAXLVL];
};

E 2
/*
 * formal routine structure
 */
struct formalrtn {
D 7
	char		*entryaddr;
	long		cbn;
	struct disp	disp[2*MAXLVL];
E 7
I 7
	char		*fentryaddr;		/* formal entry point */
	long		fbn;			/* block number of function */
	struct disp	fdisp[ MAXLVL ];	/* saved at first passing */
E 7
};

/*
E 12
 * program variables
 */
D 2
extern struct disp	_display[MAXLVL];	/* runtime display */
extern struct disp	*_dp;			/* runtime display */
extern long		_lino;			/* current line number */
extern int		_argc;			/* number of passed args */
extern char		**_argv;		/* values of passed args */
extern long		_nodump;		/* 1 => no post mortum dump */
extern long		_mode;			/* execl by PX, PIPE, or PIX */
extern long		_stlim;			/* statement limit */
extern long		_stcnt;			/* statement count */
extern char		*_maxptr;		/* maximum valid pointer */
extern char		*_minptr;		/* minimum valid pointer */
extern long		*_pcpcount;		/* pointer to pxp buffer */
extern long		_cntrs;			/* number of counters */
extern long		_rtns;			/* number of routine cntrs */

E 2
I 2
D 12
extern union disply	_display;	/* runtime display */
extern struct disp	*_dp;		/* ptr to active frame */
E 12
I 12
extern union display	_display;	/* runtime display */
extern struct dispsave	*_dp;		/* ptr to active frame */
E 12
extern long		_lino;		/* current line number */
extern int		_argc;		/* number of passed args */
extern char		**_argv;	/* values of passed args */
D 3
extern long		_nodump;	/* 1 => no post mortum dump */
E 3
I 3
D 6
extern long		_nodump;	/* TRUE => no post mortum dump */
extern long		_runtst;	/* TRUE => runtime tests */
E 6
I 6
extern bool		_nodump;	/* TRUE => no post mortum dump */
D 12
extern bool		_runtst;	/* TRUE => runtime tests */
E 12
I 12
extern long		_runtst;	/* TRUE => runtime tests */
E 12
E 6
E 3
extern long		_mode;		/* execl by PX, PIPE, or PIX */
extern long		_stlim;		/* statement limit */
extern long		_stcnt;		/* statement count */
I 3
extern long		_seed;		/* random number seed */
E 3
extern char		*_maxptr;	/* maximum valid pointer */
extern char		*_minptr;	/* minimum valid pointer */
extern long		*_pcpcount;	/* pointer to pxp buffer */
extern long		_cntrs;		/* number of counters */
extern long		_rtns;		/* number of routine cntrs */

E 2
/*
 * The file i/o routines maintain a notion of a "current file".
 * A pointer to this file structure is kept in "curfile".
 *
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
	short		fblk;		/* index into active file table */
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
	short		fblk;		/* index into active file table */
	long		fsize;		/* size of elements in the file */
	char		fname[NAMSIZ];	/* name of associated UNIX file */
	char		buf[BUFSIZ];	/* I/O buffer */
	char		window[1];	/* file window element */
};
D 2

E 2
I 2

E 2
/*
 * unit flags
 */
#define	FDEF	0x80	/* 1 => reserved file name */
#define	FTEXT	0x40	/* 1 => text file, process EOLN */
#define	FWRITE	0x20	/* 1 => open for writing */
#define	FREAD	0x10	/* 1 => open for reading */
#define	TEMP	0x08	/* 1 => temporary file */
#define	SYNC	0x04	/* 1 => window is out of sync */
#define	EOLN	0x02	/* 1 => at end of line */
#define	EOFF	0x01	/* 1 => at end of file */

/*
 * file routines
 */
extern struct iorec	*GETNAME();
extern char		*MKTEMP();

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
D 2

#ifdef profile
E 2
I 2

E 2
/*
D 2
 * Px execution profile data
E 2
I 2
 * Px execution profile array
E 2
 */
D 2
#define	numops 256
struct cntrec {
	double	counts[numops];	/* instruction counts */
	long	runs;		/* number of interpreter runs */
	long	startdate;	/* date profile started */
	long	usrtime;	/* total user time consumed */
	long	systime;	/* total system time consumed */
	double	stmts;		/* number of pascal statements executed */
	} profdata;
long	profcnts[numops];
#define	proffile	"/usr/grad/mckusick/px/profile/pcnt.out"
FILE	*datafile;		/* input datafiles */
#else
int	profcnts;	/* dummy just to keep the linker happy */
#endif
E 2
I 2
#ifdef PROFILE
#define	NUMOPS 256
extern long _profcnts[NUMOPS];
#endif PROFILE
E 2
E 1
