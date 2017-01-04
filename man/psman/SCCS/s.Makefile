h61180
s 00006/00003/00308
d D 5.3 04/10/26 17:55:54 msokolov 3 2
c add fed(1), vfontinfo(1), vtroff(1), vwidth(1)
e
s 00009/00001/00302
d D 5.2 04/10/22 06:48:08 msokolov 2 1
c generate book covers
e
s 00303/00000/00000
d D 5.1 04/10/21 08:21:13 msokolov 1 0
c date and time created 04/10/21 08:21:13 by msokolov
e
u
U
t
T
I 1
# Building the manual books (URM and PRM) for printing
#
#	%W% (Berkeley) %E%

MAN1=	../man1/intro.1.ps ../man1/adb.1.ps ../man1/addbib.1.ps \
	../man1/admin.1.ps ../man1/apply.1.ps ../man1/apropos.1.ps \
	../man1/ar.1.ps ../man1/as.1.ps ../man1/at.1.ps ../man1/atq.1.ps \
	../man1/atrm.1.ps ../man1/awk.1.ps ../man1/basename.1.ps \
	../man1/bc.1.ps ../man1/bdiff.1.ps ../man1/biff.1.ps \
	../man1/binmail.1.ps ../man1/cal.1.ps ../man1/calendar.1.ps \
	../man1/cat.1.ps ../man1/cb.1.ps ../man1/cc.1.ps ../man1/cd.1.ps \
	../man1/checknr.1.ps ../man1/chghist.1.ps ../man1/chgrp.1.ps \
	../man1/chmod.1.ps ../man1/clear.1.ps ../man1/cmp.1.ps \
	../man1/col.1.ps ../man1/colcrt.1.ps ../man1/colrm.1.ps \
	../man1/comb.1.ps ../man1/comm.1.ps ../man1/compress.1.ps \
	../man1/cp.1.ps ../man1/cpio.1.ps ../man1/crypt.1.ps ../man1/csh.1.ps \
	../man1/ctags.1.ps ../man1/date.1.ps ../man1/dbx.1.ps ../man1/dc.1.ps \
	../man1/dd.1.ps ../man1/delta.1.ps ../man1/deroff.1.ps ../man1/df.1.ps \
	../man1/diction.1.ps ../man1/diff.1.ps ../man1/diff3.1.ps \
	../man1/du.1.ps ../man1/echo.1.ps ../man1/ed.1.ps ../man1/efl.1.ps \
	../man1/eqn.1.ps ../man1/error.1.ps ../man1/ex.1.ps \
	../man1/expand.1.ps ../man1/expr.1.ps ../man1/f77.1.ps \
D 3
	../man1/false.1.ps ../man1/file.1.ps ../man1/find.1.ps \
E 3
I 3
	../man1/false.1.ps ../man1/fed.1.ps ../man1/file.1.ps \
	../man1/find.1.ps \
