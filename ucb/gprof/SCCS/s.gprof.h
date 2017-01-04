h35695
s 00010/00005/00277
d D 5.6 88/06/29 19:23:11 bostic 28 27
c install approved copyright notice
e
s 00008/00002/00274
d D 5.5 88/05/05 17:50:12 bostic 27 26
c add Berkeley specific header; written by K. McKusick and P. Kessler
e
s 00021/00003/00255
d D 5.4 88/01/02 23:47:31 bostic 26 25
c ANSI C doesn't allow combining a modifier with a typedef; neither K&R
c or ANSI C allow untyped function declarations
e
s 00003/00000/00255
d D 5.3 87/04/27 17:30:50 mckusick 25 24
c add -k to allow selective deletion of arcs
e
s 00005/00002/00250
d D 5.2 86/01/07 00:00:53 sam 24 23
c add tahoe; CALLSDEBUG -> CALLDEBUG (so folks won't think they must redefine)
e
s 00007/00001/00245
d D 5.1 85/06/04 13:31:14 dist 23 22
c Add copyright
e
s 00002/00002/00244
d D 1.21 84/08/09 13:34:20 mckusick 22 21
c shorten name of blurb file
e
s 00001/00001/00245
d D 1.20 84/08/07 11:26:36 mckusick 21 20
c doarcs() now returns pointer to sorted list for gprof print function to use
e
s 00001/00001/00245
d D 1.19 83/08/11 22:36:43 sam 20 19
c standardize sccs keyword lines
e
s 00000/00001/00246
d D 1.18 83/06/10 23:40:57 sam 19 18
c purge pagsiz.h
e
s 00009/00023/00238
d D 1.17 83/03/30 20:48:41 peter 18 17
c pull vax-dependent stuff to vax.h;  add aligned entry point field to nl.
e
s 00003/00003/00258
d D 1.16 83/01/15 13:14:49 peter 17 16
c make the names of the blurb files more reasonable;
c and distribute them less around the code.
e
s 00002/00000/00259
d D 1.15 83/01/15 12:47:42 peter 16 15
c catch detached strongly-connected components.
c [this is only part of a change that is needed
c to make dfn() do the real tarjan algorithm.]
e
s 00001/00001/00258
d D 1.14 83/01/11 15:05:59 peter 15 14
c sampling frequency changes from a constant to a variable.
e
s 00019/00001/00240
d D 1.13 82/06/18 20:22:09 peter 14 13
c -e -E -f and -F flags, this time for sure.
e
s 00022/00017/00219
d D 1.12 82/06/14 18:08:47 peter 13 12
c -f and -e flags.
e
s 00043/00040/00193
d D 1.11 82/06/08 11:29:09 peter 12 11
c cycle headers have their own namelist.
e
s 00006/00000/00227
d D 1.10 81/11/12 15:08:14 mckusic 11 10
c put blurb in /usr/lib
e
s 00001/00011/00226
d D 1.9 81/11/12 14:48:43 mckusic 10 9
c "gmcrt0" becomes "gcrt0"; eliminate stdio in gcrt0.c
e
s 00003/00001/00234
d D 1.8 81/11/11 21:53:32 mckusic 9 8
c add the -s option to summarize multiple runs
e
s 00007/00002/00228
d D 1.7 81/11/10 22:07:53 peter 8 6
c add the -b option to print a blurb about the listings.
e
s 00006/00002/00228
d R 1.7 81/11/10 21:04:59 peter 7 6
c add the -b option to print a blurb about the listings.
e
s 00004/00002/00226
d D 1.6 81/11/10 12:20:22 peter 6 5
c adding -a flag to find statically declared functions;
c and simultaneously throwing out pascal labels.
e
s 00073/00004/00155
d D 1.5 81/11/09 13:58:44 peter 5 4
c lint.
e
s 00003/00001/00156
d D 1.4 81/11/06 17:26:33 peter 4 3
c stash low and high pc from gmon.out for range check in findcalls().
e
s 00005/00001/00152
d D 1.3 81/11/02 14:32:14 peter 3 2
c gather and use static call graph from a.out file.
e
s 00007/00007/00146
d D 1.2 81/10/20 15:49:29 peter 2 1
c name change to confuse to innocent/
e
s 00153/00000/00000
d D 1.1 81/10/15 13:46:54 peter 1 0
c date and time created 81/10/15 13:46:54 by peter
e
u
U
t
T
I 1
D 20
    /* sccsid:  %W% (Berkeley) %G% */
E 20
I 20
D 23
/*	%M%	%I%	%E%	*/
E 23
I 23
/*
 * Copyright (c) 1983 Regents of the University of California.
D 27
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 27
I 27
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 28
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 28
I 28
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
E 28
E 27
 *
 *	%W% (Berkeley) %G%
 */
E 23
E 20

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <a.out.h>
D 19
#include <pagsiz.h>
E 19
D 9
#include "monitor.h"
E 9
I 9
D 10
#include "gmcrt0.h"
E 10
I 10
#include "gcrt0.h"
E 10
E 9

I 18
#if vax
#   include "vax.h"
#endif
#if sun
D 24
#    include "sun.h"
E 24
I 24
#   include "sun.h"
E 24
#endif
I 24
#if tahoe
#   include "tahoe.h"
#endif
E 24


E 18
    /*
I 12
     *	who am i, for error messages.
     */
char	*whoami;

    /*
I 13
     * booleans
     */
typedef int	bool;
#define	FALSE	0
#define	TRUE	1

    /*
D 18
     *	opcode of the `calls' instruction
     */
#define	CALLS	0xfb

    /*
E 18
E 13
E 12
     *	ticks per second
     */
D 15
#define	HZ	60
E 15
I 15
long	hz;
E 15

D 26
typedef	short UNIT;		/* unit of profiling */
E 26
I 26
typedef	u_short UNIT;		/* unit of profiling */
E 26
char	*a_outname;
#define	A_OUTNAME		"a.out"

D 2
char	*dmonname;
#define	DMONNAME		"dmon.out"
E 2
I 2
char	*gmonname;
#define	GMONNAME		"gmon.out"
I 9
#define	GMONSUM			"gmon.sum"
I 11
D 26
	
E 26
I 26

E 26
    /*
D 17
     *	the directory where the descriptions of the fields
     *	of the profiles are kept.
E 17
I 17
     *	blurbs on the flat and graph profiles.
E 17
     */
D 17
#define	BLURBLIB		"/usr/lib/"
E 17
I 17
D 22
#define	FLAT_BLURB	"/usr/lib/gprof.flat.blurb"
#define	CALLG_BLURB	"/usr/lib/gprof.callg.blurb"
E 22
I 22
#define	FLAT_BLURB	"/usr/lib/gprof.flat"
#define	CALLG_BLURB	"/usr/lib/gprof.callg"
E 22
E 17
E 11
E 9
E 2

    /*
     *	a constructed arc,
     *	    with pointers to the namelist entry of the parent and the child,
     *	    a count of how many times this arc was traversed,
     *	    and pointers to the next parent of this child and
     *		the next child of this parent.
     */
struct arcstruct {
    struct nl		*arc_parentp;	/* pointer to parent's nl entry */
    struct nl		*arc_childp;	/* pointer to child's nl entry */
    long		arc_count;	/* how calls from parent to child */
    double		arc_time;	/* time inherited along arc */
    double		arc_childtime;	/* childtime inherited along arc */
    struct arcstruct	*arc_parentlist; /* parents-of-this-child list */
    struct arcstruct	*arc_childlist;	/* children-of-this-parent list */
};
typedef struct arcstruct	arctype;

D 10
    /*
     *	a raw arc,
     *	    with pointers to the calling site and the called site
     *	    and a count.
     */
struct rawarc {
    unsigned long	raw_frompc;
    unsigned long	raw_selfpc;
    long		raw_count;
};
E 10
D 12
/*
 * The symbol table;
 * for each external in the specified file we gather
 * its address, the number of calls and compute its share of cpu time.
 */
E 12
I 12
    /*
     * The symbol table;
     * for each external in the specified file we gather
     * its address, the number of calls and compute its share of cpu time.
     */
E 12
struct nl {
D 12
	char		*name;		/* the name */
	unsigned long	value;		/* the pc entry point */
	double		time;		/* ticks in this routine */
D 2
	double		childtime;	/* cumulative ticks in dynamic childs */
E 2
I 2
	double		childtime;	/* cumulative ticks in children */
E 2
	long		ncall;		/* how many times called */
	long		selfcalls;	/* how many calls to self */
D 2
	int		index;		/* index in the dynamic list */
	int		toporder;	/* dynamic call chain top-sort order */
E 2
I 2
	int		index;		/* index in the graph list */
	int		toporder;	/* graph call chain top-sort order */
E 2
	int		cycleno;	/* internal number of cycle on */
	struct nl	*cyclehead;	/* pointer to head of cycle */
	struct nl	*cnext;		/* pointer to next member of cycle */
	arctype		*parents;	/* list of caller arcs */
	arctype		*children;	/* list of callee arcs */
E 12
I 12
    char		*name;		/* the name */
    unsigned long	value;		/* the pc entry point */
I 18
    unsigned long	svalue;		/* entry point aligned to histograms */
E 18
    double		time;		/* ticks in this routine */
    double		childtime;	/* cumulative ticks in children */
    long		ncall;		/* how many times called */
    long		selfcalls;	/* how many calls to self */
I 14
    double		propfraction;	/* what % of time propagates */
    double		propself;	/* how much self time propagates */
    double		propchild;	/* how much child time propagates */
E 14
I 13
    bool		printflag;	/* should this be printed? */
E 13
    int			index;		/* index in the graph list */
    int			toporder;	/* graph call chain top-sort order */
    int			cycleno;	/* internal number of cycle on */
    struct nl		*cyclehead;	/* pointer to head of cycle */
    struct nl		*cnext;		/* pointer to next member of cycle */
    arctype		*parents;	/* list of caller arcs */
    arctype		*children;	/* list of callee arcs */
E 12
};
typedef struct nl	nltype;

nltype	*nl;			/* the whole namelist */
nltype	*npe;			/* the virtual end of the namelist */
D 12
int		nname;			/* the number of function names */
E 12
I 12
int	nname;			/* the number of function names */
E 12

    /*
     *	flag which marks a nl entry as topologically ``busy''
I 16
     *	flag which marks a nl entry as topologically ``not_numbered''
E 16
     */
#define	DFN_BUSY	-1
I 16
#define	DFN_NAN		0
E 16

    /* 
D 12
     *	the number of cycles is estimated as this fraction of nnames
     *	ncycles, the number of allocated cycle namelist entries,
     *	not to be confused with cyclemax, the number of discovered cycles.
E 12
I 12
     *	namelist entries for cycle headers.
     *	the number of discovered cycles.
E 12
     */
D 12
#define	CYCLEFRACTION	( 0.10 )
int	ncycles;		/* maximum allocated cycle headers */
int	cyclemax;		/* number of cycles discovered */
E 12
I 12
nltype	*cyclenl;		/* cycle header namelist */
int	ncycle;			/* number of cycles discovered */
E 12

D 12
/*
D 2
 * The header on the dmon.out file.
 * dmon.out consists of one of these headers,
E 2
I 2
 * The header on the gmon.out file.
 * gmon.out consists of one of these headers,
E 2
 * and then an array of ncnt samples
 * representing the discretized program counter values.
 *	this should be a struct phdr, but since everything is done
 *	as UNITs, this is in UNITs too.
 */
E 12
I 12
    /*
     * The header on the gmon.out file.
     * gmon.out consists of one of these headers,
     * and then an array of ncnt samples
     * representing the discretized program counter values.
     *	this should be a struct phdr, but since everything is done
     *	as UNITs, this is in UNITs too.
     */
E 12
struct hdr {
D 12
	UNIT	*lowpc;
	UNIT	*highpc;
	int	ncnt;
E 12
I 12
    UNIT	*lowpc;
    UNIT	*highpc;
    int	ncnt;
E 12
};

struct hdr	h;

int	debug;

D 12
/*
 * Each discretized pc sample has
 * a count of the number of samples in its range
 */
E 12
I 12
    /*
     * Each discretized pc sample has
     * a count of the number of samples in its range
     */
E 12
D 26
unsigned UNIT	*samples;
E 26
I 26
UNIT	*samples;
E 26

D 4
unsigned lowpc, highpc;		/* range profiled */
E 4
I 4
unsigned long	s_lowpc;	/* lowpc from the profile file */
unsigned long	s_highpc;	/* highpc from the profile file */
unsigned lowpc, highpc;		/* range profiled, in UNIT's */
E 4
unsigned sampbytes;		/* number of bytes of samples */
int	nsamples;		/* number of samples */
double	actime;			/* accumulated time thus far for putprofline */
double	totime;			/* total time for all routines */
I 13
double	printtime;		/* total of time being printed */
E 13
double	scale;			/* scale factor converting samples to pc
				   values: each sample covers scale bytes */
char	*strtab;		/* string table in core */
off_t	ssiz;			/* size of the string table */
struct	exec xbuf;		/* exec header of a.out */
I 3
unsigned char	*textspace;		/* text space of a.out in core */
E 3

D 6
int	zflg;
I 3
int	cflag;
E 6
I 6
D 8
int	zflg;				/* zero time/called functions, too */
int	cflag;				/* discovered call graph, too */
E 8
I 8
    /*
     *	option flags, from a to z.
     */
E 8
D 13
int	aflag;				/* static functions, too */
I 8
int	bflag;				/* blurbs, too */
int	cflag;				/* discovered call graph, too */
I 9
int	sflag;				/* sum multiple gmon.out files */
E 9
int	zflag;				/* zero time/called functions, too */
E 8
E 6
E 3

    /*
     * booleans
     */
typedef int	bool;
#define	FALSE	0
#define	TRUE	1

D 5
int	timecmp();
int	valcmp();
int	totalcmp();
E 5
I 5
    /*
     *	opcode of the `calls' instruction
     */
#define	CALLS	0xfb
E 13
I 13
bool	aflag;				/* suppress static functions */
bool	bflag;				/* blurbs, too */
bool	cflag;				/* discovered call graph, too */
bool	dflag;				/* debugging options */
bool	eflag;				/* specific functions excluded */
I 14
bool	Eflag;				/* functions excluded with time */
E 14
bool	fflag;				/* specific functions requested */
I 14
bool	Fflag;				/* functions requested with time */
I 25
bool	kflag;				/* arcs to be deleted */
E 25
E 14
bool	sflag;				/* sum multiple gmon.out files */
bool	zflag;				/* zero time/called functions, too */
E 13
E 5

D 5
nltype	*nllookup();
E 5
I 5
    /*
I 14
     *	structure for various string lists
     */
struct stringlist {
    struct stringlist	*next;
    char		*string;
};
struct stringlist	*elist;
struct stringlist	*Elist;
struct stringlist	*flist;
struct stringlist	*Flist;
I 25
struct stringlist	*kfromlist;
struct stringlist	*ktolist;
E 25
D 18

    /*
E 14
     *	register for pc relative addressing
     */
#define	PC	0xf

enum opermodes {
    literal, indexed, reg, regdef, autodec, autoinc, autoincdef, 
    bytedisp, bytedispdef, worddisp, worddispdef, longdisp, longdispdef,
    immediate, absolute, byterel, bytereldef, wordrel, wordreldef,
    longrel, longreldef
};
typedef enum opermodes	operandenum;

struct modebyte {
    unsigned int	regfield:4;
    unsigned int	modefield:4;
};
E 18

    /*
     *	function declarations
     */
I 26
/*
E 26
		addarc();
I 26
*/
E 26
int		arccmp();
E 5
arctype		*arclookup();
I 26
/*
E 26
I 5
		asgnsamples();
I 8
		printblurb();
E 8
		cyclelink();
		dfn();
I 26
*/
E 26
E 5
bool		dfn_busy();
I 26
/*
E 26
I 5
		dfn_findcycle();
I 26
*/
E 26
bool		dfn_numbered();
I 26
/*
E 26
		dfn_post_visit();
		dfn_pre_visit();
		dfn_self_cycle();
I 26
*/
E 26
D 21
		doarcs();
E 21
I 21
nltype		**doarcs();
I 26
/*
E 26
E 21
		done();
		findcalls();
		flatprofheader();
		flatprofline();
I 26
*/
E 26
I 6
bool		funcsymbol();
I 26
/*
E 26
E 6
		getnfile();
		getpfile();
		getstrtab();
		getsymtab();
		gettextspace();
		gprofheader();
		gprofline();
		main();
I 26
*/
E 26
unsigned long	max();
int		membercmp();
unsigned long	min();
nltype		*nllookup();
FILE		*openpfile();
long		operandlength();
operandenum	operandmode();
char		*operandname();
I 26
/*
E 26
		printchildren();
		printcycle();
		printgprof();
		printmembers();
		printname();
		printparents();
		printprof();
		readsamples();
I 26
*/
E 26
unsigned long	reladdr();
I 26
/*
E 26
		sortchildren();
		sortmembers();
		sortparents();
		tally();
		timecmp();
		topcmp();
I 26
*/
E 26
int		totalcmp();
I 26
/*
E 26
		valcmp();
I 26
*/
E 26
E 5

#define	LESSTHAN	-1
#define	EQUALTO		0
#define	GREATERTHAN	1

#define	DFNDEBUG	1
#define	CYCLEDEBUG	2
#define	ARCDEBUG	4
#define	TALLYDEBUG	8
#define	TIMEDEBUG	16
#define	SAMPLEDEBUG	32
#define	AOUTDEBUG	64
D 3
#define	ANYDEBUG	128
E 3
I 3
D 24
#define	CALLSDEBUG	128
E 24
I 24
#define	CALLDEBUG	128
E 24
#define	LOOKUPDEBUG	256
D 14
#define	ANYDEBUG	512
E 14
I 14
#define	PROPDEBUG	512
#define	ANYDEBUG	1024
E 14
E 3
E 1
