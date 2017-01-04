h57016
s 00039/00060/00205
d D 4.22 88/04/21 11:42:45 bostic 22 21
c add getopt for "--" capability
e
s 00002/00001/00263
d D 4.21 87/12/20 09:17:26 bostic 21 20
c "not removed" doesn't tell you a whole helluva lot
e
s 00001/00001/00263
d D 4.20 87/04/08 18:21:43 bostic 20 19
c realloc not used
e
s 00008/00006/00256
d D 4.19 87/04/07 18:14:38 bostic 19 18
c ask for protection override even if -i set; bug report 4.2BSD/bin/49
e
s 00001/00001/00261
d D 4.18 86/01/06 13:51:58 mckusick 18 17
c ``rm -f'' produces no error message (from whm%arizona.csnet)
e
s 00003/00007/00259
d D 4.17 85/11/05 18:57:36 bloom 17 16
c allocate only enough space for the maximum path length (should really walk
c the tree instead of building a path)
e
s 00071/00067/00195
d D 4.16 85/03/18 12:46:35 ralph 16 15
c don't use chdir(). Build full name & malloc size needed.
e
s 00025/00016/00237
d D 4.15 85/03/13 15:05:17 ralph 15 14
c always exit 0 if -f given.
e
s 00181/00092/00072
d D 4.14 85/03/08 13:40:40 ralph 14 13
c fix rm -r limitations on number of open files.
e
s 00008/00001/00156
d D 4.13 85/02/14 17:10:52 serge 13 12
c usage error message; BUFSIZ -> MAXPATHLEN
e
s 00002/00002/00155
d D 4.12 83/06/30 14:51:49 sam 12 11
c from sun
e
s 00012/00025/00145
d D 4.11 82/12/19 13:16:42 sam 11 10
c use rmdir sys call
e
s 00001/00001/00169
d D 4.10 82/06/25 12:53:01 sam 10 9
c can't access a symbolic link, get target
e
s 00001/00001/00169
d D 4.9 82/05/07 16:47:29 mckusick 9 8
c update to new fs
e
s 00001/00001/00169
d D 4.8 82/03/31 21:55:59 mckusic 8 7
c change <sys/types.h> to <sys/param.h> for benefit of <ndir.h>
e
s 00001/00001/00169
d D 4.7 82/03/31 12:04:56 root 7 6
c use lstat
e
s 00003/00012/00167
d D 4.6 82/02/28 13:55:00 root 6 5
c back out incorrect fix
e
s 00009/00008/00170
d D 4.5 82/02/19 17:37:02 mckusic 5 4
c convert to new directory structure
e
s 00011/00002/00167
d D 4.4 82/02/11 12:26:57 root 4 3
c new error message (if you can't rm 'cause you're not owner)
e
s 00005/00005/00164
d D 4.3 81/01/04 20:18:24 root 3 2
c I changed the messages printed out by rm to conform to those
c printed by mv and cp (which I changed some time ago). --- Dave Presotto
e
s 00006/00000/00163
d D 4.2 80/12/18 14:24:41 root 2 1
c A new option '-' has been added which forces all following 
c arguments to be interpreted as file names.  This allows file names 
c starting with - to be specified.
e
s 00163/00000/00000
d D 4.1 80/10/01 17:28:13 bill 1 0
c date and time created 80/10/01 17:28:13 by bill
e
u
U
t
T
I 1
static char *sccsid = "%W% (Berkeley) %G%";
D 14
int	errcode;
E 14
I 4
D 6
short	uid, euid;
E 6
E 4

I 14
/*
 * rm - for ReMoving files, directories & trees.
 */

E 14
#include <stdio.h>
D 8
#include <sys/types.h>
E 8
I 8
#include <sys/param.h>
E 8
#include <sys/stat.h>
D 5
#include <sys/dir.h>
E 5
I 5
D 9
#include <ndir.h>
E 9
I 9
D 12
#include <dir.h>
E 12
I 12
#include <sys/dir.h>
I 14
#include <sys/file.h>
E 14
E 12
E 9
E 5

D 14
char	*sprintf();
E 14
I 14
D 16
int	fflg;			/* -f force - supress error messages */
int	iflg;			/* -i interrogate user on each file */
int	rflg;			/* -r recurse */
E 16
I 16
int	fflg;		/* -f force - supress error messages */
int	iflg;		/* -i interrogate user on each file */
int	rflg;		/* -r recurse */
E 16
E 14

I 14
D 16
int	errcode;		/* true if errors occured */
E 16
I 16
int	errcode;	/* true if errors occured */
E 16

D 16
char	*strcpy();
E 16
I 16
D 20
char	*strcpy(), *malloc(), *realloc();
E 20
I 20
char	*strcpy(), *malloc();
E 20
E 16

E 14
main(argc, argv)
D 14
char *argv[];
E 14
I 14
D 22
	char *argv[];
E 22
I 22
	int argc;
	char **argv;
E 22
E 14
{
D 22
	register char *arg;
E 22
I 22
	extern int optind;
	int ch;
E 22
D 14
	int fflg, iflg, rflg;
E 14

D 14
	fflg = 0;
	if (isatty(0) == 0)
		fflg++;
E 14
I 14
	fflg = !isatty(0);
E 14
D 22
	iflg = 0;
	rflg = 0;
I 4
D 6
	uid = getuid();
	euid = geteuid();
E 6
E 4
D 14
	while(argc>1 && argv[1][0]=='-') {
E 14
I 14
	while (argc > 1 && argv[1][0] == '-') {
E 14
		arg = *++argv;
		argc--;
I 2

		/*
		 *  all files following a null option are considered file names
		 */
D 14
		if (*(arg+1) == '\0') break;
E 14
I 14
		if (arg[1] == '\0')
E 22
I 22
	while ((ch = getopt(argc, argv, "-Rfir")) != EOF)
		switch((char)ch) {
		case '-':
			goto endarg;
		case 'f':
			fflg++;
E 22
			break;
I 22
		case 'i':
			iflg++;
			break;
		case 'R':
		case 'r':
			rflg++;
			break;
		case '?':
		default:
			usage();
		}
endarg:	argv += optind;
E 22
E 14

E 2
D 14
		while(*++arg != '\0')
E 14
I 14
D 22
		while (*++arg != '\0')
E 14
			switch(*arg) {
			case 'f':
				fflg++;
				break;
I 14

E 14
			case 'i':
				iflg++;
				break;
I 14

E 14
I 13
			case 'R':
E 13
			case 'r':
				rflg++;
				break;
I 14

E 14
			default:
D 14
				printf("rm: unknown option %s\n", *argv);
E 14
I 14
				fprintf(stderr, "usage: rm [-rif] file ...\n");
E 14
				exit(1);
			}
E 22
I 22
	if (!*argv) {
		if (fflg)
			exit(0);
		usage();
E 22
	}
I 13
D 22

D 18
	if (argc < 2) {
E 18
I 18
	if (argc < 2 && !fflg) {
E 18
		fprintf(stderr, "usage: rm [-rif] file ...\n");
		exit(1);
	}

E 13
D 14
	while(--argc > 0) {
		if(!strcmp(*++argv, "..")) {
			fprintf(stderr, "rm: cannot remove `..'\n");
			continue;
		}
		rm(*argv, fflg, rflg, iflg, 0);
	}
E 14
I 14
	while (--argc > 0)
		(void) rm(*++argv, 0);
E 14

E 22
I 22
	do {
		(void)rm(*argv, 0);
	} while (*++argv);
E 22
D 14
	exit(errcode);
E 14
I 14
	exit(errcode != 0);
E 14
}

D 14
rm(arg, fflg, rflg, iflg, level)
char arg[];
E 14
I 14
D 16
struct nambuf {
	char	*name;			/* pointer to name */
	struct	nambuf *next;		/* linked list of names */
} path, *pathp;
E 16
I 16
char	*path;		/* pointer to malloc'ed buffer for path */
char	*pathp;		/* current pointer to end of path */
int	pathsz;		/* size of path */
E 16

I 22
#define	isdot(a)	(a[0] == '.' && (!a[1] || a[1] == '.' && !a[2]))
E 22
/*
 * Return TRUE if sucessful. Recursive with -r (rflg)
 */
rm(arg, level)
	char arg[];
E 14
{
D 14
	struct stat buf;
D 5
	struct direct direct;
	char name[100];
E 5
I 5
	struct direct *dp;
	DIR *dirp;
D 13
	char name[BUFSIZ];
E 13
I 13
	char name[MAXPATHLEN + 1];
E 13
E 5
	int d;
E 14
I 14
	int ok;				/* true if recursive rm succeeded */
	struct stat buf;		/* for finding out what a file is */
	struct direct *dp;		/* for reading a directory */
	DIR *dirp;			/* for reading a directory */
D 16
	char name[MAXNAMLEN + 1];	/* buffer for file name */
E 16
	char prevname[MAXNAMLEN + 1];	/* previous name for -r */
D 16
	struct nambuf nambuf, *pp;
E 16
I 16
	char *cp;
E 16
E 14

D 7
	if(stat(arg, &buf)) {
E 7
I 7
D 14
	if(lstat(arg, &buf)) {
E 7
		if (fflg==0) {
			printf("rm: %s nonexistent\n", arg);
			++errcode;
		}
		return;
E 14
I 14
D 22
	if (dotname(arg)) {
E 22
I 22
	if (isdot(arg)) {
E 22
		fprintf(stderr, "rm: cannot remove `.' or `..'\n");
		return (0);
E 14
	}
I 14
D 16
	if (level == 0) {
		path.name = arg;
		path.next = NULL;
		pathp = &path;
	}
E 16
	if (lstat(arg, &buf)) {
D 15
		if (!fflg)
E 15
I 15
		if (!fflg) {
E 15
D 16
			error("nonexistent");
E 16
I 16
			fprintf(stderr, "rm: %s nonexistent\n", arg);
E 16
D 15
		errcode++;
E 15
I 15
			errcode++;
		}
E 15
		return (0);		/* error */
	}
E 14
	if ((buf.st_mode&S_IFMT) == S_IFDIR) {
D 14
		if(rflg) {
			if (access(arg, 02) < 0) {
				if (fflg==0)
					printf("%s not changed\n", arg);
				errcode++;
				return;
E 14
I 14
		if (!rflg) {
D 15
			error("directory");
			errcode++;
E 15
I 15
			if (!fflg) {
D 16
				error("directory");
E 16
I 16
				fprintf(stderr, "rm: %s directory\n", arg);
E 16
				errcode++;
			}
E 15
			return (0);
		}
I 16
		if (iflg && level != 0) {
			printf("rm: remove directory %s? ", arg);
			if (!yes())
				return (0);	/* didn't remove everything */
		}
E 16
		if (access(arg, R_OK|W_OK|X_OK) != 0) {
			if (rmdir(arg) == 0)
				return (1);	/* salvaged: removed empty dir */
D 15
			if (!fflg)
E 15
I 15
			if (!fflg) {
E 15
D 16
				error("not changed");
E 16
I 16
				fprintf(stderr, "rm: %s not changed\n", arg);
E 16
D 15
			errcode++;
E 15
I 15
				errcode++;
			}
E 15
			return (0);		/* error */
		}
D 16
		if (iflg && level != 0) {
			if (!yes("remove directory"))
				return (0);	/* didn't remove everything */
		}
		if (chdir(arg) < 0 || (dirp = opendir(".")) == NULL) {
E 16
I 16
		if ((dirp = opendir(arg)) == NULL) {
E 16
D 15
			if (!fflg)
E 15
I 15
			if (!fflg) {
E 15
D 16
				error("cannot read?");
E 16
I 16
				fprintf(stderr, "rm: cannot read %s?\n", arg);
E 16
D 15
			errcode++;
E 15
I 15
				errcode++;
			}
E 15
			return (0);
		}
D 16
		nambuf.name = name;
		nambuf.next = NULL;
		pathp->next = &nambuf;
		pp = pathp;
		pathp = &nambuf;
E 16
I 16
		if (level == 0)
			append(arg);
E 16
		prevname[0] = '\0';
		while ((dp = readdir(dirp)) != NULL) {
D 22
			if (dotname(dp->d_name)) {
E 22
I 22
			if (isdot(dp->d_name)) {
E 22
				strcpy(prevname, dp->d_name);
				continue;
E 14
			}
D 14
			if(iflg && level!=0) {
D 3
				printf("directory %s: ", arg);
E 3
I 3
				printf("remove directory %s? ", arg);
E 3
				if(!yes())
					return;
			}
D 5
			if((d=open(arg, 0)) < 0) {
E 5
I 5
			if((dirp = opendir(arg)) == NULL) {
E 5
D 3
				printf("rm: %s: cannot read\n", arg);
E 3
I 3
				printf("rm: cannot read %s?\n", arg);
E 3
				exit(1);
			}
D 5
			while(read(d, (char *)&direct, sizeof(direct)) == sizeof(direct)) {
				if(direct.d_ino != 0 && !dotname(direct.d_name)) {
					sprintf(name, "%s/%.14s", arg, direct.d_name);
E 5
I 5
			while((dp = readdir(dirp)) != NULL) {
				if(dp->d_ino != 0 && !dotname(dp->d_name)) {
D 6
					sprintf(name, "%s/%.14s", arg, dp->d_name);
E 6
I 6
					sprintf(name, "%s/%s", arg, dp->d_name);
E 6
E 5
					rm(name, fflg, rflg, iflg, level+1);
				}
			}
E 14
I 14
D 16
			strcpy(name, dp->d_name);
E 16
I 16
			append(dp->d_name);
E 16
E 14
D 5
			close(d);
E 5
I 5
			closedir(dirp);
E 5
D 11
			errcode += rmdir(arg, iflg);
E 11
I 11
D 14
			if (dotname(arg))
				return;
			if (iflg) {
				printf("rm: remove %s? ", arg);
				if (!yes())
					return;
			}
			if (rmdir(arg) < 0) {
D 12
				fprintf("rm: ");
E 12
I 12
				fprintf(stderr, "rm: ");
E 12
				perror(arg);
E 14
I 14
D 16
			ok = rm(name, level + 1);
			if ((dirp = opendir(".")) == NULL) {
E 16
I 16
			ok = rm(path, level + 1);
			for (cp = pathp; *--cp != '/' && cp > path; )
				;
			pathp = cp;
			*cp++ = '\0';
			if ((dirp = opendir(arg)) == NULL) {
E 16
D 15
				if (!fflg)
E 15
I 15
				if (!fflg) {
E 15
D 16
					error("cannot read?");
E 16
I 16
					fprintf(stderr, "rm: cannot read %s?\n", arg);
E 16
E 14
D 15
				errcode++;
E 15
I 15
					errcode++;
				}
E 15
I 14
				break;
E 14
			}
E 11
D 14
			return;
E 14
I 14
			/* pick up where we left off */
			if (prevname[0] != '\0') {
				while ((dp = readdir(dirp)) != NULL &&
				    strcmp(prevname, dp->d_name) != 0)
					;
			}
			/* skip the one we just failed to delete */
			if (!ok) {
				dp = readdir(dirp);
D 16
				if (dp != NULL && strcmp(name, dp->d_name) != 0)
					error("internal synchronization error");
				strcpy(prevname, name);
E 16
I 16
				if (dp != NULL && strcmp(cp, dp->d_name)) {
					fprintf(stderr,
			"rm: internal synchronization error: %s, %s, %s\n",
						arg, cp, dp->d_name);
				}
				strcpy(prevname, dp->d_name);
E 16
			}
E 14
		}
D 14
		printf("rm: %s directory\n", arg);
		++errcode;
		return;
E 14
I 14
		closedir(dirp);
D 16
		pathp = pp;
		pathp->next = NULL;
		if (chdir("..") < 0) {
D 15
			if (!fflg)
E 15
I 15
			if (!fflg) {
E 15
				error("cannot cd to '..'?");
D 15
			errcode++;
E 15
I 15
				errcode++;
			}
E 15
			return (0);
E 16
I 16
		if (level == 0) {
			pathp = path;
			*pathp = '\0';
E 16
		}
		if (iflg) {
D 16
			if (!yes("remove"))
E 16
I 16
			printf("rm: remove %s? ", arg);
			if (!yes())
E 16
				return (0);
		}
		if (rmdir(arg) < 0) {
D 15
			if (!fflg || iflg)
E 15
I 15
			if (!fflg || iflg) {
E 15
D 16
				error("not removed");
E 16
I 16
				fprintf(stderr, "rm: %s not removed\n", arg);
E 16
D 15
			errcode++;
E 15
I 15
				errcode++;
			}
E 15
			return (0);
		}
		return (1);
E 14
	}

D 14
	if(iflg) {
D 3
		printf("%s: ", arg);
E 3
I 3
		printf("rm: remove %s? ", arg);
E 3
		if(!yes())
			return;
	}
	else if(!fflg) {
D 10
		if (access(arg, 02)<0) {
E 10
I 10
		if ((buf.st_mode&S_IFMT) != S_IFLNK && access(arg, 02) < 0) {
E 10
D 3
			printf("rm: %s %o mode ", arg, buf.st_mode&0777);
E 3
I 3
D 4
			printf("rm: override protection %o for %s? ", buf.st_mode&0777, arg);
E 3
			if(!yes())
E 4
I 4
D 6
			if (uid == buf.st_uid || euid == buf.st_uid) {
				printf("rm: override protection %o for %s? ",
					buf.st_mode&0777, arg);
				if(!yes())
					return;
			} else {
				printf("rm: %s: not owner.\n", arg);
E 6
I 6
			printf("rm: override protection %o for %s? ", buf.st_mode&0777, arg);
			if(!yes())
E 6
E 4
				return;
E 14
I 14
D 19
	if (iflg) {
D 16
		if (!yes("remove"))
E 16
I 16
		printf("rm: remove %s? ", arg);
		if (!yes())
E 16
			return (0);
	} else if (!fflg) {
E 19
I 19
	if (!fflg) {
E 19
		if ((buf.st_mode&S_IFMT) != S_IFLNK && access(arg, W_OK) < 0) {
D 16
			sprintf(name, "override protection %o for",
				buf.st_mode&0777);
			if (!yes(name))
E 16
I 16
			printf("rm: override protection %o for %s? ",
				buf.st_mode&0777, arg);
			if (!yes())
E 16
				return (0);
I 19
			goto rm;
E 19
E 14
I 4
D 6
			}
E 6
E 4
		}
	}
D 14
	if(unlink(arg) && (fflg==0 || iflg)) {
		printf("rm: %s not removed\n", arg);
		++errcode;
E 14
I 14
D 19
	if (unlink(arg) < 0) {
E 19
I 19
	if (iflg) {
		printf("rm: remove %s? ", arg);
		if (!yes())
			return (0);
	}
rm:	if (unlink(arg) < 0) {
E 19
D 15
		if (!fflg || iflg)
E 15
I 15
		if (!fflg || iflg) {
E 15
D 16
			error("not removed");
E 16
I 16
D 21
			fprintf(stderr, "rm: %s not removed\n", arg);
E 21
I 21
			fprintf(stderr, "rm: %s: ", arg);
			perror((char *)NULL);
E 21
E 16
D 15
		errcode++;
E 15
I 15
			errcode++;
		}
E 15
		return (0);
E 14
	}
I 14
	return (1);
E 14
}

I 14
/*
D 22
 * boolean: is it "." or ".." ?
 */
E 14
dotname(s)
D 14
char *s;
E 14
I 14
	char *s;
E 14
{
D 14
	if(s[0] == '.')
		if(s[1] == '.')
			if(s[2] == '\0')
				return(1);
E 14
I 14
	if (s[0] == '.')
		if (s[1] == '.')
			if (s[2] == '\0')
				return (1);
E 14
			else
D 14
				return(0);
		else if(s[1] == '\0')
			return(1);
	return(0);
E 14
I 14
				return (0);
		else if (s[1] == '\0')
			return (1);
	return (0);
E 14
D 11
}

rmdir(f, iflg)
char *f;
{
	int status, i;

	if(dotname(f))
		return(0);
	if(iflg) {
D 3
		printf("%s: ", f);
E 3
I 3
		printf("rm: remove %s? ", f);
E 3
		if(!yes())
			return(0);
	}
	while((i=fork()) == -1)
		sleep(3);
	if(i) {
		wait(&status);
		return(status);
	}
	execl("/bin/rmdir", "rmdir", f, 0);
	execl("/usr/bin/rmdir", "rmdir", f, 0);
	printf("rm: can't find rmdir\n");
	exit(1);
E 11
}

D 14
yes()
E 14
I 14
/*
E 22
 * Get a yes/no answer from the user.
 */
D 16
yes(msg)
	char *msg;
E 16
I 16
yes()
E 16
E 14
{
I 14
D 16
	register struct nambuf *pp;
E 16
E 14
	int i, b;

I 14
D 16
	printf("rm: %s %s", msg, path.name);
	for (pp = &path; pp->next != NULL; pp = pp->next)
		printf("/%s", pp->next->name);
	printf("? ");
E 16
E 14
	i = b = getchar();
D 14
	while(b != '\n' && b != EOF)
E 14
I 14
	while (b != '\n' && b != EOF)
E 14
		b = getchar();
D 14
	return(i == 'y');
E 14
I 14
	return (i == 'y');
}

/*
D 16
 * Print the current path and error message.
E 16
I 16
 * Append 'name' to 'path'.
E 16
 */
D 16
error(msg)
	char *msg;
E 16
I 16
append(name)
	char *name;
E 16
{
D 16
	register struct nambuf *pp;
E 16
I 16
	register int n;
E 16

D 16
	fprintf(stderr, "rm: %s", path.name);
	for (pp = &path; pp->next != NULL; pp = pp->next)
		fprintf(stderr, "/%s", pp->next->name);
	fprintf(stderr, ": %s\n", msg);
E 16
I 16
	n = strlen(name);
	if (path == NULL) {
D 17
		pathsz = n + 2048;
E 17
I 17
		pathsz = MAXNAMLEN + MAXPATHLEN + 2;
E 17
D 22
		if ((path = malloc(pathsz)) == NULL) {
E 22
I 22
		if ((path = malloc((u_int)pathsz)) == NULL) {
E 22
			fprintf(stderr, "rm: ran out of memory\n");
			exit(1);
		}
		pathp = path;
	} else if (pathp + n + 2 > path + pathsz) {
D 17
		pathsz = n + 2048;
		if ((path = realloc(path, pathsz)) == NULL) {
			fprintf(stderr, "rm: ran out of memory\n");
			exit(1);
		}
		pathp = path;
E 17
I 17
		fprintf(stderr, "rm: path name too long: %s\n", path);
		exit(1);
E 17
	} else if (pathp != path && pathp[-1] != '/')
		*pathp++ = '/';
	strcpy(pathp, name);
	pathp += n;
I 22
}

usage()
{
	fputs("usage: rm [-rif] file ...\n", stderr);
	exit(1);
E 22
E 16
E 14
}
E 1
