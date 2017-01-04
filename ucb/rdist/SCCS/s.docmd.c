h63014
s 00010/00005/00580
d D 5.3 88/06/29 20:19:27 bostic 30 29
c install approved copyright notice
e
s 00009/00003/00576
d D 5.2 88/02/01 11:34:38 bostic 29 28
c add new Berkeley headers
e
s 00008/00002/00571
d D 5.1 85/06/06 08:49:19 dist 28 27
c Add copyright
e
s 00024/00007/00549
d D 4.26 85/03/05 15:48:25 ralph 27 25
c use getservbyname(), change host.user to user@host.
e
s 00007/00001/00555
d R 4.26 85/02/28 15:23:35 ralph 26 25
c get rid of IPPORT_CMDSERVER.
e
s 00001/00001/00555
d D 4.25 85/02/28 14:40:51 ralph 25 24
c moved rdist to /usr/ucb
e
s 00001/00001/00555
d D 4.24 85/02/05 09:50:58 ralph 24 23
c null machine list same as no list.
e
s 00009/00001/00547
d D 4.23 85/02/04 14:31:31 ralph 23 22
c added -m option to update listed hosts only.
e
s 00008/00001/00540
d D 4.22 84/12/06 14:59:31 ralph 22 21
c added FILE variable for special commands, allow symbolic links to non-existing file
e
s 00014/00004/00527
d D 4.21 84/06/28 11:44:50 ralph 21 20
c handle symbolic and hard links.
e
s 00021/00031/00510
d D 4.20 84/05/03 11:41:00 ralph 20 19
c added regular expressions for exception pattern matching.
e
s 00028/00014/00513
d D 4.19 84/04/06 15:48:18 ralph 19 18
c added labels for partial updates.
e
s 00003/00004/00524
d D 4.18 84/03/19 14:00:42 ralph 18 17
c update cur_host correctly so multiple connections work.
e
s 00014/00010/00514
d D 4.17 84/03/14 11:46:37 ralph 17 16
c fix multiple connections to same (down) host and loss of connection.
e
s 00003/00001/00521
d D 4.16 84/03/13 09:49:47 ralph 16 15
c print host being updated when -n specified.
e
s 00009/00006/00513
d D 4.15 84/02/24 13:55:35 ralph 15 14
c fix return value in makeconn().
e
s 00010/00010/00509
d D 4.14 84/02/16 11:56:38 ralph 14 13
c don't update stamp file time if -v.
e
s 00167/00103/00352
d D 4.13 84/02/09 16:22:02 ralph 13 12
c read entire distfile and sort entries by host.
e
s 00002/00002/00453
d D 4.12 84/01/04 09:57:21 ralph 12 11
c minor bug in creating mail address list.
e
s 00000/00002/00455
d D 4.11 83/12/19 14:44:36 ralph 11 10
c making lint happier
e
s 00020/00004/00437
d D 4.10 83/11/29 16:51:54 ralph 10 9
c added version number for protocol changes.
e
s 00053/00069/00388
d D 4.9 83/11/29 16:00:01 ralph 9 8
c bug fixes and added `special' command.
e
s 00063/00091/00394
d D 4.8 83/11/01 14:29:20 ralph 8 7
c fixes for -r and -w.
e
s 00002/00002/00483
d D 4.7 83/10/27 10:44:40 ralph 7 6
c fixed a bug in making the exceptions list (ouch!)
e
s 00043/00012/00442
d D 4.6 83/10/26 11:42:02 ralph 6 5
c added -b option for binary compare. Fixed -r w/ except.
e
s 00015/00006/00439
d D 4.5 83/10/20 12:14:33 ralph 5 4
c added -r option to remove extra files.
e
s 00045/00030/00400
d D 4.4 83/10/12 16:38:35 ralph 4 3
c fixed install flags, file comparisons, mail addresses, added -c.
e
s 00032/00026/00398
d D 4.3 83/10/10 16:15:06 ralph 3 2
c stable version that works.
e
s 00219/00030/00205
d D 4.2 83/09/27 14:38:21 ralph 2 1
c First stable version.
e
s 00235/00000/00000
d D 4.1 83/09/07 13:19:26 ralph 1 0
c date and time created 83/09/07 13:19:26 by ralph
e
u
U
t
T
I 28
/*
 * Copyright (c) 1983 Regents of the University of California.
D 29
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 29
I 29
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 30
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 30
I 30
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
E 30
E 29
 */

E 28
I 1
#ifndef lint
D 28
static	char *sccsid = "%W% (Berkeley) %E%";
#endif
E 28
I 28
static char sccsid[] = "%W% (Berkeley) %G%";
D 29
#endif not lint
E 29
I 29
#endif /* not lint */
E 29
E 28

#include "defs.h"
I 13
#include <setjmp.h>
I 27
#include <netdb.h>
E 27
E 13

I 22
#ifndef RDIST
D 25
#define RDIST "/usr/local/rdist"
E 25
I 25
#define RDIST "/usr/ucb/rdist"
E 25
#endif

E 22
D 13
FILE	*lfp;		/* log file for recording files updated */
I 9
struct	block *special;	/* list of special commands */
E 13
I 13
FILE	*lfp;			/* log file for recording files updated */
D 20
struct	subcmd *special;	/* list of special commands */
E 20
I 20
struct	subcmd *subcmds;	/* list of sub-commands for current cmd */
E 20
jmp_buf	env;
E 13
E 9

I 13
int	cleanup();
int	lostconn();

E 13
/*
I 13
 * Do the commands in cmds (initialized by yyparse).
 */
D 23
docmds(argc, argv)
E 23
I 23
docmds(dhosts, argc, argv)
	char **dhosts;
E 23
	int argc;
	char **argv;
{
	register struct cmd *c;
I 19
	register struct namelist *f;
	register char **cpp;
E 19
	extern struct cmd *cmds;

	signal(SIGHUP, cleanup);
	signal(SIGINT, cleanup);
	signal(SIGQUIT, cleanup);
	signal(SIGTERM, cleanup);

	for (c = cmds; c != NULL; c = c->c_next) {
I 23
D 24
		if (dhosts != NULL) {
E 24
I 24
		if (dhosts != NULL && *dhosts != NULL) {
E 24
			for (cpp = dhosts; *cpp; cpp++)
				if (strcmp(c->c_name, *cpp) == 0)
					goto fndhost;
			continue;
		}
	fndhost:
E 23
I 19
		if (argc) {
			for (cpp = argv; *cpp; cpp++) {
				if (c->c_label != NULL &&
D 20
				    strcmp(c->c_label, (*cpp)+1) == 0) {
E 20
I 20
				    strcmp(c->c_label, *cpp) == 0) {
E 20
					cpp = NULL;
					goto found;
				}
				for (f = c->c_files; f != NULL; f = f->n_next)
					if (strcmp(f->n_name, *cpp) == 0)
						goto found;
			}
			continue;
		} else
			cpp = NULL;
	found:
E 19
		switch (c->c_type) {
		case ARROW:
D 19
			doarrow(c->c_files, c->c_name, c->c_cmds);
E 19
I 19
			doarrow(cpp, c->c_files, c->c_name, c->c_cmds);
E 19
			break;
		case DCOLON:
D 19
			dodcolon(c->c_files, c->c_name, c->c_cmds);
E 19
I 19
			dodcolon(cpp, c->c_files, c->c_name, c->c_cmds);
E 19
			break;
		default:
			fatal("illegal command type %d\n", c->c_type);
		}
	}
	closeconn();
}

/*
E 13
D 2
 * Routines to process commands.
E 2
I 2
 * Process commands for sending files to other machines.
E 2
 */
D 2
docmd(files, hosts, cmds)
E 2
I 2
D 13
dohcmds(files, hosts, cmds)
E 2
	struct block *files, *hosts, *cmds;
E 13
I 13
D 15
doarrow(files, host, cmds)
E 15
I 15
D 19
doarrow(files, rhost, cmds)
E 19
I 19
doarrow(filev, files, rhost, cmds)
	char **filev;
E 19
E 15
	struct namelist *files;
D 15
	char *host;
E 15
I 15
	char *rhost;
E 15
	struct subcmd *cmds;
E 13
{
D 13
	register struct block *h, *f, *c;
D 3
	register char *cp, **cpp;
E 3
I 3
	register char **cpp;
E 13
I 13
	register struct namelist *f;
	register struct subcmd *sc;
I 19
	register char **cpp;
E 19
E 13
I 6
D 8
	static struct block excpt = { EXCEPT };
	char *cp;
E 8
E 6
E 3
D 2
	int n;
E 2
I 2
D 21
	int n, ddir;
E 21
I 21
	int n, ddir, opts = options;
E 21
E 2

	if (debug)
D 2
		printf("docmd()\n");
E 2
I 2
D 13
		printf("dohcmds(%x, %x, %x)\n", files, hosts, cmds);
E 13
I 13
D 15
		printf("doarrow(%x, %s, %x)\n", files, host, cmds);
E 15
I 15
		printf("doarrow(%x, %s, %x)\n", files, rhost, cmds);
E 15
E 13
E 2

D 2
	files = expand(files);
	hosts = expand(hosts);
E 2
I 2
D 9
	files = expand(files, 0);
E 9
I 9
D 13
	files = expand(files, E_VARS|E_SHELL);
E 13
E 9
I 6
	if (files == NULL) {
		error("no files to be updated\n");
		return;
	}
E 6
D 9
	hosts = expand(hosts, 1);
E 9
I 9
D 13
	hosts = expand(hosts, E_VARS|E_SHELL);
E 9
E 2
D 6
	if (files == NULL)
		fatal("no files to be updated\n");
	if (hosts == NULL)
		fatal("empty list of hosts to be updated\n");
	except = cmds;
E 6
I 6
	if (hosts == NULL) {
		error("empty list of hosts to be updated\n");
		return;
	}
E 13
I 8
D 20
	if (!mkexceptlist(cmds))
		return;
I 9
	special = cmds;
E 20
E 9

I 20
	subcmds = cmds;
E 20
E 8
E 6
I 2
D 13
	ddir = files->b_next != NULL;
E 13
I 13
	ddir = files->n_next != NULL;	/* destination is a directory */
E 13
I 6
D 8
	f = NULL;
	except = NULL;
	for (c = cmds; c != NULL; c = c->b_next) {
		if (c->b_type != EXCEPT)
			continue;
		if (except == NULL)
			except = &excpt;
		for (h = c->b_args; h != NULL; h = h->b_next) {
			cp = h->b_name;
			if (*cp == '~') {
				(void) exptilde(buf, cp);
				cp = buf;
			}
			if (f == NULL)
				except->b_args = f = expand(makeblock(NAME, cp), 0);
D 7
			else {
E 7
I 7
			else
E 7
				f->b_next = expand(makeblock(NAME, cp), 0);
I 7
			while (f->b_next != NULL)
E 7
				f = f->b_next;
D 7
			}
E 7
		}
	}
E 8
E 6
E 2
D 20

E 20
D 13
	for (h = hosts; h != NULL; h = h->b_next) {
I 2
		if (!qflag)
			printf("updating host %s\n", h->b_name);
E 2
		if (!nflag) {
I 2
			if (!makeconn(h->b_name))
				continue;
E 2
			if ((lfp = fopen(tmpfile, "w")) == NULL) {
				fatal("cannot open %s\n", tmpfile);
				exit(1);
			}
E 13
I 13
D 16
	if (!nflag) {
E 16
I 16
	if (nflag)
		printf("updating host %s\n", rhost);
	else {
E 16
D 17
		if (setjmp(env) != 0)
E 17
I 17
		if (setjmp(env))
E 17
			goto done;
		signal(SIGPIPE, lostconn);
D 15
		if (!makeconn(host))
E 15
I 15
		if (!makeconn(rhost))
E 15
			return;
		if ((lfp = fopen(tmpfile, "w")) == NULL) {
			fatal("cannot open %s\n", tmpfile);
			exit(1);
E 13
D 2
			if (!makeconn(h->b_name))
				continue;
E 2
		}
D 13
		for (f = files; f != NULL; f = f->b_next) {
			if (filec) {
				for (cpp = filev; *cpp; cpp++)
					if (!strcmp(f->b_name, *cpp))
						goto found;
I 2
D 6
				if (!nflag) {
E 6
I 6
				if (!nflag)
E 6
					(void) fclose(lfp);
E 13
I 13
	}
	for (f = files; f != NULL; f = f->n_next) {
D 19
#ifdef notdef
		if (filec) {
			register char **cpp;

E 19
I 19
		if (filev) {
E 19
			for (cpp = filev; *cpp; cpp++)
D 19
				if (!strcmp(f->b_name, *cpp))
E 19
I 19
				if (strcmp(f->n_name, *cpp) == 0)
E 19
					goto found;
			if (!nflag)
				(void) fclose(lfp);
			continue;
		}
	found:
D 19
#endif
E 19
		n = 0;
		for (sc = cmds; sc != NULL; sc = sc->sc_next) {
			if (sc->sc_type != INSTALL)
E 13
D 6
				}
E 6
E 2
				continue;
D 13
			}
		found:
			n = 0;
D 5
			for (c = cmds; c != NULL; c = c->b_next)
				if (c->b_type == INSTALL) {
E 5
I 5
			for (c = cmds; c != NULL; c = c->b_next) {
				if (c->b_type != INSTALL)
					continue;
				n++;
D 8
				if (c->b_name == NULL)
					install(f->b_name, f->b_name, 0, c->b_options);
				else
E 5
D 2
					install(f->b_name, c->b_name, 0);
E 2
I 2
D 3
					install(f->b_name, c->b_name, ddir, 0);
E 3
I 3
					install(f->b_name, c->b_name, ddir, c->b_options);
E 8
I 8
				install(f->b_name, c->b_name,
					c->b_name == NULL ? 0 : ddir,
					c->b_options);
E 8
E 3
E 2
D 5
					n++;
D 3
				} else if (c->b_type == VERIFY) {
D 2
					install(f->b_name, c->b_name, 1);
E 2
I 2
					install(f->b_name, c->b_name, ddir, 1);
E 2
					n++;
E 3
				}
E 5
I 5
			}
E 5
			if (n == 0)
D 2
				install(f->b_name, f->b_name, 0);
E 2
I 2
D 4
				install(f->b_name, f->b_name, 0, 0);
E 4
I 4
D 8
				install(f->b_name, f->b_name, 0, options);
E 8
I 8
				install(f->b_name, NULL, 0, options);
E 13
I 13
			n++;
			install(f->n_name, sc->sc_name,
				sc->sc_name == NULL ? 0 : ddir, sc->sc_options);
I 21
			opts = sc->sc_options;
E 21
E 13
E 8
E 4
E 2
		}
D 13
		if (!nflag) {
D 2
			(void) fclose(lfp);
E 2
I 2
			/* signal end of connection */
			(void) write(rem, "\2\n", 2);
E 2
			(void) close(rem);
I 2
			(void) fclose(lfp);
E 2
		}
		for (c = cmds; c != NULL; c = c->b_next)
			if (c->b_type == NOTIFY)
D 2
				notify(h->b_name, c->b_args);
E 2
I 2
D 4
				notify(tmpfile, h->b_name, c->b_args);
E 4
I 4
				notify(tmpfile, h->b_name, c->b_args, 0);
E 13
I 13
		if (n == 0)
			install(f->n_name, NULL, 0, options);
E 13
E 4
E 2
	}
I 13
done:
	if (!nflag) {
D 17
		(void) signal(SIGPIPE, SIG_DFL);
E 17
I 17
		(void) signal(SIGPIPE, cleanup);
E 17
		(void) fclose(lfp);
		lfp = NULL;
	}
	for (sc = cmds; sc != NULL; sc = sc->sc_next)
		if (sc->sc_type == NOTIFY)
D 15
			notify(tmpfile, host, sc->sc_args, 0);
E 15
I 15
			notify(tmpfile, rhost, sc->sc_args, 0);
E 15
E 13
D 21
	if (!nflag)
E 21
I 21
	if (!nflag) {
E 21
		(void) unlink(tmpfile);
I 21
		for (; ihead != NULL; ihead = ihead->nextp) {
			free(ihead);
			if ((opts & IGNLNKS) || ihead->count == 0)
				continue;
			log(lfp, "%s: Warning: missing links\n",
				ihead->pathname);
		}
	}
E 21
}

/*
 * Create a connection to the rdist server on the machine rhost.
 */
makeconn(rhost)
	char *rhost;
{
I 6
D 11
	register struct block *c;
E 11
E 6
D 10
	register char *ruser;
E 10
I 10
	register char *ruser, *cp;
I 13
	static char *cur_host = NULL;
I 27
	static int port = -1;
	char tuser[20];
E 27
E 13
	int n;
E 10
	extern char user[];
I 22
	extern int userid;
E 22

D 4
	(void) sprintf(buf, "/usr/local/rdist -Server%s%s%s%s%s",
		vflag ? " -v" : "", qflag ? " -q" : "", nflag ? " -n" : "",
D 2
		yflag ? " -y" : "", debug ? " -d" : "");
E 2
I 2
		yflag ? " -y" : "", debug ? " -D" : "");
E 4
I 4
D 8
	(void) sprintf(buf, "/usr/local/rdist -Server%s%s",
		nflag ? " -n" : "", qflag ? " -q" : "");
E 8
I 8
D 13
	(void) sprintf(buf, "/usr/local/rdist -Server%s", qflag ? " -q" : "");
E 13
I 13
	if (debug)
		printf("makeconn(%s)\n", rhost);
E 13
E 8
E 4
E 2

I 13
D 17
	if (cur_host != NULL && strcmp(cur_host, rhost) == 0)
D 15
		return;
E 15
I 15
		return(1);
E 17
I 17
	if (cur_host != NULL && rem >= 0) {
		if (strcmp(cur_host, rhost) == 0)
			return(1);
		closeconn();
D 18
		cur_host = NULL;
E 18
	}
I 27
	cur_host = rhost;
	cp = index(rhost, '@');
	if (cp != NULL) {
		char c = *cp;
E 27
E 17
E 15

D 17
	closeconn();

E 17
E 13
D 27
	ruser = rindex(rhost, '.');
	if (ruser != NULL) {
		*ruser++ = '\0';
		if (!okname(ruser))
E 27
I 27
		*cp = '\0';
		strncpy(tuser, rhost, sizeof(tuser)-1);
		*cp = c;
		rhost = cp + 1;
		ruser = tuser;
		if (*ruser == '\0')
			ruser = user;
		else if (!okname(ruser))
E 27
			return(0);
	} else
		ruser = user;
I 13
	if (!qflag)
		printf("updating host %s\n", rhost);
D 17
	cur_host = rhost;
E 17
D 22
	(void) sprintf(buf, "/usr/local/rdist -Server%s", qflag ? " -q" : "");
E 22
I 22
	(void) sprintf(buf, "%s -Server%s", RDIST, qflag ? " -q" : "");
I 27
	if (port < 0) {
		struct servent *sp;
E 27
E 22
E 13

I 27
		if ((sp = getservbyname("shell", "tcp")) == NULL)
			fatal("shell/tcp: unknown service");
		port = sp->s_port;
	}

E 27
	if (debug) {
D 13
		printf("makeconn(%s)\n", rhost);
E 13
D 27
		printf("luser = %s, ruser = %s\n", user, ruser);
E 27
I 27
		printf("port = %d, luser = %s, ruser = %s\n", ntohs(port), user, ruser);
E 27
		printf("buf = %s\n", buf);
	}

I 2
	fflush(stdout);
I 18
D 27
	cur_host = rhost;
E 27
I 22
	setreuid(userid, 0);
E 22
E 18
E 2
D 27
	rem = rcmd(&rhost, IPPORT_CMDSERVER, user, ruser, buf, 0);
E 27
I 27
	rem = rcmd(&rhost, port, user, ruser, buf, 0);
E 27
I 22
	setreuid(0, userid);
E 22
	if (rem < 0)
		return(0);
D 10
	if (response() < 0)
		return(0);
	return(1);
E 10
I 10
	cp = buf;
	if (read(rem, cp, 1) != 1)
		lostconn();
	if (*cp == 'V') {
		do {
			if (read(rem, cp, 1) != 1)
				lostconn();
		} while (*cp++ != '\n' && cp < &buf[BUFSIZ]);
		*--cp = '\0';
		cp = buf;
		n = 0;
		while (*cp >= '0' && *cp <= '9')
			n = (n * 10) + (*cp++ - '0');
D 17
		if (*cp == '\0' && n == VERSION)
E 17
I 17
D 18
		if (*cp == '\0' && n == VERSION) {
			cur_host = rhost;
E 18
I 18
		if (*cp == '\0' && n == VERSION)
E 18
E 17
			return(1);
I 17
D 18
		}
E 18
E 17
D 21
	}
	error("connection failed: version numbers don't match\n");
E 21
I 21
		error("connection failed: version numbers don't match (local %d, remote %d)\n", VERSION, n);
	} else
		error("connection failed: version numbers don't match\n");
E 21
I 18
	closeconn();
E 18
	return(0);
E 10
}

I 13
/*
 * Signal end of previous connection.
 */
closeconn()
{
I 15
	if (debug)
		printf("closeconn()\n");

E 15
	if (rem >= 0) {
		(void) write(rem, "\2\n", 2);
		(void) close(rem);
		rem = -1;
	}
}

lostconn()
{
D 17
	fflush(stdout);
	fprintf(stderr, "rdist: lost connection\n");
E 17
I 17
	if (iamremote)
		cleanup();
	log(lfp, "rdist: lost connection\n");
E 17
	longjmp(env, 1);
}

E 13
I 2
D 3
extern char target[], *tp;

E 3
E 2
D 8
/*
 * Update the file(s) if they are different.
I 2
 * destdir = 1 if destination should be a directory
 * (i.e., more than one source is being copied to the same destination).
E 2
 */
D 2
install(src, dest, verify)
E 2
I 2
D 3
install(src, dest, destdir, verify)
E 3
I 3
D 4
install(src, dest, destdir, options)
E 4
I 4
install(src, dest, destdir, opts)
E 4
E 3
E 2
	char *src, *dest;
D 2
	int verify;
E 2
I 2
D 3
	int destdir, verify;
E 3
I 3
D 4
	int destdir, options;
E 4
I 4
	int destdir, opts;
E 8
I 8
okname(name)
	register char *name;
E 8
E 4
E 3
E 2
{
I 3
D 8
	register char *cp;
E 8
I 8
	register char *cp = name;
	register int c;
E 8

E 3
D 2
	register char *cp;
	extern char *tp;
	char lbuf[BUFSIZ];
E 2
I 2
D 8
	if (exclude(src))
		return;
E 2

D 2
	if (!qflag)
E 2
I 2
D 3
	if (nflag) {
E 2
		printf("%s %s %s\n", verify ? "verify" : "install", src, dest);
D 2
	if (nflag)
E 2
		return;
E 3
I 3
	if (nflag || debug) {
D 4
		printf("%s%s %s %s\n", options & VERIFY ? "verify" : "install",
			options & WHOLE ? " -w" : "", src, dest);
E 4
I 4
D 5
		printf("%s%s%s %s %s\n", opts & VERIFY ? "verify":"install",
E 5
I 5
D 6
		printf("%s%s%s%s %s %s\n", opts & VERIFY ? "verify":"install",
E 6
I 6
		printf("%s%s%s%s%s %s %s\n", opts & VERIFY ? "verify":"install",
E 6
E 5
			opts & WHOLE ? " -w" : "",
D 5
			opts & YOUNGER ? " -y" : "", src, dest);
E 5
I 5
			opts & YOUNGER ? " -y" : "",
I 6
			opts & COMPARE ? " -b" : "",
E 6
			opts & REMOVE ? " -r" : "", src, dest);
E 5
E 4
		if (nflag)
			return;
E 3
I 2
	}
E 2
	/*
	 * Pass the destination file/directory name to remote.
	 */
D 2
	(void) sprintf(buf, "T%s\n", dest);
E 2
I 2
	(void) sprintf(buf, "%c%s\n", destdir ? 'T' : 't', dest);
E 2
	if (debug)
		printf("buf = %s", buf);
	(void) write(rem, buf, strlen(buf));
D 3
	tp = NULL;
D 2
	shexpand(lbuf, src);
	sendf(lbuf, verify);
E 2
I 2
	sendf(src, verify);
E 3
I 3

D 4
	if (!destdir && (options & WHOLE))
		options |= STRIP;
	sendf(src, NULL, options);
E 4
I 4
	if (!destdir && (opts & WHOLE))
		opts |= STRIP;
I 5
	if (opts & REMOVE) {
		opts &= ~REMOVE;
		rmchk(src, NULL, opts);
	}
E 5
	sendf(src, NULL, opts);
E 8
I 8
	do {
		c = *cp;
		if (c & 0200)
			goto bad;
		if (!isalpha(c) && !isdigit(c) && c != '_' && c != '-')
			goto bad;
		cp++;
	} while (*cp);
	return(1);
bad:
	error("invalid user name %s\n", name);
	return(0);
E 8
E 4
E 3
E 2
}

I 2
D 9
struct tstamp {
	time_t	lastmod;
	FILE	*tfp;
} ts[NSTAMPS];
E 9
I 9
time_t	lastmod;
FILE	*tfp;
extern	char target[], *tp;
E 9

D 9
int	nstamps;

I 3
extern char target[], *tp;

E 9
E 3
E 2
/*
I 2
 * Process commands for comparing files to time stamp files.
 */
D 9
dofcmds(files, stamps, cmds)
	struct block *files, *stamps, *cmds;
E 9
I 9
D 13
dofcmds(files, stamp, cmds)
	struct block *files, *stamp, *cmds;
E 13
I 13
D 19
dodcolon(files, stamp, cmds)
E 19
I 19
dodcolon(filev, files, stamp, cmds)
	char **filev;
E 19
	struct namelist *files;
	char *stamp;
	struct subcmd *cmds;
E 13
E 9
{
D 13
	register struct block *b;
E 13
I 13
	register struct subcmd *sc;
	register struct namelist *f;
E 13
D 9
	register struct tstamp *t;
E 9
	register char **cpp;
I 4
	struct timeval tv[2];
	struct timezone tz;
E 4
	struct stat stb;
D 9
	extern char *tmpinc;
E 9
D 3
	int n;
E 3

	if (debug)
D 13
		printf("dofcmds()\n");
E 13
I 13
		printf("dodcolon()\n");
E 13

D 9
	files = expand(files, 0);
I 6
	if (files == NULL){
E 9
I 9
D 13
	files = expand(files, E_ALL);
E 13
	if (files == NULL) {
E 9
		error("no files to be updated\n");
		return;
	}
E 6
D 4
	stamps = expand(stamps, 1);
E 4
I 4
D 9
	stamps = expand(stamps, 0);
E 4
D 6
	if (files == NULL)
		fatal("no files to be updated\n");
	if (stamps == NULL)
		fatal("empty time stamp file list\n");
E 6
I 6
	if (stamps == NULL) {
		error("empty time stamp file list\n");
E 9
I 9
D 13
	stamp = expand(stamp, E_ALL);
	if (stamp == NULL || stamp->b_next != NULL) {
		error("Only one time stamp file allowed\n");
E 9
		return;
	}
E 13
E 6
D 8
	except = cmds;
E 8
I 8
D 20
	if (!mkexceptlist(cmds))
		return;
E 8

E 20
D 9
	t = ts;
	nstamps = 0;
	for (b = stamps; b != NULL; b = b->b_next) {
		if (stat(b->b_name, &stb) < 0) {
			error("%s: %s\n", b->b_name, sys_errlist[errno]);
			continue;
		}
		if (++nstamps > NSTAMPS)
			fatal("too many time stamp files in one command\n");
		if (debug)
			printf("%s: %d\n", b->b_name, stb.st_mtime);
		t->lastmod = stb.st_mtime;
E 9
I 9
D 13
	if (stat(stamp->b_name, &stb) < 0) {
		error("%s: %s\n", stamp->b_name, sys_errlist[errno]);
E 13
I 13
	if (stat(stamp, &stb) < 0) {
		error("%s: %s\n", stamp, sys_errlist[errno]);
E 13
		return;
	}
	if (debug)
D 13
		printf("%s: %d\n", stamp->b_name, stb.st_mtime);
E 13
I 13
		printf("%s: %d\n", stamp, stb.st_mtime);
E 13
D 14
	if (!nflag) {
		lastmod = stb.st_mtime;
E 9
D 4
		if (!nflag && !vflag) {
E 4
I 4
		(void) gettimeofday(&tv[0], &tz);
		tv[1] = tv[0];
D 9
		(void) utimes(b->b_name, tv);
		if (!nflag && !(options & VERIFY)) {
E 4
			if ((t->tfp = fopen(tmpfile, "w")) == NULL)
				error("%s: %s\n", b->b_name, sys_errlist[errno]);
			(*tmpinc)++;
		} else
			t->tfp = NULL;
		t++;
	}
E 9
I 9
D 13
		(void) utimes(stamp->b_name, tv);
E 13
I 13
		(void) utimes(stamp, tv);
E 13
		if (options & VERIFY)
			tfp = NULL;
		else if ((tfp = fopen(tmpfile, "w")) == NULL) {
E 14
I 14

I 20
	subcmds = cmds;
E 20
	lastmod = stb.st_mtime;
	if (nflag || (options & VERIFY))
		tfp = NULL;
	else {
		if ((tfp = fopen(tmpfile, "w")) == NULL) {
E 14
D 13
			error("%s: %s\n", stamp->b_name, sys_errlist[errno]);
E 13
I 13
			error("%s: %s\n", stamp, sys_errlist[errno]);
E 13
			return;
		}
D 14
	} else
		tfp = NULL;
E 14
I 14
		(void) gettimeofday(&tv[0], &tz);
		tv[1] = tv[0];
		(void) utimes(stamp, tv);
	}
E 14
E 9
I 4

E 4
D 13
	for (b = files; b != NULL; b = b->b_next) {
E 13
I 13
	for (f = files; f != NULL; f = f->n_next) {
D 19
#ifdef notdef
E 13
		if (filec) {
E 19
I 19
		if (filev) {
E 19
			for (cpp = filev; *cpp; cpp++)
D 19
				if (!strcmp(b->b_name, *cpp))
E 19
I 19
				if (strcmp(f->n_name, *cpp) == 0)
E 19
					goto found;
			continue;
		}
	found:
I 13
D 19
#endif
E 19
E 13
		tp = NULL;
D 13
		cmptime(b->b_name);
E 13
I 13
		cmptime(f->n_name);
E 13
	}
D 4
	if (!nflag && !vflag)
D 3
		for (t = ts; t < &ts[n]; t++)
E 3
I 3
		for (t = ts; t < &ts[nstamps]; t++)
E 3
			if (t->tfp != NULL)
				(void) fclose(t->tfp);
E 4
I 4

E 4
D 9
	*tmpinc = 'A';
D 3
	while (n--) {
E 3
I 3
D 4
	while (nstamps--) {
E 4
I 4
	for (t = ts; t < &ts[nstamps]; t++) {
		if (t->tfp != NULL)
			(void) fclose(t->tfp);
E 4
E 3
		for (b = cmds; b != NULL; b = b->b_next)
			if (b->b_type == NOTIFY)
D 4
				notify(tmpfile, NULL, b->b_args);
		if (!nflag && !vflag)
E 4
I 4
				notify(tmpfile, NULL, b->b_args, t->lastmod);
		if (!nflag && !(options & VERIFY))
E 4
			(void) unlink(tmpfile);
		(*tmpinc)++;
	}
E 9
I 9
	if (tfp != NULL)
		(void) fclose(tfp);
D 13
	for (b = cmds; b != NULL; b = b->b_next)
		if (b->b_type == NOTIFY)
			notify(tmpfile, NULL, b->b_args, lastmod);
E 13
I 13
	for (sc = cmds; sc != NULL; sc = sc->sc_next)
		if (sc->sc_type == NOTIFY)
			notify(tmpfile, NULL, sc->sc_args, lastmod);
E 13
	if (!nflag && !(options & VERIFY))
		(void) unlink(tmpfile);
E 9
}

/*
 * Compare the mtime of file to the list of time stamps.
 */
cmptime(name)
	char *name;
{
D 9
	register struct tstamp *t;
E 9
	struct stat stb;

	if (debug)
		printf("cmptime(%s)\n", name);

D 9
	if (exclude(name))
E 9
I 9
D 20
	if (inlist(except, name))
E 20
I 20
	if (except(name))
E 20
E 9
		return;

I 9
	if (nflag) {
		printf("comparing dates: %s\n", name);
		return;
	}

E 9
	/*
	 * first time cmptime() is called?
	 */
	if (tp == NULL) {
D 8
		exptilde(target, name);
E 8
I 8
		if (exptilde(target, name) == NULL)
			return;
E 8
		tp = name = target;
		while (*tp)
			tp++;
	}
	if (access(name, 4) < 0 || stat(name, &stb) < 0) {
		error("%s: %s\n", name, sys_errlist[errno]);
		return;
	}

	switch (stb.st_mode & S_IFMT) {
	case S_IFREG:
		break;

	case S_IFDIR:
		rcmptime(&stb);
		return;

	default:
		error("%s: not a plain file\n", name);
		return;
	}

D 9
	for (t = ts; t < &ts[nstamps]; t++) {
D 4
		if (stb.st_mtime <= t->lastmod)
			return;
		log(t->tfp, "updating: %s\n", name);
E 4
I 4
		if (stb.st_mtime > t->lastmod)
			log(t->tfp, "new: %s\n", name);
E 4
	}
E 9
I 9
	if (stb.st_mtime > lastmod)
		log(tfp, "new: %s\n", name);
E 9
}

rcmptime(st)
	struct stat *st;
{
	register DIR *d;
	register struct direct *dp;
	register char *cp;
	char *otp;
	int len;

	if (debug)
		printf("rcmptime(%x)\n", st);

	if ((d = opendir(target)) == NULL) {
		error("%s: %s\n", target, sys_errlist[errno]);
		return;
	}
	otp = tp;
	len = tp - target;
	while (dp = readdir(d)) {
		if (!strcmp(dp->d_name, ".") || !strcmp(dp->d_name, ".."))
			continue;
		if (len + 1 + strlen(dp->d_name) >= BUFSIZ - 1) {
			error("%s/%s: Name too long\n", target, dp->d_name);
			continue;
		}
		tp = otp;
		*tp++ = '/';
		cp = dp->d_name;
		while (*tp++ = *cp++)
			;
		tp--;
		cmptime(target);
	}
	closedir(d);
	tp = otp;
	*tp = '\0';
}

/*
E 2
 * Notify the list of people the changes that were made.
I 4
 * rhost == NULL if we are mailing a list of changes compared to at time
 * stamp file.
E 4
 */
D 2
notify(host, to)
	char *host;
E 2
I 2
D 3
notify(file, host, to)
	char *file, *host;
E 3
I 3
D 4
notify(file, rhost, to)
E 4
I 4
notify(file, rhost, to, lmod)
E 4
	char *file, *rhost;
E 3
E 2
D 13
	register struct block *to;
E 13
I 13
	register struct namelist *to;
E 13
I 4
	time_t lmod;
E 4
{
	register int fd, len;
	FILE *pf, *popen();
	struct stat stb;

D 4
	if (vflag)
E 4
I 4
D 9
	if (options & VERIFY)
E 9
I 9
	if ((options & VERIFY) || to == NULL)
E 9
E 4
		return;
	if (!qflag) {
D 2
		printf("notify @%s ", host);
E 2
I 2
		printf("notify ");
D 3
		if (host)
			printf("@%s ", host);
E 3
I 3
		if (rhost)
			printf("@%s ", rhost);
E 3
E 2
		prnames(to);
	}
	if (nflag)
		return;

D 2
	if ((fd = open(tmpfile, 0)) < 0) {
		error("%s: %s\n", tmpfile, sys_errlist[errno]);
E 2
I 2
	if ((fd = open(file, 0)) < 0) {
		error("%s: %s\n", file, sys_errlist[errno]);
E 2
		return;
	}
I 2
	if (fstat(fd, &stb) < 0) {
		error("%s: %s\n", file, sys_errlist[errno]);
		(void) close(fd);
		return;
	}
	if (stb.st_size == 0) {
		(void) close(fd);
		return;
	}
E 2
	/*
	 * Create a pipe to mailling program.
	 */
	pf = popen(MAILCMD, "w");
D 3
	if (pf == NULL)
		fatal("notify: \"%s\" failed\n", MAILCMD);
E 3
I 3
	if (pf == NULL) {
		error("notify: \"%s\" failed\n", MAILCMD);
		(void) close(fd);
		return;
	}
E 3
	/*
	 * Output the proper header information.
	 */
	fprintf(pf, "From: rdist (Remote distribution program)\n");
	fprintf(pf, "To:");
I 4
D 12
	if (!any('@', to->b_name) && host != NULL)
E 12
I 12
D 13
	if (!any('@', to->b_name) && rhost != NULL)
E 12
		fprintf(pf, " %s@%s", to->b_name, rhost);
E 13
I 13
	if (!any('@', to->n_name) && rhost != NULL)
		fprintf(pf, " %s@%s", to->n_name, rhost);
E 13
	else
D 13
		fprintf(pf, " %s", to->b_name);
	to = to->b_next;
E 13
I 13
		fprintf(pf, " %s", to->n_name);
	to = to->n_next;
E 13
E 4
	while (to != NULL) {
D 2
		fprintf(pf, " %s@%s", to->b_name, host);
E 2
I 2
D 3
		if (!any('@', to->b_name))
			fprintf(pf, " %s@%s", to->b_name, host);
E 3
I 3
D 12
		if (!any('@', to->b_name) && host != NULL)
E 12
I 12
D 13
		if (!any('@', to->b_name) && rhost != NULL)
E 12
D 4
			fprintf(pf, " %s@%s", to->b_name, rhost);
E 4
I 4
			fprintf(pf, ", %s@%s", to->b_name, rhost);
E 13
I 13
		if (!any('@', to->n_name) && rhost != NULL)
			fprintf(pf, ", %s@%s", to->n_name, rhost);
E 13
E 4
E 3
		else
D 4
			fprintf(pf, " %s", to->b_name);
E 4
I 4
D 13
			fprintf(pf, ", %s", to->b_name);
E 4
E 2
		to = to->b_next;
E 13
I 13
			fprintf(pf, ", %s", to->n_name);
		to = to->n_next;
E 13
	}
	putc('\n', pf);
D 3
	fprintf(pf, "Subject: files updated by rdist\n");
E 3
I 3
D 4
	fprintf(pf, "Subject: files updated by rdist from %s to %s\n",
		host, rhost);
E 4
I 4
	if (rhost != NULL)
		fprintf(pf, "Subject: files updated by rdist from %s to %s\n",
			host, rhost);
	else
		fprintf(pf, "Subject: files updated after %s\n", ctime(&lmod));
E 4
E 3
	putc('\n', pf);

	while ((len = read(fd, buf, BUFSIZ)) > 0)
		(void) fwrite(buf, 1, len, pf);
	(void) close(fd);
	(void) pclose(pf);
}

D 13
struct	block *except;		/* list of files to exclude */
E 13
I 13
D 20
struct	namelist *except;		/* list of files to exclude */
E 13

E 20
/*
D 9
 * Return true if name is in list.
E 9
I 9
 * Return true if name is in the list.
E 9
 */
D 9
exclude(file)
E 9
I 9
inlist(list, file)
D 13
	struct block *list;
E 13
I 13
	struct namelist *list;
E 13
E 9
	char *file;
{
D 8
	register struct block *b, *c;
E 8
I 8
D 13
	register struct block *c;
E 13
I 13
	register struct namelist *nl;
E 13
E 8

D 8
	for (c = except; c != NULL; c = c->b_next) {
		if (c->b_type != EXCEPT)
			continue;
		for (b = c->b_args; b != NULL; b = b->b_next)
			if (!strcmp(file, b->b_name))
				return(1);
	}
E 8
I 8
D 9
	for (c = except; c != NULL; c = c->b_next)
E 9
I 9
D 13
	for (c = list; c != NULL; c = c->b_next)
E 9
		if (!strcmp(file, c->b_name))
E 13
I 13
	for (nl = list; nl != NULL; nl = nl->n_next)
		if (!strcmp(file, nl->n_name))
E 13
			return(1);
E 8
	return(0);
}

D 8
okname(name)
	register char *name;
E 8
I 8
/*
D 13
 * Build the exception list from an unexpanded list of commands.
E 13
I 13
D 20
 * Build the exception list from the EXCEPT commands.
E 20
I 20
 * Return TRUE if file is in the exception list.
E 20
E 13
 */
D 20
mkexceptlist(cmds)
D 13
	struct block *cmds;
E 13
I 13
	struct subcmd *cmds;
E 20
I 20
except(file)
	char *file;
E 20
E 13
E 8
{
D 8
	register char *cp = name;
	register int c;
E 8
I 8
D 13
	register struct block *f, *a, *c;
E 13
I 13
D 20
	register struct subcmd *sc;
	register struct namelist *el, *nl;
E 20
I 20
	register struct	subcmd *sc;
	register struct	namelist *nl;
E 20
E 13
D 11
	register char *cp;
E 11
E 8

D 8
	do {
		c = *cp;
		if (c & 0200)
			goto bad;
		if (!isalpha(c) && !isdigit(c) && c != '_' && c != '-')
			goto bad;
		cp++;
	} while (*cp);
E 8
I 8
	if (debug)
D 20
		printf("mkexceptlist()\n");
E 20
I 20
		printf("except(%s)\n", file);
E 20

D 13
	except = f = NULL;
	for (c = cmds; c != NULL; c = c->b_next) {
		if (c->b_type != EXCEPT)
E 13
I 13
D 20
	except = el = NULL;
	for (sc = cmds; sc != NULL; sc = sc->sc_next) {
		if (sc->sc_type != EXCEPT)
E 20
I 20
	for (sc = subcmds; sc != NULL; sc = sc->sc_next) {
		if (sc->sc_type != EXCEPT && sc->sc_type != PATTERN)
E 20
E 13
			continue;
D 13
		for (a = c->b_args; a != NULL; a = a->b_next) {
D 9
			cp = a->b_name;
			if (*cp == '~') {
				if (exptilde(buf, cp) == NULL)
					return(0);
				cp = buf;
			}
E 9
			if (f == NULL)
D 9
				except = f = expand(makeblock(NAME, cp), 0);
E 9
I 9
				except = f = expand(makeblock(NAME, a->b_name), E_ALL);
E 9
			else
D 9
				f->b_next = expand(makeblock(NAME, cp), 0);
E 9
I 9
				f->b_next = expand(makeblock(NAME, a->b_name), E_ALL);
E 9
			while (f->b_next != NULL)
				f = f->b_next;
E 13
I 13
		for (nl = sc->sc_args; nl != NULL; nl = nl->n_next) {
D 20
			if (el == NULL)
				except = el = makenl(nl->n_name);
			else {
				el->n_next = makenl(nl->n_name);
				el = el->n_next;
E 20
I 20
			if (sc->sc_type == EXCEPT) {
				if (!strcmp(file, nl->n_name))
					return(1);
				continue;
E 20
			}
I 20
			re_comp(nl->n_name);
			if (re_exec(file) > 0)
				return(1);
E 20
E 13
		}
	}
D 13
	if (debug)
E 13
I 13
D 20
	if (debug) {
		printf("except = ");
E 13
		prnames(except);
I 13
	}
E 13
E 8
	return(1);
E 20
I 20
	return(0);
E 20
D 8
bad:
	error("invalid user name %s\n", name);
	return(0);
E 8
}

char *
colon(cp)
	register char *cp;
{

	while (*cp) {
		if (*cp == ':')
			return(cp);
		if (*cp == '/')
			return(0);
		cp++;
	}
	return(0);
}
E 1
