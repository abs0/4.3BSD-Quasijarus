IDENT=-DHARHANGW -DVAX650 -DVAX630 -DGATEWAY -DTCP_COMPAT_42 -DINET -DNOSUBSINST
PARAM=-DTIMEZONE=0 -DDST=0 -DMAXUSERS=8
INLINEOPTS=-s
#
# Copyright (c) 1980, 1986 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	@(#)Makefile.vax	7.9 (Berkeley) 1/4/04
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
	tcp_usrreq.o udp_usrreq.o init_main.o init_sysent.o kern_acct.o \
	kern_clock.o kern_descrip.o kern_exec.o kern_exit.o kern_fork.o \
	kern_malloc.o kern_mman.o kern_proc.o kern_prot.o \
	kern_resource.o kern_sig.o kern_subr.o kern_synch.o kern_time.o \
	kern_xxx.o quota_kern.o quota_subr.o quota_sys.o quota_ufs.o \
	subr_log.o subr_prf.o subr_rmap.o subr_xxx.o sys_generic.o \
	sys_inode.o sys_process.o sys_socket.o tty.o tty_conf.o \
	tty_kbhacks.o tty_subr.o tty_tty.o ufs_alloc.o ufs_bio.o \
	ufs_bmap.o ufs_disksubr.o ufs_fio.o ufs_inode.o ufs_mount.o \
	ufs_namei.o ufs_subr.o ufs_syscalls.o ufs_tables.o ufs_xxx.o \
	uipc_domain.o uipc_mbuf.o uipc_proto.o uipc_socket.o \
	uipc_socket2.o uipc_syscalls.o uipc_usrreq.o vm_drum.o vm_mem.o \
	vm_mon.o vm_page.o vm_proc.o vm_pt.o vm_sched.o vm_subr.o \
	vm_sw.o vm_swap.o vm_swp.o vm_text.o autoconf.o clock.o conf.o \
	cons.o cpudata.o cpuid.o crl.o cvax.o dkbad.o flp.o in_cksum.o \
	ka410.o ka42.o ka630.o ka650.o ka730.o ka750.o ka780.o ka820.o \
	ka860.o machdep.o mem.o mscp.o rx50.o sys_machdep.o trap.o tu.o \
	udiv.o ufs_machdep.o urem.o vm_machdep.o emul_ashp.o \
	emul_cvtlp.o emul_cvtpl.o emul_decarith.o emul_deccvt.o \
	emul_decimal.o emul_dflt.o emul_editpc.o emul_fflt.o \
	emul_float.o emul_opspec.o emul_resinstr.o emul_samemode.o \
	emul_string.o if_qe.o if_uba.o uba.o uda.o 

CFILES=../net/af.c ../net/if.c ../net/if_loop.c ../net/raw_cb.c \
	../net/raw_usrreq.c ../net/route.c ../netinet/if_ether.c \
	../netinet/in.c ../netinet/in_pcb.c ../netinet/in_proto.c \
	../netinet/ip_icmp.c ../netinet/ip_input.c \
	../netinet/ip_output.c ../netinet/raw_ip.c \
	../netinet/tcp_debug.c ../netinet/tcp_input.c \
	../netinet/tcp_output.c ../netinet/tcp_subr.c \
	../netinet/tcp_timer.c ../netinet/tcp_usrreq.c \
	../netinet/udp_usrreq.c ../sys/init_main.c ../sys/init_sysent.c \
	../sys/kern_acct.c ../sys/kern_clock.c ../sys/kern_descrip.c \
	../sys/kern_exec.c ../sys/kern_exit.c ../sys/kern_fork.c \
	../sys/kern_malloc.c ../sys/kern_mman.c ../sys/kern_proc.c \
	../sys/kern_prot.c ../sys/kern_resource.c ../sys/kern_sig.c \
	../sys/kern_subr.c ../sys/kern_synch.c ../sys/kern_time.c \
	../sys/kern_xxx.c ../sys/quota_kern.c ../sys/quota_subr.c \
	../sys/quota_sys.c ../sys/quota_ufs.c ../sys/subr_log.c \
	../sys/subr_prf.c ../sys/subr_rmap.c ../sys/subr_xxx.c \
	../sys/sys_generic.c ../sys/sys_inode.c ../sys/sys_process.c \
	../sys/sys_socket.c ../sys/tty.c ../sys/tty_conf.c \
	../sys/tty_kbhacks.c ../sys/tty_subr.c ../sys/tty_tty.c \
	../sys/ufs_alloc.c ../sys/ufs_bio.c ../sys/ufs_bmap.c \
	../sys/ufs_disksubr.c ../sys/ufs_fio.c ../sys/ufs_inode.c \
	../sys/ufs_mount.c ../sys/ufs_namei.c ../sys/ufs_subr.c \
	../sys/ufs_syscalls.c ../sys/ufs_tables.c ../sys/ufs_xxx.c \
	../sys/uipc_domain.c ../sys/uipc_mbuf.c ../sys/uipc_proto.c \
	../sys/uipc_socket.c ../sys/uipc_socket2.c \
	../sys/uipc_syscalls.c ../sys/uipc_usrreq.c ../sys/vm_drum.c \
	../sys/vm_mem.c ../sys/vm_mon.c ../sys/vm_page.c \
	../sys/vm_proc.c ../sys/vm_pt.c ../sys/vm_sched.c \
	../sys/vm_subr.c ../sys/vm_sw.c ../sys/vm_swap.c ../sys/vm_swp.c \
	../sys/vm_text.c ../vax/autoconf.c ../vax/clock.c ../vax/conf.c \
	../vax/cons.c ../vax/cpudata.c ../vax/crl.c ../vax/cvax.c \
	../vax/dkbad.c ../vax/flp.c ../vax/in_cksum.c ../vax/ka410.c \
	../vax/ka42.c ../vax/ka630.c ../vax/ka650.c ../vax/ka730.c \
	../vax/ka750.c ../vax/ka780.c ../vax/ka820.c ../vax/ka860.c \
	../vax/machdep.c ../vax/mem.c ../vax/mscp.c ../vax/rx50.c \
	../vax/sys_machdep.c ../vax/trap.c ../vax/tu.c \
	../vax/ufs_machdep.c ../vax/vm_machdep.c ../vaxif/if_qe.c \
	../vaxif/if_uba.c ../vaxuba/uba.c ../vaxuba/uda.c \
	swapvmunix.c 

