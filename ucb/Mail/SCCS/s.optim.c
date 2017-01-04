h24432
s 00011/00005/00830
d D 5.9 88/02/18 17:04:12 bostic 22 21
c written by Kurt Shoens; added Berkeley specific header
e
s 00003/00002/00832
d D 5.8 87/09/28 20:48:26 bostic 21 20
c NULL dereference; bug report 4.3BSD/ucb/118
e
s 00002/00056/00832
d D 5.7 87/05/18 12:29:02 edward 20 19
c major rework: made faster, cleaned up, obsolete code removed,
c the whole thing should be chucked and written from scratch
e
s 00001/00001/00887
d D 5.6 86/11/26 16:01:48 bostic 19 18
c included strings.h
e
s 00001/00001/00887
d D 5.5 85/11/02 17:32:59 serge 18 17
c increase nbuf[] in netlook() to BUFSIZ (from mp@allegra.UUCP)
e
s 00002/00000/00886
d D 5.4 85/09/15 17:16:12 serge 17 16
c fix uninitialized variable problem (from guy@sun)
e
s 00001/00001/00885
d D 5.3 85/06/21 17:13:14 mckusick 16 15
c botched copyright
e
s 00001/00001/00885
d D 5.2 85/06/09 00:59:53 lepreau 15 14
c bumping the wrong hash idx var caused cores. From donn@utah-cs
e
s 00007/00001/00879
d D 5.1 85/06/06 10:39:39 dist 14 13
c Add copyright
e
s 00003/00002/00877
d D 2.10 84/07/26 10:36:21 ralph 13 12
c check buffer size.
e
s 00003/00003/00876
d D 2.9 83/08/11 22:18:37 sam 12 11
c standardize sccs keyword lines
e
s 00002/00002/00877
d D 2.8 83/03/02 20:19:08 leres 11 10
c Strange string allocation bug in netmap(). Fix was to have
c netmap() use savestr() when calling arpafix().
e
s 00002/00000/00877
d D 2.7 82/11/06 11:53:56 mckusick 10 9
c changes per kurt 
e
s 00019/00000/00858
d D 2.6 82/09/02 12:35:32 mckusick 9 8
c added routine inithost() to dynamically set the local host
c name to that returned by the gethostname() system call
e
s 00005/00005/00853
d D 2.5 82/07/28 15:36:51 kurt 8 7
c changed nettypetab to ntypetab, netkindtab to nkindtab to satisfy pdp-11 
c name length restrictions. 
c 
e
s 00001/00001/00857
d D 2.4 81/09/09 11:19:42 kurt 7 6
c optim1() in some cases erroneously returned before clearing its
c result
e
s 00020/00110/00838
d D 2.3 81/09/09 09:21:05 kurt 6 5
c moved all the network configuration stuff into a separate file
c for convenient modification
e
s 00003/00000/00945
d D 2.2 81/09/08 17:01:06 kurt 5 4
c put in check for a particular botch which seems to be happening for no reason
e
s 00000/00000/00945
d D 2.1 81/07/01 11:10:03 kurt 4 3
c Release to Heidi Stettner
e
s 00011/00011/00934
d D 1.3 81/07/01 11:02:17 kurt 3 2
c fixed strange condition causing core images; not picky about "no way to get
c to..." anymore
e
s 00002/00001/00943
d D 1.2 81/03/11 15:49:26 kas 2 1
c made the Onyx machine 'x', rather than vax135
e
s 00944/00000/00000
d D 1.1 80/10/08 09:51:03 kas 1 0
c date and time created 80/10/08 09:51:03 by kas
e
u
U
f b 
t
T
I 14
/*
 * Copyright (c) 1980 Regents of the University of California.
D 22
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 22
I 22
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 22
 */

E 14
I 1
D 12
#
E 12
I 12
D 22
#ifndef lint
D 16
static char sccsid[] = "%W% (Berkeley) %G%";
E 16
I 16
static char *sccsid = "%W% (Berkeley) %G%";
E 16
D 14
#endif
E 14
I 14
#endif not lint
E 22
I 22
#ifdef notdef
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* notdef */
E 22
E 14
E 12

/*
 * Mail -- a program for sending and receiving mail.
 *
 * Network name modification routines.
 */

