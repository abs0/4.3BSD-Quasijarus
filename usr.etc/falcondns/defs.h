/*
 * FalconDNS daemon by Michael Spacefalcon
 *
 * Miscellaneous preprocessor definitions
 *
 *	@(#)defs.h	1.10 (IFCTF) 2013/01/13
 */

#define	MAX_FILENAME		255	/* for binary zone file names */
#define	FGETS_BUFSIZE		256	/* msdns.conf and class def files */
#define	CTLSOCK_MAXMSG		255

/* sanity limits for zone refresh/retry times */
#define	MINIMUM_SOA_REFRESH	300	/* 5 min */
#define	MINIMUM_SOA_RETRY	60	/* 1 min */

/* query processing */
#define	MAX_CNAME_CHAIN		4	/* of course CNAMEs aren't supposed */
					/* to be chained at all */
#define	COMPRESS_NODES_PER_CHUNK	128

/* NS-anchor defaults */
#define	NSANCHOR_DEFAULT_TTL_PERCENT		90
#define	NSANCHOR_DEFAULT_RETRY_INTERVAL		3600
#define	NSANCHOR_DEFAULT_WARN_INTERVAL		86400
