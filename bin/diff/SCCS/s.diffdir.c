h50425
s 00001/00001/00418
d D 4.12 03/07/10 23:03:13 msokolov 13 12
c add -a option to disable the check for binary files
c add -J debug option to report the "jackpot"
e
s 00001/00001/00418
d D 4.11 87/10/22 10:04:25 bostic 12 11
c ANSI C; sprintf now returns an int.
e
s 00012/00004/00407
d D 4.10 86/12/04 16:12:58 bostic 11 9
c bug report 4.3BSD/bin/34.  Not that I think I fixed 
c the problem, but I don't feel like spending the rest of my month 
c trying to figure out what this code really thinks that it's doing.
e
s 00012/00004/00407
d R 4.10 86/12/04 16:10:58 bostic 10 9
c bug report 4.3BSD/bin/34; not that I think I fixed the
e
s 00004/00002/00407
d D 4.9 84/08/28 16:38:15 ralph 9 8
c don't close files that haven't been opened.
e
s 00006/00002/00403
d D 4.8 84/02/10 16:20:36 ralph 8 7
c exclude only . and ..
e
s 00016/00013/00389
d D 4.7 83/07/01 04:00:15 sam 7 6
c from wnj; print proper file names
e
s 00077/00079/00325
d D 4.6 82/05/05 17:33:47 sam 6 5
c use opendir, readdir, closedir
e
s 00001/00001/00403
d D 4.5 81/02/28 20:59:44 wnj 5 4
c portability
e
s 00004/00004/00400
d D 4.4 81/02/28 20:59:11 wnj 4 3
c portability bugs
e
s 00003/00003/00401
d D 4.3 80/12/17 19:07:56 root 3 2
c fixes to -l option
e
s 00008/00000/00396
d D 4.2 80/10/19 13:29:45 bill 2 1
c !N_BADMAG --> binary
e
s 00396/00000/00000
d D 4.1 80/10/09 22:46:42 bill 1 0
c date and time created 80/10/09 22:46:42 by bill
e
u
U
t
T
I 1
D 4
static	char sccsid[] = "%Z%%M% %I% %G%";
E 4
I 4
D 5
static	char sccsid[] = "@(#)diffdir.c 4.4 1/25/81";
E 5
I 5
D 7
static	char *sccsid = "%W% (Berkeley) %E%";
E 7
I 7
static	char *sccsid = "%W% (Berkeley) %G%";
E 7
E 5
E 4

#include "diff.h"
/*
 * diff - directory comparison
 */
#define	d_flags	d_ino

#define	ONLY	1		/* Only in this directory */
#define	SAME	2		/* Both places and same */
#define	DIFFER	4		/* Both places and different */
#define	DIRECT	8		/* Directory */

D 6
struct	direct *setupdir();
E 6
I 6
struct dir {
	u_long	d_ino;
	short	d_reclen;
	short	d_namlen;
	char	*d_entry;
};

struct	dir *setupdir();
E 6
int	header;
I 11
static int	dirstatus;		/* exit status from diffdir */
extern int	status;
E 11
char	title[2*BUFSIZ], *etitle;