#include "rcv.h"
I 6
#include "configdefs.h"
E 6
D 20
#include <ctype.h>
I 19
#include <strings.h>
E 20
E 19
D 12

static char *SccsId = "%W% %G%";
E 12

/*
 * Map a name into the correct network "view" of the
 * name.  This is done by prepending the name with the
 * network address of the sender, then optimizing away
 * nonsense.
 */

D 6
char	*metanet = "!^:%@.";

E 6
char *
netmap(name, from)
	char name[], from[];
{
	char nbuf[BUFSIZ], ret[BUFSIZ];
	register char *cp;

	if (strlen(from) == 0)
		return(name);
	if (any('@', name) || any('%', name))
D 11
		return(arpafix(name, from));
E 11
I 11
		return(savestr(arpafix(name, from)));
E 11
	cp = revarpa(from);
	if (cp == NOSTR)
		return(name);
	strcpy(nbuf, cp);
	cp = &nbuf[strlen(nbuf) - 1];
	while (!any(*cp, metanet) && cp > nbuf)
		cp--;
	if (cp == nbuf)
		return(name);
	*++cp = 0;
D 21
	strcat(nbuf, revarpa(name));
E 21
I 21
	if ((cp = revarpa(name)) != NOSTR)
		strcat(nbuf, cp);
E 21
	optim(nbuf, ret);
	cp = revarpa(ret);
D 21
	if (!icequal(name, cp))
E 21
I 21
	if (cp && !icequal(name, cp))
E 21
D 11
		return((char *) savestr(cp));
E 11
I 11
		return(savestr(cp));
E 11
	return(name);
}

/*
D 20
 * Rename the given network path to use
 * the kinds of names that we would right here.
 */

char *
rename(str)
	char str[];
{
	register char *cp, *cp2;
	char buf[BUFSIZ], path[BUFSIZ];
	register int c, host;

I 17
	cp = str;
E 17
	strcpy(path, "");
	for (;;) {
		if ((c = *cp++) == 0)
			break;
		cp2 = buf;
		while (!any(c, metanet) && c != 0) {
			*cp2++ = c;
			c = *cp++;
		}
		*cp2 = 0;
		if (c == 0) {
			strcat(path, buf);
			break;
		}
		host = netlook(buf, ntype(c));
		strcat(path, netname(host));
		stradd(path, c);
	}
	if (strcmp(str, path) != 0)
		return(savestr(path));
	return(str);
}
I 6

E 6
/*
E 20
 * Turn a network machine name into a unique character
D 6
 * + give connection-to status.  BN -- connected to Bell Net.
 * AN -- connected to ARPA net, SN -- connected to Schmidt net.
 * CN -- connected to COCANET.
E 6
 */
D 6

#define	AN	1			/* Connected to ARPA net */
#define	BN	2			/* Connected to BTL net */
#define	CN	4			/* Connected to COCANET */
#define	SN	8			/* Connected to Schmidt net */

struct netmach {
	char	*nt_machine;
	char	nt_mid;
	short	nt_type;
} netmach[] = {
	"a",		'a',		SN,
	"b",		'b',		SN,
	"c",		'c',		SN,
	"d",		'd',		SN,
	"e",		'e',		SN,
	"f",		'f',		SN,
	"g",		'g',		SN,
	"ingres",	'i',		AN|SN,
	"ing70",	'i',		AN|SN,
	"berkeley",	'i',		AN|SN,
D 3
	"ingvax",	'j',		SN,
E 3
I 3
	"ingvax",	'j',		SN|BN,
E 3
	"virus",	'k',		SN,
	"vlsi",		'l',		SN,
	"image",	'm',		SN,
	"esvax",	'o',		SN,
	"sesm",		'o',		SN,
	"q",		'q',		SN,
	"research",	'R',		BN,
D 3
	"arpavax",	'r',		SN,
E 3
I 3
	"arpavax",	'r',		SN|BN,
E 3
	"src",		's',		SN,
	"mathstat",	't',		SN,
	"csvax",	'v',		BN|SN,
	"vax",		'v',		BN|SN,
	"ucb",		'v',		BN|SN,
	"ucbvax",	'v',		BN|SN,
D 2
	"vax135",	'x',		BN,
E 2
I 2
	"onyx",		'x',		SN,
	"vax135",	'X',		BN,
E 2
	"cory",		'y',		SN,
	"eecs40",	'z',		SN,
	0,		0,		0
};

