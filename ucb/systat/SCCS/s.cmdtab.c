h53145
s 00007/00001/00046
d D 5.1 85/05/30 16:20:03 mckusick 5 4
c Add copyright
e
s 00007/00001/00040
d D 1.4 85/04/29 00:41:30 sam 4 3
c add netstat display
e
s 00014/00009/00027
d D 1.3 85/04/28 00:37:10 sam 3 2
c add vsta in; add help command (minimal); make loadav display something 
c which can be turned off
e
s 00014/00005/00022
d D 1.2 84/08/09 19:13:28 mckusick 2 1
c update to new sources from sam; weed out unnecessary #includes
e
s 00027/00000/00000
d D 1.1 83/10/02 21:41:03 sam 1 0
c date and time created 83/10/02 21:41:03 by sam
e
u
U
t
T
I 5
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 5
I 1
#ifndef lint
D 4
static char sccsid[] = "%W% (Lucasfilm) %G%";
E 4
I 4
static char sccsid[] = "%W% (Berkeley) %G%";
E 4
D 5
#endif
E 5
I 5
#endif not lint
E 5

#include "systat.h"

D 2
int     showpigs(), fetchpigs(), labelpigs(), initpigs(), closepigs();
E 2
I 2
int     showpigs(), fetchpigs(), labelpigs();
int	initpigs(), closepigs();
E 2
WINDOW	*openpigs();
D 2
int     showswap(), fetchswap(), labelswap(), initswap(), closeswap();
E 2
I 2
int     showswap(), fetchswap(), labelswap();
int	initswap(), closeswap();
E 2
WINDOW	*openswap();
D 2
int	showmbufs(), fetchmbufs(), labelmbufs(), initmbufs(), closembufs();
E 2
I 2
int	showmbufs(), fetchmbufs(), labelmbufs();
int	initmbufs(), closembufs();
E 2
WINDOW	*openmbufs();
D 2
int	showiostat(), fetchiostat(), labeliostat(), initiostat(), closeiostat();
E 2
I 2
int	showiostat(), fetchiostat(), labeliostat();
int	initiostat(), closeiostat(), cmdiostat();
E 2
WINDOW	*openiostat();
I 2
D 3
int	showvmstat(), fetchvmstat(), labelvmstat();
int	initvmstat(), closevmstat();
WINDOW	*openvmstat();
E 3
I 3
int	showkre(), fetchkre(), labelkre();
int	initkre(), closekre(), cmdkre();
WINDOW	*openkre();
I 4
int	shownetstat(), fetchnetstat(), labelnetstat();
int	initnetstat(), closenetstat(), cmdnetstat();
WINDOW	*opennetstat();
E 4
E 3
E 2

struct	cmdtab cmdtab[] = {
        { "pigs",	showpigs,	fetchpigs,	labelpigs,
D 3
	  initpigs,	openpigs,	closepigs },
E 3
I 3
	  initpigs,	openpigs,	closepigs,	0,
	  CF_LOADAV },
E 3
        { "swap",	showswap,	fetchswap,	labelswap,
D 3
	  initswap,	openswap,	closeswap },
E 3
I 3
	  initswap,	openswap,	closeswap,	0,
	  CF_LOADAV },
E 3
        { "mbufs",	showmbufs,	fetchmbufs,	labelmbufs,
D 3
	  initmbufs,	openmbufs,	closembufs },
E 3
I 3
	  initmbufs,	openmbufs,	closembufs,	0,
	  CF_LOADAV },
E 3
        { "iostat",	showiostat,	fetchiostat,	labeliostat,
D 2
	  initiostat,	openiostat,	closeiostat },
E 2
I 2
D 3
	  initiostat,	openiostat,	closeiostat,	cmdiostat },
        { "vmstat",	showvmstat,	fetchvmstat,	labelvmstat,
	  initvmstat,	openvmstat,	closevmstat },
E 3
I 3
	  initiostat,	openiostat,	closeiostat,	cmdiostat,
	  CF_LOADAV },
        { "vmstat",	showkre,	fetchkre,	labelkre,
	  initkre,	openkre,	closekre,	cmdkre,
	  0 },
I 4
        { "netstat",	shownetstat,	fetchnetstat,	labelnetstat,
	  initnetstat,	opennetstat,	closenetstat,	cmdnetstat,
	  CF_LOADAV },
E 4
E 3
E 2
        { 0 }
};
struct  cmdtab *curcmd = &cmdtab[0];
E 1
