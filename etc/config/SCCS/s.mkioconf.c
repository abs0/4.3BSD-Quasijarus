h02927
s 00112/00001/00575
d D 5.13 04/03/20 02:16:03 msokolov 22 21
c add bva virtual bus support
e
s 00004/00012/00572
d D 5.12 04/03/06 21:34:51 msokolov 21 20
c introduce isadapter() function to tell if something is an adapter
c we have too many adapters now, need to centralise the list
e
s 00124/00012/00460
d D 5.11 04/03/02 17:49:30 msokolov 20 19
c redesign handling of VAXBI and peripheral nexus devices
e
s 00010/00005/00462
d D 5.10 88/06/18 13:43:09 bostic 19 18
c install approved copyright notice
e
s 00001/00001/00466
d D 5.9 88/05/21 16:40:52 karels 18 17
c pretend bi's connect to nexi; delete unnecessary keywords
e
s 00009/00003/00458
d D 5.8 88/04/29 13:43:31 bostic 17 16
c add Berkeley specific header; original conception by Michael Toy
e
s 00001/00001/00460
d D 5.7 88/04/26 13:34:40 bostic 16 15
c format/argument count mismatch
e
s 00004/00002/00457
d D 5.6 87/10/22 11:09:19 bostic 15 14
c ANSI C; sprintf now returns an int.
e
s 00001/00001/00458
d D 5.5 87/04/06 10:04:11 bostic 14 13
c fprintf format/argument mismatch
e
s 00007/00005/00452
d D 5.4 86/12/09 10:57:23 sam 13 12
c must output external declaration for devices w/o interrupts
e
s 00005/00005/00452
d D 5.3 86/12/07 12:05:15 sam 12 11
c some VERSAbus devices don't generate interrupts
e
s 00074/00047/00383
d D 5.2 86/10/13 15:35:35 sam 11 10
c replace ancient sun support with tahoe support
e
s 00007/00001/00423
d D 5.1 85/05/08 11:57:47 dist 10 9
c Add copyright
e
s 00003/00001/00421
d D 2.9 83/08/11 22:54:19 sam 9 8
c standardize sccs keyword lines
e
s 00004/00004/00418
d D 2.8 83/06/11 01:10:04 sam 8 7
c qu returns static
e
s 00008/00007/00414
d D 2.7 83/03/28 23:10:12 sam 7 6
c someone broke qu a ways back by removing the ns function on 
c the return value; this requires each invocation to be done in separate printfs
e
s 00002/00002/00419
d D 2.6 83/01/02 15:24:20 sam 6 5
c pte.h moved; sunmb->sundev
e
s 00035/00038/00386
d D 2.5 82/10/25 00:59:13 root 5 4
c lint and cleanup
e
s 00005/00002/00419
d D 2.4 82/10/24 22:25:26 root 4 3
c more #if stuff
e
s 00003/00007/00418
d D 2.3 82/10/24 22:21:59 root 3 2
c trivial cleanups
e
s 00391/00226/00034
d D 2.2 82/10/24 22:19:49 root 2 1
c from santa clara (but duplicated code!)
e
s 00260/00000/00000
d D 2.1 82/10/24 20:37:35 root 1 0
c date and time created 82/10/24 20:37:35 by root
e
u
U
t
T
I 10
/*
 * Copyright (c) 1980 Regents of the University of California.
D 17
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 17
I 17
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 19
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 19
I 19
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
E 19
E 17
 */

E 10
I 2
D 9
/*	%M%	%I%	%E%	*/
E 9
I 9
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 10
#endif
E 10
I 10
D 17
#endif not lint
E 17
I 17
#endif /* not lint */
E 17
E 10
E 9

E 2
I 1
#include <stdio.h>
#include "y.tab.h"
#include "config.h"

/*
D 2
 * %M%	%I%	%E%
 * ioconf:
 *	Build the ioconf.c file
E 2
I 2
 * build the ioconf.c file
E 2
 */
D 2
char *qu();
E 2
I 2
char	*qu();
I 4
char	*intv();
E 4
E 2

