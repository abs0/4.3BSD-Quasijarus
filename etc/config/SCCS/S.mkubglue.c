h09928
s 00007/00001/00158
d D 5.1 85/05/08 11:58:40 dist 14 13
c Add copyright
e
s 00001/00002/00158
d D 1.13 84/10/26 08:55:29 karels 13 12
c always count interrupts in per-device code (not twice on 780's
c with VAX750 defined)
e
s 00090/00000/00070
d D 1.12 84/08/22 11:34:52 karels 12 11
c add interrupt counters per device, and names for each counter
e
s 00003/00001/00067
d D 1.11 83/08/11 22:54:47 sam 11 10
c standardize sccs keyword lines
e
s 00003/00002/00065
d D 1.10 83/07/09 22:21:15 sam 10 9
c add stats on 750/730 unibus interrupts
e
s 00001/00001/00066
d D 1.9 83/06/16 23:03:53 sam 9 8
c oops, must pushl after calling uudma
e
s 00006/00001/00061
d D 1.8 83/06/16 15:17:28 sam 8 7
c uu pseudo dma kludge
e
s 00040/00041/00022
d D 1.7 82/10/25 00:59:41 root 7 6
c lint and cleanup
e
s 00002/00001/00061
d D 1.6 82/10/24 20:47:41 root 6 5
c move sccs line
e
s 00001/00001/00061
d D 1.5 82/06/16 22:07:39 mckusick 5 4
c change "jbr" to "jmp" to keep assembler happy
e
s 00011/00004/00051
d D 1.4 81/05/22 16:40:00 root 4 3
c allow arb number of VECTOR list entries
e
s 00004/00000/00051
d D 1.3 81/02/26 12:48:15 wnj 3 2
c stamp for sending to dec... still bugs in mkioconf.c
e
s 00002/00001/00049
d D 1.2 81/02/26 01:42:45 wnj 2 1
c 
e
s 00050/00000/00000
d D 1.1 81/02/24 15:51:20 toy 1 0
c date and time created 81/02/24 15:51:20 by toy
e
u
U
t
T
I 14
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 14
I 6
D 11
/*	%M%	%I%	%E%	*/
E 11
I 11
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 14
#endif
E 14
I 14
#endif not lint
E 14
E 11

E 6
I 1
/*
 * Make the uba interrupt file ubglue.s
I 2
D 6
 *	%M%	%I%	%E%
E 6
E 2
 */
#include <stdio.h>
#include "config.h"
#include "y.tab.h"

