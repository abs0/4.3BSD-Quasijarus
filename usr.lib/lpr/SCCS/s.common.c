h59797
s 00021/00011/00243
d D 5.9 06/02/13 03:58:13 msokolov 18 17
c support for Ethernet-attached printers
e
s 00002/00000/00252
d D 5.8 04/09/03 21:49:54 msokolov 17 16
c pp and jp capabilities for printer prep and job prep
e
s 00001/00000/00251
d D 5.7 04/08/21 19:19:33 msokolov 16 15
c implement bf (banner filter) capability
e
s 00002/00000/00249
d D 5.6 04/08/04 06:08:20 msokolov 15 14
c add ea and pi capabilities to support smarter filters
e
s 00001/00000/00248
d D 5.5 04/07/30 08:31:35 msokolov 14 13
c new ct boolen capability to ensure printer readiness with ^T
e
s 00010/00005/00238
d D 5.4 88/06/30 17:59:40 bostic 13 12
c install approved copyright notice
e
s 00009/00003/00234
d D 5.3 88/05/05 18:07:40 bostic 12 11
c written by Ralph Campbell; add Berkeley specific header
e
s 00000/00022/00237
d D 5.2 86/05/06 18:36:47 bloom 11 10
c remove local copy of rresvport
e
s 00007/00001/00252
d D 5.1 85/06/06 09:58:39 dist 10 9
c Add copyright
e
s 00001/00000/00252
d D 4.9 85/02/27 16:20:03 ralph 9 8
c added 'hl' flag to printcap to print the banner last.
e
s 00004/00001/00248
d D 4.8 83/07/17 00:10:51 sam 8 7
c put sccs id's to some use
e
s 00001/00000/00248
d D 4.7 83/06/22 09:33:53 ralph 7 6
c added -n option to print ditroff files.
e
s 00007/00005/00241
d D 4.6 83/06/17 15:09:22 ralph 6 5
c fixed `fc' and `fs' when 0177777 is needed.
e
s 00016/00011/00230
d D 4.5 83/06/02 12:21:23 ralph 5 4
c fixed getport() so sockets are not left open after errors.
e
s 00000/00014/00241
d D 4.4 83/05/27 11:36:02 ralph 4 3
c improved error messages
e
s 00006/00007/00249
d D 4.3 83/05/18 16:45:43 ralph 3 2
c fixed lprm segmentation fault when remote is down.
e
s 00004/00016/00252
d D 4.2 83/05/13 11:54:04 ralph 2 1
c bug fixes and changes for lpc command.
e
s 00268/00000/00000
d D 4.1 83/04/29 11:38:57 ralph 1 0
c date and time created 83/04/29 11:38:57 by ralph
e
u
U
t
T
I 10
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

E 10
I 1
D 8
/*	%M%	%I%	%E%	*/
E 8
I 8
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 10
#endif
E 10
I 10
D 12
#endif not lint
E 12
I 12
#endif /* not lint */
E 12
E 10

E 8
/*
 * Routines and data common to all the line printer functions.
 */

#include "lp.h"

int	DU;		/* daeomon user-id */
int	MX;		/* maximum number of blocks to copy */
I 6
int	MC;		/* maximum number of copies allowed */
E 6
char	*LP;		/* line printer device name */
char	*RM;		/* remote machine name */
char	*RP;		/* remote printer name */
char	*LO;		/* lock file name */
char	*ST;		/* status file name */
char	*SD;		/* spool directory */
char	*AF;		/* accounting file */
char	*LF;		/* log file for error messages */
char	*OF;		/* name of output filter (created once) */
char	*IF;		/* name of input filter (created per job) */
I 2
char	*RF;		/* name of fortran text filter (per job) */
E 2
char	*TF;		/* name of troff filter (per job) */
I 7
char	*NF;		/* name of ditroff filter (per job) */
E 7
char	*DF;		/* name of tex filter (per job) */
char	*GF;		/* name of graph(1G) filter (per job) */
char	*VF;		/* name of vplot filter (per job) */
char	*CF;		/* name of cifplot filter (per job) */
char	*PF;		/* name of vrast filter (per job) */
I 16
char	*BF;		/* name of banner filter */
I 17
char	*PP;		/* name of printer prep program */
char	*JP;		/* name of job prep program */
E 17
E 16
char	*FF;		/* form feed string */
char	*TR;		/* trailer string to be output when Q empties */
I 6
short	SC;		/* suppress multiple copies */
E 6
short	SF;		/* suppress FF on each print job */
short	SH;		/* suppress header page */
short	SB;		/* short banner instead of normal header */
I 9
short	HL;		/* print header last */
E 9
short	RW;		/* open LP for reading and writing */
I 14
short	CT;		/* check printer for readiness with ^T */
E 14
short	PW;		/* page width */
short	PL;		/* page length */
I 2
short	PX;		/* page width in pixels */
short	PY;		/* page length in pixels */
I 15
short	EA;		/* pass extended arguments to filters */
short	PI;		/* input filter incorporates pr functionality */
E 15
E 2
short	BR;		/* baud rate if lp is a tty */
D 6
short	FC;		/* flags to clear if lp is a tty */
short	FS;		/* flags to set if lp is a tty */
short	XC;		/* flags to clear for local mode */
short	XS;		/* flags to set for local mode */
E 6
I 6
int	FC;		/* flags to clear if lp is a tty */
int	FS;		/* flags to set if lp is a tty */
int	XC;		/* flags to clear for local mode */
int	XS;		/* flags to set for local mode */
E 6
I 2
short	RS;		/* restricted to those with local accounts */
E 2

