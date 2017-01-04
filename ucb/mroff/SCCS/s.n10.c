h48089
s 00003/00002/00295
d D 5.6 04/10/24 21:24:57 msokolov 6 5
c oops, the 7-bit terminal table conversion was busted
e
s 00003/00002/00294
d D 5.5 04/10/24 20:26:01 msokolov 5 4
c use done3() for initialization errors
e
s 00001/00000/00295
d D 5.4 04/09/17 08:44:19 msokolov 4 3
c broke down and added baseline rule to the line drawing chars
e
s 00026/00008/00269
d D 5.3 04/09/16 07:46:18 msokolov 3 2
c implement conversion of 7-bit terminal tables if they support our extended
c character set
e
s 00001/00001/00276
d D 5.2 04/09/13 03:00:43 msokolov 2 1
c don't emit a "bold backspace" as 3 backspaces
e
s 00277/00000/00000
d D 5.1 04/09/08 16:41:55 msokolov 1 0
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
#include <sgtty.h>
extern
#include "d.h"
extern
#include "v.h"
extern
#include "tw.h"
/*
nroff10.c

Device interfaces
*/

extern int lss;
extern char obuf[];
extern char *obufp;
extern int xfont;
extern int esc;
extern int lead;
extern int oline[];
extern int *olinep;
extern int ulfont;
extern int esct;
extern int sps;
extern int ics;
extern int ttysave;
extern struct sgttyb ttys;
extern char termtab[];
extern int ptid;
extern int waitf;
extern int pipeflg;
extern int eqflg;
extern int hflg;
extern int tabtab[];
extern int ascii;
extern int xxx;
int dtab;
int bdmode;
int plotmode;

