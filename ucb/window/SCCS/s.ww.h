h03995
s 00010/00005/00260
d D 3.49 88/06/29 21:37:12 bostic 64 63
c install approved copyright notice
e
s 00008/00005/00257
d D 3.48 88/06/21 17:30:13 edward 63 62
c made the window termcap more terminal specific (al, dl, dc, etc.)
e
s 00002/00002/00260
d D 3.47 88/03/19 04:31:46 edward 62 61
c bug fix: use WWT_TERM to set the environment variable
e
s 00002/00002/00260
d D 3.46 88/03/19 01:39:39 edward 61 60
c change window terminal name to window-2
e
s 00001/00001/00261
d D 3.45 88/03/19 01:34:10 edward 60 59
c added #if defined(MIPSEL) to ww.h
e
s 00011/00007/00251
d D 3.44 88/02/21 13:37:55 bostic 59 58
c written by Edward Wang; attach Berkeley specific copyright
e
s 00000/00001/00258
d D 3.43 87/10/22 19:39:01 bostic 58 57
c ANSI C; sprintf now returns an int.
e
s 00001/00001/00258
d D 3.42 87/10/02 19:36:52 edward 57 56
c changes from mips!dce, most compatibility stuff
e
s 00000/00001/00259
d D 3.41 87/10/01 22:45:57 edward 56 55
c use setenv() to set up environment, WINDOW_ID added (from mips!dce)
e
s 00008/00003/00252
d D 3.40 87/06/08 02:28:07 edward 55 54
c interrupt mechanism reworked, make SIGCHLD interrupt also
e
s 00001/00000/00254
d D 3.39 87/05/18 12:19:12 edward 54 53
c added keepopen and smooth flags, added + and - window selections
e
s 00001/00001/00253
d D 3.38 86/10/22 21:53:04 sam 53 52
c reverse ifdef so it works on tahoe and vax, as well as 68k
e
s 00011/00006/00243
d D 3.37 86/08/04 14:16:10 edward 52 50
c WWM_USR and WWM_DIM added, termcap strings XS and XE added,
c display mode escape sequences changed
e
s 00003/00001/00248
d R 3.37 86/05/02 13:35:18 edward 51 50
c added WWM_USR (user mode) and XS and XE termcap strings
e
s 00006/00000/00243
d D 3.36 85/04/24 16:11:31 edward 50 49
c copyright messages
e
s 00007/00004/00236
d D 3.35 85/03/01 17:40:43 edward 49 48
c changing window size and new WINSZ ioctl
e
s 00000/00002/00240
d D 3.34 85/01/15 15:46:07 edward 48 47
c sigmask() now a standard definition
e
s 00001/00001/00241
d D 3.33 84/05/23 01:56:30 edward 47 46
c new sccs id
e
s 00001/00001/00241
d D 3.32 84/05/23 01:22:34 edward 46 43
c O_SUN changed to mc68000
e
s 00001/00001/00241
d R 3.33 84/05/23 01:20:31 edward 45 44
c m68000 changed to mc68000
e
s 00001/00001/00241
d R 3.32 84/05/16 03:58:03 edward 44 43
c O_SUN changed to m68000 which is predefined in cpp
e
s 00000/00007/00242
d D 3.31 84/04/16 20:28:44 edward 43 42
c 4.1a, 4.1c compatibility removed, local.h added
e
s 00000/00001/00249
d D 3.30 84/04/09 23:28:41 edward 42 41
c wwbell() now a function.
e
s 00011/00007/00239
d D 3.29 84/04/08 19:22:36 edward 41 40
c new options to "window": shell, pty, frame
c and stuff to support them
e
s 00015/00017/00231
d D 3.28 84/04/08 12:07:51 edward 40 39
c control character expansion in wwwrite()
c calling of wwupdate() in wwwrite() dependent of ww_noupdate
c control character handling macros in char.h
e
s 00001/00000/00247
d D 3.27 84/03/23 18:16:23 edward 39 38
c compile with -R
e
s 00021/00012/00226
d D 3.26 84/03/03 22:42:08 edward 38 37
c interrupt driven input
e
s 00021/00001/00217
d D 3.25 84/01/16 15:25:07 edward 37 36
c new io scheme
e
s 00001/00000/00217
d D 3.24 84/01/11 16:29:16 edward 36 35
c make graphics mode available to user
e
s 00001/00000/00216
d D 3.23 83/12/17 15:38:14 edward 35 34
c WWM_GRP added
e
s 00005/00003/00211
d D 3.22 83/12/17 12:39:29 edward 34 33
c got rid of pgrp in struct ww_tty
e
s 00006/00001/00208
d D 3.21 83/12/02 22:44:46 edward 33 32
c WWU_MAJOR, clreol in wwupdate(), and more optimizations.
e
s 00004/00002/00205
d D 3.20 83/12/01 13:40:49 edward 32 31
c pty hanging bug
e
s 00000/00002/00207
d D 3.19 83/11/23 16:34:50 edward 31 30
c New cover scheme
e
s 00005/00000/00204
d D 3.18 83/11/02 11:05:46 edward 30 29
c flags for different machines.
e
s 00005/00000/00199
d D 3.17 83/10/19 10:42:56 edward 29 28
c byte swap for suns.
e
s 00005/00002/00194
d D 3.16 83/09/15 17:10:44 edward 28 27
c The 'M' command and rearranged debugging commands ('&')
e
s 00001/00000/00195
d D 3.15 83/09/15 13:27:39 edward 27 26
c inline expand some function calls
e
s 00009/00006/00186
d D 3.14 83/09/15 10:08:40 edward 26 25
c Now uses screen address for all buffers.
e
s 00001/00000/00191
d D 3.13 83/09/14 14:14:09 edward 25 24
c Off screen windows!!!!!!
e
s 00001/00001/00190
d D 3.12 83/09/01 13:00:07 edward 24 23
c moved ww_hasframe to the top
e
s 00011/00000/00180
d D 3.11 83/08/26 16:23:50 edward 23 22
c error reporting
e
s 00009/00007/00171
d D 3.10 83/08/19 17:32:37 edward 22 21
c moved fmap into struct ww and added WWO_FRAME to allocate it.
e
s 00002/00000/00176
d D 3.9 83/08/19 15:04:17 edward 21 20
c fake cursor
e
s 00002/00002/00174
d D 3.8 83/08/18 15:34:10 edward 20 19
c changed some shorts to ints
e
s 00003/00003/00173
d D 3.7 83/08/18 15:27:41 edward 19 18
c da and db flags now needed with scrolling
c and new WWT_TERMCAP scheme
e
s 00001/00000/00175
d D 3.6 83/08/17 17:40:52 edward 18 17
c better wrap around handling.
e
s 00015/00003/00160
d D 3.5 83/08/17 14:51:10 edward 17 16
c ww_availmodes and stuff
e
s 00003/00002/00160
d D 3.4 83/08/16 12:54:26 edward 16 15
c wwtouched added
e
s 00000/00001/00162
d D 3.3 83/08/15 18:14:19 edward 15 14
c tt cleanup
e
s 00058/00040/00105
d D 3.2 83/08/12 18:33:09 edward 14 13
c faster and better frames
e
s 00000/00000/00145
d D 3.1 83/08/11 17:21:25 edward 13 11
i 12
c last few day's work
e
s 00113/00040/00032
d D 2.1.1.1 83/08/09 18:34:31 edward 12 11
c mile stone
e
s 00000/00000/00072
d D 2.1 83/07/30 13:27:29 edward 11 9
c prepare for major change
e
s 00000/00000/00072
d R 1.10 83/07/30 12:29:39 edward 10 9
c branch-place-holder
e
s 00001/00001/00071
d D 1.9 83/07/29 18:22:10 edward 9 8
c wwwintty added, and turn off XTABS for the ptys.
e
s 00002/00001/00070
d D 1.8 83/07/28 15:50:18 edward 8 7
c ww_label added
e
s 00005/00003/00066
d D 1.7 83/07/28 13:05:48 edward 7 6
c CTRL stuff
e
s 00001/00000/00068
d D 1.6 83/07/27 14:33:09 edward 6 5
c io statistics
e
s 00012/00008/00056
d D 1.5 83/07/22 17:08:27 edward 5 4
c scrolling.
c uses Wscreensize() to get screen size.
c More intelligent framing.
c etc.
e
s 00000/00000/00064
d D 1.4 83/07/19 20:07:43 edward 4 3
c today's work
e
s 00024/00009/00040
d D 1.3 83/07/18 21:03:28 edward 3 2
c multiple window
e
s 00018/00012/00031
d D 1.2 83/07/17 15:42:34 edward 2 1
c 
e
s 00043/00000/00000
d D 1.1 83/07/12 17:21:09 edward 1 0
c date and time created 83/07/12 17:21:09 by edward
e
u
U
f b 
t
T
I 1
D 12
/*	%W% %E%		*/
E 12
I 12
/*
D 47
 *	%W% %E%	
E 47
I 47
D 59
 * %W% %G%	
E 47
 */
