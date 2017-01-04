h49943
s 00004/00004/00329
d D 4.6 88/07/18 18:04:52 bostic 6 5
c adb had code for handling floating reserved operands at the command level
c ('f' and 'F') that was wrong; thus adb thinks numbers like -2.93874e-39 are
c illegal; from Donn Seeley
e
s 00018/00005/00315
d D 4.5 88/04/24 14:51:04 bostic 5 4
c fix for ANSI C
e
s 00001/00004/00319
d D 4.4 87/06/30 09:50:47 bostic 4 3
c print masks as instructions right
e
s 00009/00002/00314
d D 4.3 86/02/27 20:41:38 mckusick 3 2
c fixes to avoid faulting when printing reserved operands (from Torek)
e
s 00003/00002/00313
d D 4.2 83/08/11 20:01:09 sam 2 1
c fix sccs keyword lines
e
s 00315/00000/00000
d D 4.1 81/05/14 15:19:45 root 1 0
c date and time created 81/05/14 15:19:45 by root
e
u
U
t
T
I 1
D 2
#
E 2
I 2
#ifndef lint
static	char sccsid[] = "%W% %G%";
#endif
E 2
/*
 *
 *	UNIX debugger
 *
 */

#include "defs.h"
D 2
static	char sccsid[] = "%Z%%M% %I% %G%";
E 2

MSG		BADMOD;
MSG		NOFORK;
MSG		ADWRAP;

INT		mkfault;
CHAR		*lp;
L_INT		maxoff;
ADDR		sigint;
ADDR		sigqit;
STRING		errflg;
CHAR		lastc,peekc;
L_INT		dot;
INT		dotinc;
L_INT		expv;
L_INT		var[];


STRING		fphack;
rdfp()
{
	return(lastc= *fphack++);
}

scanform(icount,ifp,itype,ptype)
L_INT		icount;
STRING		ifp;
{
	STRING		fp;
	CHAR		modifier;
	INT		fcount, init=1;
	L_INT		savdot;
	BOOL exact;
	BOOL doit = 1;

	WHILE icount
	DO  fp=ifp;
	    savdot=dot; init=0;

	    IF init==0 ANDF (exact=(findsym(dot,ptype)==0)) ANDF maxoff
	    THEN printf("\n%s:%16t",cursym->n_un.n_name);
	    FI

	    /*now loop over format*/
	    WHILE *fp ANDF errflg==0
	    DO  IF digit(modifier = *fp)
		THEN fcount = 0;
			WHILE digit(modifier = *fp++)
			DO fcount *= 10;
			   fcount += modifier-'0';
			OD
			fp--;
I 3
			IF fcount==0 THEN fcount = 1; FI
E 3
		ELSE fcount = 1;
		FI

		IF *fp==0 THEN break; FI
D 4
		IF exact ANDF dot==savdot ANDF itype==ISP ANDF cursym->n_un.n_name[0]=='_' ANDF *fp=='i'
		THEN exform(1,"x",itype,ptype); fp++; printc(EOR); /* entry mask */
		ELSE fp=exform(fcount,fp,itype,ptype);
		FI
E 4
I 4
		fp=exform(fcount,fp,itype,ptype);
E 4
	    OD
	    dotinc=dot-savdot;
	    dot=savdot;

	    IF errflg
	    THEN IF icount<0
		 THEN errflg=0; break;
		 ELSE error(errflg);
		 FI
	    FI
	    IF --icount
	    THEN dot=inkdot(dotinc);
	    FI
	    IF mkfault THEN error(0); FI
	OD
}

