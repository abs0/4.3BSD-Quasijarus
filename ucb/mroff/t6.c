#ifndef lint
static char sccsid[] = "@(#)t6.c	5.38 (Berkeley) 2012/07/22";
#endif lint

#include "tdef.h"
#include <sys/stat.h>
#include <ctype.h>
#include <strings.h>
extern
#include "d.h"
extern
#include "v.h"
#include "fontinfo.h"

/*
troff6.c

width functions, sizes and fonts
*/

extern	int	inchar[LNSIZE], *pinchar;	/* XXX */
extern int eschar;
extern int widthp;
extern int ohc;
extern int xpts;
extern int xfont;
extern int xsfont;
extern int code;
extern int smnt;
extern int setwdf;
extern int cs;
extern int ccs;
extern int spacesz, spacesz_cw_ovr;
extern u_short trtab[];
extern int xbitf;
extern int mfont;
extern int mpts;
extern int pfont;
extern int ppts;
extern int oldbits;
extern int chbits;
extern int nonumb;
extern int noscale;
extern int font;
extern int font1;
extern int pts;
extern int pts1;
extern int apts;
extern int apts1;
extern int sps;
extern int nlflg;
extern int nform;
extern int dfact;
extern int lss;
extern int lss1;
extern int vflag;
extern int ch0;
extern int lg;
char *fontlist = "R,I,B,S";
char stdfontdir[] = "/usr/lib/pstroff";
char *fontpath;
char *font_search_path[10] = {stdfontdir, 0};
char *bdsimlist;
extern int level;
extern int ch;
extern int res;
extern int ptid;
extern int xxx;
extern int ulfont;
extern int ulbit;
extern char cttab[];
extern int bd;
int nfonts;
struct fontinfo_hdr *fontab[32];
u_short *widthtab[32];
int fontlab[32];
int bdsim[32];
int bdmult, allow_bd_s = 1, bd_s_warn;
int cstab[32], ccstab[32];
int bdtab[32], bdstab[32];
int spsz = 0;
struct fz {
	char sign;
	char size;
	int inc;
	} fz[32];
struct chardef_section *lchars[32];
extern u_short chlut[94*94];
u_char uchar_font[32], uchar_char[32], nuchars;
int uchar_revmap[32];
u_long encoding_vectors;
u_char cyr_remap[32] = {
	0xA0,	0,	0,	0,	0xBD,	0,	0x87,	0x83,
	0x98,	0x85,	0,	0x8A,	0,	0xAD,	0x86,	0x95,
	0x1C,	0,	0,	0,	0x92,	0,	0x84,	0,
	0,	0,	0,	0x8B,	0,	0,	0,	0,
};

fontinit()
{
	register int i;

	parse_font_list();
	if (bdsimlist)
		parse_bdsim_list();
	if (fontpath)
		parse_font_path();
	smnt = 0;
	for (i = 0; i < nfonts; i++)
		read_font(i);
	if (nfonts == 1)
		ulfont = ulbit = 0;
	if (!smnt)
		nosymbol_remap();
}

parse_font_list()
{
	register int i, c;
	register char *cp;

	for (cp = fontlist, i = 0; *cp; i++) {
		if (!isalpha(*cp)) {
bad:			prstr("Invalid font specification\n");
			done3(-1);
		}
		c = *cp++;
		if (isalnum(*cp))
			c |= *cp++ << BYTE;
		if (*cp) {
			if (*cp == ',')
				cp++;
			else
				goto bad;
		}
		fontlab[i] = c;
	}
	if (!i)
		goto bad;
	nfonts = i;
}

