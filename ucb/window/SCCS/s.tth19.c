h48556
s 00010/00005/00267
d D 3.19 88/06/29 21:36:43 bostic 20 19
c install approved copyright notice
e
s 00023/00002/00249
d D 3.18 88/05/11 18:04:15 edward 19 18
c scrolling region, suggestion from Ray Moody (ray@j.cc.purdue.edu)
e
s 00013/00007/00238
d D 3.17 88/02/21 13:37:36 bostic 18 16
c written by Edward Wang; attach Berkeley specific copyright
e
s 00014/00000/00245
d R 3.17 86/05/02 13:35:53 edward 17 16
c added WWM_USR (user mode) and XS and XE termcap strings
e
s 00005/00006/00240
d D 3.16 85/09/20 15:15:22 edward 16 15
c correct padding
e
s 00012/00007/00234
d D 3.15 85/08/14 21:50:49 edward 15 14
c tt_setinsert and tt_setmodes added
e
s 00006/00000/00235
d D 3.14 85/04/24 16:16:02 edward 14 13
c copyright messages
e
s 00001/00001/00234
d D 3.13 84/05/23 01:58:31 edward 13 12
c new sccs id
e
s 00010/00010/00225
d D 3.12 84/03/03 22:46:31 edward 12 11
c interrupt driven input
e
s 00045/00048/00190
d D 3.11 83/12/17 15:38:37 edward 11 10
c WWM_GRP added
e
s 00001/00001/00237
d D 3.10 83/12/02 22:18:16 edward 10 9
c typo
e
s 00058/00088/00180
d D 3.9 83/09/15 12:23:10 edward 9 8
c reworked tt stuff
e
s 00003/00003/00265
d D 3.8 83/08/17 17:41:07 edward 8 7
c better wrap around handling.
e
s 00006/00001/00262
d D 3.7 83/08/17 16:36:18 edward 7 6
c fixed wrap around problem
e
s 00009/00007/00254
d D 3.6 83/08/17 15:35:27 edward 6 5
c nicer termcap interface and use vs and ve strings in tth19.c
e
s 00001/00000/00260
d D 3.5 83/08/17 14:28:58 edward 5 4
c tt_availmodes
e
s 00006/00019/00254
d D 3.4 83/08/15 18:14:51 edward 4 3
c tt cleanup
e
s 00001/00001/00272
d D 3.3 83/08/12 18:26:17 edward 3 2
c cursor home bug
e
s 00000/00000/00273
d D 3.2 83/08/11 17:24:04 edward 2 1
i
c last few day's work
e
s 00273/00000/00000
d D 3.1 83/08/09 18:35:17 edward 1 0
c date and time created 83/08/09 18:35:17 by edward
e
u
U
t
T
I 1
D 18
#ifndef lint
D 13
static	char *sccsid = "%W% %E%";
E 13
I 13
static char sccsid[] = "%W% %G%";
E 13
#endif

E 18
I 14
/*
D 18
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 18
I 18
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 20
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 20
I 20
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
E 20
E 18
 */
I 18

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 18

E 14
#include "ww.h"
I 4
#include "tt.h"
E 4

/*
kb|h19|heath|h19-b|h19b|heathkit|heath-19|z19|zenith:
	cr=^M:nl=^J:bl=^G:al=1*\EL:am:le=^H:bs:cd=\EJ:ce=\EK:
	cl=\EE:cm=\EY%+ %+ :co#80:dc=\EN:dl=1*\EM:do=\EB:
	ei=\EO:ho=\EH:im=\E@:li#24:mi:nd=\EC:as=\EF:ae=\EG:ms:
	ta=^I:pt:sr=\EI:se=\Eq:so=\Ep:up=\EA:vs=\Ex4:ve=\Ey4:
	kb=^h:ku=\EA:kd=\EB:kl=\ED:kr=\EC:kh=\EH:
	kn#8:k1=\ES:k2=\ET:k3=\EU:k4=\EV:k5=\EW:
	l6=blue:l7=red:l8=white:k6=\EP:k7=\EQ:k8=\ER:
	es:hs:ts=\Ej\Ex5\Ex1\EY8%+ \Eo:fs=\Ek\Ey5:ds=\Ey1:
*/

