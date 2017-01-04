h36552
s 00002/00002/00185
d D 1.4 87/11/04 21:14:39 bostic 5 4
c fix includes
e
s 00018/00021/00169
d D 1.3 82/08/06 17:27:57 mckusick 4 3
c update to new directory routines
e
s 00141/00098/00049
d D 1.2 81/02/12 15:25:31 halbert 3 1
c Completely rewritten by Dan Halbert and Dan Fitzpatrick.
c Includes new code to delete queue files used by vdmp and vpltdmp.
e
s 00002/00000/00147
d R 1.2 81/02/12 15:20:59 halbert 2 1
c Completely rewritten by Dan Halbert and Dan Fitzpatrick.
c Includes new code to delete queue files used by vdmp and vpltdmp.
e
s 00147/00000/00000
d D 1.1 80/11/30 15:56:35 root 1 0
c date and time created 80/11/30 15:56:35 by root
e
u
U
t
T
I 3
static char vprmSCCSid[] = "%W%\t%G%";

E 3
I 1
D 4
#include <sys/types.h>
E 4
I 4
#include <sys/param.h>
E 4
D 5
#include <dir.h>
#include <stat.h>
E 5
I 5
#include <sys/dir.h>
#include <sys/stat.h>
E 5
#include <stdio.h>

D 3
char	line[128];
int	linel;
int	wide;
char	*spooldir;
FILE	*df;
FILE	*dfb;
E 3
I 3
char *basename();

E 3
extern	char _sobuf[];

main(argc, argv)
	int argc;
	char *argv[];
{
D 3
	register int i;
	register char *ap, *cp;
	int cnt;
	int oldargc;
	char **oldargv;

E 3
	setbuf(stdout, _sobuf);
	argc--, argv++;
	if (argc == 0) {
		fprintf(stderr, "usage: vprm [ id ... ] [ filename ... ] [ user ... ]\n");
		exit(1);
	}

I 3
	/* Look for something to delete both in Varian and Versatec spool dirs. */
	delete("Varian", "/usr/spool/vad", argc, argv);
	delete("Versatec", "/usr/spool/vpd", argc, argv);
}

/*
 * Look through the argv list for things to delete.
 */
E 3

D 3
	oldargc = argc; oldargv = argv;
E 3
I 3
delete(devname, spooldir, argc, argv)
D 4
char *devname, *spooldir, *argv[];
int argc;
E 4
I 4
	char *devname, *spooldir, *argv[];
	int argc;