parse_bdsim_list()
{
	register int c, n, i;
	register char *cp;

	for (cp = bdsimlist; *cp; ) {
		if (*cp == '*') {
			if (!isdigit(*++cp)) {
bad:				prstr("Invalid -b specification\n");
				done3(-1);
			}
			for (n = 0; isdigit(*cp); )
				n = n * 10 + (*cp++ - '0');
			bdmult = n;
			goto next;
		}
		if (*cp == '!') {
			cp++;
			bd_s_warn = 1;
			goto next;
		}
		if (!isalpha(*cp))
			goto bad;
		c = *cp++;
		if (isalnum(*cp))
			c |= *cp++ << BYTE;
		if (c == 'S') {
			switch (*cp++) {
			case '+':
				allow_bd_s = 1;
				break;
			case '-':
				allow_bd_s = 0;
				break;
			case '!':
				bd_s_warn = 1;
				break;
			default:
				goto bad;
			}
			goto next;
		}
		c = find(c, fontlab);
		if (c < 0)
			goto bad;
		if (*cp++ != '=')
			goto bad;
		if (!isalpha(*cp))
			goto bad;
		n = *cp++;
		if (isalnum(*cp))
			n |= *cp++ << BYTE;
		i = find(n, fontlab);
		if (i < 0) {
			i = nfonts++;
			fontlab[i] = n;
		}
		bdsim[c] = i + 1;
next:		if (*cp) {
			if (*cp == ',')
				cp++;
			else
				goto bad;
		}
	}
}

parse_font_path()
{
	register char *cp, **pp;

	for (cp = fontpath, pp = font_search_path; cp && *cp; ) {
		if (*cp == ':')
			goto out;
		*pp++ = cp;
		cp = index(cp, ':');
		if (cp)
			*cp++ = '\0';
	}
	*pp++ = stdfontdir;
out:	*pp = 0;
}

read_font(idx)
{
	static char ftname[] = "ftXX";
	register int c;
	register char **pp;

	c = fontlab[idx];
	ftname[2] = c;
	ftname[3] = c >> BYTE;
	for (pp = font_search_path; *pp; pp++)
		if (try_font_path(*pp, ftname, idx))
			return;
	prstr("Cannot find ");
	prstr(ftname);
	prstr("\n");
	done3(-1);
}

try_font_path(dir, ftname, fontidx)
	char *dir, *ftname;
{
	register int i, c;
	register char *cp1, *cp2;
	char filename[128];
	int fd;

	for (cp1 = dir, cp2 = filename; *cp1; )
		*cp2++ = c = *cp1++;
	if (c != '/')
		*cp2++ = '/';
	strcpy(cp2, ftname);
	fd = open(filename, 0);
	if (fd < 0)
		return(0);
	if (handle_ft_file(fontidx, fd) < 0) {
		prstr(filename);
		prstr(" is invalid\n");
		done3(-1);
	}
	close(fd);
	return(1);
}

handle_ft_file(fontidx, fd)
	register int fontidx;
	int fd;
{
	struct stat st;
	extern char *setbrk();
	char *buf;
	register struct fontinfo_hdr *hdr;
	register struct chardef_section *chdef;

	fstat(fd, &st);
	if ((st.st_mode & S_IFMT) != S_IFREG)
		return(-1);
	if (st.st_size < sizeof(struct fontinfo_hdr))
		return(-1);
	buf = setbrk(st.st_size);
	read(fd, buf, st.st_size);
	hdr = (struct fontinfo_hdr *) buf;
	if (hdr->magic != FONTINFO_MAGIC)
		return(-1);
	/* take it in */
	fontab[fontidx] = hdr;
	widthtab[fontidx] = (u_short *) (buf + hdr->width_offset);
	if (hdr->flags & FONTINFO_FLAGS_SYMBOL)
		smnt = fontidx + 1;
	encoding_vectors |= hdr->flags &
			(FONTINFO_FLAGS_ROMAN | FONTINFO_FLAGS_CYRILLIC);
	if (hdr->lchars_offset) {
		chdef = (struct chardef_section *) (buf + hdr->lchars_offset);
		lchars[fontidx] = chdef;
		mark_lchars(chdef);
	}
	if (hdr->schars_offset) {
		chdef = (struct chardef_section *) (buf + hdr->schars_offset);
		add_uchars(chdef, fontidx);
	}
	return(0);
}

char_pair2idx(pair)
{
	register int c1, c2;

	c1 = pair & 0177;
	c2 = (pair >> 8) & 0177;
	if (c1 < '!' || c1 > '~' || c2 < '!' || c2 > '~')
		return(-1);
	return((c1 - '!') * 94 + (c2 - '!'));
}

mark_lchars(chdef)
	struct chardef_section *chdef;
{
	register int *p, idx;

	for (p = (int *)(chdef + 1); *p; p += 2) {
		idx = char_pair2idx(*p);
		chlut[idx] |= 0x8000;
	}
}

