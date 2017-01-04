h33355
s 00003/00001/00828
d D 5.5 87/04/23 22:43:53 mckusick 11 10
c can only define inumber if file exists on tape (from shannon@sun.com)
e
s 00036/00001/00793
d D 5.4 86/10/21 16:35:16 mckusick 10 9
c check interactive commands more closely; add `what' command
e
s 00009/00003/00785
d D 5.3 85/07/21 16:58:02 mckusick 9 7
c deal with arbitrary sized inode numbers
e
s 00001/00001/00787
d R 5.3 85/07/21 16:46:46 mckusick 8 7
c use wider format for inode numbers
e
s 00001/00001/00787
d D 5.2 85/06/18 21:11:24 mckusick 7 6
c dumprestor.h moves to /usr/include/protocols
e
s 00006/00002/00782
d D 5.1 85/05/28 15:11:46 dist 6 5
c Add copyright
e
s 00003/00002/00781
d D 3.5 85/05/27 17:29:46 mckusick 5 4
c make 'R' into a real mode
e
s 00001/00001/00782
d D 3.4 85/05/17 17:25:10 mckusick 4 3
c must use static declarations for variables passed back (from tef@ucsfcgl)
e
s 00143/00159/00640
d D 3.3 85/02/18 17:00:16 mckusick 3 2
c glob'ed files are now sorted; canon() elides extra /'s and /.'s
e
s 00275/00000/00524
d D 3.2 85/01/18 22:39:38 mckusick 2 1
c add globbing of file names
e
s 00524/00000/00000
d D 3.1 85/01/18 22:36:07 mckusick 1 0
c date and time created 85/01/18 22:36:07 by mckusick
e
u
U
t
T
I 1
D 6
/* Copyright (c) 1985 Regents of the University of California */
E 6
I 6
/*
 * Copyright (c) 1985 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 6

#ifndef lint
D 6
static char sccsid[] = "%W%	(Berkeley)	%G%";
E 6
I 6
static char sccsid[] = "%W% (Berkeley) %G%";
E 6
#endif not lint

#include "restore.h"
D 7
#include <dumprestor.h>
E 7
I 7
#include <protocols/dumprestore.h>
E 7
#include <setjmp.h>

I 2
#define round(a, b) (((a) + (b) - 1) / (b) * (b))

E 2
/*
 * Things to handle interruptions.
 */
static jmp_buf reset;
static char *nextarg = NULL;

/*
I 2
D 3
 * Structure associated with file name globbing.
 */
struct argnod {
	struct argnod *argnxt;
	char argval[1];
}; 
static struct argnod *gchain, *stakbot, *staktop;
static char *brkend, *nullstr = "";
struct argnod *locstak(), *endstak();

/*
E 3
E 2
 * Structure and routines associated with listing directories.
 */
struct afile {
	ino_t	fnum;		/* inode number of file */
	char	*fname;		/* file name */
	short	fflags;		/* extraction flags, if any */
	char	ftype;		/* file type, e.g. LEAF or NODE */
};
I 3
struct arglist {
	struct afile	*head;	/* start of argument list */
	struct afile	*last;	/* end of argument list */
	struct afile	*base;	/* current list arena */
	int		nent;	/* maximum size of list */
	char		*cmd;	/* the current command */
};
E 3
extern int fcmp();
extern char *fmtentry();
char *copynext();

/*
 * Read and execute commands from the terminal.
 */
runcmdshell()
{
	register struct entry *np;
	ino_t ino;
I 3
	static struct arglist alist = { 0, 0, 0, 0, 0 };
E 3
	char curdir[MAXPATHLEN];
	char name[MAXPATHLEN];
	char cmd[BUFSIZ];

	canon("/", curdir);
loop:
	if (setjmp(reset) != 0) {
I 2
D 3
		gchain = 0;
E 3
I 3
		for (; alist.head < alist.last; alist.head++)
			freename(alist.head->fname);
E 3
E 2
		nextarg = NULL;
		volno = 0;
	}
D 3
	getcmd(curdir, cmd, name);
E 3
I 3
	getcmd(curdir, cmd, name, &alist);
E 3
	switch (cmd[0]) {
	/*
	 * Add elements to the extraction list.
	 */
	case 'a':
I 10
		if (strncmp(cmd, "add", strlen(cmd)) != 0)
			goto bad;
E 10
		ino = dirlookup(name);
		if (ino == 0)
			break;
		if (mflag)
			pathcheck(name);
		treescan(name, ino, addfile);
		break;
	/*
	 * Change working directory.
	 */
	case 'c':
I 10
		if (strncmp(cmd, "cd", strlen(cmd)) != 0)
			goto bad;
E 10
		ino = dirlookup(name);
		if (ino == 0)
			break;
		if (inodetype(ino) == LEAF) {
			fprintf(stderr, "%s: not a directory\n", name);
			break;
		}
		(void) strcpy(curdir, name);
		break;
	/*
	 * Delete elements from the extraction list.
	 */
	case 'd':
I 10
		if (strncmp(cmd, "delete", strlen(cmd)) != 0)
			goto bad;
E 10
		np = lookupname(name);
		if (np == NIL || (np->e_flags & NEW) == 0) {
			fprintf(stderr, "%s: not on extraction list\n", name);
			break;
		}
		treescan(name, np->e_ino, deletefile);
		break;
	/*
	 * Extract the requested list.
	 */
	case 'e':
I 10
		if (strncmp(cmd, "extract", strlen(cmd)) != 0)
			goto bad;
E 10
		createfiles();
		createlinks();
		setdirmodes();
		if (dflag)
			checkrestore();
		volno = 0;
		break;
	/*
	 * List available commands.
	 */
	case 'h':
I 10
		if (strncmp(cmd, "help", strlen(cmd)) != 0)
			goto bad;
E 10
	case '?':
D 5
		fprintf(stderr, "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
E 5
I 5
D 10
		fprintf(stderr, "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
E 10
I 10
		fprintf(stderr, "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
E 10
E 5
			"Available commands are:\n",
			"\tls [arg] - list directory\n",
			"\tcd arg - change directory\n",
			"\tpwd - print current directory\n",
			"\tadd [arg] - add `arg' to list of",
			" files to be extracted\n",
			"\tdelete [arg] - delete `arg' from",
			" list of files to be extracted\n",
			"\textract - extract requested files\n",
