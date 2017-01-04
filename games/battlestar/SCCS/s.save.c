h12870
s 00010/00005/00119
d D 5.2 88/06/19 14:11:32 bostic 6 5
c install approved copyright notice
e
s 00011/00005/00113
d D 5.1 88/05/08 15:49:57 bostic 5 4
c add Berkeley header; yank to 5.1
e
s 00004/00004/00114
d D 1.4 85/11/07 13:20:55 bloom 4 3
c fix order things read in (from muller@sdcsvax)
e
s 00006/00000/00112
d D 1.3 85/04/24 15:32:36 edward 3 2
c copyright messages
e
s 00005/00005/00107
d D 1.2 84/11/28 18:31:22 edward 2 1
c Dave's changes
e
s 00112/00000/00000
d D 1.1 84/11/18 18:59:19 edward 1 0
c date and time created 84/11/18 18:59:19 by edward
e
u
U
t
T
I 3
/*
D 5
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 5
I 5
 * Copyright (c) 1983 Regents of the University of California.
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
D 5
static char sccsid[] = "%W% %G%";
#endif
E 5
I 5
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 5

#include "externs.h"

restore()
{
	char *getenv();
	char *home;
	char home1[100];
	register int n;
	int tmp;
	register FILE *fp;

	home = getenv("HOME");
	strcpy(home1, home);
	strcat(home1, "/Bstar");
	if ((fp = fopen(home1, "r")) == 0) {
		perror(home1);
		return;
	}
	fread(&WEIGHT, sizeof WEIGHT, 1, fp);
	fread(&CUMBER, sizeof CUMBER, 1, fp);
	fread(&clock, sizeof clock, 1, fp);
I 4
	fread(&tmp, sizeof tmp, 1, fp);
	location = tmp ? dayfile : nightfile;
E 4
	for (n = 1; n <= NUMOFROOMS; n++) {
		fread(location[n].link, sizeof location[n].link, 1, fp);
		fread(location[n].objects, sizeof location[n].objects, 1, fp);
	}
	fread(inven, sizeof inven, 1, fp);
	fread(wear, sizeof wear, 1, fp);
	fread(injuries, sizeof injuries, 1, fp);
	fread(notes, sizeof notes, 1, fp);
	fread(&direction, sizeof direction, 1, fp);
	fread(&position, sizeof position, 1, fp);
	fread(&time, sizeof time, 1, fp);
D 4
	fread(&tmp, sizeof tmp, 1, fp);
	location = tmp ? dayfile : nightfile;
E 4
	fread(&fuel, sizeof fuel, 1, fp);
	fread(&torps, sizeof torps, 1, fp);
	fread(&carrying, sizeof carrying, 1, fp);
	fread(&encumber, sizeof encumber, 1, fp);
	fread(&rythmn, sizeof rythmn, 1, fp);
	fread(&followfight, sizeof followfight, 1, fp);
	fread(&ate, sizeof ate, 1, fp);
	fread(&snooze, sizeof snooze, 1, fp);
	fread(&meetgirl, sizeof meetgirl, 1, fp);
	fread(&followgod, sizeof followgod, 1, fp);
	fread(&godready, sizeof godready, 1, fp);
	fread(&win, sizeof win, 1, fp);
	fread(&wintime, sizeof wintime, 1, fp);
	fread(&matchlight, sizeof matchlight, 1, fp);
	fread(&matchcount, sizeof matchcount, 1, fp);
	fread(&loved, sizeof loved, 1, fp);
	fread(&pleasure, sizeof pleasure, 1, fp);
	fread(&power, sizeof power, 1, fp);
	fread(&ego, sizeof ego, 1, fp);
}

save()
{
	char *getenv();
	char *home;
	char home1[100];
	register int n;
	int tmp;
	FILE *fp;

	home = getenv("HOME");
	strcpy(home1, home);
	strcat(home1, "/Bstar");
	if ((fp = fopen(home1, "w")) == 0) {
		perror(home1);
		return;
	}
	printf("Saved in %s.\n", home1);
D 2
	fread(&WEIGHT, sizeof WEIGHT, 1, fp);
	fread(&CUMBER, sizeof CUMBER, 1, fp);
	fread(&clock, sizeof clock, 1, fp);
E 2
I 2
	fwrite(&WEIGHT, sizeof WEIGHT, 1, fp);
	fwrite(&CUMBER, sizeof CUMBER, 1, fp);
	fwrite(&clock, sizeof clock, 1, fp);
I 4
	tmp = location == dayfile;
	fwrite(&tmp, sizeof tmp, 1, fp);
E 4
E 2
	for (n = 1; n <= NUMOFROOMS; n++) {
D 2
		fread(location[n].link, sizeof location[n].link, 1, fp);
		fread(location[n].objects, sizeof location[n].objects, 1, fp);
E 2
I 2
		fwrite(location[n].link, sizeof location[n].link, 1, fp);
		fwrite(location[n].objects, sizeof location[n].objects, 1, fp);
E 2
	}
	fwrite(inven, sizeof inven, 1, fp);
	fwrite(wear, sizeof wear, 1, fp);
	fwrite(injuries, sizeof injuries, 1, fp);
	fwrite(notes, sizeof notes, 1, fp);
	fwrite(&direction, sizeof direction, 1, fp);
	fwrite(&position, sizeof position, 1, fp);
	fwrite(&time, sizeof time, 1, fp);
D 4
	tmp = location == dayfile;
	fwrite(&tmp, sizeof tmp, 1, fp);
E 4
	fwrite(&fuel, sizeof fuel, 1, fp);
	fwrite(&torps, sizeof torps, 1, fp);
	fwrite(&carrying, sizeof carrying, 1, fp);
	fwrite(&encumber, sizeof encumber, 1, fp);
	fwrite(&rythmn, sizeof rythmn, 1, fp);
	fwrite(&followfight, sizeof followfight, 1, fp);
	fwrite(&ate, sizeof ate, 1, fp);
	fwrite(&snooze, sizeof snooze, 1, fp);
	fwrite(&meetgirl, sizeof meetgirl, 1, fp);
	fwrite(&followgod, sizeof followgod, 1, fp);
	fwrite(&godready, sizeof godready, 1, fp);
	fwrite(&win, sizeof win, 1, fp);
	fwrite(&wintime, sizeof wintime, 1, fp);
	fwrite(&matchlight, sizeof matchlight, 1, fp);
	fwrite(&matchcount, sizeof matchcount, 1, fp);
	fwrite(&loved, sizeof loved, 1, fp);
	fwrite(&pleasure, sizeof pleasure, 1, fp);
	fwrite(&power, sizeof power, 1, fp);
	fwrite(&ego, sizeof ego, 1, fp);
}
E 1
