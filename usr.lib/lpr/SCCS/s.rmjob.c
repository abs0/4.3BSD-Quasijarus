h17824
s 00001/00001/00300
d D 5.4 06/02/13 03:58:19 msokolov 14 13
c support for Ethernet-attached printers
e
s 00010/00005/00291
d D 5.3 88/06/30 18:00:14 bostic 13 12
c install approved copyright notice
e
s 00009/00003/00287
d D 5.2 88/05/05 18:08:37 bostic 12 11
c written by Ralph Campbell; add Berkeley specific header
e
s 00007/00001/00283
d D 5.1 85/06/06 10:09:18 dist 11 10
c Add copyright
e
s 00005/00011/00279
d D 4.10 84/07/24 16:57:35 ralph 10 9
c don't make vars static - rename
e
s 00001/00001/00289
d D 4.9 84/01/11 12:20:15 ralph 9 8
c fix call to startdaemon().
e
s 00006/00000/00284
d D 4.8 83/11/15 14:41:57 ralph 8 7
c trying to fix segmentation fault problem.
e
s 00004/00001/00280
d D 4.7 83/07/17 00:12:23 sam 7 6
c put sccs id's to some use
e
s 00005/00001/00276
d D 4.6 83/06/29 17:09:55 ralph 6 5
c changed to use unix domain ipc.
e
s 00001/00001/00276
d D 4.5 83/06/15 14:58:02 sam 5 4
c open and flock defines changed
e
s 00012/00006/00265
d D 4.4 83/06/02 12:23:53 ralph 4 3
c made local variables static to improve separation between functions.
e
s 00003/00004/00268
d D 4.3 83/05/18 16:45:33 ralph 3 2
c fixed lprm segmentation fault when remote is down.
e
s 00017/00018/00255
d D 4.2 83/05/13 11:53:55 ralph 2 1
c bug fixes and changes for lpc command.
e
s 00273/00000/00000
d D 4.1 83/04/29 11:29:58 ralph 1 0
c date and time created 83/04/29 11:29:58 by ralph
e
u
U
t
T
I 11
/*
 * Copyright (c) 1983 Regents of the University of California.
D 12
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 12
I 12
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 13
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 13
I 13
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
E 13
E 12
 */

E 11
I 1
D 7
/*	%M%	%I%	%E%	*/
E 7
I 7
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 11
#endif
E 11
I 11
D 12
#endif not lint
E 12
I 12
#endif /* not lint */
E 12
E 11

E 7
/*
 * rmjob - remove the specified jobs from the queue.
 */

#include "lp.h"

/*
 * Stuff for handling lprm specifications
 */
extern char	*user[];		/* users to process */
extern int	users;			/* # of users in user array */
extern int	requ[];			/* job number of spool entries */
extern int	requests;		/* # of spool requests */
I 4
extern char	*person;		/* name of person doing lprm */
E 4

D 4
char	*person;			/* name of person doing lprm */
char	root[] = "root";
int	all = 0;			/* eliminate all files (root only) */
int	cur_daemon;			/* daemon's pid */
char	current[40];			/* active control file name */
E 4
I 4
D 10
static char	root[] = "root";
static int	all = 0;		/* eliminate all files (root only) */
static int	cur_daemon;		/* daemon's pid */
static char	current[40];		/* active control file name */
E 10
I 10
char	root[] = "root";
int	all = 0;		/* eliminate all files (root only) */
int	cur_daemon;		/* daemon's pid */
char	current[40];		/* active control file name */
E 10
E 4

int	iscf();

