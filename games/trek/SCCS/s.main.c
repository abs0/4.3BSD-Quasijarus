h48743
s 00010/00005/00208
d D 5.4 88/06/18 15:07:55 bostic 6 5
c install approved copyright notice
e
s 00001/00014/00212
d D 5.3 88/06/01 18:02:45 bostic 5 4
c get rid of sibuf; requires change to user interface because of
c the way the read routines work.  Bleah.
e
s 00010/00004/00216
d D 5.2 88/05/05 18:34:15 bostic 4 3
c written by Eric Allman; add Berkeley header
e
s 00013/00001/00207
d D 5.1 86/01/29 16:36:31 mckusick 3 2
c add copyright
e
s 00040/00017/00168
d D 4.2 83/05/27 00:34:19 layer 2 1
c finished conversion to 4.1c
e
s 00185/00000/00000
d D 4.1 83/03/23 15:00:20 mckusick 1 0
c date and time created 83/03/23 15:00:20 by mckusick
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
D 6
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 6
I 6
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
E 6
E 4
 */

E 3
I 1
#ifndef lint
D 3
static char sccsid[] = "%W%	(Berkeley)	%G%";
E 3
I 3
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
D 4
#endif not lint
E 4
I 4
#endif /* not lint */
E 4

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
E 3
D 4
#endif not lint
E 4
I 4
#endif /* not lint */
E 4

# include	"trek.h"
D 2
# define	PRIO		10	/* default priority */
E 2
I 2
# include	<stdio.h>
# include	<sgtty.h>
# define	PRIO		00	/* default priority */
E 2

D 2
int	Mother	51 + (51 << 8);
E 2
I 2
int	Mother	= 51 + (51 << 8);
E 2

/*
**	 ####  #####    #    ####          #####  ####   #####  #   #
**	#        #     # #   #   #           #    #   #  #      #  #
**	 ###     #    #####  ####            #    ####   ###    ###
**	    #    #    #   #  #  #            #    #  #   #      #  #
**	####     #    #   #  #   #           #    #   #  #####  #   #
**
**	C version by Eric P. Allman 5/76 (U.C. Berkeley) with help
**		from Jeff Poskanzer and Pete Rubinstein.
**
**	I also want to thank everyone here at Berkeley who
**	where crazy enough to play the undebugged game.  I want to
**	particularly thank Nick Whyte, who made considerable
**	suggestions regarding the content of the game.  Why, I'll
**	never forget the time he suggested the name for the
**	"capture" command.
**
**	Please send comments, questions, and suggestions about this
**		game to:
**			Eric P. Allman
**			Project INGRES
**			Electronics Research Laboratory
**			Cory Hall
**			University of California
**			Berkeley, California  94720
**
**	If you make ANY changes in the game, I sure would like to
**	know about them.  It is sort of an ongoing project for me,
**	and I very much want to put in any bug fixes and improvements
**	that you might come up with.
**
**	FORTRASH version by Kay R. Fisher (DEC) "and countless others".
**	That was adapted from the "original BASIC program" (ha!) by
**		Mike Mayfield (Centerline Engineering).
**
**	Additional inspiration taken from FORTRAN version by
**		David Matuszek and Paul Reynolds which runs on the CDC
**		7600 at Lawrence Berkeley Lab, maintained there by
**		Andy Davidson.  This version is also available at LLL
**		and at LMSC.  In all fairness, this version was the
**		major inspiration for this version of the game (trans-
**		lation:  I ripped off a whole lot of code).
**
**	Minor other input from the "Battelle Version 7A" by Joe Miller
**		(Graphics Systems Group, Battelle-Columbus Labs) and
**		Ross Pavlac (Systems Programmer, Battelle Memorial
**		Institute).  That version was written in December '74
**		and extensively modified June '75.  It was adapted
**		from the FTN version by Ron Williams of CDC Sunnyvale,
**		which was adapted from the Basic version distributed
**		by DEC.  It also had "neat stuff swiped" from T. T.
**		Terry and Jim Korp (University of Texas), Hicks (Penn
**		U.), and Rick Maus (Georgia Tech).  Unfortunately, it
**		was not as readable as it could have been and so the
**		translation effort was severely hampered.  None the
**		less, I got the idea of inhabited starsystems from this
**		version.
**
**	Permission is given for use, copying, and modification of
**		all or part of this program and related documentation,
**		provided that all reference to the authors are maintained.
**
**
**********************************************************************
**
**  NOTES TO THE MAINTAINER:
**
**	There is a compilation option xTRACE which must be set for any
**	trace information to be generated.  It is probably defined in
**	the version that you get.  It can be removed, however, if you
**	have trouble finding room in core.
**
**	Many things in trek are not as clear as they might be, but are
**	done to reduce space.  I compile with the -f and -O flags.  I
**	am constrained to running with non-seperated I/D space, since
D 2
**	we don't have floating point hardware here; even if we did, I
E 2
I 2
**	we don't have doubleing point hardware here; even if we did, I
E 2
**	would like trek to be available to the large number of people
**	who either have an 11/40 or do not have FP hardware.  I also
**	found it desirable to make the code run reentrant, so this
**	added even more space constraints.
**
**	I use the portable C library to do my I/O.  This is done be-
**	cause I wanted the game easily transportable to other C
D 2
**	implementations, and because I was too lazy to do the floating
E 2
I 2
**	implementations, and because I was too lazy to do the doubleing
E 2
**	point input myself.  Little did I know.  The portable C library
**	released by Bell Labs has more bugs than you would believe, so
**	I ended up rewriting the whole blessed thing.  Trek excercises
**	many of the bugs in it, as well as bugs in some of the section
**	III UNIX routines.  We have fixed them here.  One main problem
**	was a bug in alloc() that caused it to always ask for a large
**	hunk of memory, which worked fine unless you were almost out,
**	which I inevitably was.  If you want the code for all of this
**	stuff, it is also available through me.
**
***********************************************************************
*/