E 12

I 50
/*
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 59
I 59
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 64
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 64
I 64
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
E 64
 *
 *	%W% (Berkeley) %G%
E 59
 */

E 50
I 2
D 38
#include <stdio.h>
E 38
E 2
#include <sgtty.h>
I 38
#include <setjmp.h>
E 38
D 2
#include <curses.h>
E 2
I 2
D 12
#include "window.h"
E 12
I 12
D 15
#include "tt.h"
E 15
E 12
E 2

I 12
D 37
#define NWW	30
E 37
I 37
#define NWW	30		/* maximum number of windows */
E 37

I 34
	/* a rectangle */
E 34
E 12
I 5
struct ww_dim {
D 12
	short col;
	short row;
	short ncol;
	short nrow;
E 12
I 12
	int nr;			/* number of rows */
	int nc;			/* number of columns */
	int t, b;		/* top, bottom */
	int l, r;		/* left, right */
E 12
};

I 34
	/* a coordinate */
E 34
I 12
struct ww_pos {
	int r;			/* row */
	int c;			/* column */
};

I 34
	/* the window structure */
E 34
D 14
union ww_char {
	short c_w;		/* as a word */
	struct {
		char C_c;	/* the character part */
		char C_m;	/* the mode part */
	} c_un;
};
#define c_c c_un.C_c
#define c_m c_un.C_m

