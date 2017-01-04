h37219
s 00010/00005/00135
d D 4.5 88/06/18 15:07:28 bostic 5 4
c install approved copyright notice
e
s 00009/00003/00131
d D 4.4 88/05/05 18:33:38 bostic 4 3
c written by Eric Allman; add Berkeley header
e
s 00007/00001/00127
d D 4.3 86/01/29 16:25:08 mckusick 3 2
c add copyright
e
s 00014/00013/00114
d D 4.2 83/05/27 14:57:50 layer 2 1
c git rid of compiler warns
e
s 00127/00000/00000
d D 4.1 83/03/23 14:59:03 mckusick 1 0
c date and time created 83/03/23 14:59:03 by mckusick
e
u
U
t
T
I 3
/*
 * Copyright (c) 1980 Regents of the University of California.
D 4
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 4
I 4
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 5
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
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
#ifndef lint
D 3
static char sccsid[] = "%W%	(Berkeley)	%G%";
E 3
I 3
static char sccsid[] = "%W% (Berkeley) %G%";
E 3
D 4
#endif not lint
E 4
I 4
#endif /* not lint */
E 4

# include	"trek.h"

/***  THIS CONSTANT MUST CHANGE AS THE DATA SPACES CHANGE ***/
D 2
# define	VERSION		1
E 2
I 2
# define	VERSION		2
E 2

struct dump
{
	char	*area;
	int	count;
};

D 2
struct dump	Dump_template[]
E 2
I 2

struct dump	Dump_template[] =
E 2
{
D 2
	&Ship,		sizeof Ship,
	&Now,		sizeof Now,
	&Param,		sizeof Param,
	&Etc,		sizeof Etc,
	&Game,		sizeof Game,
	&Sect,		sizeof Sect,
	&Quad,		sizeof Quad,
	&Move,		sizeof Move,
	&Event,		sizeof Event,
E 2
I 2
	(char *)&Ship,		sizeof (Ship),
	(char *)&Now,		sizeof (Now),
	(char *)&Param,		sizeof (Param),
	(char *)&Etc,		sizeof (Etc),
	(char *)&Game,		sizeof (Game),
	(char *)Sect,		sizeof (Sect),
	(char *)Quad,		sizeof (Quad),
	(char *)&Move,		sizeof (Move),
	(char *)Event,		sizeof (Event),
E 2
	0
};

/*
**  DUMP GAME
**
**	This routine dumps the game onto the file "trek.dump".  The
**	first two bytes of the file are a version number, which
**	reflects whether this image may be used.  Obviously, it must
**	change as the size, content, or order of the data structures
**	output change.
*/

dumpgame()
{
	int			version;
	register int		fd;
	register struct dump	*d;
	register int		i;

	if ((fd = creat("trek.dump", 0644)) < 0)
		return (printf("cannot dump\n"));
	version = VERSION;
	write(fd, &version, sizeof version);

	/* output the main data areas */
	for (d = Dump_template; d->area; d++)
	{
		write(fd, &d->area, sizeof d->area);
		i = d->count;
		write(fd, d->area, i);
	}

	close(fd);
}


/*
**  RESTORE GAME
**
**	The game is restored from the file "trek.dump".  In order for
**	this to succeed, the file must exist and be readable, must
**	have the correct version number, and must have all the appro-
**	priate data areas.
**
**	Return value is zero for success, one for failure.
*/

restartgame()
{
	register int	fd;
	int		version;

	if ((fd = open("trek.dump", 0)) < 0 ||
	    read(fd, &version, sizeof version) != sizeof version ||
	    version != VERSION ||
	    readdump(fd))
	{
		printf("cannot restart\n");
		close(fd);
		return (1);
	}

	close(fd);
	return (0);
}


/*
**  READ DUMP
**
**	This is the business end of restartgame().  It reads in the
**	areas.
**
**	Returns zero for success, one for failure.
*/

readdump(fd1)
int	fd1;
{
	register int		fd;
	register struct dump	*d;
	register int		i;
	int			junk;

	fd = fd1;

	for (d = Dump_template; d->area; d++)
	{
D 2
		if (read(fd, &junk, sizeof junk) != sizeof junk)
E 2
I 2
		if (read(fd, &junk, sizeof junk) != (sizeof junk))
E 2
			return (1);
D 2
		if (junk != d->area)
E 2
I 2
		if ((char *)junk != d->area)
E 2
			return (1);
		i = d->count;
		if (read(fd, d->area, i) != i)
			return (1);
	}

	/* make quite certain we are at EOF */
	return (read(fd, &junk, 1));
}
E 1
