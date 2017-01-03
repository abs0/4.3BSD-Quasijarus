.\"	@(#)0a.t	6.2 (Berkeley) 12/4/03
.\"
.sp
.SH
.ce
.LG
4.3BSD-Quasijarus0a changes
.SM
.sp
.IP \s+1\(bu\s0
SCCS commands are now part of the standard system.
.IP \s+1\(bu\s0
The MicroVAX bootblock has been added to the standard distribution tape.
Since it must reside at the beginning of the tape,
the original toggle-in bootstraps have been moved two blocks down.
.IP \s+1\(bu\s0
Franz Lisp has been separated from the main system.
.IP \s+1\(bu\s0
Jean-loup Gailly's
.I zlib
compression library (\-lz) has been included in the standard system.
.IP \s+1\(bu\s0
.B \-s
option has been added to
.IR compress \|(1)
to use strong compression instead of the standard
.I compress
algorithm (also known as LZW).
.IP \s+1\(bu\s0
Several new MSCP disks have been added to the distributed /etc/disktab
and to the compiled-in disk tables in the
.IR uda \|(4)
driver.
.IP \s+1\(bu\s0
.IR Kdb \|(4)
driver now uses the same partitions as
.IR uda \|(4)
on the same disks.
.IP \s+1\(bu\s0
The kernel and the standalone system have been taught that VAXBI KLESI
(TU81 controller)
is actually a UNIBUS adapter with a UNIBUS KLESI sitting behind it,
which DEC apparently doesn't want you to know,
instantly gaining full support for this device.
.IP \s+1\(bu\s0
Added
.I Makefile
support for building a distribution console RL02 pack for VAX 8600 and 8650
machines,
so that one can be supplied to sites cold-bootstrapping
.UX
on such a machine.
.IP \s+1\(bu\s0
The protocol used by
.IR dmc \|(4)
and
.IR dmv \|(4)
drivers has been standardized to MTU of 1284 bytes, 8 garbage bytes present.
This is the protocol used 4.3BSD
.IR dmc \|(4)
and Ultrix
.IR dmc \|(4)
and
.IR dmv \|(4),
i.e., by all existing stable releases.
.IP \s+1\(bu\s0
The ``mini root'' file system used in the full bootstrap procedure
has been increased from 2 to 3 megabytes.
.IP \s+1\(bu\s0
The
.IR troff \|(1)
sources for the supplementary documents have been moved from
/usr/doc to /usr/src/doc.
.IP \s+1\(bu\s0
The system headers are now copied rather than symlinked from /sys to
/usr/include by default, so that the system can still be used operationally,
including compiling user programs when the sources are not installed.
