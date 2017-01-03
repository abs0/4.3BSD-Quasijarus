.\"	@(#)0b.t	6.2 (Berkeley) 12/4/03
.\"
.sp
.SH
.ce
.LG
4.3BSD-Quasijarus0b changes
.SM
.sp
.IP \s+1\(bu\s0
Y2K fixes throughout the system.
.IP \s+1\(bu\s0
Fix for a critical bug in
.IR c2 ,
the peephole optimiser, which
caused it under certain circumstances to throw out instructions loading
registers which were later used in deferred or indexed addressing modes.  The
resulting misoptimised code thus dereferenced bogus addresses, dumping core or
even worse, behaving unpredictably.
Many other minor bugs have also been fixed in
.IR c2 .
Since all system binaries are compiled with
.B \-O
this potentially affects every binary in the system.
.IP \s+1\(bu\s0
.IR As \|(1)
now automatically chooses between byte branches, word branches, and long jumps,
and ignores the
.B \-J
option.
It now also provides relaxed forms of SOB, AOB, and ACB instructions,
which are now used by
.IR c2 .
.IP \s+1\(bu\s0
.IR Cc \|(1)
.B \-J
option causes
.I switch
tables to be generated in long form like on Sun3.
.IP \s+1\(bu\s0
A number of tables have been enlarged in the C compiler and preprocessor.
.IP \s+1\(bu\s0
When emulating CRC, MATCHC, and MOVTUC instructions on uVAXen the registers and
condition codes were being set incorrectly in some corner cases.
This has been fixed.
.IP \s+1\(bu\s0
A security hole in kernel affecting VAX CPUs without PDP-11 compatibility mode
support (uVAXen and VAX 8200) has been plugged.
The hole allowed any ordinary unprivileged user who is able to run programs
on the machine to cause a kernel panic by giving PSL<CM>=1 to the
.IR sigreturn \|(2)
system call.
.IP \s+1\(bu\s0
A kernel panic-causing bug in TCP has been fixed.
The kernel could panic if a
.IR setsockopt \|(2)
was attempted on a TCP socket that had its connection reset.
Fix from 4.4BSD.
.IP \s+1\(bu\s0
Support for DEC DSV11 point-to-point links using Cisco HDLC protocol.
.IP \s+1\(bu\s0
.I Sendmail
cf files: the prophecy has come true.
HOSTS.TXT is gone, everyone uses DNS, and there are
no more NIC-registered hosts to worry about.
.IP \s+1\(bu\s0
Several new MSCP disks have been added to the distributed /etc/disktab
and to the compiled-in disk tables in the
.IR uda \|(4)
and
.IR kdb \|(4)
drivers.
.IP \s+1\(bu\s0
The MicroVAX boot code no longer requires the boot disk to be unit 0.
It must still be on the first MSCP controller, though.
.IP \s+1\(bu\s0
An RX50 console floppy is now available for the standard system to bootstrap
on a VAX 8200.