I 5
			"\tsetmodes - set modes of requested directories\n",
E 5
			"\tquit - immediately exit program\n",
I 10
			"\twhat - list dump header information\n",
E 10
			"\tverbose - toggle verbose flag",
			" (useful with ``ls'')\n",
			"\thelp or `?' - print this list\n",
			"If no `arg' is supplied, the current",
			" directory is used\n");
		break;
	/*
	 * List a directory.
	 */
	case 'l':
I 10
		if (strncmp(cmd, "ls", strlen(cmd)) != 0)
			goto bad;
E 10
		ino = dirlookup(name);
		if (ino == 0)
			break;
		printlist(name, ino, curdir);
		break;
	/*
	 * Print current directory.
	 */
	case 'p':
I 10
		if (strncmp(cmd, "pwd", strlen(cmd)) != 0)
			goto bad;
E 10
		if (curdir[1] == '\0')
			fprintf(stderr, "/\n");
		else
			fprintf(stderr, "%s\n", &curdir[1]);
		break;
	/*
	 * Quit.
	 */
	case 'q':
I 10
		if (strncmp(cmd, "quit", strlen(cmd)) != 0)
			goto bad;
		return;
E 10
	case 'x':
I 10
		if (strncmp(cmd, "xit", strlen(cmd)) != 0)
			goto bad;
E 10
		return;
	/*
	 * Toggle verbose mode.
	 */
	case 'v':
I 10
		if (strncmp(cmd, "verbose", strlen(cmd)) != 0)
			goto bad;
