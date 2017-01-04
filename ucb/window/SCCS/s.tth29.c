h52252
s 00010/00005/00068
d D 3.6 88/06/29 21:36:46 bostic 7 6
c install approved copyright notice
e
s 00013/00007/00060
d D 3.5 88/02/21 13:37:38 bostic 6 5
c written by Edward Wang; attach Berkeley specific copyright
e
s 00014/00005/00053
d D 3.4 86/08/04 14:16:29 edward 5 3
c WWM_USR and WWM_DIM added, termcap strings XS and XE added,
c display mode escape sequences changed
e
s 00010/00001/00057
d R 3.4 86/05/02 13:35:45 edward 4 3
c added WWM_USR (user mode) and XS and XE termcap strings
e
s 00001/00067/00057
d D 3.3 85/08/14 21:51:05 edward 3 2
c tt_setinsert and tt_setmodes added
e
s 00006/00000/00118
d D 3.2 85/04/24 16:24:06 edward 2 1
c copyright messages
e
s 00118/00000/00000
d D 3.1 84/11/21 00:30:28 edward 1 0
c date and time created 84/11/21 00:30:28 by edward
e
u
U
t
T
I 1
D 6
#ifndef lint
static char sccsid[] = "%W% %G%";
#endif

E 6
I 2
/*
D 6
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 6
I 6
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 7
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 7
I 7
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
E 7
E 6
 */
I 6

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 6

E 2
#include "ww.h"
#include "tt.h"

/*
I 5
 * H29 Driver
 *
 * WWM_USR mode is alternate character set.
 *
E 5
kC|h29|heath-29|z29|zenith-29:\
	:am:bc=\ED:bt=\E-:cr=^M:do=^J:nl=^J:bl=^G:\
	:al=\EL:le=^H:bs:cd=\EJ:ce=\EK:cl=\EE:cm=\EY%+ %+ :co#80:dc=\EN:\
	:dl=1*\EM:do=\EB:ei=\EO:ho=\EH:im=\E@:li#24:mi:nd=\EC:as=\EF:ae=\EG:\
	:ms:ta=^I:pt:sr=\EI:se=\Eq:so=\Ep:up=\EA:vs=\Ex4:ve=\Ey4:\
	:kb=^H:ku=\EA:kd=\EB:kl=\ED:kr=\EC:kh=\EH:kn#1:k0=\E~:l0=HOME:\
	:k1=\ES:k2=\ET:k3=\EU:k4=\EV:k5=\EW:k6=\EP:k7=\EQ:k8=\ER:k9=\E01:\
	:es:hs:ts=\Ej\Ex5\Ex1\EY8%+ \Eo:fs=\Ek\Ey5:ds=\Ey1:us=\Es8:ue=\Es0:
D 5
*/
E 5
I 5
 *
 */
E 5

D 3
#define NCOL	80
#define NROW	24

extern char *gen_VS;
extern char *gen_VE;

extern int h19_msp10c;

E 3
#define pc(c)	ttputc('c')
#define esc()	pc(\033)
D 3
#define PAD(ms10) { \
	register i; \
	for (i = ((ms10) + 5) / h19_msp10c; --i >= 0;) \
		pc(\0); \
}
#define ICPAD() PAD((NCOL - tt.tt_col) * 1)	/* 0.1 ms per char */
#define ILPAD() PAD((NROW - tt.tt_row) * 10)	/* 1 ms per char */
E 3

D 3
#define h29_setinsert(m) (esc(), (tt.tt_insert = (m)) ? pc(@) : pc(O))

E 3
h29_setmodes(new)
register new;
{
	register modes = '0';

	if (new & WWM_REV)
D 5
		modes |= 1;
E 5
I 5
		modes += 0x01;
E 5
	if (new & WWM_BLK)
D 5
		modes |= 2;
E 5
I 5
		modes += 0x02;
	if (new & WWM_DIM)
		modes += 0x04;
E 5
	if (new & WWM_UL)
D 5
		modes |= 8;
E 5
I 5
		modes += 0x08;
	if (new & WWM_USR)
		modes += 0x10;
E 5
	esc();
	pc(s);
	ttputc(modes);
	if (new & WWM_GRP) {
		if ((tt.tt_modes & WWM_GRP) == 0)
			esc(), pc(F);
	} else
		if (tt.tt_modes & WWM_GRP)
			esc(), pc(G);
	tt.tt_modes = new;
}

D 3
h29_putc(c)
register char c;
{
	if (tt.tt_nmodes != tt.tt_modes)
		h29_setmodes(tt.tt_nmodes);
	if (tt.tt_ninsert != tt.tt_insert)
		h29_setinsert(tt.tt_ninsert);
	ttputc(c);
	if (tt.tt_insert)
		ICPAD();
	if (++tt.tt_col == NCOL)
		tt.tt_col = NCOL - 1;
}

h29_write(p, n)
register char *p;
register n;
{
	if (tt.tt_nmodes != tt.tt_modes)
		h29_setmodes(tt.tt_nmodes);
	if (tt.tt_ninsert != tt.tt_insert)
		h29_setinsert(tt.tt_ninsert);
	if (tt.tt_insert) {
		while (--n >= 0) {
			ttputc(*p++);
			ICPAD();
			tt.tt_col++;
		}
	} else {
		tt.tt_col += n;
		while (--n >= 0)
			ttputc(*p++);
	}
	if (tt.tt_col == NCOL)
		tt.tt_col = NCOL - 1;
}

h29_end()
{
	h29_setmodes(0);
	h29_setinsert(0);
	if (gen_VE)
		ttputs(gen_VE);
	esc();
	pc(v);
}

E 3
tt_h29()
{
	if (tt_h19() < 0)
		return -1;
D 3
	tt.tt_putc = h29_putc;
	tt.tt_write = h29_write;
	tt.tt_end = h29_end;
E 3
I 3
	tt.tt_setmodes = h29_setmodes;
E 3
D 5
	tt.tt_availmodes = WWM_BLK|WWM_UL|WWM_REV|WWM_GRP;
E 5
I 5
	tt.tt_availmodes |= WWM_BLK|WWM_UL|WWM_DIM|WWM_USR;
E 5
	return 0;
}
E 1