I 9
#define NCOL	80
#define NROW	24

E 9
D 11
char h19_frame[16] = {
	' ',      '`'|0x80, 'a'|0x80, 'e'|0x80,
	'`'|0x80, '`'|0x80, 'f'|0x80, 'v'|0x80,
	'a'|0x80, 'd'|0x80, 'a'|0x80, 'u'|0x80,
	'c'|0x80, 't'|0x80, 's'|0x80, 'b'|0x80
E 11
I 11
#define G (WWM_GRP << WWC_MSHIFT)
short h19_frame[16] = {
	' ',	'`'|G,	'a'|G,	'e'|G,
	'`'|G,	'`'|G,	'f'|G,	'v'|G,
	'a'|G,	'd'|G,	'a'|G,	'u'|G,
	'c'|G,	't'|G,	's'|G,	'b'|G
E 11
};

D 9
char h19_row, h19_col;
char h19_modes, h19_nmodes;
char h19_insert, h19_ninsert;
char h19_graphics;
E 9
I 9
D 16
extern char *gen_VS;
extern char *gen_VE;
E 16
I 16
extern struct tt_str *gen_VS;
extern struct tt_str *gen_VE;
E 16

D 11
char h19_graphics;			/* in graphics mode */
E 9
short h19_msp10c;
E 11
I 11
int h19_msp10c;
E 11
I 6
D 9
char *h19_VS;
char *h19_VE;
E 9
E 6

D 12
#define pc(c)	putchar('c')
E 12
I 12
#define pc(c)	ttputc('c')
E 12
#define esc()	pc(\033)
#define PAD(ms10) { \
	register i; \
	for (i = ((ms10) + 5) / h19_msp10c; --i >= 0;) \
		pc(\0); \
}
D 9
#define ICPAD() PAD((80 - h19_col) * 1)		/* 0.1 ms per char */
#define ILPAD() PAD((24 - h19_row) * 10);	/* 1 ms per char */
E 9
I 9
#define ICPAD() PAD((NCOL - tt.tt_col) * 1)	/* 0.1 ms per char */
#define ILPAD() PAD((NROW - tt.tt_row) * 10)	/* 1 ms per char */
E 9

D 11
#define SETINSERT(m) \
D 9
	((m) != h19_insert \
		? (esc(), (h19_insert = (m)) ? pc(@) : pc(O)) : 0)
E 9
I 9
	((m) != tt.tt_insert \
		? (esc(), (tt.tt_insert = (m)) ? pc(@) : pc(O)) : 0)
E 9
#define SETMODES(m) \
D 9
	((m) != h19_modes \
		? (esc(), (h19_modes = (m)) ? pc(p) : pc(q)) : 0)
E 9
I 9
	((m) != tt.tt_modes \
		? (esc(), (tt.tt_modes = (m)) ? pc(p) : pc(q)) : 0)
E 9
#define SETGRAPHICS(m) \
	((m) != h19_graphics \
		? (esc(), (h19_graphics = (m)) ? pc(F) : pc(G)) : 0)
E 11
I 11
D 15
#define h19_setinsert(m) (esc(), (tt.tt_insert = (m)) ? pc(@) : pc(O))
E 15
I 15
#define H19_SETINSERT(m) (esc(), (tt.tt_insert = (m)) ? pc(@) : pc(O))
E 15
E 11

I 15
h19_setinsert(new)
{
	H19_SETINSERT(new);
}

