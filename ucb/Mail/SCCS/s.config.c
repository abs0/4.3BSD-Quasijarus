h60422
s 00011/00005/00063
d D 5.3 88/02/18 17:03:42 bostic 12 11
c written by Kurt Shoens; added Berkeley specific header
e
s 00001/00001/00067
d D 5.2 85/06/21 17:09:33 mckusick 11 10
c botched copyright
e
s 00007/00001/00061
d D 5.1 85/06/06 10:29:12 dist 10 9
c Add copyright
e
s 00001/00030/00061
d D 1.9 84/07/19 15:43:36 ralph 9 8
c delete old berknet tables
e
s 00003/00003/00088
d D 1.8 83/08/11 22:14:34 sam 8 7
c standardize sccs keyword lines
e
s 00000/00004/00091
d D 1.7 83/05/24 15:01:16 leres 7 6
c Removed old c70 stuff
e
s 00001/00000/00094
d D 1.6 82/09/02 12:38:14 mckusick 6 5
c added line in netmach table that is dynamically filled in
c by hosts that have the gethostname() system call
e
s 00002/00002/00092
d D 1.5 82/07/28 15:34:37 kurt 5 4
c changed names of nettypetab and netkindtab to 
c ntypetab and nkindtab respectively to satisfy pdp-11 name length restrictions. 
c 
e
s 00001/00000/00093
d D 1.4 82/03/24 15:23:12 kurt 4 3
c added ucbcad machine 
c 
e
s 00001/00000/00092
d D 1.3 82/02/14 19:27:30 kurt 3 2
c added entry for machine kim in the table 
c 
e
s 00006/00004/00086
d D 1.2 81/12/07 15:49:28 kurt 2 1
c changed berkeley arpanet host to the c70 
c 
e
s 00090/00000/00000
d D 1.1 81/09/09 09:19:08 kurt 1 0
c date and time created 81/09/09 09:19:08 by kurt
e
u
U
f b 
f i 
t
T
I 10
/*
 * Copyright (c) 1980 Regents of the University of California.
D 12
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 12
I 12
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 12
 */

E 10
I 1
D 8
#

static	char	*SccsID[] = "%W% %G%";
E 8
I 8
D 12
#ifndef lint
D 11
static char sccsid[] = "%W% (Berkeley) %G%";
E 11
I 11
static char *sccsid = "%W% (Berkeley) %G%";
E 11
D 10
#endif
E 10
I 10
#endif not lint
E 12
I 12
#ifdef notdef
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* notdef */
E 12
E 10
E 8

/*
 * This file contains definitions of network data used by Mail
 * when replying.  See also:  configdefs.h and optim.c
 */

/*
 * The subterfuge with CONFIGFILE is to keep cc from seeing the
 * external defintions in configdefs.h.
 */
#define	CONFIGFILE
#include "configdefs.h"

/*
 * Set of network separator characters.
 */
char	*metanet = "!^:%@.";

/*
 * Host table of "known" hosts.  See the comment in configdefs.h;
 * not all accessible hosts need be here (fortunately).
 */
struct netmach netmach[] = {
I 2
D 7
	"c70",		'7',		AN|SN,
E 7
D 9
	"berkeley",	'7',		AN|SN,
D 7
	"berk-c70",	'7',		AN|SN,
	"ucb-c70",	'7',		AN|SN,
E 7
E 2
	"a",		'a',		SN,
	"b",		'b',		SN,
	"c",		'c',		SN,
	"d",		'd',		SN,
	"e",		'e',		SN,
	"f",		'f',		SN,
	"g",		'g',		SN,
D 2
	"ingres",	'i',		AN|SN,
	"ing70",	'i',		AN|SN,
	"berkeley",	'i',		AN|SN,
E 2
I 2
	"ingres",	'i',		SN,
	"ing70",	'i',		SN,
E 2
	"ingvax",	'j',		SN|BN,
	"virus",	'k',		SN,
	"vlsi",		'l',		SN,
	"image",	'm',		SN,
	"esvax",	'o',		SN,
	"sesm",		'o',		SN,
I 4
	"ucbcad",	'p',		SN|BN,
E 4
	"q",		'q',		SN,
I 3
	"kim",		'n',		SN,
E 3
	"research",	'R',		BN,
	"arpavax",	'r',		SN|BN,
	"src",		's',		SN,
	"mathstat",	't',		SN,
D 7
	"csvax",	'v',		BN|SN,
E 7
	"vax",		'v',		BN|SN,
	"ucb",		'v',		BN|SN,
	"ucbvax",	'v',		BN|SN,
	"onyx",		'x',		SN,
D 2
	"vax135",	'X',		BN,
E 2
	"cory",		'y',		SN,
	"eecs40",	'z',		SN,
I 6
	EMPTY,		EMPTYID,	SN,	/* Filled in dynamically */
E 9
I 9
	EMPTY,		EMPTYID,	AN,	/* Filled in dynamically */
E 9
E 6
	0,		0,		0
};

/*
 * Table of ordered of preferred networks.  You probably won't need
 * to fuss with this unless you add a new network character (foolishly).
 */
struct netorder netorder[] = {
	AN,	'@',
	AN,	'%',
	SN,	':',
	BN,	'!',
	-1,	0
};

/*
 * Table to convert from network separator code in address to network
 * bit map kind.  With this transformation, we can deal with more than
 * one character having the same meaning easily.
 */
D 5
struct nettypetab nettypetab[] = {
E 5
I 5
struct ntypetab ntypetab[] = {
E 5
	'%',	AN,
	'@',	AN,
	':',	SN,
	'!',	BN,
	'^',	BN,
	0,	0
};

D 5
struct netkindtab netkindtab[] = {
E 5
I 5
struct nkindtab nkindtab[] = {
E 5
	AN,	IMPLICIT,
	BN,	EXPLICIT,
	SN,	IMPLICIT,
	0,	0
};
E 1
