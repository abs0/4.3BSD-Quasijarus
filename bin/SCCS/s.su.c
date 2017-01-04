h06721
s 00001/00001/00186
d D 5.5 87/01/18 20:47:01 karels 17 16
c init USER on "su - root"
e
s 00005/00002/00182
d D 5.4 86/01/13 15:18:50 lepreau 16 15
c when logging, use pwuid->pw_name if getlogin() fails (ptys)
e
s 00004/00004/00180
d D 5.3 85/09/17 23:59:05 eric 15 14
c facilities in syslog
e
s 00002/00005/00182
d D 5.2 85/06/07 13:37:16 serge 14 13
c use syslog instead of writing to the console
e
s 00014/00002/00173
d D 5.1 85/05/02 14:48:51 dist 13 12
c 
e
s 00004/00006/00171
d D 4.10 85/03/12 11:15:13 ralph 12 11
c use syslog to log root su's.
e
s 00016/00014/00161
d D 4.9 84/03/22 11:17:59 ralph 11 9
c check group zero for any uid==0 (i.e., toor).
e
s 00011/00009/00166
d R 4.9 84/03/22 09:35:04 ralph 10 9
c check group zero for any uid==0 (i.e. toor).
e
s 00009/00011/00166
d D 4.8 84/02/01 11:26:30 ralph 9 8
c use group zero instead of /.suok
e
s 00026/00001/00151
d D 4.7 84/01/26 14:01:38 ralph 8 7
c added .suok file for list of users allowed to su root.
e
s 00002/00001/00150
d D 4.6 83/07/06 18:17:37 sam 7 6
c don't set USER, breaks sccs
e
s 00075/00034/00076
d D 4.5 83/05/23 18:36:36 sam 6 4
c cleanup after dlw; purge nice calls
e
s 00071/00033/00077
d R 4.5 83/05/23 01:18:45 sam 5 4
c mods from dlw
e
s 00028/00023/00082
d D 4.4 83/01/01 13:18:38 sam 4 3
c rewrite to use rename and file locking 
e
s 00001/00001/00104
d D 4.3 82/11/14 16:34:07 sam 3 2
c convert to 4.1c sys calls and directory layout
e
s 00002/00001/00103
d D 4.2 82/03/01 00:15:06 wnj 2 1
c group initialization
e
s 00104/00000/00000
d D 4.1 80/10/01 17:28:42 bill 1 0
c date and time created 80/10/01 17:28:42 by bill
e
u
U
t
T
I 13
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 13
I 4
#ifndef lint
E 4
I 1
D 2
static char *sccsid = "%W% (Berkeley) %G%";
E 2
I 2
D 6
static char *sccsid = "%W% (Berkeley) %I%";
E 6
I 6
D 13
static char *sccsid = "%W% (Berkeley) %G%";
E 6
I 4
#endif
E 13
I 13
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 13

E 4
E 2
#include <stdio.h>
#include <pwd.h>
I 9
#include <grp.h>
I 12
#include <syslog.h>
E 12
E 9
I 6
#include <sys/types.h>
#include <sys/time.h>
#include <sys/resource.h>
E 6

I 6
char	userbuf[16]	= "USER=";
char	homebuf[128]	= "HOME=";
char	shellbuf[128]	= "SHELL=";
char	pathbuf[128]	= "PATH=:/usr/ucb:/bin:/usr/bin";
char	*cleanenv[] = { userbuf, homebuf, shellbuf, pathbuf, 0, 0 };
char	*user = "root";
char	*shell = "/bin/sh";
int	fulllogin;
int	fastlogin;

extern char	**environ;
E 6
D 9
struct	passwd *pwd,*getpwnam();
E 9
I 9
struct	passwd *pwd;
E 9
char	*crypt();
char	*getpass();
I 6
char	*getenv();
I 16
char	*getlogin();
E 16
E 6

main(argc,argv)
D 4
int	argc;
char	**argv;
E 4
I 4
	int argc;
D 6
	char **argv;
E 6
I 6
	char *argv[];
