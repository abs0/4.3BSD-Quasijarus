h49767
s 00002/00001/00012
d D 1.8 88/03/31 22:13:18 phil 8 7
c Added smtpuucp support.
e
s 00002/00002/00011
d D 1.7 87/07/15 10:49:45 phil 7 6
c Convert to use ucbproto.mc.
e
s 00001/00001/00012
d D 1.6 87/07/05 21:13:27 phil 6 5
c Quotes to keep m4 happy.
e
s 00001/00001/00012
d D 1.5 87/07/05 20:58:58 phil 5 4
c Added some extra single quotes to keep m4 happy.
e
s 00001/00001/00012
d D 1.4 87/07/05 20:56:44 phil 4 3
c Changed MACHINE_VERSION to EXTERNAL_VERSION
e
s 00003/00003/00010
d D 1.3 87/04/25 23:02:51 phil 3 2
c Misc cleanup.
e
s 00004/00003/00009
d D 1.2 87/03/09 00:34:14 phil 2 1
c Fixed problems with M4 so that UUCP host name gets defined.
e
s 00012/00000/00000
d D 1.1 87/02/16 00:46:10 phil 1 0
c date and time created 87/02/16 00:46:10 by phil
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
# cad UUCP/TCP configuration file
#
# %W% (Berkeley) %G%
#
I 4
D 5
define(EXTERNAL_VERSION, `#	%W% (Berkeley) %G%')
E 5
I 5
D 6
define(EXTERNAL_VERSION, ``#'	%W% (Berkeley) %G%')
E 6
I 6
define(EXTERNAL_VERSION, ``#'	`%W%' (Berkeley) `%G%'')
E 6
E 5
E 4
D 2
define(INTERNET_ALIASES, cad ucbcad)
define(UUCP_NAME, ucbcad)
define(UUCP_ALIASES, ucbcad)
E 2
I 2
define(INTERNET_ALIASES, Cwcad ucbcad)
define(UUCP_NAME, DUucbcad)
define(UUCP_ALIASES, CUucbcad)
E 2
D 7
define(UUCP_HOSTS_FILE, uucp.cad.m4)
E 7
I 7
D 8
define(UUCP_HOSTS_FILE, ../m4/uucp.cad.m4)
E 8
I 8
define(UUCP_HOSTS_FILE, ../machdep/uucp.cad.m4)
define(SMTPUUCP, ../machdep/smtpuucp.cad.m4)
E 8
E 7
I 2
D 4
define(MACHINE_VERSION, `#	%W% (Berkeley) %G%')
E 4
E 2
D 3
divert(0)
include(ucbuucp.mc)
E 3
I 3
divert(0)dnl
D 7
include(ucbuucp.mc)dnl
E 7
I 7
include(ucbproto.mc)dnl
E 7
E 3
E 1