char	line[BUFSIZ];
char	pbuf[BUFSIZ/2];	/* buffer for printcap strings */
char	*bp = pbuf;	/* pointer into pbuf for pgetent() */
char	*name;		/* program name */
char	*printer;	/* printer name */
char	host[32];	/* host machine name */
char	*from = host;	/* client's machine name */

/*
D 18
 * Create a connection to the remote printer server.
E 18
I 18
 * Create a TCP connection to host "rhost" at port "rport".
 * If rport == 0, then use the printer service port.
E 18
 * Most of this code comes from rcmd.c.
 */
D 3
getport()
E 3
I 3
D 18
getport(rhost)
E 18
I 18
getport(rhost, rport)
E 18
	char *rhost;
I 18
	int rport;
E 18
E 3
{
	struct hostent *hp;
	struct servent *sp;
	struct sockaddr_in sin;
	int s, timo = 1, lport = IPPORT_RESERVED - 1;
I 5
	int err;
E 5

	/*
	 * Get the host address and port number to connect to.
	 */
D 3
	if (RM == NULL)
E 3
I 3
	if (rhost == NULL)
E 3
		fatal("no remote host to connect to");
D 3
	hp = gethostbyname(RM);
E 3
I 3
D 18
	hp = gethostbyname(rhost);
E 3
	if (hp == NULL)
D 3
		fatal("unknown host %s", RM);
E 3
I 3
		fatal("unknown host %s", rhost);
E 3
	sp = getservbyname("printer", "tcp");
	if (sp == NULL)
		fatal("printer/tcp: unknown service");
E 18
	bzero((char *)&sin, sizeof(sin));
D 18
	bcopy(hp->h_addr, (caddr_t)&sin.sin_addr, hp->h_length);
	sin.sin_family = hp->h_addrtype;
	sin.sin_port = sp->s_port;
E 18
I 18
	sin.sin_addr.s_addr = inet_addr(rhost);
	if (sin.sin_addr.s_addr != INADDR_NONE)
		sin.sin_family = AF_INET;
	else {
		hp = gethostbyname(rhost);
		if (hp == NULL)
			fatal("unknown host %s", rhost);
		bcopy(hp->h_addr, (caddr_t)&sin.sin_addr, hp->h_length);
		sin.sin_family = hp->h_addrtype;
	}
	if (rport == 0) {
		sp = getservbyname("printer", "tcp");
		if (sp == NULL)
			fatal("printer/tcp: unknown service");
		sin.sin_port = sp->s_port;
	} else
		sin.sin_port = htons(rport);
E 18

	/*
	 * Try connecting to the server.
	 */
retry:
	s = rresvport(&lport);
	if (s < 0)
		return(-1);
	if (connect(s, (caddr_t)&sin, sizeof(sin), 0) < 0) {
I 5
		err = errno;
		(void) close(s);
		errno = err;
E 5
		if (errno == EADDRINUSE) {
D 5
			close(s);
E 5
			lport--;
			goto retry;
		}
		if (errno == ECONNREFUSED && timo <= 16) {
D 5
			(void) close(s);
E 5
			sleep(timo);
			timo *= 2;
			goto retry;
		}
		return(-1);
	}
	return(s);
}

