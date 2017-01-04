/*
 * This header file defines the internal kernel structure that supports tty kb
 * hacks. When tty kb hacks are compiled in and enabled on a given tty, this
 * structure is malloc'ed and linked to the tty structure via T_LINEP (line
 * discipline private ptr).
 *
 *	@(#)ttykbhacks.h	7.1 (Berkeley) 4/7/03
 */

struct ttykbhacks {
	char	kb_rusmap[94];
	char	kb_fstyle;		/* function key catcher to use */
	char	kb_flags;		/* mode & state flags */
	char	kb_fstate;		/* function key catcher state */
	char	kb_faccum;		/* function key catcher accumulator */
	char	kb_ruskey;
	char	kb_latkey;
	char	kb_metakey;
};

/* Function key sequences supported */
#define	KBHACKS_FSTYLE_VANILLA		0
#define	KBHACKS_FSTYLE_VT2XX		1
#define	KBHACKS_FSTYLE_MAX		1

/* kb_flags */
#define	KBF_INRUS	0x01		/* in RUS mode */
#define	KBF_META	0x02		/* meta prefix */
#define	KBF_INFSEQ	0x04		/* inside a function key sequence */
#define	KBF_VT2XXF11	0x08		/* VT2xx F11/12/13 => ESC/BS/LF */

/* VT2xx/3xx function key catcher states */
#define	VT2XX_GROUND	0x00		/* ground state */
#define	VT2XX_GOTCSI	0x01		/* got CSI */
#define	VT2XX_GOT1	0x02		/* got 1 digit */
#define	VT2XX_GOT2	0x03		/* got 2 digits */
#define	VT2XX_WAITFIN	0x04		/* waiting for ctrl seq final char */
#define	VT2XX_GOTSS3	0x05		/* got SS3 */

/* VT2xx/3xx function key definitions */
#define	CSI		0x9B
#define	SS3		0x8F
#define	ESC		0x1B
#define	BS		0x08
#define	LF		0x0A
#define	F11KEY		23
#define	F12KEY		24
#define	F13KEY		25
