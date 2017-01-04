h23165
s 00002/00002/00061
d D 4.2 88/01/24 10:26:01 bostic 2 1
c remove old-style initialization
e
s 00063/00000/00000
d D 4.1 81/01/15 00:16:52 eric 1 0
c date and time created 81/01/15 00:16:52 by eric
e
u
U
f b 
f i 
t
T
I 1
# include	"stdio.h"
# include	"../hdr/macros.h"

SCCSID(%W%);

D 2
char pattern[] "@(#)";
char opattern[] "~|^`";
E 2
I 2
char *pattern = "@(#)";
char *opattern = "~|^`";
E 2


main(argc,argv)
int argc;
register char **argv;
{
	register int i;
	register FILE *iop;

	if (argc < 2)
		dowhat(stdin);
	else
		for (i = 1; i < argc; i++) {
			if ((iop = fopen(argv[i],"r")) == NULL)
				fprintf(stderr,"can't open %s (26)\n",argv[i]);
			else {
				printf("%s:\n",argv[i]);
				dowhat(iop);
			}
		}
}


dowhat(iop)
register FILE *iop;
{
	register int c;

	while ((c = getc(iop)) != EOF) {
		if (c == pattern[0])
			trypat(iop, &pattern[1]);
		else if (c == opattern[0])
			trypat(iop, &opattern[1]);
	}
	fclose(iop);
}


trypat(iop,pat)
register FILE *iop;
register char *pat;
{
	register int c;

	for (; *pat; pat++)
		if ((c = getc(iop)) != *pat)
			break;
	if (!*pat) {
		putchar('\t');
		while ((c = getc(iop)) != EOF && c && !any(c,"\">\n"))
			putchar(c);
		putchar('\n');
	}
	else if (c != EOF)
		ungetc(c, iop);
}
E 1
