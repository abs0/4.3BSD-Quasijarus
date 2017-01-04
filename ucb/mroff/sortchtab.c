#ifndef lint
static char sccsid[] = "@(#)sortchtab.c	5.1 (Berkeley) 2012/02/16";
#endif

#include <stdio.h>

extern int chtab[];
int nchars;

count_chars()
{
	register int *p;

	for (p = chtab; *p; p += 2)
		;
	nchars = (p - chtab) / 2;
}

cmpfunc(elem1, elem2)
	int *elem1, *elem2;
{
	return (*elem1 - *elem2);
}

emit()
{
	register int *p;

	puts("int chtab[] = {");
	for (p = chtab; *p; p += 2)
		printf("%d,%d,\n", p[0], p[1]);
	puts("0,0};");
	printf("int chtab_len = %d;\n", nchars);
}

main()
{
	count_chars();
	qsort(chtab, nchars, sizeof(int) * 2, cmpfunc);
	emit();
	exit(0);
}
