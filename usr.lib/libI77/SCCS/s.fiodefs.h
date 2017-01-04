h59282
s 00001/00000/00149
d D 5.2 85/07/30 16:40:18 jerry 7 6
c implement namelist
e
s 00007/00001/00142
d D 5.1 85/06/07 23:36:45 kre 6 5
c Add copyright
e
s 00001/00001/00142
d D 1.4 85/05/02 22:10:06 libs 5 3
c max unit number now 100.
e
s 00001/00000/00143
d R 1.4 85/02/14 22:22:53 libs 4 3
c Print reserved operand as '****' instead of getting interrupt.
e
s 00002/00002/00141
d D 1.3 83/04/25 17:09:09 dlw 3 2
c changed default to be BOF on open. DLW
e
s 00008/00000/00135
d D 1.2 83/04/25 01:30:39 dlw 2 1
c added ioiflg_ definition. DLW
e
s 00135/00000/00000
d D 1.1 81/02/18 18:02:21 dlw 1 0
c date and time created 81/02/18 18:02:21 by dlw
e
u
U
t
T
I 1
/*
D 6
char id_fiodefs[] = "%W%";
E 6
I 6
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 6
 *
I 6
 *	%W% (Berkeley) %G%
 */

/*
E 6
 * fortran file i/o type definitions
 */

#include <stdio.h>
#include "f_errno.h"

/* Logical Unit Table Size */
D 5
#define MXUNIT _NFILE
E 5
I 5
#define MXUNIT 100
E 5

#define GLITCH '\2'	/* special quote for Stu, generated in f77pass1 */

I 7
#define NAMELIST      -2
E 7
#define LISTDIRECTED  -1
#define FORMATTED      1

#define ERROR	1
#define OK	0
#define YES	1
#define NO	0

#define STDERR	0
#define STDIN	5
#define STDOUT	6

#define WRITE	1
#define READ	2
#define SEQ	3
#define DIR	4
#define FMT	5
#define UNF	6
#define EXT	7
#define INT	8

typedef char ioflag;
typedef long ftnint;
typedef ftnint flag;
typedef long ftnlen;

typedef struct		/*external read, write*/
{	flag cierr;
	ftnint ciunit;
	flag ciend;
	char *cifmt;
	ftnint cirec;
} cilist;

typedef struct		/*internal read, write*/
{	flag icierr;
	char *iciunit;
	flag iciend;
	char *icifmt;
	ftnint icirlen;
	ftnint icirnum;
	ftnint icirec;
} icilist;

typedef struct		/*open*/
{	flag oerr;
	ftnint ounit;
	char *ofnm;
	ftnlen ofnmlen;
	char *osta;
	char *oacc;
	char *ofm;
	ftnint orl;
	char *oblnk;
} olist;

typedef struct		/*close*/
{	flag cerr;
	ftnint cunit;
	char *csta;
} cllist;

typedef struct		/*rewind, backspace, endfile*/
{	flag aerr;
	ftnint aunit;
} alist;

typedef struct		/*units*/
{	FILE *ufd;	/*0=unconnected*/
	char *ufnm;
	long uinode;
	int url;	/*0=sequential*/
	flag useek;	/*true=can backspace, use dir, ...*/
	flag ufmt;
	flag uprnt;
	flag ublnk;
	flag uend;
	flag uwrt;	/*last io was write*/
	flag uscrtch;
} unit;

typedef struct		/* inquire */
{	flag inerr;
	ftnint inunit;
	char *infile;
	ftnlen infilen;
	ftnint	*inex;	/*parameters in standard's order*/
	ftnint	*inopen;
	ftnint	*innum;
	ftnint	*innamed;
	char	*inname;
	ftnlen	innamlen;
	char	*inacc;
	ftnlen	inacclen;
	char	*inseq;
	ftnlen	inseqlen;
	char 	*indir;
	ftnlen	indirlen;
	char	*inform;
	ftnlen	informlen;
	char	*infmt;
	ftnint	infmtlen;
	char	*inunf;
	ftnlen	inunflen;
	ftnint	*inrecl;
	ftnint	*innrec;
	char	*inblank;
	ftnlen	inblanklen;
} inlist;

typedef union
{	float pf;
	double pd;
} ufloat;

typedef union
{	short is;
	char ic;
	long il;
} uint;

I 2
struct ioiflg {
D 3
	short if_obof;
E 3
I 3
	short if_oeof;
E 3
	short if_ctrl;
	short if_bzro;
};
D 3
#define	opnbof	ioiflg_.if_obof
E 3
I 3
#define	opneof	ioiflg_.if_oeof
E 3
#define	ccntrl	ioiflg_.if_ctrl
#define	blzero	ioiflg_.if_bzro
E 2
E 1
