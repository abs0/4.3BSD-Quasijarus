h27262
s 00004/00001/00094
d D 5.2 04/10/01 23:37:35 msokolov 5 4
c plug the infamous Morris hole
e
s 00013/00001/00082
d D 5.1 85/06/06 11:04:30 dist 4 3
c Add copyright
e
s 00033/00016/00050
d D 1.3 84/07/26 11:03:42 ralph 3 2
c fix popen security hole.
e
s 00026/00018/00040
d D 1.2 84/06/18 15:21:40 ralph 2 1
c translate \n to \r\n.
e
s 00058/00000/00000
d D 1.1 84/05/11 22:24:57 sam 1 0
c date and time created 84/05/11 22:24:57 by sam
e
u
U
t
T
I 4
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 4
I 1
#ifndef lint
I 4
char copyright[] =
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
E 4
static char sccsid[] = "%W% (Berkeley) %G%";
D 4
#endif
E 4
I 4
#endif not lint
E 4

/*
 * Finger server.
 */
#include <sys/types.h>
#include <netinet/in.h>

#include <stdio.h>
#include <ctype.h>
I 5
#include <strings.h>
E 5

I 2
D 3
FILE	*popen();

E 3
E 2
main(argc, argv)
	char *argv[];
{
D 2
	register char **fargp;
	register char *cp;
	char *fargv[80], line[512];
E 2
I 2
D 3
	register char *cp, *sp;
	char cmdbuf[512], line[512];
E 3
I 3
	register char *sp;
	char line[512];
E 3
E 2
	struct sockaddr_in sin;
D 3
	int i;
E 3
I 3
	int i, p[2], pid, status;
E 3
I 2
	FILE *fp;
I 3
	char *av[4];
E 3
E 2

	i = sizeof (sin);
	if (getpeername(0, &sin, &i) < 0)
		fatal(argv[0], "getpeername");
	line[0] = '\0';
D 5
	gets(line);
E 5
I 5
	fgets(line, 512, stdin);
	if (sp = index(line, '\n'))
		*sp = '\0';
E 5
D 2
	fargp = fargv;
	*fargp++ = "finger";
	cp = line;
E 2
I 2
	sp = line;
D 3
	strcpy(cmdbuf, "/usr/ucb/finger");
	cp = cmdbuf + strlen(cmdbuf);
E 3
I 3
	av[0] = "finger";
	i = 1;
E 3
E 2
	while (1) {
D 2
		while (isspace(*cp))
			cp++;
		if (!*cp)
E 2
I 2
		while (isspace(*sp))
			sp++;
		if (!*sp)
E 2
			break;
D 2
		*fargp++ = cp;
		if (*cp == '/' && (cp[1] == 'W' || cp[1] == 'w')) {
E 2
I 2
D 3
		*cp++ = ' ';
E 3
		if (*sp == '/' && (sp[1] == 'W' || sp[1] == 'w')) {
			sp += 2;
E 2
D 3
			*cp++ = '-';
			*cp++ = 'l';
E 3
I 3
			av[i++] = "-l";
E 3
		}
D 2
		while (!isspace(*cp))
			cp++;
		*cp++ = '\0';
E 2
I 2
D 3
		while (!isspace(*sp))
			*cp++ = *sp++;
E 3
I 3
		if (*sp && !isspace(*sp)) {
			av[i++] = sp;
			while (*sp && !isspace(*sp))
				sp++;
			*sp = '\0';
		}
E 3
E 2
	}
D 2
	*fargp = NULL;
	execv("/usr/ucb/finger", fargv);
	execvp("finger", fargv);
	fatal(argv[0], "/usr/ucb/finger");
E 2
I 2
D 3
	*cp++ = '\0';
	if ((fp = popen(cmdbuf, "r")) == NULL)
		fatal(argv[0], "/usr/ucb/finger");
E 3
I 3
	av[i] = 0;
	if (pipe(p) < 0)
		fatal(argv[0], "pipe");
	if ((pid = fork()) == 0) {
		close(p[0]);
		if (p[1] != 1) {
			dup2(p[1], 1);
			close(p[1]);
		}
		execv("/usr/ucb/finger", av);
		_exit(1);
	}
	if (pid == -1)
		fatal(argv[0], "fork");
	close(p[1]);
	if ((fp = fdopen(p[0], "r")) == NULL)
		fatal(argv[0], "fdopen");
E 3
	while ((i = getc(fp)) != EOF) {
		if (i == '\n')
			putchar('\r');
		putchar(i);
	}
D 3
	pclose(fp);
E 3
I 3
	fclose(fp);
	while ((i = wait(&status)) != pid && i != -1)
		;
E 3
	return(0);
E 2
}

fatal(prog, s)
	char *prog, *s;
{

	fprintf(stderr, "%s: ", prog);
	perror(s);
	exit(1);
}
E 1
