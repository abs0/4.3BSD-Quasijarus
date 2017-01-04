h41908
s 00004/00004/00091
d D 4.5 87/10/26 07:35:57 bostic 6 5
c ANSI C; sprintf now returns an int.
e
s 00008/00001/00087
d D 4.4 84/02/15 11:03:55 ralph 5 4
c added -n option to supress instructions question.
e
s 00002/00002/00086
d D 4.3 83/06/28 12:04:56 tut 4 3
c fixed core dump problem when ref file and indx files missing
e
s 00007/00005/00081
d D 4.2 83/06/22 13:16:23 garrison 3 1
c 
e
s 00000/00000/00086
d R 4.2 83/06/22 13:08:47 garrison 2 1
c Removed error check for i[abc] files, since my changes to hunt
c allow it to make and use an fgrep file (.ig) if the .i[abc] files are
c not present.
e
s 00086/00000/00000
d D 4.1 83/05/06 23:21:13 tut 1 0
c date and time created 83/05/06 23:21:13 by tut
e
u
U
t
T
I 1
#ifndef lint
static char *sccsid = "%W% (Berkeley) %G%";
#endif

#include <stdio.h>
#include <ctype.h>

main(argc, argv)	/* look in biblio for record matching keywords */
int argc;
char **argv;
{
	FILE *fp, *hfp, *fopen(), *popen();
D 6
	char s[BUFSIZ], hunt[64], *sprintf();
E 6
I 6
	char s[BUFSIZ], hunt[64];
E 6
I 5
	int instructions = 1;
E 5

I 5
	if (strcmp(argv[1],"-n") == 0)
	{
		argv++;
		argc--;
		instructions = 0;
	}
E 5
	if (argc == 1 || argc > 2)
	{
		fputs("Usage:  lookbib database\n",
			stderr);
D 3
		fputs("\tdatabase must have indexes built by indxbib\n",
			stderr);
E 3
		fputs("\tfinds citations specified on standard input\n",
			stderr);
		exit(1);
	}
	if (!isatty(fileno(stdin)))
		fp = stdin;
	else if ((fp = fopen("/dev/tty", "r")) == NULL)
	{
		perror("lookbib: /dev/tty");
		exit(1);
	}
D 6
	sprintf(s, "%s.ia", argv[1]);
E 6
I 6
	(void)sprintf(s, "%s.ia", argv[1]);
E 6
	if (access(s, 0) == -1) {
D 3
		perror(s);
		fputs("\trun indxbib to make inverted indexes\n", stderr);
		exit(1);
E 3
I 3
D 6
		sprintf (s, "%s", argv[1]);
E 6
I 6
		(void)sprintf (s, "%s", argv[1]);
E 6
		if (access(s, 0) == -1) {
			perror(s);
D 4
			fputs("\tNeither index file %s.ia ", s, stderr);
			fputs("nor reference file %s found\n", s, stderr);
E 4
I 4
			fprintf(stderr, "\tNeither index file %s.ia ", s);
			fprintf(stderr, "nor reference file %s found\n", s);
E 4
			exit(1);
		}
E 3
	}
D 6
	sprintf(hunt, "/usr/lib/refer/hunt %s", argv[1]);
E 6
I 6
	(void)sprintf(hunt, "/usr/lib/refer/hunt %s", argv[1]);
E 6

D 5
	if (isatty(fileno(fp)))
E 5
I 5
	if (instructions && isatty(fileno(fp)))
E 5
	{
		fprintf(stderr, "Instructions? ");
		fgets(s, BUFSIZ, fp);
		if (*s == 'y')
			instruct();
	}
   again:
	fprintf(stderr, "> ");
	if (fgets(s, BUFSIZ, fp))
	{
		if (*s == '\n')
			goto again;
		if ((hfp = popen(hunt, "w")) == NULL)
		{
			perror("lookbib: /usr/lib/refer/hunt");
			exit(1);
		}
		map_lower(s);
		fputs(s, hfp);
		pclose(hfp);
		goto again;
	}
	fclose(fp);
	fprintf(stderr, "EOT\n");
	exit(0);
}

map_lower(s)		/* map string s to lower case */
char *s;
{
	for ( ; *s; ++s)
		if (isupper(*s))
			*s = tolower(*s);
}

instruct()
{
	fputs("\nType keywords (such as author and date) after the > prompt.\n",
		stderr);
	fputs("References with those keywords are printed if they exist;\n",
		stderr);
	fputs("\tif nothing matches you are given another prompt.\n",
		stderr);
	fputs("To quit lookbib, press CTRL-d after the > prompt.\n\n",
		stderr);
}
E 1