ubglue()
{
D 7
    register FILE *fp;
    register struct device *dp, *mp;
E 7
I 7
	register FILE *fp;
	register struct device *dp, *mp;
E 7

D 2
    fp = fopen(path(ubglue.c), "w");
E 2
I 2
D 7
    fp = fopen(path("ubglue.s"), "w");
I 3
    if (fp == NULL) {
	perror(path("ubglue.s"));
	exit(1);
    }
E 3
E 2
    for (dp = dtab ; dp != NULL; dp = dp->d_next)
    {
	mp = dp->d_conn;
	if (mp != NULL && mp != -1 && !eq(mp->d_name, "mba"))
	{
D 4
	    if (dp->d_vec1 != NULL)
		dump_vec(fp, dp->d_vec1, dp->d_unit);
	    if (dp->d_vec2 != NULL)
		dump_vec(fp, dp->d_vec2, dp->d_unit);
E 4
I 4
	    struct idlst *id, *id2;
	    for (id = dp->d_vec; id; id = id->id_next) {
		for (id2 = dp->d_vec; id2; id2 = id2->id_next) {
		    if (id2 == id) {
			dump_vec(fp, id->id, dp->d_unit);
			break;
		    }
		    if (!strcmp(id->id, id2->id))
			break;
E 7
I 7
	fp = fopen(path("ubglue.s"), "w");
	if (fp == 0) {
		perror(path("ubglue.s"));
		exit(1);
	}
	for (dp = dtab; dp != 0; dp = dp->d_next) {
		mp = dp->d_conn;
		if (mp != 0 && mp != (struct device *)-1 &&
		    !eq(mp->d_name, "mba")) {
			struct idlst *id, *id2;

			for (id = dp->d_vec; id; id = id->id_next) {
				for (id2 = dp->d_vec; id2; id2 = id2->id_next) {
					if (id2 == id) {
						dump_vec(fp, id->id, dp->d_unit);
						break;
					}
					if (!strcmp(id->id, id2->id))
						break;
				}
			}
E 7
		}
D 7
	    }
E 7
E 4
	}
I 12
	dump_std(fp);
	for (dp = dtab; dp != 0; dp = dp->d_next) {
		mp = dp->d_conn;
		if (mp != 0 && mp != (struct device *)-1 &&
		    !eq(mp->d_name, "mba")) {
			struct idlst *id, *id2;

			for (id = dp->d_vec; id; id = id->id_next) {
				for (id2 = dp->d_vec; id2; id2 = id2->id_next) {
					if (id2 == id) {
						dump_intname(fp, id->id,
							dp->d_unit);
						break;
					}
					if (!strcmp(id->id, id2->id))
						break;
				}
			}
		}
	}
	dump_ctrs(fp);
E 12
D 7
    }
    fclose(fp);
E 7
I 7
	(void) fclose(fp);
E 7
}

I 12
static int cntcnt = 0;		/* number of interrupt counters allocated */

E 12
/*
D 7
 * dump_vec
 *	Print an interrupt vector
E 7
I 7
 * print an interrupt vector
E 7
 */
D 7

E 7
dump_vec(fp, vector, number)
D 7
register FILE *fp;
char *vector;
int number;
E 7
I 7
	register FILE *fp;
	char *vector;
	int number;
E 7
{
D 7
    char nbuf[80];
    register char *v = nbuf;
E 7
I 7
	char nbuf[80];
	register char *v = nbuf;
E 7

D 7
    sprintf(v, "%s%d", vector, number);
    fprintf(fp, "\t.globl\t_X%s\n\t.align\t2\n_X%s:\n\tpushr\t$0x3f\n", v, v);
    if (strncmp(vector, "dzx", 3) == 0)
D 5
	fprintf(fp, "\tmovl\t$%d,r0\n\tjbr\t_dzdma\n\n", number);
E 5
I 5
	fprintf(fp, "\tmovl\t$%d,r0\n\tjmp\t_dzdma\n\n", number);
E 5
    else
    {
	fprintf(fp, "\tpushl\t$%d\n", number);
	fprintf(fp, "\tcalls\t$1,_%s\n\tpopr\t$0x3f\n\trei\n\n", vector);
    }
E 7
I 7
	(void) sprintf(v, "%s%d", vector, number);
	fprintf(fp, "\t.globl\t_X%s\n\t.align\t2\n_X%s:\n\tpushr\t$0x3f\n",
	    v, v);
I 12
	fprintf(fp, "\tincl\t_fltintrcnt+(4*%d)\n", cntcnt++);
E 12
	if (strncmp(vector, "dzx", 3) == 0)
D 8
		fprintf(fp, "\tmovl\t$%d,r0\n\tjmp\t_dzdma\n\n", number);
E 8
I 8
		fprintf(fp, "\tmovl\t$%d,r0\n\tjmp\tdzdma\n\n", number);
E 8
	else {
D 9
		fprintf(fp, "\tpushl\t$%d\n", number);
E 9
I 8
		if (strncmp(vector, "uur", 3) == 0) {
			fprintf(fp, "#ifdef UUDMA\n");
			fprintf(fp, "\tmovl\t$%d,r0\n\tjsb\tuudma\n", number);
			fprintf(fp, "#endif\n");
		}
I 9
		fprintf(fp, "\tpushl\t$%d\n", number);
E 9
E 8
D 10
		fprintf(fp, "\tcalls\t$1,_%s\n\tpopr\t$0x3f\n\trei\n\n",
		    vector);
E 10
I 10
		fprintf(fp, "\tcalls\t$1,_%s\n\tpopr\t$0x3f\n", vector);
D 13
		fprintf(fp, "#if defined(VAX750) || defined(VAX730)\n");
		fprintf(fp, "\tincl\t_cnt+V_INTR\n#endif\n\trei\n\n");
E 13
I 13
		fprintf(fp, "\tincl\t_cnt+V_INTR\n\trei\n\n");
E 13
E 10
	}
I 12
}

/*
 * Start the interrupt name table with the names
 * of the standard vectors not on the unibus.
 * The number and order of these names should correspond
 * with the definitions in scb.s.
 */
dump_std(fp)
	register FILE *fp;
{
	fprintf(fp, "\n\t.globl\t_intrnames\n");
	fprintf(fp, "\n\t.globl\t_eintrnames\n");
	fprintf(fp, "\t.data\n");
	fprintf(fp, "_intrnames:\n");
	fprintf(fp, "\t.asciz\t\"clock\"\n");
	fprintf(fp, "\t.asciz\t\"cnr\"\n");
	fprintf(fp, "\t.asciz\t\"cnx\"\n");
	fprintf(fp, "\t.asciz\t\"tur\"\n");
	fprintf(fp, "\t.asciz\t\"tux\"\n");
	fprintf(fp, "\t.asciz\t\"mba0\"\n");
	fprintf(fp, "\t.asciz\t\"mba1\"\n");
	fprintf(fp, "\t.asciz\t\"mba2\"\n");
	fprintf(fp, "\t.asciz\t\"mba3\"\n");
	fprintf(fp, "\t.asciz\t\"uba0\"\n");
	fprintf(fp, "\t.asciz\t\"uba1\"\n");
	fprintf(fp, "\t.asciz\t\"uba2\"\n");
	fprintf(fp, "\t.asciz\t\"uba3\"\n");
#define	I_FIXED		13			/* number of names above */
}

dump_intname(fp, vector, number)
	register FILE *fp;
	char *vector;
	int number;
{
	register char *cp = vector;

	fprintf(fp, "\t.asciz\t\"");
	/*
	 * Skip any "int" or "intr" in the name.
	 */
	while (*cp)
		if (cp[0] == 'i' && cp[1] == 'n' &&  cp[2] == 't') {
			cp += 3;
			if (*cp == 'r')
				cp++;
		} else {
			putc(*cp, fp);
			cp++;
		}
	fprintf(fp, "%d\"\n", number);
}

dump_ctrs(fp)
	register FILE *fp;
{
	fprintf(fp, "_eintrnames:\n");
	fprintf(fp, "\n\t.globl\t_intrcnt\n");
	fprintf(fp, "\n\t.globl\t_eintrcnt\n");
	fprintf(fp, "_intrcnt:\n", I_FIXED);
	fprintf(fp, "\t.space\t4 * %d\n", I_FIXED);
	fprintf(fp, "_fltintrcnt:\n", cntcnt);
	fprintf(fp, "\t.space\t4 * %d\n", cntcnt);
	fprintf(fp, "_eintrcnt:\n\n");
	fprintf(fp, "\t.text\n");
E 12
E 7
}
E 1
