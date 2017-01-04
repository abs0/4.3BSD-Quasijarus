h34129
s 00002/00002/00291
d D 5.2 86/03/09 20:48:23 donn 5 4
c added LIBC_SCCS condition for sccs ids
e
s 00003/00002/00290
d D 5.1 85/06/05 13:32:24 mckusick 4 3
c Add copyright
e
s 00029/00015/00263
d D 4.3 85/02/13 15:49:22 serge 3 2
c autoconfigure FILE array using getdtablesize() 
c changed all struct _iobuf to FILE 
c many miscellaneous changes
e
s 00001/00001/00277
d D 4.2 82/12/03 20:48:53 mckusick 2 1
c fix for reading non-negative numerics
e
s 00278/00000/00000
d D 4.1 82/12/03 20:47:34 mckusick 1 0
c date and time created 82/12/03 20:47:34 by mckusick
e
u
U
t
T
I 1
D 4
static char sccsid[] = "%W%	(Berkeley)	%E%";
E 4
I 4
D 5
#ifndef lint
E 5
I 5
#if defined(LIBC_SCCS) && !defined(lint)
E 5
static char sccsid[] = "%W% (Berkeley) %G%";
D 5
#endif not lint
E 5
I 5
#endif LIBC_SCCS and not lint
E 5
E 4

D 4
/* @(#)doscan.c	4.1 (Berkeley) 12/21/80 */
E 4
#include <stdio.h>
#include	<ctype.h>

#define	SPC	01
#define	STP	02

#define	SHORT	0
#define	REGULAR	1
#define	LONG	2
#define	INT	0
#define	FLOAT	1

D 3
char	*_getccl();
E 3
I 3
static char *_getccl();
E 3

