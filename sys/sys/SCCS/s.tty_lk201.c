h59296
s 00061/00025/00999
d D 7.4 04/02/28 21:19:56 msokolov 4 3
c fixes on first round of testing
e
s 00120/00000/00904
d D 7.3 04/02/27 02:03:34 msokolov 3 2
c add line discipline functions
e
s 00004/00002/00900
d D 7.2 04/02/26 18:52:29 msokolov 2 1
c check LKMODE_FORCEASCII before allowing Compose or RUS/META
e
s 00902/00000/00000
d D 7.1 04/02/23 00:21:08 msokolov 1 0
c started LK201 module, what's written so far compiles
e
u
U
t
T
I 1
/*
 * LK201 line discipline.
 *
 *	%W% (Berkeley) %G%
 */

#include "lk.h"
#if NLK
#include "param.h"
#include "systm.h"
#include "dir.h"
#include "user.h"
#include "ioctl.h"
#include "tty.h"
#include "proc.h"
#include "file.h"
#include "conf.h"
#include "dkstat.h"
#include "uio.h"
#include "kernel.h"
#include "malloc.h"
#include "lk201pr.h"
#include "lk201sc.h"

/*
 * This module turns the DEC LK201 keyboard into an IFCTF keyboard.  All LK201
 * keys are given their standard ASCII meaning, and Compose feature is supported
 * for entry of 8-bit characters (see below).  Arrow keys generate ISO standard
 * control sequences.  The keypad can operate in numeric or application mode
 * like on VT100, generating the same codes/sequences as on VT100.  All function
 * keys generate control sequences like on VT220 with some extensions.  In
 * general, the LK201 operates like the input half of VT220.
 *
 * ASCII input from the keyboard goes into a UNIX tty.  This module can be
 * activated by any user on any given tty, in which case the tty line is to be
 * connected to the LK201, and input goes into the input queue of the same tty
 * via ttyinput.  Workstation drivers in the kernel can also attach this module
 * in different ways so that the hardware which talks to the LK201 doesn't have
 * to presented as a tty, and the input can be routed to another tty that may
 * also handle workstation display output.
 *
 * Input in three charsets is supported: ASCII, ISO Latin-1 and KOI-8.  The base
 * keyboard always inputs ASCII and supports all 128 possible 7-bit characters.
 * If the tty receiving the input allows 8-bit input, Compose key is enabled and
 * 8-bit ISO Latin-1 characters can be entered.  Hex compose using the numeric
 * keypad is supported like on VT340 and VT420, which allows all 8-bit codes to
 * be entered, including C1.  (While 7-bit characters can also be entered via
 * Compose, it is intended for entering 8-bit ISO Latin-1 characters, and is
 * enabled only when the receiving tty allows 8-bit input.)
 *
 * An additional feature not offered by DEC is provided to enter 8-bit input in
 * Russian KOI-8 instead of Latin-1.  If the tty receiving the input is
 * configured for KOI-8, the Latin-1 Compose feature is not available (Latin-1
 * characters are garbage in KOI-8 environment) and the Compose key is redefined
 * as the KOI-8 RUS/LAT switch.  LAT mode is ASCII and in RUS mode Russian KOI-8
 * characters are entered per yawerty map.  Also in KOI-8 mode a Meta mode is
 * provided which temporarily supercedes the RUS/LAT mode, entered via
 * Shift-Compose.  In this mode the keyboard uses the standard 7-bit ASCII map
 * (with Shift, Caps Lock, and Ctrl working normally), but bit 7 is set.  Like
 * hexadecimal compose in Latin-1 mode, this feature allows all 8-bit codes to
 * be entered.
 *
 * The VT220-like operation of LK201 can be altered in two ways to make it more
 * UNIX-friendly.  One modification, originating in VT320, puts ESC at E00
 * (upper left corner of main keypad), moves the `~ key to B00 where DEC has put
 * <>, and puts '<>' over ',.'.  This modification makes the keyboard more like
 * traditional ASCII keyboards UNIX was designed for.  The other modification
 * makes the F11/12/13 keys generate ESC/BS/LF like in VT100 mode on VT2xx/3xx
 * terminals, while all other function keys generate their "canonical" VT2xx-
 * style control sequences.  This modification allows people to start taking
 * advantage of new VT2xx generation features while keeping the ESC/BS/LF
 * function of F11/12/13 keys from VT100 mode.  Finally, the character rubout
 * key generates the erase character set on the receiving tty.
 *
 * Autorepeat, bell and keyclick can be customised like on DEC products.  A note
 * about keyclicks though.  The LK201 is misdesigned in a way that makes very
 * clear why keyboards should be designed and built as IFCTF keyboards in
 * hardware.  LK201 was designed so that the host needs to configure it and then
 * for the most part let it take care of itself.  It implements both autorepeat
 * and keyclick internally so that in theory the host only needs to receive and
 * accept its transmissions without sending anything back on every key.
 *
 * The problem is that the keyboard doesn't know whether any given key has any
 * function or not in the application in use (in each combination of Ctrl and
 * Shift modifiers), and with the VT2xx/3xx terminals we've grown used to the
 * keyclick being generated only if the key is defined.  The keyboard isn't
 * really designed for host control of the keyclick either: while there is a
 * command to generate a keyclick, the keyboard is clearly designed for
 * automatic keyclick generation.  So how do the terminals do it?  Magic?
 * Well, they do a real kludge.  When the keyclicks are enabled in setup, the
 * LK201 is configured with keyclicks disabled.  When the terminal receives a
 * code for a pressed key, it checks whether that key is defined and thus
 * should sound a keyclick.  If a keyclick is needed, it sends a sequence to
 * the LK201 that enables the keyclicks (with the desired volume), sounds the
 * keyclick, and disables the keyclicks right away.  Of course this is ugly and
 * basically defeats the LK201 design.  (Actually this is so ugly that I just
 * couldn't believe that DEC terminals do it.  I had to sniff the traffic
 * between VT340 and LK201 to convince myself that it really does this.  It
 * really does unfortunately.)
 *
 * In this implementation I've decided not to bother with this and to let LK201
 * click on every key.  In this implementation almost all keys are always
 * defined and generate some code or sequence.  The only exceptions are Compose
 * in 7-bit only mode and some main keypad keys that are not defined with Ctrl.
 * Since these are rare exceptions and they are the only ones, I have decided
 * not to bother.
 */

/*
 * Translation tables
 *
 * For the main keypad we have 8 tables corresponding to all possible
 * combinations of {RUS,Caps Lock,Shift} (actually only 6 as Shift dominates
 * Caps Lock) and one more table for Ctrl (which overrides all other modes).
I 4
 *
 * NOTE: the code table in Appendix B of the VCB02 technical manual is wrong in
 * that the codes for the '" and , keys are swapped.
E 4
 */

