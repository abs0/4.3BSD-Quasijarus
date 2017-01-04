h62313
s 00018/00006/00375
d D 5.9 88/01/27 03:02:46 marc 11 10
c add b0 and b1 capabilities: primary and secondary boot files
e
s 00001/00018/00380
d D 5.8 88/01/03 19:38:11 mckusick 10 9
c use strcasecmp in place of ustrcmp (4.3BSD/lib/101 torek)
e
s 00002/00002/00396
d D 5.7 87/03/28 11:22:18 bostic 9 8
c linted
e
s 00000/00029/00398
d D 5.6 87/02/02 22:26:48 karels 8 7
c toss byte swapping
e
s 00151/00025/00276
d D 5.5 87/01/19 15:27:19 karels 7 6
c convert to disklabels
e
s 00002/00002/00299
d D 5.4 86/10/15 21:16:47 sam 6 5
c check for 0 sector size and/or rpm's
e
s 00002/00002/00299
d D 5.3 86/03/09 21:12:03 donn 5 4
c added LIBC_SCCS condition for sccs ids
e
s 00002/00000/00299
d D 5.2 85/10/02 00:20:57 mckusick 4 3
c add :sf: (bad144 sector forwarding) and 
c :so: (sector rather than cylinder offsets)
e
s 00009/00001/00290
d D 5.1 85/05/30 15:06:27 dist 3 2
c Add copyright
e
s 00011/00004/00280
d D 4.2 83/02/08 12:50:01 sam 2 1
c add partition tables (don't belong here, but for now...)
e
s 00284/00000/00000
d D 4.1 83/02/06 16:34:13 sam 1 0
c date and time created 83/02/06 16:34:13 by sam
e
u
U
t
T
I 1
D 3
/*	%W% (Berkeley) %G%	*/
E 3
I 3
/*
D 7
 * Copyright (c) 1983 Regents of the University of California.
E 7
I 7
 * Copyright (c) 1983,1987 Regents of the University of California.
E 7
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

D 5
#ifndef lint
E 5
I 5
#if defined(LIBC_SCCS) && !defined(lint)
E 5
static char sccsid[] = "%W% (Berkeley) %G%";
D 5
#endif not lint
E 5
I 5
#endif LIBC_SCCS and not lint
E 5
E 3

D 7
#include <disktab.h>
E 7
I 7
#include <sys/param.h>
#include <sys/fs.h>
#include <sys/file.h>
#define DKTYPENAMES
#include <sys/disklabel.h>
E 7
#include <stdio.h>
I 9
#include <strings.h>
E 9

static	char *dgetstr();

D 7
struct disktab *
E 7
I 7
struct disklabel *
E 7
getdiskbyname(name)
	char *name;
{
D 7
	static struct disktab disk;
	static char localbuf[100], *cp = localbuf;
	register struct	disktab *dp = &disk;
E 7
I 7
D 11
	static struct disklabel disk;
	static char localbuf[100];
	char *cp, *cq;
E 11
I 11
	static struct	disklabel disk;
	static char 	boot[BUFSIZ];
	char	localbuf[BUFSIZ];
	char	buf[BUFSIZ];
	char	*cp, *cq;	/* can't be register */
E 11
	register struct	disklabel *dp = &disk;
E 7
D 2
	char p, part[3], buf[BUFSIZ];
E 2
I 2
	register struct partition *pp;
D 7
	char p, psize[3], pbsize[3], pfsize[3];
E 7
I 7
D 11
	char p, max, psize[3], pbsize[3], pfsize[3], poffset[3], ptype[3];
E 7
	char buf[BUFSIZ];
I 7
D 9
	int i;
E 9
	u_long *dx;
E 11
I 11
	char	p, max, psize[3], pbsize[3],
		pfsize[3], poffset[3], ptype[3];
	u_long	*dx;
E 11
E 7
E 2

	if (dgetent(buf, name) <= 0)
D 7
		return ((struct disktab *)0);
	dp->d_name = cp;
	strcpy(cp, name);
	cp += strlen(name) + 1;
	dp->d_type = dgetstr("ty", &cp);
	dp->d_secsize = dgetnum("se");
D 6
	if (dp->d_secsize < 0)
E 6
I 6
	if (dp->d_secsize <= 0)
E 6
		dp->d_secsize = 512;
E 7
I 7
		return ((struct disklabel *)0);
	bzero((char *)&disk, sizeof(disk));
I 11
	/*
	 * typename
	 */
E 11
	cq = dp->d_typename;
	cp = buf;
	while (cq < dp->d_typename + sizeof(dp->d_typename) - 1 &&
	    (*cq = *cp) && *cq != '|' && *cq != ':')
		cq++, cp++;
	*cq = '\0';
I 11
	/*
	 * boot name (optional)  xxboot, bootxx
	 */
	cp = boot;
	dp->d_boot0 = dgetstr("b0", &cp);
	dp->d_boot1 = dgetstr("b1", &cp);
E 11
	cp = localbuf;
	cq = dgetstr("ty", &cp);
	if (cq && strcmp(cq, "removable") == 0)
		dp->d_flags |= D_REMOVABLE;
	else  if (cq && strcmp(cq, "simulated") == 0)
		dp->d_flags |= D_RAMDISK;
	if (dgetflag("sf"))
		dp->d_flags |= D_BADSECT;
I 11

E 11
#define getnumdflt(field, dname, dflt) \
	{ int f = dgetnum(dname); \
	(field) = f == -1 ? (dflt) : f; }

	getnumdflt(dp->d_secsize, "se", DEV_BSIZE);
E 7
	dp->d_ntracks = dgetnum("nt");
	dp->d_nsectors = dgetnum("ns");
	dp->d_ncylinders = dgetnum("nc");
D 7
	dp->d_rpm = dgetnum("rm");
D 6
	if (dp->d_rpm < 0)
E 6
I 6
	if (dp->d_rpm <= 0)
E 6
		dp->d_rpm = 3600;
I 4
	dp->d_badsectforw = dgetflag("sf");
	dp->d_sectoffset = dgetflag("so");
E 7
I 7
	cq = dgetstr("dt", &cp);
	if (cq)
		dp->d_type = gettype(cq, dktypenames);
	else
		getnumdflt(dp->d_type, "dt", 0);
	getnumdflt(dp->d_secpercyl, "sc", dp->d_nsectors * dp->d_ntracks);
	getnumdflt(dp->d_secperunit, "su", dp->d_secpercyl * dp->d_ncylinders);
	getnumdflt(dp->d_rpm, "rm", 3600);
	getnumdflt(dp->d_interleave, "il", 1);
	getnumdflt(dp->d_trackskew, "sk", 0);
	getnumdflt(dp->d_cylskew, "cs", 0);
	getnumdflt(dp->d_headswitch, "hs", 0);
	getnumdflt(dp->d_trkseek, "ts", 0);
	getnumdflt(dp->d_bbsize, "bs", BBSIZE);
	getnumdflt(dp->d_sbsize, "sb", SBSIZE);
E 7
E 4
D 2
	strcpy(part, "px");
E 2
I 2
	strcpy(psize, "px");
	strcpy(pbsize, "bx");
	strcpy(pfsize, "fx");
E 2
D 7
	for (p = 'a'; p < 'i'; p++) {
D 2
		part[1] = p;
		dp->d_partitions[p - 'a'] = dgetnum(part);
E 2
I 2
		psize[1] = pbsize[1] = pfsize[1] = p;
		pp = &dp->d_partitions[p - 'a'];
E 7
I 7
	strcpy(poffset, "ox");
	strcpy(ptype, "tx");
	max = 'a' - 1;
	pp = &dp->d_partitions[0];
	for (p = 'a'; p < 'a' + MAXPARTITIONS; p++, pp++) {
		psize[1] = pbsize[1] = pfsize[1] = poffset[1] = ptype[1] = p;
E 7
		pp->p_size = dgetnum(psize);
D 7
		pp->p_bsize = dgetnum(pbsize);
		pp->p_fsize = dgetnum(pfsize);
E 7
I 7
		if (pp->p_size == -1)
			pp->p_size = 0;
		else {
			pp->p_offset = dgetnum(poffset);
			getnumdflt(pp->p_fsize, pfsize, 0);
			if (pp->p_fsize)
				pp->p_frag = dgetnum(pbsize) / pp->p_fsize;
			getnumdflt(pp->p_fstype, ptype, 0);
			if (pp->p_fstype == 0 && (cq = dgetstr(ptype, &cp)))
				pp->p_fstype = gettype(cq, fstypenames);
			max = p;
		}
E 7
E 2
	}
I 7
	dp->d_npartitions = max + 1 - 'a';
D 9
	strcpy(psize, "dx");
E 9
I 9
	(void)strcpy(psize, "dx");
E 9
	dx = dp->d_drivedata;
	for (p = '0'; p < '0' + NDDATA; p++, dx++) {
		psize[1] = p;
		getnumdflt(*dx, psize, 0);
	}
	dp->d_magic = DISKMAGIC;
	dp->d_magic2 = DISKMAGIC;
E 7
	return (dp);
}

#include <ctype.h>

static	char *tbuf;
static	char *dskip();
static	char *ddecode();

/*
 * Get an entry for disk name in buffer bp,
 * from the diskcap file.  Parse is very rudimentary;
 * we just notice escaped newlines.
 */
static
dgetent(bp, name)
	char *bp, *name;
{
	register char *cp;
	register int c;
	register int i = 0, cnt = 0;
	char ibuf[BUFSIZ];
	int tf;

	tbuf = bp;
	tf = open(DISKTAB, 0);
	if (tf < 0)
		return (-1);
	for (;;) {
		cp = bp;
		for (;;) {
			if (i == cnt) {
				cnt = read(tf, ibuf, BUFSIZ);
				if (cnt <= 0) {
					close(tf);
					return (0);
				}
				i = 0;
			}
			c = ibuf[i++];
			if (c == '\n') {
				if (cp > bp && cp[-1] == '\\'){
					cp--;
					continue;
				}
				break;
			}
			if (cp >= bp+BUFSIZ) {
				write(2,"Disktab entry too long\n", 23);
				break;
			} else
				*cp++ = c;
		}
		*cp = 0;

		/*
		 * The real work for the match.
		 */
		if (dnamatch(name)) {
			close(tf);
			return (1);
		}
	}
}

/*
 * Dnamatch deals with name matching.  The first field of the disktab
 * entry is a sequence of names separated by |'s, so we compare
 * against each such name.  The normal : terminator after the last
 * name (before the first field) stops us.
 */
static
dnamatch(np)
	char *np;
{
	register char *Np, *Bp;

	Bp = tbuf;
	if (*Bp == '#')
		return (0);
	for (;;) {
		for (Np = np; *Np && *Bp == *Np; Bp++, Np++)
			continue;
		if (*Np == 0 && (*Bp == '|' || *Bp == ':' || *Bp == 0))
			return (1);
		while (*Bp && *Bp != ':' && *Bp != '|')
			Bp++;
		if (*Bp == 0 || *Bp == ':')
			return (0);
		Bp++;
	}
}

/*
 * Skip to the next field.  Notice that this is very dumb, not
 * knowing about \: escapes or any such.  If necessary, :'s can be put
 * into the diskcap file in octal.
 */
static char *
dskip(bp)
	register char *bp;
{

	while (*bp && *bp != ':')
		bp++;
	if (*bp == ':')
		bp++;
	return (bp);
}

/*
 * Return the (numeric) option id.
 * Numeric options look like
 *	li#80
 * i.e. the option string is separated from the numeric value by
 * a # character.  If the option is not found we return -1.
 * Note that we handle octal numbers beginning with 0.
 */
static
dgetnum(id)
	char *id;
{
	register int i, base;
	register char *bp = tbuf;

	for (;;) {
		bp = dskip(bp);
		if (*bp == 0)
			return (-1);
		if (*bp++ != id[0] || *bp == 0 || *bp++ != id[1])
			continue;
		if (*bp == '@')
			return (-1);
		if (*bp != '#')
			continue;
		bp++;
		base = 10;
		if (*bp == '0')
			base = 8;
		i = 0;
		while (isdigit(*bp))
			i *= base, i += *bp++ - '0';
		return (i);
	}
}

/*
 * Handle a flag option.
 * Flag options are given "naked", i.e. followed by a : or the end
 * of the buffer.  Return 1 if we find the option, or 0 if it is
 * not given.
 */
static
dgetflag(id)
	char *id;
{
	register char *bp = tbuf;

	for (;;) {
		bp = dskip(bp);
		if (!*bp)
			return (0);
		if (*bp++ == id[0] && *bp != 0 && *bp++ == id[1]) {
			if (!*bp || *bp == ':')
				return (1);
			else if (*bp == '@')
				return (0);
		}
	}
}

/*
 * Get a string valued option.
 * These are given as
 *	cl=^Z
 * Much decoding is done on the strings, and the strings are
 * placed in area, which is a ref parameter which is updated.
 * No checking on area overflow.
 */
static char *
dgetstr(id, area)
	char *id, **area;
{
	register char *bp = tbuf;

	for (;;) {
		bp = dskip(bp);
		if (!*bp)
			return (0);
		if (*bp++ != id[0] || *bp == 0 || *bp++ != id[1])
			continue;
		if (*bp == '@')
			return (0);
		if (*bp != '=')
			continue;
		bp++;
		return (ddecode(bp, area));
	}
}

/*
 * Tdecode does the grung work to decode the
 * string capability escapes.
 */
static char *
ddecode(str, area)
	register char *str;
	char **area;
{
	register char *cp;
	register int c;
	register char *dp;
	int i;

	cp = *area;
	while ((c = *str++) && c != ':') {
		switch (c) {

		case '^':
			c = *str++ & 037;
			break;

		case '\\':
			dp = "E\033^^\\\\::n\nr\rt\tb\bf\f";
			c = *str++;
nextc:
			if (*dp++ == c) {
				c = *dp++;
				break;
			}
			dp++;
			if (*dp)
				goto nextc;
			if (isdigit(c)) {
				c -= '0', i = 2;
				do
					c <<= 3, c |= *str++ - '0';
				while (--i && isdigit(*str));
			}
			break;
		}
		*cp++ = c;
	}
	*cp++ = 0;
	str = *area;
	*area = cp;
	return (str);
I 7
}

static
gettype(t, names)
	char *t;
	char **names;
{
	register char **nm;

	for (nm = names; *nm; nm++)
D 10
		if (ustrcmp(t, *nm) == 0)
E 10
I 10
		if (strcasecmp(t, *nm) == 0)
E 10
			return (nm - names);
	if (isdigit(*t))
		return (atoi(t));
D 10
	return (0);
}

static
ustrcmp(s1, s2)
	register char *s1, *s2;
{
#define	lower(c)	(islower(c) ? (c) : tolower(c))

	for (; *s1; s1++, s2++) {
		if (*s1 == *s2)
			continue;
		if (isalpha(*s1) && isalpha(*s2) &&
		    lower(*s1) == lower(*s2))
			continue;
		return (*s2 - *s1);
	}
E 10
	return (0);
}

D 8
/*
 * Swab disk label if needed.
 */
#if ENDIAN != BIG
/* ARGSUSED */
#endif
swablabel(lp)
	register struct disklabel *lp;
{
#if ENDIAN != BIG
	register u_long *p;
	register struct partition *pp;
	int npart;

	lp->d_magic = ntohl(lp->d_magic);
	lp->d_type = ntohs(lp->d_type);
	lp->d_subtype = ntohs(lp->d_subtype);
	for (p = &lp->d_swabfirst; p <= &lp->d_swablast; p++)
		*p = ntohl(*p);
	npart = lp->d_npartitions;
	for (pp = lp->d_partitions; pp < &lp->d_partitions[npart]; pp++) {
		pp->p_size = ntohl(pp->p_size);
		pp->p_offset = ntohl(pp->p_offset);
		pp->p_fsize = ntohl(pp->p_fsize);
		pp->p_cpg = ntohs(pp->p_cpg);
	}
#endif
}

E 8
dkcksum(lp)
	register struct disklabel *lp;
{
	register u_short *start, *end;
	register u_short sum = 0;

	start = (u_short *)lp;
	end = (u_short *)&lp->d_partitions[lp->d_npartitions];
	while (start < end)
		sum ^= *start++;
	return (sum);
E 7
}
E 1
