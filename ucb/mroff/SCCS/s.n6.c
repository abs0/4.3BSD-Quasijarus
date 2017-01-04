h50995
s 00002/00003/00279
d D 5.4 2012/03/04 02:06:18 msokolov 4 3
c tr handles the full 512-char set now
e
s 00018/00007/00264
d D 5.3 2012/02/16 03:29:20 msokolov 3 2
c setch() binary search
e
s 00003/00003/00268
d D 5.2 04/09/15 07:03:39 msokolov 2 1
c replace the LX/HX pair of 16-bit metacharacters with one 32-bit metacharacter
e
s 00271/00000/00000
d D 5.1 04/09/08 16:41:58 msokolov 1 0
c first working version
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif lint

#include "tdef.h"
extern
#include "d.h"
extern
#include "v.h"
#ifdef NROFF
extern
#include "tw.h"
#endif

/*
troff6.c

width functions, sizes and fonts
*/

extern  int     inchar[LNSIZE], *pinchar;       /* XXX */
extern int eschar;
extern int widthp;
extern int ohc;
extern int xfont;
extern int smnt;
extern int setwdf;
D 4
extern char trtab[];
E 4
I 4
extern u_short trtab[];
E 4
extern int chbits;
extern int nonumb;
extern int noscale;
extern int font;
extern int font1;
extern int pts;
extern int sps;
extern int nlflg;
extern int nform;
extern int dfact;
extern int dfactd;
extern int lss;
extern int lss1;
extern int vflag;
extern int ch0;
extern int level;
extern int ch;
extern int res;
extern int xxx;
int fontlab[] = {'R','I','B','S',0};

width(c)
int c;
{
	register i,j,k;

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
	if(j & ZBIT)goto rtn;
D 4
	if (!(i & 0x100))
		i = trtab[i] & BMASK;
E 4
I 4
	i = trtab[i];
E 4
	if (t.codetab[i])
		k = (*(t.codetab[i]) & 0177) * t.Char;
	else
		k = 0;
	widthp = k;
rtn:
	return(k);
}
D 3
setch(){
	register i,*j,k;
	extern int chtab[];
E 3
I 3
setch()
{
	extern int chtab[], chtab_len;
	register int *base = chtab, *p;
	register int key, lim;
E 3

D 3
	if((i = getrq()) == 0)return(0);
	for(j=chtab;*j != i;j++)if(*(j++) == 0)return(0);
	k = *(++j) | chbits;
	return(k);
E 3
I 3
	if ((key = getrq()) == 0)
		return (0);
	/* binary search */
	for (lim = chtab_len; lim != 0; lim >>= 1) {
		p = base + (lim & ~1);
		if (*p == key)
			return (p[1] | chbits);
		if (key > *p) {	/* move right */
			base = p + 2;
			lim--;
		}		/* else move left */
	}
	return (0);
E 3
}
find(i,j)
int i,j[];
{
	register k;

	if(((k = i-'0') >= 1) && (k <= 4) && (k != smnt))return(--k);
	for(k=0; j[k] != i; k++)if(j[k] == 0)return(-1);
	return(k);
}
mchbits(){
	chbits = (((pts)<<5) | font) << 16;
	sps = width(' ' | chbits);
}
setps(){
	register i,j;

	if((((i=getch() & CMASK) == '+')  || (i == '-')) &&
	  (((j=(ch = getch() & CMASK) - '0') >= 0) && (j <= 9))){
		ch = 0;
		return;
	}
	if((i -= '0') == 0){
		return;
	}
	if((i > 0) && (i <= 9)){
		if((i <= 3) &&
		  ((j=(ch = getch() & CMASK) - '0') >= 0) && (j <= 9)){
			i = 10*i +j;
			ch = 0;
		}
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
	if(i == 'S')return;
	if((j = find(i,fontlab))  == -1)return;
s0:
	font1 = font;
	font = j;
	mchbits();
}
setwd(){
	register i, base, wid;
	int delim, em, k;
	int savlevel, savhp, savfont, savfont1;
	int *savpinchar, *p, *q, tempinchar[LNSIZE];	/* XXX */

	base = v.st = v.sb = wid = v.ct = 0;
	if((delim = getch() & CMASK) & MOT)return;
	savhp = v.hp;
	savpinchar = pinchar;	/* XXX */
	for (p=inchar, q=tempinchar; p < pinchar; )	/* XXX */
		*q++ = *p++;	/* XXX */
	pinchar = inchar;	/* XXX */
	savlevel = level;
	v.hp = level = 0;
	savfont = font;
	savfont1 = font1;
	setwdf++;
	while((((i = getch()) & CMASK) != delim) && !nlflg){
		wid += width(i);
		if(!(i & MOT)){
			em = 2*t.Halfline;
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
	pinchar = savpinchar;	/* XXX */
	for (p=inchar, q=tempinchar; p < pinchar; )	/* XXX */
		*p++ = *q++;	/* XXX */
	level = savlevel;
	font = savfont;
	font1 = savfont1;
	mchbits();
	setwdf = 0;
}
vmot(){
	dfact = lss;
	vflag++;
	return(mot());
}
hmot(){
	dfact = EM;
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

	i = t.Halfline;
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
casevs(){
	register i;

	skip();
	vflag++;
	dfact = INCH; /*default scaling is points!*/
	dfactd = 72;
	res = VERT;
	i = inumb(&lss);
	if(nonumb)i = lss1;
	if(i < VERT)i = VERT;
	lss1 = lss;
	lss = i;
}
xlss(){
	register i, j;

	getch();
	dfact = lss;
	i = quant(atoi(),VERT);
	dfact = 1;
	getch();
	if((j = i) < 0)j = -j;
D 2
	ch0 = ((j & 03700)<<3) | HX;
	if(i < 0)ch0 |= 040000;
	return(((j & 077)<<9) | LX);
E 2
I 2
	j = (j << 9) | XLSS;
	if(i < 0)j |= 0x40000000;
	return(j);
E 2
}
casefz(){}
caseps(){}
caselg(){}
casecs(){}
casebd(){}
casess(){}
getlg(i)
int i;
{
	return(i);
}
E 1
