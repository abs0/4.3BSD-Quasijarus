h51545
s 00007/00001/00314
d D 5.1 85/04/30 12:30:39 dist 6 5
c Add copyright
e
s 00015/00013/00300
d D 4.5 83/06/25 01:15:16 sam 5 4
c so much...clean up after ralph's merge of wendel and mo code;
c purge VMUNIX include since changes for signals make it no longer portable 
c to systems other than 4.2; fix ventel for no echo strapping; do setjmps 
c instead of assuming interrupted system calls; purge lcmd, if people use 
e
s 00031/00002/00282
d D 4.4 83/06/15 13:53:15 ralph 4 3
c changes for local info, parity, vadic auto dialers
e
s 00071/00067/00213
d D 4.3 81/11/29 22:51:25 sam 3 2
c reformatting
e
s 00008/00008/00272
d D 4.2 81/11/20 10:45:18 sam 2 1
c cosmetics
e
s 00280/00000/00000
d D 4.1 81/05/09 16:45:29 root 1 0
c date and time created 81/05/09 16:45:29 by root
e
u
U
t
T
I 6
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 6
I 1
D 5
/*	%M%	%I%	%E%	*/
E 5
I 5
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 6
#endif
E 6
I 6
#endif not lint
E 6

E 5
#include "tip.h"

#define MIDDLE	35

I 4
D 5
static char *sccsid = "%W% %G%";
E 5
E 4
static value_t *vlookup();
static int col = 0;

/*
 * Variable manipulation
 */
vinit()
{
	register value_t *p;
	register char *cp;
	FILE *f;
	char file[256];

	for (p = vtable; p->v_name != NULL; p++) {
		if (p->v_type&ENVIRON)
			if (cp = getenv(p->v_name))
				p->v_value = cp;
		if (p->v_type&IREMOTE)
			number(p->v_value) = *address(p->v_value);
	}
	/*
	 * Read the .tiprc file in the HOME directory
	 *  for sets
	 */
	strcpy(file, value(HOME));
	strcat(file, "/.tiprc");
	if ((f = fopen(file, "r")) != NULL) {
		register char *tp;

		while (fgets(file, sizeof(file)-1, f) != NULL) {
			if (vflag)
				printf("set %s", file);
			if (tp = rindex(file, '\n'))
				*tp = '\0';
			vlex(file);
		}
		fclose(f);
	}
	/*
	 * To allow definition of exception prior to fork
	 */
	vtable[EXCEPTIONS].v_access &= ~(WRITE<<PUBLIC);
}

/*VARARGS1*/
vassign(p, v)
D 2
register value_t *p;
char *v;
E 2
I 2
	register value_t *p;
	char *v;
