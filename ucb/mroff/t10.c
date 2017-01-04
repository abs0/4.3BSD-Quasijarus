#ifndef lint
static char sccsid[] = "@(#)t10.c	5.17 (Berkeley) 2012/07/22";
#endif

#include "tdef.h"
extern
#include "d.h"
extern
#include "v.h"
#include "fontinfo.h"

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
extern int no_out;
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
extern int nfonts;
extern struct fontinfo_hdr *fontab[32];
extern u_long encoding_vectors;
extern int bd, bdmult;
int ps_page_printing, ps_page_cnt;
int ourx, oury, psx, psy, instring, string_bd;
int indrawop, strokewidth, set_bd;

ptinit()
{
	register int i;
	register struct fontinfo_hdr *hdr;

	fontinit();
	init_curve_conversion();
	if (ascii || no_out)
		return;
	if (psout_8bit_strings && psout_hex_strings) {
		prstr("-e and -h options are mutually exclusive\n");
		done3(-1);
	}
	oputs("%!PS-Adobe-3.0\n");
	oputs("%%Creator: 4.3BSD-Quasijarus PostScript troff\n");
	if (!psout_8bit_strings)
		oputs("%%DocumentData: Clean7Bit\n");
	else
		oputs("%%DocumentData: Clean8Bit\n");
	oputs("%%Pages: (atend)\n");
	oputs("%%EndComments\n");
	oputs("%%BeginProlog\n");
	PS_emit_hdrfile("/usr/lib/pstroff/TroffProcset.ps");
	if (bdmult)
		PS_emit_hdrfile("/usr/lib/pstroff/bdprocset.ps");
	if (encoding_vectors & FONTINFO_FLAGS_ROMAN &&
	    !psout_omit_troffencoding)
		PS_emit_hdrfile("/usr/lib/pstroff/TroffEncoding.ps");
	if (encoding_vectors & FONTINFO_FLAGS_CYRILLIC &&
	    !psout_omit_troffencoding)
		PS_emit_hdrfile("/usr/lib/pstroff/CyrTroffEncoding.ps");
	oputs("%%EndProlog\n");
	oputs("%%BeginSetup\n");
	oputs("/setstrokeadjust where {pop true setstrokeadjust} if\n");
	oputs("/fontset [\n");
	for (i = 0; i < nfonts; i++) {
		hdr = fontab[i];
		oputs((char *) hdr + hdr->setup_offset);
	}
	oputs("] def\n");
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
		done3(02);
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
	oputs("save $troff begin Sc\n");
	oury = pl;
	pfont = ppts = -1;
	strokewidth = -1;
	set_bd = -1;
}

PS_close_page()
{
	if (!ps_page_printing)
		return;
	oputs("end restore showpage\n");
	ps_page_printing = 0;
	pfont = ppts = -1;
	strokewidth = -1;
	set_bd = -1;
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
	register int *k, j, x;
	extern int oput();
	int savedy;

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
	savedy = oury;
	nform = 0;
	for (k=oline; k<olinep; ) {
		i = *k++;
		if (i & MOT) {
			domotion(i);
			continue;
		}
		/* handle xinfo chars first */
		switch (j = i & CMASK) {
		case DRAWOP:
			if (instring)
				PS_string_end();
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
		}
		if((i>>16) != oldbits){
			xfont = (i>>16) & 0x1F;
			xpts = (i>>21) & 0xFF;
			oldbits = i >> 16;
		}
		x = resolve_char(j, 1);
incx:		if (!(i & ZBIT))
			ourx += x;
	}
	if (instring)
		PS_string_end();
	olinep = oline;
	oury = savedy - dip->alss;
	dip->alss = 0;
}

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

domotion(i)
	int i;
{
	register int dir, amt;
	extern int oput();

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
	if (indrawop) {
		fnumb(i & VMOT ? oury : ourx, oput);
		oput(' ');
	}
}

PS_string_end()
{
	oput(psout_hex_strings ? '>' : ')');
	oput('P');
	if (string_bd) {
		oput('b');
		oput('d');
	}
	oput('\n');
	instring = 0;
}

PS_linedraw(ch, cnt)
{
	extern int oput();

	if (instring)
		PS_string_end();
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

PS_special_char(c1, c2)
{
	extern int oput();

	if (instring)
		PS_string_end();
	fnumb(ourx, oput);
	oput(' ');
	fnumb(oury, oput);
	oput(' ');
	fnumb(xpts, oput);
	oput(' ');
	oput(c1);
	oput(c2);
	oput('\n');
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
			fnumb(i, oput);
			oputs(" setlinewidth ");
			strokewidth = i;
		}
		oputs("stroke\n");
	}
}

dostop(){}
