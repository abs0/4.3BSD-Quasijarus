h51569
s 00080/00061/00026
d D 5.3 88/06/30 17:09:15 bostic 11 10
c use getopt(3); have one instance of the error switch; allow
c "swapon -a /dev/foo"; minor cleanups; add Berkeley specific headers
e
s 00002/00004/00085
d D 5.2 86/03/04 19:30:14 mckusick 10 9
c use swapon instead of syscall
e
s 00016/00001/00073
d D 5.1 85/05/28 15:37:16 dist 9 8
c Add copyright
e
s 00003/00003/00071
d D 4.8 85/03/20 09:35:20 karels 8 7
c don't be misleading
e
s 00034/00003/00040
d D 4.7 85/01/29 16:25:00 bloom 7 6
c improve error messages & ignore error message if already swapping on device
c for -a
e
s 00001/00005/00042
d D 4.6 83/11/29 19:45:31 mckusick 6 5
c clean up error message to use perror() - from decvax!dartvax!dartlib!steve
e
s 00002/00001/00045
d D 4.5 83/10/14 12:21:28 root 5 4
c say which device in error message
e
s 00005/00002/00041
d D 4.4 80/10/16 01:05:05 bill 4 3
c print on standard output
e
s 00010/00014/00033
d D 4.3 80/10/15 23:57:44 bill 3 2
c new subroutines
e
s 00022/00000/00025
d D 4.2 80/10/13 17:16:32 bill 2 1
c adding calls to fstab routines
e
s 00025/00000/00000
d D 4.1 80/10/01 17:28:45 bill 1 0
c date and time created 80/10/01 17:28:45 by bill
e
u
U
t
T
I 1
D 9
static char *sccsid = "%W% (Berkeley) %G%";
E 9
I 9
/*
 * Copyright (c) 1980 Regents of the University of California.
D 11
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 11
I 11
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
E 11
 */

#ifndef lint
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
D 11
#endif not lint
E 11
I 11
#endif /* not lint */
E 11

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 11
#endif not lint
E 11
I 11
#endif /* not lint */
E 11

E 9
D 11
#include <stdio.h>
E 11
I 2
#include <fstab.h>
I 7
#include <errno.h>
I 11
#include <stdio.h>
E 11
E 7
E 2

D 10
#define	VSWAPON	85

E 10
I 7
D 11
extern int errno;

E 11
E 7
main(argc, argv)
	int argc;
D 11
	char *argv[];
E 11
I 11
	char **argv;
E 11
{
D 11
	int stat = 0;
E 11
I 11
	extern char *optarg;
	extern int optind;
	register struct fstab *fsp;
	register int stat;
	int ch, doall;
E 11

D 11
	--argc, argv++;
	if (argc == 0) {
		fprintf(stderr, "usage: swapon name...\n");
		exit(1);
I 2
	}
	if (argc == 1 && !strcmp(*argv, "-a")) {
D 3
		FILE	*fs_file;
		struct	fstab	fs;
		if ((fs_file = fopen(FSTAB, "r")) == NULL){
			perror(FSTAB);
			exit(1);
		}
		while (!feof(fs_file)){
			fscanf(fs_file, FSTABFMT, FSTABARG(&fs));
			if (strcmp(fs.fs_type, "sw"))
E 3
I 3
		struct	fstab	*fsp;
		if (setfsent() == 0)
			perror(FSTAB), exit(1);
		while ( (fsp = getfsent()) != 0){
			if (strcmp(fsp->fs_type, FSTAB_SW) != 0)
E 3
				continue;
D 3
			fprintf(stderr, "Adding %s as swap device\n",
			    fs.fs_spec);
			if (syscall(VSWAPON, fs.fs_spec) == -1) {
				perror(fs.fs_spec);
E 3
I 3
D 4
			fprintf(stdout, "Adding %s as swap device\n",
E 4
I 4
D 8
			printf("Adding %s as swap device\n",
E 4
			    fsp->fs_spec);
E 8
D 10
			if (syscall(VSWAPON, fsp->fs_spec) == -1) {
E 10
I 10
			if (swapon(fsp->fs_spec) == -1) {
E 10
D 4
				perror(fsp->fs_spec);
E 4
I 4
D 6
				extern errno;
				extern char *sys_errlist[];
				printf("%s: %s\n",
D 5
				    sys_errlist[errno]);
E 5
I 5
				    sys_errlist[errno],
				    fsp->fs_spec);
E 6
I 6
D 7
				perror(fsp->fs_spec);
E 6
E 5
E 4
E 3
				stat = 1;
E 7
I 7
				switch(errno) {
				case EINVAL:
					fprintf(stderr,
						"%s: Device not configured\n",
						fsp->fs_spec);
					stat = 1;
					break;
E 11
I 11
	doall = 0;
	while ((ch = getopt(argc, argv, "a")) != EOF)
		switch((char)ch) {
		case 'a':
			doall = 1;
			break;
		case '?':
		default:
			usage();
		}
	argv += optind;
E 11

D 11
				case EBUSY:	/* ignore already in use */
					break;

				default:
					perror(fsp->fs_spec);
					stat = 1;
					break;
				}
E 7
D 8
			}
E 8
I 8
			} else
				printf("Adding %s as swap device\n",
E 11
I 11
	stat = 0;
	if (doall)
		while (fsp = getfsent()) {
			if (strcmp(fsp->fs_type, FSTAB_SW))
				continue;
			if (add(fsp->fs_spec, 1))
				stat = 1;
			else
				printf("swapon: adding %s as swap device\n",
E 11
				    fsp->fs_spec);
E 8
		}
D 3
		fclose(fs_file);
E 3
I 3
D 11
		endfsent();
E 3
		exit(stat);
E 2
	}
	do {
D 10
		if (syscall(VSWAPON, *argv++) == -1) {
E 10
I 10
		if (swapon(*argv++) == -1) {
E 10
			stat = 1;
D 7
			perror(argv[-1]);
E 7
I 7
			switch (errno) {
			case EINVAL:
				fprintf(stderr, "%s: Device not configured\n",
						argv[-1]);
				break;
E 11
I 11
	else if (!*argv)
		usage();
	for (; *argv; ++argv)
		stat |= add(*argv, 0);
	exit(stat);
}
E 11

D 11
			case EBUSY:
				fprintf(stderr, "%s: Device already in use\n",
						argv[-1]);
				break;
E 11
I 11
static
add(name, ignoreebusy)
	char *name;
	int ignoreebusy;
{
	extern int errno;
E 11

D 11
			default:
				perror(argv[-1]);
				break;
			}
E 11
I 11
	if (swapon(name) == -1) {
		switch (errno) {
		case EINVAL:
			fprintf(stderr, "swapon: %s: device not configured\n",
			    name);
			break;
		case EBUSY:
			if (!ignoreebusy)
				fprintf(stderr,
				    "swapon: %s: device already in use\n",
				     name);
			break;
		default:
			fprintf(stderr, "swapon: %s: ", name);
			perror((char *)NULL);
			break;
E 11
E 7
		}
D 11
		argc--;
	} while (argc > 0);
	exit(stat);
E 11
I 11
		return(1);
	}
	return(0);
}

static
usage()
{
	fprintf(stderr, "usage: swapon [-a] [special_file ...]\n");
	exit(1);
E 11
}
E 1
