/*
 * Unfortunately some input terminals (keyboards) have deficiencies that compel
 * us to remedy them with hacks in the tty driver to improve their usability
 * with UNIX. This module implements these hacks.
 *
 * Many American ASCII keyboards do not lend themselves easily to entering
 * Russian text in KOI, not even in KOI-7. Proper KOI-7 requires case reversal,
 * and while Caps Lock will produce uppercase Latin = lowercase Russian, on
 * many keyboards Shift while in Caps Lock does not produce lowercase, making
 * Caps Lock unusable for effecting KOI-7 case reversal. Thus even if the
 * terminal display or printer follows ISO 2022 and allows custom fonts/
 * charsets or can otherwise be fitted for KOI-7 or KOI-8, full terminal
 * Russification stops at the keyboard. We can, however, Russify American
 * keyboards with this tty driver hack. We trap the keyboard function key
 * sequences and borrow two function keys as RUS and LAT. In LAT mode we pass
 * keyboard ASCII input through with no hacks, while in RUS mode we do the
 * following. Assuming that every alphanumeric key on an American keyboard
 * sends an ASCII code, we trap the 94 printable ASCII codes and remap them
 * according to the user-provided table. The user can construct the table
 * knowing which ASCII code each key is hard-wired to generate and which code
 * it should produce in RUS mode. We can also have a META key which causes any
 * subsequent ASCII character to be simply ORed with 0200. META acts above
 * RUS/LAT and can be used to enter all 8-bit codes even if the RUS map lacks
 * some.
 *
 * Besides Russification, this hack's function key sequence trapping feature
 * can be used to alter function keys in other ways. On VT2xx/3xx 8-bit CSI and
 * SS3 introducer chars are converted to their 7-bit equivalents which UNIX is
 * more used to, and the Vt2xx/3xx sequences for F11/12/13 can be converted to
 * ESC/BS/LF. The last feature is a lifesaver for those who use their VT2xx/3xx
 * terminals in VT100 mode and would like to switch to the native mode to reap
 * the new features, but can't live without F11 being ESC.
 *
 *	@(#)tty_kbhacks.c	7.1 (Berkeley) 4/7/03
 */

#ifdef TTYKBHACKS
#include "../machine/reg.h"
#include "param.h"
#include "systm.h"
#include "dir.h"
#include "user.h"
#include "ioctl.h"
#include "tty.h"
#include "ttykbhacks.h"
#include "proc.h"
#include "file.h"
#include "conf.h"
#include "dkstat.h"
#include "uio.h"
#include "kernel.h"
#include "malloc.h"

/*
 * "Vanilla" processing - assume no multibyte sequences
 * If there are function keys, they must send one-byte codes.
 */
ttykbhacks_vanilla_proc1(c, tp, kb)
	register int c;
	register struct tty *tp;
	register struct ttykbhacks *kb;
{
	if (c == 0)
		return(c);
	if (c == kb->kb_ruskey && tp->t_flags & KOI) {
		kb->kb_flags |= KBF_INRUS;
		kb->kb_flags &= ~KBF_META;
		if (!(tp->t_flags & PASS8))
			ttyoutput(016, tp);
		return(-1);
	}
	if (c == kb->kb_latkey && tp->t_flags & KOI) {
		kb->kb_flags &= ~(KBF_INRUS|KBF_META);
		if (!(tp->t_flags & PASS8))
			ttyoutput(017, tp);
		return(-1);
	}
	if (c == kb->kb_metakey) {
		kb->kb_flags |= KBF_META;
		return(-1);
	}
	return(c);
}

ttykbhacks_nullproc(c, tp, kb)
	int c;
	struct tty *tp;
	struct ttykbhacks *kb;
{
	return(c);
}

ttykbhacks_vanilla_init(kb)
	register struct ttykbhacks *kb;
{
	kb->kb_ruskey = 016;
	kb->kb_latkey = 017;
	kb->kb_metakey = 0;
}

