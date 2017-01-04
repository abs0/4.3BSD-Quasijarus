h02625
s 00015/00016/00444
d D 4.4 85/08/27 21:27:21 van 4 3
c fixed missing return value in "duplicate".  changed things that lint
c complained about
e
s 00041/00006/00419
d D 4.3 85/08/18 21:44:37 van 3 2
c added -E & -X flags from Walter Tichy's rcs diff3
e
s 00003/00001/00422
d D 4.2 83/08/11 20:32:25 sam 2 1
c standardize sccs keyword lines
e
s 00423/00000/00000
d D 4.1 83/02/10 21:00:47 shannon 1 0
c date and time created 83/02/10 21:00:47 by shannon
e
u
U
t
T
I 1
D 2
/*	%M%	%I%	%E%	*/
E 2
I 2
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif
E 2

#include <stdio.h>
D 3
#
E 3

/* diff3 - 3-way differential file comparison*/

D 3
/* diff3 [-e] d13 d23 f1 f2 f3 
E 3
I 3
/* diff3 [-ex3EX] d13 d23 f1 f2 f3 [m1 m3]
E 3
 *
 * d13 = diff report on f1 vs f3
 * d23 = diff report on f2 vs f3
 * f1, f2, f3 the 3 files
I 3
 * if changes in f1 overlap with changes in f3, m1 and m3 are used
 * to mark the overlaps; otherwise, the file names f1 and f3 are used
 * (only for options E and X).
E 3
*/

struct  range {int from,to; };
	/* from is first in range of changed lines
	 * to is last+1
	 * from=to=line after point of insertion
	* for added lines
	*/
struct diff {struct range old, new;};

#define NC 200
I 3
struct diff d13[NC];
struct diff d23[NC];
E 3
/* de is used to gather editing scripts,
 * that are later spewed out in reverse order.
 * its first element must be all zero
 * the "new" component of de contains line positions
 * or byte positions depending on when you look(!?)
I 3
 * array overlap indicates which sections in de correspond to
 * lines that are different in all three files.
E 3
*/
D 3
struct diff d13[NC];
struct diff d23[NC];
E 3
struct diff de[NC];
I 3
char overlap[NC];
int  overlapcnt =0;

E 3
char line[256];
FILE *fp[3];
D 4
int linct[3] = {0,0,0};
E 4
/*	the number of the last-read line in each file
 *	is kept in cline[0-2]
*/
int cline[3];
/*	the latest known correspondence between line
 *	numbers of the 3 files is stored in last[1-3]
*/
int last[4];
int eflag;
I 3
int oflag;      /* indicates whether to mark overlaps (-E or -X)*/
E 3
int debug  = 0;
I 3
char f1mark[40], f3mark[40]; /*markers for -E and -X*/
E 3

I 3

E 3
main(argc,argv)
char **argv;
{
	register i,m,n;
I 3
        eflag=0; oflag=0;
E 3
	if(*argv[1]=='-') {
		switch(argv[1][1]) {
		default:
			eflag = 3;
			break;
		case '3':
			eflag = 2;
			break;
		case 'x':
			eflag = 1;
I 3
                        break;
                case 'E':
                        eflag = 3;
                        oflag = 1;
                        break;
                case 'X':
                        oflag = eflag = 1;
                        break;
E 3
		}
		argv++;
		argc--;
	}
	if(argc<6) {
		fprintf(stderr,"diff3: arg count\n");
		exit(1);
	}
I 3
        if (oflag) { 
D 4
                sprintf(f1mark,"<<<<<<< %s",argc>=7?argv[6]:argv[3]);
                sprintf(f3mark,">>>>>>> %s",argc>=8?argv[7]:argv[5]);
E 4
I 4
                (void)sprintf(f1mark,"<<<<<<< %s",argc>=7?argv[6]:argv[3]);
                (void)sprintf(f3mark,">>>>>>> %s",argc>=8?argv[7]:argv[5]);
E 4
        }

E 3
	m = readin(argv[1],d13);
	n = readin(argv[2],d23);
	for(i=0;i<=2;i++)
		if((fp[i] = fopen(argv[i+3],"r")) == NULL) {
			printf("diff3: can't open %s\n",argv[i+3]);
			exit(1);
		}
	merge(m,n);
}

/*pick up the line numbers of allcahnges from
 * one change file
 * (this puts the numbers in a vector, which is not
 * strictly necessary, since the vector is processed
 * in one sequential pass. The vector could be optimized
 * out of existence)
*/

