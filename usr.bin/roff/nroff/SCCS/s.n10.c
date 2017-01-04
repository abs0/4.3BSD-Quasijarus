h46233
s 00023/00002/00268
d D 4.5 04/10/24 21:07:50 msokolov 5 4
c exec nroff8 if an 8-bit terminal table is used
c if the user-specified table can't be opened, complain, don't silently switch
c to the default
c minor fixes
e
s 00001/00001/00269
d D 4.4 04/09/13 02:58:34 msokolov 4 3
c don't emit a "bold backspace" as 3 backspaces
e
s 00008/00000/00262
d D 4.3 88/04/27 19:27:49 marc 3 2
c Simulate bold font as overstrike if no bold-on sequence
e
s 00001/00001/00261
d D 4.2 85/04/17 21:43:45 karels 2 1
c don't replace single spaces with tabs
e
s 00262/00000/00000
d D 4.1 82/06/07 15:45:07 rrh 1 0
c date and time created 82/06/07 15:45:07 by rrh
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% %G%";
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

D 5
	if(((i=open(termtab,0)) < 0) && (i=open("/usr/lib/term/tablpr",0)) < 0){
E 5
I 5
	if((i=open(termtab,0)) < 0){
E 5
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
	read(i,(char *)&t.bset,j = sizeof(int)*((int *)&t.zzz - &t.bset));
I 5
	if ((int)t.bset == 0x6E380000) {
		/* This is an 8-bit terminal table, exec nroff8 */
		extern int ibf;
		extern char *unlkp;
		extern int saved_argc;
		extern char **saved_argv;
		static char nroff8[] = "/usr/ucb/nroff8";

		close(i);
		/* close and delete the temp file, nroff8 will have its own */
		close(ibf);
		unlink(unlkp);
		mesg(1);	/* can't pass saved mode to nroff8 */
		execv(nroff8, saved_argv);
		prstr("Cannot exec ");
		prstr(nroff8);
		prstr("\n");
		exit(-1);
	}
E 5
	x[2] -= j;
	q = setbrk(x[2]);
	lseek(i,(long)t.twinit+8*sizeof(int),0);
	i = read(i,q,x[2]);
I 5
	close(i);
E 5
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
	if((k = (i & CMASK)) <= 040){
		switch(k){
			case ' ': /*space*/
				esc += t.Char;
				break;
		}
		continue;
	}
	codep = t.codetab[k-32];
	w = t.Char * (*codep++ & 0177);
	phyw = w;
	if(i&ZBIT)w = 0;
	if(*codep && (esc || lead))move();
	esct += w;
	if(i&074000)xfont = (i>>9) & 03;
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
I 3

E 3
	if(xfont == ulfont){
		for(k=w/t.Char;k>0;k--)oput('_');
		for(k=w/t.Char;k>0;k--)oput('\b');
	}
	while(*codep != 0){
		if(*codep & 0200){
			codep = plot(codep);
			oputs(t.plotoff);
			oput(' ');
		}else{
			if(plotmode)oputs(t.plotoff);
I 3
			/*
			 * simulate bold font as overstrike if no t.bdon
			 */
D 4
			if (xfont == 2 && !(*t.bdon & 0377)) {
E 4
I 4
			if (xfont == 2 && !(*t.bdon & 0377) && *codep != '\b') {
E 4
				oput(*codep);
				oput('\b');
			}
E 3
			*obufp++ = *codep++;
			if(obufp == (obuf + OBUFSZ + ascii - 1))flusho();
/*			oput(*codep++);*/
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
D 2
				if(dt%t.Em)break;
E 2
I 2
				if(dt%t.Em || dt==t.Em)break;
E 2
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
ptlead(){move();}
dostop(){
	char junk;

	flusho();
	read(2,&junk,1);
}
E 1
