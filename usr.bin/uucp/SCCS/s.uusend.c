h17003
s 00054/00046/00310
d D 5.2 85/01/22 14:13:22 ralph 2 1
c bug fixes and changes from Rick Adams
e
s 00356/00000/00000
d D 5.1 83/07/02 17:57:59 sam 1 0
c date and time created 83/07/02 17:57:59 by sam
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif

/*
 * uusend: primitive operation to allow uucp like copy of binary files
 * but handle indirection over systems.
 *
 * usage: uusend [-r] [-m ooo] localfile sysname1!sysname2!...!destfile
 *        uusend [-r] [-m ooo]     -     sysname1!sysname2!...!destfile
 *
 * Author: Mark Horton, May 1980.
 *
 * "-r" switch added.  Has same effect as "-r" in uux. 11/82  CCW
 *
 * Error recovery (a la uucp) added & ifdefs for ruusend (as in rmail).
 * Checks for illegal access to /usr/lib/uucp.
 *				February 1983  Christopher Woodbury
 * Fixed mode set[ug]id loophole. 4/8/83  CCW
 *
 * Add '-f' to make uusend syntax more similar to UUCP.  "destname"
 * can now be a directory.	June 1983  CCW
 */

#include <stdio.h>
#include <pwd.h>
#include <sys/types.h>
#include <sys/stat.h>

I 2
/*
 * define RECOVER to permit requests like 'uusend file sys1!sys2!~uucp'
 * (abbreviation for 'uusend file sys1!sys2!~uucp/file').
 * define DEBUG to keep log of uusend uusage.
 * define RUUSEND if neighboring sites permit 'ruusend',
 * which they certainly should to avoid security holes
 */
E 2
#define	RECOVER
I 2
/*#define	DEBUG	"/usr/spool/uucp/uusend.log"/**/
E 2

FILE	*in, *out;
FILE	*dout;

D 2
FILE	*popen();
char	*index(), *strcpy();
E 2
I 2
extern FILE	*popen();
extern char	*index(), *strcpy(), *strcat(), *ctime();
E 2

#ifdef	RUUSEND
int	rsend;
D 2
#endif
E 2
I 2
#endif  RUUSEND
E 2
int	mode = -1;	/* mode to chmod new file to */
char	*nextsys;	/* next system in the chain */
char	dnbuf[200];	/* buffer for result of ~user/file */
char	cmdbuf[256];	/* buffer to build uux command in */
char	*rflg = "";	/* default value of rflg  ccw -- 1 Nov '82 */

struct	passwd *user;	/* entry  in /etc/passwd for ~user */
struct	passwd *getpwnam();
struct	stat	stbuf;

char	*excl;		/* location of first ! in destname */
char	*sl;		/* location of first / in destname */
char	*sourcename;	/* argv[1] */
char	*destname;	/* argv[2] */
char	*UULIB = "/usr/lib/uucp";	  /* UUCP lib directory */

#ifdef	RECOVER
char	*UUPUB = "/usr/spool/uucppublic/";  /* public UUCP directory */
char	*filename;	/* file name from end of destname */
char	*getfname();	/* routine to get filename from destname */
int	fflg;
char	f[100];		/* name of default output file */
D 2
#else
E 2
I 2
#else	!RECOVER
E 2
char	*f	= "";	/* so we waste a little space */
D 2
#endif
E 2
I 2
#endif	!RECOVER
E 2