E 3
	../man1/finger.1.ps ../man1/fmt.1.ps ../man1/fold.1.ps ../man1/fp.1.ps \
	../man1/fpr.1.ps ../man1/from.1.ps ../man1/fsplit.1.ps \
	../man1/ftp.1c.ps ../man1/gcore.1.ps ../man1/get.1.ps \
	../man1/gprof.1.ps ../man1/graph.1g.ps ../man1/grep.1.ps \
	../man1/groups.1.ps ../man1/gzcompat.1.ps ../man1/head.1.ps \
	../man1/hostid.1.ps ../man1/hostname.1.ps ../man1/indent.1.ps \
	../man1/install.1.ps ../man1/iostat.1.ps ../man1/join.1.ps \
	../man1/kill.1.ps ../man1/last.1.ps ../man1/lastcomm.1.ps \
	../man1/ld.1.ps ../man1/learn.1.ps ../man1/leave.1.ps ../man1/lex.1.ps \
	../man1/lint.1.ps ../man1/ln.1.ps ../man1/lock.1.ps \
	../man1/logger.1.ps ../man1/login.1.ps ../man1/look.1.ps \
	../man1/lookbib.1.ps ../man1/lorder.1.ps ../man1/lpq.1.ps \
	../man1/lpr.1.ps ../man1/lprm.1.ps ../man1/lptest.1.ps ../man1/ls.1.ps \
	../man1/m4.1.ps ../man1/mail.1.ps ../man1/make.1.ps ../man1/man.1.ps \
	../man1/mesg.1.ps ../man1/mkdep.1.ps ../man1/mkdir.1.ps \
	../man1/mkstr.1.ps ../man1/more.1.ps ../man1/mset.1.ps \
	../man1/msgs.1.ps ../man1/mt.1.ps ../man1/mv.1.ps ../man1/netstat.1.ps \
	../man1/newaliases.1.ps ../man1/nice.1.ps ../man1/nm.1.ps \
	../man1/nroff.1.ps ../man1/od.1.ps ../man1/pagesize.1.ps \
	../man1/passwd.1.ps ../man1/pc.1.ps ../man1/pdx.1.ps ../man1/pi.1.ps \
	../man1/pix.1.ps ../man1/plot.1g.ps ../man1/pmerge.1.ps \
	../man1/pr.1.ps ../man1/preppsfont.1.ps ../man1/printenv.1.ps \
	../man1/prof.1.ps ../man1/prt.1.ps ../man1/ps.1.ps \
	../man1/pstroff.1.ps ../man1/ptx.1.ps ../man1/pwd.1.ps ../man1/px.1.ps \
	../man1/pxp.1.ps ../man1/pxref.1.ps ../man1/quota.1.ps \
	../man1/ranlib.1.ps ../man1/ratfor.1.ps ../man1/rcp.1c.ps \
	../man1/rdist.1.ps ../man1/refer.1.ps ../man1/rev.1.ps \
	../man1/rlogin.1c.ps ../man1/rm.1.ps ../man1/rmail.1.ps \
	../man1/rmdel.1.ps ../man1/rmdir.1.ps ../man1/roffbib.1.ps \
	../man1/rsh.1c.ps ../man1/ruptime.1c.ps ../man1/rwho.1c.ps \
	../man1/sccs.1.ps ../man1/sccsdiff.1.ps ../man1/sccshelp.1.ps \
	../man1/script.1.ps ../man1/sed.1.ps ../man1/sendbug.1.ps \
	../man1/sh.1.ps ../man1/size.1.ps ../man1/sleep.1.ps \
	../man1/soelim.1.ps ../man1/sort.1.ps ../man1/sortbib.1.ps \
	../man1/spell.1.ps ../man1/spline.1g.ps ../man1/split.1.ps \
	../man1/strings.1.ps ../man1/strip.1.ps ../man1/struct.1.ps \
	../man1/stty.1.ps ../man1/style.1.ps ../man1/su.1.ps ../man1/sum.1.ps \
	../man1/symorder.1.ps ../man1/sysline.1.ps ../man1/systat.1.ps \
	../man1/tabs.1.ps ../man1/tail.1.ps ../man1/talk.1.ps ../man1/tar.1.ps \
	../man1/tbl.1.ps ../man1/tc.1.ps ../man1/tcopy.1.ps ../man1/tee.1.ps \
	../man1/telnet.1c.ps ../man1/test.1.ps ../man1/tftp.1c.ps \
	../man1/time.1.ps ../man1/tip.1c.ps ../man1/tk.1.ps \
	../man1/tn3270.1.ps ../man1/touch.1.ps ../man1/tp.1.ps ../man1/tr.1.ps \
	../man1/troff.1.ps ../man1/true.1.ps ../man1/tset.1.ps \
	../man1/tsort.1.ps ../man1/tty.1.ps ../man1/ul.1.ps \
	../man1/unifdef.1.ps ../man1/uniq.1.ps ../man1/units.1.ps \
	../man1/uptime.1.ps ../man1/users.1.ps ../man1/uucp.1c.ps \
	../man1/uuencode.1c.ps ../man1/uulog.1c.ps ../man1/uuname.1c.ps \
	../man1/uuq.1c.ps ../man1/uusend.1c.ps ../man1/uux.1c.ps \
D 3
	../man1/vacation.1.ps ../man1/vgrind.1.ps ../man1/vi.1.ps \
	../man1/vmstat.1.ps ../man1/w.1.ps ../man1/wait.1.ps ../man1/wall.1.ps \
E 3
I 3
	../man1/vacation.1.ps ../man1/vfontinfo.1.ps ../man1/vgrind.1.ps \
	../man1/vi.1.ps ../man1/vmstat.1.ps ../man1/vtroff.1.ps \
	../man1/vwidth.1.ps \
	../man1/w.1.ps ../man1/wait.1.ps ../man1/wall.1.ps \
