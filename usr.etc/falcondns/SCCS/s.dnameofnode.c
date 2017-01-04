h00301
s 00038/00000/00000
d D 1.1 2011/11/01 05:51:52 msokolov 1 0
c split off from dname.c
e
u
U
t
T
I 1
/*
 * The messy dname_of_node() function
 */

#ifndef lint
static char sccsid[] = "%W% (IFCTF) %E%";
#endif

#include <sys/types.h>
#include <arpa/nameser.h>
#include "dname.h"
#include "tree.h"
#include "zone.h"

void
dname_of_node(n, dn)
	register struct node *n;
	register struct dname *dn;
{
	register int d;
	register struct dname *zd;

	dn->dn_stringlen = 0;
	for (d = 0; n; n = n->n_parent) {
		if (n->n_zone) {
			zd = n->n_zone->z_dname;
			dn->dn_stringlen += zd->dn_stringlen;
			dn->dn_nlabels = zd->dn_nlabels + d;
			bcopy(zd->dn_labels, dn->dn_labels + d,
				(zd->dn_nlabels + 1) * sizeof(u_char *));
			return;
		}
		dn->dn_labels[d] = (u_char *) n;
		dn->dn_stringlen += dn->dn_labels[d][0] + 1;
		d++;
	}
	dn->dn_nlabels = d - 1;
}
E 1
