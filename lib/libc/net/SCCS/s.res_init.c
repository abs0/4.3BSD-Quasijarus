h39678
s 00010/00005/00133
d D 6.9 88/06/27 17:14:16 bostic 24 23
c install approved copyright notice
e
s 00009/00003/00129
d D 6.8 88/03/07 21:17:21 bostic 23 22
c added Berkeley specific header
e
s 00003/00005/00129
d D 6.7 87/09/30 10:20:45 bostic 22 21
c get rid of global conffile
e
s 00018/00013/00116
d D 6.6 87/05/12 22:12:16 karels 21 20
c keep list of local domains
e
s 00001/00001/00128
d D 6.5 86/04/11 11:14:46 kjd 20 19
c change RES_TIMEOUT to 4
e
s 00007/00007/00122
d D 6.4 86/03/18 08:57:08 kjd 19 17
c move resolver.h to /usr/include
e
s 00001/00001/00128
d R 6.4 86/03/17 09:06:53 kjd 18 17
c move resolv.h to /usr/include
e
s 00002/00002/00127
d D 6.3 86/03/09 20:35:53 donn 17 16
c added LIBC_SCCS condition for sccs ids
e
s 00001/00006/00128
d D 6.2 85/11/26 18:25:04 kjd 16 15
c Stop announcing what server we are trying
e
s 00000/00000/00134
d D 6.1 85/10/31 15:29:43 kjd 15 14
c Freeze for November 1 network distribution
e
s 00002/00002/00132
d D 5.10 85/10/23 19:16:58 bloom 14 13
c bitwise not logical and kevin
e
s 00083/00057/00051
d D 5.9 85/10/21 17:18:09 kjd 13 12
c Changes to make work on sun and have resolver query multiple servers
e
s 00003/00005/00105
d D 5.8 85/10/08 16:10:16 karels 12 11
c don't fail if can't get domain name from hostname
e
s 00001/00005/00109
d D 5.7 85/09/15 14:16:56 bloom 11 10
c must have port number compiled in
e
s 00059/00015/00055
d D 5.6 85/09/14 11:28:00 bloom 10 9
c change algorithm for initialization, move conf file, return error code
e
s 00002/00002/00068
d D 5.5 85/08/05 14:29:25 kjd 9 8
c Change default settings of resolver state
e
s 00013/00001/00057
d D 5.4 85/07/31 14:26:27 kjd 8 7
c Move definition of CONFFILE from resolv.h to here
e
s 00002/00002/00056
d D 5.3 85/07/29 18:01:10 kjd 7 6
c Move /usr/include/nameser.h to /usrs/include/arpa/nameser.h 
c and move /usr/include/resolv.h /usr/include/arpa/resolv.h
e
s 00001/00001/00057
d D 5.2 85/07/16 11:02:44 kjd 6 5
c Change HTONS to standard htons()
e
s 00007/00006/00051
d D 5.1 85/05/30 12:05:59 dist 5 4
c Add copyright
e
s 00005/00000/00052
d D 4.4 85/04/01 15:11:14 ralph 4 3
c add copyright notice
e
s 00000/00002/00052
d D 4.3 85/03/28 09:26:04 ralph 3 2
c name changes and fix return value in res_init().
e
s 00007/00010/00047
d D 4.2 85/03/27 14:57:07 ralph 2 1
c allow environment LOCALDOMAIN to override default domain.
e
s 00048/00000/00000
d D 4.1 85/03/01 10:42:16 ralph 1 0
c date and time created 85/03/01 10:42:16 by ralph
e
u
U
t
T
I 1
D 5
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif

E 5
I 4
/*
D 5
 * Copyright (c) 1985 Regents of the University of California
 *	All Rights Reserved
E 5
I 5
 * Copyright (c) 1985 Regents of the University of California.
D 23
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 23
I 23
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 24
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 24
I 24
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
E 24
E 23
E 5
 */
I 5