STRING
exform(fcount,ifp,itype,ptype)
INT		fcount;
STRING		ifp;
{
	/* execute single format item `fcount' times
	 * sets `dotinc' and moves `dot'
	 * returns address of next format item
	 */
	POS		w;
	L_INT		savdot, wx;
	STRING		fp;
	CHAR		c, modifier, longpr;
	L_REAL		fw;
D 5
	struct{
E 5
I 5
	struct bad_programming {
E 5
		L_INT	sa;
		INT	sb,sc;
	};

	WHILE fcount>0
	DO	fp = ifp; c = *fp;
		longpr=(c>='A')&(c<='Z')|(c=='f')|(c=='4')|(c=='p');
		IF itype==NSP ORF *fp=='a'
		THEN wx=dot; w=dot;
		ELSE w=get(dot,itype);
		     IF longpr
		     THEN wx=itol(get(inkdot(2),itype),w);
		     ELSE wx=w;
		     FI
		FI
		IF c=='F'
D 5
		THEN fw.sb=get(inkdot(4),itype);
		     fw.sc=get(inkdot(6),itype);
E 5
I 5
		/*
		 * This used to be the following, but real C compilers won't
		 * let you use a double as a struct!
		 *
		 *	THEN fw.sb=get(inkdot(4),itype);
		 *	fw.sc=get(inkdot(6),itype);
		 */
		THEN (*(struct bad_programming *)&fw).sb=get(inkdot(4),itype);
		     (*(struct bad_programming *)&fw).sc=get(inkdot(6),itype);
E 5
		FI
		IF errflg THEN return(fp); FI
		IF mkfault THEN error(0); FI
		var[0]=wx;
		modifier = *fp++;
		dotinc=(longpr?4:2);;

		IF charpos()==0 ANDF modifier!='a' THEN printf("%16m"); FI

		switch(modifier) {

		    case SP: case TB:
			break;

		    case 't': case 'T':
			printf("%T",fcount); return(fp);

		    case 'r': case 'R':
			printf("%M",fcount); return(fp);

		    case 'a':
			psymoff(dot,ptype,":%16t"); dotinc=0; break;

		    case 'p':
			psymoff(var[0],ptype,"%16t"); break;

		    case 'u':
			printf("%-8u",w); break;

		    case 'U':
			printf("%-16U",wx); break;

		    case 'c': case 'C':
			IF modifier=='C'
			THEN printesc(w&LOBYTE);
			ELSE printc(w&LOBYTE);
			FI
			dotinc=1; break;

		    case 'b': case 'B':
			printf("%-8o", w&LOBYTE); dotinc=1; break;

			case '1':
			printf("%-8r", w&LOBYTE); dotinc=1; break;

			case '2':
		    case 'w':
			printf("%-8r", w); break;

			case '4':
		    case 'W':
			printf("%-16R", wx); break;

		    case 's': case 'S':
			savdot=dot; dotinc=1;
			WHILE (c=get(dot,itype)&LOBYTE) ANDF errflg==0
			DO dot=inkdot(1);
			   IF modifier == 'S'
			   THEN printesc(c);
			   ELSE printc(c);
			   FI
			   endline();
			OD
			dotinc=dot-savdot+1; dot=savdot; break;

		    case 'x':
			printf("%-8x",w); break;

		    case 'X':
			printf("%-16X", wx); break;

		    case 'Y':
			printf("%-24Y", wx); break;

		    case 'q':
			printf("%-8q", w); break;

		    case 'Q':
			printf("%-16Q", wx); break;

		    case 'o':
			printf("%-8o", w); break;

		    case 'O':
			printf("%-16O", wx); break;

		    case 'i':
			printins(0,itype,w); printc(EOR); break;

		    case 'd':
			printf("%-8d", w); break;

		    case 'D':
			printf("%-16D", wx); break;

		    case 'f':
			fw = 0;
D 5
			fw.sa = wx;
E 5
I 5
			/*
			 * This used to be the following, but real compilers
			 * won't let you use a double as a struct!
			 *
			 *	fw.sa = wx;
			 */
			(*(struct bad_programming *)&fw).sa = wx;
E 5
D 3
			printf("%-16.9f", fw);
E 3
I 3
D 6
			IF (wx & ~0xFFFF00FF) == 0x8000
			THEN printf("(reserved oprnd)");
E 6
I 6
			IF (wx & ~0xFFFF007F) == 0x8000
			THEN printf("(reserved operand)");
E 6
			ELSE printf("%-16.9f", fw);
			FI
E 3
			dotinc=4; break;

		    case 'F':
D 5
			fw.sa = wx;
E 5
I 5
			(*(struct bad_programming *)&fw).sa = wx;
E 5
D 3
			printf("%-32.18F", fw);
E 3
I 3
D 6
			IF (wx & ~0xFFFF00FF) == 0x8000
			THEN printf("%-32s", "(reserved oprnd)");
E 6
I 6
			IF (wx & ~0xFFFF007F) == 0x8000
			THEN printf("%-32s", "(reserved operand)");
E 6
			ELSE printf("%-32.18F", fw);
			FI
E 3
			dotinc=8; break;

		    case 'n': case 'N':
			printc('\n'); dotinc=0; break;

		    case '"':
			dotinc=0;
			WHILE *fp != '"' ANDF *fp
			DO printc(*fp++); OD
			IF *fp THEN fp++; FI
			break;

		    case '^':
			dot=inkdot(-dotinc*fcount); return(fp);

		    case '+':
			dot=inkdot(fcount); return(fp);

		    case '-':
			dot=inkdot(-fcount); return(fp);

		    default: error(BADMOD);
		}
		IF itype!=NSP
		THEN	dot=inkdot(dotinc);
		FI
		fcount--; endline();
	OD

	return(fp);
}

shell()
{
#ifndef EDDT
	INT		rc, status, unixpid;
	STRING		argp = lp;
	STRING		getenv(), shell = getenv("SHELL");
#ifdef VFORK
	char		oldstlp;
#endif

	if (shell == 0)
		shell = "/bin/sh";
	WHILE lastc!=EOR DO rdc(); OD
#ifndef VFORK
	IF (unixpid=fork())==0
#else
	oldstlp = *lp;
	IF (unixpid=vfork())==0
#endif
	THEN	signal(SIGINT,sigint); signal(SIGQUIT,sigqit);
		*lp=0; execl(shell, "sh", "-c", argp, 0);
		_exit(16);
#ifndef VFORK
	ELIF unixpid == -1
#else
	ELIF *lp = oldstlp, unixpid == -1
#endif
	THEN	error(NOFORK);
	ELSE	signal(SIGINT,1);
		WHILE (rc = wait(&status)) != unixpid ANDF rc != -1 DONE
		signal(SIGINT,sigint);
		prints("!"); lp--;
	FI
#endif
}


printesc(c)
{
	c &= STRIP;
	IF c==0177 THEN printf("^?");
	ELIF c<SP
	THEN printf("^%c", c + '@');
	ELSE printc(c);
	FI
}

L_INT	inkdot(incr)
{
	L_INT		newdot;

	newdot=dot+incr;
	IF (dot NEQ newdot) >> 24 THEN error(ADWRAP); FI
	return(newdot);
}

digit(c)
{
	return c >= '0' && c <= '9';
}
E 1