E 6
E 4
{
D 4
	char *nptr;
E 4
I 4
D 6
	char *nptr = "root";
E 6
E 4
	char *password;
I 8
	char buf[1000];
	FILE *fp;
I 16
	register char *p;
E 16
E 8
D 4
	int badsw = 0;
E 4
D 6
	char *shell = "/bin/sh";
E 6
D 4
	int niced = 0;
E 4

I 15
	openlog("su", LOG_ODELAY, LOG_AUTH);

E 15
D 4
	if(argc > 1)
E 4
I 4
D 6
	if (argc > 1)
E 4
		nptr = argv[1];
D 4
	else {
		nptr = "root";
		nice(-4);
		niced = -4;
	}
	if((pwd=getpwnam(nptr)) == NULL) {
E 4
I 4
	if ((pwd = getpwnam(nptr)) == NULL) {
E 4
		printf("Unknown id: %s\n",nptr);
E 6
I 6
again:
	if (argc > 1 && strcmp(argv[1], "-f") == 0) {
		fastlogin++;
		argc--, argv++;
		goto again;
	}
	if (argc > 1 && strcmp(argv[1], "-") == 0) {
		fulllogin++;
		argc--, argv++;
		goto again;
	}
	if (argc > 1 && argv[1][0] != '-') {
		user = argv[1];
		argc--, argv++;
	}
D 8
	if (strcmp(user, "root") == 0)
E 8
I 8
D 11
	if (strcmp(user, "root") == 0) {
E 11
I 11
	if ((pwd = getpwuid(getuid())) == NULL) {
		fprintf(stderr, "Who are you?\n");
		exit(1);
	}
	strcpy(buf, pwd->pw_name);
	if ((pwd = getpwnam(user)) == NULL) {
		fprintf(stderr, "Unknown login: %s\n", user);
		exit(1);
	}
	/*
	 * Only allow those in group zero to su to root.
	 */
	if (pwd->pw_uid == 0) {
E 11
I 9
		struct	group *gr;
		int i;

E 9
D 11
		/*
D 9
		 * Read the "/.suok" file for list of people who can su.
E 9
I 9
		 * Only allow those in group zero to su.
E 9
		 */
		if ((pwd = getpwuid(getuid())) == NULL) {
			fprintf(stderr, "Who are you?\n");
			exit(1);
		}
E 11
D 9
		if ((fp = fopen("/.suok", "r")) != NULL) {
			while ((fgets(buf, sizeof(buf), fp)) != NULL) {
				/* blast newline */
				buf[strlen(buf) - 1] = '\0';
				if (strcmp(pwd->pw_name, buf) == 0) {
					fclose(fp);
E 9
I 9
		if ((gr = getgrgid(0)) != NULL) {
			for (i = 0; gr->gr_mem[i] != NULL; i++)
D 11
				if (strcmp(pwd->pw_name, gr->gr_mem[i]) == 0)
E 11
I 11
				if (strcmp(buf, gr->gr_mem[i]) == 0)
E 11
E 9
					goto userok;
D 9
				}
			}
			fclose(fp);
E 9
D 11
			fprintf(stderr, "You do not have permission to su root\n");
E 11
I 11
			fprintf(stderr, "You do not have permission to su %s\n",
				user);
E 11
			exit(1);
		}
	userok:
E 8
		setpriority(PRIO_PROCESS, 0, -2);
I 8
	}

I 16
#define Getlogin()  (((p = getlogin()) && *p) ? p : buf)
E 16
E 8
D 11
	if ((pwd = getpwnam(user)) == NULL) {
		fprintf(stderr, "Unknown login: %s\n", user);
E 6
		exit(1);
	}
E 11
D 4
	if(pwd->pw_passwd[0] == '\0' || getuid() == 0)
E 4
I 4
	if (pwd->pw_passwd[0] == '\0' || getuid() == 0)
E 4
		goto ok;
	password = getpass("Password:");
D 4
	if(badsw || (strcmp(pwd->pw_passwd, crypt(password, pwd->pw_passwd)) != 0)) {
bad:
E 4
I 4
	if (strcmp(pwd->pw_passwd, crypt(password, pwd->pw_passwd)) != 0) {
E 4
D 6
		printf("Sorry\n");
E 6
I 6
		fprintf(stderr, "Sorry\n");
E 6
D 4
		if(pwd->pw_uid == 0) {
E 4
I 4
		if (pwd->pw_uid == 0) {
E 4
D 14
			FILE *console = fopen("/dev/console", "w");
			if (console != NULL) {
D 4
				fprintf(console, "BADSU: %s %s\r\n", getlogin(), ttyname(2));
E 4
I 4
				fprintf(console, "BADSU: %s %s\r\n",
E 14
I 14
D 15
			openlog("su", 0, 0);
			syslog(LOG_SECURITY, "BAD SU %s on %s",
E 15
I 15
			syslog(LOG_CRIT, "BAD SU %s on %s",
E 15
E 14
D 16
					getlogin(), ttyname(2));
E 16
I 16
					Getlogin(), ttyname(2));
E 16
E 4
D 14
				fclose(console);
			}
E 14
		}
		exit(2);
	}
ok:
	endpwent();
D 4
	if(pwd->pw_uid == 0) {
E 4
I 4
	if (pwd->pw_uid == 0) {
E 4
D 12
		FILE *console = fopen("/dev/console", "w");
		if (console != NULL) {
D 4
			fprintf(console, "SU: %s %s\r\n", getlogin(), ttyname(2));
E 4
I 4
			fprintf(console, "SU: %s %s\r\n",
				getlogin(), ttyname(2));
E 4
			fclose(console);
		}
E 12
I 12
D 15
		openlog("su", 0, 0);
		syslog(LOG_SECURITY, "%s on %s", getlogin(), ttyname(2));
E 15
I 15
D 16
		syslog(LOG_NOTICE, "%s on %s", getlogin(), ttyname(2));
E 16
I 16
		syslog(LOG_NOTICE, "%s on %s", Getlogin(), ttyname(2));
E 16
E 15
		closelog();
E 12
	}
D 4
	setgid(pwd->pw_gid);
I 2
D 3
	inigrp(nptr, pwd->pw_gid);
E 3
I 3
	initgroups(nptr, pwd->pw_gid);
E 3
E 2
	setuid(pwd->pw_uid);
E 4
I 4
	if (setgid(pwd->pw_gid) < 0) {
		perror("su: setgid");
		exit(3);
	}
D 6
	if (initgroups(nptr, pwd->pw_gid)) {
E 6
I 6
	if (initgroups(user, pwd->pw_gid)) {
E 6
		fprintf(stderr, "su: initgroups failed\n");
		exit(4);
	}
	if (setuid(pwd->pw_uid) < 0) {
		perror("su: setuid");
		exit(5);
	}
E 4
	if (pwd->pw_shell && *pwd->pw_shell)
		shell = pwd->pw_shell;
D 6
	homeis(pwd->pw_dir);
	shellis(shell);
D 4
	nice(-niced);
E 4
	execl(shell, "su", 0);
	printf("No shell\n");
	exit(3);
E 6
I 6
	if (fulllogin) {
		cleanenv[4] = getenv("TERM");
		environ = cleanenv;
	}
D 7
	setenv("USER", pwd->pw_name, userbuf);
E 7
I 7
D 17
	if (strcmp(user, "root"))
E 17
I 17
	if (fulllogin || strcmp(user, "root") != 0)
E 17
		setenv("USER", pwd->pw_name, userbuf);
E 7
	setenv("SHELL", shell, shellbuf);
	setenv("HOME", pwd->pw_dir, homebuf);
	setpriority(PRIO_PROCESS, 0, 0);
	if (fastlogin) {
		*argv-- = "-f";
		*argv = "su";
	} else if (fulllogin) {
		if (chdir(pwd->pw_dir) < 0) {
			fprintf(stderr, "No directory\n");
			exit(6);
		}
		*argv = "-su";
	} else
		*argv = "su";
	execv(shell, argv);
	fprintf(stderr, "No shell\n");
	exit(7);
E 6
}

D 6
char	**environ;

homeis(hp)
	char *hp;
E 6
I 6
setenv(ename, eval, buf)
	char *ename, *eval, *buf;
E 6
{
	register char *cp, *dp;
	register char **ep = environ;
D 6
	static char homebuf[128];
E 6

I 6
	/*
	 * this assumes an environment variable "ename" already exists
	 */
E 6
	while (dp = *ep++) {
D 6
		for (cp = "HOME"; *cp == *dp && *cp; cp++, dp++)
E 6
I 6
		for (cp = ename; *cp == *dp && *cp; cp++, dp++)
E 6
			continue;
		if (*cp == 0 && (*dp == '=' || *dp == 0)) {
D 6
			strcpy(homebuf, "HOME=");
			strcat(homebuf, hp);
			*--ep = homebuf;
E 6
I 6
			strcat(buf, eval);
			*--ep = buf;
E 6
			return;
		}
	}
}

D 6
shellis(sp)
	char *sp;
E 6
I 6
char *
getenv(ename)
	char *ename;
E 6
{
	register char *cp, *dp;
	register char **ep = environ;
D 6
	static char shellbuf[128];
E 6

	while (dp = *ep++) {
D 6
		for (cp = "SHELL"; *cp == *dp && *cp; cp++, dp++)
E 6
I 6
		for (cp = ename; *cp == *dp && *cp; cp++, dp++)
E 6
			continue;
D 6
		if (*cp == 0 && (*dp == '=' || *dp == 0)) {
			strcpy(shellbuf, "SHELL=");
			strcat(shellbuf, sp);
			*--ep = shellbuf;
			return;
		}
E 6
I 6
		if (*cp == 0 && (*dp == '=' || *dp == 0))
			return (*--ep);
E 6
	}
I 6
	return ((char *)0);
E 6
}
E 1