#define WWC_CMASK	0x00ff
#define WWC_MMASK	0xff00
#define WWC_MSHIFT	8

	/* c_m bits */
#define WWM_REV		0x01	/* reverse video */
#define WWM_BLK		0x02	/* blinking */
#define WWM_UL		0x04	/* underlined */
#define WWM_GLS		0x10	/* window only, glass, i.e. transparent */
#define WWM_COV		0x20	/* window only, covered */

E 14
E 12
E 5
struct ww {
I 49
		/* general flags and states */
	char ww_state;		/* state of window */
	char ww_oflags;		/* wwopen flags */

E 49
I 40
		/* information for overlap */
E 40
I 12
	struct ww *ww_forw;	/* doubly linked list, for overlapping info */
	struct ww *ww_back;
E 12
D 3
	int ww_state :4;
	int ww_wstate :4;
D 2
	int ww_touched :1;
	WINDOW *ww_win;
E 2
I 2
	int ww_insert :1;		/* insert mode */
	int ww_refresh:1;		/* force refresh after \n and others */
E 3
I 3
D 40
	char ww_state;		/* state of window creation */
D 12
	char ww_mode;		/* mode used to open this window */
E 12
	char ww_wstate;		/* state for printing charcters */
D 17
	int ww_insert :1;	/* insert mode, for printing */
D 12
	int ww_refresh :1;	/* force refresh after \n and others */
D 8
	char ww_ident;
E 8
I 8
	char ww_ident;		/* the window id */
	char *ww_label;		/* the user supplied label */
E 8
E 3
	Win *ww_win;
E 2
D 3
	int ww_row;
E 3
I 3
D 5
	int ww_row;		/* outside dimensions */
E 3
	int ww_col;
	int ww_nrow;
	int ww_ncol;
D 2
	int ww_x;
	int ww_y;
E 2
I 2
D 3
	int ww_pty;
E 3
I 3
	int ww_irow;		/* inside dimensions */
	int ww_icol;
	int ww_inrow;
	int ww_incol;
E 5
I 5
	struct ww_dim ww_o;	/* outside dimemsions */
	struct ww_dim ww_i;	/* inside dimemsions */
E 12
I 12
	int ww_mapnl :1;	/* map \n to \r\n */
	int ww_haspty :1;	/* has pty */
E 17
I 17
	char ww_modes;		/* current printing modes */
	char ww_insert :1;	/* insert mode, for printing */
	char ww_mapnl :1;	/* map \n to \r\n */
D 32
	char ww_haspty :1;	/* has pty */
E 32
I 21
	char ww_hascursor :1;	/* has fake cursor */
I 24
	char ww_hasframe :1;	/* frame it */
I 38
	char ww_nointr : 1;	/* wwwrite() not interruptable */
E 38
E 24
E 21
E 17
	char ww_index;		/* the index, for wwindex[] */
E 40
I 40
D 49
	char ww_state;		/* state of window */
E 49
	char ww_index;		/* the window index, for wwindex[] */
E 40
	char ww_order;		/* the overlapping order */
E 12
D 26
	struct ww_dim ww_w;	/* window dimemsions */
E 26
I 26