main(argc, argv)
int	argc;
char	**argv;
{
D 2
	int			vect[3];
	extern int		f_log;
E 2
I 2
	long			vect;
	/* extern FILE		*f_log; */
E 2
	register char		opencode;
	int			prio;
	register int		ac;
	register char		**av;
I 2
	struct	sgttyb		argp;
	int			been_here = 0;
E 2

	av = argv;
	ac = argc;
	av++;
D 2
	time(vect);
	srand(vect[1]);
E 2
I 2
	time(&vect);
	srand(vect);
E 2
	opencode = 'w';
	prio = PRIO;
D 2
	if (gtty(1, vect) == 0)
E 2
I 2
	if (gtty(1, &argp) == 0)
E 2
	{
D 2
		if ((vect[0] & 0377) > 8)
E 2
I 2
		if ((argp.sg_ispeed ) < B1200)
E 2
			Etc.fast++;
	}
	while (ac > 1 && av[0][0] == '-')
	{
		switch (av[0][1])
		{
		  case 'a':	/* append to log file */
			opencode = 'a';
			break;

		  case 'f':	/* set fast mode */
			Etc.fast++;
			break;

		  case 's':	/* set slow mode */
			Etc.fast = 0;
			break;

#		ifdef xTRACE
		  case 't':	/* trace */
			if (getuid() != Mother)
				goto badflag;
			Trace++;
			break;
#		endif

		  case 'p':	/* set priority */
			if (getuid() != Mother)
				goto badflag;
			if (scanf(-1, &av[0][2], "%d", &prio) > 0)
				break;

		  default:
		  badflag:
			printf("Invalid option: %s\n", av[0]);

		}
		ac--;
		av++;
	}
	if (ac > 2)
		syserr(0, "arg count");
I 2
		/*
E 2
	if (ac > 1)
D 2
		f_log = copen(av[0], opencode);
E 2
I 2
		f_log = fopen(av[0], opencode);
		*/
E 2

D 5
	printf("\n   * * *   S T A R   T R E K   * * *\n\n");
E 5
I 5
	printf("\n   * * *   S T A R   T R E K   * * *\n\nPress return to continue.\n");
E 5
D 2
	ungetc('\n', 0);		/* prime the standard input */
	ungetc('y', 0);
	nice(prio);
E 2

I 2
D 5
	play_with(stdin);
	ungetc('\n',stdin);
E 5
E 2
	setexit();
D 2
	while (getynpar("Another game"))
E 2
I 2
	if ( been_here == 1 )
E 2
	{
I 2
		if ( !getynpar("Another game") )
			exit(0);
	}
	been_here = 1;
	do
	{
E 2
		setup();
		play();
D 2
	}
	flush();
E 2
I 2
	} while (getynpar("Another game"));

	fflush(stdout);
D 5
}

play_with(iop)
register	FILE	*iop;
{
	extern	char	_sibuf[];

	iop->_cnt = 0;
	iop->_base = _sibuf;
	iop->_ptr = iop->_base;
	iop->_bufsiz = BUFSIZ;
E 5
E 2
}
E 1
