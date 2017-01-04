h56267
s 00004/00004/00880
d D 5.15 87/12/21 12:36:31 bostic 15 14
c make ANSI C compatible
e
s 00001/00000/00883
d D 5.14 87/12/02 15:42:35 bostic 14 13
c bug report 4.3BSD/bin/104; exit 0 on success
e
s 00004/00004/00879
d D 5.13 87/10/22 09:53:35 bostic 13 12
c ANSI C; sprintf now returns an int.
e
s 00001/00011/00882
d D 5.12 84/05/14 15:03:29 ralph 12 11
c use bcmp library routine. also, bufncmp had a bug.
e
s 00001/00001/00892
d D 5.11 83/04/29 00:52:02 mckusick 11 10
c added perror
e
s 00037/00035/00851
d D 5.10 83/02/16 09:47:31 dlw 10 9
c added w[n] option. DLW
e
s 00009/00003/00877
d D 5.9 83/02/15 20:17:55 dlw 9 8
c fixed seek for raw disk devices. DLW
e
s 00000/00005/00880
d D 5.8 81/11/12 16:51:07 dlw 8 7
c made default addr_base be OCTAL (ugh). DLW
e
s 00012/00002/00873
d D 5.7 81/11/12 16:42:19 dlw 7 6
c fixed buffer compare. DLW
e
s 00018/00012/00857
d D 5.6 81/11/01 01:14:43 dlw 6 5
c fixed string conversion with bytes > 0200. DLW
e
s 00336/00134/00533
d D 5.5 81/10/31 11:50:39 dlw 5 4
c added '-s'; added _ctype; cleaned up code. DLW
e
s 00083/00014/00610
d D 5.4 81/10/16 18:36:07 dlw 4 3
c added [label] offset & bad flag error. DLW
e
s 00005/00006/00619
d D 5.3 81/10/14 22:55:43 dlw 3 2
c fixed bug in underlining. DLW
e
s 00017/00002/00608
d D 5.2 81/10/14 17:35:36 dlw 2 1
c added check for illegal f.p. format. DLW
e
s 00610/00000/00000
d D 5.1 81/10/13 18:59:57 dlw 1 0
c date and time created 81/10/13 18:59:57 by dlw
e
u
U
t
T
I 1
static char *sccsid = "%W% (Berkeley) %G%";
/*
 * od -- octal, hex, decimal, character dump of data in a file.
 *
D 4
 * usage:	od [-abcdDefFhHiIlLopPvxX] [file] [[+]offset[.][b]]
E 4
I 4
D 5
 * usage:  od [-abcdDefFhHiIlLopPvxX] [file] [[+]offset[.][b] [label]]
E 5
I 5
D 10
 * usage:  od [-abBcdDefFhHiIlLopPsvxX] [file] [[+]offset[.][b] [label]]
E 10
I 10
 * usage:  od [-abBcdDefFhHiIlLopPs[n]vw[n]xX] [file] [[+]offset[.][b] [label]]
E 10
E 5
E 4
 *
 * where the option flags have the following meaning:
 *   character	object	radix	signed?
 *	a	byte	(10)	(n.a.)	ASCII named byte stream
 *	b	byte	  8	 no	byte octal
 *	c	byte	 (8)	(no)	character with octal non-graphic bytes
 *	d	short	 10	 no
 *	D	long	 10	 no
 *	e,F	double	(10)		double precision floating pt.
 *	f	float	(10)		single precision floating pt.
 *	h,x	short	 16	 no
 *	H,X	long	 16	 no
 *	i	short	 10	yes
 *	I,l,L	long	 10	yes
D 5
 *	o	short	  8	 no	(default conversion)
E 5
I 5
 *	o,B	short	  8	 no	(default conversion)
E 5
 *	O	long	  8	 no
I 5
D 10
 *	s	string	 (8)		ASCII graphic strings
E 10
I 10
 *	s[n]	string	 (8)		ASCII graphic strings
E 10
E 5
 *
 *	p				indicate EVEN parity on 'a' conversion
 *	P				indicate ODD parity on 'a' conversion
 *	v				show all data - don't skip like lines.
I 10
 *	w[n]				bytes per display line
E 10
 *
 * More than one format character may be given.
 * If {file} is not specified, standard input is read.
 * If {file} is not specified, then {offset} must start with '+'.
D 10
 * {Offset} may be HEX (0xnnn), OCTAL (0nn), or decimal (nnn.); the default
 * is the same as the address radix, which will be the same as the first
 * object radix.
E 10
I 10
 * {Offset} may be HEX (0xnnn), OCTAL (0nn), or decimal (nnn.).
 * The default is octal. The same radix will be used to display the address.
E 10
 */

#include <stdio.h>

D 5
#define NO	0
#define YES	1
#define EVEN	-1
#define ODD	1
#define UNSIGNED 0
#define SIGNED	1
E 5
I 5
D 10
#define DBUF_SIZE      16
E 10
I 10
#define DBUF_SIZE	BUFSIZ
#define BIG_DBUF	32
E 10
#define NO		0
#define YES		1
#define EVEN	       -1
#define ODD		1
#define UNSIGNED	0
#define SIGNED		1
#define PADDR		1
#define MIN_SLEN	3
E 5

