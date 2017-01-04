h17161
s 00010/00005/00117
d D 5.4 88/06/18 15:08:22 bostic 6 5
c install approved copyright notice
e
s 00009/00003/00113
d D 5.3 88/05/05 18:34:46 bostic 5 4
c written by Eric Allman; add Berkeley header
e
s 00002/00002/00114
d D 5.2 87/10/22 11:39:20 bostic 4 3
c ANSI C; sprintf now returns an int.
e
s 00007/00001/00109
d D 5.1 86/01/29 16:37:07 mckusick 3 2
c add copyright
e
s 00006/00006/00104
d D 4.2 83/05/27 14:58:12 layer 2 1
c git rid of compiler warns
e
s 00110/00000/00000
d D 4.1 83/03/23 15:01:33 mckusick 1 0
c date and time created 83/03/23 15:01:33 by mckusick
e
u
U
t
T
I 3
/*
 * Copyright (c) 1980 Regents of the University of California.
D 5
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 5
I 5
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
E 5
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
D 5
#endif not lint
E 5
I 5
#endif /* not lint */
E 5

# include	"trek.h"
# include	"getpar.h"

/*
**  SHIELD AND CLOAKING DEVICE CONTROL
**
**	'f' is one for auto shield up (in case of Condition RED),
**	zero for shield control, and negative one for cloaking
**	device control.
**
**	Called with an 'up' or 'down' on the same line, it puts
**	the shields/cloak into the specified mode.  Otherwise it
**	reports to the user the current mode, and asks if she wishes
**	to change.
**
**	This is not a free move.  Hits that occur as a result of
**	this move appear as though the shields are half up/down,
**	so you get partial hits.
*/

D 2
struct cvntab Udtab[]
E 2
I 2
struct cvntab Udtab[] =
E 2
{
D 2
	"u",		"p",			1,		0,
E 2
I 2
	"u",		"p",			(int (*)())1,		0,
E 2
	"d",		"own",			0,		0,
	0
};

shield(f)
int	f;
{
	register int		i;
	char			c;
	struct cvntab		*r;
	char			s[100];
	char			*device, *dev2, *dev3;
	int			ind;
	char			*stat;

	if (f > 0 && (Ship.shldup || damaged(SRSCAN)))
		return;
	if (f < 0)
	{
		/* cloaking device */
		if (Ship.ship == QUEENE)
			return (printf("Ye Faire Queene does not have the cloaking device.\n"));
		device = "Cloaking device";
		dev2 = "is";
		ind = CLOAK;
		dev3 = "it";
		stat = &Ship.cloaked;
	}
	else
	{
		/* shields */
		device = "Shields";
		dev2 = "are";
		dev3 = "them";
		ind = SHIELD;
		stat = &Ship.shldup;
	}
	if (damaged(ind))
	{
		if (f <= 0)
			out(ind);
		return;
	}
	if (Ship.cond == DOCKED)
	{
		printf("%s %s down while docked\n", device, dev2);
		return;
	}
	if (f <= 0 && !testnl())
	{
		r = getcodpar("Up or down", Udtab);
D 2
		i = r->value;
E 2
I 2
		i = (int) r->value;
E 2
	}
	else
	{
		if (*stat)
D 2
			printf(-1, s, "%s %s up.  Do you want %s down", device, dev2, dev3);
E 2
I 2
D 4
			sprintf(s, "%s %s up.  Do you want %s down", device, dev2, dev3);
E 4
I 4
			(void)sprintf(s, "%s %s up.  Do you want %s down", device, dev2, dev3);
E 4
E 2
		else
D 2
			printf(-1, s, "%s %s down.  Do you want %s up", device, dev2, dev3);
E 2
I 2
D 4
			sprintf(s, "%s %s down.  Do you want %s up", device, dev2, dev3);
E 4
I 4
			(void)sprintf(s, "%s %s down.  Do you want %s up", device, dev2, dev3);
E 4
E 2
		if (!getynpar(s))
			return;
		i = !*stat;
	}
	if (*stat == i)
	{
		printf("%s already ", device);
		if (i)
			printf("up\n");
		else
			printf("down\n");
		return;
	}
	if (i)
		if (f >= 0)
D 2
			Ship.energy =- Param.shupengy;
E 2
I 2
			Ship.energy -= Param.shupengy;
E 2
		else
			Ship.cloakgood = 0;
	Move.free = 0;
	if (f >= 0)
		Move.shldchg = 1;
	*stat = i;
	return;
}
E 1