E 15
I 11
h19_setmodes(new)
register new;
{
	register diff;

	diff = new ^ tt.tt_modes;
	if (diff & WWM_REV) {
		esc();
		if (new & WWM_REV)
			pc(p);
		else
			pc(q);
	}
	if (diff & WWM_GRP) {
		esc();
		if (new & WWM_GRP)
			pc(F);
		else
			pc(G);
	}
	tt.tt_modes = new;
}

E 11
D 9
h19_setinsert(new)
char new;
{
	h19_ninsert = new;
}

h19_setmodes(new)
{
	h19_nmodes = new & WWM_REV;
}

E 9
h19_insline()
{
	esc();
	pc(L);
	ILPAD();
}

h19_delline()
{
	esc();
	pc(M);
	ILPAD();
}

h19_putc(c)
register char c;
{
D 9
	SETMODES(h19_nmodes);
	SETINSERT(h19_ninsert);
E 9
I 9
D 11
	SETMODES(tt.tt_nmodes);
	SETINSERT(tt.tt_ninsert);
E 9
	if (c & 0x80) {
		SETGRAPHICS(1);
		putchar(c & 0x7f);
	} else {
		SETGRAPHICS(0);
		putchar(c);
	}
E 11
I 11
	if (tt.tt_nmodes != tt.tt_modes)
D 15
		h19_setmodes(tt.tt_nmodes);
E 15
I 15
		(*tt.tt_setmodes)(tt.tt_nmodes);
E 15
	if (tt.tt_ninsert != tt.tt_insert)
D 15
		h19_setinsert(tt.tt_ninsert);
E 15
I 15
		H19_SETINSERT(tt.tt_ninsert);
E 15
D 12
	putchar(c);
E 12
I 12
	ttputc(c);
E 12
E 11
D 9
	if (h19_insert)
E 9
I 9
	if (tt.tt_insert)
E 9
		ICPAD();
D 7
	h19_col++;
E 7
I 7
D 8
	if (++h19_col >= 80)
E 8
I 8
D 9
	if (++h19_col == 80)
E 8
		h19_col = 79;
E 9
I 9
	if (++tt.tt_col == NCOL)
		tt.tt_col = NCOL - 1;
E 9
E 7
}