D 3
char	_sctab[128] = {
E 3
I 3
static char _sctab[256] = {
E 3
	0,0,0,0,0,0,0,0,
	0,SPC,SPC,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	SPC,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
};

_doscan(iop, fmt, argp)
FILE *iop;
register char *fmt;
register int **argp;
{
	register int ch;
	int nmatch, len, ch1;
	int **ptr, fileended, size;

	nmatch = 0;
	fileended = 0;
	for (;;) switch (ch = *fmt++) {
	case '\0': 
		return (nmatch);
	case '%': 
		if ((ch = *fmt++) == '%')
			goto def;
		ptr = 0;
		if (ch != '*')
			ptr = argp++;
		else
			ch = *fmt++;
		len = 0;
		size = REGULAR;
		while (isdigit(ch)) {
			len = len*10 + ch - '0';
			ch = *fmt++;
		}
		if (len == 0)
			len = 30000;
		if (ch=='l') {
			size = LONG;
			ch = *fmt++;
		} else if (ch=='h') {
			size = SHORT;
			ch = *fmt++;
		} else if (ch=='[')
			fmt = _getccl(fmt);
		if (isupper(ch)) {
			ch = tolower(ch);
			size = LONG;
		}
		if (ch == '\0')
			return(-1);
		if (_innum(ptr, ch, len, size, iop, &fileended) && ptr)
			nmatch++;
		if (fileended)
			return(nmatch? nmatch: -1);
		break;

	case ' ':
	case '\n':
	case '\t': 
		while ((ch1 = getc(iop))==' ' || ch1=='\t' || ch1=='\n')
			;
		if (ch1 != EOF)
			ungetc(ch1, iop);
		break;

	default: 
	def:
		ch1 = getc(iop);
		if (ch1 != ch) {
			if (ch1==EOF)
				return(-1);
			ungetc(ch1, iop);
			return(nmatch);
		}
	}
}

I 3
static
E 3
_innum(ptr, type, len, size, iop, eofptr)
int **ptr, *eofptr;
D 3
struct _iobuf *iop;
E 3
I 3
FILE *iop;
E 3
{
	extern double atof();
	register char *np;
	char numbuf[64];
	register c, base;
	int expseen, scale, negflg, c1, ndigit;
	long lcval;

	if (type=='c' || type=='s' || type=='[')
		return(_instr(ptr? *(char **)ptr: (char *)NULL, type, len, iop, eofptr));
	lcval = 0;
	ndigit = 0;
	scale = INT;
	if (type=='e'||type=='f')
		scale = FLOAT;
	base = 10;
	if (type=='o')
		base = 8;
	else if (type=='x')
		base = 16;
	np = numbuf;
	expseen = 0;
	negflg = 0;
	while ((c = getc(iop))==' ' || c=='\t' || c=='\n');
	if (c=='-') {
		negflg++;
		*np++ = c;
		c = getc(iop);
		len--;
	} else if (c=='+') {
		len--;
		c = getc(iop);
	}
	for ( ; --len>=0; *np++ = c, c = getc(iop)) {
		if (isdigit(c)
		 || base==16 && ('a'<=c && c<='f' || 'A'<=c && c<='F')) {
			ndigit++;
			if (base==8)
				lcval <<=3;
			else if (base==10)
				lcval = ((lcval<<2) + lcval)<<1;
			else
				lcval <<= 4;
			c1 = c;
			if (isdigit(c))
				c -= '0';
			else if ('a'<=c && c<='f')
				c -= 'a'-10;
			else
				c -= 'A'-10;
			lcval += c;
			c = c1;
			continue;
		} else if (c=='.') {
			if (base!=10 || scale==INT)
				break;
			ndigit++;
			continue;
		} else if ((c=='e'||c=='E') && expseen==0) {
			if (base!=10 || scale==INT || ndigit==0)
				break;
			expseen++;
			*np++ = c;
			c = getc(iop);
			if (c!='+'&&c!='-'&&('0'>c||c>'9'))
				break;
		} else
			break;
	}
	if (negflg)
		lcval = -lcval;
	if (c != EOF) {
		ungetc(c, iop);
		*eofptr = 0;
	} else
		*eofptr = 1;
D 2
 	if (ptr==NULL || np==numbuf)
E 2
I 2
 	if (ptr==NULL || np==numbuf || (negflg && np==numbuf+1) )/* gene dykes*/
E 2
		return(0);
	*np++ = 0;
	switch((scale<<4) | size) {

	case (FLOAT<<4) | SHORT:
	case (FLOAT<<4) | REGULAR:
		**(float **)ptr = atof(numbuf);
		break;

	case (FLOAT<<4) | LONG:
		**(double **)ptr = atof(numbuf);
		break;

	case (INT<<4) | SHORT:
		**(short **)ptr = lcval;
		break;

	case (INT<<4) | REGULAR:
		**(int **)ptr = lcval;
		break;

	case (INT<<4) | LONG:
		**(long **)ptr = lcval;
		break;
	}
	return(1);
}

I 3
static
E 3
_instr(ptr, type, len, iop, eofptr)
register char *ptr;
D 3
register struct _iobuf *iop;
E 3
I 3
register FILE *iop;
E 3
int *eofptr;
{
	register ch;
	register char *optr;
	int ignstp;

	*eofptr = 0;
	optr = ptr;
	if (type=='c' && len==30000)
		len = 1;
	ignstp = 0;
	if (type=='s')
		ignstp = SPC;
D 3
	while (_sctab[ch = getc(iop)] & ignstp)
		if (ch==EOF)
			break;
E 3
I 3
	while ((ch = getc(iop)) != EOF && _sctab[ch] & ignstp)
		;
E 3
	ignstp = SPC;
	if (type=='c')
		ignstp = 0;
	else if (type=='[')
		ignstp = STP;
	while (ch!=EOF && (_sctab[ch]&ignstp)==0) {
		if (ptr)
			*ptr++ = ch;
		if (--len <= 0)
			break;
		ch = getc(iop);
	}
	if (ch != EOF) {
		if (len > 0)
			ungetc(ch, iop);
		*eofptr = 0;
	} else
		*eofptr = 1;
	if (ptr && ptr!=optr) {
		if (type!='c')
			*ptr++ = '\0';
		return(1);
	}
	return(0);
}

D 3
char *
E 3
I 3
static char *
E 3
_getccl(s)
D 3
register char *s;
E 3
I 3
register unsigned char *s;
E 3
{
	register c, t;

	t = 0;
	if (*s == '^') {
		t++;
		s++;
	}
D 3
	for (c = 0; c < 128; c++)
E 3
I 3
	for (c = 0; c < (sizeof _sctab / sizeof _sctab[0]); c++)
E 3
		if (t)
			_sctab[c] &= ~STP;
		else
			_sctab[c] |= STP;
D 3
	while (((c = *s++)&0177) != ']') {
E 3
I 3
	if ((c = *s) == ']' || c == '-') {	/* first char is special */
E 3
		if (t)
D 3
			_sctab[c++] |= STP;
E 3
I 3
			_sctab[c] |= STP;
E 3
		else
D 3
			_sctab[c++] &= ~STP;
E 3
I 3
			_sctab[c] &= ~STP;
		s++;
	}
	while ((c = *s++) != ']') {
E 3
		if (c==0)
D 3
			return(--s);
E 3
I 3
			return((char *)--s);
		else if (c == '-' && *s != ']' && s[-2] < *s) {
			for (c = s[-2] + 1; c < *s; c++)
				if (t)
					_sctab[c] |= STP;
				else
					_sctab[c] &= ~STP;
		} else if (t)
			_sctab[c] |= STP;
		else
			_sctab[c] &= ~STP;
E 3
	}
D 3
	return(s);
E 3
I 3
	return((char *)s);
E 3
}
E 1
