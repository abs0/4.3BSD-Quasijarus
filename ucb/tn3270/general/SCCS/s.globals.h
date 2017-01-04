h35251
s 00014/00001/00095
d D 3.2 88/03/28 12:28:46 bostic 12 11
c add Berkeley specific headers
e
s 00000/00000/00096
d D 3.1 87/08/11 10:19:13 minshall 11 10
c New version numbering.
e
s 00002/00004/00094
d D 1.10 87/07/17 10:04:14 minshall 10 9
c Install sccs headers and copyright notices.
e
s 00000/00016/00098
d D 1.9 87/06/19 12:51:45 minshall 9 8
c Directory changes, plus move some globals out of here.
e
s 00003/00001/00111
d D 1.8 87/06/16 17:19:37 minshall 8 7
c Add ps_modified.
e
s 00000/00001/00112
d D 1.7 87/06/15 09:26:37 minshall 7 6
c Remove unused global variable (yeah!).
e
s 00006/00000/00107
d D 1.6 87/05/31 17:09:28 minshall 6 5
c Version without termcode.m4.
e
s 00011/00000/00096
d D 1.5 87/05/25 16:26:05 minshall 5 4
c Add 'shell_active' global.
e
s 00003/00001/00093
d D 1.4 87/05/24 14:34:10 minshall 4 3
c New OIA.
e
s 00006/00000/00088
d D 1.3 87/05/22 11:55:28 minshall 3 2
c Move OIA into global storage.
e
s 00000/00007/00088
d D 1.2 87/05/10 14:48:46 minshall 2 1
c Get rid of FieldForward, FieldReverse, and Terminal (Terminal 
c from here at least).
e
s 00095/00000/00000
d D 1.1 87/05/10 14:32:07 minshall 1 0
c date and time created 87/05/10 14:32:07 by minshall
e
u
U
t
T
I 1
/*
I 12
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
 *
 *	%W% (Berkeley) %G%
 */

/*
E 12
D 10
 *	@(#)globals.h	3.1  10/29/86
 */

/*
E 10
 *	This file contains all the globals used by tn3270.
 *
 *	Since various files may want to reference this file,
 *	and since they may only want subsets of the globals,
 *	we assume they have #include'd all the other .h files
 *	first, and we only give those globals relevant to
 *	the #include'd .h files.
I 10
 *
D 12
 * %W% (Berkeley) %G%
E 12
E 10
 */

#if	defined(DEFINING_INSTANCES)
#define	EXTERN
#else
#define	EXTERN extern
#endif


I 5
EXTERN int
		/*
		 * shell_active ==>
		 *		1.  Don't do input.
		 *		2.  Don't do output.
		 *		3.  Don't block in select.
		 *		4.  When nothing to do, call shell_continue()
		 */
	shell_active;


E 5
D 9
#if	defined(INCLUDED_3270)
#endif

#if	defined(INCLUDED_ASCEBC)
#endif

#if	defined(INCLUDED_DCTYPE)
extern char dctype[];		/* 256 byte array */
#endif

E 9
#if	defined(INCLUDED_OPTIONS)
EXTERN int	OptHome;		/* where home should send us */

EXTERN int	OptLeftMargin;		/* where new line should send us */

EXTERN char	OptColTabs[80];		/* local tab stops */

EXTERN int	OptAPLmode;

EXTERN int	OptNullProcessing;	/* improved null processing */

EXTERN int	OptZonesMode;		/* zones mode off */

EXTERN int	OptEnterNL;		/* regular enter/new line keys */

EXTERN int	OptColFieldTab;		/* regular column/field tab keys */

EXTERN int	OptPacing;		/* do pacing */

EXTERN int	OptAlphaInNumeric;	/* allow alpha in numeric fields */

EXTERN int	OptHome;

EXTERN int	OptLeftMargin;

EXTERN int	OptWordWrap;
#endif

#if	defined(INCLUDED_SCREEN)
EXTERN ScreenImage
	Host[MAXSCREENSIZE];		/* host view of screen */
D 2
#if	defined(SLOWSCREEN)
EXTERN ScreenImage
	Terminal[MAXSCREENSIZE];
#endif	/* defined(SLOWSCREEN) */

EXTERN char	FieldForward[MAXSCREENSIZE],	/* non-zero for SF, 0..1919 */
		FieldReverse[MAXSCREENSIZE];	/* non-zero for SF, 1919..0 */
E 2

EXTERN char	Orders[256];			/* Non-zero for orders */

			/* Run-time screen geometry */
EXTERN int
	MaxNumberLines,		/* How many rows the 3270 COULD have */
	MaxNumberColumns,	/* How many columns the 3270 COULD have */
	NumberLines,		/* How many lines the 3270 screen contains */
	NumberColumns,		/* How many columns the 3270 screen contains */
	ScreenSize;

EXTERN int CursorAddress;			/* where cursor is */
EXTERN int BufferAddress;			/* where writes are going */

EXTERN int Lowest, Highest;

extern char CIABuffer[];

EXTERN int UnLocked;		/* is the keyboard unlocked */
EXTERN int AidByte;

D 7
EXTERN int Initialized;	/* are we initialized? */
E 7
#endif

#if	defined(INCLUDED_STATE)
#endif
I 3

#if	defined(INCLUDED_OIA)

D 4
OIA OperatorInformationArea;
E 4
I 4
EXTERN OIA OperatorInformationArea;

D 8
EXTERN int oia_modified;		/* Has the oia been modified */
E 8
I 8
EXTERN int
    oia_modified,		/* Has the oia been modified */
    ps_modified;		/* Has the presentation space been modified */
E 8
E 4

#endif	/* defined(INCLUDED_OIA) */
I 6
D 9

#if	defined(INCLUDED_ASTOSC)

EXTERN	struct astosc astosc[256];

#endif	/* defined(INCLUDED_ASTOSC) */
E 9
E 6
E 3
E 1
