# Makefile for FalconDNS
#
#	@(#)Makefile	1.45 (IFCTF) 2013/01/14

CFLAGS=	-O
PROGS=	dnsd dnsdctl
SRCS=	askforns.c attachns.c axfrserv.c cachesweep.c class.c classreload.c \
	ctlsock.c dname.c dnameofnode.c fsrcache.c globals.c intquery.c label.c\
	main.c masterconf.c msgparse.c nsanchor.c nsanchorcmd.c nsanchorval.c \
	paths.c querydedup.c queryfor.c queryinit.c querystage.c querytrace.c \
	queryutil.c querywrap.c respwriter.c rrint.c selectloop.c stats.c \
	tcpqueue.c tcpserv.c treedump.c treenode.c udpout.c udpserv.c util.c \
	zoneinst.c zoneload.c zonemgmt.c zonerr.c zonesecond.c dnsdctl.c
DOBJS=	askforns.o attachns.o axfrserv.o cachesweep.o class.o classreload.o \
	ctlsock.o dname.o dnameofnode.o fsrcache.o globals.o intquery.o label.o\
	main.o masterconf.o msgparse.o nsanchor.o nsanchorcmd.o nsanchorval.o \
	paths.o querydedup.o queryfor.o queryinit.o querystage.o querytrace.o \
	queryutil.o querywrap.o respwriter.o rrint.o selectloop.o stats.o \
	tcpqueue.o tcpserv.o treedump.o treenode.o udpout.o udpserv.o util.o \
	zoneinst.o zoneload.o zonemgmt.o zonerr.o zonesecond.o

all:	${PROGS}

dnsd:	${DOBJS}
	${CC} -o $@ ${DOBJS}

dnsdctl:	dnsdctl.o
	${CC} -o $@ $@.o

clean: FRC
	rm -f *.o ${PROGS} *.out core errs

lint: FRC
	lint ${CFLAGS} ${SRCS}

tags: FRC
	ctags ${SRCS}

depend: FRC
	mkdep ${CFLAGS} ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