E 10
		if (vflag) {
			fprintf(stderr, "verbose mode off\n");
			vflag = 0;
			break;
		}
		fprintf(stderr, "verbose mode on\n");
		vflag++;
		break;
	/*
	 * Just restore requested directory modes.
	 */
D 5
	case 'R':
E 5
I 5
	case 's':
I 10
		if (strncmp(cmd, "setmodes", strlen(cmd)) != 0)
			goto bad;
E 10
E 5
		setdirmodes();
		break;
	/*
I 10
	 * Print out dump header information.
	 */
	case 'w':
		if (strncmp(cmd, "what", strlen(cmd)) != 0)
			goto bad;
		printdumpinfo();
		break;
	/*
E 10
	 * Turn on debugging.
	 */
	case 'D':
I 10
		if (strncmp(cmd, "Debug", strlen(cmd)) != 0)
			goto bad;
E 10
		if (dflag) {
			fprintf(stderr, "debugging mode off\n");
			dflag = 0;
			break;
		}
		fprintf(stderr, "debugging mode on\n");
		dflag++;
		break;
	/*
	 * Unknown command.
	 */
	default:
I 10
	bad:
E 10
		fprintf(stderr, "%s: unknown command; type ? for help\n", cmd);
		break;
	}
	goto loop;
}

/*
 * Read and parse an interactive command.
 * The first word on the line is assigned to "cmd". If
 * there are no arguments on the command line, then "curdir"
 * is returned as the argument. If there are arguments
 * on the line they are returned one at a time on each
 * successive call to getcmd. Each argument is first assigned
 * to "name". If it does not start with "/" the pathname in
 * "curdir" is prepended to it. Finally "canon" is called to
 * eliminate any embedded ".." components.
 */
D 3
getcmd(curdir, cmd, name)
E 3
I 3
getcmd(curdir, cmd, name, ap)
E 3
	char *curdir, *cmd, *name;
I 3
	struct arglist *ap;
E 3
{
	register char *cp;
	static char input[BUFSIZ];
	char output[BUFSIZ];
#	define rawname input	/* save space by reusing input buffer */

	/*
	 * Check to see if still processing arguments.
	 */
I 2
D 3
	if (gchain != 0)
		goto getnextexp;
E 3
I 3
	if (ap->head != ap->last) {
		strcpy(name, ap->head->fname);
		freename(ap->head->fname);
		ap->head++;
		return;
	}
E 3
E 2
	if (nextarg != NULL)
		goto getnext;
	/*
	 * Read a command line and trim off trailing white space.
	 */
	do	{
		fprintf(stderr, "restore > ");
		(void) fflush(stderr);
		(void) fgets(input, BUFSIZ, terminal);
	} while (!feof(terminal) && input[0] == '\n');
	if (feof(terminal)) {
		(void) strcpy(cmd, "quit");
		return;
	}
	for (cp = &input[strlen(input) - 2]; *cp == ' ' || *cp == '\t'; cp--)
		/* trim off trailing white space and newline */;
	*++cp = '\0';
	/*
	 * Copy the command into "cmd".
	 */
	cp = copynext(input, cmd);
I 3
	ap->cmd = cmd;
E 3
	/*
	 * If no argument, use curdir as the default.
	 */
	if (*cp == '\0') {
		(void) strcpy(name, curdir);
		return;
	}
	nextarg = cp;
	/*
	 * Find the next argument.
	 */
getnext:
	cp = copynext(nextarg, rawname);
	if (*cp == '\0')
		nextarg = NULL;
	else
		nextarg = cp;
	/*
	 * If it an absolute pathname, canonicalize it and return it.
	 */
	if (rawname[0] == '/') {
		canon(rawname, name);
	} else {
		/*
		 * For relative pathnames, prepend the current directory to
		 * it then canonicalize and return it.
		 */
		(void) strcpy(output, curdir);
		(void) strcat(output, "/");
		(void) strcat(output, rawname);
		canon(output, name);
	}
I 2
D 3
	expandarg(name);
getnextexp:
	strcpy(name, gchain->argval);
	gchain = gchain->argnxt;
E 3
I 3
	expandarg(name, ap);
	strcpy(name, ap->head->fname);
	freename(ap->head->fname);
	ap->head++;
E 3
E 2
#	undef rawname
}

