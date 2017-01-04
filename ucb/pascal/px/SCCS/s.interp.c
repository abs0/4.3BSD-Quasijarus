h30284
s 00004/00004/01830
d D 5.5 86/11/12 19:56:45 mckusick 38 37
c disable debugging
e
s 00103/00068/01731
d D 5.4 86/11/12 19:24:33 mckusick 37 36
c add machine specific macros for extracting inline data to support CCI (tahoe)
e
s 00020/00005/01779
d D 5.3 85/09/18 23:50:01 mckusick 36 35
c fix up inline expansions
e
s 00000/00000/01784
d D 5.2 85/06/05 14:10:04 dist 35 34
c Add copyright
e
s 00008/00002/01776
d D 5.1 85/06/05 13:51:02 dist 34 33
c Add copyright
e
s 00000/00000/01778
d D 2.1 84/02/08 20:29:43 aoki 33 32
c synchronize to version 2
e
s 00052/00001/01726
d D 1.31 84/02/08 00:57:47 mckusick 32 31
c merge conformant array code of Carol Nishizak
e
s 00035/00069/01692
d D 1.30 83/02/09 13:58:06 mckusick 31 30
c hoist range checks out of loops
e
s 00009/00009/01752
d D 1.29 83/02/09 12:19:27 mckusick 30 29
c fix reversed "real" operators
e
s 00197/00107/01564
d D 1.28 83/01/22 01:31:26 mckusick 29 28
c for loop shadow variables now take on the type of the actual variable
c name changes to confuse the innocent
c pop all args before doing math ops since they may need to use the stack
e
s 00001/00001/01670
d D 1.27 83/01/07 12:37:55 mckusick 28 27
c fix PUSH
e
s 00001/00001/01670
d D 1.26 82/11/16 12:35:22 mckusick 27 26
c type cast missing...
e
s 00023/00023/01648
d D 1.25 82/11/14 18:03:47 mckusick 26 25
c NEWZ becomes NEW+blkclr; ASRT becomes ASRTS; blkclr/blkcpy 
c take size last to be compatable with bzero/bcopy
e
s 00016/00008/01655
d D 1.24 82/08/29 16:37:50 mckusick 25 24
c add disposal of dynamic files
e
s 00002/00002/01661
d D 1.23 82/08/26 23:57:06 mckusick 24 23
c convert "assert" from being a reserved word to being a non-standard procedure
e
s 00001/00001/01662
d D 1.22 82/07/28 16:07:26 mckusick 23 22
c fix "input" initialization
e
s 00001/00000/01662
d D 1.21 82/02/16 23:56:08 linton 22 21
c added a PFLUSH prior to zero byte in processing BPT op, 
c this way all output will be out whenever the debugger is entered.
e
s 00016/00000/01646
d D 1.20 82/02/08 21:10:24 mckusic 21 20
c add runtime checking for sin, cos, atan, and exp
e
s 00014/00010/01632
d D 1.19 82/02/03 00:01:07 mckusic 20 19
c get rid of panics, so that all signals and errors pass through ERROR()
e
s 00003/00003/01639
d D 1.18 82/02/02 16:05:55 mckusic 19 18
c convert CASEOP* to use CASERNG instead of explicit error message
e
s 00015/00000/01627
d D 1.17 82/02/02 13:32:30 linton 18 17
c added some hooks for pdx
e
s 00055/00061/01572
d D 1.16 81/07/22 19:14:14 mckusic 17 16
c modify semantics of FOR to reflect shadowing of for loop vars in longs
e
s 00009/00005/01624
d D 1.15 81/07/15 15:58:41 mckusic 16 15
c rmdel -r1.13
e
s 00004/00005/01625
d D 1.14 81/06/10 01:44:15 mckusic 15 14
c change over to new error message format
e
s 00008/00010/01622
d D 1.13 81/06/08 00:43:39 mckusic 14 13
c put display save area back into formal routine structure
e
s 00019/00014/01613
d D 1.12 81/04/01 23:02:00 mckusic 13 12
c mods for dynamically allocated display save area for formal calls
e
s 00001/00014/01626
d D 1.11 81/03/18 12:19:52 mckusic 12 11
c mods to FCALL protocol
e
s 00006/00022/01634
d D 1.10 81/03/10 00:36:41 mckusic 11 10
c onyx optimizations
e
s 00196/00157/01460
d D 1.9 81/03/06 22:58:59 mckusic 10 9
c add onyx code
e
s 00001/00001/01616
d D 1.8 81/02/04 15:39:28 mckusic 9 8
c align O_RV, run pc2 after /lib/c2
e
s 00014/00007/01603
d D 1.7 81/01/26 17:02:38 mckusic 8 7
c change RV8, LRV8, and IND8 to use `struct' instead of `double' assignment
e
s 00003/00003/01607
d D 1.6 81/01/26 12:02:48 mckusic 7 6
c fix bug in CASE error message data
e
s 00001/00002/01609
d D 1.5 81/01/24 15:19:01 mckusic 6 5
c change BEG header size info
e
s 00169/00049/01442
d D 1.4 81/01/16 18:51:03 mckusic 5 4
c Update FOR*, add runtime tests
e
s 00002/00003/01489
d D 1.3 81/01/13 12:14:30 mckusic 4 2
c fix O_STLIM to use library function STLIM
e
s 00003/00004/01488
d R 1.3 81/01/13 12:09:41 mckusic 3 2
c fix STLIM to use library function
e
s 00098/00095/01394
d D 1.2 81/01/10 18:24:17 mckusic 2 1
c add "ap" and "fp" notion, fix SUCC and PRED
e
s 01489/00000/00000
d D 1.1 81/01/07 16:55:12 mckusick 1 0
c date and time created 81/01/07 16:55:12 by mckusick
e
u
U
t
T
I 1
D 34
/* Copyright (c) 1979 Regents of the University of California */
E 34
I 34
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 34

D 34
static char sccsid[] = "%Z%%M% %I% %G%";
E 34
I 34
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 34

#include <math.h>
I 29
#include <signal.h>
E 29
I 10
#include "whoami.h"
D 29
#include "objfmt.h"
E 29
E 10
#include "vars.h"
I 29
#include "objfmt.h"
E 29
D 20
#include "panics.h"
E 20
#include "h02opcs.h"
#include "machdep.h"
D 15
#include "h01errs.h"
E 15
#include "libpc.h"

D 2
/* debugging variables */
char opc[10];
long opcptr = 9;

E 2
/*
 * program variables
 */
D 2
struct disp	_display[MAXLVL];
E 2
I 2
D 29
union disply	_display;
E 2
struct disp	*_dp;
E 29
I 29
union display _display;
struct dispsave	*_dp;
E 29
long	_lino = 0;
int	_argc;
char	**_argv;
long	_mode;
D 5
long	_nodump;
E 5
I 5
D 10
long	_runtst = TRUE;
long	_nodump = FALSE;
E 10
I 10
D 29
bool	_runtst = TRUE;
E 29
I 29
long	_runtst = (long)TRUE;
E 29
bool	_nodump = FALSE;
E 10
E 5
long	_stlim = 500000;
long	_stcnt = 0;
I 5
long	_seed = 1;
I 10
D 29
#ifdef VAX
E 29
I 29
#ifdef ADDR32
E 29
E 10
E 5
char	*_minptr = (char *)0x7fffffff;
I 10
D 29
#else
E 29
I 29
#endif ADDR32
#ifdef ADDR16
E 29
char	*_minptr = (char *)0xffff;
D 29
#endif VAX
E 29
I 29
#endif ADDR16
E 29
E 10
char	*_maxptr = (char *)0;
long	*_pcpcount = (long *)0;
long	_cntrs = 0;
long	_rtns = 0;

/*
D 10
 * file record variables
 */
long		_filefre = PREDEF;
struct iorechd	_fchain = {
	0, 0, 0, 0,		/* only use fchain field */
	INPUT			/* fchain  */
};
struct iorec	*_actfile[MAXFILES] = {
	INPUT,
	OUTPUT,
	ERR
};

/*
E 10
 * standard files
 */
