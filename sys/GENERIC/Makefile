IDENT=-DGENERIC -DVAX650 -DVAX630 -DVAX730 -DVAX750 -DVAX780 -DVAX8200 -DVAX8600 -DTCP_COMPAT_42 -DNS -DINET -DQUOTA
PARAM=-DTIMEZONE=480 -DDST=1 -DMAXUSERS=8
#
# Copyright (c) 1980, 1986 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	@(#)Makefile.vax	7.8 (Berkeley) 10/22/87
#
# Makefile for 4.3 BSD
#
# This makefile is constructed from a machine description:
#	config machineid
# Most changes should be made in the machine description
#	/sys/conf/``machineid''
# after which you should do
#	 config machineid
# Generic makefile changes should be made in
#	/sys/conf/Makefile.``machinetype''
# after which config should be rerun for all machines.
#
# N.B.: NO DEPENDENCIES ON FOLLOWING FLAGS ARE VISIBLE TO MAKEFILE
#	IF YOU CHANGE THE DEFINITION OF ANY OF THESE RECOMPILE EVERYTHING
#
# -DTRACE	compile in kernel tracing hooks
# -DQUOTA	compile in file system quotas
# -DUUDMA	compile in unibus tu58 pseudo-dma code
#
C2=	/lib/c2
LD=	/bin/ld
INLINECMD= ../vax/inline/inline
INLINE=	${INLINECMD} ${INLINEOPTS}
TOUCH=	touch -f -c

INCLUDES= -I. -I../h
COPTS=	${INCLUDES} ${IDENT} -DKERNEL
CFLAGS=	-O ${COPTS}

AHEADS=	../vax/pcb.m

OBJS=af.o if.o if_loop.o raw_cb.o raw_usrreq.o route.o if_ether.o in.o \
	in_pcb.o in_proto.o ip_icmp.o ip_input.o ip_output.o raw_ip.o \
	tcp_debug.o tcp_input.o tcp_output.o tcp_subr.o tcp_timer.o \
	tcp_usrreq.o udp_usrreq.o idp_usrreq.o ns.o ns_error.o ns_ip.o \
	ns_input.o ns_output.o ns_pcb.o ns_proto.o spp_debug.o \
	spp_usrreq.o init_main.o init_sysent.o kern_acct.o kern_clock.o \
	kern_descrip.o kern_exec.o kern_exit.o kern_fork.o kern_malloc.o \
	kern_mman.o kern_proc.o kern_prot.o kern_resource.o kern_sig.o \
	kern_subr.o kern_synch.o kern_time.o kern_xxx.o quota_kern.o \
	quota_subr.o quota_sys.o quota_ufs.o subr_log.o subr_prf.o \
	subr_rmap.o subr_xxx.o sys_generic.o sys_inode.o sys_process.o \
	sys_socket.o tty.o tty_conf.o tty_pty.o tty_subr.o tty_tty.o \
	ufs_alloc.o ufs_bio.o ufs_bmap.o ufs_disksubr.o ufs_fio.o \
	ufs_inode.o ufs_mount.o ufs_namei.o ufs_subr.o ufs_syscalls.o \
	ufs_tables.o ufs_xxx.o uipc_domain.o uipc_mbuf.o uipc_proto.o \
	uipc_socket.o uipc_socket2.o uipc_syscalls.o uipc_usrreq.o \
	vm_drum.o vm_mem.o vm_mon.o vm_page.o vm_proc.o vm_pt.o \
	vm_sched.o vm_subr.o vm_sw.o vm_swap.o vm_swp.o vm_text.o \
	autoconf.o clock.o conf.o cons.o cpudata.o crl.o dkbad.o flp.o \
	in_cksum.o ka650.o ka630.o ka730.o ka750.o ka780.o ka820.o \
	ka860.o machdep.o mem.o mscp.o ns_cksum.o rx50.o sys_machdep.o \
	trap.o tu.o udiv.o ufs_machdep.o urem.o vm_machdep.o bi.o kdb.o \
	if_de.o if_ec.o if_ex.o if_il.o if_qe.o if_uba.o hp.o ht.o mba.o \
	mt.o dh.o dhu.o dmf.o dmx.o dmz.o dz.o idc.o lp.o rk.o rl.o tm.o \
	tmscp.o ts.o uba.o uda.o up.o ut.o qv.o qfont.o qd.o 

CFILES=../net/af.c ../net/if.c ../net/if_loop.c ../net/raw_cb.c \
	../net/raw_usrreq.c ../net/route.c ../netinet/if_ether.c \
	../netinet/in.c ../netinet/in_pcb.c ../netinet/in_proto.c \
	../netinet/ip_icmp.c ../netinet/ip_input.c \
	../netinet/ip_output.c ../netinet/raw_ip.c \
	../netinet/tcp_debug.c ../netinet/tcp_input.c \
	../netinet/tcp_output.c ../netinet/tcp_subr.c \
	../netinet/tcp_timer.c ../netinet/tcp_usrreq.c \
	../netinet/udp_usrreq.c ../netns/idp_usrreq.c ../netns/ns.c \
	../netns/ns_error.c ../netns/ns_ip.c ../netns/ns_input.c \
	../netns/ns_output.c ../netns/ns_pcb.c ../netns/ns_proto.c \
	../netns/spp_debug.c ../netns/spp_usrreq.c ../sys/init_main.c \
	../sys/init_sysent.c ../sys/kern_acct.c ../sys/kern_clock.c \
	../sys/kern_descrip.c ../sys/kern_exec.c ../sys/kern_exit.c \
	../sys/kern_fork.c ../sys/kern_malloc.c ../sys/kern_mman.c \
	../sys/kern_proc.c ../sys/kern_prot.c ../sys/kern_resource.c \
	../sys/kern_sig.c ../sys/kern_subr.c ../sys/kern_synch.c \
	../sys/kern_time.c ../sys/kern_xxx.c ../sys/quota_kern.c \
	../sys/quota_subr.c ../sys/quota_sys.c ../sys/quota_ufs.c \
	../sys/subr_log.c ../sys/subr_prf.c ../sys/subr_rmap.c \
	../sys/subr_xxx.c ../sys/sys_generic.c ../sys/sys_inode.c \
	../sys/sys_process.c ../sys/sys_socket.c ../sys/tty.c \
	../sys/tty_conf.c ../sys/tty_pty.c ../sys/tty_subr.c \
	../sys/tty_tty.c ../sys/ufs_alloc.c ../sys/ufs_bio.c \
	../sys/ufs_bmap.c ../sys/ufs_disksubr.c ../sys/ufs_fio.c \
	../sys/ufs_inode.c ../sys/ufs_mount.c ../sys/ufs_namei.c \
	../sys/ufs_subr.c ../sys/ufs_syscalls.c ../sys/ufs_tables.c \
	../sys/ufs_xxx.c ../sys/uipc_domain.c ../sys/uipc_mbuf.c \
	../sys/uipc_proto.c ../sys/uipc_socket.c ../sys/uipc_socket2.c \
	../sys/uipc_syscalls.c ../sys/uipc_usrreq.c ../sys/vm_drum.c \
	../sys/vm_mem.c ../sys/vm_mon.c ../sys/vm_page.c \
	../sys/vm_proc.c ../sys/vm_pt.c ../sys/vm_sched.c \
	../sys/vm_subr.c ../sys/vm_sw.c ../sys/vm_swap.c ../sys/vm_swp.c \
	../sys/vm_text.c ../vax/autoconf.c ../vax/clock.c ../vax/conf.c \
	../vax/cons.c ../vax/cpudata.c ../vax/crl.c ../vax/dkbad.c \
	../vax/flp.c ../vax/in_cksum.c ../vax/ka650.c ../vax/ka630.c \
	../vax/ka730.c ../vax/ka750.c ../vax/ka780.c ../vax/ka820.c \
	../vax/ka860.c ../vax/machdep.c ../vax/mem.c ../vax/mscp.c \
	../vax/ns_cksum.c ../vax/rx50.c ../vax/sys_machdep.c \
	../vax/trap.c ../vax/tu.c ../vax/ufs_machdep.c \
	../vax/vm_machdep.c ../vaxbi/bi.c ../vaxbi/kdb.c \
	../vaxif/if_de.c ../vaxif/if_ec.c ../vaxif/if_ex.c \
	../vaxif/if_il.c ../vaxif/if_qe.c ../vaxif/if_uba.c \
	../vaxmba/hp.c ../vaxmba/ht.c ../vaxmba/mba.c ../vaxmba/mt.c \
	../vaxuba/dh.c ../vaxuba/dhu.c ../vaxuba/dmf.c ../vaxuba/dmx.c \
	../vaxuba/dmz.c ../vaxuba/dz.c ../vaxuba/idc.c ../vaxuba/lp.c \
	../vaxuba/rk.c ../vaxuba/rl.c ../vaxuba/tm.c ../vaxuba/tmscp.c \
	../vaxuba/ts.c ../vaxuba/uba.c ../vaxuba/uda.c ../vaxuba/up.c \
	../vaxuba/ut.c ../vaxuba/qv.c ../vaxuba/qfont.c ../vaxuba/qd.c \
	../vax/swapgeneric.c 

vmunix: Makefile ../machine/symbols.sort ${INLINECMD} locore.o emulate.o ${OBJS} param.o ioconf.o swapgeneric.o
	@echo loading vmunix
	@rm -f vmunix
	@sh ../conf/newvers.sh
	@${CC} $(CFLAGS) -c vers.c
	@${LD} -n -o vmunix -e start -x -T 80000000 locore.o emulate.o ${OBJS} vers.o ioconf.o param.o swapgeneric.o
	@echo rearranging symbols
	@-symorder ../vax/symbols.sort vmunix
	@size vmunix
	@chmod 755 vmunix

swapgeneric.o: ../vax/swapgeneric.c
	${CC} -c -S ${COPTS} ../vax/swapgeneric.c
	${C2} swapgeneric.s | ${INLINE} | ${AS} -o swapgeneric.o
	rm -f swapgeneric.s

all: vmunix

clean:
	rm -f eddep *vmunix tags *.o locore.i [a-tv-z]*.s \
		errs linterrs makelinks

lint: /tmp param.c
	@lint -hbxn -DGENERIC ${COPTS} ${PARAM} \
	  ../vax/Locore.c ${CFILES} ioconf.c param.c | \
	    grep -v 'struct/union .* never defined' | \
	    grep -v 'possible pointer alignment problem'

../vax/symbols.sort: ../vax/symbols.raw
	grep -v '^#' ../vax/symbols.raw \
	    | sed 's/^	//' | sort -u > ../vax/symbols.sort

../vax/inline/inline: ../vax/inline/inline.h ../vax/inline/langpats.c
../vax/inline/inline: ../vax/inline/libcpats.c ../vax/inline/machdep.c
../vax/inline/inline: ../vax/inline/machpats.c ../vax/inline/main.c
	cd ../vax/inline; make

locore.o: assym.s ${AHEADS} ../vax/rpb.s ../vax/scb.s ubvec.s \
    ../vax/locore.s ubglue.s ../vax/mtpr.h ../vax/trap.h ../machine/psl.h \
    ../machine/pte.h ../vax/cpu.h mba.h
	cat assym.s ../vax/rpb.s ../vax/scb.s ubvec.s ../vax/locore.s \
	    ubglue.s > locore.c
	cc -E -DLOCORE -I../vax ${COPTS} locore.c > locore.i
	@echo 'as -o locore.o $${AHEADS} locore.i'
	@as -o locore.o ${AHEADS} locore.i
	@rm locore.i

emulate.o: ../vax/emulate.s
	/lib/cpp -I. ${COPTS} ../vax/emulate.s | ${AS} -o emulate.o

# the following is necessary because autoconf.o depends on #if GENERIC
autoconf.o tu.o: Makefile

# the following are necessary because the files depend on the types of
# vax cpu's included in the system configuration
clock.o machdep.o autoconf.o conf.o cons.o cpudata.o : Makefile
crl.o flp.o mba.o uba.o vaxcpu.o : Makefile

# depend on network configuration
af.o uipc_proto.o uipc_domain.o locore.o: Makefile

# depends on kdb being configured
trap.o:	Makefile

# depend on maxusers
assym.s: Makefile

assym.s: ../h/param.h ../machine/pte.h ../h/buf.h ../h/vmparam.h \
    ../h/vmmeter.h ../h/dir.h ../h/cmap.h ../h/map.h ../vaxuba/ubavar.h \
    ../vaxuba/ubareg.h ../h/proc.h ../h/msgbuf.h ../h/text.h ../h/user.h \
    ../vax/rpb.h ../machine/vmparam.h
	cc ${INCLUDES} ${IDENT} ${PARAM} ../vax/genassym.c
	./a.out >assym.s; rm -f a.out

depend:	assym.s
	mkdep ${COPTS} ${CFILES}

links:
	egrep '#if' ${CFILES} | sed -f ../conf/defines | \
	  sed -e 's/:.*//' -e 's/\.c/.o/' | sort -u > dontlink
	echo ${CFILES} | tr -s ' ' '\12' | sed 's/\.c/.o/' | \
	  sort -u | comm -23 - dontlink | \
	  sed 's,../.*/\(.*.o\),rm -f \1;ln -s ../GENERIC/\1 \1,' > makelinks
	echo 'rm -f udiv.o;ln -s ../GENERIC/udiv.o udiv.o' >> makelinks
	echo 'rm -f urem.o;ln -s ../GENERIC/urem.o urem.o' >> makelinks
	sh makelinks && rm -f dontlink

tags:
	@echo "see ../sys/Makefile for tags"

print:
	@pr -f Makefile ../sys/TODO linterrs
	@/usr/ucb/ctags -x ${CFILES} | pr -f -h XREF
	@(size vmunix *.o) | pr -f -h sizes
	@ls -ls | pr -f
	@cd ../h; ls -ls | pr -f ; pr -f *.m *.h
	@echo 'once upon a time ...'
	@cd ../vax; pr -f Locore.c scb.s locore.s
	@cd ../vax/inline; make print
	@pr -f ${CFILES}

ioconf.o: ioconf.c ../h/param.h ../machine/pte.h ../h/buf.h ../h/map.h \
    ../vaxmba/mbavar.h ../h/vm.h ../vaxuba/ubavar.h
	${CC} -c -S ${COPTS} ioconf.c
	${C2} ioconf.s | ../vax/inline/inline | ${AS} -o ioconf.o
	rm -f ioconf.s

param.c: ../conf/param.c
	-rm -f param.c
	cp ../conf/param.c .

param.o: param.c Makefile
	${CC} -c ${CFLAGS} ${PARAM} param.c

af.o: ../net/af.c
	${CC} -c -S ${COPTS} ../net/af.c
	${C2} af.s | ${INLINE} | ${AS} -o af.o
	rm -f af.s

if.o: ../net/if.c
	${CC} -c -S ${COPTS} ../net/if.c
	${C2} if.s | ${INLINE} | ${AS} -o if.o
	rm -f if.s

if_loop.o: ../net/if_loop.c
	${CC} -c -S ${COPTS} ../net/if_loop.c
	${C2} if_loop.s | ${INLINE} | ${AS} -o if_loop.o
	rm -f if_loop.s

raw_cb.o: ../net/raw_cb.c
	${CC} -c -S ${COPTS} ../net/raw_cb.c
	${C2} raw_cb.s | ${INLINE} | ${AS} -o raw_cb.o
	rm -f raw_cb.s

raw_usrreq.o: ../net/raw_usrreq.c
	${CC} -c -S ${COPTS} ../net/raw_usrreq.c
	${C2} raw_usrreq.s | ${INLINE} | ${AS} -o raw_usrreq.o
	rm -f raw_usrreq.s

route.o: ../net/route.c
	${CC} -c -S ${COPTS} ../net/route.c
	${C2} route.s | ${INLINE} | ${AS} -o route.o
	rm -f route.s

if_ether.o: ../netinet/if_ether.c
	${CC} -c -S ${COPTS} ../netinet/if_ether.c
	${C2} if_ether.s | ${INLINE} | ${AS} -o if_ether.o
	rm -f if_ether.s

in.o: ../netinet/in.c
	${CC} -c -S ${COPTS} ../netinet/in.c
	${C2} in.s | ${INLINE} | ${AS} -o in.o
	rm -f in.s

in_pcb.o: ../netinet/in_pcb.c
	${CC} -c -S ${COPTS} ../netinet/in_pcb.c
	${C2} in_pcb.s | ${INLINE} | ${AS} -o in_pcb.o
	rm -f in_pcb.s

in_proto.o: ../netinet/in_proto.c
	${CC} -c -S ${COPTS} ../netinet/in_proto.c
	${C2} in_proto.s | ${INLINE} | ${AS} -o in_proto.o
	rm -f in_proto.s

ip_icmp.o: ../netinet/ip_icmp.c
	${CC} -c -S ${COPTS} ../netinet/ip_icmp.c
	${C2} ip_icmp.s | ${INLINE} | ${AS} -o ip_icmp.o
	rm -f ip_icmp.s

ip_input.o: ../netinet/ip_input.c
	${CC} -c -S ${COPTS} ../netinet/ip_input.c
	${C2} ip_input.s | ${INLINE} | ${AS} -o ip_input.o
	rm -f ip_input.s

ip_output.o: ../netinet/ip_output.c
	${CC} -c -S ${COPTS} ../netinet/ip_output.c
	${C2} ip_output.s | ${INLINE} | ${AS} -o ip_output.o
	rm -f ip_output.s

raw_ip.o: ../netinet/raw_ip.c
	${CC} -c -S ${COPTS} ../netinet/raw_ip.c
	${C2} raw_ip.s | ${INLINE} | ${AS} -o raw_ip.o
	rm -f raw_ip.s

tcp_debug.o: ../netinet/tcp_debug.c
	${CC} -c -S ${COPTS} ../netinet/tcp_debug.c
	${C2} tcp_debug.s | ${INLINE} | ${AS} -o tcp_debug.o
	rm -f tcp_debug.s

tcp_input.o: ../netinet/tcp_input.c
	${CC} -c -S ${COPTS} ../netinet/tcp_input.c
	${C2} tcp_input.s | ${INLINE} | ${AS} -o tcp_input.o
	rm -f tcp_input.s

tcp_output.o: ../netinet/tcp_output.c
	${CC} -c -S ${COPTS} ../netinet/tcp_output.c
	${C2} tcp_output.s | ${INLINE} | ${AS} -o tcp_output.o
	rm -f tcp_output.s

tcp_subr.o: ../netinet/tcp_subr.c
	${CC} -c -S ${COPTS} ../netinet/tcp_subr.c
	${C2} tcp_subr.s | ${INLINE} | ${AS} -o tcp_subr.o
	rm -f tcp_subr.s

tcp_timer.o: ../netinet/tcp_timer.c
	${CC} -c -S ${COPTS} ../netinet/tcp_timer.c
	${C2} tcp_timer.s | ${INLINE} | ${AS} -o tcp_timer.o
	rm -f tcp_timer.s

tcp_usrreq.o: ../netinet/tcp_usrreq.c
	${CC} -c -S ${COPTS} ../netinet/tcp_usrreq.c
	${C2} tcp_usrreq.s | ${INLINE} | ${AS} -o tcp_usrreq.o
	rm -f tcp_usrreq.s

udp_usrreq.o: ../netinet/udp_usrreq.c
	${CC} -c -S ${COPTS} ../netinet/udp_usrreq.c
	${C2} udp_usrreq.s | ${INLINE} | ${AS} -o udp_usrreq.o
	rm -f udp_usrreq.s

idp_usrreq.o: ../netns/idp_usrreq.c
	${CC} -c -S ${COPTS} ../netns/idp_usrreq.c
	${C2} idp_usrreq.s | ${INLINE} | ${AS} -o idp_usrreq.o
	rm -f idp_usrreq.s

ns.o: ../netns/ns.c
	${CC} -c -S ${COPTS} ../netns/ns.c
	${C2} ns.s | ${INLINE} | ${AS} -o ns.o
	rm -f ns.s

ns_error.o: ../netns/ns_error.c
	${CC} -c -S ${COPTS} ../netns/ns_error.c
	${C2} ns_error.s | ${INLINE} | ${AS} -o ns_error.o
	rm -f ns_error.s

ns_ip.o: ../netns/ns_ip.c
	${CC} -c -S ${COPTS} ../netns/ns_ip.c
	${C2} ns_ip.s | ${INLINE} | ${AS} -o ns_ip.o
	rm -f ns_ip.s

ns_input.o: ../netns/ns_input.c
	${CC} -c -S ${COPTS} ../netns/ns_input.c
	${C2} ns_input.s | ${INLINE} | ${AS} -o ns_input.o
	rm -f ns_input.s

ns_output.o: ../netns/ns_output.c
	${CC} -c -S ${COPTS} ../netns/ns_output.c
	${C2} ns_output.s | ${INLINE} | ${AS} -o ns_output.o
	rm -f ns_output.s

ns_pcb.o: ../netns/ns_pcb.c
	${CC} -c -S ${COPTS} ../netns/ns_pcb.c
	${C2} ns_pcb.s | ${INLINE} | ${AS} -o ns_pcb.o
	rm -f ns_pcb.s