E 3
	../man1/wc.1.ps ../man1/what.1.ps ../man1/whatis.1.ps \
	../man1/whereis.1.ps ../man1/which.1.ps ../man1/who.1.ps \
	../man1/whoami.1.ps ../man1/whois.1.ps ../man1/window.1.ps \
	../man1/write.1.ps ../man1/xsend.1.ps ../man1/xstr.1.ps \
	../man1/yacc.1.ps ../man1/yes.1.ps
MAN2=	../man2/intro.2.ps ../man2/accept.2.ps ../man2/access.2.ps \
	../man2/acct.2.ps ../man2/adjtime.2.ps ../man2/bind.2.ps \
	../man2/brk.2.ps ../man2/chdir.2.ps ../man2/chmod.2.ps \
	../man2/chown.2.ps ../man2/chroot.2.ps ../man2/close.2.ps \
	../man2/connect.2.ps ../man2/creat.2.ps ../man2/dup.2.ps \
	../man2/execve.2.ps ../man2/exit.2.ps ../man2/fcntl.2.ps \
	../man2/flock.2.ps ../man2/fork.2.ps ../man2/fsync.2.ps \
	../man2/getdtablesize.2.ps ../man2/getgid.2.ps ../man2/getgroups.2.ps \
	../man2/gethostid.2.ps ../man2/gethostname.2.ps ../man2/getitimer.2.ps \
	../man2/getpagesize.2.ps ../man2/getpeername.2.ps ../man2/getpgrp.2.ps \
	../man2/getpid.2.ps ../man2/getpriority.2.ps ../man2/getrlimit.2.ps \
	../man2/getrusage.2.ps ../man2/getsockname.2.ps \
	../man2/getsockopt.2.ps ../man2/gettimeofday.2.ps ../man2/getuid.2.ps \
	../man2/ioctl.2.ps ../man2/kill.2.ps ../man2/killpg.2.ps \
	../man2/link.2.ps ../man2/listen.2.ps ../man2/lseek.2.ps \
	../man2/mkdir.2.ps ../man2/mknod.2.ps ../man2/mount.2.ps \
	../man2/open.2.ps ../man2/pipe.2.ps ../man2/profil.2.ps \
	../man2/ptrace.2.ps ../man2/quota.2.ps ../man2/read.2.ps \
	../man2/readlink.2.ps ../man2/reboot.2.ps ../man2/recv.2.ps \
	../man2/rename.2.ps ../man2/rmdir.2.ps ../man2/select.2.ps \
	../man2/send.2.ps ../man2/setgroups.2.ps ../man2/setpgrp.2.ps \
	../man2/setquota.2.ps ../man2/setregid.2.ps ../man2/setreuid.2.ps \
	../man2/shutdown.2.ps ../man2/sigblock.2.ps ../man2/sigpause.2.ps \
	../man2/sigreturn.2.ps ../man2/sigsetmask.2.ps ../man2/sigstack.2.ps \
	../man2/sigvec.2.ps ../man2/socket.2.ps ../man2/socketpair.2.ps \
	../man2/stat.2.ps ../man2/swapon.2.ps ../man2/symlink.2.ps \
	../man2/sync.2.ps ../man2/syscall.2.ps ../man2/truncate.2.ps \
	../man2/umask.2.ps ../man2/unlink.2.ps ../man2/utimes.2.ps \
	../man2/vadvise.2.ps ../man2/vfork.2.ps ../man2/vhangup.2.ps \
	../man2/wait.2.ps ../man2/write.2.ps
