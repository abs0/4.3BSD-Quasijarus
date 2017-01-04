h19091
s 00005/00001/00192
d D 5.2 85/11/21 18:22:25 karels 13 12
c "mount foo" should skip xx'd entries, mount in same manner as "mount -a"
e
s 00014/00002/00179
d D 5.1 85/05/28 15:00:00 dist 12 11
c Add copyright
e
s 00019/00001/00162
d D 4.11 84/07/05 20:06:44 sam 11 10
c add errno interpretation code 
e
s 00068/00044/00095
d D 4.10 83/05/28 13:08:04 sam 10 9
c lots of cleanups; use <mtab.h>; handle quotas more cleanly; add 
c type field to mtab so we can see read-only and quotas
e
s 00002/00001/00137
d D 4.9 83/05/25 23:02:29 sam 9 8
c quotas
e
s 00005/00003/00133
d D 4.8 83/02/09 14:58:32 sam 8 7
c braindamage
e
s 00002/00004/00134
d D 4.7 82/03/31 12:04:15 root 7 6
c fix -r option and arg count to a real diagnostic
e
s 00011/00003/00127
d D 4.6 81/11/25 14:46:21 root 6 5
c implement -r
e
s 00071/00080/00059
d D 4.5 81/10/03 16:07:04 root 5 4
c add -f and -v
e
s 00004/00002/00135
d D 4.4 81/07/12 16:34:52 root 4 3
c mount -f makes a mount table entry
e
s 00043/00021/00094
d D 4.3 80/10/15 23:48:57 bill 3 2
c new routines
e
s 00009/00015/00106
d D 4.2 80/10/13 17:03:08 bill 2 1
c Adding calls to fstab routines
e
s 00121/00000/00000
d D 4.1 80/10/01 17:27:32 bill 1 0
c date and time created 80/10/01 17:27:32 by bill
e
u
U
t
T
I 12
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 12
I 8
#ifndef lint
E 8
I 1
D 12
static char *sccsid = "%W% (Berkeley) %G%";
D 8
#include <stdio.h>
#include <fstab.h>
E 8
I 8
#endif
E 12
I 12
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 12
E 8

/*
D 2
 *	Mount file systems.
 *
 *	mount -a	Mount all file systems, as determined from the
 *			file /etc/fstab.
 *	If the name entry in /etc/fstab is "/", don't mount.
 *	If the read only entry in /etc/fstab is "ro", mount read only
 *	The special file names in /etc/fstab are the block devices;
 *		this is what we want to mount.
 *	Tries to mount all of the files in /etc/fstab.
 *	
 *	mount special name	Mount special on name
 *	mount special name -r	Mount special on name, read/write
E 2
I 2
 * mount
E 2
 */
I 10
#include <sys/param.h>

E 10
I 8
#include <stdio.h>
#include <fstab.h>
I 10
#include <mtab.h>
I 11
#include <errno.h>
E 11
E 10
E 8

D 5
int	mountall;
E 5
D 10
#define	NMOUNT	16
#define	NAMSIZ	32
E 10
I 10
#define	DNMAX	(sizeof (mtab[0].m_dname) - 1)
#define	PNMAX	(sizeof (mtab[0].m_path) - 1)
E 10

D 10
struct mtab {
	char	file[NAMSIZ];
	char	spec[NAMSIZ];
} mtab[NMOUNT];
E 10
I 10
struct	mtab mtab[NMOUNT];
E 10

I 5
int	all;
E 5
I 3
int	ro;
I 4
int	fake;
I 5
int	verbose;
I 10
char	*index(), *rindex();
E 10
I 6

E 6
E 5
E 4
E 3
main(argc, argv)
D 6
char **argv;
E 6
I 6
	int argc;
	char **argv;
