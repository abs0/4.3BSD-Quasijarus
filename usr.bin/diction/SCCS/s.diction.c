h28769
s 00181/00044/00354
d D 4.2 82/11/06 14:32:50 rrh 2 1
c Bill Jolitz @ Berkeley received this version from Lorindia Cherry
c around September 1981, as the ``most recent version''.  Deltas 
c seem to be progressive, rather than regressive, although the BTL sid for
c deroff.c is retrograde; this is probably a case of parallel development
e
s 00398/00000/00000
d D 4.1 82/11/06 13:47:41 rrh 1 0
c Oldest available version at Berkeley
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W%	(Berkeley)	%E%";
#endif not lint

/*
D 2
* diction -- print all sentences containing one of default phrases
E 2
I 2
 * diction -- print all sentences containing one of default phrases
E 2
 *
 *	status returns:
 *		0 - ok, and some matches
 *		1 - ok, but no matches
 *		2 - some error
 */

#include <stdio.h>
#include <ctype.h>

#define	MAXSIZ 6500
#define QSIZE 650
I 2
int linemsg;
long olcount;
long lcount;
E 2
struct words {
	char 	inp;
	char	out;
	struct	words *nst;
	struct	words *link;
	struct	words *fail;
} w[MAXSIZ], *smax, *q;

I 2
char table[128] = {
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, ' ', 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	' ', '.', ' ', ' ', ' ', ' ', ' ', ' ',
	' ', ' ', ' ', ' ', ' ', ' ', '.', ' ',
	'0', '1', '2', '3', '4', '5', '6', '7',
	'8', '9', ' ', ' ', ' ', ' ', ' ', '.',
	' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g',
	'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
	'p', 'q', 'r', 's', 't', 'u', 'v', 'w',
	'x', 'y', 'z', ' ', ' ', ' ', ' ', ' ',
	' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g',
	'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
	'p', 'q', 'r', 's', 't', 'u', 'v', 'w',
	'x', 'y', 'z', ' ', ' ', ' ', ' ', ' '
	};
int	caps = 0;
int	lineno = 0;
E 2
int fflag;
int nflag	= 1; /*use default file*/
char *filename;
I 2
int	mflg	= 0;	/*don't catch output*/
E 2
int	nfile;
int	nsucc;
long nsent = 0;
long nhits = 0;
char *nlp;
char *begp, *endp;
I 2
int beg, last;
char *myst;
int myct = 0;
E 2
int oct = 0;
FILE	*wordf;
I 2
FILE *mine;
E 2
char	*argptr;
I 2
long tl = 0;
long th = 0;
E 2

main(argc, argv)
D 2
char **argv;
E 2
I 2
char *argv[];
E 2
{
I 2
	int sv;
E 2
	while (--argc > 0 && (++argv)[0][0]=='-')
		switch (argv[0][1]) {

		case 'f':
			fflag++;
D 2
			filename = ++argv;
E 2
I 2
			filename = (++argv)[0];
E 2
			argc--;
			continue;

		case 'n':
			nflag = 0;
			continue;
		case 'd':
I 2
			mflg=0;
E 2
			continue;
I 2
		case 'c':
			caps++;
			continue;
		case 'l':
			lineno++;
			continue;
E 2
		default:
			fprintf(stderr, "diction: unknown flag\n");
			continue;
		}
out:
	if(nflag){
		wordf = fopen(DICT,"r");
		if(wordf == NULL){
			fprintf(stderr,"diction: can't open default dictionary\n");
			exit(2);
		}
	}
	else {
D 2
		wordf = fopen(*filename,"r");
E 2
I 2
		wordf = fopen(filename,"r");
E 2
		if(wordf == NULL){
			fprintf(stderr,"diction: can't open %s\n",filename);
			exit(2);
		}
	}

I 2
#ifdef CATCH
	if(fopen(CATCH,"r") != NULL)
		if((mine=fopen(CATCH,"a"))!=NULL)mflg=1;
#endif
#ifdef MACS
	if(caps){
		printf(".so ");
		printf(MACS);
		printf("\n");
	}
#endif
E 2
	cgotofn();
	cfail();
	nfile = argc;
	if (argc<=0) {
		execute((char *)NULL);
	}
	else while (--argc >= 0) {
		execute(*argv);
I 2
		if(lineno){
			printf("file %s: number of lines %ld number of phrases found %ld\n",
				*argv, lcount-1, nhits);
			tl += lcount-1;
			th += nhits;
			sv = lcount-1;
			lcount = nhits = 0;
		}
E 2
		argv++;
	}
D 2
	printf("number of sentences %ld number of hits %ld\n",nsent,nhits);
E 2
I 2
	if(mflg)fprintf(mine,"number of sentences %ld %ld number of hits %ld %ld\n",nsent,tl,nhits,th);
	if(!caps&& !lineno)printf("number of sentences %ld number of phrases found %ld\n",nsent,nhits);
	else if(tl != sv)
		 if(!caps)printf("totals: number of lines %ld number of phrases found %ld\n",tl,th);
E 2
	exit(nsucc == 0);
}