add_uchars(chdef, fontidx)
	struct chardef_section *chdef;
{
	register int *p, ch, idx;
	int lastchar = 0;

	for (p = (int *)(chdef + 1); *p; p += 2) {
		idx = char_pair2idx(*p);
		if (p[1] != lastchar) {
			uchar_font[nuchars] = fontidx;
			uchar_char[nuchars] = lastchar = p[1];
			uchar_revmap[nuchars] = p[0];
			ch = 0x180 + nuchars++;
		}
		chlut[idx] = ch;
	}
}

nosymbol_remap()
{
	static int tab[] = {
		PAIR('n','o'), 0254,
		PAIR('m','.'), 0267,
		PAIR('m','u'), 0327,
		PAIR('d','i'), 0367,
		0, 0};
	register int i, *p;

	for (p = tab; *p; p += 2) {
		i = char_pair2idx(*p);
		chlut[i] = p[1];
	}
}

char *
debug_char_name(c)
	register int c;
{
	static char str[5] = "\\xxx";
	static char hexdigits[] = "0123456789abcdef";

	switch (c) {
	case CFMINUS:
		return "\\-";
	case NARSP:
		return "\\|";
	case HNSP:
		return "\\^";
	case UNDRULE:
		return "\\(ul";
	case OVRRULE:
		return "\\(rn";
	case BOXRULE:
		return "\\(br";
	case BASRULE:
		return "\\(ru";
	}
	if (c & 0x100) {
		if (c >= 0x180 && c < 0x180 + nuchars) {
			c = uchar_revmap[c - 0x180];
			str[1] = '(';
			str[2] = c & 0177;
			str[3] = (c >> 8) & 0177;
			return str;
		}
		str[1] = 'S';
	} else
		str[1] = 'X';
	str[2] = hexdigits[(c >> 4) & 0xF];
	str[3] = hexdigits[c & 0xF];
	return str;
}

resolve_char(c, print)
	register int c;
{
	register int x;

	if(cs = cstab[xfont]){
		if(ccs = ccstab[xfont])x = ccs; else x = xpts;
		cs = (cs * x * 10 + 3) / 6;
	}
	switch (c >> 5) {
	case 1:
		if (c == ' ') {
			if (cs)
				return(cs);
			if (spacesz &&
			    (!(fontab[xfont]->flags & FONTINFO_FLAGS_CWIDTH)
			     || spacesz_cw_ovr))
				return((spacesz * xpts * 10 + 3) / 6);
			x = widthtab[xfont][' '];
			if (x)
				return((x * xpts * 3 + 25) / 50);
			else
				return((SS * xpts * 10 + 3) / 6);
		}
		/* FALL THRU */
	case 0: case 2: case 3: case 4: case 5: case 6: case 7:
	base:
		xsfont = xfont;
		if (bdmult) {
			x = bdtab[xfont];
			if (x > 1)
				bd = (x - 1) * bdmult;
			else
				bd = 0;
		}
	char_from_font:
		x = widthtab[xsfont][c];
		if (!x)
			return(0);
		x = (x * xpts * 3 + 25) / 50 + bd;
		if (print)
			print_regular_char(c, x);
		if (cs)
			return(cs);
		else
			return(x);
	case 8:
		switch (c) {
		case CFMINUS:
			c = '-';
			goto base;
		case NARSP:
			if (cs)
				return(cs);
			return(xpts*10);
		case HNSP:
			if (cs)
				return(cs);
			return(xpts*5);
		case UNDRULE:
		case OVRRULE:
		case BASRULE:
			if (print)
				PS_linedraw(c, 1);
			if (cs)
				return(cs);
			else
				return(xpts * 30);
		case BOXRULE:
			if (print)
				PS_special_char('b', 'r');
			if (cs)
				return(cs);
			else
				return(0);
		default:
			return(0);
		}
	case 9: case 10: case 11: case 13: case 14: case 15:
		/* 192 code points for Symbol */
		c &= 0xFF;
		if (!smnt)
			goto base;
		xsfont = smnt - 1;
	handle_bds:
		if (bdmult) {
			x = bdstab[xfont];
			if (!x)
				x = bdtab[xfont];
			if (x > 1 && allow_bd_s)
				bd = (x - 1) * bdmult;
			else
				bd = 0;
		}
		goto char_from_font;
	case 12:
		/* dynamically assigned special chars */
		c -= 0x180;
		xsfont = uchar_font[c];
		c = uchar_char[c];
		goto handle_bds;
	}
}

