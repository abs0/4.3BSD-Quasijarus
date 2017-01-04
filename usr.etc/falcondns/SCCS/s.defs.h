h11904
s 00001/00001/00024
d D 1.10 2013/01/13 15:38:49 msokolov 10 9
c MAX_CNAME_CHAIN bumped up to 4
e
s 00001/00001/00024
d D 1.9 2013/01/06 07:03:34 msokolov 9 8
c MSDNS => FalconDNS
e
s 00001/00000/00024
d D 1.8 2011/12/11 06:29:33 msokolov 8 7
c prep for NS-anchor refresh logic
e
s 00004/00000/00020
d D 1.7 2011/10/28 04:27:08 msokolov 7 6
c NS-anchor installation fully implemented
e
s 00005/00000/00015
d D 1.6 2011/07/20 06:23:39 msokolov 6 5
c query processing defs added
e
s 00004/00000/00011
d D 1.5 2011/07/18 05:54:11 msokolov 5 4
c basic refresh logic implemented
e
s 00001/00000/00010
d D 1.4 2011/07/16 06:08:16 msokolov 4 3
c msdnsctl written
e
s 00001/00002/00009
d D 1.3 2011/07/14 22:51:49 msokolov 3 2
c daemonization better thought through
e
s 00003/00001/00008
d D 1.2 2011/07/13 19:23:16 msokolov 2 1
c we now read the class def file, although don't do anything with it yet
e
s 00009/00000/00000
d D 1.1 11/07/11 08:04:03 msokolov 1 0
c MSDNS project started, template compiles
e
u
U
t
T
I 1
/*
D 9
 * Michael Sokolov's Domain Name Server (MSDNS)
E 9
I 9
 * FalconDNS daemon by Michael Spacefalcon
E 9
 *
 * Miscellaneous preprocessor definitions
 *
 *	%W% (IFCTF) %E%
 */

D 2
#define	MAX_FILENAME	255
E 2
I 2
D 3
#define	MAX_FILENAME		255
#define	MAX_ASCII_DOMNAME	255
E 3
I 3
#define	MAX_FILENAME		255	/* for binary zone file names */
E 3
#define	FGETS_BUFSIZE		256	/* msdns.conf and class def files */
I 4
#define	CTLSOCK_MAXMSG		255
I 5

/* sanity limits for zone refresh/retry times */
#define	MINIMUM_SOA_REFRESH	300	/* 5 min */
#define	MINIMUM_SOA_RETRY	60	/* 1 min */
I 6

/* query processing */
D 10
#define	MAX_CNAME_CHAIN		2	/* of course CNAMEs aren't supposed */
E 10
I 10
#define	MAX_CNAME_CHAIN		4	/* of course CNAMEs aren't supposed */
E 10
					/* to be chained at all */
#define	COMPRESS_NODES_PER_CHUNK	128
I 7

/* NS-anchor defaults */
#define	NSANCHOR_DEFAULT_TTL_PERCENT		90
#define	NSANCHOR_DEFAULT_RETRY_INTERVAL		3600
I 8
#define	NSANCHOR_DEFAULT_WARN_INTERVAL		86400
E 8
E 7
E 6
E 5
E 4
E 2
E 1