askforns.o: askforns.c /usr/include/sys/param.h /usr/include/sys/types.h
askforns.o: /usr/include/signal.h /usr/include/machine/trap.h
askforns.o: /usr/include/machine/machparam.h /usr/include/machine/endian.h
askforns.o: /usr/include/sys/socket.h /usr/include/netinet/in.h
askforns.o: /usr/include/arpa/inet.h /usr/include/arpa/nameser.h
askforns.o: /usr/include/stdio.h /usr/include/syslog.h dname.h class.h
askforns.o: /usr/include/stdio.h tree.h nsrec.h /usr/include/stdio.h rr.h
askforns.o: dname.h query.h /usr/include/stdio.h defs.h dname.h udpout.h
askforns.o: globals.h selectloop.h tcpqueue.h
attachns.o: attachns.c /usr/include/sys/param.h /usr/include/sys/types.h
attachns.o: /usr/include/signal.h /usr/include/machine/trap.h
attachns.o: /usr/include/machine/machparam.h /usr/include/machine/endian.h
attachns.o: /usr/include/arpa/nameser.h dname.h tree.h nsrec.h
attachns.o: /usr/include/stdio.h rr.h dname.h globals.h msgparse.h dname.h
axfrserv.o: axfrserv.c /usr/include/sys/types.h /usr/include/machine/endian.h
axfrserv.o: /usr/include/netinet/in.h /usr/include/arpa/nameser.h
axfrserv.o: /usr/include/syslog.h class.h /usr/include/stdio.h tree.h zone.h
axfrserv.o: /usr/include/stdio.h defs.h query.h /usr/include/stdio.h defs.h
axfrserv.o: dname.h globals.h
cachesweep.o: cachesweep.c /usr/include/sys/types.h /usr/include/netinet/in.h
cachesweep.o: /usr/include/arpa/nameser.h /usr/include/syslog.h tree.h nsrec.h
cachesweep.o: /usr/include/stdio.h rr.h dname.h globals.h selectloop.h
class.o: class.c /usr/include/sys/types.h /usr/include/netinet/in.h
class.o: /usr/include/arpa/inet.h /usr/include/arpa/nameser.h
class.o: /usr/include/ctype.h /usr/include/stdio.h /usr/include/strings.h
class.o: /usr/include/syslog.h defs.h class.h /usr/include/stdio.h globals.h
class.o: selectloop.h
classreload.o: classreload.c /usr/include/sys/types.h
classreload.o: /usr/include/arpa/nameser.h /usr/include/ctype.h
classreload.o: /usr/include/strings.h /usr/include/syslog.h class.h
classreload.o: /usr/include/stdio.h globals.h selectloop.h zone.h
classreload.o: /usr/include/stdio.h defs.h tree.h nsrec.h /usr/include/stdio.h
classreload.o: rr.h dname.h
ctlsock.o: ctlsock.c /usr/include/sys/types.h /usr/include/sys/socket.h
ctlsock.o: /usr/include/sys/un.h /usr/include/stdio.h /usr/include/ctype.h
ctlsock.o: /usr/include/strings.h /usr/include/syslog.h defs.h globals.h
ctlsock.o: selectloop.h
dname.o: dname.c /usr/include/sys/types.h /usr/include/arpa/nameser.h
dname.o: /usr/include/ctype.h /usr/include/stdio.h dname.h
dnameofnode.o: dnameofnode.c /usr/include/sys/types.h
dnameofnode.o: /usr/include/arpa/nameser.h dname.h tree.h zone.h
dnameofnode.o: /usr/include/stdio.h defs.h
fsrcache.o: fsrcache.c /usr/include/sys/types.h /usr/include/netinet/in.h
fsrcache.o: /usr/include/arpa/nameser.h /usr/include/syslog.h dname.h tree.h
fsrcache.o: nsrec.h /usr/include/stdio.h rr.h dname.h query.h
fsrcache.o: /usr/include/stdio.h defs.h dname.h msgparse.h dname.h globals.h
globals.o: globals.c /usr/include/sys/types.h
intquery.o: intquery.c /usr/include/sys/types.h
intquery.o: /usr/include/machine/machparam.h /usr/include/machine/endian.h
intquery.o: /usr/include/netinet/in.h /usr/include/arpa/nameser.h
intquery.o: /usr/include/stdio.h query.h /usr/include/stdio.h defs.h dname.h
intquery.o: globals.h
label.o: label.c /usr/include/sys/types.h /usr/include/arpa/nameser.h
label.o: /usr/include/stdio.h tree.h
main.o: main.c /usr/include/sys/types.h /usr/include/sys/file.h
main.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
main.o: /usr/include/sys/ttydev.h /usr/include/sys/signal.h
main.o: /usr/include/machine/trap.h /usr/include/sys/time.h /usr/include/time.h
main.o: /usr/include/sys/resource.h /usr/include/stdio.h /usr/include/ctype.h
main.o: /usr/include/syslog.h globals.h
masterconf.o: masterconf.c /usr/include/sys/types.h /usr/include/sys/stat.h
masterconf.o: /usr/include/netinet/in.h /usr/include/arpa/inet.h
masterconf.o: /usr/include/arpa/nameser.h /usr/include/stdio.h
masterconf.o: /usr/include/ctype.h /usr/include/strings.h /usr/include/syslog.h
masterconf.o: /usr/include/pwd.h defs.h globals.h acl.h query.h
masterconf.o: /usr/include/stdio.h defs.h dname.h
msgparse.o: msgparse.c /usr/include/sys/types.h /usr/include/arpa/nameser.h
msgparse.o: msgparse.h dname.h
nsanchor.o: nsanchor.c /usr/include/sys/param.h /usr/include/sys/types.h
nsanchor.o: /usr/include/signal.h /usr/include/machine/trap.h
nsanchor.o: /usr/include/machine/machparam.h /usr/include/machine/endian.h
nsanchor.o: /usr/include/netinet/in.h /usr/include/arpa/inet.h
nsanchor.o: /usr/include/arpa/nameser.h /usr/include/syslog.h
nsanchor.o: /usr/include/ctype.h /usr/include/strings.h defs.h class.h
nsanchor.o: /usr/include/stdio.h dname.h tree.h nsrec.h /usr/include/stdio.h
nsanchor.o: rr.h dname.h globals.h selectloop.h
nsanchorcmd.o: nsanchorcmd.c /usr/include/sys/param.h /usr/include/sys/types.h
nsanchorcmd.o: /usr/include/signal.h /usr/include/machine/trap.h
nsanchorcmd.o: /usr/include/machine/machparam.h /usr/include/machine/endian.h
nsanchorcmd.o: /usr/include/netinet/in.h /usr/include/arpa/nameser.h
nsanchorcmd.o: /usr/include/syslog.h /usr/include/ctype.h
nsanchorcmd.o: /usr/include/strings.h defs.h class.h /usr/include/stdio.h
nsanchorcmd.o: dname.h nsrec.h /usr/include/stdio.h rr.h dname.h globals.h
nsanchorval.o: nsanchorval.c /usr/include/sys/param.h /usr/include/sys/types.h
nsanchorval.o: /usr/include/signal.h /usr/include/machine/trap.h
nsanchorval.o: /usr/include/machine/machparam.h /usr/include/machine/endian.h
nsanchorval.o: /usr/include/netinet/in.h /usr/include/arpa/nameser.h
nsanchorval.o: /usr/include/syslog.h class.h /usr/include/stdio.h tree.h
nsanchorval.o: nsrec.h /usr/include/stdio.h rr.h dname.h globals.h selectloop.h
nsanchorval.o: msgparse.h dname.h query.h /usr/include/stdio.h defs.h dname.h
nsanchorval.o: udpout.h
paths.o: paths.c
querydedup.o: querydedup.c /usr/include/sys/types.h /usr/include/netinet/in.h
querydedup.o: /usr/include/arpa/nameser.h dname.h class.h /usr/include/stdio.h
querydedup.o: query.h /usr/include/stdio.h defs.h dname.h
queryfor.o: queryfor.c /usr/include/sys/param.h /usr/include/sys/types.h
queryfor.o: /usr/include/signal.h /usr/include/machine/trap.h
queryfor.o: /usr/include/machine/machparam.h /usr/include/machine/endian.h
queryfor.o: /usr/include/netinet/in.h /usr/include/arpa/inet.h
queryfor.o: /usr/include/arpa/nameser.h /usr/include/syslog.h dname.h class.h
queryfor.o: /usr/include/stdio.h tree.h nsrec.h /usr/include/stdio.h rr.h
queryfor.o: dname.h query.h /usr/include/stdio.h defs.h dname.h globals.h
queryfor.o: msgparse.h dname.h udpout.h
queryinit.o: queryinit.c /usr/include/sys/types.h /usr/include/machine/endian.h
queryinit.o: /usr/include/netinet/in.h /usr/include/arpa/nameser.h class.h
queryinit.o: /usr/include/stdio.h query.h /usr/include/stdio.h defs.h dname.h
queryinit.o: globals.h acl.h
querystage.o: querystage.c /usr/include/sys/types.h /usr/include/netinet/in.h
querystage.o: /usr/include/arpa/nameser.h dname.h class.h /usr/include/stdio.h
querystage.o: tree.h nsrec.h /usr/include/stdio.h rr.h dname.h query.h
querystage.o: /usr/include/stdio.h defs.h dname.h globals.h
querytrace.o: querytrace.c /usr/include/sys/types.h /usr/include/netinet/in.h
querytrace.o: /usr/include/arpa/nameser.h /usr/include/ctype.h
querytrace.o: /usr/include/stdio.h /usr/include/strings.h /usr/include/syslog.h
querytrace.o: class.h /usr/include/stdio.h dname.h query.h /usr/include/stdio.h
querytrace.o: defs.h dname.h
queryutil.o: queryutil.c /usr/include/sys/types.h /usr/include/machine/endian.h
queryutil.o: /usr/include/netinet/in.h /usr/include/arpa/nameser.h query.h
queryutil.o: /usr/include/stdio.h defs.h dname.h globals.h
querywrap.o: querywrap.c /usr/include/sys/types.h /usr/include/machine/endian.h
querywrap.o: /usr/include/netinet/in.h /usr/include/arpa/nameser.h
querywrap.o: /usr/include/syslog.h dname.h query.h /usr/include/stdio.h defs.h
querywrap.o: dname.h class.h /usr/include/stdio.h tree.h rr.h dname.h globals.h
respwriter.o: respwriter.c /usr/include/sys/param.h /usr/include/sys/types.h
respwriter.o: /usr/include/signal.h /usr/include/machine/trap.h
respwriter.o: /usr/include/machine/machparam.h /usr/include/machine/endian.h
respwriter.o: /usr/include/netinet/in.h /usr/include/arpa/nameser.h
respwriter.o: /usr/include/syslog.h class.h /usr/include/stdio.h dname.h tree.h
respwriter.o: nsrec.h /usr/include/stdio.h rr.h dname.h query.h
respwriter.o: /usr/include/stdio.h defs.h dname.h zone.h /usr/include/stdio.h
respwriter.o: defs.h globals.h msgparse.h dname.h
rrint.o: rrint.c /usr/include/sys/types.h /usr/include/arpa/nameser.h dname.h
rrint.o: rr.h dname.h msgparse.h dname.h globals.h
selectloop.o: selectloop.c /usr/include/sys/types.h /usr/include/sys/time.h
selectloop.o: /usr/include/time.h /usr/include/sys/errno.h
selectloop.o: /usr/include/netinet/in.h /usr/include/stdio.h
selectloop.o: /usr/include/syslog.h globals.h selectloop.h query.h
selectloop.o: /usr/include/stdio.h defs.h dname.h
stats.o: stats.c /usr/include/sys/types.h /usr/include/netinet/in.h
stats.o: /usr/include/arpa/inet.h /usr/include/arpa/nameser.h
stats.o: /usr/include/ctype.h /usr/include/stdio.h /usr/include/syslog.h
stats.o: /usr/include/time.h class.h /usr/include/stdio.h dname.h query.h
stats.o: /usr/include/stdio.h defs.h dname.h globals.h
tcpqueue.o: tcpqueue.c /usr/include/sys/types.h /usr/include/sys/socket.h
tcpqueue.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
tcpqueue.o: /usr/include/sys/ttydev.h /usr/include/sys/errno.h
tcpqueue.o: /usr/include/netinet/in.h /usr/include/arpa/nameser.h
tcpqueue.o: /usr/include/syslog.h tcpqueue.h globals.h selectloop.h
tcpserv.o: tcpserv.c /usr/include/sys/types.h /usr/include/machine/endian.h
tcpserv.o: /usr/include/sys/socket.h /usr/include/sys/ioctl.h
tcpserv.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
tcpserv.o: /usr/include/netinet/in.h /usr/include/arpa/nameser.h
tcpserv.o: /usr/include/syslog.h query.h /usr/include/stdio.h defs.h dname.h
tcpserv.o: globals.h selectloop.h acl.h
treedump.o: treedump.c /usr/include/sys/types.h /usr/include/netinet/in.h
treedump.o: /usr/include/arpa/nameser.h /usr/include/arpa/inet.h
treedump.o: /usr/include/ctype.h /usr/include/stdio.h /usr/include/time.h
treedump.o: /usr/include/syslog.h tree.h nsrec.h /usr/include/stdio.h rr.h
treedump.o: dname.h zone.h /usr/include/stdio.h defs.h class.h
treedump.o: /usr/include/stdio.h globals.h
treenode.o: treenode.c /usr/include/sys/types.h /usr/include/arpa/nameser.h
treenode.o: /usr/include/ctype.h /usr/include/syslog.h class.h
treenode.o: /usr/include/stdio.h dname.h tree.h nsrec.h /usr/include/stdio.h
treenode.o: rr.h dname.h globals.h
udpout.o: udpout.c /usr/include/sys/types.h /usr/include/sys/socket.h
udpout.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
udpout.o: /usr/include/sys/ttydev.h /usr/include/netinet/in.h
udpout.o: /usr/include/arpa/nameser.h /usr/include/stdio.h
udpout.o: /usr/include/syslog.h udpout.h globals.h selectloop.h
udpserv.o: udpserv.c /usr/include/sys/types.h /usr/include/machine/endian.h
udpserv.o: /usr/include/sys/socket.h /usr/include/sys/ioctl.h
udpserv.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
udpserv.o: /usr/include/netinet/in.h /usr/include/arpa/nameser.h
udpserv.o: /usr/include/syslog.h query.h /usr/include/stdio.h defs.h dname.h
udpserv.o: globals.h selectloop.h acl.h
util.o: util.c /usr/include/ctype.h /usr/include/syslog.h
zoneinst.o: zoneinst.c /usr/include/sys/types.h /usr/include/arpa/nameser.h
zoneinst.o: /usr/include/syslog.h dname.h tree.h zone.h /usr/include/stdio.h
zoneinst.o: defs.h class.h /usr/include/stdio.h nsrec.h /usr/include/stdio.h
zoneinst.o: rr.h dname.h
zoneload.o: zoneload.c /usr/include/sys/types.h /usr/include/machine/endian.h
zoneload.o: /usr/include/sys/stat.h /usr/include/netinet/in.h
zoneload.o: /usr/include/arpa/nameser.h /usr/include/stdio.h
zoneload.o: /usr/include/syslog.h defs.h dname.h tree.h nsrec.h
zoneload.o: /usr/include/stdio.h rr.h dname.h zone.h /usr/include/stdio.h
zoneload.o: defs.h class.h /usr/include/stdio.h globals.h selectloop.h
zoneload.o: msgparse.h dname.h
zonemgmt.o: zonemgmt.c /usr/include/sys/types.h /usr/include/sys/stat.h
zonemgmt.o: /usr/include/arpa/nameser.h /usr/include/ctype.h
zonemgmt.o: /usr/include/stdio.h /usr/include/strings.h /usr/include/syslog.h
zonemgmt.o: defs.h dname.h class.h /usr/include/stdio.h zone.h
zonemgmt.o: /usr/include/stdio.h defs.h tree.h rr.h dname.h selectloop.h
zonemgmt.o: globals.h
zonerr.o: zonerr.c /usr/include/sys/types.h /usr/include/arpa/nameser.h
zonerr.o: /usr/include/syslog.h dname.h tree.h rr.h dname.h msgparse.h dname.h
zonesecond.o: zonesecond.c /usr/include/sys/types.h /usr/include/sys/socket.h
zonesecond.o: /usr/include/sys/wait.h /usr/include/machine/endian.h
zonesecond.o: /usr/include/machine/endian.h /usr/include/netinet/in.h
zonesecond.o: /usr/include/arpa/inet.h /usr/include/arpa/nameser.h
zonesecond.o: /usr/include/syslog.h class.h /usr/include/stdio.h dname.h zone.h
zonesecond.o: /usr/include/stdio.h defs.h tree.h rr.h dname.h query.h
zonesecond.o: /usr/include/stdio.h defs.h dname.h tcpqueue.h msgparse.h dname.h
zonesecond.o: globals.h
dnsdctl.o: dnsdctl.c /usr/include/sys/types.h /usr/include/sys/file.h
dnsdctl.o: /usr/include/sys/socket.h /usr/include/sys/un.h /usr/include/stdio.h
dnsdctl.o: /usr/include/ctype.h /usr/include/strings.h defs.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