ns_proto.o: ../netns/ns_proto.c
	${CC} -c -S ${COPTS} ../netns/ns_proto.c
	${C2} ns_proto.s | ${INLINE} | ${AS} -o ns_proto.o
	rm -f ns_proto.s

spp_debug.o: ../netns/spp_debug.c
	${CC} -c -S ${COPTS} ../netns/spp_debug.c
	${C2} spp_debug.s | ${INLINE} | ${AS} -o spp_debug.o
	rm -f spp_debug.s

spp_usrreq.o: ../netns/spp_usrreq.c
	${CC} -c -S ${COPTS} ../netns/spp_usrreq.c
	${C2} spp_usrreq.s | ${INLINE} | ${AS} -o spp_usrreq.o
	rm -f spp_usrreq.s

init_main.o: ../sys/init_main.c
	${CC} -c -S ${COPTS} ../sys/init_main.c
	${C2} init_main.s | ${INLINE} | ${AS} -o init_main.o
	rm -f init_main.s

init_sysent.o: ../sys/init_sysent.c
	${CC} -c -S ${COPTS} ../sys/init_sysent.c
	${C2} init_sysent.s | ${INLINE} | ${AS} -o init_sysent.o
	rm -f init_sysent.s

kern_acct.o: ../sys/kern_acct.c
	${CC} -c -S ${COPTS} ../sys/kern_acct.c
	${C2} kern_acct.s | ${INLINE} | ${AS} -o kern_acct.o
	rm -f kern_acct.s

kern_clock.o: ../sys/kern_clock.c
	${CC} -c -S ${COPTS} ../sys/kern_clock.c
	${C2} kern_clock.s | ${INLINE} | ${AS} -o kern_clock.o
	rm -f kern_clock.s

kern_descrip.o: ../sys/kern_descrip.c
	${CC} -c -S ${COPTS} ../sys/kern_descrip.c
	${C2} kern_descrip.s | ${INLINE} | ${AS} -o kern_descrip.o
	rm -f kern_descrip.s

kern_exec.o: ../sys/kern_exec.c
	${CC} -c -S ${COPTS} ../sys/kern_exec.c
	${C2} kern_exec.s | ${INLINE} | ${AS} -o kern_exec.o
	rm -f kern_exec.s

kern_exit.o: ../sys/kern_exit.c
	${CC} -c -S ${COPTS} ../sys/kern_exit.c
	${C2} kern_exit.s | ${INLINE} | ${AS} -o kern_exit.o
	rm -f kern_exit.s

kern_fork.o: ../sys/kern_fork.c
	${CC} -c -S ${COPTS} ../sys/kern_fork.c
	${C2} kern_fork.s | ${INLINE} | ${AS} -o kern_fork.o
	rm -f kern_fork.s

kern_malloc.o: ../sys/kern_malloc.c
	${CC} -c -S ${COPTS} ../sys/kern_malloc.c
	${C2} kern_malloc.s | ${INLINE} | ${AS} -o kern_malloc.o
	rm -f kern_malloc.s

kern_mman.o: ../sys/kern_mman.c
	${CC} -c -S ${COPTS} ../sys/kern_mman.c
	${C2} kern_mman.s | ${INLINE} | ${AS} -o kern_mman.o
	rm -f kern_mman.s

kern_proc.o: ../sys/kern_proc.c
	${CC} -c -S ${COPTS} ../sys/kern_proc.c
	${C2} kern_proc.s | ${INLINE} | ${AS} -o kern_proc.o
	rm -f kern_proc.s

kern_prot.o: ../sys/kern_prot.c
	${CC} -c -S ${COPTS} ../sys/kern_prot.c
	${C2} kern_prot.s | ${INLINE} | ${AS} -o kern_prot.o
	rm -f kern_prot.s

kern_resource.o: ../sys/kern_resource.c
	${CC} -c -S ${COPTS} ../sys/kern_resource.c
	${C2} kern_resource.s | ${INLINE} | ${AS} -o kern_resource.o
	rm -f kern_resource.s

kern_sig.o: ../sys/kern_sig.c
	${CC} -c -S ${COPTS} ../sys/kern_sig.c
	${C2} kern_sig.s | ${INLINE} | ${AS} -o kern_sig.o
	rm -f kern_sig.s

kern_subr.o: ../sys/kern_subr.c
	${CC} -c -S ${COPTS} ../sys/kern_subr.c
	${C2} kern_subr.s | ${INLINE} | ${AS} -o kern_subr.o
	rm -f kern_subr.s

kern_synch.o: ../sys/kern_synch.c
	${CC} -c -S ${COPTS} ../sys/kern_synch.c
	${C2} kern_synch.s | ${INLINE} | ${AS} -o kern_synch.o
	rm -f kern_synch.s

kern_time.o: ../sys/kern_time.c
	${CC} -c -S ${COPTS} ../sys/kern_time.c
	${C2} kern_time.s | ${INLINE} | ${AS} -o kern_time.o
	rm -f kern_time.s

kern_xxx.o: ../sys/kern_xxx.c
	${CC} -c -S ${COPTS} ../sys/kern_xxx.c
	${C2} kern_xxx.s | ${INLINE} | ${AS} -o kern_xxx.o
	rm -f kern_xxx.s

quota_kern.o: ../sys/quota_kern.c
	${CC} -c -S ${COPTS} ../sys/quota_kern.c
	${C2} quota_kern.s | ${INLINE} | ${AS} -o quota_kern.o
	rm -f quota_kern.s

quota_subr.o: ../sys/quota_subr.c
	${CC} -c -S ${COPTS} ../sys/quota_subr.c
	${C2} quota_subr.s | ${INLINE} | ${AS} -o quota_subr.o
	rm -f quota_subr.s

quota_sys.o: ../sys/quota_sys.c
	${CC} -c -S ${COPTS} ../sys/quota_sys.c
	${C2} quota_sys.s | ${INLINE} | ${AS} -o quota_sys.o
	rm -f quota_sys.s

quota_ufs.o: ../sys/quota_ufs.c
	${CC} -c -S ${COPTS} ../sys/quota_ufs.c
	${C2} quota_ufs.s | ${INLINE} | ${AS} -o quota_ufs.o
	rm -f quota_ufs.s

subr_log.o: ../sys/subr_log.c
	${CC} -c -S ${COPTS} ../sys/subr_log.c
	${C2} subr_log.s | ${INLINE} | ${AS} -o subr_log.o
	rm -f subr_log.s

subr_prf.o: ../sys/subr_prf.c
	${CC} -c -S ${COPTS} ../sys/subr_prf.c
	${C2} subr_prf.s | ${INLINE} | ${AS} -o subr_prf.o
	rm -f subr_prf.s

subr_rmap.o: ../sys/subr_rmap.c
	${CC} -c -S ${COPTS} ../sys/subr_rmap.c
	${C2} subr_rmap.s | ${INLINE} | ${AS} -o subr_rmap.o
	rm -f subr_rmap.s

subr_xxx.o: ../sys/subr_xxx.c
	${CC} -c -S ${COPTS} ../sys/subr_xxx.c
	${C2} subr_xxx.s | ${INLINE} | ${AS} -o subr_xxx.o
	rm -f subr_xxx.s

sys_generic.o: ../sys/sys_generic.c
	${CC} -c -S ${COPTS} ../sys/sys_generic.c
	${C2} sys_generic.s | ${INLINE} | ${AS} -o sys_generic.o
	rm -f sys_generic.s

sys_inode.o: ../sys/sys_inode.c
	${CC} -c -S ${COPTS} ../sys/sys_inode.c
	${C2} sys_inode.s | ${INLINE} | ${AS} -o sys_inode.o
	rm -f sys_inode.s

sys_process.o: ../sys/sys_process.c
	${CC} -c -S ${COPTS} ../sys/sys_process.c
	${C2} sys_process.s | ${INLINE} | ${AS} -o sys_process.o
	rm -f sys_process.s

sys_socket.o: ../sys/sys_socket.c
	${CC} -c -S ${COPTS} ../sys/sys_socket.c
	${C2} sys_socket.s | ${INLINE} | ${AS} -o sys_socket.o
	rm -f sys_socket.s

tty.o: ../sys/tty.c
	${CC} -c -S ${COPTS} ../sys/tty.c
	${C2} tty.s | ${INLINE} | ${AS} -o tty.o
	rm -f tty.s

tty_conf.o: ../sys/tty_conf.c
	${CC} -c -S ${COPTS} ../sys/tty_conf.c
	${C2} tty_conf.s | ${INLINE} | ${AS} -o tty_conf.o
	rm -f tty_conf.s

tty_pty.o: ../sys/tty_pty.c
	${CC} -c -S ${COPTS} ../sys/tty_pty.c
	${C2} tty_pty.s | ${INLINE} | ${AS} -o tty_pty.o
	rm -f tty_pty.s

tty_subr.o: ../sys/tty_subr.c
	${CC} -c -S ${COPTS} ../sys/tty_subr.c
	${C2} tty_subr.s | ${INLINE} | ${AS} -o tty_subr.o
	rm -f tty_subr.s

tty_tty.o: ../sys/tty_tty.c
	${CC} -c -S ${COPTS} ../sys/tty_tty.c
	${C2} tty_tty.s | ${INLINE} | ${AS} -o tty_tty.o
	rm -f tty_tty.s

ufs_alloc.o: ../sys/ufs_alloc.c
	${CC} -c -S ${COPTS} ../sys/ufs_alloc.c
	${C2} ufs_alloc.s | ${INLINE} | ${AS} -o ufs_alloc.o
	rm -f ufs_alloc.s

ufs_bio.o: ../sys/ufs_bio.c
	${CC} -c -S ${COPTS} ../sys/ufs_bio.c
	${C2} ufs_bio.s | ${INLINE} | ${AS} -o ufs_bio.o
	rm -f ufs_bio.s

ufs_bmap.o: ../sys/ufs_bmap.c
	${CC} -c -S ${COPTS} ../sys/ufs_bmap.c
	${C2} ufs_bmap.s | ${INLINE} | ${AS} -o ufs_bmap.o
	rm -f ufs_bmap.s

ufs_disksubr.o: ../sys/ufs_disksubr.c
	${CC} -c -S ${COPTS} ../sys/ufs_disksubr.c
	${C2} ufs_disksubr.s | ${INLINE} | ${AS} -o ufs_disksubr.o
	rm -f ufs_disksubr.s

ufs_fio.o: ../sys/ufs_fio.c
	${CC} -c -S ${COPTS} ../sys/ufs_fio.c
	${C2} ufs_fio.s | ${INLINE} | ${AS} -o ufs_fio.o
	rm -f ufs_fio.s

ufs_inode.o: ../sys/ufs_inode.c
	${CC} -c -S ${COPTS} ../sys/ufs_inode.c
	${C2} ufs_inode.s | ${INLINE} | ${AS} -o ufs_inode.o
	rm -f ufs_inode.s

ufs_mount.o: ../sys/ufs_mount.c
	${CC} -c -S ${COPTS} ../sys/ufs_mount.c
	${C2} ufs_mount.s | ${INLINE} | ${AS} -o ufs_mount.o
	rm -f ufs_mount.s

ufs_namei.o: ../sys/ufs_namei.c
	${CC} -c -S ${COPTS} ../sys/ufs_namei.c
	${C2} ufs_namei.s | ${INLINE} | ${AS} -o ufs_namei.o
	rm -f ufs_namei.s

ufs_subr.o: ../sys/ufs_subr.c
	${CC} -c -S ${COPTS} ../sys/ufs_subr.c
	${C2} ufs_subr.s | ${INLINE} | ${AS} -o ufs_subr.o
	rm -f ufs_subr.s

ufs_syscalls.o: ../sys/ufs_syscalls.c
	${CC} -c -S ${COPTS} ../sys/ufs_syscalls.c
	${C2} ufs_syscalls.s | ${INLINE} | ${AS} -o ufs_syscalls.o
	rm -f ufs_syscalls.s

ufs_tables.o: ../sys/ufs_tables.c
	${CC} -c -S ${COPTS} ../sys/ufs_tables.c
	${C2} ufs_tables.s | ${INLINE} | ${AS} -o ufs_tables.o
	rm -f ufs_tables.s

ufs_xxx.o: ../sys/ufs_xxx.c
	${CC} -c -S ${COPTS} ../sys/ufs_xxx.c
	${C2} ufs_xxx.s | ${INLINE} | ${AS} -o ufs_xxx.o
	rm -f ufs_xxx.s

uipc_domain.o: ../sys/uipc_domain.c
	${CC} -c -S ${COPTS} ../sys/uipc_domain.c
	${C2} uipc_domain.s | ${INLINE} | ${AS} -o uipc_domain.o
	rm -f uipc_domain.s

uipc_mbuf.o: ../sys/uipc_mbuf.c
	${CC} -c -S ${COPTS} ../sys/uipc_mbuf.c
	${C2} uipc_mbuf.s | ${INLINE} | ${AS} -o uipc_mbuf.o
	rm -f uipc_mbuf.s

uipc_proto.o: ../sys/uipc_proto.c
	${CC} -c -S ${COPTS} ../sys/uipc_proto.c
	${C2} uipc_proto.s | ${INLINE} | ${AS} -o uipc_proto.o
	rm -f uipc_proto.s

uipc_socket.o: ../sys/uipc_socket.c
	${CC} -c -S ${COPTS} ../sys/uipc_socket.c
	${C2} uipc_socket.s | ${INLINE} | ${AS} -o uipc_socket.o
	rm -f uipc_socket.s

uipc_socket2.o: ../sys/uipc_socket2.c
	${CC} -c -S ${COPTS} ../sys/uipc_socket2.c
	${C2} uipc_socket2.s | ${INLINE} | ${AS} -o uipc_socket2.o
	rm -f uipc_socket2.s

uipc_syscalls.o: ../sys/uipc_syscalls.c
	${CC} -c -S ${COPTS} ../sys/uipc_syscalls.c
	${C2} uipc_syscalls.s | ${INLINE} | ${AS} -o uipc_syscalls.o
	rm -f uipc_syscalls.s

uipc_usrreq.o: ../sys/uipc_usrreq.c
	${CC} -c -S ${COPTS} ../sys/uipc_usrreq.c
	${C2} uipc_usrreq.s | ${INLINE} | ${AS} -o uipc_usrreq.o
	rm -f uipc_usrreq.s

vm_drum.o: ../sys/vm_drum.c
	${CC} -c -S ${COPTS} ../sys/vm_drum.c
	${C2} vm_drum.s | ${INLINE} | ${AS} -o vm_drum.o
	rm -f vm_drum.s

vm_mem.o: ../sys/vm_mem.c
	${CC} -c -S ${COPTS} ../sys/vm_mem.c
	${C2} vm_mem.s | ${INLINE} | ${AS} -o vm_mem.o
	rm -f vm_mem.s

vm_mon.o: ../sys/vm_mon.c
	${CC} -c -S ${COPTS} ../sys/vm_mon.c
	${C2} vm_mon.s | ${INLINE} | ${AS} -o vm_mon.o
	rm -f vm_mon.s

vm_page.o: ../sys/vm_page.c
	${CC} -c -S ${COPTS} ../sys/vm_page.c
	${C2} vm_page.s | ${INLINE} | ${AS} -o vm_page.o
	rm -f vm_page.s

vm_proc.o: ../sys/vm_proc.c
	${CC} -c -S ${COPTS} ../sys/vm_proc.c
	${C2} vm_proc.s | ${INLINE} | ${AS} -o vm_proc.o
	rm -f vm_proc.s

vm_pt.o: ../sys/vm_pt.c
	${CC} -c -S ${COPTS} ../sys/vm_pt.c
	${C2} vm_pt.s | ${INLINE} | ${AS} -o vm_pt.o
	rm -f vm_pt.s

vm_sched.o: ../sys/vm_sched.c
	${CC} -c -S ${COPTS} ../sys/vm_sched.c
	${C2} vm_sched.s | ${INLINE} | ${AS} -o vm_sched.o
	rm -f vm_sched.s

vm_subr.o: ../sys/vm_subr.c
	${CC} -c -S ${COPTS} ../sys/vm_subr.c
	${C2} vm_subr.s | ${INLINE} | ${AS} -o vm_subr.o
	rm -f vm_subr.s

vm_sw.o: ../sys/vm_sw.c
	${CC} -c -S ${COPTS} ../sys/vm_sw.c
	${C2} vm_sw.s | ${INLINE} | ${AS} -o vm_sw.o
	rm -f vm_sw.s

vm_swap.o: ../sys/vm_swap.c
	${CC} -c -S ${COPTS} ../sys/vm_swap.c
	${C2} vm_swap.s | ${INLINE} | ${AS} -o vm_swap.o
	rm -f vm_swap.s

vm_swp.o: ../sys/vm_swp.c
	${CC} -c -S ${COPTS} ../sys/vm_swp.c
	${C2} vm_swp.s | ${INLINE} | ${AS} -o vm_swp.o
	rm -f vm_swp.s

vm_text.o: ../sys/vm_text.c
	${CC} -c -S ${COPTS} ../sys/vm_text.c
	${C2} vm_text.s | ${INLINE} | ${AS} -o vm_text.o
	rm -f vm_text.s

autoconf.o: ../vax/autoconf.c
	${CC} -c -S ${COPTS} ../vax/autoconf.c
	${C2} -i autoconf.s | ${INLINE} | ${AS} -o autoconf.o
	rm -f autoconf.s

clock.o: ../vax/clock.c
	${CC} -c -S ${COPTS} ../vax/clock.c
	${C2} clock.s | ${INLINE} | ${AS} -o clock.o
	rm -f clock.s

conf.o: ../vax/conf.c
	${CC} -c -S ${COPTS} ../vax/conf.c
	${C2} conf.s | ${INLINE} | ${AS} -o conf.o
	rm -f conf.s

cons.o: ../vax/cons.c
	${CC} -c -S ${COPTS} ../vax/cons.c
	${C2} cons.s | ${INLINE} | ${AS} -o cons.o
	rm -f cons.s

cpudata.o: ../vax/cpudata.c
	${CC} -c -S ${COPTS} ../vax/cpudata.c
	${C2} cpudata.s | ${INLINE} | ${AS} -o cpudata.o
	rm -f cpudata.s

crl.o: ../vax/crl.c
	${CC} -c -S ${COPTS} ../vax/crl.c
	${C2} crl.s | ${INLINE} | ${AS} -o crl.o
	rm -f crl.s

dkbad.o: ../vax/dkbad.c
	${CC} -c -S ${COPTS} ../vax/dkbad.c
	${C2} dkbad.s | ${INLINE} | ${AS} -o dkbad.o
	rm -f dkbad.s

flp.o: ../vax/flp.c
	${CC} -c -S ${COPTS} ../vax/flp.c
	${C2} flp.s | ${INLINE} | ${AS} -o flp.o
	rm -f flp.s

in_cksum.o: ../vax/in_cksum.c
	${CC} -c -S ${COPTS} ../vax/in_cksum.c
	${C2} in_cksum.s | ${INLINE} | ${AS} -o in_cksum.o
	rm -f in_cksum.s

ka650.o: ../vax/ka650.c
	${CC} -c -S ${COPTS} ../vax/ka650.c
	${C2} ka650.s | ${INLINE} | ${AS} -o ka650.o
	rm -f ka650.s

ka630.o: ../vax/ka630.c
	${CC} -c -S ${COPTS} ../vax/ka630.c
	${C2} ka630.s | ${INLINE} | ${AS} -o ka630.o
	rm -f ka630.s

ka730.o: ../vax/ka730.c
	${CC} -c -S ${COPTS} ../vax/ka730.c
	${C2} ka730.s | ${INLINE} | ${AS} -o ka730.o
	rm -f ka730.s

ka750.o: ../vax/ka750.c
	${CC} -c -S ${COPTS} ../vax/ka750.c
	${C2} ka750.s | ${INLINE} | ${AS} -o ka750.o
	rm -f ka750.s

ka780.o: ../vax/ka780.c
	${CC} -c -S ${COPTS} ../vax/ka780.c
	${C2} ka780.s | ${INLINE} | ${AS} -o ka780.o
	rm -f ka780.s

ka820.o: ../vax/ka820.c
	${CC} -c -S ${COPTS} ../vax/ka820.c
	${C2} ka820.s | ${INLINE} | ${AS} -o ka820.o
	rm -f ka820.s

ka860.o: ../vax/ka860.c
	${CC} -c -S ${COPTS} ../vax/ka860.c
	${C2} ka860.s | ${INLINE} | ${AS} -o ka860.o
	rm -f ka860.s

machdep.o: ../vax/machdep.c
	${CC} -c -S ${COPTS} ${PARAM} ../vax/machdep.c
	${C2} machdep.s | ${INLINE} | ${AS} -o machdep.o
	rm -f machdep.s

mem.o: ../vax/mem.c
	${CC} -c -S ${COPTS} ../vax/mem.c
	${C2} mem.s | ${INLINE} | ${AS} -o mem.o
	rm -f mem.s

mscp.o: ../vax/mscp.c
	${CC} -c -S ${COPTS} ../vax/mscp.c
	${C2} mscp.s | ${INLINE} | ${AS} -o mscp.o
	rm -f mscp.s

