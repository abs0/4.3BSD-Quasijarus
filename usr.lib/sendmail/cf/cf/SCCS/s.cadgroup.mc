h07874
s 00001/00001/00011
d D 1.5 88/04/08 11:27:07 phil 5 4
c FQ cad.
e
s 00002/00002/00010
d D 1.4 87/07/15 10:49:47 phil 4 3
c Convert to use ucbproto.mc.
e
s 00001/00001/00011
d D 1.3 87/07/05 21:11:51 phil 3 2
c More m4 crap.
e
s 00001/00001/00011
d D 1.2 87/07/05 21:10:21 phil 2 1
c More quotes to keep m4 from bitching.
e
s 00012/00000/00000
d D 1.1 87/07/05 20:57:02 phil 1 0
c date and time created 87/07/05 20:57:02 by phil
e
u
U
t
T
I 1
divert(10)dnl
#
# cad group TCP configuration file
#
# %W% (Berkeley) %G%
#
define(INTERNET_ALIASES, `Fw/usr/lib/sendmail.cw')
define(INTERNET_RELAY, `DAcad.Berkeley.EDU')
D 5
define(UUCP_RELAY, `DRcad')
E 5
I 5
define(UUCP_RELAY, `DRcad.Berkeley.EDU')
E 5
D 2
define(EXTERNAL_VERSION, ``#'	%W% (Berkeley) %G% made from')
E 2
I 2
D 3
define(EXTERNAL_VERSION, ``#'	%W% `('Berkeley`)' %G% made from')
E 3
I 3
D 4
define(EXTERNAL_VERSION, ``#'	`%W%' (Berkeley) `%G%' made from')
E 4
I 4
define(EXTERNAL_VERSION, ``#'	`%W%' (Berkeley) `%G%'')
E 4
E 3
E 2
divert(0)dnl
D 4
include(ucbtcp.mc)dnl
E 4
I 4
include(ucbproto.mc)dnl
E 4
E 1
