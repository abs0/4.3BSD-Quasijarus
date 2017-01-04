h10191
s 00014/00002/00131
d D 3.2 88/03/28 12:34:14 bostic 7 6
c add Berkeley specific header
e
s 00000/00000/00133
d D 3.1 87/08/11 10:18:54 minshall 6 5
c New version numbering.
e
s 00002/00000/00131
d D 1.5 87/07/17 10:03:27 minshall 5 4
c Install sccs headers and copyright notices.
e
s 00013/00000/00118
d D 1.4 87/05/24 16:50:06 minshall 4 3
c AcceptKeyboard, and globally known bits for shiftstate 
c (and a 'make depend').
e
s 00002/00001/00116
d D 1.3 87/03/23 10:40:14 minshall 3 2
c This is the way 3270's really work.
e
s 00105/00077/00012
d D 1.2 86/11/16 15:21:29 minshall 2 1
c Turn FCN_... into enum, rather than  #define's.
e
s 00089/00000/00000
d D 1.1 86/11/11 22:54:13 minshall 1 0
c date and time created 86/11/11 22:54:13 by minshall
e
u
U
t
T
I 1
/*
I 7
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
E 7
I 2
 * The following are the various functions which the keyboard can ask
 * the controller to perform.
 *
 * Note that this file (the following entries) are scanned by mkhit.c,
 * and that the format must remain more-or-less consistent
 * [ \t]*TOKEN
I 5
D 7
 *
 * %W% (Berkeley) %G%
E 7
E 5
 */

enum ctlrfcn {

	undefined = 0,			/* Not yet touched */

	FCN_NULL,	  		/* Illegal sequence */

	FCN_RESET,			/* unlock keyboard */
D 3
	FCN_CAPS_LOCK,
E 3
I 3
	FCN_MAKE_SHIFT_LOCK,
	FCN_BREAK_SHIFT_LOCK,
E 3

	FCN_MAKE_SHIFT,			/* shift key pressed DOWN */
	FCN_BREAK_SHIFT,		/* shift key released */

	FCN_MAKE_ALT,			/* alt key pressed DOWN */
	FCN_BREAK_ALT,			/* alt key released */

	FCN_MAKE_CTRL,

I 4
	FCN_CAPS_LOCK,

E 4
	FCN_MONOCASE,			/* DISPLAY in upper case */
	FCN_DVCNL,

	FCN_CHARACTER,			/* Not one of the following, but ... */
	FCN_VERTICAL_BAR,		/* EBCDIC solid vertical bar */
	FCN_CENTSIGN,			/* EBCDIC cent sign */
	FCN_SPACE,			/* EBCDIC space */
	FCN_DP,				/* EBCDIC dup character */
	FCN_FM,				/* EBCDIC field mark */

	FCN_AID,			/* Some AID key */
	FCN_ATTN,
	FCN_CURSEL,			/* Cursor select function (and aid) */
	FCN_TEST,			/* Test function */

	FCN_EINP,			/* erase input (dangerous) */
	FCN_EEOF,
	FCN_DELETE,
	FCN_INSRT,
	FCN_TAB,
	FCN_BTAB,
	FCN_NL,
	FCN_HOME,
	FCN_UP,
	FCN_DOWN,
	FCN_RIGHT,
	FCN_LEFT,
	FCN_LEFT2,
	FCN_RIGHT2,

#if	!defined(PURE3274)
	/*
	 * Local editing functions
	 */
	FCN_SETTAB,			/* set a column tab */
	FCN_DELTAB,
	FCN_COLTAB,
	FCN_COLBAK,
	FCN_INDENT,			/* more margin over one col tab */
	FCN_UNDENT,
	FCN_SETMRG,
	FCN_SETHOM,
	FCN_CLRTAB,
	FCN_ERASE,			/* erase last character */
	FCN_WERASE,
	FCN_FERASE,
	FCN_WORDTAB,			/* tab to start of next word */
	FCN_WORDBACKTAB,
	FCN_WORDEND,			/* find next end of word */
	FCN_FIELDEND,			/* find next end of field */

	/*
	 * APL functions
	 */
	FCN_APLON,			/* start using apl character set */
	FCN_APLOFF,
	FCN_APLEND,

