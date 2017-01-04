h27372
s 00013/00007/00159
d D 7.2 86/12/15 20:26:53 sam 2 1
c lint
e
s 00166/00000/00000
d D 7.1 86/11/20 12:22:07 sam 1 0
c date and time created 86/11/20 12:22:07 by sam
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

/*
 * adb - symbol table routines
 */
#include "../kdb/defs.h"
#include <stab.h>

/*
 * Initialize the symbol table.
 */
setsym(sym, esym, strtab, strsize)
D 2
	struct nlist *sym, *esym;
	char *strtab;
E 2
I 2
	char *sym, *esym, *strtab;
E 2
{
	register struct nlist *sp;

D 2
	symtab = sym, esymtab = esym;
E 2
I 2
	symtab = (struct nlist *)sym, esymtab = (struct nlist *)esym;
E 2
	for (sp = symtab; sp < esymtab; sp++)
		if (sp->n_un.n_strx) {
			if (sp->n_un.n_strx > strsize) {
				printf("setsym: Bad string table index (%d)\n",
				    sp->n_un.n_strx);
				sp->n_un.n_strx = 0;	/* XXX */
				continue;
			}
			sp->n_un.n_name = strtab + sp->n_un.n_strx;
		}
}

/*
 * Lookup a symbol by name.
 */
struct nlist *
lookup(symstr)
	char *symstr;
{
	register struct nlist *sp;

	cursym = 0;
	if (symtab)
	for (sp = symtab; sp < esymtab; sp++)
		/* SHOULD DO SOME OF EQSYM INLINE TO SAVE TIME */
		if ((sp->n_type&N_STAB)==0 && eqsym(sp->n_un.n_name, symstr, '_'))
			return(cursym = sp);
	return (0);
}

/*
 * Find the closest symbol to val, and return
 * the difference between val and the symbol found.
 * Leave a pointer to the symbol found as cursym.
 */
findsym(val, type)
D 2
	register val;
E 2
I 2
	register long val;
E 2
	int type;
{
	register diff;
	register struct nlist *sp;

	cursym = 0;
	diff = MAXINT;
	if (type == NSYM || symtab == 0)
		return (diff);
	for (sp = symtab; sp < esymtab; sp++) {
		if (sp->n_type&N_STAB || (sp->n_type&N_EXT)==0)
			continue;
		if (val - sp->n_value < diff && val >= sp->n_value) {
			diff = val - sp->n_value;
			cursym = sp;
			if (diff == 0)
				break;
		}
	}
	return (diff);
}

/*
 * Advance cursym to the next local variable.
 * Leave its value in localval as a side effect.
 * Return 0 at end of file.
 */
localsym(cframe)
D 2
	ADDR cframe;
E 2
I 2
	long cframe;
E 2
{
	register int type;
	register struct nlist *sp;

	if (cursym)
	for (sp = cursym; ++sp < esymtab; ) {
		type = sp->n_type;
		if (sp->n_un.n_name[0] =='_' || type == N_FN)
			return (0);
		switch (type) {

		case N_TEXT:
		case N_TEXT|N_EXT:
		case N_DATA:
		case N_DATA|N_EXT:
		case N_BSS:
		case N_BSS|N_EXT:
			localval = sp->n_value;
			cursym = sp;
			return (1);

		case N_LSYM:
			localval = cframe - sp->n_value;
			cursym = sp;
			return (1);

		case N_PSYM:
		case N_ABS:
			localval = cframe + sp->n_value;
			cursym = sp;
			return (1);
		}
	}
	cursym = 0;
	return (0);
}

/*
 * Print value v and then the string s.
 * If v is not zero, then we look for a nearby symbol
 * and print name+offset if we find a symbol for which
 * offset is small enough.
 *
 * For values which are just into kernel address space
 * that they match exactly or that they be more than maxoff
 * bytes into kernel space.
 */
psymoff(v, type, s)
D 2
	register v;
E 2
I 2
	register long v;
E 2
	int type;
	char *s;
{
	register w;

	if (v) 
		w = findsym(v, type);
	if (v==0 || w >= maxoff)
		printf(LPRMODE, v);
	else {
		printf("%s", cursym->n_un.n_name);
		if (w)
			printf(OFFMODE, w);
	}
	printf(s);
}

/*
 * Print value v symbolically if it has a reasonable
 * interpretation as name+offset.  If not, print nothing.
 * Used in printing out registers $r.
 */
valpr(v, idsp)
I 2
	long v;
E 2
{
	register off_t d;

	d = findsym(v, idsp);
	if (d >= maxoff)
		return;
	printf("%s", cursym->n_un.n_name);
	if (d)
		printf(OFFMODE, d);
}
E 1