/*
 * VT2xx/3xx function key processing
 *
 * This is a real kludge. To distinguish between function key sequences and the
 * user pressing ESC (or typing Ctrl-[) we require the terminal to be sending
 * 8-bit controls. However, to break recursion and since UNIX would otherwise
 * want 7-bit controls, we convert all function key sequences we process to
 * 7-bit controls.
 */
ttykbhacks_vt2xx_proc1(c, tp, kb)
	register int c;
	register struct tty *tp;
	register struct ttykbhacks *kb;
{
	/* We are triggered by and always ready for C1 codes */
	if (c == CSI) {
		kb->kb_fstate = VT2XX_GOTCSI;
		kb->kb_flags |= KBF_INFSEQ;
		kb->kb_flags &= ~KBF_META;
		return(-1);
	}
	if (c == SS3) {
		kb->kb_fstate = VT2XX_GOTSS3;
		kb->kb_flags |= KBF_INFSEQ;
		kb->kb_flags &= ~KBF_META;
		/* Pass it through right away (converting to 7-bit) */
		ttykbhacks_pass(ESC, tp);
		return('O');
	}
	/* Not a hot code, normal processing */
	switch (kb->kb_fstate) {
	case VT2XX_GROUND:
		return(c);
	case VT2XX_GOTCSI:
		if (c >= '0' && c <= '9') {
			kb->kb_faccum = c - '0';
			kb->kb_fstate = VT2XX_GOT1;
			return(-1);
		}
		ttykbhacks_vt2xx_outmem(tp, kb);
		goto waitfin;
	case VT2XX_GOT1:
		if (c >= '0' && c <= '9') {
			kb->kb_faccum = kb->kb_faccum * 10 + c - '0';
			kb->kb_fstate = VT2XX_GOT2;
			return(-1);
		}
		if (c == '~')
			return(ttykbhacks_vt2xx_fkey(tp, kb));
		ttykbhacks_vt2xx_outmem(tp, kb);
		goto waitfin;
	case VT2XX_GOT2:
		if (c == '~')
			return(ttykbhacks_vt2xx_fkey(tp, kb));
		ttykbhacks_vt2xx_outmem(tp, kb);
		/* FALLTHROUGH */
	case VT2XX_WAITFIN:
	waitfin:
		if (c >= ' ' && c <= '?')
			kb->kb_fstate = VT2XX_WAITFIN;
		else if (c >= '@' && c <= '~')
			kb->kb_fstate = VT2XX_GROUND;
		else {
			kb->kb_fstate = VT2XX_GROUND;
			kb->kb_flags &= ~KBF_INFSEQ;
		}
		return(c);
	case VT2XX_GOTSS3:
		kb->kb_fstate = VT2XX_GROUND;
		return(c);
	default:
		panic("ttykbhacks VT2xx");
	}
	/* NOTREACHED */
}

ttykbhacks_vt2xx_proc2(c, tp, kb)
	int c;
	struct tty *tp;
	register struct ttykbhacks *kb;
{
	if (kb->kb_fstate == VT2XX_GROUND)
		kb->kb_flags &= ~KBF_INFSEQ;
}

/* Actually got a function key! */
ttykbhacks_vt2xx_fkey(tp, kb)
	register struct tty *tp;
	register struct ttykbhacks *kb;
{
	register int fn;

	fn = kb->kb_faccum;
	if (fn == kb->kb_ruskey && tp->t_flags & KOI) {
		kb->kb_fstate = VT2XX_GROUND;
		kb->kb_flags |= KBF_INRUS;
		kb->kb_flags &= ~(KBF_META|KBF_INFSEQ);
		if (!(tp->t_flags & PASS8))
			ttyoutput(016, tp);
		return(-1);
	}
	if (fn == kb->kb_latkey && tp->t_flags & KOI) {
		kb->kb_fstate = VT2XX_GROUND;
		kb->kb_flags &= ~(KBF_INRUS|KBF_META|KBF_INFSEQ);
		if (!(tp->t_flags & PASS8))
			ttyoutput(017, tp);
		return(-1);
	}
	if (fn == kb->kb_metakey) {
		kb->kb_fstate = VT2XX_GROUND;
		kb->kb_flags |= KBF_META;
		kb->kb_flags &= ~KBF_INFSEQ;
		return(-1);
	}
	if (kb->kb_flags & KBF_VT2XXF11 && fn == F11KEY) {
		kb->kb_fstate = VT2XX_GROUND;
		return(ESC);
	}
	if (kb->kb_flags & KBF_VT2XXF11 && fn == F12KEY) {
		kb->kb_fstate = VT2XX_GROUND;
		return(BS);
	}
	if (kb->kb_flags & KBF_VT2XXF11 && fn == F13KEY) {
		kb->kb_fstate = VT2XX_GROUND;
		return(LF);
	}
	/* Pass it through */
	ttykbhacks_vt2xx_outmem(tp, kb);
	kb->kb_fstate = VT2XX_GROUND;
	return('~');
}

