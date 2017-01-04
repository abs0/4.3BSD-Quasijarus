h34256
s 00015/00009/00239
d D 7.4 86/12/15 20:26:47 sam 4 3
c lint
e
s 00003/00001/00245
d D 7.3 86/11/23 13:36:02 sam 3 2
c move machine dependencies to ../machine/kdbparam.h
e
s 00016/00033/00230
d D 7.2 86/11/20 14:43:55 sam 2 1
c pitch floating point formats; fix expr=[cCbb1] handling
e
s 00263/00000/00000
d D 7.1 86/11/20 12:22:03 sam 1 0
c date and time created 86/11/20 12:22:03 by sam
e
u
U
t
T
I 1
D 4
/*	%M%	%I%	%E%	*/
E 4
I 4
/*
 * Copyright (c) 1986 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 4

#include "../kdb/defs.h"

char	*BADMOD;
char	*ADWRAP;

char	*lp;
char	lastc,peekc;
long	expv;

scanform(icount,ifp,itype,ptype)
	long icount;
	char *ifp;
{
	register char *fp;
	char modifier;
	register fcount, init=1;
	long savdot;
	int exact;

	while (icount) {
		fp=ifp;
		savdot=dot; init=0;
		if (!init && (exact=(findsym(dot,ptype)==0)) && maxoff)
			printf("\n%s:%16t",cursym->n_un.n_name);
		/*now loop over format*/
		while (*fp && errflg==0) {
			if (isdigit(modifier = *fp)) {
				fcount = 0;
				while (isdigit(modifier = *fp++)) {
				   fcount *= 10;
				   fcount += modifier-'0';
				}
				fp--;
			} else
				fcount = 1;
			if (*fp==0)
				break;
I 3
#ifdef	ENTRYMASK
E 3
			/* check for entry mask */
			if (exact && dot==savdot && 
			   (cursym->n_type&N_TYPE)==N_TEXT &&
			   cursym->n_un.n_name[0]=='_' && *fp=='i') {
D 4
				exform(1,"x",itype,ptype);
E 4
I 4
				(void) exform(1,"x",itype,ptype);
E 4
				fp++;
				printc(EOR);
			} else
I 3
#endif
E 3
D 4
				fp=exform(fcount,fp,itype,ptype);
E 4
I 4
				fp = exform(fcount,fp,itype,ptype);
E 4
		}
		dotinc=dot-savdot;
		dot=savdot;

		if (errflg) {
			if (icount<0) {
				 errflg=0;
				 break;
			}
			error(errflg);
		}
		if (--icount)
			dot=inkdot(dotinc);
		if (mkfault)
D 4
			error(0);
E 4
I 4
			error((char *)0);
E 4
	}
}

/*
 * Execute single format item `fcount' times
 * sets `dotinc' and moves `dot'
 * returns address of next format item
 */
