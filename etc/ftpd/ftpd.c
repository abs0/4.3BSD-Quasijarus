/*
 * Copyright (c) 1985 Regents of the University of California.
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
 */

#ifndef lint
char copyright[] =
"@(#) Copyright (c) 1985 Regents of the University of California.\n\
 All rights reserved.\n";
#endif /* not lint */

#ifndef lint
static char sccsid[] = "@(#)ftpd.c	5.24 (Berkeley) 4/16/11";
#endif /* not lint */

/*
 * FTP server.
 */
#include <sys/param.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/file.h>
#include <sys/wait.h>

#include <netinet/in.h>

#include <arpa/ftp.h>
#include <arpa/inet.h>
#include <arpa/telnet.h>

#include <stdio.h>
#include <signal.h>
#include <pwd.h>
#include <setjmp.h>
#include <netdb.h>
#include <errno.h>
#include <strings.h>
#include <syslog.h>

/*
 * File containing login names
 * NOT to be used on this machine.
 * Commonly used to disallow uucp.
 */
#define	FTPUSERS	"/etc/ftpusers"
/*
 * File containing pathnames that guest users can access. If not found, guest
 * users can do anything that file permissions allow.
 */
#define	ANONFTPALLOW	"/etc/anonftp.allow"
/*
 * We keep a buffer with pointers to pathnames read from the above file.
 * Allocate it 32 entries at a time (first malloc, then realloc).
 */
#define	GUESTDIRSINCR	32

/* Longest arglist we are willing to generate from globbing */
#define	GAVSIZ		(NCARGS/6)

char	version[] = "Version 5.24 April 16, 2011 00:35:58";

extern	int errno;
extern	char *sys_errlist[];
extern	char *crypt();
extern	FILE *popen(), *fopen(), *freopen();
extern	int  pclose(), fclose();
extern	char *alloca();
extern	char *getline();
extern	char cbuf[];
extern	int _pw_stayopen;
extern	int epsquota;

struct	sockaddr_in ctrl_addr;
struct	sockaddr_in data_source;
struct	sockaddr_in data_dest;
struct	sockaddr_in his_addr;

int	data;
jmp_buf	errcatch, urgcatch;
int	logged_in;
struct	passwd *pw;
int	debug;
int	timeout = 900;    /* timeout after 15 minutes of inactivity */
int	logging;
int	wtmp;
int	type;
int	form;
int	stru;			/* avoid C keyword */
int	mode;
int	usedefault = 1;		/* for data transfers */
int	pdata;			/* for passive mode */
int	transflag;
char	tmpline[7];
char	hostname[32];
char	remotehost[32];
char	**guestdirs;
int	nguestdirs;
int	authmode;
char	epsaccount[10];
int	chrooted;

#define	AUTHMODE_INIT	0
#define	AUTHMODE_USER	1
#define	AUTHMODE_GUEST	2
#define	AUTHMODE_EPS	3
#define	AUTHMODE_BAD	4

/*
 * Timeout intervals for retrying connections
 * to hosts that don't accept PORT cmds.  This
 * is a kludge, but given the problems with TCP...
 */
#define	SWAITMAX	90	/* wait at most 90 seconds */
#define	SWAITINT	5	/* interval between retries */

int	swaitmax = SWAITMAX;
int	swaitint = SWAITINT;

int	lostconn();
int	myoob();
FILE	*getdatasock(), *dataconn();
FILE	*mypopen();
int	mypclose();

main(argc, argv)
	int argc;
	char *argv[];
{
	int addrlen, on = 1;
	long pgid;
	char *cp;

	addrlen = sizeof (his_addr);
	if (getpeername(0, &his_addr, &addrlen) < 0) {
		syslog(LOG_ERR, "getpeername (%s): %m",argv[0]);
		exit(1);
	}
	addrlen = sizeof (ctrl_addr);
	if (getsockname(0, (char *) &ctrl_addr, &addrlen) < 0) {
		syslog(LOG_ERR, "getsockname (%s): %m",argv[0]);
		exit(1);
	}
	data_source.sin_port = htons(ntohs(ctrl_addr.sin_port) - 1);
	debug = 0;
	openlog("ftpd", LOG_PID|LOG_NDELAY, LOG_DAEMON);
	argc--, argv++;
	while (argc > 0 && *argv[0] == '-') {
		for (cp = &argv[0][1]; *cp; cp++) switch (*cp) {

		case 'v':
			debug = 1;
			break;

		case 'd':
			debug = 1;
			break;

		case 'l':
			logging = 1;
			break;

		case 't':
			timeout = atoi(++cp);
			goto nextopt;
			break;

		default:
			fprintf(stderr, "ftpd: Unknown flag -%c ignored.\n",
			     *cp);
			break;
		}
nextopt:
		argc--, argv++;
	}
	(void) freopen("/dev/null", "w", stderr);
	(void) signal(SIGPIPE, lostconn);
	(void) signal(SIGCHLD, SIG_IGN);
	if (signal(SIGURG, myoob) < 0) {
		syslog(LOG_ERR, "signal: %m");
	}
	/* handle urgent data inline */
#ifdef SO_OOBINLINE
	if (setsockopt(0, SOL_SOCKET, SO_OOBINLINE, (char *)&on, sizeof(on)) < 0) {
		syslog(LOG_ERR, "setsockopt: %m");
	}
#endif SO_OOBINLINE
	pgid = getpid();
	if (ioctl(fileno(stdin), SIOCSPGRP, (char *) &pgid) < 0) {
		syslog(LOG_ERR, "ioctl: %m");
	}
	dolog(&his_addr);
	/* do telnet option negotiation here */
	/*
	 * Set up default state
	 */
	logged_in = 0;
	data = -1;
	type = TYPE_A;
	form = FORM_N;
	stru = STRU_F;
	mode = MODE_S;
	tmpline[0] = '\0';
	(void) gethostname(hostname, sizeof (hostname));
	reply(220, "%s FTP server (%s) ready.",
		hostname, version);
	_pw_stayopen = 1;
	init_special_guests();
	for (;;) {
		(void) setjmp(errcatch);
		(void) yyparse();
	}
}