D 17
#ifndef lint
E 17
I 17
#if defined(LIBC_SCCS) && !defined(lint)
E 17
static char sccsid[] = "%W% (Berkeley) %G%";
D 17
#endif not lint
E 17
I 17
D 23
#endif LIBC_SCCS and not lint
E 23
I 23
#endif /* LIBC_SCCS and not lint */
E 23
E 17
E 5

E 4
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
I 10
D 11
#include <netdb.h>
E 11
E 10
D 7
#include <nameser.h>
#include <resolv.h>
E 7
I 7
#include <arpa/nameser.h>
D 19
#include <arpa/resolv.h>
E 19
I 19
#include <resolv.h>
E 19
E 7

/*
I 8
 * Resolver configuration file. Contains the address of the
 * inital name server to query and the default domain for
 * non fully qualified domain names.
 */

D 22
#ifdef CONFFILE
D 13
char	*conffile = CONFFILE;
E 13
I 13
char    *conffile = CONFFILE;
E 13
#else
D 10
char	*conffile = "/usr/local/lib/resolv.conf";
E 10
I 10
D 13
char	*conffile = "/etc/resolv.conf";
E 13
I 13
char    *conffile = "/etc/resolv.conf";
E 22
I 22
#ifndef	CONFFILE
#define	CONFFILE	"/etc/resolv.conf"
E 22
E 13
E 10
#endif

/*
E 8
 * Resolver state default settings
 */
I 13

D 21
#ifndef RES_TIMEOUT
D 20
#define RES_TIMEOUT 10
E 20
I 20
#define RES_TIMEOUT 4
E 20
#endif

E 21
E 13
struct state _res = {
D 9
	90,
	2,
E 9
I 9
D 13
	10,
	4,
E 9
	RES_RECURSE|RES_DEFNAMES,
E 13
I 13
D 21
    RES_TIMEOUT,                 /* retransmition time interval */
    4,                           /* number of times to retransmit */
    RES_RECURSE|RES_DEFNAMES,    /* options flags */
    1,                           /* number of name servers */
E 21
I 21
    RES_TIMEOUT,               	/* retransmition time interval */
    4,                         	/* number of times to retransmit */
    RES_DEFAULT,		/* options flags */
    1,                         	/* number of name servers */
E 21
E 13
};

/*
D 10
 * Read the configuration file for default settings.
 * Return true if the name server address is initialized.
E 10
I 10
 * Set up default settings.  If the configuration file exist, the values
 * there will have precedence.  Otherwise, the server address is set to
 * INADDR_ANY and the default domain name comes from the gethostname().
 *
 * The configuration file should only be used if you want to redefine your
 * domain or run without a server on your machine.
 *
 * Return 0 if completes successfully, -1 on error
E 10
 */