ptinit(){
	register i, j;
	register char **p;
	char *q;
	int x[8];
	extern char *setbrk();

	if((i=open(termtab,0)) < 0){
		prstr("Cannot open ");
		prstr(termtab);
		prstr("\n");
D 5
		exit(-1);
E 5
I 5
		t.twrest = "";
		done3(-1);
E 5
	}
	read(i,(char *)x,8*sizeof(int));
	read(i,(char *)&t.magic,j = sizeof(int)*((int *)&t.zzz - &t.magic));
	if (t.magic != 0x6E380000) {
D 3
		/* terminal table for the old troff character set */
		/* needs conversion */
		/* not implemented yet */
		prstr(termtab);
		prstr(" is an old nroff terminal table\n");
		prstr("automatic conversion not implemented yet\n");
		exit(-1);
E 3
I 3
		/* table for a 7-bit terminal */
		/* see if it has the extra entries for rendering */
		/* our extended character set */
		lseek(i,(long)(8*sizeof(int)),0);
		read(i,(char *)&t.bset,
			j = sizeof(int)*((int *)&t.codetab[228] - &t.bset));
		if ((u_long)t.codetab[224] != 0xE8455854) {
			prstr(termtab);
			prstr(" doesn't support our character set\n");
D 5
			exit(-1);
E 5
I 5
			done3(-1);
E 5
		}
		/* it does support our character set, shuffle it around */
D 6
		for (i = 0; i < 32; i++)
			t.codetab[0x100+i] = t.codetab[0x180+i] = "\0";
E 6
I 6
		for (j = 0; j < 32; j++)
			t.codetab[0x100+j] = t.codetab[0x180+j] = "\0";
E 6
I 4
		t.codetab[BASRULE] = t.codetab[0204-32];
E 4
		t.codetab[UNDRULE] = t.codetab[225];
		t.codetab[OVRRULE] = t.codetab[226];
		t.codetab[BOXRULE] = t.codetab[227];
		t.codetab[CFMINUS] = t.codetab[0210-32];
		t.codetab[NARSP] = t.codetab[0177-32];
		t.codetab[HNSP] = t.codetab[0226-32];
		bcopy(t.codetab, t.codetab + 32, sizeof(char*) * 96);
		read(i, (char *)t.codetab, sizeof(char*) * 32);
		read(i, (char *)&t.codetab[0x80], sizeof(char*) * 128);
		read(i, (char *)&t.codetab[0x120], sizeof(char*) * 96);
		read(i, (char *)&t.codetab[0x1A0], sizeof(char*) * 96);
E 3
	}
D 3
	x[2] -= j;
E 3
I 3
	x[2] -= (int) t.twinit;
E 3
	q = setbrk(x[2]);
	lseek(i,(long)t.twinit+8*sizeof(int),0);
	i = read(i,q,x[2]);
I 6
	close(i);
E 6
	j = q - t.twinit;
	for(p = &t.twinit; p < &t.zzz; p++){
		if(*p)*p += j;else *p = "";
	}
	sps = EM;
	ics = EM*2;
	dtab = 8 * t.Em;
	for(i=0; i<16; i++)tabtab[i] = dtab * (i+1);
	if(eqflg)t.Adj = t.Hor;
}
twdone(){
	obufp = obuf;
	oputs(t.twrest);
	flusho();
	if(pipeflg){
		close(ptid);
		wait(&waitf);
	}
	if(ttysave != -1) {
		ttys.sg_flags = ttysave;
		stty(1, &ttys);
	}
}
ptout(i)
int i;
{
	*olinep++ = i;
	if(olinep >= &oline[LNSIZE])olinep--;
	if((i&CMASK) != '\n')return;
	olinep--;
	lead += dip->blss + lss - t.Newline;
	dip->blss = 0;
	esct = esc = 0;
	if(olinep>oline){
		move();
		ptout1();
		oputs(t.twnl);
	}else{
		lead += t.Newline;
		move();
	}
	lead += dip->alss;
	dip->alss = 0;
	olinep = oline;
}
ptout1()
{
	register i, k;
	register char *codep;
	extern char *plot();
	int *q, w, j, phyw;

	for(q=oline; q<olinep; q++){
	if((i = *q) & MOT){
		j = i & ~MOTV;
		if(i & NMOT)j = -j;
		if(i & VMOT)lead += j;
		else esc += j;
		continue;
	}
	if((k = (i & CMASK)) == 040){
		esc += t.Char;
		continue;
	}
	codep = t.codetab[k];
	w = t.Char * (*codep++ & 0177);
	phyw = w;
	if(i&ZBIT)w = 0;
	if(*codep && (esc || lead))move();
	esct += w;
	xfont = (i>>16) & 03;
	if(*t.bdon & 0377){
		if(!bdmode && (xfont == 2)){
			oputs(t.bdon);
			bdmode++;
		}
		if(bdmode && (xfont != 2)){
			oputs(t.bdoff);
			bdmode = 0;
		}
	}

	if(xfont == ulfont){
		for(k=w/t.Char;k>0;k--)oput('_');
		for(k=w/t.Char;k>0;k--)oput('\b');
	}
	while(k = *codep & 0377){
		if(k & 0200){
			if (t.magic == 0x6E380000 && k != 0200)
				goto char8;
			codep = plot(codep);
			oputs(t.plotoff);
			oput(' ');
		}else{
char8:			if(plotmode)oputs(t.plotoff);
			/*
			 * simulate bold font as overstrike if no t.bdon
			 */
D 2
			if (xfont == 2 && !(*t.bdon & 0377)) {
E 2
I 2
			if (xfont == 2 && !(*t.bdon & 0377) && k != '\b') {
E 2
				oput(k);
				oput('\b');
			}
			*obufp++ = k;
			if(obufp == (obuf + OBUFSZ))flusho();
/*			oput(k);*/
			codep++;
		}
	}
	if(!w)for(k=phyw/t.Char;k>0;k--)oput('\b');
	}
}
char *plot(x)
char *x;
{
	register int i;
	register char *j, *k;

	if(!plotmode)oputs(t.ploton);
	k = x;
	if((*k & 0377) == 0200)k++;
	for(; *k; k++){
		if(*k & 0200){
			if(*k & 0100){
				if(*k & 040)j = t.up; else j = t.down;
			}else{
				if(*k & 040)j = t.left; else j = t.right;
			}
			if(!(i = *k & 037))return(++k);
			while(i--)oputs(j);
		}else oput(*k);
	}
	return(k);
}
move(){
	register k;
	register char *i, *j;
	char *p, *q;
	int iesct, dt;

	iesct = esct;
	if(esct += esc)i = "\0"; else i = "\n\0";
	j = t.hlf;
	p = t.right;
	q = t.down;
	if(lead){
		if(lead < 0){
			lead = -lead;
			i = t.flr;
		/*	if(!esct)i = t.flr; else i = "\0";*/
			j = t.hlr;
			q = t.up;
		}
		if(*i & 0377){
			k = lead/t.Newline;
			lead = lead%t.Newline;
			while(k--)oputs(i);
		}
		if(*j & 0377){
			k = lead/t.Halfline;
			lead = lead%t.Halfline;
			while(k--)oputs(j);
		}
		else { /* no half-line forward, not at line begining */
			k = lead/t.Newline;
			lead = lead%t.Newline;
			if (k>0) esc=esct;
			i = "\n";
			while (k--) oputs(i);
		}
	}
	if(esc){
		if(esc < 0){
			esc = -esc;
			j = "\b";
			p = t.left;
		}else{
			j = " ";
			if(hflg)while((dt = dtab - (iesct%dtab)) <= esc){
				if(dt%t.Em || dt==t.Em)break;
				oput(TAB);
				esc -= dt;
				iesct += dt;
			}
		}
		k = esc/t.Em;
		esc = esc%t.Em;
		while(k--)oputs(j);
	}
	if((*t.ploton & 0377) && (esc || lead)){
		if(!plotmode)oputs(t.ploton);
		esc /= t.Hor;
		lead /= t.Vert;
		while(esc--)oputs(p);
		while(lead--)oputs(q);
		oputs(t.plotoff);
	}
	esc = lead = 0;
}
dostop(){
	char junk;

	flusho();
	read(2,&junk,1);
}
E 1
