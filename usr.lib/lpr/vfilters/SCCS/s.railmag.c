h47093
s 00010/00005/00137
d D 5.3 88/06/30 17:53:15 bostic 5 4
c install approved copyright notice
e
s 00015/00003/00127
d D 5.2 88/03/08 08:30:01 bostic 4 3
c add Berkeley specific header
e
s 00007/00001/00123
d D 5.1 85/05/15 11:32:26 dist 3 2
c Add copyright notice
e
s 00004/00001/00120
d D 4.2 83/07/16 23:47:26 sam 2 1
c add useful sccs id's
e
s 00121/00000/00000
d D 4.1 83/04/28 15:02:11 ralph 1 0
c date and time created 83/04/28 15:02:11 by ralph
e
u
U
t
T
I 3
/*
 * Copyright (c) 1983 Regents of the University of California.
D 4
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 4
I 4
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 5
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 5
I 5
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
E 5
E 4
 */

E 3
I 1
D 2
/*	%M%	%I%	%E%	*/
E 2
I 2
#ifndef lint
I 4
char copyright[] =
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
 All rights reserved.\n";
#endif /* not lint */

#ifndef lint
E 4
static char sccsid[] = "%W% (Berkeley) %G%";
D 3
#endif
E 3
I 3
D 4
#endif not lint
E 4
I 4
#endif /* not lint */
E 4
E 3

E 2
/*
 * tell vcat which fonts are loaded on the "typesetter"
 */

#define MAGIC_NUMBER 0436
#define RAILMAG_FILE "/usr/lib/vfont/railmag"

char	*concat();
int	rmfd;
char	*rm[4];
char	tbuf[256];

main(argc, argv)
	int argc;
	char *argv[];
{
	register int fnum;
	char cbuf[4][50];

	readrm();
	if (argc <= 1) {
		printrm();
		exit(0);
	}
	while (--argc) {
		argv++;
		fnum = argv[0][0] - '0';
		if (fnum < 1 || fnum > 4)
			error("Invalid font number");
		checkfont(argv[1]);
		if (argv[1][0] == '/')
			rm[fnum-1] = argv[1];
		else
			rm[fnum-1] = concat(cbuf[fnum-1], "/usr/lib/vfont/", argv[1]);
		argv++;	argc--;
	}
	writerm();
}

error(str)
	char *str;
{
	write(2, "Railmag: ", 9);
	write(2, str, strlen(str));
	write(2, "\n", 1);
	exit();
}

checkfont(file)
	char *file;
{
	register int fd;
	char cbuf[80];
	char cbuf2[80];
	short word;

	if ((fd = open(concat(cbuf, file, ".10"), 0)) < 0)
		if ((fd = open(concat(cbuf2, "/usr/lib/vfont/", cbuf), 0)) < 0)
			error("cant open font");
	if (read(fd, &word, 2) != 2)
		error("cant read font");
	if (word != MAGIC_NUMBER)
		error("font has no magic number");
	close(fd);
}

readrm()
{
	register int i;
	register char *cp;
	char c;

	if ((rmfd = open(RAILMAG_FILE, 0)) < 0)
		error("No railmag file");
	cp = tbuf;
	for (i = 0; i < 4; i++) {
		rm[i] = cp;
		while (read(rmfd, &c, 1) == 1 && c != '\n')
			*cp++ = c;
		*cp++ = '\0';
	}
}

printrm()
{
	register int i;

	for (i = 0; i < 4; i++)
		printf("%s on %d\n", rm[i], i+1);
}

writerm()
{
	register int i;
	register char *cp;

	unlink(RAILMAG_FILE);
	if ((rmfd = creat(RAILMAG_FILE, 0644)) < 0)
		error("cant recreate railmag file");
	for (i = 0; i < 4; i++) {
		cp = rm[i];
		while (*cp != '\0')
			write(rmfd, cp++, 1);
		write(rmfd, "\n", 1);
	}
}

char *
concat(outbuf, in1, in2)
	register char *outbuf, *in1, *in2;
{
	char *save;

	save = outbuf;
	while (*in1)
		*outbuf++ = *in1++;
	while (*in2)
		*outbuf++ = *in2++;
	return(save);
}
E 1