char		_inwin, _outwin, _errwin;
D 10
struct iorechd	input = {
	&_inwin,		/* fileptr */
E 10
I 10
struct iorechd	_err = {
	&_errwin,		/* fileptr */
E 10
	0,			/* lcount  */
	0x7fffffff,		/* llimit  */
D 10
	&_iob[0],		/* fbuf    */
	OUTPUT,			/* fchain  */
E 10
I 10
	&_iob[2],		/* fbuf    */
	FILNIL,			/* fchain  */
E 10
	STDLVL,			/* flev    */
D 10
	"standard input",	/* pfname  */
	FTEXT | FREAD | SYNC,	/* funit   */
	0,			/* fblk    */
E 10
I 10
	"Message file",		/* pfname  */
	FTEXT | FWRITE | EOFF,	/* funit   */
	2,			/* fblk    */
E 10
	1			/* fsize   */
};
struct iorechd	output = {
	&_outwin,		/* fileptr */
	0,			/* lcount  */
	0x7fffffff,		/* llimit  */
	&_iob[1],		/* fbuf    */
	ERR,			/* fchain  */
	STDLVL,			/* flev    */
	"standard output",	/* pfname  */
	FTEXT | FWRITE | EOFF,	/* funit   */
	1,			/* fblk    */
	1			/* fsize   */
};
D 10
struct iorechd	_err = {
	&_errwin,		/* fileptr */
E 10
I 10
struct iorechd	input = {
	&_inwin,		/* fileptr */
E 10
	0,			/* lcount  */
	0x7fffffff,		/* llimit  */
D 10
	&_iob[2],		/* fbuf    */
	FILNIL,			/* fchain  */
E 10
I 10
	&_iob[0],		/* fbuf    */
	OUTPUT,			/* fchain  */
E 10
	STDLVL,			/* flev    */
D 10
	"Message file",		/* pfname  */
	FTEXT | FWRITE | EOFF,	/* funit   */
	2,			/* fblk    */
E 10
I 10
	"standard input",	/* pfname  */
D 23
	FTEXT | FREAD | SYNC,	/* funit   */
E 23
I 23
	FTEXT|FREAD|SYNC|EOLN,	/* funit   */
E 23
	0,			/* fblk    */
E 10
	1			/* fsize   */
};

I 2
/*
I 10
 * file record variables
 */
long		_filefre = PREDEF;
struct iorechd	_fchain = {
	0, 0, 0, 0,		/* only use fchain field */
	INPUT			/* fchain  */
};
struct iorec	*_actfile[MAXFILES] = {
	INPUT,
	OUTPUT,
	ERR
};

/*
I 18
 * stuff for pdx
 */

union progcntr *pcaddrp;
asm(".globl _loopaddr");

/*
E 18
E 10
 * Px profile array
 */
#ifdef PROFILE
long _profcnts[NUMOPS];
#endif PROFILE

/*
 * debugging variables
 */
D 38
#ifdef DEBUG
E 38
I 38
#ifdef PXDEBUG
E 38
char opc[10];
long opcptr = 9;
D 38
#endif DEBUG
E 38
I 38
#endif PXDEBUG
E 38

E 2
interpreter(base)
	char *base;
{
	union progcntr pc;		/* interpreted program cntr */
	register char *vpc;		/* register used for "pc" */
	struct iorec *curfile;		/* active file */
D 29
	register struct stack *stp;	/* active stack frame ptr */
E 29
I 29
	register struct blockmark *stp;	/* active stack frame ptr */
E 29
	/*
	 * the following variables are used as scratch
	 */
D 8
	double td, td1;
E 8
I 8
	register char *tcp;
I 29
	register short *tsp;
E 29
E 8
D 37
	register long tl, tl1, tl2;
E 37
I 37
	register long tl, tl1, tl2, tl3;
E 37
I 8
	double td, td1;
	struct sze8 t8;
I 29
	register short *tsp1;
E 29
E 8
D 32
	long *tlp;
E 32
I 32
D 37
	long *tlp, tl3;
E 37
I 37
	long *tlp;
E 37
E 32
D 10
	short *tsp, *tsp1;
E 10
I 10
D 29
	register short *tsp, *tsp1, ts;
	bool tb;
E 29
E 10
D 8
	register char *tcp;
E 8
	char *tcp1;
D 29
	struct stack *tstp;
	struct formalrtn *tfp;
E 29
I 29
	bool tb;
	struct blockmark *tstp;
	register struct formalrtn *tfp;
E 29
	union progcntr tpc;
	struct iorec **ip;
I 31
	int mypid;
E 31

I 18
	pcaddrp = &pc;
I 31
	mypid = getpid();
E 31

E 18
	/*
I 8
	 * Setup sets up any hardware specific parameters before
	 * starting the interpreter. Typically this is inline replaced
	 * by interp.sed to utilize specific machine instructions.
	 */
	 setup();
	/*
E 8
	 * necessary only on systems which do not initialize
	 * memory to zero
	 */
	for (ip = &_actfile[3]; ip < &_actfile[MAXFILES]; *ip++ = FILNIL)
		/* void */;
	/*
	 * set up global environment, then ``call'' the main program
	 */
D 2
	_display[0].locvars = pushsp(2 * sizeof(struct iorec *));
	*(struct iorec **)(_display[0].locvars + 4) = OUTPUT;
	*(struct iorec **)(_display[0].locvars) = INPUT;
	_display[0].locvars += 8;	/* >>> kludge <<< */
	asm("	bispsw	$0xe0");	/* enable overflow traps */
E 2
I 2
D 10
	_display.frame[0].locvars = pushsp(2 * sizeof(struct iorec *));
	_display.frame[0].locvars += 8;	/* local offsets are negative */
	*(struct iorec **)(_display.frame[0].locvars - 4) = OUTPUT;
	*(struct iorec **)(_display.frame[0].locvars - 8) = INPUT;
D 5
	enableovrflo();
E 5
E 2
	stp = (struct stack *)pushsp(sizeof(struct stack));
E 10
I 10
D 37
	_display.frame[0].locvars = pushsp((long)(2 * sizeof(struct iorec *)));
E 37
I 37
	STACKALIGN(tl, 2 * sizeof(struct iorec *));
	_display.frame[0].locvars = pushsp(tl);
E 37
	_display.frame[0].locvars += 2 * sizeof(struct iorec *);
	*(struct iorec **)(_display.frame[0].locvars + OUTPUT_OFF) = OUTPUT;
	*(struct iorec **)(_display.frame[0].locvars + INPUT_OFF) = INPUT;
D 29
	stp = (struct stack *)pushsp((long)(sizeof(struct stack)));
E 29
I 29
D 37
	stp = (struct blockmark *)pushsp((long)(sizeof(struct blockmark)));
E 37
I 37
	STACKALIGN(tl, sizeof(struct blockmark));
	stp = (struct blockmark *)pushsp(tl);
E 37
E 29
E 10
D 2
	_dp = &_display[0];
E 2
I 2
	_dp = &_display.frame[0];
E 2
	pc.cp = base;
I 18

	asm("_loopaddr:");
E 18
	for(;;) {
I 2
D 38
#		ifdef DEBUG
E 38
I 38
#		ifdef PXDEBUG
E 38
E 2
		if (++opcptr == 10)
			opcptr = 0;
		opc[opcptr] = *pc.ucp;
I 2
D 38
#		endif DEBUG
E 38
I 38
#		endif PXDEBUG
E 38
#		ifdef PROFILE
		_profcnts[*pc.ucp]++;
#		endif PROFILE
E 2
		switch (*pc.ucp++) {
I 18
		case O_BPT:			/* breakpoint trap */
I 22
			PFLUSH();
E 22
D 29
			asm(".byte 0");
E 29
I 29
D 31
			kill(getpid(), SIGILL);
E 31
I 31
			kill(mypid, SIGILL);
E 31
E 29
			pc.ucp--;
			continue;
E 18
D 10
		default:
			panic(PBADOP);
			continue;
E 10
		case O_NODUMP:
D 5
			_nodump++;
D 2
			asm("	bicpsw	$0xe0");/* disable overflow checks */
E 2
I 2
			disableovrflo();
E 5
I 5
			_nodump = TRUE;
E 5
E 2
			/* and fall through */
		case O_BEG:
			_dp += 1;		/* enter local scope */
			stp->odisp = *_dp;	/* save old display value */
			tl = *pc.ucp++;		/* tl = name size */
			stp->entry = pc.hdrp;	/* pointer to entry info */
D 2
			tl1 = -*pc.lp++;	/* tl1 = local variable size */
E 2
I 2
D 5
			tl1 = *pc.lp++;		/* tl1 = local variable size */
E 2
			pc.lp++;		/* skip over number of args */
			_lino = *pc.usp++;	/* set new lino */
			pc.cp += tl;		/* skip over name text */
E 5
I 5
			tl1 = pc.hdrp->framesze;/* tl1 = size of frame */
			_lino = pc.hdrp->offset;
			_runtst = pc.hdrp->tests;
			disableovrflo();
			if (_runtst)
				enableovrflo();
D 6
			pc.cp += tl +		/* skip over proc hdr info */
				 sizeof(struct hdr) - 4;
E 6
I 6
D 10
			pc.cp += tl;		/* skip over proc hdr info */
E 10
I 10
			pc.cp += (int)tl;	/* skip over proc hdr info */
E 10
E 6
E 5
			stp->file = curfile;	/* save active file */
D 37
			tcp = pushsp(tl1);	/* tcp = new top of stack */
E 37
I 37
			STACKALIGN(tl2, tl1);
			tcp = pushsp(tl2);	/* tcp = new top of stack */
E 37
D 10
			blkclr(tl1, tcp);	/* zero stack frame */
I 2
			tcp += tl1;		/* offsets of locals are neg */
E 10
I 10
			if (_runtst)		/* zero stack frame */
D 26
				blkclr(tl1, tcp);
E 26
I 26
				blkclr(tcp, tl1);
E 26
			tcp += (int)tl1;	/* offsets of locals are neg */
E 10
			_dp->locvars = tcp;	/* set new display pointer */
			_dp->stp = stp;
E 2
D 10
			stp->tos = pushsp(0);	/* set top of stack pointer */
E 10
I 10
			stp->tos = pushsp((long)0); /* set tos pointer */
E 10
D 2
			_dp->stp = stp;		/* set new display pointer */
			/* _dp->locvars = tcp; */
			_dp->locvars = (char *)stp; /* kludge, use prev line */
E 2
			continue;
		case O_END:
			PCLOSE(_dp->locvars);	/* flush & close local files */
			stp = _dp->stp;
			curfile = stp->file;	/* restore old active file */
			*_dp = stp->odisp;	/* restore old display entry */
D 2
			if (_dp == &_display[1])
E 2
I 2
			if (_dp == &_display.frame[1])
E 2
				return;		/* exiting main proc ??? */
			_lino = stp->lino;	/* restore lino, pc, dp */
D 29
			pc.cp = stp->pc.cp;
E 29
I 29
			pc.cp = stp->pc;
E 29
			_dp = stp->dp;
I 5
			_runtst = stp->entry->tests;
			disableovrflo();
			if (_runtst)
				enableovrflo();
E 5
D 2
			popsp(-stp->entry->framesze +	/* pop local vars */
E 2
I 2
D 37
			popsp(stp->entry->framesze +	/* pop local vars */
E 2
D 29
			      sizeof(struct stack) +	/* pop stack frame */
			      stp->entry->nargs);	/* pop parms */
E 29
I 29
			     sizeof(struct blockmark) +	/* pop stack frame */
			     stp->entry->nargs);	/* pop parms */
E 37
I 37
			STACKALIGN(tl, stp->entry->framesze);
			STACKALIGN(tl1, sizeof(struct blockmark));
			popsp(tl +		/* pop local vars */
			     tl1 +		/* pop stack frame */
			     stp->entry->nargs);/* pop parms */
E 37
E 29
			continue;
		case O_CALL:
			tl = *pc.cp++;
D 37
			tcp = base + *pc.lp++;/* calc new entry point */
			tcp += sizeof(short);
			tcp = base + *(long *)tcp;
D 10
			stp = (struct stack *)pushsp(sizeof(struct stack));
E 10
I 10
D 29
			stp = (struct stack *)
				pushsp((long)(sizeof(struct stack)));
E 29
I 29
			stp = (struct blockmark *)
				pushsp((long)(sizeof(struct blockmark)));
E 37
I 37
			PCLONGVAL(tl1);
			tcp = base + tl1 + sizeof(short);/* new entry point */
			GETLONGVAL(tl1, tcp);
			tcp = base + tl1;
			STACKALIGN(tl1, sizeof(struct blockmark));
			stp = (struct blockmark *)pushsp(tl1);
E 37
E 29
E 10
			stp->lino = _lino;	/* save lino, pc, dp */
D 29
			stp->pc.cp = pc.cp;
E 29
I 29
			stp->pc = pc.cp;
E 29
			stp->dp = _dp;
D 2
			_dp = &_display[tl];	/* set up new display ptr */
E 2
I 2
			_dp = &_display.frame[tl]; /* set up new display ptr */
E 2
			pc.cp = tcp;
			continue;
		case O_FCALL:
D 12
			tl = *pc.cp++;		/* tl = number of args */
			if (tl == 0)
				tl = *pc.lp++;
E 12
I 12
			pc.cp++;
I 16
 			tcp = popaddr(); /* ptr to display save area */
E 16
I 13
D 14
			tcp = popaddr(); /* ptr to display save area */
E 14
E 13
E 12
			tfp = (struct formalrtn *)popaddr();
D 10
			stp = (struct stack *)pushsp(sizeof(struct stack));
E 10
I 10
D 29
			stp = (struct stack *)
				pushsp((long)(sizeof(struct stack)));
E 29
I 29
D 37
			stp = (struct blockmark *)
				pushsp((long)(sizeof(struct blockmark)));
E 37
I 37
			STACKALIGN(tl, sizeof(struct blockmark));
			stp = (struct blockmark *)pushsp(tl);
E 37
E 29
E 10
			stp->lino = _lino;	/* save lino, pc, dp */
D 29
			stp->pc.cp = pc.cp;
E 29
I 29
			stp->pc = pc.cp;
E 29
			stp->dp = _dp;
D 13
			pc.cp = tfp->entryaddr;	/* calc new entry point */
D 5
			tpc.sp = pc.sp + 1;
			tl -= tpc.hdrp->nargs;
			if (tl != 0) {
				if (tl > 0)
					tl += sizeof(int) - 1;
				else
					tl -= sizeof(int) - 1;
				ERROR(ENARGS, tl / sizeof(int));
E 5
I 5
D 12
			if (_runtst) {
				tpc.sp = pc.sp + 1;
				tl -= tpc.hdrp->nargs;
				if (tl != 0) {
					if (tl > 0)
						tl += sizeof(int) - 1;
					else
						tl -= sizeof(int) - 1;
					ERROR(ENARGS, tl / sizeof(int));
				}
E 5
			}
E 12
D 2
			_dp = &_display[tfp->cbn];/* set up new display ptr */
E 2
I 2
			_dp = &_display.frame[tfp->cbn];/* new display ptr */
E 2
D 10
			blkcpy(sizeof(struct disp) * tfp->cbn,
E 10
I 10
			blkcpy(tfp->cbn * sizeof(struct disp),
E 10
D 2
				&_display[1], &tfp->disp[tfp->cbn]);
E 2
I 2
				&_display.frame[1], &tfp->disp[tfp->cbn]);
E 2
D 10
			blkcpy(sizeof(struct disp) * tfp->cbn,
E 10
I 10
			blkcpy(tfp->cbn * sizeof(struct disp),
E 10
D 2
				&tfp->disp[0], &_display[1]);
E 2
I 2
				&tfp->disp[0], &_display.frame[1]);
E 13
I 13
D 29
			pc.cp = tfp->fentryaddr;/* calc new entry point */
E 29
I 29
			pc.cp = (char *)(tfp->fentryaddr);/* new entry point */
E 29
			_dp = &_display.frame[tfp->fbn];/* new display ptr */
D 26
			blkcpy(tfp->fbn * sizeof(struct disp),
D 14
				&_display.frame[1], tcp);
E 14
I 14
D 16
				&_display.frame[1], &tfp->fdisp[tfp->fbn]);
E 16
I 16
 				&_display.frame[1], tcp);
E 16
E 14
			blkcpy(tfp->fbn * sizeof(struct disp),
				&tfp->fdisp[0], &_display.frame[1]);
E 26
I 26
 			blkcpy(&_display.frame[1], tcp,
D 29
				tfp->fbn * sizeof(struct disp));
E 29
I 29
				tfp->fbn * sizeof(struct dispsave));
E 29
			blkcpy(&tfp->fdisp[0], &_display.frame[1],
D 29
				tfp->fbn * sizeof(struct disp));
E 29
I 29
				tfp->fbn * sizeof(struct dispsave));
E 29
E 26
E 13
E 2
			continue;
		case O_FRTN:
			tl = *pc.cp++;		/* tl = size of return obj */
			if (tl == 0)
				tl = *pc.usp++;
D 10
			tcp = pushsp(0);
E 10
I 10
			tcp = pushsp((long)(0));
E 10
			tfp = *(struct formalrtn **)(tcp + tl);
I 16
 			tcp1 = *(char **)
 			    (tcp + tl + sizeof(struct formalrtn *));
E 16
D 13
			blkcpy(tl, tcp, tcp + sizeof(struct formalrtn *));
D 10
			popsp(sizeof(struct formalrtn *));
			blkcpy(sizeof(struct disp) * tfp->cbn,
E 10
I 10
			popsp((long)(sizeof(struct formalrtn *)));
			blkcpy(tfp->cbn * sizeof(struct disp),
E 10
D 2
				&tfp->disp[tfp->cbn], &_display[1]);
E 2
I 2
				&tfp->disp[tfp->cbn], &_display.frame[1]);
E 13
I 13
D 14
			tcp1 = *(char **)
			    (tcp + tl + sizeof(struct formalrtn *));
			blkcpy(tl, tcp,
			    tcp + sizeof(struct formalrtn *) + sizeof(char *));
			popsp((long)
			    (sizeof(struct formalrtn *) + sizeof (char *)));
E 14
I 14
			if (tl != 0) {
D 16
				blkcpy(tl, tcp,
				    tcp + sizeof(struct formalrtn *));
E 16
I 16
D 26
				blkcpy(tl, tcp, tcp + sizeof(struct formalrtn *)
				    + sizeof(char *));
E 26
I 26
				blkcpy(tcp, tcp + sizeof(struct formalrtn *)
				    + sizeof(char *), tl);
E 26
E 16
			}
D 16
			popsp((long)(sizeof(struct formalrtn *)));
E 16
I 16
D 37
 			popsp((long)
 			    (sizeof(struct formalrtn *) + sizeof (char *)));
E 37
I 37
			STACKALIGN(tl,
				sizeof(struct formalrtn *) + sizeof (char *));
 			popsp(tl);
E 37
E 16
E 14
D 26
			blkcpy(tfp->fbn * sizeof(struct disp),
D 14
			    tcp1, &_display.frame[1]);
E 14
I 14
D 16
			    &tfp->fdisp[tfp->fbn], &_display.frame[1]);
E 16
I 16
 			    tcp1, &_display.frame[1]);
E 26
I 26
 			blkcpy(tcp1, &_display.frame[1],
D 29
			    tfp->fbn * sizeof(struct disp));