int	a_put();
int	b_put();
int	c_put();
int	s_put();
int	us_put();
int	l_put();
int	f_put();
int	d_put();
I 5
int	st_put();
E 5

struct dfmt {
	int	df_field;	/* external field required for object */
	int	df_size;	/* size (bytes) of object */
	int	df_radix;	/* conversion radix */
	int	df_signed;	/* signed? flag */
I 5
	int	df_paddr;	/* "put address on each line?" flag */
E 5
	int	(*df_put)();	/* function to output object */
D 5
	char	*df_fmt;
E 5
I 5
	char	*df_fmt;	/* output string format */
E 5
} *conv_vec[32];		/* vector of conversions to be done */

D 5
struct dfmt	ascii	= { 3, sizeof (char),   10,        0,  a_put, 0};
struct dfmt	byte	= { 3, sizeof (char),    8, UNSIGNED,  b_put, 0};
struct dfmt	cchar	= { 3, sizeof (char),    8, UNSIGNED,  c_put, 0};
struct dfmt	u_s_oct	= { 6, sizeof (short),   8, UNSIGNED, us_put, 0};
struct dfmt	u_s_dec	= { 5, sizeof (short),  10, UNSIGNED, us_put, 0};
struct dfmt	u_s_hex	= { 4, sizeof (short),  16, UNSIGNED, us_put, 0};
struct dfmt	u_l_oct	= {11, sizeof (long),    8, UNSIGNED,  l_put, 0};
struct dfmt	u_l_dec	= {10, sizeof (long),   10, UNSIGNED,  l_put, 0};
struct dfmt	u_l_hex	= { 8, sizeof (long),   16, UNSIGNED,  l_put, 0};
struct dfmt	s_s_dec	= { 6, sizeof (short),  10,   SIGNED,  s_put, 0};
struct dfmt	s_l_dec	= {11, sizeof (long),   10,   SIGNED,  l_put, 0};
struct dfmt	flt	= {14, sizeof (float),  10,   SIGNED,  f_put, 0};
struct dfmt	dble	= {21, sizeof (double), 10,   SIGNED,  d_put, 0};
E 5
I 5
struct dfmt	ascii	= { 3, sizeof (char),   10,        0, PADDR,  a_put, 0};
struct dfmt	byte	= { 3, sizeof (char),    8, UNSIGNED, PADDR,  b_put, 0};
struct dfmt	cchar	= { 3, sizeof (char),    8, UNSIGNED, PADDR,  c_put, 0};
struct dfmt	u_s_oct	= { 6, sizeof (short),   8, UNSIGNED, PADDR, us_put, 0};
struct dfmt	u_s_dec	= { 5, sizeof (short),  10, UNSIGNED, PADDR, us_put, 0};
struct dfmt	u_s_hex	= { 4, sizeof (short),  16, UNSIGNED, PADDR, us_put, 0};
struct dfmt	u_l_oct	= {11, sizeof (long),    8, UNSIGNED, PADDR,  l_put, 0};
struct dfmt	u_l_dec	= {10, sizeof (long),   10, UNSIGNED, PADDR,  l_put, 0};
struct dfmt	u_l_hex	= { 8, sizeof (long),   16, UNSIGNED, PADDR,  l_put, 0};
struct dfmt	s_s_dec	= { 6, sizeof (short),  10,   SIGNED, PADDR,  s_put, 0};
struct dfmt	s_l_dec	= {11, sizeof (long),   10,   SIGNED, PADDR,  l_put, 0};
struct dfmt	flt	= {14, sizeof (float),  10,   SIGNED, PADDR,  f_put, 0};
struct dfmt	dble	= {21, sizeof (double), 10,   SIGNED, PADDR,  d_put, 0};
struct dfmt	string	= { 0,               0,  8,        0,    NO, st_put, 0};
E 5

I 4

D 5
char	usage[]	= "od [-abcdfhilopvx] [file] [[+]offset[.][b] [label]]";
E 4
char	dbuf[16];
char	lastdbuf[16];
E 5
I 5
D 10
char	usage[]	= "usage: od [-abcdfhilopsvx] [file] [[+]offset[.][b] [label]]";
E 10
I 10
char	usage[]	="usage: od [-abcdfhilopswvx] [file] [[+]offset[.][b] [label]]";
E 10
char	dbuf[DBUF_SIZE];
char	lastdbuf[DBUF_SIZE];
E 5
D 7
int	addr_base;
E 7
I 7
D 10
int	addr_base = 8;			/* default address base is OCTAL */
E 7
long	addr;
I 4
long	label = -1L;
E 4
int	_parity = NO;
E 10
I 10
int	addr_base	= 8;		/* default address base is OCTAL */
long	addr		= 0L;		/* current file offset */
long	label		= -1L;		/* current label; -1 is "off" */
int	dbuf_size	= 16;		/* file bytes / display line */
int	_parity		= NO;		/* show parity on ascii bytes */
E 10
char	fmt[]	= "            %s";	/* 12 blanks */
char	*icvt();
I 5
char	*scvt();
E 5
char	*underline();
I 4
long	get_addr();
E 4

