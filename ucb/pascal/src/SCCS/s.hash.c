h20688
s 00007/00003/00192
d D 5.1 85/06/05 14:20:26 dist 8 7
c Add copyright
e
s 00000/00000/00195
d D 2.1 84/02/08 20:41:43 aoki 7 6
c synchronize to version 2
e
s 00000/00000/00195
d D 1.6 83/09/19 06:58:47 thien 6 5
c Restoring to unlinted version
e
s 00017/00010/00178
d D 1.5 83/08/19 04:58:01 thien 5 4
c The changes were made to allow successful linting
e
s 00013/00004/00175
d D 1.4 82/08/29 15:36:52 mckusick 4 3
c conditionally load non-standard keywords based on -s flag.
e
s 00000/00001/00179
d D 1.3 82/08/27 00:34:08 mckusick 3 2
c convert "assert" from being a reserved word to being a non-standard procedure
e
s 00001/00001/00179
d D 1.2 80/11/24 18:58:51 peter 2 1
c malloc returns 0 on out of memory, not -1 as in version 6.
e
s 00180/00000/00000
d D 1.1 80/08/27 19:55:12 peter 1 0
c date and time created 80/08/27 19:55:12 by peter
e
u
U
t
T
I 1
D 8
/* Copyright (c) 1979 Regents of the University of California */
E 8
I 8
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 8

I 5
#ifndef lint
E 5
D 8
static	char sccsid[] = "%Z%%M% %I% %G%";
I 5
#endif
E 8
I 8
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 8
E 5

#include "whoami.h"
#include "0.h"
I 5
#include "tree_ty.h"		/* must be included for yy.h */
E 5
#include "yy.h"

/*
 * The definition for the segmented hash tables.
 */
struct ht {
	int	*ht_low;
	int	*ht_high;
	int	ht_used;
} htab[MAXHASH];

/*
 * This is the array of keywords and their
 * token values, which are hashed into the table
 * by inithash.
 */
struct kwtab yykey[] = {
	"and",		YAND,
	"array",	YARRAY,
D 3
	"assert",	YASSERT,
E 3
	"begin",	YBEGIN,
	"case",		YCASE,
	"const",	YCONST,
	"div",		YDIV,
	"do",		YDO,
	"downto",	YDOWNTO,
	"else",		YELSE,
	"end",		YEND,
	"file",		YFILE,
	"for",		YFOR,
	"forward",	YFORWARD,
	"function",	YFUNCTION,
	"goto",		YGOTO,
	"if",		YIF,
	"in",		YIN,
	"label",	YLABEL,
	"mod",		YMOD,
	"nil",		YNIL,
	"not",		YNOT,
	"of",		YOF,
	"or",		YOR,
	"packed",	YPACKED,
	"procedure",	YPROCEDURE,
	"program",	YPROG,
	"record",	YRECORD,
	"repeat",	YREPEAT,
	"set",		YSET,
	"then",		YTHEN,
	"to",		YTO,
	"type",		YTYPE,
	"until",	YUNTIL,
	"var",		YVAR,
	"while",	YWHILE,
	"with",		YWITH,
D 4
	"oct",		YOCT,	 /* non-standard Pascal */
	"hex",		YHEX,	 /* non-standard Pascal */
	"external",	YEXTERN, /* non-standard Pascal */
E 4
I 4
	0,		0,	 /* the following keywords are non-standard */
	"oct",		YOCT,
	"hex",		YHEX,
	"external",	YEXTERN,
E 4
	0
};

D 4
char	*lastkey	= &yykey[sizeof yykey/sizeof yykey[0]];
E 4
I 4
char *lastkey;
E 4

/*
 * Inithash initializes the hash table routines
 * by allocating the first hash table segment using
 * an already existing memory slot.
 */
#ifndef PI0
inithash()
#else
inithash(hshtab)
	int *hshtab;