execute(file)
char *file;
{
	register char *p;
	register struct words *c;
	register ccount;
I 2
	int count1;
	char *beg1;
E 2
	struct words *savc;
	char *savp;
	int savct;
	int scr;
	char buf[1024];
	int f;
	int hit;
I 2
	last = 0;
E 2
	if (file) {
		if ((f = open(file, 0)) < 0) {
			fprintf(stderr, "diction: can't open %s\n", file);
			exit(2);
		}
	}
	else f = 0;
I 2
	lcount = olcount = 1;
	linemsg = 1;
E 2
	ccount = 0;
I 2
	count1 = -1;
E 2
	p = buf;
	nlp = p;
	c = w;
	oct = hit = 0;
D 2
	savc = savp = 0;
E 2
I 2
	savc = (struct words *) 0;
	savp = (char *) 0;
E 2
	for (;;) {
D 2
		if (--ccount <= 0) {
E 2
I 2
		if(--ccount <= 0) {
E 2
			if (p == &buf[1024]) p = buf;
			if (p > &buf[512]) {
				if ((ccount = read(f, p, &buf[1024] - p)) <= 0) break;
			}
			else if ((ccount = read(f, p, 512)) <= 0) break;
D 2
			convert(p,ccount);
E 2
I 2
			if(caps && (count1 > 0))
				fwrite(beg1,sizeof(*beg1),count1,stdout);
			count1 = ccount;
			beg1 = p;
E 2
		}
		if(p == &buf[1024])p=buf;
		nstate:
D 2
			if (c->inp == *p) {
E 2
I 2
			if (c->inp == table[*p]) {
E 2
				c = c->nst;
			}
			else if (c->link != 0) {
				c = c->link;
				goto nstate;
			}
			else {
				if(savp != 0){
					c=savc;
					p=savp;
					if(ccount > savct)ccount += savct;
					else ccount = savct;
D 2
					savc=savp=0;
E 2
I 2
					savc = (struct words *) 0;
					savp = (char *) 0;
E 2
					goto hadone;
				}
				c = c->fail;
				if (c==0) {
					c = w;
					istate:
D 2
					if (c->inp == *p) {
E 2
I 2
					if (c->inp == table[*p]) {
E 2
						c = c->nst;
					}
					else if (c->link != 0) {
						c = c->link;
						goto istate;
					}
				}
				else goto nstate;
			}
		if(c->out){
D 2
			if((c->inp == *(p+1)) && (c->nst != 0)){
E 2
I 2
			if((c->inp == table[*(p+1)]) && (c->nst != 0)){
E 2
				savp=p;
				savc=c;
				savct=ccount;
				goto cont;
			}
			else if(c->link != 0){
				savc=c;
				while((savc=savc->link)!= 0){
D 2
					if(savc->inp == *(p+1)){
E 2
I 2
					if(savc->inp == table[*(p+1)]){
E 2
						savp=p;
						savc=c;
						savct=ccount;
						goto cont;
					}
				}
			}
		hadone:
D 2
			savc=savp=0;
E 2
I 2
			savc = (struct words *) 0;
			savp = (char *) 0;
E 2
			if(c->out == (char)(0377)){
				c=w;
				goto nstate;
			}
			begp = p - (c->out);
			if(begp < &buf[0])begp = &buf[1024] - (&buf[0]-begp);
			endp=p;
I 2
			if(mflg){
				if(begp-20 < &buf[0]){
					myst = &buf[1024]-20;
					if(nlp < &buf[512])myst=nlp;
				}
				else myst = begp-20;
				if(myst < nlp)myst = nlp;
				beg = 0;
			}
E 2
			hit = 1;
			nhits++;
D 2
			if (*p++ == '.') {
E 2
I 2
			if(*p == '\n')lcount++;
			if (table[*p++] == '.') {
				linemsg = 1;
E 2
				if (--ccount <= 0) {
					if (p == &buf[1024]) p = buf;
					if (p > &buf[512]) {
						if ((ccount = read(f, p, &buf[1024] - p)) <= 0) break;
					}
					else if ((ccount = read(f, p, 512)) <= 0) break;
D 2
					convert(p,ccount);
E 2
I 2
					if(caps && (count1 > 0))
						fwrite(beg1,sizeof(*beg1),count1,stdout);
					count1=ccount;
					beg1=p;
E 2
				}
			}
	succeed:	nsucc = 1;
			{
				if (p <= nlp) {
D 2
					outc(&buf[1024]);
E 2
I 2
					outc(&buf[1024],file);
E 2
					nlp = buf;
				}
D 2
				outc(p);
E 2
I 2
				outc(p,file);
E 2
			}
I 2
			if(mflg)last=1;
E 2
	nomatch:
			nlp = p;
			c = w;
			begp = endp = 0;
			continue;
		}
	cont:
D 2
		if (*p++ == '.'){
E 2
I 2
		if(*p == '\n')lcount++;
		if (table[*p++] == '.'){
E 2
				if(hit){
					if(p <= nlp){
D 2
						outc(&buf[1024]);
E 2
I 2
						outc(&buf[1024],file);
E 2
						nlp = buf;
					}
D 2
					outc(p);
					putchar('\n'); putchar('\n');
E 2
I 2
					outc(p,file);
					if(!caps)printf("\n\n");
					if(mflg && last){putc('\n',mine);myct = 0;}
E 2
					}
I 2
				linemsg = 1;
				if(*p == '\n')olcount = lcount+1;
				else
					olcount=lcount;
				last = 0;
E 2
				hit = 0;
				oct = 0;
				nlp = p;
				c = w;
				begp = endp = 0;
I 2
				nsent++;
E 2
			}
	}
I 2
	if(caps && (count1 > 0))
		fwrite(beg1,sizeof(*beg1),count1,stdout);
E 2
	close(f);
}

getargc()
{
	register c;
	if (wordf){
		if((c=getc(wordf))==EOF){
			fclose(wordf);
			if(nflag && fflag){
				nflag=0;
D 2
				wordf=fopen(*filename,"r");
E 2
I 2
				wordf=fopen(filename,"r");
E 2
				if(wordf == NULL){
D 2
					fprintf("can't open %s\n",filename);
E 2
I 2
					fprintf("diction can't open %s\n",filename);
E 2
					exit(2);
				}
				return(getc(wordf));
			}
			else return(EOF);
		}
		else return(c);
	}
	if ((c = *argptr++) == '\0')
		return(EOF);
	return(c);
}

cgotofn() {
	register c;
	register struct words *s;
	register ct;
	int neg;

	s = smax = w;
	neg = ct = 0;
nword:	for(;;) {
		c = getargc();
		if(c == '~'){
			neg++;
			c = getargc();
		}
		if (c==EOF)
			return;
		if (c == '\n') {
			if(neg)s->out = 0377;
			else s->out = ct-1;
			neg = ct = 0;
			s = w;
		} else {
		loop:	if (s->inp == c) {
				s = s->nst;
				ct++;
				continue;
			}
			if (s->inp == 0) goto enter;
			if (s->link == 0) {
				if (smax >= &w[MAXSIZ - 1]) overflo();
				s->link = ++smax;
				s = smax;
				goto enter;
			}
			s = s->link;
			goto loop;
		}
	}

	enter:
	do {
		s->inp = c;
		ct++;
		if (smax >= &w[MAXSIZ - 1]) overflo();
		s->nst = ++smax;
		s = smax;
	} while ((c = getargc()) != '\n' && c!=EOF);
	if(neg)smax->out = 0377;
	else smax->out = ct-1;
	neg = ct = 0;
	s = w;
	if (c != EOF)
		goto nword;
}

overflo() {
	fprintf(stderr, "wordlist too large\n");
	exit(2);
}
cfail() {
	struct words *queue[QSIZE];
	struct words **front, **rear;
	struct words *state;
	int bstart;
	register char c;
	register struct words *s;
	s = w;
	front = rear = queue;
init:	if ((s->inp) != 0) {
		*rear++ = s->nst;
		if (rear >= &queue[QSIZE - 1]) overflo();
	}
	if ((s = s->link) != 0) {
		goto init;
	}

	while (rear!=front) {
		s = *front;
		if (front == &queue[QSIZE-1])
			front = queue;
		else front++;
	cloop:	if ((c = s->inp) != 0) {
			bstart=0;
			*rear = (q = s->nst);
			if (front < rear)
				if (rear >= &queue[QSIZE-1])
					if (front == queue) overflo();
					else rear = queue;
				else rear++;
			else
				if (++rear == front) overflo();
			state = s->fail;
		floop:	if (state == 0){ state = w;bstart=1;}
			if (state->inp == c) {
			qloop:	q->fail = state->nst;
				if ((state->nst)->out != 0 && q->out == 0) q->out = (state->nst)->out;
				if((q=q->link) != 0)goto qloop;
			}
			else if ((state = state->link) != 0)
				goto floop;
			else if(bstart==0){state=0; goto floop;}
		}
		if ((s = s->link) != 0)
			goto cloop;
	}
/*	for(s=w;s<=smax;s++)
		printf("s %d ch %c out %d nst %d link %d fail %d\n",s,
			s->inp,s->out,s->nst,s->link,s->fail);
*/
}
D 2
convert(p,ccount)
char *p;
{
	int ct;
	char *pt;
	for(pt=p,ct=ccount;--ct>=0;pt++){
		if(isupper(*pt))*pt=tolower(*pt);
		else if(isspace(*pt))*pt=' ';
		else if(*pt=='.' || *pt=='?'||*pt=='!'){
			*pt='.';
			nsent++;
		}
		else if(ispunct(*pt))*pt=' ';
	}
}
outc(addr)
E 2
I 2
outc(addr,file)
E 2
char *addr;
I 2
char *file;
E 2
{
I 2
	int inside;
E 2

I 2
	inside = 0;
	if(!caps && lineno && linemsg){
		printf("beginning line %ld",olcount);
		if(file != (char *)NULL)printf(" %s\n",file);
		else printf("\n");
		linemsg = 0;
	}
E 2
	while(nlp < addr){
D 2
		if(oct++ > 70 && *nlp == ' ' && nlp != begp && nlp != endp){
E 2
I 2
		if(!caps && oct > 60 && table[*nlp] == ' ' && nlp != begp && nlp != endp){
E 2
			oct=0;
			putchar('\n');
		}
		if(nlp == begp){
D 2
			putchar('[');
E 2
I 2
			if(caps)inside++;
			else {
				if( oct >45){putchar('\n');
					oct=0;
				}
				if( oct==0 || table[*nlp] != ' '){
					printf("*[");
					oct+=2;
				}
				else {printf(" *[");;
					oct+=3;
				}
			}
			if(mflg)putc('[',mine);
E 2
		}
D 2
		putchar(*nlp);
E 2
I 2
		if(inside){
			if(islower(*nlp))*nlp = toupper(*nlp);
		}
		else {
			if(!caps && *nlp == '\n')*nlp = ' ';
			if(*nlp == ' ' && oct==0);
			else if(!caps) {putchar(*nlp); oct++;}
		}
E 2
		if(nlp == endp){
D 2
			putchar(']');
E 2
I 2
			if(caps)
				inside= 0;
			else {
				if(*(nlp) != ' '){printf("]*");
					oct+=2;
				}
				else {printf("]* ");
					oct+=3;
				}
				if(oct >60){putchar('\n');
					oct=0;
				}
			}
			if(mflg)putc(']',mine);
			beg = 0;
		}
		if(mflg){
			if(nlp == myst)beg = 1;
			if(beg || last){
				putc(*nlp,mine);
				if(myct++ >= 72 || last == 20){
					putc('\n',mine);
					if(last == 20)last=myct=0;
					else myct=0;
				}
				if(last)last++;
			}
E 2
		}
		nlp++;
	}
}
E 1
