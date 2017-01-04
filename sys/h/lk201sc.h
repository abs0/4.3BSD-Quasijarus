/*
 * LK201 line discipline software state and configuration
 *
 *	@(#)lk201sc.h	7.4 (Berkeley) 12/8/04
 */

struct lk201_softc {
	struct	tty *lk_rxtty;		/* tty to receive kbd input */
	struct	tty *lk_ctlxmittty;	/* raw tty via which to xmit to LK */
	int	(*lk_ctlxmitfunc)();	/* function to xmit cmd bytes to LK */
	int	(*lk_ctlxmitstart)();	/* function to start output */
	short	lk_mode;		/* mode set by LKIOCSMODE */
	short	lk_prefs;		/* user preference flags */
	short	lk_state;		/* state flags */
	char	lk_repeat_delay;	/* repeat delay * 5 ms */
	char	lk_repeat_rate;		/* # of repeats per s, 0 disables rpt */
	u_char	lk_lastcode;		/* last keycode received (for repeat) */
	char	lk_bell_volume;		/* 0-8, 0 disables bell */
	char	lk_keyclick_volume;	/* 0-8, 0 disables keyclick */
	char	lk_compstate;		/* where we are in a compose sequence */
	u_char	lk_compseq[2];		/* storage for compose sequences */
};

/*
 * LK201 input modes.
 * These are intended to be application expectations rather user preferences.
 */
#define	LKMODE_FORCEASCII	0x0001	/* allow 7-bit only, block Compose */
#define	LKMODE_7BITC1		0x0002	/* xmit C1 ctrl chars as 7-bit seqs */
#define	LKMODE_F11ESC		0x0004	/* turn F11/12/13 into ESC/BS/LF */
#define	LKMODE_APPKEYPAD	0x0008	/* application keypad */
#define	LKMODE_RETURNCRLF	0x0010	/* Return should produce CR LF */

/* User preference flags */
#define	LKPREFS_ALTLAYOUT	0x0001	/* put ESC at E00, move `~ to B00, */
					/* <> over ,. */
#define	LKPREFS_TABRPT		0x0002	/* Tab autorepeat enable */
#define	LKPREFS_ENTERRPT	0x0004	/* Enter autorepeat enable */
#define	LKPREFS_ERASERPT	0x0008	/* Erase autorepeat enable */

/* Dynamic states */
#define	LKSTATE_SHIFT		0x0001
#define	LKSTATE_LOCK		0x0002	/* Caps Lock */
#define	LKSTATE_RUS		0x0004	/* for KOI-8 */
#define	LKSTATE_CTRL		0x0008
#define	LKSTATE_META		0x0010	/* for KOI-8 */
#define	LKSTATE_METABLINK	0x0020	/* Meta blinking indicator state */
#define	LKSTATE_NEEDCONFIG	0x0040	/* need to configure the LK201 */

/* structure for setting keyboard preferences with LKIOCSPREFS */
struct lk201_prefs {
	short	lkprefs_flags;		/* user preference flags */
	char	lkprefs_repeat_delay;	/* repeat delay * 5 ms */
	char	lkprefs_repeat_rate;	/* # of repeats per s, 0 disables rpt */
	char	lkprefs_bell_volume;	/* 0-8, 0 disables bell */
	char	lkprefs_keyclick_volume;/* 0-8, 0 disables keyclick */
};

/* ioctls for configuring the lk201 module */
#define	LKIOCSMODE	_IOW(l, 0, int)		/* set application modes */
#define	LKIOCGMODE	_IOR(l, 1, int)		/* get application modes */
#define	LKIOCSPREFS	_IOW(l, 2, struct lk201_prefs)
						/* set user preferences */
#define	LKIOCGPREFS	_IOR(l, 3, struct lk201_prefs)
						/* get user preferences */
