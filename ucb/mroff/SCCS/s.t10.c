h31052
s 00001/00000/00423
d D 5.17 2012/07/22 14:27:14 msokolov 17 16
c setstrokeadjust line added
e
s 00097/00160/00326
d D 5.16 2012/07/22 09:08:41 msokolov 16 15
c new resolve_char() function is like old troff's getcw()
c hoping that this reduction in the number of function calls per character
c will speed things up
e
s 00063/00040/00423
d D 5.15 2012/07/21 07:16:57 msokolov 15 14
c bd'ing implemented
e
s 00000/00001/00463
d D 5.14 2012/07/18 06:09:32 msokolov 14 13
c don't need the %%LanguageLevel: 1 line
e
s 00024/00001/00440
d D 5.13 2012/07/15 22:45:50 msokolov 13 12
c suppress "0-width" chars not listed in mkfont input
e
s 00011/00010/00430
d D 5.12 2012/07/15 03:18:29 msokolov 12 11
c troff: named char handling converted to LUT, Cyrillic support added
e
s 00007/00017/00433
d D 5.11 2012/03/06 04:12:38 msokolov 11 10
c converted to ftXX files and font search paths
e
s 00016/00027/00434
d D 5.10 2012/03/05 00:07:45 msokolov 10 9
c first restructuring steps for fcXX and .bd simulation
e
s 00011/00010/00450
d D 5.9 10/10/07 01:29:43 msokolov 9 8
c the SuperSpecial font is here
e
s 00013/00004/00447
d D 5.8 10/09/22 03:33:41 msokolov 8 7
c \(ci reimplemented via the procset
e
s 00003/00001/00448
d D 5.7 10/09/04 04:50:36 msokolov 7 6
c do vertical local motion compensation like troff has done all along
c it turns out that pic depends on it
e
s 00051/00001/00398
d D 5.6 10/08/29 03:35:19 msokolov 6 5
c drawing operations added to pstroff
e
s 00001/00001/00398
d D 5.5 05/09/17 04:57:59 msokolov 5 4
c allow 2nd char of font name to be a digit
e
s 00084/00012/00315
d D 5.4 04/10/30 03:42:17 msokolov 4 3
c some improvements
c using a real procset
c line drawing chars done via the procset, no more raping of Symbol
e
s 00002/00002/00325
d D 5.3 04/10/24 20:25:59 msokolov 3 2
c use done3() for initialization errors
e
s 00001/00001/00326
d D 5.2 04/09/08 16:51:50 msokolov 2 1
c TroffEncoding.ps moved from /usr/lib/psutils to /usr/lib/pstroff
e
s 00327/00000/00000
d D 5.1 04/09/08 16:42:02 msokolov 1 0
c first working version
e
u
U
t
T
I 1
#ifndef lint
D 10
static char sccsid[] = "%W% (Berkeley) %G%";
E 10
I 10
static char sccsid[] = "%W% (Berkeley) %E%";
E 10
#endif

#include "tdef.h"
D 11
#include <ctype.h>
E 11
extern
#include "d.h"
extern
#include "v.h"
I 11
#include "fontinfo.h"

E 11
/*
troff10.c

PostScript output
*/

extern int *olinep;
extern int oline[];
extern int xpts;
extern int po;
extern int xflg;
extern int line[];
extern int lss;
extern char obuf[];
extern char *obufp;
extern int cs;
extern int smnt;
extern int xfont;
extern int xsfont;
extern int ascii;
I 16
extern int no_out;
E 16
extern int pfont;
extern int ppts;
extern int oldbits;
extern int xxx;
extern int tflg;
extern int nform;
extern int fmt[];
extern int pl;
extern int ccs;
extern int cstab[], ccstab[];

extern int psout_omit_troffencoding;
extern int psout_8bit_strings;
extern int psout_hex_strings;
D 10
extern char *fontdir, *fontlist;
E 10
I 10
D 11
extern char *fontdir;
extern int fontlab[32];
E 11
E 10
extern int nfonts;
I 11
extern struct fontinfo_hdr *fontab[32];
I 12
D 15
u_long encoding_vectors;
E 15
I 15
extern u_long encoding_vectors;
extern int bd, bdmult;
E 15
E 12
E 11
int ps_page_printing, ps_page_cnt;
D 15
int ourx, oury, psx, psy, instring;
I 4
D 6
int inlinedraw, ldx, ldy, ldps, ldch, ldcnt;
E 6
I 6
int indrawop, strokewidth;
E 15
I 15
int ourx, oury, psx, psy, instring, string_bd;
int indrawop, strokewidth, set_bd;
E 15
E 6
E 4

ptinit()
{
D 11
	register int i, c;
D 10
	register char *cp, *cp1, *cp2;
E 10
I 10
	register char *cp1, *cp2;
E 10
	char filename[128];
E 11
I 11
	register int i;
	register struct fontinfo_hdr *hdr;
E 11

	fontinit();
I 6
	init_curve_conversion();
E 6
D 16
	if (ascii)
E 16
I 16
	if (ascii || no_out)
E 16
		return;
	if (psout_8bit_strings && psout_hex_strings) {
		prstr("-e and -h options are mutually exclusive\n");
D 3
		exit(-1);
E 3
I 3
		done3(-1);
E 3
	}
	oputs("%!PS-Adobe-3.0\n");
	oputs("%%Creator: 4.3BSD-Quasijarus PostScript troff\n");
	if (!psout_8bit_strings)
		oputs("%%DocumentData: Clean7Bit\n");
	else
		oputs("%%DocumentData: Clean8Bit\n");
D 14
	oputs("%%LanguageLevel: 1\n");
E 14
I 4
D 12
	if (!psout_omit_troffencoding)
		oputs("%%DocumentSuppliedResources: encoding TroffEncoding\n");
E 12
E 4
	oputs("%%Pages: (atend)\n");
	oputs("%%EndComments\n");
D 4
	if (!psout_omit_troffencoding) {
		oputs("%%BeginProlog\n");
E 4
I 4
	oputs("%%BeginProlog\n");
	PS_emit_hdrfile("/usr/lib/pstroff/TroffProcset.ps");
I 15
	if (bdmult)
		PS_emit_hdrfile("/usr/lib/pstroff/bdprocset.ps");
E 15
D 12
	if (!psout_omit_troffencoding)
E 12
I 12
	if (encoding_vectors & FONTINFO_FLAGS_ROMAN &&
	    !psout_omit_troffencoding)
E 12
E 4
D 2
		PS_emit_hdrfile("/usr/lib/psutils/TroffEncoding.ps");
E 2
I 2
		PS_emit_hdrfile("/usr/lib/pstroff/TroffEncoding.ps");
I 12
	if (encoding_vectors & FONTINFO_FLAGS_CYRILLIC &&
	    !psout_omit_troffencoding)
		PS_emit_hdrfile("/usr/lib/pstroff/CyrTroffEncoding.ps");
E 12
E 2
D 4
		oputs("%%EndProlog\n");
	}
E 4
I 4
	oputs("%%EndProlog\n");
E 4
	oputs("%%BeginSetup\n");
I 17
	oputs("/setstrokeadjust where {pop true setstrokeadjust} if\n");
E 17
	oputs("/fontset [\n");
D 10
	for (i = 0, cp = fontlist; i < nfonts; i++) {
		for (cp1 = fontdir, cp2 = filename, c = '/'; *cp1; )
			*cp2++ = c = *cp1++;
		if (c != '/')
			*cp2++ = '/';
		*cp2++ = 'f';
		*cp2++ = 's';
		*cp2++ = *cp++;
D 5
		if (isalpha(*cp))
E 5
I 5
		if (isalnum(*cp))
E 5
			*cp2++ = *cp++;
		if (*cp == ',')
			cp++;
		*cp2 = '\0';
E 10
I 10
D 11
	for (cp1 = fontdir, cp2 = filename, c = '/'; *cp1; )
		*cp2++ = c = *cp1++;
	if (c != '/')
		*cp2++ = '/';
	*cp2++ = 'f';
	*cp2++ = 's';
	cp2[2] = '\0';
E 11
	for (i = 0; i < nfonts; i++) {
D 11
		c = fontlab[i];
		cp2[0] = c;
		cp2[1] = c >> BYTE;
E 10
		PS_emit_hdrfile(filename);
E 11
I 11
		hdr = fontab[i];
		oputs((char *) hdr + hdr->setup_offset);
E 11
	}
	oputs("] def\n");
D 4
	oputs("/SF {exch fontset exch get exch 60 mul scalefont setfont} bind def\n");
	oputs("/P {3 1 roll moveto show} bind def\n");
E 4
	oputs("%%EndSetup\n");
}

PS_emit_hdrfile(filename)
	char *filename;
{
	register int fd, i, n;
	char buf[OBUFSZ];

	fd = open(filename, 0);
	if (fd < 0) {
		prstr("can't open file ");
		prstr(filename);
		prstr("\n");
D 3
		done(02);
E 3
I 3
		done3(02);
E 3
	}
	while ((n = read(fd, buf, OBUFSZ)) > 0)
		for (i = 0; i < n; i++)
			oput(buf[i]);
	close(fd);
}

PS_open_page()
{
	extern oput();

	if (ps_page_printing)
		return;
	oputs("%%Page: ");
	nform = fmt[findr('%')];
	fnumb(v.pn, oput);
	oput(' ');
	nform = 0;
	fnumb(++ps_page_cnt, oput);
	oput('\n');
	ps_page_printing = 1;
D 4
	oputs("save 1 60 div dup scale\n");
E 4
I 4
	oputs("save $troff begin Sc\n");
E 4
	oury = pl;
	pfont = ppts = -1;
I 6
	strokewidth = -1;
I 15
	set_bd = -1;
E 15
E 6
}

PS_close_page()
{
	if (!ps_page_printing)
		return;
D 4
	oputs("restore showpage\n");
E 4
I 4
	oputs("end restore showpage\n");
E 4
	ps_page_printing = 0;
	pfont = ppts = -1;
I 6
	strokewidth = -1;
I 15
	set_bd = -1;
E 15
E 6
}

PS_emit_trailer()
{
	extern int oput();

	oputs("%%Trailer\n");
	oputs("%%Pages: ");
	nform = 0;
	fnumb(ps_page_cnt, oput);
	oput('\n');
	oputs("%%EOF\n");
}

ptout(i)
	register int i;
{
D 12
	register int *k, j, x;
E 12
I 12
D 16
	register int *k, j, x, p;
E 16
I 16
	register int *k, j, x;
E 16
E 12
	extern int oput();
I 7
	int savedy;
I 9
D 10
	int nchar;
E 10
E 9
E 7

	if (tflg) {
		oput(i);
		return;
	}
	if((i & CMASK) != '\n'){
		*olinep++ = i;
		return;
	}
	PS_open_page();
	if(olinep == oline){
		oury -= lss;
		return;
	}
	oury -= dip->blss + lss;
	dip->blss = 0;
	ourx = po;
I 7
	savedy = oury;
I 16
	nform = 0;
E 16
E 7
D 4
	for (k=oline; k<olinep; k++) {
		i = *k;
E 4
I 4
	for (k=oline; k<olinep; ) {
		i = *k++;
E 4
		if (i & MOT) {
			domotion(i);
			continue;
		}
I 15
		/* handle xinfo chars first */
D 16
		switch (i & CMASK) {
E 16
I 16
		switch (j = i & CMASK) {
E 16
		case DRAWOP:
			if (instring)
				PS_string_end();
D 16
			nform = 0;
E 16
			fnumb(ourx, oput);
			oput(' ');
			fnumb(oury, oput);
			oputs(" moveto\n");
			indrawop = 1;
			continue;
		case LINETO:
			oputs("lineto\n");
			continue;
		case CURVETO:
			oputs("curveto\n");
			continue;
		case DRAWFIN:
			PS_finish_drawop(i);
			indrawop = 0;
			continue;
I 16
		/* continuous line drawing too */
		case BASRULE:
		case UNDRULE:
		case OVRRULE:
			if(i & ZBIT)
				break;
			if((i>>16) != oldbits){
				xfont = (i>>16) & 0x1F;
				xpts = (i>>21) & 0xFF;
				oldbits = i >> 16;
			}
			if (cstab[xfont])
				break;
			x = 1;
			while (k < olinep && *k == i)
				x++, k++;
			PS_linedraw(j, x);
			x *= xpts * 30;
			goto incx;
E 16
		}
E 15
		if((i>>16) != oldbits){
			xfont = (i>>16) & 0x1F;
			xpts = (i>>21) & 0xFF;
			oldbits = i >> 16;
		}
D 16
		if(cs = cstab[xfont]){
			if(ccs = ccstab[xfont])x = ccs; else x = xpts;
D 15
			cs = (j = (cs&077)*(x&0377)*10)/6;
			if((j%6) >= 3)cs++;
E 15
I 15
			cs = (cs * x * 10 + 3) / 6;
E 15
		}
		j = spacewidth(i & CMASK);
		if (j) {
			if (i & ZBIT)	/* a non-spacing space is an oxymoron */
				continue;
I 15
			if (cs)
				j = cs;
E 15
			domotion(MOT | j);
			continue;
		}
D 4
		if ((i & CMASK) == CFMINUS)
E 4
I 4
		switch (i & CMASK) {
		case CFMINUS:
E 4
			i = i & ~CMASK | '-';
I 4
			break;
		case BASRULE:
		case UNDRULE:
		case OVRRULE:
			if (instring)
				PS_string_end();
			j = 1;
			if (!cs && !(i & ZBIT))
				while (k < olinep && *k == i)
					j++, k++;
			PS_linedraw(i & CMASK, j);
			if (!cs)
				x = xpts * j * 30;
			else
				x = cs;
			goto incx;
		case BOXRULE:
			if (instring)
				PS_string_end();
D 8
			PS_boxrule();
E 8
I 8
			PS_special_char('b', 'r');
E 8
			if (!cs)
				continue;
			x = cs;
			goto incx;
I 8
D 9
		case CIRCLE:
			if (instring)
				PS_string_end();
			PS_special_char('c', 'i');
			if (!cs)
				x = xpts * 45;
			else
				x = cs;
			goto incx;
E 9
I 9
D 10
		case SPECIAL_BS:
		case SPECIAL_CI:
		case SPECIAL_LH:
		case SPECIAL_RH:
			if (handle_SS_char(i & CMASK, &xsfont, &nchar)) {
				i = (i & ~CMASK) | nchar;
				goto print;
			} else
				continue;
E 10
E 9
E 8
I 6
D 15
		case DRAWOP:
			if (instring)
				PS_string_end();
			nform = 0;
			fnumb(ourx, oput);
			oput(' ');
			fnumb(oury, oput);
			oputs(" moveto\n");
			indrawop = 1;
			continue;
		case LINETO:
			oputs("lineto\n");
			continue;
		case CURVETO:
			oputs("curveto\n");
			continue;
		case DRAWFIN:
			PS_finish_drawop(i);
			indrawop = 0;
			continue;
E 15
E 6
		}
E 4
D 12
		xsfont = xfont;
		if (i & 0x100 && smnt)
			xsfont = smnt - 1;
E 12
I 12
		p = handle_9bit_char(i & CMASK);
I 13
		j = getcw(p, xsfont, xpts);
		if (!j) {
			/*
			 * Current policy, subject to change if
			 * necessary: a zero in the width table
			 * means that the character hasn't been
			 * defined in the input to mkfont.  We
			 * don't know what would happen if we tried
			 * to print it: we might get the .notdef char,
			 * (whose width isn't 0 in the standard fonts),
			 * or the font in actual use may have some new
			 * char added in there which wasn't known to
			 * our mkfont source.  Either way, the result
			 * would be disagreement between our notion of the
			 * x coordinate and that of the PS interpreter.
			 *
			 * Our current solution: suppress the printing
			 * of this char.  It has the nice side effect
			 * of giving more authority to the data fed to
			 * mkfont.
			 */
			x = cs;
			goto incx;
		}
E 13
E 12
D 9
		if (xsfont != pfont || xpts != ppts) {
E 9
I 9
D 10
print:		if (xsfont != pfont || xpts != ppts) {
E 10
I 10
		if (xsfont != pfont || xpts != ppts) {
E 10
E 9
			if (instring)
				PS_string_end();
			nform = 0;
			fnumb(xsfont, oput);
			oput(' ');
			fnumb(xpts, oput);
			oput(' ');
			oput('S');
			oput('F');
			oput('\n');
			pfont = xsfont;
			ppts = xpts;
		}
I 15
		getbd(i & CMASK);
		if (bd) {
			j += bd;
			if (bd != set_bd) {
				if (instring)
					PS_string_end();
				nform = 0;
				fnumb(bd, oput);
				oput(' ');
				oput('b');
				oput('d');
				oput('\n');
				set_bd = bd;
			}
		}
E 15
D 12
		j = getcw(i & BMASK, pfont, ppts);
E 12
I 12
D 13
		j = getcw(p, pfont, ppts);
E 13
E 12
		if (!cs) {
D 15
			if (instring && (ourx != psx || oury != psy))
E 15
I 15
			if (instring &&
			    (ourx != psx || oury != psy || bd != string_bd))
E 15
				PS_string_end();
			if (!instring)
D 15
				PS_string_start();
E 15
I 15
				PS_string_start(ourx, oury);
E 15
D 12
			PS_string_char(i & BMASK);
E 12
I 12
			PS_string_char(p);
E 12
			psx += j;
			x = j;
		} else {
			if (instring)
				PS_string_end();
D 15
			nform = 0;
			fnumb(ourx + (cs - j) / 2, oput);
			oput(' ');
			fnumb(oury, oput);
			oput(' ');
			oput(psout_hex_strings ? '<' : '(');
E 15
I 15
			PS_string_start(ourx + (cs - j) / 2, oury);
E 15
D 12
			PS_string_char(i & BMASK);
E 12
I 12
			PS_string_char(p);
E 12
			PS_string_end();
			x = cs;
		}
E 16
I 16
		x = resolve_char(j, 1);
E 16
D 4
		if (!(i & ZBIT))
E 4
I 4
incx:		if (!(i & ZBIT))
E 4
			ourx += x;
	}
	if (instring)
		PS_string_end();
	olinep = oline;
D 7
	oury -= dip->alss;
E 7
I 7
	oury = savedy - dip->alss;
E 7
	dip->alss = 0;
}

I 16
print_regular_char(c, x)
	register int c;
	int x;
{
	extern int oput();
	register int xc;
	static char octstr[] = "\\ooo";
	static char hexdigits[] = "0123456789ABCDEF";

	if (xsfont != pfont || xpts != ppts) {
		if (instring)
			PS_string_end();
		fnumb(xsfont, oput);
		oput(' ');
		fnumb(xpts, oput);
		oput(' ');
		oput('S');
		oput('F');
		oput('\n');
		pfont = xsfont;
		ppts = xpts;
	}
	if (bd && bd != set_bd) {
		if (instring)
			PS_string_end();
		fnumb(bd, oput);
		oput(' ');
		oput('b');
		oput('d');
		oput('\n');
		set_bd = bd;
	}
	if (cs)
		xc = ourx + (cs - x) / 2;
	else
		xc = ourx;
	if (instring && (xc != psx || oury != psy || bd != string_bd))
		PS_string_end();
	if (!instring) {
		fnumb(xc, oput);
		oput(' ');
		fnumb(oury, oput);
		oput(psout_hex_strings ? '<' : '(');
		instring = 1;
		psx = xc;
		psy = oury;
		string_bd = bd;
	}
	if (psout_hex_strings) {
		oput(hexdigits[c>>4]);
		oput(hexdigits[c&0xF]);
	} else {
		if (c<0x20 || c>=0x7F && (!psout_8bit_strings || c<=0x9F)) {
			octstr[3] = (c & 7) + '0';
			c >>= 3;
			octstr[2] = (c & 7) + '0';
			c >>= 3;
			octstr[1] = c + '0';
			oputs(octstr);
		} else {
			if (c == '\\' || c == '(' || c == ')')
				oput('\\');
			oput(c);
		}
	}
	psx += x;
}

E 16
domotion(i)
	int i;
{
	register int dir, amt;
I 6
	extern int oput();
E 6

	dir = (i >> 29) & 3;
	amt = i & ~MOTV;
	switch (dir) {
	case 0:
		ourx += amt;
		break;
	case 1:
		ourx -= amt;
		break;
	case 2:
		oury -= amt;
		break;
	case 3:
		oury += amt;
		break;
	}
I 6
	if (indrawop) {
D 16
		nform = 0;
E 16
		fnumb(i & VMOT ? oury : ourx, oput);
		oput(' ');
	}
E 6
}

D 15
PS_string_start()
E 15
I 15
D 16
PS_string_start(x, y)
E 15
{
	extern int oput();

	nform = 0;
D 15
	fnumb(ourx, oput);
E 15
I 15
	fnumb(x, oput);
E 15
	oput(' ');
D 15
	fnumb(oury, oput);
	oput(' ');
E 15
I 15
	fnumb(y, oput);
E 15
	oput(psout_hex_strings ? '<' : '(');
	instring = 1;
D 15
	psx = ourx;
	psy = oury;
E 15
I 15
	psx = x;
	psy = y;
	string_bd = bd;
E 15
}

PS_string_char(c)
	register int c;
{
	static char octstr[] = "\\ooo";
	static char hexdigits[] = "0123456789ABCDEF";

	if (psout_hex_strings) {
		oput(hexdigits[c>>4]);
		oput(hexdigits[c&0xF]);
	} else {
		if (c<0x20 || c>=0x7F && (!psout_8bit_strings || c<=0x9F)) {
			octstr[3] = (c & 7) + '0';
			c >>= 3;
			octstr[2] = (c & 7) + '0';
			c >>= 3;
			octstr[1] = c + '0';
			oputs(octstr);
		} else {
			if (c == '\\' || c == '(' || c == ')')
				oput('\\');
			oput(c);
		}
	}
}

E 16
PS_string_end()
{
	oput(psout_hex_strings ? '>' : ')');
D 15
	oput(' ');
E 15
	oput('P');
I 15
	if (string_bd) {
		oput('b');
		oput('d');
	}
E 15
	oput('\n');
	instring = 0;
I 4
}

PS_linedraw(ch, cnt)
{
	extern int oput();

D 16
	nform = 0;
E 16
I 16
	if (instring)
		PS_string_end();
E 16
	fnumb(ourx, oput);
	oput(' ');
	fnumb(oury, oput);
	oput(' ');
	fnumb(xpts, oput);
	oput(' ');
	switch (ch) {
	case BASRULE:
		oputs("0");
		break;
	case UNDRULE:
		oputs("-100");
		break;
	case OVRRULE:
		oputs("900");
		break;
	}
	oput(' ');
	fnumb(cnt, oput);
	oput(' ');
	oput('L');
	oput('\n');
}

D 8
PS_boxrule()
E 8
I 8
PS_special_char(c1, c2)
E 8
{
	extern int oput();

D 16
	nform = 0;
E 16
I 16
	if (instring)
		PS_string_end();
E 16
	fnumb(ourx, oput);
	oput(' ');
	fnumb(oury, oput);
	oput(' ');
	fnumb(xpts, oput);
	oput(' ');
D 8
	oput('b');
	oput('r');
E 8
I 8
	oput(c1);
	oput(c2);
E 8
	oput('\n');
I 6
}

PS_finish_drawop(code)
{
	register int i;
	extern int oput();

	if (code & 0x200)
		oputs("closepath ");
	if (code & 0x400)
		oputs("fill\n");
	else {
		i = code >> 11;
		if (i != strokewidth) {
D 16
			nform = 0;
E 16
			fnumb(i, oput);
			oputs(" setlinewidth ");
			strokewidth = i;
		}
		oputs("stroke\n");
	}
E 6
E 4
}

dostop(){}
E 1