		/* sizes and positions */
	struct ww_dim ww_w;	/* window size and pos */
	struct ww_dim ww_b;	/* buffer size and pos */
E 26
I 25
	struct ww_dim ww_i;	/* the part inside the screen */
E 25
E 5
D 12
	int ww_pty;		/* pty or socket pair */
E 3
	int ww_tty;
	int ww_pid;
D 3
	int ww_newrow;			/* for cursor addressing */
E 3
	struct ww *ww_next;
I 5
	char ww_ttyname[11];
E 12
I 12
D 20
	short ww_nline;		/* size of the buffer */
	short ww_scroll;	/* where the window is relative to the buffer */
E 20
I 20
D 26
	int ww_nline;		/* size of the buffer */
	int ww_scroll;		/* where the window is relative to the buffer */
E 26
E 20
	struct ww_pos ww_cur;	/* the cursor position, relative to ww_w */
I 26

		/* arrays */
E 26
	char **ww_win;		/* the window */
	union ww_char **ww_buf;	/* the buffer */
D 31
	char **ww_cov;		/* the covered-by array */
E 31
I 22
	char **ww_fmap;		/* map for frame and box windows */
E 22
	short *ww_nvis;		/* how many ww_buf chars are visible per row */
I 26

I 40
		/* information for wwwrite() and company */
	char ww_wstate;		/* state for outputting characters */
	char ww_modes;		/* current display modes */
	char ww_insert;		/* insert mode */
	char ww_mapnl;		/* map \n to \r\n */
	char ww_noupdate;	/* don't do updates in wwwrite() */
	char ww_unctrl;		/* expand control characters */
	char ww_nointr;		/* wwwrite() not interruptable */
	char ww_hascursor;	/* has fake cursor */
D 49
	char ww_hasframe;	/* frame it */
E 49

E 40
I 28
D 38
		/* things for the window process */
E 38
I 38
		/* things for the window process and io */
E 38
E 28
E 26
D 41
	int ww_pty;		/* file descriptor of pty */
E 41
I 41
	char ww_ispty;		/* ww_pty is really a pty, not socket pair */
	char ww_stopped;	/* output stopped */
	int ww_pty;		/* file descriptor of pty or socket pair */
	int ww_socket;		/* other end of socket pair */
E 41
D 32
	int ww_tty;		/* . . . tty */
E 32
	int ww_pid;		/* pid of process, if WWS_HASPROC true */
D 14
	char ww_ttyname[11];	/* /dev/ttyp? */
E 14
I 14
	char ww_ttyname[11];	/* "/dev/ttyp?" */
I 37
	char *ww_ob;		/* output buffer */
	char *ww_obe;		/* end of ww_ob */
D 41
	char *ww_obp;		/* current position in ww_ob */
	int ww_obc;		/* character count */
D 38
	char ww_stopped;	/* flow control */
E 38
I 38
	char ww_stopped;	/* output stopped */
E 41
I 41
	char *ww_obp;		/* current read position in ww_ob */
	char *ww_obq;		/* current write position in ww_ob */
E 41
E 38
E 37
E 14
D 28
	/* below are things for the user */
E 28
I 28

		/* things for the user, they really don't belong here */
E 28
D 24
	char ww_hasframe :1;	/* frame it */
E 24
D 38
	char ww_center :1;	/* center the label */
E 38
I 38
D 49
	char ww_center;		/* center the label */
E 49
E 38
D 28
	int ww_id;		/* the user id */
E 28
I 28
D 40
	int ww_id;		/* the user window id */
E 40
I 40
	char ww_id;		/* the user window id */
I 49
	char ww_center;		/* center the label */
	char ww_hasframe;	/* frame it */
I 54
	char ww_keepopen;	/* keep it open after the process dies */
E 54
E 49
E 40
E 28
	char *ww_label;		/* the user supplied label */
I 28
D 49
	struct ww_pos ww_altpos;/* alternate position */
E 49
I 49
	struct ww_dim ww_alt;	/* alternate position and size */
E 49
E 28
E 12
E 5
};

