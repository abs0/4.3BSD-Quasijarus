h17069
s 00015/00000/00158
d D 1.4 88/03/03 14:56:48 bostic 4 3
c move trap and uncache from sys.c to prf.c
e
s 00000/00063/00158
d D 1.3 88/03/02 11:23:50 bostic 3 2
c printn and gets are in ../stand now
e
s 00029/00063/00192
d D 1.2 86/11/04 13:40:46 karels 2 1
c cleanups, rm unused
e
s 00255/00000/00000
d D 1.1 86/01/12 18:05:01 sam 1 0
c date and time created 86/01/12 18:05:01 by sam
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/
/*	prf.c	4.3	81/05/05	*/

#include "../machine/mtpr.h"

#include "param.h"
#include "../tahoe/cp.h"
D 2
#ifdef NOIO
#define CINADR	0xf0000		/* Dummy keyboard (memory mapped) */
#define COUTADR	0xf1000		/* Dummy screen 	-,,-	  */
#endif
E 2

/*
 * Scaled down version of C Library printf.
 * Used to print diagnostic information directly on console tty.
 * Since it is not interrupt driven, all system activities are
 * suspended.  Printf should not be used for chit-chat.
 *
 * One additional format: %b is supported to decode error registers.
 * Usage is:
 *	printf("reg=%b\n", regval, "<base><arg>*");
 * Where <base> is the output base expressed as a control character,
 * e.g. \10 gives octal; \20 gives hex.  Each arg is a sequence of
 * characters, the first of which gives the bit number to be inspected
 * (origin 1), and the next characters (up to a control character, i.e.
 * a character <= 32), give the name of the register.  Thus
 *	printf("reg=%b\n", 3, "\10\2BITTWO\1BITONE\n");
 * would produce output:
 *	reg=2<BITTWO,BITONE>
 */
/*VARARGS1*/
printf(fmt, x1)
	char *fmt;
	unsigned x1;
{

	prf(fmt, &x1);
}

prf(fmt, adx)
	register char *fmt;
	register u_int *adx;
{
	register int b, c, i;
	char *s;
	int any;

loop:
	while ((c = *fmt++) != '%') {
D 2
		if(c == '\0')
E 2
I 2
		if (c == '\0')
E 2
			return;
		putchar(c);
	}
again:
	c = *fmt++;
	/* THIS CODE IS VAX DEPENDENT IN HANDLING %l? AND %c */
	switch (c) {

	case 'l':
		goto again;
	case 'x': case 'X':
		b = 16;
		goto number;
	case 'd': case 'D':
	case 'u':		/* what a joke */
		b = 10;
		goto number;
	case 'o': case 'O':
		b = 8;
number:
		printn((u_long)*adx, b);
		break;
	case 'c':
		b = *adx;
		for (i = 24; i >= 0; i -= 8)
			if (c = (b >> i) & 0x7f)
				putchar(c);
		break;
	case 'b':
		b = *adx++;
		s = (char *)*adx;
		printn((u_long)b, *s++);
		any = 0;
		if (b) {
D 2
			putchar('<');
E 2
			while (i = *s++) {
				if (b & (1 << (i-1))) {
D 2
					if (any)
						putchar(',');
E 2
I 2
					putchar(any? ',' : '<');
E 2
					any = 1;
					for (; (c = *s) > 32; s++)
						putchar(c);
				} else
					for (; *s > 32; s++)
						;
			}
D 2
			putchar('>');
E 2
I 2
			if (any)
				putchar('>');
E 2
		}
		break;

	case 's':
		s = (char *)*adx;
		while (c = *s++)
			putchar(c);
		break;
	}
	adx++;
	goto loop;
}

/*
D 3
 * Printn prints a number n in base b.
 * We don't use recursion to avoid deep kernel stacks.
 */
printn(n, b)
	u_long n;
{
	char prbuf[11];
	register char *cp;

	if (b == 10 && (int)n < 0) {
		putchar('-');
		n = (unsigned)(-(int)n);
	}
	cp = prbuf;
	do {
		*cp++ = "0123456789abcdef"[n%b];
		n /= b;
	} while (n);
	do
		putchar(*--cp);
	while (cp > prbuf);
}

