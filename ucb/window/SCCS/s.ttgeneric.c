h32728
s 00010/00005/00442
d D 3.35 88/06/29 21:36:39 bostic 37 36
c install approved copyright notice
e
s 00054/00005/00393
d D 3.34 88/05/11 18:04:17 edward 36 35
c scrolling region, suggestion from Ray Moody (ray@j.cc.purdue.edu)
e
s 00013/00007/00385
d D 3.33 88/02/21 13:37:34 bostic 35 34
c written by Edward Wang; attach Berkeley specific copyright
e
s 00001/00001/00391
d D 3.32 87/09/15 14:55:51 bostic 34 33
c >128 column fix; bug report 4.3BSD/ucb/114
e
s 00003/00000/00389
d D 3.31 87/05/18 12:11:20 edward 33 32
c use \n at bottom to scroll entire screen,
c use clear to eos to clear entire screen
e
s 00014/00006/00375
d D 3.30 86/08/05 00:30:07 edward 32 30
c handle xn, check for UL == SO, ttstrcmp() added
e
s 00014/00006/00375
d R 3.30 86/08/04 14:20:44 edward 31 30
c handle xn, check for US == SO, ttstrcmp() added
e
s 00014/00000/00367
d D 3.29 86/08/04 14:16:35 edward 30 28
c WWM_USR and WWM_DIM added, termcap strings XS and XE added,
c display mode escape sequences changed
e
s 00014/00000/00367
d R 3.29 86/05/02 13:36:05 edward 29 28
c added WWM_USR (user mode) and XS and XE termcap strings
e
s 00000/00001/00367
d D 3.28 86/01/30 18:43:46 edward 28 27
c removed extra tt_col += n in gen_write
e
s 00074/00084/00294
d D 3.27 85/09/20 15:15:31 edward 27 26
c correct padding
e
s 00002/00002/00376
d D 3.26 85/08/14 21:50:56 edward 26 25
c tt_setinsert and tt_setmodes added
e
s 00015/00001/00363
d D 3.25 85/06/04 18:57:11 edward 25 24
c check for ANSI graphics, from Dave Comay
e
s 00006/00000/00358
d D 3.24 85/04/24 16:17:29 edward 24 23
c copyright messages
e
s 00001/00001/00357
d D 3.23 84/05/23 01:59:12 edward 23 22
c new sccs id
e
s 00041/00042/00317
d D 3.22 84/03/03 22:47:13 edward 22 21
c interrupt driven input
e
s 00006/00009/00353
d D 3.21 84/03/02 13:30:46 edward 21 20
c lint (termcap)
e
s 00010/00006/00352
d D 3.20 84/01/11 16:27:51 edward 20 19
c Use as and ae for WWM_GRP, and set tt_availmodes accordingly
e
s 00001/00001/00357
d D 3.19 83/12/21 13:21:53 edward 19 18
c = instead of ==
e
s 00014/00043/00344
d D 3.18 83/12/17 15:38:46 edward 18 17
c WWM_GRP added
e
s 00044/00005/00343
d D 3.17 83/09/17 17:10:47 edward 17 16
c support graphics if setup by somebody else.
e
s 00064/00108/00284
d D 3.16 83/09/15 12:23:47 edward 16 15
c reworked tt stuff
e
s 00003/00000/00389
d D 3.15 83/08/24 17:46:19 edward 15 14
c knows about the bd flag now
e
s 00002/00002/00387
d D 3.14 83/08/24 11:39:44 edward 14 13
c use gen_set*1() in gen_move() instead of gen_set*()
e
s 00044/00018/00345
d D 3.13 83/08/23 20:28:43 edward 13 12
c delay set modes and insert.
c and a lot of stuff to make concepts work.
e
s 00008/00000/00355
d D 3.12 83/08/23 15:13:14 edward 12 11
c knows about ug sg
e
s 00000/00002/00355
d D 3.11 83/08/18 12:12:03 edward 11 10
c gen_strings and gen_strp left over from before.
e
s 00017/00026/00340
d D 3.10 83/08/17 17:41:26 edward 10 9
c better wrap around handling.
e
s 00025/00003/00341
d D 3.9 83/08/17 16:36:27 edward 9 8
c fixed wrap around problem
e
s 00035/00062/00309
d D 3.8 83/08/17 15:35:35 edward 8 7
c nicer termcap interface and use vs and ve strings in tth19.c
e
s 00003/00004/00368
d D 3.7 83/08/17 14:51:49 edward 7 6
c ww_availmodes and stuff
e
s 00003/00002/00369
d D 3.6 83/08/15 18:46:17 edward 6 5
c lint
e
s 00006/00010/00365
d D 3.5 83/08/15 18:13:33 edward 5 4
c tt cleanup and some bug fixes
e
s 00242/00140/00133
d D 3.4 83/08/15 17:43:01 edward 4 3
c really uses termcap now.
e
s 00001/00001/00272
d D 3.3 83/08/12 18:26:12 edward 3 2
c cursor home bug
e
s 00000/00000/00273
d D 3.2 83/08/11 17:25:10 edward 2 1
c last few day's work
e
s 00273/00000/00000
d D 3.1 83/08/09 18:49:13 edward 1 0
c date and time created 83/08/09 18:49:13 by edward
e
u
U
t
T
I 1
D 35
#ifndef lint
D 23
static	char *sccsid = "%W% %E%";
E 23
I 23
static char sccsid[] = "%W% %G%";
E 23
#endif

E 35
I 24
/*
D 35
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 35
I 35
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 37
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 37
I 37
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
E 37
E 35
 */
I 35

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 35

E 24
#include "ww.h"
I 5
#include "tt.h"
E 5

I 21
char PC, *BC, *UP;
short ospeed;
E 21
I 6
D 8
char *tgetstr();
E 8
D 27
char *tgoto();
E 27