MAN3=	../man3/intro.3.ps ../man3/abort.3.ps ../man3/abs.3.ps \
	../man3/alarm.3c.ps ../man3/asinh.3m.ps ../man3/assert.3.ps \
	../man3/atof.3.ps ../man3/bstring.3.ps ../man3/byteorder.3n.ps \
	../man3/compat-sys5.3.ps ../man3/crypt.3.ps ../man3/ctime.3.ps \
	../man3/ctype.3.ps ../man3/curses.3x.ps ../man3/dbm.3x.ps \
	../man3/directory.3.ps ../man3/ecvt.3.ps ../man3/end.3.ps \
	../man3/erf.3m.ps ../man3/execl.3.ps ../man3/exit.3.ps \
	../man3/exp.3m.ps ../man3/fclose.3s.ps ../man3/ferror.3s.ps \
	../man3/floor.3m.ps ../man3/fopen.3s.ps ../man3/fread.3s.ps \
	../man3/frexp.3.ps ../man3/fseek.3s.ps ../man3/getc.3s.ps \
	../man3/getdiskbyname.3.ps ../man3/getenv.3.ps ../man3/getfsent.3.ps \
	../man3/getgrent.3.ps ../man3/gethostbyname.3n.ps \
	../man3/getlogin.3.ps ../man3/getnetent.3n.ps ../man3/getopt.3.ps \
	../man3/getpass.3.ps ../man3/getprotoent.3n.ps ../man3/getpw.3c.ps \
	../man3/getpwent.3.ps ../man3/gets.3s.ps ../man3/getservent.3n.ps \
	../man3/getttyent.3.ps ../man3/getusershell.3.ps ../man3/getwd.3.ps \
	../man3/hypot.3m.ps ../man3/ieee.3m.ps ../man3/inet.3n.ps \
	../man3/infnan.3m.ps ../man3/initgroups.3.ps ../man3/insque.3.ps \
	../man3/j0.3m.ps ../man3/lgamma.3m.ps ../man3/lib2648.3x.ps \
	../man3/malloc.3.ps ../man3/math.3.ps ../man3/mktemp.3.ps \
	../man3/monitor.3.ps ../man3/mp.3x.ps ../man3/ndbm.3.ps \
	../man3/nice.3c.ps ../man3/nlist.3.ps ../man3/ns.3n.ps \
	../man3/pause.3c.ps ../man3/perror.3.ps ../man3/plot.3.ps \
	../man3/popen.3.ps ../man3/printf.3s.ps ../man3/psignal.3.ps \
	../man3/putc.3s.ps ../man3/puts.3s.ps ../man3/qsort.3.ps \
	../man3/rand.3c.ps ../man3/random.3.ps ../man3/rcmd.3.ps \
	../man3/regex.3.ps ../man3/regexp.3.ps ../man3/resolver.3.ps \
	../man3/rexec.3.ps ../man3/scandir.3.ps ../man3/scanf.3s.ps \
	../man3/setbuf.3s.ps ../man3/setjmp.3.ps ../man3/setuid.3.ps \
	../man3/siginterrupt.3.ps ../man3/signal.3c.ps ../man3/sin.3m.ps \
	../man3/sinh.3m.ps ../man3/sleep.3.ps ../man3/sqrt.3m.ps \
	../man3/stdio.3s.ps ../man3/string.3.ps ../man3/stty.3c.ps \
	../man3/swab.3.ps ../man3/syslog.3.ps ../man3/system.3.ps \
	../man3/termcap.3x.ps ../man3/time.3c.ps ../man3/times.3c.ps \
	../man3/ttyname.3.ps ../man3/ualarm.3.ps ../man3/ungetc.3s.ps \
	../man3/usleep.3.ps ../man3/utime.3c.ps ../man3/valloc.3c.ps \
	../man3/varargs.3.ps ../man3/vlimit.3c.ps ../man3/vtimes.3c.ps