/*
E 3
 * Print a character on console.
D 2
 * Attempts to save and restore device
 * status.
 *
 * Whether or not printing is inhibited,
 * the last MSGBUFS characters
 * are saved in msgbuf for inspection later.
E 2
 */
D 2
#ifdef NOIO
char	*coutadr=(char *)COUTADR;
putchar(c)
	register c;
{
	*coutadr++ = c;
}

char	*cinadr=(char *)CINADR;
getchar()
{
	return( *cinadr++ );
}

#else
E 2
struct	cpdcb_o cpout;
struct	cpdcb_i cpin;

/* console requires even parity */
#define EVENP
I 2

E 2
putchar(c)
D 2
char c;
E 2
I 2
	char c;
E 2
{
	int time;
#ifdef EVENP
	register mask, par;

D 2
	for(par=0, mask=1; mask!=0200; mask<<=1, par<<=1)
E 2
I 2
	for (par = 0, mask = 1; mask != 0200; mask <<= 1, par <<= 1)
E 2
		par ^= c&mask;
	c |= par;
#endif EVENP
	cpout.cp_hdr.cp_unit = CPCONS;	/* Resets done bit */
	cpout.cp_hdr.cp_comm = CPWRITE;
	cpout.cp_hdr.cp_count = 1;
	cpout.cp_buf[0] = c;
	mtpr(CPMDCB, &cpout);
D 2
#ifdef SIMIO
	simout(&cpout);
#endif
E 2
	time = 100000;				/* Delay loop */
	while (time--) {
D 2
		uncache (&cpout.cp_hdr.cp_unit) ;
		if (cpout.cp_hdr.cp_unit & CPDONE) break;
E 2
I 2
		uncache(&cpout.cp_hdr.cp_unit);
		if (cpout.cp_hdr.cp_unit & CPDONE)
			break;
E 2
	}
D 2
	if (c == '\n') putchar ('\r');
E 2
I 2
	if (c == '\n')
		putchar ('\r');
E 2
}

D 2
#ifdef SIMIO
simout(addr)
{
	asm(".byte 0x4");
}
simin(addr)
{
	asm(".byte 0x3");
}
#endif

E 2
getchar()
{
D 2
	char	c;
E 2
I 2
	char c;
E 2

	cpin.cp_hdr.cp_unit = CPCONS;	/* Resets done bit */
	cpin.cp_hdr.cp_comm = CPREAD;
	cpin.cp_hdr.cp_count = 1;
	mtpr(CPMDCB, &cpin);
D 2
#ifdef SIMIO
	simin(&cpin);
#endif
E 2
	while ((cpin.cp_hdr.cp_unit & CPDONE) == 0) 
D 2
		uncache (&cpin.cp_hdr.cp_unit);
	uncache (&cpin.cpi_buf[0]);
E 2
I 2
		uncache(&cpin.cp_hdr.cp_unit);
	uncache(&cpin.cpi_buf[0]);
E 2
	c = cpin.cpi_buf[0] & 0x7f;
D 2
	if (c == '\r')  c = '\n';
	putchar(c);
	return(c);
E 2
I 2
	if (c == '\r')
		c = '\n';
	if (c != '\b' && c != '\177')
		putchar(c);
	return (c);
E 2
D 3
}
D 2
#endif
E 2

D 2

E 2
gets(buf)
	char *buf;
{
	register char *lp;
	register c;

	lp = buf;
	for (;;) {
		c = getchar() & 0177;
D 2
	store:
E 2
		switch(c) {
		case '\n':
		case '\r':
			c = '\n';
			*lp++ = '\0';
			return;
		case '\b':
I 2
		case '\177':
			if (lp > buf) {
				lp--;
				putchar('\b');
				putchar(' ');
				putchar('\b');
			}
			continue;
E 2
		case '#':
D 2
			lp--;
			if (lp < buf)
E 2
I 2
			if (--lp < buf)
E 2
				lp = buf;
			continue;
		case '@':
		case 'u'&037:
			lp = buf;
			putchar('\n');
			continue;
		default:
			*lp++ = c;
		}
	}
E 3
}
I 4

trap(ps)
	int ps;
{
	printf("Trap %o\n", ps);
	for (;;)
		;
}

uncache (addr)
	char *addr;
{
	/* Return *(addr-0x4000); DIRTY assumes this address is valid */
	mtpr(PDCS, addr);
}
E 4
E 1
