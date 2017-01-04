h59905
s 00082/00000/00000
d D 5.1 04/03/02 17:47:52 msokolov 1 0
c date and time created 04/03/02 17:47:52 by msokolov
e
u
U
t
T
I 1
/*
 * Copyright (c) 1980 Regents of the University of California.
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
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */

#include <stdio.h>
#include <sys/types.h>
#include <sys/buf.h>
#include <vax/nexus.h>
#include <vaxuba/ubavar.h>
#include "y.tab.h"
#include "config.h"

vax_flatten_nexi()
{
	register struct device *dp, *mp;

	for (dp = dtab; dp != 0; dp = dp->d_next) {
		if (dp->d_unit < 0)
			continue;
		mp = dp->d_conn;
		if (mp == 0)
			continue;
		if (mp == TO_NEXUS) {
			if (eq(dp->d_name, "uba") || eq(dp->d_name, "mba") ||
			    eq(dp->d_name, "vaxbi") || eq(dp->d_name, "xmi"))
				continue;
			if (dp->d_node >= 0) {
	printf("%s%d: can't tie down a node number on an amorphous nexus\n",
		dp->d_name, dp->d_unit);
				continue;
			}
			dp->d_node = -1;
		} else {
			if (eq(mp->d_name, "vaxbi")) {
				if (mp->d_unit < 0 && dp->d_node < 0) {
					dp->d_node = -1;
					dp->d_conn = TO_NEXUS;
					continue;
				}
				if (mp->d_unit < 0 || dp->d_node < 0) {
			printf("%s: can't partially tie down a VAXBI node\n",
				dp->d_name, dp->d_unit);
					continue;
				}
				dp->d_node = PNEXUS_TIE(NEXCLASS_VAXBI,
							mp->d_unit, dp->d_node);
				dp->d_conn = TO_NEXUS;
			} else if (eq(mp->d_name, "xmi")) {
				if (mp->d_unit < 0 && dp->d_node < 0) {
					dp->d_node = -1;
					dp->d_conn = TO_NEXUS;
					continue;
				}
				if (mp->d_unit < 0 || dp->d_node < 0) {
			printf("%s: can't partially tie down an XMI node\n",
				dp->d_name, dp->d_unit);
					continue;
				}
				dp->d_node = PNEXUS_TIE(NEXCLASS_XMI,
							mp->d_unit, dp->d_node);
				dp->d_conn = TO_NEXUS;
			}
		}
	}
}
E 1
