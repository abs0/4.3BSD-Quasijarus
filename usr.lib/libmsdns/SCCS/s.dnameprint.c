h34906
s 00071/00000/00000
d D 1.1 2011/12/27 02:01:52 msokolov 1 0
c beginning of libmsdns
e
u
U
t
T
I 1
/*
 * Functions for dumping domain names or individual labels
 * in ASCII form to stdio streams.
 */

#ifndef lint
static char sccsid[] = "%W% (IFCTF) %E%";
#endif

#include <sys/types.h>
#include <stdio.h>
#include "dname.h"

static char labchartab[256] = {
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};

print_label(lab, f)
	register u_char *lab;
	register FILE *f;
{
	register int c, i;
	int lablen;

	lablen = *lab++;
	if (!lablen) {
		putc('.', f);
		return;
	}
	for (i = 0; i < lablen; i++) {
		c = *lab++;
		switch (labchartab[c]) {
		case 1:
			putc('\\', f);
			/*FALLTHRU*/
		case 0:
			putc(c, f);
			break;
		default:
			fprintf(f, "\\%03d", c);
		}
	}
}

print_dname(dn, f)
	register struct dname *dn;
	register FILE *f;
{
	register int i;

	for (i = 0; i < dn->dn_nlabels; i++) {
		print_label(dn->dn_labels[i], f);
		putc('.', f);
	}
	if (!i)
		putc('.', f);
}
E 1