rmjob()
{
	register int i, nitems;
	int assasinated = 0;
	struct direct **files;

D 2
	name = "rmjob";

E 2
	if ((i = pgetent(line, printer)) < 0)
		fatal("cannot open printer description file");
	else if (i == 0)
		fatal("unknown printer");
	if ((SD = pgetstr("sd", &bp)) == NULL)
		SD = DEFSPOOL;
	if ((LO = pgetstr("lo", &bp)) == NULL)
		LO = DEFLOCK;
	if ((LP = pgetstr("lp", &bp)) == NULL)
		LP = DEFDEVLP;
	if ((RP = pgetstr("rp", &bp)) == NULL)
D 2
		RP = printer;
E 2
I 2
		RP = DEFLP;
E 2
D 3
	if ((RM = pgetstr("rm", &bp)) == NULL)
		RM = host;
E 3
I 3
	RM = pgetstr("rm", &bp);
E 3

	/*
	 * If the format was `lprm -' and the user isn't the super-user,
	 *  then fake things to look like he said `lprm user'.
	 */
	if (users < 0) {
		if (getuid() == 0)
			all = 1;	/* all files in local queue */
		else {
			user[0] = person;
			users = 1;
		}
	}
	if (!strcmp(person, "-all")) {
		if (from == host)
			fatal("The login name \"-all\" is reserved");
		all = 1;	/* all those from 'from' */
		person = root;
	}

	if (chdir(SD) < 0)
		fatal("cannot chdir to spool directory");
	if ((nitems = scandir(".", &files, iscf, NULL)) < 0)
		fatal("cannot access spool directory");

	if (nitems) {
		/*
		 * Check for an active printer daemon (in which case we
		 *  kill it if it is reading our file) then remove stuff
		 *  (after which we have to restart the daemon).
		 */
		if (lockchk(LO) && chk(current)) {
			assasinated = kill(cur_daemon, SIGINT) == 0;
			if (!assasinated)
				fatal("cannot kill printer daemon");
		}
		/*
		 * process the files
		 */
		for (i = 0; i < nitems; i++)
			process(files[i]->d_name);
	}
	chkremote();
	/*
	 * Restart the printer daemon if it was killed
	 */
D 4
	if (assasinated && !startdaemon())
E 4
I 4
D 9
	if (assasinated && !startdaemon(host))
E 9
I 9
	if (assasinated && !startdaemon(printer))
E 9
E 4
		fatal("cannot restart printer daemon\n");
	exit(0);
}

/*
 * Process a lock file: collect the pid of the active
 *  daemon and the file name of the active spool entry.
 * Return boolean indicating existence of a lock file.
 */
