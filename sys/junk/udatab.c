/*
 * Copyright (c) 1983, 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
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
 */

#ifndef lint
char copyright[] =
"@(#) Copyright (c) 1983, 1988 Regents of the University of California.\n\
 All rights reserved.\n";
#endif /* not lint */

#ifndef lint
static char sccsid[] = "@(#)udatab.c	7.1 (Berkeley) 11/24/03";
#endif /* not lint */

/*
 * Program to generate these uda driver tables we are still stuck with
 * from /etc/disktab.  Unlike diskpart this program takes the partitions from
 * disktab rather than compute them.
 */
#include <sys/param.h>
#include <sys/disklabel.h>

#include <stdio.h>
#include <ctype.h>

#define	NPARTITIONS	8
#define	PART(x)		(x - 'a')

main(argc, argv)
	int argc;
	char *argv[];
{
	register struct disklabel *dp;
	register int part;
	register struct partition *pp;
	char *lp, *tyname;
	int sflag = 0;

	argc--, argv++;
	if (argc > 0 && strcmp(*argv, "-s") == 0) {
		sflag++;
		argc--, argv++;
	}
	if (argc < 1) {
		fprintf(stderr, "usage: udatab [ -s ] disk-type\n");
		exit(1);
	}
	dp = getdiskbyname(*argv);
	if (dp == NULL) {
		if (dp == NULL) {
			fprintf(stderr, "%s: unknown disk type\n", *argv);
			exit(2);
		}
	}
	if (dp->d_type != DTYPE_MSCP) {
		fprintf(stderr, "%s: not an MSCP disk\n", *argv);
		exit(3);
	}
	if (!sflag) {
		printf("}, %s_sizes[%d] = {\n", dp->d_typename, NPARTITIONS);
		for (part = PART('a'); part < NPARTITIONS; part++) {
			pp = &dp->d_partitions[part];
			printf("\t%d,\t%d,\t\t/* %c=sectors %d thru %d */\n",
				pp->p_size, pp->p_offset, 'A' + part,
				pp->p_offset, pp->p_offset + pp->p_size - 1);
		}
	} else {
		printf("u_long %s_off[] = { ", dp->d_typename);
		for (part = PART('a'); part < NPARTITIONS; part++) {
			pp = &dp->d_partitions[part];
			printf("%d", pp->p_size ? pp->p_offset : -1);
			if (part != PART('h'))
				putchar(',');
			putchar(' ');
		}
		printf("};\n");
	}
	exit(0);
}
