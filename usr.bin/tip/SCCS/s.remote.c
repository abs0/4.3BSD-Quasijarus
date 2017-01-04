h38220
s 00002/00002/00165
d D 5.3 86/04/30 14:41:50 mckusick 10 9
c avoid dereference of null pointer (from kirk@oz)
e
s 00011/00000/00156
d D 5.2 85/12/09 21:36:40 karels 9 8
c behave sensibly if using cu -l and /etc/remote has nothing to say
c about it
e
s 00007/00001/00149
d D 5.1 85/04/30 12:34:34 dist 8 7
c Add copyright
e
s 00046/00024/00104
d D 4.7 83/06/25 01:14:24 sam 7 6
c so much...clean up after ralph's merge of wendel and mo code;
c purge VMUNIX include since changes for signals make it no longer portable 
c to systems other than 4.2; fix ventel for no echo strapping; do setjmps 
c instead of assuming interrupted system calls; purge lcmd, if people use 
e
s 00033/00002/00095
d D 4.6 83/06/15 13:52:49 ralph 6 5
c changes for local info, parity, vadic auto dialers
e
s 00009/00006/00088
d D 4.5 81/11/29 22:50:41 sam 5 4
c reformatting
e
s 00000/00000/00094
d D 4.4 81/11/20 10:44:52 sam 4 3
c cosmetics
e
s 00006/00000/00088
d D 4.3 81/07/13 09:43:08 sam 3 2
c guard against missing "hw" attributes
e
s 00001/00000/00087
d D 4.2 81/06/16 16:43:33 sam 2 1
c lots of patches to satisfy the DN-11's wants
e
s 00087/00000/00000
d D 4.1 81/05/09 16:45:21 root 1 0
c date and time created 81/05/09 16:45:21 by root
e
u
U
t
T
I 8
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 8
I 1
D 7
/*	%M%	%I%	%E%	*/
E 7
I 7
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 8
#endif
E 8
I 8
#endif not lint
E 8

E 7
# include "tip.h"

I 6
D 7
static char *sccsid = "%W% %G%";

E 7
E 6
/*
 * Attributes to be gleened from remote host description
 *   data base.
 */
static char **caps[] = {
D 6
	&AT, &DV, &CM, &CU, &EL, &IE, &OE, &PN
E 6
I 6
	&AT, &DV, &CM, &CU, &EL, &IE, &OE, &PN, &PR, &DI,
	&ES, &EX, &FO, &RC, &RE, &PA
E 6
};

static char *capstrings[] = {
D 6
	"at", "dv", "cm", "cu", "el", "ie", "oe", "pn", 0
E 6
I 6
	"at", "dv", "cm", "cu", "el", "ie", "oe", "pn", "pr",
	"di", "es", "ex", "fo", "rc", "re", "pa", 0
E 6
};

char *rgetstr();