lostconn()
{

	if (debug)
		syslog(LOG_DEBUG, "lost connection");
	dologout(-1);
}

user(name)
	register char *name;
{
	/*
	 * RFC 959 allows us to change users, but doesn't
	 * require us to.  We used to support this, but it never
	 * worked right and now we have to block it altogether.
	 * 503 reply code is not in the table for USER, but RFC 1123
	 * relaxed rules let us use it.
	 */
	if (logged_in) {
		reply(503, "Changing USER is not supported.");
	} else if (strcmp(name, "ftp") == 0 || strcmp(name, "anonymous") == 0) {
		if ((pw = getpwnam("ftp")) != NULL) {
			authmode = AUTHMODE_GUEST;
			reply(331, "Guest login ok, send ident as password.");
		}
		else {
			reply(530, "No anonymous FTP service.");
		}
	} else if (pw = getpwnam(name)) {
		if (is_special_guest(name)) {
			authmode = AUTHMODE_GUEST;
			reply(331,
				"Special guest login ok, send dummy password.");
		} else if (checkuser(name)) {
			authmode = AUTHMODE_USER;
askpass:		reply(331, "Password required for %s.", name);
		} else
			reply(530, "User %s access denied.", name);
	} else if (isepsname(name) && !eps_readaccount(name)) {
		authmode = AUTHMODE_EPS;
		strcpy(epsaccount, name);
		goto askpass;
	} else {
		/*
		 * Don't tell them whether the username or the password is
		 * invalid.
		 */
		authmode = AUTHMODE_BAD;
		goto askpass;
	}
}

pass(passwd)
	char *passwd;
{
	char *xpasswd, *savestr();
	static struct passwd save;

	if (logged_in) {
		reply(503, "You are already logged in.");
		return;
	}
	switch (authmode) {
	case AUTHMODE_INIT:
		reply(503, "Login with USER first.");
		return;
	case AUTHMODE_USER:
		chrooted = 0;
		goto checkpass;
	case AUTHMODE_EPS:
		chrooted = 1;
	checkpass:
		xpasswd = crypt(passwd, pw->pw_passwd);
		/* The strcmp does not catch null passwords! */
		if (*pw->pw_passwd == '\0' || strcmp(xpasswd, pw->pw_passwd))
			goto badlogin;
		break;
	case AUTHMODE_GUEST:
		/* anonymous - anything goes for the password */
		if (strcmp(pw->pw_dir, "/"))
			chrooted = 1;
		else
			chrooted = 0;
		break;
	case AUTHMODE_BAD:
	badlogin:
		reply(530, "Login incorrect.");
		authmode = AUTHMODE_INIT;
		return;
	}
	setegid(pw->pw_gid);
	initgroups(pw->pw_name, pw->pw_gid);
	if (chdir(pw->pw_dir)) {
		reply(530, "User %s: can't change directory to %s.",
			pw->pw_name, pw->pw_dir);
		goto bad;
	}

	/* grab wtmp before chroot */
	if (authmode != AUTHMODE_EPS)
		wtmp = open("/usr/adm/wtmp", O_WRONLY|O_APPEND);
	if (chrooted && chroot(pw->pw_dir) < 0) {
		reply(530, "Can't set guest privileges.");
		if (wtmp >= 0) {
			(void) close(wtmp);
			wtmp = -1;
		}
		goto bad;
	}
	switch (authmode) {
	case AUTHMODE_USER:
		reply(230, "User %s logged in.", pw->pw_name);
		break;
	case AUTHMODE_GUEST:
		init_guest_dirs();
		reply(230, "Guest login ok, access restrictions apply.");
		break;
	case AUTHMODE_EPS:
		reply(230, "Logged into EPS account %s.", epsaccount);
		break;
	}
	logged_in = 1;
	if (authmode != AUTHMODE_EPS)
		dologin(pw);
	else
		syslog(LOG_INFO, "EPS session: account %s, connection from %s",
			epsaccount, remotehost);
	seteuid(pw->pw_uid);
	/*
	 * Save everything so globbing doesn't
	 * clobber the fields.
	 */
	save = *pw;
	save.pw_name = savestr(pw->pw_name);
	save.pw_passwd = savestr(pw->pw_passwd);
	save.pw_comment = savestr(pw->pw_comment);
	save.pw_gecos = savestr(pw->pw_gecos);
	save.pw_dir = savestr(pw->pw_dir);
	save.pw_shell = savestr(pw->pw_shell);
	pw = &save;
	return;
bad:
	seteuid(0);
	authmode = AUTHMODE_INIT;
}

