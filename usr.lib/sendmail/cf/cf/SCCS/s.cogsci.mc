h19114
s 00001/00001/00012
d D 1.5 88/03/31 22:13:21 phil 5 4
c Added smtpuucp support.
e
s 00003/00003/00010
d D 1.4 87/07/15 11:10:21 phil 4 3
c m4 includes now in ../m4
e
s 00003/00003/00010
d D 1.3 87/04/25 23:00:44 phil 3 2
c Misc cleanup.
e
s 00004/00003/00009
d D 1.2 87/03/09 00:53:49 phil 2 1
c Fixed bocthed uucp hostname definition.
e
s 00012/00000/00000
d D 1.1 87/02/16 00:55:55 phil 1 0
c date and time created 87/02/16 00:55:55 by phil
e
u
U
t
T
I 1
D 3
divert(10)
E 3
I 3
divert(10)dnl
E 3
#
D 3
# cad UUCP/TCP configuration file
E 3
I 3
# cogsci UUCP/TCP configuration file
E 3
#
# %W% (Berkeley) %G%
#
D 2
define(INTERNET_ALIASES, cogsci ucbcogsci)
define(UUCP_NAME, cogsci)
define(UUCP_ALIASES, cogsci)
E 2
I 2
define(INTERNET_ALIASES, Cwcogsci ucbcogsci)
define(UUCP_NAME, DUcogsci)
define(UUCP_ALIASES, CUcogsci)
E 2
D 4
define(UUCP_HOSTS_FILE, uucp.cogsci.m4)
I 2
define(MACHINE_VERSION, `#	%W% (Berkeley) %G%')
E 4
I 4
D 5
define(UUCP_HOSTS_FILE, ../m4/uucp.cogsci.m4)
E 5
I 5
define(UUCP_HOSTS_FILE, ../machdep/uucp.cogsci.m4)
E 5
define(EXTERNAL_VERSION, ``#'	`%W%' (Berkeley) `%G%'')
E 4
E 2
D 3
divert(0)
E 3
I 3
divert(0)dnl
E 3
D 4
include(ucbuucp.mc)
E 4
I 4
include(ucbproto.mc)
E 4
E 1
