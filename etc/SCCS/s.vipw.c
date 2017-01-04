h55722
s 00010/00005/00232
d D 5.5 88/06/18 14:34:58 bostic 12 11
c install approved copyright notice
e
s 00011/00005/00226
d D 5.4 88/02/19 11:12:55 bostic 11 10
c added Berkeley specific header
e
s 00097/00043/00134
d D 5.3 87/11/23 21:21:35 bostic 10 9
c fix uid/gid rollover; check all password entries for correctness; 
c bug reports 4.3BSD/etc/100, 4.3BSD/sys/176
e
s 00124/00126/00053
d D 5.2 87/07/01 16:49:22 bostic 9 8
c well, it started 'cause vipw should realize that you haven't 
c modified the file and kind of got out of control.  
e
s 00013/00001/00166
d D 5.1 85/05/28 15:43:49 dist 8 7
c Add copyright
e
s 00001/00001/00166
d D 4.7 85/02/24 12:25:18 bloom 7 6
c strncmp requires 3 arguments
e
s 00000/00001/00167
d D 4.6 84/02/27 16:13:42 ralph 6 5
c don't trap SIGTSTP.
e
s 00010/00007/00158
d D 4.5 83/12/02 17:53:11 ralph 5 4
c unlink .pag and .dir; trap SIGTSTP.
e
s 00027/00001/00138
d D 4.4 83/12/01 16:57:17 ralph 4 3
c changed to build passwd.pag and passwd.dir
e
s 00003/00000/00136
d D 4.3 83/10/04 15:10:00 ralph 3 2
c fixed exit codes
e
s 00001/00000/00135
d D 4.2 83/09/07 09:19:05 ralph 2 1
c added umask(0) so mode of /etc/passwd will be correct
e
s 00135/00000/00000
d D 4.1 83/07/03 01:53:35 sam 1 0
c date and time created 83/07/03 01:53:35 by sam
e
u
U
t
T
I 8
/*
D 9
 * Copyright (c) 1980 Regents of the University of California.
E 9
I 9
 * Copyright (c) 1987 Regents of the University of California.
E 9
D 11
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 11
I 11
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 12
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 12
I 12
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
E 12
E 11
 */

E 8
I 1
#ifndef lint
I 8
char copyright[] =
D 9
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
E 9
I 9
"%Z% Copyright (c) 1987 Regents of the University of California.\n\
E 9
 All rights reserved.\n";
D 10
#endif not lint
E 10
I 10
D 11
#endif /* !lint */
E 11
I 11
#endif /* not lint */
E 11
E 10

#ifndef lint
E 8
static char sccsid[] = "%W% (Berkeley) %G%";
D 8
#endif
E 8
I 8
D 10
#endif not lint
E 10
I 10
D 11
#endif /* !lint */
E 11
I 11
#endif /* not lint */
E 11
E 10
E 8

I 10
#include <machine/machparam.h>
E 10
#include <sys/types.h>
#include <sys/stat.h>
I 10
#include <sys/signal.h>
E 10
#include <sys/file.h>
D 9

E 9
#include <stdio.h>
#include <errno.h>
D 10
#include <signal.h>
E 10

/*
 * Password file editor with locking.
 */
D 5
char	*temp = "/etc/ptmp";
I 4
char	*temp_pag = "/etc/ptmp.pag";
char	*temp_dir = "/etc/ptmp.dir";
E 4
char	*passwd = "/etc/passwd";
I 4
char	*passwd_pag = "/etc/passwd.pag";
char	*passwd_dir = "/etc/passwd.dir";
E 5
I 5
D 9
char	temp[] = "/etc/ptmp";
char	temp_pag[] = "/etc/ptmp.pag";
char	temp_dir[] = "/etc/ptmp.dir";
char	passwd[] = "/etc/passwd";
char	passwd_pag[] = "/etc/passwd.pag";
char	passwd_dir[] = "/etc/passwd.dir";
E 5
E 4
char	buf[BUFSIZ];
char	*getenv();
char	*index();
extern	int errno;
E 9
I 9
D 10
static char	*passwd = "/etc/passwd",
		buf[BUFSIZ];
E 10
I 10
static char	*passwd = "/etc/passwd", buf[BUFSIZ];
E 10
E 9

D 9
main(argc, argv)
	char *argv[];
