h46238
s 00022/00017/00191
d D 7.2 86/12/15 20:26:50 sam 2 1
c lint
e
s 00208/00000/00000
d D 7.1 86/11/20 12:22:05 sam 1 0
c date and time created 86/11/20 12:22:05 by sam
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
/*
 * Copyright (c) 1986 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 2

#include "../kdb/defs.h"

long	maxpos;
int	radix = 16;

char	printbuf[MAXLIN];
char	*printptr = printbuf;
char	*digitptr;

printc(c)
	char c;
{
	char d;
	register char *q;
	register posn, tabs, p;

	if (mkfault)
		return;
	if ((*printptr=c)==EOR) {
		tabs=0; posn=0; q=printbuf;
		for (p=0; p<printptr-printbuf; p++) {
			d=printbuf[p];
			if ((p&7)==0 && posn) {
				tabs++;
				posn=0;
			}
			if (d!=SP) {
				while (tabs>0)
					*q++=TB, tabs--;
				while (posn>0)
					*q++=SP, posn--;
				*q++=d;
			} else
				posn++;
		 }
		 *q++=EOR;
		 kdbwrite(printbuf,q-printbuf);
		 printptr=printbuf;
	} else if (c==TB) {
		*printptr++=SP;
		while ((printptr-printbuf)&7)
			*printptr++=SP;
	} else if (c)
		printptr++;
	if (printptr >= &printbuf[MAXLIN-9]) {
		kdbwrite(printbuf, printptr - printbuf);
		printptr = printbuf;
	}
}

charpos()
{

	return (printptr-printbuf);
}

flushbuf()
{

	if (printptr!=printbuf)
		printc(EOR);
}

/* VARARGS1 */
printf(fmat,a1)
	char *fmat, *a1;
{
	char *fptr;
	register char *s;
	register long *dptr;
D 2
	double *rptr;
E 2
	register width, prec;
	char c, adj;
	int x, n;
	register long lx;
	char digits[64];

	fptr = fmat; dptr = (long *)&a1;
	while (c = *fptr++) {
		if (c!='%') {
			printc(c);
			continue;
		}
		if (*fptr=='-') {
			adj='l'; fptr++;
		} else
			adj='r';
		width=convert(&fptr);
		if (*fptr=='.') {
			fptr++; prec=convert(&fptr);
		} else
			prec = -1;
		digitptr=digits;
D 2
		rptr=(double *)dptr; x = lx = *dptr++;
E 2
I 2
		x = lx = *dptr++;
E 2
		s=0;
		switch (c = *fptr++) {
		case 'd':
D 2
			printnum(x, -10); break;
E 2
I 2
			printnum((u_long)x, -10); break;
E 2
		case 'u':
D 2
			printnum((unsigned short)x, 10); break;
E 2
I 2
			printnum((u_long)x, 10); break;
E 2
		case 'o':
D 2
			printnum((unsigned short)x, 8); break;
E 2
I 2
			printnum((u_long)x, 8); break;
E 2
		case 'q':
D 2
			printnum(x, -8); break;
E 2
I 2
			printnum((u_long)x, -8); break;
E 2
		case 'x':
D 2
			printnum((unsigned short)x, 16); break;
E 2
I 2
			printnum((u_long)x, 16); break;
E 2
		case 'z':
D 2
			printnum((unsigned short)x, -16); break;
E 2
I 2
			printnum((u_long)x, -16); break;
E 2
		case 'R':
D 2
			printnum(lx, radix); break;
E 2
I 2
			printnum((u_long)lx, radix); break;
E 2
		case 'D':
D 2
			printnum(lx, -10); break;
E 2
I 2
			printnum((u_long)lx, -10); break;
E 2
		case 'U':
D 2
			printnum(lx, 10); break;
E 2
I 2
			printnum((u_long)lx, 10); break;
E 2
		case 'O':
D 2
			printnum(lx, 8); break;
E 2
I 2
			printnum((u_long)lx, 8); break;
E 2
		case 'Q':
D 2
			printnum(lx, -8); break;
E 2
I 2
			printnum((u_long)lx, -8); break;
E 2
		case 'X':
D 2
			printnum(lx, 16); break;
E 2
I 2
			printnum((u_long)lx, 16); break;
E 2
		case 'Z':
D 2
			printnum(lx, -16); break;
E 2
I 2
			printnum((u_long)lx, -16); break;
E 2
		case 'c':
			printc(x); break;
		case 's':
			s=(char *)lx; break;
		case 'm':
			break;
		case 'M':
			width=x; break;
		case 'T': case 't':
			if (c=='T')
				width=x;
			else
				dptr--;
			if (width)
				width -= charpos()%width;
			break;
		default:
			printc(c); dptr--;
			break;
		}
		if (s==0) {
			*digitptr=0; s=digits;
		}
		n=strlen(s);
		n=(prec<n && prec>=0 ? prec : n);
		width -= n;
		if (adj=='r')
			while (width-- > 0)
				printc(SP);
		while (n--)
			printc(*s++);
		while (width-- > 0)
			printc(SP);
		digitptr=digits;
	}
}

static
convert(cp)
	register char **cp;
{
	register char c;
	int n;

	n=0;
	while (((c = *(*cp)++)>='0') && c<='9')
		n=n*10+c-'0';
	(*cp)--;
	return (n);
}

static
printnum(n, base)
D 2
	register POS n;
E 2
I 2
	register u_long n;
E 2
{
	register char *dptr;
	char digs[15];

	dptr=digs;
	if (base<0) {
		base = -base;
		if ((long)n<0) {
			n = -n;
			*digitptr++ = '-';
		}
	}
	while (n) {
		*dptr++ = n%base;
		n /= base;
	}
	if (dptr==digs)
		*dptr++=0;
	while (dptr!=digs) {
		n = *--dptr;
		*digitptr++ = (n+(n<=9 ? '0' : 'a'-10));
	}
}

endline()
{

	if (maxpos <= charpos())
		printf("\n");
}
E 1