I 34
	/* state of a tty */
E 34
I 12
D 14
	/* ww_state values */
#define WWS_INITIAL	0	/* just opened */
#define WWS_HASPROC	1	/* forked, in parent */
#define WWS_INCHILD	2	/* forked, in child */
#define WWS_DEAD	3	/* child died */

E 14
E 12
struct ww_tty {
E 2
	struct sgttyb ww_sgttyb;
	struct tchars ww_tchars;
	struct ltchars ww_ltchars;
	int ww_lmode;
	int ww_ldisc;
I 38
	int ww_fflags;
E 38
D 34
	int ww_pgrp;
E 34
D 2
	int ww_pty;
	int ww_tty;
	int ww_pid;
	struct ww *ww_next;
E 2
};

I 14
union ww_char {
	short c_w;		/* as a word */
	struct {
I 29
D 46
#ifndef O_SUN
E 46
I 46
D 53
#ifndef mc68000
E 53
I 53
D 60
#if defined(vax)
E 60
I 60
#if defined(vax) || defined(MIPSEL)
E 60
E 53
E 46
E 29
		char C_c;	/* the character part */
		char C_m;	/* the mode part */
I 29
#else
		char C_m;	/* the mode part */
		char C_c;	/* the character part */
#endif
E 29
	} c_un;
};
#define c_c c_un.C_c
#define c_m c_un.C_m

	/* parts of ww_char */
#define WWC_CMASK	0x00ff
#define WWC_MMASK	0xff00
#define WWC_MSHIFT	8

	/* c_m bits */
#define WWM_REV		0x01	/* reverse video */
#define WWM_BLK		0x02	/* blinking */
#define WWM_UL		0x04	/* underlined */
I 35
#define WWM_GRP		0x08	/* graphics */
E 35
D 52
#define WWM_GLS		0x10	/* window only, glass, i.e. transparent */
E 52
I 52
#define WWM_DIM		0x10	/* half intensity */
#define WWM_USR		0x20	/* user specified mode */
#define WWM_GLS		0x40	/* window only, glass, i.e., transparent */
E 52
D 31
#define WWM_COV		0x20	/* window only, covered */
E 31

	/* ww_state values */
#define WWS_INITIAL	0	/* just opened */
D 34
#define WWS_HASPROC	1	/* forked, in parent */
#define WWS_INCHILD	2	/* forked, in child */
E 34
I 34
#define WWS_HASPROC	1	/* has process on pty */
E 34
#define WWS_DEAD	3	/* child died */

E 14
I 3
D 12
	/* ww_state values */
E 3
#define WW_INITIAL	0
#define WW_HASPROC	1
#define WW_INCHILD	2
#define WW_DEAD		3
E 12
I 12
D 22
	/* flags to wwopen() */
#define WWO_PTY		0x01		/* want pty */
#define WWO_REVERSE	0x02		/* make it all reverse video */
#define WWO_GLASS	0x04		/* make it all glass */
E 12

I 14
	/* flags for wwfmap */
E 22
I 22
	/* flags for ww_fmap */
E 22
#define WWF_U		0x01
#define WWF_R		0x02
#define WWF_D		0x04
#define WWF_L		0x08
#define WWF_MASK	(WWF_U|WWF_R|WWF_D|WWF_L)
#define WWF_LABEL	0x40
#define WWF_TOP		0x80

I 22
	/* flags to wwopen() */
#define WWO_PTY		0x01		/* want pty */
D 41
#define WWO_REVERSE	0x02		/* make it all reverse video */
#define WWO_GLASS	0x04		/* make it all glass */
#define WWO_FRAME	0x08		/* this is a frame window */
E 41
I 41
#define WWO_SOCKET	0x02		/* want socket pair */
#define WWO_REVERSE	0x04		/* make it all reverse video */
#define WWO_GLASS	0x08		/* make it all glass */
#define WWO_FRAME	0x10		/* this is a frame window */
E 41

E 22
	/* special ww_index value */
#define WWX_NOBODY	NWW

I 33
	/* error codes */
