h07972
s 00010/00005/00164
d D 5.3 88/06/18 15:08:25 bostic 5 4
c install approved copyright notice
e
s 00009/00003/00160
d D 5.2 88/05/05 18:34:50 bostic 4 3
c written by Eric Allman; add Berkeley header
e
s 00007/00001/00156
d D 5.1 86/01/29 16:37:15 mckusick 3 2
c add copyright
e
s 00003/00003/00154
d D 4.2 83/05/27 00:34:49 layer 2 1
c finished conversion to 4.1c
e
s 00157/00000/00000
d D 4.1 83/03/23 15:01:44 mckusick 1 0
c date and time created 83/03/23 15:01:44 by mckusick
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
# include	"getpar.h"

/*
**  SHORT RANGE SENSOR SCAN
**
**	A short range scan is taken of the current quadrant.  If the
**	flag 'f' is one, it is an "auto srscan", which is not done
**	unless in 'fast' mode.  It does a status report and a srscan.
**	If 'f' is -1, you get a status report only.  If it is zero,
**	you get a srscan and an optional status report.  The status
**	report is taken if you enter "srscan yes"; for all srscans
**	thereafter you get a status report with your srscan until
**	you type "srscan no".  It defaults to on.
**
**	The current quadrant is filled in on the computer chart.
*/

D 2
char	*Color[4]
E 2
I 2
char	*Color[4] =
E 2
{
	"GREEN",
	"DOCKED",
	"YELLOW",
	"RED"
};

srscan(f)
int	f;
{
	register int		i, j;
	register int		statinfo;
	char			*s;
	int			percent;
	struct quad		*q;
	extern struct cvntab	Skitab[];
	extern struct cvntab	Lentab[];
	struct cvntab		*p;

	if (f >= 0 && check_out(SRSCAN))
	{
		return;
	}
	if (f)
		statinfo = 1;
	else
	{
		if (!testnl())
			Etc.statreport = getynpar("status report");
		statinfo = Etc.statreport;
	}
	if (f > 0)
	{
		Etc.statreport = 1;
		if (!Etc.fast)
			return;
	}
	if (f >= 0)
	{
		printf("\nShort range sensor scan\n");
		q = &Quad[Ship.quadx][Ship.quady];
		q->scanned = q->klings * 100 + q->bases * 10 + q->stars;
		printf("  ");
		for (i = 0; i < NSECTS; i++)
		{
			printf("%d ", i);
		}
		printf("\n");
	}

	for (i = 0; i < NSECTS; i++)
	{
		if (f >= 0)
		{
			printf("%d ", i);
			for (j = 0; j < NSECTS; j++)
				printf("%c ", Sect[i][j]);
			printf("%d", i);
			if (statinfo)
				printf("   ");
		}
		if (statinfo)
			switch (i)
			{
			  case 0:
				printf("stardate      %.2f", Now.date);
				break;
			  case 1:
				printf("condition     %s", Color[Ship.cond]);
				if (Ship.cloaked)
					printf(", CLOAKED");
				break;
			  case 2:
				printf("position      %d,%d/%d,%d",Ship.quadx, Ship.quady, Ship.sectx, Ship.secty);
				break;
			  case 3:
				printf("warp factor   %.1f", Ship.warp);
				break;
			  case 4:
				printf("total energy  %d", Ship.energy);
				break;
			  case 5:
				printf("torpedoes     %d", Ship.torped);
				break;
			  case 6:
				s = "down";
				if (Ship.shldup)
					s = "up";
				if (damaged(SHIELD))
					s = "damaged";
				percent = 100.0 * Ship.shield / Param.shield;
				printf("shields       %s, %d%%", s, percent);
				break;
			  case 7:
				printf("Klingons left %d", Now.klings);
				break;
			  case 8:
				printf("time left     %.2f", Now.time);
				break;
			  case 9:
				printf("life support  ");
				if (damaged(LIFESUP))
				{
					printf("damaged, reserves = %.2f", Ship.reserves);
					break;
				}
				printf("active");
				break;
			}
		printf("\n");
	}
	if (f < 0)
	{
		printf("current crew  %d\n", Ship.crew);
		printf("brig space    %d\n", Ship.brigfree);
		printf("Klingon power %d\n", Param.klingpwr);
		p = &Lentab[Game.length - 1];
		if (Game.length > 2)
			p--;
		printf("Length, Skill %s%s, ", p->abrev, p->full);
		p = &Skitab[Game.skill - 1];
		printf("%s%s\n", p->abrev, p->full);
		return;
	}
	printf("  ");
	for (i = 0; i < NSECTS; i++)
		printf("%d ", i);
	printf("\n");

D 2
	if (q->systemname & Q_DISTRESSED)
E 2
I 2
	if (q->qsystemname & Q_DISTRESSED)
E 2
		printf("Distressed ");
D 2
	if (q->systemname)
E 2
I 2
	if (q->qsystemname)
E 2
		printf("Starsystem %s\n", systemname(q));
}
E 1