I 4
D 10
static
E 10
E 4
lockchk(s)
	char *s;
{
	register FILE *fp;
	register int i, n;

	if ((fp = fopen(s, "r")) == NULL)
		if (errno == EACCES)
			fatal("can't access lock file");
		else
			return(0);
D 5
	if (!getline(fp) || flock(fileno(fp), FSHLOCK|FNBLOCK) == 0) {
E 5
I 5
D 6
	if (!getline(fp) || flock(fileno(fp), LOCK_SH|LOCK_NB) == 0) {
E 6
I 6
	if (!getline(fp)) {
E 6
E 5
		(void) fclose(fp);
		return(0);		/* no daemon present */
	}
	cur_daemon = atoi(line);
I 6
	if (kill(cur_daemon, 0) < 0) {
		(void) fclose(fp);
		return(0);		/* no daemon present */
	}
E 6
	for (i = 1; (n = fread(current, sizeof(char), sizeof(current), fp)) <= 0; i++) {
D 3
		if (i > 20) {
E 3
I 3
		if (i > 5) {
E 3
			n = 1;
			break;
		}
		sleep(i);
	}
	current[n-1] = '\0';
	(void) fclose(fp);
	return(1);
}

/*
 * Process a control file.
 */
I 4
D 10
static
E 10
E 4
process(file)
	char *file;
{
	FILE *cfp;

	if (!chk(file))
		return;
	if ((cfp = fopen(file, "r")) == NULL)
		fatal("cannot open %s", file);
D 10
	while (getline()) {
E 10
I 10
	while (getline(cfp)) {
E 10
		switch (line[0]) {
		case 'U':  /* unlink associated files */
			if (from != host)
				printf("%s: ", host);
			printf(unlink(line+1) ? "cannot dequeue %s\n" :
				"%s dequeued\n", line+1);
		}
	}
	(void) fclose(cfp);
	if (from != host)
		printf("%s: ", host);
	printf(unlink(file) ? "cannot dequeue %s\n" : "%s dequeued\n", file);
}

/*
 * Do the dirty work in checking
 */
I 4
D 10
static
E 10
E 4
chk(file)
	char *file;
{
	register int *r, n;
	register char **u, *cp;
	FILE *cfp;

I 8
	/*
	 * Check for valid cf file name (mostly checking current).
	 */
	if (strlen(file) < 7 || file[0] != 'c' || file[1] != 'f')
		return(0);

E 8
	if (all && (from == host || !strcmp(from, file+6)))
		return(1);

	/*
	 * get the owner's name from the control file.
	 */
	if ((cfp = fopen(file, "r")) == NULL)
		return(0);
	while (getline(cfp)) {
		if (line[0] == 'P')
			break;
	}
	(void) fclose(cfp);
	if (line[0] != 'P')
		return(0);

	if (users == 0 && requests == 0)
		return(!strcmp(file, current) && isowner(line+1, file));
	/*
	 * Check the request list
	 */
	for (n = 0, cp = file+3; isdigit(*cp); )
		n = n * 10 + (*cp++ - '0');
	for (r = requ; r < &requ[requests]; r++)
		if (*r == n && isowner(line+1, file))
			return(1);
	/*
	 * Check to see if it's in the user list
	 */
	for (u = user; u < &user[users]; u++)
		if (!strcmp(*u, line+1) && isowner(line+1, file))
			return(1);
	return(0);
}

/*
 * If root is removing a file on the local machine, allow it.
D 2
 * If root is removing a file on a remote machine, only allow
 * files sent from the local machine to be removed.
E 2
I 2
 * If root is removing a file from a remote machine, only allow
 * files sent from the remote machine to be removed.
E 2
 * Normal users can only remove the file from where it was sent.
 */
I 4
D 10
static
E 10
E 4
isowner(owner, file)
	char *owner, *file;
{
D 2
	register int r;

	if (from == host)
		r = access(file, 2) == 0;
	else
		r = (!strcmp(person, root) || !strcmp(person, owner)) &&
			!strcmp(from, file+6);
	if (!r) {
		if (from != host)
			printf("%s: ", host);
		printf("%s: Permission denied\n", file);
	}
	return(r);
E 2
I 2
	if (!strcmp(person, root) && (from == host || !strcmp(from, file+6)))
		return(1);
	if (!strcmp(person, owner) && !strcmp(from, file+6))
		return(1);
	if (from != host)
		printf("%s: ", host);
	printf("%s: Permission denied\n", file);
	return(0);
E 2
}

/*
 * Check to see if we are sending files to a remote machine. If we are,
 * then try removing files on the remote machine.
 */
I 4
D 10
static
E 10
E 4
chkremote()
{
	register char *cp;
	register int i, rem;
	char buf[BUFSIZ];

	if (*LP || RM == NULL)
		return;	/* not sending to a remote machine */
I 2

	/*
	 * Flush stdout so the user can see what has been deleted
	 * while we wait (possibly) for the connection.
	 */
	fflush(stdout);
E 2

	sprintf(buf, "\5%s %s", RP, all ? "-all" : person);
	cp = buf;
	for (i = 0; i < users; i++) {
		cp += strlen(cp);
		*cp++ = ' ';
		strcpy(cp, user[i]);
	}
	for (i = 0; i < requests; i++) {
		cp += strlen(cp);
		(void) sprintf(cp, " %d", requ[i]);
	}
	strcat(cp, "\n");
D 3
	rem = getport();
E 3
I 3
D 14
	rem = getport(RM);
E 14
I 14
	rem = getport(RM, 0);
E 14
E 3
	if (rem < 0) {
		if (from != host)
			printf("%s: ", host);
		printf("connection to %s is down\n", RM);
	} else {
		i = strlen(buf);
		if (write(rem, buf, i) != i)
			fatal("Lost connection");
		while ((i = read(rem, buf, sizeof(buf))) > 0)
			(void) fwrite(buf, 1, i, stdout);
		(void) close(rem);
	}
}

/*
 * Return 1 if the filename begins with 'cf'
 */
I 4
D 10
static
E 10
E 4
iscf(d)
	struct direct *d;
{
	return(d->d_name[0] == 'c' && d->d_name[1] == 'f');
}
E 1