E 6
netlook(machine, attnet)
	char machine[];
{
	register struct netmach *np;
	register char *cp, *cp2;
D 13
	char nbuf[20];
E 13
I 13
D 18
	char nbuf[100];
E 18
I 18
	char nbuf[BUFSIZ];
E 18
E 13

	/*
	 * Make into lower case.
	 */

	for (cp = machine, cp2 = nbuf; *cp; *cp2++ = little(*cp++))
D 13
		;
E 13
I 13
		if (cp2 >= &nbuf[sizeof(nbuf)-1])
			break;
E 13
	*cp2 = 0;

	/*
	 * If a single letter machine, look through those first.
	 */

	if (strlen(nbuf) == 1)
		for (np = netmach; np->nt_mid != 0; np++)
			if (np->nt_mid == nbuf[0])
				return(nbuf[0]);

	/*
	 * Look for usual name
	 */

	for (np = netmach; np->nt_mid != 0; np++)
		if (strcmp(np->nt_machine, nbuf) == 0)
			return(np->nt_mid);

	/*
	 * Look in side hash table.
	 */

	return(mstash(nbuf, attnet));
}

/*
 * Make a little character.
 */

little(c)
	register int c;
{

	if (c >= 'A' && c <= 'Z')
		c += 'a' - 'A';
	return(c);
}

/*
 * Turn a network unique character identifier into a network name.
 */

char *
netname(mid)
{
	register struct netmach *np;
	char *mlook();

	if (mid & 0200)
		return(mlook(mid));
	for (np = netmach; np->nt_mid != 0; np++)
		if (np->nt_mid == mid)
			return(np->nt_machine);
	return(NOSTR);
}

/*
 * Deal with arpa net addresses.  The way this is done is strange.
 * In particular, if the destination arpa net host is not Berkeley,
 * then the address is correct as stands.  Otherwise, we strip off
 * the trailing @Berkeley, then cook up a phony person for it to
 * be from and optimize the result.
 */
char *
arpafix(name, from)
	char name[];
	char from[];
{
	register char *cp;
	register int arpamach;
	char newname[BUFSIZ];
	char fake[5];
	char fakepath[20];

	if (debug) {
		fprintf(stderr, "arpafix(%s, %s)\n", name, from);
	}
	cp = rindex(name, '@');
	if (cp == NOSTR)
		cp = rindex(name, '%');
	if (cp == NOSTR) {
D 20
		fprintf(stderr, "Somethings amiss -- no @ or % in arpafix\n");
E 20
I 20
		fprintf(stderr, "Somethings amiss -- no @ or %% in arpafix\n");
E 20
		return(name);
	}
	cp++;
	arpamach = netlook(cp, '@');
	if (arpamach == 0) {
		if (debug)
			fprintf(stderr, "machine %s unknown, uses: %s\n", cp, name);
		return(name);
	}
	if (((nettype(arpamach) & nettype(LOCAL)) & ~AN) == 0) {
		if (debug)
			fprintf(stderr, "machine %s known but remote, uses: %s\n",
			    cp, name);
		return(name);
	}
	strcpy(newname, name);
	cp = rindex(newname, '@');
	if (cp == NOSTR)
		cp = rindex(newname, '%');
	*cp = 0;
	fake[0] = arpamach;
	fake[1] = ':';
	fake[2] = LOCAL;
	fake[3] = ':';
	fake[4] = 0;
	prefer(fake);
	strcpy(fakepath, netname(fake[0]));
	stradd(fakepath, fake[1]);
	strcat(fakepath, "daemon");
	if (debug)
		fprintf(stderr, "machine local, call netmap(%s, %s)\n",
		    newname, fakepath);
	return(netmap(newname, fakepath));
}

/*
 * Take a network machine descriptor and find the types of connected
 * nets and return it.
 */

nettype(mid)
{
	register struct netmach *np;

	if (mid & 0200)
		return(mtype(mid));
	for (np = netmach; np->nt_mid != 0; np++)
		if (np->nt_mid == mid)
			return(np->nt_type);
	return(0);
}

/*
 * Hashing routines to salt away machines seen scanning
 * networks paths that we don't know about.
 */