E 2
{

	if (!vaccess(p->v_access, WRITE)) {
		printf("access denied\r\n");
		return;
	}
D 3
	switch(p->v_type&TMASK) {
E 3
I 3
	switch (p->v_type&TMASK) {
E 3

D 3
		case STRING:
			if (equal(p->v_value, v))
				return;
			if (!(p->v_type&(ENVIRON|INIT)))
				free(p->v_value);
			if ((p->v_value = malloc(size(v)+1)) == NOSTR) {
				printf("out of core\r\n");
				return;
			}
			p->v_type &= ~(ENVIRON|INIT);
			strcpy(p->v_value, v);
			break;
E 3
I 3
	case STRING:
		if (equal(p->v_value, v))
			return;
		if (!(p->v_type&(ENVIRON|INIT)))
			free(p->v_value);
		if ((p->v_value = malloc(size(v)+1)) == NOSTR) {
			printf("out of core\r\n");
			return;
		}
		p->v_type &= ~(ENVIRON|INIT);
		strcpy(p->v_value, v);
		break;
E 3

D 3
		case NUMBER:
			if (number(p->v_value) == number(v))
				return;
			number(p->v_value) = number(v);
			break;
E 3
I 3
	case NUMBER:
		if (number(p->v_value) == number(v))
			return;
		number(p->v_value) = number(v);
		break;
E 3

D 3
		case BOOL:
			if (boolean(p->v_value) == (*v != '!'))
				return;
			boolean(p->v_value) = (*v != '!');
			break;
E 3
I 3
	case BOOL:
		if (boolean(p->v_value) == (*v != '!'))
			return;
		boolean(p->v_value) = (*v != '!');
		break;
E 3

D 3
		case CHAR:
			if (character(p->v_value) == *v)
				return;
			character(p->v_value) = *v;
E 3
I 3
	case CHAR:
		if (character(p->v_value) == *v)
			return;
		character(p->v_value) = *v;
E 3
	}
	p->v_access |= CHANGED;
}

vlex(s)
D 2
register char *s;
E 2
I 2
	register char *s;
E 2
{
	register value_t *p;

	if (equal(s, "all")) {
		for (p = vtable; p->v_name; p++)
			if (vaccess(p->v_access, READ))
				vprint(p);
	} else {
		register char *cp;

		do {
			if (cp = vinterp(s, ' '))
				cp++;
			vtoken(s);
			s = cp;
		} while (s);
	}
	if (col > 0) {
		printf("\r\n");
		col = 0;
	}
}

static int
vtoken(s)
D 2
register char *s;
E 2
I 2
	register char *s;
E 2
{
	register value_t *p;
	register char *cp;
I 4
	char *expand();
E 4

	if (cp = index(s, '=')) {
		*cp = '\0';
		if (p = vlookup(s)) {
			cp++;
			if (p->v_type&NUMBER)
				vassign(p, atoi(cp));
D 4
			else
E 4
I 4
			else {
				if (strcmp(s, "record") == 0)
					cp = expand(cp);
E 4
				vassign(p, cp);
I 4
			}
E 4
			return;
		}
	} else if (cp = index(s, '?')) {
		*cp = '\0';
		if ((p = vlookup(s)) && vaccess(p->v_access, READ)) {
			vprint(p);
			return;
		}
	} else {
		if (*s != '!')
			p = vlookup(s);
		else
			p = vlookup(s+1);
		if (p != NOVAL) {
			vassign(p, s);
			return;
		}
	}
	printf("%s: unknown variable\r\n", s);
}

static int
vprint(p)
D 2
register value_t *p;
E 2
I 2
	register value_t *p;
E 2
{
	register char *cp;
	extern char *interp(), *ctrl();

	if (col > 0 && col < MIDDLE)
		while (col++ < MIDDLE)
			putchar(' ');
	col += size(p->v_name);
D 3
	switch(p->v_type&TMASK)
	{
		case BOOL:
			if (boolean(p->v_value) == FALSE) {
				col++;
				putchar('!');
			}
			printf("%s", p->v_name);
			break;
		case STRING:
			printf("%s=", p->v_name);
E 3
I 3
	switch (p->v_type&TMASK) {

	case BOOL:
		if (boolean(p->v_value) == FALSE) {
E 3
			col++;
D 3
			if (p->v_value) {
				cp = interp(p->v_value);
				col += size(cp);
				printf("%s", cp);
			}
			break;
		case NUMBER:
			col += 6;
			printf("%s=%-5d", p->v_name, number(p->v_value));
			break;
		case CHAR:
			printf("%s=", p->v_name);
			col++;
			if (p->v_value) {
				cp = ctrl(character(p->v_value));
				col += size(cp);
				printf("%s", cp);
			}
			break;
E 3
I 3
			putchar('!');
		}
		printf("%s", p->v_name);
		break;

	case STRING:
		printf("%s=", p->v_name);
		col++;
		if (p->v_value) {
D 4
			cp = interp(p->v_value);
E 4
I 4
			cp = interp(p->v_value, NULL);
E 4
			col += size(cp);
			printf("%s", cp);
		}
		break;

	case NUMBER:
		col += 6;
		printf("%s=%-5d", p->v_name, number(p->v_value));
		break;

	case CHAR:
		printf("%s=", p->v_name);
		col++;
		if (p->v_value) {
			cp = ctrl(character(p->v_value));
			col += size(cp);
			printf("%s", cp);
		}
		break;
E 3
	}
	if (col >= MIDDLE) {
		col = 0;
		printf("\r\n");
		return;
	}
}


static int
vaccess(mode, rw)
D 2
register unsigned mode, rw;
E 2
I 2
	register unsigned mode, rw;
E 2
{
	if (mode & (rw<<PUBLIC))
D 3
		return(1);
E 3
I 3
		return (1);
E 3
	if (mode & (rw<<PRIVATE))
D 3
		return(1);
	return((mode & (rw<<ROOT)) && getuid() == 0);
E 3
I 3
		return (1);
	return ((mode & (rw<<ROOT)) && getuid() == 0);
E 3
}

static value_t *
vlookup(s)
D 2
register char *s;
E 2
I 2
	register char *s;
E 2
{
	register value_t *p;

	for (p = vtable; p->v_name; p++)
		if (equal(p->v_name, s) || (p->v_abrev && equal(p->v_abrev, s)))
D 3
			return(p);
	return(NULL);
E 3
I 3
			return (p);
	return (NULL);
E 3
}

char *
vinterp(s, stop)
D 2
register char *s;
E 2
I 2
	register char *s;
E 2
D 3
char stop;
E 3
I 3
	char stop;
E 3
{
	register char *p = s, c;
	int num;

D 3
	while ((c = *s++) && c != stop) switch(c)
	{
E 3
I 3
	while ((c = *s++) && c != stop)
		switch (c) {

E 3
		case '^':
			if (*s)
				*p++ = *s++ - 0100;
			else
				*p++ = c;
			break;

		case '\\':
			num = 0;
			c = *s++;
			if (c >= '0' && c <= '7')
				num = (num<<3)+(c-'0');
			else {
				register char *q = "n\nr\rt\tb\bf\f";

				for (; *q; q++)
					if (c == *q++) {
						*p++ = *q;
						goto cont;
					}
				*p++ = c;
			cont:
				break;
			}
			if ((c = *s++) >= '0' && c <= '7') {
				num = (num<<3)+(c-'0');
				if ((c = *s++) >= '0' && c <= '7')
					num = (num<<3)+(c-'0');
				else
					s--;
			} else
				s--;
			*p++ = num;
			break;

		default:
			*p++ = c;
D 3
	}
E 3
I 3
		}
E 3
	*p = '\0';
D 3
	return(c == stop ? s-1 : NULL);
E 3
I 3
	return (c == stop ? s-1 : NULL);
I 4
}

/*
 * assign variable s with value v (for NUMBER or STRING or CHAR types)
 */

vstring(s,v)
	register char *s;
	register char *v;
{
	register value_t *p;
	char *expand();

D 5
	if (p = vlookup(s)) {
		if (p->v_type&NUMBER)
			vassign(p, atoi(v));
		else {
			if (strcmp(s, "record") == 0)
				v = expand(v);
			vassign(p, v);
		}
		return(0);
	} else
		return(1);
E 5
I 5
	p = vlookup(s); 
	if (p == 0)
		return (1);
	if (p->v_type&NUMBER)
		vassign(p, atoi(v));
	else {
		if (strcmp(s, "record") == 0)
			v = expand(v);
		vassign(p, v);
	}
	return (0);
E 5
E 4
E 3
}
E 1