E 33
I 23
#define WWE_NOERR	0
#define WWE_SYS		1		/* system error */
#define WWE_NOMEM	2		/* out of memory */
#define WWE_TOOMANY	3		/* too many windows */
#define WWE_NOPTY	4		/* no more ptys */
#define WWE_SIZE	5		/* bad window size */
#define WWE_BADTERM	6		/* bad terminal type */
#define WWE_CANTDO	7		/* dumb terminal */

I 33
	/* wwtouched[] bits */
#define WWU_TOUCHED	0x01		/* touched */
#define WWU_MAJOR	0x02		/* major change */

I 37
	/* the window structures */
E 37
E 33
E 23
E 14
I 3
D 12
	/* ww_mode values */
#define WW_PTY		0		/* has pty */
#define WW_SOCKET	1		/* has socket pair */
#define WW_NONE		2		/* has nothing */
E 12
I 12
struct ww wwhead;
D 14
struct ww *wwindex[NWW + 1];
E 14
I 14
struct ww *wwindex[NWW + 1];		/* last location is for wwnobody */
E 14
struct ww wwnobody;
D 14
#define WWX_NOBODY	NWW
E 14
E 12

I 37
	/* tty things */
E 37
E 3
D 7
#ifndef CTRL
#define CTRL(c)	('c'&0x1f)
#endif
E 7
I 7
D 12
#undef CTRL
#define CTRL(c)		('c'&0x1f)
#define DEL		0x7f
#define ISCTRL(c)	((c) < ' ' || (c) >= DEL)
E 12
I 12
D 14
struct ww_tty wwoldtty, wwnewtty, wwwintty;
E 14
I 14
struct ww_tty wwoldtty;		/* the old (saved) terminal settings */
struct ww_tty wwnewtty;		/* the new (current) terminal settings */
struct ww_tty wwwintty;		/* the terminal settings for windows */
char *wwterm;			/* the terminal name */
char wwtermcap[1024];		/* place for the termcap */
D 63
char wwkeys[512];		/* termcap fields for the function keys */
E 63
I 39
D 56
char wwwintermcap[1024];	/* termcap for windows */
E 56
E 39
E 14
E 12
E 7

I 37
	/* generally useful variables */
E 37
D 3
struct ww *wwopen();

E 3
D 2
extern struct ww *_wwhead, *_wwcurrent;
E 2
I 2
D 12
extern struct ww *wwhead, *curwin;
D 9
extern struct ww_tty wwoldtty, wwnewtty;
E 9
I 9
extern struct ww_tty wwoldtty, wwnewtty, wwwintty;
E 9
extern int wwnwrite;
I 6
extern int wwnwritec;
E 6
I 5
extern int wwnrow, wwncol;		/* the screen size */
E 12
I 12
D 14
char *wwterm;
char wwtermcap[1024];
char wwkeys[512];
E 14
int wwnrow, wwncol;		/* the screen size */
I 17
char wwavailmodes;		/* actually supported modes */
I 21
char wwcursormodes;		/* the modes for the fake cursor */
E 21
I 18
char wwwrap;			/* terminal has auto wrap around */
E 18
E 17
D 14
int wwcursorrow, wwcursorcol;	/* the terminal cursor position */
int wwdtablesize;
E 14
I 14
int wwdtablesize;		/* result of getdtablesize() call */
E 14
char **wwsmap;			/* the screen map */
D 14
union ww_char **wwns;
union ww_char **wwos;
int wwbaud;
int wwbaudmap[];
E 14
I 14
D 22
char **wwfmap;			/* the frame map */
E 22
union ww_char **wwos;		/* the old (current) screen */
union ww_char **wwns;		/* the new (desired) screen */
I 16
char *wwtouched;		/* wwns changed flags */
E 16
D 57
int wwbaudmap[];		/* maps stty() baud rate code into number */
E 57
I 57
extern int wwbaudmap[];		/* maps stty() baud rate code into number */
E 57
int wwbaud;			/* wwbaudmap[wwoldtty.ww_sgttyb.sg_ospeed] */
int wwcursorrow, wwcursorcol;	/* where we want the cursor to be */
I 23
int wwerrno;			/* error number */
E 23
E 14
E 12
E 5
E 2

