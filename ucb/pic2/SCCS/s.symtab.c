h04000
s 00001/00000/00117
d D 3.1 85/07/30 15:06:14 jaap 3 2
c Edition 8 Version of pic (July 1985). 
c Local hacks from jaap.
e
s 00027/00002/00090
d D 2.1 85/07/23 11:21:24 jaap 2 1
c Edition 8 Version of pic (May 1985). 
c Local hacks from jaap.
e
s 00092/00000/00000
d D 1.1 85/07/19 13:59:36 jaap 1 0
c date and time created 85/07/19 13:59:36 by jaap
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% (CWI) %E%";
#endif lint
I 3

E 3
D 2

E 2
#include	<stdio.h>
#include	<ctype.h>
#include	"pic.h"
#include	"y.tab.h"

YYSTYPE getvar(s)	/* return value of variable s (usually pointer) */
	char *s;
{
	struct symtab *p;
	static YYSTYPE bug;

	p = lookup(s);
	if (p == NULL) {
		if (islower(s[0]))
			yyerror("no such variable as %s", s);
		else
			yyerror("no such place as %s", s);
		return(bug);
	}
	return(p->s_val);
}

float getfval(s)	/* return float value of variable s */
	char *s;
{
	YYSTYPE y;

	y = getvar(s);
	return y.f;
}

setfval(s, f)	/* set variable s to f */
	char *s;
	float f;
{
	struct symtab *p;

	if ((p = lookup(s)) != NULL)
		p->s_val.f = f;
}

struct symtab *makevar(s, t, v)	/* make variable named s in table */
	char *s;		/* assumes s is static or from tostring */
	int t;
	YYSTYPE v;
{
	int i;
	struct symtab *p;

	for (p = stack[nstack].p_symtab; p != NULL; p = p->s_next)
		if (strcmp(s, p->s_name) == 0)
			break;
	if (p == NULL) {	/* it's a new one */
		p = (struct symtab *) malloc(sizeof(struct symtab));
		if (p == NULL) {
			yyerror("out of symtab space with %s", s);
			exit(1);
		}
		p->s_next = stack[nstack].p_symtab;
		stack[nstack].p_symtab = p;	/* stick it at front */
	}
	p->s_name = s;
	p->s_type = t;
	p->s_val = v;
	return(p);
}

struct symtab *lookup(s)	/* find s in symtab */
	char *s;
{
	int i;
	struct symtab *p;

	for (i = nstack; i >= 0; i--)	/* look in each active symtab */
		for (p = stack[i].p_symtab; p != NULL; p = p->s_next)
			if (strcmp(s, p->s_name) == 0)
				return(p);
	return(NULL);
}

freesymtab(p)	/* free space used by symtab at p */
	struct symtab *p;
{
D 2
	for ( ; p != NULL; p = p->s_next) {
E 2
I 2
	struct symtab *q;

	for ( ; p != NULL; p = q) {
		q = p->s_next;
E 2
		free(p->s_name);	/* assumes done with tostring */
		free(p);
	}
I 2
}

freedef(s)	/* free definition for string s */
	char *s;
{
	struct symtab *p, *q, *op;

	for (p = op = q = stack[nstack].p_symtab; p != NULL; p = p->s_next) {
		if (strcmp(s, p->s_name) == 0) { 	/* got it */
			if (p->s_type != DEFNAME)
				break;
			if (p == op)	/* 1st elem */
				stack[nstack].p_symtab = p->s_next;
			else
				q->s_next = p->s_next;
			free(p->s_name);
			free(p->s_val.p);
			free(p);
			return;
		}
		q = p;
	}
	yyerror("%s is not defined at this point", s);
E 2
}
E 1
