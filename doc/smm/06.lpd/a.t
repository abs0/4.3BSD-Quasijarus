.\"	@(#)a.t	6.1 (Berkeley) 8/24/04
.\"
.SH
Appendix A. PostScript Printer Support
.PP
4.3BSD-Quasijarus includes a set of filters, as well as a few modifications to
.I lpd
itself, to support PostScript printers.
To be more precise, this description, like the code itself, is written
assuming a classic pure PostScript printer interfaced via a serial line,
such as Apple LaserWriter or DEC LN03R,
that has PostScript as its native and sole language.
Note, however, that most modern printer manufacturers, most notably HP,
have demoted PostScript from being the primary and native language to a
secondary option.
.PP
The 4.3BSD-Quasijarus PostScript printer support code is not designed
to support a PS option on an otherwise non-PS printer.
However,
if you want, you can configure your PS-enabled HP printer to default
to the PS personality, ignore the PCL personality and pretend that it's
a pure PostScript printer, and configure it under 4.3BSD-Quasijarus
as the latter.
.SH
Interface Considerations
.PP
PostScript printers are markedly different from most other printer types
in that the PostScript language is strongly oriented toward bidirectional
communication channels.
As a result, PostScript printers have traditionally used RS-232 serial
interfaces, since the other dominant printer interface, Centronics parallel,
is unidirectional in its standard form.
The 4.3BSD-Quasijarus PostScript job filter assumes a bidirectional
serial interface, in that it collects job messages from the printer,
waits until the printer indicates that the job has finished, and uses
the end-of-file convention established for PostScript printers with
serial interfaces.
Interfaces other than RS-232 serial will most likely require modifications
to the
.I lppsjf
job filter.
Whichever interface is chosen, however, it should be bidirectional
to reap full functionality.
While it is possible to use PostScript with a unidirectional interface,
many useful functions which involve obtaining information from the printer
would be unavailable.
.PP
The preferred serial line configuration for PostScript is 8 bits,
no parity, 1 stop bit, and it is the default for most PostScript printers.
Using an 8-bit serial line allows a wider range of PostScript files to be
printed than possible with a 7-bit serial line (Clean8Bit spec as opposed to
Clean7Bit).
.PP
Correct setting of the serial line configuration capabilities in the
.I printcap
entry is critical.
The tty line must be opened for read/write (specify the
.B rw
capability) and set to either raw or CBREAK mode.
Cooked mode doesn't work, most of the cooked mode input processing is
unnecessary for collecting job messages from the PostScript interpreter,
and cooked mode interferes with
.I lppsjf
sending and receiving the ^D end-of-file marker.
The
.B fc
numeric capability must be set to disable echo and CRMOD.
Disabling the echo is most critical, since it would otherwise loop the
PostScript interpreter's output back to its input, with disastrous results.
If CRMOD is not disabled and the PS interpreter sends job messages
terminated with CR-LF, line endings would be erroneously doubled.
(\fIlppsjf\fP knows about all 3 PostScript newline conventions, but
the tty driver doesn't.)
.PP
Either raw or CBREAK mode may be used.
Which one is better is subject to some debate.
CBREAK mode provides useful in-kernel handling of the printer's
XON/XOFF flow control.
In raw mode they are handled by
.I lppsjf
in user mode.
CBREAK mode, however, does some additional input processing that is
unnecessary and may be undesirable, especially when the new tty driver
is active.
The unnecessary output processing also wastes CPU cycles, although
it can be disabled by enabling the LITOUT local mode with the
.B xs
numeric capability.
Raw mode is always 8-bit.
CBREAK mode is normally 7-bit, but can be made 8-bit by enabling
PASS8 and/or LITOUT local modes.
We use raw mode for printers at our facilities.
.PP
Some printers unfortunately have misdesigned serial interfaces with
unusable DTR lines and thus cannot be used in the normal configuration
in which the DTR signal from the printer tells the kernel that the tty
line is ready.
In this case another mechanism is needed to prevent print jobs from
going into the bit bucket when the printer is off-line.
4.3BSD-Quasijarus version of
.I lpd
has a feature to solve this problem for PostScript printers.
If the
.B ct
capability is specified in the
.I printcap
entry,
after the tty line has been successfully opened and set to the proper modes,
.I lpd
does not immediately assume that the printer is ready,
but first does a PostScript printer readiness test with ^T.
It sends ^T to the printer and waits for a
.DS
%%[ status: idle ]%%
.DE
response.
If this response is not received, the printer is assumed to be off-line
and
.I lpd
waits for it to come on-line like it would for normal printers that don't open.
.SH
Filter Implementation
.PP
The 4.3BSD-Quasijarus PostScript printer support package consists of three
filters:
.I lppsif
default input filter,
.I lppsbf
banner filter, and
.I lppsjf
generic job filter.
The
.I lppsif
default input filter supports printing plain text (explained in detail later)
and PostScript.
PostScript input is automatically detected if the file starts with the
``%!'' PostScript signature comment.
PostScript can be forced by invoking
.IR lpr (1)
with \fB\-l\fP.
Note, however, that since a serial line is used, which is a Clean8Bit channel,
printed PostScript files are always limited to the Clean8Bit spec even with
\fB\-l\fP.
In plain text mode
.I lppsif
converts text to PostScript and then invokes
.IR lppsjf .
In PostScript mode it simply invokes
.IR lppsjf .
.PP
.I lppsjf
is the generic PostScript job filter that sends a PostScript file to the
printer in a controlled manner.
It is never invoked directly by
.I lpd
and does not appear in the
.I printcap
entry,
but is instead invoked by various input filters after they have converted
their input to PostScript.
It collects job messages from the printer,
waits until the printer indicates that the job has finished, terminates
the job if it detects that the PostScript interpreter has detected an error
and is flushing, and supports accounting by reading the printer's page
count before and after the job and logging the difference.
.PP
.I lppsbf
generates nice PostScript banner pages and invokes
.I lppsjf
to send them to the printer.
No output filter is used.
Input filters handle all users' print jobs, and
the only output that
.I lpd
sends to the output filter or directly to the printer is banners and
form feeds.
Text banners are not generated since
.I lppsbf
is used instead, and form feeds are suppressed by
specifying the
.B sf
capability in the
.I printcap
entry.
.SH
printcap configuration
.PP
Here is a sample
.I printcap
entry for a PostScript printer:
.DS
.DT
ps|ln03r|DEC LN03R:\e
	:lp=/dev/tty03:sd=/usr/spool/lpd:lf=/usr/adm/lpd-errs:\e
	:rw:br#9600:fc#030:fs#040:sf:px#612:py#792:\e
	:if=/usr/lib/lppsif:ea:pi:bf=/usr/lib/lppsbf:
.DE
The
.B px
and
.B py
numeric capabilities need to be set to the width and height of paper
in PostScript default user coordinate system units (points).
They need to be set correctly, as they are used when converting plain
text to PS and when generating banner pages.
The
.B ea
capability must be specified so that the values of the
.B px
and
.B py
capabilities are passed to
.I lppsif
which needs them, and the
.B pi
capability should be specified to indicate that
.I lppsif
incorporates the functionality of
.IR pr (1)
(see below).
.SH
Printing Plain Text
.PP
The
.I lppsif
input filter converts plain text to PostScript by invoking
.IR txtps (1).
Text is printed in 10 point Courier font
(10 point vertical spacing, 12 characters per inch horizontally)
with 1/2" top and bottom margins,
giving 72 lines per page (8.5" by 11").
The left margin is 3/4" (or 9 characters or 54 PostScript
default user coordinate system units) by default and can be changed with the
.B \-i
option to
.IR lpr (1).
There is no right margin except where the printer itself cuts it off,
but with the default left margin 80-column text appears almost perfectly
centered.
.PP
These defaults are different from the terminal and line printer tradition
of 12 point vertical spacing, 10 characters per inch horizontally,
66 lines per page with no margins, expecting the text itself to provide
margins with blank lines and leading spaces for acceptable appearance,
but they allow one to easily print drafts and random text files and
get usable printouts.
If you don't like these defaults, e.g., if you need to print a text
file that has already been formatted for 66-line marginless printing,
you can invoke
.IR txtps (1)
directly with the desired options, i.e.
.DS
txtps \-p12 \-t0 \-b0 \-l18 textfile | lpr
.DE
.PP
The
.B pi
capability tells
.I lpd
to defer the processing of
.I lpr
.B \-p
option to
.I lppsif
instead of piping the job through
.IR pr (1)
first.
Omitting the
.B pi
capability and allowing the standard
.IR pr (1)
won't produce any useful results since
.IR pr (1)
will assume 66 lines per page, resulting in a mismatch
between \fIpr\fP's pages and actual pages,
and even if one specifies the
.B pl#72
capability (not needed otherwise) to tell
.IR pr (1)
how many lines per page
.IR txtps (1)
allows, this will produce double margins and won't be very useful.
.PP
Since margins are already produced by default anyway,
it is much more useful to specify the
.B pi
capability and let
.I lppsif
completely supplant
.IR pr (1).
If this is done, the only effect of
.I lpr
.B \-p
option will be the \fIpr\fP(1)-like header line with the date, title and page
number, which along with two blank lines will take up the first 3 of the 72
allotted printable lines.
.SH
Accounting
.PP
The
.I lppsjf
generic job filter, which is used by all input filters,
supports accounting.
It does so by reading the printer's page count before and after the job,
which is the only reasonable way to count the number of pages printed by
an arbitrary PostScript program.
The following one line program is sent to the printer to read the page count:
.DS
statusdict begin pagecount = end\en\e4
.DE
There is no standardized way to read the page count in the official PostScript
language, but this method should work on all PostScript printers,
both Level 1 and Level 2.
.PP
It needs to be noted, however, that some printers have been observed
to update the page count asynchronously with the PostScript interpreter,
rather than synchronously by the
.B showpage
and
.B copypage
operators.
The result is that although the PS interpreter is done with the job and
gets queried for the final page count, the latter has not been updated yet
for some of the pages printed by the job, resulting in wrong accounting
information.
This is believed to be a problem with printers that support PostScript
as a secondary option rather than as the primary and native language;
we have observed it on our HP LaserJet 4Si.
There is no known solution or workaround for this problem.