char *
savestr(s)
	char *s;
{
	char *malloc();
	char *new = malloc((unsigned) strlen(s) + 1);

	if (new != NULL)
		(void) strcpy(new, s);
	return (new);
}

/*
 * Here is how we implement the list commands.
 *
 * First if a pathname is specified and it contains slash(es), we first chdir
 * to the last slash (rindex). No globbing is allowed before the last slash,
 * and we do the anonymous FTP protection at this point.
 *
 * After this we have four possibilities as far as the list spec goes: nothing,
 * a filename, a directory name, or a globbing pattern. If nothing, we ls the
 * current directory. If a subdirectory name, we ls that subdirectory. If a
 * single filename, we ls that (arguably not very useful). The last two cases
 * are distinguished by ls, not by us. The specified thing must exist (tested
 * by lstat) or we 550. Finally, if we have a globbing pattern (contains '*',
 * '?', '[', or '{'), we glob it. If we got nothing, we 550. Otherwise, we give
 * the list to ls with -d.
 */
list(spec)
	register char *spec;
{
	int p[2];
	char *dir = ".";
	int haveglob = 0;
	char *argv[GAVSIZ], **globvec;
	register int argc;
	register int i;
	register char *cp;
	register char **av;
	struct stat st;
	char flg;

	if (pipe(p) < 0) {
		reply(451, "System error: pipe: %s.", sys_errlist[errno]);
		return;
	}
	i = fork();
	if (i < 0) {
		reply(451, "System error: fork: %s.", sys_errlist[errno]);
		close(p[0]);
		close(p[1]);
		return;
	}
	if (i > 0) {
		close(p[1]);
		i = p[0];
		read(i, &flg, 1);
		if (flg) {
			close(i);
			goto out;
		}
		retrcore(fdopen(i, "r"), "file list", (off_t) -1);
out:		(void) wait();
		return;
	}
	close(p[0]);

	if (spec) {
		if (guestdirs && guest_check_pathname(spec)) {
			reply(550, "%s: %s.", spec, sys_errlist[EACCES]);
			goto childfail;
		}
		cp = rindex(spec, '/');
		if (cp) {
			if (cp == spec)
				dir = "/";
			else {
				*cp = '\0';
				dir = spec;
			}
			if (chdir(dir) < 0) {
				reply(550, "%s: %s.", dir, sys_errlist[errno]);
				goto childfail;
			}
			spec = cp + 1;
		}
		haveglob = isaglob(spec);
	}

	argv[0] = "ls";
	argc = 1;
	if (spec == NULL || *spec == '\0')
		goto doit;
	if (!haveglob) {
		if (lstat(spec, &st) < 0) {
			reply(550, "%s: %s.", spec, sys_errlist[errno]);
			goto childfail;
		}
		argv[argc++] = spec;
		goto doit;
	}
	globvec = argv + argc;
	i = glob(spec, globvec, GAVSIZ - argc - 1);
	if (i < 0) {
		reply(550, "%s: %s.", dir, sys_errlist[errno]);
		goto childfail;
	}
	if (i == 0) {
		reply(550, "%s: No match.", spec);
		goto childfail;
	}
	argc += i;

doit:	flg = 0;
	argv[argc] = NULL;
	dup2(p[1], 1);
	dup2(p[1], 2);
	close(p[1]);
	write(1, &flg, 1);
	exit(ls(haveglob, argc, argv));

childfail:
	flg = 1;
	write(p[1], &flg, 1);
	exit(1);
}

