h63224
s 00010/00005/00222
d D 4.5 88/06/27 16:35:17 bostic 5 4
c install approved copyright notice
e
s 00017/00005/00210
d D 4.4 87/11/30 15:09:22 bostic 4 3
c Berkeley code, add copyright
e
s 00182/00171/00033
d D 4.3 87/04/02 20:12:40 bostic 3 2
c it would be difficult to explain.  complete rewrite.
e
s 00006/00004/00198
d D 4.2 86/11/26 13:52:10 bostic 2 1
c bug report 4.3BSD/games/4
e
s 00202/00000/00000
d D 4.1 82/10/24 18:26:36 mckusick 1 0
c date and time created 82/10/24 18:26:36 by mckusick
e
u
U
t
T
I 3
/*
D 4
 * Copyright (c) 1987 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 4
I 4
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 5
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific written prior permission. This software
 * is provided ``as is'' without express or implied warranty.
E 5
I 5
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
E 5
E 4
 */
E 3
I 1

I 3
#ifndef lint
E 3
D 4
static char sccsid[] = "	%M%	%I%	%E%	";
I 3
#endif
E 4
I 4
char copyright[] =
"%Z% Copyright (c) 1988 Regents of the University of California.\n\
 All rights reserved.\n";
#endif /* not lint */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 4
E 3

I 2
#include <stdio.h>
I 3
#include <ctype.h>
E 3