ns_cksum.o: ../vax/ns_cksum.c
	${CC} -c -S ${COPTS} ../vax/ns_cksum.c
	${C2} ns_cksum.s | ${INLINE} | ${AS} -o ns_cksum.o
	rm -f ns_cksum.s

rx50.o: ../vax/rx50.c
	${CC} -c -S ${COPTS} ../vax/rx50.c
	${C2} -i rx50.s | ${INLINE} | ${AS} -o rx50.o
	rm -f rx50.s

sys_machdep.o: ../vax/sys_machdep.c
	${CC} -c -S ${COPTS} ../vax/sys_machdep.c
	${C2} sys_machdep.s | ${INLINE} | ${AS} -o sys_machdep.o
	rm -f sys_machdep.s

trap.o: ../vax/trap.c
	${CC} -c -S ${COPTS} ../vax/trap.c
	${C2} trap.s | ${INLINE} | ${AS} -o trap.o
	rm -f trap.s

tu.o: ../vax/tu.c
	${CC} -c -S ${COPTS} ../vax/tu.c
	${C2} tu.s | ${INLINE} | ${AS} -o tu.o
	rm -f tu.s

udiv.o: ../vax/udiv.s
	-ln -s ../vax/udiv.s udiv.c
	${CC} -E ${COPTS} udiv.c | ${AS} -o udiv.o
	rm -f udiv.c

ufs_machdep.o: ../vax/ufs_machdep.c
	${CC} -c -S ${COPTS} ../vax/ufs_machdep.c
	${C2} ufs_machdep.s | ${INLINE} | ${AS} -o ufs_machdep.o
	rm -f ufs_machdep.s

urem.o: ../vax/urem.s
	-ln -s ../vax/urem.s urem.c
	${CC} -E ${COPTS} urem.c | ${AS} -o urem.o
	rm -f urem.c

vm_machdep.o: ../vax/vm_machdep.c
	${CC} -c -S ${COPTS} ../vax/vm_machdep.c
	${C2} vm_machdep.s | ${INLINE} | ${AS} -o vm_machdep.o
	rm -f vm_machdep.s

bi.o: ../vaxbi/bi.c
	${CC} -c -S ${COPTS} ../vaxbi/bi.c
	${C2} -i bi.s | ${INLINE} | ${AS} -o bi.o
	rm -f bi.s

kdb.o: ../vaxbi/kdb.c
	${CC} -c -S ${COPTS} ../vaxbi/kdb.c
	${C2} -i kdb.s | ${INLINE} | ${AS} -o kdb.o
	rm -f kdb.s

if_de.o: ../vaxif/if_de.c
	${CC} -c -S ${COPTS} ../vaxif/if_de.c
	${C2} -i if_de.s | ${INLINE} | ${AS} -o if_de.o
	rm -f if_de.s

if_ec.o: ../vaxif/if_ec.c
	${CC} -c -S ${COPTS} ../vaxif/if_ec.c
	${C2} -i if_ec.s | ${INLINE} | ${AS} -o if_ec.o
	rm -f if_ec.s

if_ex.o: ../vaxif/if_ex.c
	${CC} -c -S ${COPTS} ../vaxif/if_ex.c
	${C2} -i if_ex.s | ${INLINE} | ${AS} -o if_ex.o
	rm -f if_ex.s

if_il.o: ../vaxif/if_il.c
	${CC} -c -S ${COPTS} ../vaxif/if_il.c
	${C2} -i if_il.s | ${INLINE} | ${AS} -o if_il.o
	rm -f if_il.s

if_qe.o: ../vaxif/if_qe.c
	${CC} -c -S ${COPTS} ../vaxif/if_qe.c
	${C2} -i if_qe.s | ${INLINE} | ${AS} -o if_qe.o
	rm -f if_qe.s

if_uba.o: ../vaxif/if_uba.c
	${CC} -c -S ${COPTS} ../vaxif/if_uba.c
	${C2} -i if_uba.s | ${INLINE} | ${AS} -o if_uba.o
	rm -f if_uba.s

hp.o: ../vaxmba/hp.c
	${CC} -c -S ${COPTS} ../vaxmba/hp.c
	${C2} -i hp.s | ${INLINE} | ${AS} -o hp.o
	rm -f hp.s

ht.o: ../vaxmba/ht.c
	${CC} -c -S ${COPTS} ../vaxmba/ht.c
	${C2} -i ht.s | ${INLINE} | ${AS} -o ht.o
	rm -f ht.s

mba.o: ../vaxmba/mba.c
	${CC} -c -S ${COPTS} ../vaxmba/mba.c
	${C2} -i mba.s | ${INLINE} | ${AS} -o mba.o
	rm -f mba.s

mt.o: ../vaxmba/mt.c
	${CC} -c -S ${COPTS} ../vaxmba/mt.c
	${C2} -i mt.s | ${INLINE} | ${AS} -o mt.o
	rm -f mt.s

dh.o: ../vaxuba/dh.c
	${CC} -c -S ${COPTS} ../vaxuba/dh.c
	${C2} -i dh.s | ${INLINE} | ${AS} -o dh.o
	rm -f dh.s

dhu.o: ../vaxuba/dhu.c
	${CC} -c -S ${COPTS} ../vaxuba/dhu.c
	${C2} -i dhu.s | ${INLINE} | ${AS} -o dhu.o
	rm -f dhu.s

dmf.o: ../vaxuba/dmf.c
	${CC} -c -S ${COPTS} ../vaxuba/dmf.c
	${C2} -i dmf.s | ${INLINE} | ${AS} -o dmf.o
	rm -f dmf.s

dmx.o: ../vaxuba/dmx.c
	${CC} -c -S ${COPTS} ../vaxuba/dmx.c
	${C2} -i dmx.s | ${INLINE} | ${AS} -o dmx.o
	rm -f dmx.s

dmz.o: ../vaxuba/dmz.c
	${CC} -c -S ${COPTS} ../vaxuba/dmz.c
	${C2} -i dmz.s | ${INLINE} | ${AS} -o dmz.o
	rm -f dmz.s

dz.o: ../vaxuba/dz.c
	${CC} -c -S ${COPTS} ../vaxuba/dz.c
	${C2} -i dz.s | ${INLINE} | ${AS} -o dz.o
	rm -f dz.s

idc.o: ../vaxuba/idc.c
	${CC} -c -S ${COPTS} ../vaxuba/idc.c
	${C2} -i idc.s | ${INLINE} | ${AS} -o idc.o
	rm -f idc.s

lp.o: ../vaxuba/lp.c
	${CC} -c -S ${COPTS} ../vaxuba/lp.c
	${C2} -i lp.s | ${INLINE} | ${AS} -o lp.o
	rm -f lp.s

rk.o: ../vaxuba/rk.c
	${CC} -c -S ${COPTS} ../vaxuba/rk.c
	${C2} -i rk.s | ${INLINE} | ${AS} -o rk.o
	rm -f rk.s

rl.o: ../vaxuba/rl.c
	${CC} -c -S ${COPTS} ../vaxuba/rl.c
	${C2} -i rl.s | ${INLINE} | ${AS} -o rl.o
	rm -f rl.s

tm.o: ../vaxuba/tm.c
	${CC} -c -S ${COPTS} ../vaxuba/tm.c
	${C2} -i tm.s | ${INLINE} | ${AS} -o tm.o
	rm -f tm.s

tmscp.o: ../vaxuba/tmscp.c
	${CC} -c -S ${COPTS} ../vaxuba/tmscp.c
	${C2} -i tmscp.s | ${INLINE} | ${AS} -o tmscp.o
	rm -f tmscp.s

ts.o: ../vaxuba/ts.c
	${CC} -c -S ${COPTS} ../vaxuba/ts.c
	${C2} -i ts.s | ${INLINE} | ${AS} -o ts.o
	rm -f ts.s

uba.o: ../vaxuba/uba.c
	${CC} -c -S ${COPTS} ../vaxuba/uba.c
	${C2} -i uba.s | ${INLINE} | ${AS} -o uba.o
	rm -f uba.s

uda.o: ../vaxuba/uda.c
	${CC} -c -S ${COPTS} ../vaxuba/uda.c
	${C2} -i uda.s | ${INLINE} | ${AS} -o uda.o
	rm -f uda.s

up.o: ../vaxuba/up.c
	${CC} -c -S ${COPTS} ../vaxuba/up.c
	${C2} -i up.s | ${INLINE} | ${AS} -o up.o
	rm -f up.s

ut.o: ../vaxuba/ut.c
	${CC} -c -S ${COPTS} ../vaxuba/ut.c
	${C2} -i ut.s | ${INLINE} | ${AS} -o ut.o
	rm -f ut.s

qv.o: ../vaxuba/qv.c
	${CC} -c -S ${COPTS} ../vaxuba/qv.c
	${C2} -i qv.s | ${INLINE} | ${AS} -o qv.o
	rm -f qv.s

qfont.o: ../vaxuba/qfont.c
	${CC} -c -S ${COPTS} ../vaxuba/qfont.c
	${C2} -i qfont.s | ${INLINE} | ${AS} -o qfont.o
	rm -f qfont.s

qd.o: ../vaxuba/qd.c
	${CC} -c -S ${COPTS} ../vaxuba/qd.c
	${C2} -i qd.s | ${INLINE} | ${AS} -o qd.o
	rm -f qd.s


# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