retrieve(cmd, name)
	char *cmd, *name;
{
	FILE *fin, *dout;
	struct stat st;
	int (*closefunc)(), tmp;
	char **argv = (char **) name;
#ifdef GZCOMPAT
	char *gzcompat_argv[3];
#endif

retry:
	if (cmd == 0) {
#ifdef notdef
		/* no remote command execution -- it's a security hole */
		if (*name == '|')
			fin = popen(name + 1, "r"), closefunc = pclose;
		else
#endif
		{
			if (guestdirs && guest_check_pathname(name))
				fin = NULL, errno = EACCES;
			else
				fin = fopen(name, "r"), closefunc = fclose;
		}
	} else {
		fin = mypopen(cmd, argv, "r"), closefunc = mypclose;
		name = cmd;
	}
	if (fin == NULL) {
#ifdef GZCOMPAT
		if (cmd == NULL && errno == ENOENT && !chrooted) {
			int namelen;
			char *newname;

			namelen = strlen(name);
			if (namelen > 2 && name[namelen-2] == '.'
			  && name[namelen-1] == 'Z') {
				newname = alloca(namelen + 2);
				strncpy(newname, name, namelen - 2);
				strcat(newname, ".gz");
			} else if (namelen > 3 && name[namelen-3] == '.'
			  && name[namelen-2] == 'g' && name[namelen-1] == 'z') {
				newname = alloca(namelen);
				strncpy(newname, name, namelen - 3);
				strcat(newname, ".Z");
			} else
				goto bailout;
			if (stat(newname, &st) < 0
			    || (st.st_mode&S_IFMT) != S_IFREG)
				goto bailout;
			cmd = "/usr/ucb/gzcompat";
			argv = gzcompat_argv;
			argv[0] = "gzcompat";
			argv[1] = newname;
			argv[2] = NULL;
			goto retry;
bailout:		errno = ENOENT;
		}
#endif
		if (errno != 0)
			reply(550, "%s: %s.", name, sys_errlist[errno]);
		return;
	}
	st.st_size = -1;
	if (cmd == 0 &&
	    (stat(name, &st) < 0 || (st.st_mode&S_IFMT) != S_IFREG)) {
		reply(550, "%s: not a plain file.", name);
		goto done;
	}
	dout = dataconn(name, st.st_size, "w");
	if (dout == NULL)
		goto done;
	if ((tmp = send_data(fin, dout)) > 0 || ferror(dout) > 0) {
		reply(550, "%s: %s.", name, sys_errlist[errno]);
	}
	else if (tmp == 0) {
		reply(226, "Transfer complete.");
	}
	(void) fclose(dout);
	data = -1;
	pdata = -1;
done:
	(*closefunc)(fin);
}

retrcore(fin, name, size)
	FILE *fin;
	char *name;
	off_t size;
{
	FILE *dout;
	int tmp;

	dout = dataconn(name, size, "w");
	if (dout == NULL)
		goto done;
	if ((tmp = send_data(fin, dout)) > 0 || ferror(dout) > 0) {
		reply(550, "%s: %s.", name, sys_errlist[errno]);
	}
	else if (tmp == 0) {
		reply(226, "Transfer complete.");
	}
	(void) fclose(dout);
	data = -1;
	pdata = -1;
done:
	(void) fclose(fin);
}

store(name, mode)
	char *name, *mode;
{
	FILE *fout, *din;
	int (*closefunc)(), dochown = 0, tmp, localcnt = 0;
	char *local, localname[MAXPATHLEN], *localtail;

	if (authmode == AUTHMODE_EPS && !epsquota) {
		reply(550, "This EPS account is read-only.");
		return;
	}
#ifdef notdef
	/* no remote command execution -- it's a security hole */
	if (name[0] == '|')
		fout = popen(&name[1], "w"), closefunc = pclose;
	else
#endif
	{
		if (guestdirs != NULL && guest_check_pathname(name)) {
			reply(553, "%s: %s.", name, sys_errlist[EACCES]);
			return;
		}
		local = name;
openretry:
		tmp = open(local, O_CREAT | O_EXCL | O_WRONLY, 0666);
		if (tmp >= 0) {
			dochown++;
			goto openok;
		}
		if (errno != EEXIST) {
			reply(553, "%s: %s.", local, sys_errlist[errno]);
			return;
		}
		switch (*mode) {
		case 'w':
			tmp = open(local, O_TRUNC | O_WRONLY);
			break;
		case 'a':
			tmp = open(local, O_WRONLY);
			break;
		case 'u':
			if (!localcnt) {
				if (strlen(name) > MAXPATHLEN - 4) {
					reply(553, "%s: %s.", name,
					      sys_errlist[ENAMETOOLONG]);
					return;
				}
				strcpy(localname, name);
				local = localname;
				localtail = index(local, '\0');
			}
			if (++localcnt == 100) {
				reply(452,
				      "Unique file name cannot be created.");
				return;
			}
			sprintf(localtail, ".%d", localcnt);
			goto openretry;
		}
		if (tmp < 0) {
			reply(553, "%s: %s.", local, sys_errlist[errno]);
			return;
		}
openok:
		fout = fdopen(tmp, *mode == 'u' ? "w" : mode);
		closefunc = fclose;
	}
	if (fout == NULL) {
		reply(553, "%s: %s.", local, sys_errlist[errno]);
		return;
	}
	din = dataconn(local, (off_t)-1, "r");
	if (din == NULL)
		goto done;
	if ((tmp = receive_data(din, fout)) > 0 || ferror(fout) > 0) {
		reply(552, "%s: %s.", local, sys_errlist[errno]);
	}
	else if (tmp == 0 && *mode != 'u') {
		reply(226, "Transfer complete.");
	}
	else if (tmp == 0 && *mode == 'u') {
		reply(226, "Transfer complete (unique file name:%s).", local);
	}
	(void) fclose(din);
	data = -1;
	pdata = -1;
done:
	if (dochown)
		(void) chown(local, pw->pw_uid, -1);
	(*closefunc)(fout);
}