char *
exform(fcount,ifp,itype,ptype)
	int fcount;
	char *ifp;
{
	register POS w;
	register long savdot, wx;
	register char *fp;
	char c, modifier, longpr;
D 2
	union{	/* compatible with both VAX and TAHOE */
		double	d;
		int	s[4];
	} fw;
E 2

	while (fcount>0) {
	  	fp = ifp; c = *fp;
D 2
		longpr=(c>='A')&&(c<='Z')||(c=='f')||(c=='4')||(c=='p');
		if (itype==NSP || *fp=='a') {
			wx=dot; w=dot;
E 2
I 2
		longpr = (isupper(c) || c=='f' || c=='4' || c=='p');
		if (itype != NSP && *fp != 'a') {
			wx = get(dot, itype);
			w = shorten(wx);
E 2
		} else {
D 2
			wx=get(dot,itype);
			w=shorten(wx);
E 2
I 2
			wx = w = dot;
			if (itype == NSP &&
			    (c == 'b' || c == 'B' ||
			     c == 'c' || c == 'C' || c == '1'))
				w = btol(wx);
E 2
		}
		if (errflg)
			return (fp);
		if (mkfault)
D 4
			error(0);
E 4
I 4
			error((char *)0);
E 4
D 2
		var[0]=wx;
E 2
I 2
		var[0] = wx;
E 2
		modifier = *fp++;
D 2
		dotinc=(longpr?4:2);
E 2
I 2
		dotinc = (longpr ? sizeof (long):sizeof (short));
E 2

		if (charpos()==0 && modifier!='a')
			printf("%16m");
		switch (modifier) {

		case SP: case TB:
			break;

		case 't': case 'T':
			printf("%T",fcount); return (fp);

		case 'r': case 'R':
			printf("%M",fcount); return (fp);

		case 'a':
			psymoff(dot,ptype,":%16t"); dotinc=0; break;

		case 'p':
			psymoff(var[0],ptype,"%16t"); break;

		case 'u':
			printf("%-8u",w); break;

		case 'U':
			printf("%-16U",wx); break;

		case 'c': case 'C':
D 2
			if (modifier=='C')
				printesc(byte(wx));
E 2
I 2
			if (modifier == 'C')
D 4
				printesc(byte(w));
E 4
I 4
				printesc((int)byte(w));
E 4
E 2
			else
D 2
				printc(byte(wx));
E 2
I 2
D 4
				printc(byte(w));
E 4
I 4
				printc((char)byte(w));
E 4
E 2
			dotinc=1; break;

		case 'b': case 'B':
D 2
			printf("%-8o", byte(wx)); dotinc=1; break;
E 2
I 2
			printf("%-8o", byte(w)); dotinc=1; break;
E 2

		case '1':
D 2
			printf("%-8R", byte(wx)); dotinc=1; break;
E 2
I 2
			printf("%-8R", byte(w)); dotinc=1; break;
E 2

		case 'w': case '2':
			printf("%-8R", w); break;

		case 'W': case '4':
			printf("%-16R", wx); break;

		case 's': case 'S':
			savdot=dot; dotinc=1;
			while ((c=byte(get(dot,itype))) && errflg==0) {
				dot=inkdot(1);
				if (modifier == 'S')
D 4
					printesc(c);
E 4
I 4
					printesc((int)c);
E 4
				else
					printc(c);
				endline();
			}
			dotinc=dot-savdot+1; dot=savdot; break;

		case 'x':
			printf("%-8x",w); break;

		case 'X':
			printf("%-16X", wx); break;

		case 'z':
			printf("%-8z",w); break;

		case 'Z':
			printf("%-16Z", wx); break;

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

		case 'i': case 'I':
			printins(itype,wx); printc(EOR); break;

		case 'd':
			printf("%-8d", w); break;

		case 'D':
			printf("%-16D", wx); break;
D 2

		case 'f':
			fw.d = 0;
			fw.s[0] = w;
			fw.s[1] = wx&0xffff;
			printf("%-16.9f", fw.d);
			dotinc=4; break;

		case 'F':	/* may be done with one get call on TAHOE */
			fw.s[0] = w;
			fw.s[1] = wx&0xffff;
			fw.s[2]=shorten(get(inkdot(4),itype));
			fw.s[3]=shorten(get(inkdot(6),itype));
			if (errflg)
				return (fp);
			printf("%-32.18F", fw.d);
			dotinc=8; break;
E 2

		case 'n': case 'N':
			printc('\n'); dotinc=0; break;

		case '"':
			dotinc=0;
			while (*fp != '"' && *fp)
				printc(*fp++);
			if (*fp)
				fp++;
			break;

		case '^':
			dot=inkdot(-dotinc*fcount); return (fp);

		case '+':
			dot=inkdot(fcount); return (fp);

		case '-':
			dot=inkdot(-fcount); return (fp);

		default:
			error(BADMOD);
		}
		if (itype!=NSP)
			dot=inkdot(dotinc);
		fcount--; endline();
	}
	return (fp);
}

static
printesc(c)
D 4
	register c;
E 4
I 4
	register int c;
E 4
{

	c &= STRIP;
	if (c==0177 || c<SP)
		printf("^%c", c ^ 0100);
	else
		printc(c);
}

long
inkdot(incr)
{
	register long newdot;

	newdot=dot+incr;
D 3
	if ((dot ^ newdot) >> 24)
E 3
I 3
	if (addrwrap(dot, newdot))
E 3
		error(ADWRAP);
	return (newdot);
}
E 1