I 4
#if MACHINE_VAX
E 4
D 2
ioconf()
E 2
I 2
vax_ioconf()
E 2
{
D 2
    register struct device *dp, *mp, *np;
    register int uba_n, slave;
    char *intv();
    FILE *fp;
E 2
I 2
	register struct device *dp, *mp, *np;
	register int uba_n, slave;
D 4
	char *intv();
E 4
	FILE *fp;
E 2

D 2
    fp = fopen(path("ioconf.c"), "w");
    if (fp == NULL) {
	perror(path("ioconf.c"));
	exit(1);
    }
    fprintf(fp, "#include \"../h/param.h\"\n");
    fprintf(fp, "#include \"../h/pte.h\"\n");
    fprintf(fp, "#include \"../h/buf.h\"\n");
    fprintf(fp, "#include \"../h/map.h\"\n");
    fprintf(fp, "#include \"../h/mbavar.h\"\n");
    fprintf(fp, "#include \"../h/vm.h\"\n");
    fprintf(fp, "#include \"../h/ubavar.h\"\n\n");
    fprintf(fp, "#define C (caddr_t)\n\n");
    /*
     * First print the mba initialization structures
     */
    if (seen_mba)
    {
	for (dp = dtab; dp != NULL; dp = dp->d_next)
	{
	    mp = dp->d_conn;
	    if (mp == NULL || mp == TO_NEXUS || !eq(mp->d_name, "mba"))
		continue;
	    fprintf(fp, "extern struct mba_driver %sdriver;\n", dp->d_name);
E 2
I 2
	fp = fopen(path("ioconf.c"), "w");
D 5
	if (fp == NULL) {
E 5
I 5
	if (fp == 0) {
E 5
		perror(path("ioconf.c"));
		exit(1);
E 2
	}
I 6
	fprintf(fp, "#include \"../machine/pte.h\"\n");
E 6
D 2
	fprintf(fp, "\nstruct mba_device mbdinit[] = {\n");
	fprintf(fp, "\t/* Device,  Unit, Mba, Drive, Dk */\n");
	for (dp = dtab; dp != NULL; dp = dp->d_next)
	{
	    mp = dp->d_conn;
	    if (dp->d_unit == QUES || mp == NULL || mp == TO_NEXUS || !eq(mp->d_name, "mba"))
		continue;
	    if (dp->d_addr) {
		printf("can't specify csr address on mba for %s%d\n",
		    dp->d_name, dp->d_unit);
		continue;
	    }
	    if (dp->d_vec != NULL) {
		printf("can't specify vector for %s%d on mba\n",
			dp->d_name, dp->d_unit);
		continue;
	    }
	    if (dp->d_drive == UNKNOWN) {
		printf("drive not specified for %s%d\n",
		    dp->d_name, dp->d_unit);
		continue;
	    }
	    if (dp->d_slave != UNKNOWN) {
		printf("can't specify slave number for %s%d\n", 
		    dp->d_name, dp->d_unit);
		continue;
	    }
	    fprintf(fp, "\t{ &%sdriver, %d,   %s,  %s,    %d },\n",
		dp->d_name, dp->d_unit, qu(mp->d_unit),
		qu(dp->d_drive), dp->d_dk);
E 2
I 2
	fprintf(fp, "#include \"../h/param.h\"\n");
D 6
	fprintf(fp, "#include \"../h/pte.h\"\n");
E 6
	fprintf(fp, "#include \"../h/buf.h\"\n");
	fprintf(fp, "#include \"../h/map.h\"\n");
	fprintf(fp, "#include \"../h/vm.h\"\n");
	fprintf(fp, "\n");
	fprintf(fp, "#include \"../vaxmba/mbavar.h\"\n");
	fprintf(fp, "#include \"../vaxuba/ubavar.h\"\n\n");
	fprintf(fp, "\n");
	fprintf(fp, "#define C (caddr_t)\n\n");
	/*
	 * First print the mba initialization structures
	 */
	if (seen_mba) {
D 5
		for (dp = dtab; dp != NULL; dp = dp->d_next) {
E 5
I 5
		for (dp = dtab; dp != 0; dp = dp->d_next) {
E 5
			mp = dp->d_conn;
D 5
			if (mp == NULL || mp == TO_NEXUS ||
E 5
I 5
			if (mp == 0 || mp == TO_NEXUS ||
E 5
			    !eq(mp->d_name, "mba"))
				continue;
			fprintf(fp, "extern struct mba_driver %sdriver;\n",
			    dp->d_name);
		}
		fprintf(fp, "\nstruct mba_device mbdinit[] = {\n");
		fprintf(fp, "\t/* Device,  Unit, Mba, Drive, Dk */\n");
D 5
		for (dp = dtab; dp != NULL; dp = dp->d_next) {
E 5
I 5
		for (dp = dtab; dp != 0; dp = dp->d_next) {
E 5
			mp = dp->d_conn;
D 5
			if (dp->d_unit == QUES || mp == NULL ||
E 5
I 5
			if (dp->d_unit == QUES || mp == 0 ||
E 5
			    mp == TO_NEXUS || !eq(mp->d_name, "mba"))
				continue;
			if (dp->d_addr) {
				printf("can't specify csr address on mba for %s%d\n",
				    dp->d_name, dp->d_unit);
				continue;
			}
D 5
			if (dp->d_vec != NULL) {
E 5
I 5
			if (dp->d_vec != 0) {
E 5
				printf("can't specify vector for %s%d on mba\n",
				    dp->d_name, dp->d_unit);
				continue;
			}
			if (dp->d_drive == UNKNOWN) {
				printf("drive not specified for %s%d\n",
				    dp->d_name, dp->d_unit);
				continue;
			}
			if (dp->d_slave != UNKNOWN) {
				printf("can't specify slave number for %s%d\n", 
				    dp->d_name, dp->d_unit);
				continue;
			}
D 7
			fprintf(fp,
				"\t{ &%sdriver, %d,   %s,  %s,    %d },\n",
				dp->d_name, dp->d_unit, qu(mp->d_unit),
E 7
I 7
			fprintf(fp, "\t{ &%sdriver, %d,   %s,",
				dp->d_name, dp->d_unit, qu(mp->d_unit));
			fprintf(fp, "  %s,  %d },\n",
E 7
				qu(dp->d_drive), dp->d_dk);
		}
		fprintf(fp, "\t0\n};\n\n");
		/*
		 * Print the mbsinit structure
		 * Driver Controller Unit Slave
		 */
		fprintf(fp, "struct mba_slave mbsinit [] = {\n");
		fprintf(fp, "\t/* Driver,  Ctlr, Unit, Slave */\n");
D 5
		for (dp = dtab; dp != NULL; dp = dp->d_next) {
E 5
I 5
		for (dp = dtab; dp != 0; dp = dp->d_next) {
E 5
			/*
			 * All slaves are connected to something which
			 * is connected to the massbus.
			 */
D 5
			if ((mp = dp->d_conn) == NULL || mp == TO_NEXUS)
E 5
I 5
			if ((mp = dp->d_conn) == 0 || mp == TO_NEXUS)
E 5
				continue;
			np = mp->d_conn;
D 5
			if (np == NULL || np == TO_NEXUS ||
E 5
I 5
			if (np == 0 || np == TO_NEXUS ||
E 5
			    !eq(np->d_name, "mba"))
				continue;
D 8
			fprintf(fp,
			    "\t{ &%sdriver, %s,  %2d,    %s },\n",
			    mp->d_name, qu(mp->d_unit), dp->d_unit,
			    qu(dp->d_slave));
E 8
I 8
			fprintf(fp, "\t{ &%sdriver, %s",
			    mp->d_name, qu(mp->d_unit));
			fprintf(fp, ",  %2d,    %s },\n",
			    dp->d_unit, qu(dp->d_slave));
E 8
		}
		fprintf(fp, "\t0\n};\n\n");
E 2
	}
D 2
	fprintf(fp, "\t0\n};\n\n");
E 2
	/*
D 2
	 * Print the mbsinit structure
	 * Driver Controller Unit Slave
E 2
I 2
	 * Now generate interrupt vectors for the unibus
I 20
	 * Peripheral nexus interrupts are handled the same way
E 20
E 2
	 */
D 2
	fprintf(fp, "struct mba_slave mbsinit [] = {\n");
	fprintf(fp, "\t/* Driver,  Ctlr, Unit, Slave */\n");
	for (dp = dtab; dp != NULL; dp = dp->d_next)
	{
	    /*
	     * All slaves are connected to something which is connected to
	     * the massbus.
	     */
	    if ((mp = dp->d_conn) == NULL || mp == TO_NEXUS)
		continue;
	    np = mp->d_conn;
	    if (np == NULL || np == TO_NEXUS || !eq(np->d_name, "mba"))
		continue;
	    fprintf(fp, "\t{ &%sdriver, %s,  %2d,    %s },\n",
		mp->d_name, qu(mp->d_unit), dp->d_unit, qu(dp->d_slave));
E 2
I 2
D 5
	for (dp = dtab; dp != NULL; dp = dp->d_next) {
		if (dp->d_vec != NULL) {
E 5
I 5
	for (dp = dtab; dp != 0; dp = dp->d_next) {
		if (dp->d_vec != 0) {
E 5
			struct idlst *ip;
			mp = dp->d_conn;
D 5
			if (mp == NULL || mp == TO_NEXUS ||
E 5
I 5
D 20
			if (mp == 0 || mp == TO_NEXUS ||
E 5
D 18
			    !eq(mp->d_name, "uba"))
E 18
I 18
			    (!eq(mp->d_name, "uba") && !eq(mp->d_name, "bi")))
E 20
I 20
			if (mp == 0 || mp != TO_NEXUS &&
D 22
			    (!eq(mp->d_name, "uba")))
E 22
I 22
			    !eq(mp->d_name, "uba") && !eq(mp->d_name, "bva"))
E 22
E 20
E 18
				continue;
I 20
D 21
			if (mp == TO_NEXUS) {
				if (eq(dp->d_name, "uba") ||
				    eq(dp->d_name, "mba") ||
				    eq(dp->d_name, "vaxbi") ||
				    eq(dp->d_name, "xmi"))
					continue;
			}
E 21
I 21
			if (mp == TO_NEXUS && isadapter(dp->d_name))
				continue;
E 21
E 20
			fprintf(fp,
			    "extern struct uba_driver %sdriver;\n",
			    dp->d_name);
			fprintf(fp, "extern ");
			ip = dp->d_vec;
			for (;;) {
				fprintf(fp, "X%s%d()", ip->id, dp->d_unit);
				ip = ip->id_next;
				if (ip == 0)
					break;
				fprintf(fp, ", ");
			}
			fprintf(fp, ";\n");
			fprintf(fp, "int\t (*%sint%d[])() = { ", dp->d_name,
D 14
			    dp->d_unit, dp->d_unit);
E 14
I 14
			    dp->d_unit);
E 14
			ip = dp->d_vec;
			for (;;) {
				fprintf(fp, "X%s%d", ip->id, dp->d_unit);
				ip = ip->id_next;
				if (ip == 0)
					break;
				fprintf(fp, ", ");
			}
			fprintf(fp, ", 0 } ;\n");
		}
E 2
	}
D 2
	fprintf(fp, "\t0\n};\n\n");
    }
    /*
     * Now generate interrupt vectors for the unibus
     */
    for (dp = dtab; dp != NULL; dp = dp->d_next) {
	if (dp->d_vec != NULL) {
	    struct idlst *ip;
	    mp = dp->d_conn;
	    if (mp == NULL || mp == TO_NEXUS || !eq(mp->d_name, "uba"))
		continue;
	    fprintf(fp, "extern struct uba_driver %sdriver;\n", dp->d_name);
	    fprintf(fp, "extern ");
	    ip = dp->d_vec;
	    for (;;) {
		fprintf(fp, "X%s%d()", ip->id, dp->d_unit);
		ip = ip->id_next;
		if (ip == 0)
		    break;
		fprintf(fp, ", ");
	    }
	    fprintf(fp, ";\n");
	    fprintf(fp, "int\t (*%sint%d[])() = { ", dp->d_name,
		    dp->d_unit, dp->d_unit);
	    ip = dp->d_vec;
	    for (;;) {
		fprintf(fp, "X%s%d", ip->id, dp->d_unit);
		ip = ip->id_next;
		if (ip == 0)
		    break;
		fprintf(fp, ", ");
	    }
	    fprintf(fp, ", 0 } ;\n");
E 2
I 2
D 3
	/*
	 * Now spew forth the uba_minfo structure
	 */
E 3
	fprintf(fp, "\nstruct uba_ctlr ubminit[] = {\n");
	fprintf(fp, "/*\t driver,\tctlr,\tubanum,\talive,\tintr,\taddr */\n");
D 5
	for (dp = dtab; dp != NULL; dp = dp->d_next) {
E 5
I 5
	for (dp = dtab; dp != 0; dp = dp->d_next) {
E 5
		mp = dp->d_conn;
D 5
		if (dp->d_type != CONTROLLER || mp == TO_NEXUS || mp == NULL ||
E 5
I 5
		if (dp->d_type != CONTROLLER || mp == TO_NEXUS || mp == 0 ||
E 5
		    !eq(mp->d_name, "uba"))
			continue;
		if (dp->d_vec == 0) {
			printf("must specify vector for %s%d\n",
			    dp->d_name, dp->d_unit);
			continue;
		}
		if (dp->d_addr == 0) {
			printf("must specify csr address for %s%d\n",
			    dp->d_name, dp->d_unit);
			continue;
		}
		if (dp->d_drive != UNKNOWN || dp->d_slave != UNKNOWN) {
			printf("drives need their own entries; dont ");
			printf("specify drive or slave for %s%d\n",
			    dp->d_name, dp->d_unit);
			continue;
		}
		if (dp->d_flags) {
			printf("controllers (e.g. %s%d) ",
			    dp->d_name, dp->d_unit);
			printf("don't have flags, only devices do\n");
			continue;
		}
		fprintf(fp,
		    "\t{ &%sdriver,\t%d,\t%s,\t0,\t%sint%d, C 0%o },\n",
		    dp->d_name, dp->d_unit, qu(mp->d_unit),
		    dp->d_name, dp->d_unit, dp->d_addr);
E 2
	}
D 2
    }
    /*
     * Now spew forth the uba_minfo structure
     */
    fprintf(fp, "\nstruct uba_ctlr ubminit[] = {\n");
    fprintf(fp, "/*\t driver,\tctlr,\tubanum,\talive,\tintr,\taddr */\n");
    for (dp = dtab; dp != NULL; dp = dp->d_next) {
	mp = dp->d_conn;
	if (dp->d_type != CONTROLLER || mp == TO_NEXUS || mp == NULL || !eq(mp->d_name, "uba"))
	    continue;
	if (dp->d_vec == 0) {
	    printf("must specify vector for %s%d\n", dp->d_name, dp->d_unit);
	    continue;
E 2
I 2
	fprintf(fp, "\t0\n};\n");
D 3
	/*
	 * Now we go for the uba_device stuff
	 */
E 3
I 3
/* unibus devices */
E 3
	fprintf(fp, "\nstruct uba_device ubdinit[] = {\n");
D 3
	fprintf(fp, "\t/* driver,  unit, ctlr,  ubanum, slave,   intr,    addr,    dk, flags*/\n");
E 3
I 3
	fprintf(fp,
"\t/* driver,  unit, ctlr,  ubanum, slave,   intr,    addr,    dk, flags*/\n");
E 3
D 5
	for (dp = dtab; dp != NULL; dp = dp->d_next) {
E 5
I 5
	for (dp = dtab; dp != 0; dp = dp->d_next) {
E 5
		mp = dp->d_conn;
D 5
		if (dp->d_unit == QUES || dp->d_type != DEVICE || mp == NULL ||
E 5
I 5
		if (dp->d_unit == QUES || dp->d_type != DEVICE || mp == 0 ||
E 5
		    mp == TO_NEXUS || mp->d_type == MASTER ||
		    eq(mp->d_name, "mba"))
			continue;
		np = mp->d_conn;
D 5
		if (np != NULL && np != TO_NEXUS && eq(np->d_name, "mba"))
E 5
I 5
D 20
		if (np != 0 && np != TO_NEXUS && eq(np->d_name, "mba"))
E 20
I 20
		if (np == 0) {
			printf("%s%d isn't connected to anything ",
			    mp->d_name, mp->d_unit);
			printf(", so %s%d is unattached\n",
			    dp->d_name, dp->d_unit);
E 20
E 5
			continue;
D 5
		np = NULL;
E 5
I 5
D 20
		np = 0;
E 5
		if (eq(mp->d_name, "uba")) {
E 20
I 20
		}
		if (np == TO_NEXUS) {
			if (!eq(mp->d_name, "uba"))
				continue;
		} else {
			if (!eq(np->d_name, "uba"))
				continue;
		}
		if (np == TO_NEXUS) {
E 20
			if (dp->d_vec == 0) {
				printf("must specify vector for device %s%d\n",
				    dp->d_name, dp->d_unit);
				continue;
			}
			if (dp->d_addr == 0) {
				printf("must specify csr for device %s%d\n",
				    dp->d_name, dp->d_unit);
				continue;
			}
			if (dp->d_drive != UNKNOWN || dp->d_slave != UNKNOWN) {
				printf("drives/slaves can be specified ");
				printf("only for controllers, ");
				printf("not for device %s%d\n",
				    dp->d_name, dp->d_unit);
				continue;
			}
			uba_n = mp->d_unit;
			slave = QUES;
		} else {
D 5
			if ((np = mp->d_conn) == NULL) {
E 5
I 5
D 20
			if ((np = mp->d_conn) == 0) {
E 5
				printf("%s%d isn't connected to anything ",
				    mp->d_name, mp->d_unit);
				printf(", so %s%d is unattached\n",
				    dp->d_name, dp->d_unit);
				continue;
			}
E 20
			uba_n = np->d_unit;
			if (dp->d_drive == UNKNOWN) {
				printf("must specify ``drive number'' ");
				printf("for %s%d\n", dp->d_name, dp->d_unit);
				continue;
			}
			/* NOTE THAT ON THE UNIBUS ``drive'' IS STORED IN */
			/* ``SLAVE'' AND WE DON'T WANT A SLAVE SPECIFIED */
			if (dp->d_slave != UNKNOWN) {
				printf("slave numbers should be given only ");
				printf("for massbus tapes, not for %s%d\n",
				    dp->d_name, dp->d_unit);
				continue;
			}
			if (dp->d_vec != 0) {
				printf("interrupt vectors should not be ");
				printf("given for drive %s%d\n",
				    dp->d_name, dp->d_unit);
				continue;
			}
			if (dp->d_addr != 0) {
				printf("csr addresses should be given only ");
				printf("on controllers, not on %s%d\n",
				    dp->d_name, dp->d_unit);
				continue;
			}
			slave = dp->d_drive;
		}
D 7
		fprintf(fp,
"\t{ &%sdriver,  %2d,   %s,  %s,    %2d,   %s, C 0%-6o,  %d,  0x%x },\n",
E 7
I 7
		fprintf(fp, "\t{ &%sdriver,  %2d,   %s,",
E 7
		    eq(mp->d_name, "uba") ? dp->d_name : mp->d_name, dp->d_unit,
D 7
		    eq(mp->d_name, "uba") ? " -1" : qu(mp->d_unit), qu(uba_n),
		    slave, intv(dp), dp->d_addr, dp->d_dk, dp->d_flags);
E 7
I 7
		    eq(mp->d_name, "uba") ? " -1" : qu(mp->d_unit));
		fprintf(fp, "  %s,    %2d,   %s, C 0%-6o,  %d,  0x%x },\n",
		    qu(uba_n), slave, intv(dp), dp->d_addr, dp->d_dk,
I 20
		    dp->d_flags);
	}
	fprintf(fp, "\t0\n};\n");
	/*
	 * Now generate unibus-like tables for pnexus controllers and devices
	 */
	fprintf(fp, "\nstruct uba_ctlr pnexminit[] = {\n");
	fprintf(fp, "/*\t driver,\tctlr,\ttie,\talive,\tintr */\n");
	for (dp = dtab; dp != 0; dp = dp->d_next) {
		mp = dp->d_conn;
		if (dp->d_type != CONTROLLER || mp != TO_NEXUS ||
D 21
		    eq(dp->d_name, "uba") || eq(dp->d_name, "mba") ||
		    eq(dp->d_name, "vaxbi") || eq(dp->d_name, "xmi"))
E 21
I 21
		    isadapter(dp->d_name))
E 21
			continue;
		if (dp->d_vec == 0) {
			printf("must specify vector for %s%d\n",
			    dp->d_name, dp->d_unit);
			continue;
		}
		if (dp->d_drive != UNKNOWN || dp->d_slave != UNKNOWN) {
			printf("drives need their own entries; dont ");
			printf("specify drive or slave for %s%d\n",
			    dp->d_name, dp->d_unit);
			continue;
		}
		if (dp->d_flags) {
			printf("controllers (e.g. %s%d) ",
			    dp->d_name, dp->d_unit);
			printf("don't have flags, only devices do\n");
			continue;
		}
		fprintf(fp,
		    "\t{ &%sdriver,\t%d,\t%d,\t0,\t%sint%d },\n",
		    dp->d_name, dp->d_unit, dp->d_node,
		    dp->d_name, dp->d_unit, dp->d_addr);
	}
	fprintf(fp, "\t0\n};\n");
	/* devices */
	fprintf(fp, "\nstruct uba_device pnexdinit[] = {\n");
	fprintf(fp,
"\t/* driver,  unit, ctlr,  tie, slave,   intr,    addr,    dk, flags*/\n");
	for (dp = dtab; dp != 0; dp = dp->d_next) {
		mp = dp->d_conn;
		if (dp->d_unit == QUES || dp->d_type != DEVICE || mp == 0)
			continue;
		if (mp != TO_NEXUS) {
D 21
			if (mp->d_conn != TO_NEXUS || eq(mp->d_name, "uba") ||
			    eq(mp->d_name, "mba") || eq(mp->d_name, "vaxbi") ||
			    eq(mp->d_name, "xmi"))
E 21
I 21
			if (mp->d_conn != TO_NEXUS || isadapter(mp->d_name))
E 21
				continue;
		}
		if (mp == TO_NEXUS) {
			if (dp->d_vec == 0) {
				printf("must specify vector for device %s%d\n",
				    dp->d_name, dp->d_unit);
				continue;
			}
			if (dp->d_drive != UNKNOWN || dp->d_slave != UNKNOWN) {
				printf("drives/slaves can be specified ");
				printf("only for controllers, ");
				printf("not for device %s%d\n",
				    dp->d_name, dp->d_unit);
				continue;
			}
			uba_n = dp->d_node;
			slave = QUES;
		} else {
			uba_n = mp->d_node;
			if (dp->d_drive == UNKNOWN) {
				printf("must specify ``drive number'' ");
				printf("for %s%d\n", dp->d_name, dp->d_unit);
				continue;
			}
			/* NOTE THAT ON THE UNIBUS ``drive'' IS STORED IN */
			/* ``SLAVE'' AND WE DON'T WANT A SLAVE SPECIFIED */
			if (dp->d_slave != UNKNOWN) {
				printf("slave numbers should be given only ");
				printf("for massbus tapes, not for %s%d\n",
				    dp->d_name, dp->d_unit);
				continue;
			}
			if (dp->d_vec != 0) {
				printf("interrupt vectors should not be ");
				printf("given for drive %s%d\n",
				    dp->d_name, dp->d_unit);
				continue;
			}
			if (dp->d_addr != 0) {
				printf("csr addresses should be given only ");
				printf("on controllers, not on %s%d\n",
				    dp->d_name, dp->d_unit);
				continue;
			}
			slave = dp->d_drive;
		}
		fprintf(fp, "\t{ &%sdriver,  %2d,   %s,",
		    mp == TO_NEXUS ? dp->d_name : mp->d_name, dp->d_unit,
		    mp == TO_NEXUS ? " -1" : qu(mp->d_unit));
		fprintf(fp, "  %d,    %2d,   %s, C 0x%x,  %d,  0x%x },\n",
		    uba_n, slave, intv(dp), dp->d_addr, dp->d_dk,
E 20
		    dp->d_flags);
E 7
E 2
	}
D 2
	if (dp->d_addr == 0) {
	    printf("must specify csr address for %s%d\n",
		dp->d_name, dp->d_unit);
	    continue;
E 2
I 2
	fprintf(fp, "\t0\n};\n");
I 22
	/* BabyVAX controller and device tables */
	if (seen_bva) {
		fprintf(fp, "\nstruct uba_ctlr bvaxminit[] = {\n");
		fprintf(fp, "/*\t driver,\tctlr,\tubanum,\talive,\tintr,\taddr */\n");
		for (dp = dtab; dp != 0; dp = dp->d_next) {
			mp = dp->d_conn;
			if (dp->d_type != CONTROLLER || mp == TO_NEXUS ||
			    mp == 0 || !eq(mp->d_name, "bva"))
				continue;
			if (dp->d_vec == 0) {
				printf("must specify vector for %s%d\n",
				    dp->d_name, dp->d_unit);
				continue;
			}
			if (dp->d_drive != UNKNOWN || dp->d_slave != UNKNOWN) {
				printf("drives need their own entries; dont ");
				printf("specify drive or slave for %s%d\n",
				    dp->d_name, dp->d_unit);
				continue;
			}
			if (dp->d_flags) {
				printf("controllers (e.g. %s%d) ",
				    dp->d_name, dp->d_unit);
				printf("don't have flags, only devices do\n");
				continue;
			}
			fprintf(fp,
			    "\t{ &%sdriver,\t%d,\t%s,\t0,\t%sint%d, C 0%o },\n",
			    dp->d_name, dp->d_unit, qu(mp->d_unit),
			    dp->d_name, dp->d_unit, dp->d_addr);
		}
		fprintf(fp, "\t0\n};\n");
		/* non-mass storage devices */
		fprintf(fp, "\nstruct uba_device bvaxdinit[] = {\n");
		fprintf(fp,
"\t/* driver,  unit, ctlr,  ubanum, slave,   intr,    addr,    dk, flags*/\n");
		for (dp = dtab; dp != 0; dp = dp->d_next) {
			mp = dp->d_conn;
			if (dp->d_unit == QUES || dp->d_type != DEVICE ||
			    mp == 0 || mp == TO_NEXUS || mp->d_type == MASTER ||
			    eq(mp->d_name, "mba"))
				continue;
			np = mp->d_conn;
			if (np == 0) {
				printf("%s%d isn't connected to anything ",
				    mp->d_name, mp->d_unit);
				printf(", so %s%d is unattached\n",
				    dp->d_name, dp->d_unit);
				continue;
			}
			if (np == TO_NEXUS) {
				if (!eq(mp->d_name, "bva"))
					continue;
			} else {
				if (!eq(np->d_name, "bva"))
					continue;
			}
			if (np == TO_NEXUS) {
				if (dp->d_vec == 0) {
				printf("must specify vector for device %s%d\n",
					    dp->d_name, dp->d_unit);
					continue;
				}
				if (dp->d_drive != UNKNOWN ||
				    dp->d_slave != UNKNOWN) {
				    printf("drives/slaves can be specified ");
					printf("only for controllers, ");
					printf("not for device %s%d\n",
					    dp->d_name, dp->d_unit);
					continue;
				}
				uba_n = mp->d_unit;
				slave = QUES;
			} else {
			    uba_n = np->d_unit;
			    if (dp->d_drive == UNKNOWN) {
				printf("must specify ``drive number'' ");
				printf("for %s%d\n", dp->d_name, dp->d_unit);
				continue;
			    }
			    /* NOTE THAT ON THE UNIBUS ``drive'' IS STORED IN */
			    /* ``SLAVE'' AND WE DON'T WANT A SLAVE SPECIFIED */
			    if (dp->d_slave != UNKNOWN) {
				printf("slave numbers should be given only ");
				printf("for massbus tapes, not for %s%d\n",
					dp->d_name, dp->d_unit);
					continue;
			    }
			    if (dp->d_vec != 0) {
				printf("interrupt vectors should not be ");
				printf("given for drive %s%d\n",
					dp->d_name, dp->d_unit);
				continue;
			    }
			    if (dp->d_addr != 0) {
				printf("csr addresses should be given only ");
				printf("on controllers, not on %s%d\n",
					dp->d_name, dp->d_unit);
				continue;
			    }
			    slave = dp->d_drive;
			}
			fprintf(fp, "\t{ &%sdriver,  %2d,   %s,",
			    eq(mp->d_name, "bva") ? dp->d_name : mp->d_name, dp->d_unit,
			    eq(mp->d_name, "bva") ? " -1" : qu(mp->d_unit));
			fprintf(fp, "  %s,    %2d,   %s, C 0%-6o,  %d,  0x%x },\n",
			    qu(uba_n), slave, intv(dp), dp->d_addr, dp->d_dk,
			    dp->d_flags);
		}
		fprintf(fp, "\t0\n};\n");
	}
E 22
D 5
	fclose(fp);
E 5
I 5
	(void) fclose(fp);
E 5
}
I 4
#endif
E 4

I 4
D 11
#if MACHINE_SUN
E 4
sun_ioconf()
E 11
I 11
#if MACHINE_TAHOE
tahoe_ioconf()
E 11
{
D 5
	register struct device *dp, *mp, *np;
	register int uba_n, slave;
E 5
I 5
D 11
	register struct device *dp, *mp;
	register int slave;
E 11
I 11
	register struct device *dp, *mp, *np;
	register int vba_n, slave;
E 11
E 5
D 4
	char *intv();
E 4
	FILE *fp;

	fp = fopen(path("ioconf.c"), "w");
D 5
	if (fp == NULL) {
E 5
I 5
	if (fp == 0) {
E 5
		perror(path("ioconf.c"));
		exit(1);
E 2
	}
D 2
	if (dp->d_drive != UNKNOWN || dp->d_slave != UNKNOWN) {
	    printf("drives need their own entries; dont specify drive or slave for %s%d\n",
		dp->d_name, dp->d_unit);
	    continue;
E 2
I 2
	fprintf(fp, "#include \"../h/param.h\"\n");
I 11
	fprintf(fp, "#include \"../machine/pte.h\"\n");
E 11
	fprintf(fp, "#include \"../h/buf.h\"\n");
	fprintf(fp, "#include \"../h/map.h\"\n");
D 11
	fprintf(fp, "#include \"../h/vm.h\"\n");
E 11
	fprintf(fp, "\n");
D 6
	fprintf(fp, "#include \"../sunmb/mbvar.h\"\n");
E 6
I 6
D 11
	fprintf(fp, "#include \"../sundev/mbvar.h\"\n");
E 11
I 11
	fprintf(fp, "#include \"../tahoevba/vbavar.h\"\n");
E 11
E 6
	fprintf(fp, "\n");
	fprintf(fp, "#define C (caddr_t)\n\n");
D 11
	fprintf(fp, "\n");
E 11
	/*
D 11
	 * Now generate interrupt vectors for the Multibus
E 11
I 11
	 * Now generate interrupt vectors for the versabus
E 11
	 */
D 5
	for (dp = dtab; dp != NULL; dp = dp->d_next) {
		if (dp->d_pri != NULL) {
E 5
I 5
	for (dp = dtab; dp != 0; dp = dp->d_next) {
I 13
		mp = dp->d_conn;
		if (mp == 0 || mp == TO_NEXUS || !eq(mp->d_name, "vba"))
			continue;
E 13
D 11
		if (dp->d_pri != 0) {
E 11
I 11
		if (dp->d_vec != 0) {
			struct idlst *ip;
E 11
E 5
D 13
			mp = dp->d_conn;
D 5
			if (mp == NULL || mp == TO_NEXUS ||
E 5
I 5
			if (mp == 0 || mp == TO_NEXUS ||
E 5
D 11
			    !eq(mp->d_name, "mb"))
E 11
I 11
			    !eq(mp->d_name, "vba"))
E 11
				continue;
E 13
D 11
			fprintf(fp, "extern struct mb_driver %sdriver;\n",
E 11
I 11
			fprintf(fp,
			    "extern struct vba_driver %sdriver;\n",
E 11
			    dp->d_name);
I 11
			fprintf(fp, "extern ");
			ip = dp->d_vec;
			for (;;) {
				fprintf(fp, "X%s%d()", ip->id, dp->d_unit);
				ip = ip->id_next;
				if (ip == 0)
					break;
				fprintf(fp, ", ");
			}
			fprintf(fp, ";\n");
			fprintf(fp, "int\t (*%sint%d[])() = { ", dp->d_name,
D 16
			    dp->d_unit, dp->d_unit);
E 16
I 16
			    dp->d_unit);
E 16
			ip = dp->d_vec;
			for (;;) {
				fprintf(fp, "X%s%d", ip->id, dp->d_unit);
				ip = ip->id_next;
				if (ip == 0)
					break;
				fprintf(fp, ", ");
			}
			fprintf(fp, ", 0 } ;\n");
E 11
D 13
		}
E 13
I 13
		} else if (dp->d_type == DRIVER)  /* devices w/o interrupts */
			fprintf(fp,
			    "extern struct vba_driver %sdriver;\n",
			    dp->d_name);
E 13
E 2
	}
D 2
	if (dp->d_flags) {
	    printf("controllers (e.g. %s%d) don't have flags, only devices do\n",
		dp->d_name, dp->d_unit);
	    continue;
E 2
I 2
D 11
	/*
	 * Now spew forth the mb_cinfo structure
	 */
	fprintf(fp, "\nstruct mb_ctlr mbcinit[] = {\n");
	fprintf(fp, "/*\t driver,\tctlr,\talive,\taddr,\tintpri */\n");
E 11
I 11
	fprintf(fp, "\nstruct vba_ctlr vbminit[] = {\n");
	fprintf(fp, "/*\t driver,\tctlr,\tvbanum,\talive,\tintr,\taddr */\n");
E 11
D 5
	for (dp = dtab; dp != NULL; dp = dp->d_next) {
E 5
I 5
	for (dp = dtab; dp != 0; dp = dp->d_next) {
E 5
		mp = dp->d_conn;
D 5
		if (dp->d_type != CONTROLLER || mp == TO_NEXUS || mp == NULL ||
E 5
I 5
		if (dp->d_type != CONTROLLER || mp == TO_NEXUS || mp == 0 ||
E 5
D 11
		    !eq(mp->d_name, "mb"))
E 11
I 11
		    !eq(mp->d_name, "vba"))
E 11
			continue;
D 11
		if (dp->d_pri == 0) {
			printf("must specify priority for %s%d\n",
E 11
I 11
		if (dp->d_vec == 0) {
			printf("must specify vector for %s%d\n",
E 11
			    dp->d_name, dp->d_unit);
			continue;
		}
		if (dp->d_addr == 0) {
			printf("must specify csr address for %s%d\n",
			    dp->d_name, dp->d_unit);
			continue;
		}
		if (dp->d_drive != UNKNOWN || dp->d_slave != UNKNOWN) {
D 11
			printf("drives need their own entries; ");
			printf("dont specify drive or slave for %s%d\n",
E 11
I 11
			printf("drives need their own entries; dont ");
			printf("specify drive or slave for %s%d\n",
E 11
			    dp->d_name, dp->d_unit);
			continue;
		}
		if (dp->d_flags) {
D 11
			printf("controllers (e.g. %s%d) don't have flags, ");
			printf("only devices do\n",
E 11
I 11
			printf("controllers (e.g. %s%d) ",
E 11
			    dp->d_name, dp->d_unit);
I 11
			printf("don't have flags, only devices do\n");
E 11
			continue;
		}
D 11
		fprintf(fp, "\t{ &%sdriver,\t%d,\t0,\tC 0x%x,\t%d },\n",
		    dp->d_name, dp->d_unit, dp->d_addr, dp->d_pri);
E 11
I 11
		fprintf(fp,
		    "\t{ &%sdriver,\t%d,\t%s,\t0,\t%sint%d, C 0x%x },\n",
		    dp->d_name, dp->d_unit, qu(mp->d_unit),
		    dp->d_name, dp->d_unit, dp->d_addr);
E 11
E 2
	}
D 2
	fprintf(fp, "\t{ &%sdriver,\t%d,\t%s,\t0,\t%sint%d, C 0%o },\n",
	    dp->d_name, dp->d_unit, qu(mp->d_unit),
	    dp->d_name, dp->d_unit, dp->d_addr);
    }
    fprintf(fp, "\t0\n};\n");
    /*
     * Now we go for the uba_device stuff
     */
    fprintf(fp, "\nstruct uba_device ubdinit[] = {\n");
    fprintf(fp, "\t/* driver,  unit, ctlr,  ubanum, slave,   intr,    addr,    dk, flags*/\n");
    for (dp = dtab; dp != NULL; dp = dp->d_next) {
	mp = dp->d_conn;
	if (dp->d_unit == QUES || dp->d_type != DEVICE || mp == NULL ||
		mp == TO_NEXUS || mp->d_type == MASTER || eq(mp->d_name, "mba"))
	    continue;
        np = mp->d_conn;
        if (np != NULL && np != TO_NEXUS && eq(np->d_name, "mba"))
	    continue;
	np = NULL;
	if (eq(mp->d_name, "uba")) {
	    if (dp->d_vec == 0) {
		printf("must specify vector for device %s%d\n",
		    dp->d_name, dp->d_unit);
		continue;
	    }
	    if (dp->d_addr == 0) {
		printf("must specify csr address for device %s%d\n",
		    dp->d_name, dp->d_unit);
		continue;
	    }
	    if (dp->d_drive != UNKNOWN || dp->d_slave != UNKNOWN) {
		printf("drives/slaves can be specified only for controllers, not for device %s%d\n",
		    dp->d_name, dp->d_unit);
		continue;
	    }
	    uba_n = mp->d_unit;
	    slave = QUES;
	} else {
	    if ((np = mp->d_conn) == NULL) {
		printf("%s%d isn't connected to anything, so %s%d is unattached\n",
		    mp->d_name, mp->d_unit, dp->d_name, dp->d_unit);
		continue;
	    }
	    uba_n = np->d_unit;
	    if (dp->d_drive == UNKNOWN) {
		printf("must specify ``drive number'' for %s%d\n",
		   dp->d_name, dp->d_unit);
		continue;
	    }
	    /* NOTE THAT ON THE UNIBUS ``drive'' IS STORED IN */
	    /* ``SLAVE'' AND WE DON'T WANT A SLAVE SPECIFIED */
	    if (dp->d_slave != UNKNOWN) {
		printf("slave numbers should be given only for massbus tapes, not for %s%d\n",
		    dp->d_name, dp->d_unit);
		continue;
	    }
	    if (dp->d_vec != 0) {
		printf("interrupt vectors should not be given for drive %s%d\n",
		    dp->d_name, dp->d_unit);
		continue;
	    }
	    if (dp->d_addr != 0) {
		printf("csr addresses should be given only on controllers, not on %s%d\n",
		    dp->d_name, dp->d_unit);
		continue;
	    }
	    slave = dp->d_drive;
E 2
I 2
	fprintf(fp, "\t0\n};\n");
D 11
	/*
	 * Now we go for the mb_device stuff
	 */
	fprintf(fp, "\nstruct mb_device mbdinit[] = {\n");
E 11
I 11
/* versabus devices */
	fprintf(fp, "\nstruct vba_device vbdinit[] = {\n");
E 11
	fprintf(fp,
D 11
"\t/* driver,  unit, ctlr,  slave,   addr,    pri,    dk, flags*/\n");
E 11
I 11
"\t/* driver,  unit, ctlr,  vbanum, slave,   intr,    addr,    dk, flags*/\n");
E 11
D 5
	for (dp = dtab; dp != NULL; dp = dp->d_next) {
E 5
I 5
	for (dp = dtab; dp != 0; dp = dp->d_next) {
E 5
		mp = dp->d_conn;
D 5
		if (dp->d_unit == QUES || dp->d_type != DEVICE || mp == NULL ||
E 5
I 5
		if (dp->d_unit == QUES || dp->d_type != DEVICE || mp == 0 ||
E 5
		    mp == TO_NEXUS || mp->d_type == MASTER ||
		    eq(mp->d_name, "mba"))
			continue;
D 5
		np = NULL;
E 5
D 11
		if (eq(mp->d_name, "mb")) {
			if (dp->d_pri == 0) {
E 11
I 11
		np = mp->d_conn;
		if (np != 0 && np != TO_NEXUS && eq(np->d_name, "mba"))
			continue;
		np = 0;
		if (eq(mp->d_name, "vba")) {
D 12
			if (dp->d_vec == 0) {
E 11
				printf("must specify vector for device %s%d\n",
E 12
I 12
			if (dp->d_vec == 0)
				printf(
		"Warning, no interrupt vector specified for device %s%d\n",
E 12
				    dp->d_name, dp->d_unit);
D 12
				continue;
			}
E 12
			if (dp->d_addr == 0) {
				printf("must specify csr for device %s%d\n",
				    dp->d_name, dp->d_unit);
				continue;
			}
			if (dp->d_drive != UNKNOWN || dp->d_slave != UNKNOWN) {
D 11
				printf("drives/slaves can be specified only ");
				printf("for controllers, not for device %s%d\n",
E 11
I 11
				printf("drives/slaves can be specified ");
				printf("only for controllers, ");
				printf("not for device %s%d\n",
E 11
				    dp->d_name, dp->d_unit);
				continue;
			}
I 11
			vba_n = mp->d_unit;
E 11
			slave = QUES;
		} else {
D 5
			if ((np = mp->d_conn) == NULL) {
E 5
I 5
D 11
			if (mp->d_conn == 0) {
E 5
				printf("%s%d isn't connected to anything, ",
E 11
I 11
			if ((np = mp->d_conn) == 0) {
				printf("%s%d isn't connected to anything ",
E 11
				    mp->d_name, mp->d_unit);
D 11
				printf("so %s%d is unattached\n",
E 11
I 11
				printf(", so %s%d is unattached\n",
E 11
				    dp->d_name, dp->d_unit);
				continue;
			}
I 11
			vba_n = np->d_unit;
E 11
			if (dp->d_drive == UNKNOWN) {
D 11
				printf("must specify ``drive number'' for %s%d\n",
				   dp->d_name, dp->d_unit);
E 11
I 11
				printf("must specify ``drive number'' ");
				printf("for %s%d\n", dp->d_name, dp->d_unit);
E 11
				continue;
			}
			/* NOTE THAT ON THE UNIBUS ``drive'' IS STORED IN */
			/* ``SLAVE'' AND WE DON'T WANT A SLAVE SPECIFIED */
			if (dp->d_slave != UNKNOWN) {
				printf("slave numbers should be given only ");
				printf("for massbus tapes, not for %s%d\n",
				    dp->d_name, dp->d_unit);
				continue;
			}
D 11
			if (dp->d_pri != 0) {
				printf("interrupt priority should not be ");
E 11
I 11
			if (dp->d_vec != 0) {
				printf("interrupt vectors should not be ");
E 11
				printf("given for drive %s%d\n",
				    dp->d_name, dp->d_unit);
				continue;
			}
			if (dp->d_addr != 0) {
D 11
				printf("csr addresses should be given only");
E 11
I 11
				printf("csr addresses should be given only ");
E 11
				printf("on controllers, not on %s%d\n",
				    dp->d_name, dp->d_unit);
				continue;
			}
			slave = dp->d_drive;
		}
D 11
		fprintf(fp,
"\t{ &%sdriver,  %2d,   %s,    %2d,   C 0x%x, %d,  %d,  0x%x },\n",
		    eq(mp->d_name, "mb") ? dp->d_name : mp->d_name, dp->d_unit,
		    eq(mp->d_name, "mb") ? " -1" : qu(mp->d_unit),
		    slave, dp->d_addr, dp->d_pri, dp->d_dk, dp->d_flags);
E 11
I 11
		fprintf(fp, "\t{ &%sdriver,  %2d,   %s,",
		    eq(mp->d_name, "vba") ? dp->d_name : mp->d_name, dp->d_unit,
		    eq(mp->d_name, "vba") ? " -1" : qu(mp->d_unit));
		fprintf(fp, "  %s,    %2d,   %s, C 0x%-6x,  %d,  0x%x },\n",
		    qu(vba_n), slave, intv(dp), dp->d_addr, dp->d_dk,
		    dp->d_flags);
E 11
E 2
	}
D 2
	fprintf(fp, "\t{ &%sdriver,  %2d,   %s,  %s,    %2d,   %s, C 0%-6o,  %d,  0x%x },\n",
	    eq(mp->d_name, "uba") ? dp->d_name : mp->d_name, dp->d_unit,
	    eq(mp->d_name, "uba") ? " -1" : qu(mp->d_unit), qu(uba_n),
	    slave, intv(dp), dp->d_addr, dp->d_dk, dp->d_flags);
    }
    fprintf(fp, "\t0\n};\n");
    fclose(fp);
E 2
I 2
	fprintf(fp, "\t0\n};\n");
D 5
	fclose(fp);
E 5
I 5
	(void) fclose(fp);
E 5
E 2
}
I 4
#endif
E 4

D 2
/*
 * intv
 *	Return vector name
 */

E 2
D 12
char *intv(dev)
E 12
I 12
char *
intv(dev)
E 12
D 2
register struct device *dev;
E 2
I 2
	register struct device *dev;
E 2
{
	static char buf[20];

D 2
	if (dev->d_vec == NULL)
	    return "     0";
E 2
I 2
	if (dev->d_vec == 0)
		return ("     0");
E 2
D 5
	else
D 2
	    return sprintf(buf, "%sint%d", dev->d_name, dev->d_unit);
E 2
I 2
		return (sprintf(buf, "%sint%d", dev->d_name, dev->d_unit));
E 5
I 5
D 15
	return (sprintf(buf, "%sint%d", dev->d_name, dev->d_unit));
E 15
I 15
	(void) sprintf(buf, "%sint%d", dev->d_name, dev->d_unit);
	return (buf);
E 15
E 5
E 2
}

char *
qu(num)
{
I 2

E 2
	if (num == QUES)
D 2
		return "'?'";
	if(num == UNKNOWN)
		return " -1";
	return ns(sprintf(errbuf, "%3d", num));
E 2
I 2
		return ("'?'");
D 5
	else if (num == UNKNOWN)
E 5
I 5
	if (num == UNKNOWN)
E 5
		return (" -1");
D 5
	else
		return (ns(sprintf(errbuf, "%3d", num)));
E 5
I 5
D 15
	return (sprintf(errbuf, "%3d", num));
E 15
I 15
	(void) sprintf(errbuf, "%3d", num);
	return (errbuf);
E 15
E 5
E 2
}
E 1