readin(name,dd)
char *name;
struct diff *dd;
{
	register i;
	int a,b,c,d;
	char kind;
	char *p;
	fp[0] = fopen(name,"r");
	for(i=0;getchange(fp[0]);i++) {
		if(i>=NC) {
			fprintf(stderr,"diff3: too many changes\n");
			exit(0);
		}
		p = line;
		a = b = number(&p);
		if(*p==',') {
			p++;
			b = number(&p);
		}
		kind = *p++;
		c = d = number(&p);
		if(*p==',') {
			p++;
			d = number(&p);
		}
		if(kind=='a')
			a++;
		if(kind=='d')
			c++;
		b++;
		d++;
		dd[i].old.from = a;
		dd[i].old.to = b;
		dd[i].new.from = c;
		dd[i].new.to = d;
	}
	dd[i].old.from = dd[i-1].old.to;
	dd[i].new.from = dd[i-1].new.to;
D 4
	fclose(fp[0]);
E 4
I 4
	(void)fclose(fp[0]);
E 4
	return(i);
}

number(lc)
char **lc;
{
	register nn;
	nn = 0;
	while(digit(**lc))
		nn = nn*10 + *(*lc)++ - '0';
	return(nn);
}

digit(c)
{
	return(c>='0'&&c<='9');
}

getchange(b)
FILE *b;
{
	while(getline(b))
		if(digit(line[0]))
			return(1);
	return(0);
}

getline(b)
FILE *b;
{
	register i, c;
	for(i=0;i<sizeof(line)-1;i++) {
		c = getc(b);
		if(c==EOF)
			break;
		line[i] = c;
		if(c=='\n') {
			line[++i] = 0;
			return(i);
		}
	}
	return(0);
}

merge(m1,m2)
{
	register struct diff *d1, *d2, *d3;
	int dup;
	int j;
	int t1,t2;
	d1 = d13;
	d2 = d23;
	j = 0;
	for(;(t1 = d1<d13+m1) | (t2 = d2<d23+m2);) {
		if(debug) {
			printf("%d,%d=%d,%d %d,%d=%d,%d\n",
			d1->old.from,d1->old.to,
			d1->new.from,d1->new.to,
			d2->old.from,d2->old.to,
			d2->new.from,d2->new.to);
		}
/*			first file is different from others*/
		if(!t2||t1&&d1->new.to < d2->new.from) {
/*			stuff peculiar to 1st file */
			if(eflag==0) {
				separate("1");
				change(1,&d1->old,0);
D 4
				keep(2,&d1->old,&d1->new);
E 4
I 4
				keep(2,&d1->new);
E 4
				change(3,&d1->new,0);
			}
			d1++;
			continue;
		}
/*			second file is different from others*/
		if(!t1||t2&&d2->new.to < d1->new.from) {
			if(eflag==0) {
				separate("2");
D 4
				keep(1,&d2->old,&d2->new);
E 4
I 4
				keep(1,&d2->new);
E 4
				change(2,&d2->old,0);
				change(3,&d2->new,0);
			}
			d2++;
			continue;
		}
/*			merge overlapping changes in first file
 *			this happens after extension see below*/
		if(d1+1<d13+m1 &&
		   d1->new.to>=d1[1].new.from) {
			d1[1].old.from = d1->old.from;
			d1[1].new.from = d1->new.from;
			d1++;
			continue;
		}
/*			merge overlapping changes in second*/
		if(d2+1<d23+m2 &&
		   d2->new.to>=d2[1].new.from) {
			d2[1].old.from = d2->old.from;
			d2[1].new.from = d2->new.from;
			d2++;
			continue;
		}
/*			stuff peculiar to third file or different in all*/
		if(d1->new.from==d2->new.from&&
		   d1->new.to==d2->new.to) {
			dup = duplicate(&d1->old,&d2->old);
/*				dup=0 means all files differ
 *				dup =1 meands files 1&2 identical*/
			if(eflag==0) {
				separate(dup?"3":"");
				change(1,&d1->old,dup);
				change(2,&d2->old,0);
				d3 = d1->old.to>d1->old.from?d1:d2;
				change(3,&d3->new,0);
			} else
				j = edit(d1,dup,j);
			d1++;
			d2++;
			continue;
		}
/*			overlapping changes from file1 & 2
 *			extend changes appropriately to
 *			make them coincide*/
		 if(d1->new.from<d2->new.from) {
			d2->old.from -= d2->new.from-d1->new.from;
			d2->new.from = d1->new.from;
		}
		else if(d2->new.from<d1->new.from) {
			d1->old.from -= d1->new.from-d2->new.from;
			d1->new.from = d2->new.from;
		}
		if(d1->new.to >d2->new.to) {
			d2->old.to += d1->new.to - d2->new.to;
			d2->new.to = d1->new.to;
		}
		else if(d2->new.to >d1->new.to) {
			d1->old.to += d2->new.to - d1->new.to;
			d1->new.to = d2->new.to;
		}
	}
	if(eflag)
		edscript(j);
}

separate(s)
char *s;
{
	printf("====%s\n",s);
}

