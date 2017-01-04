h64220
s 00010/00005/00191
d D 5.6 88/06/18 13:43:15 bostic 8 7
c install approved copyright notice
e
s 00009/00003/00187
d D 5.5 88/04/29 13:43:38 bostic 7 6
c add Berkeley specific header; original conception by Michael Toy
e
s 00001/00001/00189
d D 5.4 88/04/26 13:35:22 bostic 6 5
c cp unused in function do_swap
e
s 00002/00002/00188
d D 5.3 88/04/05 11:46:32 mckusick 5 4
c go to end of list, so a error can be reported (4.3BSD/etc/111 mouse@mcgill.edu)
e
s 00002/00002/00188
d D 5.2 87/10/22 11:10:12 bostic 4 3
c ANSI C; sprintf now returns an int.
e
s 00007/00001/00183
d D 5.1 85/05/08 11:58:34 dist 3 2
c Add copyright
e
s 00001/00001/00183
d D 4.2 84/12/04 10:39:32 karels 2 1
c bogus drive number check
e
s 00184/00000/00000
d D 4.1 83/08/13 16:56:24 sam 1 0
c date and time created 83/08/13 16:56:24 by sam
e
u
U
t
T
I 3
/*
 * Copyright (c) 1980 Regents of the University of California.
D 7
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 7
I 7
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 8
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 8
I 8
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
E 8
E 7
 */

E 3
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 3
#endif
E 3
I 3
D 7
#endif not lint
E 7
I 7
#endif /* not lint */
E 7
E 3

/*
 * Build a swap configuration file.
 */
#include "config.h"

#include <stdio.h>
#include <ctype.h>

swapconf()
{
	register struct file_list *fl;
	struct file_list *do_swap();

	fl = conf_list;
	while (fl) {
		if (fl->f_type != SYSTEMSPEC) {
			fl = fl->f_next;
			continue;
		}
		fl = do_swap(fl);
	}
}

struct file_list *
do_swap(fl)
	register struct file_list *fl;
{
	FILE *fp;
D 6
	char  swapname[80], *cp;
E 6
I 6
	char  swapname[80];
E 6
	register struct file_list *swap;
	dev_t dev;

	if (eq(fl->f_fn, "generic")) {
		fl = fl->f_next;
		return (fl->f_next);
	}
	(void) sprintf(swapname, "swap%s.c", fl->f_fn);
	fp = fopen(path(swapname), "w");
	if (fp == 0) {
		perror(path(swapname));
		exit(1);
	}
	fprintf(fp, "#include \"../h/param.h\"\n");
	fprintf(fp, "#include \"../h/conf.h\"\n");
	fprintf(fp, "\n");
	/*
	 * If there aren't any swap devices
	 * specified, just return, the error
	 * has already been noted.
	 */
	swap = fl->f_next;
	if (swap == 0 || swap->f_type != SWAPSPEC) {
		(void) unlink(path(swapname));
		fclose(fp);
		return (swap);
	}
	fprintf(fp, "dev_t\trootdev = makedev(%d, %d);\n",
		major(fl->f_rootdev), minor(fl->f_rootdev));
	fprintf(fp, "dev_t\targdev  = makedev(%d, %d);\n",
		major(fl->f_argdev), minor(fl->f_argdev));
	fprintf(fp, "dev_t\tdumpdev = makedev(%d, %d);\n",
		major(fl->f_dumpdev), minor(fl->f_dumpdev));
	fprintf(fp, "\n");
	fprintf(fp, "struct\tswdevt swdevt[] = {\n");
	do {
		dev = swap->f_swapdev;
		fprintf(fp, "\t{ makedev(%d, %d),\t0,\t%d },\t/* %s */\n",
		    major(dev), minor(dev), swap->f_swapsize, swap->f_fn);
		swap = swap->f_next;
	} while (swap && swap->f_type == SWAPSPEC);
	fprintf(fp, "\t{ 0, 0, 0 }\n");
	fprintf(fp, "};\n");
	fclose(fp);
	return (swap);
}

static	int devtablenotread = 1;
static	struct devdescription {
	char	*dev_name;
	int	dev_major;
	struct	devdescription *dev_next;
} *devtable;

/*
 * Given a device name specification figure out:
 *	major device number
 *	partition
 *	device name
 *	unit number
 * This is a hack, but the system still thinks in
 * terms of major/minor instead of string names.
 */
dev_t
nametodev(name, defunit, defpartition)
	char *name;
	int defunit;
	char defpartition;
{
	char *cp, partition;
	int unit;
	register struct devdescription *dp;

	cp = name;
	if (cp == 0) {
		fprintf(stderr, "config: internal error, nametodev\n");
		exit(1);
	}
	while (*cp && !isdigit(*cp))
		cp++;
	unit = *cp ? atoi(cp) : defunit;
D 2
	if (unit < 0 || unit > 7) {
E 2
I 2
	if (unit < 0 || unit > 31) {
E 2
		fprintf(stderr,
"config: %s: invalid device specification, unit out of range\n", name);
		unit = defunit;			/* carry on more checking */
	}
	if (*cp) {
		*cp++ = '\0';
		while (*cp && isdigit(*cp))
			cp++;
	}
	partition = *cp ? *cp : defpartition;
	if (partition < 'a' || partition > 'h') {
		fprintf(stderr,
"config: %c: invalid device specification, bad partition\n", *cp);
		partition = defpartition;	/* carry on */
	}
	if (devtablenotread)
		initdevtable();
D 5
	for (dp = devtable; dp->dev_next; dp = dp->dev_next)
E 5
I 5
	for (dp = devtable; dp; dp = dp->dev_next)
E 5
		if (eq(name, dp->dev_name))
			break;
	if (dp == 0) {
		fprintf(stderr, "config: %s: unknown device\n", name);
		return (NODEV);
	}
	return (makedev(dp->dev_major, (unit << 3) + (partition - 'a')));
}

char *
devtoname(dev)
	dev_t dev;
{
	char buf[80]; 
	register struct devdescription *dp;

	if (devtablenotread)
		initdevtable();
D 5
	for (dp = devtable; dp->dev_next; dp = dp->dev_next)
E 5
I 5
	for (dp = devtable; dp; dp = dp->dev_next)
E 5
		if (major(dev) == dp->dev_major)
			break;
	if (dp == 0)
		dp = devtable;
D 4
	sprintf(buf, "%s%d%c", dp->dev_name,
E 4
I 4
	(void) sprintf(buf, "%s%d%c", dp->dev_name,
E 4
		minor(dev) >> 3, (minor(dev) & 07) + 'a');
	return (ns(buf));
}

initdevtable()
{
	char buf[BUFSIZ];
	int maj;
	register struct devdescription **dp = &devtable;
	FILE *fp;

D 4
	sprintf(buf, "../conf/devices.%s", machinename);
E 4
I 4
	(void) sprintf(buf, "../conf/devices.%s", machinename);
E 4
	fp = fopen(buf, "r");
	if (fp == NULL) {
		fprintf(stderr, "config: can't open %s\n", buf);
		exit(1);
	}
	while (fscanf(fp, "%s\t%d\n", buf, &maj) == 2) {
		*dp = (struct devdescription *)malloc(sizeof (**dp));
		(*dp)->dev_name = ns(buf);
		(*dp)->dev_major = maj;
		dp = &(*dp)->dev_next;
	}
	*dp = 0;
	fclose(fp);
	devtablenotread = 0;
}
E 1
