h60964
s 00035/00000/00179
d D 6.5 04/08/24 20:23:24 msokolov 6 5
c document Quasijarus PostScript support
e
s 00007/00004/00172
d D 6.4 86/04/28 19:08:34 bloom 5 4
c more comments about syslog, phrasing cleanup
e
s 00012/00012/00164
d D 6.3 86/04/17 19:53:54 bloom 4 3
c clean up diction
e
s 00010/00008/00166
d D 6.2 86/04/17 17:56:46 bloom 3 2
c spelling cleanup, describe err logging as using syslogd
e
s 00031/00002/00143
d D 6.1 86/04/17 16:45:25 mckusick 2 1
c 4.3BSD beta release document
e
s 00145/00000/00000
d D 5.1 86/04/17 16:45:13 mckusick 1 0
c document distributed with 4.2BSD
e
u
U
t
T
I 1
.\" Copyright (c) 1983 Regents of the University of California.
.\" All rights reserved.  The Berkeley software License Agreement
.\" specifies the terms and conditions for redistribution.
.\"
.\"	%W% (Berkeley) %G%
.\"
.NH 1
Setting up
.PP
D 3
The 4.2BSD release comes with the necessary programs 
E 3
I 3
The 4.3BSD release comes with the necessary programs 
E 3
installed and with the default line printer queue
created.  If the system must be modified, the
makefile in the directory /usr/src/usr.lib/lpr
should be used in recompiling and reinstalling
the necessary programs.
.PP
The real work in setting up is to create the
.I printcap
file and any printer filters for printers not supported
in the distribution system.
.NH 2
Creating a printcap file
.PP
The 
.I printcap
database contains one or more entries per printer.
A printer should have a separate spooling directory;
otherwise, jobs will be printed on
different printers depending on which printer daemon starts first.
D 4
This section describes how to create entries for printers which do not
E 4
I 4
This section describes how to create entries for printers that do not
E 4
conform to the default printer description (an LP-11 style interface to a
standard, band printer).
.NH 3
Printers on serial lines
.PP
When a printer is connected via a serial communication line
it must have the proper baud rate and terminal modes set.
The following example is for a DecWriter III printer connected
locally via a 1200 baud serial line.
.DS
.DT
lp|LA-180 DecWriter III:\e
	:lp=/dev/lp:br#1200:fs#06320:\e
	:tr=\ef:of=/usr/lib/lpf:lf=/usr/adm/lpd-errs:
.DE
The
.B lp
D 4
entry specifies the file name to open for output. In this case it could
E 4
I 4
entry specifies the file name to open for output. Here it could
E 4
be left out since ``/dev/lp'' is the default.
The
.B br
entry sets the baud rate for the tty line and the
.B fs
entry sets CRMOD, no parity, and XTABS (see \fItty\fP\|(4)).
The
.B tr
D 4
entry indicates a form-feed should be printed when the queue
E 4
I 4
entry indicates that a form-feed should be printed when the queue
E 4
empties so the paper can be torn off without turning the printer off-line and
pressing form feed.
The
.B of
entry specifies the filter program
.I lpf
should be used for printing the files;
more will be said about filters later.
The last entry causes errors
to be written to the file ``/usr/adm/lpd-errs''
D 3
instead of the console.
E 3
I 3
instead of the console.  Most errors from \fIlpd\fP are logged using
\fIsyslogd\fP\|(8) and will not be logged in the specified file.  The
D 5
filters may use either method of reporting errors.
E 5
I 5
filters should use \fIsyslogd\fP to report errors; only those that
write to standard error output will end up with errors in the \fBlf\fP file.
(Occasionally errors sent to standard error output have not appeared
in the log file; the use of \fIsyslogd\fP is highly recommended.)
E 5
E 3
.NH 3
Remote printers
.PP
D 4
Printers which reside on remote hosts should have an empty
E 4
I 4
Printers that reside on remote hosts should have an empty
E 4
.B lp
entry.
For example, the following printcap entry would send output to the printer
named ``lp'' on the machine ``ucbvax''.
.DS
.DT
lp|default line printer:\e
	:lp=:rm=ucbvax:rp=lp:sd=/usr/spool/vaxlpd:
.DE
The
.B rm
entry is the name of the remote machine to connect to; this name must
D 5
appear in the /etc/hosts database, see \fIhosts\fP\|(5).
E 5
I 5
be a known host name for a machine on the network.
E 5
The
.B rp
capability indicates
the name of the printer on the remote machine is ``lp'';
D 4
in this case it could be left out since this is the default value.
E 4
I 4
here it could be left out since this is the default value.
E 4
The
.B sd
entry specifies ``/usr/spool/vaxlpd''
as the spooling directory instead of the
default value of ``/usr/spool/lpd''.
.NH 2
Output filters
.PP
Filters are used to handle device dependencies and to
D 4
perform accounting functions.  The output filter
E 4
I 4
do accounting functions.  The output filtering of
E 4
.B of
D 4
is used to filter text data to the printer device when accounting is
E 4
I 4
D 5
is for when accounting is
E 4
not used or when all text data must be passed through a filter.
E 5
I 5
is used when accounting is
not being done or when all text data must be passed through a filter.
E 5
D 4
It is not intended to perform accounting since it is started only once,
E 4
I 4
It is not intended to do accounting since it is started only once,
E 4
all text files are filtered through it, and no provision is made for passing
D 3
owners' login name, identifying the begining and ending of jobs, etc.
E 3
I 3
owners' login name, identifying the beginning and ending of jobs, etc.
E 3
The other filters (if specified) are started for each file
D 4
printed and perform accounting if there is an
E 4
I 4
printed and do accounting if there is an
E 4
.B af
entry.
If entries for both
.B of
D 4
and one of the other filters are specified,
E 4
I 4
and other filters are specified,
E 4
the output filter is used only to print the banner page;
it is then stopped to allow other filters access to the printer.
D 4
An example of a printer which requires output filters
E 4
I 4
An example of a printer that requires output filters
E 4
is the Benson-Varian.
.DS
.DT
va|varian|Benson-Varian:\e
	:lp=/dev/va0:sd=/usr/spool/vad:of=/usr/lib/vpf:\e
D 2
	:tf=/usr/lib/rvcat:mx#2000:pl#58:tr=\ef:
E 2
I 2
	:tf=/usr/lib/rvcat:mx#2000:pl#58:px=2112:py=1700:tr=\ef:
E 2
.DE
The
.B tf
entry specifies ``/usr/lib/rvcat'' as the filter to be
used in printing \fItroff\fP\|(1) output.
This filter is needed to set the device into print mode
for text, and plot mode for printing
.I troff
files and raster images (see \fIva\fP\|(4V)).
Note that the page length is set to 58 lines by the
.B pl
entry for 8.5" by 11" fan-fold paper.
To enable accounting, the varian entry would be
augmented with an
.B af
filter as shown below.
.DS
.DT
va|varian|Benson-Varian:\e
	:lp=/dev/va0:sd=/usr/spool/vad:of=/usr/lib/vpf:\e
	:if=/usr/lib/vpf:tf=/usr/lib/rvcat:af=/usr/adm/vaacct:\e
D 2
	:mx#2000:pl#58:tr=\ef:
E 2
I 2
	:mx#2000:pl#58:px=2112:py=1700:tr=\ef:
.DE
I 6
See Appendix A for how to configure the filters for PostScript printers.
.NH 2
Banner pages
.PP
By default
.I lpd
generates banner pages between print jobs to help users find
their printouts in the stack.
Banner pages are normally generated directly by
.I lpd
in plain text, either filling the whole page (default) or
consisting of a single line (if the
.B sb
capability is specified).
It is also possible to direct
.I lpd
to invoke an external program to generate banner pages instead of
doing it directly.
See the description of the
.B bf
capability in
.IR printcap (5).
This mechanism is used for PostScript printers.
.PP
The banner page is normally printed before the job itself.
However, if the
.B hl
capability is specified, the banner page is printed last.
Banner pages may be completely disabled by specifying the
.B sh
capability.
A user may also individually suppress the banner page for a print job
by invoking
.I lpr
with \fB\-h\fP.
E 6
.NH 2
Access Control
.PP
D 3
Local access to printer queues is controled with the
E 3
I 3
Local access to printer queues is controlled with the
E 3
.B rg
printcap entry.
.DS
	:rg=lprgroup:
.DE
Users must be in the group
.I lprgroup
D 3
in order to sumbit jobs to the specified printer.
E 3
I 3
D 4
in order to submit jobs to the specified printer.
E 4
I 4
to submit jobs to the specified printer.
E 4
E 3
The default is to allow all users access.
Note that once the files are in the local queue, they can be printed
locally or forwarded to another host depending on the configuration.
.PP
D 3
Remote access is controled by listing the hosts in either the file
E 3
I 3
Remote access is controlled by listing the hosts in either the file
E 3
/etc/hosts.equiv or /etc/hosts.lpd, one host per line. Note that
.IR rsh (1)
and
.IR rlogin (1)
D 3
use /etc/hosts to determine which hosts are equivalent for allowing logins
E 3
I 3
use /etc/hosts.equiv to determine which hosts are equivalent for allowing logins
E 3
without passwords. The file /etc/hosts.lpd is only used to control
which hosts have line printer access.
Remote access can be further restricted to only allow remote users with accounts
D 3
on the local host to print jobs.
E 3
I 3
on the local host to print jobs by using the \fBrs\fP printcap entry.
E 3
.DS
	:rs:
E 2
.DE
E 1