width(c)
int c;
{
	register i,j,k,x;

	j = c;
	k = 0;
	if(j & MOT){
		if(j & VMOT)goto rtn;
		k = j & ~MOTV;
		if(j & NMOT)k = -k;
		goto rtn;
	}
	if((i = (j & CMASK)) == 010){
		k = -widthp;
		goto rtn;
	}
	if(i == PRESC)i = eschar;
	if((i == ohc) || is_xinfo_char(i))
		goto rtn;
	if((j>>16) != oldbits){
		xfont = (j>>16) & 0x1F;
		xpts = (j>>21) & 0xFF;
		oldbits = j >> 16;
	}
	if(j & ZBIT)goto rtn;
	i = trtab[i];
	if (setwdf)
		v.ct |= cttab[i];
	k = resolve_char(i, 0);
	widthp = k;
rtn:
	return(k);
}

bd_warn_check(i)
	register int i;
{
	register int c;
	static char warnmsg[] = "Warning: bd special char ";
	static char fontmsg[] = " on font xx\n";

	c = i & CMASK;
	if (c < 0x120)
		switch (c) {
		case UNDRULE:
		case OVRRULE:
		case BOXRULE:
		case BASRULE:
			break;
		default:
			return;
		}
	if((i>>16) != oldbits){
		xfont = (i>>16) & 0x1F;
		xpts = (i>>21) & 0xFF;
		oldbits = i >> 16;
	}
	if (!bdtab[xfont] && !bdstab[xfont])
		return;
	prstr(warnmsg);
	prstr(debug_char_name(c));
	fontmsg[9] = fontlab[xfont] & 0177;
	c = (fontlab[xfont] >> 8) & 0177;
	if (!c)
		c = ' ';
	fontmsg[10] = c;
	prstr(fontmsg);
}

setch()
{
	register int key, idx, l;

	if ((key = getrq()) == 0)
		return (0);
	idx = char_pair2idx(key);
	if (idx < 0)
		return (0);
	l = chlut[idx];
	if (l & 0x8000) {
		if (lchars[font] && (l = setch_extsearch(lchars[font], key)))
			return (l | chbits);
		l = chlut[idx] & 0x7FFF;
	}
	if (l >= 0xA0 && l <= 0xBF &&
	    fontab[font]->flags & FONTINFO_FLAGS_CYRILLIC)
		l = cyr_remap[l - 0xA0];
	if (l)
		l |= chbits;
	return (l);
}

setch_extsearch(chdef, key)
	struct chardef_section *chdef;
	register int key;
{
	register int *p;

	for (p = (int *)(chdef + 1); *p; p += 2)
		if (*p == key)
			return(p[1]);
	return(0);
}