E 9
I 9
main()
E 9
{
D 9
	int fd;
	FILE *ft, *fp;
	char *editor;
E 9
I 9
D 10
	register int	n, fd_passwd, fd_temp;
	static char	*temp = "/etc/ptmp";
	struct stat	s1, s2;
	char	*editor,
		*getenv();
E 10
I 10
	register int n, fd_passwd, fd_temp;
	static char *temp = "/etc/ptmp";
	struct stat s1, s2;
D 11
	char	*editor, *getenv();
E 11
I 11
	char *editor, *getenv();
E 11
E 10
E 9

I 5
D 9
	signal(SIGHUP, SIG_IGN);
E 5
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
D 5
	signal(SIGHUP, SIG_IGN);
E 5
I 5
D 6
	signal(SIGTSTP, SIG_IGN);
E 6
E 5
	setbuf(stderr, NULL);
E 9
I 9
	(void)signal(SIGHUP, SIG_IGN);
	(void)signal(SIGINT, SIG_IGN);
	(void)signal(SIGQUIT, SIG_IGN);

	setbuf(stderr, (char *)NULL);
E 9
I 2
D 10
	umask(0);
E 10
I 10
	(void)umask(0);
E 10
E 2
D 9
	fd = open(temp, O_WRONLY|O_CREAT|O_EXCL, 0644);
	if (fd < 0) {
E 9
I 9

	if ((fd_passwd = open(passwd, O_RDONLY, 0)) < 0) {
D 10
		fprintf(stderr, "vipw: ");
E 10
I 10
		fputs("vipw: ", stderr);
E 10
		perror(passwd);
		exit(1);
	}
	if ((fd_temp = open(temp, O_WRONLY|O_CREAT|O_EXCL, 0644)) < 0) {
		extern int errno;

E 9
		if (errno == EEXIST) {
D 9
			fprintf(stderr, "vipw: password file busy\n");
E 9
I 9
D 10
			fputs("vipw: password file busy\n", stderr);
E 10
I 10
			fputs("vipw: password file busy.\n", stderr);
E 10
E 9
			exit(1);
		}
D 9
		fprintf(stderr, "vipw: "); perror(temp);
E 9
I 9
D 10
		fprintf(stderr, "vipw: ");
E 10
I 10
		fputs("vipw: ", stderr);
E 10
		perror(temp);
E 9
		exit(1);
	}
D 9
	ft = fdopen(fd, "w");
	if (ft == NULL) {
		fprintf(stderr, "vipw: "); perror(temp);
E 9
I 9
	while ((n = read(fd_passwd, buf, sizeof(buf))) > 0)
		if (write(fd_temp, buf, n) != n) {
			perror("vipw: write");
			goto bad;
		}
	if (n == -1) {
		perror("vipw: read");
E 9
		goto bad;
	}
D 9
	fp = fopen(passwd, "r");
	if (fp == NULL) {
		fprintf(stderr, "vipw: "); perror(passwd);
E 9
I 9
	(void)close(fd_passwd);
	if (fsync(fd_temp)) {
		perror("vipw: fsync");
E 9
		goto bad;
	}
D 9
	while (fgets(buf, sizeof (buf) - 1, fp) != NULL)
		fputs(buf, ft);
	fclose(ft); fclose(fp);
	editor = getenv("EDITOR");
	if (editor == 0)
E 9
I 9
	if (fstat(fd_temp, &s1)) {
		perror("vipw: fstat");
		goto bad;
	}
	(void)close(fd_temp);

	if (!(editor = getenv("EDITOR")))
E 9
		editor = "vi";
D 9
	sprintf(buf, "%s %s", editor, temp);
	if (system(buf) == 0) {
		struct stat sbuf;
		int ok;
E 9
I 9
	(void)sprintf(buf, "%s %s", editor, temp);
	if (system(buf)) {
		perror("vipw: system");
		goto bad;
	}
E 9

D 9
		/* sanity checks */
		if (stat(temp, &sbuf) < 0) {
			fprintf(stderr,
			    "vipw: can't stat temp file, %s unchanged\n",
			    passwd);
			goto bad;
E 9
I 9
	if (!freopen(temp, "r", stdin)) {
D 10
		fprintf(stderr, "vipw: can't reopen temp file, %s unchanged\n", passwd);
E 10
I 10
		fprintf(stderr, "vipw: can't reopen temp file; %s unchanged.\n", passwd);
E 10
		goto bad;
	}
	if (fstat(fileno(stdin), &s2)) {
D 10
		fprintf(stderr, "vipw: can't stat temp file, %s unchanged\n", passwd);
E 10
I 10
		fprintf(stderr, "vipw: can't stat temp file; %s unchanged.\n", passwd);
E 10
		goto bad;
	}
	if (s1.st_mtime == s2.st_mtime) {
D 10
		fprintf(stderr, "vipw: %s unchanged\n", passwd);
E 10
I 10
		fprintf(stderr, "vipw: %s unchanged.\n", passwd);
E 10
		goto bad;
	}
	if (!s2.st_size) {
D 10
		fprintf(stderr, "vipw: bad temp file, %s unchanged\n", passwd);
E 10
I 10
		fprintf(stderr, "vipw: bad temp file; %s unchanged.\n", passwd);
E 10
		goto bad;
	}
D 10
	if (checkroot()) {
E 10
I 10
	if (check()) {
E 10
		static char	*temp_pag = "/etc/ptmp.pag",
				*temp_dir = "/etc/ptmp.dir",
				*passwd_pag = "/etc/passwd.pag",
				*passwd_dir = "/etc/passwd.dir";

		if (makedb(temp) < 0)
			fputs("vipw: mkpasswd failed.\n", stderr);
		else if (rename(temp_pag, passwd_pag) < 0) {
			fprintf(stderr, "vipw: ");
			perror(temp_pag);
E 9
		}
D 9
		if (sbuf.st_size == 0) {
			fprintf(stderr, "vipw: bad temp file, %s unchanged\n",
			    passwd);
			goto bad;
E 9
I 9
		else if (rename(temp_dir, passwd_dir) < 0) {
			fprintf(stderr, "vipw: ");
			perror(temp_dir);
E 9
		}
D 9
		ft = fopen(temp, "r");
		if (ft == NULL) {
			fprintf(stderr,
			    "vipw: can't reopen temp file, %s unchanged\n",
			    passwd);
			goto bad;
E 9
I 9
		else if (rename(temp, passwd) < 0) {
			fprintf(stderr, "vipw: ");
			perror("rename");
E 9
		}
D 9
		ok = 0;
		while (fgets(buf, sizeof (buf) - 1, ft) != NULL) {
			register char *cp;

			cp = index(buf, '\n');
			if (cp == 0)
				continue;
			*cp = '\0';
			cp = index(buf, ':');
			if (cp == 0)
				continue;
			*cp = '\0';
			if (strcmp(buf, "root"))
				continue;
			/* password */
			cp = index(cp + 1, ':');
			if (cp == 0)
				break;
			/* uid */
			if (atoi(cp + 1) != 0)
				break;
			cp = index(cp + 1, ':');
			if (cp == 0)
				break;
			/* gid */
			cp = index(cp + 1, ':');
			if (cp == 0)
				break;
			/* gecos */
			cp = index(cp + 1, ':');
			if (cp == 0)
				break;
			/* login directory */
D 7
			if (strncmp(++cp, "/:"))
E 7
I 7
			if (strncmp(++cp, "/:", 2))
E 7
				break;
			cp += 2;
			if (*cp && strcmp(cp, "/bin/sh") &&
			    strcmp(cp, "/bin/csh"))
				break;
			ok++;
		}
		fclose(ft);
		if (ok) {
D 4
			if (rename(temp, passwd) < 0)
E 4
I 4
			if (makedb(temp) < 0)
				fprintf(stderr, "vipw: mkpasswd failed\n");
			else if (rename(temp_pag, passwd_pag) < 0)
				fprintf(stderr, "vipw: "), perror(temp_pag);
			else if (rename(temp_dir, passwd_dir) < 0)
				fprintf(stderr, "vipw: "), perror(temp_dir);
			else if (rename(temp, passwd) < 0)
E 4
				fprintf(stderr, "vipw: "), perror("rename");
I 3
			else
				exit(0);
E 3
		} else
			fprintf(stderr,
			    "vipw: you mangled the temp file, %s unchanged\n",
			    passwd);
E 9
I 9
		else
			exit(0);
		(void)unlink(temp_pag);
		(void)unlink(temp_dir);
E 9
	}
D 9
bad:
I 5
	unlink(temp_pag);
	unlink(temp_dir);
E 5
	unlink(temp);
E 9
I 9
bad:	(void)unlink(temp);
E 9
I 3
	exit(1);
I 4
}

I 10
#define	CHN	((char *)NULL)
E 10
I 9
static
D 10
checkroot()
E 10
I 10
check()
E 10
{
D 10
	register int	cnt;
	register char	*cp, *sh;
	char	*getusershell();
E 10
I 10
	register char *cp, *sh;
	register long id;
	register int root;
	long atol();
	char *token(), *getusershell();
E 10

D 10
	while (gets(buf)) {
		if (strncmp(buf, "root:", sizeof("root:") - 1))
E 10
I 10
	for (root = 0; gets(buf); root = 0) {
		if (!*buf) {
			fputs("vipw: empty line.\n", stderr);
E 10
			continue;
D 10
						/* skip password */
		for (cp = buf + sizeof("root:") - 1; *cp && *cp != ':'; ++cp);
		if (!*cp || atoi(++cp))		/* uid exists && uid == 0 */
			break;			/* skip uid, gid, gcos, dir */
		for (cnt = 0; *cp && cnt < 4; ++cp)
			if (*cp == ':')
				++cnt;
		if (!*cp)
			break;
		while (sh = getusershell())
			if (!strcmp(cp, sh))
				return(1);
		fprintf(stderr, "vipw: illegal shell (%s) for root login, %s unchanged.\n", cp, passwd);
		return(0);
E 10
I 10
		}
		if (!(cp = token(buf)) || !*cp)		/* login */
			goto bad;
		if (!strcmp(cp, "root"))
			root = 1;
		(void)token(CHN);			/* passwd */
		if (!(cp = token(CHN)) || !*cp)		/* uid */
			goto bad;
		id = atol(cp);
		if (root && id) {
			fprintf(stderr, "vipw: root uid should be 0; %s unchanged.\n", passwd);
			return(0);
		}
		if (id > USHRT_MAX) {
			fprintf(stderr, "vipw: %s > max uid value (%u); %s unchanged.\n", cp, USHRT_MAX, passwd);
			return(0);
		}
		if (!(cp = token(CHN)) || !*cp)		/* gid */
			goto bad;
		id = atol(cp);
		if (id > USHRT_MAX) {
			fprintf(stderr, "vipw: %s > max gid value (%u); %s unchanged.\n", cp, USHRT_MAX, passwd);
			return(0);
		}
		(void)token(CHN);			/* gcos */
		if (!token(CHN))			/* home directory */
			goto bad;
		if (!(cp = token(CHN)))			/* shell */
			goto bad;
		if (root && *cp)			/* empty == /bin/sh */
			for (;;)
				if (!(sh = getusershell())) {
					fprintf(stderr, "vipw: illegal shell (%s) for root; %s unchanged.\n", cp, passwd);
					return(0);
				}
				else if (!strcmp(cp, sh))
					break;
		if (token(CHN)) {			/* too many fields */
bad:			fprintf(stderr, "vipw: corrupted entry; %s unchanged.\n", passwd);
			return(0);
		}
E 10
	}
D 10
	fprintf(stderr, "vipw: root login corrupted, %s unchanged.\n", passwd);
	return(0);
E 10
I 10
	return(1);
E 10
}

static
E 9
makedb(file)
D 9
	char *file;
E 9
I 9
D 10
	char	*file;
E 10
I 10
	char *file;
E 10
E 9
{
D 9
	int status, pid, w;
E 9
I 9
D 10
	int	status, pid, w;
E 10
I 10
	int status, pid, w;
E 10
E 9

D 9
	if ((pid = vfork()) == 0) {
E 9
I 9
	if (!(pid = vfork())) {
E 9
		execl("/etc/mkpasswd", "mkpasswd", file, 0);
		_exit(127);
	}
D 9
	while ((w = wait(&status)) != pid && w != -1)
		;
	if (w == -1 || status != 0)
		status = -1;
	return(status);
E 9
I 9
	while ((w = wait(&status)) != pid && w != -1);
	if (w == -1 || status)
		return(-1);
	return(0);
I 10
}

static char *
token(bfr)
	char *bfr;
{
	static char *cp;
	char *start;

	if (bfr)			/* re-init string */
		cp = bfr;
	else if (!cp)			/* check if hit EOS last time */
		return(CHN);
	else if (!bfr)			/* start at next char after ':' */
		++cp;
	for (start = cp;; ++cp)
		if (!*cp) {		/* found EOS; mark it for next time */
			cp = CHN;
			break;
		}
		else if (*cp == ':') {	/* found ':'; end token */
			*cp = '\0';
			break;
		}
	return(start);			/* return token */
E 10
E 9
E 4
E 3
}
E 1