/* Regurgitate remembered part of control sequence */
ttykbhacks_vt2xx_outmem(tp, kb)
	register struct tty *tp;
	register struct ttykbhacks *kb;
{
	switch (kb->kb_fstate) {
	case VT2XX_GOTCSI:
		ttykbhacks_pass(ESC, tp);
		ttykbhacks_pass('[', tp);
		break;
	case VT2XX_GOT1:
		ttykbhacks_pass(ESC, tp);
		ttykbhacks_pass('[', tp);
		ttykbhacks_pass('0' + kb->kb_faccum, tp);
		break;
	case VT2XX_GOT2:
		ttykbhacks_pass(ESC, tp);
		ttykbhacks_pass('[', tp);
		ttykbhacks_pass('0' + kb->kb_faccum / 10, tp);
		ttykbhacks_pass('0' + kb->kb_faccum % 10, tp);
		break;
	}
}

ttykbhacks_vt2xx_init(kb)
	register struct ttykbhacks *kb;
{
	kb->kb_ruskey = 0;
	kb->kb_latkey = 0;
	kb->kb_metakey = 0;
	kb->kb_fstate = VT2XX_GROUND;
}

/* Pass a byte downward breaking recursion */
ttykbhacks_pass(c, tp)
	register int c;
	register struct tty *tp;
{
	tp->t_state |= TS_TYPEN;
	ttyinput(c, tp);
	tp->t_state &= ~TS_TYPEN;
}

int (*ttykbhacks_fkey_proc1[])() =
	{ttykbhacks_vanilla_proc1, ttykbhacks_vt2xx_proc1};
int (*ttykbhacks_fkey_proc2[])() =
	{ttykbhacks_nullproc, ttykbhacks_vt2xx_proc2};
int (*ttykbhacks_fkey_init[])() =
	{ttykbhacks_vanilla_init, ttykbhacks_vt2xx_init};

/* Main tty kb hacks processing function */
ttykbhacks(c, tp)
	register int c;
	register struct tty *tp;
{
	register struct ttykbhacks *kb = (struct ttykbhacks *) tp->T_LINEP;

	/* Break recursion */
	if (tp->t_state & TS_TYPEN)
		return(c);
	/* First look for function keys */
	c = ttykbhacks_fkey_proc1[kb->kb_fstyle](c, tp, kb);
	if (c < 0)
		return(c);
	/* Now check for META and RUS */
	if ((kb->kb_flags & (KBF_META|KBF_INFSEQ)) == KBF_META) {
		kb->kb_flags &= ~KBF_META;
		c |= 0200;
	} else if ((kb->kb_flags & (KBF_INRUS|KBF_INFSEQ)) == KBF_INRUS &&
		   c >= '!' && c <= '~' && tp->t_flags & KOI)
		c = kb->kb_rusmap[c-'!'] & 0377;
	ttykbhacks_fkey_proc2[kb->kb_fstyle](c, tp, kb);
	return(c);
}

