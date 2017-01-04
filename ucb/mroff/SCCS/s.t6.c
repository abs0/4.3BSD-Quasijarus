h41834
s 00018/00000/01010
d D 5.38 2012/07/22 15:40:08 msokolov 38 37
c remap \(no, \(m., \(mu and \(di to base font (Latin-1) if no Symbol
e
s 00018/00002/00992
d D 5.37 2012/07/22 14:39:12 msokolov 37 36
c -b S+/S- reinstated, default to S+ for now
e
s 00009/00002/00985
d D 5.36 2012/07/22 09:43:24 msokolov 36 35
c bugfix in the bd_warn_check logic
e
s 00106/00115/00881
d D 5.35 2012/07/22 09:08:39 msokolov 35 34
c new resolve_char() function is like old troff's getcw()
c hoping that this reduction in the number of function calls per character
c will speed things up
e
s 00036/00028/00960
d D 5.34 2012/07/22 02:52:29 msokolov 34 33
c .bd S warning mechanism split out so it would work with -z
e
s 00008/00001/00980
d D 5.33 2012/07/22 01:01:30 msokolov 33 32
c a bare ".bd S" cancels all .bd S f x settings, like in the original
e
s 00061/00015/00920
d D 5.32 2012/07/22 00:20:44 msokolov 32 31
c bd'ing of S actually works
e
s 00058/00020/00877
d D 5.31 2012/07/21 07:16:55 msokolov 31 30
c bd'ing implemented
e
s 00010/00003/00887
d D 5.30 2012/07/21 00:44:35 msokolov 30 29
c .bd: substitution mode implemented
e
s 00018/00001/00872
d D 5.29 2012/07/21 00:18:54 msokolov 29 28
c .bd: casebd() setting bdtab[] implemented
e
s 00066/00000/00807
d D 5.28 2012/07/21 00:08:18 msokolov 28 27
c -b spec parsing implemented
e
s 00005/00000/00802
d D 5.27 2012/07/18 02:07:25 msokolov 27 26
c getlg: restricted to Roman charset fonts without "nolig"
e
s 00020/00015/00782
d D 5.26 2012/07/18 01:31:51 msokolov 26 25
c implemented automatic ".ss 0" for CWIDTH fonts, and an override capability
e
s 00011/00002/00786
d D 5.25 2012/07/17 08:29:03 msokolov 25 24
c .fz S F N is known to do nothing, so don't bother trying
e
s 00088/00038/00700
d D 5.24 2012/07/15 03:18:31 msokolov 24 23
c troff: named char handling converted to LUT, Cyrillic support added
e
s 00046/00003/00692
d D 5.23 2012/03/06 05:06:53 msokolov 23 22
c character set extension implemented
e
s 00071/00047/00624
d D 5.22 2012/03/06 04:12:36 msokolov 22 21
c converted to ftXX files and font search paths
e
s 00081/00103/00590
d D 5.21 2012/03/05 00:07:47 msokolov 21 20
c first restructuring steps for fcXX and .bd simulation
e
s 00002/00003/00691
d D 5.20 2012/03/04 02:06:22 msokolov 20 19
c tr handles the full 512-char set now
e
s 00017/00014/00677
d D 5.19 2012/02/16 03:11:25 msokolov 19 18
c argh, I meant binary search!
c *** CHANGED *** 2012/02/16 03:13:48 msokolov
c setch: linear search implemented
e
s 00063/00006/00628
d D 5.18 10/10/07 01:29:44 msokolov 18 17
c the SuperSpecial font is here
e
s 00003/00000/00631
d D 5.17 10/09/22 03:33:42 msokolov 17 16
c \(ci reimplemented via the procset
e
s 00002/00000/00629
d D 5.16 10/09/05 23:52:32 msokolov 16 15
c have .ss w/o argument restore the default
e
s 00016/00000/00613
d D 5.15 10/08/24 03:51:42 msokolov 15 14
c .lg 5 mode implemented
e
s 00001/00001/00612
d D 5.14 05/09/17 04:44:36 msokolov 14 13
c allow 2nd char of font name to be a digit
e
s 00002/00006/00611
d D 5.13 04/11/22 23:44:05 msokolov 13 12
c make it possible to print space like all other characters using its true width
c with .ss 0 (very useful for Courier)
e
s 00000/00000/00617
d D 5.12 04/11/05 05:54:34 msokolov 12 11
i 10
c recognise St after all
e
s 00000/00000/00617
d D 5.11 04/10/31 08:47:50 msokolov 11 10
x 10
c use a different font directory instead of different font names
c for troffemu, so no St
e
s 00001/00001/00616
d D 5.10 04/10/31 05:55:49 msokolov 10 9
c recognise St as an alternative special font
e
s 00010/00001/00607
d D 5.9 04/10/30 03:42:18 msokolov 9 8
c some improvements
c using a real procset
c line drawing chars done via the procset, no more raping of Symbol
e
s 00002/00002/00606
d D 5.8 04/10/24 20:25:58 msokolov 8 7
c use done3() for initialization errors
e
s 00003/00003/00605
d D 5.7 04/09/15 07:03:40 msokolov 7 6
c replace the LX/HX pair of 16-bit metacharacters with one 32-bit metacharacter
e
s 00003/00000/00605
d D 5.6 04/09/14 23:04:35 msokolov 6 5
c reimplement the ct register functionality
e
s 00012/00003/00593
d D 5.5 04/09/13 01:21:49 msokolov 5 4
c had to revert the \sN mechanism back to the historic 4-39 range
c for arbitrary point sizes the new mechanism is \s'N'
e
s 00004/00002/00592
d D 5.4 04/09/11 10:31:32 msokolov 4 3
c setps:	don't lose bits when putting unwanted chars back in ch
e
s 00002/00001/00592
d D 5.3 04/09/09 18:20:05 msokolov 3 2
c width:	need to translate through trtab before checking for space
e
s 00001/00002/00592
d D 5.2 04/09/09 17:59:42 msokolov 2 1
c handling of Symbol chars in width() was broken
e
s 00594/00000/00000
d D 5.1 04/09/08 16:42:02 msokolov 1 0
c first working version
e
u
U
t
T
I 1
#ifndef lint
D 21
static char sccsid[] = "%W% (Berkeley) %G%";
E 21
I 21
static char sccsid[] = "%W% (Berkeley) %E%";
E 21
#endif lint

#include "tdef.h"
I 21
#include <sys/stat.h>
E 21
#include <ctype.h>
I 22
#include <strings.h>
E 22
extern
#include "d.h"
extern
#include "v.h"
I 21
D 22
#include "chardef.h"
E 22
I 22
#include "fontinfo.h"
E 22
E 21

/*
troff6.c

width functions, sizes and fonts
*/

D 32
/*
D 21
 * This version of troff does not support the .bd request.
 * The PostScript font machinery was certainly never designed for
 * this kind of abuse; in the amazing assortment of available
 * Type 1 fonts you can find any weight you want, and finally
 * bold and italic are not mutually exclusive any more.
 *
 * I debated with myself whether implementing .bd would be useful
D 18
 * for backwark compatibility, but decided against it.  First off,
E 18
I 18
 * for backward compatibility, but decided against it.  First off,
E 18
 * note that it takes its displacement argument in internal units
 * with no scaling possible, and our internal units are 10 times
 * smaller than the original troff's.  But in reality whether you
 * offset by .5 points (3 units of old troff) or by .05 points
 * (3 units of ours), the printed output will not look any better,
 * and probably a little worse, than it would with the .bd silently
 * ignored.  Therefore, I have decided that the latter strategy is
 * the best even in backward compatibility applications.
E 21
I 21
 * .bd will be handled by way of "idiom recognition":
 * invoking troff with an option like -bI,BI will cause "bd-ing"
 * of font I to substitute font BI.
E 21
 */

E 32
extern	int	inchar[LNSIZE], *pinchar;	/* XXX */
extern int eschar;
extern int widthp;
extern int ohc;
extern int xpts;
extern int xfont;
I 24
extern int xsfont;
E 24
extern int code;
extern int smnt;
extern int setwdf;
extern int cs;
extern int ccs;
D 26
extern int spacesz;
E 26
I 26
extern int spacesz, spacesz_cw_ovr;
E 26
D 20
extern char trtab[];
E 20
I 20
extern u_short trtab[];
E 20
extern int xbitf;
extern int mfont;
extern int mpts;
extern int pfont;
extern int ppts;
extern int oldbits;
extern int chbits;
D 25
extern int spbits;
E 25
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
D 22
char *fontdir = "/usr/lib/pstroff";
E 22
I 22
char stdfontdir[] = "/usr/lib/pstroff";
char *fontpath;
char *font_search_path[10] = {stdfontdir, 0};
E 22
I 21
char *bdsimlist;
E 21
extern int level;
extern int ch;
extern int res;
extern int ptid;
extern int xxx;
extern int ulfont;
extern int ulbit;
I 6
extern char cttab[];
I 31
extern int bd;
E 31
E 6
int nfonts;
D 22
u_short *fontab[32];
E 22
I 22
struct fontinfo_hdr *fontab[32];
u_short *widthtab[32];
E 22
int fontlab[32];
I 21
int bdsim[32];
I 28
D 31
int bdmult, bd_s_ok, bd_s_warn;
E 31
I 31
D 37
int bdmult, bd_s_warn;
E 37
I 37
int bdmult, allow_bd_s = 1, bd_s_warn;
E 37
E 31
E 28
E 21
int cstab[32], ccstab[32];
I 28
D 31
int bdtab[32], bdstab[32];
E 31
I 31
D 34
int bdtab[32], bdstab[32], bdswarn[32];
E 34
I 34
int bdtab[32], bdstab[32];
E 34
E 31
E 28
int spsz = 0;
struct fz {
	char sign;
	char size;
	int inc;
	} fz[32];
I 23
D 24
struct chardef_section *lchars[32], *spchars;
E 24
I 24
struct chardef_section *lchars[32];
extern u_short chlut[94*94];
u_char uchar_font[32], uchar_char[32], nuchars;
I 32
int uchar_revmap[32];
E 32
u_long encoding_vectors;
u_char cyr_remap[32] = {
	0xA0,	0,	0,	0,	0xBD,	0,	0x87,	0x83,
	0x98,	0x85,	0,	0x8A,	0,	0xAD,	0x86,	0x95,
	0x1C,	0,	0,	0,	0x92,	0,	0x84,	0,
	0,	0,	0,	0x8B,	0,	0,	0,	0,
};
E 24
E 23
I 18
D 21
int SSfont;
E 21
E 18

fontinit()
{
I 22
	register int i;

E 22
I 21
	parse_font_list();
I 28
	if (bdsimlist)
		parse_bdsim_list();
E 28
D 22
	read_fw_fc_files();
E 22
I 22
	if (fontpath)
		parse_font_path();
I 24
	smnt = 0;
E 24
	for (i = 0; i < nfonts; i++)
		read_font(i);
E 22
	if (nfonts == 1)
		ulfont = ulbit = 0;
I 38
	if (!smnt)
		nosymbol_remap();
E 38
}

parse_font_list()
{
E 21
	register int i, c;
D 21
	register char *cp, *cp1, *cp2;
	char *widthbuf;
	extern char *setbrk();
	char filename[128];
	int fd;
E 21
I 21
	register char *cp;
E 21

D 21
	for (cp = fontlist, i = 0; *cp; cp++)
		if (*cp == ',')
			i++;
	nfonts = i + 1;
D 18
	smnt = 0;
E 18
I 18
	SSfont = smnt = 0;
E 18
	widthbuf = setbrk(nfonts * 512);
	for (i = 0, cp = fontlist; i < nfonts; i++) {
		fontab[i] = (u_short *)widthbuf;
		for (cp1 = fontdir, cp2 = filename, c = '/'; *cp1; )
			*cp2++ = c = *cp1++;
		if (c != '/')
			*cp2++ = '/';
		*cp2++ = 'f';
		*cp2++ = 'w';
E 21
I 21
	for (cp = fontlist, i = 0; *cp; i++) {
E 21
		if (!isalpha(*cp)) {
bad:			prstr("Invalid font specification\n");
D 8
			exit(-1);
E 8
I 8
			done3(-1);
E 8
		}
D 21
		c = *cp;
		*cp2++ = *cp++;
D 14
		if (isalpha(*cp)) {
E 14
I 14
		if (isalnum(*cp)) {
E 14
			c |= *cp << BYTE;
			*cp2++ = *cp++;
		}
E 21
I 21
		c = *cp++;
		if (isalnum(*cp))
			c |= *cp++ << BYTE;
E 21
		if (*cp) {
			if (*cp == ',')
				cp++;
			else
				goto bad;
		}
		fontlab[i] = c;
D 10
		if (c == 'S')
E 10
I 10
D 18
		if (c == 'S' || c == PAIR('S','t'))
E 18
I 18
D 21
		if (c == 'S' || c == PAIR('S','t') || c == PAIR('S','v'))
E 18
E 10
			smnt = i + 1;
I 18
		else if (c == PAIR('S','S'))
			SSfont = i + 1;
E 18
		*cp2 = '\0';
E 21
I 21
	}
	if (!i)
		goto bad;
	nfonts = i;
I 28
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
I 31
		if (*cp == '!') {
			cp++;
			bd_s_warn = 1;
			goto next;
		}
E 31
		if (!isalpha(*cp))
			goto bad;
		c = *cp++;
		if (isalnum(*cp))
			c |= *cp++ << BYTE;
I 37
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
E 37
D 31
		if (c == 'S') {
			switch (*cp++) {
			case '+':
				bd_s_ok = 1;
				break;
			case '-':
				bd_s_ok = 0;
				break;
			case '!':
				bd_s_warn = 1;
				break;
			default:
				goto bad;
			}
			goto next;
		}
E 31
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
E 28
}

D 22
read_fw_fc_files()
E 22
I 22
parse_font_path()
E 22
{
I 22
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
E 22
	register int i, c;
	register char *cp1, *cp2;
D 22
	char *widthbuf;
	extern char *setbrk();
E 22
	char filename[128];
	int fd;

D 22
	smnt = 0;
	widthbuf = setbrk(nfonts * 512);
	for (cp1 = fontdir, cp2 = filename, c = '/'; *cp1; )
E 22
I 22
	for (cp1 = dir, cp2 = filename; *cp1; )
E 22
		*cp2++ = c = *cp1++;
	if (c != '/')
		*cp2++ = '/';
D 22
	*cp2++ = 'f';
	cp2[3] = '\0';
	for (i = 0; i < nfonts; i++) {
		/* fw is mandatory */
		c = fontlab[i];
		cp2[0] = 'w';
		cp2[1] = c;
		cp2[2] = c >> BYTE;
		fontab[i] = (u_short *)widthbuf;
E 21
		fd = open(filename, 0);
		if (fd < 0) {
			prstr("Cannot open ");
			prstr(filename);
			prstr("\n");
D 8
			exit(-1);
E 8
I 8
			done3(-1);
E 8
		}
		read(fd, widthbuf, 512);
		close(fd);
		widthbuf += 512;
I 21
		/* look for optional fc */
		cp2[0] = 'c';
		fd = open(filename, 0);
		if (fd >- 0) {
			if (handle_fc_file(i, fd) < 0) {
				prstr(filename);
				prstr(" is invalid\n");
				done3(-1);
			}
			close(fd);
		}
E 22
I 22
	strcpy(cp2, ftname);
	fd = open(filename, 0);
	if (fd < 0)
		return(0);
	if (handle_ft_file(fontidx, fd) < 0) {
		prstr(filename);
		prstr(" is invalid\n");
		done3(-1);
E 22
E 21
	}
I 22
	close(fd);
	return(1);
E 22
D 21
	if (nfonts == 1)
		ulfont = ulbit = 0;
E 21
}

I 18
D 21
handle_SS_char(c, newfont, newchar)
	register int c;
	int *newfont, *newchar;
E 21
I 21
D 22
handle_fc_file(fontidx, fd)
E 22
I 22
handle_ft_file(fontidx, fd)
I 23
	register int fontidx;
	int fd;
E 23
E 22
E 21
{
D 21
	switch (c) {
	case SPECIAL_BS:
		if (SSfont) {
			*newfont = SSfont - 1;
			*newchar = 'B';
			return(1);
		}
		return(0);
	case SPECIAL_CI:
		if (SSfont) {
			*newfont = SSfont - 1;
			*newchar = 'C';
			return(1);
		}
		return(0);
	case SPECIAL_LH:
		if (SSfont) {
			*newfont = SSfont - 1;
			*newchar = 'L';
			return(1);
		}
		if (smnt) {
			*newfont = smnt - 1;
			*newchar = 0xDC;
			return(1);
		}
		return(0);
	case SPECIAL_RH:
		if (SSfont) {
			*newfont = SSfont - 1;
			*newchar = 'R';
			return(1);
		}
		if (smnt) {
			*newfont = smnt - 1;
			*newchar = 0xDE;
			return(1);
		}
		return(0);
	}
	return(0);
E 21
I 21
	struct stat st;
	extern char *setbrk();
	char *buf;
D 22
	register struct chardef_hdr *hdr;
E 22
I 22
	register struct fontinfo_hdr *hdr;
I 23
	register struct chardef_section *chdef;
E 23
E 22

	fstat(fd, &st);
	if ((st.st_mode & S_IFMT) != S_IFREG)
		return(-1);
D 22
	if (st.st_size < sizeof(struct chardef_hdr))
E 22
I 22
	if (st.st_size < sizeof(struct fontinfo_hdr))
E 22
		return(-1);
	buf = setbrk(st.st_size);
	read(fd, buf, st.st_size);
D 22
	hdr = (struct chardef_hdr *) buf;
	if (hdr->magic != CHARDEF_MAGIC)
E 22
I 22
	hdr = (struct fontinfo_hdr *) buf;
	if (hdr->magic != FONTINFO_MAGIC)
E 22
		return(-1);
D 22
	if (hdr->flags & CHARDEF_FLAGS_SYMBOL)
E 22
I 22
	/* take it in */
	fontab[fontidx] = hdr;
	widthtab[fontidx] = (u_short *) (buf + hdr->width_offset);
	if (hdr->flags & FONTINFO_FLAGS_SYMBOL)
E 22
		smnt = fontidx + 1;
I 24
	encoding_vectors |= hdr->flags &
			(FONTINFO_FLAGS_ROMAN | FONTINFO_FLAGS_CYRILLIC);
E 24
D 23
	/* character set extension handling to be implemented */
E 23
I 23
	if (hdr->lchars_offset) {
		chdef = (struct chardef_section *) (buf + hdr->lchars_offset);
		lchars[fontidx] = chdef;
I 24
		mark_lchars(chdef);
E 24
	}
	if (hdr->schars_offset) {
		chdef = (struct chardef_section *) (buf + hdr->schars_offset);
D 24
		spchar_set_font_bits(chdef, fontidx);
		chdef->next = spchars;
		spchars = chdef;
E 24
I 24
		add_uchars(chdef, fontidx);
E 24
	}
E 23
I 22
	return(0);
E 22
E 21
}

I 23
D 24
spchar_set_font_bits(chdef, fontidx)
E 24
I 24
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
E 24
	struct chardef_section *chdef;
{
D 24
	register int *p;
	register int mask;
E 24
I 24
	register int *p, idx;
E 24

D 24
	mask = fontidx << 16;
	for (p = (int *)(chdef + 1); *p; p += 2)
		p[1] |= mask;
E 24
I 24
	for (p = (int *)(chdef + 1); *p; p += 2) {
		idx = char_pair2idx(*p);
		chlut[idx] |= 0x8000;
	}
E 24
}

I 24
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
I 32
			uchar_revmap[nuchars] = p[0];
E 32
			ch = 0x180 + nuchars++;
		}
		chlut[idx] = ch;
I 38
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
E 38
	}
}

D 35
handle_9bit_char(c)
	register int c;
{
	xsfont = xfont;
	if (!(c & 0x100))
		return(c);
	if (c >= 0x180 && c < 0x180 + nuchars) {
		c -= 0x180;
		xsfont = uchar_font[c];
		return(uchar_char[c]);
	}
	if (smnt)
		xsfont = smnt - 1;
	return(c & BMASK);
}

I 31
is_printchar_valid(c)
	register int c;
{
	if (c < 0x100 || c >= 0x120)
		return(1);
	switch (c) {
	case CFMINUS:
	case NARSP:
	case HNSP:
	case UNDRULE:
	case OVRRULE:
	case BOXRULE:
	case BASRULE:
		return(1);
	default:
		return(0);
	}
}

E 35
I 32
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

I 35
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
D 37
			if (x > 1)
E 37
I 37
			if (x > 1 && allow_bd_s)
E 37
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

E 35
E 32
E 31
E 24
E 23
E 18
width(c)
int c;
{
	register i,j,k,x;
I 18
D 31
	int nc, nf;
E 31
E 18

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
D 35
	if(cs = cstab[xfont]){
		if(ccs = ccstab[xfont])x = ccs; else x = xpts;
D 26
		cs = (j = (cs&077)*(x&0377)*10)/6;
		if((j%6) >= 3)cs++;
E 26
I 26
D 31
		cs = ((cs&077)*(x&0377)*10+3)/6;
E 31
I 31
		cs = (cs * x * 10 + 3) / 6;
E 31
E 26
	}
E 35
I 3
D 20
	if (!(i & 0x100))
		i = trtab[i] & BMASK;
E 20
I 20
	i = trtab[i];
I 31
D 35
	if (!is_printchar_valid(i))
		goto rtn;
E 35
E 31
E 20
I 6
	if (setwdf)
		v.ct |= cttab[i];
I 26
D 35
	if (cs) {
		k = cs;
		goto w1;
	}
E 26
E 6
E 3
	k = spacewidth(i);
	if (k)
		goto w1;
I 31
	getbd(i);
E 31
	if (i & 0x100) {
D 9
		if (i == CFMINUS) {
E 9
I 9
		switch (i) {
		case CFMINUS:
E 9
			i = '-';
			goto w0;
I 9
		case BASRULE:
		case UNDRULE:
		case OVRRULE:
			k = xpts * 30;
			goto w1;
		case BOXRULE:
			k = 0;
			goto w1;
I 17
D 18
		case CIRCLE:
			k = xpts * 45;
			goto w1;
E 18
I 18
D 21
		case SPECIAL_BS:
		case SPECIAL_CI:
		case SPECIAL_LH:
		case SPECIAL_RH:
			if (handle_SS_char(i, &nf, &nc)) {
				k = getcw(nc, nf, xpts);
				goto w1;
			} else
				return(0);
E 21
E 18
E 17
E 9
		}
D 2
		if ((i & 0x7F) < 0x20)
			goto rtn;
E 2
I 2
D 24
		i &= BMASK;
E 2
		if (smnt)
			k = getcw(i, smnt - 1, xpts);
		else
			goto w0;
E 24
I 24
		i = handle_9bit_char(i);
		k = getcw(i, xsfont, xpts);
E 24
	} else {
D 3
		i = trtab[i] & BMASK;
E 3
w0:		k = getcw(i, xfont, xpts);
	}
I 31
	if (k)
		k += bd;
E 31
D 26
w1:	if(cs)k = cs;
	widthp = k;
E 26
I 26
w1:	widthp = k;
E 35
I 35
	k = resolve_char(i, 0);
	widthp = k;
E 35
E 26
rtn:
	return(k);
D 35
}

spacewidth(i)
{
D 26
	register int j, k;
E 26
I 26
	register int k;
E 26

	switch (i) {
	case ' ':
D 26
		k = (j = spacesz * xpts * 10) / 6;
		if ((j%6) >= 3)
			k++;
E 26
I 26
		if (fontab[xfont]->flags & FONTINFO_FLAGS_CWIDTH &&
		    !spacesz_cw_ovr)
			return(0);
		k = (spacesz * xpts * 10 + 3) / 6;
E 26
		return(k);
	case NARSP:
		return(xpts*10);
	case HNSP:
		return(xpts*5);
	}
	return(0);
}

getcw(i, f, pts)
int i, f, pts;
{
D 26
	register j,k;
	register char *p;
	int x;
E 26
I 26
	register k;
E 26

D 22
	k = fontab[f][i];
E 22
I 22
	k = widthtab[f][i];
E 22
D 26
	k = (j = k * pts * 3) / 50;
	if((j%50) >= 25)k++;
E 26
I 26
	k = (k * pts * 3 + 25) / 50;
E 26
	return(k);
}
I 23

I 31
getbd(c)
{
D 32
	register int bdv;
E 32
I 32
D 34
	register int t;
	static char warnmsg[] = "Warning: bd special char ";
	static char fontmsg[] = " on font xx\n";
E 34
I 34
	register int v;
E 34
E 32

D 32
	if (bd_s_warn && c >= 0x120 && bdswarn[xfont]) {
		prstr("bd_s_warn stub\n");
E 32
I 32
D 34
	if (bd_s_warn && c & 0x100 && c != CFMINUS && bdswarn[xfont]) {
		prstr(warnmsg);
		prstr(debug_char_name(c));
		fontmsg[9] = fontlab[xfont] & 0177;
		t = (fontlab[xfont] >> 8) & 0177;
		if (!t)
			t = ' ';
		fontmsg[10] = t;
		prstr(fontmsg);
E 32
	}
E 34
	bd = 0;
	if (!bdmult)
		return;
	if (c >= 0x120 && bdstab[xfont])
D 32
		bdv = bdstab[xfont];
E 32
I 32
D 34
		t = bdstab[xfont];
E 34
I 34
		v = bdstab[xfont];
E 34
E 32
	else
D 32
		bdv = bdtab[xfont];
	if (bdv > 1)
		bd = (bdv - 1) * bdmult;
E 32
I 32
D 34
		t = bdtab[xfont];
	if (t > 1)
		bd = (t - 1) * bdmult;
E 34
I 34
		v = bdtab[xfont];
	if (v > 1)
		bd = (v - 1) * bdmult;
E 35
E 34
E 32
}

I 34
D 36
bd_warn_check(c)
	register int c;
E 36
I 36
bd_warn_check(i)
	register int i;
E 36
{
I 36
	register int c;
E 36
	static char warnmsg[] = "Warning: bd special char ";
	static char fontmsg[] = " on font xx\n";

I 36
	c = i & CMASK;
E 36
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
I 36
	if((i>>16) != oldbits){
		xfont = (i>>16) & 0x1F;
		xpts = (i>>21) & 0xFF;
		oldbits = i >> 16;
	}
E 36
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

E 34
E 31
E 23
D 19
setch(){
	register i,*j,k;
	extern int chtab[];
E 19
I 19
setch()
{
D 24
	extern int chtab[], chtab_len;
D 23
	register int *base = chtab, *p;
E 23
I 23
	register int *base, *p;
E 23
	register int key, lim;
E 24
I 24
	register int key, idx, l;
E 24
E 19

D 19
	if((i = getrq()) == 0)return(0);
	for(j=chtab;*j != i;j++)if(*(j++) == 0)return(0);
	k = *(++j) | chbits;
/*
	if((i & CMASK) == '*'){
		if(((i = find('R',fontlab)) < 0) &&
		   ((i = find('G',fontlab)) < 0))
			return(k);
		else return((k & ~(03<<(BYTE+1))) | (i<<(BYTE+1)));
E 19
I 19
	if ((key = getrq()) == 0)
		return (0);
I 23
D 24
	/* check for extensions */
	if (lchars[font] && (lim = setch_extsearch(lchars[font], key)))
		return (lim | chbits);
	if (spchars && (lim = setch_extsearch(spchars, key)))
		return (lim | chbits & 0xFFE0FFFF);
E 23
	/* binary search */
D 23
	for (lim = chtab_len; lim != 0; lim >>= 1) {
E 23
I 23
	for (base = chtab, lim = chtab_len; lim != 0; lim >>= 1) {
E 23
		p = base + (lim & ~1);
		if (*p == key)
			return (p[1] | chbits);
		if (key > *p) {	/* move right */
			base = p + 2;
			lim--;
		}		/* else move left */
E 24
I 24
	idx = char_pair2idx(key);
	if (idx < 0)
		return (0);
	l = chlut[idx];
	if (l & 0x8000) {
		if (lchars[font] && (l = setch_extsearch(lchars[font], key)))
			return (l | chbits);
		l = chlut[idx] & 0x7FFF;
E 24
E 19
	}
D 19
*/
	return(k);
E 19
I 19
D 24
	return (0);
E 24
I 24
	if (l >= 0xA0 && l <= 0xBF &&
	    fontab[font]->flags & FONTINFO_FLAGS_CYRILLIC)
		l = cyr_remap[l - 0xA0];
	if (l)
		l |= chbits;
	return (l);
E 24
E 19
}
I 24

E 24
I 23
setch_extsearch(chdef, key)
D 24
	register struct chardef_section *chdef;
E 24
I 24
	struct chardef_section *chdef;
E 24
	register int key;
{
	register int *p;

D 24
	for (; chdef; chdef = chdef->next)
		for (p = (int *)(chdef + 1); *p; p += 2)
			if (*p == key)
				return(p[1]);
E 24
I 24
	for (p = (int *)(chdef + 1); *p; p += 2)
		if (*p == key)
			return(p[1]);
E 24
	return(0);
}

E 23
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
D 30
	register i;
E 30
I 30
D 34
	register i, f;
E 34
I 34
	register f;
E 34
E 30
I 25
	/* extern int spbits; */
E 25

D 25
	spbits = 0;
E 25
I 25
/*
 * The spbits logic implements the .fz S F N "feature".  In the original
 * troff this feature affected only ASCII characters implemented via
 * the Special Font, not characters like \(*a, hence it is not applicable
 * to our implementation.
 */

	/* spbits = 0; */
E 25
D 34
	i = pts & 0377;
E 34
D 30
	chbits = ((i<<5) | font) << 16;
E 30
I 30
	if (bdtab[font] && bdsim[font])
		f = bdsim[font] - 1;
	else
		f = font;
D 34
	chbits = ((i<<5) | f) << 16;
E 34
I 34
	chbits = ((pts << 5) | f) << 16;
E 34
E 30
I 4
	if (!chbits)
		prstr("mchbits: chbits set to 0!\n");
E 4
	sps = width(' ' | chbits);
I 25
/*
E 25
	if(font == (spsz-1)){
		i = getfz(smnt-1, apts + fz[font].inc) & 0377;
		spbits = ((i<<5) | font) << 16;
	}
I 25
*/
E 25
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
D 4
	  (((j=(ch = getch() & CMASK) - '0') >= 0) && (j <= 9))){
E 4
I 4
	  (((j=((ch = getch()) & CMASK) - '0') >= 0) && (j <= 9))){
E 4
		if(i == '-')j = -j;
		ch = 0;
		casps1(apts+j);
		return;
	}
D 5
	if((i -= '0') == 0){
E 5
I 5
	if(i == '0'){
E 5
		casps1(apts1);
		return;
	}
D 5
	if((i > 0) && (i <= 9)){
D 4
		if(((j=(ch = getch() & CMASK) - '0') >= 0) && (j <= 9)){
E 4
I 4
		if(((j=((ch = getch()) & CMASK) - '0') >= 0) && (j <= 9)){
E 5
I 5
	if((i > '0') && (i <= '9')){
		i -= '0';
		if((i <= 3) &&
		  ((j=((ch = getch()) & CMASK) - '0') >= 0) && (j <= 9)){
E 5
E 4
			i = 10*i +j;
			ch = 0;
		}
I 5
		casps1(i);
	} else {
		noscale++;
		i = inumb(&apts);
		noscale = 0;
		getch();	/* eat other delim */
		if(nonumb)return;
E 5
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

I 27
	j = (i>>16) & 0x1F;
	k = fontab[j]->flags;
	if (!(k & FONTINFO_FLAGS_ROMAN) || (k & FONTINFO_FLAGS_NOLIG))
		return(i);

E 27
	switch((j = getch0()) & CMASK){
I 15
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
E 15
		case 'l':
			j = 0x8B;
			break;
		case 'i':
			j = 0x8A;
			break;
		default:
I 15
		nope:
E 15
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
D 29
/* UNIMPLEMENTED */
E 29
I 29
	register i, j, k;

	k = 0;
bd0:
D 32
	if(skip() || !(i = getrq()) || ((j = find(i,fontlab)) == -1))
E 32
I 32
D 33
	if(skip() || !(i = getrq()))
E 33
I 33
	if(skip() || !(i = getrq())) {
		/*
		 * In the original troff code implementation,
		 * a bare ".bd S" cancels all .bd S f x settings.
		 */
		if (k)
			bzero(bdstab, sizeof bdstab);
E 33
E 32
		return;
I 33
	}
E 33
D 32
	if(j == 'S'){
E 32
I 32
	if(i == 'S'){
E 32
		k = 1;
		goto bd0;
	}
I 32
	if((j = find(i,fontlab)) == -1)
		return;
E 32
	skip();
	noscale++;
	i = atoi();
	noscale = 0;
	if (k)
		bdstab[j] = i;
D 30
	else
E 30
I 30
	else {
E 30
		bdtab[j] = i;
I 30
		if (j == font)
			mchbits();
I 31
D 34
	}
	if (bd_s_warn) {
		k++;
		if (i)
			bdswarn[j] |= k;
		else
			bdswarn[j] &= ~k;
E 34
E 31
	}
E 30
E 29
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
D 13
	register i;

E 13
	noscale++;
	skip();
D 13
	if(i = atoi()){
		spacesz = i& 0177;
		sps = width(' ' | chbits);
	}
E 13
I 13
	spacesz = atoi();
I 16
D 26
	if (nonumb)
E 26
I 26
	if (nonumb) {
E 26
		spacesz = SS;
I 26
		spacesz_cw_ovr = 0;
	} else if (getach() == 'o')	/* stands for "override" */
		spacesz_cw_ovr = 1;
	else
		spacesz_cw_ovr = 0;
E 26
E 16
	sps = width(' ' | chbits);
E 13
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
D 7
	ch0 = ((j & 03700)<<3) | HX;
	if(i < 0)ch0 |= 040000;
	return(((j & 077)<<9) | LX);
E 7
I 7
	j = (j << 9) | XLSS;
	if(i < 0)j |= 0x40000000;
	return(j);
E 7
}
E 1