FILE *
getdatasock(mode)
	char *mode;
{
	int s, on = 1;

	if (data >= 0)
		return (fdopen(data, mode));
	s = socket(AF_INET, SOCK_STREAM, 0);
	if (s < 0)
		return (NULL);
	seteuid(0);
	if (setsockopt(s, SOL_SOCKET, SO_REUSEADDR, (char *) &on, sizeof (on)) < 0)
		goto bad;
	/* anchor socket to avoid multi-homing problems */
	data_source.sin_family = AF_INET;
	data_source.sin_addr = ctrl_addr.sin_addr;
	if (bind(s, &data_source, sizeof (data_source)) < 0)
		goto bad;
	seteuid(pw->pw_uid);
	return (fdopen(s, mode));
bad:
	seteuid(pw->pw_uid);
	(void) close(s);
	return (NULL);
}

FILE *
dataconn(name, size, mode)
	char *name;
	off_t size;
	char *mode;
{
	char sizebuf[32];
	FILE *file;
	int retry = 0;

	if (size >= 0)
		(void) sprintf (sizebuf, " (%ld bytes)", size);
	else
		(void) strcpy(sizebuf, "");
	if (pdata > 0) {
		struct sockaddr_in from;
		int s, fromlen = sizeof(from);

		s = accept(pdata, &from, &fromlen);
		if (s < 0) {
			reply(425, "Can't open data connection.");
			(void) close(pdata);
			pdata = -1;
			return(NULL);
		}
		(void) close(pdata);
		pdata = s;
		reply(150, "Opening data connection for %s (%s,%d)%s.",
		     name, inet_ntoa(from.sin_addr),
		     ntohs(from.sin_port), sizebuf);
		return(fdopen(pdata, mode));
	}
	if (data >= 0) {
		reply(125, "Using existing data connection for %s%s.",
		    name, sizebuf);
		usedefault = 1;
		return (fdopen(data, mode));
	}
	if (usedefault)
		data_dest = his_addr;
	usedefault = 1;
	file = getdatasock(mode);
	if (file == NULL) {
		reply(425, "Can't create data socket (%s,%d): %s.",
		    inet_ntoa(data_source.sin_addr),
		    ntohs(data_source.sin_port),
		    sys_errlist[errno]);
		return (NULL);
	}
	data = fileno(file);
	while (connect(data, &data_dest, sizeof (data_dest)) < 0) {
		if (errno == EADDRINUSE && retry < swaitmax) {
			sleep((unsigned) swaitint);
			retry += swaitint;
			continue;
		}
		reply(425, "Can't build data connection: %s.",
		    sys_errlist[errno]);
		(void) fclose(file);
		data = -1;
		return (NULL);
	}
	reply(150, "Opening data connection for %s (%s,%d)%s.",
	    name, inet_ntoa(data_dest.sin_addr),
	    ntohs(data_dest.sin_port), sizebuf);
	return (file);
}

/*
 * Tranfer the contents of "instr" to
 * "outstr" peer using the appropriate
 * encapulation of the date subject
 * to Mode, Structure, and Type.
 *
 * NB: Form isn't handled.
 */
send_data(instr, outstr)
	FILE *instr, *outstr;
{
	register int c;
	int netfd, filefd, cnt;
	char buf[BUFSIZ];

	transflag++;
	if (setjmp(urgcatch)) {
		transflag = 0;
		return(-1);
	}
	switch (type) {

	case TYPE_A:
		while ((c = getc(instr)) != EOF) {
			if (c == '\n') {
				if (ferror (outstr)) {
					transflag = 0;
					return (1);
				}
				(void) putc('\r', outstr);
			}
			(void) putc(c, outstr);
		/*	if (c == '\r')			*/
		/*		putc ('\0', outstr);	*/
		}
		transflag = 0;
		if (ferror (instr) || ferror (outstr)) {
			return (1);
		}
		return (0);
		
	case TYPE_I:
	case TYPE_L:
		netfd = fileno(outstr);
		filefd = fileno(instr);

		while ((cnt = read(filefd, buf, sizeof (buf))) > 0) {
			if (write(netfd, buf, cnt) < 0) {
				transflag = 0;
				return (1);
			}
		}
		transflag = 0;
		return (cnt < 0);
	}
	reply(550, "Unimplemented TYPE %d in send_data", type);
	transflag = 0;
	return (-1);
}

/*
 * Transfer data from peer to
 * "outstr" using the appropriate
 * encapulation of the data subject
 * to Mode, Structure, and Type.
 *
 * N.B.: Form isn't handled.
 */
receive_data(instr, outstr)
	FILE *instr, *outstr;
{
	register int c;
	int cnt;
	char buf[BUFSIZ];


	transflag++;
	if (setjmp(urgcatch)) {
		transflag = 0;
		return(-1);
	}
	switch (type) {

	case TYPE_I:
	case TYPE_L:
		while ((cnt = read(fileno(instr), buf, sizeof buf)) > 0) {
			if (write(fileno(outstr), buf, cnt) < 0) {
				transflag = 0;
				return (1);
			}
		}
		transflag = 0;
		return (cnt < 0);

	case TYPE_E:
		reply(553, "TYPE E not implemented.");
		transflag = 0;
		return (-1);

	case TYPE_A:
		while ((c = getc(instr)) != EOF) {
			while (c == '\r') {
				if (ferror (outstr)) {
					transflag = 0;
					return (1);
				}
				if ((c = getc(instr)) != '\n')
					(void) putc ('\r', outstr);
			/*	if (c == '\0')			*/
			/*		continue;		*/
			}
			(void) putc (c, outstr);
		}
		transflag = 0;
		if (ferror (instr) || ferror (outstr))
			return (1);
		return (0);
	}
	transflag = 0;
	fatal("Unknown type in receive_data.");
	/*NOTREACHED*/
}