ttykbhacks_ioctl(tp, com, data, flag)
	register struct tty *tp;
	caddr_t data;
{
	register struct ttykbhacks *kb;
	register int i;
	register char *cp;
	int s;

	switch (com) {

	case TIOCKBHACKS:
		i = *(int *)data;
		if (i && !(tp->t_state & TS_KBHACKS)) {
			kb = (struct ttykbhacks *)
			    malloc(sizeof(struct ttykbhacks), M_PCB, M_WAITOK);
			tp->T_LINEP = (caddr_t) kb;
			/* set our defaults */
			/* default rusmap is sort of KOI-7 w/o case reverse */
			for (i = '!', cp = kb->kb_rusmap; i <= '?'; i++)
				*cp++ = i;
			for (; i <= 'Z'; i++)
				*cp++ = i | 0240;
			for (; i <= '_'; i++)
				*cp++ = i | 0200;
			for (; i <= 'z'; i++)
				*cp++ = i ^ 0240;
			for (; i <= '~'; i++)
				*cp++ = i | 0200;
			kb->kb_fstyle = KBHACKS_FSTYLE_VANILLA;
			kb->kb_flags = 0;
			ttykbhacks_fkey_init[kb->kb_fstyle](kb);
			tp->t_state |= TS_KBHACKS;
		} else if (!i && (tp->t_state & TS_KBHACKS)) {
			tp->t_state &= ~TS_KBHACKS;
			free(tp->T_LINEP, M_PCB);
		}
		break;

	case TIOCKBSFSTYLE:
		if (!(tp->t_state & TS_KBHACKS))
			return(ENOTTY);
		kb = (struct ttykbhacks *)tp->T_LINEP;
		i = *(int *)data;
		if (i > KBHACKS_FSTYLE_MAX)
			return(EINVAL);
		s = spltty();
		kb->kb_fstyle = i;
		ttykbhacks_fkey_init[kb->kb_fstyle](kb);
		splx(s);
		break;

	case TIOCKBGFSTYLE:
		if (!(tp->t_state & TS_KBHACKS))
			return(ENOTTY);
		kb = (struct ttykbhacks *)tp->T_LINEP;
		*(int *)data = kb->kb_fstyle;
		break;

	case TIOCKBSF11MOD:
		if (!(tp->t_state & TS_KBHACKS))
			return(ENOTTY);
		kb = (struct ttykbhacks *)tp->T_LINEP;
		if (*(int *)data)
			kb->kb_flags |= KBF_VT2XXF11;
		else
			kb->kb_flags &= ~KBF_VT2XXF11;
		break;

	case TIOCKBGF11MOD:
		if (!(tp->t_state & TS_KBHACKS))
			return(ENOTTY);
		kb = (struct ttykbhacks *)tp->T_LINEP;
		*(int *)data = (kb->kb_flags & KBF_VT2XXF11) != 0;
		break;

	case TIOCKBSFKEYS:
		if (!(tp->t_state & TS_KBHACKS))
			return(ENOTTY);
		kb = (struct ttykbhacks *)tp->T_LINEP;
		bcopy(data, &kb->kb_ruskey, 3);
		break;

	case TIOCKBGFKEYS:
		if (!(tp->t_state & TS_KBHACKS))
			return(ENOTTY);
		kb = (struct ttykbhacks *)tp->T_LINEP;
		bcopy(&kb->kb_ruskey, data, 3);
		break;

	case TIOCKBSRUSMAP:
		if (!(tp->t_state & TS_KBHACKS))
			return(ENOTTY);
		kb = (struct ttykbhacks *)tp->T_LINEP;
		bcopy(data, kb->kb_rusmap, 94);
		break;

	case TIOCKBGRUSMAP:
		if (!(tp->t_state & TS_KBHACKS))
			return(ENOTTY);
		kb = (struct ttykbhacks *)tp->T_LINEP;
		bcopy(kb->kb_rusmap, data, 94);
		break;

	case TIOCKBRESET:
		if (!(tp->t_state & TS_KBHACKS))
			return(ENOTTY);
		kb = (struct ttykbhacks *)tp->T_LINEP;
		kb->kb_flags &= ~(KBF_INRUS|KBF_META);
		break;

	default:
		return (-1);
	}
	return (0);
}
#endif