E 4
{
D 4
	FILE *dir;		/* The spool dir. */
	struct dir dirent;	/* An entry read from the spool dir.*/
E 4
I 4
	DIR *dir;		/* The spool dir. */
	struct direct *dirp;	/* An entry read from the spool dir.*/
E 4
	int deletion = 0;	/* Flag noting something has been deleted. */
E 3

D 3
	printf("Varian - ");
	if (chdir("/usr/spool/vad") < 0)
		perror("/usr/spool/vad");
	else {
		df = fopen(".", "r");
		if (df == NULL)
			perror("/usr/spool/vad");
		else do {
			clobber(*oldargv++);
		} while (--oldargc);
E 3
I 3
	/* Change to the spool directory. */
	if (chdir(spooldir) < 0) {
		perror(spooldir);
		return(1);
E 3
	}

D 3
	printf("Versatec - ");
	if (chdir("/usr/spool/vpd") < 0)
		perror("/usr/spool/vpd");
	else {
		df = fopen(".", "r");
		if (df == NULL)
			perror("/usr/spool/vpd");
		else do {
			clobber(*argv++);
		} while (--argc);
E 3
I 3
	/* Open it. */
D 4
	if ((dir = fopen(".", "r")) == NULL) {
E 4
I 4
	if ((dir = opendir(".")) == NULL) {
E 4
		perror(spooldir);
		return(1);
E 3
	}
D 3
}
E 3

D 3
clobber(cp)
	char *cp;
{
	struct dir dirent;
	int did = 0;
E 3
I 3
	printf("%s -", devname);
E 3

D 3
	rewind(df);
	while (fread(&dirent, sizeof dirent, 1, df) == 1) {
		if (dirent.d_ino == 0)
			continue;
		if (dirent.d_name[0] != 'd' || dirent.d_name[1] != 'f')
			continue;
		if (dirent.d_name[7] == 0 || dirent.d_name[8] != 0)
			continue;
		if (chkclob(cp, dirent.d_name)) {
			did++;
			printf("removing %s\n", dirent.d_name+3);
			unlink(dirent.d_name);
			dirent.d_name[0] = 'c'; unlink(dirent.d_name);
			dirent.d_name[2] = 'b'; unlink(dirent.d_name);
			dirent.d_name[2] = 'a';
			dirent.d_name[0] = 'l'; unlink(dirent.d_name);
			dirent.d_name[0] = 't'; unlink(dirent.d_name);
			dirent.d_name[0] = 'd';
E 3
I 3
	/*
	 * Loop through the args and the spool dir, looking for a spool
	 * command file (has a prefix of 'df'),
	 * and trying to match it with the argument.
	 */
	while (argc-- > 0) {
D 4
		rewind(dir);
		while (fread(&dirent, sizeof dirent, 1, dir) == 1) {
			if (dirent.d_ino == 0)
				continue;
			if (dirent.d_name[0] == 'd' &&
			    dirent.d_name[1] == 'f') {
				if (delcheck(dirent.d_name, *argv)) {
					printf(" removing %s", dirent.d_name+3);
					deletion = 1;
				}
E 4
I 4
		rewinddir(dir);
		while ((dirp = readdir(dir)) != NULL) {
			if (dirp->d_name[0] == 'd' &&
			    dirp->d_name[1] == 'f' &&
			    delcheck(dirp->d_name, *argv)) {
				printf(" removing %s", &(dirp->d_name[3]));
				deletion = 1;
E 4
			}
E 3
		}
I 3
		argv++;
E 3
	}
D 3
	if (did == 0)
		printf("%s: nothing to remove\n", cp);
E 3
I 3
D 4

E 4
I 4
	closedir(dir);
E 4
	if (!deletion)
		printf(" nothing to remove\n");
	else
		putchar('\n');
E 3
}

D 3
chkclob(pattern, file)
	char *pattern, *file;
E 3
I 3

/*
 * delcheck tries to match the given arg against the given command file in
 * various ways.  For instance, if dfname = 'dfa12345', then there is a match if
 * arg == 'dfa12345', or
 * arg == '12345', or
 * arg == the name given on the L line of the file (the owner), or
 * arg == the basename of a file given on a command line in the file.
 * If there is a match, all the U (unlink) commands in the command file
 * are executed, and then the command file itself is unlinked.
 */

int
delcheck(dfname, arg)
D 4
char *dfname, *arg;
E 4
I 4
	char *dfname, *arg;
E 4
E 3
{
D 3
	register char *id = pattern;
E 3
I 3
	FILE *df = NULL;	/* The command file. */
	int delfile = 0;	/* A match was found, so do a deletion. */
	char line[256];		/* Command line in command file. */
E 3

D 3
	/*
	 * Quick check for matching id
	 */
	if (any(id[0], "cd") && id[1] == 'f' && id[2] == 'a')
		id += 3;
	if (strcmp(file+3, id) == 0)
		return (1);
	/*
	 * Now check for matching filename 'B', 'F' or id 'L'
	 */
	dfb = fopen(file, "r");
	if (dfb == NULL)
		return (0);
	while (getline()) switch (line[0]) {
E 3
I 3
	if (strcmp(arg, dfname) == 0)
		delfile = 1;	/* arg == 'dfa12345'. */
	else if (strcmp(arg, dfname+3) == 0)
		delfile = 1;	/* arg == '12345' (skip 'dfa'). */
	else {			/* No match; look inside on command lines. */
		if ((df = fopen(dfname, "r")) == NULL)
			return(0);
		while (!delfile && getline(df, line)) {
			switch (line[0]) {
				case 'L':
					/* Check owner name. */
					if (strcmp(arg, line+1) == 0)
						delfile = 1;
					break;
E 3

D 3
	case 'L':
	case 'B':
	case 'F':
	case 'T':
		if (strcmp(line+1, pattern) == 0) {
			fclose(dfb);
			return (1);
E 3
I 3
				case 'C':
				case 'V':
				case 'F':
				case 'G':
				case 'P':
				case 'T':
					/* Check command line arg. */
					if (strcmp (basename(arg), basename(line)) == 0)
						delfile = 1;
					break;
			}
E 3
		}
D 3
		continue;
E 3
	}
D 3
	fclose(dfb);
	return (0);
}
E 3

D 3
any(c, cp)
	char c;
	register char *cp;
{
E 3
I 3
	if (delfile) {
		if (df == NULL)		/* File not open yet. */
			df = fopen(dfname, "r");
		if (df == NULL)
			return(0);
		
		/* Run through the command file, executing Unlink commands. */
		rewind(df);
		while (getline(df, line)) {
			if (line[0] == 'U')
				unlink(line+1);
		}
E 3

D 3
	while (*cp)
		if (c == *cp++)
			return (1);
	return (0);
E 3
I 3
		unlink(dfname);		/* Now unlink the command file itself. */
	}

	if (df != NULL)
		fclose(df);
	return(delfile);
E 3
}

D 3
getline()
E 3
I 3



getline(file, line)
D 4
FILE *file;
char *line;
E 4
I 4
	FILE *file;
	char *line;
E 4
E 3
{
	register int i, c;

	i = 0;
D 3
	while ((c = getc(dfb)) != '\n') {
E 3
I 3
	while ((c = getc(file)) != '\n') {
E 3
		if (c <= 0)
			return(0);
D 3
		if (i < 100)
E 3
I 3
		if (i < 256)
E 3
			line[i++] = c;
	}
	line[i++] = 0;
	return (1);
I 3
}


/*
 * basename gets the final component of the given pathname. E.g. "c" in
 * /a/b/c.
 */

char *
basename(pathname)
D 4
char *pathname;
E 4
I 4
	char *pathname;
E 4
{
	register char *lastname;

	lastname = pathname + strlen(pathname)-1; /* Move to last char in name. */
	while (lastname >= pathname) {
		if (*lastname == '/')
			return(lastname + 1);
		lastname--;
	}
	return(pathname);		/* No /'s at all. */
E 3
}
E 1