vmunix: Makefile ../machine/symbols.sort ${INLINECMD} locore.o ${OBJS} param.o ioconf.o swapvmunix.o
	@echo loading vmunix
	@rm -f vmunix
	@sh ../conf/newvers.sh
	@${CC} $(CFLAGS) -c vers.c
	@${LD} -n -o vmunix -e start -x -T 80000000 locore.o ${OBJS} vers.o ioconf.o param.o swapvmunix.o
	@echo rearranging symbols
	@-symorder ../vax/symbols.sort vmunix
	@size vmunix
	@chmod 755 vmunix

swapvmunix.o: swapvmunix.c
	${CC} -c -O ${COPTS} swapvmunix.c

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

tty_kbhacks.o: ../sys/tty_kbhacks.c
	${CC} -c -S ${COPTS} ../sys/tty_kbhacks.c
	${C2} tty_kbhacks.s | ${INLINE} | ${AS} -o tty_kbhacks.o
	rm -f tty_kbhacks.s

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

cpuid.o: ../vax/cpuid.s
	-ln -s ../vax/cpuid.s cpuid.c
	${CC} -E ${COPTS} cpuid.c | ${AS} -o cpuid.o
	rm -f cpuid.c

crl.o: ../vax/crl.c
	${CC} -c -S ${COPTS} ../vax/crl.c
	${C2} crl.s | ${INLINE} | ${AS} -o crl.o
	rm -f crl.s

cvax.o: ../vax/cvax.c
	${CC} -c -S ${COPTS} ../vax/cvax.c
	${C2} cvax.s | ${INLINE} | ${AS} -o cvax.o
	rm -f cvax.s

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

ka410.o: ../vax/ka410.c
	${CC} -c -S ${COPTS} ../vax/ka410.c
	${C2} ka410.s | ${INLINE} | ${AS} -o ka410.o
	rm -f ka410.s

ka42.o: ../vax/ka42.c
	${CC} -c -S ${COPTS} ../vax/ka42.c
	${C2} ka42.s | ${INLINE} | ${AS} -o ka42.o
	rm -f ka42.s

ka630.o: ../vax/ka630.c
	${CC} -c -S ${COPTS} ../vax/ka630.c
	${C2} ka630.s | ${INLINE} | ${AS} -o ka630.o
	rm -f ka630.s

ka650.o: ../vax/ka650.c
	${CC} -c -S ${COPTS} ../vax/ka650.c
	${C2} ka650.s | ${INLINE} | ${AS} -o ka650.o
	rm -f ka650.s

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

emul_ashp.o: ../vax/emul/emul_ashp.s
	-ln -s ../vax/emul/emul_ashp.s emul_ashp.c
	${CC} -E ${COPTS} emul_ashp.c | ${AS} -o emul_ashp.o
	rm -f emul_ashp.c

emul_cvtlp.o: ../vax/emul/emul_cvtlp.s
	-ln -s ../vax/emul/emul_cvtlp.s emul_cvtlp.c
	${CC} -E ${COPTS} emul_cvtlp.c | ${AS} -o emul_cvtlp.o
	rm -f emul_cvtlp.c

emul_cvtpl.o: ../vax/emul/emul_cvtpl.s
	-ln -s ../vax/emul/emul_cvtpl.s emul_cvtpl.c
	${CC} -E ${COPTS} emul_cvtpl.c | ${AS} -o emul_cvtpl.o
	rm -f emul_cvtpl.c

