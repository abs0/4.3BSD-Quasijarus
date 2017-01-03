h45982
s 00001/00001/00012
d D 1.2 88/03/31 22:13:26 phil 2 1
c Added smtpuucp support.
e
s 00013/00000/00000
d D 1.1 87/10/28 21:19:51 phil 1 0
c date and time created 87/10/28 21:19:51 by phil
e
u
U
t
T
I 1
divert(10)dnl
#
# ucbarpa UUCP/TCP configuration file
#
# %W% (Berkeley) %G%
#
define(EXTERNAL_VERSION, ``#'	`%W%' (Berkeley) `%G%'')
define(INTERNET_ALIASES, `Cwucbarpa arpa arpavax ucb-arpa kim ucbkim')
define(UUCP_NAME, DUucbarpa)
define(UUCP_ALIASES, CUucbarpa)
D 2
define(UUCP_HOSTS_FILE, ../m4/uucp.ucbarpa.m4)
E 2
I 2
define(UUCP_HOSTS_FILE, ../machdep/uucp.ucbarpa.m4)
E 2
divert(0)dnl
include(ucbproto.mc)dnl
E 1