/*
 * Strip off the next token of the input.
 */
char *
copynext(input, output)
	char *input, *output;
{
	register char *cp, *bp;
	char quote;

	for (cp = input; *cp == ' ' || *cp == '\t'; cp++)
		/* skip to argument */;
	bp = output;
	while (*cp != ' ' && *cp != '\t' && *cp != '\0') {
		/*
		 * Handle back slashes.
		 */
		if (*cp == '\\') {
			if (*++cp == '\0') {
				fprintf(stderr,
					"command lines cannot be continued\n");
				continue;
			}
			*bp++ = *cp++;
			continue;
		}
		/*
		 * The usual unquoted case.
		 */
		if (*cp != '\'' && *cp != '"') {
			*bp++ = *cp++;
			continue;
		}
		/*
		 * Handle single and double quotes.
		 */
		quote = *cp++;
		while (*cp != quote && *cp != '\0')
			*bp++ = *cp++ | 0200;
		if (*cp++ == '\0') {
			fprintf(stderr, "missing %c\n", quote);
			cp--;
			continue;
		}
	}
	*bp = '\0';
	return (cp);
}

/*
 * Canonicalize file names to always start with ``./'' and
D 3
 * remove any imbedded ".." components.
E 3
I 3
 * remove any imbedded "." and ".." components.
E 3
 */
canon(rawname, canonname)
	char *rawname, *canonname;
{
	register char *cp, *np;
	int len;

	if (strcmp(rawname, ".") == 0 || strncmp(rawname, "./", 2) == 0)
		(void) strcpy(canonname, "");
	else if (rawname[0] == '/')
		(void) strcpy(canonname, ".");
	else
		(void) strcpy(canonname, "./");
	(void) strcat(canonname, rawname);
D 3
	len = strlen(canonname) - 1;
	if (canonname[len] == '/')
		canonname[len] = '\0';
E 3
	/*
D 3
	 * Eliminate extraneous ".." from pathnames.
E 3
I 3
	 * Eliminate multiple and trailing '/'s
E 3
	 */
I 3
	for (cp = np = canonname; *np != '\0'; cp++) {
		*cp = *np++;
		while (*cp == '/' && *np == '/')
			np++;
	}
	*cp = '\0';
	if (*--cp == '/')
		*cp = '\0';
	/*
	 * Eliminate extraneous "." and ".." from pathnames.
	 */
E 3
	for (np = canonname; *np != '\0'; ) {
		np++;
		cp = np;
		while (*np != '/' && *np != '\0')
			np++;
I 3
		if (np - cp == 1 && *cp == '.') {
			cp--;
			(void) strcpy(cp, np);
			np = cp;
		}
E 3
		if (np - cp == 2 && strncmp(cp, "..", 2) == 0) {
			cp--;
			while (cp > &canonname[1] && *--cp != '/')
				/* find beginning of name */;
			(void) strcpy(cp, np);
			np = cp;
		}
	}
I 2
}

/*
 * globals (file name generation)
 *
 * "*" in params matches r.e ".*"
 * "?" in params matches r.e. "."
 * "[...]" in params matches character class
 * "[...a-z...]" in params matches a through z.
 */
D 3
expandarg(arg)
E 3
I 3
expandarg(arg, ap)
E 3
	char *arg;
I 3
	register struct arglist *ap;