u_char lk201_mainkeypad_table[] = {
	'`', '1', 'q', 'a', 'z', 0,   '2', 'w', 's', 'x', '<', 0,   '3', 'e',
	'd', 'c', 0,   '4', 'r', 'f', 'v', ' ', 0,   '5', 't', 'g', 'b', 0,
D 4
	'6', 'y', 'h', 'n', 0,   '7', 'u', 'j', 'm', 0,   '8', 'i', 'k', '\'',
E 4
I 4
	'6', 'y', 'h', 'n', 0,   '7', 'u', 'j', 'm', 0,   '8', 'i', 'k', ',',
E 4
	0,   '9', 'o', 'l', '.', 0,   '0', 'p', 0,   ';', '/', 0,   '=', ']',
D 4
	'\\',0,   '-', '[', ','
E 4
I 4
	'\\',0,   '-', '[', '\''
E 4
};

u_char lk201_mainkeypad_table_shift[] = {
D 4
	'`', '!', 'Q', 'A', 'Z', 0,   '@', 'W', 'S', 'X', '>', 0,   '#', 'E',
E 4
I 4
	'~', '!', 'Q', 'A', 'Z', 0,   '@', 'W', 'S', 'X', '>', 0,   '#', 'E',
E 4
	'D', 'C', 0,   '$', 'R', 'F', 'V', ' ', 0,   '%', 'T', 'G', 'B', 0,
D 4
	'^', 'Y', 'H', 'N', 0,   '&', 'U', 'J', 'M', 0,   '*', 'I', 'K', '\"',
E 4
I 4
	'^', 'Y', 'H', 'N', 0,   '&', 'U', 'J', 'M', 0,   '*', 'I', 'K', '<',
E 4
	0,   '(', 'O', 'L', '>', 0,   ')', 'P', 0,   ':', '?', 0,   '+', '}',
D 4
	'|', 0,   '_', '{', '<'
E 4
I 4
	'|', 0,   '_', '{', '\"'
E 4
};

u_char lk201_mainkeypad_table_caps[] = {
	'`', '1', 'Q', 'A', 'Z', 0,   '2', 'W', 'S', 'X', '<', 0,   '3', 'E',
	'D', 'C', 0,   '4', 'R', 'F', 'V', ' ', 0,   '5', 'T', 'G', 'B', 0,
D 4
	'6', 'Y', 'H', 'N', 0,   '7', 'U', 'J', 'M', 0,   '8', 'I', 'K', '\'',
E 4
I 4
	'6', 'Y', 'H', 'N', 0,   '7', 'U', 'J', 'M', 0,   '8', 'I', 'K', ',',
E 4
	0,   '9', 'O', 'L', '.', 0,   '0', 'P', 0,   ';', '/', 0,   '=', ']',
D 4
	'\\',0,   '-', '[', ','
E 4
I 4
	'\\',0,   '-', '[', '\''
E 4
};

u_char lk201_mainkeypad_table_rus[] = {
	0xC0, '1',  0xD1, 0xC1, 0xDA, 0,    '2',  0xD7, 0xD3, 0xD8, '<',  0,
	'3',  0xC5, 0xC4, 0xC3, 0,    '4',  0xD2, 0xC6, 0xD6, ' ',  0,    '5',
	0xD4, 0xC7, 0xC2, 0,    '6',  0xD9, 0xC8, 0xCE, 0,    '7',  0xD5, 0xCA,
D 4
	0xCD, 0,    '8',  0xC9, 0xCB, '\'', 0,    '9',  0xCF, 0xCC, '.',  0,
E 4
I 4
	0xCD, 0,    '8',  0xC9, 0xCB, ',',  0,    '9',  0xCF, 0xCC, '.',  0,
E 4
	'0',  0xD0, 0,    ';',  '/',  0,    0xDE, 0xDD, 0xDC, 0,    '-',  0xDB,
D 4
	','
E 4
I 4
	'\''
E 4
};

u_char lk201_mainkeypad_table_russhift[] = {
	0xE0, '!',  0xF1, 0xE1, 0xFA, 0,    '@',  0xF7, 0xF3, 0xF8, '>',  0,
	0xDF, 0xE5, 0xE4, 0xE3, 0,    0xFF, 0xF2, 0xE6, 0xF6, ' ',  0,    '%',
	0xF4, 0xE7, 0xE2, 0,    0xA3, 0xF9, 0xE8, 0xEE, 0,    0xB3, 0xF5, 0xEA,
D 4
	0xED, 0,    '(',  0xE9, 0xEB, '\"', 0,    ')',  0xEF, 0xEC, '>',  0,
E 4
I 4
	0xED, 0,    '(',  0xE9, 0xEB, '<',  0,    ')',  0xEF, 0xEC, '>',  0,
E 4
	'0',  0xF0, 0,    ':',  '?',  0,    0xFE, 0xFD, 0xFC, 0,    '_',  0xFB,
D 4
	'<'
E 4
I 4
	'\"'
E 4
};

u_char lk201_mainkeypad_table_ruscaps[] = {
	0xE0, '1',  0xF1, 0xE1, 0xFA, 0,    '2',  0xF7, 0xF3, 0xF8, '<',  0,
	'3',  0xE5, 0xE4, 0xE3, 0,    '4',  0xF2, 0xE6, 0xF6, ' ',  0,    '5',
	0xF4, 0xE7, 0xE2, 0,    '6',  0xF9, 0xE8, 0xEE, 0,    '7',  0xF5, 0xEA,
D 4
	0xED, 0,    '8',  0xE9, 0xEB, '\'', 0,    '9',  0xEF, 0xEC, '.',  0,
E 4
I 4
	0xED, 0,    '8',  0xE9, 0xEB, ',',  0,    '9',  0xEF, 0xEC, '.',  0,
E 4
	'0',  0xF0, 0,    ';',  '/',  0,    0xFE, 0xFD, 0xFC, 0,    '-',  0xFB,
D 4
	','
E 4
I 4
	'\''
E 4
};

u_char *lk201_mainkeypad_tables[] = {
	lk201_mainkeypad_table,
	lk201_mainkeypad_table_shift,
	lk201_mainkeypad_table_caps,
	lk201_mainkeypad_table_shift,
	lk201_mainkeypad_table_rus,
	lk201_mainkeypad_table_russhift,
	lk201_mainkeypad_table_ruscaps,
	lk201_mainkeypad_table_russhift
};

u_char lk201_mainkeypad_table_ctrl[] = {
	0x1E, 0,    0x11, 0x01, 0x1A, 0,    0x80, 0x17, 0x13, 0x18, 0,    0,
	0x1B, 0x05, 0x04, 0x03, 0,    0x1C, 0x12, 0x06, 0x16, 0x80, 0,    0x1D,
	0x14, 0x07, 0x02, 0,    0x1E, 0x19, 0x08, 0x0E, 0,    0x1F, 0x15, 0x0A,
	0x0D, 0,    0x7F, 0x09, 0x0B, 0,    0,    0,    0x0F, 0x0C, 0,    0,
	0,    0x10, 0,    0,    0x1F, 0,    0,    0x1D, 0x1C, 0,    0,    0x1B,
	0
};

/*
 * Arrow keys
 * These generate ISO control sequences consisting of CSI and a letter in [A-D].
 * The table stores just the letter.
 */
u_char lk201_arrowkeys_table[4] = {'D', 'C', 'B', 'A'};