fatal(s)
	char *s;
{
	reply(451, "Error in server: %s\n", s);
	reply(221, "Closing connection due to server error.");
	dologout(0);
}

reply(n, s, p0, p1, p2, p3, p4, p5)
	int n;
	char *s;
{

	printf("%d ", n);
	printf(s, p0, p1, p2, p3, p4, p5);
	printf("\r\n");
	(void) fflush(stdout);
	if (debug) {
		syslog(LOG_DEBUG, "<--- %d ", n);
		syslog(LOG_DEBUG, s, p0, p1, p2, p3, p4, p5);
	}
}

lreply(n, s, p0, p1, p2, p3, p4, p5)
	int n;
	char *s;
{
	printf("%d-", n);
	printf(s, p0, p1, p2, p3, p4, p5);
	printf("\r\n");
	(void) fflush(stdout);
	if (debug) {
		syslog(LOG_DEBUG, "<--- %d- ", n);
		syslog(LOG_DEBUG, s, p0, p1, p2, p3, p4, p5);
	}
}

ack(s)
	char *s;
{
	reply(250, "%s command successful.", s);
}

nack(s)
	char *s;
{
	reply(502, "%s command not implemented.", s);
}

yyerror(s)
	char *s;
{
	char *cp;

	cp = index(cbuf,'\n');
	*cp = '\0';
	reply(500, "'%s': command not understood.",cbuf);
}

delete(name)
	char *name;
{
	struct stat st;

	if (authmode == AUTHMODE_GUEST || authmode == AUTHMODE_EPS) {
		reply(550, "Guest users are not allowed to delete files.");
		return;
	}
	if (guestdirs != NULL && guest_check_pathname(name)) {
		reply(550, "%s: %s.", name, sys_errlist[EACCES]);
		return;
	}
	if (stat(name, &st) < 0) {
		reply(550, "%s: %s.", name, sys_errlist[errno]);
		return;
	}
	if ((st.st_mode&S_IFMT) == S_IFDIR) {
		if (rmdir(name) < 0) {
			reply(550, "%s: %s.", name, sys_errlist[errno]);
			return;
		}
		goto done;
	}
	if (unlink(name) < 0) {
		reply(550, "%s: %s.", name, sys_errlist[errno]);
		return;
	}
done:
	ack("DELE");
}

cwd(path)
	char *path;
{
	if (guestdirs != NULL && guest_check_pathname(path)) {
		reply(550, "%s: %s.", path, sys_errlist[EACCES]);
		return;
	}
	if (chdir(path) < 0) {
		reply(550, "%s: %s.", path, sys_errlist[errno]);
		return;
	}
	ack("CWD");
}

makedir(name)
	char *name;
{
	if (authmode == AUTHMODE_GUEST || authmode == AUTHMODE_EPS) {
		reply(550,
			"Guest users are not allowed to create directories.");
		return;
	}
	if (mkdir(name, 0777) < 0) {
		reply(550, "%s: %s.", name, sys_errlist[errno]);
		return;
	}
	(void) chown(name, pw->pw_uid, -1);
	reply(257, "MKD command successful.");
}

removedir(name)
	char *name;
{
	if (authmode == AUTHMODE_GUEST || authmode == AUTHMODE_EPS) {
		reply(550,
			"Guest users are not allowed to delete directories.");
		return;
	}
	if (rmdir(name) < 0) {
		reply(550, "%s: %s.", name, sys_errlist[errno]);
		return;
	}
	ack("RMD");
}

pwd()
{
	char path[MAXPATHLEN];

	if (getwd(path) == NULL) {
		reply(550, "%s.", path);
		return;
	}
	reply(257, "\"%s\" is current directory.", path);
}

char *
renamefrom(name)
	char *name;
{
	struct stat st;

	if (authmode == AUTHMODE_GUEST || authmode == AUTHMODE_EPS) {
		reply(550, "Guest users are not allowed to rename files.");
		return;
	}
	if (stat(name, &st) < 0) {
		reply(550, "%s: %s.", name, sys_errlist[errno]);
		return ((char *)0);
	}
	reply(350, "File exists, ready for destination name");
	return (name);
}

renamecmd(from, to)
	char *from, *to;
{
	if (rename(from, to) < 0) {
		reply(550, "rename: %s.", sys_errlist[errno]);
		return;
	}
	ack("RNTO");
}

dolog(sin)
	struct sockaddr_in *sin;
{
	struct hostent *hp = gethostbyaddr(&sin->sin_addr,
		sizeof (struct in_addr), AF_INET);
	time_t t;
	extern char *ctime();