MAN3F=	../man3/man3f/intro.3f.ps ../man3/man3f/abort.3f.ps \
	../man3/man3f/access.3f.ps ../man3/man3f/alarm.3f.ps \
	../man3/man3f/bessel.3f.ps ../man3/man3f/bit.3f.ps \
	../man3/man3f/chdir.3f.ps ../man3/man3f/chmod.3f.ps \
	../man3/man3f/etime.3f.ps ../man3/man3f/exit.3f.ps \
	../man3/man3f/fdate.3f.ps ../man3/man3f/flmin.3f.ps \
	../man3/man3f/flush.3f.ps ../man3/man3f/fork.3f.ps \
	../man3/man3f/fseek.3f.ps ../man3/man3f/getarg.3f.ps \
	../man3/man3f/getc.3f.ps ../man3/man3f/getcwd.3f.ps \
	../man3/man3f/getenv.3f.ps ../man3/man3f/getlog.3f.ps \
	../man3/man3f/getpid.3f.ps ../man3/man3f/getuid.3f.ps \
	../man3/man3f/hostnm.3f.ps ../man3/man3f/idate.3f.ps \
	../man3/man3f/index.3f.ps ../man3/man3f/ioinit.3f.ps \
	../man3/man3f/kill.3f.ps ../man3/man3f/link.3f.ps \
	../man3/man3f/loc.3f.ps ../man3/man3f/long.3f.ps \
	../man3/man3f/malloc.3f.ps ../man3/man3f/perror.3f.ps \
	../man3/man3f/plot.3f.ps ../man3/man3f/putc.3f.ps \
	../man3/man3f/qsort.3f.ps ../man3/man3f/rand.3f.ps \
	../man3/man3f/random.3f.ps ../man3/man3f/rename.3f.ps \
	../man3/man3f/signal.3f.ps ../man3/man3f/sleep.3f.ps \
	../man3/man3f/stat.3f.ps ../man3/man3f/system.3f.ps \
	../man3/man3f/time.3f.ps ../man3/man3f/topen.3f.ps \
	../man3/man3f/traper.3f.ps ../man3/man3f/trapov.3f.ps \
	../man3/man3f/trpfpe.3f.ps ../man3/man3f/ttynam.3f.ps \
	../man3/man3f/unlink.3f.ps ../man3/man3f/wait.3f.ps
MAN4=	../man4/vax/intro.4.ps ../man4/intro.4n.ps ../man4/vax/acc.4.ps \
	../man4/vax/ad.4.ps ../man4/arp.4p.ps ../man4/vax/autoconf.4.ps \
	../man4/bk.4.ps ../man4/vax/cons.4.ps ../man4/vax/crl.4.ps \
	../man4/vax/css.4.ps ../man4/vax/ct.4.ps ../man4/vax/ddn.4.ps \
	../man4/vax/de.4.ps ../man4/vax/dh.4.ps ../man4/vax/dhu.4.ps \
	../man4/vax/dmc.4.ps ../man4/vax/dmf.4.ps ../man4/vax/dmv.4.ps \
	../man4/vax/dmz.4.ps ../man4/vax/dn.4.ps ../man4/drum.4.ps \
	../man4/vax/dz.4.ps ../man4/vax/ec.4.ps ../man4/vax/en.4.ps \
	../man4/vax/ex.4.ps ../man4/vax/fl.4.ps ../man4/vax/hdh.4.ps \
	../man4/vax/hk.4.ps ../man4/vax/hp.4.ps ../man4/vax/ht.4.ps \
	../man4/vax/hy.4.ps ../man4/icmp.4p.ps ../man4/idp.4p.ps \
	../man4/vax/ik.4.ps ../man4/vax/il.4.ps ../man4/vax/imp.4.ps \
	../man4/imp.4p.ps ../man4/inet.4f.ps ../man4/ip.4p.ps \
	../man4/vax/ix.4.ps ../man4/kdb.4.ps ../man4/vax/kg.4.ps \
	../man4/lo.4.ps ../man4/vax/lp.4.ps ../man4/vax/mem.4.ps \
	../man4/vax/mt.4.ps ../man4/vax/mtio.4.ps ../man4/vax/np.4.ps \
	../man4/ns.4f.ps ../man4/nsip.4.ps ../man4/null.4.ps \
	../man4/vax/pcl.4.ps ../man4/vax/ps.4.ps ../man4/pty.4.ps \
	../man4/vax/qe.4.ps ../man4/vax/rx.4.ps ../man4/spp.4p.ps \
	../man4/vax/tb.4.ps ../man4/tcp.4p.ps ../man4/vax/tm.4.ps \
	../man4/vax/tmscp.4.ps ../man4/vax/ts.4.ps ../man4/tty.4.ps \
	../man4/vax/tu.4.ps ../man4/vax/uda.4.ps ../man4/udp.4p.ps \
	../man4/vax/up.4.ps ../man4/vax/ut.4.ps ../man4/vax/uu.4.ps \
	../man4/vax/va.4.ps ../man4/vax/vp.4.ps ../man4/vax/vv.4.ps