/*
 * Numeric keypad
 *
 * We have three tables for this one: numeric, application and hex compose.  In
 * numeric and application modes we can generate ASCII or SS3 characters
 * (mixture of the two in numeric mode, SS3 only in application mode).  We keep
 * just one character in the table and the code figures out whether it's ASCII
 * or SS3 based on knowledge that numeric keypad ASCII codes are in the digit
 * range whereas SS3 codes are in the letter range.
 *
 * For hex compose we store 8x (x = hex digit) for valid hex digits and 0 for
 * '.' and Enter.  If the operator presses '.' or Enter while in Compose, we
 * handle it like all other special keys: cancel Compose and take the special
 * key's normal action.  VT340 and VT420 do the same.
 */

u_char lk201_keypad_numeric[] = {
	'0', 0,   '.', 0x0D,'1', '2', '3', '4', '5', '6', ',', '7', '8', '9',
	'-', 'P', 'Q', 'R', 'S'
};

u_char lk201_keypad_application[] = {
	'p', 0,   'n', 'M' ,'q', 'r', 's', 't', 'u', 'v', 'l', 'w', 'x', 'y',
	'm', 'P', 'Q', 'R', 'S'
};

u_char lk201_keypad_hexcompose[] = {
	0x80, 0,    0,    0,    0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x8F, 0x87,
	0x88, 0x89, 0x8E, 0x8A, 0x8B, 0x8C, 0x8D
};

/*
 * Function keys
 *
 * Each of these keys transmits CSI n ~ where n is a number transmitted in
 * decimal digits.  We store n values in the table.
 */
u_char lk201_funckeys_table[] = {
	11, 12, 13, 14, 15, 0,  0,  0,  0,  0,  0,  0,  0,  0,  17, 18, 19, 20,
	21, 0,  0,  0,  0,  0,  0,  0,  0,  23, 24, 25, 26, 0,  0,  0,  0,  0,
	0,  0,  28, 29, 0,  0,  31, 32, 33, 34, 0,  0,  0,  0,  0,  0,  1,  2,
	3,  4,  5,  6
};

/*
 * Compose sequences.
 *
 * We support exactly the same ones as VT320 and VT420.  Our struct includes a
 * case mask to support case-insensitive compose sequences and a flag indicating
 * if the sequence should also be accepted in reversed form.
 */
struct comptbl {
	u_short	sequence;
	u_short casemask;
	char	reverseok;
	u_char	character;
} lk201_compose_table[] = {
	/* ISO Latin-1 characters from A0 through FF */
	0x2020,	0,	0,	0xA0,	/*    */
	0x2121,	0,	0,	0xA1,	/* !! */
	0x632F,	0x2000,	1,	0xA2,	/* c/ */
	0x637C,	0x2000,	1,	0xA2,	/* c| */
	0x6C2D,	0x2000,	1,	0xA3,	/* l- */
	0x6C3D,	0x2000,	1,	0xA3,	/* l= */
	0x786F,	0x2020,	1,	0xA4,	/* xo */
	0x7830,	0x2000,	1,	0xA4,	/* x0 */
	0x792D,	0x2000,	1,	0xA5,	/* y- */
	0x793D,	0x2000,	1,	0xA5,	/* y= */
	0x7C7C,	0,	0,	0xA6,	/* || */
	0x215E,	0,	1,	0xA6,	/* !^ */
	0x736F,	0x2020,	1,	0xA7,	/* so */
	0x7321,	0x2000,	1,	0xA7,	/* s! */
	0x7330,	0x2000,	1,	0xA7,	/* s0 */
	/*
	 * Diaeresis is an ISO extension.  VT320 manual lists the compose
	 * sequence as "".  In actuality in addition to "" VT320 maps "(sp) to
	 * ISO diaeresis when in ISO mode.  This is better documented in the
	 * VT420 manual.
	 */
	0x2222,	0,	0,	0xA8,	/* "" */
	0x2220,	0,	1,	0xA8,	/* "  */
	0x636F,	0x2020,	1,	0xA9,	/* co */
	0x6330,	0x2000,	1,	0xA9,	/* c0 */
	0x615F,	0x2000,	1,	0xAA,	/* a_ */
	0x3C3C,	0,	0,	0xAB,	/* << */
	0x2D2C,	0,	0,	0xAC,	/* -, */
	0x2D2D,	0,	0,	0xAD,	/* -- */
	0x726F,	0x2020,	1,	0xAE,	/* ro */
	0x7230,	0x2000,	1,	0xAE,	/* r0 */
	0x2D5E,	0,	1,	0xAF,	/* -^ */
	0x5F5E,	0,	1,	0xAF,	/* _^ not documented */
	0x305E,	0,	1,	0xB0,	/* 0^ */
	0x2B2D,	0,	1,	0xB1,	/* +- */
	0x325E,	0,	1,	0xB2,	/* 2^ */
	0x335E,	0,	1,	0xB3,	/* 3^ */
	0x2727,	0,	0,	0xB4,	/* '' */
	0x2F75,	0,	0,	0xB5,	/* /u */
	0x7021,	0x2000,	1,	0xB6,	/* p! */
	0x2E5E,	0,	1,	0xB7,	/* .^ */
	0x2C2C,	0,	0,	0xB8,	/* ,, */
	0x315E,	0,	1,	0xB9,	/* 1^ */
	0x6F5F,	0x2000,	1,	0xBA,	/* o_ */
	0x3E3E,	0,	0,	0xBB,	/* >> */
	0x3134,	0,	0,	0xBC,	/* 14 */
	0x3132,	0,	0,	0xBD,	/* 12 */
	0x3334,	0,	0,	0xBE,	/* 34 */
	0x3F3F,	0,	0,	0xBF,	/* ?? */
	0x4160,	0,	1,	0xC0,	/* A` */
	0x4127,	0,	1,	0xC1,	/* A' */
	0x415E,	0,	1,	0xC2,	/* A^ */
	0x417E,	0,	1,	0xC3,	/* A~ */
	0x4122,	0,	1,	0xC4,	/* A" */
	0x412A,	0,	1,	0xC5,	/* A* */
	0x4145,	0,	0,	0xC6,	/* AE */
	0x432C,	0,	1,	0xC7,	/* C, */
	0x4560,	0,	1,	0xC8,	/* E` */
	0x4527,	0,	1,	0xC9,	/* E' */
	0x455E,	0,	1,	0xCA,	/* E^ */
	0x4522,	0,	1,	0xCB,	/* E" */
	0x4960,	0,	1,	0xCC,	/* I` */
	0x4927,	0,	1,	0xCD,	/* I' */
	0x495E,	0,	1,	0xCE,	/* I^ */
	0x4922,	0,	1,	0xCF,	/* I" */
	0x2D44,	0,	1,	0xD0,	/* -D */
	0x4E7E,	0,	1,	0xD1,	/* N~ */
	0x4F60,	0,	1,	0xD2,	/* O` */
	0x4F27,	0,	1,	0xD3,	/* O' */
	0x4F5E,	0,	1,	0xD4,	/* O^ */
	0x4F7E,	0,	1,	0xD5,	/* O~ */
	0x4F22,	0,	1,	0xD6,	/* O" */
	0x7878,	0,	0,	0xD7,	/* xx */
	0x4F2F,	0,	1,	0xD8,	/* O/ */
	0x5560,	0,	1,	0xD9,	/* U` */
	0x5527,	0,	1,	0xDA,	/* U' */
	0x555E,	0,	1,	0xDB,	/* U^ */
	0x5522,	0,	1,	0xDC,	/* U" */
	0x5927,	0,	1,	0xDD,	/* Y' */
	0x5448,	0,	0,	0xDE,	/* TH */
	0x7373,	0,	0,	0xDF,	/* ss */
	0x6160,	0,	1,	0xE0,	/* a` */
	0x6127,	0,	1,	0xE1,	/* a' */
	0x615E,	0,	1,	0xE2,	/* a^ */
	0x617E,	0,	1,	0xE3,	/* a~ */
	0x6122,	0,	1,	0xE4,	/* a" */
	0x612A,	0,	1,	0xE5,	/* a* */
	0x6165,	0,	0,	0xE6,	/* ae */
	0x632C,	0,	1,	0xE7,	/* c, */
	0x6560,	0,	1,	0xE8,	/* e` */
	0x6527,	0,	1,	0xE9,	/* e' */
	0x655E,	0,	1,	0xEA,	/* e^ */
	0x6522,	0,	1,	0xEB,	/* e" */
	0x6960,	0,	1,	0xEC,	/* i` */
	0x6927,	0,	1,	0xED,	/* i' */
	0x695E,	0,	1,	0xEE,	/* i^ */
	0x6922,	0,	1,	0xEF,	/* i" */
	0x2D64,	0,	1,	0xF0,	/* -d */
	0x6E7E,	0,	1,	0xF1,	/* n~ */
	0x6F60,	0,	1,	0xF2,	/* o` */
	0x6F27,	0,	1,	0xF3,	/* o' */
	0x6F5E,	0,	1,	0xF4,	/* o^ */
	0x6F7E,	0,	1,	0xF5,	/* o~ */
	0x6F22,	0,	1,	0xF6,	/* o" */
	0x2D3A,	0,	1,	0xF7,	/* -: */
	0x6F2F,	0,	1,	0xF8,	/* o/ */
	0x7560,	0,	1,	0xF9,	/* u` */
	0x7527,	0,	1,	0xFA,	/* u' */
	0x755E,	0,	1,	0xFB,	/* u^ */
	0x7522,	0,	1,	0xFC,	/* u" */
	0x7927,	0,	1,	0xFD,	/* y' */
	0x7468,	0,	0,	0xFE,	/* th */
	0x7922,	0,	1,	0xFF,	/* y" */
	/*
	 * There are also compose sequences for some ASCII characters, for poor
	 * souls who have configured their keyboards to generate some national
	 * characters instead of ASCII on the main keypad in base state.  We do
	 * not support such configuration (the base is always ASCII), but we
	 * support the ASCII compose sequences for the benefit of users who have
	 * them programmed into their finger firmware.
	 */
	0x2B2B,	0,	0,	'#',	/* ++ */
	0x6161,	0x2020,	0,	'@',	/* aa */
	0x2828,	0,	0,	'[',	/* (( */
	0x2F2F,	0,	0,	'\\',	/* // */
	0x2F3C,	0,	1,	'\\',	/* /< */
	0x2929,	0,	0,	']',	/* )) */
	0x282D,	0,	1,	'{',	/* (- */
	0x2F5E,	0,	1,	'|',	/* /^ */
	0x292D,	0,	1,	'}',	/* )- */
	/*
	 * On some national keyboards DEC replaced ASCII characters "'^`~ with
	 * similar-looking diacritical marks that activate two-stroke compose
	 * sequences (which we don't support).  They then provided 3-stroke
	 * Compose sequences for entering the standard ASCII characters, each
	 * having the form <Compose> <diacritical mark key> <space>.  These
	 * compose sequences also work starting with ASCII characters instead of
	 * diacritical marks, though this is of course redundant.  We support
	 * them for compatibility.  Note that "(sp) => " is excluded, as "(sp)
	 * maps to ISO Latin-1 diaeresis like "" in ISO mode on DEC terminals,
	 * which we mimic.
	 */
	0x2720,	0,	1,	'\'',	/* '  */
	0x5E20,	0,	1,	'^',	/* ^  */
	0x6020,	0,	1,	'`',	/* `  */
	0x7E20,	0,	1,	'~',	/* ~  */
	0,	0,	0,	0
};