#define	XHSIZE		19		/* Size of extra hash table */
#define	NXMID		(XHSIZE*3/4)	/* Max extra machines */

struct xtrahash {
	char	*xh_name;		/* Name of machine */
	short	xh_mid;			/* Machine ID */
	short	xh_attnet;		/* Attached networks */
} xtrahash[XHSIZE];

struct xtrahash	*xtab[XHSIZE];		/* F: mid-->machine name */

short	midfree;			/* Next free machine id */

/*
 * Initialize the extra host hash table.
 * Called by sreset.
 */

minit()
{
	register struct xtrahash *xp, **tp;
D 20
	register int i;
E 20

	midfree = 0;
	tp = &xtab[0];
	for (xp = &xtrahash[0]; xp < &xtrahash[XHSIZE]; xp++) {
		xp->xh_name = NOSTR;
		xp->xh_mid = 0;
		xp->xh_attnet = 0;
		*tp++ = (struct xtrahash *) 0;
	}
}

/*
 * Stash a net name in the extra host hash table.
 * If a new entry is put in the hash table, deduce what
 * net the machine is attached to from the net character.
 *
 * If the machine is already known, add the given attached
 * net to those already known.
 */

mstash(name, attnet)
	char name[];
{
	register struct xtrahash *xp;
	struct xtrahash *xlocate();
I 6
	int x;
E 6

	xp = xlocate(name);
	if (xp == (struct xtrahash *) 0) {
		printf("Ran out of machine id spots\n");
		return(0);
	}
	if (xp->xh_name == NOSTR) {
		if (midfree >= XHSIZE) {
			printf("Out of machine ids\n");
			return(0);
		}
		xtab[midfree] = xp;
		xp->xh_name = savestr(name);
		xp->xh_mid = 0200 + midfree++;
	}
D 6
	switch (attnet) {
	case '!':
	case '^':
		xp->xh_attnet |= BN;
		break;

	default:
	case ':':
E 6
I 6
	x = ntype(attnet);
	if (x == 0)
E 6
		xp->xh_attnet |= SN;
D 6
		break;

	case '@':
	case '%':
		xp->xh_attnet |= AN;
		break;
	}
E 6
I 6
	else
		xp->xh_attnet |= x;
E 6
	return(xp->xh_mid);
}

/*
 * Search for the given name in the hash table
 * and return the pointer to it if found, or to the first
 * empty slot if not found.
 *
 * If no free slots can be found, return 0.
 */

struct xtrahash *
xlocate(name)
	char name[];
{
	register int h, q, i;
	register char *cp;
	register struct xtrahash *xp;

	for (h = 0, cp = name; *cp; h = (h << 2) + *cp++)
		;
	if (h < 0 && (h = -h) < 0)
		h = 0;
	h = h % XHSIZE;
	cp = name;
	for (i = 0, q = 0; q < XHSIZE; i++, q = i * i) {
		xp = &xtrahash[(h + q) % XHSIZE];
		if (xp->xh_name == NOSTR)
			return(xp);
		if (strcmp(cp, xp->xh_name) == 0)
			return(xp);
		if (h - q < 0)
D 15
			q += XHSIZE;
E 15
I 15
			h += XHSIZE;
E 15
		xp = &xtrahash[(h - q) % XHSIZE];
		if (xp->xh_name == NOSTR)
			return(xp);
		if (strcmp(cp, xp->xh_name) == 0)
			return(xp);
	}
	return((struct xtrahash *) 0);
}

/*
 * Return the name from the extra host hash table corresponding
 * to the passed machine id.
 */

char *
mlook(mid)
{
	register int m;

	if ((mid & 0200) == 0)
		return(NOSTR);
	m = mid & 0177;
	if (m >= midfree) {
		printf("Use made of undefined machine id\n");
		return(NOSTR);
	}
	return(xtab[m]->xh_name);
}

/*
 * Return the bit mask of net's that the given extra host machine
 * id has so far.
 */

mtype(mid)
{
	register int m;

	if ((mid & 0200) == 0)
		return(0);
	m = mid & 0177;
	if (m >= midfree) {
		printf("Use made of undefined machine id\n");
		return(0);
	}
	return(xtab[m]->xh_attnet);
}