D 9
h19_write(start, end)
register char *start, *end;
E 9
I 9
h19_write(p, n)
register char *p;
register n;
E 9
{
D 11
	register char c;

D 9
	SETMODES(h19_nmodes);
	SETINSERT(h19_ninsert);
	if (h19_insert) {
		while (start <= end) {
			if ((c = *start++) & 0x80) {
E 9
I 9
	SETMODES(tt.tt_nmodes);
	SETINSERT(tt.tt_ninsert);
E 11
I 11
	if (tt.tt_nmodes != tt.tt_modes)
D 15
		h19_setmodes(tt.tt_nmodes);
E 15
I 15
		(*tt.tt_setmodes)(tt.tt_nmodes);
E 15
	if (tt.tt_ninsert != tt.tt_insert)
D 15
		h19_setinsert(tt.tt_ninsert);
E 15
I 15
		H19_SETINSERT(tt.tt_ninsert);
E 15
E 11
	if (tt.tt_insert) {
		while (--n >= 0) {
D 11
			if ((c = *p++) & 0x80) {
E 9
				SETGRAPHICS(1);
				putchar(c & 0x7f);
			} else {
				SETGRAPHICS(0);
				putchar(c);
			}
E 11
I 11
D 12
			putchar(*p++);
E 12
I 12
			ttputc(*p++);
E 12
E 11
			ICPAD();
D 9
			h19_col++;
E 9
I 9
			tt.tt_col++;
E 9
		}
	} else {
D 9
		h19_col += end - start + 1;
		while (start <= end)
			if ((c = *start++) & 0x80) {
E 9
I 9
		tt.tt_col += n;
D 16
		while (--n >= 0)
D 11
			if ((c = *p++) & 0x80) {
E 9
				SETGRAPHICS(1);
				putchar(c & 0x7f);
			} else {
				SETGRAPHICS(0);
				putchar(c);
			}
E 11
I 11
D 12
			putchar(*p++);
E 12
I 12
			ttputc(*p++);
E 16
I 16
		ttwrite(p, n);
E 16
E 12
E 11
	}
I 7
D 8
	if (h19_col >= 80)
E 8
I 8
D 9
	if (h19_col == 80)
E 8
		h19_col = 79;
E 9
I 9
	if (tt.tt_col == NCOL)
		tt.tt_col = NCOL - 1;
E 9
E 7
}

D 9
h19_blank(n)
register n;
{
	if (n <= 0)
		return;
	SETMODES(h19_nmodes);
	SETINSERT(h19_ninsert);
	if (h19_insert) {
		while (--n >= 0) {
			putchar(' ');
			ICPAD();
			h19_col++;
		}
	} else {
		h19_col += n;
		while (--n >= 0)
			putchar(' ');
	}
I 7
D 8
	if (h19_col >= 80)
E 8
I 8
	if (h19_col == 80)
E 8
		h19_col = 79;
E 7
}

E 9
h19_move(row, col)
register char row, col;
{
D 9
	if (h19_row == row) {
		if (h19_col == col)
E 9
I 9
	if (tt.tt_row == row) {
		if (tt.tt_col == col)
E 9
			return;
I 19
		if (col == 0) {
			pc(\r);
			goto out;
		}
E 19
D 9
		if (h19_col == col - 1) {
E 9
I 9
		if (tt.tt_col == col - 1) {
E 9
			esc();
			pc(C);
			goto out;
D 9
		} else if (h19_col == col + 1) {
E 9
I 9
D 19
		} else if (tt.tt_col == col + 1) {
E 19
I 19
		}
		if (tt.tt_col == col + 1) {
E 19
E 9
			pc(\b);
			goto out;
		}
	}
D 9
	if (h19_col == col) {
		if (h19_row == row + 1) {
E 9
I 9
	if (tt.tt_col == col) {
		if (tt.tt_row == row + 1) {
E 9
			esc();
			pc(A);
			goto out;
D 9
		} else if (h19_row == row + 1) {
E 9
I 9
D 10
		} else if (tt.tt_row == row + 1) {
E 10
I 10
D 19
		} else if (tt.tt_row == row - 1) {
E 19
I 19
		}
		if (tt.tt_row == row - 1) {
E 19
E 10
E 9
			pc(\n);
			goto out;
		}
	}
D 3
	if (col == 1 && row == 1) {
E 3
I 3
	if (col == 0 && row == 0) {
E 3
		esc();
		pc(H);
		goto out;
	}
	esc();
	pc(Y);
D 12
	putchar(' ' + row);
	putchar(' ' + col);
E 12
I 12
	ttputc(' ' + row);
	ttputc(' ' + col);
E 12
out:
D 9
	h19_col = col;
	h19_row = row;
E 9
I 9
	tt.tt_col = col;
	tt.tt_row = row;
E 9
}

h19_init()
{
I 6
D 9
	if (h19_VS)
		fputs(h19_VS, stdout);
E 9
I 9
	if (gen_VS)
D 12
		fputs(gen_VS, stdout);
E 12
I 12
D 16
		ttputs(gen_VS);
E 16
I 16
		ttxputs(gen_VS);
E 16
E 12
E 9
E 6
D 4
	float cpms = (float) wwbaud / 10000;	/* char per ms */

	h19_msp10c = 10 / cpms;			/* ms per 10 char */
#ifdef notdef
	tt.tt_ILmf = cpms;			/* 1 ms */
	tt.tt_ILov = 2;
	tt.tt_ICmf = cpms * 1.5 ;		/* 1.5 ms */
	tt.tt_ICov = 2;
	tt.tt_DCmf = 0;
	tt.tt_DCov = 2;
#endif
	return 0;
}

h19_reset()
{
E 4
	esc();
D 6
	pc(x);
	pc(4);
E 6
I 6
	pc(w);
E 6
	esc();
	pc(E);
D 6
	esc();
	pc(w);
E 6
D 9
	h19_col = h19_row = 0;
	h19_insert = 0;
E 9
I 9
	tt.tt_col = tt.tt_row = 0;
	tt.tt_ninsert = tt.tt_insert = 0;
	tt.tt_nmodes = tt.tt_modes = 0;
E 9
D 11
	h19_graphics = 0;
E 11
D 9
	h19_modes = 0;
E 9
}

D 4
h19_cleanup()
E 4
I 4
h19_end()
E 4
{
D 11
	SETMODES(0);
	SETINSERT(0);
	SETGRAPHICS(0);
E 11
I 11
D 15
	h19_setmodes(0);
	h19_setinsert(0);
E 15
E 11
I 6
D 9
	if (h19_VE)
		fputs(h19_VE, stdout);
E 9
I 9
	if (gen_VE)
D 12
		fputs(gen_VE, stdout);
E 12
I 12
D 16
		ttputs(gen_VE);
E 16
I 16
		ttxputs(gen_VE);
E 16
E 12
E 9
E 6
	esc();
D 6
	pc(y);
	pc(4);
	esc();
E 6
	pc(v);
}

h19_clreol()
{
	esc();
	pc(K);
}

h19_clreos()
{
	esc();
	pc(J);
}

h19_clear()
{
	esc();
	pc(E);
}

h19_delchar()
{
	esc();
	pc(N);
}

I 19
h19_scroll_down()
{
	h19_move(NROW - 1, 0);
	pc(\n);
}

h19_scroll_up()
{
	h19_move(0, 0);
	esc();
	pc(I);
}

E 19
tt_h19()
{
I 4
	float cpms = (float) wwbaud / 10000;	/* char per ms */

	h19_msp10c = 10 / cpms;			/* ms per 10 char */
I 6
D 9
	h19_VS = tt_xgetstr("vs");
	h19_VE = tt_xgetstr("ve");
E 6
E 4
	tt.tt_setinsert = h19_setinsert;
	tt.tt_setmodes = h19_setmodes;
E 9
I 9
D 12
	gen_VS = tt_xgetstr("vs");
	gen_VE = tt_xgetstr("ve");
E 12
I 12
	gen_VS = ttxgetstr("vs");
	gen_VE = ttxgetstr("ve");
E 12

	tt.tt_init = h19_init;
	tt.tt_end = h19_end;

E 9
	tt.tt_insline = h19_insline;
	tt.tt_delline = h19_delline;
	tt.tt_delchar = h19_delchar;
D 9
	tt.tt_blank = h19_blank;
	tt.tt_init = h19_init;
D 4
	tt.tt_cleanup = h19_cleanup;
E 4
I 4
	tt.tt_end = h19_end;
E 9
E 4
	tt.tt_clreol = h19_clreol;
	tt.tt_clreos = h19_clreos;
	tt.tt_clear = h19_clear;
	tt.tt_move = h19_move;
D 4
	tt.tt_reset = h19_reset;
E 4
	tt.tt_write = h19_write;
	tt.tt_putc = h19_putc;
I 19
	tt.tt_scroll_down = h19_scroll_down;
	tt.tt_scroll_up = h19_scroll_up;
E 19
I 15
	tt.tt_setinsert = h19_setinsert;
	tt.tt_setmodes = h19_setmodes;
E 15
D 9
	tt.tt_ncol = 80;
	tt.tt_nrow = 24;
E 9
I 9

	tt.tt_ncol = NCOL;
	tt.tt_nrow = NROW;
	tt.tt_hasinsert = 1;
E 9
I 5
D 11
	tt.tt_availmodes = WWM_REV;
E 11
I 11
	tt.tt_availmodes = WWM_REV|WWM_GRP;
E 11
E 5
	tt.tt_frame = h19_frame;
	return 0;
}
E 1
