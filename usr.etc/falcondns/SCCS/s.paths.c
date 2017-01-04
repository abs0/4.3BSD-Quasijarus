h10365
s 00001/00001/00011
d D 1.5 2013/01/12 08:19:25 msokolov 5 4
c comment fix
e
s 00001/00001/00011
d D 1.4 2013/01/06 07:03:38 msokolov 4 3
c MSDNS => FalconDNS
e
s 00001/00001/00011
d D 1.3 2011/12/14 01:50:51 msokolov 3 2
c let's go with /usr/adm/dns
e
s 00001/00002/00011
d D 1.2 2011/07/13 16:07:23 msokolov 2 1
c binary zone files adopted
e
s 00013/00000/00000
d D 1.1 11/07/11 08:04:06 msokolov 1 0
c MSDNS project started, template compiles
e
u
U
t
T
I 1
/*
D 4
 * Michael Sokolov's Domain Name Server (MSDNS)
E 4
I 4
 * FalconDNS daemon by Michael Spacefalcon
E 4
 *
D 5
 * MSDNS pathnames are defined here
E 5
I 5
 * These pathnames get compiled into the dnsd binary.
E 5
 */

#ifndef lint
static char sccsid[] = "%W% (IFCTF) %E%";
#endif

D 3
char default_msdns_directory[] = "/usr/local/domain";
E 3
I 3
char default_msdns_directory[] = "/usr/adm/dns";
E 3
D 2
char axfr_puller[] = "/usr/etc/zonexfer";
char text_parse_assistant[] = "/usr/lib/msdns-textparse";
E 2
I 2
char axfr_puller[] = "/usr/ucb/zonexfer";
E 2
E 1
