#ifndef lint
static char sccsid[] = "%W% (Berkeley) %E%";
#endif

#include <sys/param.h>
#include <stdio.h>

char pagefile[] = "pages/XXXXXX";
FILE *pagef;
int pagecnt, linecnt;
int linesperpage = 2200;

main(argc, argv)
	char **argv;
{
	u_char buf[264];
	register u_char *cp;
	register int i, j;

	if (argc >= 2 && argv[1][0] == '-' && argv[1][1] == 'y')
		linesperpage = atoi(argv[1]+2);
	while (fread(buf, 1, sizeof(buf), stdin) == sizeof(buf)) {
		if (!pagef) {
			sprintf(pagefile + 6, "%d", ++pagecnt);
			pagef = fopen(pagefile, "w");
			if (!pagef) {
				perror(pagefile);
				exit(1);
			}
			linecnt = 0;
		}
		for (i = 0, cp = buf; i < 8; i++) {
			for (j = 0; j < 33; j++)
				fprintf(pagef, "%02X", *cp++);
			putc('\n', pagef);
		}
		linecnt++;
		if (linecnt >= linesperpage) {
			fclose(pagef);
			pagef = NULL;
		}
	}
	return(0);
}