D 2
#define wwputchar(c)	wwputc((c), _wwcurrent)
#define wwputstr(s)	wwputs((s), _wwcurrent)
E 2
I 2
D 12
#define wwputchar(c)	wwputc((c), curwin)
#define wwputstr(s)	wwputs((s), curwin)
I 3
#define wwsetcursor(r,c) (WRCurRow = (r), WRCurCol = (c))
#define wwflush()	Wrefresh(1)
E 12
I 12
	/* statistics */
D 16
int wwnwrite;
int wwnwritec;
E 16
I 16
D 38
int wwnwrite, wwnwritec;
E 38
I 38
int wwnflush, wwnwr, wwnwre, wwnwrz, wwnwrc;
int wwnwwr, wwnwwra, wwnwwrc;
E 38
D 33
int wwnupdate, wwntouched, wwnmiss;
E 33
I 33
int wwnupdate, wwnupdline, wwnupdmiss, wwnmajline, wwnmajmiss;
I 37
int wwnread, wwnreade, wwnreadz, wwnreadc;
int wwnwread, wwnwreade, wwnwreadz, wwnwreadd, wwnwreadc, wwnwreadp;
int wwnselect, wwnselecte, wwnselectz;
E 37
E 33
E 16
E 12

I 14
	/* quicky macros */
I 41
D 42
#define wwbell()	write(1, "\7", 1)
E 42
E 41
E 14
I 12
D 26
#define wwcurrow(w)	((w)->ww_cur.r + (w)->ww_w.t)
#define wwcurcol(w)	((w)->ww_cur.c + (w)->ww_w.l)
E 26
#define wwsetcursor(r,c) (wwcursorrow = (r), wwcursorcol = (c))
D 26
#define wwcurtowin(w)	wwsetcursor(wwcurrow(w), wwcurcol(w))
E 26
I 26
#define wwcurtowin(w)	wwsetcursor((w)->ww_cur.r, (w)->ww_cur.c)
E 26
D 38
#define wwbell()	putchar(CTRL(g))
E 38
I 22
#define wwunbox(w)	wwunframe(w)
I 26
#define wwclreol(w,r,c)	wwclreol1((w), (r), (c), 0)
I 27
#define wwredrawwin(w)	wwredrawwin1((w), (w)->ww_i.t, (w)->ww_i.b, 0)
I 38
#define wwupdate()	wwupdate1(0, wwnrow);
E 38
I 37

	/* things for handling input */
I 38
int wwrint();		/* interrupt handler */
struct ww *wwcurwin;	/* window to copy input into */
D 55
char wwsetjmp;		/* want a longjmp() from wwrint() */
jmp_buf wwjmpbuf;	/* jmpbuf for above */
E 55
E 38
char *wwib;		/* input (keyboard) buffer */
char *wwibe;		/* wwib + sizeof buffer */
D 38
char *wwibp;		/* current position in buffer */
int wwibc;		/* character count */
#define wwgetc()	(wwibc ? wwibc--, *wwibp++&0x7f : -1)
#define wwpeekc()	(wwibc ? *wwibp&0x7f : -1)
#define wwungetc(c)	(wwibp > wwib ? wwibc++, *--wwibp = (c) : -1)
E 38
I 38
char *wwibp;		/* current read position in buffer */
char *wwibq;		/* current write position in buffer */
#define wwgetc()	(wwibp < wwibq ? *wwibp++ & 0x7f : -1)
#define wwpeekc()	(wwibp < wwibq ? *wwibp & 0x7f : -1)
#define wwungetc(c)	(wwibp > wwib ? *--wwibp = (c) : -1)
D 55
#define wwinterrupt()	(wwibp < wwibq)
E 55
I 55

	/* things for short circuiting wwiomux() */
char wwintr;		/* interrupting */
char wwsetjmp;		/* want a longjmp() from wwrint() and wwchild() */
jmp_buf wwjmpbuf;	/* jmpbuf for above */
#define wwinterrupt()	wwintr
#define wwsetintr()	(wwintr = 1, wwsetjmp ? longjmp(wwjmpbuf, 1) : 0)
#define wwclrintr()	(wwintr = 0)
E 55
E 38
E 37
E 27
E 26
E 22
I 17

	/* the window virtual terminal */