E 29
I 29
			    tfp->fbn * sizeof(struct dispsave));
E 29
E 26
E 16
E 14
E 13
E 2
			continue;
		case O_FSAV:
			tfp = (struct formalrtn *)popaddr();
D 13
			tfp->cbn = *pc.cp++;	/* blk number of routine */
E 13
I 13
			tfp->fbn = *pc.cp++;	/* blk number of routine */
E 13
D 14
			tcp = base + *pc.lp++;/* calc new entry point */
E 14
I 14
D 37
			tcp = base + *pc.lp++;	/* calc new entry point */
E 14
			tcp += sizeof(short);
D 13
			tfp->entryaddr = base + *(long *)tcp;
D 10
			blkcpy(sizeof(struct disp) * tfp->cbn,
E 10
I 10
			blkcpy(tfp->cbn * sizeof(struct disp),
E 10
D 2
				&_display[1], &tfp->disp[0]);
E 2
I 2
				&_display.frame[1], &tfp->disp[0]);
E 13
I 13
D 29
			tfp->fentryaddr = base + *(long *)tcp;
E 29
I 29
			tfp->fentryaddr = (long (*)())(base + *(long *)tcp);
E 37
I 37
			PCLONGVAL(tl);
			tcp = base + tl + sizeof(short);/* new entry point */
			GETLONGVAL(tl, tcp);
			tfp->fentryaddr = (long (*)())(base + tl);
E 37
E 29
D 26
			blkcpy(tfp->fbn * sizeof(struct disp),
				&_display.frame[1], &tfp->fdisp[0]);
E 26
I 26
			blkcpy(&_display.frame[1], &tfp->fdisp[0],
D 29
				tfp->fbn * sizeof(struct disp));
E 29
I 29
				tfp->fbn * sizeof(struct dispsave));
E 29
E 26
E 13
E 2
			pushaddr(tfp);
			continue;
		case O_SDUP2:
			pc.cp++;
			tl = pop2();
D 10
			push2(tl);
			push2(tl);
E 10
I 10
			push2((short)(tl));
			push2((short)(tl));
E 10
			continue;
		case O_SDUP4:
			pc.cp++;
			tl = pop4();
			push4(tl);
			push4(tl);
			continue;
		case O_TRA:
			pc.cp++;
			pc.cp += *pc.sp;
			continue;
		case O_TRA4:
			pc.cp++;
D 37
			pc.cp = base + *pc.lp;
E 37
I 37
			PCLONGVAL(tl);
			pc.cp = base + tl;
E 37
			continue;
		case O_GOTO:
D 2
			tstp = _display[*pc.cp++].stp; /* ptr to exit frame */
E 2
I 2
			tstp = _display.frame[*pc.cp++].stp; /* ptr to
								exit frame */
E 2
D 37
			pc.cp = base + *pc.lp;
E 37
I 37
			PCLONGVAL(tl);
			pc.cp = base + tl;
E 37
			stp = _dp->stp;
			while (tstp != stp) {
D 2
				if (_dp == &_display[1])
E 2
I 2
				if (_dp == &_display.frame[1])
E 2
D 15
					ERROR(EGOTO); /* exiting prog ??? */
E 15
I 15
					ERROR("Active frame not found in non-local goto\n", 0); /* exiting prog ??? */
E 15
				PCLOSE(_dp->locvars); /* close local files */
				curfile = stp->file;  /* restore active file */
				*_dp = stp->odisp;    /* old display entry */
				_dp = stp->dp;	      /* restore dp */
				stp = _dp->stp;
			}
			/* pop locals, stack frame, parms, and return values */
D 10
			popsp(stp->tos - pushsp(0));
E 10
I 10
			popsp((long)(stp->tos - pushsp((long)(0))));
E 10
			continue;
		case O_LINO:
D 10
			if (_dp->stp->tos != pushsp(0))
E 10
I 10
			if (_dp->stp->tos != pushsp((long)(0)))
E 10
D 20
				panic(PSTKNEMP);
E 20
I 20
				ERROR("Panic: stack not empty between statements\n");
E 20
			_lino = *pc.cp++;	/* set line number */
			if (_lino == 0)
				_lino = *pc.sp++;
D 10
			LINO();			/* inc statement count */
E 10
I 10
			if (_runtst) {
				LINO();		/* inc statement count */
				continue;
			}
			_stcnt++;
E 10
			continue;
		case O_PUSH:
			tl = *pc.cp++;
			if (tl == 0)
D 28
				tl = *pc.usp++;
E 28
I 28
D 37
				tl = *pc.lp++;
E 28
			tl = (-tl + 1) & ~1;
			tcp = pushsp(tl);
E 37
I 37
				PCLONGVAL(tl);
			STACKALIGN(tl1, -tl);
			tcp = pushsp(tl1);
E 37
D 10
			blkclr(tl, tcp);
E 10
I 10
			if (_runtst)
D 26
				blkclr(tl, tcp);
E 26
I 26
D 37
				blkclr(tcp, tl);
E 37
I 37
				blkclr(tcp, tl1);
E 37
E 26
E 10
			continue;
		case O_IF:
			pc.cp++;
D 5
			if (pop2())
E 5
I 5
			if (pop2()) {
E 5
				pc.sp++;
D 5
			else
				pc.cp += *pc.sp;
E 5
I 5
				continue;
			}
			pc.cp += *pc.sp;
E 5
			continue;
		case O_REL2:
			tl = pop2();
			tl1 = pop2();
			goto cmplong;
		case O_REL24:
			tl = pop2();
			tl1 = pop4();
			goto cmplong;
		case O_REL42:
			tl = pop4();
			tl1 = pop2();
			goto cmplong;
		case O_REL4:
			tl = pop4();
			tl1 = pop4();
		cmplong:
D 20
			tl2 = *pc.cp++;
			switch (tl2) {
E 20
I 20
			switch (*pc.cp++) {
E 20
			case releq:
				push2(tl1 == tl);
				continue;
			case relne:
				push2(tl1 != tl);
				continue;
			case rellt:
				push2(tl1 < tl);
				continue;
			case relgt:
				push2(tl1 > tl);
				continue;
			case relle:
				push2(tl1 <= tl);
				continue;
			case relge:
				push2(tl1 >= tl);
				continue;
			default:
D 20
				panic(PSYSTEM);
E 20
I 20
				ERROR("Panic: bad relation %d to REL4*\n",
				    *(pc.cp - 1));
E 20
				continue;
			}
		case O_RELG:
			tl2 = *pc.cp++;		/* tc has jump opcode */
			tl = *pc.usp++;		/* tl has comparison length */
D 37
			tl1 = (tl + 1) & ~1;	/* tl1 has arg stack length */
E 37
I 37
			STACKALIGN(tl1, tl);	/* tl1 has arg stack length */
E 37
D 10
			tcp = pushsp(0);	/* tcp pts to first arg */
E 10
I 10
			tcp = pushsp((long)(0));/* tcp pts to first arg */
E 10
			switch (tl2) {
			case releq:
D 10
				tl = RELEQ(tl, tcp + tl1, tcp);
E 10
I 10
				tb = RELEQ(tl, tcp + tl1, tcp);
E 10
				break;
			case relne:
D 10
				tl = RELNE(tl, tcp + tl1, tcp);
E 10
I 10
				tb = RELNE(tl, tcp + tl1, tcp);
E 10
				break;
			case rellt:
D 10
				tl = RELSLT(tl, tcp + tl1, tcp);
E 10
I 10
				tb = RELSLT(tl, tcp + tl1, tcp);
E 10
				break;
			case relgt:
D 10
				tl = RELSGT(tl, tcp + tl1, tcp);
E 10
I 10
				tb = RELSGT(tl, tcp + tl1, tcp);
E 10
				break;
			case relle:
D 10
				tl = RELSLE(tl, tcp + tl1, tcp);
E 10
I 10
				tb = RELSLE(tl, tcp + tl1, tcp);
E 10
				break;
			case relge:
D 10
				tl = RELSGE(tl, tcp + tl1, tcp);
E 10
I 10
				tb = RELSGE(tl, tcp + tl1, tcp);
E 10
				break;
			default:
D 20
				panic(PSYSTEM);
E 20
I 20
				ERROR("Panic: bad relation %d to RELG*\n", tl2);
E 20
				break;
			}
			popsp(tl1 << 1);
D 10
			push2(tl);
E 10
I 10
			push2((short)(tb));
E 10
			continue;
		case O_RELT:
			tl2 = *pc.cp++;		/* tc has jump opcode */
			tl1 = *pc.usp++;	/* tl1 has comparison length */
D 10
			tcp = pushsp(0);	/* tcp pts to first arg */
E 10
I 10
			tcp = pushsp((long)(0));/* tcp pts to first arg */
E 10
			switch (tl2) {
			case releq:
D 10
				tl = RELEQ(tl1, tcp + tl1, tcp);
E 10
I 10
				tb = RELEQ(tl1, tcp + tl1, tcp);
E 10
				break;
			case relne:
D 10
				tl = RELNE(tl1, tcp + tl1, tcp);
E 10
I 10
				tb = RELNE(tl1, tcp + tl1, tcp);
E 10
				break;
			case rellt:
D 10
				tl = RELTLT(tl1, tcp + tl1, tcp);
E 10
I 10
				tb = RELTLT(tl1, tcp + tl1, tcp);
E 10
				break;
			case relgt:
D 10
				tl = RELTGT(tl1, tcp + tl1, tcp);
E 10
I 10
				tb = RELTGT(tl1, tcp + tl1, tcp);
E 10
				break;
			case relle:
D 10
				tl = RELTLE(tl1, tcp + tl1, tcp);
E 10
I 10
				tb = RELTLE(tl1, tcp + tl1, tcp);
E 10
				break;
			case relge:
D 10
				tl = RELTGE(tl1, tcp + tl1, tcp);
E 10
I 10
				tb = RELTGE(tl1, tcp + tl1, tcp);
E 10
				break;
			default:
D 20
				panic(PSYSTEM);
E 20
I 20
				ERROR("Panic: bad relation %d to RELT*\n", tl2);
E 20
				break;
			}
D 37
			popsp(tl1 << 1);
E 37
I 37
			STACKALIGN(tl, tl1);
			popsp(tl << 1);
E 37
D 10
			push2(tl);
E 10
I 10
			push2((short)(tb));
E 10
			continue;
		case O_REL28:
			td = pop2();
			td1 = pop8();
			goto cmpdbl;
		case O_REL48:
			td = pop4();
			td1 = pop8();
			goto cmpdbl;
		case O_REL82:
			td = pop8();
			td1 = pop2();
			goto cmpdbl;
		case O_REL84:
			td = pop8();
			td1 = pop4();
			goto cmpdbl;
		case O_REL8:
			td = pop8();
			td1 = pop8();
		cmpdbl:
			switch (*pc.cp++) {
			case releq:
				push2(td1 == td);
				continue;
			case relne:
				push2(td1 != td);
				continue;
			case rellt:
				push2(td1 < td);
				continue;
			case relgt:
				push2(td1 > td);
				continue;
			case relle:
				push2(td1 <= td);
				continue;
			case relge:
				push2(td1 >= td);
				continue;
			default:
D 20
				panic(PSYSTEM);
E 20
I 20
				ERROR("Panic: bad relation %d to REL8*\n",
				    *(pc.cp - 1));
E 20
				continue;
			}
		case O_AND:
			pc.cp++;
D 29
			push2(pop2() & pop2());
E 29
I 29
			tl = pop2();
			tl1 = pop2();
D 30
			push2(tl & tl1);
E 30
I 30
			push2(tl1 & tl);
E 30
E 29
			continue;
		case O_OR:
			pc.cp++;
D 29
			push2(pop2() | pop2());
E 29
I 29
			tl = pop2();
			tl1 = pop2();
D 30
			push2(tl | tl1);
E 30
I 30
			push2(tl1 | tl);
E 30
E 29
			continue;
		case O_NOT:
			pc.cp++;
D 29
			push2(pop2() ^ 1);
E 29
I 29
			tl = pop2();
			push2(tl ^ 1);
E 29
			continue;
		case O_AS2:
			pc.cp++;
			tl = pop2();
			*(short *)popaddr() = tl;
			continue;
		case O_AS4:
			pc.cp++;
			tl = pop4();
			*(long *)popaddr() = tl;
			continue;
		case O_AS24:
			pc.cp++;
			tl = pop2();
			*(long *)popaddr() = tl;
			continue;
		case O_AS42:
			pc.cp++;
			tl = pop4();
			*(short *)popaddr() = tl;
			continue;
		case O_AS21:
			pc.cp++;
			tl = pop2();
			*popaddr() = tl;
			continue;
		case O_AS41:
			pc.cp++;
			tl = pop4();
			*popaddr() = tl;
			continue;
		case O_AS28:
			pc.cp++;
			tl = pop2();
			*(double *)popaddr() = tl;
			continue;
		case O_AS48:
			pc.cp++;
			tl = pop4();
			*(double *)popaddr() = tl;
			continue;
		case O_AS8:
			pc.cp++;
D 8
			td = pop8();
			*(double *)popaddr() = td;
E 8
I 8
			t8 = popsze8();
			*(struct sze8 *)popaddr() = t8;
E 8
			continue;
		case O_AS:
			tl = *pc.cp++;
			if (tl == 0)
				tl = *pc.usp++;
D 37
			tl1 = (tl + 1) & ~1;
E 37
I 37
			STACKALIGN(tl1, tl);
E 37
D 10
			tcp = pushsp(0);
E 10
I 10
			tcp = pushsp((long)(0));
E 10
D 26
			blkcpy(tl, tcp, *(char **)(tcp + tl1));
E 26
I 26
			blkcpy(tcp, *(char **)(tcp + tl1), tl);
E 26
			popsp(tl1 + sizeof(char *));
			continue;
I 32
		case O_VAS:
			pc.cp++;
			tl = pop4();
			tcp1 = popaddr();
			tcp = popaddr();
			blkcpy(tcp1, tcp, tl);
			continue;
E 32
		case O_INX2P2:
			tl = *pc.cp++;		/* tl has shift amount */
D 29
			tl1 = (pop2() - *pc.sp++) << tl;
			pushaddr(popaddr() + tl1);
E 29
I 29
			tl1 = pop2();
			tl1 = (tl1 - *pc.sp++) << tl;
			tcp = popaddr();
			pushaddr(tcp + tl1);
E 29
			continue;
		case O_INX4P2:
			tl = *pc.cp++;		/* tl has shift amount */
D 29
			tl1 = (pop4() - *pc.sp++) << tl;
			pushaddr(popaddr() + tl1);
E 29
I 29
			tl1 = pop4();
			tl1 = (tl1 - *pc.sp++) << tl;
			tcp = popaddr();
			pushaddr(tcp + tl1);
E 29
			continue;
		case O_INX2:
			tl = *pc.cp++;		/* tl has element size */
			if (tl == 0)
				tl = *pc.usp++;
			tl1 = pop2();		/* index */
			tl2 = *pc.sp++;
D 2
			SUBSC(tl1, tl2, tl2 + *pc.usp++); /* range check */
E 2
I 2
D 5
			SUBSC(tl1, tl2, *pc.usp++); /* range check */
E 5
E 2
D 29
			pushaddr(popaddr() + (tl1 - tl2) * tl);
E 29
I 29
			tcp = popaddr();
			pushaddr(tcp + (tl1 - tl2) * tl);
E 29
I 5
			tl = *pc.usp++;
			if (_runtst)
				SUBSC(tl1, tl2, tl); /* range check */
E 5
			continue;
		case O_INX4:
			tl = *pc.cp++;		/* tl has element size */
			if (tl == 0)
				tl = *pc.usp++;
			tl1 = pop4();		/* index */
			tl2 = *pc.sp++;
D 2
			SUBSC(tl1, tl2, tl2 + *pc.usp++); /* range check */
E 2
I 2
D 5
			SUBSC(tl1, tl2, *pc.usp++); /* range check */
E 5
E 2
D 29
			pushaddr(popaddr() + (tl1 - tl2) * tl);
E 29
I 29
			tcp = popaddr();
			pushaddr(tcp + (tl1 - tl2) * tl);
E 29
I 5
			tl = *pc.usp++;
			if (_runtst)
				SUBSC(tl1, tl2, tl); /* range check */
I 32
			continue;
		case O_VINX2:
			pc.cp++;
			tl = pop2();		/* tl has element size */
			tl1 = pop2();		/* upper bound */
			tl2 = pop2();		/* lower bound */
			tl3 = pop2();		/* index */
			tcp = popaddr();
			pushaddr(tcp + (tl3 - tl2) * tl);
			if (_runtst)
				SUBSC(tl3, tl2, tl1); /* range check */
			continue;
		case O_VINX24:
			pc.cp++;
			tl = pop2();		/* tl has element size */
			tl1 = pop2();		/* upper bound */
			tl2 = pop2();		/* lower bound */
			tl3 = pop4();		/* index */
			tcp = popaddr();
			pushaddr(tcp + (tl3 - tl2) * tl);
			if (_runtst)
				SUBSC(tl3, tl2, tl1); /* range check */
			continue;
		case O_VINX42:
			pc.cp++;
			tl = pop4();		/* tl has element size */
			tl1 = pop4();		/* upper bound */
			tl2 = pop4();		/* lower bound */
			tl3 = pop2();		/* index */
			tcp = popaddr();
			pushaddr(tcp + (tl3 - tl2) * tl);
			if (_runtst)
				SUBSC(tl3, tl2, tl1); /* range check */
			continue;
		case O_VINX4:
			pc.cp++;
			tl = pop4();		/* tl has element size */
			tl1 = pop4();		/* upper bound */
			tl2 = pop4();		/* lower bound */
			tl3 = pop4();		/* index */
			tcp = popaddr();
			pushaddr(tcp + (tl3 - tl2) * tl);
			if (_runtst)
				SUBSC(tl3, tl2, tl1); /* range check */
E 32
E 5
			continue;
		case O_OFF:
			tl = *pc.cp++;
			if (tl == 0)
				tl = *pc.usp++;
D 10
			push4(pop4() + tl);
E 10
I 10
D 29
			pushaddr(popaddr() + tl);
E 29
I 29
			tcp = popaddr();
			pushaddr(tcp + tl);
E 29
E 10
			continue;
		case O_NIL:
			pc.cp++;
D 36
			NIL();
E 36
I 36
			tcp = popaddr();
			NIL(tcp);
			pushaddr(tcp);
E 36
			continue;
		case O_ADD2:
			pc.cp++;
D 10
			push4(pop2() + pop2());
E 10
I 10
D 29
			push4((long)(pop2() + pop2()));
E 29
I 29
			tl = pop2();
			tl1 = pop2();
			push4(tl1 + tl);
E 29
E 10
			continue;
		case O_ADD4:
			pc.cp++;
D 29
			push4(pop4() + pop4());
E 29
I 29
			tl = pop4();
			tl1 = pop4();
			push4(tl1 + tl);
E 29
			continue;
		case O_ADD24:
			pc.cp++;
			tl = pop2();
D 29
			push4(pop4() + tl);
E 29
I 29
			tl1 = pop4();
			push4(tl1 + tl);
E 29
			continue;
		case O_ADD42:
			pc.cp++;
			tl = pop4();
D 29
			push4(pop2() + tl);
E 29
I 29
			tl1 = pop2();
			push4(tl1 + tl);
E 29
			continue;
		case O_ADD28:
			pc.cp++;
			tl = pop2();
D 29
			push8(pop8() + tl);
E 29
I 29
			td = pop8();
			push8(td + tl);
E 29
			continue;
		case O_ADD48:
			pc.cp++;
			tl = pop4();
D 29
			push8(pop8() + tl);
E 29
I 29
			td = pop8();
			push8(td + tl);
E 29
			continue;
		case O_ADD82:
			pc.cp++;
			td = pop8();
D 29
			push8(pop2() + td);
E 29
I 29
			td1 = pop2();
			push8(td1 + td);
E 29
			continue;
		case O_ADD84:
			pc.cp++;
			td = pop8();
D 29
			push8(pop4() + td);
E 29
I 29
			td1 = pop4();
			push8(td1 + td);
E 29
			continue;
		case O_SUB2:
			pc.cp++;
			tl = pop2();
D 29
			push4(pop2() - tl);
E 29
I 29
			tl1 = pop2();
			push4(tl1 - tl);
E 29
			continue;
		case O_SUB4:
			pc.cp++;
			tl = pop4();
D 29
			push4(pop4() - tl);
E 29
I 29
			tl1 = pop4();
			push4(tl1 - tl);
E 29
			continue;
		case O_SUB24:
			pc.cp++;
			tl = pop2();
D 29
			push4(pop4() - tl);
E 29
I 29
			tl1 = pop4();
			push4(tl1 - tl);
E 29
			continue;
		case O_SUB42:
			pc.cp++;
			tl = pop4();
D 29
			push4(pop2() - tl);
E 29
I 29
			tl1 = pop2();
			push4(tl1 - tl);
E 29
			continue;
		case O_SUB28:
			pc.cp++;
			tl = pop2();
D 29
			push8(pop8() - tl);
E 29
I 29
			td = pop8();
			push8(td - tl);
E 29
			continue;
		case O_SUB48:
			pc.cp++;
			tl = pop4();
D 29
			push8(pop8() - tl);
E 29
I 29
			td = pop8();
			push8(td - tl);
E 29
			continue;
		case O_SUB82:
			pc.cp++;
			td = pop8();
D 29
			push8(pop2() - td);
E 29
I 29
			td1 = pop2();
			push8(td1 - td);
E 29
			continue;
		case O_SUB84:
			pc.cp++;
			td = pop8();
D 29
			push8(pop4() - td);
E 29
I 29
			td1 = pop4();
			push8(td1 - td);
E 29
			continue;
		case O_MUL2:
			pc.cp++;
D 10
			push4(pop2() * pop2());
E 10
I 10
D 29
			push4((long)(pop2() * pop2()));
E 29
I 29
			tl = pop2();
			tl1 = pop2();
			push4(tl1 * tl);
E 29
E 10
			continue;
		case O_MUL4:
			pc.cp++;
D 29
			push4(pop4() * pop4());
E 29
I 29
			tl = pop4();
			tl1 = pop4();
			push4(tl1 * tl);
E 29
			continue;
		case O_MUL24:
			pc.cp++;
			tl = pop2();
D 29
			push4(pop4() * tl);
E 29
I 29
			tl1 = pop4();
			push4(tl1 * tl);
E 29
			continue;
		case O_MUL42:
			pc.cp++;
			tl = pop4();
D 29
			push4(pop2() * tl);
E 29
I 29
			tl1 = pop2();
			push4(tl1 * tl);
E 29
			continue;
		case O_MUL28:
			pc.cp++;
			tl = pop2();
D 29
			push8(pop8() * tl);
E 29
I 29
			td = pop8();
			push8(td * tl);
E 29
			continue;
		case O_MUL48:
			pc.cp++;
			tl = pop4();
D 29
			push8(pop8() * tl);
E 29
I 29
			td = pop8();
			push8(td * tl);
E 29
			continue;
		case O_MUL82:
			pc.cp++;
			td = pop8();
D 29
			push8(pop2() * td);
E 29
I 29
			td1 = pop2();
			push8(td1 * td);
E 29
			continue;
		case O_MUL84:
			pc.cp++;
			td = pop8();
D 29
			push8(pop4() * td);
E 29
I 29
			td1 = pop4();
			push8(td1 * td);
E 29
			continue;
		case O_ABS2:
		case O_ABS4:
			pc.cp++;
			tl = pop4();
			push4(tl >= 0 ? tl : -tl);
			continue;
		case O_ABS8:
			pc.cp++;
			td = pop8();
			push8(td >= 0.0 ? td : -td);
			continue;
		case O_NEG2:
			pc.cp++;
D 10
			push4(-pop2());
E 10
I 10
			push4((long)(-pop2()));
E 10
			continue;
		case O_NEG4:
			pc.cp++;
			push4(-pop4());
			continue;
		case O_NEG8:
			pc.cp++;
			push8(-pop8());
			continue;
		case O_DIV2:
			pc.cp++;
			tl = pop2();
D 29
			push4(pop2() / tl);
E 29
I 29
			tl1 = pop2();
			push4(tl1 / tl);
E 29
			continue;
		case O_DIV4:
			pc.cp++;
			tl = pop4();
D 29
			push4(pop4() / tl);
E 29
I 29
			tl1 = pop4();
			push4(tl1 / tl);
E 29
			continue;
		case O_DIV24:
			pc.cp++;
			tl = pop2();
D 29
			push4(pop4() / tl);
E 29
I 29
			tl1 = pop4();
			push4(tl1 / tl);
E 29
			continue;
		case O_DIV42:
			pc.cp++;
			tl = pop4();
D 29
			push4(pop2() / tl);
E 29
I 29
			tl1 = pop2();
			push4(tl1 / tl);
E 29
			continue;
		case O_MOD2:
			pc.cp++;
			tl = pop2();
D 29
			push4(pop2() % tl);
E 29
I 29
			tl1 = pop2();
			push4(tl1 % tl);
E 29
			continue;
		case O_MOD4:
			pc.cp++;
			tl = pop4();
D 29
			push4(pop4() % tl);
E 29
I 29
			tl1 = pop4();
			push4(tl1 % tl);
E 29
			continue;
		case O_MOD24:
			pc.cp++;
			tl = pop2();
D 29
			push4(pop4() % tl);
E 29
I 29
			tl1 = pop4();
			push4(tl1 % tl);
E 29
			continue;
		case O_MOD42:
			pc.cp++;
			tl = pop4();
D 29
			push4(pop2() % tl);
E 29
I 29
			tl1 = pop2();
			push4(tl1 % tl);
E 29
			continue;
		case O_ADD8:
			pc.cp++;
D 29
			push8(pop8() + pop8());
E 29
I 29
			td = pop8();
			td1 = pop8();
D 30
			push8(td + td1);
E 30
I 30
			push8(td1 + td);
E 30
E 29
			continue;
		case O_SUB8:
			pc.cp++;
			td = pop8();
D 29
			push8(pop8() - td);
E 29
I 29
			td1 = pop8();
D 30
			push8(td - td1);
E 30
I 30
			push8(td1 - td);
E 30
E 29
			continue;
		case O_MUL8:
			pc.cp++;
D 29
			push8(pop8() * pop8());
E 29
I 29
			td = pop8();
			td1 = pop8();
D 30
			push8(td * td1);
E 30
I 30
			push8(td1 * td);
E 30
E 29
			continue;
		case O_DVD8:
			pc.cp++;
			td = pop8();
D 29
			push8(pop8() / td);
E 29
I 29
			td1 = pop8();
D 30
			push8(td / td1);
E 30
I 30
			push8(td1 / td);
E 30
E 29
			continue;
		case O_STOI:
			pc.cp++;
D 10
			push4(pop2());
E 10
I 10
			push4((long)(pop2()));
E 10
			continue;
		case O_STOD:
			pc.cp++;
			td = pop2();
			push8(td);
			continue;
		case O_ITOD:
			pc.cp++;
			td = pop4();
			push8(td);
			continue;
		case O_ITOS:
			pc.cp++;
D 10
			push2(pop4());
E 10
I 10
			push2((short)(pop4()));
E 10
			continue;
		case O_DVD2:
			pc.cp++;
			td = pop2();
D 29
			push8(pop2() / td);
E 29
I 29
			td1 = pop2();
			push8(td1 / td);
E 29
			continue;
		case O_DVD4:
			pc.cp++;
			td = pop4();
D 29
			push8(pop4() / td);
E 29
I 29
			td1 = pop4();
			push8(td1 / td);
E 29
			continue;
		case O_DVD24:
			pc.cp++;
			td = pop2();
D 29
			push8(pop4() / td);
E 29
I 29
			td1 = pop4();
			push8(td1 / td);
E 29
			continue;
		case O_DVD42:
			pc.cp++;
			td = pop4();
D 29
			push8(pop2() / td);
E 29
I 29
			td1 = pop2();
			push8(td1 / td);
E 29
			continue;
		case O_DVD28:
			pc.cp++;
			td = pop2();
D 29
			push8(pop8() / td);
E 29
I 29
			td1 = pop8();
			push8(td1 / td);
E 29
			continue;
		case O_DVD48:
			pc.cp++;
D 29
			td = pop4();
			push8(pop8() / td);
E 29
I 29
D 30
			td1 = pop4();
			td = pop8();
			push8(td / td1);
E 30
I 30
			td = pop4();
			td1 = pop8();
			push8(td1 / td);
E 30
E 29
			continue;
		case O_DVD82:
			pc.cp++;
			td = pop8();
D 29
			push8(pop2() / td);
E 29
I 29
			td1 = pop2();
			push8(td1 / td);
E 29
			continue;
		case O_DVD84:
			pc.cp++;
			td = pop8();
D 29
			push8(pop4() / td);
E 29
I 29
			td1 = pop4();
			push8(td1 / td);
E 29
			continue;
		case O_RV1:
D 2
			tcp = _display[*pc.ucp++].locvars;
E 2
I 2
			tcp = _display.raw[*pc.ucp++];
E 2
D 10
			push2(*(tcp + *pc.sp++));
E 10
I 10
			push2((short)(*(tcp + *pc.sp++)));
E 10
			continue;
		case O_RV14:
D 2
			tcp = _display[*pc.ucp++].locvars;
E 2
I 2
			tcp = _display.raw[*pc.ucp++];
E 2
D 10
			push4(*(tcp + *pc.sp++));
E 10
I 10
			push4((long)(*(tcp + *pc.sp++)));
E 10
			continue;
		case O_RV2:
D 2
			tcp = _display[*pc.ucp++].locvars;
E 2
I 2
			tcp = _display.raw[*pc.ucp++];
E 2
			push2(*(short *)(tcp + *pc.sp++));
			continue;
		case O_RV24:
D 2
			tcp = _display[*pc.ucp++].locvars;
E 2
I 2
			tcp = _display.raw[*pc.ucp++];
E 2
D 10
			push4(*(short *)(tcp + *pc.sp++));
E 10
I 10
			push4((long)(*(short *)(tcp + *pc.sp++)));
E 10
			continue;
		case O_RV4:
D 2
			tcp = _display[*pc.ucp++].locvars;
E 2
I 2
			tcp = _display.raw[*pc.ucp++];
E 2
			push4(*(long *)(tcp + *pc.sp++));
			continue;
		case O_RV8:
D 2
			tcp = _display[*pc.ucp++].locvars;
E 2
I 2
			tcp = _display.raw[*pc.ucp++];
E 2
D 8
			push8(*(double *)(tcp + *pc.sp++));
E 8
I 8
			pushsze8(*(struct sze8 *)(tcp + *pc.sp++));
E 8
			continue;
		case O_RV:
D 2
			tcp = _display[*pc.ucp++].locvars;
E 2
I 2
			tcp = _display.raw[*pc.ucp++];
E 2
			tcp += *pc.sp++;
			tl = *pc.usp++;
D 9
			tcp1 = pushsp(tl);
E 9
I 9
D 37
			tcp1 = pushsp((tl + 1) & ~1);
E 37
I 37
			STACKALIGN(tl1, tl);
			tcp1 = pushsp(tl1);
E 37
E 9
D 26
			blkcpy(tl, tcp, tcp1);
E 26
I 26
			blkcpy(tcp, tcp1, tl);
E 26
			continue;
		case O_LV:
D 2
			tcp = _display[*pc.ucp++].locvars;
E 2
I 2
			tcp = _display.raw[*pc.ucp++];
E 2
			pushaddr(tcp + *pc.sp++);
			continue;
		case O_LRV1:
D 2
			tcp = _display[*pc.ucp++].locvars;
E 2
I 2
			tcp = _display.raw[*pc.ucp++];
E 2
D 10
			push2(*(tcp + *pc.lp++));
E 10
I 10
D 37
			push2((short)(*(tcp + *pc.lp++)));
E 37
I 37
			PCLONGVAL(tl);
			push2((short)(*(tcp + tl)));
E 37
E 10
			continue;
		case O_LRV14:
D 2
			tcp = _display[*pc.ucp++].locvars;
E 2
I 2
			tcp = _display.raw[*pc.ucp++];
E 2
D 10
			push4(*(tcp + *pc.lp++));
E 10
I 10
D 37
			push4((long)(*(tcp + *pc.lp++)));
E 37
I 37
			PCLONGVAL(tl);
			push4((long)(*(tcp + tl)));
E 37
E 10
			continue;
		case O_LRV2:
D 2
			tcp = _display[*pc.ucp++].locvars;
E 2
I 2
			tcp = _display.raw[*pc.ucp++];
E 2
D 37
			push2(*(short *)(tcp + *pc.lp++));
E 37
I 37
			PCLONGVAL(tl);
			push2(*(short *)(tcp + tl));
E 37
			continue;
		case O_LRV24:
D 2
			tcp = _display[*pc.ucp++].locvars;
E 2
I 2
			tcp = _display.raw[*pc.ucp++];
E 2
D 10
			push4(*(short *)(tcp + *pc.lp++));
E 10
I 10
D 37
			push4((long)(*(short *)(tcp + *pc.lp++)));
E 37
I 37
			PCLONGVAL(tl);
			push4((long)(*(short *)(tcp + tl)));
E 37
E 10
			continue;
		case O_LRV4:
D 2
			tcp = _display[*pc.ucp++].locvars;
E 2
I 2
			tcp = _display.raw[*pc.ucp++];
E 2
D 37
			push4(*(long *)(tcp + *pc.lp++));
E 37
I 37
			PCLONGVAL(tl);
			push4(*(long *)(tcp + tl));
E 37
			continue;
		case O_LRV8:
D 2
			tcp = _display[*pc.ucp++].locvars;
E 2
I 2
			tcp = _display.raw[*pc.ucp++];
E 2
D 8
			push8(*(double *)(tcp + *pc.lp++));
E 8
I 8
D 37
			pushsze8(*(struct sze8 *)(tcp + *pc.lp++));
E 37
I 37
			PCLONGVAL(tl);
			pushsze8(*(struct sze8 *)(tcp + tl));
E 37
E 8
			continue;
		case O_LRV:
D 2
			tcp = _display[*pc.ucp++].locvars;
E 2
I 2
			tcp = _display.raw[*pc.ucp++];
E 2
D 10
			tcp += *pc.lp++;
E 10
I 10
D 37
			tcp += (int)*pc.lp++;
E 37
I 37
			PCLONGVAL(tl);
			tcp += tl;
E 37
E 10
			tl = *pc.usp++;
D 10
			tcp1 = pushsp(tl);
E 10
I 10
D 37
			tcp1 = pushsp((tl + 1) & ~1);
E 37
I 37
			STACKALIGN(tl1, tl);
			tcp1 = pushsp(tl1);
E 37
E 10
D 26
			blkcpy(tl, tcp, tcp1);
E 26
I 26
			blkcpy(tcp, tcp1, tl);
E 26
			continue;
		case O_LLV:
D 2
			tcp = _display[*pc.ucp++].locvars;
E 2
I 2
			tcp = _display.raw[*pc.ucp++];
E 2
D 37
			pushaddr(tcp + *pc.lp++);
E 37
I 37
			PCLONGVAL(tl);
			pushaddr(tcp + tl);
E 37
			continue;
		case O_IND1:
			pc.cp++;
D 10
			push2(*popaddr());
E 10
I 10
			push2((short)(*popaddr()));
E 10
			continue;
		case O_IND14:
			pc.cp++;
D 10
			push4(*popaddr());
E 10
I 10
			push4((long)(*popaddr()));
E 10
			continue;
		case O_IND2:
			pc.cp++;
			push2(*(short *)(popaddr()));
			continue;
		case O_IND24:
			pc.cp++;
D 10
			push4(*(short *)(popaddr()));
E 10
I 10
			push4((long)(*(short *)(popaddr())));
E 10
			continue;
		case O_IND4:
			pc.cp++;
			push4(*(long *)(popaddr()));
			continue;
		case O_IND8:
			pc.cp++;
D 8
			push8(*(double *)(popaddr()));
E 8
I 8
			pushsze8(*(struct sze8 *)(popaddr()));
E 8
			continue;
		case O_IND:
			tl = *pc.cp++;
			if (tl == 0)
				tl = *pc.usp++;
			tcp = popaddr();
D 37
			tcp1 = pushsp((tl + 1) & ~1);
E 37
I 37
			STACKALIGN(tl1, tl);
			tcp1 = pushsp(tl1);
E 37
D 26
			blkcpy(tl, tcp, tcp1);
E 26
I 26
			blkcpy(tcp, tcp1, tl);
E 26
			continue;
		case O_CON1:
D 10
			push2(*pc.cp++);
E 10
I 10
			push2((short)(*pc.cp++));
E 10
			continue;
		case O_CON14:
D 10
			push4(*pc.cp++);
E 10
I 10
			push4((long)(*pc.cp++));
E 10
			continue;
		case O_CON2:
			pc.cp++;
			push2(*pc.sp++);
			continue;
		case O_CON24:
			pc.cp++;
D 10
			push4(*pc.sp++);
E 10
I 10
			push4((long)(*pc.sp++));
E 10
			continue;
		case O_CON4:
			pc.cp++;
D 37
			push4(*pc.lp++);
E 37
I 37
			PCLONGVAL(tl);
			push4(tl);
E 37
			continue;
		case O_CON8:
			pc.cp++;
D 10
			push8(*pc.dp++);
E 10
I 10
D 37
			push8(*pc.dbp++);
E 37
I 37
			tcp = pushsp(sizeof(double));
			blkcpy(pc.cp, tcp, sizeof(double));
			pc.dbp++;
E 37
E 10
			continue;
		case O_CON:
			tl = *pc.cp++;
			if (tl == 0)
				tl = *pc.usp++;
D 37
			tl = (tl + 1) & ~1;
			tcp = pushsp(tl);
E 37
I 37
			STACKALIGN(tl1, tl);
			tcp = pushsp(tl1);
E 37
D 26
			blkcpy(tl, pc.cp, tcp);
E 26
I 26
			blkcpy(pc.cp, tcp, tl);
E 26
D 10
			pc.cp += tl;
E 10
I 10
			pc.cp += (int)tl;
E 10
			continue;
I 10
		case O_CONG:
			tl = *pc.cp++;
			if (tl == 0)
				tl = *pc.usp++;
D 37
			tl1 = (tl + 1) & ~1;
E 37
I 37
			STACKALIGN(tl1, tl);
E 37
			tcp = pushsp(tl1);
D 26
			blkcpy(tl1, pc.cp, tcp);
E 26
I 26
			blkcpy(pc.cp, tcp, tl1);
E 26
			pc.cp += (int)((tl + 2) & ~1);
			continue;
E 10
		case O_LVCON:
			tl = *pc.cp++;
			if (tl == 0)
				tl = *pc.usp++;
D 37
			tl = (tl + 1) & ~1;
E 37
			pushaddr(pc.cp);
I 37
			tl = (tl + 1) & ~1;
E 37
D 10
			pc.cp += tl;
E 10
I 10
			pc.cp += (int)tl;
E 10
			continue;
		case O_RANG2:
			tl = *pc.cp++;
			if (tl == 0)
				tl = *pc.sp++;
			tl1 = pop2();
D 10
			push2(RANG4(tl1, tl, *pc.sp++));
E 10
I 10
D 17
			push2((short)(RANG4(tl1, tl, *pc.sp++)));
E 17
I 17
			push2((short)(RANG4(tl1, tl, (long)(*pc.sp++))));
E 17
E 10
			continue;
		case O_RANG42:
			tl = *pc.cp++;
			if (tl == 0)
				tl = *pc.sp++;
			tl1 = pop4();
D 17
			push4(RANG4(tl1, tl, *pc.sp++));
E 17
I 17
			push4(RANG4(tl1, tl, (long)(*pc.sp++)));
E 17
			continue;
		case O_RSNG2:
			tl = *pc.cp++;
			if (tl == 0)
				tl = *pc.sp++;
			tl1 = pop2();
D 10
			push2(RSNG4(tl1, tl));
E 10
I 10
			push2((short)(RSNG4(tl1, tl)));
E 10
			continue;
		case O_RSNG42:
			tl = *pc.cp++;
			if (tl == 0)
				tl = *pc.sp++;
			tl1 = pop4();
			push4(RSNG4(tl1, tl));
			continue;
		case O_RANG4:
D 17
			pc.cp++;
			tl = *pc.lp++;
E 17
I 17
			tl = *pc.cp++;
			if (tl == 0)
D 37
				tl = *pc.lp++;
E 37
I 37
				PCLONGVAL(tl);
E 37
E 17
			tl1 = pop4();
D 37
			push4(RANG4(tl1, tl, *pc.lp++));
E 37
I 37
			PCLONGVAL(tl2);
			push4(RANG4(tl1, tl, tl2));
E 37
			continue;
		case O_RANG24:
D 17
			pc.cp++;
			tl = *pc.lp++;
E 17
I 17
			tl = *pc.cp++;
			if (tl == 0)
D 37
				tl = *pc.lp++;
E 37
I 37
				PCLONGVAL(tl);
E 37
E 17
			tl1 = pop2();
D 10
			push2(RANG4(tl1, tl, *pc.lp++));
E 10
I 10
D 37
			push2((short)(RANG4(tl1, tl, *pc.lp++)));
E 37
I 37
			PCLONGVAL(tl2);
			push2((short)(RANG4(tl1, tl, tl2)));
E 37
E 10
			continue;
		case O_RSNG4:
D 17
			pc.cp++;
			tl = pop4();
			push4(RSNG4(tl, *pc.lp++));
E 17
I 17
			tl = *pc.cp++;
			if (tl == 0)
D 37
				tl = *pc.lp++;
E 37
I 37
				PCLONGVAL(tl);
E 37
			tl1 = pop4();
			push4(RSNG4(tl1, tl));
E 17
			continue;
		case O_RSNG24:
D 17
			pc.cp++;
			tl = pop2();
D 10
			push2(RSNG4(tl, *pc.lp++));
E 10
I 10
			push2((short)(RSNG4(tl, *pc.lp++)));
E 17
I 17
			tl = *pc.cp++;
			if (tl == 0)
D 37
				tl = *pc.lp++;
E 37
I 37
				PCLONGVAL(tl);
E 37
			tl1 = pop2();
			push2((short)(RSNG4(tl1, tl)));
E 17
E 10
			continue;
		case O_STLIM:
			pc.cp++;
D 4
			_stlim = pop4();
			_stcnt--;
			LINO();
E 4
I 4
			STLIM();
D 10
			popargs(1);
E 10
I 10
			popsp((long)(sizeof(long)));
E 10
E 4
			continue;
		case O_LLIMIT:
			pc.cp++;
			LLIMIT();
D 10
			popargs(2);
E 10
I 10
			popsp((long)(sizeof(char *)+sizeof(long)));
E 10
			continue;
		case O_BUFF:
D 10
			BUFF(*pc.cp++);
E 10
I 10
			BUFF((long)(*pc.cp++));
E 10
			continue;
		case O_HALT:
			pc.cp++;
D 20
			panic(PHALT);
E 20
I 20
			if (_nodump == TRUE)
				psexit(0);
			fputs("\nCall to procedure halt\n", stderr);
			backtrace("Halted");
			psexit(0);
E 20
			continue;
		case O_PXPBUF:
			pc.cp++;
D 37
			_cntrs = *pc.lp++;
			_rtns = *pc.lp++;
E 37
I 37
			PCLONGVAL(tl);
			_cntrs = tl;
			PCLONGVAL(tl);
			_rtns = tl;
E 37
D 10
			_pcpcount = (long *)calloc(_cntrs + 1, sizeof(long));
E 10
I 10
D 26
			NEWZ(&_pcpcount, (_cntrs + 1) * sizeof(long));
E 26
I 26
			NEW(&_pcpcount, (_cntrs + 1) * sizeof(long));
			blkclr(_pcpcount, (_cntrs + 1) * sizeof(long));
E 26
E 10
			continue;
		case O_COUNT:
			pc.cp++;
			_pcpcount[*pc.usp++]++;
			continue;
		case O_CASE1OP:
			tl = *pc.cp++;		/* tl = number of cases */
			if (tl == 0)
				tl = *pc.usp++;
			tsp = pc.sp + tl;	/* ptr to end of jump table */
			tcp = (char *)tsp;	/* tcp = ptr to case values */
			tl1 = pop2();		/* tl1 = element to find */
			for(; tl > 0; tl--)	/* look for element */
				if (tl1 == *tcp++)
					break;
			if (tl == 0)		/* default case => error */
D 7
				ERROR(ECASE, tl2);
E 7
I 7
D 15
				ERROR(ECASE, tl1);
E 15
I 15
D 19
				ERROR("Label of %D not found in case\n", tl1);
E 19
I 19
				CASERNG(tl1);
E 19
E 15
E 7
			pc.cp += *(tsp - tl);
			continue;
		case O_CASE2OP:
			tl = *pc.cp++;		/* tl = number of cases */
			if (tl == 0)
				tl = *pc.usp++;
			tsp = pc.sp + tl;	/* ptr to end of jump table */
			tsp1 = tsp;		/* tsp1 = ptr to case values */
			tl1 = (unsigned short)pop2();/* tl1 = element to find */
			for(; tl > 0; tl--)	/* look for element */
D 37
				if (tl1 == *tsp1++)
E 37
I 37
				if (tl1 == *tsp++)
E 37
					break;
			if (tl == 0)		/* default case => error */
D 7
				ERROR(ECASE, tl2);
E 7
I 7
D 15
				ERROR(ECASE, tl1);
E 15
I 15
D 19
				ERROR("Label of %D not found in case\n", tl1);
E 19
I 19
				CASERNG(tl1);
E 19
E 15
E 7
D 37
			pc.cp += *(tsp - tl);
E 37
I 37
			pc.cp += *(tsp1 - tl);
E 37
			continue;
		case O_CASE4OP:
			tl = *pc.cp++;		/* tl = number of cases */
			if (tl == 0)
				tl = *pc.usp++;
D 37
			tsp = pc.sp + tl;	/* ptr to end of jump table */
			tlp = (long *)tsp;	/* tlp = ptr to case values */
E 37
I 37
			tsp1 = pc.sp + tl;	/* ptr to end of jump table */
			tlp = (long *)tsp1;	/* tlp = ptr to case values */
E 37
			tl1 = pop4();		/* tl1 = element to find */
D 37
			for(; tl > 0; tl--)	/* look for element */
				if (tl1 == *tlp++)
E 37
I 37
			for(; tl > 0; tl--) {	/* look for element */
				GETLONGVAL(tl2, tlp++);
				if (tl1 == tl2)
E 37
					break;
I 37
			}
E 37
			if (tl == 0)		/* default case => error */
D 7
				ERROR(ECASE, tl2);
E 7
I 7
D 15
				ERROR(ECASE, tl1);
E 15
I 15
D 19
				ERROR("Label of %D not found in case\n", tl1);
E 19
I 19
				CASERNG(tl1);
E 19
E 15
E 7
D 37
			pc.cp += *(tsp - tl);
E 37
I 37
			pc.cp += *(tsp1 - tl);
E 37
			continue;
		case O_ADDT:
			tl = *pc.cp++;		/* tl has comparison length */
			if (tl == 0)
				tl = *pc.usp++;
D 10
			tcp = pushsp(0);	/* tcp pts to first arg */
E 10
I 10
			tcp = pushsp((long)(0));/* tcp pts to first arg */
E 10
			ADDT(tcp + tl, tcp + tl, tcp, tl >> 2);
			popsp(tl);
			continue;
		case O_SUBT:
			tl = *pc.cp++;		/* tl has comparison length */
			if (tl == 0)
				tl = *pc.usp++;
D 10
			tcp = pushsp(0);	/* tcp pts to first arg */
E 10
I 10
			tcp = pushsp((long)(0));/* tcp pts to first arg */
E 10
			SUBT(tcp + tl, tcp + tl, tcp, tl >> 2);
			popsp(tl);
			continue;
		case O_MULT:
			tl = *pc.cp++;		/* tl has comparison length */
			if (tl == 0)
				tl = *pc.usp++;
D 10
			tcp = pushsp(0);	/* tcp pts to first arg */
E 10
I 10
			tcp = pushsp((long)(0));/* tcp pts to first arg */
E 10
			MULT(tcp + tl, tcp + tl, tcp, tl >> 2);
			popsp(tl);
			continue;
		case O_INCT:
			tl = *pc.cp++;		/* tl has number of args */
			if (tl == 0)
				tl = *pc.usp++;
D 10
			tl1 = INCT();
			popargs(tl);
			push2(tl1);
E 10
I 10
			tb = INCT();
			popsp(tl*sizeof(long));
			push2((short)(tb));
E 10
			continue;
		case O_CTTOT:
			tl = *pc.cp++;		/* tl has number of args */
			if (tl == 0)
				tl = *pc.usp++;
			tl1 = tl * sizeof(long);
D 10
			tcp = pushsp(0) + tl1;	/* tcp pts to result space */
E 10
I 10
			tcp = pushsp((long)(0)) + tl1; /* tcp pts to result */
E 10
			CTTOT(tcp);
D 10
			popargs(tl);
E 10
I 10
			popsp(tl*sizeof(long));
E 10
			continue;
		case O_CARD:
			tl = *pc.cp++;		/* tl has comparison length */
			if (tl == 0)
				tl = *pc.usp++;
D 10
			tcp = pushsp(0);	/* tcp pts to set */
E 10
I 10
			tcp = pushsp((long)(0));/* tcp pts to set */
E 10
			tl1 = CARD(tcp, tl);
			popsp(tl);
D 10
			push2(tl1);
E 10
I 10
			push2((short)(tl1));
E 10
			continue;
		case O_IN:
			tl = *pc.cp++;		/* tl has comparison length */
			if (tl == 0)
				tl = *pc.usp++;
			tl1 = pop4();		/* tl1 is the element */
D 10
			tcp = pushsp(0);	/* tcp pts to set */
E 10
I 10
			tcp = pushsp((long)(0));/* tcp pts to set */
E 10
D 17
			tl2 = *pc.usp++;	/* lower bound */
E 17
I 17
			tl2 = *pc.sp++;	/* lower bound */
E 17
D 10
			tl1 = IN(tl1, tl2, *pc.usp++, tcp);
E 10
I 10
			tb = IN(tl1, tl2, (long)(*pc.usp++), tcp);
E 10
			popsp(tl);
D 10
			push2(tl1);
E 10
I 10
			push2((short)(tb));
E 10
			continue;
		case O_ASRT:
			pc.cp++;
D 2
			ASRT(pop2());
E 2
I 2
D 10
			ASRT(pop2(), "");
E 10
I 10
D 24
			ts = pop2();
			ASRT(ts, "");
E 24
I 24
D 26
			ASRT();
E 26
I 26
D 36
			ASRTS();
E 26
			popsp((long)(sizeof(long)+sizeof(char *)));
E 36
I 36
			tl = pop4();
			tcp = popaddr();
			ASRTS(tl, tcp);
E 36
E 24
E 10
E 2
			continue;
		case O_FOR1U:
D 17
			pc.cp++;
D 10
			tcp = (char *)pop4();	/* tcp = ptr to index var */
E 10
I 10
			tcp = popaddr();	/* tcp = ptr to index var */
E 10
			if (*tcp < pop4()) {	/* still going up */
D 5
				*tcp += 1;	/* inc index var */
E 5
I 5
				tl = *tcp + 1;	/* inc index var */
				tl1 = *pc.sp++;	/* index lower bound */
				tl2 = *pc.sp++;	/* index upper bound */
				if (_runtst)
					RANG4(tl, tl1, tl2);
				*tcp = tl;	/* update index var */
E 5
				pc.cp += *pc.sp;/* return to top of loop */
				continue;
			}
D 5
			pc.sp++;		/* else fall through */
E 5
I 5
			pc.sp += 3;		/* else fall through */
E 5
			continue;
E 17
I 17
D 29
			/*
			 * with the shadowing of for loop variables
			 * the variable is always sizeof(long) hence
			 * nullifying the need for shorter length
			 * assignments
			 */
E 29
I 29
D 31
			tl1 = *pc.cp++;		/* tl1 index lower bound */
E 31
I 31
			tl1 = *pc.cp++;		/* tl1 loop branch */
E 31
			if (tl1 == 0)
				tl1 = *pc.sp++;
			tcp = popaddr();	/* tcp = ptr to index var */
D 31
			tl = pop4();
			if (*tcp < tl) {	/* still going up */
				tl = *tcp + 1;	/* inc index var */
				tl2 = *pc.sp++;	/* index upper bound */
				if (_runtst)
					RANG4(tl, tl1, tl2);
				*tcp = tl;	/* update index var */
				pc.cp += *pc.sp;/* return to top of loop */
E 31
I 31
			tl = pop4();		/* tl upper bound */
			if (*tcp == tl)		/* loop is done, fall through */
E 31
				continue;
D 31
			}
			pc.sp += 2;		/* else fall through */
E 31
I 31
			*tcp += 1;		/* inc index var */
			pc.cp += tl1;		/* return to top of loop */
E 31
			continue;
E 29
E 17
		case O_FOR2U:
D 17
			pc.cp++;
D 10
			tsp = (short *)pop4();	/* tsp = ptr to index var */
E 10
I 10
			tsp = (short *)popaddr(); /* tsp = ptr to index var */
E 10
			if (*tsp < pop4()) {	/* still going up */
D 5
				*tsp += 1;	/* inc index var */
E 5
I 5
				tl = *tsp + 1;	/* inc index var */
				tl1 = *pc.sp++;	/* index lower bound */
E 17
I 17
D 31
			tl1 = *pc.cp++;		/* tl1 index lower bound */
E 31
I 31
			tl1 = *pc.cp++;		/* tl1 loop branch */
E 31
			if (tl1 == 0)
				tl1 = *pc.sp++;
D 29
			tlp = (long *)popaddr(); /* tlp = ptr to index var */
			if (*tlp < pop4()) {	/* still going up */
				tl = *tlp + 1;	/* inc index var */
E 29
I 29
			tsp = (short *)popaddr(); /* tsp = ptr to index var */
D 31
			tl = pop4();
			if (*tsp < tl) {	/* still going up */
				tl = *tsp + 1;	/* inc index var */
E 29
E 17
				tl2 = *pc.sp++;	/* index upper bound */
				if (_runtst)
					RANG4(tl, tl1, tl2);
D 17
				*tsp = tl;	/* update index var */
E 17
I 17
D 29
				*tlp = tl;	/* update index var */
E 29
I 29
				*tsp = tl;	/* update index var */
E 29
E 17
E 5
				pc.cp += *pc.sp;/* return to top of loop */
E 31
I 31
			tl = pop4();		/* tl upper bound */
			if (*tsp == tl)		/* loop is done, fall through */
E 31
				continue;
D 31
			}
D 5
			pc.sp++;		/* else fall through */
E 5
I 5
D 17
			pc.sp += 3;		/* else fall through */
E 17
I 17
			pc.sp += 2;		/* else fall through */
E 31
I 31
			*tsp += 1;		/* inc index var */
			pc.cp += tl1;		/* return to top of loop */
E 31
E 17
E 5
			continue;
		case O_FOR4U:
D 17
			pc.cp++;
E 17
I 17
D 31
			tl1 = *pc.cp++;		/* tl1 index lower bound */
E 31
I 31
			tl1 = *pc.cp++;		/* tl1 loop branch */
E 31
			if (tl1 == 0)
D 31
				tl1 = *pc.lp++;
E 31
I 31
				tl1 = *pc.sp++;
E 31
E 17
D 10
			tlp = (long *)pop4();	/* tlp = ptr to index var */
E 10
I 10
			tlp = (long *)popaddr(); /* tlp = ptr to index var */
E 10
D 29
			if (*tlp < pop4()) {	/* still going up */
E 29
I 29
D 31
			tl = pop4();
			if (*tlp < tl) {	/* still going up */
E 29
D 5
				*tlp += 1;	/* inc index var */
E 5
I 5
				tl = *tlp + 1;	/* inc index var */
D 17
				tl1 = *pc.lp++;	/* index lower bound */
E 17
				tl2 = *pc.lp++;	/* index upper bound */
				if (_runtst)
					RANG4(tl, tl1, tl2);
				*tlp = tl;	/* update index var */
E 5
				pc.cp += *pc.sp;/* return to top of loop */
E 31
I 31
			tl = pop4();		/* tl upper bound */
			if (*tlp == tl)		/* loop is done, fall through */
E 31
				continue;
D 31
			}
D 5
			pc.sp++;		/* else fall through */
E 5
I 5
D 17
			pc.sp += 5;		/* else fall through */
E 5
			continue;
		case O_FOR1D:
			pc.cp++;
D 10
			tcp = (char *)pop4();	/* tcp = ptr to index var */
E 10
I 10
			tcp = popaddr();	/* tcp = ptr to index var */
E 10
			if (*tcp > pop4()) {	/* still going down */
D 5
				*tcp -= 1;	/* dec index var */
E 5
I 5
				tl = *tcp - 1;	/* inc index var */
				tl1 = *pc.sp++;	/* index lower bound */
				tl2 = *pc.sp++;	/* index upper bound */
				if (_runtst)
					RANG4(tl, tl1, tl2);
				*tcp = tl;	/* update index var */
E 5
				pc.cp += *pc.sp;/* return to top of loop */
				continue;
			}
E 17
D 5
			pc.sp++;		/* else fall through */
E 5
I 5
			pc.sp += 3;		/* else fall through */
E 31
I 31
			*tlp += 1;		/* inc index var */
			pc.cp += tl1;		/* return to top of loop */
E 31
E 5
			continue;
I 17
		case O_FOR1D:
D 29
			/*
			 * with the shadowing of for loop variables
			 * the variable is always sizeof(long) hence
			 * nullifying the need for shorter length
			 * assignments
			 */
E 29
I 29
D 31
			tl1 = *pc.cp++;		/* tl1 index lower bound */
E 31
I 31
			tl1 = *pc.cp++;		/* tl1 loop branch */
E 31
			if (tl1 == 0)
				tl1 = *pc.sp++;
			tcp = popaddr();	/* tcp = ptr to index var */
D 31
			tl = pop4();
			if (*tcp > tl) {	/* still going down */
				tl = *tcp - 1;	/* inc index var */
				tl2 = *pc.sp++;	/* index upper bound */
				if (_runtst)
					RANG4(tl, tl1, tl2);
				*tcp = tl;	/* update index var */
				pc.cp += *pc.sp;/* return to top of loop */
E 31
I 31
			tl = pop4();		/* tl upper bound */
			if (*tcp == tl)		/* loop is done, fall through */
E 31
				continue;
D 31
			}
			pc.sp += 2;		/* else fall through */
E 31
I 31
			*tcp -= 1;		/* dec index var */
			pc.cp += tl1;		/* return to top of loop */
E 31
			continue;
E 29
E 17
		case O_FOR2D:
D 17
			pc.cp++;
D 10
			tsp = (short *)pop4();	/* tsp = ptr to index var */
E 10
I 10
			tsp = (short *)popaddr(); /* tsp = ptr to index var */
E 10
			if (*tsp > pop4()) {	/* still going down */
D 5
				*tsp -= 1;	/* dec index var */
E 5
I 5
				tl = *tsp - 1;	/* inc index var */
				tl1 = *pc.sp++;	/* index lower bound */
E 17
I 17
D 31
			tl1 = *pc.cp++;		/* tl1 index lower bound */
E 31
I 31
			tl1 = *pc.cp++;		/* tl1 loop branch */
E 31
			if (tl1 == 0)
				tl1 = *pc.sp++;
D 29
			tlp = (long *)popaddr(); /* tlp = ptr to index var */
			if (*tlp > pop4()) {	/* still going down */
				tl = *tlp - 1;	/* inc index var */
E 29
I 29
			tsp = (short *)popaddr(); /* tsp = ptr to index var */
D 31
			tl = pop4();
			if (*tsp > tl) {	/* still going down */
				tl = *tsp - 1;	/* inc index var */
E 29
E 17
				tl2 = *pc.sp++;	/* index upper bound */
				if (_runtst)
					RANG4(tl, tl1, tl2);
D 17
				*tsp = tl;	/* update index var */
E 17
I 17
D 29
				*tlp = tl;	/* update index var */
E 29
I 29
				*tsp = tl;	/* update index var */
E 29
E 17
E 5
				pc.cp += *pc.sp;/* return to top of loop */
E 31
I 31
			tl = pop4();		/* tl upper bound */
			if (*tsp == tl)		/* loop is done, fall through */
E 31
				continue;
D 31
			}
D 5
			pc.sp++;		/* else fall through */
E 5
I 5
D 17
			pc.sp += 3;		/* else fall through */
E 17
I 17
			pc.sp += 2;		/* else fall through */
E 31
I 31
			*tsp -= 1;		/* dec index var */
			pc.cp += tl1;		/* return to top of loop */
E 31
E 17
E 5
			continue;
		case O_FOR4D:
D 17
			pc.cp++;
E 17
I 17
D 31
			tl1 = *pc.cp++;		/* tl1 index lower bound */
E 31
I 31
			tl1 = *pc.cp++;		/* tl1 loop branch */
E 31
			if (tl1 == 0)
D 31
				tl1 = *pc.lp++;
E 31
I 31
				tl1 = *pc.sp++;
E 31
E 17
D 10
			tlp = (long *)pop4();	/* tlp = ptr to index var */
E 10
I 10
			tlp = (long *)popaddr(); /* tlp = ptr to index var */
E 10
D 29
			if (*tlp > pop4()) {	/* still going down */
E 29
I 29
D 31
			tl = pop4();
			if (*tlp > tl) {	/* still going down */
E 29
D 5
				*tlp -= 1;	/* dec index var */
E 5
I 5
				tl = *tlp - 1;	/* inc index var */
D 17
				tl1 = *pc.lp++;	/* index lower bound */
E 17
				tl2 = *pc.lp++;	/* index upper bound */
				if (_runtst)
					RANG4(tl, tl1, tl2);
				*tlp = tl;	/* update index var */
E 5
				pc.cp += *pc.sp;/* return to top of loop */
E 31
I 31
			tl = pop4();		/* tl upper bound */
			if (*tlp == tl)		/* loop is done, fall through */
E 31
				continue;
D 31
			}
D 5
			pc.sp++;		/* else fall through */
E 5
I 5
D 17
			pc.sp += 5;		/* else fall through */
E 17
I 17
			pc.sp += 3;		/* else fall through */
E 31
I 31
			*tlp -= 1;		/* dec index var */
			pc.cp += tl1;		/* return to top of loop */
E 31
E 17
E 5
			continue;
		case O_READE:
			pc.cp++;
D 10
			push2(READE(curfile, base + *pc.lp++));
E 10
I 10
D 37
			push2((short)(READE(curfile, base + *pc.lp++)));
E 37
I 37
			PCLONGVAL(tl);
			push2((short)(READE(curfile, base + tl)));
E 37
E 10
			continue;
		case O_READ4:
			pc.cp++;
			push4(READ4(curfile));
			continue;
		case O_READC:
			pc.cp++;
D 10
			push2(READC(curfile));
E 10
I 10
			push2((short)(READC(curfile)));
E 10
			continue;
		case O_READ8:
			pc.cp++;
			push8(READ8(curfile));
			continue;
		case O_READLN:
			pc.cp++;
			READLN(curfile);
			continue;
		case O_EOF:
			pc.cp++;
D 10
			push2(TEOF(popaddr()));
E 10
I 10
			push2((short)(TEOF(popaddr())));
E 10
			continue;
		case O_EOLN:
			pc.cp++;
D 10
			push2(TEOLN(popaddr()));
E 10
I 10
			push2((short)(TEOLN(popaddr())));
E 10
			continue;
		case O_WRITEC:
D 11
			pc.cp++;
E 11
D 5
			WRITEC(curfile);
E 5
I 5
			if (_runtst) {
				WRITEC(curfile);
D 10
				popargs(2);
E 10
I 10
D 11
				popsp((long)(sizeof(long)+sizeof(FILE *)));
E 11
I 11
				popsp((long)(*pc.cp++));
E 11
E 10
				continue;
			}
I 10
D 11
#ifdef VAX
E 11
E 10
D 36
			fputc();
E 5
D 10
			popargs(2);
E 10
I 10
D 11
#else
			WRITEC(curfile);
#endif VAX
			popsp((long)(sizeof(long)+sizeof(FILE *)));
E 11
I 11
			popsp((long)(*pc.cp++));
E 36
I 36
			tl = *pc.cp++;
			switch (tl - sizeof(FILE *)) {
			case 2:
				tl1 = pop2();
				break;
			case 4:
				tl1 = pop4();
				break;
			default:
				ERROR("Panic: bad size to O_WRITEC");
				/* NOT REACHED */
			}
			tcp = popaddr();
			fputc(tl1, tcp);
E 36
E 11
E 10
			continue;
		case O_WRITES:
D 11
			pc.cp++;
E 11
D 5
			WRITES(curfile);
E 5
I 5
			if (_runtst) {
				WRITES(curfile);
D 10
				popargs(4);
E 10
I 10
D 11
				popsp((long)(2*sizeof(char *)+2*sizeof(long)));
E 11
I 11
				popsp((long)(*pc.cp++));
E 11
E 10
				continue;
			}
I 10
D 11
#ifdef VAX
E 11
E 10
			fwrite();
E 5
D 10
			popargs(4);
E 10
I 10
D 11
#else
			WRITES(curfile);
#endif VAX
			popsp((long)(2*sizeof(char *)+2*sizeof(long)));
E 11
I 11
			popsp((long)(*pc.cp++));
E 11
E 10
			continue;
		case O_WRITEF:
D 5
			WRITEF(curfile);
E 5
I 5
			if (_runtst) {
				WRITEF(curfile);
D 10
				popargs(*pc.cp++);
E 10
I 10
D 11
				popsp((long)(((*pc.cp++ - 2) * sizeof(long)) +
					2 * sizeof(char *)));
E 11
I 11
				popsp((long)(*pc.cp++));
E 11
E 10
				continue;
			}
I 10
D 11
#ifdef VAX
E 11
E 10
			fprintf();
E 5
D 10
			popargs(*pc.cp++);
E 10
I 10
D 11
#else
			WRITEF(curfile);
#endif VAX
			popsp((long)(((*pc.cp++ - 2) * sizeof(long)) +
				2 * sizeof(char *)));
E 11
I 11
			popsp((long)(*pc.cp++));
E 11
E 10
			continue;
		case O_WRITLN:
			pc.cp++;
D 5
			WRITLN(curfile);
E 5
I 5
			if (_runtst) {
				WRITLN(curfile);
				continue;
			}
			fputc('\n', ACTFILE(curfile));
E 5
			continue;
		case O_PAGE:
			pc.cp++;
D 5
			PAGE(curfile);
E 5
I 5
			if (_runtst) {
				PAGE(curfile);
				continue;
			}
D 10
			fputc('^L', ACTFILE(curfile));
E 10
I 10
			fputc('', ACTFILE(curfile));
E 10
E 5
			continue;
		case O_NAM:
			pc.cp++;
			tl = pop4();
D 37
			pushaddr(NAM(tl, base + *pc.lp++));
E 37
I 37
			PCLONGVAL(tl1);
			pushaddr(NAM(tl, base + tl1));
E 37
			continue;
		case O_MAX:
			tl = *pc.cp++;
			if (tl == 0)
				tl = *pc.usp++;
			tl1 = pop4();
D 5
			push4(MAX(tl1, tl, *pc.usp++));
E 5
I 5
			if (_runtst) {
D 10
				push4(MAX(tl1, tl, *pc.usp++));
E 10
I 10
				push4(MAX(tl1, tl, (long)(*pc.usp++)));
E 10
				continue;
			}
			tl1 -= tl;
			tl = *pc.usp++;
			push4(tl1 > tl ? tl1 : tl);
E 5
			continue;
		case O_MIN:
			tl = *pc.cp++;
			if (tl == 0)
				tl = *pc.usp++;
			tl1 = pop4();
			push4(tl1 < tl ? tl1 : tl);
			continue;
		case O_UNIT:
			pc.cp++;
			curfile = UNIT(popaddr());
			continue;
		case O_UNITINP:
			pc.cp++;
			curfile = INPUT;
			continue;
		case O_UNITOUT:
			pc.cp++;
			curfile = OUTPUT;
			continue;
		case O_MESSAGE:
			pc.cp++;
			PFLUSH();
			curfile = ERR;
			continue;
I 2
		case O_PUT:
			pc.cp++;
			PUT(curfile);
			continue;
E 2
		case O_GET:
			pc.cp++;
			GET(curfile);
			continue;
		case O_FNIL:
			pc.cp++;
			pushaddr(FNIL(popaddr()));
			continue;
		case O_DEFNAME:
			pc.cp++;
			DEFNAME();
D 10
			popargs(4);
E 10
I 10
			popsp((long)(2*sizeof(char *)+2*sizeof(long)));
E 10
			continue;
		case O_RESET:
			pc.cp++;
			RESET();
D 10
			popargs(4);
E 10
I 10
			popsp((long)(2*sizeof(char *)+2*sizeof(long)));
E 10
			continue;
		case O_REWRITE:
			pc.cp++;
			REWRITE();
D 10
			popargs(4);
E 10
I 10
			popsp((long)(2*sizeof(char *)+2*sizeof(long)));
E 10
			continue;
		case O_FILE:
			pc.cp++;
			pushaddr(ACTFILE(curfile));
			continue;
		case O_REMOVE:
			pc.cp++;
			REMOVE();
D 10
			popargs(2);
E 10
I 10
			popsp((long)(sizeof(char *)+sizeof(long)));
E 10
			continue;
		case O_FLUSH:
			pc.cp++;
			FLUSH();
D 10
			popargs(1);
E 10
I 10
			popsp((long)(sizeof(char *)));
E 10
			continue;
		case O_PACK:
			pc.cp++;
			PACK();
D 10
			popargs(7);
E 10
I 10
			popsp((long)(5*sizeof(long)+2*sizeof(char*)));
E 10
			continue;
		case O_UNPACK:
			pc.cp++;
			UNPACK();
D 10
			popargs(7);
E 10
I 10
			popsp((long)(5*sizeof(long)+2*sizeof(char*)));
E 10
			continue;
		case O_ARGC:
			pc.cp++;
D 10
			push4(_argc);
E 10
I 10
			push4((long)_argc);
E 10
			continue;
		case O_ARGV:
			tl = *pc.cp++;		/* tl = size of char array */
			if (tl == 0)
				tl = *pc.usp++;
			tcp = popaddr();	/* tcp = addr of char array */
			tl1 = pop4();		/* tl1 = argv subscript */
			ARGV(tl1, tcp, tl);
			continue;
		case O_CLCK:
			pc.cp++;
			push4(CLCK());
			continue;
		case O_WCLCK:
			pc.cp++;
			push4(time(0));
			continue;
		case O_SCLCK:
			pc.cp++;
			push4(SCLCK());
			continue;
D 25
		case O_DISPOSE:
			tl = *pc.cp++;		/* tl = size being disposed */
			if (tl == 0)
				tl = *pc.usp++;
			tcp = popaddr();	/* ptr to ptr being disposed */
			DISPOSE(tcp, tl);
			*(char **)tcp = (char *)0;
			continue;
E 25
		case O_NEW:
			tl = *pc.cp++;		/* tl = size being new'ed */
			if (tl == 0)
				tl = *pc.usp++;
			tcp = popaddr();	/* ptr to ptr being new'ed */
I 26
			NEW(tcp, tl);
E 26
D 5
			NEWZ(tcp, tl);
E 5
I 5
			if (_runtst) {
D 26
				NEWZ(tcp, tl);
				continue;
E 26
I 26
D 27
				blkclr(*tcp, tl);
E 27
I 27
				blkclr(*((char **)(tcp)), tl);
E 27
E 26
			}
D 26
			NEW(tcp, tl);
E 26
I 25
			continue;
		case O_DISPOSE:
			tl = *pc.cp++;		/* tl = size being disposed */
			if (tl == 0)
				tl = *pc.usp++;
			tcp = popaddr();	/* ptr to ptr being disposed */
			DISPOSE(tcp, tl);
			*(char **)tcp = (char *)0;
			continue;
		case O_DFDISP:
			tl = *pc.cp++;		/* tl = size being disposed */
			if (tl == 0)
				tl = *pc.usp++;
			tcp = popaddr();	/* ptr to ptr being disposed */
			DFDISPOSE(tcp, tl);
			*(char **)tcp = (char *)0;
E 25
E 5
			continue;
		case O_DATE:
			pc.cp++;
			DATE(popaddr());
			continue;
		case O_TIME:
			pc.cp++;
			TIME(popaddr());
			continue;
		case O_UNDEF:
			pc.cp++;
D 37
			pop8();
E 37
I 37
			td = pop8();
E 37
D 10
			push2(0);
E 10
I 10
			push2((short)(0));
E 10
			continue;
		case O_ATAN:
			pc.cp++;
I 21
			if (_runtst) {
				push8(ATAN(pop8()));
				continue;
			}
E 21
			push8(atan(pop8()));
			continue;
		case O_COS:
			pc.cp++;
I 21
			if (_runtst) {
				push8(COS(pop8()));
				continue;
			}
E 21
			push8(cos(pop8()));
			continue;
		case O_EXP:
			pc.cp++;
I 21
			if (_runtst) {
				push8(EXP(pop8()));
				continue;
			}
E 21
			push8(exp(pop8()));
			continue;
		case O_LN:
			pc.cp++;
D 5
			push8(LN(pop8()));
E 5
I 5
			if (_runtst) {
				push8(LN(pop8()));
				continue;
			}
			push8(log(pop8()));
E 5
			continue;
		case O_SIN:
			pc.cp++;
I 21
			if (_runtst) {
				push8(SIN(pop8()));
				continue;
			}
E 21
			push8(sin(pop8()));
			continue;
		case O_SQRT:
			pc.cp++;
D 5
			push8(SQRT(pop8()));
E 5
I 5
			if (_runtst) {
				push8(SQRT(pop8()));
				continue;
			}
			push8(sqrt(pop8()));
E 5
			continue;
		case O_CHR2:
		case O_CHR4:
			pc.cp++;
D 5
			push2(CHR(pop4()));
E 5
I 5
			if (_runtst) {
D 10
				push2(CHR(pop4()));
E 10
I 10
				push2((short)(CHR(pop4())));
E 10
				continue;
			}
D 10
			push2(pop4());
E 10
I 10
			push2((short)(pop4()));
E 10
E 5
			continue;
		case O_ODD2:
		case O_ODD4:
			pc.cp++;
D 10
			push2(pop4() & 1);
E 10
I 10
D 29
			push2((short)(pop4() & 1));
E 29
I 29
			tl = pop4();
			push2((short)(tl & 1));
E 29
E 10
			continue;
		case O_SUCC2:
D 2
			/* Pi should be fixed to gen code for:
			 *	tl = *pc.cp++;
			 *	if (tl == 0)
			 *		tl = *pc.sp++;
			 *	tl1 = pop4();
			 *	push2(SUCC(tl1, tl, *pc.sp++));
			 */
			pc.cp++;
			push2(pop4() + 1);
E 2
I 2
			tl = *pc.cp++;
			if (tl == 0)
				tl = *pc.sp++;
			tl1 = pop4();
D 5
			push2(SUCC(tl1, tl, *pc.sp++));
E 5
I 5
			if (_runtst) {
D 10
				push2(SUCC(tl1, tl, *pc.sp++));
E 10
I 10
				push2((short)(SUCC(tl1, tl, (long)(*pc.sp++))));
E 10
				continue;
			}
D 10
			push2(tl1 + 1);
E 10
I 10
			push2((short)(tl1 + 1));
E 10
			pc.sp++;
E 5
E 2
			continue;
		case O_SUCC24:
D 2
			/* Pi should be fixed to gen code for:
			 *	tl = *pc.cp++;
			 *	if (tl == 0)
			 *		tl = *pc.sp++;
			 *	tl1 = pop4();
			 *	push4(SUCC(tl1, tl, *pc.sp++));
			 */
E 2
I 2
			tl = *pc.cp++;
			if (tl == 0)
				tl = *pc.sp++;
			tl1 = pop4();
D 5
			push4(SUCC(tl1, tl, *pc.sp++));
E 5
I 5
			if (_runtst) {
D 10
				push4(SUCC(tl1, tl, *pc.sp++));
E 10
I 10
				push4(SUCC(tl1, tl, (long)(*pc.sp++)));
E 10
				continue;
			}
			push4(tl1 + 1);
			pc.sp++;
E 5
			continue;
E 2
		case O_SUCC4:
D 2
			/* Pi should be fixed to gen code for:
			 *	tl = *pc.cp++;
			 *	if (tl == 0)
			 *		tl = *pc.lp++;
			 *	tl1 = pop4();
			 *	push4(SUCC(tl1, tl, *pc.lp++));
			 */
			pc.cp++;
			push4(pop4() + 1);
E 2
I 2
			tl = *pc.cp++;
			if (tl == 0)
D 37
				tl = *pc.lp++;
E 37
I 37
				PCLONGVAL(tl);
E 37
			tl1 = pop4();
D 5
			push4(SUCC(tl1, tl, *pc.lp++));
E 5
I 5
			if (_runtst) {
D 10
				push4(SUCC(tl1, tl, *pc.lp++));
E 10
I 10
D 37
				push4(SUCC(tl1, tl, (long)(*pc.lp++)));
E 37
I 37
				PCLONGVAL(tl2);
				push4(SUCC(tl1, tl, (long)(tl2)));
E 37
E 10
				continue;
			}
			push4(tl1 + 1);
			pc.lp++;
E 5
E 2
			continue;
		case O_PRED2:
D 2
			/* Pi should be fixed to gen code for:
			 *	tl = *pc.cp++;
			 *	if (tl == 0)
			 *		tl = *pc.sp++;
			 *	tl1 = pop4();
			 *	push2(PRED(tl1, tl, *pc.sp++));
			 */
			pc.cp++;
			push2(pop4() - 1);
E 2
I 2
			tl = *pc.cp++;
			if (tl == 0)
				tl = *pc.sp++;
			tl1 = pop4();
D 5
			push2(PRED(tl1, tl, *pc.sp++));
E 5
I 5
			if (_runtst) {
D 10
				push2(PRED(tl1, tl, *pc.sp++));
E 10
I 10
				push2((short)(PRED(tl1, tl, (long)(*pc.sp++))));
E 10
				continue;
			}
D 10
			push2(tl1 - 1);
E 10
I 10
			push2((short)(tl1 - 1));
E 10
			pc.sp++;
E 5
E 2
			continue;
		case O_PRED24:
D 2
			/* Pi should be fixed to gen code for:
			 *	tl = *pc.cp++;
			 *	if (tl == 0)
			 *		tl = *pc.sp++;
			 *	tl1 = pop4();
			 *	push4(PRED(tl1, tl, *pc.sp++));
			 */
E 2
I 2
			tl = *pc.cp++;
			if (tl == 0)
				tl = *pc.sp++;
			tl1 = pop4();
D 5
			push4(PRED(tl1, tl, *pc.sp++));
E 5
I 5
			if (_runtst) {
D 10
				push4(PRED(tl1, tl, *pc.sp++));
E 10
I 10
				push4(PRED(tl1, tl, (long)(*pc.sp++)));
E 10
				continue;
			}
			push4(tl1 - 1);
			pc.sp++;
E 5
			continue;
E 2
		case O_PRED4:
D 2
			/* Pi should be fixed to gen code for:
			 *	tl = *pc.cp++;
			 *	if (tl == 0)
			 *		tl = *pc.lp++;
			 *	tl1 = pop4();
			 *	push4(PRED(tl1, tl, *pc.lp++));
			 */
			pc.cp++;
			push4(pop4() - 1);
E 2
I 2
			tl = *pc.cp++;
			if (tl == 0)
D 37
				tl = *pc.lp++;
E 37
I 37
				PCLONGVAL(tl);
E 37
			tl1 = pop4();
D 5
			push4(PRED(tl1, tl, *pc.lp++));
E 5
I 5
			if (_runtst) {
D 10
				push4(PRED(tl1, tl, *pc.lp++));
E 10
I 10
D 37
				push4(PRED(tl1, tl, (long)(*pc.lp++)));
E 37
I 37
				PCLONGVAL(tl2);
				push4(PRED(tl1, tl, (long)(tl2)));
E 37
E 10
				continue;
			}
			push4(tl1 - 1);
			pc.lp++;
E 5
E 2
			continue;
		case O_SEED:
			pc.cp++;
			push4(SEED(pop4()));
			continue;
		case O_RANDOM:
			pc.cp++;
			push8(RANDOM(pop8()));
			continue;
		case O_EXPO:
			pc.cp++;
			push4(EXPO(pop8()));
			continue;
		case O_SQR2:
		case O_SQR4:
			pc.cp++;
			tl = pop4();
			push4(tl * tl);
			continue;
		case O_SQR8:
			pc.cp++;
			td = pop8();
			push8(td * td);
			continue;
		case O_ROUND:
			pc.cp++;
			push4(ROUND(pop8()));
			continue;
		case O_TRUNC:
			pc.cp++;
			push4(TRUNC(pop8()));
I 10
			continue;
		default:
D 20
			panic(PBADOP);
E 20
I 20
			ERROR("Panic: bad op code\n");
E 20
E 10
			continue;
		}
	}
}
E 1