	if (hp) {
		(void) strncpy(remotehost, hp->h_name, sizeof (remotehost));
		endhostent();
	} else
		(void) strncpy(remotehost, inet_ntoa(sin->sin_addr),
		    sizeof (remotehost));
	if (!logging)
		return;
	t = time((time_t *) 0);
	syslog(LOG_INFO,"FTPD: connection from %s at %s", remotehost, ctime(&t));
}

#include <utmp.h>

#define	SCPYN(a, b)	(void) strncpy(a, b, sizeof (a))
struct	utmp utmp;

/*
 * Record login in wtmp file.
 */
dologin(pw)
	struct passwd *pw;
{
	char line[32];

	if (wtmp >= 0) {
		/* hack, but must be unique and no tty line */
		(void) sprintf(line, "ftp%d", getpid());
		SCPYN(utmp.ut_line, line);
		SCPYN(utmp.ut_name, pw->pw_name);
		SCPYN(utmp.ut_host, remotehost);
		utmp.ut_time = (long) time((time_t *) 0);
		(void) write(wtmp, (char *)&utmp, sizeof (utmp));
		if (!chrooted) {		/* anon must hang on */
			(void) close(wtmp);
			wtmp = -1;
		}
	}
}

/*
 * Record logout in wtmp file
 * and exit with supplied status.
 */
dologout(status)
	int status;
{
	if (logged_in && authmode != AUTHMODE_EPS) {
		if (guestdirs)
			free_guest_dirs();
		(void) seteuid(0);
		if (wtmp < 0)
			wtmp = open("/usr/adm/wtmp", O_WRONLY|O_APPEND);
		if (wtmp >= 0) {
			SCPYN(utmp.ut_name, "");
			SCPYN(utmp.ut_host, "");
			utmp.ut_time = (long) time((time_t *) 0);
			(void) write(wtmp, (char *)&utmp, sizeof (utmp));
			(void) close(wtmp);
		}
	}
	/* beware of flushing buffers after a SIGPIPE */
	_exit(status);
}

/*
 * Special version of popen which avoids
 * call to shell.  This insures noone may 
 * create a pipe to a hidden program as a side
 * effect of a list or dir command.
 *
 * This version is also more efficient and
 * convenient for us as it takes ready argv,
 * which is what globbing gives us.
 */
#define	tst(a,b)	(*mode == 'r'? (b) : (a))
#define	RDR	0
#define	WTR	1
static	int popen_pid[20];

FILE *
mypopen(cmd, argv, mode)
	char *cmd, **argv, *mode;
{
	int p[2];
	register myside, hisside, pid;
	register char *cp;

	if (pipe(p) < 0)
		return (NULL);
	myside = tst(p[WTR], p[RDR]);
	hisside = tst(p[RDR], p[WTR]);
	if ((pid = vfork()) == 0) {
		/* myside and hisside reverse roles in child */
		(void) close(myside);
		(void) dup2(hisside, tst(0, 1));
		(void) close(hisside);
		execv(cmd, argv);
		_exit(1);
	}
	if (pid == -1)
		return (NULL);
	popen_pid[myside] = pid;
	(void) close(hisside);
	return (fdopen(myside, mode));
}

mypclose(ptr)
	FILE *ptr;
{
	register f, r, (*hstat)(), (*istat)(), (*qstat)();
	int status;

	f = fileno(ptr);
	(void) fclose(ptr);
	istat = signal(SIGINT, SIG_IGN);
	qstat = signal(SIGQUIT, SIG_IGN);
	hstat = signal(SIGHUP, SIG_IGN);
	while ((r = wait(&status)) != popen_pid[f] && r != -1)
		;
	if (r == -1)
		status = -1;
	(void) signal(SIGINT, istat);
	(void) signal(SIGQUIT, qstat);
	(void) signal(SIGHUP, hstat);
	return (status);
}

/*
 * Check user requesting login priviledges.
 * Disallow anyone who does not have a standard
 * shell returned by getusershell() (/etc/shells).
 * Disallow anyone mentioned in the file FTPUSERS
 * to allow people such as uucp to be avoided.
 */
checkuser(name)
	register char *name;
{
	register char *cp;
	char line[BUFSIZ], *getusershell();
	FILE *fd;
	int found = 0;

	if (pw ->pw_shell == NULL || pw->pw_shell[0] == NULL)
		pw->pw_shell = "/bin/sh";
	while ((cp = getusershell()) != NULL)
		if (strcmp(cp, pw->pw_shell) == 0)
			break;
	endusershell();
	if (cp == NULL)
		return (0);
	fd = fopen(FTPUSERS, "r");
	if (fd == NULL)
		return (1);
	while (fgets(line, sizeof (line), fd) != NULL) {
		cp = index(line, '\n');
		if (cp)
			*cp = '\0';
		if (strcmp(line, name) == 0) {
			found++;
			break;
		}
	}
	(void) fclose(fd);
	return (!found);
}

myoob()
{
	char *cp;

	/* only process if transfer occurring */
	if (!transflag) {
		return;
	}
	cp = tmpline;
	if (getline(cp, 7, stdin) == NULL) {
		reply(221, "You could at least say goodbye.");
		dologout(0);
	}
	upper(cp);
	if (strcmp(cp, "ABOR\r\n"))
		return;
	tmpline[0] = '\0';
	reply(426,"Transfer aborted. Data connection closed.");
	reply(226,"Abort successful");
	longjmp(urgcatch, 1);
}

