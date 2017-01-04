h42723
s 00010/00005/00956
d D 5.4 88/06/30 17:59:35 bostic 18 17
c install approved copyright notice
e
s 00009/00003/00952
d D 5.3 88/05/05 18:07:31 bostic 17 16
c written by Ralph Campbell; add Berkeley specific header
e
s 00000/00002/00955
d D 5.2 86/03/30 19:22:03 bloom 16 15
c local machine name no longer used
e
s 00007/00001/00950
d D 5.1 85/06/06 09:57:41 dist 15 14
c Add copyright
e
s 00001/00001/00950
d D 4.13 84/07/26 15:16:48 ralph 14 13
c minor fix for operator precedence.
e
s 00065/00022/00886
d D 4.12 84/07/24 16:48:05 ralph 13 12
c added `up' command. restart kills & restarts.
e
s 00006/00003/00902
d D 4.11 84/03/19 15:29:14 ralph 12 10
c clear status file if no args to down command.
e
s 00001/00003/00902
d R 4.11 84/03/19 14:16:17 ralph 11 10
c clear status file if no args to down command.
e
s 00099/00000/00806
d D 4.10 84/01/30 16:15:47 ralph 10 9
c added lpc down printer "status message".
e
s 00161/00094/00645
d D 4.9 83/12/16 10:27:19 ralph 9 8
c faster version of topq, clean command removes incomplete jobs only.
e
s 00022/00020/00717
d D 4.8 83/07/27 09:49:44 ralph 8 7
c fixed topq command
e
s 00000/00000/00737
d D 4.7 83/07/17 00:10:43 sam 7 6
c put sccs id's to some use
e
s 00148/00001/00589
d D 4.6 83/07/02 23:48:03 root 6 5
c for ralph; stuff for moving jobs to the top of a queue
e
s 00003/00003/00587
d D 4.5 83/06/17 14:36:41 ralph 5 4
c added some comments
e
s 00009/00007/00581
d D 4.4 83/06/15 14:56:43 sam 4 3
c open and flock defines changed
e
s 00001/00002/00587
d D 4.3 83/06/02 12:23:39 ralph 3 2
c made local variables static to improve separation between functions.
e
s 00018/00018/00571
d D 4.2 83/05/18 10:04:53 ralph 2 1
c fixed error messages missing '\n'.
e
s 00589/00000/00000
d D 4.1 83/05/11 16:03:58 ralph 1 0
c date and time created 83/05/11 16:03:58 by ralph
e
u
U
t
T
I 15
/*
 * Copyright (c) 1983 Regents of the University of California.
D 17
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 17
I 17
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 18
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 18
I 18
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
E 18
E 17
 */

E 15
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 15
#endif
E 15
I 15
D 17
#endif not lint
E 17
I 17
#endif /* not lint */
E 17
E 15

/*
D 9
 * lpc -- line printer control program
E 9
I 9
 * lpc -- line printer control program -- commands:
E 9
 */

#include "lp.h"
I 9
#include <sys/time.h>
E 9

/*
 * kill an existing daemon and disable printing.
 */
abort(argc, argv)
	char *argv[];
{
	register int c, status;
	register char *cp1, *cp2;
	char prbuf[100];

	if (argc == 1) {
		printf("Usage: abort {all | printer ...}\n");
		return;
	}
	if (argc == 2 && !strcmp(argv[1], "all")) {
		printer = prbuf;
		while (getprent(line) > 0) {
			cp1 = prbuf;
			cp2 = line;
			while ((c = *cp2++) && c != '|' && c != ':')
				*cp1++ = c;
			*cp1 = '\0';
D 13
			abortpr();
E 13
I 13
			abortpr(1);
E 13
		}
		return;
	}
	while (--argc) {
		printer = *++argv;
		if ((status = pgetent(line, printer)) < 0) {
D 2
			printf("cannot open printer description file");
E 2
I 2
			printf("cannot open printer description file\n");
E 2
			continue;
		} else if (status == 0) {
D 2
			printf("unknown printer %s", printer);
E 2
I 2
			printf("unknown printer %s\n", printer);
E 2
			continue;
		}
D 13
		abortpr();
E 13
I 13
		abortpr(1);
E 13
	}
}

D 13
abortpr()
E 13
I 13
abortpr(dis)
E 13
{
	register FILE *fp;
	struct stat stbuf;
	int pid, fd;

	bp = pbuf;
	if ((SD = pgetstr("sd", &bp)) == NULL)
		SD = DEFSPOOL;
	if ((LO = pgetstr("lo", &bp)) == NULL)
		LO = DEFLOCK;
	(void) sprintf(line, "%s/%s", SD, LO);
	printf("%s:\n", printer);

	/*
	 * Turn on the owner execute bit of the lock file to disable printing.
	 */
D 13
	if (stat(line, &stbuf) >= 0) {
		if (chmod(line, (stbuf.st_mode & 0777) | 0100) < 0)
			printf("\tcannot disable printing\n");
		else
			printf("\tprinting disabled\n");
	} else if (errno == ENOENT) {
D 4
		if ((fd = open(line, FWRONLY|FCREATE, 0760)) < 0)
E 4
I 4
		if ((fd = open(line, O_WRONLY|O_CREAT, 0760)) < 0)
E 4
D 2
			printf("\tcannot create lock file");
E 2
I 2
			printf("\tcannot create lock file\n");
E 2
		else {
			(void) close(fd);
			printf("\tprinting disabled\n");
			printf("\tno daemon to abort\n");
E 13
I 13
	if (dis) {
		if (stat(line, &stbuf) >= 0) {
			if (chmod(line, (stbuf.st_mode & 0777) | 0100) < 0)
				printf("\tcannot disable printing\n");
			else
				printf("\tprinting disabled\n");
		} else if (errno == ENOENT) {
			if ((fd = open(line, O_WRONLY|O_CREAT, 0760)) < 0)
				printf("\tcannot create lock file\n");
			else {
				(void) close(fd);
				printf("\tprinting disabled\n");
				printf("\tno daemon to abort\n");
			}
			return;
		} else {
			printf("\tcannot stat lock file\n");
			return;
E 13
		}
D 13
		return;
	} else {
		printf("\tcannot stat lock file\n");
		return;
E 13
	}
	/*
	 * Kill the current daemon to stop printing now.
	 */
	if ((fp = fopen(line, "r")) == NULL) {
		printf("\tcannot open lock file\n");
		return;
	}
D 4
	if (!getline(fp) || flock(fileno(fp), FSHLOCK|FNBLOCK) == 0) {
E 4
I 4
	if (!getline(fp) || flock(fileno(fp), LOCK_SH|LOCK_NB) == 0) {
E 4
D 5
		(void) fclose(fp);
E 5
I 5
		(void) fclose(fp);	/* unlocks as well */
E 5
		printf("\tno daemon to abort\n");
		return;
	}
	(void) fclose(fp);
D 13
	if (kill(pid = atoi(line), SIGINT) < 0)
E 13
I 13
	if (kill(pid = atoi(line), SIGTERM) < 0)
E 13
		printf("\tWarning: daemon (pid %d) not killed\n", pid);
	else
		printf("\tdaemon (pid %d) killed\n", pid);
}

/*
 * Remove all spool files and temporaries from the spooling area.
 */
clean(argc, argv)
	char *argv[];
{
	register int c, status;
	register char *cp1, *cp2;
	char prbuf[100];

	if (argc == 1) {
		printf("Usage: clean {all | printer ...}\n");
		return;
	}
	if (argc == 2 && !strcmp(argv[1], "all")) {
		printer = prbuf;
		while (getprent(line) > 0) {
			cp1 = prbuf;
			cp2 = line;
			while ((c = *cp2++) && c != '|' && c != ':')
				*cp1++ = c;
			*cp1 = '\0';
			cleanpr();
		}
		return;
	}
	while (--argc) {
		printer = *++argv;
		if ((status = pgetent(line, printer)) < 0) {
D 2
			printf("cannot open printer description file");
E 2
I 2
			printf("cannot open printer description file\n");
E 2
			continue;
		} else if (status == 0) {
D 2
			printf("unknown printer %s", printer);
E 2
I 2
			printf("unknown printer %s\n", printer);
E 2
			continue;
		}
		cleanpr();
	}
}

I 9
select(d)
struct direct *d;
{
	int c = d->d_name[0];

	if ((c == 't' || c == 'c' || c == 'd') && d->d_name[1] == 'f')
		return(1);
	return(0);
}

/*
 * Comparison routine for scandir. Sort by job number and machine, then
 * by `cf', `tf', or `df', then by the sequence letter A-Z, a-z.
 */
sortq(d1, d2)
struct direct **d1, **d2;
{
	int c1, c2;

	if (c1 = strcmp((*d1)->d_name + 3, (*d2)->d_name + 3))
		return(c1);
	c1 = (*d1)->d_name[0];
	c2 = (*d2)->d_name[0];
	if (c1 == c2)
		return((*d1)->d_name[2] - (*d2)->d_name[2]);
	if (c1 == 'c')
		return(-1);
	if (c1 == 'd' || c2 == 'c')
		return(1);
	return(-1);
}

/*
 * Remove incomplete jobs from spooling area.
 */
E 9
cleanpr()
{
D 9
	register int c;
	register DIR *dirp;
	register struct direct *dp;
	char *cp, *cp1;
E 9
I 9
	register int i, n;
	register char *cp, *cp1, *lp;
	struct direct **queue;
	int nitems;
E 9

	bp = pbuf;
	if ((SD = pgetstr("sd", &bp)) == NULL)
		SD = DEFSPOOL;
D 9
	for (cp = line, cp1 = SD; *cp++ = *cp1++; );
	cp[-1] = '/';
E 9
	printf("%s:\n", printer);

D 9
	if ((dirp = opendir(SD)) == NULL) {
E 9
I 9
	for (lp = line, cp = SD; *lp++ = *cp++; )
		;
	lp[-1] = '/';

	nitems = scandir(SD, &queue, select, sortq);
	if (nitems < 0) {
E 9
		printf("\tcannot examine spool directory\n");
		return;
	}
D 9
	while ((dp = readdir(dirp)) != NULL) {
		c = dp->d_name[0];
		if ((c == 'c' || c == 't' || c == 'd') && dp->d_name[1]=='f') {
			strcpy(cp, dp->d_name);
			if (unlink(line) < 0)
				printf("\tcannot remove %s\n", line);
			else
				printf("\tremoved %s\n", line);
E 9
I 9
	if (nitems == 0)
		return;
	i = 0;
	do {
		cp = queue[i]->d_name;
		if (*cp == 'c') {
			n = 0;
			while (i + 1 < nitems) {
				cp1 = queue[i + 1]->d_name;
				if (*cp1 != 'd' || strcmp(cp + 3, cp1 + 3))
					break;
				i++;
				n++;
			}
			if (n == 0) {
				strcpy(lp, cp);
				unlinkf(line);
			}
		} else {
			/*
			 * Must be a df with no cf (otherwise, it would have
			 * been skipped above) or a tf file (which can always
			 * be removed).
			 */
			strcpy(lp, cp);
			unlinkf(line);
E 9
		}
D 9
	}
	closedir(dirp);
E 9
I 9
     	} while (++i < nitems);
E 9
}
I 9
 
unlinkf(name)
	char	*name;
{
	if (unlink(name) < 0)
		printf("\tcannot remove %s\n", name);
	else
		printf("\tremoved %s\n", name);
}
E 9

/*
 * Enable queuing to the printer (allow lpr's).
 */
enable(argc, argv)
	char *argv[];
{
	register int c, status;
	register char *cp1, *cp2;
	char prbuf[100];

	if (argc == 1) {
		printf("Usage: enable {all | printer ...}\n");
		return;
	}
	if (argc == 2 && !strcmp(argv[1], "all")) {
		printer = prbuf;
		while (getprent(line) > 0) {
			cp1 = prbuf;
			cp2 = line;
			while ((c = *cp2++) && c != '|' && c != ':')
				*cp1++ = c;
			*cp1 = '\0';
			enablepr();
		}
		return;
	}
	while (--argc) {
		printer = *++argv;
		if ((status = pgetent(line, printer)) < 0) {
D 2
			printf("cannot open printer description file");
E 2
I 2
			printf("cannot open printer description file\n");
E 2
			continue;
		} else if (status == 0) {
D 2
			printf("unknown printer %s", printer);
E 2
I 2
			printf("unknown printer %s\n", printer);
E 2
			continue;
		}
		enablepr();
	}
}

enablepr()
{
	struct stat stbuf;

	bp = pbuf;
	if ((SD = pgetstr("sd", &bp)) == NULL)
		SD = DEFSPOOL;
	if ((LO = pgetstr("lo", &bp)) == NULL)
		LO = DEFLOCK;
	(void) sprintf(line, "%s/%s", SD, LO);
	printf("%s:\n", printer);

	/*
	 * Turn off the group execute bit of the lock file to enable queuing.
	 */
	if (stat(line, &stbuf) >= 0) {
		if (chmod(line, stbuf.st_mode & 0767) < 0)
D 2
			printf("\tcannot enable queuing");
E 2
I 2
			printf("\tcannot enable queuing\n");
E 2
		else
			printf("\tqueuing enabled\n");
	}
}

/*
 * Disable queuing.
 */
disable(argc, argv)
	char *argv[];
{
	register int c, status;
	register char *cp1, *cp2;
	char prbuf[100];

	if (argc == 1) {
		printf("Usage: disable {all | printer ...}\n");
		return;
	}
	if (argc == 2 && !strcmp(argv[1], "all")) {
		printer = prbuf;
		while (getprent(line) > 0) {
			cp1 = prbuf;
			cp2 = line;
			while ((c = *cp2++) && c != '|' && c != ':')
				*cp1++ = c;
			*cp1 = '\0';
			disablepr();
		}
		return;
	}
	while (--argc) {
		printer = *++argv;
		if ((status = pgetent(line, printer)) < 0) {
D 2
			printf("cannot open printer description file");
E 2
I 2
			printf("cannot open printer description file\n");
E 2
			continue;
		} else if (status == 0) {
D 2
			printf("unknown printer %s", printer);
E 2
I 2
			printf("unknown printer %s\n", printer);
E 2
			continue;
		}
		disablepr();
	}
}

disablepr()
{
	register int fd;
	struct stat stbuf;

	bp = pbuf;
	if ((SD = pgetstr("sd", &bp)) == NULL)
		SD = DEFSPOOL;
	if ((LO = pgetstr("lo", &bp)) == NULL)
		LO = DEFLOCK;
	(void) sprintf(line, "%s/%s", SD, LO);
	printf("%s:\n", printer);
	/*
	 * Turn on the group execute bit of the lock file to disable queuing.
	 */
	if (stat(line, &stbuf) >= 0) {
		if (chmod(line, (stbuf.st_mode & 0777) | 010) < 0)
			printf("\tcannot disable queuing\n");
		else
			printf("\tqueuing disabled\n");
	} else if (errno == ENOENT) {
D 4
		if ((fd = open(line, FWRONLY|FCREATE, 0670)) < 0)
E 4
I 4
		if ((fd = open(line, O_WRONLY|O_CREAT, 0670)) < 0)
E 4
			printf("\tcannot create lock file\n");
		else {
			(void) close(fd);
			printf("\tqueuing disabled\n");
		}
		return;
	} else
		printf("\tcannot stat lock file\n");
}

/*
I 10
 * Disable queuing and printing and put a message into the status file
 * (reason for being down).
 */
down(argc, argv)
	char *argv[];
{
	register int c, status;
	register char *cp1, *cp2;
	char prbuf[100];

	if (argc == 1) {
D 12
		printf("Usage: disable {all | printer} [message ...]\n");
E 12
I 12
		printf("Usage: down {all | printer} [message ...]\n");
E 12
		return;
	}
	if (!strcmp(argv[1], "all")) {
		printer = prbuf;
		while (getprent(line) > 0) {
			cp1 = prbuf;
			cp2 = line;
			while ((c = *cp2++) && c != '|' && c != ':')
				*cp1++ = c;
			*cp1 = '\0';
			putmsg(argc - 2, argv + 2);
		}
		return;
	}
	printer = argv[1];
	if ((status = pgetent(line, printer)) < 0) {
		printf("cannot open printer description file\n");
		return;
	} else if (status == 0) {
		printf("unknown printer %s\n", printer);
		return;
	}
	putmsg(argc - 2, argv + 2);
}

putmsg(argc, argv)
	char **argv;
{
	register int fd;
	register char *cp1, *cp2;
	char buf[1024];
	struct stat stbuf;

	bp = pbuf;
	if ((SD = pgetstr("sd", &bp)) == NULL)
		SD = DEFSPOOL;
	if ((LO = pgetstr("lo", &bp)) == NULL)
		LO = DEFLOCK;
	if ((ST = pgetstr("st", &bp)) == NULL)
		ST = DEFSTAT;
	printf("%s:\n", printer);
	/*
	 * Turn on the group execute bit of the lock file to disable queuing and
	 * turn on the owner execute bit of the lock file to disable printing.
	 */
	(void) sprintf(line, "%s/%s", SD, LO);
	if (stat(line, &stbuf) >= 0) {
		if (chmod(line, (stbuf.st_mode & 0777) | 0110) < 0)
			printf("\tcannot disable queuing\n");
		else
			printf("\tprinter and queuing disabled\n");
	} else if (errno == ENOENT) {
		if ((fd = open(line, O_WRONLY|O_CREAT, 0770)) < 0)
			printf("\tcannot create lock file\n");
		else {
			(void) close(fd);
			printf("\tprinter and queuing disabled\n");
		}
		return;
	} else
		printf("\tcannot stat lock file\n");
	/*
	 * Write the message into the status file.
	 */
D 12
	if (argc <= 0)
		return;
E 12
	(void) sprintf(line, "%s/%s", SD, ST);
	fd = open(line, O_WRONLY|O_CREAT, 0664);
	if (fd < 0 || flock(fd, LOCK_EX) < 0) {
		printf("\tcannot create status file\n");
		return;
	}
	(void) ftruncate(fd, 0);
I 12
	if (argc <= 0) {
		(void) write(fd, "\n", 1);
		(void) close(fd);
		return;
	}
E 12
	cp1 = buf;
	while (--argc >= 0) {
		cp2 = *argv++;
		while (*cp1++ = *cp2++)
			;
		cp1[-1] = ' ';
	}
	cp1[-1] = '\n';
	*cp1 = '\0';
	(void) write(fd, buf, strlen(buf));
	(void) close(fd);
}

/*
E 10
 * Exit lpc
 */
quit(argc, argv)
	char *argv[];
{
	exit(0);
}

/*
D 13
 * Startup the daemon.
E 13
I 13
 * Kill and restart the daemon.
E 13
 */
restart(argc, argv)
	char *argv[];
{
	register int c, status;
	register char *cp1, *cp2;
	char prbuf[100];

	if (argc == 1) {
		printf("Usage: restart {all | printer ...}\n");
		return;
	}
D 16
	gethostname(host, sizeof(host));
E 16
	if (argc == 2 && !strcmp(argv[1], "all")) {
		printer = prbuf;
		while (getprent(line) > 0) {
			cp1 = prbuf;
			cp2 = line;
			while ((c = *cp2++) && c != '|' && c != ':')
				*cp1++ = c;
			*cp1 = '\0';
I 13
			abortpr(0);
E 13
			startpr(0);
		}
		return;
	}
	while (--argc) {
		printer = *++argv;
		if ((status = pgetent(line, printer)) < 0) {
D 2
			printf("cannot open printer description file");
E 2
I 2
			printf("cannot open printer description file\n");
E 2
			continue;
		} else if (status == 0) {
D 2
			printf("unknown printer %s", printer);
E 2
I 2
			printf("unknown printer %s\n", printer);
E 2
			continue;
		}
I 13
		abortpr(0);
E 13
		startpr(0);
	}
}

/*
 * Enable printing on the specified printer and startup the daemon.
 */
start(argc, argv)
	char *argv[];
{
	register int c, status;
	register char *cp1, *cp2;
	char prbuf[100];

	if (argc == 1) {
		printf("Usage: start {all | printer ...}\n");
		return;
	}
D 16
	gethostname(host, sizeof(host));
E 16
	if (argc == 2 && !strcmp(argv[1], "all")) {
		printer = prbuf;
		while (getprent(line) > 0) {
			cp1 = prbuf;
			cp2 = line;
			while ((c = *cp2++) && c != '|' && c != ':')
				*cp1++ = c;
			*cp1 = '\0';
			startpr(1);
		}
		return;
	}
	while (--argc) {
		printer = *++argv;
		if ((status = pgetent(line, printer)) < 0) {
D 2
			printf("cannot open printer description file");
E 2
I 2
			printf("cannot open printer description file\n");
E 2
			continue;
		} else if (status == 0) {
D 2
			printf("unknown printer %s", printer);
E 2
I 2
			printf("unknown printer %s\n", printer);
E 2
			continue;
		}
		startpr(1);
	}
}

startpr(enable)
{
	struct stat stbuf;

	bp = pbuf;
	if ((SD = pgetstr("sd", &bp)) == NULL)
		SD = DEFSPOOL;
	if ((LO = pgetstr("lo", &bp)) == NULL)
		LO = DEFLOCK;
D 3
	RM = host;
E 3
	(void) sprintf(line, "%s/%s", SD, LO);
	printf("%s:\n", printer);

	/*
	 * Turn off the owner execute bit of the lock file to enable printing.
	 */
	if (enable && stat(line, &stbuf) >= 0) {
D 13
		if (chmod(line, stbuf.st_mode & 0677) < 0)
E 13
I 13
D 14
		if (chmod(line, stbuf.st_mode & (enable == 2)?0666:0677) < 0)
E 14
I 14
		if (chmod(line, stbuf.st_mode & (enable==2 ? 0666 : 0677)) < 0)
E 14
E 13
			printf("\tcannot enable printing\n");
		else
			printf("\tprinting enabled\n");
	}
D 3
	if (!startdaemon())
E 3
I 3
D 6
	if (!startdaemon(host))
E 6
I 6
	if (!startdaemon(printer))
E 6
E 3
		printf("\tcouldn't start daemon\n");
	else
		printf("\tdaemon started\n");
}

/*
 * Print the status of each queue listed or all the queues.
 */
status(argc, argv)
	char *argv[];
{
	register int c, status;
	register char *cp1, *cp2;
	char prbuf[100];

	if (argc == 1) {
		printer = prbuf;
		while (getprent(line) > 0) {
			cp1 = prbuf;
			cp2 = line;
			while ((c = *cp2++) && c != '|' && c != ':')
				*cp1++ = c;
			*cp1 = '\0';
			prstat();
		}
		return;
	}
	while (--argc) {
		printer = *++argv;
		if ((status = pgetent(line, printer)) < 0) {
D 2
			printf("cannot open printer description file");
E 2
I 2
			printf("cannot open printer description file\n");
E 2
			continue;
		} else if (status == 0) {
D 2
			printf("unknown printer %s", printer);
E 2
I 2
			printf("unknown printer %s\n", printer);
E 2
			continue;
		}
		prstat();
	}
}

/*
 * Print the status of the printer queue.
 */
prstat()
{
	struct stat stbuf;
	register int fd, i;
	register struct direct *dp;
	DIR *dirp;

	bp = pbuf;
	if ((SD = pgetstr("sd", &bp)) == NULL)
		SD = DEFSPOOL;
	if ((LO = pgetstr("lo", &bp)) == NULL)
		LO = DEFLOCK;
	if ((ST = pgetstr("st", &bp)) == NULL)
		ST = DEFSTAT;
	printf("%s:\n", printer);
	(void) sprintf(line, "%s/%s", SD, LO);
	if (stat(line, &stbuf) >= 0) {
		printf("\tqueuing is %s\n",
			(stbuf.st_mode & 010) ? "disabled" : "enabled");
		printf("\tprinting is %s\n",
			(stbuf.st_mode & 0100) ? "disabled" : "enabled");
	} else {
		printf("\tqueuing is enabled\n");
		printf("\tprinting is enabled\n");
	}
	if ((dirp = opendir(SD)) == NULL) {
		printf("\tcannot examine spool directory\n");
		return;
	}
	i = 0;
	while ((dp = readdir(dirp)) != NULL) {
		if (*dp->d_name == 'c' && dp->d_name[1] == 'f')
			i++;
	}
	closedir(dirp);
	if (i == 0)
		printf("\tno entries\n");
	else if (i == 1)
		printf("\t1 entry in spool area\n");
	else
		printf("\t%d entries in spool area\n", i);
D 4
	fd = open(line, FRDONLY);
	if (fd < 0 || flock(fd, FSHLOCK|FNBLOCK) == 0) {
E 4
I 4
	fd = open(line, O_RDONLY);
	if (fd < 0 || flock(fd, LOCK_SH|LOCK_NB) == 0) {
E 4
D 5
		(void) close(fd);
E 5
I 5
		(void) close(fd);	/* unlocks as well */
E 5
		printf("\tno daemon present\n");
		return;
	}
	(void) close(fd);
	putchar('\t');
	(void) sprintf(line, "%s/%s", SD, ST);
D 4
	if ((fd = open(line, FRDONLY|FSHLOCK)) >= 0) {
E 4
I 4
	fd = open(line, O_RDONLY);
	if (fd >= 0) {
		(void) flock(fd, LOCK_SH);
E 4
		while ((i = read(fd, line, sizeof(line))) > 0)
			(void) fwrite(line, 1, i, stdout);
D 5
		(void) close(fd);
E 5
I 5
		(void) close(fd);	/* unlocks as well */
E 5
	}
}

/*
 * Stop the specified daemon after completing the current job and disable
 * printing.
 */
stop(argc, argv)
	char *argv[];
{
	register int c, status;
	register char *cp1, *cp2;
	char prbuf[100];

	if (argc == 1) {
		printf("Usage: stop {all | printer ...}\n");
		return;
	}
	if (argc == 2 && !strcmp(argv[1], "all")) {
		printer = prbuf;
		while (getprent(line) > 0) {
			cp1 = prbuf;
			cp2 = line;
			while ((c = *cp2++) && c != '|' && c != ':')
				*cp1++ = c;
			*cp1 = '\0';
			stoppr();
		}
		return;
	}
	while (--argc) {
		printer = *++argv;
		if ((status = pgetent(line, printer)) < 0) {
D 2
			printf("cannot open printer description file");
E 2
I 2
			printf("cannot open printer description file\n");
E 2
			continue;
		} else if (status == 0) {
D 2
			printf("unknown printer %s", printer);
E 2
I 2
			printf("unknown printer %s\n", printer);
E 2
			continue;
		}
		stoppr();
	}
}

stoppr()
{
	register int fd;
	struct stat stbuf;

	bp = pbuf;
	if ((SD = pgetstr("sd", &bp)) == NULL)
		SD = DEFSPOOL;
	if ((LO = pgetstr("lo", &bp)) == NULL)
		LO = DEFLOCK;
	(void) sprintf(line, "%s/%s", SD, LO);
	printf("%s:\n", printer);

	/*
	 * Turn on the owner execute bit of the lock file to disable printing.
	 */
	if (stat(line, &stbuf) >= 0) {
		if (chmod(line, (stbuf.st_mode & 0777) | 0100) < 0)
			printf("\tcannot disable printing\n");
		else
			printf("\tprinting disabled\n");
	} else if (errno == ENOENT) {
D 4
		if ((fd = open(line, FWRONLY|FCREATE, 0760)) < 0)
E 4
I 4
		if ((fd = open(line, O_WRONLY|O_CREAT, 0760)) < 0)
E 4
			printf("\tcannot create lock file\n");
		else {
			(void) close(fd);
			printf("\tprinting disabled\n");
		}
	} else
		printf("\tcannot stat lock file\n");
I 6
}

I 9
struct	queue **queue;
int	nitems;
time_t	mtime;

E 9
/*
 * Put the specified jobs at the top of printer queue.
 */
topq(argc, argv)
	char *argv[];
{
D 9
	register int status, nitems, n;
E 9
I 9
	register int n, i;
E 9
	struct stat stbuf;
	register char *cfname;
D 9
	struct queue **queue;
I 8
	int changed = 0;
E 9
I 9
	int status, changed;
E 9
E 8

D 9
	if (argc == 1) {
E 9
I 9
	if (argc < 3) {
E 9
		printf("Usage: topq printer [jobnum ...] [user ...]\n");
		return;
	}

	--argc;
	printer = *++argv;
	status = pgetent(line, printer);
	if (status < 0) {
		printf("cannot open printer description file\n");
		return;
D 8
	}
	if (status == 0) {
E 8
I 8
	} else if (status == 0) {
E 8
		printf("%s: unknown printer\n", printer);
		return;
	}
	bp = pbuf;
	if ((SD = pgetstr("sd", &bp)) == NULL)
		SD = DEFSPOOL;
	if ((LO = pgetstr("lo", &bp)) == NULL)
		LO = DEFLOCK;
	printf("%s:\n", printer);

	if (chdir(SD) < 0) {
		printf("\tcannot chdir to %s\n", SD);
		return;
	}
	nitems = getq(&queue);
D 9
	while (--argc) {
		if ((n = inqueue(*++argv, queue, nitems)) < 0) {
			printf("\tjob %s is not in the queue\n", *argv);
E 9
I 9
	if (nitems == 0)
		return;
	changed = 0;
	mtime = queue[0]->q_time;
	for (i = argc; --i; ) {
		if (doarg(argv[i]) == 0) {
			printf("\tjob %s is not in the queue\n", argv[i]);
E 9
			continue;
D 9
		}
		/*
		 * Reposition the job by changing the modification time of
		 * the control file.
		 */
D 8
		if (touch(queue[n]->q_name) == 0) {
E 8
I 8
		if (touch(queue[n]->q_name)) {
E 8
			free(queue[n]);
			queue[n] = NULL;
E 9
I 9
		} else
E 9
I 8
			changed++;
E 8
D 9
		}
E 9
	}
D 9
	/*
	 * Put the remaining jobs at the end of the queue.
	 */
	for (n = 0; n < nitems; n++) {
D 8
		cfname = queue[n]->q_name;
		if (cfname == NULL)
E 8
I 8
		if (queue[n] == NULL)
E 8
			continue;
D 8
		touch(cfname);
E 8
I 8
		cfname = queue[n]->q_name;
		if (changed)
			touch(cfname);
E 8
		free(cfname);
	}
E 9
I 9
	for (i = 0; i < nitems; i++)
		free(queue[i]);
E 9
	free(queue);
I 8
D 9
	printf("\tqueue order %s\n", changed ? "changed" : "unchanged");
E 9
I 9
	if (!changed) {
		printf("\tqueue order unchanged\n");
		return;
	}
E 9
E 8
	/*
	 * Turn on the public execute bit of the lock file to
	 * get lpd to rebuild the queue after the current job.
	 */
D 8
	if (stat(LO, &stbuf) >= 0)
		(void) chmod(line, (stbuf.st_mode & 0777) | 01);
E 8
I 8
	if (changed && stat(LO, &stbuf) >= 0)
		(void) chmod(LO, (stbuf.st_mode & 0777) | 01);
E 8
} 

D 9
/* 
 * Change the modification time of the file.
 *	Returns boolean if successful.  
E 9
I 9
/*
 * Reposition the job by changing the modification time of
 * the control file.
E 9
 */
D 9
touch(cfname)
	char *cfname;
E 9
I 9
touch(q)
	struct queue *q;
E 9
{
D 9
	register int fd;
E 9
I 9
	struct timeval tvp[2];
E 9

D 9
	fd = open(cfname, O_RDWR);
	if (fd < 0) {
D 8
		printf("\tcannot to open %s\n", cfname);
E 8
I 8
		printf("\tcannot open %s\n", cfname);
E 8
		return(0); 
	}
	(void) read(fd, line, 1);
D 8
	(void) lseek(fd, 0, 0); 	/* set pointer back to top of file */
E 8
I 8
	(void) lseek(fd, 0L, 0); 	/* set pointer back to top of file */
E 8
	(void) write(fd, line, 1);
	(void) close(fd);
I 8
	sleep(1);			/* so times will be different */
E 8
	return(1);
E 9
I 9
	tvp[0].tv_sec = tvp[1].tv_sec = --mtime;
	tvp[0].tv_usec = tvp[1].tv_usec = 0;
	return(utimes(q->q_name, tvp));
E 9
}

/*
 * Checks if specified job name is in the printer's queue.
 * Returns:  negative (-1) if argument name is not in the queue.
D 9
 *     0 to n:  array index of pointer to argument name.
E 9
 */
D 9
inqueue(job, queue, nitems)
E 9
I 9
doarg(job)
E 9
	char *job;
D 9
	struct queue *queue[];
	int nitems;
E 9
{
D 9
	register struct queue *q;
D 8
	register int n, jobnum, fd;
E 8
I 8
	register int n, jobnum;
E 8
	register char *cp;
E 9
I 9
	register struct queue **qq;
	register int jobnum, n;
	register char *cp, *machine;
	int cnt = 0;
E 9
I 8
	FILE *fp;
E 8

D 8
	printf("inqueue(%s, %x, %d)\n", job, queue, nitems);
E 8
D 9
	jobnum = -1;
E 9
I 9
	/*
	 * Look for a job item consisting of system name, colon, number 
	 * (example: ucbarpa:114)  
	 */
	if ((cp = index(job, ':')) != NULL) {
		machine = job;
		*cp++ = '\0';
		job = cp;
	} else
		machine = NULL;

	/*
	 * Check for job specified by number (example: 112 or 235ucbarpa).
	 */
E 9
	if (isdigit(*job)) {
		jobnum = 0;
		do
			jobnum = jobnum * 10 + (*job++ - '0');
		while (isdigit(*job));
D 8
		printf("jobnum = %d\n", jobnum);
E 8
D 9
	}

	while (--nitems >= 0) {
		if ((q = queue[nitems]) == NULL)
			continue;
		/* this needs to be fixed since the same number can be used
		   by different machines (i.e. jobnum & machine) */
D 8
		printf("q = %s\n", q->q_name);
E 8
		if (jobnum >= 0) {
E 9
I 9
		for (qq = queue + nitems; --qq >= queue; ) {
E 9
			n = 0;
D 8
			for (cp = q->q_name+3; isdigit(*cp); cp++)
				n = n * 10 + (*cp - '0');
E 8
I 8
D 9
			for (cp = q->q_name+3; isdigit(*cp); )
E 9
I 9
			for (cp = (*qq)->q_name+3; isdigit(*cp); )
E 9
				n = n * 10 + (*cp++ - '0');
E 8
D 9
			if (jobnum == n)
				return(nitems);
			continue;
		}
		/*
		 * Read cf file for owner's name
		 */
D 8
		if ((fd = open(q->q_name, O_RDONLY)) < 0)
E 8
I 8
		if ((fp = fopen(q->q_name, "r")) == NULL)
E 8
			continue;
D 8
		while (getline(fd) > 0) {
E 8
I 8
		while (getline(fp) > 0) {
E 8
			if (line[0] == 'P' && !strcmp(job, line+1)) {
D 8
				(void) close(fd);
E 8
I 8
				(void) fclose(fp);
E 8
				return(nitems);
E 9
I 9
			if (jobnum != n)
				continue;
			if (*job && strcmp(job, cp) != 0)
				continue;
			if (machine != NULL && strcmp(machine, cp) != 0)
				continue;
			if (touch(*qq) == 0) {
				printf("\tmoved %s\n", (*qq)->q_name);
				cnt++;
E 9
			}
		}
I 9
		return(cnt);
	}
	/*
	 * Process item consisting of owner's name (example: henry).
	 */
	for (qq = queue + nitems; --qq >= queue; ) {
		if ((fp = fopen((*qq)->q_name, "r")) == NULL)
			continue;
		while (getline(fp) > 0)
			if (line[0] == 'P')
				break;
E 9
D 8
		(void) close(fd);
E 8
I 8
		(void) fclose(fp);
I 9
		if (line[0] != 'P' || strcmp(job, line+1) != 0)
			continue;
		if (touch(*qq) == 0) {
			printf("\tmoved %s\n", (*qq)->q_name);
			cnt++;
		}
E 9
E 8
	}
D 9
	return(-1);
E 9
I 9
	return(cnt);
I 13
}

/*
 * Enable everything and start printer (undo `down').
 */
up(argc, argv)
	char *argv[];
{
	register int c, status;
	register char *cp1, *cp2;
	char prbuf[100];

	if (argc == 1) {
		printf("Usage: up {all | printer ...}\n");
		return;
	}
	if (argc == 2 && !strcmp(argv[1], "all")) {
		printer = prbuf;
		while (getprent(line) > 0) {
			cp1 = prbuf;
			cp2 = line;
			while ((c = *cp2++) && c != '|' && c != ':')
				*cp1++ = c;
			*cp1 = '\0';
			startpr(2);
		}
		return;
	}
	while (--argc) {
		printer = *++argv;
		if ((status = pgetent(line, printer)) < 0) {
			printf("cannot open printer description file\n");
			continue;
		} else if (status == 0) {
			printf("unknown printer %s\n", printer);
			continue;
		}
		startpr(2);
	}
E 13
E 9
E 6
}
E 1
