h62069
s 00002/00002/00097
d D 5.2 86/03/09 19:51:37 donn 10 9
c added LIBC_SCCS condition for sccs ids
e
s 00009/00001/00090
d D 5.1 85/05/30 10:46:42 dist 9 8
c Add copyright
e
s 00001/00001/00090
d D 4.7 85/01/22 16:52:32 ralph 8 7
c return -1 not NULL.
e
s 00001/00001/00090
d D 4.6 84/07/06 09:58:06 ralph 7 6
c return the number of symbols not found
e
s 00025/00015/00066
d D 4.5 84/07/05 17:01:02 ralph 6 5
c keep two open files to avoid seeks (from Robert Elz).
e
s 00001/00001/00080
d D 4.4 83/10/17 10:32:26 ralph 5 4
c close() fixed to fclose().
e
s 00000/00001/00081
d D 4.3 83/06/10 22:43:02 sam 4 3
c purge pagsiz.h
e
s 00001/00001/00081
d D 4.2 83/01/02 16:10:58 sam 3 1
c null pointer bug
e
s 00002/00001/00081
d R 4.2 81/07/03 23:38:26 root 2 1
c return only externals
e
s 00082/00000/00000
d D 4.1 80/12/21 16:39:57 wnj 1 0
c date and time created 80/12/21 16:39:57 by wnj
e
u
U
t
T
I 1
D 9
/* %W% (Berkeley) %G% */
E 9
I 9
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

D 10
#ifndef lint
E 10
I 10
#if defined(LIBC_SCCS) && !defined(lint)
E 10
static char sccsid[] = "%W% (Berkeley) %G%";
D 10
#endif not lint
E 10
I 10
#endif LIBC_SCCS and not lint
E 10
E 9
I 6

E 6
#include <sys/types.h>
D 4
#include <pagsiz.h>
E 4
#include <a.out.h>
#include <stdio.h>

/*
 * nlist - retreive attributes from name list (string table version)
 */
nlist(name, list)
	char *name;
	struct nlist *list;
{
	register struct nlist *p, *q;
D 6
	register n, m, i, nreq;
E 6
I 6
	register char *s1, *s2;
	register n, m;
	int maxlen, nreq;
E 6
	FILE *f;
I 6
	FILE *sf;
E 6
	off_t sa;		/* symbol address */
	off_t ss;		/* start of strings */
	struct exec buf;
	struct nlist space[BUFSIZ/sizeof (struct nlist)];
D 6
	int maxlen;
E 6

	maxlen = 0;
	for (q = list, nreq = 0; q->n_un.n_name && q->n_un.n_name[0]; q++, nreq++) {
		q->n_type = 0;
		q->n_value = 0;
		q->n_desc = 0;
		q->n_other = 0;
D 6
		i = strlen(q->n_un.n_name);
		if (i > maxlen)
			maxlen = i;
E 6
I 6
		n = strlen(q->n_un.n_name);
		if (n > maxlen)
			maxlen = n;
E 6
	}
	f = fopen(name, "r");
	if (f == NULL)
D 8
		return (NULL);
E 8
I 8
		return (-1);
E 8
	fread((char *)&buf, sizeof buf, 1, f);
	if (N_BADMAG(buf)) {
D 5
		close(f);
E 5
I 5
		fclose(f);
E 5
		return (-1);
	}
I 6
	sf = fopen(name, "r");
	if (sf == NULL) {
		/* ??? */
		fclose(f);
		return(-1);
	}
E 6
	sa = N_SYMOFF(buf);
	ss = sa + buf.a_syms;
	n = buf.a_syms;
I 6
	fseek(f, sa, 0);
E 6
	while (n) {
		m = sizeof (space);
		if (n < m)
			m = n;
D 6
		fseek(f, sa, 0);
		i = fread((char *)space, m, 1, f);
		sa += m;
E 6
I 6
		if (fread((char *)space, m, 1, f) != 1)
			break;
E 6
		n -= m;
		for (q = space; (m -= sizeof(struct nlist)) >= 0; q++) {
			char nambuf[BUFSIZ];

			if (q->n_un.n_strx == 0 || q->n_type & N_STAB)
				continue;
D 6
			fseek(f, ss+q->n_un.n_strx, 0);
			fread(nambuf, maxlen+1, 1, f);
E 6
I 6
			fseek(sf, ss+q->n_un.n_strx, 0);
			fread(nambuf, maxlen+1, 1, sf);
E 6
D 3
			for (p = list; p->n_un.n_name[0]; p++) {
E 3
I 3
			for (p = list; p->n_un.n_name && p->n_un.n_name[0]; p++) {
E 3
D 6
				i = 0;
				while (p->n_un.n_name[i]) {
					if (p->n_un.n_name[i] != nambuf[i])
E 6
I 6
				s1 = p->n_un.n_name;
				s2 = nambuf;
				while (*s1) {
					if (*s1++ != *s2++)
E 6
						goto cont;
D 6
					i++;
E 6
				}
D 6
				if (nambuf[i])
E 6
I 6
				if (*s2)
E 6
					goto cont;
				p->n_value = q->n_value;
				p->n_type = q->n_type;
				p->n_desc = q->n_desc;
				p->n_other = q->n_other;
				if (--nreq == 0)
					goto alldone;
				break;
		cont:		;
			}
		}
	}
alldone:
	fclose(f);
I 6
	fclose(sf);
E 6
D 7
	return (0);
E 7
I 7
	return (nreq);
E 7
}
E 1