emul_decarith.o: ../vax/emul/emul_decarith.s
	-ln -s ../vax/emul/emul_decarith.s emul_decarith.c
	${CC} -E ${COPTS} emul_decarith.c | ${AS} -o emul_decarith.o
	rm -f emul_decarith.c

emul_deccvt.o: ../vax/emul/emul_deccvt.s
	-ln -s ../vax/emul/emul_deccvt.s emul_deccvt.c
	${CC} -E ${COPTS} emul_deccvt.c | ${AS} -o emul_deccvt.o
	rm -f emul_deccvt.c

emul_decimal.o: ../vax/emul/emul_decimal.s
	-ln -s ../vax/emul/emul_decimal.s emul_decimal.c
	${CC} -E ${COPTS} emul_decimal.c | ${AS} -o emul_decimal.o
	rm -f emul_decimal.c

emul_dflt.o: ../vax/emul/emul_dflt.s
	-ln -s ../vax/emul/emul_dflt.s emul_dflt.c
	${CC} -E ${COPTS} emul_dflt.c | ${AS} -o emul_dflt.o
	rm -f emul_dflt.c

emul_editpc.o: ../vax/emul/emul_editpc.s
	-ln -s ../vax/emul/emul_editpc.s emul_editpc.c
	${CC} -E ${COPTS} emul_editpc.c | ${AS} -o emul_editpc.o
	rm -f emul_editpc.c

emul_fflt.o: ../vax/emul/emul_fflt.s
	-ln -s ../vax/emul/emul_fflt.s emul_fflt.c
	${CC} -E ${COPTS} emul_fflt.c | ${AS} -o emul_fflt.o
	rm -f emul_fflt.c

emul_float.o: ../vax/emul/emul_float.s
	-ln -s ../vax/emul/emul_float.s emul_float.c
	${CC} -E ${COPTS} emul_float.c | ${AS} -o emul_float.o
	rm -f emul_float.c

emul_opspec.o: ../vax/emul/emul_opspec.s
	-ln -s ../vax/emul/emul_opspec.s emul_opspec.c
	${CC} -E ${COPTS} emul_opspec.c | ${AS} -o emul_opspec.o
	rm -f emul_opspec.c

emul_resinstr.o: ../vax/emul/emul_resinstr.s
	-ln -s ../vax/emul/emul_resinstr.s emul_resinstr.c
	${CC} -E ${COPTS} emul_resinstr.c | ${AS} -o emul_resinstr.o
	rm -f emul_resinstr.c

emul_samemode.o: ../vax/emul/emul_samemode.s
	-ln -s ../vax/emul/emul_samemode.s emul_samemode.c
	${CC} -E ${COPTS} emul_samemode.c | ${AS} -o emul_samemode.o
	rm -f emul_samemode.c

emul_string.o: ../vax/emul/emul_string.s
	-ln -s ../vax/emul/emul_string.s emul_string.c
	${CC} -E ${COPTS} emul_string.c | ${AS} -o emul_string.o
	rm -f emul_string.c

if_qe.o: ../vaxif/if_qe.c
	${CC} -c -S ${COPTS} ../vaxif/if_qe.c
	${C2} -i if_qe.s | ${INLINE} | ${AS} -o if_qe.o
	rm -f if_qe.s

if_uba.o: ../vaxif/if_uba.c
	${CC} -c -S ${COPTS} ../vaxif/if_uba.c
	${C2} -i if_uba.s | ${INLINE} | ${AS} -o if_uba.o
	rm -f if_uba.s

uba.o: ../vaxuba/uba.c
	${CC} -c -S ${COPTS} ../vaxuba/uba.c
	${C2} -i uba.s | ${INLINE} | ${AS} -o uba.o
	rm -f uba.s