E 3
{
D 3
	static char *expbuf = NULL;
	static unsigned expsize = BUFSIZ;
E 3
I 3
D 4
	struct afile single;
E 4
I 4
	static struct afile single;
I 11
	struct entry *ep;
E 11
E 4
E 3
	int size;
D 3
	char argbuf[BUFSIZ];
E 3

D 3
	do {
		if (expbuf != NULL)
			free(expbuf);
		expbuf = malloc(expsize);
		brkend = expbuf + expsize;
		expsize <<= 1;
		stakbot = (struct argnod *)expbuf;
		gchain = 0;
		(void)strcpy(argbuf, arg);
		size = expand(argbuf, 0);
	} while (size < 0);
E 3
I 3
	ap->head = ap->last = (struct afile *)0;
	size = expand(arg, 0, ap);
E 3
	if (size == 0) {
D 3
		gchain = (struct argnod *)expbuf;
		gchain->argnxt = 0;
		(void)strcpy(gchain->argval, arg);
E 3
I 3
D 11
		single.fnum = lookupname(arg)->e_ino;
E 11
I 11
		ep = lookupname(arg);
		single.fnum = ep ? ep->e_ino : 0;
E 11
		single.fname = savename(arg);
		ap->head = &single;
		ap->last = ap->head + 1;
		return;
E 3
	}
I 3
	qsort((char *)ap->head, ap->last - ap->head, sizeof *ap->head, fcmp);
E 3
}

/*
 * Expand a file name
 */
D 3
expand(as, rflg)
E 3
I 3
expand(as, rflg, ap)
E 3
	char *as;
	int rflg;
I 3
	register struct arglist *ap;
