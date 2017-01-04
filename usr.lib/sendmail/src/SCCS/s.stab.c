h54006
s 00011/00009/00116
d D 5.5 88/06/30 14:59:52 bostic 21 20
c install approved copyright notice
e
s 00016/00010/00109
d D 5.4 88/03/13 19:53:22 bostic 20 19
c add Berkeley specific header
e
s 00001/00002/00118
d D 5.3 88/03/13 18:21:54 bostic 19 18
c replace sameword with strcasecmp
e
s 00000/00002/00120
d D 5.2 85/06/07 22:19:33 miriam 18 17
m 
c Resolve duplicate SccsId
e
s 00014/00000/00108
d D 5.1 85/06/07 15:15:30 dist 17 16
m 
c Add copyright
e
s 00001/00001/00107
d D 4.2 84/08/11 16:50:24 eric 16 15
m 
c Changes from Greg Couch <ucsfcgl!gregc> for V7 compatibility and
c miscellaneous bug fixes; "clear" => "bzero" and "bmove" => "bcopy"
c throughout for consistency; bzero is now in bcopy.c (these are
c supplied by libc on 4.2bsd)
e
s 00000/00000/00108
d D 4.1 83/07/25 19:43:12 eric 15 14
m 
c 4.2 release version
e
s 00006/00001/00102
d D 3.14 83/02/02 12:54:51 eric 14 13
m 165
c implement classes and mailer flags as a bit map; define new class 'w'
c as the set of all hosts we are known by
e
s 00004/00004/00099
d D 3.13 82/08/08 01:03:53 eric 13 12
c change debug level to a debug vector; add levels on logging (and the
c -L flag); change logging to be by message-id; elevate message-id;
c some lint-type cleanup
e
s 00001/00001/00102
d D 3.12 82/03/20 16:12:59 eric 12 11
c 16 bit changes -- should have no effect on VAX binaries to
c speak of.
e
s 00001/00001/00102
d D 3.11 81/12/06 12:40:12 eric 11 10
c cleanup so it will go through lint without any fancy grep -v's;
c change the way SCCS Id's are handled.
e
s 00001/00001/00102
d D 3.10 81/09/29 14:58:56 eric 10 9
c fix hash function computation for symbol table on 16-bit machines
e
s 00001/00004/00102
d D 3.9 81/09/24 10:31:13 eric 9 8
c changes to work under a V6 system -- mostly compilation flags
e
s 00001/00000/00105
d D 3.8 81/09/06 19:49:29 eric 8 7
c cleanup, commenting, linting, etc.
e
s 00035/00010/00070
d D 3.7 81/08/17 11:00:43 eric 7 6
c implement hashing
e
s 00001/00001/00079
d D 3.6 81/08/10 18:49:01 eric 6 5
c make the non-DBM case work
e
s 00007/00006/00073
d D 3.5 81/08/10 16:57:38 eric 5 4
c totally rework aliasing scheme -- sucks when no DBM now,
c but works better for the usual case; fix some quoting problems
c (and how many did I add?); remove .mailer feature since .forward
c will simulate this happily
e
s 00000/00001/00079
d D 3.4 81/08/09 15:03:49 eric 4 3
c lint it
e
s 00022/00001/00058
d D 3.3 81/08/09 10:15:13 eric 3 2
c change to debugging levels; fix bug causing continual match
e
s 00003/00001/00056
d D 3.2 81/08/08 11:14:38 eric 2 1
c map everything into lower case
e
s 00057/00000/00000
d D 3.1 81/08/08 10:23:37 eric 1 0
c date and time created 81/08/08 10:23:37 by eric
e
u
U
f b 
f i 
t
T
I 17
/*
I 21
 * Copyright (c) 1983 Eric P. Allman
E 21
D 20
**  Sendmail
**  Copyright (c) 1983  Eric P. Allman
**  Berkeley, California
**
**  Copyright (c) 1983 Regents of the University of California.
**  All rights reserved.  The Berkeley software License Agreement
**  specifies the terms and conditions for redistribution.
*/
E 20
I 20
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 21
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
 *
 *  Sendmail
 *  Copyright (c) 1983  Eric P. Allman
 *  Berkeley, California
E 21
I 21
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
E 21
 */
E 20

#ifndef lint
D 20
static char	SccsId[] = "%W% (Berkeley) %G%";
#endif not lint
E 20
I 20
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 20

E 17
I 1
# include "sendmail.h"

D 11
static char SccsId[] = "%W%	%G%";
E 11
I 11
D 18
SCCSID(%W%	%Y%	%G%);
E 11