uda.o: ../vaxuba/uda.c
	${CC} -c -S ${COPTS} ../vaxuba/uda.c
	${C2} -i uda.s | ${INLINE} | ${AS} -o uda.o
	rm -f uda.s


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
if.o: ../net/../net/if_arp.h ../net/af.h ether.h netmon.h
if_loop.o: ../net/if_loop.c ../h/param.h ../h/types.h ../h/signal.h
if_loop.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
if_loop.o: ../h/systm.h ../h/mbuf.h ../h/socket.h ../h/errno.h ../h/ioctl.h
if_loop.o: ../h/ttychars.h ../h/ttydev.h ../net/../net/if.h
if_loop.o: ../net/../net/../net/if_arp.h ../net/../net/netisr.h
if_loop.o: ../net/../net/route.h ../net/../machine/mtpr.h
if_loop.o: ../net/../machine/../vax/cpucond.h ../net/../netinet/in.h
if_loop.o: ../net/../netinet/in_systm.h ../net/../netinet/in_var.h
if_loop.o: ../net/../netinet/ip.h
raw_cb.o: ../net/raw_cb.c ../h/param.h ../h/types.h ../h/signal.h
raw_cb.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
raw_cb.o: ../h/systm.h ../h/mbuf.h ../h/socket.h ../h/socketvar.h ../h/domain.h
raw_cb.o: ../h/protosw.h ../h/errno.h ../net/if.h ../net/../net/if_arp.h
raw_cb.o: ../net/route.h ../net/raw_cb.h ../net/../netinet/in.h
raw_cb.o: ../net/../machine/mtpr.h ../net/../machine/../vax/cpucond.h
raw_usrreq.o: ../net/raw_usrreq.c ../h/param.h ../h/types.h ../h/signal.h
raw_usrreq.o: ../h/../machine/trap.h ../h/../machine/machparam.h
raw_usrreq.o: machine/endian.h ../h/mbuf.h ../h/domain.h ../h/protosw.h
raw_usrreq.o: ../h/socket.h ../h/socketvar.h ../h/errno.h ../net/if.h
raw_usrreq.o: ../net/../net/if_arp.h ../net/route.h ../net/netisr.h
raw_usrreq.o: ../net/raw_cb.h ../net/../machine/mtpr.h
raw_usrreq.o: ../net/../machine/../vax/cpucond.h
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
ip_output.o: ../netinet/../machine/../vax/cpucond.h
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
init_main.o: ../sys/../machine/cpu.h loop.h kg.h sl.h ppp.h
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
kern_clock.o: ../sys/../machine/../vax/cpucond.h ../sys/../machine/clock.h
kern_descrip.o: ../sys/kern_descrip.c ../h/param.h ../h/types.h ../h/signal.h
kern_descrip.o: ../h/../machine/trap.h ../h/../machine/machparam.h
kern_descrip.o: machine/endian.h ../h/systm.h ../h/dir.h ../h/user.h
kern_descrip.o: ../h/../machine/pcb.h ../h/dmap.h ../h/time.h ../h/resource.h
kern_descrip.o: ../h/namei.h ../h/uio.h ../h/errno.h ../h/kernel.h ../h/inode.h
kern_descrip.o: ../h/proc.h ../h/file.h ../h/socket.h ../h/socketvar.h
kern_descrip.o: ../h/mount.h ../h/stat.h ../h/ioctl.h ../h/ttychars.h
kern_descrip.o: ../h/ttydev.h
kern_exec.o: ../sys/kern_exec.c ../sys/../machine/reg.h ../sys/../machine/pte.h
kern_exec.o: ../sys/../machine/psl.h ../sys/../machine/mtpr.h
kern_exec.o: ../sys/../machine/../vax/cpucond.h ../h/param.h ../h/types.h
kern_exec.o: ../h/signal.h ../h/../machine/trap.h ../h/../machine/machparam.h
kern_exec.o: machine/endian.h ../h/systm.h ../h/map.h ../h/dir.h ../h/user.h
kern_exec.o: ../h/../machine/pcb.h ../h/dmap.h ../h/time.h ../h/resource.h
kern_exec.o: ../h/namei.h ../h/uio.h ../h/errno.h ../h/kernel.h ../h/proc.h
kern_exec.o: ../h/buf.h ../h/inode.h ../h/seg.h ../h/vm.h ../h/vmparam.h
kern_exec.o: ../h/../machine/vmparam.h ../h/vmmac.h ../h/vmmeter.h
kern_exec.o: ../h/vmsystm.h ../h/text.h ../h/file.h ../h/uio.h ../h/acct.h
kern_exec.o: ../h/exec.h
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
kern_mman.o: ../sys/../machine/mtpr.h ../sys/../machine/../vax/cpucond.h
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
kern_sig.o: ../sys/../machine/psl.h ../sys/../machine/mtpr.h
kern_sig.o: ../sys/../machine/../vax/cpucond.h ../h/param.h ../h/types.h
kern_sig.o: ../h/signal.h ../h/../machine/trap.h ../h/../machine/machparam.h
kern_sig.o: machine/endian.h ../h/systm.h ../h/dir.h ../h/user.h
kern_sig.o: ../h/../machine/pcb.h ../h/dmap.h ../h/time.h ../h/resource.h
kern_sig.o: ../h/namei.h ../h/uio.h ../h/errno.h ../h/inode.h ../h/proc.h
kern_sig.o: ../h/timeb.h ../h/times.h ../h/buf.h ../h/mount.h ../h/text.h
kern_sig.o: ../h/seg.h ../h/vm.h ../h/vmparam.h ../h/../machine/vmparam.h
kern_sig.o: ../h/vmmac.h ../h/vmmeter.h ../h/vmsystm.h ../h/acct.h ../h/uio.h
kern_sig.o: ../h/kernel.h
kern_subr.o: ../sys/kern_subr.c ../h/param.h ../h/types.h ../h/signal.h
kern_subr.o: ../h/../machine/trap.h ../h/../machine/machparam.h
kern_subr.o: machine/endian.h ../h/systm.h ../h/dir.h ../h/user.h
kern_subr.o: ../h/../machine/pcb.h ../h/dmap.h ../h/time.h ../h/resource.h
kern_subr.o: ../h/namei.h ../h/uio.h ../h/errno.h ../h/uio.h
kern_synch.o: ../sys/kern_synch.c ../sys/../machine/pte.h
kern_synch.o: ../sys/../machine/psl.h ../sys/../machine/mtpr.h
kern_synch.o: ../sys/../machine/../vax/cpucond.h ../h/param.h ../h/types.h
kern_synch.o: ../h/signal.h ../h/../machine/trap.h ../h/../machine/machparam.h
kern_synch.o: machine/endian.h ../h/systm.h ../h/dir.h ../h/user.h
kern_synch.o: ../h/../machine/pcb.h ../h/dmap.h ../h/time.h ../h/resource.h
kern_synch.o: ../h/namei.h ../h/uio.h ../h/errno.h ../h/proc.h ../h/vm.h
kern_synch.o: ../h/vmparam.h ../h/../machine/vmparam.h ../h/vmmac.h
kern_synch.o: ../h/vmmeter.h ../h/vmsystm.h ../h/kernel.h ../h/buf.h
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
quota_kern.o: ../sys/quota_kern.c
quota_subr.o: ../sys/quota_subr.c
quota_sys.o: ../sys/quota_sys.c ../h/param.h ../h/types.h ../h/signal.h
quota_sys.o: ../h/../machine/trap.h ../h/../machine/machparam.h
quota_sys.o: machine/endian.h ../h/systm.h ../h/dir.h ../h/user.h
quota_sys.o: ../h/../machine/pcb.h ../h/dmap.h ../h/time.h ../h/resource.h
quota_sys.o: ../h/namei.h ../h/uio.h ../h/errno.h ../h/proc.h ../h/inode.h
quota_sys.o: ../h/quota.h ../h/mount.h ../h/fs.h ../h/uio.h
quota_ufs.o: ../sys/quota_ufs.c
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
subr_prf.o: ../sys/../machine/../vax/cpucond.h
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
tty.o: ../h/malloc.h sl.h ppp.h
tty_conf.o: ../sys/tty_conf.c ../h/param.h ../h/types.h ../h/signal.h
tty_conf.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
tty_conf.o: ../h/systm.h ../h/buf.h ../h/ioctl.h ../h/ttychars.h ../h/ttydev.h
tty_conf.o: ../h/tty.h ../h/ttychars.h ../h/ttydev.h ../h/conf.h bk.h tb.h sl.h
tty_conf.o: ppp.h lk.h
tty_kbhacks.o: ../sys/tty_kbhacks.c
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
ufs_inode.o: ../h/buf.h ../h/cmap.h ../h/kernel.h ../h/malloc.h
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
vm_mem.o: ../sys/../machine/mtpr.h ../sys/../machine/../vax/cpucond.h
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
vm_page.o: ../sys/../machine/mtpr.h ../sys/../machine/../vax/cpucond.h
vm_proc.o: ../sys/vm_proc.c ../h/param.h ../h/types.h ../h/signal.h
vm_proc.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
vm_proc.o: ../h/systm.h ../h/dir.h ../h/user.h ../h/../machine/pcb.h
vm_proc.o: ../h/dmap.h ../h/time.h ../h/resource.h ../h/namei.h ../h/uio.h
vm_proc.o: ../h/errno.h ../h/proc.h ../h/map.h ../h/cmap.h ../h/text.h
vm_proc.o: ../h/vm.h ../h/vmparam.h ../h/../machine/vmparam.h ../h/vmmac.h
vm_proc.o: ../h/vmmeter.h ../h/vmsystm.h ../sys/../machine/pte.h
vm_proc.o: ../sys/../machine/mtpr.h ../sys/../machine/../vax/cpucond.h
vm_proc.o: ../sys/../machine/cpu.h
vm_pt.o: ../sys/vm_pt.c ../sys/../machine/pte.h ../sys/../machine/mtpr.h
vm_pt.o: ../sys/../machine/../vax/cpucond.h ../h/param.h ../h/types.h
vm_pt.o: ../h/signal.h ../h/../machine/trap.h ../h/../machine/machparam.h
vm_pt.o: machine/endian.h ../h/systm.h ../h/dir.h ../h/user.h
vm_pt.o: ../h/../machine/pcb.h ../h/dmap.h ../h/time.h ../h/resource.h
vm_pt.o: ../h/namei.h ../h/uio.h ../h/errno.h ../h/proc.h ../h/map.h
vm_pt.o: ../h/cmap.h ../h/vm.h ../h/vmparam.h ../h/../machine/vmparam.h
vm_pt.o: ../h/vmmac.h ../h/vmmeter.h ../h/vmsystm.h ../h/buf.h ../h/text.h
vm_pt.o: ../h/mount.h ../h/inode.h ../h/kernel.h
vm_sched.o: ../sys/vm_sched.c ../h/param.h ../h/types.h ../h/signal.h
vm_sched.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
vm_sched.o: ../h/systm.h ../h/seg.h ../h/dir.h ../h/user.h
vm_sched.o: ../h/../machine/pcb.h ../h/dmap.h ../h/time.h ../h/resource.h
vm_sched.o: ../h/namei.h ../h/uio.h ../h/errno.h ../h/proc.h ../h/text.h
vm_sched.o: ../h/vm.h ../h/vmparam.h ../h/../machine/vmparam.h ../h/vmmac.h
vm_sched.o: ../h/vmmeter.h ../h/vmsystm.h ../h/cmap.h ../h/kernel.h
vm_subr.o: ../sys/vm_subr.c ../sys/../machine/pte.h ../sys/../machine/mtpr.h
vm_subr.o: ../sys/../machine/../vax/cpucond.h ../h/param.h ../h/types.h
vm_subr.o: ../h/signal.h ../h/../machine/trap.h ../h/../machine/machparam.h
vm_subr.o: machine/endian.h ../h/systm.h ../h/dir.h ../h/user.h
vm_subr.o: ../h/../machine/pcb.h ../h/dmap.h ../h/time.h ../h/resource.h
vm_subr.o: ../h/namei.h ../h/uio.h ../h/errno.h ../h/vm.h ../h/vmparam.h
vm_subr.o: ../h/../machine/vmparam.h ../h/vmmac.h ../h/vmmeter.h ../h/vmsystm.h
vm_subr.o: ../h/proc.h ../h/cmap.h ../h/inode.h ../h/buf.h ../h/text.h
vm_subr.o: ../h/fs.h
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
vm_swap.o: ../sys/../machine/../vax/cpucond.h
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
autoconf.o: ../vax/autoconf.c mba.h uba.h vaxbi.h bva.h ../h/param.h
autoconf.o: ../h/types.h ../h/signal.h ../h/../machine/trap.h
autoconf.o: ../h/../machine/machparam.h machine/endian.h ../h/systm.h
autoconf.o: ../h/map.h ../h/buf.h ../h/dkstat.h ../h/vm.h ../h/vmparam.h
autoconf.o: ../h/../machine/vmparam.h ../h/vmmac.h ../h/vmmeter.h
autoconf.o: ../h/vmsystm.h ../h/malloc.h ../h/conf.h ../h/dmap.h ../h/reboot.h
autoconf.o: ../vax/pte.h ../vax/cpu.h ../vax/mem.h ../vax/mtpr.h
autoconf.o: ../vax/../vax/cpucond.h ../vax/nexus.h ../vax/scb.h ../vax/ioa.h
autoconf.o: ../vax/../vaxbi/bireg.h ../vax/../vaxbi/bivar.h
autoconf.o: ../vax/../vaxmba/mbareg.h ../vax/../vaxmba/mbavar.h
autoconf.o: ../vax/../vaxuba/ubareg.h ../vax/../vaxuba/ubavar.h
autoconf.o: ../vax/../babyvax/bvvar.h
clock.o: ../vax/clock.c ../h/param.h ../h/types.h ../h/signal.h
clock.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
clock.o: ../h/time.h ../h/kernel.h ../vax/mtpr.h ../vax/../vax/cpucond.h
clock.o: ../vax/clock.h ../vax/cpu.h ../vax/cpucond.h
conf.o: ../vax/conf.c ../h/param.h ../h/types.h ../h/signal.h
conf.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
conf.o: ../h/systm.h ../h/buf.h ../h/ioctl.h ../h/ttychars.h ../h/ttydev.h
conf.o: ../h/tty.h ../h/ttychars.h ../h/ttydev.h ../h/conf.h hp.h tu.h rk.h
conf.o: te.h tms.h ts.h mu.h ra.h kra.h up.h tj.h rb.h rx.h uu.h rl.h np.h
conf.o: acc.h ct.h dh.h dmf.h dz.h ss.h lp.h va.h vp.h pty.h lpa.h dn.h ik.h
conf.o: ps.h ad.h dhu.h vs.h dmz.h qv.h qd.h netmon.h
cons.o: ../vax/cons.c ../h/param.h ../h/types.h ../h/signal.h
cons.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
cons.o: ../h/conf.h ../h/dir.h ../h/user.h ../h/../machine/pcb.h ../h/dmap.h
cons.o: ../h/time.h ../h/resource.h ../h/namei.h ../h/uio.h ../h/errno.h
cons.o: ../h/proc.h ../h/ioctl.h ../h/ttychars.h ../h/ttydev.h ../h/tty.h
cons.o: ../h/ttychars.h ../h/ttydev.h ../h/systm.h ../h/uio.h ../vax/cpu.h
cons.o: ../vax/cons.h ../vax/mtpr.h ../vax/../vax/cpucond.h
cpudata.o: ../vax/cpudata.c ../vax/pte.h ../h/param.h ../h/types.h
cpudata.o: ../h/signal.h ../h/../machine/trap.h ../h/../machine/machparam.h
cpudata.o: machine/endian.h ../vax/cpu.h ../vax/cpucond.h ../vax/nexus.h
cpudata.o: ../vax/ioa.h ../vax/../vaxbi/bireg.h ../vax/../vaxuba/ubareg.h
crl.o: ../vax/crl.c
cvax.o: ../vax/cvax.c ../vax/cpucond.h ../h/param.h ../h/types.h ../h/signal.h
cvax.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
cvax.o: ../h/time.h ../h/kernel.h ../h/systm.h ../vax/cpu.h ../vax/psl.h
cvax.o: ../vax/mem.h ../vax/mtpr.h ../vax/../vax/cpucond.h ../vax/cvax.h
cvax.o: ../vax/ka650.h
dkbad.o: ../vax/dkbad.c ../h/param.h ../h/types.h ../h/signal.h
dkbad.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
dkbad.o: ../h/buf.h ../h/dkbad.h
flp.o: ../vax/flp.c
in_cksum.o: ../vax/in_cksum.c ../h/types.h ../h/mbuf.h
ka410.o: ../vax/ka410.c
ka42.o: ../vax/ka42.c
ka630.o: ../vax/ka630.c ../h/param.h ../h/types.h ../h/signal.h
ka630.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
ka630.o: ../h/time.h ../h/kernel.h ../h/vmmac.h ../vax/mtpr.h
ka630.o: ../vax/../vax/cpucond.h ../vax/cpu.h ../vax/clock.h ../vax/pte.h
ka630.o: ../vax/78032.h ../vax/ka630.h
ka650.o: ../vax/ka650.c ../h/param.h ../h/types.h ../h/signal.h
ka650.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
ka650.o: ../h/time.h ../h/kernel.h ../h/systm.h ../vax/cpu.h ../vax/psl.h
ka650.o: ../vax/mem.h ../vax/mtpr.h ../vax/../vax/cpucond.h ../vax/cvax.h
ka650.o: ../vax/ka650.h
ka730.o: ../vax/ka730.c
ka750.o: ../vax/ka750.c
ka780.o: ../vax/ka780.c
ka820.o: ../vax/ka820.c
ka860.o: ../vax/ka860.c
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
machdep.o: ../vax/cons.h ../vax/cpu.h ../vax/cpucond.h ../vax/mem.h
machdep.o: ../vax/mtpr.h ../vax/../vax/cpucond.h ../vax/rpb.h ../vax/ka630.h
machdep.o: ../vax/ka650.h ../vax/../vaxuba/ubavar.h ../vax/../vaxuba/ubareg.h
machdep.o: ../vax/../mdec/vmb.h qv.h qd.h
mem.o: ../vax/mem.c ../vax/pte.h ../h/param.h ../h/types.h ../h/signal.h
mem.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
mem.o: ../h/dir.h ../h/user.h ../h/../machine/pcb.h ../h/dmap.h ../h/time.h
mem.o: ../h/resource.h ../h/namei.h ../h/uio.h ../h/errno.h ../h/conf.h
mem.o: ../h/buf.h ../h/systm.h ../h/vm.h ../h/vmparam.h
mem.o: ../h/../machine/vmparam.h ../h/vmmac.h ../h/vmmeter.h ../h/vmsystm.h
mem.o: ../h/cmap.h ../h/uio.h ../vax/mtpr.h ../vax/../vax/cpucond.h
mscp.o: ../vax/mscp.c ../h/param.h ../h/types.h ../h/signal.h
mscp.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
mscp.o: ../h/buf.h ../h/errno.h ../h/dkstat.h ../h/ioctl.h ../h/ttychars.h
mscp.o: ../h/ttydev.h ../h/disklabel.h ../h/syslog.h ../vax/../vaxuba/ubavar.h
mscp.o: ../vax/mscp.h ../vax/mscpvar.h
rx50.o: ../vax/rx50.c
sys_machdep.o: ../vax/sys_machdep.c ../h/param.h ../h/types.h ../h/signal.h
sys_machdep.o: ../h/../machine/trap.h ../h/../machine/machparam.h
sys_machdep.o: machine/endian.h ../h/systm.h ../h/dir.h ../h/user.h
sys_machdep.o: ../h/../machine/pcb.h ../h/dmap.h ../h/time.h ../h/resource.h
sys_machdep.o: ../h/namei.h ../h/uio.h ../h/errno.h ../h/ioctl.h
sys_machdep.o: ../h/ttychars.h ../h/ttydev.h ../h/file.h ../h/proc.h ../h/uio.h
sys_machdep.o: ../h/kernel.h ../h/mtio.h ../h/buf.h ../h/trace.h ../vax/dkio.h
sys_machdep.o: ../vax/pte.h ../vax/../vaxuba/ubareg.h ../vax/../vaxuba/ubavar.h
sys_machdep.o: uba.h
trap.o: ../vax/trap.c ../vax/psl.h ../vax/reg.h ../vax/pte.h ../vax/vmparam.h
trap.o: ../h/param.h ../h/types.h ../h/signal.h ../h/../machine/trap.h
trap.o: ../h/../machine/machparam.h machine/endian.h ../h/systm.h ../h/dir.h
trap.o: ../h/user.h ../h/../machine/pcb.h ../h/dmap.h ../h/time.h
trap.o: ../h/resource.h ../h/namei.h ../h/uio.h ../h/errno.h assym.s
trap.o: ../h/proc.h ../h/seg.h ../vax/trap.h ../h/acct.h ../h/kernel.h
trap.o: ../vax/mtpr.h ../vax/../vax/cpucond.h
tu.o: ../vax/tu.c
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
vm_machdep.o: ../vax/pte.h ../vax/mtpr.h ../vax/../vax/cpucond.h
if_qe.o: ../vaxif/if_qe.c qe.h ../h/param.h ../h/types.h ../h/signal.h
if_qe.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
if_qe.o: ../h/systm.h ../h/mbuf.h ../h/buf.h ../h/protosw.h ../h/socket.h
if_qe.o: ../h/vmmac.h ../h/ioctl.h ../h/ttychars.h ../h/ttydev.h ../h/errno.h
if_qe.o: ../h/syslog.h ../h/time.h ../h/kernel.h ../vaxif/../net/if.h
if_qe.o: ../vaxif/../net/../net/if_arp.h ../vaxif/../net/netisr.h
if_qe.o: ../vaxif/../net/route.h ../vaxif/../netinet/in.h
if_qe.o: ../vaxif/../netinet/in_systm.h ../vaxif/../netinet/in_var.h
if_qe.o: ../vaxif/../netinet/ip.h ../vaxif/../netinet/if_ether.h
if_qe.o: ../vaxif/../vax/pte.h ../vaxif/../vax/cpu.h ../vaxif/../vax/mtpr.h
if_qe.o: ../vaxif/../vax/../vax/cpucond.h ../vaxif/if_qereg.h ../vaxif/if_uba.h
if_qe.o: ../vaxif/../vaxuba/ubareg.h ../vaxif/../vaxuba/ubavar.h
if_uba.o: ../vaxif/if_uba.c ../h/param.h ../h/types.h ../h/signal.h
if_uba.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
if_uba.o: ../h/systm.h ../h/mbuf.h ../h/map.h ../h/buf.h ../h/cmap.h
if_uba.o: ../h/vmmac.h ../h/socket.h ../h/syslog.h ../h/malloc.h
if_uba.o: ../vaxif/../net/if.h ../vaxif/../net/../net/if_arp.h
if_uba.o: ../vaxif/../vax/pte.h ../vaxif/../vax/mtpr.h
if_uba.o: ../vaxif/../vax/../vax/cpucond.h ../vaxif/if_uba.h
if_uba.o: ../vaxif/../vaxuba/ubareg.h ../vaxif/../vaxuba/ubavar.h
uba.o: ../vaxuba/uba.c ../h/param.h ../h/types.h ../h/signal.h
uba.o: ../h/../machine/trap.h ../h/../machine/machparam.h machine/endian.h
uba.o: ../h/systm.h ../h/map.h ../h/buf.h ../h/vm.h ../h/vmparam.h
uba.o: ../h/../machine/vmparam.h ../h/vmmac.h ../h/vmmeter.h ../h/vmsystm.h
uba.o: ../h/dir.h ../h/user.h ../h/../machine/pcb.h ../h/dmap.h ../h/time.h
uba.o: ../h/resource.h ../h/namei.h ../h/uio.h ../h/errno.h ../h/proc.h
uba.o: ../h/conf.h ../h/dkstat.h ../h/kernel.h ../vaxuba/../vax/pte.h
uba.o: ../vaxuba/../vax/cpu.h ../vaxuba/../vax/mtpr.h
uba.o: ../vaxuba/../vax/../vax/cpucond.h ../vaxuba/../vax/nexus.h
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
uda.o: ../vaxuba/../vax/../vax/cpucond.h
swapvmunix.o: swapvmunix.c ../h/param.h ../h/types.h ../h/signal.h
swapvmunix.o: ../h/../machine/trap.h ../h/../machine/machparam.h
swapvmunix.o: machine/endian.h ../h/conf.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