	FCN_PCON,
	FCN_PCOFF,
	FCN_INIT,			/* re-init screen */
	FCN_SYNCH,			/* synch up after line/control error */
	FCN_FLINP,			/* flush input buffer */
	FCN_RESHOW,			/* redraw screen */
	FCN_MASTER_RESET,		/* FLINP, RESET, RESHOW, + more */

	FCN_DISC,			/* suspend application */
	FCN_ESCAPE,			/* enter command mode */

	FCN_ALTK,			/* Dvorak keyboard */

	FCN_XOFF,			/* suspend output to screen */
	FCN_XON,			/* resume output to screen */

	FCN_LPRT			/* print screen on printer */
#endif	/* !defined(PURE3274) */
};
/*
E 2
 * The following is the structure which defines what a 3270 keystroke
 * can do.
 */

struct hits {
    unsigned char keynumber;
    struct hit {
D 2
	enum type { undefined = 0, illegal, character, function, aid } type;
	unsigned char code;	/* AID value; 3270 display code; function id */
E 2
I 2
	enum ctlrfcn ctlrfcn;
	unsigned char code;	/* AID value or 3270 display code */
E 2
    } hit[4];	/* plain, shifted, alted, shiftalted */
};

extern struct hits hits[];
I 4

/*
 * Definitions of the shift state (and the left/right shift key position).
 */

#define	SHIFT_RIGHT	0x20	/* Right shift key is down */
#define	SHIFT_LEFT	0x10	/* Left shift key is down */
#define	SHIFT_CONTROL	0x08	/* Control shift state (unused) */
#define	SHIFT_ALT	0x04	/* ALT shift state */
#define	SHIFT_CAPS	0x02	/* Caps lock state */
#define	SHIFT_UPSHIFT	0x01	/* Upshift state */
E 4
D 2


/*
 * The following are the various functions which the keyboard can ask
 * the controller to perform.
 *
 * Note that this file (the following entries) are scanned by mkhit.c,
 * and that the format must remain more-or-less consistent
 * (#define\tFCN_name\t[\t]*TOKEN)
 */

#define	FCN_NULL		131  		/* Illegal sequence */
#define	FCN_VERTICAL_BAR	132
#define	FCN_CAPS_LOCK		134
#define	FCN_MAKE_SHIFT		135
#define	FCN_DVCNL		136
#define	FCN_MAKE_ALT		137
#define	FCN_SPACE		138
#define	FCN_LEFT2		139
#define	FCN_RIGHT2		140
#define	FCN_MONOCASE		141
#define	FCN_BREAK_SHIFT		142
#define	FCN_BREAK_ALT		143
#define	FCN_ATTN		144
#define	FCN_LPRT		145
#define	FCN_DP			146
#define	FCN_FM			147
#define	FCN_CURSEL		148
#define	FCN_CENTSIGN		149
#define	FCN_RESHOW		150
#define	FCN_EINP		151
#define	FCN_EEOF		152
#define	FCN_DELETE		153
#define	FCN_INSRT		154
#define	FCN_TAB			155
#define	FCN_BTAB		156
#define	FCN_COLTAB		157
#define	FCN_COLBAK		158
#define	FCN_INDENT		159
#define	FCN_UNDENT		160
#define	FCN_NL			161
#define	FCN_HOME		162
#define	FCN_UP			163
#define	FCN_DOWN		164
#define	FCN_RIGHT		165
#define	FCN_LEFT		166
#define	FCN_SETTAB		167
#define	FCN_DELTAB		168
#define	FCN_SETMRG		169
#define	FCN_SETHOM		170
#define	FCN_CLRTAB		171
#define	FCN_APLON		172
#define	FCN_APLOFF		173
#define	FCN_APLEND		174
#define	FCN_PCON		175
#define	FCN_PCOFF		176
#define	FCN_DISC		177
#define	FCN_INIT		178
#define	FCN_ALTK		179
#define	FCN_FLINP		180
#define	FCN_ERASE		181
#define	FCN_WERASE		182
#define	FCN_FERASE		183
#define	FCN_SYNCH		184
#define	FCN_RESET		185
#define	FCN_MASTER_RESET	186
#define	FCN_XOFF		187
#define	FCN_XON			188
#define	FCN_ESCAPE		189
#define	FCN_WORDTAB		190
#define	FCN_WORDBACKTAB		191
#define	FCN_WORDEND		192
#define	FCN_FIELDEND		193
#define	FCN_MAKE_CTRL		194
#define	FCN_TEST		195
E 2
E 1