E 3
{
	int		count, size;
	char		dir = 0;
	char		*rescan = 0;
	DIR		*dirp;
	register char	*s, *cs;
D 3
	struct argnod	*schain = gchain;
E 3
I 3
	int		sindex, rindex, lindex;
E 3
	struct direct	*dp;
	register char	slash; 
	register char	*rs; 
D 3
	struct argnod	*rchain;
E 3
	register char	c;

	/*
	 * check for meta chars
	 */
	s = cs = as;
	slash = 0;
	while (*cs != '*' && *cs != '?' && *cs != '[') {	
D 3
		if (*cs++==0) {	
E 3
I 3
		if (*cs++ == 0) {	
E 3
			if (rflg && slash)
				break; 
			else
				return (0) ;
D 3
		} else if (*cs=='/') {	
E 3
I 3
		} else if (*cs == '/') {	
E 3
			slash++;
		}
	}
	for (;;) {	
		if (cs == s) {	
D 3
			s = nullstr;
E 3
I 3
			s = "";
E 3
			break;
		} else if (*--cs == '/') {	
			*cs = 0;
			if (s == cs)
				s = "/";
			break;
		}
	}
	if ((dirp = rst_opendir(s)) != NULL)
		dir++;
	count = 0;
	if (*cs == 0)
D 3
		*cs++=0200 ;
E 3
I 3
		*cs++ = 0200;
E 3
	if (dir) {
		/*
		 * check for rescan
		 */
		rs = cs;
		do {	
			if (*rs == '/') { 
				rescan = rs; 
				*rs = 0; 
D 3
				gchain = 0 ;
E 3
			}
		} while (*rs++);
I 3
		sindex = ap->last - ap->head;
E 3
		while ((dp = rst_readdir(dirp)) != NULL && dp->d_ino != 0) {
			if (!dflag && BIT(dp->d_ino, dumpmap) == 0)
				continue;
			if ((*dp->d_name == '.' && *cs != '.'))
				continue;
			if (gmatch(dp->d_name, cs)) {	
D 3
				if (addg(s, dp->d_name, rescan) < 0)
E 3
I 3
				if (addg(dp, s, rescan, ap) < 0)
E 3
					return (-1);
				count++;
			}
		}
		if (rescan) {	
D 3
			rchain = gchain; 
			gchain = schain;
E 3
I 3
			rindex = sindex; 
			lindex = ap->last - ap->head;
E 3
			if (count) {	
				count = 0;
D 3
				while (rchain) {	
					size = expand(rchain->argval, 1);
E 3
I 3
				while (rindex < lindex) {	
					size = expand(ap->head[rindex].fname,
					    1, ap);
E 3
					if (size < 0)
						return (size);
					count += size;
D 3
					rchain = rchain->argnxt;
E 3
I 3
					rindex++;
E 3
				}
			}
I 3
			bcopy((char *)&ap->head[lindex],
			     (char *)&ap->head[sindex],
			     (ap->last - &ap->head[rindex]) * sizeof *ap->head);
			ap->last -= lindex - sindex;
E 3
			*rescan = '/';
		}
	}
	s = as;
	while (c = *s)
		*s++ = (c&0177 ? c : '/');
	return (count);
}

/*
 * Check for a name match
 */
gmatch(s, p)
	register char	*s, *p;
{
	register int	scc;
	char		c;
	char		ok; 
	int		lc;

	if (scc = *s++)
		if ((scc &= 0177) == 0)
			scc = 0200;
	switch (c = *p++) {

	case '[':
		ok = 0; 
		lc = 077777;
		while (c = *p++) {	
D 3
			if (c==']') {
E 3
I 3
			if (c == ']') {
E 3
				return (ok ? gmatch(s, p) : 0);
			} else if (c == '-') {	
				if (lc <= scc && scc <= (*p++))
					ok++ ;
			} else {	
				if (scc == (lc = (c&0177)))
					ok++ ;
			}
		}
		return (0);

	default:
		if ((c&0177) != scc)
			return (0) ;
		/* falls through */

	case '?':
		return (scc ? gmatch(s, p) : 0);

	case '*':
		if (*p == 0)
			return (1) ;
		s--;
		while (*s) {  
			if (gmatch(s++, p))
				return (1);
		}
		return (0);

	case 0:
		return (scc == 0);
	}
}

/*
 * Construct a matched name.
 */
D 3
addg(as1, as2, as3)
	char		*as1, *as2, *as3;
E 3
I 3
addg(dp, as1, as3, ap)
	struct direct	*dp;
	char		*as1, *as3;
	struct arglist	*ap;
E 3
{
	register char	*s1, *s2;
	register int	c;
I 3
	char		buf[BUFSIZ];
E 3

D 3
	if ((s2 = (char *)locstak()) == 0)
		return (-1);
	s2 += sizeof(char *);
E 3
I 3
	s2 = buf;
E 3
	s1 = as1;
	while (c = *s1++) {	
		if ((c &= 0177) == 0) {	
D 3
			*s2++='/';
E 3
I 3
			*s2++ = '/';
E 3
			break;
		}
		*s2++ = c;
	}
D 3
	s1 = as2;
E 3
I 3
	s1 = dp->d_name;
E 3
	while (*s2 = *s1++)
		s2++;
	if (s1 = as3) {	
		*s2++ = '/';
		while (*s2++ = *++s1)
			/* void */;
	}
D 3
	makearg(endstak(s2));
	return (0);
E 3
I 3
	if (mkentry(buf, dp->d_ino, ap) == FAIL)
		return (-1);
E 3
}

/*
D 3
 * Add a matched name to the list.
 */
makearg(args)
	register struct argnod *args;
{
	args->argnxt = gchain;
	gchain = args;
}

/*
 * set up stack for local use
 * should be followed by `endstak'
 */
struct argnod *
locstak()
{
	if (brkend - (char *)stakbot < 100) {	
		fprintf(stderr, "ran out of arg space\n");
		return (0);
	}
	return (stakbot);
}

/*
 * tidy up after `locstak'
 */
struct argnod *
endstak(argp)
	register char *argp;
{
	register struct argnod *oldstak;

	*argp++ = 0;
	oldstak = stakbot;
	stakbot = staktop = (struct argnod *)round((int)argp, sizeof(char *));
	return (oldstak);
E 2
}

/*
E 3
 * Do an "ls" style listing of a directory
 */
printlist(name, ino, basename)
	char *name;
	ino_t ino;
	char *basename;
{
	register struct afile *fp;
D 3
	struct afile *dfp0, *dfplast;
E 3
I 3
	register struct direct *dp;
	static struct arglist alist = { 0, 0, 0, 0, "ls" };
E 3
	struct afile single;
	DIR *dirp;

	if ((dirp = rst_opendir(name)) == NULL) {
		single.fnum = ino;
D 3
		single.fname = savename(name + strlen(basename));
		dfp0 = &single;
		dfplast = dfp0 + 1;
E 3
I 3
		single.fname = savename(name + strlen(basename) + 1);
		alist.head = &single;
		alist.last = alist.head + 1;
E 3
	} else {
D 3
		if (getdir(dirp, &dfp0, &dfplast) == FAIL)
			return;
E 3
I 3
		alist.head = (struct afile *)0;
		fprintf(stderr, "%s:\n", name);
		while (dp = rst_readdir(dirp)) {
			if (dp == NULL || dp->d_ino == 0)
				break;
			if (!dflag && BIT(dp->d_ino, dumpmap) == 0)
				continue;
			if (vflag == 0 &&
			    (strcmp(dp->d_name, ".") == 0 ||
			     strcmp(dp->d_name, "..") == 0))
				continue;
			if (!mkentry(dp->d_name, dp->d_ino, &alist))
				return;
		}
E 3
	}
D 3
	qsort((char *)dfp0, dfplast - dfp0, sizeof (struct afile), fcmp);
	formatf(dfp0, dfplast);
	for (fp = dfp0; fp < dfplast; fp++)
		freename(fp->fname);
E 3
I 3
	if (alist.head != 0) {
		qsort((char *)alist.head, alist.last - alist.head,
			sizeof *alist.head, fcmp);
		formatf(&alist);
		for (fp = alist.head; fp < alist.last; fp++)
			freename(fp->fname);
	}
	if (dirp != NULL)
		fprintf(stderr, "\n");
E 3
}

/*
 * Read the contents of a directory.
 */
D 3
getdir(dirp, pfp0, pfplast)
	DIR *dirp;
	struct afile **pfp0, **pfplast;
E 3
I 3
mkentry(name, ino, ap)
	char *name;
	ino_t ino;
	register struct arglist *ap;
E 3
{
	register struct afile *fp;
D 3
	register struct direct *dp;
	static struct afile *basefp = NULL;
	static long nent = 20;
E 3

D 3
	if (basefp == NULL) {
		basefp = (struct afile *)calloc((unsigned)nent,
E 3
I 3
	if (ap->base == NULL) {
		ap->nent = 20;
		ap->base = (struct afile *)calloc((unsigned)ap->nent,
E 3
			sizeof (struct afile));
D 3
		if (basefp == NULL) {
			fprintf(stderr, "ls: out of memory\n");
E 3
I 3
		if (ap->base == NULL) {
			fprintf(stderr, "%s: out of memory\n", ap->cmd);
E 3
			return (FAIL);
		}
	}
D 3
	fp = *pfp0 = basefp;
	*pfplast = *pfp0 + nent;
	while (dp = rst_readdir(dirp)) {
		if (dp == NULL || dp->d_ino == 0)
			break;
		if (!dflag && BIT(dp->d_ino, dumpmap) == 0)
			continue;
		if (vflag == 0 &&
		    (strcmp(dp->d_name, ".") == 0 ||
		     strcmp(dp->d_name, "..") == 0))
			continue;
		fp->fnum = dp->d_ino;
		fp->fname = savename(dp->d_name);
		fp++;
		if (fp == *pfplast) {
			basefp = (struct afile *)realloc((char *)basefp,
			    (unsigned)(2 * nent * sizeof (struct afile)));
			if (basefp == 0) {
				fprintf(stderr, "ls: out of memory\n");
				return (FAIL);
			}
			*pfp0 = basefp;
			fp = *pfp0 + nent;
			*pfplast = fp + nent;
			nent *= 2;
E 3
I 3
	if (ap->head == 0)
		ap->head = ap->last = ap->base;
	fp = ap->last;
	fp->fnum = ino;
	fp->fname = savename(name);
	fp++;
	if (fp == ap->head + ap->nent) {
		ap->base = (struct afile *)realloc((char *)ap->base,
		    (unsigned)(2 * ap->nent * sizeof (struct afile)));
		if (ap->base == 0) {
			fprintf(stderr, "%s: out of memory\n", ap->cmd);
			return (FAIL);
E 3
		}
I 3
		ap->head = ap->base;
		fp = ap->head + ap->nent;
		ap->nent *= 2;
E 3
	}
D 3
	*pfplast = fp;
E 3
I 3
	ap->last = fp;
E 3
	return (GOOD);
}

/*
 * Print out a pretty listing of a directory
 */
D 3
formatf(fp0, fplast)
	struct afile *fp0, *fplast;
E 3
I 3
formatf(ap)
	register struct arglist *ap;
E 3
{
	register struct afile *fp;
	struct entry *np;
D 3
	int width = 0, w, nentry = fplast - fp0;
E 3
I 3
	int width = 0, w, nentry = ap->last - ap->head;
E 3
	int i, j, len, columns, lines;
	char *cp;

D 3
	if (fp0 == fplast)
E 3
I 3
	if (ap->head == ap->last)
E 3
		return;
D 3
	for (fp = fp0; fp < fplast; fp++) {
E 3
I 3
	for (fp = ap->head; fp < ap->last; fp++) {
E 3
		fp->ftype = inodetype(fp->fnum);
		np = lookupino(fp->fnum);
		if (np != NIL)
			fp->fflags = np->e_flags;
		else
			fp->fflags = 0;
		len = strlen(fmtentry(fp));
		if (len > width)
			width = len;
	}
	width += 2;
	columns = 80 / width;
	if (columns == 0)
		columns = 1;
	lines = (nentry + columns - 1) / columns;
	for (i = 0; i < lines; i++) {
		for (j = 0; j < columns; j++) {
D 3
			fp = fp0 + j * lines + i;
E 3
I 3
			fp = ap->head + j * lines + i;
E 3
			cp = fmtentry(fp);
			fprintf(stderr, "%s", cp);
D 3
			if (fp + lines >= fplast) {
E 3
I 3
			if (fp + lines >= ap->last) {
E 3
				fprintf(stderr, "\n");
				break;
			}
			w = strlen(cp);
			while (w < width) {
				w++;
				fprintf(stderr, " ");
			}
		}
	}
}

/*
 * Comparison routine for qsort.
 */
fcmp(f1, f2)
	register struct afile *f1, *f2;
{

	return (strcmp(f1->fname, f2->fname));
}

/*
 * Format a directory entry.
 */
char *
fmtentry(fp)
	register struct afile *fp;
{
	static char fmtres[BUFSIZ];
I 9
	static int precision = 0;
	int i;
E 9
	register char *cp, *dp;

D 9
	if (vflag)
		(void) sprintf(fmtres, "%5d ", fp->fnum);
	else
E 9
I 9
	if (!vflag) {
E 9
		fmtres[0] = '\0';
I 9
	} else {
		if (precision == 0)
			for (i = maxino; i > 0; i /= 10)
				precision++;
		(void) sprintf(fmtres, "%*d ", precision, fp->fnum);
	}
E 9
	dp = &fmtres[strlen(fmtres)];
	if (dflag && BIT(fp->fnum, dumpmap) == 0)
		*dp++ = '^';
	else if ((fp->fflags & NEW) != 0)
		*dp++ = '*';
	else
		*dp++ = ' ';
	for (cp = fp->fname; *cp; cp++)
		if (!vflag && (*cp < ' ' || *cp >= 0177))
			*dp++ = '?';
		else
			*dp++ = *cp;
	if (fp->ftype == NODE)
		*dp++ = '/';
	*dp++ = 0;
	return (fmtres);
}

/*
 * respond to interrupts
 */
onintr()
{
	if (command == 'i')
		longjmp(reset, 1);
	if (reply("restore interrupted, continue") == FAIL)
		done(1);
}
E 1
