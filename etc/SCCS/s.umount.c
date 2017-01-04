h11703
s 00014/00002/00154
d D 5.1 85/05/28 15:42:25 dist 9 8
c Add copyright
e
s 00062/00019/00094
d D 4.8 83/05/28 13:08:10 sam 8 7
c lots of cleanups; use <mtab.h>; handle quotas more cleanly; add 
c type field to mtab so we can see read-only and quotas
e
s 00001/00001/00112
d D 4.7 83/05/10 15:40:19 sam 7 6
c back to good old umount
e
s 00002/00002/00111
d D 4.6 83/01/02 15:22:29 sam 6 5
c from sun
e
s 00001/00001/00112
d D 4.5 82/12/04 17:11:27 mckusick 5 4
c umount -> unmount
e
s 00067/00062/00046
d D 4.4 82/02/28 21:28:14 wnj 4 3
c cleanup and use perror
e
s 00035/00023/00073
d D 4.3 80/10/16 01:06:45 bill 3 2
c print on standard output; -a reverse order
e
s 00005/00006/00091
d D 4.2 80/10/13 17:04:48 bill 2 1
c adding calls to fstab routines
e
s 00097/00000/00000
d D 4.1 80/10/01 17:29:08 bill 1 0
c date and time created 80/10/01 17:29:08 by bill
e
u
U
t
T
I 9
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 9
I 8
#ifndef lint
E 8
I 1
D 9
static char *sccsid = "%W% (Berkeley) %G%";
I 8
#endif
E 9
I 9
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 9
E 8
I 4

E 4
D 8
#include <stdio.h>
#include <fstab.h>
I 4

E 8
E 4
/*
D 2
 *	umount name
 *
 *	umount -a
 *		This tries to unmount all of the block special file names
 *		as given in /etc/fstab.
E 2
I 2
 * umount
E 2
 */
I 8
#include <sys/param.h>
E 8

D 8
#define	NMOUNT	16
#define	NAMSIZ	32
E 8
I 8
#include <stdio.h>
#include <fstab.h>
#include <mtab.h>
E 8

D 8
struct mtab {
	char	file[NAMSIZ];
	char	spec[NAMSIZ];
} mtab[NMOUNT];
E 8
I 8
struct	mtab mtab[NMOUNT];
E 8

I 4
char	*rindex();
int	vflag, all, errs;

E 4
main(argc, argv)
D 4
char **argv;
E 4
I 4
	int argc;
	char **argv;