MAN5=	../man5/L-devices.5.ps ../man5/L-dialcodes.5.ps ../man5/L.aliases.5.ps \
	../man5/L.cmds.5.ps ../man5/L.sys.5.ps ../man5/USERFILE.5.ps \
	../man5/a.out.5.ps ../man5/acct.5.ps ../man5/aliases.5.ps \
	../man5/ar.5.ps ../man5/core.5.ps ../man5/cpio.5.ps ../man5/dbx.5.ps \
	../man5/dir.5.ps ../man5/disklabel.5.ps ../man5/disktab.5.ps \
	../man5/dm.config.5.ps ../man5/dump.5.ps ../man5/fs.5.ps \
	../man5/fstab.5.ps ../man5/gettytab.5.ps ../man5/group.5.ps \
	../man5/hosts.5.ps ../man5/map3270.5.ps ../man5/mtab.5.ps \
	../man5/networks.5.ps ../man5/passwd.5.ps ../man5/phones.5.ps \
	../man5/plot.5.ps ../man5/printcap.5.ps ../man5/protocols.5.ps \
	../man5/remote.5.ps ../man5/resolver.5.ps ../man5/sccsfile.5.ps \
	../man5/services.5.ps ../man5/shells.5.ps ../man5/stab.5.ps \
	../man5/tar.5.ps ../man5/termcap.5.ps ../man5/tp.5.ps \
	../man5/ttys.5.ps ../man5/types.5.ps ../man5/tzfile.5.ps \
	../man5/utmp.5.ps ../man5/uuencode.5.ps ../man5/vfont.5.ps \
	../man5/vgrindefs.5.ps
MAN6=	../man6/aardvark.6.ps ../man6/adventure.6.ps ../man6/arithmetic.6.ps \
	../man6/atc.6.ps ../man6/backgammon.6.ps ../man6/banner.6.ps \
	../man6/battlestar.6.ps ../man6/bcd.6.ps ../man6/boggle.6.ps \
	../man6/canfield.6.ps ../man6/chess.6.ps ../man6/ching.6.ps \
	../man6/cribbage.6.ps ../man6/fish.6.ps ../man6/fortune.6.ps \
	../man6/hack.6.ps ../man6/hangman.6.ps ../man6/hunt.6.ps \
	../man6/mille.6.ps ../man6/monop.6.ps ../man6/number.6.ps \
	../man6/phantasia.6.ps ../man6/ppt.6.ps ../man6/quiz.6.ps \
	../man6/rain.6.ps \
	../man6/robots.6.ps ../man6/rogue.6.ps ../man6/sail.6.ps \
	../man6/snake.6.ps ../man6/trek.6.ps ../man6/worm.6.ps \
	../man6/worms.6.ps ../man6/wump.6.ps ../man6/zork.6.ps
MAN7=	../man7/intro.7.ps ../man7/ascii.7.ps ../man7/environ.7.ps \
	../man7/eqnchar.7.ps ../man7/hier.7.ps ../man7/hostname.7.ps \
	../man7/koi.7.ps ../man7/mailaddr.7.ps ../man7/man.7.ps \
	../man7/me.7.ps ../man7/ms.7.ps ../man7/term.7.ps