/*
 * Note: The 530 reply codes could be 4xx codes, except nothing is
 * given in the state tables except 421 which implies an exit.  (RFC959)
 */
passive()
{
	int len;
	struct sockaddr_in tmp;
	register char *p, *a;

	pdata = socket(AF_INET, SOCK_STREAM, 0);
	if (pdata < 0) {
		reply(530, "Can't open passive connection");
		return;
	}
	tmp = ctrl_addr;
	tmp.sin_port = 0;
	seteuid(0);
	if (bind(pdata, (struct sockaddr *) &tmp, sizeof(tmp)) < 0) {
		seteuid(pw->pw_uid);
		(void) close(pdata);
		pdata = -1;
		reply(530, "Can't open passive connection");
		return;
	}
	seteuid(pw->pw_uid);
	len = sizeof(tmp);
	if (getsockname(pdata, (char *) &tmp, &len) < 0) {
		(void) close(pdata);
		pdata = -1;
		reply(530, "Can't open passive connection");
		return;
	}
	if (listen(pdata, 1) < 0) {
		(void) close(pdata);
		pdata = -1;
		reply(530, "Can't open passive connection");
		return;
	}
	a = (char *) &tmp.sin_addr;
	p = (char *) &tmp.sin_port;

#define UC(b) (((int) b) & 0xff)

	reply(227, "Entering Passive Mode (%d,%d,%d,%d,%d,%d)", UC(a[0]),
		UC(a[1]), UC(a[2]), UC(a[3]), UC(p[0]), UC(p[1]));
}

/*
 * The following functions implement the logic for restricting the set of
 * directories that anonymous users can access to less than all world-readable
 * directories without chrooting. This is accomplished by listing the allowed
 * directories in /etc/anonftp.allow as absolute pathnames. Their parent
 * directories are also necessarily accessible, as are their subdirectories,
 * unless the listed pathname ends with a slash. All files in an accessible
 * directory are also accessible. However, directories that are not children of
 * an explicitly listed allowed directory, but are children of a parent
 * directory of one, are NOT accessible.
 */

init_guest_dirs()
{
	FILE *fd;
	int nalloc;
	char line[MAXPATHLEN + 1];

	fd = fopen(ANONFTPALLOW, "r");
	if (fd == NULL)
		return;
	guestdirs = (char **) malloc(sizeof(char *) * GUESTDIRSINCR);
	if (guestdirs == NULL)
		return;
	bzero((char *) guestdirs, sizeof(char *) * GUESTDIRSINCR);
	nguestdirs = 0;
	nalloc = GUESTDIRSINCR;
	while (fgets(line, sizeof(line), fd) != NULL) {
		char *copy, *cp;

		cp = index(line, '\n');
		if (cp)
			*cp = '\0';
		else
			break;
		if (line[0] != '/')
			continue;
		if (nguestdirs == nalloc) {
			guestdirs = (char **) realloc((char *) guestdirs,
					sizeof(char *) *
					(nalloc + GUESTDIRSINCR));
			if (guestdirs == NULL)
				break;
			bzero((char *) guestdirs + sizeof(char *) * nalloc,
			      sizeof(char *) * GUESTDIRSINCR);
			nalloc += GUESTDIRSINCR;
		}
		copy = malloc(strlen(line) + 1);
		if (copy == NULL)
			break;
		strcpy(copy, line);
		guestdirs[nguestdirs++] = copy;
	}
	(void) fclose(fd);
}

free_guest_dirs()
{
	int i;

	for (i = 0; i < nguestdirs; i++)
		free(guestdirs[i]);
	free((char *) guestdirs);
	guestdirs = NULL;
}

guest_check_curdir()
{
	char curdir[MAXPATHLEN];
	int i;

	getwd(curdir);
	if (!strcmp(curdir, "/"))
		return(0);
	for (i = 0; i < nguestdirs; i++) {
		char *cp1 = curdir, *cp2 = guestdirs[i];

		while (*cp1 == *cp2 && *cp1 != '\0')
			cp1++, cp2++;
		if (*cp1 == '\0' && *cp2 == '\0')
			return(0);
		if (*cp1 == '\0' && *cp2 == '/')
			return(0);
		if (*cp1 == '/' && *cp2 == '\0')
			return(0);
	}
	return(1);
}

guest_check_pathname(pathname)
	char *pathname;
{
	char origdir[MAXPATHLEN];
	char *comp, *slash;
	int status;

	getwd(origdir);
	if (pathname[0] == '/')
		chdir("/");
	for (comp = pathname; ; comp = slash) {
		while (*comp == '/')
			comp++;
		if (*comp == '\0')
			break;
		slash = index(comp, '/');
		if (slash != NULL)
			*slash = '\0';
		status = chdir(comp);
		if (slash != NULL)
			*slash = '/';
		if (status)
			break;
		if (guest_check_curdir()) {
			chdir(origdir);
			return(1);
		}
		if (slash == NULL)
			break;
	}
	chdir(origdir);
	return(0);
}
