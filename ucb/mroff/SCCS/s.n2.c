h59445
s 00002/00002/00285
d D 5.7 2012/07/22 09:43:23 msokolov 7 6
c bugfix in the bd_warn_check logic
e
s 00009/00016/00278
d D 5.6 2012/07/22 02:52:28 msokolov 6 5
c .bd S warning mechanism split out so it would work with -z
e
s 00018/00014/00276
d D 5.5 2012/07/15 03:18:28 msokolov 5 4
c troff: named char handling converted to LUT, Cyrillic support added
e
s 00003/00003/00287
d D 5.4 2012/03/04 02:06:15 msokolov 4 3
c tr handles the full 512-char set now
e
s 00001/00001/00289
d D 5.3 04/09/21 22:22:35 msokolov 3 2
c do not translate through trtab in transparent mode
e
s 00004/00009/00286
d D 5.2 04/09/15 07:03:38 msokolov 2 1
c replace the LX/HX pair of 16-bit metacharacters with one 32-bit metacharacter
e
s 00295/00000/00000
d D 5.1 04/09/08 16:41:55 msokolov 1 0
c first working version
e
u
U
t
T
I 1
#ifndef lint
D 6
static char sccsid[] = "%W% (Berkeley) %G%";
E 6
I 6
static char sccsid[] = "%W% (Berkeley) %E%";
E 6
#endif lint

#include "tdef.h"
#include <sgtty.h>
extern
#include "d.h"
extern
#include "v.h"
#ifdef NROFF
extern
#include "tw.h"
#endif
#include "sdef.h"
#include <setjmp.h>
jmp_buf sjbuf;

/*
troff2.c

output, cleanup
*/

extern struct s *frame, *stk, *nxf;
extern filep ip;
extern filep offset;
extern char *enda;


extern char obuf[OBUFSZ];
extern char *obufp;
extern int dilev;
extern int eschar;
D 2
extern int tlss;
E 2
extern int tflg;
extern int ascii;
extern int print;
D 4
extern char trtab[];
E 4
I 4
extern u_short trtab[];
E 4
extern int waitf;
extern char ptname[];
extern int ptid;
extern int em;
extern int ds;
extern int mflg;
extern filep woff;
extern int nflush;
extern int lgf;
extern int app;
extern int nfo;
extern int donef;
extern int *pendw;
extern int nofeed;
extern int trap;
extern struct sgttyb ttys;
extern int ttysave;
extern int quiet;
extern int pendnf;
extern int ndone;
extern int lead;
extern int ralss;
extern int paper;
extern char *unlkp;
extern char nextf[];
extern int pipeflg;
extern int ejf;
extern int no_out;
extern int level;
extern int stopmesg;
extern int xxx;
int toolate;
int error;
#ifndef NROFF
D 6
extern int acctf;
E 6
I 6
extern int bd_s_warn;
E 6
#endif