I 4

I 5
/*
 * special form of _ctype
 */

#define A	01
#define G	02
#define D	04
#define P	010
#define X	020
#define isdigit(c)	(_ctype[c] & D)
#define isascii(c)	(_ctype[c] & A)
#define isgraphic(c)	(_ctype[c] & G)
#define isprint(c)	(_ctype[c] & P)
#define ishex(c)	(_ctype[c] & (X|D))

char	_ctype[256] = {
/* 000 */	0,	0,	0,	0,	0,	0,	0,	0,
/* 010 */	A,	A,	A,	0,	A,	A,	0,	0,
/* 020 */	0,	0,	0,	0,	0,	0,	0,	0,
/* 030 */	0,	0,	0,	0,	0,	0,	0,	0,
/* 040 */     P|A,  P|G|A,  P|G|A,  P|G|A,  P|G|A,  P|G|A,  P|G|A,  P|G|A,
/* 050 */   P|G|A,  P|G|A,  P|G|A,  P|G|A,  P|G|A,  P|G|A,  P|G|A,  P|G|A,
/* 060 */ P|G|D|A,P|G|D|A,P|G|D|A,P|G|D|A,P|G|D|A,P|G|D|A,P|G|D|A,P|G|D|A,
/* 070 */ P|G|D|A,P|G|D|A,  P|G|A,  P|G|A,  P|G|A,  P|G|A,  P|G|A,  P|G|A,
/* 100 */   P|G|A,  P|G|A,  P|G|A,  P|G|A,  P|G|A,  P|G|A,  P|G|A,  P|G|A,
/* 110 */   P|G|A,  P|G|A,  P|G|A,  P|G|A,  P|G|A,  P|G|A,  P|G|A,  P|G|A,
/* 120 */   P|G|A,  P|G|A,  P|G|A,  P|G|A,  P|G|A,  P|G|A,  P|G|A,  P|G|A,
/* 130 */   P|G|A,  P|G|A,  P|G|A,  P|G|A,  P|G|A,  P|G|A,  P|G|A,  P|G|A,
/* 140 */   P|G|A,X|P|G|A,X|P|G|A,X|P|G|A,X|P|G|A,X|P|G|A,X|P|G|A,  P|G|A,
/* 150 */   P|G|A,  P|G|A,  P|G|A,  P|G|A,  P|G|A,  P|G|A,  P|G|A,  P|G|A,
/* 160 */   P|G|A,  P|G|A,  P|G|A,  P|G|A,  P|G|A,  P|G|A,  P|G|A,  P|G|A,
/* 170 */   P|G|A,  P|G|A,  P|G|A,  P|G|A,  P|G|A,  P|G|A,  P|G|A,	0,
/* 200 */	0,	0,	0,	0,	0,	0,	0,	0,
/* 210 */	0,	0,	0,	0,	0,	0,	0,	0,
/* 220 */	0,	0,	0,	0,	0,	0,	0,	0,
/* 230 */	0,	0,	0,	0,	0,	0,	0,	0,
/* 240 */	0,	0,	0,	0,	0,	0,	0,	0,
/* 250 */	0,	0,	0,	0,	0,	0,	0,	0,
/* 260 */	0,	0,	0,	0,	0,	0,	0,	0,
/* 270 */	0,	0,	0,	0,	0,	0,	0,	0,
/* 300 */	0,	0,	0,	0,	0,	0,	0,	0,
/* 310 */	0,	0,	0,	0,	0,	0,	0,	0,
/* 320 */	0,	0,	0,	0,	0,	0,	0,	0,
/* 330 */	0,	0,	0,	0,	0,	0,	0,	0,
/* 340 */	0,	0,	0,	0,	0,	0,	0,	0,
/* 350 */	0,	0,	0,	0,	0,	0,	0,	0,
/* 360 */	0,	0,	0,	0,	0,	0,	0,	0,
/* 370 */	0,	0,	0,	0,	0,	0,	0,	0,
};


