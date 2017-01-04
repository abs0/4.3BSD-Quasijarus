h19123
s 00010/00005/00201
d D 5.4 88/06/18 14:34:43 bostic 8 7
c install approved copyright notice
e
s 00010/00004/00196
d D 5.3 88/05/20 12:15:30 bostic 7 6
c add Berkeley specific header
e
s 00001/00001/00199
d D 5.2 85/08/08 17:20:15 mckusick 6 5
c be more persistent in looking for mount entry
e
s 00014/00002/00186
d D 5.1 85/05/30 19:55:23 mckusick 5 4
c Add copyright
e
s 00109/00024/00079
d D 4.4 83/05/28 14:20:23 sam 4 3
c reflect status in mtab
e
s 00014/00006/00089
d D 4.3 83/05/25 16:05:57 mckusick 3 2
c allow fs names or special devices as arguments
e
s 00043/00024/00052
d D 4.2 83/05/22 18:20:42 mckusick 2 1
c break out into "quotaon" and "quotaoff" (still same binary)
e
s 00076/00000/00000
d D 4.1 83/05/22 16:20:50 mckusick 1 0
c date and time created 83/05/22 16:20:50 by mckusick
e
u
U
t
T
I 5
/*
 * Copyright (c) 1980 Regents of the University of California.
D 7
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 7
I 7
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 8
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 8
I 8
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
E 8
E 7
 */

E 5
I 1
#ifndef lint
D 2
static char sccsid[] = "%W% (Melbourne) %G%";
E 2
I 2
D 5
static char sccsid[] = "%W% (Berkeley, Melbourne) %G%";
E 2
#endif
E 5
I 5
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
D 7
#endif not lint
E 7
I 7
#endif /* not lint */
E 7

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 7
#endif not lint
E 7
I 7
#endif /* not lint */
E 7
E 5
I 4

E 4
/*
D 2
 * Turn quota on/off for a filesystem
E 2
I 2
 * Turn quota on/off for a filesystem.
D 4
 *
 * NEED TO REFLECT CURRENT STATUS IN MTAB.
E 4
E 2
 */
#include <sys/param.h>
I 4
#include <sys/file.h>
E 4
D 2

E 2
#include <stdio.h>
#include <fstab.h>
I 4
#include <mtab.h>
E 4

I 4
struct	mtab mtab[NMOUNT];

E 4
int	vflag;		/* verbose */
int	aflag;		/* all file systems */
I 3
int	done;
I 4
int	mf;
E 4
E 3

I 2
D 4
char *qfname = "quotas";
char quotafile[MAXPATHLEN + 1];
E 4
I 4
char	*qfname = "quotas";
char	quotafile[MAXPATHLEN + 1];
char	*index(), *rindex();
E 4

E 2
main(argc, argv)
I 2
	int argc;