#endif
{
	register int *ip;
#ifndef PI0
	static int hshtab[HASHINC];
#endif

	htab[0].ht_low = hshtab;
	htab[0].ht_high = &hshtab[HASHINC];
D 5
	for (ip = yykey; *ip; ip += 2)
		hash(ip[0], 0)[0] = ip;
E 5
I 5
	for (ip = ((int *)yykey); *ip; ip += 2)
		hash((char *) ip[0], 0)[0] = ((int) ip);
E 5
I 4
	/*
	 * If we are not running in "standard-only" mode,
	 * we load the non-standard keywords.
	 */
	if (!opt('s'))
		for (ip += 2; *ip; ip += 2)
D 5
			hash(ip[0], 0)[0] = ip;
E 5
I 5
			hash((char *) ip[0], 0)[0] = ((int) ip);
E 5
	lastkey = (char *)ip;
E 4
}

/*
 * Hash looks up the s(ymbol) argument
 * in the string table, entering it if
 * it is not found. If save is 0, then
 * the argument string is already in
 * a safe place. Otherwise, if hash is
 * entering the symbol for the first time
 * it will save the symbol in the string
 * table using savestr.
 */
int *hash(s, save)
	char *s;
	int save;
{
	register int *h;
	register i;
	register char *cp;
	int *sym;
I 5
	struct cstruct *temp;
E 5
	struct ht *htp;
	int sh;

	/*
	 * The hash function is a modular hash of
	 * the sum of the characters with the sum
	 * doubled before each successive character
	 * is added.
	 */
	cp = s;
	if (cp == NIL)
		cp = token;	/* default symbol to be hashed */
	i = 0;
	while (*cp)
		i = i*2 + *cp++;
	sh = (i&077777) % HASHINC;
	cp = s;
	if (cp == NIL)
		cp = token;
	/*
	 * There are as many as MAXHASH active
	 * hash tables at any given point in time.
	 * The search starts with the first table
	 * and continues through the active tables
	 * as necessary.
	 */
	for (htp = htab; htp < &htab[MAXHASH]; htp++) {
		if (htp->ht_low == NIL) {
D 5
			cp = (char *) calloc(sizeof ( int * ), HASHINC);
E 5
I 5
			cp = (char *) pcalloc(sizeof ( int * ), HASHINC);
E 5
D 2
			if (cp == -1) {
E 2
I 2
			if (cp == 0) {
E 2
				yerror("Ran out of memory (hash)");
				pexit(DIED);
			}
D 5
			htp->ht_low = cp;
E 5
I 5
			htp->ht_low = ((int *)cp);
E 5
			htp->ht_high = htp->ht_low + HASHINC;
			cp = s;
			if (cp == NIL)
				cp = token;
		}
		h = htp->ht_low + sh;
		/*
		 * quadratic rehash increment
		 * starts at 1 and incremented
		 * by two each rehash.
		 */
		i = 1;
		do {
			if (*h == 0) {
				if (htp->ht_used > (HASHINC * 3)/4)
					break;
				htp->ht_used++;
				if (save != 0) {
					*h = (int) savestr(cp);
				} else
D 5
					*h = s;
E 5
I 5
					*h = ((int) s);
E 5
				return (h);
			}
D 5
			sym = *h;
			if (sym < lastkey && sym >= yykey)
				sym = *sym;
			if (sym->pchar == *cp && strcmp(sym, cp) == 0)
E 5
I 5
			sym = ((int *) *h);
			if (sym < ((int *) lastkey) && sym >= ((int *) yykey))
				sym = ((int *) *sym);
			temp = ((struct cstruct *) sym);
			if (temp->pchar == *cp && pstrcmp((char *) sym, cp) == 0)
E 5
				return (h);
			h += i;
			i += 2;
			if (h >= htp->ht_high)
				h -= HASHINC;
		} while (i < HASHINC);
	}
	yerror("Ran out of hash tables");
	pexit(DIED);
I 5
	return (NIL);

E 5
}
E 1
