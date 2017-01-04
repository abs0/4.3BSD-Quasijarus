h25452
s 00000/00000/00118
d D 5.5 04/12/08 04:15:11 msokolov 9 8
x 8
c I wrote all this code only to find out that the modem does not after all behave
c the way I thought. Back to smgetty.
e
s 00001/00000/00118
d D 5.4 04/12/07 23:43:20 msokolov 8 7
c smart modem support
e
s 00001/00000/00117
d D 5.3 03/03/22 18:44:20 msokolov 7 6
c Add PASS8 support (p8 boolean flag)
c This is necessary for 8-bit terminals as the default parity will screw them
e
s 00001/00000/00116
d D 5.2 86/01/07 15:10:03 mckusick 6 5
c set DECCTLQ on specifc lines with getty (from muller@nprdc.arpa)
e
s 00007/00001/00109
d D 5.1 85/04/29 12:44:41 dist 5 4
c Add copyright
e
s 00001/00000/00109
d D 4.4 85/02/05 08:48:51 ralph 4 3
c added autobaud detection.
e
s 00001/00000/00108
d D 4.3 83/07/09 18:34:18 sam 3 2
c allow output to be flushed before first prompt to handle open lines
e
s 00004/00000/00104
d D 4.2 83/07/07 03:34:49 kre 2 1
c added a couple of #defines
e
s 00104/00000/00000
d D 4.1 83/07/06 00:10:10 sam 1 0
c date and time created 83/07/06 00:10:10 by sam
e
u
U
t
T
I 1
D 5
/*	%M%	%I%	%E%	*/
E 5
I 5
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 5

/*
 * Getty description definitions.
 */
struct	gettystrs {
	char	*field;		/* name to lookup in gettytab */
	char	*defalt;	/* value we find by looking in defaults */
	char	*value;		/* value that we find there */
};

struct	gettynums {
	char	*field;		/* name to lookup */
	long	defalt;		/* number we find in defaults */
	long	value;		/* number we find there */
	int	set;		/* we actually got this one */
};

struct gettyflags {
	char	*field;		/* name to lookup */
	char	invrt;		/* name existing in gettytab --> false */
	char	defalt;		/* true/false in defaults */
	char	value;		/* true/false flag */
	char	set;		/* we found it */
};

/*
 * String values.
 */
#define	NX	gettystrs[0].value
#define	CL	gettystrs[1].value
#define IM	gettystrs[2].value
#define	LM	gettystrs[3].value
#define	ER	gettystrs[4].value
#define	KL	gettystrs[5].value
#define	ET	gettystrs[6].value
#define	PC	gettystrs[7].value
#define	TT	gettystrs[8].value
#define	EV	gettystrs[9].value
#define	LO	gettystrs[10].value
#define HN	gettystrs[11].value
#define HE	gettystrs[12].value
#define IN	gettystrs[13].value
#define QU	gettystrs[14].value
#define XN	gettystrs[15].value
#define XF	gettystrs[16].value
#define BK	gettystrs[17].value
#define SU	gettystrs[18].value
#define DS	gettystrs[19].value
#define RP	gettystrs[20].value
#define FL	gettystrs[21].value
#define WE	gettystrs[22].value
#define LN	gettystrs[23].value

/*
 * Numeric definitions.
 */
#define	IS	gettynums[0].value
#define	OS	gettynums[1].value
#define	SP	gettynums[2].value
#define	ND	gettynums[3].value
#define	CD	gettynums[4].value
#define	TD	gettynums[5].value
#define	FD	gettynums[6].value
#define	BD	gettynums[7].value
#define	TO	gettynums[8].value
#define	F0	gettynums[9].value
#define	F0set	gettynums[9].set
#define	F1	gettynums[10].value
#define	F1set	gettynums[10].set
#define	F2	gettynums[11].value
#define	F2set	gettynums[11].set
I 3
#define	PF	gettynums[12].value
E 3

/*
 * Boolean values.
 */
#define	HT	gettyflags[0].value
#define	NL	gettyflags[1].value
#define	EP	gettyflags[2].value
I 2
#define	EPset	gettyflags[2].set
E 2
#define	OP	gettyflags[3].value
I 2
#define	OPset	gettyflags[2].set
E 2
#define	AP	gettyflags[4].value
I 2
#define	APset	gettyflags[2].set
E 2
#define	EC	gettyflags[5].value
#define	CO	gettyflags[6].value
#define	CB	gettyflags[7].value
#define	CK	gettyflags[8].value
#define	CE	gettyflags[9].value
#define	PE	gettyflags[10].value
#define	RW	gettyflags[11].value
#define	XC	gettyflags[12].value
#define	LC	gettyflags[13].value
#define	UC	gettyflags[14].value
#define	IG	gettyflags[15].value
#define	PS	gettyflags[16].value
#define	HC	gettyflags[17].value
I 2
#define UB	gettyflags[18].value
I 4
#define AB	gettyflags[19].value
I 6
#define DX	gettyflags[20].value
I 7
#define P8	gettyflags[21].value
I 8
#define	SM	gettyflags[22].value
E 8
E 7
E 6
E 4
E 2

int	getent();
long	getnum();
int	getflag();
char	*getstr();

extern	struct gettyflags gettyflags[];
extern	struct gettynums gettynums[];
extern	struct gettystrs gettystrs[];
extern	int hopcount;
E 1
