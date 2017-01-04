h04191
s 00023/00015/00175
d D 4.2 86/05/11 15:42:17 donn 2 1
c Permit tests for the null string in arbitrary positions in the argument
c list, not just at the end (the null string test is a crock; why couldn't we
c just have -n string?).  Added test to ensure that the argument list is
c exhausted when the expression has been parsed.  Made some lint hacks.
e
s 00190/00000/00000
d D 4.1 80/10/01 17:28:55 bill 1 0
c date and time created 80/10/01 17:28:55 by bill
e
u
U
t
T
I 2
#ifndef lint
E 2
I 1
static char *sccsid = "%W% (Berkeley) %G%";
I 2
#endif

E 2
/*
 *	test expression
 *	[ expression ]
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#define EQ(a,b)	((tmp=a)==0?0:(strcmp(tmp,b)==0))

#define DIR 1
#define FIL 2
int	ap;
int	ac;
char	**av;
char	*tmp;
I 2
char	*nxtarg();
E 2

main(argc, argv)
char *argv[];
{
I 2
	int status;
E 2

	ac = argc; av = argv; ap = 1;
	if(EQ(argv[0],"[")) {
		if(!EQ(argv[--ac],"]"))
			synbad("] missing","");
	}
	argv[ac] = 0;
	if (ac<=1) exit(1);
D 2
	exit(exp()?0:1);
E 2
I 2
	status = (exp()?0:1);
	if (nxtarg(1)!=0)
		synbad("too many arguments","");
	exit(status);
E 2
}

char *nxtarg(mt) {

	if (ap>=ac) {
		if(mt) {
			ap++;
			return(0);
		}
		synbad("argument expected","");
	}
	return(av[ap++]);
}

exp() {
	int p1;

	p1 = e1();
	if (EQ(nxtarg(1), "-o")) return(p1 | exp());
	ap--;
	return(p1);
}

e1() {
	int p1;

	p1 = e2();
	if (EQ(nxtarg(1), "-a")) return (p1 & e1());
	ap--;
	return(p1);
}

e2() {
	if (EQ(nxtarg(0), "!"))
		return(!e3());
	ap--;
	return(e3());
}

e3() {
	int p1;
	register char *a;
	char *p2;
D 2
	int int1, int2;
E 2
I 2
	int int1;
E 2

	a=nxtarg(0);
	if(EQ(a, "(")) {
		p1 = exp();
		if(!EQ(nxtarg(0), ")")) synbad(") expected","");
		return(p1);
	}

	if(EQ(a, "-r"))
		return(tio(nxtarg(0), 0));

	if(EQ(a, "-w"))
		return(tio(nxtarg(0), 1));

	if(EQ(a, "-d"))
		return(ftype(nxtarg(0))==DIR);

	if(EQ(a, "-f"))
		return(ftype(nxtarg(0))==FIL);

	if(EQ(a, "-s"))
		return(fsizep(nxtarg(0)));

	if(EQ(a, "-t"))
		if(ap>=ac)
			return(isatty(1));
		else
			return(isatty(atoi(nxtarg(0))));

	if(EQ(a, "-n"))
		return(!EQ(nxtarg(0), ""));
	if(EQ(a, "-z"))
		return(EQ(nxtarg(0), ""));

	p2 = nxtarg(1);
	if (p2==0)
		return(!EQ(a,""));
	if(EQ(p2, "="))
		return(EQ(nxtarg(0), a));

	if(EQ(p2, "!="))
		return(!EQ(nxtarg(0), a));

	if(EQ(a, "-l")) {
		int1=length(p2);
		p2=nxtarg(0);
	} else{	int1=atoi(a);
	}
D 2
	int2 = atoi(nxtarg(0));
E 2
	if(EQ(p2, "-eq"))
D 2
		return(int1==int2);
E 2
I 2
		return(int1==atoi(nxtarg(0)));
E 2
	if(EQ(p2, "-ne"))
D 2
		return(int1!=int2);
E 2
I 2
		return(int1!=atoi(nxtarg(0)));
E 2
	if(EQ(p2, "-gt"))
D 2
		return(int1>int2);
E 2
I 2
		return(int1>atoi(nxtarg(0)));
E 2
	if(EQ(p2, "-lt"))
D 2
		return(int1<int2);
E 2
I 2
		return(int1<atoi(nxtarg(0)));
E 2
	if(EQ(p2, "-ge"))
D 2
		return(int1>=int2);
E 2
I 2
		return(int1>=atoi(nxtarg(0)));
E 2
	if(EQ(p2, "-le"))
D 2
		return(int1<=int2);
E 2
I 2
		return(int1<=atoi(nxtarg(0)));
E 2

D 2
	synbad("unknown operator ",p2);
E 2
I 2
	--ap;
	return(!EQ(a,""));
E 2
}

tio(a, f)
char *a;
int f;
{

	f = open(a, f);
	if (f>=0) {
D 2
		close(f);
E 2
I 2
		(void) close(f);
E 2
		return(1);
	}
	return(0);
}

ftype(f)
char *f;
{
	struct stat statb;

	if(stat(f,&statb)<0)
		return(0);
	if((statb.st_mode&S_IFMT)==S_IFDIR)
		return(DIR);
	return(FIL);
}

fsizep(f)
char *f;
{
	struct stat statb;
	if(stat(f,&statb)<0)
		return(0);
	return(statb.st_size>0);
}

synbad(s1,s2)
char *s1, *s2;
{
D 2
	write(2, "test: ", 6);
	write(2, s1, strlen(s1));
	write(2, s2, strlen(s2));
	write(2, "\n", 1);
E 2
I 2
	(void) write(2, "test: ", 6);
	(void) write(2, s1, strlen(s1));
	(void) write(2, s2, strlen(s2));
	(void) write(2, "\n", 1);
E 2
	exit(255);
}

length(s)
	char *s;
{
	char *es=s;
	while(*es++);
	return(es-s-1);
}
E 1