#define	BS		0x08
#define	LF		0x0A
#define	CR		0x0D
#define	ESC		0x1B
#define	SS3		0x8F
#define	CSI		0x9B

int lk201_configure();
int lk201_metablink();
I 3
extern int ttyoutput();
E 3

lk201_input(k, tp)
	int k;
	register struct tty *tp;
{
	lk201_input1(k, tp->T_LINEP);
}

lk201_input1(k, lk)
	register int k;
	register struct lk201_softc *lk;
{
	k &= 0xFF;
	if (k < LK_FIRSTOPER) {
		/*
		 * We want to detect keyboard resets and configure the keyboard
		 * whenever it gets reset.  The end of the reset sequence is
		 * difficult to catch, however.  The sequence consists entirely
		 * of codes below 0x40 (LK_FIRSTOPER), which are not used for
		 * normal operational communication.  But it's hard to catch
		 * the last byte of the sequence.  What we do is we schedule a
		 * 10 ms timeout on each power-up byte received, and reschedule
		 * it on each subsequent byte received before it expires.  When
		 * the timeout expires the LK201 configuration routine is called
		 * and configures the keyboard.  If an operational code (i.e.,
		 * a keystroke) is received during the wait, the configuration
		 * is sent right away.
		 */
		if (lk->lk_state & LKSTATE_NEEDCONFIG)
			untimeout(lk201_configure, lk);
		timeout(lk201_configure, lk, MAX(hz / 100, 2));
		lk->lk_state |= LKSTATE_NEEDCONFIG;
		return;
	}
	if (lk->lk_state & LKSTATE_NEEDCONFIG) {
		untimeout(lk201_configure, lk);
		lk201_configure(lk);
	}
	if (k == LK_REPEAT)
		k = lk->lk_lastcode;
	else
		lk->lk_lastcode = k;
	if (k >= LK_FIRSTMAIN) {
		lk201_input_mainkeypad(k, lk);
		return;
	}
	if (k >= LK_FIRSTARROW && k <= LK_LASTARROW) {
		lk201_input_arrowkey(k, lk);
		return;
	}
	if (k >= LK_FIRSTKP && k <= LK_LASTKP) {
		lk201_input_numkeypad(k, lk);
		return;
	}
	if (k >= LK_F1 && k <= LK_LASTFUNC) {
		lk201_input_funckey(k, lk);
		return;
	}
	switch (k) {
	case LK_SHIFT:
		lk->lk_state ^= LKSTATE_SHIFT;
		return;
	case LK_CTRL:
		lk->lk_state ^= LKSTATE_CTRL;
		return;
	case LK_LOCK:
		lk->lk_state ^= LKSTATE_LOCK;
		if (lk->lk_state & LKSTATE_LOCK)
			lk->lk_ctlxmitfunc(LKCMD_LEDON, lk->lk_ctlxmittty);
		else
			lk->lk_ctlxmitfunc(LKCMD_LEDOFF, lk->lk_ctlxmittty);
		lk->lk_ctlxmitfunc(LKCMD_LOCKLED, lk->lk_ctlxmittty);
I 4
		lk->lk_ctlxmitstart(lk->lk_ctlxmittty);
E 4
		return;
	case LK_COMPOSE:
		untimeout(lk201_metablink, lk);
		/* are we supporting Compose? */
D 2
		if ((lk->lk_rxtty->t_flags & (PASS8|KOI)) == PASS8) {
E 2
I 2
		if ((lk->lk_rxtty->t_flags & (PASS8|KOI)) == PASS8 &&
		    !(lk->lk_mode & LKMODE_FORCEASCII)) {
E 2
			lk->lk_compstate = 1;
			lk->lk_ctlxmitfunc(LKCMD_LEDON, lk->lk_ctlxmittty);
			lk->lk_ctlxmitfunc(LKCMD_COMPOSELED, lk->lk_ctlxmittty);
I 4
			lk->lk_ctlxmitstart(lk->lk_ctlxmittty);
E 4
			lk->lk_state &= ~(LKSTATE_RUS | LKSTATE_META |
						LKSTATE_METABLINK);
			return;
		}
		lk->lk_compstate = 0;
		/* are we supporting RUS/META? */
D 2
		if ((lk->lk_rxtty->t_flags & (PASS8|KOI)) == (PASS8|KOI)) {
E 2
I 2
		if ((lk->lk_rxtty->t_flags & (PASS8|KOI)) == (PASS8|KOI) &&
		    !(lk->lk_mode & LKMODE_FORCEASCII)) {
E 2
			if (lk->lk_state & LKSTATE_SHIFT) {
				lk->lk_state |= LKSTATE_META |
						LKSTATE_METABLINK;
				lk->lk_ctlxmitfunc(LKCMD_LEDON,
							lk->lk_ctlxmittty);
				lk->lk_ctlxmitfunc(LKCMD_COMPOSELED,
							lk->lk_ctlxmittty);
I 4
				lk->lk_ctlxmitstart(lk->lk_ctlxmittty);
E 4
				timeout(lk201_metablink, lk, hz / 2);
				return;
			}
			if (!(lk->lk_state & (LKSTATE_RUS|LKSTATE_META))) {
				lk->lk_state |= LKSTATE_RUS;
				lk->lk_ctlxmitfunc(LKCMD_LEDON,
							lk->lk_ctlxmittty);
				lk->lk_ctlxmitfunc(LKCMD_COMPOSELED,
							lk->lk_ctlxmittty);
I 4
				lk->lk_ctlxmitstart(lk->lk_ctlxmittty);
E 4
				return;
			}
		}
		lk->lk_state &= ~(LKSTATE_RUS | LKSTATE_META |
					LKSTATE_METABLINK);
		lk->lk_ctlxmitfunc(LKCMD_LEDOFF, lk->lk_ctlxmittty);
		lk->lk_ctlxmitfunc(LKCMD_COMPOSELED, lk->lk_ctlxmittty);
I 4
		lk->lk_ctlxmitstart(lk->lk_ctlxmittty);
E 4
		return;
	case LK_ALLUPS:
		lk->lk_state &= ~(LKSTATE_SHIFT | LKSTATE_CTRL);
		return;
	case LK_LOCKACK:
		/*
		 * The LK201 got an inhibit command.  Since we never send one,
		 * it must have been line noise.  Send a resume command.
		 */
		lk->lk_ctlxmitfunc(LKCMD_RESUME, lk->lk_ctlxmittty);
I 4
		lk->lk_ctlxmitstart(lk->lk_ctlxmittty);
E 4
		return;
	case LK_TMACK:
		/*
		 * Test mode is something we should never get into.  If we do
		 * somehow fall into it, the doc tells us to send it a 0x80 to
		 * take it out of test mode and jump to reset.
		 */
		lk->lk_ctlxmitfunc(0x80, lk->lk_ctlxmittty);
I 4
		lk->lk_ctlxmitstart(lk->lk_ctlxmittty);
E 4
		return;
	case LK_DELETE:
D 4
		if (lk201_drop_compose())
E 4
I 4
		if (lk201_drop_compose(lk))
E 4
			return;
D 4
		lk201_drop_meta();
E 4
I 4
		lk201_drop_meta(lk);
E 4
		/*
		 * On VT320 Ctrl + the rubout key generates ^X.  We don't handle
		 * it specially, however, for the sake of simplicity, since it
		 * is not necessary (there is Ctrl-X), it is not intuitive at
		 * all (again, why not Ctrl-X?), and the ^X generation
		 * complicates the interaction with compose.
		 */
		ttyinput(lk->lk_rxtty->t_erase, lk->lk_rxtty);
		return;
	case LK_RETURN:
D 4
		lk201_drop_compose();
		lk201_drop_meta();
		if (!(lk->lk_prefs & LKPREFS_ENTERRPT))
E 4
I 4
		lk201_drop_compose(lk);
		lk201_drop_meta(lk);
		if (!(lk->lk_prefs & LKPREFS_ENTERRPT)) {
E 4
			lk->lk_ctlxmitfunc(LKCMD_STOPREPEAT, lk->lk_ctlxmittty);
I 4
			lk->lk_ctlxmitstart(lk->lk_ctlxmittty);
		}
E 4
		ttyinput(CR, lk->lk_rxtty);
		if (lk->lk_mode & LKMODE_RETURNCRLF)
			ttyinput(LF, lk->lk_rxtty);
		return;
	case LK_TAB:
D 4
		lk201_drop_compose();
		lk201_drop_meta();
		if (!(lk->lk_prefs & LKPREFS_TABRPT))
E 4
I 4
		lk201_drop_compose(lk);
		lk201_drop_meta(lk);
		if (!(lk->lk_prefs & LKPREFS_TABRPT)) {
E 4
			lk->lk_ctlxmitfunc(LKCMD_STOPREPEAT, lk->lk_ctlxmittty);
I 4
			lk->lk_ctlxmitstart(lk->lk_ctlxmittty);
		}
E 4
		ttyinput('\t', lk->lk_rxtty);
		return;
	}
}

lk201_input_mainkeypad(k, lk)
	register int k;
	register struct lk201_softc *lk;
{
	register int c;

	if (lk->lk_prefs & LKPREFS_ALTLAYOUT) {
		if (k == LK_E00) {	/* Esc */
			/*
			 * While it doesn't do this on my VT320, Esc should
			 * jump out of compose just like Tab, Enter, etc.
			 */
			lk201_drop_compose(lk);
			c = ESC;
			goto checkmeta;
		}
		if (k == LK_B00)
			k = LK_E00;
	}
	if (!(lk->lk_state & LKSTATE_CTRL))
D 4
		c = lk201_mainkeypad_tables[lk->lk_state&3][k-LK_FIRSTMAIN];
E 4
I 4
		c = lk201_mainkeypad_tables[lk->lk_state&7][k-LK_FIRSTMAIN];
E 4
	else {
		lk201_drop_compose(lk);
		c = lk201_mainkeypad_table_ctrl[k-LK_FIRSTMAIN];
	}
	if (!c) {
		lk->lk_ctlxmitfunc(LKCMD_STOPREPEAT, lk->lk_ctlxmittty);
		return;
	}
	if (c == 0x80)	/* kludge for ^@ to escape the test above */
		c = 0;
	if (!(lk->lk_prefs & LKPREFS_ALTLAYOUT) && k != LK_B00) {
		if (c == '<')
			c = ',';
		if (c == '>')
			c = '.';
	}
	if (lk->lk_compstate) {
		lk201_compose_entry(c, lk);
		return;
	}
checkmeta:
	if (lk->lk_state & LKSTATE_META) {
		c |= 0x80;
		lk->lk_state &= ~(LKSTATE_META | LKSTATE_METABLINK);
		lk->lk_ctlxmitfunc(LKCMD_STOPREPEAT, lk->lk_ctlxmittty);
		if (lk->lk_state & LKSTATE_RUS)
			lk->lk_ctlxmitfunc(LKCMD_LEDON, lk->lk_ctlxmittty);
		else
			lk->lk_ctlxmitfunc(LKCMD_LEDOFF, lk->lk_ctlxmittty);
		lk->lk_ctlxmitfunc(LKCMD_COMPOSELED, lk->lk_ctlxmittty);
I 4
		lk->lk_ctlxmitstart(lk->lk_ctlxmittty);
E 4
		untimeout(lk201_metablink, lk);
	}
	ttyinput(c, lk->lk_rxtty);
}

lk201_input_arrowkey(k, lk)
	register int k;
	register struct lk201_softc *lk;
{
	register int dirchar;

	lk201_drop_compose(lk);
	lk201_drop_meta(lk);
	dirchar = lk201_arrowkeys_table[k-LK_FIRSTARROW];
	if ((lk->lk_rxtty->t_flags & PASS8) && !(lk->lk_mode & LKMODE_7BITC1))
		ttyinput(CSI, lk->lk_rxtty);
	else {
		ttyinput(ESC, lk->lk_rxtty);
		ttyinput('[', lk->lk_rxtty);
	}
	ttyinput(dirchar, lk->lk_rxtty);
}

lk201_input_numkeypad(k, lk)
	register int k;
	register struct lk201_softc *lk;
{
	register int c;

	lk201_drop_meta(lk);
	if (lk->lk_compstate) {
		c = lk201_keypad_hexcompose[k-LK_FIRSTKP];
		if (c) {
			lk201_compose_entry(c, lk);
			return;
		} else {
			/* drop Compose on '.' and Enter */
			lk->lk_compstate = 0;
			lk->lk_ctlxmitfunc(LKCMD_LEDOFF, lk->lk_ctlxmittty);
			lk->lk_ctlxmitfunc(LKCMD_COMPOSELED, lk->lk_ctlxmittty);
I 4
			lk->lk_ctlxmitstart(lk->lk_ctlxmittty);
E 4
		}
	}
	if (lk->lk_mode & LKMODE_APPKEYPAD)
		c = lk201_keypad_application[k-LK_FIRSTKP];
	else
		c = lk201_keypad_numeric[k-LK_FIRSTKP];
	if (!c) {
		lk->lk_ctlxmitfunc(LKCMD_STOPREPEAT, lk->lk_ctlxmittty);
I 4
		lk->lk_ctlxmitstart(lk->lk_ctlxmittty);
E 4
		return;
	}
	if (c >= '@') {		/* trick to tell whether we need SS3 or not */
		if ((lk->lk_rxtty->t_flags & PASS8) &&
		    !(lk->lk_mode & LKMODE_7BITC1))
			ttyinput(SS3, lk->lk_rxtty);
		else {
			ttyinput(ESC, lk->lk_rxtty);
			ttyinput('O', lk->lk_rxtty);
		}
	}
	ttyinput(c, lk->lk_rxtty);
	if (c == CR && (lk->lk_mode & LKMODE_RETURNCRLF))
		ttyinput(LF, lk->lk_rxtty);
	return;
}

lk201_input_funckey(k, lk)
	register int k;
	register struct lk201_softc *lk;
{
	register int n, m;

	lk201_drop_compose(lk);
	lk201_drop_meta(lk);
	n = lk201_funckeys_table[k-LK_F1];
	if (!n)
		return;
	if (lk->lk_mode & LKMODE_F11ESC) {
		if (n == 23) {
			ttyinput(ESC, lk->lk_rxtty);
			return;
		}
		if (n == 24) {
			ttyinput(BS, lk->lk_rxtty);
			return;
		}
		if (n == 25) {
			ttyinput(LF, lk->lk_rxtty);
			return;
		}
	}
	if ((lk->lk_rxtty->t_flags & PASS8) && !(lk->lk_mode & LKMODE_7BITC1))
		ttyinput(CSI, lk->lk_rxtty);
	else {
		ttyinput(ESC, lk->lk_rxtty);
		ttyinput('[', lk->lk_rxtty);
	}
	if (n > 9)
		ttyinput(n / 10 + '0', lk->lk_rxtty);
	ttyinput(n % 10 + '0', lk->lk_rxtty);
	/* our extension to VT2xx/3xx function key sequences */
	if (lk->lk_state & (LKSTATE_CTRL|LKSTATE_SHIFT)) {
		ttyinput(';', lk->lk_rxtty);
		m = '0';
		if (lk->lk_state & LKSTATE_CTRL)
			m |= 2;
		if (lk->lk_state & LKSTATE_SHIFT)
			m |= 1;
		ttyinput(m, lk->lk_rxtty);
	}
	ttyinput('~', lk->lk_rxtty);
}

/*
 * Character going into compose sequence
 */
lk201_compose_entry(c, lk)
	register int c;
	register struct lk201_softc *lk;
{
	register int seq, revseq;
	register struct comptbl *tp;

	lk->lk_ctlxmitfunc(LKCMD_STOPREPEAT, lk->lk_ctlxmittty);
	lk->lk_compseq[lk->lk_compstate++ - 1] = c;
	if (lk->lk_compstate < 3)	/* more to come */
D 4
		return;
E 4
I 4
		goto out;
E 4
	/* Got the complete sequence, process it */
	seq = lk->lk_compseq[0] << 8 | lk->lk_compseq[1];
	lk->lk_compstate = 0;
	lk->lk_ctlxmitfunc(LKCMD_LEDOFF, lk->lk_ctlxmittty);
	lk->lk_ctlxmitfunc(LKCMD_COMPOSELED, lk->lk_ctlxmittty);
	/* Check for hex compose */
	if ((seq & 0xF0F0) == 0x8080) {
		c = (seq & 0xF00) >> 4 | seq & 0xF;
		ttyinput(c, lk->lk_rxtty);
D 4
		return;
E 4
I 4
		goto out;
E 4
	}
	/* search the table */
	revseq = lk->lk_compseq[1] << 8 | lk->lk_compseq[0];
	for (tp = lk201_compose_table; tp->sequence; tp++)
		if ((seq | tp->casemask) == tp->sequence ||
		    tp->reverseok && (revseq | tp->casemask) == tp->sequence) {
			ttyinput(tp->character, lk->lk_rxtty);
D 4
			return;
E 4
I 4
			goto out;
E 4
		}
	/* doesn't match anything, sound error bell */
	lk->lk_ctlxmitfunc(LKCMD_SNDBELL, lk->lk_ctlxmittty);
I 4
out:	lk->lk_ctlxmitstart(lk->lk_ctlxmittty);
E 4
}

/*
 * Drop out of compose on keys that don't belong in a compose sequence like
 * arrows and function keys.
 */
lk201_drop_compose(lk)
	register struct lk201_softc *lk;
{
	if (lk->lk_compstate) {
		lk->lk_compstate = 0;
		lk->lk_ctlxmitfunc(LKCMD_LEDOFF, lk->lk_ctlxmittty);
		lk->lk_ctlxmitfunc(LKCMD_COMPOSELED, lk->lk_ctlxmittty);
I 4
		lk->lk_ctlxmitstart(lk->lk_ctlxmittty);
E 4
		return(1);
	}
	return(0);
}

/* Drop meta similarly */
lk201_drop_meta(lk)
	register struct lk201_softc *lk;
{
	if (lk->lk_state & LKSTATE_META) {
		lk->lk_state &= ~(LKSTATE_META | LKSTATE_METABLINK);
		if (lk->lk_state & LKSTATE_RUS)
			lk->lk_ctlxmitfunc(LKCMD_LEDON, lk->lk_ctlxmittty);
		else
			lk->lk_ctlxmitfunc(LKCMD_LEDOFF, lk->lk_ctlxmittty);
		lk->lk_ctlxmitfunc(LKCMD_COMPOSELED, lk->lk_ctlxmittty);
I 4
		lk->lk_ctlxmitstart(lk->lk_ctlxmittty);
E 4
		untimeout(lk201_metablink, lk);
	}
}

lk201_configure(lk)
	register struct lk201_softc *lk;
{
I 4
	int s;

	s = spltty();
E 4
	if (lk->lk_repeat_rate) {
		lk->lk_ctlxmitfunc(LKCMD_SETRPTRATEBUF(0), lk->lk_ctlxmittty);
		lk->lk_ctlxmitfunc(lk->lk_repeat_delay, lk->lk_ctlxmittty);
		lk->lk_ctlxmitfunc(0x80|lk->lk_repeat_rate, lk->lk_ctlxmittty);
		lk->lk_ctlxmitfunc(LKCMD_TRANSMODEP(1, LKTMODE_AUTOREPEAT),
					lk->lk_ctlxmittty);
		lk->lk_ctlxmitfunc(0x80, lk->lk_ctlxmittty);
		lk->lk_ctlxmitfunc(LKCMD_TRANSMODEP(2, LKTMODE_AUTOREPEAT),
					lk->lk_ctlxmittty);
		lk->lk_ctlxmitfunc(0x80, lk->lk_ctlxmittty);
		lk->lk_ctlxmitfunc(LKCMD_TRANSMODEP(4, LKTMODE_AUTOREPEAT),
					lk->lk_ctlxmittty);
		lk->lk_ctlxmitfunc(0x80, lk->lk_ctlxmittty);
		lk->lk_ctlxmitfunc(LKCMD_TRANSMODEP(7, LKTMODE_AUTOREPEAT),
					lk->lk_ctlxmittty);
		lk->lk_ctlxmitfunc(0x80, lk->lk_ctlxmittty);
		lk->lk_ctlxmitfunc(LKCMD_TRANSMODEP(8, LKTMODE_AUTOREPEAT),
					lk->lk_ctlxmittty);
		lk->lk_ctlxmitfunc(0x80, lk->lk_ctlxmittty);
		lk->lk_ctlxmitfunc(LKCMD_TRANSMODEP(9, LKTMODE_AUTOREPEAT),
					lk->lk_ctlxmittty);
		lk->lk_ctlxmitfunc(0x80, lk->lk_ctlxmittty);
	} else {
		lk->lk_ctlxmitfunc(LKCMD_TRANSMODE(1, LKTMODE_DOWNONLY),
					lk->lk_ctlxmittty);
		lk->lk_ctlxmitfunc(LKCMD_TRANSMODE(2, LKTMODE_DOWNONLY),
					lk->lk_ctlxmittty);
		lk->lk_ctlxmitfunc(LKCMD_TRANSMODE(4, LKTMODE_DOWNONLY),
					lk->lk_ctlxmittty);
		lk->lk_ctlxmitfunc(LKCMD_TRANSMODE(7, LKTMODE_DOWNONLY),
					lk->lk_ctlxmittty);
		lk->lk_ctlxmitfunc(LKCMD_TRANSMODE(8, LKTMODE_DOWNONLY),
					lk->lk_ctlxmittty);
		lk->lk_ctlxmitfunc(LKCMD_TRANSMODE(9, LKTMODE_DOWNONLY),
					lk->lk_ctlxmittty);
	}
	if (lk->lk_repeat_rate && lk->lk_prefs & LKPREFS_ERASERPT) {
		lk->lk_ctlxmitfunc(LKCMD_TRANSMODEP(3, LKTMODE_AUTOREPEAT),
					lk->lk_ctlxmittty);
		lk->lk_ctlxmitfunc(0x80, lk->lk_ctlxmittty);
	} else
		lk->lk_ctlxmitfunc(LKCMD_TRANSMODE(3, LKTMODE_DOWNONLY),
					lk->lk_ctlxmittty);
	lk->lk_ctlxmitfunc(LKCMD_TRANSMODE(5, LKTMODE_DOWNONLY),
				lk->lk_ctlxmittty);
	lk->lk_ctlxmitfunc(LKCMD_TRANSMODE(6, LKTMODE_DOWNUP),
				lk->lk_ctlxmittty);
	lk->lk_ctlxmitfunc(LKCMD_TRANSMODE(10, LKTMODE_DOWNONLY),
				lk->lk_ctlxmittty);
	lk->lk_ctlxmitfunc(LKCMD_TRANSMODE(11, LKTMODE_DOWNONLY),
				lk->lk_ctlxmittty);
	lk->lk_ctlxmitfunc(LKCMD_TRANSMODE(12, LKTMODE_DOWNONLY),
				lk->lk_ctlxmittty);
	lk->lk_ctlxmitfunc(LKCMD_TRANSMODE(13, LKTMODE_DOWNONLY),
				lk->lk_ctlxmittty);
	lk->lk_ctlxmitfunc(LKCMD_TRANSMODE(14, LKTMODE_DOWNONLY),
				lk->lk_ctlxmittty);
	if (lk->lk_repeat_rate)
		lk->lk_ctlxmitfunc(LKCMD_ENREPEAT, lk->lk_ctlxmittty);
	if (lk->lk_keyclick_volume) {
		lk->lk_ctlxmitfunc(LKCMD_ENKEYCLICK, lk->lk_ctlxmittty);
		lk->lk_ctlxmitfunc(0x80 | (8 - lk->lk_keyclick_volume),
					lk->lk_ctlxmittty);
	} else
		lk->lk_ctlxmitfunc(LKCMD_DISKEYCLICK, lk->lk_ctlxmittty);
	lk->lk_ctlxmitfunc(LKCMD_DISCTRLKEYCLICK, lk->lk_ctlxmittty);
	if (lk->lk_bell_volume) {
		lk->lk_ctlxmitfunc(LKCMD_ENBELL, lk->lk_ctlxmittty);
		lk->lk_ctlxmitfunc(0x80 | (8 - lk->lk_bell_volume),
					lk->lk_ctlxmittty);
	} else
		lk->lk_ctlxmitfunc(LKCMD_DISBELL, lk->lk_ctlxmittty);
	if (lk->lk_state & LKSTATE_LOCK)
		lk->lk_ctlxmitfunc(LKCMD_LEDON, lk->lk_ctlxmittty);
	else
		lk->lk_ctlxmitfunc(LKCMD_LEDOFF, lk->lk_ctlxmittty);
	lk->lk_ctlxmitfunc(LKCMD_LOCKLED, lk->lk_ctlxmittty);
	if (lk->lk_compstate || lk->lk_state & LKSTATE_RUS)
		lk->lk_ctlxmitfunc(LKCMD_LEDON, lk->lk_ctlxmittty);
	else
		lk->lk_ctlxmitfunc(LKCMD_LEDOFF, lk->lk_ctlxmittty);
	lk->lk_ctlxmitfunc(LKCMD_COMPOSELED, lk->lk_ctlxmittty);
I 4
	lk->lk_ctlxmitstart(lk->lk_ctlxmittty);
E 4
	lk->lk_state &= ~LKSTATE_NEEDCONFIG;
I 4
	splx(s);
E 4
}

lk201_metablink(lk)
	register struct lk201_softc *lk;
{
I 4
	int s;

	s = spltty();
	if (!(lk->lk_state & LKSTATE_META)) {
		splx(s);
		return;
	}
E 4
	lk->lk_state ^= LKSTATE_METABLINK;
	if (lk->lk_state & LKSTATE_METABLINK)
		lk->lk_ctlxmitfunc(LKCMD_LEDON, lk->lk_ctlxmittty);
	else
		lk->lk_ctlxmitfunc(LKCMD_LEDOFF, lk->lk_ctlxmittty);
	lk->lk_ctlxmitfunc(LKCMD_COMPOSELED, lk->lk_ctlxmittty);
I 4
	lk->lk_ctlxmitstart(lk->lk_ctlxmittty);
E 4
	timeout(lk201_metablink, lk, hz / 2);
I 4
	splx(s);
E 4
I 3
}

/* Routines for activating this module as a regular line discipline */
lk201_lopen(dev, tp)
	dev_t dev;
	register struct tty *tp;
{
	register struct lk201_softc *lk;

	/*
	 * If this is the first open of this line discipline, allocate, and
	 * initialise struct lk201_softc and attach it to the tty.
	 */
	if (tp->t_line != LK201DISC) {
		lk = (struct lk201_softc *)
			malloc(sizeof(struct lk201_softc), M_PCB, M_WAITOK);
		bzero(lk, sizeof(*lk));
		lk->lk_rxtty = tp;
		lk->lk_ctlxmittty = tp;
		lk->lk_ctlxmitfunc = ttyoutput;
I 4
		lk->lk_ctlxmitstart = tp->t_oproc;
E 4
		tp->T_LINEP = (caddr_t) lk;
		lk201_configure(lk);
	}
	return(0);
}

lk201_lclose(tp)
	register struct tty *tp;
{
	register struct lk201_softc *lk;
	int s;

	s = spltty();
	lk = (struct lk201_softc *) tp->T_LINEP;
	if (lk->lk_state & LKSTATE_NEEDCONFIG)
		untimeout(lk201_configure, lk);
	if (lk->lk_state & LKSTATE_META)
		untimeout(lk201_metablink, lk);
	free(lk, M_PCB);
	ttywflush(tp);
	tp->t_line = 0;
	splx(s);
}

lk201_ioctl(tp, com, data, flag)
	register struct tty *tp;
	caddr_t data;
{
	register struct lk201_softc *lk;
	register struct lk201_prefs *pr;
	int s;

	lk = (struct lk201_softc *)tp->T_LINEP;
	switch (com) {

	case LKIOCSMODE:
		lk->lk_mode = *(int *)data;
		break;

	case LKIOCGMODE:
		*(int *)data = lk->lk_mode;
		break;

	case TIOCKBSF11MOD:
		if (*(int *)data)
			lk->lk_mode |= LKMODE_F11ESC;
		else
			lk->lk_mode &= ~LKMODE_F11ESC;
		break;

	case TIOCKBGF11MOD:
		*(int *)data = (lk->lk_mode & LKMODE_F11ESC) != 0;
		break;

	case LKIOCSPREFS:
		pr = (struct lk201_prefs *)data;
		s = spltty();
		lk->lk_prefs = pr->lkprefs_flags;
		lk->lk_repeat_delay = pr->lkprefs_repeat_delay;
		lk->lk_repeat_rate = pr->lkprefs_repeat_rate;
		lk->lk_bell_volume = pr->lkprefs_bell_volume;
		lk->lk_keyclick_volume = pr->lkprefs_keyclick_volume;
		if (!(lk->lk_state & LKSTATE_NEEDCONFIG))
			lk201_configure(lk);
		splx(s);
		break;

	case LKIOCGPREFS:
		pr = (struct lk201_prefs *)data;
		pr->lkprefs_flags = lk->lk_prefs;
		pr->lkprefs_repeat_delay = lk->lk_repeat_delay;
		pr->lkprefs_repeat_rate = lk->lk_repeat_rate;
		pr->lkprefs_bell_volume = lk->lk_bell_volume;
		pr->lkprefs_keyclick_volume = lk->lk_keyclick_volume;
		break;

	case TIOCKBRESET:
		s = spltty();
		lk->lk_state &= ~(LKSTATE_RUS|LKSTATE_META|LKSTATE_METABLINK);
		lk->lk_compstate = 0;
		lk->lk_ctlxmitfunc(LKCMD_LEDOFF, lk->lk_ctlxmittty);
		lk->lk_ctlxmitfunc(LKCMD_COMPOSELED, lk->lk_ctlxmittty);
I 4
		lk->lk_ctlxmitstart(lk->lk_ctlxmittty);
E 4
		untimeout(lk201_metablink, lk);
		splx(s);
		break;

	case TIOCKBHACKS:
		/*
		 * We need to block this one so that one can't activate lk201
		 * and ttykbhacks together, as they would conflict over T_LINEP.
		 * tty kb hacks are not needed with this module since we
		 * generate the codes we want in the first place.
		 */
		return(ENOTTY);

	default:
		return (-1);
	}
	return (0);
E 3
}
#endif
E 1