res_init()
{
D 13
	FILE *fp;
	char buf[BUFSIZ], *cp;
D 10
	int n;
E 10
	extern u_long inet_addr();
D 2
	extern char *index();
E 2
I 2
D 10
	extern char *index(), *getenv();
E 10
I 10
	extern char *index();
	extern char *strcpy(), *strncpy();
E 13
I 13
    register FILE *fp;
D 21
    char buf[BUFSIZ], *cp;
E 21
I 21
    register char *cp, **pp;
    char buf[BUFSIZ];
E 21
    extern u_long inet_addr();
    extern char *index();
    extern char *strcpy(), *strncpy();
E 13
D 11
	struct servent *serv;
E 11
D 21
#ifdef DEBUG
E 21
D 13
	extern char *getenv();
#endif
E 13
I 13
    extern char *getenv();
D 21
#endif DEBUG
E 21
    int n = 0;    /* number of nameserver records read from file */
E 13
E 10
E 2

D 10
	_res.options |= RES_INIT;
E 10
D 13
	_res.nsaddr.sin_family = AF_INET;
	_res.nsaddr.sin_addr.s_addr = INADDR_ANY;
D 2
	_res.nsaddr.sin_port = HTONS(53);	/* well known port number */
E 2
I 2
D 6
	_res.nsaddr.sin_port = HTONS(NAMESERVER_PORT);
E 6
I 6
D 10
	_res.nsaddr.sin_port = htons(NAMESERVER_PORT);
E 10
I 10
	_res.defdname[0] = '\0';
D 11
	if ((serv = getservbyname(NAMESERVER_SNAME, "tcp")) == NULL)
		return(-1);
	_res.nsaddr.sin_port = (u_short)serv->s_port;
E 11
I 11
	_res.nsaddr.sin_port = htons(NAMESERVER_PORT);
E 13
I 13
    _res.nsaddr.sin_addr.s_addr = INADDR_ANY;
    _res.nsaddr.sin_family = AF_INET;
    _res.nsaddr.sin_port = htons(NAMESERVER_PORT);
    _res.nscount = 1;
    _res.defdname[0] = '\0';
E 13
E 11
E 10
E 6
E 2

D 10
	/* first try reading the config file */
E 10
D 8
	if ((fp = fopen(CONFFILE, "r")) != NULL) {
E 8
I 8
D 13
	if ((fp = fopen(conffile, "r")) != NULL) {
E 8
D 2
		if (fgets(_res.defdname, MAXDNAME, fp) == NULL)
E 2
I 2
D 10
		if (fgets(_res.defdname, sizeof(_res.defdname), fp) == NULL)
E 2
			_res.defdname[0] = '\0';
		else if ((cp = index(_res.defdname, '\n')) != NULL)
			*cp = '\0';
D 2
		if (fgets(buf, sizeof (buf), fp) != NULL) {
			(void) fclose(fp);
E 2
I 2
		if (fgets(buf, sizeof (buf), fp) != NULL)
E 2
			_res.nsaddr.sin_addr.s_addr = inet_addr(buf);
E 10
I 10
		while (fgets(buf, sizeof(buf), fp) != NULL) {
			if (!strncmp(buf, "domain", sizeof("domain") - 1)) {
				cp = buf + sizeof("domain") - 1;
				while (*cp == ' ' || *cp == '\t')
					cp++;
				if (*cp == '\0')
					continue;
				(void)strncpy(_res.defdname, cp,
				        sizeof(_res.defdname));
				_res.defdname[sizeof(_res.defdname) - 1] = '\0';
				if ((cp = index(_res.defdname, '\n')) != NULL)
					*cp = '\0';
				continue;
			}
			if (!strncmp(buf, "resolver", sizeof("resolver") - 1)) {
				cp = buf + sizeof("resolver") - 1;
				while (*cp == ' ' || *cp == '\t')
					cp++;
				if (*cp == '\0')
					continue;
				_res.nsaddr.sin_addr.s_addr = inet_addr(cp);
				if (_res.nsaddr.sin_addr.s_addr == (unsigned)-1)
					_res.nsaddr.sin_addr.s_addr =
						INADDR_ANY;
				continue;
			}
		}
E 10
D 2
			return (1);
		}
E 2
		(void) fclose(fp);
	}
I 10
	if (_res.defdname[0] == 0) {
D 12
		if (gethostname(buf, sizeof(_res.defdname)) == -1)
			return(-1);
		if ((cp = index(buf, '.')) == NULL)
			return(-1);
		(void)strcpy(_res.defdname, cp + 1);
E 12
I 12
		if (gethostname(buf, sizeof(_res.defdname)) == 0 &&
		    (cp = index(buf, '.')))
			(void)strcpy(_res.defdname, cp + 1);
E 12
	}
E 13
I 13
D 22
    if ((fp = fopen(conffile, "r")) != NULL) {
E 22
I 22
    if ((fp = fopen(CONFFILE, "r")) != NULL) {
E 22
        /* read the config file */
        while (fgets(buf, sizeof(buf), fp) != NULL) {
            /* read default domain name */
            if (!strncmp(buf, "domain", sizeof("domain") - 1)) {
                cp = buf + sizeof("domain") - 1;
                while (*cp == ' ' || *cp == '\t')
                    cp++;
                if (*cp == '\0')
                    continue;
                (void)strncpy(_res.defdname, cp, sizeof(_res.defdname));
                _res.defdname[sizeof(_res.defdname) - 1] = '\0';
                if ((cp = index(_res.defdname, '\n')) != NULL)
                    *cp = '\0';
                continue;
            }
            /* read nameservers to query */
            if (!strncmp(buf, "nameserver", 
               sizeof("nameserver") - 1) && (n < MAXNS)) {
                cp = buf + sizeof("nameserver") - 1;
                while (*cp == ' ' || *cp == '\t')
                    cp++;
                if (*cp == '\0')
                    continue;
                _res.nsaddr_list[n].sin_addr.s_addr = inet_addr(cp);
                if (_res.nsaddr_list[n].sin_addr.s_addr == (unsigned)-1) 
                    _res.nsaddr_list[n].sin_addr.s_addr = INADDR_ANY;
D 19
                    _res.nsaddr_list[n].sin_family = AF_INET;
                    _res.nsaddr_list[n].sin_port = htons(NAMESERVER_PORT);
D 16
#ifdef DEBUG
D 14
                if ( _res.options && RES_DEBUG )
E 14
I 14
                if ( _res.options & RES_DEBUG )
E 14
                    printf("Server #%d address = %s\n", n+1,
                         inet_ntoa(_res.nsaddr_list[n].sin_addr.s_addr));
#endif DEBUG
E 16
                    if ( ++n >= MAXNS) { 
                       n = MAXNS;
E 19
I 19
                _res.nsaddr_list[n].sin_family = AF_INET;
                _res.nsaddr_list[n].sin_port = htons(NAMESERVER_PORT);
                if ( ++n >= MAXNS) { 
                    n = MAXNS;
E 19
#ifdef DEBUG
D 14
                       if ( _res.options && RES_DEBUG )
E 14
I 14
D 19
                       if ( _res.options & RES_DEBUG )
E 14
D 16
                          printf("MAXNS reached\n");
E 16
I 16
                          printf("MAXNS reached, reading resolv.conf\n");
E 19
I 19
                    if ( _res.options & RES_DEBUG )
                        printf("MAXNS reached, reading resolv.conf\n");
E 19
E 16
#endif DEBUG
                }
                continue;
            }
        }
        if ( n > 1 ) 
            _res.nscount = n;
        (void) fclose(fp);
    }
    if (_res.defdname[0] == 0) {
        if (gethostname(buf, sizeof(_res.defdname)) == 0 &&
           (cp = index(buf, '.')))
             (void)strcpy(_res.defdname, cp + 1);
    }
E 13
E 10

I 10
D 21
#ifdef DEBUG
E 21
E 10
D 2
	/* next, try getting the address of this host */

	/* finally, try broadcast */
E 2
I 2
D 13
	/* Allow user to override the local domain definition */
	if ((cp = getenv("LOCALDOMAIN")) != NULL)
D 10
		strncpy(_res.defdname, cp, sizeof(_res.defdname));
E 10
I 10
		(void)strncpy(_res.defdname, cp, sizeof(_res.defdname));
#endif
	_res.options |= RES_INIT;
	return(0);
E 13
I 13
    /* Allow user to override the local domain definition */
    if ((cp = getenv("LOCALDOMAIN")) != NULL)
        (void)strncpy(_res.defdname, cp, sizeof(_res.defdname));
D 21
#endif DEBUG
E 21
I 21

    /* find components of local domain that might be searched */
    pp = _res.dnsrch;
    *pp++ = _res.defdname;
    for (cp = _res.defdname, n = 0; *cp; cp++)
	if (*cp == '.')
	    n++;
    cp = _res.defdname;
    for (; n >= LOCALDOMAINPARTS && pp < _res.dnsrch + MAXDNSRCH; n--) {
	cp = index(cp, '.');
	*pp++ = ++cp;
    }
E 21
    _res.options |= RES_INIT;
    return(0);
E 13
E 10
E 2
D 3

	return (0);
E 3
}
E 1