af.o: ../net/af.c ../h/param.h ../h/types.h ../h/signal.h
af.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
af.o: ../h/mbuf.h ../h/protosw.h ../h/socket.h ../h/socketvar.h ../net/af.h
if.o: ../net/if.c ../h/param.h ../h/types.h ../h/signal.h
if.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
if.o: ../h/mbuf.h ../h/systm.h ../h/socket.h ../h/socketvar.h ../h/protosw.h
if.o: ../h/dir.h ../h/user.h ../h/../machine/pcb.h ../h/dmap.h ../h/time.h
if.o: ../h/resource.h ../h/namei.h ../h/uio.h ../h/errno.h ../h/kernel.h
if.o: ../h/ioctl.h ../h/ttychars.h ../h/ttydev.h ../h/errno.h ../net/if.h
if.o: ../net/../net/if_arp.h ../net/af.h ether.h
if_loop.o: ../net/if_loop.c ../h/param.h ../h/types.h ../h/signal.h
if_loop.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
if_loop.o: ../h/systm.h ../h/mbuf.h ../h/socket.h ../h/errno.h ../h/ioctl.h
if_loop.o: ../h/ttychars.h ../h/ttydev.h ../net/../net/if.h
if_loop.o: ../net/../net/../net/if_arp.h ../net/../net/netisr.h
if_loop.o: ../net/../net/route.h ../net/../machine/mtpr.h
if_loop.o: ../net/../netinet/in.h ../net/../netinet/in_systm.h
if_loop.o: ../net/../netinet/in_var.h ../net/../netinet/ip.h
if_loop.o: ../net/../netns/ns.h ../net/../netns/ns_if.h
raw_cb.o: ../net/raw_cb.c ../h/param.h ../h/types.h ../h/signal.h
raw_cb.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
raw_cb.o: ../h/systm.h ../h/mbuf.h ../h/socket.h ../h/socketvar.h ../h/domain.h
raw_cb.o: ../h/protosw.h ../h/errno.h ../net/if.h ../net/../net/if_arp.h
raw_cb.o: ../net/route.h ../net/raw_cb.h ../net/../netinet/in.h
raw_cb.o: ../net/../machine/mtpr.h
raw_usrreq.o: ../net/raw_usrreq.c ../h/param.h ../h/types.h ../h/signal.h
raw_usrreq.o: ../h/../machine/trap.h ../h/../machine/machparam.h
raw_usrreq.o: machine/endian.h ../h/mbuf.h ../h/domain.h ../h/protosw.h
raw_usrreq.o: ../h/socket.h ../h/socketvar.h ../h/errno.h ../net/if.h
raw_usrreq.o: ../net/../net/if_arp.h ../net/route.h ../net/netisr.h
raw_usrreq.o: ../net/raw_cb.h ../net/../machine/mtpr.h
route.o: ../net/route.c ../h/param.h ../h/types.h ../h/signal.h
route.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
route.o: ../h/systm.h ../h/mbuf.h ../h/protosw.h ../h/socket.h ../h/dir.h
route.o: ../h/user.h ../h/../machine/pcb.h ../h/dmap.h ../h/time.h
route.o: ../h/resource.h ../h/namei.h ../h/uio.h ../h/errno.h ../h/ioctl.h
route.o: ../h/ttychars.h ../h/ttydev.h ../h/errno.h ../net/if.h
route.o: ../net/../net/if_arp.h ../net/af.h ../net/route.h
if_ether.o: ../netinet/if_ether.c ../h/param.h ../h/types.h ../h/signal.h
if_ether.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
if_ether.o: ../h/systm.h ../h/mbuf.h ../h/socket.h ../h/time.h ../h/kernel.h
if_ether.o: ../h/errno.h ../h/ioctl.h ../h/ttychars.h ../h/ttydev.h
if_ether.o: ../h/syslog.h ../netinet/../net/if.h
if_ether.o: ../netinet/../net/../net/if_arp.h ../netinet/in.h
if_ether.o: ../netinet/in_systm.h ../netinet/ip.h ../netinet/if_ether.h
in.o: ../netinet/in.c ../h/param.h ../h/types.h ../h/signal.h
in.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
in.o: ../h/ioctl.h ../h/ttychars.h ../h/ttydev.h ../h/mbuf.h ../h/protosw.h
in.o: ../h/socket.h ../h/socketvar.h ../h/uio.h ../h/dir.h ../h/user.h
in.o: ../h/../machine/pcb.h ../h/dmap.h ../h/time.h ../h/resource.h
in.o: ../h/namei.h ../h/uio.h ../h/errno.h ../netinet/in_systm.h
in.o: ../netinet/../net/if.h ../netinet/../net/../net/if_arp.h
in.o: ../netinet/../net/route.h ../netinet/../net/af.h ../netinet/in.h
in.o: ../netinet/in_var.h
in_pcb.o: ../netinet/in_pcb.c ../h/param.h ../h/types.h ../h/signal.h
in_pcb.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
in_pcb.o: ../h/systm.h ../h/dir.h ../h/user.h ../h/../machine/pcb.h ../h/dmap.h
in_pcb.o: ../h/time.h ../h/resource.h ../h/namei.h ../h/uio.h ../h/errno.h
in_pcb.o: ../h/mbuf.h ../h/socket.h ../h/socketvar.h ../h/ioctl.h
in_pcb.o: ../h/ttychars.h ../h/ttydev.h ../netinet/in.h ../netinet/in_systm.h
in_pcb.o: ../netinet/../net/if.h ../netinet/../net/../net/if_arp.h
in_pcb.o: ../netinet/../net/route.h ../netinet/in_pcb.h ../netinet/in_var.h
in_pcb.o: ../h/protosw.h
in_proto.o: ../netinet/in_proto.c ../h/param.h ../h/types.h ../h/signal.h
in_proto.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
in_proto.o: ../h/socket.h ../h/protosw.h ../h/domain.h ../h/mbuf.h
in_proto.o: ../netinet/in.h ../netinet/in_systm.h imp.h hy.h
ip_icmp.o: ../netinet/ip_icmp.c ../h/param.h ../h/types.h ../h/signal.h
ip_icmp.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
ip_icmp.o: ../h/systm.h ../h/mbuf.h ../h/protosw.h ../h/socket.h ../h/time.h
ip_icmp.o: ../h/kernel.h ../netinet/../net/route.h ../netinet/../net/if.h
ip_icmp.o: ../netinet/../net/../net/if_arp.h ../netinet/in.h
ip_icmp.o: ../netinet/in_systm.h ../netinet/in_var.h ../netinet/ip.h
ip_icmp.o: ../netinet/ip_icmp.h ../netinet/icmp_var.h
ip_input.o: ../netinet/ip_input.c ../h/param.h ../h/types.h ../h/signal.h
ip_input.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
ip_input.o: ../h/systm.h ../h/mbuf.h ../h/domain.h ../h/protosw.h ../h/socket.h
ip_input.o: ../h/errno.h ../h/time.h ../h/kernel.h ../netinet/../net/if.h
ip_input.o: ../netinet/../net/../net/if_arp.h ../netinet/../net/route.h
ip_input.o: ../netinet/in.h ../netinet/in_pcb.h ../netinet/in_systm.h
ip_input.o: ../netinet/in_var.h ../netinet/ip.h ../netinet/ip_var.h
ip_input.o: ../netinet/ip_icmp.h ../netinet/tcp.h
ip_output.o: ../netinet/ip_output.c ../h/param.h ../h/types.h ../h/signal.h
ip_output.o: ../h/../machine/trap.h ../h/../machine/machparam.h
ip_output.o: machine/endian.h ../h/mbuf.h ../h/errno.h ../h/protosw.h
ip_output.o: ../h/socket.h ../h/socketvar.h ../netinet/../net/if.h
ip_output.o: ../netinet/../net/../net/if_arp.h ../netinet/../net/route.h
ip_output.o: ../netinet/in.h ../netinet/in_pcb.h ../netinet/in_systm.h
ip_output.o: ../netinet/in_var.h ../netinet/ip.h ../netinet/ip_var.h
ip_output.o: ../netinet/../machine/mtpr.h
raw_ip.o: ../netinet/raw_ip.c ../h/param.h ../h/types.h ../h/signal.h
raw_ip.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
raw_ip.o: ../h/mbuf.h ../h/socket.h ../h/protosw.h ../h/socketvar.h
raw_ip.o: ../h/errno.h ../netinet/../net/if.h ../netinet/../net/../net/if_arp.h
raw_ip.o: ../netinet/../net/route.h ../netinet/../net/raw_cb.h ../netinet/in.h
raw_ip.o: ../netinet/in_systm.h ../netinet/ip.h ../netinet/ip_var.h
tcp_debug.o: ../netinet/tcp_debug.c ../h/param.h ../h/types.h ../h/signal.h
tcp_debug.o: ../h/../machine/trap.h ../h/../machine/machparam.h
tcp_debug.o: machine/endian.h ../h/systm.h ../h/mbuf.h ../h/socket.h
tcp_debug.o: ../h/socketvar.h ../h/protosw.h ../h/errno.h
tcp_debug.o: ../netinet/../net/route.h ../netinet/../net/if.h
tcp_debug.o: ../netinet/../net/../net/if_arp.h ../netinet/in.h
tcp_debug.o: ../netinet/in_pcb.h ../netinet/in_systm.h ../netinet/ip.h
tcp_debug.o: ../netinet/ip_var.h ../netinet/tcp.h ../netinet/tcp_fsm.h
tcp_debug.o: ../netinet/tcp_seq.h ../netinet/tcp_timer.h ../netinet/tcp_var.h
tcp_debug.o: ../netinet/tcpip.h ../netinet/tcp_debug.h
tcp_input.o: ../netinet/tcp_input.c ../h/param.h ../h/types.h ../h/signal.h
tcp_input.o: ../h/../machine/trap.h ../h/../machine/machparam.h
tcp_input.o: machine/endian.h ../h/systm.h ../h/mbuf.h ../h/protosw.h
tcp_input.o: ../h/socket.h ../h/socketvar.h ../h/errno.h ../netinet/../net/if.h
tcp_input.o: ../netinet/../net/../net/if_arp.h ../netinet/../net/route.h
tcp_input.o: ../netinet/in.h ../netinet/in_pcb.h ../netinet/in_systm.h
tcp_input.o: ../netinet/ip.h ../netinet/ip_var.h ../netinet/tcp.h
tcp_input.o: ../netinet/tcp_fsm.h ../netinet/tcp_seq.h ../netinet/tcp_timer.h
tcp_input.o: ../netinet/tcp_var.h ../netinet/tcpip.h ../netinet/tcp_debug.h
tcp_output.o: ../netinet/tcp_output.c ../h/param.h ../h/types.h ../h/signal.h
tcp_output.o: ../h/../machine/trap.h ../h/../machine/machparam.h
tcp_output.o: machine/endian.h ../h/systm.h ../h/mbuf.h ../h/protosw.h
tcp_output.o: ../h/socket.h ../h/socketvar.h ../h/errno.h
tcp_output.o: ../netinet/../net/route.h ../netinet/in.h ../netinet/in_pcb.h
tcp_output.o: ../netinet/in_systm.h ../netinet/ip.h ../netinet/ip_var.h
tcp_output.o: ../netinet/tcp.h ../netinet/tcp_fsm.h ../netinet/tcp_seq.h
tcp_output.o: ../netinet/tcp_timer.h ../netinet/tcp_var.h ../netinet/tcpip.h
tcp_output.o: ../netinet/tcp_debug.h
tcp_subr.o: ../netinet/tcp_subr.c ../h/param.h ../h/types.h ../h/signal.h
tcp_subr.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
tcp_subr.o: ../h/systm.h ../h/mbuf.h ../h/socket.h ../h/socketvar.h
tcp_subr.o: ../h/protosw.h ../h/errno.h ../netinet/../net/route.h
tcp_subr.o: ../netinet/../net/if.h ../netinet/../net/../net/if_arp.h
tcp_subr.o: ../netinet/in.h ../netinet/in_pcb.h ../netinet/in_systm.h
tcp_subr.o: ../netinet/ip.h ../netinet/ip_var.h ../netinet/ip_icmp.h
tcp_subr.o: ../netinet/tcp.h ../netinet/tcp_fsm.h ../netinet/tcp_seq.h
tcp_subr.o: ../netinet/tcp_timer.h ../netinet/tcp_var.h ../netinet/tcpip.h
tcp_timer.o: ../netinet/tcp_timer.c ../h/param.h ../h/types.h ../h/signal.h
tcp_timer.o: ../h/../machine/trap.h ../h/../machine/machparam.h
tcp_timer.o: machine/endian.h ../h/systm.h ../h/mbuf.h ../h/socket.h
tcp_timer.o: ../h/socketvar.h ../h/protosw.h ../h/errno.h
tcp_timer.o: ../netinet/../net/if.h ../netinet/../net/../net/if_arp.h
tcp_timer.o: ../netinet/../net/route.h ../netinet/in.h ../netinet/in_pcb.h
tcp_timer.o: ../netinet/in_systm.h ../netinet/ip.h ../netinet/ip_var.h
tcp_timer.o: ../netinet/tcp.h ../netinet/tcp_fsm.h ../netinet/tcp_seq.h
tcp_timer.o: ../netinet/tcp_timer.h ../netinet/tcp_var.h ../netinet/tcpip.h
tcp_usrreq.o: ../netinet/tcp_usrreq.c ../h/param.h ../h/types.h ../h/signal.h
tcp_usrreq.o: ../h/../machine/trap.h ../h/../machine/machparam.h
tcp_usrreq.o: machine/endian.h ../h/systm.h ../h/mbuf.h ../h/socket.h
tcp_usrreq.o: ../h/socketvar.h ../h/protosw.h ../h/errno.h ../h/stat.h
tcp_usrreq.o: ../netinet/../net/if.h ../netinet/../net/../net/if_arp.h
tcp_usrreq.o: ../netinet/../net/route.h ../netinet/in.h ../netinet/in_pcb.h
tcp_usrreq.o: ../netinet/in_systm.h ../netinet/ip.h ../netinet/ip_var.h
tcp_usrreq.o: ../netinet/tcp.h ../netinet/tcp_fsm.h ../netinet/tcp_seq.h
tcp_usrreq.o: ../netinet/tcp_timer.h ../netinet/tcp_var.h ../netinet/tcpip.h
tcp_usrreq.o: ../netinet/tcp_debug.h
udp_usrreq.o: ../netinet/udp_usrreq.c ../h/param.h ../h/types.h ../h/signal.h
udp_usrreq.o: ../h/../machine/trap.h ../h/../machine/machparam.h
udp_usrreq.o: machine/endian.h ../h/dir.h ../h/user.h ../h/../machine/pcb.h
udp_usrreq.o: ../h/dmap.h ../h/time.h ../h/resource.h ../h/namei.h ../h/uio.h
udp_usrreq.o: ../h/errno.h ../h/mbuf.h ../h/protosw.h ../h/socket.h
udp_usrreq.o: ../h/socketvar.h ../h/errno.h ../h/stat.h ../netinet/../net/if.h
udp_usrreq.o: ../netinet/../net/../net/if_arp.h ../netinet/../net/route.h
udp_usrreq.o: ../netinet/in.h ../netinet/in_pcb.h ../netinet/in_systm.h
udp_usrreq.o: ../netinet/ip.h ../netinet/ip_var.h ../netinet/ip_icmp.h
udp_usrreq.o: ../netinet/udp.h ../netinet/udp_var.h
idp_usrreq.o: ../netns/idp_usrreq.c ../h/param.h ../h/types.h ../h/signal.h
idp_usrreq.o: ../h/../machine/trap.h ../h/../machine/machparam.h
idp_usrreq.o: machine/endian.h ../h/dir.h ../h/user.h ../h/../machine/pcb.h
idp_usrreq.o: ../h/dmap.h ../h/time.h ../h/resource.h ../h/namei.h ../h/uio.h
idp_usrreq.o: ../h/errno.h ../h/mbuf.h ../h/protosw.h ../h/socket.h
idp_usrreq.o: ../h/socketvar.h ../h/errno.h ../h/stat.h ../netns/../net/if.h
idp_usrreq.o: ../netns/../net/../net/if_arp.h ../netns/../net/route.h
idp_usrreq.o: ../netns/ns.h ../netns/ns_pcb.h ../netns/ns_if.h ../netns/idp.h
idp_usrreq.o: ../netns/idp_var.h ../netns/ns_error.h
ns.o: ../netns/ns.c ../h/param.h ../h/types.h ../h/signal.h
ns.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
ns.o: ../h/mbuf.h ../h/ioctl.h ../h/ttychars.h ../h/ttydev.h ../h/protosw.h
ns.o: ../h/socket.h ../h/socketvar.h ../h/uio.h ../h/dir.h ../h/user.h
ns.o: ../h/../machine/pcb.h ../h/dmap.h ../h/time.h ../h/resource.h
ns.o: ../h/namei.h ../h/uio.h ../h/errno.h ../netns/../net/if.h
ns.o: ../netns/../net/../net/if_arp.h ../netns/../net/route.h
ns.o: ../netns/../net/af.h ../netns/ns.h ../netns/ns_if.h
ns_error.o: ../netns/ns_error.c ../h/param.h ../h/types.h ../h/signal.h
ns_error.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
ns_error.o: ../h/systm.h ../h/mbuf.h ../h/protosw.h ../h/socket.h ../h/time.h
ns_error.o: ../h/kernel.h ../netns/../net/route.h ../netns/ns.h
ns_error.o: ../netns/ns_pcb.h ../netns/idp.h ../netns/ns_error.h
ns_ip.o: ../netns/ns_ip.c
ns_input.o: ../netns/ns_input.c ../h/param.h ../h/types.h ../h/signal.h
ns_input.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
ns_input.o: ../h/systm.h ../h/mbuf.h ../h/domain.h ../h/protosw.h ../h/socket.h
ns_input.o: ../h/socketvar.h ../h/errno.h ../h/time.h ../h/kernel.h
ns_input.o: ../netns/../net/if.h ../netns/../net/../net/if_arp.h
ns_input.o: ../netns/../net/route.h ../netns/../net/raw_cb.h ../netns/ns.h
ns_input.o: ../netns/ns_if.h ../netns/ns_pcb.h ../netns/idp.h
ns_input.o: ../netns/idp_var.h ../netns/ns_error.h
ns_output.o: ../netns/ns_output.c ../h/param.h ../h/types.h ../h/signal.h
ns_output.o: ../h/../machine/trap.h ../h/../machine/machparam.h
ns_output.o: machine/endian.h ../h/mbuf.h ../h/errno.h ../h/socket.h
ns_output.o: ../h/socketvar.h ../netns/../net/if.h
ns_output.o: ../netns/../net/../net/if_arp.h ../netns/../net/route.h
ns_output.o: ../netns/ns.h ../netns/ns_if.h ../netns/idp.h ../netns/idp_var.h
ns_output.o: ../netns/../vax/mtpr.h
ns_pcb.o: ../netns/ns_pcb.c ../h/param.h ../h/types.h ../h/signal.h
ns_pcb.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
ns_pcb.o: ../h/systm.h ../h/dir.h ../h/user.h ../h/../machine/pcb.h ../h/dmap.h
ns_pcb.o: ../h/time.h ../h/resource.h ../h/namei.h ../h/uio.h ../h/errno.h
ns_pcb.o: ../h/mbuf.h ../h/socket.h ../h/socketvar.h ../netns/../net/if.h
ns_pcb.o: ../netns/../net/../net/if_arp.h ../netns/../net/route.h
ns_pcb.o: ../h/protosw.h ../netns/ns.h ../netns/ns_if.h ../netns/ns_pcb.h
ns_proto.o: ../netns/ns_proto.c ../h/param.h ../h/types.h ../h/signal.h
ns_proto.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
ns_proto.o: ../h/socket.h ../h/protosw.h ../h/domain.h ../h/mbuf.h
ns_proto.o: ../netns/ns.h
spp_debug.o: ../netns/spp_debug.c ../h/param.h ../h/types.h ../h/signal.h
spp_debug.o: ../h/../machine/trap.h ../h/../machine/machparam.h
spp_debug.o: machine/endian.h ../h/systm.h ../h/mbuf.h ../h/socket.h
spp_debug.o: ../h/socketvar.h ../h/protosw.h ../h/errno.h
spp_debug.o: ../netns/../net/route.h ../netns/../net/if.h
spp_debug.o: ../netns/../net/../net/if_arp.h ../netns/../netinet/tcp_fsm.h
spp_debug.o: ../netns/ns.h ../netns/ns_pcb.h ../netns/idp.h ../netns/idp_var.h
spp_debug.o: ../netns/sp.h ../netns/spidp.h ../netns/spp_timer.h
spp_debug.o: ../netns/spp_var.h ../netns/spp_debug.h
spp_usrreq.o: ../netns/spp_usrreq.c ../h/param.h ../h/types.h ../h/signal.h
spp_usrreq.o: ../h/../machine/trap.h ../h/../machine/machparam.h
spp_usrreq.o: machine/endian.h ../h/systm.h ../h/dir.h ../h/user.h
spp_usrreq.o: ../h/../machine/pcb.h ../h/dmap.h ../h/time.h ../h/resource.h
spp_usrreq.o: ../h/namei.h ../h/uio.h ../h/errno.h ../h/mbuf.h ../h/protosw.h
spp_usrreq.o: ../h/socket.h ../h/socketvar.h ../h/errno.h ../netns/../net/if.h
spp_usrreq.o: ../netns/../net/../net/if_arp.h ../netns/../net/route.h
spp_usrreq.o: ../netns/../netinet/tcp_fsm.h ../netns/ns.h ../netns/ns_pcb.h
spp_usrreq.o: ../netns/idp.h ../netns/idp_var.h ../netns/ns_error.h
spp_usrreq.o: ../netns/sp.h ../netns/spidp.h ../netns/spp_timer.h
spp_usrreq.o: ../netns/spp_var.h ../netns/spp_debug.h
init_main.o: ../sys/init_main.c ../sys/../machine/pte.h ../h/param.h
init_main.o: ../h/types.h ../h/signal.h ../h/../machine/trap.h
init_main.o: ../h/../machine/machparam.h machine/endian.h ../h/systm.h
init_main.o: ../h/dir.h ../h/user.h ../h/../machine/pcb.h ../h/dmap.h
init_main.o: ../h/time.h ../h/resource.h ../h/namei.h ../h/uio.h ../h/errno.h
init_main.o: ../h/kernel.h ../h/fs.h ../h/mount.h ../h/map.h ../h/proc.h
init_main.o: ../h/inode.h ../h/seg.h ../h/conf.h ../h/buf.h ../h/vm.h
init_main.o: ../h/vmparam.h ../h/../machine/vmparam.h ../h/vmmac.h
init_main.o: ../h/vmmeter.h ../h/vmsystm.h ../h/cmap.h ../h/text.h ../h/clist.h
init_main.o: ../h/protosw.h ../h/quota.h ../h/reboot.h ../sys/../machine/reg.h
init_main.o: ../sys/../machine/cpu.h loop.h kg.h sl.h
init_sysent.o: ../sys/init_sysent.c ../h/param.h ../h/types.h ../h/signal.h
init_sysent.o: ../h/../machine/trap.h ../h/../machine/machparam.h
init_sysent.o: machine/endian.h ../h/systm.h
kern_acct.o: ../sys/kern_acct.c ../h/param.h ../h/types.h ../h/signal.h
kern_acct.o: ../h/../machine/trap.h ../h/../machine/machparam.h
kern_acct.o: machine/endian.h ../h/systm.h ../h/dir.h ../h/user.h
kern_acct.o: ../h/../machine/pcb.h ../h/dmap.h ../h/time.h ../h/resource.h
kern_acct.o: ../h/namei.h ../h/uio.h ../h/errno.h ../h/inode.h ../h/fs.h
kern_acct.o: ../h/kernel.h ../h/acct.h ../h/uio.h
kern_clock.o: ../sys/kern_clock.c ../sys/../machine/reg.h
kern_clock.o: ../sys/../machine/psl.h ../h/param.h ../h/types.h ../h/signal.h
kern_clock.o: ../h/../machine/trap.h ../h/../machine/machparam.h
kern_clock.o: machine/endian.h ../h/systm.h ../h/dkstat.h ../h/callout.h
kern_clock.o: ../h/dir.h ../h/user.h ../h/../machine/pcb.h ../h/dmap.h
kern_clock.o: ../h/time.h ../h/resource.h ../h/namei.h ../h/uio.h ../h/errno.h
kern_clock.o: ../h/kernel.h ../h/proc.h ../h/vm.h ../h/vmparam.h
kern_clock.o: ../h/../machine/vmparam.h ../h/vmmac.h ../h/vmmeter.h
kern_clock.o: ../h/vmsystm.h ../h/text.h ../sys/../machine/mtpr.h
kern_clock.o: ../sys/../machine/clock.h
kern_descrip.o: ../sys/kern_descrip.c ../h/param.h ../h/types.h ../h/signal.h
kern_descrip.o: ../h/../machine/trap.h ../h/../machine/machparam.h
kern_descrip.o: machine/endian.h ../h/systm.h ../h/dir.h ../h/user.h
kern_descrip.o: ../h/../machine/pcb.h ../h/dmap.h ../h/time.h ../h/resource.h
kern_descrip.o: ../h/namei.h ../h/uio.h ../h/errno.h ../h/kernel.h ../h/inode.h
kern_descrip.o: ../h/proc.h ../h/file.h ../h/socket.h ../h/socketvar.h
kern_descrip.o: ../h/mount.h ../h/stat.h ../h/ioctl.h ../h/ttychars.h
kern_descrip.o: ../h/ttydev.h
kern_exec.o: ../sys/kern_exec.c ../sys/../machine/reg.h ../sys/../machine/pte.h
kern_exec.o: ../sys/../machine/psl.h ../sys/../machine/mtpr.h ../h/param.h
kern_exec.o: ../h/types.h ../h/signal.h ../h/../machine/trap.h
kern_exec.o: ../h/../machine/machparam.h machine/endian.h ../h/systm.h
kern_exec.o: ../h/map.h ../h/dir.h ../h/user.h ../h/../machine/pcb.h
kern_exec.o: ../h/dmap.h ../h/time.h ../h/resource.h ../h/namei.h ../h/uio.h
kern_exec.o: ../h/errno.h ../h/kernel.h ../h/proc.h ../h/buf.h ../h/inode.h
kern_exec.o: ../h/seg.h ../h/vm.h ../h/vmparam.h ../h/../machine/vmparam.h
kern_exec.o: ../h/vmmac.h ../h/vmmeter.h ../h/vmsystm.h ../h/text.h ../h/file.h
kern_exec.o: ../h/uio.h ../h/acct.h ../h/exec.h
kern_exit.o: ../sys/kern_exit.c ../sys/../machine/reg.h ../sys/../machine/psl.h
kern_exit.o: ../h/param.h ../h/types.h ../h/signal.h ../h/../machine/trap.h
kern_exit.o: ../h/../machine/machparam.h machine/endian.h ../h/systm.h
kern_exit.o: ../h/map.h ../h/dir.h ../h/user.h ../h/../machine/pcb.h
kern_exit.o: ../h/dmap.h ../h/time.h ../h/resource.h ../h/namei.h ../h/uio.h
kern_exit.o: ../h/errno.h ../h/kernel.h ../h/proc.h ../h/buf.h ../h/wait.h
kern_exit.o: ../h/vm.h ../h/vmparam.h ../h/../machine/vmparam.h ../h/vmmac.h
kern_exit.o: ../h/vmmeter.h ../h/vmsystm.h ../h/file.h ../h/inode.h
kern_exit.o: ../h/syslog.h ../h/malloc.h
kern_fork.o: ../sys/kern_fork.c ../sys/../machine/reg.h ../sys/../machine/pte.h
kern_fork.o: ../sys/../machine/psl.h ../h/param.h ../h/types.h ../h/signal.h
kern_fork.o: ../h/../machine/trap.h ../h/../machine/machparam.h
kern_fork.o: machine/endian.h ../h/systm.h ../h/map.h ../h/dir.h ../h/user.h
kern_fork.o: ../h/../machine/pcb.h ../h/dmap.h ../h/time.h ../h/resource.h
kern_fork.o: ../h/namei.h ../h/uio.h ../h/errno.h ../h/kernel.h ../h/proc.h
kern_fork.o: ../h/inode.h ../h/seg.h ../h/vm.h ../h/vmparam.h
kern_fork.o: ../h/../machine/vmparam.h ../h/vmmac.h ../h/vmmeter.h
kern_fork.o: ../h/vmsystm.h ../h/text.h ../h/file.h ../h/acct.h ../h/quota.h
kern_malloc.o: ../sys/kern_malloc.c ../h/param.h ../h/types.h ../h/signal.h
kern_malloc.o: ../h/../machine/trap.h ../h/../machine/machparam.h
kern_malloc.o: machine/endian.h ../h/vm.h ../h/vmparam.h
kern_malloc.o: ../h/../machine/vmparam.h ../h/vmmac.h ../h/vmmeter.h
kern_malloc.o: ../h/vmsystm.h ../h/cmap.h ../h/time.h ../h/proc.h ../h/map.h
kern_malloc.o: ../h/kernel.h ../h/malloc.h ../sys/../machine/pte.h
kern_mman.o: ../sys/kern_mman.c ../h/param.h ../h/types.h ../h/signal.h
kern_mman.o: ../h/../machine/trap.h ../h/../machine/machparam.h
kern_mman.o: machine/endian.h ../h/systm.h ../h/map.h ../h/dir.h ../h/user.h
kern_mman.o: ../h/../machine/pcb.h ../h/dmap.h ../h/time.h ../h/resource.h
kern_mman.o: ../h/namei.h ../h/uio.h ../h/errno.h ../h/proc.h ../h/buf.h
kern_mman.o: ../h/inode.h ../h/seg.h ../h/acct.h ../h/wait.h ../h/vm.h
kern_mman.o: ../h/vmparam.h ../h/../machine/vmparam.h ../h/vmmac.h
kern_mman.o: ../h/vmmeter.h ../h/vmsystm.h ../h/text.h ../h/file.h
kern_mman.o: ../h/vadvise.h ../h/cmap.h ../h/trace.h ../h/mman.h ../h/conf.h
kern_mman.o: ../sys/../machine/cpu.h ../sys/../machine/reg.h
kern_mman.o: ../sys/../machine/psl.h ../sys/../machine/pte.h
kern_mman.o: ../sys/../machine/mtpr.h
kern_proc.o: ../sys/kern_proc.c ../sys/../machine/reg.h ../sys/../machine/pte.h
kern_proc.o: ../sys/../machine/psl.h ../h/param.h ../h/types.h ../h/signal.h
kern_proc.o: ../h/../machine/trap.h ../h/../machine/machparam.h
kern_proc.o: machine/endian.h ../h/systm.h ../h/map.h ../h/dir.h ../h/user.h
kern_proc.o: ../h/../machine/pcb.h ../h/dmap.h ../h/time.h ../h/resource.h
kern_proc.o: ../h/namei.h ../h/uio.h ../h/errno.h ../h/kernel.h ../h/proc.h
kern_proc.o: ../h/buf.h ../h/seg.h ../h/acct.h ../h/wait.h ../h/vm.h
kern_proc.o: ../h/vmparam.h ../h/../machine/vmparam.h ../h/vmmac.h
kern_proc.o: ../h/vmmeter.h ../h/vmsystm.h ../h/text.h ../h/file.h ../h/quota.h
kern_proc.o: ../h/uio.h ../h/mbuf.h
kern_prot.o: ../sys/kern_prot.c ../sys/../machine/reg.h ../h/param.h
kern_prot.o: ../h/types.h ../h/signal.h ../h/../machine/trap.h
kern_prot.o: ../h/../machine/machparam.h machine/endian.h ../h/systm.h
kern_prot.o: ../h/dir.h ../h/user.h ../h/../machine/pcb.h ../h/dmap.h
kern_prot.o: ../h/time.h ../h/resource.h ../h/namei.h ../h/uio.h ../h/errno.h
kern_prot.o: ../h/inode.h ../h/proc.h ../h/timeb.h ../h/times.h ../h/reboot.h
kern_prot.o: ../h/fs.h ../h/buf.h ../h/mount.h ../h/quota.h
kern_resource.o: ../sys/kern_resource.c ../h/param.h ../h/types.h ../h/signal.h
kern_resource.o: ../h/../machine/trap.h ../h/../machine/machparam.h
kern_resource.o: machine/endian.h ../h/dir.h ../h/user.h ../h/../machine/pcb.h
kern_resource.o: ../h/dmap.h ../h/time.h ../h/resource.h ../h/namei.h
kern_resource.o: ../h/uio.h ../h/errno.h ../h/proc.h
kern_sig.o: ../sys/kern_sig.c ../sys/../machine/reg.h ../sys/../machine/pte.h
kern_sig.o: ../sys/../machine/psl.h ../sys/../machine/mtpr.h ../h/param.h
kern_sig.o: ../h/types.h ../h/signal.h ../h/../machine/trap.h
kern_sig.o: ../h/../machine/machparam.h machine/endian.h ../h/systm.h
kern_sig.o: ../h/dir.h ../h/user.h ../h/../machine/pcb.h ../h/dmap.h
kern_sig.o: ../h/time.h ../h/resource.h ../h/namei.h ../h/uio.h ../h/errno.h
kern_sig.o: ../h/inode.h ../h/proc.h ../h/timeb.h ../h/times.h ../h/buf.h
kern_sig.o: ../h/mount.h ../h/text.h ../h/seg.h ../h/vm.h ../h/vmparam.h
kern_sig.o: ../h/../machine/vmparam.h ../h/vmmac.h ../h/vmmeter.h
kern_sig.o: ../h/vmsystm.h ../h/acct.h ../h/uio.h ../h/kernel.h
kern_subr.o: ../sys/kern_subr.c ../h/param.h ../h/types.h ../h/signal.h
kern_subr.o: ../h/../machine/trap.h ../h/../machine/machparam.h
kern_subr.o: machine/endian.h ../h/systm.h ../h/dir.h ../h/user.h
kern_subr.o: ../h/../machine/pcb.h ../h/dmap.h ../h/time.h ../h/resource.h
kern_subr.o: ../h/namei.h ../h/uio.h ../h/errno.h ../h/uio.h
kern_synch.o: ../sys/kern_synch.c ../sys/../machine/pte.h
kern_synch.o: ../sys/../machine/psl.h ../sys/../machine/mtpr.h ../h/param.h
kern_synch.o: ../h/types.h ../h/signal.h ../h/../machine/trap.h
kern_synch.o: ../h/../machine/machparam.h machine/endian.h ../h/systm.h
kern_synch.o: ../h/dir.h ../h/user.h ../h/../machine/pcb.h ../h/dmap.h
kern_synch.o: ../h/time.h ../h/resource.h ../h/namei.h ../h/uio.h ../h/errno.h
kern_synch.o: ../h/proc.h ../h/vm.h ../h/vmparam.h ../h/../machine/vmparam.h
kern_synch.o: ../h/vmmac.h ../h/vmmeter.h ../h/vmsystm.h ../h/kernel.h
kern_synch.o: ../h/buf.h
kern_time.o: ../sys/kern_time.c ../h/param.h ../h/types.h ../h/signal.h
kern_time.o: ../h/../machine/trap.h ../h/../machine/machparam.h
kern_time.o: machine/endian.h ../h/dir.h ../h/user.h ../h/../machine/pcb.h
kern_time.o: ../h/dmap.h ../h/time.h ../h/resource.h ../h/namei.h ../h/uio.h
kern_time.o: ../h/errno.h ../h/kernel.h ../h/proc.h ../sys/../machine/reg.h
kern_time.o: ../sys/../machine/cpu.h
kern_xxx.o: ../sys/kern_xxx.c ../h/param.h ../h/types.h ../h/signal.h
kern_xxx.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
kern_xxx.o: ../h/systm.h ../h/dir.h ../h/user.h ../h/../machine/pcb.h
kern_xxx.o: ../h/dmap.h ../h/time.h ../h/resource.h ../h/namei.h ../h/uio.h
kern_xxx.o: ../h/errno.h ../h/kernel.h ../h/proc.h ../h/reboot.h
quota_kern.o: ../sys/quota_kern.c ../h/param.h ../h/types.h ../h/signal.h
quota_kern.o: ../h/../machine/trap.h ../h/../machine/machparam.h
quota_kern.o: machine/endian.h ../h/systm.h ../h/dir.h ../h/user.h
quota_kern.o: ../h/../machine/pcb.h ../h/dmap.h ../h/time.h ../h/resource.h
quota_kern.o: ../h/namei.h ../h/uio.h ../h/errno.h ../h/proc.h ../h/inode.h
quota_kern.o: ../h/quota.h ../h/mount.h ../h/fs.h ../h/uio.h
quota_subr.o: ../sys/quota_subr.c ../h/param.h ../h/types.h ../h/signal.h
quota_subr.o: ../h/../machine/trap.h ../h/../machine/machparam.h
quota_subr.o: machine/endian.h ../h/systm.h ../h/dir.h ../h/user.h
quota_subr.o: ../h/../machine/pcb.h ../h/dmap.h ../h/time.h ../h/resource.h
quota_subr.o: ../h/namei.h ../h/uio.h ../h/errno.h ../h/proc.h ../h/inode.h
quota_subr.o: ../h/quota.h ../h/mount.h ../h/fs.h ../h/uio.h
quota_sys.o: ../sys/quota_sys.c ../h/param.h ../h/types.h ../h/signal.h
quota_sys.o: ../h/../machine/trap.h ../h/../machine/machparam.h
quota_sys.o: machine/endian.h ../h/systm.h ../h/dir.h ../h/user.h
quota_sys.o: ../h/../machine/pcb.h ../h/dmap.h ../h/time.h ../h/resource.h
quota_sys.o: ../h/namei.h ../h/uio.h ../h/errno.h ../h/proc.h ../h/inode.h
quota_sys.o: ../h/quota.h ../h/mount.h ../h/fs.h ../h/uio.h
quota_ufs.o: ../sys/quota_ufs.c ../h/param.h ../h/types.h ../h/signal.h
quota_ufs.o: ../h/../machine/trap.h ../h/../machine/machparam.h
quota_ufs.o: machine/endian.h ../h/systm.h ../h/dir.h ../h/user.h
quota_ufs.o: ../h/../machine/pcb.h ../h/dmap.h ../h/time.h ../h/resource.h
quota_ufs.o: ../h/namei.h ../h/uio.h ../h/errno.h ../h/proc.h ../h/inode.h
quota_ufs.o: ../h/quota.h ../h/mount.h ../h/fs.h ../h/uio.h
subr_log.o: ../sys/subr_log.c ../h/param.h ../h/types.h ../h/signal.h
subr_log.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
subr_log.o: ../h/dir.h ../h/user.h ../h/../machine/pcb.h ../h/dmap.h
subr_log.o: ../h/time.h ../h/resource.h ../h/namei.h ../h/uio.h ../h/errno.h
subr_log.o: ../h/proc.h ../h/ioctl.h ../h/ttychars.h ../h/ttydev.h
subr_log.o: ../h/msgbuf.h ../h/file.h ../h/errno.h
subr_prf.o: ../sys/subr_prf.c ../h/param.h ../h/types.h ../h/signal.h
subr_prf.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
subr_prf.o: ../h/systm.h ../h/seg.h ../h/buf.h ../h/conf.h ../h/reboot.h
subr_prf.o: ../h/vm.h ../h/vmparam.h ../h/../machine/vmparam.h ../h/vmmac.h
subr_prf.o: ../h/vmmeter.h ../h/vmsystm.h ../h/msgbuf.h ../h/dir.h ../h/user.h
subr_prf.o: ../h/../machine/pcb.h ../h/dmap.h ../h/time.h ../h/resource.h
subr_prf.o: ../h/namei.h ../h/uio.h ../h/errno.h ../h/proc.h ../h/ioctl.h
subr_prf.o: ../h/ttychars.h ../h/ttydev.h ../h/tty.h ../h/ttychars.h
subr_prf.o: ../h/ttydev.h ../h/syslog.h ../sys/../machine/mtpr.h
subr_rmap.o: ../sys/subr_rmap.c ../h/param.h ../h/types.h ../h/signal.h
subr_rmap.o: ../h/../machine/trap.h ../h/../machine/machparam.h
subr_rmap.o: machine/endian.h ../h/systm.h ../h/map.h ../h/dir.h ../h/user.h
subr_rmap.o: ../h/../machine/pcb.h ../h/dmap.h ../h/time.h ../h/resource.h
subr_rmap.o: ../h/namei.h ../h/uio.h ../h/errno.h ../h/proc.h ../h/text.h
subr_rmap.o: ../h/kernel.h
subr_xxx.o: ../sys/subr_xxx.c ../h/errno.h
sys_generic.o: ../sys/sys_generic.c ../h/param.h ../h/types.h ../h/signal.h
sys_generic.o: ../h/../machine/trap.h ../h/../machine/machparam.h
sys_generic.o: machine/endian.h ../h/systm.h ../h/dir.h ../h/user.h
sys_generic.o: ../h/../machine/pcb.h ../h/dmap.h ../h/time.h ../h/resource.h
sys_generic.o: ../h/namei.h ../h/uio.h ../h/errno.h ../h/ioctl.h
sys_generic.o: ../h/ttychars.h ../h/ttydev.h ../h/file.h ../h/proc.h ../h/uio.h
sys_generic.o: ../h/kernel.h ../h/stat.h ../h/malloc.h
sys_inode.o: ../sys/sys_inode.c ../h/param.h ../h/types.h ../h/signal.h
sys_inode.o: ../h/../machine/trap.h ../h/../machine/machparam.h
sys_inode.o: machine/endian.h ../h/systm.h ../h/dir.h ../h/user.h
sys_inode.o: ../h/../machine/pcb.h ../h/dmap.h ../h/time.h ../h/resource.h
sys_inode.o: ../h/namei.h ../h/uio.h ../h/errno.h ../h/inode.h ../h/proc.h
sys_inode.o: ../h/fs.h ../h/conf.h ../h/buf.h ../h/mount.h ../h/file.h
sys_inode.o: ../h/uio.h ../h/ioctl.h ../h/ttychars.h ../h/ttydev.h ../h/tty.h
sys_inode.o: ../h/ttychars.h ../h/ttydev.h ../h/cmap.h ../h/stat.h
sys_inode.o: ../h/kernel.h ../h/disklabel.h
sys_process.o: ../sys/sys_process.c ../sys/../machine/reg.h
sys_process.o: ../sys/../machine/psl.h ../sys/../machine/pte.h ../h/param.h
sys_process.o: ../h/types.h ../h/signal.h ../h/../machine/trap.h
sys_process.o: ../h/../machine/machparam.h machine/endian.h ../h/systm.h
sys_process.o: ../h/dir.h ../h/user.h ../h/../machine/pcb.h ../h/dmap.h
sys_process.o: ../h/time.h ../h/resource.h ../h/namei.h ../h/uio.h ../h/errno.h
sys_process.o: ../h/proc.h ../h/inode.h ../h/text.h ../h/seg.h ../h/vm.h
sys_process.o: ../h/vmparam.h ../h/../machine/vmparam.h ../h/vmmac.h
sys_process.o: ../h/vmmeter.h ../h/vmsystm.h ../h/buf.h ../h/acct.h
sys_process.o: ../h/ptrace.h ../sys/../vax/cpu.h
sys_socket.o: ../sys/sys_socket.c ../h/param.h ../h/types.h ../h/signal.h
sys_socket.o: ../h/../machine/trap.h ../h/../machine/machparam.h
sys_socket.o: machine/endian.h ../h/systm.h ../h/dir.h ../h/user.h
sys_socket.o: ../h/../machine/pcb.h ../h/dmap.h ../h/time.h ../h/resource.h
sys_socket.o: ../h/namei.h ../h/uio.h ../h/errno.h ../h/file.h ../h/mbuf.h
sys_socket.o: ../h/protosw.h ../h/socket.h ../h/socketvar.h ../h/ioctl.h
sys_socket.o: ../h/ttychars.h ../h/ttydev.h ../h/uio.h ../h/stat.h
sys_socket.o: ../sys/../net/if.h ../sys/../net/../net/if_arp.h
sys_socket.o: ../sys/../net/route.h
tty.o: ../sys/tty.c ../sys/../machine/reg.h ../h/param.h ../h/types.h
tty.o: ../h/signal.h ../h/../machine/trap.h ../h/../machine/machparam.h
tty.o: machine/endian.h ../h/systm.h ../h/dir.h ../h/user.h
tty.o: ../h/../machine/pcb.h ../h/dmap.h ../h/time.h ../h/resource.h
tty.o: ../h/namei.h ../h/uio.h ../h/errno.h ../h/ioctl.h ../h/ttychars.h
tty.o: ../h/ttydev.h ../h/tty.h ../h/ttychars.h ../h/ttydev.h ../h/proc.h
tty.o: ../h/file.h ../h/conf.h ../h/dkstat.h ../h/uio.h ../h/kernel.h
tty_conf.o: ../sys/tty_conf.c ../h/param.h ../h/types.h ../h/signal.h
tty_conf.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
tty_conf.o: ../h/systm.h ../h/buf.h ../h/ioctl.h ../h/ttychars.h ../h/ttydev.h
tty_conf.o: ../h/tty.h ../h/ttychars.h ../h/ttydev.h ../h/conf.h bk.h tb.h sl.h
tty_pty.o: ../sys/tty_pty.c pty.h ../h/param.h ../h/types.h ../h/signal.h
tty_pty.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
tty_pty.o: ../h/systm.h ../h/ioctl.h ../h/ttychars.h ../h/ttydev.h ../h/tty.h
tty_pty.o: ../h/ttychars.h ../h/ttydev.h ../h/dir.h ../h/user.h
tty_pty.o: ../h/../machine/pcb.h ../h/dmap.h ../h/time.h ../h/resource.h
tty_pty.o: ../h/namei.h ../h/uio.h ../h/errno.h ../h/conf.h ../h/file.h
tty_pty.o: ../h/proc.h ../h/uio.h ../h/kernel.h
tty_subr.o: ../sys/tty_subr.c ../h/param.h ../h/types.h ../h/signal.h
tty_subr.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
tty_subr.o: ../h/systm.h ../h/buf.h ../h/ioctl.h ../h/ttychars.h ../h/ttydev.h
tty_subr.o: ../h/tty.h ../h/ttychars.h ../h/ttydev.h ../h/clist.h
tty_tty.o: ../sys/tty_tty.c ../h/param.h ../h/types.h ../h/signal.h
tty_tty.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
tty_tty.o: ../h/systm.h ../h/conf.h ../h/dir.h ../h/user.h
tty_tty.o: ../h/../machine/pcb.h ../h/dmap.h ../h/time.h ../h/resource.h
tty_tty.o: ../h/namei.h ../h/uio.h ../h/errno.h ../h/ioctl.h ../h/ttychars.h
tty_tty.o: ../h/ttydev.h ../h/tty.h ../h/ttychars.h ../h/ttydev.h ../h/proc.h
tty_tty.o: ../h/uio.h
ufs_alloc.o: ../sys/ufs_alloc.c ../h/param.h ../h/types.h ../h/signal.h
ufs_alloc.o: ../h/../machine/trap.h ../h/../machine/machparam.h
ufs_alloc.o: machine/endian.h ../h/systm.h ../h/mount.h ../h/fs.h ../h/buf.h
ufs_alloc.o: ../h/inode.h ../h/dir.h ../h/user.h ../h/../machine/pcb.h
ufs_alloc.o: ../h/dmap.h ../h/time.h ../h/resource.h ../h/namei.h ../h/uio.h
ufs_alloc.o: ../h/errno.h ../h/quota.h ../h/kernel.h ../h/syslog.h ../h/cmap.h
ufs_bio.o: ../sys/ufs_bio.c ../sys/../machine/pte.h ../h/param.h ../h/types.h
ufs_bio.o: ../h/signal.h ../h/../machine/trap.h ../h/../machine/machparam.h
ufs_bio.o: machine/endian.h ../h/systm.h ../h/dir.h ../h/user.h
ufs_bio.o: ../h/../machine/pcb.h ../h/dmap.h ../h/time.h ../h/resource.h
ufs_bio.o: ../h/namei.h ../h/uio.h ../h/errno.h ../h/buf.h ../h/conf.h
ufs_bio.o: ../h/proc.h ../h/seg.h ../h/vm.h ../h/vmparam.h
ufs_bio.o: ../h/../machine/vmparam.h ../h/vmmac.h ../h/vmmeter.h ../h/vmsystm.h
ufs_bio.o: ../h/trace.h
ufs_bmap.o: ../sys/ufs_bmap.c ../h/param.h ../h/types.h ../h/signal.h
ufs_bmap.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
ufs_bmap.o: ../h/systm.h ../h/inode.h ../h/dir.h ../h/user.h
ufs_bmap.o: ../h/../machine/pcb.h ../h/dmap.h ../h/time.h ../h/resource.h
ufs_bmap.o: ../h/namei.h ../h/uio.h ../h/errno.h ../h/buf.h ../h/proc.h
ufs_bmap.o: ../h/fs.h
ufs_disksubr.o: ../sys/ufs_disksubr.c ../h/param.h ../h/types.h ../h/signal.h
ufs_disksubr.o: ../h/../machine/trap.h ../h/../machine/machparam.h
ufs_disksubr.o: machine/endian.h ../h/systm.h ../h/buf.h ../h/disklabel.h
ufs_disksubr.o: ../h/syslog.h ../h/dir.h ../h/user.h ../h/../machine/pcb.h
ufs_disksubr.o: ../h/dmap.h ../h/time.h ../h/resource.h ../h/namei.h ../h/uio.h
ufs_disksubr.o: ../h/errno.h
ufs_fio.o: ../sys/ufs_fio.c ../sys/../machine/reg.h ../h/param.h ../h/types.h
ufs_fio.o: ../h/signal.h ../h/../machine/trap.h ../h/../machine/machparam.h
ufs_fio.o: machine/endian.h ../h/systm.h ../h/dir.h ../h/user.h
ufs_fio.o: ../h/../machine/pcb.h ../h/dmap.h ../h/time.h ../h/resource.h
ufs_fio.o: ../h/namei.h ../h/uio.h ../h/errno.h ../h/fs.h ../h/file.h
ufs_fio.o: ../h/conf.h ../h/inode.h ../h/acct.h ../h/mount.h ../h/socket.h
ufs_fio.o: ../h/socketvar.h ../h/proc.h
ufs_inode.o: ../sys/ufs_inode.c ../h/param.h ../h/types.h ../h/signal.h
ufs_inode.o: ../h/../machine/trap.h ../h/../machine/machparam.h
ufs_inode.o: machine/endian.h ../h/systm.h ../h/mount.h ../h/dir.h ../h/user.h
ufs_inode.o: ../h/../machine/pcb.h ../h/dmap.h ../h/time.h ../h/resource.h
ufs_inode.o: ../h/namei.h ../h/uio.h ../h/errno.h ../h/inode.h ../h/fs.h
ufs_inode.o: ../h/buf.h ../h/cmap.h ../h/quota.h ../h/kernel.h ../h/malloc.h
ufs_mount.o: ../sys/ufs_mount.c ../h/param.h ../h/types.h ../h/signal.h
ufs_mount.o: ../h/../machine/trap.h ../h/../machine/machparam.h
ufs_mount.o: machine/endian.h ../h/systm.h ../h/dir.h ../h/user.h
ufs_mount.o: ../h/../machine/pcb.h ../h/dmap.h ../h/time.h ../h/resource.h
ufs_mount.o: ../h/namei.h ../h/uio.h ../h/errno.h ../h/inode.h ../h/proc.h
ufs_mount.o: ../h/fs.h ../h/buf.h ../h/mount.h ../h/file.h ../h/conf.h
ufs_mount.o: ../h/ioctl.h ../h/ttychars.h ../h/ttydev.h ../h/disklabel.h
ufs_mount.o: ../h/stat.h ../h/malloc.h
ufs_namei.o: ../sys/ufs_namei.c ../h/param.h ../h/types.h ../h/signal.h
ufs_namei.o: ../h/../machine/trap.h ../h/../machine/machparam.h
ufs_namei.o: machine/endian.h ../h/systm.h ../h/inode.h ../h/fs.h ../h/mount.h
ufs_namei.o: ../h/dir.h ../h/user.h ../h/../machine/pcb.h ../h/dmap.h
ufs_namei.o: ../h/time.h ../h/resource.h ../h/namei.h ../h/uio.h ../h/errno.h
ufs_namei.o: ../h/buf.h ../h/conf.h ../h/uio.h ../h/kernel.h ../h/malloc.h
ufs_subr.o: ../sys/ufs_subr.c ../h/param.h ../h/types.h ../h/signal.h
ufs_subr.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
ufs_subr.o: ../h/systm.h ../h/mount.h ../h/fs.h ../h/buf.h ../h/inode.h
ufs_subr.o: ../h/dir.h ../h/user.h ../h/../machine/pcb.h ../h/dmap.h
ufs_subr.o: ../h/time.h ../h/resource.h ../h/namei.h ../h/uio.h ../h/errno.h
ufs_subr.o: ../h/quota.h ../h/kernel.h
ufs_syscalls.o: ../sys/ufs_syscalls.c ../h/param.h ../h/types.h ../h/signal.h
ufs_syscalls.o: ../h/../machine/trap.h ../h/../machine/machparam.h
ufs_syscalls.o: machine/endian.h ../h/systm.h ../h/dir.h ../h/user.h
ufs_syscalls.o: ../h/../machine/pcb.h ../h/dmap.h ../h/time.h ../h/resource.h
ufs_syscalls.o: ../h/namei.h ../h/uio.h ../h/errno.h ../h/kernel.h ../h/file.h
ufs_syscalls.o: ../h/stat.h ../h/inode.h ../h/fs.h ../h/buf.h ../h/proc.h
ufs_syscalls.o: ../h/quota.h ../h/uio.h ../h/socket.h ../h/socketvar.h
ufs_syscalls.o: ../h/mount.h
ufs_tables.o: ../sys/ufs_tables.c ../h/param.h ../h/types.h ../h/signal.h
ufs_tables.o: ../h/../machine/trap.h ../h/../machine/machparam.h
ufs_tables.o: machine/endian.h
ufs_xxx.o: ../sys/ufs_xxx.c ../h/param.h ../h/types.h ../h/signal.h
ufs_xxx.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
ufs_xxx.o: ../h/systm.h ../h/inode.h ../h/fs.h ../h/mount.h ../h/dir.h
ufs_xxx.o: ../h/user.h ../h/../machine/pcb.h ../h/dmap.h ../h/time.h
ufs_xxx.o: ../h/resource.h ../h/namei.h ../h/uio.h ../h/errno.h ../h/buf.h
ufs_xxx.o: ../h/conf.h
uipc_domain.o: ../sys/uipc_domain.c ../h/param.h ../h/types.h ../h/signal.h
uipc_domain.o: ../h/../machine/trap.h ../h/../machine/machparam.h
uipc_domain.o: machine/endian.h ../h/socket.h ../h/protosw.h ../h/domain.h
uipc_domain.o: ../h/time.h ../h/kernel.h imp.h
uipc_mbuf.o: ../sys/uipc_mbuf.c ../sys/../machine/pte.h ../h/param.h
uipc_mbuf.o: ../h/types.h ../h/signal.h ../h/../machine/trap.h
uipc_mbuf.o: ../h/../machine/machparam.h machine/endian.h ../h/dir.h
uipc_mbuf.o: ../h/user.h ../h/../machine/pcb.h ../h/dmap.h ../h/time.h
uipc_mbuf.o: ../h/resource.h ../h/namei.h ../h/uio.h ../h/errno.h ../h/proc.h
uipc_mbuf.o: ../h/cmap.h ../h/map.h ../h/mbuf.h ../h/vm.h ../h/vmparam.h
uipc_mbuf.o: ../h/../machine/vmparam.h ../h/vmmac.h ../h/vmmeter.h
uipc_mbuf.o: ../h/vmsystm.h ../h/kernel.h ../h/syslog.h ../h/domain.h
uipc_mbuf.o: ../h/protosw.h
uipc_proto.o: ../sys/uipc_proto.c ../h/param.h ../h/types.h ../h/signal.h
uipc_proto.o: ../h/../machine/trap.h ../h/../machine/machparam.h
uipc_proto.o: machine/endian.h ../h/socket.h ../h/protosw.h ../h/domain.h
uipc_proto.o: ../h/mbuf.h
uipc_socket.o: ../sys/uipc_socket.c ../h/param.h ../h/types.h ../h/signal.h
uipc_socket.o: ../h/../machine/trap.h ../h/../machine/machparam.h
uipc_socket.o: machine/endian.h ../h/dir.h ../h/user.h ../h/../machine/pcb.h
uipc_socket.o: ../h/dmap.h ../h/time.h ../h/resource.h ../h/namei.h ../h/uio.h
uipc_socket.o: ../h/errno.h ../h/proc.h ../h/file.h ../h/mbuf.h ../h/domain.h
uipc_socket.o: ../h/protosw.h ../h/socket.h ../h/socketvar.h
uipc_socket2.o: ../sys/uipc_socket2.c ../h/param.h ../h/types.h ../h/signal.h
uipc_socket2.o: ../h/../machine/trap.h ../h/../machine/machparam.h
uipc_socket2.o: machine/endian.h ../h/systm.h ../h/dir.h ../h/user.h
uipc_socket2.o: ../h/../machine/pcb.h ../h/dmap.h ../h/time.h ../h/resource.h
uipc_socket2.o: ../h/namei.h ../h/uio.h ../h/errno.h ../h/proc.h ../h/file.h
uipc_socket2.o: ../h/inode.h ../h/buf.h ../h/mbuf.h ../h/protosw.h
uipc_socket2.o: ../h/socket.h ../h/socketvar.h
uipc_syscalls.o: ../sys/uipc_syscalls.c ../h/param.h ../h/types.h ../h/signal.h
uipc_syscalls.o: ../h/../machine/trap.h ../h/../machine/machparam.h
uipc_syscalls.o: machine/endian.h ../h/dir.h ../h/user.h ../h/../machine/pcb.h
uipc_syscalls.o: ../h/dmap.h ../h/time.h ../h/resource.h ../h/namei.h
uipc_syscalls.o: ../h/uio.h ../h/errno.h ../h/file.h ../h/buf.h ../h/mbuf.h
uipc_syscalls.o: ../h/protosw.h ../h/socket.h ../h/socketvar.h
uipc_usrreq.o: ../sys/uipc_usrreq.c ../h/param.h ../h/types.h ../h/signal.h
uipc_usrreq.o: ../h/../machine/trap.h ../h/../machine/machparam.h
uipc_usrreq.o: machine/endian.h ../h/dir.h ../h/user.h ../h/../machine/pcb.h
uipc_usrreq.o: ../h/dmap.h ../h/time.h ../h/resource.h ../h/namei.h ../h/uio.h
uipc_usrreq.o: ../h/errno.h ../h/mbuf.h ../h/domain.h ../h/protosw.h
uipc_usrreq.o: ../h/socket.h ../h/socketvar.h ../h/unpcb.h ../h/un.h
uipc_usrreq.o: ../h/inode.h ../h/file.h ../h/stat.h
vm_drum.o: ../sys/vm_drum.c ../sys/../machine/pte.h ../h/param.h ../h/types.h
vm_drum.o: ../h/signal.h ../h/../machine/trap.h ../h/../machine/machparam.h
vm_drum.o: machine/endian.h ../h/systm.h ../h/dir.h ../h/user.h
vm_drum.o: ../h/../machine/pcb.h ../h/dmap.h ../h/time.h ../h/resource.h
vm_drum.o: ../h/namei.h ../h/uio.h ../h/errno.h ../h/proc.h ../h/buf.h
vm_drum.o: ../h/text.h ../h/map.h ../h/vm.h ../h/vmparam.h
vm_drum.o: ../h/../machine/vmparam.h ../h/vmmac.h ../h/vmmeter.h ../h/vmsystm.h
vm_drum.o: ../h/cmap.h ../h/kernel.h
vm_mem.o: ../sys/vm_mem.c ../h/param.h ../h/types.h ../h/signal.h
vm_mem.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
vm_mem.o: ../h/systm.h ../h/cmap.h ../h/dir.h ../h/user.h ../h/../machine/pcb.h
vm_mem.o: ../h/dmap.h ../h/time.h ../h/resource.h ../h/namei.h ../h/uio.h
vm_mem.o: ../h/errno.h ../h/proc.h ../h/text.h ../h/vm.h ../h/vmparam.h
vm_mem.o: ../h/../machine/vmparam.h ../h/vmmac.h ../h/vmmeter.h ../h/vmsystm.h
vm_mem.o: ../h/file.h ../h/buf.h ../h/mount.h ../h/trace.h ../h/map.h
vm_mem.o: ../sys/../machine/cpu.h ../sys/../machine/pte.h
vm_mem.o: ../sys/../machine/mtpr.h
vm_mon.o: ../sys/vm_mon.c ../h/param.h ../h/types.h ../h/signal.h
vm_mon.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
vm_mon.o: ../h/systm.h ../h/dir.h ../h/user.h ../h/../machine/pcb.h ../h/dmap.h
vm_mon.o: ../h/time.h ../h/resource.h ../h/namei.h ../h/uio.h ../h/errno.h
vm_mon.o: ../h/vmmeter.h ../h/trace.h ../h/kernel.h
vm_page.o: ../sys/vm_page.c ../h/param.h ../h/types.h ../h/signal.h
vm_page.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
vm_page.o: ../h/systm.h ../h/inode.h ../h/dir.h ../h/user.h
vm_page.o: ../h/../machine/pcb.h ../h/dmap.h ../h/time.h ../h/resource.h
vm_page.o: ../h/namei.h ../h/uio.h ../h/errno.h ../h/proc.h ../h/buf.h
vm_page.o: ../h/text.h ../h/cmap.h ../h/vm.h ../h/vmparam.h
vm_page.o: ../h/../machine/vmparam.h ../h/vmmac.h ../h/vmmeter.h ../h/vmsystm.h
vm_page.o: ../h/file.h ../h/trace.h ../sys/../machine/cpu.h
vm_page.o: ../sys/../machine/reg.h ../sys/../machine/pte.h
vm_page.o: ../sys/../machine/mtpr.h
vm_proc.o: ../sys/vm_proc.c ../h/param.h ../h/types.h ../h/signal.h
vm_proc.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
vm_proc.o: ../h/systm.h ../h/dir.h ../h/user.h ../h/../machine/pcb.h
vm_proc.o: ../h/dmap.h ../h/time.h ../h/resource.h ../h/namei.h ../h/uio.h
vm_proc.o: ../h/errno.h ../h/proc.h ../h/map.h ../h/cmap.h ../h/text.h
vm_proc.o: ../h/vm.h ../h/vmparam.h ../h/../machine/vmparam.h ../h/vmmac.h
vm_proc.o: ../h/vmmeter.h ../h/vmsystm.h ../sys/../machine/pte.h
vm_proc.o: ../sys/../machine/mtpr.h ../sys/../machine/cpu.h
vm_pt.o: ../sys/vm_pt.c ../sys/../machine/pte.h ../sys/../machine/mtpr.h
vm_pt.o: ../h/param.h ../h/types.h ../h/signal.h ../h/../machine/trap.h
vm_pt.o: ../h/../machine/machparam.h machine/endian.h ../h/systm.h ../h/dir.h
vm_pt.o: ../h/user.h ../h/../machine/pcb.h ../h/dmap.h ../h/time.h
vm_pt.o: ../h/resource.h ../h/namei.h ../h/uio.h ../h/errno.h ../h/proc.h
vm_pt.o: ../h/map.h ../h/cmap.h ../h/vm.h ../h/vmparam.h
vm_pt.o: ../h/../machine/vmparam.h ../h/vmmac.h ../h/vmmeter.h ../h/vmsystm.h
vm_pt.o: ../h/buf.h ../h/text.h ../h/mount.h ../h/inode.h ../h/kernel.h
vm_sched.o: ../sys/vm_sched.c ../h/param.h ../h/types.h ../h/signal.h
vm_sched.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
vm_sched.o: ../h/systm.h ../h/seg.h ../h/dir.h ../h/user.h
vm_sched.o: ../h/../machine/pcb.h ../h/dmap.h ../h/time.h ../h/resource.h
vm_sched.o: ../h/namei.h ../h/uio.h ../h/errno.h ../h/proc.h ../h/text.h
vm_sched.o: ../h/vm.h ../h/vmparam.h ../h/../machine/vmparam.h ../h/vmmac.h
vm_sched.o: ../h/vmmeter.h ../h/vmsystm.h ../h/cmap.h ../h/kernel.h
vm_subr.o: ../sys/vm_subr.c ../sys/../machine/pte.h ../sys/../machine/mtpr.h
vm_subr.o: ../h/param.h ../h/types.h ../h/signal.h ../h/../machine/trap.h
vm_subr.o: ../h/../machine/machparam.h machine/endian.h ../h/systm.h ../h/dir.h
vm_subr.o: ../h/user.h ../h/../machine/pcb.h ../h/dmap.h ../h/time.h
vm_subr.o: ../h/resource.h ../h/namei.h ../h/uio.h ../h/errno.h ../h/vm.h
vm_subr.o: ../h/vmparam.h ../h/../machine/vmparam.h ../h/vmmac.h ../h/vmmeter.h
vm_subr.o: ../h/vmsystm.h ../h/proc.h ../h/cmap.h ../h/inode.h ../h/buf.h
vm_subr.o: ../h/text.h ../h/fs.h
vm_sw.o: ../sys/vm_sw.c ../h/param.h ../h/types.h ../h/signal.h
vm_sw.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
vm_sw.o: ../h/systm.h ../h/buf.h ../h/conf.h ../h/dir.h ../h/user.h
vm_sw.o: ../h/../machine/pcb.h ../h/dmap.h ../h/time.h ../h/resource.h
vm_sw.o: ../h/namei.h ../h/uio.h ../h/errno.h ../h/inode.h ../h/map.h
vm_sw.o: ../h/uio.h ../h/file.h ../h/stat.h
vm_swap.o: ../sys/vm_swap.c ../h/param.h ../h/types.h ../h/signal.h
vm_swap.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
vm_swap.o: ../h/systm.h ../h/dir.h ../h/user.h ../h/../machine/pcb.h
vm_swap.o: ../h/dmap.h ../h/time.h ../h/resource.h ../h/namei.h ../h/uio.h
vm_swap.o: ../h/errno.h ../h/proc.h ../h/text.h ../h/map.h ../h/buf.h
vm_swap.o: ../h/cmap.h ../h/vm.h ../h/vmparam.h ../h/../machine/vmparam.h
vm_swap.o: ../h/vmmac.h ../h/vmmeter.h ../h/vmsystm.h ../sys/../machine/cpu.h
vm_swap.o: ../sys/../machine/pte.h ../sys/../machine/mtpr.h
vm_swp.o: ../sys/vm_swp.c ../sys/../machine/pte.h ../h/param.h ../h/types.h
vm_swp.o: ../h/signal.h ../h/../machine/trap.h ../h/../machine/machparam.h
vm_swp.o: machine/endian.h ../h/systm.h ../h/dir.h ../h/user.h
vm_swp.o: ../h/../machine/pcb.h ../h/dmap.h ../h/time.h ../h/resource.h
vm_swp.o: ../h/namei.h ../h/uio.h ../h/errno.h ../h/buf.h ../h/conf.h
vm_swp.o: ../h/proc.h ../h/seg.h ../h/vm.h ../h/vmparam.h
vm_swp.o: ../h/../machine/vmparam.h ../h/vmmac.h ../h/vmmeter.h ../h/vmsystm.h
vm_swp.o: ../h/trace.h ../h/map.h ../h/uio.h
vm_text.o: ../sys/vm_text.c ../h/param.h ../h/types.h ../h/signal.h
vm_text.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
vm_text.o: ../h/systm.h ../h/map.h ../h/dir.h ../h/user.h ../h/../machine/pcb.h
vm_text.o: ../h/dmap.h ../h/time.h ../h/resource.h ../h/namei.h ../h/uio.h
vm_text.o: ../h/errno.h ../h/proc.h ../h/text.h ../h/inode.h ../h/buf.h
vm_text.o: ../h/seg.h ../h/vm.h ../h/vmparam.h ../h/../machine/vmparam.h
vm_text.o: ../h/vmmac.h ../h/vmmeter.h ../h/vmsystm.h ../h/cmap.h ../h/uio.h
vm_text.o: ../h/exec.h ../sys/../machine/pte.h ../sys/../machine/cpu.h
autoconf.o: ../vax/autoconf.c mba.h uba.h kra.h ../h/param.h ../h/types.h
autoconf.o: ../h/signal.h ../h/../machine/trap.h ../h/../machine/machparam.h
autoconf.o: machine/endian.h ../h/systm.h ../h/map.h ../h/buf.h ../h/dkstat.h
autoconf.o: ../h/vm.h ../h/vmparam.h ../h/../machine/vmparam.h ../h/vmmac.h
autoconf.o: ../h/vmmeter.h ../h/vmsystm.h ../h/malloc.h ../h/conf.h ../h/dmap.h
autoconf.o: ../h/reboot.h ../vax/pte.h ../vax/cpu.h ../vax/mem.h ../vax/mtpr.h
autoconf.o: ../vax/nexus.h ../vax/scb.h ../vax/ioa.h ../vax/../vaxbi/bireg.h
autoconf.o: ../vax/../vaxmba/mbareg.h ../vax/../vaxmba/mbavar.h
autoconf.o: ../vax/../vaxuba/ubareg.h ../vax/../vaxuba/ubavar.h bi.h
clock.o: ../vax/clock.c ../h/param.h ../h/types.h ../h/signal.h
clock.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
clock.o: ../h/time.h ../h/kernel.h ../vax/mtpr.h ../vax/clock.h ../vax/cpu.h
conf.o: ../vax/conf.c ../h/param.h ../h/types.h ../h/signal.h
conf.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
conf.o: ../h/systm.h ../h/buf.h ../h/ioctl.h ../h/ttychars.h ../h/ttydev.h
conf.o: ../h/tty.h ../h/ttychars.h ../h/ttydev.h ../h/conf.h hp.h tu.h rk.h
conf.o: te.h tms.h ts.h mu.h ra.h kra.h up.h tj.h rb.h rx.h uu.h rl.h np.h
conf.o: acc.h ct.h dh.h dmf.h dz.h lp.h va.h vp.h pty.h lpa.h dn.h ik.h ps.h
conf.o: ad.h dhu.h vs.h dmz.h qv.h qd.h
cons.o: ../vax/cons.c ../h/param.h ../h/types.h ../h/signal.h
cons.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
cons.o: ../h/conf.h ../h/dir.h ../h/user.h ../h/../machine/pcb.h ../h/dmap.h
cons.o: ../h/time.h ../h/resource.h ../h/namei.h ../h/uio.h ../h/errno.h
cons.o: ../h/proc.h ../h/ioctl.h ../h/ttychars.h ../h/ttydev.h ../h/tty.h
cons.o: ../h/ttychars.h ../h/ttydev.h ../h/systm.h ../h/uio.h ../vax/cpu.h
cons.o: ../vax/cons.h ../vax/mtpr.h
cpudata.o: ../vax/cpudata.c ../vax/pte.h ../h/param.h ../h/types.h
cpudata.o: ../h/signal.h ../h/../machine/trap.h ../h/../machine/machparam.h
cpudata.o: machine/endian.h ../vax/cpu.h ../vax/nexus.h ../vax/ioa.h
cpudata.o: ../vax/../vaxbi/bireg.h ../vax/../vaxuba/ubareg.h
crl.o: ../vax/crl.c ../h/param.h ../h/types.h ../h/signal.h
crl.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
crl.o: ../h/systm.h ../h/conf.h ../h/dir.h ../h/user.h ../h/../machine/pcb.h
crl.o: ../h/dmap.h ../h/time.h ../h/resource.h ../h/namei.h ../h/uio.h
crl.o: ../h/errno.h ../h/buf.h ../h/uio.h ../vax/cons.h ../vax/cpu.h
crl.o: ../vax/crl.h ../vax/mtpr.h
dkbad.o: ../vax/dkbad.c ../h/param.h ../h/types.h ../h/signal.h
dkbad.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
dkbad.o: ../h/buf.h ../h/dkbad.h
flp.o: ../vax/flp.c ../h/param.h ../h/types.h ../h/signal.h
flp.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
flp.o: ../h/systm.h ../h/conf.h ../h/dir.h ../h/user.h ../h/../machine/pcb.h
flp.o: ../h/dmap.h ../h/time.h ../h/resource.h ../h/namei.h ../h/uio.h
flp.o: ../h/errno.h ../h/buf.h ../h/uio.h ../vax/cons.h ../vax/cpu.h
flp.o: ../vax/flp.h ../vax/mtpr.h
in_cksum.o: ../vax/in_cksum.c ../h/types.h ../h/mbuf.h
ka650.o: ../vax/ka650.c ../h/param.h ../h/types.h ../h/signal.h
ka650.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
ka650.o: ../h/time.h ../h/kernel.h ../h/systm.h ../vax/cpu.h ../vax/clock.h
ka650.o: ../vax/psl.h ../vax/mem.h ../vax/mtpr.h ../vax/ka650.h
ka630.o: ../vax/ka630.c ../h/param.h ../h/types.h ../h/signal.h
ka630.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
ka630.o: ../h/time.h ../h/kernel.h ../h/vmmac.h ../vax/mtpr.h ../vax/cpu.h
ka630.o: ../vax/clock.h ../vax/pte.h ../vax/ka630.h
ka730.o: ../vax/ka730.c ../h/param.h ../h/types.h ../h/signal.h
ka730.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
ka730.o: ../vax/cpu.h ../vax/mem.h ../vax/mtpr.h
ka750.o: ../vax/ka750.c ../h/param.h ../h/types.h ../h/signal.h
ka750.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
ka750.o: ../vax/cpu.h ../vax/mem.h ../vax/mtpr.h
ka780.o: ../vax/ka780.c ../h/param.h ../h/types.h ../h/signal.h
ka780.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
ka780.o: ../vax/cpu.h ../vax/mem.h ../vax/mtpr.h
ka820.o: ../vax/ka820.c ../h/param.h ../h/types.h ../h/signal.h
ka820.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
ka820.o: ../h/time.h ../h/kernel.h ../h/vmmac.h ../vax/cpu.h ../vax/clock.h
ka820.o: ../vax/ka820.h ../vax/mem.h ../vax/mtpr.h ../vax/pte.h
ka820.o: ../vax/../vaxbi/bireg.h
ka860.o: ../vax/ka860.c ../h/param.h ../h/types.h ../h/signal.h
ka860.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
ka860.o: ../vax/cpu.h ../vax/mtpr.h
machdep.o: ../vax/machdep.c ../h/param.h ../h/types.h ../h/signal.h
machdep.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
machdep.o: ../h/systm.h ../h/dir.h ../h/user.h ../h/../machine/pcb.h
machdep.o: ../h/dmap.h ../h/time.h ../h/resource.h ../h/namei.h ../h/uio.h
machdep.o: ../h/errno.h ../h/kernel.h ../h/malloc.h ../h/map.h ../h/vm.h
machdep.o: ../h/vmparam.h ../h/../machine/vmparam.h ../h/vmmac.h ../h/vmmeter.h
machdep.o: ../h/vmsystm.h ../h/proc.h ../h/buf.h ../h/reboot.h ../h/conf.h
machdep.o: ../h/inode.h ../h/file.h ../h/text.h ../h/clist.h ../h/callout.h
machdep.o: ../h/cmap.h ../h/mbuf.h ../h/msgbuf.h ../h/quota.h ../vax/reg.h
machdep.o: ../vax/pte.h ../vax/psl.h ../vax/frame.h ../vax/clock.h
machdep.o: ../vax/cons.h ../vax/cpu.h ../vax/mem.h ../vax/mtpr.h ../vax/rpb.h
machdep.o: ../vax/ka630.h ../vax/ka650.h ../vax/../vaxuba/ubavar.h
machdep.o: ../vax/../vaxuba/ubareg.h qv.h qd.h
mem.o: ../vax/mem.c ../vax/pte.h ../h/param.h ../h/types.h ../h/signal.h
mem.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
mem.o: ../h/dir.h ../h/user.h ../h/../machine/pcb.h ../h/dmap.h ../h/time.h
mem.o: ../h/resource.h ../h/namei.h ../h/uio.h ../h/errno.h ../h/conf.h
mem.o: ../h/buf.h ../h/systm.h ../h/vm.h ../h/vmparam.h
mem.o: ../h/../machine/vmparam.h ../h/vmmac.h ../h/vmmeter.h ../h/vmsystm.h
mem.o: ../h/cmap.h ../h/uio.h ../vax/mtpr.h
mscp.o: ../vax/mscp.c ../h/param.h ../h/types.h ../h/signal.h
mscp.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
mscp.o: ../h/buf.h ../h/errno.h ../h/dkstat.h ../h/ioctl.h ../h/ttychars.h
mscp.o: ../h/ttydev.h ../h/disklabel.h ../h/syslog.h ../vax/../vaxuba/ubavar.h
mscp.o: ../vax/mscp.h ../vax/mscpvar.h
ns_cksum.o: ../vax/ns_cksum.c ../h/types.h ../h/mbuf.h
rx50.o: ../vax/rx50.c ../h/param.h ../h/types.h ../h/signal.h
rx50.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
rx50.o: ../h/time.h ../h/kernel.h ../h/vmmac.h ../h/buf.h ../h/errno.h
rx50.o: ../h/uio.h ../vax/cpu.h ../vax/rx50reg.h
sys_machdep.o: ../vax/sys_machdep.c ../h/param.h ../h/types.h ../h/signal.h
sys_machdep.o: ../h/../machine/trap.h ../h/../machine/machparam.h
sys_machdep.o: machine/endian.h ../h/systm.h ../h/dir.h ../h/user.h
sys_machdep.o: ../h/../machine/pcb.h ../h/dmap.h ../h/time.h ../h/resource.h
sys_machdep.o: ../h/namei.h ../h/uio.h ../h/errno.h ../h/ioctl.h
sys_machdep.o: ../h/ttychars.h ../h/ttydev.h ../h/file.h ../h/proc.h ../h/uio.h
sys_machdep.o: ../h/kernel.h ../h/mtio.h ../h/buf.h ../h/trace.h ../vax/dkio.h
sys_machdep.o: ../vax/pte.h ../vax/../vaxuba/ubareg.h ../vax/../vaxuba/ubavar.h
trap.o: ../vax/trap.c ../vax/psl.h ../vax/reg.h ../vax/pte.h ../vax/vmparam.h
trap.o: ../h/param.h ../h/types.h ../h/signal.h ../h/../machine/trap.h
trap.o: ../h/../machine/machparam.h machine/endian.h ../h/systm.h ../h/dir.h
trap.o: ../h/user.h ../h/../machine/pcb.h ../h/dmap.h ../h/time.h
trap.o: ../h/resource.h ../h/namei.h ../h/uio.h ../h/errno.h assym.s
trap.o: ../h/proc.h ../h/seg.h ../vax/trap.h ../h/acct.h ../h/kernel.h
trap.o: ../vax/mtpr.h
tu.o: ../vax/tu.c ../h/param.h ../h/types.h ../h/signal.h
tu.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
tu.o: ../h/systm.h ../h/buf.h ../h/conf.h ../h/dir.h ../h/user.h
tu.o: ../h/../machine/pcb.h ../h/dmap.h ../h/time.h ../h/resource.h
tu.o: ../h/namei.h ../h/uio.h ../h/errno.h ../h/kernel.h ../vax/cpu.h
tu.o: ../vax/mtpr.h ../vax/rsp.h
ufs_machdep.o: ../vax/ufs_machdep.c ../vax/pte.h ../h/param.h ../h/types.h
ufs_machdep.o: ../h/signal.h ../h/../machine/trap.h ../h/../machine/machparam.h
ufs_machdep.o: machine/endian.h ../h/systm.h ../h/dir.h ../h/user.h
ufs_machdep.o: ../h/../machine/pcb.h ../h/dmap.h ../h/time.h ../h/resource.h
ufs_machdep.o: ../h/namei.h ../h/uio.h ../h/errno.h ../h/buf.h ../h/conf.h
ufs_machdep.o: ../h/proc.h ../h/seg.h ../h/vm.h ../h/vmparam.h
ufs_machdep.o: ../h/../machine/vmparam.h ../h/vmmac.h ../h/vmmeter.h
ufs_machdep.o: ../h/vmsystm.h
vm_machdep.o: ../vax/vm_machdep.c ../h/param.h ../h/types.h ../h/signal.h
vm_machdep.o: ../h/../machine/trap.h ../h/../machine/machparam.h
vm_machdep.o: machine/endian.h ../h/systm.h ../h/dir.h ../h/user.h
vm_machdep.o: ../h/../machine/pcb.h ../h/dmap.h ../h/time.h ../h/resource.h
vm_machdep.o: ../h/namei.h ../h/uio.h ../h/errno.h ../h/proc.h ../h/cmap.h
vm_machdep.o: ../h/mount.h ../h/vm.h ../h/vmparam.h ../h/../machine/vmparam.h
vm_machdep.o: ../h/vmmac.h ../h/vmmeter.h ../h/vmsystm.h ../h/text.h
vm_machdep.o: ../vax/pte.h ../vax/mtpr.h
bi.o: ../vaxbi/bi.c ../h/param.h ../h/types.h ../h/signal.h
bi.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
bi.o: ../vaxbi/../vax/cpu.h ../vaxbi/../vax/mtpr.h ../vaxbi/../vax/nexus.h
bi.o: ../vaxbi/bireg.h
kdb.o: ../vaxbi/kdb.c kra.h ../h/param.h ../h/types.h ../h/signal.h
kdb.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
kdb.o: ../h/systm.h ../h/malloc.h ../h/map.h ../h/buf.h ../h/conf.h ../h/dir.h
kdb.o: ../h/user.h ../h/../machine/pcb.h ../h/dmap.h ../h/time.h
kdb.o: ../h/resource.h ../h/namei.h ../h/uio.h ../h/errno.h ../h/proc.h
kdb.o: ../h/vm.h ../h/vmparam.h ../h/../machine/vmparam.h ../h/vmmac.h
kdb.o: ../h/vmmeter.h ../h/vmsystm.h ../h/dkstat.h ../h/cmap.h ../h/syslog.h
kdb.o: ../h/kernel.h ../vaxbi/../vax/pte.h ../vaxbi/../vax/cpu.h
kdb.o: ../vaxbi/../vax/mscp.h ../vaxbi/../vax/mscpvar.h ../vaxbi/../vax/mtpr.h
kdb.o: ../vaxbi/bireg.h ../vaxbi/kdbreg.h ../vaxbi/../vaxuba/ubavar.h
if_de.o: ../vaxif/if_de.c de.h ../vaxif/../machine/pte.h ../h/param.h
if_de.o: ../h/types.h ../h/signal.h ../h/../machine/trap.h
if_de.o: ../h/../machine/machparam.h machine/endian.h ../h/systm.h ../h/mbuf.h
if_de.o: ../h/buf.h ../h/protosw.h ../h/socket.h ../h/vmmac.h ../h/ioctl.h
if_de.o: ../h/ttychars.h ../h/ttydev.h ../h/errno.h ../h/syslog.h
if_de.o: ../vaxif/../net/if.h ../vaxif/../net/../net/if_arp.h
if_de.o: ../vaxif/../net/netisr.h ../vaxif/../net/route.h
if_de.o: ../vaxif/../netinet/in.h ../vaxif/../netinet/in_systm.h
if_de.o: ../vaxif/../netinet/in_var.h ../vaxif/../netinet/ip.h
if_de.o: ../vaxif/../netinet/if_ether.h ../vaxif/../netns/ns.h
if_de.o: ../vaxif/../netns/ns_if.h ../vaxif/../vax/cpu.h ../vaxif/../vax/mtpr.h
if_de.o: ../vaxif/if_dereg.h ../vaxif/if_uba.h ../vaxif/../vaxuba/ubareg.h
if_de.o: ../vaxif/../vaxuba/ubavar.h
if_ec.o: ../vaxif/if_ec.c ec.h ../vaxif/../machine/pte.h ../h/param.h
if_ec.o: ../h/types.h ../h/signal.h ../h/../machine/trap.h
if_ec.o: ../h/../machine/machparam.h machine/endian.h ../h/systm.h ../h/mbuf.h
if_ec.o: ../h/buf.h ../h/protosw.h ../h/socket.h ../h/syslog.h ../h/vmmac.h
if_ec.o: ../h/ioctl.h ../h/ttychars.h ../h/ttydev.h ../h/errno.h
if_ec.o: ../vaxif/../net/if.h ../vaxif/../net/../net/if_arp.h
if_ec.o: ../vaxif/../net/netisr.h ../vaxif/../net/route.h
if_ec.o: ../vaxif/../netinet/in.h ../vaxif/../netinet/in_systm.h
if_ec.o: ../vaxif/../netinet/in_var.h ../vaxif/../netinet/ip.h
if_ec.o: ../vaxif/../netinet/if_ether.h ../vaxif/../netns/ns.h
if_ec.o: ../vaxif/../netns/ns_if.h ../vaxif/../vax/cpu.h ../vaxif/../vax/mtpr.h
if_ec.o: ../vaxif/if_ecreg.h ../vaxif/if_uba.h ../vaxif/../vaxuba/ubareg.h
if_ec.o: ../vaxif/../vaxuba/ubavar.h
if_ex.o: ../vaxif/if_ex.c ex.h ../h/param.h ../h/types.h ../h/signal.h
if_ex.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
if_ex.o: ../h/systm.h ../h/mbuf.h ../h/buf.h ../h/protosw.h ../h/socket.h
if_ex.o: ../h/vmmac.h ../h/ioctl.h ../h/ttychars.h ../h/ttydev.h ../h/syslog.h
if_ex.o: ../h/errno.h ../vaxif/../net/if.h ../vaxif/../net/../net/if_arp.h
if_ex.o: ../vaxif/../net/netisr.h ../vaxif/../net/route.h
if_ex.o: ../vaxif/../netinet/in.h ../vaxif/../netinet/in_systm.h
if_ex.o: ../vaxif/../netinet/in_var.h ../vaxif/../netinet/ip.h
if_ex.o: ../vaxif/../netinet/if_ether.h ../vaxif/../netns/ns.h
if_ex.o: ../vaxif/../netns/ns_if.h ../vaxif/../vax/pte.h ../vaxif/../vax/cpu.h
if_ex.o: ../vaxif/../vax/mtpr.h ../vaxif/if_exreg.h ../vaxif/if_uba.h
if_ex.o: ../vaxif/../vaxuba/ubareg.h ../vaxif/../vaxuba/ubavar.h
if_il.o: ../vaxif/if_il.c il.h ../vaxif/../machine/pte.h ../h/param.h
if_il.o: ../h/types.h ../h/signal.h ../h/../machine/trap.h
if_il.o: ../h/../machine/machparam.h machine/endian.h ../h/systm.h ../h/mbuf.h
if_il.o: ../h/buf.h ../h/protosw.h ../h/socket.h ../h/vmmac.h ../h/ioctl.h
if_il.o: ../h/ttychars.h ../h/ttydev.h ../h/errno.h ../h/syslog.h
if_il.o: ../vaxif/../net/if.h ../vaxif/../net/../net/if_arp.h
if_il.o: ../vaxif/../net/netisr.h ../vaxif/../net/route.h
if_il.o: ../vaxif/../netinet/in.h ../vaxif/../netinet/in_systm.h
if_il.o: ../vaxif/../netinet/in_var.h ../vaxif/../netinet/ip.h
if_il.o: ../vaxif/../netinet/if_ether.h ../vaxif/../netns/ns.h
if_il.o: ../vaxif/../netns/ns_if.h ../vaxif/../vax/cpu.h ../vaxif/../vax/mtpr.h
if_il.o: ../vaxif/if_il.h ../vaxif/if_ilreg.h ../vaxif/if_uba.h
if_il.o: ../vaxif/../vaxuba/ubareg.h ../vaxif/../vaxuba/ubavar.h
if_qe.o: ../vaxif/if_qe.c qe.h ../h/param.h ../h/types.h ../h/signal.h
if_qe.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
if_qe.o: ../h/systm.h ../h/mbuf.h ../h/buf.h ../h/protosw.h ../h/socket.h
if_qe.o: ../h/vmmac.h ../h/ioctl.h ../h/ttychars.h ../h/ttydev.h ../h/errno.h
if_qe.o: ../h/syslog.h ../h/time.h ../h/kernel.h ../vaxif/../net/if.h
if_qe.o: ../vaxif/../net/../net/if_arp.h ../vaxif/../net/netisr.h
if_qe.o: ../vaxif/../net/route.h ../vaxif/../netinet/in.h
if_qe.o: ../vaxif/../netinet/in_systm.h ../vaxif/../netinet/in_var.h
if_qe.o: ../vaxif/../netinet/ip.h ../vaxif/../netinet/if_ether.h
if_qe.o: ../vaxif/../netns/ns.h ../vaxif/../netns/ns_if.h ../vaxif/../vax/pte.h
if_qe.o: ../vaxif/../vax/cpu.h ../vaxif/../vax/mtpr.h ../vaxif/if_qereg.h
if_qe.o: ../vaxif/if_uba.h ../vaxif/../vaxuba/ubareg.h
if_qe.o: ../vaxif/../vaxuba/ubavar.h
if_uba.o: ../vaxif/if_uba.c ../h/param.h ../h/types.h ../h/signal.h
if_uba.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
if_uba.o: ../h/systm.h ../h/mbuf.h ../h/map.h ../h/buf.h ../h/cmap.h
if_uba.o: ../h/vmmac.h ../h/socket.h ../h/syslog.h ../h/malloc.h
if_uba.o: ../vaxif/../net/if.h ../vaxif/../net/../net/if_arp.h
if_uba.o: ../vaxif/../vax/pte.h ../vaxif/../vax/mtpr.h ../vaxif/if_uba.h
if_uba.o: ../vaxif/../vaxuba/ubareg.h ../vaxif/../vaxuba/ubavar.h
hp.o: ../vaxmba/hp.c hp.h ../h/param.h ../h/types.h ../h/signal.h
hp.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
hp.o: ../h/systm.h ../h/dkstat.h ../h/buf.h ../h/conf.h ../h/dir.h ../h/file.h
hp.o: ../h/user.h ../h/../machine/pcb.h ../h/dmap.h ../h/time.h ../h/resource.h
hp.o: ../h/namei.h ../h/uio.h ../h/errno.h ../h/map.h ../vaxmba/../vax/mtpr.h
hp.o: ../h/vm.h ../h/vmparam.h ../h/../machine/vmparam.h ../h/vmmac.h
hp.o: ../h/vmmeter.h ../h/vmsystm.h ../h/cmap.h ../h/dkbad.h ../h/disklabel.h
hp.o: ../h/ioctl.h ../h/ttychars.h ../h/ttydev.h ../h/uio.h ../h/syslog.h
hp.o: ../h/stat.h ../vaxmba/../machine/pte.h ../vaxmba/../vax/dkio.h
hp.o: ../vaxmba/mbareg.h ../vaxmba/mbavar.h ../vaxmba/hpreg.h
ht.o: ../vaxmba/ht.c tu.h ../h/param.h ../h/types.h ../h/signal.h
ht.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
ht.o: ../h/systm.h ../h/buf.h ../h/conf.h ../h/dir.h ../h/file.h ../h/user.h
ht.o: ../h/../machine/pcb.h ../h/dmap.h ../h/time.h ../h/resource.h
ht.o: ../h/namei.h ../h/uio.h ../h/errno.h ../h/map.h ../h/ioctl.h
ht.o: ../h/ttychars.h ../h/ttydev.h ../h/mtio.h ../h/cmap.h ../h/uio.h
ht.o: ../h/tty.h ../h/ttychars.h ../h/ttydev.h ../h/syslog.h
ht.o: ../vaxmba/../machine/pte.h ../vaxmba/../vax/cpu.h ../vaxmba/mbareg.h
ht.o: ../vaxmba/mbavar.h ../vaxmba/htreg.h
mba.o: ../vaxmba/mba.c mba.h ../vaxmba/../machine/pte.h ../h/param.h
mba.o: ../h/types.h ../h/signal.h ../h/../machine/trap.h
mba.o: ../h/../machine/machparam.h machine/endian.h ../h/systm.h ../h/dkstat.h
mba.o: ../h/buf.h ../h/conf.h ../h/dir.h ../h/user.h ../h/../machine/pcb.h
mba.o: ../h/dmap.h ../h/time.h ../h/resource.h ../h/namei.h ../h/uio.h
mba.o: ../h/errno.h ../h/proc.h ../h/map.h ../vaxmba/../vax/mtpr.h ../h/vm.h
mba.o: ../h/vmparam.h ../h/../machine/vmparam.h ../h/vmmac.h ../h/vmmeter.h
mba.o: ../h/vmsystm.h ../vaxmba/mbareg.h ../vaxmba/mbavar.h
mt.o: ../vaxmba/mt.c mu.h ../h/param.h ../h/types.h ../h/signal.h
mt.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
mt.o: ../h/systm.h ../h/buf.h ../h/conf.h ../h/dir.h ../h/file.h ../h/user.h
mt.o: ../h/../machine/pcb.h ../h/dmap.h ../h/time.h ../h/resource.h
mt.o: ../h/namei.h ../h/uio.h ../h/errno.h ../h/map.h ../h/ioctl.h
mt.o: ../h/ttychars.h ../h/ttydev.h ../h/mtio.h ../h/cmap.h ../h/uio.h
mt.o: ../h/tty.h ../h/ttychars.h ../h/ttydev.h ../h/syslog.h
mt.o: ../vaxmba/../vax/pte.h ../vaxmba/../vax/cpu.h ../vaxmba/mbareg.h
mt.o: ../vaxmba/mbavar.h ../vaxmba/mtreg.h
dh.o: ../vaxuba/dh.c dh.h ../vaxuba/../machine/pte.h bk.h uba.h ../h/param.h
dh.o: ../h/types.h ../h/signal.h ../h/../machine/trap.h
dh.o: ../h/../machine/machparam.h machine/endian.h ../h/conf.h ../h/dir.h
dh.o: ../h/user.h ../h/../machine/pcb.h ../h/dmap.h ../h/time.h ../h/resource.h
dh.o: ../h/namei.h ../h/uio.h ../h/errno.h ../h/proc.h ../h/ioctl.h
dh.o: ../h/ttychars.h ../h/ttydev.h ../h/tty.h ../h/ttychars.h ../h/ttydev.h
dh.o: ../h/map.h ../h/buf.h ../h/vm.h ../h/vmparam.h ../h/../machine/vmparam.h
dh.o: ../h/vmmac.h ../h/vmmeter.h ../h/vmsystm.h ../h/kernel.h ../h/syslog.h
dh.o: ../vaxuba/ubareg.h ../vaxuba/ubavar.h ../vaxuba/dhreg.h ../vaxuba/dmreg.h
dh.o: ../h/bkmac.h ../h/clist.h ../h/file.h ../h/uio.h
dhu.o: ../vaxuba/dhu.c dhu.h ../vaxuba/../machine/pte.h bk.h ../h/param.h
dhu.o: ../h/types.h ../h/signal.h ../h/../machine/trap.h
dhu.o: ../h/../machine/machparam.h machine/endian.h ../h/conf.h ../h/dir.h
dhu.o: ../h/user.h ../h/../machine/pcb.h ../h/dmap.h ../h/time.h
dhu.o: ../h/resource.h ../h/namei.h ../h/uio.h ../h/errno.h ../h/proc.h
dhu.o: ../h/ioctl.h ../h/ttychars.h ../h/ttydev.h ../h/tty.h ../h/ttychars.h
dhu.o: ../h/ttydev.h ../h/map.h ../h/buf.h ../h/vm.h ../h/vmparam.h
dhu.o: ../h/../machine/vmparam.h ../h/vmmac.h ../h/vmmeter.h ../h/vmsystm.h
dhu.o: ../h/kernel.h ../h/syslog.h uba.h ../vaxuba/ubareg.h ../vaxuba/ubavar.h
dhu.o: ../vaxuba/dhureg.h ../h/bkmac.h ../h/clist.h ../h/file.h ../h/uio.h
dmf.o: ../vaxuba/dmf.c dmf.h ../vaxuba/../machine/pte.h bk.h uba.h ../h/param.h
dmf.o: ../h/types.h ../h/signal.h ../h/../machine/trap.h
dmf.o: ../h/../machine/machparam.h machine/endian.h ../h/conf.h ../h/dir.h
dmf.o: ../h/user.h ../h/../machine/pcb.h ../h/dmap.h ../h/time.h
dmf.o: ../h/resource.h ../h/namei.h ../h/uio.h ../h/errno.h ../h/proc.h
dmf.o: ../h/ioctl.h ../h/ttychars.h ../h/ttydev.h ../h/tty.h ../h/ttychars.h
dmf.o: ../h/ttydev.h ../h/map.h ../h/buf.h ../h/vm.h ../h/vmparam.h
dmf.o: ../h/../machine/vmparam.h ../h/vmmac.h ../h/vmmeter.h ../h/vmsystm.h
dmf.o: ../h/bkmac.h ../h/clist.h ../h/file.h ../h/uio.h ../h/kernel.h
dmf.o: ../h/syslog.h ../vaxuba/dmx.h ../vaxuba/ubareg.h ../vaxuba/ubavar.h
dmf.o: ../vaxuba/dmxreg.h ../vaxuba/dmfreg.h ../vaxuba/dmreg.h
dmx.o: ../vaxuba/dmx.c dmf.h dmz.h ../vaxuba/../machine/pte.h bk.h uba.h
dmx.o: ../h/param.h ../h/types.h ../h/signal.h ../h/../machine/trap.h
dmx.o: ../h/../machine/machparam.h machine/endian.h ../h/conf.h ../h/dir.h
dmx.o: ../h/user.h ../h/../machine/pcb.h ../h/dmap.h ../h/time.h
dmx.o: ../h/resource.h ../h/namei.h ../h/uio.h ../h/errno.h ../h/proc.h
dmx.o: ../h/ioctl.h ../h/ttychars.h ../h/ttydev.h ../h/tty.h ../h/ttychars.h
dmx.o: ../h/ttydev.h ../h/map.h ../h/buf.h ../h/vm.h ../h/vmparam.h
dmx.o: ../h/../machine/vmparam.h ../h/vmmac.h ../h/vmmeter.h ../h/vmsystm.h
dmx.o: ../h/bkmac.h ../h/clist.h ../h/file.h ../h/uio.h ../h/kernel.h
dmx.o: ../h/syslog.h ../vaxuba/dmx.h ../vaxuba/ubareg.h ../vaxuba/ubavar.h
dmx.o: ../vaxuba/dmxreg.h ../vaxuba/dmreg.h
dmz.o: ../vaxuba/dmz.c dmz.h ../vaxuba/../machine/pte.h bk.h uba.h ../h/param.h
dmz.o: ../h/types.h ../h/signal.h ../h/../machine/trap.h
dmz.o: ../h/../machine/machparam.h machine/endian.h ../h/conf.h ../h/dir.h
dmz.o: ../h/user.h ../h/../machine/pcb.h ../h/dmap.h ../h/time.h
dmz.o: ../h/resource.h ../h/namei.h ../h/uio.h ../h/errno.h ../h/proc.h
dmz.o: ../h/ioctl.h ../h/ttychars.h ../h/ttydev.h ../h/tty.h ../h/ttychars.h
dmz.o: ../h/ttydev.h ../h/map.h ../h/buf.h ../h/vm.h ../h/vmparam.h
dmz.o: ../h/../machine/vmparam.h ../h/vmmac.h ../h/vmmeter.h ../h/vmsystm.h
dmz.o: ../h/bkmac.h ../h/clist.h ../h/file.h ../h/uio.h ../h/kernel.h
dmz.o: ../h/syslog.h ../vaxuba/dmx.h ../vaxuba/ubareg.h ../vaxuba/ubavar.h
dmz.o: ../vaxuba/dmxreg.h ../vaxuba/dmzreg.h ../vaxuba/dmreg.h
dz.o: ../vaxuba/dz.c dz.h bk.h ../vaxuba/../machine/pte.h ../h/param.h
dz.o: ../h/types.h ../h/signal.h ../h/../machine/trap.h
dz.o: ../h/../machine/machparam.h machine/endian.h ../h/systm.h ../h/ioctl.h
dz.o: ../h/ttychars.h ../h/ttydev.h ../h/tty.h ../h/ttychars.h ../h/ttydev.h
dz.o: ../h/dir.h ../h/user.h ../h/../machine/pcb.h ../h/dmap.h ../h/time.h
dz.o: ../h/resource.h ../h/namei.h ../h/uio.h ../h/errno.h ../h/proc.h
dz.o: ../h/map.h ../h/buf.h ../h/vm.h ../h/vmparam.h ../h/../machine/vmparam.h
dz.o: ../h/vmmac.h ../h/vmmeter.h ../h/vmsystm.h ../h/conf.h ../h/bkmac.h
dz.o: ../h/file.h ../h/uio.h ../h/kernel.h ../h/syslog.h ../vaxuba/pdma.h
dz.o: ../vaxuba/ubavar.h ../vaxuba/dzreg.h
idc.o: ../vaxuba/idc.c rb.h ../h/param.h ../h/types.h ../h/signal.h
idc.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
idc.o: ../h/systm.h ../h/buf.h ../h/conf.h ../h/dir.h ../h/user.h
idc.o: ../h/../machine/pcb.h ../h/dmap.h ../h/time.h ../h/resource.h
idc.o: ../h/namei.h ../h/uio.h ../h/errno.h ../h/map.h ../h/vm.h ../h/vmparam.h
idc.o: ../h/../machine/vmparam.h ../h/vmmac.h ../h/vmmeter.h ../h/vmsystm.h
idc.o: ../h/ioctl.h ../h/ttychars.h ../h/ttydev.h ../h/disklabel.h
idc.o: ../h/dkstat.h ../h/cmap.h ../h/dkbad.h ../h/uio.h ../h/kernel.h
idc.o: ../h/syslog.h ../vaxuba/../machine/pte.h ../vaxuba/../vax/cpu.h
idc.o: ../vaxuba/ubareg.h ../vaxuba/ubavar.h ../vaxuba/idcreg.h
lp.o: ../vaxuba/lp.c lp.h ../vaxuba/../machine/pte.h ../h/param.h ../h/types.h
lp.o: ../h/signal.h ../h/../machine/trap.h ../h/../machine/machparam.h
lp.o: machine/endian.h ../h/dir.h ../h/user.h ../h/../machine/pcb.h ../h/dmap.h
lp.o: ../h/time.h ../h/resource.h ../h/namei.h ../h/uio.h ../h/errno.h
lp.o: ../h/buf.h ../h/systm.h ../h/map.h ../h/uio.h ../h/ioctl.h
lp.o: ../h/ttychars.h ../h/ttydev.h ../h/tty.h ../h/ttychars.h ../h/ttydev.h
lp.o: ../h/kernel.h ../vaxuba/ubavar.h
rk.o: ../vaxuba/rk.c rk.h ../vaxuba/../machine/pte.h ../h/param.h ../h/types.h
rk.o: ../h/signal.h ../h/../machine/trap.h ../h/../machine/machparam.h
rk.o: machine/endian.h ../h/systm.h ../h/buf.h ../h/conf.h ../h/dir.h
rk.o: ../h/user.h ../h/../machine/pcb.h ../h/dmap.h ../h/time.h ../h/resource.h
rk.o: ../h/namei.h ../h/uio.h ../h/errno.h ../h/map.h ../h/vm.h ../h/vmparam.h
rk.o: ../h/../machine/vmparam.h ../h/vmmac.h ../h/vmmeter.h ../h/vmsystm.h
rk.o: ../h/dkstat.h ../h/cmap.h ../h/dkbad.h ../h/ioctl.h ../h/ttychars.h
rk.o: ../h/ttydev.h ../h/disklabel.h ../h/uio.h ../h/kernel.h ../h/syslog.h
rk.o: ../vaxuba/../vax/cpu.h ../vaxuba/ubareg.h ../vaxuba/ubavar.h
rk.o: ../vaxuba/rkreg.h
rl.o: ../vaxuba/rl.c rl.h ../vaxuba/../machine/pte.h ../h/param.h ../h/types.h
rl.o: ../h/signal.h ../h/../machine/trap.h ../h/../machine/machparam.h
rl.o: machine/endian.h ../h/systm.h ../h/dkstat.h ../h/dkbad.h ../h/ioctl.h
rl.o: ../h/ttychars.h ../h/ttydev.h ../h/disklabel.h ../h/buf.h ../h/conf.h
rl.o: ../h/dir.h ../h/user.h ../h/../machine/pcb.h ../h/dmap.h ../h/time.h
rl.o: ../h/resource.h ../h/namei.h ../h/uio.h ../h/errno.h ../h/map.h ../h/vm.h
rl.o: ../h/vmparam.h ../h/../machine/vmparam.h ../h/vmmac.h ../h/vmmeter.h
rl.o: ../h/vmsystm.h ../h/cmap.h ../h/uio.h ../h/kernel.h ../h/syslog.h
rl.o: ../vaxuba/../vax/cpu.h ../vaxuba/../vax/nexus.h ../vaxuba/ubavar.h
rl.o: ../vaxuba/ubareg.h ../vaxuba/rlreg.h
tm.o: ../vaxuba/tm.c te.h ts.h ../h/param.h ../h/types.h ../h/signal.h
tm.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
tm.o: ../h/systm.h ../h/buf.h ../h/dir.h ../h/conf.h ../h/user.h
tm.o: ../h/../machine/pcb.h ../h/dmap.h ../h/time.h ../h/resource.h
tm.o: ../h/namei.h ../h/uio.h ../h/errno.h ../h/file.h ../h/map.h ../h/vm.h
tm.o: ../h/vmparam.h ../h/../machine/vmparam.h ../h/vmmac.h ../h/vmmeter.h
tm.o: ../h/vmsystm.h ../h/ioctl.h ../h/ttychars.h ../h/ttydev.h ../h/mtio.h
tm.o: ../h/cmap.h ../h/uio.h ../h/kernel.h ../h/tty.h ../h/ttychars.h
tm.o: ../h/ttydev.h ../h/syslog.h ../vaxuba/../machine/pte.h
tm.o: ../vaxuba/../vax/cpu.h ../vaxuba/ubareg.h ../vaxuba/ubavar.h
tm.o: ../vaxuba/tmreg.h
tmscp.o: ../vaxuba/tmscp.c tms.h ../h/param.h ../h/types.h ../h/signal.h
tmscp.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
tmscp.o: ../h/systm.h ../h/buf.h ../h/conf.h ../h/dir.h ../h/user.h
tmscp.o: ../h/../machine/pcb.h ../h/dmap.h ../h/time.h ../h/resource.h
tmscp.o: ../h/namei.h ../h/uio.h ../h/errno.h ../h/file.h ../h/map.h ../h/vm.h
tmscp.o: ../h/vmparam.h ../h/../machine/vmparam.h ../h/vmmac.h ../h/vmmeter.h
tmscp.o: ../h/vmsystm.h ../h/ioctl.h ../h/ttychars.h ../h/ttydev.h
tmscp.o: ../h/syslog.h ../h/mtio.h ../h/cmap.h ../h/uio.h ../h/tty.h
tmscp.o: ../h/ttychars.h ../h/ttydev.h ../vaxuba/../vax/pte.h
tmscp.o: ../vaxuba/../vax/cpu.h ../vaxuba/../vax/mtpr.h ../vaxuba/ubareg.h
tmscp.o: ../vaxuba/ubavar.h ../vaxuba/tmscpreg.h ../vaxuba/../vax/tmscp.h
ts.o: ../vaxuba/ts.c ts.h ../h/param.h ../h/types.h ../h/signal.h
ts.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
ts.o: ../h/systm.h ../h/buf.h ../h/dir.h ../h/conf.h ../h/user.h
ts.o: ../h/../machine/pcb.h ../h/dmap.h ../h/time.h ../h/resource.h
ts.o: ../h/namei.h ../h/uio.h ../h/errno.h ../h/file.h ../h/map.h ../h/vm.h
ts.o: ../h/vmparam.h ../h/../machine/vmparam.h ../h/vmmac.h ../h/vmmeter.h
ts.o: ../h/vmsystm.h ../h/ioctl.h ../h/ttychars.h ../h/ttydev.h ../h/mtio.h
ts.o: ../h/cmap.h ../h/uio.h ../h/tty.h ../h/ttychars.h ../h/ttydev.h
ts.o: ../h/syslog.h ../vaxuba/../machine/pte.h ../vaxuba/../vax/cpu.h
ts.o: ../vaxuba/ubareg.h ../vaxuba/ubavar.h ../vaxuba/tsreg.h
uba.o: ../vaxuba/uba.c ../h/param.h ../h/types.h ../h/signal.h
uba.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
uba.o: ../h/systm.h ../h/map.h ../h/buf.h ../h/vm.h ../h/vmparam.h
uba.o: ../h/../machine/vmparam.h ../h/vmmac.h ../h/vmmeter.h ../h/vmsystm.h
uba.o: ../h/dir.h ../h/user.h ../h/../machine/pcb.h ../h/dmap.h ../h/time.h
uba.o: ../h/resource.h ../h/namei.h ../h/uio.h ../h/errno.h ../h/proc.h
uba.o: ../h/conf.h ../h/dkstat.h ../h/kernel.h ../vaxuba/../vax/pte.h
uba.o: ../vaxuba/../vax/cpu.h ../vaxuba/../vax/mtpr.h ../vaxuba/../vax/nexus.h
uba.o: ../vaxuba/ubareg.h ../vaxuba/ubavar.h ik.h vs.h
uda.o: ../vaxuba/uda.c ra.h ../h/param.h ../h/types.h ../h/signal.h
uda.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
uda.o: ../h/systm.h ../h/buf.h ../h/conf.h ../h/dir.h ../h/file.h ../h/ioctl.h
uda.o: ../h/ttychars.h ../h/ttydev.h ../h/user.h ../h/../machine/pcb.h
uda.o: ../h/dmap.h ../h/time.h ../h/resource.h ../h/namei.h ../h/uio.h
uda.o: ../h/errno.h ../h/map.h ../h/vm.h ../h/vmparam.h
uda.o: ../h/../machine/vmparam.h ../h/vmmac.h ../h/vmmeter.h ../h/vmsystm.h
uda.o: ../h/dkstat.h ../h/cmap.h ../h/disklabel.h ../h/syslog.h ../h/stat.h
uda.o: ../vaxuba/../machine/pte.h ../vaxuba/../vax/cpu.h ../vaxuba/ubareg.h
uda.o: ../vaxuba/ubavar.h ../vaxuba/udareg.h ../vaxuba/../vax/mscp.h
uda.o: ../vaxuba/../vax/mscpvar.h ../vaxuba/../vax/mtpr.h
up.o: ../vaxuba/up.c up.h ../vaxuba/../machine/pte.h ../h/param.h ../h/types.h
up.o: ../h/signal.h ../h/../machine/trap.h ../h/../machine/machparam.h
up.o: machine/endian.h ../h/systm.h ../h/dkstat.h ../h/dkbad.h ../h/ioctl.h
up.o: ../h/ttychars.h ../h/ttydev.h ../h/disklabel.h ../h/buf.h ../h/conf.h
up.o: ../h/dir.h ../h/user.h ../h/../machine/pcb.h ../h/dmap.h ../h/time.h
up.o: ../h/resource.h ../h/namei.h ../h/uio.h ../h/errno.h ../h/map.h ../h/vm.h
up.o: ../h/vmparam.h ../h/../machine/vmparam.h ../h/vmmac.h ../h/vmmeter.h
up.o: ../h/vmsystm.h ../h/cmap.h ../h/uio.h ../h/kernel.h ../h/syslog.h
up.o: ../vaxuba/../vax/cpu.h ../vaxuba/../vax/nexus.h ../vaxuba/ubavar.h
up.o: ../vaxuba/ubareg.h ../vaxuba/upreg.h
ut.o: ../vaxuba/ut.c tj.h ../h/param.h ../h/types.h ../h/signal.h
ut.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
ut.o: ../h/systm.h ../h/buf.h ../h/conf.h ../h/dir.h ../h/file.h ../h/user.h
ut.o: ../h/../machine/pcb.h ../h/dmap.h ../h/time.h ../h/resource.h
ut.o: ../h/namei.h ../h/uio.h ../h/errno.h ../h/map.h ../h/ioctl.h
ut.o: ../h/ttychars.h ../h/ttydev.h ../h/mtio.h ../h/cmap.h ../h/uio.h
ut.o: ../h/kernel.h ../h/tty.h ../h/ttychars.h ../h/ttydev.h ../h/syslog.h
ut.o: ../vaxuba/../machine/pte.h ../vaxuba/../vax/cpu.h ../vaxuba/ubareg.h
ut.o: ../vaxuba/ubavar.h ../vaxuba/utreg.h
qv.o: ../vaxuba/qv.c qv.h ../vaxuba/../machine/pte.h ../h/param.h ../h/types.h
qv.o: ../h/signal.h ../h/../machine/trap.h ../h/../machine/machparam.h
qv.o: machine/endian.h ../h/conf.h ../h/dir.h ../h/user.h ../h/../machine/pcb.h
qv.o: ../h/dmap.h ../h/time.h ../h/resource.h ../h/namei.h ../h/uio.h
qv.o: ../h/errno.h ../vaxuba/qvioctl.h ../h/ioctl.h ../h/ttychars.h
qv.o: ../h/ttydev.h ../vaxuba/qvreg.h ../vaxuba/qevent.h ../h/tty.h
qv.o: ../h/ttychars.h ../h/ttydev.h ../h/map.h ../h/buf.h ../h/vm.h
qv.o: ../h/vmparam.h ../h/../machine/vmparam.h ../h/vmmac.h ../h/vmmeter.h
qv.o: ../h/vmsystm.h bk.h ../h/clist.h ../h/file.h ../h/uio.h ../h/kernel.h
qv.o: ../h/syslog.h ../vaxuba/../machine/cpu.h ../vaxuba/../machine/mtpr.h
qv.o: ../vaxuba/ubareg.h ../vaxuba/ubavar.h
qfont.o: ../vaxuba/qfont.c
qd.o: ../vaxuba/qd.c qd.h ../h/types.h ../vaxuba/../machine/pte.h
qd.o: ../vaxuba/../machine/mtpr.h ../vaxuba/../machine/cpu.h ../h/param.h
qd.o: ../h/types.h ../h/signal.h ../h/../machine/trap.h
qd.o: ../h/../machine/machparam.h machine/endian.h ../h/conf.h ../h/dir.h
qd.o: ../h/user.h ../h/../machine/pcb.h ../h/dmap.h ../h/time.h ../h/resource.h
qd.o: ../h/namei.h ../h/uio.h ../h/errno.h ../vaxuba/qdioctl.h ../h/ioctl.h
qd.o: ../h/ttychars.h ../h/ttydev.h ../h/tty.h ../h/ttychars.h ../h/ttydev.h
qd.o: ../h/map.h ../h/buf.h ../h/vm.h ../h/vmparam.h ../h/../machine/vmparam.h
qd.o: ../h/vmmac.h ../h/vmmeter.h ../h/vmsystm.h bk.h ../h/clist.h ../h/file.h
qd.o: ../h/uio.h ../h/kernel.h ../h/exec.h ../h/proc.h ../vaxuba/ubareg.h
qd.o: ../vaxuba/ubavar.h ../h/syslog.h ../vaxuba/qduser.h ../vaxuba/qevent.h
qd.o: ../vaxuba/qdreg.h
swapgeneric.o: ../vax/swapgeneric.c mba.h ../vax/pte.h ../h/param.h
swapgeneric.o: ../h/types.h ../h/signal.h ../h/../machine/trap.h
swapgeneric.o: ../h/../machine/machparam.h machine/endian.h ../h/conf.h
swapgeneric.o: ../h/buf.h ../h/vm.h ../h/vmparam.h ../h/../machine/vmparam.h
swapgeneric.o: ../h/vmmac.h ../h/vmmeter.h ../h/vmsystm.h ../h/systm.h
swapgeneric.o: ../h/reboot.h ../vax/cons.h ../vax/mtpr.h
swapgeneric.o: ../vax/../vaxmba/mbareg.h ../vax/../vaxmba/mbavar.h
swapgeneric.o: ../vax/../vaxuba/ubareg.h ../vax/../vaxuba/ubavar.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