D 61
#define WWT_TERM	"TERM=window"
D 19
#define WWT_TERMCAP	"TERMCAP=WW|window|window package:\
E 19
I 19
D 52
#define WWT_TERMCAP	"WW|window|window package:\
E 52
I 52
#define WWT_TERMCAP	"WW|window|window program:\
E 61
I 61
D 62
#define WWT_TERM	"TERM=window-v2"	/* version 2 */
#define WWT_TERMCAP	"WW|window-v2|window program:\
E 62
I 62
#define WWT_TERM	"window-v2"
#define WWT_TERMCAP	"WW|window-v2|window program version 2:\
E 62
E 61
E 52
E 19
D 63
	:cr=^M:nl=^J:bl=^G:\
D 19
	:al=\\EL:am:le=^H:bs:cd=\\EJ:ce=\\EK:cl=\\EE:cm=\\EY%%+ %%+ :\
	:co#%d:dc=\\EN:dl=\\EM:do=\\EB:ei=\\EO:ho=\\EH:li#%d:im=\\E@:mi:\
E 19
I 19
	:al=\\EL:am:le=^H:bs:cd=\\EJ:ce=\\EK:cl=\\EE:cm=\\EY%+ %+ :\
	:da:db:dc=\\EN:dl=\\EM:do=\\EB:ei=\\EO:ho=\\EH:im=\\E@:mi:\
E 19
D 52
	:nd=\\EC:ta=^I:pt:up=\\EA:"
#define WWT_REV		"se=\\Eq:so=\\Ep:"
#define WWT_UL		"ue=\\Es:us=\\Er:"
I 36
#define WWT_GRP		"ae=\\EG:as=\\EF:"
E 52
I 52
	:nd=\\EC:ta=^I:pt:up=\\EA:me=\\Er^?:"
E 63
I 63
	:am:bs:da:db:ms:pt:cr=^M:nl=^J:bl=^G:ta=^I:\
	:cm=\\EY%+ %+ :le=^H:nd=\\EC:up=\\EA:do=\\EB:ho=\\EH:\
	:cd=\\EJ:ce=\\EK:cl=\\EE:me=\\Er^?:"
E 63
#define WWT_REV		"se=\\ErA:so=\\EsA:mr=\\EsA:"
#define WWT_BLK		"BE=\\ErB:BS=\\EsB:mb=\\EsB:"
#define WWT_UL		"ue=\\ErD:us=\\EsD:"
#define WWT_GRP		"ae=\\ErH:as=\\EsH:"
#define WWT_DIM		"HE=\\ErP:HS=\\EsP:mh=\\EsP:"
#define WWT_USR		"XE=\\Er`:XS=\\Es`:"
I 63
#define WWT_ALDL	"al=\\EL:dl=\\EM:"
#define WWT_IMEI	"im=\\E@:ei=\\EO:mi:"
#define WWT_DC		"dc=\\EN:"
char wwwintermcap[1024];	/* terminal-specific but window-independent
				   part of the window termcap */
E 63
E 52
E 36
E 17

I 14
	/* our functions */
E 14
E 12
struct ww *wwopen();
D 40
struct ww *wwfind();
E 40
int wwchild();
I 12
int wwsuspend();
E 12
I 7
D 40
char *unctrl();
E 40
I 12
char **wwalloc();
I 23
char *wwerror();
E 23

I 14
	/* c library functions */
E 14
char *malloc();
char *calloc();
char *getenv();
char *tgetstr();
char *rindex();
char *strcpy();
char *strcat();
I 38
D 58
char *sprintf();
E 58
E 38

#undef MIN
#undef MAX
#define MIN(x, y)	((x) > (y) ? (y) : (x))
#define MAX(x, y)	((x) > (y) ? (x) : (y))
D 40

#undef CTRL
#define CTRL(c)		('c'&0x1f)
#define DEL		0x7f
D 38
#define ISCTRL(c)	((c) < ' ' || (c) >= DEL)
E 38
I 38
#define ISCTRL(c)	((c) < ' ' & (c) != '\t' || (c) >= DEL)
E 40
E 38
I 30
D 48

D 43
#if defined(O_4_1A)||defined(O_4_1C)
int (*sigset)();
#define signal(s, v)	sigset((s), (v))
I 32
#else
E 43
#define sigmask(s)	(1 << (s) - 1)
E 48
D 43
#define sighold(s)	sigblock(sigmask(s))
#define sigrelse(s)	sigsetmask(sigblock(0) & ~sigmask(s))
E 32
#endif
E 43
E 30
E 12
E 7
E 3
E 2
E 1