D 11
rresvport(alport)
	int *alport;
{
	struct sockaddr_in sin;
	int s;

	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = 0;
	s = socket(AF_INET, SOCK_STREAM, 0);
	if (s < 0)
		return(-1);
D 5
	for (;;) {
E 5
I 5
	for (; *alport > IPPORT_RESERVED/2; (*alport)--) {
E 5
		sin.sin_port = htons((u_short) *alport);
		if (bind(s, (caddr_t)&sin, sizeof(sin), 0) >= 0)
			return(s);
		if (errno != EADDRINUSE && errno != EADDRNOTAVAIL)
D 5
			return(-1);
		(*alport)--;
D 3
		if (*alport == IPPORT_RESERVED/2) {
			printf("%s: All ports in use\n", name);
E 3
I 3
		if (*alport == IPPORT_RESERVED/2)
E 3
			return(-1);
E 5
I 5
			break;
E 5
D 3
		}
E 3
	}
I 5
	(void) close(s);
	return(-1);
E 5
}

E 11
/*
 * Getline reads a line from the control file cfp, removes tabs, converts
 *  new-line to null and leaves it in line.
 * Returns 0 at EOF or the number of characters read.
 */
getline(cfp)
	FILE *cfp;
{
	register int linel = 0;
	register char *lp = line;
	register c;

	while ((c = getc(cfp)) != '\n') {
		if (c == EOF)
			return(0);
		if (c == '\t') {
			do {
				*lp++ = ' ';
				linel++;
			} while ((linel & 07) != 0);
			continue;
		}
		*lp++ = c;
		linel++;
	}
	*lp++ = '\0';
	return(linel);
}

/*
 * Scan the current directory and make a list of daemon files sorted by
 * creation time.
 * Return the number of entries and a pointer to the list.
 */
getq(namelist)
	struct queue *(*namelist[]);
{
	register struct direct *d;
	register struct queue *q, **queue;
	register int nitems;
	struct stat stbuf;
	int arraysz, compar();
	DIR *dirp;

D 6
	if ((dirp = opendir(".")) == NULL)
E 6
I 6
	if ((dirp = opendir(SD)) == NULL)
E 6
		return(-1);
	if (fstat(dirp->dd_fd, &stbuf) < 0)
D 5
		return(-1);
E 5
I 5
		goto errdone;
E 5

	/*
	 * Estimate the array size by taking the size of the directory file
	 * and dividing it by a multiple of the minimum size entry. 
	 */
	arraysz = (stbuf.st_size / 24);
	queue = (struct queue **)malloc(arraysz * sizeof(struct queue *));
	if (queue == NULL)
D 5
		return(-1);
E 5
I 5
		goto errdone;
E 5

	nitems = 0;
	while ((d = readdir(dirp)) != NULL) {
		if (d->d_name[0] != 'c' || d->d_name[1] != 'f')
			continue;	/* daemon control files only */
		if (stat(d->d_name, &stbuf) < 0)
			continue;	/* Doesn't exist */
		q = (struct queue *)malloc(sizeof(time_t)+strlen(d->d_name)+1);
		if (q == NULL)
D 5
			return(-1);
E 5
I 5
			goto errdone;
E 5
		q->q_time = stbuf.st_mtime;
		strcpy(q->q_name, d->d_name);
		/*
		 * Check to make sure the array has space left and
		 * realloc the maximum size.
		 */
		if (++nitems > arraysz) {
			queue = (struct queue **)realloc((char *)queue,
				(stbuf.st_size/12) * sizeof(struct queue *));
			if (queue == NULL)
D 5
				return(-1);
E 5
I 5
				goto errdone;
E 5
		}
		queue[nitems-1] = q;
	}
	closedir(dirp);
	if (nitems)
		qsort(queue, nitems, sizeof(struct queue *), compar);
	*namelist = queue;
	return(nitems);
I 5

errdone:
	closedir(dirp);
	return(-1);
E 5
}

/*
 * Compare modification times.
 */
static
compar(p1, p2)
	register struct queue **p1, **p2;
{
	if ((*p1)->q_time < (*p2)->q_time)
		return(-1);
	if ((*p1)->q_time > (*p2)->q_time)
		return(1);
	return(0);
D 2
}

/*VARARGS1*/
status(msg, a1, a2, a3)
	char *msg;
{
	register int fd;
	char buf[BUFSIZ];

	umask(0);
	if ((fd = open(ST, FWRONLY|FCREATE|FTRUNCATE|FEXLOCK, 0664)) < 0)
		fatal("cannot create status file");
	sprintf(buf, msg, a1, a2, a3);
	strcat(buf, "\n");
	(void) write(fd, buf, strlen(buf));
	(void) close(fd);
E 2
}

/*VARARGS1*/
fatal(msg, a1, a2, a3)
	char *msg;
{
	if (from != host)
		printf("%s: ", host);
	printf("%s: ", name);
	if (printer)
		printf("%s: ", printer);
	printf(msg, a1, a2, a3);
	putchar('\n');
	exit(1);
}
D 4

fatalerror(msg)
	char *msg;
{
	extern int sys_nerr;
	extern char *sys_errlist[];

	printf("%s: ", name);
	if (*msg)
		printf("%s: ", msg);
	fputs(errno < sys_nerr ? sys_errlist[errno] : "Unknown error" , stdout);
	putchar('\n');
	exit(1);
}
E 4
E 1