main(argc, argv)
int	argc;
char	**argv;
{
	register int c;
D 2
	long count = 0;
E 2
I 2
	long count;
	extern char **environ;
E 2

#ifdef DEBUG
	long t;
I 2
	umask(022);
E 2
	dout = fopen(DEBUG, "a");
	if (dout == NULL) {
		printf("Cannot append to %s\n", DEBUG);
		exit(1);
	}
	freopen(DEBUG, "a", stdout);
D 2
/*xxx
	freopen(DEBUG, "a", stderr);
  xxx*/
	chmod(DEBUG, 0666);
E 2
	fprintf(dout, "\nuusend run: ");
	for (c=0; c<argc; c++)
		fprintf(dout, "%s ", argv[c]);
	time(&t);
	fprintf(dout, "%s", ctime(&t));
D 2
#endif
E 2
I 2
#endif DEBUG
E 2

#ifdef	RUUSEND
	if(argv[0][0] == 'r')
		rsend++;
D 2
#endif
E 2
I 2
#endif RUUSEND
E 2
	while (argc > 1 && argv[1][0] == '-' && argv[1][1]) {
		switch(argv[1][1]) {
		case 'm':
			sscanf(argv[2], "%o", &mode);
			mode &= 0777;  /* fix set[ug]id loophole */
			argc--; argv++;
			break;
		case 'r':		/* -r flag for uux */
			rflg = "-r ";
			break;
#ifdef	RECOVER
		case 'f':
			fflg++;
			strcpy(f, argv[1]);
			break;
D 2
#endif
E 2
I 2
#endif RECOVER
E 2
		default:
			fprintf(stderr, "Bad flag: %s\n", argv[1]);
			break;
		}
		argc--; argv++;
	}

	if (argc != 3) {
		fprintf(stderr, "Usage: uusend [-m ooo] [-r] -/file sys!sys!..!rfile\n");
		exit(1);
	}

	sourcename = argv[1];
	destname = argv[2];

	if (sourcename[0] == '-')
		in = stdin;
	else {
#ifdef	RUUSEND
		if (rsend) {
			fprintf(stderr, "illegal input\n");
			exit(2);
		}
D 2
#endif
E 2
I 2
#endif RUUSEND
E 2
		in = fopen(sourcename, "r");
		if (in == NULL) {
			perror(argv[1]);
			exit(2);
		}
		if (!fflg || f[2] == '\0') {
			strcpy(f, "-f");
			strcat(f, getfname(sourcename));
			fflg++;
		}
	}

	excl = index(destname, '!');
	if (excl) {
		/*
		 * destname is on a remote system.
		 */
		nextsys = destname;
		*excl++ = 0;
		destname = excl;
		if (mode < 0) {
			fstat(fileno(in), &stbuf);
			mode = stbuf.st_mode & 0777;
		}
#ifdef	RUUSEND
D 2
		sprintf(cmdbuf,"uux %s- \"%s!ruusend %s -m %o - (%s)\"",
#else
		sprintf(cmdbuf, "uux %s- \"%s!uusend %s -m %o - (%s)\"",
#endif
E 2
I 2
		sprintf(cmdbuf,"uux -gn -z %s- \"%s!ruusend %s -m %o - (%s)\"",
#else !RUUSEND
		sprintf(cmdbuf, "uux -gn -z %s- \"%s!uusend %s -m %o - (%s)\"",
#endif !RUUSEND
E 2
			rflg, nextsys, f, mode, destname);
#ifdef DEBUG
		fprintf(dout, "remote: nextsys='%s', destname='%s', cmd='%s'\n", nextsys, destname, cmdbuf);
D 2
#endif
E 2
I 2
#endif DEBUG
E 2
		out = popen(cmdbuf, "w");
	} else {
		/*
		 * destname is local.
		 */
		if (destname[0] == '~') {
#ifdef DEBUG
			fprintf(dout, "before ~: '%s'\n", destname);
fflush(dout);
D 2
#endif
E 2
I 2
#endif DEBUG
E 2
			sl = index(destname, '/');
#ifdef	RECOVER
			if (sl == NULL && !fflg) {
				fprintf(stderr, "Illegal ~user\n");
				exit(3);
			}
			for (sl = destname; *sl != '\0'; sl++)
				;	/* boy, is this a hack! */
D 2
#else
E 2
I 2
#else !RECOVER
E 2
			if (sl == NULL) {
				fprintf(stderr, "Illegal ~user\n");
				exit(3);
			}
			*sl++ = 0;
D 2
#endif
E 2
I 2
#endif !RECOVER
E 2
			user = getpwnam(destname+1);
			if (user == NULL) {
				fprintf(stderr, "No such user as %s\n",
					destname);
#ifdef	RECOVER
				if ((filename =getfname(sl)) == NULL &&
				     !fflg)
					exit(4);
				strcpy(dnbuf, UUPUB);
				if (fflg)
					strcat(dnbuf, &f[2]);
				else
					strcat(dnbuf, filename);
			}
			else {
				strcpy(dnbuf, user->pw_dir);
				strcat(dnbuf, "/");
				strcat(dnbuf, sl);
			}
D 2
#else
E 2
I 2
#else !RECOVER
E 2
				exit(4);
			}
			strcpy(dnbuf, user->pw_dir);
			strcat(dnbuf, "/");
			strcat(dnbuf, sl);
D 2
#endif
E 2
I 2
#endif !RECOVER
E 2
			destname = dnbuf;
		}
#ifdef	RECOVER
		else
			destname = strcpy(dnbuf, destname);
D 2
#endif
E 2
I 2
#endif !RECOVER
E 2
		if(strncmp(UULIB, destname, strlen(UULIB)) == 0) {
			fprintf(stderr, "illegal file: %s", destname);
			exit(4);
		}
#ifdef	RECOVER
		if (stat(destname, &stbuf) == 0 &&
		    (stbuf.st_mode & S_IFMT) == S_IFDIR &&
		     fflg) {
D 2
			strcat(dnbuf, "/");
			strcat(dnbuf, &f[2]);
E 2
I 2
			strcat(destname, "/");
			strcat(destname, &f[2]);
E 2
		}
D 2
#endif
E 2
I 2
#endif RECOVER
E 2
		out = fopen(destname, "w");
#ifdef DEBUG
		fprintf(dout, "local, file='%s'\n", destname);
D 2
#endif
E 2
I 2
#endif DEBUG
E 2
		if (out == NULL) {
			perror(destname);
#ifdef	RECOVER
			if (strncmp(destname,UUPUB,strlen(UUPUB)) == 0)
				exit(5);	/* forget it! */
			filename = getfname(destname);
			if (destname == dnbuf) /* cmdbuf is scratch */
				filename = strcpy(cmdbuf, filename);
			destname = strcpy(dnbuf, UUPUB);
			if (user != NULL) {
				strcat(destname, user->pw_name);
				if (stat(destname, &stbuf) == -1) {
D 2
					mkdir(destname);
					chmod(destname, 0777);
E 2
I 2
					mkdir(destname, 0777);
E 2
				}
				strcat(destname, "/");
			}
D 2
#ifdef	RECOVER
E 2
			if (fflg)
				strcat(destname, &f[2]);
			else
				strcat(destname, filename);
D 2
#endif
E 2
			if ((out = fopen(destname, "w")) == NULL)
				exit(5); /* all for naught! */
D 2
#else
E 2
I 2
#else !RECOVER
E 2
			exit(5);
D 2
#endif
E 2
I 2
#endif !RECOVER
E 2
		}
		if (mode > 0)
			chmod(destname, mode);	/* don't bother to check it */
	}

	/*
	 * Now, in any case, copy from in to out.
	 */

I 2
	count = 0;
E 2
	while ((c=getc(in)) != EOF) {
		putc(c, out);
		count++;
	}
#ifdef DEBUG
	fprintf(dout, "count %ld bytes\n", count);
	fclose(dout);
D 2
#endif
	
E 2
I 2
#endif DEBUG

E 2
	fclose(in);
	fclose(out);	/* really should pclose in that case */
	exit(0);
}

/*
 * Return the ptr in sp at which the character c appears;
 * NULL if not found.  Included so I don't have to fight the
 * index/strchr battle.
 */

#define	NULL	0

char *
index(sp, c)
register char *sp, c;
{
	do {
		if (*sp == c)
			return(sp);
	} while (*sp++);
	return(NULL);
}

#ifdef	RECOVER
char *
getfname(p)
register char *p;
{
	register char *s;
	s = p;
	while (*p != '\0')
		p++;
	if (p == s)
		return (NULL);
	for (;p != s; p--)
		if (*p == '/') {
			p++;
			break;
		}
	return (p);
}

D 2
mkdir(dirname)
E 2
I 2
#ifndef BSD4_2
makedir(dirname, mode)
E 2
char *dirname;
I 2
int mode;
E 2
{
	register int pid;
	int retcode, status;
	switch ((pid = fork())) {
	    case -1:		/* error */
		return (-1);
D 2
		break;
E 2
	    case 0:		/* child */
		umask(0);
D 2
		execl("/bin/mkdir", "mkdir", dirname, 0);
E 2
I 2
		execl("/bin/mkdir", "mkdir", dirname, (char *)0);
E 2
		exit(1);
D 2
		break;
E 2
I 2
		/* NOTREACHED */
E 2
	    default:		/* parent */
		while ((retcode=wait(&status)) != pid && retcode != -1)
			;
		if (retcode == -1)
D 2
			return (-1);
		else
			return (status);
		break;
E 2
I 2
			return  -1;
		else {
			chmod(dirname, mode);
			return status;
		}
E 2
	}
I 2
	/* NOTREACHED */
E 2
}
D 2
#endif
E 2
I 2
#endif !BSD4_2
#endif RECOVER
E 2
E 1