E 2
D 3
int	flag;
int max = 21;
char	*card[] =
{
	"hundred",
	"thousand",
	"million",
	"billion",
	"trillion",
	"quadrillion",
	"quintillion",
	"sextillion",
	"septillion",
	"octillion",
	"nonillion",
	"decillion",
	"undecillion",
	"duodecillion",
	"tredecillion",
	"quattuordecillion",
	"quindecillion",
	"sexdecillion",
	"septendecillion",
	"octodecillion",
	"novemdecillion",
	"vigintillion"
E 3
I 3
#define	YES		1
#define	NO		0
#define	EOS		'\0'
#define	MAXNUM		65		/* biggest number we handle */

static char	*name1[] = {
	"",		"one",		"two",		"three",
	"four",		"five",		"six",		"seven",
	"eight",	"nine",		"ten",		"eleven",
	"twelve",	"thirteen",	"fourteen",	"fifteen",
	"sixteen",	"seventeen",	"eighteen",	"nineteen",
},
		*name2[] = {
	"",		"ten",		"twenty",	"thirty",
	"forty",	"fifty",	"sixty",	"seventy",
	"eighty",	"ninety",
},
		*name3[] = {
	"hundred",	"thousand",	"million",	"billion",
	"trillion",	"quadrillion",	"quintillion",	"sextillion",
	"septillion",	"octillion",	"nonillion",	"decillion",
	"undecillion",	"duodecillion",	"tredecillion",	"quattuordecillion",
	"quindecillion",		"sexdecillion",	
	"septendecillion",		"octodecillion",
	"novemdecillion",		"vigintillion",
E 3
};
D 3
char *unit[] = {
	"zero",
	"one",
	"two",
	"three",
	"four",
	"five",
	"six",
	"seven",
	"eight",
	"nine"
};
char *teen[] = {
	"ten",
	"eleven",
	"twelve",
	"thirteen",
	"fourteen",
	"fifteen",
	"sixteen",
	"seventeen",
	"eighteen",
	"nineteen"
};
char *decade[] = {
	"zero",
	"ten",
	"twenty",
	"thirty",
	"forty",
	"fifty",
	"sixty",
	"seventy",
	"eighty",
	"ninety"
};
char	line[100];
main()
E 3
I 3

main(argc,argv)
	int	argc;
	char	**argv;
E 3
{
D 3
	register c, i, fraction;
	int r;
E 3
I 3
	register int	cnt;
	char	line[MAXNUM * 2 + 2];		/* MAXNUM '.' MAXNUM '\0' */
E 3

D 3

	fraction = 0;
D 2
	while(c = getchar()) {
E 2
I 2
	while((c = getchar()) != EOF) {
E 2
		if(!digit(c))  {
			fraction = (c == '.');
			putchar(c);
			continue;
E 3
I 3
	if (argc > 1)
		for (cnt = 1;cnt < argc;++cnt) {
			convert(argv[cnt]);
			puts("...");
E 3
		}
D 3
		if(fraction) {
			while(digit(c)) {
				putchar(' ');
				putchar(c);
D 2
				if(!(c=getchar()))
E 2
I 2
				if((c=getchar()) == EOF)
E 2
					exit(1);
			}
			putchar(' ');
			goto out;
E 3
I 3
	else
		while (fgets(line,sizeof(line),stdin)) {
			convert(line);
			puts("...");
E 3
		}
D 3

		putchar(' ');
		i = 0;
		line[i++] = '0';
		line[i++] = '0';
		while(c == '0')
D 2
			if(!(c=getchar()))
E 2
I 2
			if((c=getchar()) == EOF)
E 2
				exit(1);
		while(digit(c)) {
			if(i < 98)
				line[i++] = c;
D 2
			if(!(c=getchar()))
E 2
I 2
			if((c=getchar()) == EOF)
E 2
				exit(1);
		}
		line[i] = 0;
		r = i/3;
		if(r == 0) {
			print("zero");
			goto out;
		}
		conv(line+i-3*r, r);

out:
		fraction = (c == '.');
		nline();
		printf("...\n");
		if(c != '\n')
			putchar(c);
	}
E 3
I 3
	exit(0);
E 3
}

D 3
conv(p, c)
char *p;
E 3
I 3
static
convert(line)
	char	*line;
E 3
{
I 3
	register int	len,
			ret;
	register char	*C,
			*fraction;
E 3

D 3
	if(c > max) {
		conv(p, c-max);
		print(card[max]);
		nline();
		p += (c-max)*3;
		c = max;
E 3
I 3
	for (fraction = NULL, C = line;*C && *C != '\n';++C)
		if (!isdigit(*C))
			switch(*C) {
			case '-':
				if (C != line)
					usage(NO);
				break;
			case '.':
				if (!fraction) {
					fraction = C + 1;
					*C = EOS;
					break;
				}
			default:
				usage(NO);
			}
	*C = EOS;
	if (*line == '-') {
		puts("minus");
		++line;
E 3
	}
D 3
	while(c > 1) {
		c--;
		conv(p, 1);
		cprint(card[c]);
		nline();
		p += 3;
E 3
I 3
	ret = NO;
	if (len = strlen(line)) {
		if (len > MAXNUM)
			usage(YES);
		ret = unit(len,line);
E 3
	}
D 3
	ones(p[0]);
	cprint(card[0]);
	tens(p);
	ones(p[2]);
E 3
I 3
	if (fraction && (len = strlen(fraction))) {
		if (len > MAXNUM)
			usage(YES);
		for (C = fraction;*C;++C)
			if (*C != '0') {
				if (ret)
					puts("and");
				if (unit(len,fraction)) {
					++ret;
					pfract(len);
				}
				break;
			}
	}
	if (!ret)
		puts("zero.");
E 3
}

D 3
ones(d)
E 3
I 3
static
unit(len,C)
	register int	len;
	register char	*C;
E 3
{
D 3
	if(d=='0')
		return;
	print(unit[d-'0']);
}
E 3
I 3
	register int	off,
			ret;
E 3

D 3
tens(p)
char *p;
{

	switch(p[1]) {

	case '0':
		return;

	case '1':
		print(teen[p[2]-'0']);
		p[2] = '0';
		return;
E 3
I 3
	ret = NO;
	if (len > 3) {
		if (len % 3) {
			off = len % 3;
			len -= off;
			if (number(C,off)) {
				ret = YES;
				printf(" %s.\n",name3[len / 3]);
			}
			C += off;
		}
		for (;len > 3;C += 3) {
			len -= 3;
			if (number(C,3)) {
				ret = YES;
				printf(" %s.\n",name3[len / 3]);
			}
		}
E 3
	}
D 3

	print(decade[p[1]-'0']);
E 3
I 3
	if (number(C,len)) {
		puts(".");
		ret = YES;
	}
	return(ret);
E 3
}

D 3

digit(c)
E 3
I 3
static
number(C,len)
	register char	*C;
	int	len;
E 3
{
I 3
	register int	val,
			ret;
E 3

D 3
	if(c < '0' || c > '9')
		return(0);
	return(1);
E 3
I 3
	ret = 0;
	switch(len) {
	case 3:
		if (*C != '0') {
			++ret;
			printf("%s hundred",name1[*C - '0']);
		}
		++C;
		/*FALLTHROUGH*/
	case 2:
		val = (C[1] - '0') + (C[0] - '0') * 10;
		if (val) {
			if (ret++)
				putchar(' ');
			if (val < 20)
				fputs(name1[val],stdout);
			else {
				fputs(name2[val / 10],stdout);
				if (val % 10)
					printf("-%s",name1[val % 10]);
			}
		}
		break;
	case 1:
		if (*C != '0') {
			++ret;
			fputs(name1[*C - '0'],stdout);
		}
	}
	return(ret);
E 3
}

D 3
nline()
E 3
I 3
static
pfract(len)
	register int	len;
E 3
{
I 3
	static char	*pref[] = { "", "ten-", "hundred-" };
E 3

D 3
	if(flag)
		printf(".\n");
	flag = 0;
E 3
I 3
	switch(len) {
	case 1:
		puts("tenths.");
		break;
	case 2:
		puts("hundredths.");
		break;
	default:
		printf("%s%sths.\n",pref[len % 3],name3[len / 3]);
	}
E 3
}

D 3
cprint(s)
E 3
I 3
static
usage(toobig)
	int	toobig;
E 3
{
D 3

	if(flag)
		print(s);
}

print(s)
{

	if(flag)
		printf(" ");
	printf(s);
	flag = 1;
E 3
I 3
	if (toobig)
		fprintf(stderr,"number: number too large, max %d digits.\n",MAXNUM);
	fputs("usage: number # ...\n",stderr);
	exit(-1);
E 3
}
E 1