/*
 * Take a network name and optimize it.  This gloriously messy
D 3
 * opertions takes place as follows:  the name with machine names
E 3
I 3
 * operation takes place as follows:  the name with machine names
E 3
 * in it is tokenized by mapping each machine name into a single
 * character machine id (netlook).  The separator characters (network
 * metacharacters) are left intact.  The last component of the network
 * name is stripped off and assumed to be the destination user name --
 * it does not participate in the optimization.  As an example, the
 * name "research!vax135!research!ucbvax!bill" becomes, tokenized,
 * "r!x!r!v!" and "bill"  A low level routine, optim1, fixes up the
 * network part (eg, "r!x!r!v!"), then we convert back to network
 * machine names and tack the user name on the end.
 *
 * The result of this is copied into the parameter "name"
 */

optim(net, name)
	char net[], name[];
{
	char netcomp[BUFSIZ], netstr[40], xfstr[40];
	register char *cp, *cp2;
	register int c;

	strcpy(netstr, "");
	cp = net;
	for (;;) {
		/*
		 * Rip off next path component into netcomp
		 */
		cp2 = netcomp;
		while (*cp && !any(*cp, metanet))
			*cp2++ = *cp++;
		*cp2 = 0;
		/*
		 * If we hit null byte, then we just scanned
		 * the destination user name.  Go off and optimize
		 * if its so.
		 */
		if (*cp == 0)
			break;
		if ((c = netlook(netcomp, *cp)) == 0) {
			printf("No host named \"%s\"\n", netcomp);
err:
			strcpy(name, net);
			return;
		}
		stradd(netstr, c);
		stradd(netstr, *cp++);
		/*
		 * If multiple network separators given,
		 * throw away the extras.
		 */
		while (any(*cp, metanet))
			cp++;
	}
	if (strlen(netcomp) == 0) {
		printf("net name syntax\n");
		goto err;
	}
	optim1(netstr, xfstr);

	/*
	 * Convert back to machine names.
	 */

	cp = xfstr;
	strcpy(name, "");
	while (*cp) {
		if ((cp2 = netname(*cp++)) == NOSTR) {
			printf("Made up bad net name\n");
I 5
			printf("Machine code %c (0%o)\n", cp[-1], cp[-1]);
			printf("Sorry -- dumping now.  Alert K. Shoens\n");
D 20
			core(0);
E 20
I 20
			core();
E 20
E 5
			goto err;
		}
		strcat(name, cp2);
		stradd(name, *cp++);
	}
	strcat(name, netcomp);
}

/*
 * Take a string of network machine id's and separators and
 * optimize them.  We process these by pulling off maximal
 * leading strings of the same type, passing these to the appropriate
 * optimizer and concatenating the results.
 */

D 6
#define	IMPLICIT	1
#define	EXPLICIT	2

E 6
optim1(netstr, name)
	char netstr[], name[];
{
	char path[40], rpath[40];
	register char *cp, *cp2;
	register int tp, nc;

	cp = netstr;
	prefer(cp);
I 7
	strcpy(name, "");
E 7
I 3
	/*
	 * If the address ultimately points back to us,
	 * just return a null network path.
	 */
	if (strlen(cp) > 1 && cp[strlen(cp) - 2] == LOCAL)
		return;
E 3
D 7
	strcpy(name, "");
E 7
	while (*cp != 0) {
		strcpy(path, "");
		tp = ntype(cp[1]);
		nc = cp[1];
		while (*cp && tp == ntype(cp[1])) {
			stradd(path, *cp++);
			cp++;
		}
		switch (netkind(tp)) {
		default:
			strcpy(rpath, path);
			break;

		case IMPLICIT:
			optimimp(path, rpath);
			break;

		case EXPLICIT:
			optimex(path, rpath);
			break;
		}
		for (cp2 = rpath; *cp2 != 0; cp2++) {
			stradd(name, *cp2);
			stradd(name, nc);
		}
	}
	optiboth(name);
	prefer(name);
}

/*
 * Return the network of the separator --
 *	AN for arpa net
 *	BN for Bell labs net
 *	SN for Schmidt (berkeley net)
 *	0 if we don't know.
 */