static
getremcap(host)
	register char *host;
{
	int stat;
	char tbuf[BUFSIZ];
	static char buf[BUFSIZ/2];
	char *bp = buf;
	register char **p, ***q;

	if ((stat = rgetent(tbuf, host)) <= 0) {
I 9
		if (DV ||
		    host[0] == '/' && access(DV = host, R_OK | W_OK) == 0) {
			CU = DV;
			HO = host;
			HW = 1;
			DU = 0;
			if (!BR)
				BR = DEFBR;
			FS = DEFFS;
			return;
		}
E 9
		fprintf(stderr, stat == 0 ?
			"tip: unknown host %s\n" :
			"tip: can't open host description file\n", host);
		exit(3);
	}

	for (p = capstrings, q = caps; *p != NULL; p++, q++)
D 5
		**q = rgetstr(*p, &bp);
	if ((BR = rgetnum("br")) < 0)
E 5
I 5
		if (**q == NULL)
			**q = rgetstr(*p, &bp);
	if (!BR && (BR = rgetnum("br")) < 0)
E 5
		BR = DEFBR;
	if ((FS = rgetnum("fs")) < 0)
		FS = DEFFS;
D 5
	DU = rgetflag("du");
I 2
	HW = rgetflag("hw");
E 5
I 5
	if (DU < 0)
		DU = 0;
	else
		DU = rgetflag("du");
E 5
E 2
	if (DV == NOSTR) {
		fprintf(stderr, "%s: missing device spec\n", host);
		exit(3);
	}
	if (DU && CU == NOSTR)
		CU = DV;
	if (DU && PN == NOSTR) {
		fprintf(stderr, "%s: missing phone number\n", host);
		exit(3);
	}
I 6

	HD = rgetflag("hd");

E 6
I 3
	/*
	 * This effectively eliminates the "hw" attribute
	 *   from the description file
	 */
	if (!HW)
		HW = (CU == NOSTR) || (DU && equal(DV, CU));
E 3
	HO = host;
I 6
	/*
	 * see if uppercase mode should be turned on initially
	 */
D 7
	if (rgetflag("ra")) boolean(value(RAISE)) = 1;
	if (rgetflag("ec")) boolean(value(ECHOCHECK)) = 1;
	if (rgetflag("be")) boolean(value(BEAUTIFY)) = 1;
	if (rgetflag("nb")) boolean(value(BEAUTIFY)) = 0;
	if (rgetflag("sc")) boolean(value(SCRIPT)) = 1;
	if (rgetflag("tb")) boolean(value(TABEXPAND)) = 1;
	if (rgetflag("vb")) boolean(value(VERBOSE)) = 1;
	if (rgetflag("nv")) boolean(value(VERBOSE)) = 0;
	if (rgetflag("ta")) boolean(value(TAND)) = 1;
	if (rgetflag("nt")) boolean(value(TAND)) = 0;
	if (rgetflag("rw")) boolean(value(RAWFTP)) = 1;
	if (rgetflag("hd")) boolean(value(HALFDUPLEX)) = 1;
	if (*RE == NULL) RE = (char *)"tip.record";
	if (*EX == NULL) EX = (char *)"\t\n\b\f";
	if (ES != NOSTR) vstring("es",ES);
	if (FO != NOSTR) vstring("fo",FO);
	if (PR != NOSTR) vstring("pr",PR);
	if (RC != NOSTR) vstring("rc",RC);
	if ((DL = rgetnum("dl")) < 0) DL = 0;
	if ((CL = rgetnum("cl")) < 0) CL = 0;
	if ((ET = rgetnum("et")) < 0) ET = 10;
E 7
I 7
	if (rgetflag("ra"))
		boolean(value(RAISE)) = 1;
	if (rgetflag("ec"))
		boolean(value(ECHOCHECK)) = 1;
	if (rgetflag("be"))
		boolean(value(BEAUTIFY)) = 1;
	if (rgetflag("nb"))
		boolean(value(BEAUTIFY)) = 0;
	if (rgetflag("sc"))
		boolean(value(SCRIPT)) = 1;
	if (rgetflag("tb"))
		boolean(value(TABEXPAND)) = 1;
	if (rgetflag("vb"))
		boolean(value(VERBOSE)) = 1;
	if (rgetflag("nv"))
		boolean(value(VERBOSE)) = 0;
	if (rgetflag("ta"))
		boolean(value(TAND)) = 1;
	if (rgetflag("nt"))
		boolean(value(TAND)) = 0;
	if (rgetflag("rw"))
		boolean(value(RAWFTP)) = 1;
	if (rgetflag("hd"))
		boolean(value(HALFDUPLEX)) = 1;
D 10
	if (*RE == NULL)
E 10
I 10
	if (RE == NOSTR)
E 10
		RE = (char *)"tip.record";
D 10
	if (*EX == NULL)
E 10
I 10
	if (EX == NOSTR)
E 10
		EX = (char *)"\t\n\b\f";
	if (ES != NOSTR)
		vstring("es", ES);
	if (FO != NOSTR)
		vstring("fo", FO);
	if (PR != NOSTR)
		vstring("pr", PR);
	if (RC != NOSTR)
		vstring("rc", RC);
	if ((DL = rgetnum("dl")) < 0)
		DL = 0;
	if ((CL = rgetnum("cl")) < 0)
		CL = 0;
	if ((ET = rgetnum("et")) < 0)
		ET = 10;
E 7
E 6
}

char *
getremote(host)
	char *host;
{
	register char *cp;
	static char *next;
	static int lookedup = 0;

	if (!lookedup) {
		if (host == NOSTR && (host = getenv("HOST")) == NOSTR) {
			fprintf(stderr, "tip: no host specified\n");
			exit(3);
		}
		getremcap(host);
		next = DV;
		lookedup++;
	}
	/*
	 * We return a new device each time we're called (to allow
	 *   a rotary action to be simulated)
	 */
	if (next == NOSTR)
D 5
		return(NOSTR);
E 5
I 5
		return (NOSTR);
E 5
	if ((cp = index(next, ',')) == NULL) {
		DV = next;
		next = NOSTR;
	} else {
		*cp++ = '\0';
		DV = next;
		next = cp;
	}
D 5
	return(DV);
E 5
I 5
	return (DV);
E 5
}
E 1