E 4
{
	register struct mtab *mp;
	register char *p1, *p2;
	int mf;

I 4
	argc--, argv++;
E 4
	sync();
	mf = open("/etc/mtab", 0);
D 4
	read(mf, (char *)mtab, NMOUNT*2*NAMSIZ);
	if(argc != 2) {
		printf("arg count\n");
		return(1);
E 4
I 4
	read(mf, (char *)mtab, sizeof (mtab));
again:
D 6
	if (!strcmp(*argv, "-v")) {
E 6
I 6
	if (argc > 0 && !strcmp(*argv, "-v")) {
E 6
		vflag++;
		argc--, argv++;
		goto again;
E 4
	}
D 4
	if (strcmp(argv[1], "-a") == 0){
E 4
I 4
D 6
	if (!strcmp(*argv, "-a")) {
E 6
I 6
	if (argc > 0 && !strcmp(*argv, "-a")) {
E 6
		all++;
		argc--, argv++;
		goto again;
	}
	if (argc == 0 && !all) {
		fprintf(stderr, "Usage: umount [ -a ] [ -v ] [ dev ... ]\n");
		exit(1);
	}
	if (all) {
E 4
D 3
		FILE	*fs_file;
		struct	fstab	fs;
D 2
		if ( (fs_file = fopen(FSTAB, "r")) == NULL){
E 2
I 2
		if ((fs_file = fopen(FSTAB, "r")) == NULL){
E 2
			perror(FSTAB);
			exit(1);
		}
		while (!feof(fs_file)){
			fscanf(fs_file, FSTABFMT, FSTABARG(&fs));
			if (strcmp(fs.fs_file, "/") == 0)
I 2
				continue;
			if (strcmp(fs.fs_type, "rw") &&
			    strcmp(fs.fs_type, "ro"))
E 2
				continue;
			fprintf(stderr, "Unmounting special file %s\n",
				fs.fs_spec);
			fflush(stderr);
			if (umountfs(fs.fs_spec))
				continue;
		}
		fclose(fs_file);
E 3
I 3
		if (setfsent() == 0)
			perror(FSTAB), exit(1);
		umountall();
D 4
		endfsent();
E 3
	} else {
D 3
		if (umountfs(argv[1]))
E 3
I 3
		int	back;
		if (back = umountfs(argv[1])){
			if (back < 0)
				perror("umount");
E 3
			exit(1);
I 3
		}
E 4
I 4
		exit(0);
E 4
E 3
	}
D 4
	exit(0);
E 4
I 4
	while (argc > 0) {
		if (umountfs(*argv++) == 0)
			errs++;
		argc--;
	}
	exit(errs);
E 4
}
I 3
D 4
/*
 *	It is important to unmount the files in
 *	reverse! order from the order they were mounted,
 *	so that file systems mounted as children to other
 *	file systems get removed in the right order.
 */
E 4
I 4

E 4
umountall()
{
D 4
	struct	fstab	fs;
	struct	fstab	*fsp;
	if ( (fsp = getfsent()) == 0)
E 4
I 4
D 8
	struct fstab fs, *fsp;
E 8
I 8
	struct fstab *fs, *allocfsent();
E 8

D 8
	if ((fsp = getfsent()) == 0)
E 8
I 8
	if ((fs = getfsent()) == 0)
E 8
E 4
		return;
D 8
	fs = *fsp;	/* save info locally; it is static from getfsent() */
E 8
I 8
	fs = allocfsent(fs);
E 8
	umountall();
D 8
	if (strcmp(fs.fs_file, "/") == 0)
E 8
I 8
	if (strcmp(fs->fs_file, "/") == 0) {
		freefsent(fs);
E 8
		return;
D 4
	if (strcmp(fs.fs_type, FSTAB_RW) &&
	    strcmp(fs.fs_type, FSTAB_RO))
E 4
I 4
D 8
	if (strcmp(fs.fs_type, FSTAB_RW) && strcmp(fs.fs_type, FSTAB_RO))
E 8
I 8
	}
	if (strcmp(fs->fs_type, FSTAB_RW) &&
	    strcmp(fs->fs_type, FSTAB_RO) &&
	    strcmp(fs->fs_type, FSTAB_RQ)) {
		freefsent(fs);
E 8
E 4
		return;
D 4
	if (umountfs(fs.fs_spec) < 0)
		fprintf(stdout, "Unmount of special file %s FAILED\n", fs.fs_spec);
	else
		fprintf(stdout, "Unmounted special file %s\n", fs.fs_spec);
	fflush(stdout);
E 4
I 4
D 8
	if (umountfs(fs.fs_spec) < 0) {
		perror(fs.fs_spec);
		return;
E 8
	}
I 8
	if (umountfs(fs->fs_spec) < 0)
		perror(fs->fs_spec);
	freefsent(fs);
E 8
E 4
}
E 3

I 8
struct fstab *
allocfsent(fs)
	register struct fstab *fs;
{
	register struct fstab *new;
	register char *cp;
	char *malloc();

	new = (struct fstab *)malloc(sizeof (*fs));
	cp = malloc(strlen(fs->fs_file) + 1);
	strcpy(cp, fs->fs_file);
	new->fs_file = cp;
	cp = malloc(strlen(fs->fs_type) + 1);
	strcpy(cp, fs->fs_type);
	new->fs_type = cp;
	cp = malloc(strlen(fs->fs_spec) + 1);
	strcpy(cp, fs->fs_spec);
	new->fs_spec = cp;
	new->fs_passno = fs->fs_passno;
	new->fs_freq = fs->fs_freq;
	return (new);
}

freefsent(fs)
	register struct fstab *fs;
{

	if (fs->fs_file)
		free(fs->fs_file);
	if (fs->fs_spec)
		free(fs->fs_spec);
	if (fs->fs_type)
		free(fs->fs_type);
	free((char *)fs);
}

E 8
D 4
int umountfs(name)
	char	*name;
E 4
I 4
struct	mtab zeromtab;

umountfs(name)
	char *name;
E 4
{
D 4
	register	char	*p1, *p2;
	register	struct	mtab	*mp;
	int	mf;
E 4
I 4
	register char *p1, *p2;
	register struct	mtab *mp;
	int mf;
I 8
	struct fstab *fs;
E 8
E 4

I 8
	fs = getfsfile(name);
	if (fs != NULL)
		name = fs->fs_spec;
E 8
D 5
	if (umount(name) < 0) {
E 5
I 5
D 7
	if (unmount(name) < 0) {
E 7
I 7
	if (umount(name) < 0) {
E 7
E 5
D 3
		perror("umount");
		return(1);
E 3
I 3
D 4
		return(-1);
E 4
I 4
		perror(name);
		return (0);
E 4
E 3
	}
D 4
	p1 = name;
	while(*p1++)
		;
	p1--;
	while(*--p1 == '/')
		*p1 = '\0';
	while(p1 > name && *--p1 != '/')
		;
	if(*p1 == '/')
		p1++;
	name = p1;
E 4
I 4
	if (vflag)
		fprintf(stderr, "%s: Unmounted\n", name);
	while ((p1 = rindex(name, '/')) && p1[1] == 0)
		*p1 = 0;
	if (p1)
		name = p1 + 1;
E 4
	for (mp = mtab; mp < &mtab[NMOUNT]; mp++) {
D 4
		p1 = name;
		p2 = &mp->spec[0];
		while (*p1++ == *p2)
			if (*p2++ == 0) {
				for (p1 = mp->file; p1 < &mp->file[NAMSIZ*2];)
					*p1++ = 0;
				mp = &mtab[NMOUNT];
				while ((--mp)->file[0] == 0);
				mf = creat("/etc/mtab", 0644);
				write(mf, (char *)mtab, (mp-mtab+1)*2*NAMSIZ);
				return(0);
			}
E 4
I 4
D 8
		if (strncmp(mp->spec, name, sizeof (mp->spec)))
E 8
I 8
		if (strncmp(mp->m_dname, name, sizeof (mp->m_dname)))
E 8
			continue;
		*mp = zeromtab;
		for (mp = &mtab[NMOUNT]; mp >= mtab; mp--)
D 8
			if (mp->file[0])
E 8
I 8
			if (mp->m_path[0])
E 8
				break;
		mp++;
		mf = creat("/etc/mtab", 0644);
		write(mf, (char *)mtab, (mp-mtab) * sizeof (struct mtab));
		return (1);
E 4
	}
D 4
	printf("%s not in mount table\n", name);
	return(1);
E 4
I 4
	fprintf(stderr, "%s: Not mounted\n", name);
	return (0);
E 4
}
E 1