ntype(nc)
	register int nc;
{
I 6
D 8
	register struct nettypetab *np;
E 8
I 8
	register struct ntypetab *np;
E 8
E 6

D 6
	switch (nc) {
	case '^':
	case '!':
		return(BN);

	case ':':
	case '.':
		return(SN);

	case '@':
	case '%':
		return(AN);

	default:
		return(0);
	}
	/* NOTREACHED */
E 6
I 6
D 8
	for (np = nettypetab; np->nt_char != 0; np++)
E 8
I 8
	for (np = ntypetab; np->nt_char != 0; np++)
E 8
		if (np->nt_char == nc)
D 8
			return(np->nt_type);
E 8
I 8
			return(np->nt_bcode);
E 8
	return(0);
E 6
}

/*
 * Return the kind of routing used for the particular net
 * EXPLICIT means explicitly routed
 * IMPLICIT means implicitly routed
 * 0 means don't know
 */

netkind(nt)
	register int nt;
{
I 6
D 8
	register struct netkindtab *np;
E 8
I 8
	register struct nkindtab *np;
E 8
E 6

D 6
	switch (nt) {
	case BN:
		return(EXPLICIT);

	case AN:
	case SN:
		return(IMPLICIT);

	default:
		return(0);
	}
	/* NOTREACHED */
E 6
I 6
D 8
	for (np = netkindtab; np->nk_type != 0; np++)
E 8
I 8
	for (np = nkindtab; np->nk_type != 0; np++)
E 8
		if (np->nk_type == nt)
			return(np->nk_kind);
	return(0);
E 6
}

/*
 * Do name optimization for an explicitly routed network (eg BTL network).
 */

optimex(net, name)
	char net[], name[];
{
	register char *cp, *rp;
	register int m;
D 19
	char *rindex();
E 19

	strcpy(name, net);
	cp = name;
	if (strlen(cp) == 0)
		return(-1);
	if (cp[strlen(cp)-1] == LOCAL) {
		name[0] = 0;
		return(0);
	}
	for (cp = name; *cp; cp++) {
		m = *cp;
		rp = rindex(cp+1, m);
		if (rp != NOSTR)
			strcpy(cp, rp);
	}
	return(0);
}

/*
 * Do name optimization for implicitly routed network (eg, arpanet,
 * Berkeley network)
 */

optimimp(net, name)
	char net[], name[];
{
	register char *cp;
	register int m;

	cp = net;
	if (strlen(cp) == 0)
		return(-1);
	m = cp[strlen(cp) - 1];
	if (m == LOCAL) {
		strcpy(name, "");
		return(0);
	}
	name[0] = m;
	name[1] = 0;
	return(0);
}

/*
D 3

E 3
 * Perform global optimization on the given network path.
 * The trick here is to look ahead to see if there are any loops
 * in the path and remove them.  The interpretation of loops is
 * more strict here than in optimex since both the machine and net
 * type must match.
 */

optiboth(net)
	char net[];
{
	register char *cp, *cp2;
	char *rpair();

	cp = net;
	if (strlen(cp) == 0)
		return;
	if ((strlen(cp) % 2) != 0) {
		printf("Strange arg to optiboth\n");
		return;
	}
	while (*cp) {
		cp2 = rpair(cp+2, *cp);
		if (cp2 != NOSTR)
			strcpy(cp, cp2);
		cp += 2;
	}
}

/*
 * Find the rightmost instance of the given (machine, type) pair.
 */

char *
rpair(str, mach)
	char str[];
{
	register char *cp, *last;

I 17
	cp = str;
E 17
	last = NOSTR;
	while (*cp) {
		if (*cp == mach)
			last = cp;
		cp += 2;
	}
	return(last);
}

/*
 * Change the network separators in the given network path
 * to the preferred network transmission means.
 */

prefer(name)
	char name[];
{
	register char *cp;
	register int state, n;

	state = LOCAL;
	for (cp = name; *cp; cp += 2) {
		n = best(state, *cp);
		if (n)
			cp[1] = n;
		state = *cp;
	}
}

/*
 * Return the best network separator for the given machine pair.
 */

D 6
struct netorder {
	short	no_stat;
	char	no_char;
} netorder[] = {
	CN,	':',
	AN,	'@',
	AN,	'%',
	SN,	':',
	BN,	'!',
	-1,	0
};

