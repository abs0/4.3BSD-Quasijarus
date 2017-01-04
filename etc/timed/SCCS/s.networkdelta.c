h47844
s 00010/00005/00077
d D 2.3 88/06/18 14:08:20 bostic 4 3
c install approved copyright notice
e
s 00009/00003/00073
d D 2.2 87/12/23 14:30:13 bostic 3 2
c append Berkeley header; NASA wants a copy
e
s 00000/00002/00076
d D 2.1 85/12/10 13:07:14 bloom 2 1
c Multi network support
e
s 00078/00000/00000
d D 1.1 85/06/24 18:27:03 gusella 1 0
c date and time created 85/06/24 18:27:03 by gusella
e
u
U
t
T
I 1
/*
 * Copyright (c) 1983 Regents of the University of California.
D 3
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 3
I 3
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 4
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 4
I 4
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
E 4
E 3
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 3
#endif not lint
E 3
I 3
#endif /* not lint */
E 3

#include "globals.h"
#include <protocols/timed.h>

extern int machup;
D 2
extern int slvcount;
extern struct host hp[];
E 2

/*
 * `networkdelta' selects the largest set of deltas that fall within the
 * interval RANGE, and uses them to compute the network average delta 
 */

long networkdelta()
{
	int i, j, maxind, minind;
	int ext;
	int tempind;
	long tempdata;
	long x[NHOSTS];
	long average;

	for (i=0; i<slvcount; i++)
		x[i] = hp[i].delta;
	for (i=0; i<slvcount-1; i++) {
		tempdata = x[i];
		tempind = i;
		for (j=i+1; j<slvcount; j++) {
			if (x[j] < tempdata) {
				tempdata = x[j];
				tempind = j;
			}
		}
		x[tempind] = x[i];
		x[i] = tempdata;
	}

	/* this piece of code is critical: DO NOT TOUCH IT! */
/****/
	i=0; j=1; minind=0; maxind=1;
	if (machup == 2)
		goto compute;
	do {
		if (x[j]-x[i] <= RANGE)
			j++;
		else {
			if (j > i+1) 
 				j--; 
			if ((x[j]-x[i] <= RANGE) && (j-i >= maxind-minind)) {
				minind=i;
				maxind=j;
			}	
			i++;
			if(i = j)
				j++;
		}
	} while (j < machup);
	if ((x[machup-1] - x[i] <= RANGE) && (machup-i-1 >= maxind-minind)) {
		minind=i; maxind=machup-1;
	}
/****/
compute:
	ext = maxind - minind + 1;
	average = 0;
	for (i=minind; i<=maxind; i++)
		average += x[i];
	average /= ext;
	return(average);
}
E 1