E 18
/*
**  STAB -- manage the symbol table
**
**	Parameters:
**		name -- the name to be looked up or inserted.
I 5
**		type -- the type of symbol.
E 5
**		op -- what to do:
**			ST_ENTER -- enter the name if not
**				already present.
**			ST_FIND -- find it only.
**
**	Returns:
**		pointer to a STAB entry for this name.
**		NULL if not found and not entered.
**
**	Side Effects:
**		can update the symbol table.
D 7
**
**	Notes:
**		Obviously, this deserves a better algorithm.  But
**		for the moment......
E 7
*/

D 7
static STAB	*SymTab;
E 7
I 7
# define STABSIZE	400
E 7

I 7
static STAB	*SymTab[STABSIZE];

E 7
STAB *
D 5
stab(name, op)
E 5
I 5
stab(name, type, op)
E 5
	char *name;
I 5
	int type;
E 5
	int op;
{
D 7
	register STAB *s = SymTab;
	register STAB **ps = &SymTab;
E 7
I 7
	register STAB *s;
	register STAB **ps;
E 7
D 4
	extern char *newstr();
E 4
I 2
D 19
	extern bool sameword();
E 19
I 7
	register int hfunc;
	register char *p;
I 8
	extern char lower();
E 8
E 7
E 2

D 2
	while (s != NULL && strcmp(name, s->s_name) != '\0')
E 2
I 2
D 3
	while (s != NULL && sameword(name, s->s_name))
E 3
I 3
# ifdef DEBUG
D 13
	if (Debug > 4)
E 13
I 13
	if (tTd(36, 5))
E 13
D 5
		printf("STAB: %s ", name);
E 5
I 5
		printf("STAB: %s %d ", name, type);
E 5
# endif DEBUG

D 5
	while (s != NULL && !sameword(name, s->s_name))
E 5
I 5
D 6
	while (s != NULL && !sameword(name, s->s_name) && s->s_type != type)
E 6
I 6
D 7
	while (s != NULL && (!sameword(name, s->s_name) || s->s_type != type))
E 7
I 7
	/*
	**  Compute the hashing function
	**
	**	We could probably do better....
	*/

	hfunc = type;
	for (p = name; *p != '\0'; p++)
D 10
		hfunc = ((hfunc << 7) | lower(*p)) % STABSIZE;
E 10
I 10
		hfunc = (((hfunc << 7) | lower(*p)) & 077777) % STABSIZE;
E 10

# ifdef DEBUG
D 9
	if (Debug > 15)
E 9
I 9
D 13
	if (Debug > 5)
E 13
I 13
	if (tTd(36, 9))
E 13
E 9
		printf("(hfunc=%d) ", hfunc);
# endif DEBUG

	ps = &SymTab[hfunc];
D 19
	while ((s = *ps) != NULL && (!sameword(name, s->s_name) || s->s_type != type))
E 19
I 19
	while ((s = *ps) != NULL && (strcasecmp(name, s->s_name) || s->s_type != type))
E 19
E 7
E 6
E 5
E 3
E 2
D 9
	{
E 9
		ps = &s->s_next;
D 9
		s = s->s_next;
	}
E 9
I 7

	/*
	**  Dispose of the entry.
	*/

E 7
	if (s != NULL || op == ST_FIND)
I 3
	{
# ifdef DEBUG
D 13
		if (Debug > 4)
E 13
I 13
		if (tTd(36, 5))
E 13
		{
			if (s == NULL)
				printf("not found\n");
			else
D 7
				printf("type %d class %x\n", s->s_type, s->s_class);
E 7
I 7
D 12
				printf("type %d val %x\n", s->s_type, s->s_class);
E 12
I 12
D 14
				printf("type %d val %lx\n", s->s_type, s->s_class);
E 14
I 14
			{
				long *lp = (long *) s->s_class;

				printf("type %d val %lx %lx %lx %lx\n",
					s->s_type, lp[0], lp[1], lp[2], lp[3]);
			}
E 14
E 12
E 7
		}
# endif DEBUG
E 3
		return (s);
I 3
	}

I 7
	/*
	**  Make a new entry and link it in.
	*/

E 7
# ifdef DEBUG
D 13
	if (Debug > 4)
E 13
I 13
	if (tTd(36, 5))
E 13
		printf("entered\n");
# endif DEBUG
E 3

	/* make new entry */
	s = (STAB *) xalloc(sizeof *s);
I 5
D 16
	clear((char *) s, sizeof *s);
E 16
I 16
	bzero((char *) s, sizeof *s);
E 16
E 5
	s->s_name = newstr(name);
I 2
	makelower(s->s_name);
E 2
D 5
	s->s_type = 0;
	s->s_class = 0;
	s->s_next = NULL;
E 5
I 5
	s->s_type = type;
E 5

D 7
	/* and link it in */
E 7
I 7
	/* link it in */
E 7
	*ps = s;

	return (s);
}
E 1