E 5
E 4
main(argc, argv)
D 5
char **argv;
E 5
I 5
int	argc;
char	**argv;
E 5
{
	register char *p;
	register char *l;
	register n, same;
	struct dfmt	*d;
	struct dfmt	**cv = conv_vec;
	int	showall = NO;
	int	field, llen, nelm;
	int	max_llen = 0;

	argv++;
I 4
	argc--;
E 4
D 10
	max_llen = max_nelm = 0;
E 10

D 4
	if(argc > 1) {
E 4
I 4
D 5
	if(argc > 0) {
E 5
I 5
	if(argc > 0)
	{
E 5
E 4
		p = *argv;
D 5
		if(*p == '-') {
			while(*++p != '\0') {
				switch(*p) {
E 5
I 5
		if(*p == '-')
		{
			while(*++p != '\0')
			{
				switch(*p)
				{
E 5
				case 'a':
					d = &ascii;
					break;
				case 'b':
					d = &byte;
					break;
				case 'c':
					d = &cchar;
					break;
				case 'd':
					d = &u_s_dec;
					break;
				case 'D':
					d = &u_l_dec;
					break;
				case 'e':
				case 'F':
					d = &dble;
					break;
				case 'f':
					d = &flt;
					break;
				case 'h':
				case 'x':
					d = &u_s_hex;
					break;
				case 'H':
				case 'X':
					d = &u_l_hex;
					break;
				case 'i':
					d = &s_s_dec;
					break;
				case 'I':
				case 'l':
				case 'L':
					d = &s_l_dec;
					break;
				case 'o':
I 5
				case 'B':
E 5
					d = &u_s_oct;
					break;
				case 'O':
					d = &u_l_oct;
					break;
				case 'p':
					_parity = EVEN;
					continue;
				case 'P':
					_parity = ODD;
					continue;
I 5
				case 's':
					d = &string;
					*(cv++) = d;
D 8
					if (addr_base == 0)
						addr_base = d->df_radix;
E 8
					while (isdigit(p[1]))
						d->df_size = (10 * d->df_size) + (*++p - '0');
					if (d->df_size <= 0)
						d->df_size = MIN_SLEN;
					showall = YES;
					continue;
I 10
				case 'w':
					dbuf_size = 0;
					while (isdigit(p[1]))
						dbuf_size = (10 * dbuf_size) + (*++p - '0');
					if (dbuf_size == 0)
						dbuf_size = BIG_DBUF;
					continue;
E 10
E 5
				case 'v':
					showall = YES;
					continue;
I 4
				default:
					printf("od: bad flag -%c\n", *p);
					puts(usage);
					exit(1);
E 4
				}
D 5
				nelm = 16 / d->df_size;
E 5
I 5
D 10
				nelm = DBUF_SIZE / d->df_size;
E 5
				llen = (d->df_field + 1) * nelm;
				if (llen > max_llen)
					max_llen = llen;
				if (nelm > max_nelm)
					max_nelm = nelm;
				/*
				 * nelm will always be a power of 2.
				 * line length must always be multiple
				 * of max_nelm.
				 */
				nelm = max_nelm - 1;
				max_llen = (max_llen + nelm) & (~nelm);
E 10
D 8
				if (addr_base == 0)
					addr_base = d->df_radix;
E 8
				*(cv++) = d;
			}
			argc--;
			argv++;
		}
	}

D 5
	if(cv == conv_vec) {
E 5
I 5
	/*
	 * if nothing spec'd, setup default conversion.
	 */
	if(cv == conv_vec)
D 10
	{
E 10
E 5
D 8
		addr_base = 8;
E 8
		*(cv++) = &u_s_oct;
D 4
		max_llen = (16 / u_s_oct.df_size) * (u_s_oct.df_field + 1);
E 4
I 4
D 5
		max_nelm = 16 / u_s_oct.df_size;
E 5
I 5
D 10
		max_nelm = DBUF_SIZE / u_s_oct.df_size;
E 5
		max_llen = max_nelm * (u_s_oct.df_field + 1);
E 4
	}
E 10
I 10

E 10
	*cv = (struct dfmt *)0;

I 5
	/*
I 10
	 * calculate display parameters
	 */
	for (cv = conv_vec; d = *cv; cv++)
	{
		nelm = (dbuf_size + d->df_size - 1) / d->df_size;
		llen = nelm * (d->df_field + 1);
		if (llen > max_llen)
			max_llen = llen;
	}

	/*
E 10
	 * setup df_fmt to point to uniform output fields.
	 */
E 5
D 10
	cv = conv_vec;
D 5
	while (d = *cv++) {
		nelm = 16 / d->df_size;
		field = max_llen / nelm;
		d->df_fmt = fmt + 12 - (field - d->df_field);
E 5
I 5
	while (d = *cv++)
E 10
I 10
	for (cv = conv_vec; d = *cv; cv++)
E 10
	{
		if (d->df_field)	/* only if external field is known */
		{
D 10
			nelm = DBUF_SIZE / d->df_size;
E 10
I 10
			nelm = (dbuf_size + d->df_size - 1) / d->df_size;
E 10
			field = max_llen / nelm;
			d->df_fmt = fmt + 12 - (field - d->df_field);
		}
E 5
	}

D 4
	if(argc > 1 && **argv != '+') {
E 4
I 4
D 5
	if(argc > 0 && **argv != '+') {
E 4
		if (freopen(*argv, "r", stdin) == NULL) {
E 5
I 5
	/*
	 * input file specified ?
	 */
	if(argc > 0 && **argv != '+')
	{
		if (freopen(*argv, "r", stdin) == NULL)
		{
E 5
D 11
			printf("od: cannot open %s\n", *argv);
E 11
I 11
			perror(*argv);
E 11
			exit(1);
		}
		argv++;
		argc--;
	}

I 5
	/*
	 * check for possible offset [label]
	 */
E 5
D 4
	if (argc > 1)
		offset(*argv);
E 4
I 4
	if (argc > 0)
	{
		addr = get_addr(*argv);
		offset(addr);
		argv++;
		argc--;
E 4

I 4
		if (argc > 0)
			label = get_addr(*argv);
	}

I 5
	/*
	 * main dump loop
	 */
E 5
E 4
	same = -1;
D 5
	while ((n = fread(dbuf, 1, sizeof(dbuf), stdin)) > 0) {
		if (same>=0 && strncmp(dbuf, lastdbuf, 16) == 0 && !showall) {
			if (same==0) {
E 5
I 5
D 10
	while ((n = fread(dbuf, 1, DBUF_SIZE, stdin)) > 0)
E 10
I 10
	while ((n = fread(dbuf, 1, dbuf_size, stdin)) > 0)
E 10
	{
D 7
		if (same>=0 && strncmp(dbuf, lastdbuf, DBUF_SIZE) == 0 && !showall)
E 7
I 7
D 10
		if (same>=0 && bufncmp(dbuf, lastdbuf, DBUF_SIZE) == 0 && !showall)
E 10
I 10
D 12
		if (same>=0 && bufncmp(dbuf, lastdbuf, dbuf_size) == 0 && !showall)
E 12
I 12
		if (same>=0 && bcmp(dbuf, lastdbuf, dbuf_size) == 0 && !showall)
E 12
E 10
E 7
		{
			if (same==0)
			{
E 5
				printf("*\n");
				same = 1;
			}
		}
D 5
		else {
E 5
I 5
		else
		{
E 5
			line(n);
			same = 0;
			p = dbuf;
			l = lastdbuf;
D 5
			for (nelm=0; nelm<16; nelm++) {
E 5
I 5
D 10
			for (nelm = 0; nelm < DBUF_SIZE; nelm++)
E 10
I 10
			for (nelm = 0; nelm < dbuf_size; nelm++)
E 10
			{
E 5
				*l++ = *p;
				*p++ = '\0';
			}
		}
		addr += n;
I 4
		if (label >= 0)
			label += n;
E 4
	}
D 4
	puts(icvt(addr, addr_base, UNSIGNED, 7));
E 4
I 4
D 5
	put_addr('\n');
E 5
I 5

	/*
	 * Some conversions require "flushing".
	 */
	n = 0;
	for (cv = conv_vec; *cv; cv++)
	{
		if ((*cv)->df_paddr)
		{
			if (n++ == 0)
				put_addr(addr, label, '\n');
		}
		else
			(*((*cv)->df_put))(0, *cv);
	}
I 14
	exit(0);
E 14
E 5
E 4
}

I 4
D 5
put_addr(c)
E 5
I 5
put_addr(a, l, c)
long	a;
long	l;
E 5
char	c;
{
D 5
	fputs(icvt(addr, addr_base, UNSIGNED, 7), stdout);
	if (label >= 0)
		printf(" (%s)", icvt(label, addr_base, UNSIGNED, 7));
E 5
I 5
	fputs(icvt(a, addr_base, UNSIGNED, 7), stdout);
	if (l >= 0)
		printf(" (%s)", icvt(l, addr_base, UNSIGNED, 7));
E 5
	putchar(c);
}

E 4
line(n)
int	n;
{
	register i, first;
	register struct dfmt *c;
	register struct dfmt **cv = conv_vec;

	first = YES;
D 5
	while (c = *cv++) {
		if (first) {
D 4
			printf("%s ", icvt(addr, addr_base, UNSIGNED, 7));
E 4
I 4
			put_addr(' ');
E 4
			first = NO;
D 4
		} else
E 4
I 4
		} else {
E 4
			putchar('\t');
I 4
			if (label >= 0)
				fputs("\t  ", stdout);
E 5
I 5
	while (c = *cv++)
	{
		if (c->df_paddr)
		{
			if (first)
			{
				put_addr(addr, label, ' ');
				first = NO;
			}
			else
			{
				putchar('\t');
				if (label >= 0)
					fputs("\t  ", stdout);
			}
E 5
		}
E 4
		i = 0;
		while (i < n)
			i += (*(c->df_put))(dbuf+i, c);
D 5
		putchar('\n');
E 5
I 5
		if (c->df_paddr)
			putchar('\n');
E 5
	}
}

s_put(n, d)
short	*n;
struct dfmt	*d;
{
	printf(d->df_fmt, icvt((long)*n, d->df_radix, d->df_signed, d->df_field));
	return(d->df_size);
}

us_put(n, d)
unsigned short	*n;
struct dfmt	*d;
{
	printf(d->df_fmt, icvt((long)*n, d->df_radix, d->df_signed, d->df_field));
	return(d->df_size);
}

l_put(n, d)
long	*n;
struct dfmt	*d;
{
	printf(d->df_fmt, icvt(*n, d->df_radix, d->df_signed, d->df_field));
	return(d->df_size);
}

d_put(f, d)
double	*f;
struct dfmt *d;
{
	char fbuf[24];
D 2
	sprintf(fbuf, "%21.14e", *f);
E 2
I 2
	struct l { long n[2]; };

#if	vax
	if ((((struct l *)f)->n[0] & 0xff00) == 0x8000)	/* Vax illegal f.p. */
D 13
		sprintf(fbuf, "    %08x %08x",
E 13
I 13
		(void)sprintf(fbuf, "    %08x %08x",
E 13
			((struct l *)f)->n[0], ((struct l *)f)->n[1]);
	else
#endif

D 13
		sprintf(fbuf, "%21.14e", *f);
E 13
I 13
		(void)sprintf(fbuf, "%21.14e", *f);
E 13
E 2
	printf(d->df_fmt, fbuf);
	return(d->df_size);
}

f_put(f, d)
float	*f;
struct dfmt *d;
{
	char fbuf[16];
D 2
	sprintf(fbuf, "%14.7e", *f);
E 2
I 2

#if	vax
	if ((*(long *)f & 0xff00) == 0x8000)	/* Vax illegal f.p. form */
D 13
		sprintf(fbuf, "      %08x", *(long *)f);
E 13
I 13
		(void)sprintf(fbuf, "      %08x", *(long *)f);
E 13
	else
#endif
D 13
		sprintf(fbuf, "%14.7e", *f);
E 13
I 13
		(void)sprintf(fbuf, "%14.7e", *f);
E 13
E 2
	printf(d->df_fmt, fbuf);
	return(d->df_size);
}


char	asc_name[34][4] = {
D 5
	"nul",
	"soh",
	"stx",
	"etx",
	"eot",
	"enq",
	"ack",
	"bel",
	" bs",
	" ht",
	" nl",
	" vt",
	" ff",
	" cr",
	" so",
	" si",
	"dle",
	"dc1",
	"dc2",
	"dc3",
	"dc4",
	"nak",
	"syn",
	"etb",
	"can",
	" em",
	"sub",
	"esc",
	" fs",
	" gs",
	" rs",
	" us",
	" sp",
	"del"
E 5
I 5
/* 000 */	"nul",	"soh",	"stx",	"etx",	"eot",	"enq",	"ack",	"bel",
/* 010 */	" bs",	" ht",	" nl",	" vt",	" ff",	" cr",	" so",	" si",
/* 020 */	"dle",	"dc1",	"dc2",	"dc3",	"dc4",	"nak",	"syn",	"etb",
/* 030 */	"can",	" em",	"sub",	"esc",	" fs",	" gs",	" rs",	" us",
/* 040 */	" sp",	"del"
E 5
};

a_put(cc, d)
char	*cc;
struct dfmt *d;
{
	int c = *cc;
	register char *s = "   ";
	register pbit = parity((int)c & 0377);

	c &= 0177;
D 5
	if (c > ' ' && c < 0177)
E 5
I 5
	if (isgraphic(c))
E 5
	{
D 5
		s[2] = *cc;
E 5
I 5
		s[2] = c;
E 5
		if (pbit == _parity)
D 3
			printf(d->df_fmt, underline(s, 1));
E 3
I 3
			printf(d->df_fmt, underline(s));
E 3
		else
			printf(d->df_fmt, s);
	}
	else
	{
		if (c == 0177)
			c = ' ' + 1;
		if (pbit == _parity)
D 3
			printf(d->df_fmt, underline(asc_name[c], 3));
E 3
I 3
			printf(d->df_fmt, underline(asc_name[c]));
E 3
		else
			printf(d->df_fmt, asc_name[c]);
	}
	return(1);
}

parity(word)
int	word;
{
	register int p = 0;
	register int w = word;

	if (w)
D 5
		do {
E 5
I 5
		do
		{
E 5
			p ^= 1;
		} while(w &= (~(-w)));
	return (p? ODD:EVEN);
}

char *
D 3
underline(s, n)
E 3
I 3
underline(s)
E 3
char	*s;
D 3
int	n;
E 3
{
	static char ulbuf[16];
	register char *u = ulbuf;

D 3
	while (n--) {
		if (*s && *s != ' ') {
E 3
I 3
D 5
	while (*s) {
		if (*s != ' ') {
E 5
I 5
	while (*s)
	{
		if (*s != ' ')
		{
E 5
E 3
			*u++ = '_';
			*u++ = '\b';
		}
		*u++ = *s++;
	}
	*u = '\0';
	return(ulbuf);
}

b_put(b, d)
char	*b;
struct dfmt *d;
{
	printf(d->df_fmt, icvt((long)*b & 0377, d->df_radix, d->df_signed, d->df_field));
	return(1);
}

c_put(cc, d)
char	*cc;
struct dfmt *d;
{
D 5
	int c = *cc & 0377;
	register char *s = "   ";
E 5
I 5
	register char	*s;
	register int	n;
	register int	c = *cc & 0377;
E 5

D 5
	if(c>037 && c<0177) {
		s[2] = *cc;
		printf(d->df_fmt, s);
		return(1);
E 5
I 5
	s = scvt(c, d);
	for (n = d->df_field - strlen(s); n > 0; n--)
		putchar(' ');
	printf(d->df_fmt, s);
	return(1);
}

char *scvt(c, d)
int	c;
struct dfmt	*d;
{
	static char s[2];

	switch(c)
	{
		case '\0':
			return("\\0");

		case '\b':
			return("\\b");

		case '\f':
			return("\\f");

		case '\n':
			return("\\n");

		case '\r':
			return("\\r");

		case '\t':
			return("\\t");

		default:
			if (isprint(c))
			{
				s[0] = c;
				return(s);
			}
			return(icvt((long)c, d->df_radix, d->df_signed, d->df_field));
E 5
	}
I 5
}
E 5

D 5
	switch(c) {
	case '\0':
		s = " \\0";
		break;
	case '\b':
		s = " \\b";
		break;
	case '\f':
		s = " \\f";
		break;
	case '\n':
		s = " \\n";
		break;
	case '\r':
		s = " \\r";
		break;
	case '\t':
		s = " \\t";
		break;
	default:
		s = icvt((long)c, d->df_radix, d->df_signed, d->df_field);
E 5
I 5
/*
 * Look for strings.
 * A string contains bytes > 037 && < 177, and ends with a null.
 * The minimum length is given in the dfmt structure.
 */

#define CNULL		'\0'
#define S_EMPTY	0
#define S_FILL	1
#define	S_CONT	2
#define SBUFSIZE	1024

static char	str_buf[SBUFSIZE];
static int	str_mode = S_EMPTY;
static char	*str_ptr;
static long	str_addr;
static long	str_label;

D 6
st_put(c, d)
register char	*c;
E 6
I 6
st_put(cc, d)
char	*cc;
E 6
struct dfmt	*d;
{
D 6
	if (c == 0)
E 6
I 6
	register int	c;

	if (cc == 0)
E 6
	{
		pr_sbuf(d, YES);
I 6
		return(1);
E 6
E 5
	}
D 5
	printf(d->df_fmt, s);
E 5
I 5
D 6
	else if (str_mode & S_FILL)
E 6
I 6

	c = (*cc & 0377);

	if (str_mode & S_FILL)
E 6
	{
D 6
		if (isascii(*c))
			put_sbuf(*c, d);
E 6
I 6
		if (isascii(c))
			put_sbuf(c, d);
E 6
		else
		{
			*str_ptr = CNULL;
D 6
			if (*c == CNULL)
E 6
I 6
			if (c == NULL)
E 6
				pr_sbuf(d, YES);
			str_mode = S_EMPTY;
		}
	}
D 6
	else if (isascii(*c))
E 6
I 6
	else if (isascii(c))
E 6
	{
		str_mode = S_FILL;
D 6
		str_addr = addr + (c - dbuf);	/* ugly */
E 6
I 6
		str_addr = addr + (cc - dbuf);	  /* ugly */
E 6
		if ((str_label = label) >= 0)
D 6
			str_label += (c - dbuf);/*  ''  */
E 6
I 6
			str_label += (cc - dbuf); /*  ''  */
E 6
		str_ptr = str_buf;
D 6
		put_sbuf(*c, d);
E 6
I 6
		put_sbuf(c, d);
E 6
	}

E 5
	return(1);
}

I 5
put_sbuf(c, d)
D 6
char	c;
E 6
I 6
int	c;
E 6
struct dfmt	*d;
{
	*str_ptr++ = c;
	if (str_ptr >= (str_buf + SBUFSIZE))
	{
		pr_sbuf(d, NO);
		str_ptr = str_buf;
		str_mode |= S_CONT;
	}
}

pr_sbuf(d, end)
struct dfmt	*d;
int	end;
{
	register char	*p = str_buf;

	if (str_mode == S_EMPTY
	    || (!(str_mode & S_CONT) && (str_ptr - str_buf) < d->df_size))
		return;

	if (!(str_mode & S_CONT))
		put_addr(str_addr, str_label, ' ');

	while (p < str_ptr)
		fputs(scvt(*p++, d), stdout);

	if (end)
		putchar('\n');
}

E 5
/*
 * integer to ascii conversion
 *
 * This code has been rearranged to produce optimized runtime code.
 */

#define MAXINTLENGTH	32
static char	_digit[] = "0123456789abcdef";
static char	_icv_buf[MAXINTLENGTH+1];
static long	_mask = 0x7fffffff;

char *
D 15
icvt (value, radix, signed, ndigits)
E 15
I 15
icvt (value, radix, hassign, ndigits)
E 15
long	value;
int	radix;
D 15
int	signed;
E 15
I 15
int	hassign;
E 15
int	ndigits;
{
	register long	val = value;
	register long	rad = radix;
	register char	*b = &_icv_buf[MAXINTLENGTH];
	register char	*d = _digit;
	register long	tmp1;
	register long	tmp2;
	long	rem;
	long	kludge;
	int	sign;

	if (val == 0)
	{
		*--b = '0';
		sign = 0;
		goto done; /*return(b);*/
	}

D 15
	if (signed && (sign = (val < 0)))	/* signed conversion */
E 15
I 15
	if (hassign && (sign = (val < 0)))	/* signed conversion */
E 15
	{
		/*
		 * It is necessary to do the first divide
		 * before the absolute value, for the case -2^31
		 *
		 * This is actually what is being done...
		 * tmp1 = (int)(val % rad);
		 * val /= rad;
		 * val = -val
		 * *--b = d[-tmp1];
		 */
		tmp1 = val / rad;
		*--b = d[(tmp1 * rad) - val];
		val = -tmp1;
	}
	else				/* unsigned conversion */
	{
		sign = 0;
		if (val < 0)
		{	/* ALL THIS IS TO SIMULATE UNSIGNED LONG MOD & DIV */
			kludge = _mask - (rad - 1);
			val &= _mask;
			/*
			 * This is really what's being done...
			 * rem = (kludge % rad) + (val % rad);
			 * val = (kludge / rad) + (val / rad) + (rem / rad) + 1;
			 * *--b = d[rem % rad];
			 */
			tmp1 = kludge / rad;
			tmp2 = val / rad;
			rem = (kludge - (tmp1 * rad)) + (val - (tmp2 * rad));
			val = ++tmp1 + tmp2;
			tmp1 = rem / rad;
			val += tmp1;
			*--b = d[rem - (tmp1 * rad)];
		}
	}

	while (val)
	{
		/*
		 * This is really what's being done ...
		 * *--b = d[val % rad];
		 * val /= rad;
		 */
		tmp1 = val / rad;
		*--b = d[val - (tmp1 * rad)];
		val = tmp1;
	}

done:
	if (sign)
		*--b = '-';

	tmp1 = ndigits - (&_icv_buf[MAXINTLENGTH] - b);
D 15
	tmp2 = signed? ' ':'0';
E 15
I 15
	tmp2 = hassign? ' ':'0';
E 15
	while (tmp1 > 0)
	{
		*--b = tmp2;
		tmp1--;
	}

	return(b);
}

D 4
offset(s)
E 4
I 4
D 5
long
get_addr(s)
E 5
I 5
long get_addr(s)
E 5
E 4
register char *s;
{
	register char *p;
D 4
	long a;
E 4
I 4
	register long a;
E 4
	register int d;

	if (*s=='+')
		s++;
D 5
	if (*s=='x') {
E 5
I 5
	if (*s=='x')
	{
E 5
		s++;
		addr_base = 16;
D 5
	} else if (*s=='0' && s[1]=='x') {
E 5
I 5
	}
	else if (*s=='0' && s[1]=='x')
	{
E 5
		s += 2;
		addr_base = 16;
D 5
	} else if (*s == '0')
E 5
I 5
	}
	else if (*s == '0')
E 5
		addr_base = 8;
	p = s;
D 5
	while(*p) {
E 5
I 5
	while(*p)
	{
E 5
		if (*p++=='.')
			addr_base = 10;
	}
D 5
	for (a=0; *s; s++) {
E 5
I 5
	for (a=0; *s; s++)
	{
E 5
		d = *s;
D 5
		if(d>='0' && d<='9')
E 5
I 5
		if(isdigit(d))
E 5
			a = a*addr_base + d - '0';
D 5
		else if (d>='a' && d<='f' && addr_base==16)
E 5
I 5
		else if (ishex(d) && addr_base==16)
E 5
			a = a*addr_base + d + 10 - 'a';
		else
			break;
	}
I 4

E 4
	if (*s == '.')
		s++;
D 4
	if(*s=='b' || *s=='B')
E 4
I 4
	if(*s=='b')
E 4
		a *= 512;
I 4
	if(*s=='B')
		a *= 1024;

	return(a);
I 7
D 12
}

bufncmp(a, b, n)
char	*a;
char	*b;
int	n;
{
	while (n--)
		if (*a++ != *b++)
			return(1);
E 12
E 7
}

offset(a)
long	a;
{
E 4
	if (canseek(stdin))
D 9
		fseek(stdin, a, 0);
	else
		dumbseek(stdin, a);
E 9
I 9
	{
		/*
		 * in case we're accessing a raw disk,
		 * we have to seek in multiples of a physical block.
		 */
		fseek(stdin, a & 0xfffffe00L, 0);
		a &= 0x1ffL;
	}
	dumbseek(stdin, a);
E 9
D 4
	addr = a;
E 4
}

dumbseek(s, offset)
FILE	*s;
long	offset;
{
	char	buf[BUFSIZ];
	int	n;
	int	nr;

	while (offset > 0)
	{
		nr = (offset > BUFSIZ) ? BUFSIZ : (int)offset;
		if ((n = fread(buf, 1, nr, s)) != nr)
		{
			fprintf(stderr, "EOF\n");
			exit(1);
		}
		offset -= n;
	}
}

#include <sys/types.h>
#include <sys/stat.h>

canseek(f)
FILE	*f;
{
	struct stat statb;

	return( (fstat(fileno(f),&statb)==0) &&
		(statb.st_nlink > 0) &&		/*!pipe*/
		(!isatty(fileno(f))) );
}
E 1