find(i,j)
int i,j[];
{
	register k;

	if (isdigit(i & 0377)) {
		if (k = i >> BYTE) {
			if (!isdigit(k))
				return(-1);
			k = ((i & 0377) - '0') * 10 + k - '0';
		} else
			k = i - '0';
		k--;
		if (k < nfonts)
			return(k);
		else
			return(-1);
	}
	for(k=0; j[k] != i; k++)if(k >= nfonts)return(-1);
	return(k);
}
casefz(){
	register i, j, k;
	int savinc;

	k = 0;
fz0:
	if(skip() || !(i = getrq()) ||
	  ((j = find(i,fontlab))  == -1)){
		if(k)goto fz1;
		else return;
	}
	if(j == (smnt-1)){
		k = smnt;
		goto fz0;
	}
	if(k){
		spsz = j + 1;
		j = k -1;
	}
fz1:
	if((j==font) && fz[j].inc)savinc = fz[j].inc;
	else savinc = 0;
	fz[j].inc = fz[j].sign = fz[j].size = 0;
	if(skip()){
		if(k)spsz = 0;
		goto fz2;
	}
	if(((i=((k=getch()) & CMASK)) == '+') || (i == '-'))fz[j].sign = i;
	else{
		fz[j].sign = 0;
		ch = k;
	}
	noscale++;
	fz[j].size = atoi();
	noscale = 0;
fz2:
	if(j==font)casps1(apts + savinc);
	else if(j == smnt-1)mchbits();
}
caseps(){
	register i;

	if(skip())i = apts1;
	else{
		noscale++;
		i = inumb(&apts);
		noscale = 0;
		if(nonumb)return;
	}
	casps1(i);
}
casps1(i)
int i;
{
	if(i <= 0)return;
	if(fz[font].size){
		i = getfz(font, i);
	}
	apts1 = apts;
	apts = i;
	pts1 = pts;
	pts = i & 0377;
	mchbits();
}
mchbits(){
	register f;
	/* extern int spbits; */

/*
 * The spbits logic implements the .fz S F N "feature".  In the original
 * troff this feature affected only ASCII characters implemented via
 * the Special Font, not characters like \(*a, hence it is not applicable
 * to our implementation.
 */

	/* spbits = 0; */
	if (bdtab[font] && bdsim[font])
		f = bdsim[font] - 1;
	else
		f = font;
	chbits = ((pts << 5) | f) << 16;
	if (!chbits)
		prstr("mchbits: chbits set to 0!\n");
	sps = width(' ' | chbits);
/*
	if(font == (spsz-1)){
		i = getfz(smnt-1, apts + fz[font].inc) & 0377;
		spbits = ((i<<5) | font) << 16;
	}
*/
}
getfz(x,y)
int x, y;
{
	register i, j, k;

	i = fz[x].size;
	j = fz[x].sign;
	if(i || j){
		if(j == '+')i += y;
		else if(j == '-')i = y - i;
	}
	fz[x].inc = y - i;
	return(i);
}
setps(){
	register i,j;

	if((((i=getch() & CMASK) == '+')  || (i == '-')) &&
	  (((j=((ch = getch()) & CMASK) - '0') >= 0) && (j <= 9))){
		if(i == '-')j = -j;
		ch = 0;
		casps1(apts+j);
		return;
	}
	if(i == '0'){
		casps1(apts1);
		return;
	}
	if((i > '0') && (i <= '9')){
		i -= '0';
		if((i <= 3) &&
		  ((j=((ch = getch()) & CMASK) - '0') >= 0) && (j <= 9)){
			i = 10*i +j;
			ch = 0;
		}
		casps1(i);
	} else {
		noscale++;
		i = inumb(&apts);
		noscale = 0;
		getch();	/* eat other delim */
		if(nonumb)return;
		casps1(i);
	}
}
caseft(){
	skip();
	setfont(1);
}
setfont(a)
int a;
{
	register i,j;

	if(a)i = getrq();
		else i = getsn();
	if(!i || (i == 'P')){
		j = font1;
		goto s0;
	}
	if((j = find(i,fontlab))  == -1)return;
s0:
	font1 = font;
	font = j;
	i = 0;
	if(fz[font1].size){
		i++;
		casps1(apts + fz[font1].inc);
	}else if(fz[font].size){
		i++;
		casps1(apts);
	}
	if(!i)mchbits();
}
setwd(){
	register i, base, wid;
	int delim, em, k;
	int savlevel, savhp, savapts, savapts1, savfont, savfont1,
		savpts, savpts1;
        int *savpinchar, *p, *q, tempinchar[LNSIZE];    /* XXX */

	base = v.st = v.sb = wid = v.ct = 0;
	if((delim = getch() & CMASK) & MOT)return;
	savhp = v.hp;
        savpinchar = pinchar;   /* XXX */
        for (p=inchar, q=tempinchar; p < pinchar; )     /* XXX */
                *q++ = *p++;    /* XXX */
        pinchar = inchar;       /* XXX */
	savlevel = level;
	v.hp = level = 0;
	savapts = apts;
	savapts1 = apts1;
	savfont = font;
	savfont1 = font1;
	savpts = pts;
	savpts1 = pts1;
	setwdf++;
	while((((i = getch()) & CMASK) != delim) && !nlflg){
		wid += width(i);
		if(!(i & MOT)){
			em = (xpts & 0377)*60;
		}else if(i & VMOT){
			k = i & ~MOTV;
			if(i & NMOT)k = -k;
			base -= k;
			em = 0;
		}else continue;
		if(base < v.sb)v.sb = base;
		if((k=base + em) > v.st)v.st = k;
	}
	nform = 0;
	setn1(wid);
	v.hp = savhp;
        pinchar = savpinchar;   /* XXX */
        for (p=inchar, q=tempinchar; p < pinchar; )     /* XXX */
                *p++ = *q++;    /* XXX */
	level = savlevel;
	apts = savapts;
	apts1 = savapts1;
	font = savfont;
	font1 = savfont1;
	pts = savpts;
	pts1 = savpts1;
	mchbits();
	setwdf = 0;
}
vmot(){
	dfact = lss;
	vflag++;
	return(mot());
}
hmot(){
	dfact = 60 * (pts & 0377);
	return(mot());
}
mot(){
	register i, j;

	j = HOR;
	getch(); /*eat delim*/
	if(i = atoi()){
		if(vflag)j = VERT;
		i = makem(quant(i,j));
	}
	getch();
	vflag = 0;
	dfact = 1;
	return(i);
}
sethl(k)
int k;
{
	register i;

	i = 30 * (pts & 0377);
	if(k == 'u')i = -i;
	else if(k == 'r')i = -2*i;
	vflag++;
	i = makem(i);
	vflag = 0;
	return(i);
}
makem(i)
int i;
{
	register j;

	if((j = i) < 0)j = -j;
	j = (j & ~MOTV) | MOT;
	if(i < 0)j |= NMOT;
	if(vflag)j |= VMOT;
	return(j);
}
getlg(i)
int i;
{
	register j, k;

	j = (i>>16) & 0x1F;
	k = fontab[j]->flags;
	if (!(k & FONTINFO_FLAGS_ROMAN) || (k & FONTINFO_FLAGS_NOLIG))
		return(i);

	switch((j = getch0()) & CMASK){
		case 'f':
			if (lg != 5)
				goto nope;
			switch((k =getch0()) & CMASK){
				case 'i':
					j = 0x1D;
					break;
				case 'l':
					j = 0x1E;
					break;
				default:
					ch0 = k;
					j = 0x1C;
			}
			break;
		case 'l':
			j = 0x8B;
			break;
		case 'i':
			j = 0x8A;
			break;
		default:
		nope:
			ch0 = j;
			j = i;
	}
	return((i & ~CMASK) | j);
}
caselg(){

	lg = 1;
	if(skip())return;
	lg = atoi();
}
casecs(){
	register i, j;

	noscale++;
	skip();
	if(!(i=getrq()) ||
	  ((i = find(i,fontlab)) < 0))goto rtn;
	skip();
	cstab[i] = atoi();
	skip();
	j = atoi();
	if(!nonumb)ccstab[i] = j;
rtn:
	noscale = 0;
}
casebd(){
	register i, j, k;

	k = 0;
bd0:
	if(skip() || !(i = getrq())) {
		/*
		 * In the original troff code implementation,
		 * a bare ".bd S" cancels all .bd S f x settings.
		 */
		if (k)
			bzero(bdstab, sizeof bdstab);
		return;
	}
	if(i == 'S'){
		k = 1;
		goto bd0;
	}
	if((j = find(i,fontlab)) == -1)
		return;
	skip();
	noscale++;
	i = atoi();
	noscale = 0;
	if (k)
		bdstab[j] = i;
	else {
		bdtab[j] = i;
		if (j == font)
			mchbits();
	}
}
casevs(){
	register i;

	skip();
	vflag++;
	dfact = 60; /*default scaling is points!*/
	res = VERT;
	i = inumb(&lss);
	if(nonumb)i = lss1;
	if(i < VERT)i = VERT;
	lss1 = lss;
	lss = i;
}
casess(){
	noscale++;
	skip();
	spacesz = atoi();
	if (nonumb) {
		spacesz = SS;
		spacesz_cw_ovr = 0;
	} else if (getach() == 'o')	/* stands for "override" */
		spacesz_cw_ovr = 1;
	else
		spacesz_cw_ovr = 0;
	sps = width(' ' | chbits);
	noscale = 0;
}
xlss(){
	register i, j;

	getch();
	dfact = lss;
	i = quant(atoi(),VERT);
	dfact = 1;
	getch();
	if((j = i) < 0)j = -j;
	j = (j << 9) | XLSS;
	if(i < 0)j |= 0x40000000;
	return(j);
}