diffdir(argv)
	char **argv;
{
D 6
	register struct direct *d1, *d2;
	struct direct *dir1, *dir2;
E 6
I 6
	register struct dir *d1, *d2;
	struct dir *dir1, *dir2;
E 6
	register int i;
	int cmp;

	if (opt == D_IFDEF) {
		fprintf(stderr, "diff: can't specify -I with directories\n");
		done();
	}
	if (opt == D_EDIT && (sflag || lflag))
		fprintf(stderr,
		    "diff: warning: shouldn't give -s or -l with -e\n");
	title[0] = 0;
	strcpy(title, "diff ");
	for (i = 1; diffargv[i+2]; i++) {
		if (!strcmp(diffargv[i], "-"))
			continue;	/* was -S, dont look silly */
		strcat(title, diffargv[i]);
		strcat(title, " ");
	}
	for (etitle = title; *etitle; etitle++)
		;
	setfile(&file1, &efile1, file1);
	setfile(&file2, &efile2, file2);
	argv[0] = file1;
	argv[1] = file2;
	dir1 = setupdir(file1);
	dir2 = setupdir(file2);
	d1 = dir1; d2 = dir2;
D 6
	while (d1->d_name[0] != 0 || d2->d_name[0] != 0) {
		if (d1->d_name[0] && useless(d1->d_name)) {
E 6
I 6
	while (d1->d_entry != 0 || d2->d_entry != 0) {
		if (d1->d_entry && useless(d1->d_entry)) {
E 6
			d1++;
			continue;
		}
D 6
		if (d2->d_name[0] && useless(d2->d_name)) {
E 6
I 6
		if (d2->d_entry && useless(d2->d_entry)) {
E 6
			d2++;
			continue;
		}
D 6
		if (d1->d_name[0] == 0)
E 6
I 6
		if (d1->d_entry == 0)
E 6
			cmp = 1;
D 6
		else if (d2->d_name[0] == 0)
E 6
I 6
		else if (d2->d_entry == 0)
E 6
			cmp = -1;
		else
D 6
			cmp = strncmp(d1->d_name, d2->d_name, DIRSIZ);
E 6
I 6
			cmp = strcmp(d1->d_entry, d2->d_entry);
E 6
		if (cmp < 0) {
			if (lflag)
				d1->d_flags |= ONLY;
D 6
			else if (opt == 0 || opt == 2) {
E 6
I 6
			else if (opt == 0 || opt == 2)
E 6
				only(d1, 1);
D 6
				printf(": %.*s\n", DIRSIZ, d1->d_name);
			}
E 6
			d1++;
I 11
			dirstatus |= 1;
E 11
		} else if (cmp == 0) {
			compare(d1);
			d1++;
			d2++;
		} else {
			if (lflag)
				d2->d_flags |= ONLY;
D 6
			else if (opt == 0 || opt == 2) {
E 6
I 6
			else if (opt == 0 || opt == 2)
E 6
				only(d2, 2);
D 6
				printf(": %.*s\n", DIRSIZ, d2->d_name);
			}
E 6
			d2++;
I 11
			dirstatus |= 1;
E 11
		}
	}
	if (lflag) {
D 7
		scanpr(dir1, ONLY, "Only in %.*s", file1, efile1);
		scanpr(dir2, ONLY, "Only in %.*s", file2, efile2);
		scanpr(dir1, SAME, "Common identical files", 0, 0);
		scanpr(dir1, DIFFER, "Binary files which differ", 0, 0);
		scanpr(dir1, DIRECT, "Common subdirectories", 0, 0);
E 7
I 7
		scanpr(dir1, ONLY, "Only in %.*s", file1, efile1, 0, 0);
		scanpr(dir2, ONLY, "Only in %.*s", file2, efile2, 0, 0);
		scanpr(dir1, SAME, "Common identical files in %.*s and %.*s",
		    file1, efile1, file2, efile2);
		scanpr(dir1, DIFFER, "Binary files which differ in %.*s and %.*s",
		    file1, efile1, file2, efile2);
		scanpr(dir1, DIRECT, "Common subdirectories of %.*s and %.*s",
		    file1, efile1, file2, efile2);
E 7
	}
	if (rflag) {
		if (header && lflag)
			printf("\f");
D 6
		for (d1 = dir1; d1->d_name[0]; d1++)  {
E 6
I 6
		for (d1 = dir1; d1->d_entry; d1++)  {
E 6
			if ((d1->d_flags & DIRECT) == 0)
				continue;
D 6
			strncpy(efile1, d1->d_name, DIRSIZ);
			strncpy(efile2, d1->d_name, DIRSIZ);
/*
			if (opt != D_EDIT) {
				*etitle = 0;
				printf("%s%s %s\n", title, file1, file2);
			}
*/
E 6
I 6
			strcpy(efile1, d1->d_entry);
			strcpy(efile2, d1->d_entry);
E 6
			calldiff(0);
		}
	}
I 11
	status = dirstatus;
E 11
}

setfile(fpp, epp, file)
	char **fpp, **epp;
	char *file;
{
	register char *cp;

	*fpp = malloc(BUFSIZ);
	if (*fpp == 0) {
		fprintf(stderr, "diff: ran out of memory\n");
		exit(1);
	}
	strcpy(*fpp, file);
	for (cp = *fpp; *cp; cp++)
		continue;
	*cp++ = '/';
	*epp = cp;
}

D 7
scanpr(dp, test, title, file, efile)
E 7
I 7
scanpr(dp, test, title, file1, efile1, file2, efile2)
E 7
D 6
	register struct direct *dp;
E 6
I 6
	register struct dir *dp;
E 6
	int test;
D 7
	char *title, *file, *efile;
E 7
I 7
	char *title, *file1, *efile1, *file2, *efile2;
E 7
{
	int titled = 0;

D 6
	for (; dp->d_name[0]; dp++)
		if (dp->d_flags & test) {
			if (titled == 0) {
				if (header == 0) {
					if (anychange)
						printf("\f");
					header = 1;
				} else
					printf("\n");
				printf(title, efile - file - 1, file);
				printf(":\n");
				titled = 1;
			}
			ptname(dp);
E 6
I 6
	for (; dp->d_entry; dp++) {
		if ((dp->d_flags & test) == 0)
			continue;
		if (titled == 0) {
D 7
			if (header == 0) {
				if (anychange)
					printf("\f");
E 7
I 7
			if (header == 0)
E 7
				header = 1;
D 7
			} else
E 7
I 7
			else
E 7
				printf("\n");
D 7
			printf(title, efile - file - 1, file);
E 7
I 7
			printf(title,
			    efile1 - file1 - 1, file1,
			    efile2 - file2 - 1, file2);
E 7
			printf(":\n");
			titled = 1;
E 6
		}
I 6
		printf("\t%s\n", dp->d_entry);
	}
E 6
}

only(dp, which)
D 6
	struct direct *dp;
E 6
I 6
	struct dir *dp;
E 6
	int which;
{
	char *file = which == 1 ? file1 : file2;
	char *efile = which == 1 ? efile1 : efile2;

D 6
	printf("Only in %.*s", efile - file - 1, file, DIRSIZ, dp->d_name);
E 6
I 6
	printf("Only in %.*s: %s\n", efile - file - 1, file, dp->d_entry);
I 11
	
E 11
E 6
}

D 6
ptname(dp)
	struct direct *dp;
{

	printf("\t%.*s\n", DIRSIZ, dp->d_name);
}

E 6
int	entcmp();

D 6
struct direct *
E 6
I 6
struct dir *
E 6
setupdir(cp)
	char *cp;
{
D 6
	struct stat stb;
	register struct direct *dp, *ep;
E 6
I 6
	register struct dir *dp = 0, *ep;
	register struct direct *rp;
	register int nitems, n;
	DIR *dirp;
E 6

D 6
	close(0);
	if (open(cp, 0) < 0) {
E 6
I 6
	dirp = opendir(cp);
	if (dirp == NULL) {
E 6
		fprintf(stderr, "diff: ");
		perror(cp);
		done();
	}
D 6
	fstat(0, &stb);
D 4
	dp = (struct direct *)malloc(stb.st_size + sizeof (struct direct));
E 4
I 4
	dp = (struct direct *)malloc((unsigned) stb.st_size + sizeof (struct direct));
E 6
I 6
	nitems = 0;
	dp = (struct dir *)malloc(sizeof (struct dir));
E 6
E 4
	if (dp == 0) {
		fprintf(stderr, "diff: ran out of memory\n");
		done();
	}
D 4
	if (read(0, (char *)dp, (short)stb.st_size) != (short)stb.st_size) {
E 4
I 4
D 6
	if (read(0, (char *)dp, (int)stb.st_size) != (int)stb.st_size) {
E 4
		fprintf(stderr, "diff: ");
		perror(cp);
		done();
	}
D 4
	qsort(dp, stb.st_size / sizeof (struct direct), 
E 4
I 4
	qsort(dp, (int) stb.st_size / sizeof (struct direct), 
E 4
	    sizeof (struct direct), entcmp);
	ep = &dp[stb.st_size / sizeof (struct direct)];
	ep->d_name[0] = 0;
	while (--ep >= dp && ep->d_ino == 0)
		ep->d_name[0] = 0;
	for (; ep >= dp; ep--)
E 6
I 6
	while (rp = readdir(dirp)) {
		ep = &dp[nitems++];
		ep->d_reclen = rp->d_reclen;
		ep->d_namlen = rp->d_namlen;
		ep->d_entry = 0;
E 6
		ep->d_flags = 0;
I 6
		if (ep->d_namlen > 0) {
			ep->d_entry = malloc(ep->d_namlen + 1);
			if (ep->d_entry == 0) {
				fprintf(stderr, "diff: out of memory\n");
				done();
			}
			strcpy(ep->d_entry, rp->d_name);
		}
		dp = (struct dir *)realloc((char *)dp,
			(nitems + 1) * sizeof (struct dir));
		if (dp == 0) {
			fprintf(stderr, "diff: ran out of memory\n");
			done();
		}
	}
	dp[nitems].d_entry = 0;		/* delimiter */
	closedir(dirp);
	qsort(dp, nitems, sizeof (struct dir), entcmp);
E 6
	return (dp);
}

entcmp(d1, d2)
D 6
	struct direct *d1, *d2;
E 6
I 6
	struct dir *d1, *d2;
E 6
{
D 6

	if (d1->d_ino == 0)
		return (1);
	if (d2->d_ino == 0)
		return (-1);
	return (strncmp(d1->d_name, d2->d_name, DIRSIZ));
E 6
I 6
	return (strcmp(d1->d_entry, d2->d_entry));
E 6
}

compare(dp)
D 6
	register struct direct *dp;
E 6
I 6
	register struct dir *dp;
E 6
{
	register int i, j;
	int f1, f2, fmt1, fmt2;
	struct stat stb1, stb2;
	int flag = 0;
	char buf1[BUFSIZ], buf2[BUFSIZ];

D 6
	strncpy(efile1, dp->d_name, DIRSIZ);
	strncpy(efile2, dp->d_name, DIRSIZ);
E 6
I 6
	strcpy(efile1, dp->d_entry);
	strcpy(efile2, dp->d_entry);
E 6
	f1 = open(file1, 0);
	if (f1 < 0) {
		perror(file1);
		return;
	}
	f2 = open(file2, 0);
	if (f2 < 0) {
		perror(file2);
		close(f1);
		return;
	}
	fstat(f1, &stb1); fstat(f2, &stb2);
	fmt1 = stb1.st_mode & S_IFMT;
	fmt2 = stb2.st_mode & S_IFMT;
	if (fmt1 != S_IFREG || fmt2 != S_IFREG) {
		if (fmt1 == fmt2) {
			if (fmt1 != S_IFDIR && stb1.st_rdev == stb2.st_rdev)
				goto same;
			if (fmt1 == S_IFDIR) {
				dp->d_flags = DIRECT;
				if (lflag || opt == D_EDIT)
					goto closem;
				printf("Common subdirectories: %s and %s\n",
				    file1, file2);
				goto closem;
			}
		}
		goto notsame;
	}
	if (stb1.st_size != stb2.st_size)
		goto notsame;
	for (;;) {
		i = read(f1, buf1, BUFSIZ);
		j = read(f2, buf2, BUFSIZ);
		if (i < 0 || j < 0 || i != j)
			goto notsame;
		if (i == 0 && j == 0)
			goto same;
		for (j = 0; j < i; j++)
			if (buf1[j] != buf2[j])
				goto notsame;
	}
same:
	if (sflag == 0)
		goto closem;
	if (lflag)
		dp->d_flags = SAME;
	else
		printf("Files %s and %s are identical\n", file1, file2);
	goto closem;
notsame:
I 11
	dirstatus |= 1;
E 11
D 13
	if (!ascii(f1) || !ascii(f2)) {
E 13
I 13
	if (!aflag && (!ascii(f1) || !ascii(f2))) {
E 13
		if (lflag)
			dp->d_flags |= DIFFER;
		else if (opt == D_NORMAL || opt == D_CONTEXT)
			printf("Binary files %s and %s differ\n",
			    file1, file2);
		goto closem;
	}
	close(f1); close(f2);
	anychange = 1;
	if (lflag)
		calldiff(title);
	else {
		if (opt == D_EDIT) {
D 6
			printf("ed - %.*s << '-*-END-*-'\n",
			    DIRSIZ, dp->d_name);
E 6
I 6
			printf("ed - %s << '-*-END-*-'\n", dp->d_entry);
E 6
			calldiff(0);
		} else {
			printf("%s%s %s\n", title, file1, file2);
			calldiff(0);
		}
		if (opt == D_EDIT)
			printf("w\nq\n-*-END-*-\n");
	}
	return;
closem:
	close(f1); close(f2);
}

D 3
char	*prargs[] = { "pr", "-h", "-f", 0, 0 };
E 3
I 3
char	*prargs[] = { "pr", "-h", 0, "-f", 0, 0 };
E 3

calldiff(wantpr)
	char *wantpr;
{
D 11
	int pid, status, status2, pv[2];
E 11
I 11
	int pid, lstatus, lstatus2, pv[2];
E 11

D 3
	prargs[3] = wantpr;
E 3
I 3
	prargs[2] = wantpr;
E 3
	fflush(stdout);
	if (wantpr) {
D 12
		sprintf(etitle, "%s %s", file1, file2);
E 12
I 12
		(void)sprintf(etitle, "%s %s", file1, file2);
E 12
		pipe(pv);
		pid = fork();
		if (pid == -1) {
			fprintf(stderr, "No more processes");
			done();
		}
		if (pid == 0) {
			close(0);
			dup(pv[0]);
			close(pv[0]);
			close(pv[1]);
			execv(pr+4, prargs);
D 3
			execl(pr, prargs);
E 3
I 3
			execv(pr, prargs);
E 3
			perror(pr);
			done();
		}
	}
	pid = fork();
	if (pid == -1) {
		fprintf(stderr, "diff: No more processes\n");
		done();
	}
	if (pid == 0) {
		if (wantpr) {
			close(1);
			dup(pv[1]);
			close(pv[0]);
			close(pv[1]);
		}
		execv(diff+4, diffargv);
		execv(diff, diffargv);
		perror(diff);
		done();
	}
D 9
	close(pv[0]);
	close(pv[1]);
E 9
I 9
	if (wantpr) {
		close(pv[0]);
		close(pv[1]);
	}
E 9
D 11
	while (wait(&status) != pid)
E 11
I 11
	while (wait(&lstatus) != pid)
E 11
		continue;
D 11
	while (wait(&status2) != -1)
E 11
I 11
	while (wait(&lstatus2) != -1)
E 11
		continue;
/*
D 11
	if ((status >> 8) >= 2)
E 11
I 11
	if ((lstatus >> 8) >= 2)
E 11
		done();
*/
I 11
	dirstatus |= lstatus >> 8;
E 11
}

I 2
#include <a.out.h>

E 2
ascii(f)
	int f;
{
	char buf[BUFSIZ];
	register int cnt;
	register char *cp;

	lseek(f, (long)0, 0);
	cnt = read(f, buf, BUFSIZ);
I 2
	if (cnt >= sizeof (struct exec)) {
		struct exec hdr;
		hdr = *(struct exec *)buf;
		if (!N_BADMAG(hdr))
			return (0);
	}
E 2
	cp = buf;
	while (--cnt >= 0)
		if (*cp++ & 0200)
			return (0);
	return (1);
}

/*
 * THIS IS CRUDE.
 */
useless(cp)
register char *cp;
{

D 8
	if (cp[0] == '.')
		return (1);
E 8
I 8
	if (cp[0] == '.') {
		if (cp[1] == '\0')
			return (1);	/* directory "." */
		if (cp[1] == '.' && cp[2] == '\0')
			return (1);	/* directory ".." */
	}
E 8
	if (start && strcmp(start, cp) > 0)
		return (1);
	return (0);
}
E 1
