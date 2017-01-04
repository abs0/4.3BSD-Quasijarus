h10589
s 00068/00000/00000
d D 7.1 04/02/23 00:21:40 msokolov 1 0
c started LK201 module, what's written so far compiles
e
u
U
t
T
I 1
/*
 * Definitions for the LK201 protocol
 *
 *	%W% (Berkeley) %G%
 */

/* Codes transmitted by the keyboard */
#define	LK_FIRSTOPER	0x40	/* 1st operational, everything below powerup */
#define	LK_F1		0x56	/* function, keypad, and arrow ranges are */
#define	LK_LASTFUNC	0x8F	/* decoded by tables */
#define	LK_FIRSTKP	0x92
#define	LK_LASTKP	0xA4
#define	LK_FIRSTARROW	0xA7
#define	LK_LASTARROW	0xAA
#define	LK_SHIFT	0xAE
#define	LK_CTRL		0xAF
#define	LK_LOCK		0xB0
#define	LK_COMPOSE	0xB1
#define	LK_ALLUPS	0xB3
#define	LK_REPEAT	0xB4	/* called metronome in the spec */
#define	LK_OUTERR	0xB5
#define	LK_INERR	0xB6
#define	LK_LOCKACK	0xB7	/* kbd locked ack */
#define	LK_TMACK	0xB8	/* test mode ack */
#define	LK_KEYSDOWN	0xB9	/* prefix to keys down on entry to down/up */
#define	LK_MCHGACK	0xBA	/* mode change ack */
#define	LK_DELETE	0xBC
#define	LK_RETURN	0xBD
#define	LK_TAB		0xBE
#define	LK_FIRSTMAIN	0xBF	/* from here to FF, decoded by tables */
#define	LK_E00		0xBF
#define	LK_B00		0xC9

/* Commands that can be sent to the keyboard */
#define	LKCMD_RESUME		0x8B
#define	LKCMD_INHIBIT		0x89
#define	LKCMD_LEDON		0x13
#define	LKCMD_LEDOFF		0x11
#define	LKCMD_DISKEYCLICK	0x99	/* disable keyclick */
#define	LKCMD_ENKEYCLICK	0x1B	/* enable keyclick */
#define	LKCMD_DISCTRLKEYCLICK	0xB9	/* disable Ctrl keyclick */
#define	LKCMD_ENCTRLKEYCLICK	0xBB	/* enable Ctrl keyclick */
#define	LKCMD_SNDKEYCLICK	0x9F	/* sound keyclick */
#define	LKCMD_DISBELL		0xA1	/* disable bell */
#define	LKCMD_ENBELL		0x23	/* enable bell */
#define	LKCMD_SNDBELL		0xA7	/* sound bell */
#define	LKCMD_STOPREPEAT	0xC1	/* stop autorepeat of current key */
#define	LKCMD_ENREPEAT		0xE3	/* enable autorepeat */
#define	LKCMD_DISREPEAT		0xE1	/* disable autorepeat */
#define	LKCMD_CHGTODOWN		0xD9	/* change all autorepeat to down-only */
#define	LKCMD_REQKBDID		0xAB	/* request keyboard ID */
#define	LKCMD_RESET		0xFD	/* jump to power-up */
#define	LKCMD_TESTMODE		0xCB	/* jump to test mode */
#define	LKCMD_DEFAULTS		0xD3	/* reinstate defaults */
/* second command bytes to be sent after LKCMD_LEDON and LKCMD_LEDOFF */
#define	LKCMD_HOLDLED		0x88
#define	LKCMD_LOCKLED		0x84
#define	LKCMD_COMPOSELED	0x82
#define	LKCMD_WAITLED		0x81
#define	LKCMD_ALLLEDS		0x8F
/* set transmission mode command */
#define	LKCMD_TRANSMODE(div,mode)	(0x80 | (div) << 3 | (mode) << 1)
#define	LKCMD_TRANSMODEP(div,mode)	((div) << 3 | (mode) << 1)
#define	LKTMODE_DOWNONLY	0
#define	LKTMODE_AUTOREPEAT	1
#define	LKTMODE_DOWNUP		2
/* Setting autorepeat rate buffers. Send the command followed by two params. */
#define	LKCMD_SETRPTRATEBUF(buf)	(0x78 | (buf) << 1)
E 1