E 2
	char **argv;
{
D 2
	register i, on;
E 2
	register struct fstab *fs;
I 2
	char *whoami, *rindex();
D 3
	int offmode = 0, errs = 0;
E 3
I 3
	int offmode = 0, errs = 0, i;
E 3
E 2

I 2
	whoami = rindex(*argv, '/') + 1;
	if (whoami == (char *)1)
		whoami = *argv;
	if (strcmp(whoami, "quotaoff") == 0)
		offmode++;
	else if (strcmp(whoami, "quotaon") != 0) {
		fprintf(stderr, "Name must be quotaon or quotaoff not %s\n",
			whoami);
		exit(1);
	}
E 2
again:
	argc--, argv++;
	if (argc > 0 && strcmp(*argv, "-v") == 0) {
		vflag++;
		goto again;
	}
	if (argc > 0 && strcmp(*argv, "-a") == 0) {
		aflag++;
		goto again;
	}
D 2
	if (argc <= 0 || strcmp(*argv, "on") && strcmp(*argv, "off")) {
		fprintf(stderr,
			"usage: setquota [-v] [-a] on | off [filesys...]\n");
E 2
I 2
	if (argc <= 0 && !aflag) {
		fprintf(stderr, "Usage:\n\t%s [-v] -a\n\t%s [-v] filesys ...\n",
			whoami, whoami);
E 2
		exit(1);
	}
I 4
	mf = open("/etc/mtab", O_RDONLY);
	if (mf < 0) {
		perror("/etc/mtab");
		exit(1);
	}
	(void) read(mf, (char *)mtab, sizeof (mtab));
	close(mf);
E 4
D 2
	on = strcmp(*argv, "on") == 0;
	argc--, argv++;
E 2
	setfsent();
	while ((fs = getfsent()) != NULL) {
D 2
		if (fs->fs_quotafile == 0 || *fs->fs_quotafile == '\0')
E 2
I 2
D 3
		if (fs->fs_type == 0)
E 3
I 3
		if (aflag &&
		    (fs->fs_type == 0 || strcmp(fs->fs_type, "rq") != 0))
E 3
E 2
			continue;
D 2
		if (fs->fs_type == 0 || strcmp(fs->fs_type, "rw"))
E 2
I 2
D 3
		if (aflag && strcmp(fs->fs_type, "rq") != 0)
E 3
I 3
		if (!aflag &&
		    !(oneof(fs->fs_file, argv, argc) ||
		      oneof(fs->fs_spec, argv, argc)))
E 3
E 2
			continue;
D 3
		if (!aflag && !oneof(fs->fs_file, argv, argc))
			continue;
E 3
D 2
		if (vflag)
			printf("%s: quotas turned %s\n", fs->fs_file,
				on ? "on" : "off");
		if (on) {
			char quotafile[MAXPATHLEN + 1];

			(void) sprintf(quotafile, "%s/%s", fs->fs_file,
			   fs->fs_quotafile);
			i = setquota(fs->fs_spec, quotafile);
		} else
			i = setquota(fs->fs_spec, NULL);
		if (i < 0) {
E 2
I 2
D 4
		if (offmode) {
			if (setquota(fs->fs_spec, NULL) < 0) {
				fprintf(stderr, "setquota: ");
				perror(fs->fs_spec);
				errs++;
				continue;
			}
			if (vflag)
				printf("%s: quotas turned off\n", fs->fs_file);
			continue;
		}
		(void) sprintf(quotafile, "%s/%s", fs->fs_file, qfname);
		if (setquota(fs->fs_spec, quotafile) < 0) {
E 2
			fprintf(stderr, "setquota: ");
			perror(fs->fs_spec);
I 2
			errs++;
			continue;
E 2
		}
I 2
		if (vflag)
			printf("%s: quotas turned on\n", fs->fs_file);
E 4
I 4
		errs += quotaonoff(fs, offmode);
E 4
E 2
	}
	endfsent();
I 3
	for (i = 0; i < argc; i++)
		if ((done & (1 << i)) == 0)
			fprintf(stderr, "%s not found in /etc/fstab\n",
				argv[i]);
E 3
D 2
	exit(i < 0);
E 2
I 2
	exit(errs);
E 2
}

I 4
quotaonoff(fs, offmode)
	register struct fstab *fs;
	int offmode;
{

	if (strcmp(fs->fs_file, "/") && readonly(fs))
		return (1);
	if (offmode) {
		if (setquota(fs->fs_spec, NULL) < 0)
			goto bad;
		if (vflag)
			printf("%s: quotas turned off\n", fs->fs_file);
		changemtab(fs, FSTAB_RW);
		return (0);
	}
	(void) sprintf(quotafile, "%s/%s", fs->fs_file, qfname);
	if (setquota(fs->fs_spec, quotafile) < 0)
		goto bad;
	if (vflag)
		printf("%s: quotas turned on\n", fs->fs_file);
	changemtab(fs, FSTAB_RQ);
	return (0);
bad:
	fprintf(stderr, "setquota: ");
	perror(fs->fs_spec);
	return (1);
}

E 4
oneof(target, list, n)
	char *target, *list[];
	register int n;
{
	register int i;

	for (i = 0; i < n; i++)
D 3
		if (strcmp(target, list[i]) == 0)
E 3
I 3
		if (strcmp(target, list[i]) == 0) {
			done |= 1 << i;
E 3
			return (1);
I 3
		}
E 3
	return (0);
I 4
}

changemtab(fs, type)
	register struct fstab *fs;
	char *type;
{
	register struct mtab *mp;
	register char *cp;

	cp = index(fs->fs_spec, '\0');
	while (*--cp == '/')
		*cp = '\0';
	cp = rindex(fs->fs_spec, '/');
	if (cp)
		cp++;
	else
		cp = fs->fs_spec;
	for (mp = mtab; mp < &mtab[NMOUNT]; mp++)
		if (strcmp(mp->m_dname, cp) == 0)
			goto replace;
	for (mp = mtab; mp < &mtab[NMOUNT]; mp++)
		if (mp->m_path[0] == '\0')
			goto replace;
	return;
replace:
	strcpy(mp->m_type, type);
	mp = mtab + NMOUNT - 1;
	while (mp > mtab && mp->m_path[0] == '\0')
		--mp;
	mf = creat("/etc/mtab", 0644);
	(void) write(mf, (char *)mtab, (mp - mtab + 1) * sizeof (struct mtab));
	close(mf);
}

/*
 * Verify file system is mounted and not readonly.
 */
readonly(fs)
	register struct fstab *fs;
{
	register struct mtab *mp;
	register char *cp;

	cp = index(fs->fs_spec, '\0');
	while (*--cp == '/')
		*cp = '\0';
	cp = rindex(fs->fs_spec, '/');
	if (cp)
		cp++;
	else
		cp = fs->fs_spec;
	for (mp = mtab; mp < mtab + NMOUNT; mp++) {
		if (mp->m_path[0] == '\0')
D 6
			break;
E 6
I 6
			continue;
E 6
		if (strcmp(cp, mp->m_dname) == 0) {
			if (strcmp(mp->m_type, FSTAB_RO) == 0) {
				printf("%s: mounted read-only\n", fs->fs_file);
				return (1);
			}
			return (0);
		}
	}
	printf("%s: not mounted\n", fs->fs_file);
	return (1);
E 4
}
E 1
