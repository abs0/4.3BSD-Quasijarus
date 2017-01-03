h43480
s 00001/00001/00012
d D 1.2 88/03/31 22:13:24 phil 2 1
c Added smtpuucp support.
e
s 00013/00000/00000
d D 1.1 87/11/04 17:36:28 phil 1 0
c date and time created 87/11/04 17:36:28 by phil
e
u
U
t
T
I 1
divert(10)dnl
#
# okeeffe UUCP/TCP configuration file
#
# %W% (Berkeley) %G%
#
define(INTERNET_ALIASES, Cwokeeffe ucbokeeffe)
define(UUCP_NAME, DUokeeffe)
define(UUCP_ALIASES, CUokeeffe)
D 2
define(UUCP_HOSTS_FILE, ../m4/uucp.okeeffe.m4)
E 2
I 2
define(UUCP_HOSTS_FILE, ../machdep/uucp.okeeffe.m4)
E 2
define(EXTERNAL_VERSION, ``#'	`%W%' (Berkeley) `%G%'')
divert(0)dnl
include(ucbproto.mc)
E 1