E 6
{
D 3
	register int ro;
E 3
	register struct mtab *mp;
	register char *np;
	int mf;
I 10
	char *type = FSTAB_RW;
E 10

D 5
	mountall = 0;
E 5
	mf = open("/etc/mtab", 0);
D 10
	read(mf, (char *)mtab, NMOUNT*2*NAMSIZ);
	if (argc==1) {
E 10
I 10
	read(mf, (char *)mtab, sizeof (mtab));
	if (argc == 1) {
E 10
		for (mp = mtab; mp < &mtab[NMOUNT]; mp++)
D 10
			if (mp->file[0])
				printf("%s on %s\n", mp->spec, mp->file);
E 10
I 10
			if (mp->m_path[0] != '\0')
				prmtab(mp);
E 10
		exit(0);
	}
D 5

	if (argc == 2){
		if (strcmp(argv[1], "-a") == 0)
			mountall++;
		else {
D 3
			fprintf(stderr,"arg count\n");
E 3
I 3
			fprintf(stdout,"arg count\n");
E 3
			exit(1);
E 5
I 5
top:
	if (argc > 1) {
D 6
		if (strcmp(argv[1], "-a") == 0) {
E 6
I 6
		if (!strcmp(argv[1], "-a")) {
E 6
			all++;
			argc--, argv++;
			goto top;
E 5
		}
I 6
		if (!strcmp(argv[1], "-r")) {
D 10
			ro++;
E 10
I 10
			type = FSTAB_RO;
E 10
			argc--, argv++;
			goto top;
		}
E 6
D 5
	}
I 4
	if (!strcmp(argv[1], "-f"))
		fake++, argc--, argv++;
E 4

	if (!mountall){
		ro = 0;
		if(argc > 3)
			ro++;
D 3
		if (mountfs(argv[1], argv[2], ro))
E 3
I 3
		if (mountfs(argv[1], argv[2], ro)){
			perror("mount");
E 3
			exit(1);
E 5
I 5
		if (!strcmp(argv[1], "-f")) {
			fake++;
			argc--, argv++;
			goto top;
E 5
D 3
	} else {
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
E 3
		}
D 3
		while (!feof(fs_file)){
I 2
			int ro;
E 2
			fscanf(fs_file, FSTABFMT, FSTABARG(&fs));
			if (strcmp(fs.fs_file, "/") == 0)
E 3
I 3
D 5
	} else {
E 5
I 5
		if (!strcmp(argv[1], "-v")) {
			verbose++;
			argc--, argv++;
			goto top;
		}
	}
	if (all) {
E 5
D 6
		struct	fstab	*fsp;
E 6
I 6
		struct fstab *fsp;

E 6
I 5
		if (argc > 1)
			goto argcnt;
E 5
		close(2); dup(1);
		if (setfsent() == 0)
			perror(FSTAB), exit(1);
D 5
		while ( (fsp = getfsent()) != 0){
E 5
I 5
D 10
		while ( (fsp = getfsent()) != 0) {
E 10
I 10
		while ((fsp = getfsent()) != 0) {
E 10
E 5
			if (strcmp(fsp->fs_file, "/") == 0)
E 3
				continue;
I 2
D 3
			ro = !strcmp(fs.fs_type, "ro");
			if (ro==0 && strcmp(fs.fs_type, "rw"))
E 3
I 3
D 10
			ro = !strcmp(fsp->fs_type, FSTAB_RO);
D 9
			if (ro==0 && strcmp(fsp->fs_type, FSTAB_RW))
E 9
I 9
			if (ro==0 && strcmp(fsp->fs_type, FSTAB_RW) &&
E 10
I 10
			if (strcmp(fsp->fs_type, FSTAB_RO) &&
			    strcmp(fsp->fs_type, FSTAB_RW) &&
E 10
			    strcmp(fsp->fs_type, FSTAB_RQ))
E 9
E 3
				continue;
E 2
D 3
			fprintf(stderr, "Mounting %s on %s %s",
				fs.fs_file, fs.fs_spec,
D 2
				FSRO(&fs) ? "(Read Only)\n" : "\n");
			mountfs(fs.fs_spec, fs.fs_file, FSRO(&fs));
E 2
I 2
				ro ? "(Read Only)\n" : "\n");
			mountfs(fs.fs_spec, fs.fs_file, ro);
E 3
I 3
D 5
			if (mountfs(fsp->fs_spec, fsp->fs_file, ro))
				failed(fsp);
			else
				succeed(fsp);
E 5
I 5
D 10
			mountfs(fsp->fs_spec, fsp->fs_file, ro);
E 10
I 10
			mountfs(fsp->fs_spec, fsp->fs_file, fsp->fs_type);
E 10
E 5
E 3
E 2
		}
D 3
		fclose(fs_file);
E 3
I 3
D 5
		endfsent();
E 5
I 5
		exit(0);
E 5
E 3
	}
I 10
	if (argc == 2) {
		struct fstab *fs;

		if (setfsent() == 0)
			perror(FSTAB), exit(1);
		fs = getfsfile(argv[1]);
		if (fs == NULL)
			goto argcnt;
D 13
		mountfs(fs->fs_spec, fs->fs_file, type);
E 13
I 13
		if (strcmp(fs->fs_type, FSTAB_RO) &&
		    strcmp(fs->fs_type, FSTAB_RW) &&
		    strcmp(fs->fs_type, FSTAB_RQ))
			goto argcnt;
		mountfs(fs->fs_spec, fs->fs_file, fs->fs_type);
E 13
		exit(0);
	}
E 10
D 5
	exit(0);
E 5
I 5
D 8
	if (argc < 2 || argc > 3) {
E 8
I 8
	if (argc != 3) {
E 8
argcnt:
D 7
		printf("arg count\n");
E 7
I 7
		fprintf(stderr,
D 10
	    "usage: mount [ -a ] [ -r ] [ -f ] [ -v ] [ special dir ]\n");
E 10
I 10
    "usage: mount [ -a ] [ -r ] [ -f ] [ -v ] [ special dir ] [ dir ]\n");
E 10
E 7
		exit(1);
	}
D 7
	ro = 0;
	if(argc > 3)
		ro++;
E 7
D 10
	mountfs(argv[1], argv[2], ro);
E 10
I 10
	mountfs(argv[1], argv[2], type);
E 10
E 5
}
I 3
D 5
failed(fsp)
	register	struct	fstab *fsp;
{
	extern int errno;
	extern char *sys_errlist[];
	int err = errno;
	printf("Attempt to mount ");
	location(fsp);
	printf("FAILED: %s\n", sys_errlist[err]);
}
succeed(fsp)
	register	struct	fstab *fsp;
{
	printf("Mounted ");
	location(fsp);
	printf("\n");
}
location(fsp)
	register	struct	fstab *fsp;
{
	extern	int	ro;
	printf("%s on %s %s ",
		fsp->fs_file, fsp->fs_spec,
		ro ? "(Read Only)" : "");
}
E 5
E 3

D 10
mountfs(spec, name, ro)
D 5
	char	*spec, *name;
	int	ro;
E 5
I 5
	char *spec, *name;
E 10
I 10
prmtab(mp)
	register struct mtab *mp;
E 10
E 5
{
I 10

	printf("%s on %s", mp->m_dname, mp->m_path);
	if (strcmp(mp->m_type, FSTAB_RO) == 0)
		printf("\t(read-only)");
	if (strcmp(mp->m_type, FSTAB_RQ) == 0)
		printf("\t(with quotas)");
	putchar('\n');
}

mountfs(spec, name, type)
	char *spec, *name, *type;
{
E 10
D 5
	register	char	*np;
	register	struct	mtab	*mp;
	int	mf;
E 5
I 5
	register char *np;
	register struct mtab *mp;
	int mf;
E 5

D 4
	if(mount(spec, name, ro) < 0) {
E 4
I 4
D 5
	if(fake==0 && mount(spec, name, ro) < 0)
E 4
D 3
		perror("mount");
E 3
		return(1);
E 5
I 5
D 10
	if (fake==0) {
		if (mount(spec, name, ro) < 0) {
E 10
I 10
	if (!fake) {
		if (mount(spec, name, strcmp(type, FSTAB_RO) == 0) < 0) {
I 11
			extern int errno;
			char *cp;

E 11
E 10
			fprintf(stderr, "%s on ", spec);
D 11
			perror(name);
E 11
I 11
			switch (errno) {

			case EMFILE:
				cp = "Mount table full";
				break;

			case EINVAL:
				cp = "Bogus super block";
				break;

			default:
				perror(name);
				return;
			}
			fprintf(stderr, "%s: %s\n", name, cp);
E 11
			return;
		}
I 10
		/* we don't do quotas.... */
		if (strcmp(type, FSTAB_RQ) == 0)
			type = FSTAB_RW;
E 10
	}
D 10
	if (verbose)
		fprintf(stderr, "%s on %s%s\n", spec, name,
		    ro ? " read only" : "");
E 5
D 4
	}
E 4
	np = spec;
D 5
	while(*np++)
E 5
I 5
	while (*np++)
E 5
		;
	np--;
E 10
I 10
	np = index(spec, '\0');
E 10
D 5
	while(*--np == '/')
E 5
I 5
	while (*--np == '/')
E 5
		*np = '\0';
D 5
	while(np > spec && *--np != '/')
E 5
I 5
D 10
	while (np > spec && *--np != '/')
E 5
		;
D 5
	if(*np == '/')
E 5
I 5
	if (*np == '/')
E 5
		np++;
	spec = np;
E 10
I 10
	np = rindex(spec, '/');
	if (np) {
		*np++ = '\0';
		spec = np;
	}
E 10
D 5
	for (mp = mtab; mp < &mtab[NMOUNT]; mp++) {
		if (mp->file[0] == 0) {
			for (np = mp->spec; np < &mp->spec[NAMSIZ-1];)
				if ((*np++ = *spec++) == 0)
					spec--;
			for (np = mp->file; np < &mp->file[NAMSIZ-1];)
				if ((*np++ = *name++) == 0)
					name--;
			mp = &mtab[NMOUNT];
			while ((--mp)->file[0] == 0);
			mf = creat("/etc/mtab", 0644);
			write(mf, (char *)mtab, (mp-mtab+1)*2*NAMSIZ);
I 2
			return(0);
E 2
		}
	}
	return(0);
E 5
I 5
	for (mp = mtab; mp < &mtab[NMOUNT]; mp++)
D 10
		if (!strcmp(mp->spec, spec))
E 10
I 10
		if (strcmp(mp->m_dname, spec) == 0)
E 10
			goto replace;
	for (mp = mtab; mp < &mtab[NMOUNT]; mp++)
D 10
		if (mp->file[0] == 0)
E 10
I 10
		if (mp->m_path[0] == '\0')
E 10
			goto replace;
	return;
replace:
D 10
	for (np = mp->spec; np < &mp->spec[NAMSIZ-1];)
		if ((*np++ = *spec++) == 0)
			spec--;
	for (np = mp->file; np < &mp->file[NAMSIZ-1];)
		if ((*np++ = *name++) == 0)
			name--;
	mp = &mtab[NMOUNT];
	while ((--mp)->file[0] == 0);
E 10
I 10
	strncpy(mp->m_dname, spec, DNMAX);
	mp->m_dname[DNMAX] = '\0';
	strncpy(mp->m_path, name, PNMAX);
	mp->m_path[PNMAX] = '\0';
	strcpy(mp->m_type, type);
	if (verbose)
		prmtab(mp);
	mp = mtab + NMOUNT - 1;
	while (mp > mtab && mp->m_path[0] == '\0')
		--mp;
E 10
	mf = creat("/etc/mtab", 0644);
D 10
	write(mf, (char *)mtab, (mp-mtab+1)*2*NAMSIZ);
E 10
I 10
	write(mf, (char *)mtab, (mp - mtab + 1) * sizeof (struct mtab));
E 10
	close(mf);
	return;
E 5
}
E 1