E 6
best(src, dest)
{
	register int dtype, stype;
	register struct netorder *np;

	stype = nettype(src);
	dtype = nettype(dest);
I 3
	fflush(stdout);
E 3
	if (stype == 0 || dtype == 0) {
		printf("ERROR:  unknown internal machine id\n");
		return(0);
	}
D 3
	if ((stype & dtype) == 0) {
#ifdef DELIVERMAIL
		if (src != LOCAL)
#endif
			printf("No way to get from \"%s\" to \"%s\"\n", 
			    netname(src), netname(dest));
E 3
I 3
	if ((stype & dtype) == 0)
E 3
		return(0);
D 3
	}
E 3
	np = &netorder[0];
	while ((np->no_stat & stype & dtype) == 0)
		np++;
	return(np->no_char);
}

I 10
#ifdef	GETHOST
E 10
/*
I 9
 * Initialize the network name of the current host.
 */
inithost()
{
	register struct netmach *np;
	static char host[64];

	gethostname(host, sizeof host);
	for (np = netmach; np->nt_machine != 0; np++)
		if (strcmp(np->nt_machine, EMPTY) == 0)
			break;
	if (np->nt_machine == 0) {
		printf("Cannot find empty slot for dynamic host entry\n");
		exit(1);
	}
	np->nt_machine = host;
}
I 10
#endif	GETHOST
E 10

/*
E 9
 * Code to twist around arpa net names.
 */

#define WORD 257			/* Token for a string */

static	char netbuf[256];
static	char *yylval;

/*
 * Reverse all of the arpa net addresses in the given name to
 * be of the form "host @ user" instead of "user @ host"
 * This function is its own inverse.
 */

char *
revarpa(str)
	char str[];
{

	if (yyinit(str) < 0)
		return(NOSTR);
	if (name())
		return(NOSTR);
	if (strcmp(str, netbuf) == 0)
		return(str);
	return(savestr(netbuf));
}

/*
 * Parse (by recursive descent) network names, using the following grammar:
 *	name:
 *		term {':' term}
 *		term {'^' term}
 *		term {'!' term}
 *		term '@' name
 *		term '%' name
 *
 *	term:
 *		string of characters.
 */

name()
{
	register int t;
	register char *cp;

	for (;;) {
		t = yylex();
		if (t != WORD)
			return(-1);
		cp = yylval;
		t = yylex();
		switch (t) {
		case 0:
			strcat(netbuf, cp);
			return(0);

		case '@':
		case '%':
			if (name())
				return(-1);
			stradd(netbuf, '@');
			strcat(netbuf, cp);
			return(0);

		case WORD:
			return(-1);

		default:
			strcat(netbuf, cp);
			stradd(netbuf, t);
		}
	}
}

/*
 * Scanner for network names.
 */

static	char *charp;			/* Current input pointer */
static	int nexttok;			/* Salted away next token */

/*
 * Initialize the network name scanner.
 */

yyinit(str)
	char str[];
{
	static char lexbuf[BUFSIZ];

	netbuf[0] = 0;
	if (strlen(str) >= sizeof lexbuf - 1)
		return(-1);
	nexttok = 0;
	strcpy(lexbuf, str);
	charp = lexbuf;
	return(0);
}

/*
 * Scan and return a single token.
 * yylval is set to point to a scanned string.
 */

yylex()
{
	register char *cp, *dot;
	register int s;

	if (nexttok) {
		s = nexttok;
		nexttok = 0;
		return(s);
	}
	cp = charp;
	while (*cp && isspace(*cp))
		cp++;
	if (*cp == 0)
		return(0);
D 6
	if (any(*cp, "!^@:%")) {
E 6
I 6
	if (any(*cp, metanet)) {
E 6
		charp = cp+1;
		return(*cp);
	}
	dot = cp;
D 6
	while (*cp && !any(*cp, " \t!^@:%"))
E 6
I 6
	while (*cp && !any(*cp, metanet) && !any(*cp, " \t"))
E 6
		cp++;
D 6
	if (any(*cp, "!^@:%"))
E 6
I 6
	if (any(*cp, metanet))
E 6
		nexttok = *cp;
	if (*cp == 0)
		charp = cp;
	else
		charp = cp+1;
	*cp = 0;
	yylval = dot;
	return(WORD);
D 20
}

/*
 * Add a single character onto a string.
 */

stradd(str, c)
	register char *str;
	register int c;
{

	str += strlen(str);
	*str++ = c;
	*str = 0;
E 20
}
E 1