MAN8=	../man8/intro.8.ps ../man8/XNSrouted.8c.ps ../man8/ac.8.ps \
	../man8/acucntrl.8c.ps ../man8/adduser.8.ps ../man8/vax/arff.8v.ps \
	../man8/arp.8c.ps ../man8/vax/bad144.8.ps ../man8/badsect.8.ps \
	../man8/bugfiler.8.ps ../man8/catman.8.ps ../man8/chown.8.ps \
	../man8/clri.8.ps ../man8/comsat.8c.ps ../man8/config.8.ps \
	../man8/vax/crash.8v.ps ../man8/cron.8.ps ../man8/dcheck.8.ps \
	../man8/disklabel.8.ps ../man8/diskpart.8.ps ../man8/dm.8.ps \
	../man8/dmesg.8.ps ../man8/vax/drtest.8v.ps ../man8/dump.8.ps \
	../man8/dumpfs.8.ps ../man8/edquota.8.ps ../man8/fastboot.8.ps \
	../man8/fingerd.8c.ps ../man8/vax/format.8v.ps ../man8/fsck.8.ps \
	../man8/fsdb.8.ps ../man8/fstat.8.ps ../man8/ftpd.8c.ps \
	../man8/gettable.8c.ps ../man8/getty.8.ps ../man8/halt.8.ps \
	../man8/htable.8.ps ../man8/icheck.8.ps ../man8/ifconfig.8c.ps \
	../man8/implog.8c.ps ../man8/implogd.8c.ps ../man8/inetd.8.ps \
	../man8/init.8.ps ../man8/kgmon.8.ps ../man8/lpc.8.ps ../man8/lpd.8.ps \
	../man8/makedev.8.ps ../man8/makekey.8.ps ../man8/mkhosts.8.ps \
	../man8/mknod.8.ps ../man8/mkpasswd.8.ps ../man8/mkproto.8.ps \
	../man8/mount.8.ps ../man8/named.8.ps ../man8/ncheck.8.ps \
	../man8/newfs.8.ps ../man8/pac.8.ps ../man8/ping.8.ps \
	../man8/pstat.8.ps ../man8/quot.8.ps ../man8/quotacheck.8.ps \
	../man8/quotaon.8.ps ../man8/rc.8.ps ../man8/rdump.8c.ps \
	../man8/vax/reboot.8.ps ../man8/renice.8.ps ../man8/repquota.8.ps \
	../man8/restore.8.ps ../man8/rexecd.8c.ps ../man8/rlogind.8c.ps \
	../man8/rmt.8c.ps ../man8/route.8c.ps ../man8/routed.8c.ps \
	../man8/rrestore.8c.ps ../man8/rshd.8c.ps ../man8/rwhod.8c.ps \
	../man8/vax/rxformat.8v.ps ../man8/sa.8.ps ../man8/savecore.8.ps \
	../man8/sendmail.8.ps ../man8/shutdown.8.ps ../man8/slattach.8c.ps \
	../man8/sticky.8.ps ../man8/swapon.8.ps ../man8/sync.8.ps \
	../man8/syslogd.8.ps ../man8/talkd.8c.ps ../man8/telnetd.8c.ps \
	../man8/tftpd.8c.ps ../man8/timed.8.ps ../man8/timedc.8.ps \
	../man8/trpt.8c.ps ../man8/trsp.8c.ps ../man8/tunefs.8.ps \
	../man8/update.8.ps ../man8/uucico.8c.ps ../man8/uuclean.8c.ps \
	../man8/uupoll.8c.ps ../man8/uusnap.8c.ps ../man8/uuxqt.8c.ps \
	../man8/vipw.8.ps ../man8/zdump.8.ps ../man8/zic.8.ps

SECTIONS=	man1.ps man2.ps man3.ps man3f.ps man4.ps man5.ps man6.ps \
		man7.ps man8.ps

D 2
all psman:	${SECTIONS} urm.ps prm.ps
E 2
I 2
all psman:	${SECTIONS} urm.ps urmcover.ps prm.ps prmcover.ps
E 2

man1.ps:	${MAN1}
	pstmerge ${MAN1} > $@

man2.ps:	${MAN2}
	pstmerge ${MAN2} > $@

man3.ps:	${MAN3}
	pstmerge ${MAN3} > $@

man3f.ps:	${MAN3F}
	pstmerge ${MAN3F} > $@

man4.ps:	${MAN4}
	pstmerge ${MAN4} > $@

man5.ps:	${MAN5}
	pstmerge ${MAN5} > $@

man6.ps:	${MAN6}
	pstmerge ${MAN6} > $@

man7.ps:	${MAN7}
	pstmerge ${MAN7} > $@

man8.ps:	${MAN8}
	pstmerge ${MAN8} > $@

urm.ps:	../man0/urmhead.ps man1.ps man6.ps man7.ps
	pstmerge -s ../man0/urmhead.ps man1.ps man6.ps man7.ps > $@

I 2
urmcover.ps:	../man0/title.urm.ps
	psrange ../man0/title.urm.ps 1 > urmcover.ps
	ex - urmcover.ps < fixcover.ex

E 2
prm.ps:	../man0/title.prm.ps man2.ps man3.ps man3f.ps man4.ps man5.ps
	pstmerge -s ../man0/title.prm.ps man2.ps man3.ps man3f.ps man4.ps \
		man5.ps > $@
I 2

prmcover.ps:	../man0/title.prm.ps
	psrange ../man0/title.prm.ps 1 > prmcover.ps
	ex - prmcover.ps < fixcover.ex
E 2

clean:
	rm -f *.ps
E 1