pchar(c)
int c;
{
	register i, j;

	if((i=c) & MOT){pchar1(i); return;}
	switch(j = i & CMASK){
		case 0:
		case IMP:
		case RIGHT:
		case LEFT:
			return;
D 2
		case HX:
			j = (tlss>>9) | ((i&~0777)>>3);
			if(i & 040000){
				j &= ~(040000>>3);
E 2
I 2
		case XLSS:
			j = i >> 9;
			if(i & 0x40000000){
				j &= ~(0x40000000>>9);
E 2
				if(j > dip->blss)dip->blss = j;
			}else{
				if(j > dip->alss)dip->alss = j;
				ralss = dip->alss;
			}
D 2
			tlss = 0;
			return;
		case LX:
			tlss = i;
E 2
			return;
		case PRESC:
			if(dip == &d[0])j = eschar;
		default:
D 3
			if (!(j & 0x100))
E 3
I 3
D 4
			if (!tflg && !(j & 0x100))
E 3
				i = (trtab[j] & BMASK) | (i & ~CMASK);
E 4
I 4
			if (!tflg && !is_xinfo_char(j))
				i = trtab[j] | (i & ~CMASK);
E 4
	}
	pchar1(i);
}
pchar1(c)
int c;
{
D 5
	register i, j, *k;
	extern int chtab[];
E 5
I 5
	register i, j;
E 5

	j = (i = c) & CMASK;
	if(dip != &d[0]){
		wbf(i);
		dip->op = offset;
		return;
	}
	if(!tflg && !print){
		if(j == '\n')dip->alss = dip->blss = 0;
		return;
	}
I 6
#ifndef NROFF
D 7
	if (bd_s_warn)
		bd_warn_check(j);
E 7
I 7
	if (bd_s_warn && !(i & MOT))
		bd_warn_check(i);
E 7
#endif
E 6
	if(no_out || (j == FILLER))return;
#ifndef NROFF
	if(ascii){
I 5
D 6
		extern u_short chlut[];
E 6
I 6
		extern char *debug_char_name();
E 6

E 5
		if(i & MOT){
			oput(' ');
			return;
		}
D 5
		if (j == 0x8A) {
E 5
I 5
		switch (j) {
		case 0x8A:
E 5
			oputs("fi");
			return;
D 5
		}
		if (j == 0x8B) {
E 5
I 5
		case 0x8B:
E 5
			oputs("fl");
			return;
I 5
D 6
		case CFMINUS:
			oput('-');
			return;
E 6
E 5
		}
D 5
		if(j < 0x100){
E 5
I 5
D 6
		if(j >= 0x20 && j <= 0x7E || j >= 0xA0 && j <= 0xFF){
E 6
I 6
		if(j >= 0x20 && j <= 0x7E){
E 6
E 5
			oput(i);
			return;
		}
D 5
		if (j == CFMINUS) {
			oput('-');
			return;
		}
		for(k=chtab; *++k != j; k++)
			if(*k == 0)return;
E 5
I 5
D 6
		for (i = 0; i < 94*94; i++)
			if (chlut[i] == j)
				goto chlut_out;
E 6
I 6
		oputs(debug_char_name(j));
E 6
		return;
D 6
chlut_out:	j = i / 94;
		i -= j * 94;
E 5
		oput('\\');
		oput('(');
D 5
		oput(*--k & BMASK);
		oput(*k >> BYTE);
E 5
I 5
		oput(j + '!');
		oput(i + '!');
E 6
E 5
	}else
#endif
	ptout(i);
}
oput(i)
char i;
{
	*obufp++ = i;
	if(obufp == (obuf + OBUFSZ))flusho();
}
oputs(i)
char *i;
{
	while(*i != 0)oput(*i++);
}
flusho(){
	if(no_out == 0){
		if (!toolate) {
			toolate++;
#ifdef NROFF
			if(t.bset || t.breset){
				if(ttysave == -1) {
					gtty(1, &ttys);
					ttysave = ttys.sg_flags;
				}
				ttys.sg_flags &= ~t.breset;
				ttys.sg_flags |= t.bset;
				stty(1, &ttys);
			}
			{
			char *p = t.twinit;
			while (*p++)
				;
			write(ptid, t.twinit, p-t.twinit-1);
			}
#endif
		}
		toolate += write(ptid, obuf, obufp-obuf);
	}
	obufp = obuf;
}
done(x) int x;{
	register i;

	error |= x;
	level = 0;
	app = ds = lgf = 0;
	if(i=em){
		donef = -1;
		em = 0;
		if(control(i,0))longjmp(sjbuf,1);
	}
	if(!nfo)done3(0);
	mflg = 0;
	dip = &d[0];
	if(woff)wbt(0);
	if(pendw)getword(1);
	pendnf = 0;
	if(donef == 1)done1(0);
	donef = 1;
	ip = 0;
	frame = stk;
	nxf = frame + 1;
	if(!ejf)tbreak();
	nflush++;
	eject((struct s *)0);
	longjmp(sjbuf,1);
}
done1(x) int x; {
	error |= x;
	if(v.nl){
		trap = 0;
		eject((struct s *)0);
		longjmp(sjbuf,1);
	}
	done2(0);
}
done2(x) int x; {
	register i;

#ifndef NROFF
	if(!ascii){
		PS_close_page();
		PS_emit_trailer();
	}
#endif
#ifdef NROFF
	move();
#endif
	flusho();
	done3(x);
}
done3(x) int x;{
	error |= x;
	signal(SIGINT, SIG_IGN);
	signal(SIGTERM, SIG_IGN);
	unlink(unlkp);
#ifdef NROFF
	twdone();
#endif
	if(quiet){
		ttys.sg_flags |= ECHO;
		stty(0, &ttys);
	}
	if(ascii)mesg(1);
	exit(error);
}
edone(x) int x;{
	frame = stk;
	nxf = frame + 1;
	ip = 0;
	done(x);
}
#ifdef NROFF
casepi(){
	register i;
	int id[2];

	if(toolate || skip() || !getname() || (pipe(id) == -1) ||
	   ((i=fork()) == -1)){
		prstr("Pipe not created.\n");
		return;
	}
	ptid = id[1];
	if(i>0){
		close(id[0]);
		toolate++;
		pipeflg++;
		return;
	}
	close(0);
	dup(id[0]);
	close(id[1]);
	execl(nextf,nextf,0);
	prstr("Cannot exec: ");
	prstr(nextf);
	prstr("\n");
	exit(-4);
}
#endif
E 1