I 25
	/* normal frame */
E 25
E 6
D 4
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

E 4
D 18
char gen_frame[16] = {
E 18
I 18
short gen_frame[16] = {
E 18
	' ', '|', '-', '+',
	'|', '|', '+', '+',
D 5
	'-', '|', '-', '+',
E 5
I 5
	'-', '+', '-', '+',
E 5
	'+', '+', '+', '+'
};

I 25
	/* ANSI graphics frame */
#define G (WWM_GRP << WWC_MSHIFT)
short ansi_frame[16] = {
	' ',	'x'|G,	'Q'|G,	'm'|G,
	'x'|G,	'x'|G,	'l'|G,	't'|G,
	'q'|G,	'j'|G,	'q'|G,	'v'|G,
	'k'|G,	'u'|G,	'w'|G,	'n'|G
};
D 32
#define ANSI_AS "\033(0"	/* ) */
E 32
I 32
struct tt_str ansi_AS = {
	"\033(0", 3
};
E 32

E 25
I 17
D 18
char gen_graphics;

E 18
E 17
D 4
char gen_row, gen_col;
char gen_modes, gen_nmodes;
char gen_insert, gen_ninsert;
char gen_graphics;
short gen_msp10c;
E 4
I 4
D 16
int gen_row, gen_col;
D 13
char gen_modes;
D 7
char gen_availmodes;
E 7
char gen_insert;
E 13
I 13
char gen_modes, gen_nmodes;
char gen_insert, gen_ninsert;
E 13
E 4
D 6

D 4
#define pc(c)	putchar('c')
#define esc()	pc(\033)
#define PAD(ms10) { \
	register i; \
	for (i = ((ms10) + 5) / gen_msp10c; --i >= 0;) \
		pc(\0); \
E 4
I 4
char *tgetstr();
E 6

E 16
D 27
char *gen_CM;
char *gen_IM;
char *gen_IC;
char *gen_IP;
char *gen_EI;
char *gen_DC;
char *gen_AL;
char *gen_DL;
char *gen_CE;
char *gen_CD;
char *gen_CL;
char *gen_VS;
char *gen_VE;
I 13
char *gen_TI;
char *gen_TE;
E 13
char *gen_SO;
char *gen_SE;
char *gen_US;
char *gen_UE;
char *gen_UP;
char *gen_PC;
char *gen_BC;
char *gen_ND;
char *gen_HO;
char *gen_NL;
I 17
D 20
char *gen_GS;			/* graphics */
char *gen_GE;
E 20
I 20
char *gen_AS;
char *gen_AE;
E 27
I 27
struct tt_str *gen_CM;
struct tt_str *gen_IM;
struct tt_str *gen_IC;
struct tt_str *gen_IP;
struct tt_str *gen_EI;
struct tt_str *gen_DC;
struct tt_str *gen_AL;
struct tt_str *gen_DL;
struct tt_str *gen_CE;
struct tt_str *gen_CD;
struct tt_str *gen_CL;
struct tt_str *gen_VS;
struct tt_str *gen_VE;
struct tt_str *gen_TI;
struct tt_str *gen_TE;
struct tt_str *gen_SO;
struct tt_str *gen_SE;
struct tt_str *gen_US;
struct tt_str *gen_UE;
struct tt_str *gen_UP;
struct tt_str *gen_PC;
struct tt_str *gen_BC;
struct tt_str *gen_ND;
struct tt_str *gen_HO;
struct tt_str *gen_NL;
I 36
struct tt_str *gen_CR;
E 36
struct tt_str *gen_AS;
struct tt_str *gen_AE;
I 30
struct tt_str *gen_XS;
struct tt_str *gen_XE;
I 36
struct tt_str *gen_SF;
struct tt_str *gen_SR;
struct tt_str *gen_CS;
E 36
E 30
E 27
E 20
E 17
char gen_MI;
char gen_MS;
char gen_AM;
char gen_OS;
char gen_BS;
I 36
char gen_DA;
E 36
I 15
char gen_DB;
I 33
char gen_NS;
E 33
I 32
char gen_XN;
E 32
E 15
int gen_CO;
int gen_LI;
I 12
int gen_UG;
int gen_SG;
E 12
D 11
char gen_strings[1024];
char *gen_strp = gen_strings;
E 11

D 22
#define pc(c) putchar('c')
#define ps(s) fputs((s), stdout)
E 22
I 22
D 27
#define ps(s) ttputs(s)
E 22

E 27
D 8
gen_pc(c)
{
	putchar(c);
E 4
}
D 4
#define ICPAD() PAD((80 - gen_col) * 1)		/* 0.1 ms per char */
#define ILPAD() PAD((24 - gen_row) * 10);	/* 1 ms per char */
E 4

D 4
#define SETINSERT(m) \
	((m) != gen_insert \
		? (esc(), (gen_insert = (m)) ? pc(@) : pc(O)) : 0)
#define SETMODES(m) \
	((m) != gen_modes \
		? (esc(), (gen_modes = (m)) ? pc(p) : pc(q)) : 0)
#define SETGRAPHICS(m) \
	((m) != gen_graphics \
		? (esc(), (gen_graphics = (m)) ? pc(F) : pc(G)) : 0)
E 4
I 4
gen_sc(c)
{
	*gen_strp++ = c;
}
E 4

E 8
gen_setinsert(new)
I 13
D 16
{
	gen_ninsert = new;
}

gen_setinsert1(new)
E 16
E 13
char new;
{
D 4
	gen_ninsert = new;
E 4
I 4
D 16
	if (gen_insert == new)
		return;
E 16
	if (new) {
		if (gen_IM)
D 27
			ps(gen_IM);
E 27
I 27
			ttxputs(gen_IM);
E 27
	} else
		if (gen_EI)
D 27
			ps(gen_EI);
E 27
I 27
			ttxputs(gen_EI);
E 27
D 16
	gen_insert = new;
E 16
I 16
	tt.tt_insert = new;
E 16
E 4
}

gen_setmodes(new)
I 13
D 16
char new;
{
	gen_nmodes = new & tt.tt_availmodes;
}

gen_setmodes1(new)
E 16
E 13
I 4
register new;
E 4
{
D 4
	gen_nmodes = new & WWM_REV;
E 4
I 4
	register diff;

D 7
	new &= gen_availmodes;
E 7
I 7
D 13
	new &= tt.tt_availmodes;
E 13
E 7
D 16
	if ((diff = new ^ gen_modes) == 0)
		return;
E 16
I 16
	diff = new ^ tt.tt_modes;
E 16
	if (diff & WWM_REV) {
		if (new & WWM_REV) {
			if (gen_SO)
D 27
				ps(gen_SO);
E 27
I 27
				ttxputs(gen_SO);
E 27
		} else
			if (gen_SE)
D 27
				ps(gen_SE);
E 27
I 27
				ttxputs(gen_SE);
E 27
	}
	if (diff & WWM_UL) {
		if (new & WWM_UL) {
			if (gen_US)
D 27
				ps(gen_US);
E 27
I 27
				ttxputs(gen_US);
E 27
		} else
			if (gen_UE)
D 27
				ps(gen_UE);
E 27
I 27
				ttxputs(gen_UE);
E 27
	}
I 18
	if (diff & WWM_GRP) {
		if (new & WWM_GRP) {
D 20
			if (gen_GS)
				ps(gen_GS);
E 20
I 20
			if (gen_AS)
D 27
				ps(gen_AS);
E 27
I 27
				ttxputs(gen_AS);
E 27
E 20
		} else
D 20
			if (gen_GE)
				ps(gen_GE);
E 20
I 20
			if (gen_AE)
D 27
				ps(gen_AE);
E 27
I 27
				ttxputs(gen_AE);
E 27
E 20
	}
I 30
	if (diff & WWM_USR) {
		if (new & WWM_USR) {
			if (gen_XS)
				ttxputs(gen_XS);
		} else
			if (gen_XE)
				ttxputs(gen_XE);
	}
E 30
E 18
D 16
	gen_modes = new;
E 16
I 16
	tt.tt_modes = new;
E 16
E 4
}

gen_insline()
{
I 13
D 16
	if (gen_modes)			/* for concept 100 */
		gen_setmodes1(0);
E 16
I 16
	if (tt.tt_modes)			/* for concept 100 */
		gen_setmodes(0);
E 16
E 13
D 4
	esc();
	pc(L);
	ILPAD();
E 4
I 4
	if (gen_AL)
D 8
		tputs(gen_AL, gen_LI - gen_row, gen_pc);
E 8
I 8
D 16
		tt_tputs(gen_AL, gen_LI - gen_row);
E 16
I 16
D 22
		tt_tputs(gen_AL, gen_LI - tt.tt_row);
E 22
I 22
		tttputs(gen_AL, gen_LI - tt.tt_row);
E 22
E 16
E 8
E 4
}

gen_delline()
{
I 13
D 16
	if (gen_modes)			/* for concept 100 */
		gen_setmodes1(0);
E 16
I 16
	if (tt.tt_modes)			/* for concept 100 */
		gen_setmodes(0);
E 16
E 13
D 4
	esc();
	pc(M);
	ILPAD();
E 4
I 4
	if (gen_DL)
D 8
		tputs(gen_DL, gen_LI - gen_row, gen_pc);
E 8
I 8
D 16
		tt_tputs(gen_DL, gen_LI - gen_row);
E 16
I 16
D 22
		tt_tputs(gen_DL, gen_LI - tt.tt_row);
E 22
I 22
		tttputs(gen_DL, gen_LI - tt.tt_row);
E 22
E 16
E 8
E 4
}

gen_putc(c)
register char c;
{
I 13
D 16
	gen_setinsert1(gen_ninsert);
	gen_setmodes1(gen_nmodes);
E 13
I 9
D 10
	if (gen_AM && gen_row == gen_LI - 1 && gen_col + 1 >= gen_CO)
		return;
E 10
E 9
D 4
	SETMODES(gen_nmodes);
	SETINSERT(gen_ninsert);
	if (c & 0x80) {
		SETGRAPHICS(1);
		putchar(c & 0x7f);
	} else {
		SETGRAPHICS(0);
E 4
I 4
	if (gen_insert) {
E 16
I 16
	if (tt.tt_ninsert != tt.tt_insert)
		gen_setinsert(tt.tt_ninsert);
	if (tt.tt_nmodes != tt.tt_modes)
		gen_setmodes(tt.tt_nmodes);
I 17
D 18
	if (c & 0x80) {
		if (gen_GS != 0 && !gen_graphics) {
			gen_graphics = 1;
			ps(gen_GS);
		}
	} else {
		if (gen_GE != 0 && gen_graphics) {
			gen_graphics = 0;
			ps(gen_GE);
		}
	}
E 18
E 17
	if (tt.tt_insert) {
E 16
		if (gen_IC)
D 8
			tputs(gen_IC, gen_CO - gen_col, gen_pc);
E 8
I 8
D 16
			tt_tputs(gen_IC, gen_CO - gen_col);
E 16
I 16
D 22
			tt_tputs(gen_IC, gen_CO - tt.tt_col);
E 16
E 8
E 4
D 17
		putchar(c);
E 17
I 17
D 18
		putchar(c & 0x7f);
E 18
I 18
		putchar(c);
E 22
I 22
			tttputs(gen_IC, gen_CO - tt.tt_col);
		ttputc(c);
E 22
E 18
E 17
D 4
	}
	if (gen_insert)
		ICPAD();
E 4
I 4
		if (gen_IP)
D 8
			tputs(gen_IP, gen_CO - gen_col, gen_pc);
E 8
I 8
D 16
			tt_tputs(gen_IP, gen_CO - gen_col);
E 16
I 16
D 22
			tt_tputs(gen_IP, gen_CO - tt.tt_col);
E 22
I 22
			tttputs(gen_IP, gen_CO - tt.tt_col);
E 22
E 16
E 8
	} else
D 17
		putchar(c);
E 17
I 17
D 18
		putchar(c & 0x7f);
E 18
I 18
D 22
		putchar(c);
E 22
I 22
		ttputc(c);
E 22
E 18
E 17
E 4
D 9
	gen_col++;
E 9
I 9
D 10
	if (++gen_col >= gen_CO)
		if (gen_AM) {
			gen_col = 0;
			gen_row++;
		} else
E 10
I 10
D 16
	if (++gen_col == gen_CO)
E 16
I 16
	if (++tt.tt_col == gen_CO)
E 16
D 32
		if (gen_AM)
E 32
I 32
		if (gen_XN)
			tt.tt_col = tt.tt_row = -10;
		else if (gen_AM)
E 32
D 16
			gen_col = 0, gen_row++;
E 16
I 16
			tt.tt_col = 0, tt.tt_row++;
E 16
		else
E 10
D 16
			gen_col--;
E 16
I 16
			tt.tt_col--;
E 16
E 9
}

D 16
gen_write(start, end)
register char *start, *end;
{
I 13
	gen_setinsert1(gen_ninsert);
	gen_setmodes1(gen_nmodes);
E 13
I 9
D 10
	if (gen_AM && gen_row == gen_LI - 1
	    && gen_col + (end - start + 1) >= gen_CO)
		end--;
E 10
E 9
D 4
	register char c;

	SETMODES(gen_nmodes);
	SETINSERT(gen_ninsert);
E 4
	if (gen_insert) {
		while (start <= end) {
D 4
			if ((c = *start++) & 0x80) {
				SETGRAPHICS(1);
				putchar(c & 0x7f);
			} else {
				SETGRAPHICS(0);
				putchar(c);
			}
			ICPAD();
E 4
I 4
			if (gen_IC)
D 8
				tputs(gen_IC, gen_CO - gen_col, gen_pc);
E 8
I 8
				tt_tputs(gen_IC, gen_CO - gen_col);
E 8
			putchar(*start++);
			if (gen_IP)
D 8
				tputs(gen_IP, gen_CO - gen_col, gen_pc);
E 8
I 8
				tt_tputs(gen_IP, gen_CO - gen_col);
E 8
E 4
			gen_col++;
		}
	} else {
		gen_col += end - start + 1;
		while (start <= end)
D 4
			if ((c = *start++) & 0x80) {
				SETGRAPHICS(1);
				putchar(c & 0x7f);
			} else {
				SETGRAPHICS(0);
				putchar(c);
			}
E 4
I 4
			putchar(*start++);
E 4
	}
I 9
D 10
	if (gen_col >= gen_CO)
		if (gen_AM) {
			gen_col = 0;
			gen_row++;
		} else
E 10
I 10
	if (gen_col == gen_CO)
		if (gen_AM)
			gen_col = 0, gen_row++;
		else
E 10
			gen_col--;
E 9
}

gen_blank(n)
E 16
I 16
gen_write(p, n)
D 27
register char *p;
E 16
register n;
E 27
I 27
	register char *p;
	register n;
E 27
{
I 9
D 10
	if (gen_AM && gen_row == gen_LI - 1 && gen_col + n >= gen_CO)
		n--;
E 10
E 9
D 16
	if (n <= 0)
		return;
I 13
	gen_setinsert1(gen_ninsert);
	gen_setmodes1(gen_nmodes);
E 13
D 4
	SETMODES(gen_nmodes);
	SETINSERT(gen_ninsert);
E 4
	if (gen_insert) {
E 16
I 16
	if (tt.tt_ninsert != tt.tt_insert)
		gen_setinsert(tt.tt_ninsert);
	if (tt.tt_nmodes != tt.tt_modes)
		gen_setmodes(tt.tt_nmodes);
D 27
	if (tt.tt_insert) {
E 27
I 27
D 28
	tt.tt_col += n;
E 28
	if (tt.tt_insert && (gen_IC || gen_IP)) {
E 27
E 16
		while (--n >= 0) {
I 17
D 18
			if (*p & 0x80) {
				if (gen_GS != 0 && !gen_graphics) {
					gen_graphics = 1;
					ps(gen_GS);
				}
			} else {
				if (gen_GE != 0 && gen_graphics) {
					gen_graphics = 0;
					ps(gen_GE);
				}
			}
E 18
E 17
I 4
			if (gen_IC)
D 8
				tputs(gen_IC, gen_CO - gen_col, gen_pc);
E 8
I 8
D 16
				tt_tputs(gen_IC, gen_CO - gen_col);
E 8
E 4
			putchar(' ');
E 16
I 16
D 22
				tt_tputs(gen_IC, gen_CO - tt.tt_col);
D 17
			putchar(*p++);
E 17
I 17
D 18
			putchar(*p++ & 0x7f);
E 18
I 18
			putchar(*p++);
E 22
I 22
				tttputs(gen_IC, gen_CO - tt.tt_col);
			ttputc(*p++);
E 22
E 18
E 17
E 16
D 4
			ICPAD();
E 4
I 4
			if (gen_IP)
D 8
				tputs(gen_IP, gen_CO - gen_col, gen_pc);
E 8
I 8
D 16
				tt_tputs(gen_IP, gen_CO - gen_col);
E 8
E 4
			gen_col++;
E 16
I 16
D 22
				tt_tputs(gen_IP, gen_CO - tt.tt_col);
E 22
I 22
				tttputs(gen_IP, gen_CO - tt.tt_col);
E 22
			tt.tt_col++;
E 16
		}
	} else {
D 16
		gen_col += n;
E 16
I 16
		tt.tt_col += n;
E 16
D 17
		while (--n >= 0)
D 16
			putchar(' ');
E 16
I 16
			putchar(*p++);
E 17
I 17
D 18
		while (--n >= 0) {
			if (*p & 0x80) {
				if (gen_GS != 0 && !gen_graphics) {
					gen_graphics = 1;
					ps(gen_GS);
				}
			} else {
				if (gen_GE != 0 && gen_graphics) {
					gen_graphics = 0;
					ps(gen_GE);
				}
			}
			putchar(*p++ & 0x7f);
		}
E 18
I 18
D 27
		while (--n >= 0)
D 22
			putchar(*p++);
E 22
I 22
			ttputc(*p++);
E 27
I 27
		ttwrite(p, n);
E 27
E 22
E 18
E 17
E 16
	}
I 9
D 10
	if (gen_col >= gen_CO)
		if (gen_AM) {
			gen_col = 0;
			gen_row++;
		} else
E 10
I 10
D 16
	if (gen_col == gen_CO)
E 16
I 16
	if (tt.tt_col == gen_CO)
E 16
D 32
		if (gen_AM)
E 32
I 32
		if (gen_XN)
			tt.tt_col = tt.tt_row = -10;
		else if (gen_AM)
E 32
D 16
			gen_col = 0, gen_row++;
E 16
I 16
			tt.tt_col = 0, tt.tt_row++;
E 16
		else
E 10
D 16
			gen_col--;
E 16
I 16
			tt.tt_col--;
E 16
E 9
}

gen_move(row, col)
D 34
register char row, col;
E 34
I 34
register int row, col;
E 34
{
I 4
D 16
	if (gen_row == row && gen_col == col)
E 16
I 16
	if (tt.tt_row == row && tt.tt_col == col)
E 16
		return;
D 16
	if (!gen_MI && gen_insert)
D 13
		if (gen_EI)
			ps(gen_EI);
	if (!gen_MS && gen_modes & WWM_REV)
		if (gen_SE)
			ps(gen_SE);
E 13
I 13
D 14
		gen_setinsert(0);
E 14
I 14
		gen_setinsert1(0);
E 14
	if (!gen_MS && gen_modes)
D 14
		gen_setmodes(0);
E 14
I 14
		gen_setmodes1(0);
E 14
E 13
E 4
	if (gen_row == row) {
		if (gen_col == col)
E 16
I 16
	if (!gen_MI && tt.tt_insert)
		gen_setinsert(0);
	if (!gen_MS && tt.tt_modes)
		gen_setmodes(0);
I 36
	if (row < tt.tt_scroll_top || row > tt.tt_scroll_bot)
		gen_setscroll(tt.tt_nrow - 1, 0);
E 36
	if (tt.tt_row == row) {
D 36
		if (tt.tt_col == col)
E 16
			return;
E 36
I 36
		if (col == 0) {
			ttxputs(gen_CR);
			goto out;
		}
E 36
D 16
		if (gen_col == col - 1) {
E 16
I 16
		if (tt.tt_col == col - 1) {
E 16
D 4
			esc();
			pc(C);
			goto out;
E 4
I 4
			if (gen_ND) {
D 27
				ps(gen_ND);
E 27
I 27
				ttxputs(gen_ND);
E 27
				goto out;
			}
E 4
D 16
		} else if (gen_col == col + 1) {
E 16
I 16
		} else if (tt.tt_col == col + 1) {
E 16
D 4
			pc(\b);
			goto out;
E 4
I 4
			if (gen_BC) {
D 27
				ps(gen_BC);
E 27
I 27
				ttxputs(gen_BC);
E 27
				goto out;
			}
E 4
		}
	}
D 16
	if (gen_col == col) {
		if (gen_row == row + 1) {
E 16
I 16
	if (tt.tt_col == col) {
		if (tt.tt_row == row + 1) {
E 16
D 4
			esc();
			pc(A);
			goto out;
E 4
I 4
			if (gen_UP) {
D 27
				ps(gen_UP);
E 27
I 27
				ttxputs(gen_UP);
E 27
				goto out;
			}
E 4
D 16
		} else if (gen_row == row + 1) {
E 16
I 16
		} else if (tt.tt_row == row + 1) {
E 16
D 4
			pc(\n);
			goto out;
E 4
I 4
D 27
			if (gen_NL) {
				ps(gen_NL);
				goto out;
			}
E 27
I 27
			ttxputs(gen_NL);
			goto out;
E 27
E 4
		}
	}
D 3
	if (col == 1 && row == 1) {
E 3
I 3
D 4
	if (col == 0 && row == 0) {
E 3
		esc();
		pc(H);
E 4
I 4
	if (gen_HO && col == 0 && row == 0) {
D 27
		ps(gen_HO);
E 27
I 27
		ttxputs(gen_HO);
E 27
E 4
		goto out;
	}
D 4
	esc();
	pc(Y);
	putchar(' ' + row);
	putchar(' ' + col);
E 4
I 4
D 8
	tputs(tgoto(gen_CM, col, row), 1, gen_pc);
E 8
I 8
D 27
	ps(tgoto(gen_CM, col, row));
E 27
I 27
	tttgoto(gen_CM, col, row);
E 27
E 8
E 4
out:
D 16
	gen_col = col;
	gen_row = row;
E 16
I 16
	tt.tt_col = col;
	tt.tt_row = row;
E 16
I 4
D 13
	if (!gen_MI && gen_insert)
		if (gen_IM)
			ps(gen_IM);
	if (!gen_MS && gen_modes & WWM_REV)
		if (gen_SO)
			ps(gen_SO);
E 13
E 4
}

gen_init()
{
D 4
	float cpms = (float) wwbaud / 10000;	/* char per ms */

	gen_msp10c = 10 / cpms;			/* ms per 10 char */
#ifdef notdef
	tt.tt_ILmf = cpms;			/* 1 ms */
	tt.tt_ILov = 2;
	tt.tt_ICmf = cpms * 1.5 ;		/* 1.5 ms */
	tt.tt_ICov = 2;
	tt.tt_DCmf = 0;
	tt.tt_DCov = 2;
#endif
	return 0;
E 4
D 5
}

gen_reset()
{
E 5
D 4
	esc();
	pc(x);
	pc(4);
	esc();
	pc(E);
	esc();
	pc(w);
E 4
I 4
	if (gen_VS)
D 27
		ps(gen_VS);
E 27
I 27
		ttxputs(gen_VS);
E 27
I 13
	if (gen_TI)
D 27
		ps(gen_TI);
E 13
D 5
	if (gen_HO)
		ps(gen_HO);
E 5
I 5
	if (gen_CL)
		ps(gen_CL);
E 27
I 27
		ttxputs(gen_TI);
	ttxputs(gen_CL);
E 27
E 5
E 4
D 16
	gen_col = gen_row = 0;
D 13
	gen_insert = 0;
D 4
	gen_graphics = 0;
E 4
	gen_modes = 0;
E 13
I 13
	gen_ninsert = gen_insert = 0;
	gen_nmodes = gen_modes = 0;
E 16
I 16
	tt.tt_col = tt.tt_row = 0;
	tt.tt_ninsert = tt.tt_insert = 0;
	tt.tt_nmodes = tt.tt_modes = 0;
I 17
D 18
	gen_graphics = 0;
E 18
E 17
E 16
E 13
}

D 5
gen_cleanup()
E 5
I 5
gen_end()
E 5
{
D 4
	SETMODES(0);
	SETINSERT(0);
	SETGRAPHICS(0);
	esc();
	pc(y);
	pc(4);
	esc();
	pc(v);
E 4
I 4
D 13
	gen_setmodes(0);
	gen_setinsert(0);
E 13
I 13
D 16
	gen_setmodes1(0);
	gen_setinsert1(0);
E 16
I 16
D 26
	gen_setmodes(0);
	gen_setinsert(0);
E 26
E 16
	if (gen_TE)
D 27
		ps(gen_TE);
E 27
I 27
		ttxputs(gen_TE);
E 27
E 13
	if (gen_VE)
D 27
		ps(gen_VE);
E 27
I 27
		ttxputs(gen_VE);
E 27
E 4
}

gen_clreol()
{
I 13
D 16
	if (gen_modes)			/* for concept 100 */
		gen_setmodes1(0);
E 16
I 16
	if (tt.tt_modes)			/* for concept 100 */
		gen_setmodes(0);
E 16
E 13
D 4
	esc();
	pc(K);
E 4
I 4
D 27
	if (gen_CE)
D 8
		tputs(gen_CE, gen_CO - gen_col, gen_pc);
E 8
I 8
D 16
		tt_tputs(gen_CE, gen_CO - gen_col);
E 16
I 16
D 22
		tt_tputs(gen_CE, gen_CO - tt.tt_col);
E 22
I 22
		tttputs(gen_CE, gen_CO - tt.tt_col);
E 27
I 27
	tttputs(gen_CE, gen_CO - tt.tt_col);
E 27
E 22
E 16
E 8
E 4
}

gen_clreos()
{
I 13
D 16
	if (gen_modes)			/* for concept 100 */
		gen_setmodes1(0);
E 16
I 16
	if (tt.tt_modes)			/* for concept 100 */
		gen_setmodes(0);
E 16
E 13
D 4
	esc();
	pc(J);
E 4
I 4
D 27
	if (gen_CD)
D 8
		tputs(gen_CD, gen_LI - gen_row, gen_pc);
E 8
I 8
D 16
		tt_tputs(gen_CD, gen_LI - gen_row);
E 16
I 16
D 22
		tt_tputs(gen_CD, gen_LI - tt.tt_row);
E 22
I 22
		tttputs(gen_CD, gen_LI - tt.tt_row);
E 27
I 27
	tttputs(gen_CD, gen_LI - tt.tt_row);
E 27
E 22
E 16
E 8
E 4
}

gen_clear()
{
I 13
D 16
	if (gen_modes)			/* for concept 100 */
		gen_setmodes1(0);
E 16
I 16
	if (tt.tt_modes)			/* for concept 100 */
		gen_setmodes(0);
E 16
E 13
D 4
	esc();
	pc(E);
E 4
I 4
D 27
	if (gen_CL)
		ps(gen_CL);
E 27
I 27
	ttxputs(gen_CL);
E 27
E 4
}

gen_delchar()
{
D 4
	esc();
	pc(N);
E 4
I 4
D 27
	if (gen_DC)
D 8
		tputs(gen_DC, gen_CO - gen_col, gen_pc);
E 8
I 8
D 16
		tt_tputs(gen_DC, gen_CO - gen_col);
E 16
I 16
D 22
		tt_tputs(gen_DC, gen_CO - tt.tt_col);
E 22
I 22
		tttputs(gen_DC, gen_CO - tt.tt_col);
E 27
I 27
	tttputs(gen_DC, gen_CO - tt.tt_col);
E 27
E 22
E 16
E 8
E 4
}

I 36
gen_scroll_down()
{
	gen_move(tt.tt_scroll_bot, 0);
	ttxputs(gen_SF);
}

gen_scroll_up()
{
	gen_move(tt.tt_scroll_top, 0);
	ttxputs(gen_SR);
}

gen_setscroll(top, bot)
{
	tttgoto(gen_CS, bot, top);
	tt.tt_scroll_top = top;
	tt.tt_scroll_bot = bot;
	tt.tt_row = tt.tt_col = -10;
}

E 36
I 4
D 8
char *
gen_getstr(str)
char *str;
{
	char buf[100];
	char *bufp = buf;

	str = tgetstr(str, &bufp);
	if (str == 0)
		return 0;
	str = gen_strp;
	tputs(buf, 1, gen_sc);
	gen_sc(0);
	return str;
}

E 8
E 4
tt_generic()
{
I 27
	gen_PC = tttgetstr("pc");
	PC = gen_PC ? *gen_PC->ts_str : 0;
	ospeed = wwoldtty.ww_sgttyb.sg_ospeed;

E 27
D 4
	tt.tt_setinsert = gen_setinsert;
	tt.tt_setmodes = gen_setmodes;
	tt.tt_insline = gen_insline;
	tt.tt_delline = gen_delline;
	tt.tt_delchar = gen_delchar;
	tt.tt_blank = gen_blank;
E 4
I 4
D 8
	gen_CM = tgetstr("cm", &gen_strp);
	gen_IM = gen_getstr("im");
	gen_IC = tgetstr("ic", &gen_strp);
	gen_IP = tgetstr("ip", &gen_strp);
	gen_EI = gen_getstr("ei");
	gen_DC = tgetstr("dc", &gen_strp);
	gen_AL = tgetstr("al", &gen_strp);
	gen_DL = tgetstr("dl", &gen_strp);
	gen_CE = tgetstr("ce", &gen_strp);
	gen_CD = tgetstr("cd", &gen_strp);
	gen_CL = gen_getstr("cl");
	gen_VS = gen_getstr("vs");
	gen_VE = gen_getstr("ve");
	gen_SO = gen_getstr("so");
	gen_SE = gen_getstr("se");
	gen_US = gen_getstr("us");
	gen_UE = gen_getstr("ue");
	gen_UP = gen_getstr("up");
	gen_PC = tgetstr("pc", &gen_strp);
	gen_BC = gen_getstr("bc");
	gen_ND = gen_getstr("nd");
	gen_HO = gen_getstr("ho");
	gen_NL = gen_getstr("nl");
E 8
I 8
D 22
	gen_CM = tt_xgetstr("cm");		/* may not work */
	gen_IM = tt_xgetstr("im");
	gen_IC = tt_tgetstr("ic");
	gen_IP = tt_tgetstr("ip");
	gen_EI = tt_xgetstr("ei");
	gen_DC = tt_tgetstr("dc");
	gen_AL = tt_tgetstr("al");
	gen_DL = tt_tgetstr("dl");
	gen_CE = tt_tgetstr("ce");
	gen_CD = tt_tgetstr("cd");
	gen_CL = tt_xgetstr("cl");
	gen_VS = tt_xgetstr("vs");
	gen_VE = tt_xgetstr("ve");
I 13
	gen_TI = tt_xgetstr("ti");
	gen_TE = tt_xgetstr("te");
E 13
	gen_SO = tt_xgetstr("so");
	gen_SE = tt_xgetstr("se");
	gen_US = tt_xgetstr("us");
	gen_UE = tt_xgetstr("ue");
	gen_UP = tt_xgetstr("up");
	gen_PC = tt_tgetstr("pc");
	gen_BC = tt_xgetstr("bc");
	gen_ND = tt_xgetstr("nd");
	gen_HO = tt_xgetstr("ho");
	gen_NL = tt_xgetstr("nl");
I 20
	gen_AS = tt_xgetstr("as");
	gen_AE = tt_xgetstr("ae");
E 22
I 22
	gen_CM = ttxgetstr("cm");		/* may not work */
	gen_IM = ttxgetstr("im");
	gen_IC = tttgetstr("ic");
	gen_IP = tttgetstr("ip");
	gen_EI = ttxgetstr("ei");
	gen_DC = tttgetstr("dc");
	gen_AL = tttgetstr("al");
	gen_DL = tttgetstr("dl");
	gen_CE = tttgetstr("ce");
	gen_CD = tttgetstr("cd");
	gen_CL = ttxgetstr("cl");
	gen_VS = ttxgetstr("vs");
	gen_VE = ttxgetstr("ve");
	gen_TI = ttxgetstr("ti");
	gen_TE = ttxgetstr("te");
	gen_SO = ttxgetstr("so");
	gen_SE = ttxgetstr("se");
	gen_US = ttxgetstr("us");
	gen_UE = ttxgetstr("ue");
	gen_UP = ttxgetstr("up");
D 27
	gen_PC = tttgetstr("pc");
E 27
	gen_BC = ttxgetstr("bc");
	gen_ND = ttxgetstr("nd");
	gen_HO = ttxgetstr("ho");
	gen_NL = ttxgetstr("nl");
I 36
	gen_CR = ttxgetstr("cr");
E 36
	gen_AS = ttxgetstr("as");
	gen_AE = ttxgetstr("ae");
I 30
	gen_XS = ttxgetstr("XS");
	gen_XE = ttxgetstr("XE");
I 36
	gen_SF = ttxgetstr("sf");
	gen_SR = ttxgetstr("sr");
	gen_CS = ttxgetstr("cs");
E 36
E 30
E 22
E 20
E 8
	gen_MI = tgetflag("mi");
	gen_MS = tgetflag("ms");
	gen_AM = tgetflag("am");
	gen_OS = tgetflag("os");
	gen_BS = tgetflag("bs");
I 36
	gen_DA = tgetflag("da");
E 36
I 15
	gen_DB = tgetflag("db");
I 33
	gen_NS = tgetflag("ns");
E 33
I 32
	gen_XN = tgetflag("xn");
E 32
E 15
	gen_CO = tgetnum("co");
	gen_LI = tgetnum("li");
I 12
	gen_UG = tgetnum("ug");
	gen_SG = tgetnum("sg");
I 36
	if (gen_CL == 0 || gen_OS || gen_CM == 0)
		return -1;
E 36
E 12

D 27
	if (gen_CL == 0 || gen_CM == 0 || gen_OS)
E 27
I 27
	if (gen_NL == 0) {
		static struct tt_str nl = { "\n", 1 };
		gen_NL = &nl;
	}
I 36
	if (gen_CR == 0) {
		static struct tt_str cr = { "\r", 1 };
		gen_CR = &cr;
	}
E 36
	if (gen_BC == 0 && gen_BS) {
		static struct tt_str bc = { "\b", 1 };
		gen_BC = &bc;
	}
I 36
	if (gen_SF == 0 && !gen_NS)
		gen_SF = gen_NL;
E 36
	BC = gen_BC ? gen_BC->ts_str : 0;
	UP = gen_UP ? gen_UP->ts_str : 0;
D 36
	if (gen_CL == 0 || gen_OS || gen_CM == 0)
E 27
		return -1;
E 36

D 27
	if (gen_NL == 0)
		gen_NL = "\n";
	if (gen_BC == 0 && gen_BS)
D 19
		gen_BC == "\b";
E 19
I 19
		gen_BC = "\b";
E 19

D 21
	{
		extern char PC, *BC, *UP;
		extern short ospeed;

		PC = gen_PC ? *gen_PC : 0;
		BC = gen_BC;
		UP = gen_UP;
		ospeed = wwoldtty.ww_sgttyb.sg_ospeed;
	}
E 21
I 21
	PC = gen_PC ? *gen_PC : 0;
	BC = gen_BC;
	UP = gen_UP;
	ospeed = wwoldtty.ww_sgttyb.sg_ospeed;
E 21

E 27
D 10
	if (gen_SO)
D 7
		gen_availmodes |= WWM_REV;
E 7
I 7
		tt.tt_availmodes |= WWM_REV;
E 7
	if (gen_US)
D 7
		gen_availmodes |= WWM_UL;
E 7
I 7
		tt.tt_availmodes |= WWM_UL;
E 10
E 7
D 16
	if (gen_IM)
		tt.tt_setinsert = gen_setinsert;
E 16
	if (gen_DC)
		tt.tt_delchar = gen_delchar;
	if (gen_AL)
		tt.tt_insline = gen_insline;
	if (gen_DL)
		tt.tt_delline = gen_delline;
	if (gen_CE)
		tt.tt_clreol = gen_clreol;
	if (gen_CD)
		tt.tt_clreos = gen_clreos;
I 36
	if (gen_SF)
		tt.tt_scroll_down = gen_scroll_down;
	/*
	 * Don't allow scroll_up if da or db but not cs.
	 * See comment in wwscroll.c.
	 */
	if (gen_SR && (gen_CS || !gen_DA && !gen_DB))
		tt.tt_scroll_up = gen_scroll_up;
	if (gen_CS)
		tt.tt_setscroll = gen_setscroll;
E 36
D 27
	if (gen_CL)
		tt.tt_clear = gen_clear;
E 27
I 12
	if (gen_SG > 0)
		gen_SO = 0;
D 32
	if (gen_UG > 0)
E 32
I 32
	if (gen_UG > 0 || gen_US && gen_SO && ttstrcmp(gen_US, gen_SO) == 0)
E 32
		gen_US = 0;
E 12
I 10
	if (gen_SO)
		tt.tt_availmodes |= WWM_REV;
	if (gen_US)
		tt.tt_availmodes |= WWM_UL;
I 20
	if (gen_AS)
		tt.tt_availmodes |= WWM_GRP;
I 30
	if (gen_XS)
		tt.tt_availmodes |= WWM_USR;
E 30
E 20
I 16
	tt.tt_hasinsert = gen_IM != 0;
E 16
	tt.tt_wrap = gen_AM;
I 15
	tt.tt_retain = gen_DB;
I 33
D 36
	tt.tt_noscroll = gen_NS;
E 36
E 33
E 15
E 10
	tt.tt_ncol = gen_CO;
D 9
	if (gen_AM)
		tt.tt_ncol--;
E 9
	tt.tt_nrow = gen_LI;
E 4
	tt.tt_init = gen_init;
D 4
	tt.tt_cleanup = gen_cleanup;
	tt.tt_clreol = gen_clreol;
	tt.tt_clreos = gen_clreos;
	tt.tt_clear = gen_clear;
	tt.tt_move = gen_move;
E 4
D 5
	tt.tt_reset = gen_reset;
I 4
	tt.tt_cleanup = gen_cleanup;
E 5
I 5
	tt.tt_end = gen_end;
E 5
D 16
	tt.tt_setmodes = gen_setmodes;
	tt.tt_blank = gen_blank;
E 16
E 4
	tt.tt_write = gen_write;
	tt.tt_putc = gen_putc;
D 4
	tt.tt_ncol = 80;
	tt.tt_nrow = 24;
E 4
I 4
	tt.tt_move = gen_move;
I 27
	tt.tt_clear = gen_clear;
E 27
I 26
	tt.tt_setinsert = gen_setinsert;
	tt.tt_setmodes = gen_setmodes;
E 26
E 4
D 25
	tt.tt_frame = gen_frame;
E 25
I 25
D 27
	if (gen_AS && strcmp(gen_AS, ANSI_AS) == 0)
		tt.tt_frame = ansi_frame;
	else
		tt.tt_frame = gen_frame;
E 27
I 27
D 32
	tt.tt_frame = gen_AS && !strncmp(gen_AS->ts_str, ANSI_AS, gen_AS->ts_n)
		? ansi_frame : gen_frame;
E 32
I 32
	tt.tt_frame = gen_AS && ttstrcmp(gen_AS, &ansi_AS) == 0 ?
		ansi_frame : gen_frame;
E 32
E 27
E 25
	return 0;
}
E 1