/*	the range of ines rold.from thru rold.to in file i
 *	is to be changed. it is to be printed only if
 *	it does not duplicate something to be printed later
*/
change(i,rold,dup)
struct range *rold;
{
	printf("%d:",i);
	last[i] = rold->to;
	prange(rold);
	if(dup)
		return;
	if(debug)
		return;
	i--;
D 4
	skip(i,rold->from,(char *)0);
	skip(i,rold->to,"  ");
E 4
I 4
	(void)skip(i,rold->from,(char *)0);
	(void)skip(i,rold->to,"  ");
E 4
}

/*	print the range of line numbers, rold.from  thru rold.to
 *	as n1,n2 or n1
*/
prange(rold)
struct range *rold;
{
	if(rold->to<=rold->from)
		printf("%da\n",rold->from-1);
	else {
		printf("%d",rold->from);
		if(rold->to > rold->from+1)
			printf(",%d",rold->to-1);
		printf("c\n");
	}
}

/*	no difference was reported by diff between file 1(or 2)
 *	and file 3, and an artificial dummy difference (trange)
 *	must be ginned up to correspond to the change reported
 *	in the other file
*/
D 4
keep(i,rold,rnew)
struct range *rold, *rnew;
E 4
I 4
keep(i,rnew)
struct range *rnew;
E 4
{
	register delta;
	struct range trange;
	delta = last[3] - last[i];
	trange.from = rnew->from - delta;
	trange.to = rnew->to - delta;
	change(i,&trange,1);
}

/*	skip to just befor line number from in file i
 *	if "pr" is nonzero, print all skipped stuff
 * w	with string pr as a prefix
*/
skip(i,from,pr)
char *pr;
{
	register j,n;
	for(n=0;cline[i]<from-1;n+=j) {
		if((j=getline(fp[i]))==0)
			trouble();
		if(pr)
			printf("%s%s",pr,line);
		cline[i]++;
	}
	return(n);
}

/*	return 1 or 0 according as the old range
 *	(in file 1) contains exactly the same data
 *	as the new range (in file 2)
*/
duplicate(r1,r2)
struct range *r1, *r2;
{
	register c,d;
	register nchar;
	int nline;
	if(r1->to-r1->from != r2->to-r2->from)
		return(0);
D 4
	skip(0,r1->from,(char *)0);
	skip(1,r2->from,(char *)0);
E 4
I 4
	(void)skip(0,r1->from,(char *)0);
	(void)skip(1,r2->from,(char *)0);
E 4
	nchar = 0;
	for(nline=0;nline<r1->to-r1->from;nline++) {
		do {
			c = getc(fp[0]);
			d = getc(fp[1]);
			if(c== -1||d== -1)
				trouble();
			nchar++;
			if(c!=d) {
				repos(nchar);
D 4
				return;
E 4
I 4
				return(0);
E 4
			}
		} while(c!= '\n');
	}
	repos(nchar);
	return(1);
}

repos(nchar)
{
	register i;
	for(i=0;i<2;i++) 
D 4
		fseek(fp[i], (long)-nchar, 1);
E 4
I 4
		(void)fseek(fp[i], (long)-nchar, 1);
E 4
}

trouble()
{
	fprintf(stderr,"diff3: logic error\n");
	abort();
}

/*	collect an editing script for later regurgitation
*/
edit(diff,dup,j)
struct diff *diff;
{
	if(((dup+1)&eflag)==0)
		return(j);
	j++;
I 3
        overlap[j] = !dup;
        if (!dup) overlapcnt++;
E 3
	de[j].old.from = diff->old.from;
	de[j].old.to = diff->old.to;
	de[j].new.from = de[j-1].new.to
	    +skip(2,diff->new.from,(char *)0);
	de[j].new.to = de[j].new.from
	    +skip(2,diff->new.to,(char *)0);
	return(j);
}

/*		regurgitate */
edscript(n)
{
	register j,k;
	char block[BUFSIZ];
	for(n=n;n>0;n--) {
D 3
		prange(&de[n].old);
E 3
I 3
                if (!oflag || !overlap[n]) 
                        prange(&de[n].old);
                else
                        printf("%da\n=======\n", de[n].old.to -1);
E 3
D 4
		fseek(fp[2], (long)de[n].new.from, 0);
E 4
I 4
		(void)fseek(fp[2], (long)de[n].new.from, 0);
E 4
		for(k=de[n].new.to-de[n].new.from;k>0;k-= j) {
			j = k>BUFSIZ?BUFSIZ:k;
			if(fread(block,1,j,fp[2])!=j)
				trouble();
D 4
			fwrite(block, 1, j, stdout);
E 4
I 4
			(void)fwrite(block, 1, j, stdout);
E 4
		}
D 3
		printf(".\n");
E 3
I 3
                if (!oflag || !overlap[n]) 
                        printf(".\n");
                else {
                        printf("%s\n.\n",f3mark);
                        printf("%da\n%s\n.\n",de[n].old.from-1,f1mark);
                }
E 3
	}
I 3
        exit(overlapcnt);
E 3
}
E 1
