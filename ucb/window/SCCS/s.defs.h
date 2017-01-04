h39417
s 00010/00005/00041
d D 3.18 88/06/29 21:35:55 bostic 28 27
c install approved copyright notice
e
s 00011/00007/00035
d D 3.17 88/02/21 13:36:53 bostic 27 26
c written by Edward Wang; attach Berkeley specific copyright
e
s 00006/00000/00036
d D 3.16 85/04/24 16:13:15 edward 26 25
c copyright messages
e
s 00001/00001/00035
d D 3.15 84/05/23 01:57:01 edward 25 24
c new sccs id
e
s 00002/00002/00034
d D 3.14 84/04/08 19:23:04 edward 24 23
c new options to "window": shell, pty, frame
c and stuff to support them
e
s 00000/00005/00036
d D 3.13 84/04/05 17:32:51 edward 23 22
c "s," "t," and "T" moved to long commands (iostat, time).
c "S" removed.
e
s 00000/00002/00041
d D 3.12 84/04/05 00:56:43 edward 22 21
c no more background windows.
e
s 00001/00000/00042
d D 3.11 84/04/05 00:31:55 edward 21 20
c -c flag, incmd, setcmd(), setterse() added
e
s 00005/00000/00037
d D 3.10 84/03/29 00:03:02 edward 20 19
c foreground and background windows
e
s 00005/00008/00032
d D 3.9 84/03/03 22:44:32 edward 19 18
c interrupt driven input
e
s 00000/00012/00040
d D 3.8 84/01/16 15:25:56 edward 18 17
c new io scheme
e
s 00001/00000/00051
d D 3.7 83/11/30 11:55:29 edward 17 16
c lastselwin, and restructured some code
e
s 00001/00007/00050
d D 3.6 83/11/22 19:57:35 edward 16 15
c new parser
e
s 00004/00000/00053
d D 3.5 83/11/02 11:08:09 edward 15 14
c flags for different machines.
e
s 00001/00001/00052
d D 3.4 83/09/01 18:34:54 edward 14 13
c Got rid of 'curwin'.
c and now knows about dead processes.
e
s 00007/00004/00046
d D 3.3 83/08/25 17:57:05 edward 13 12
c added user setable buffer size.
e
s 00001/00000/00049
d D 3.2 83/08/18 17:18:05 edward 12 11
c the box
e
s 00000/00000/00049
d D 3.1 83/08/11 17:22:37 edward 11 9
i 10
c last few day's work
e
s 00020/00004/00029
d D 2.1.1.1 83/08/09 18:35:49 edward 10 9
c mile stone
e
s 00000/00000/00033
d D 2.1 83/07/30 13:27:26 edward 9 8
c prepare for major change
e
s 00004/00000/00029
d D 1.8 83/07/29 17:12:28 edward 8 7
c new variables:  shell, shellname, and debug.
e
s 00002/00000/00027
d D 1.7 83/07/28 18:14:19 edward 7 6
c NWINDOW added
e
s 00000/00005/00027
d D 1.6 83/07/28 16:02:33 edward 6 5
c forgot to remove the CLOSE_* macros.
e
s 00002/00002/00030
d D 1.5 83/07/28 13:08:00 edward 5 4
c terse flag and changable escape character
e
s 00003/00000/00029
d D 1.4 83/07/27 14:33:45 edward 4 3
c io statistics
e
s 00005/00000/00024
d D 1.3 83/07/22 17:11:00 edward 3 2
c scrolling.
c uses Wscreensize() to get screen size.
c More intelligent framing.
c etc.
e
s 00000/00000/00024
d D 1.2 83/07/19 20:08:12 edward 2 1
c today's work
e
s 00024/00000/00000
d D 1.1 83/07/18 21:05:20 edward 1 0
c date and time created 83/07/18 21:05:20 by edward
e
u
U
f b 
t
T
I 1
D 10
/*	%W% %E%		*/
E 10
I 10
/*
D 25
 *	%W% %E%	
E 25
I 25
D 27
 * %W% %G%	
E 25
 */
E 10

I 26
/*
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 27
I 27
 * Copyright (c) 1983 Regents of the University of California.
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
 *
 *	%W% (Berkeley) %G%
E 27
 */

E 26
#include "ww.h"
D 19
#include <signal.h>
E 19
I 15
D 23
#ifndef O_4_1A
E 23
E 15
#include <sys/time.h>
D 23
#include <sys/resource.h>
I 15
#endif
E 23
E 15

I 7
#define NWINDOW 9

E 7
D 5
#define ESCAPE CTRL(p)

E 5
D 18
int nread;
I 4
int nreade;
int nreadz;
int nreadc;
E 18
I 15
D 23
#ifndef O_4_1A
E 23
E 15
E 4
struct timeval starttime;
I 15
D 23
#endif
E 23
E 15
D 10
struct timezone timezone;
E 10
D 18

I 10
	/* things for handling input */
E 10
char ibuf[512];
char *ibufp;
int ibufc;
#define bgetc()		(ibufc ? ibufc--, *ibufp++&0x7f : -1)
#define bpeekc()	(ibufc ? *ibufp&0x7f : -1)
#define bungetc(c)	(ibufp > ibuf ? ibufc++, *--ibufp = (c) : -1)
E 18

D 10
struct ww *selwin;
struct ww *cmdwin;
E 10
I 10
struct ww *window[NWINDOW];	/* the windows */
struct ww *selwin;		/* the selected window */
I 17
struct ww *lastselwin;		/* the last selected window */
E 17
struct ww *cmdwin;		/* the command window */
struct ww *framewin;		/* the window for framing */
I 12
struct ww *boxwin;		/* the window for the box */
I 20
struct ww *fgwin;		/* the last foreground window */
D 22
struct ww *bgwin;		/* the first background window */
E 22

#define isfg(w)		((w)->ww_order <= fgwin->ww_order)
D 22
#define isbg(w)		((w)->ww_order >= bgwin->ww_order)
E 22
E 20
E 12
D 13
struct ww *curwin;
E 13
I 13
D 14
struct ww *curwin;		/* the current window */
E 14
E 13
E 10

I 8
D 13
char *shell;
char *shellname;
E 13
I 13
D 24
char *shell;			/* the shell program */
char *shellname;		/* the shell program name (for argv[0]) */
E 24
I 24
char *shell[128];		/* the shell argv */
char *shellfile;		/* the shell program */
E 24
I 19
int nbufline;			/* default buffer size for new windows */
char escapec;			/* the escape character */
E 19
E 13

I 13
D 19
int nbufline;			/* number of lines in the buffer */

E 19
	/* flags */
E 13
E 8
D 19
char quit;
I 5
char terse;
I 8
char debug;
I 14
char incmd;			/* in command mode */
E 14
E 8
D 13
char escapec;
E 13
I 13
char escapec;			/* escape character */
E 19
I 19
char quit;			/* quit command issued */
char terse;			/* terse mode */
char debug;			/* debug mode */
I 21
char incmd;			/* in command mode */
E 21
E 19
E 13
I 10

struct ww *getwin();
struct ww *openwin();
D 16
struct ww *idtowin();
E 16
I 16
struct ww *vtowin();
E 16
struct ww *openiwin();
D 16

	/* stuff for long commands */
int argc;
char *argv[100];
int lineno;			/* line number in the source file */
char insource;			/* we're in a source */
E 16
E 10
E 5
I 3
D 6

	/* flags to doclose() */
#define CLOSE_ONE	0
#define CLOSE_ALL	1
#define CLOSE_DEAD	2
E 6
E 3
E 1
