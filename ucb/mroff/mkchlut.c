#ifndef lint
static char sccsid[] = "@(#)mkchlut.c	5.1 (Berkeley) 2012/07/14";
#endif

#include <sys/types.h>
#include <stdio.h>

extern int chtab[];

#define	LUTSIZE	(94*94)
int chlut[LUTSIZE];

process_chtab()
{
	register int *p, c1, c2, idx;

	for (p = chtab; *p; p += 2) {
		c1 = *p & 0x7F;
		c2 = (*p >> 8) & 0x7F;
		if (c1 < '!' || c1 > '~' || c2 < '!' || c2 > '~') {
			fprintf(stderr,
				"chtab.c: pair value 0x%x is invalid\n", *p);
			exit(1);
		}
		idx = (c1 - '!') * 94 + (c2 - '!');
		if (chlut[idx]) {
			fprintf(stderr, "chtab.c: \\(%c%c is defined twice\n",
				c1, c2);
			exit(1);
		}
		chlut[idx] = p[1];
	}
}

emit_chlut()
{
	register int idx;

	printf("unsigned short chlut[%d] = {", LUTSIZE);
	for (idx = 0; idx < LUTSIZE; idx++) {
		if (!(idx & 7)) {
			putchar('\n');
			putchar('\t');
		}
		printf("0x%04x,", chlut[idx]);
	}
	fputs("\n};\n", stdout);
}

main()
{
	process_chtab();
	emit_chlut();
	exit(0);
}
