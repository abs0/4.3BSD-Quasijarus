h00210
s 00024/00029/00113
d D 5.4 86/05/19 23:04:07 karels 6 5
c comments now delimited, quoted strings may escape quotes, can quote
c anything but flags
c 
e
s 00004/00003/00138
d D 5.3 86/05/19 15:15:57 lepreau 5 4
c magic flag strings must be tokens
e
s 00002/00002/00139
d D 5.2 86/03/09 19:48:50 donn 4 3
c added LIBC_SCCS condition for sccs ids
e
s 00009/00001/00132
d D 5.1 85/05/30 10:42:51 dist 3 2
c Add copyright
e
s 00062/00013/00071
d D 4.2 85/01/30 12:07:05 ralph 2 1
c added quoted fields & support for windows.
e
s 00084/00000/00000
d D 4.1 84/04/27 10:25:32 ralph 1 0
c date and time created 84/04/27 10:25:32 by ralph
e
u
U
t
T
I 1
D 3
/* %W% (Berkeley) %G% */
E 3
I 3
/*
D 6
 * Copyright (c) 1983 Regents of the University of California.
E 6
I 6
 * Copyright (c) 1985 Regents of the University of California.
E 6
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

D 4
#ifndef lint
E 4
I 4
#if defined(LIBC_SCCS) && !defined(lint)
E 4
static char sccsid[] = "%W% (Berkeley) %G%";
D 4
#endif not lint
E 4
I 4
#endif LIBC_SCCS and not lint
E 4
E 3

#include <stdio.h>
I 2
#include <strings.h>
E 2
#include <ttyent.h>

static char TTYFILE[] = "/etc/ttys";
D 6
static char EMPTY[] = "";
E 6
I 6
static char zapchar;
E 6
static FILE *tf = NULL;
D 2
static char line[BUFSIZ+1];
E 2
I 2
#define LINE 256
static char line[LINE];
E 2
static struct ttyent tty;

setttyent()
{
	if (tf == NULL)
		tf = fopen(TTYFILE, "r");
	else
		rewind(tf);
}

endttyent()
{
	if (tf != NULL) {
		(void) fclose(tf);
		tf = NULL;
	}
}

I 2
D 6
#define QUOTED 1
E 6
I 6
#define QUOTED	1
E 6

/*
D 6
 * Skip over the current field and 
 * return a pointer to the next field.
E 6
I 6
 * Skip over the current field, removing quotes,
 * and return a pointer to the next field.
E 6
 */
E 2
static char *
skip(p)
D 2
register char *p;
E 2
I 2
	register char *p;
E 2
{
I 6
	register char *t = p;
E 6
	register int c;
I 2
	register int q = 0;
E 2

D 2
	while ((c = *p) != '\0') {
E 2
I 2
	for (; (c = *p) != '\0'; p++) {
		if (c == '"') {
			q ^= QUOTED;	/* obscure, but nice */
			continue;
		}
I 6
		if (q == QUOTED && *p == '\\' && *(p+1) == '"')
			p++;
		*t++ = *p;
E 6
		if (q == QUOTED)
			continue;
E 2
		if (c == '#') {
D 6
			*p = '\0';
E 6
I 6
			zapchar = c;
			*p = 0;
E 6
			break;
		}
		if (c == '\t' || c == ' ' || c == '\n') {
D 6
			*p++ = '\0';
E 6
I 6
			zapchar = c;
			*p++ = 0;
E 6
			while ((c = *p) == '\t' || c == ' ' || c == '\n')
				p++;
			break;
		}
D 2
		p++;
E 2
	}
I 6
	*--t = '\0';
E 6
	return (p);
}

I 2
static char *
value(p)
	register char *p;
{
	if ((p = index(p,'=')) == 0)
		return(NULL);
	p++;			/* get past the = sign */
	return(p);
}

D 6
/* get rid of quotes. */

static
qremove(p)
	register char *p;
{
	register char *t;

	for (t = p; *p; p++)
		if (*p != '"')
			*t++ = *p;
	*t = '\0';
}

E 6
E 2
struct ttyent *
getttyent()
{
D 2
	register char *p, *cp;
E 2
I 2
	register char *p;
E 2
	register int c;

	if (tf == NULL) {
		if ((tf = fopen(TTYFILE, "r")) == NULL)
			return (NULL);
	}
	do {
D 2
		p = fgets(line, BUFSIZ, tf);
E 2
I 2
		p = fgets(line, LINE, tf);
E 2
		if (p == NULL)
			return (NULL);
		while ((c = *p) == '\t' || c == ' ' || c == '\n')
			p++;
	} while (c == '\0' || c == '#');
I 6
	zapchar = 0;
E 6
	tty.ty_name = p;
	p = skip(p);
	tty.ty_getty = p;
	p = skip(p);
	tty.ty_type = p;
I 2
	p = skip(p);
E 2
	tty.ty_status = 0;
D 2
	for (p = skip(p); *p; p = cp) {
		cp = skip(p);
		if (strcmp(p, "on") == 0)
E 2
I 2
D 6
	tty.ty_window = EMPTY;
E 6
I 6
	tty.ty_window = NULL;
E 6
	for (; *p; p = skip(p)) {
D 5
		if (strncmp(p, "on", 2) == 0)
E 5
I 5
#define space(x) ((c = p[x]) == ' ' || c == '\t' || c == '\n')
		if (strncmp(p, "on", 2) == 0 && space(2))
E 5
E 2
			tty.ty_status |= TTY_ON;
D 2
		else if (strcmp(p, "off") == 0)
E 2
I 2
D 5
		else if (strncmp(p, "off", 3) == 0)
E 5
I 5
		else if (strncmp(p, "off", 3) == 0 && space(3))
E 5
E 2
			tty.ty_status &= ~TTY_ON;
D 2
		else if (strcmp(p, "secure") == 0)
E 2
I 2
D 5
		else if (strncmp(p, "secure", 6) == 0)
E 5
I 5
		else if (strncmp(p, "secure", 6) == 0 && space(6))
E 5
E 2
			tty.ty_status |= TTY_SECURE;
I 2
D 6
		else if (strncmp(p, "window", 6) == 0) {
			if ((tty.ty_window = value(p)) == NULL)
				tty.ty_window = EMPTY;
		} else
E 6
I 6
		else if (strncmp(p, "window=", 7) == 0)
			tty.ty_window = value(p);
		else
E 6
			break;
E 2
	}
I 6
	if (zapchar == '#' || *p == '#')
		while ((c = *++p) == ' ' || c == '\t')
			;
E 6
D 2
	tty.ty_comment = EMPTY;
	return (&tty);
E 2
I 2
	tty.ty_comment = p;
I 6
	if (*p == 0)
		tty.ty_comment = 0;
E 6
	if (p = index(p, '\n'))
		*p = '\0';
D 6
	qremove(tty.ty_getty);
	qremove(tty.ty_window);
	qremove(tty.ty_comment);
E 6
	return(&tty);
E 2
}
E 1
