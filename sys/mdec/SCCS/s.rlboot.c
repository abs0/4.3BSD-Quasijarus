h24194
s 00002/00002/00112
d D 7.4 04/02/28 23:38:19 msokolov 12 11
c move to using R5<31:28> instead of <15:12> for partition
e
s 00004/00005/00110
d D 7.3 87/02/21 11:30:44 karels 11 10
c squish
e
s 00012/00000/00103
d D 7.2 86/08/28 20:59:17 karels 10 9
c changes for pack labels; use cpp, now are *.c
e
s 00001/00001/00102
d D 7.1 86/06/05 01:53:00 mckusick 9 8
c 4.3BSD release version
e
s 00032/00047/00071
d D 6.4 86/03/14 16:28:06 karels 8 7
c use unit and uba from registers
e
s 00001/00003/00117
d D 6.3 85/06/26 14:02:41 bloom 7 6
c sccsids aren't executable kirk
e
s 00009/00001/00111
d D 6.2 85/06/08 12:20:16 mckusick 6 5
c Add copyright
e
s 00000/00000/00112
d D 6.1 83/07/29 07:43:20 sam 5 4
c 4.2 distribution
e
s 00006/00005/00106
d D 4.3 83/06/16 18:37:41 sam 4 3
c from gross
e
s 00063/00171/00048
d D 4.2 83/02/20 22:22:19 sam 3 1
c coded, now test
e
s 00063/00171/00048
d R 4.2 83/02/20 22:14:44 sam 2 1
c works maybe?
e
s 00219/00000/00000
d D 4.1 83/02/16 22:06:34 sam 1 0
c date and time created 83/02/16 22:06:34 by sam
e
u
U
t
T
I 1
D 6
/*	%M%	%I%	%E%	*/
E 6
I 6
/*
D 9
 * Copyright (c) 1980 Regents of the University of California.
E 9
I 9
 * Copyright (c) 1980, 1986 Regents of the University of California.
E 9
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

D 7
#ifndef lint
_sccsid:.asciz	"%W% (Berkeley) %G%"
#endif not lint
E 7
I 7
/* "%W% (Berkeley) %G%" */
I 10
#include <sys/disklabel.h>
E 10
E 7
E 6

I 8
	.set	MAJOR,14		/* major("/dev/rl0a") */

E 8
/*
D 3
 * RL02 disk boot program to load "/boot" from
 * a UNIX filesystem (starting at block 1 on pack on
 * drive 0) into low core and to execute that file.
 *
 * This program can only read regular small 1k byte (3bsd+) files
 * from the root of a UNIX filesystem.
 *
 * Hacked from a rk07 boot by Hank Trapnell, IMS.
 *
 *	/sys/mdec/hlboot.s	4.1	82/12/17
E 3
I 3
 * RL02 1st level boot program: loads next 7.5Kbytes from
 * boot sector of file system and sets it up to run.
D 8
 * Always reads from drive 0.
 * 	UNTESTED
E 8
E 3
 */
D 3
        .set    BLKSIZ,1024             /* file system block size */
        .set    BPSECT,256              /* size of sector in bytes */
E 3
I 3
	.set	BOOTSIZE,15		/* 15 ``sectors'' */
E 3
        .set    RELOC,0x50000
D 3
        .set    INOSIZ,64               /* no. bytes/inode entry */
        .set    INOBLK,BLKSIZ/INOSIZ    /* no. inodes/disc block */
        .set    INOMSK,0xfffffff0       /* changes with inode size */
        .set    NAMSIZ,14               /* bytes in directory name */
        .set    ENTADR,024              /* offset to entry addr in a.out */
        .set    DIRSIZ,16               /* size of directory entry, bytes */
        .set    ROOTINO,2               /* root dir inode no. */
        .set    NBOO,1                  /* no. of boot blocks */
        .set    NSUP,1                  /* no. of superblocks */
        .set    SID,62                  /* system ID register */
E 3
I 3
D 8
        .set    SID,62			/* system ID register */
E 8
E 3
/* UBA registers */
D 3
        .set    UBA_CNFGR,0             /* UBA configuration register */
        .set    UBA_CR,4                /* UBA control register offset */
        .set    UBA_MAP,0x800           /* UBA offset to map reg's */
        .set    UBAinit,1               /* UBA init bit in UBA control reg */
        .set    pUBIC,16                /* Unibus init complete */
E 3
I 3
        .set    UBA_CNFGR,0		/* UBA configuration register */
        .set    UBA_CR,4		/* UBA control register offset */
        .set    UBA_MAP,0x800		/* UBA offset to map reg's */
D 8
        .set    UBAinit,1		/* UBA init bit in UBA control reg */
        .set    pUBIC,16		/* Unibus init complete */
E 8
E 3
/* RL11 registers and bits */
D 3
        .set    HL,0174400-0160000      /* address of RL11 */
        .set    HL_cs,HL+0              /* control and status */
        .set    HL_ba,HL+2              /* bus address */
        .set    HL_da,HL+4              /* disk address */
        .set    HL_mp,HL+6              /* word count */
        .set    HLSECT,40               /* sectors per track */
        .set    HLTRAC,2                /* tracks per cylinder */
        .set    HLST,HLSECT*HLTRAC
        .set    HL_GO,0                 /* go bit */
        .set    HL_RCOM,014             /* read command */
        .set    HL_SEEK,06              /* seek */
        .set    HL_GSTAT,04             /* get status command */
        .set    HL_RHDR,010             /* read header */
        .set    HL_RESET,013            /* reset drive */
        .set    HL_HS,020               /* head select */
        .set    HL_DIR,04               /* seek direction */
        .set    HL_pRDY,7               /* position of ready bit */
        .set    HL_pERR,15              /* position of error bit */
E 3
I 3
        .set    HL,0174400-0160000	/* address of RL11 */
        .set    HLBPSECT,512		/* sector size in bytes (kludge) */
        .set    HL_cs,HL+0		/* control and status */
        .set    HL_ba,HL+2		/* bus address */
        .set    HL_da,HL+4		/* disk address */
        .set    HL_wc,HL+6		/* word count */
D 8
        .set    HL_GO,0			/* go bit */
E 8
I 8
        .set    HL_RDY,0200		/* READY  */
E 8
        .set    HL_RCOM,014		/* read command */
        .set    HL_SEEK,06		/* seek */
        .set    HL_RESET,013		/* reset drive */
        .set    HL_GSTAT,04		/* get status command */
        .set    HL_pRDY,7		/* position of ready bit */
        .set    HL_pERR,15		/* position of error bit */
E 3

init:
/* r9   UBA address */
D 8
/* r10  umem addr */
E 8
I 8
/* r8	RL addr */
E 8
D 3
        .word   0                       /* entry mask for dec monitor */
        nop;nop;nop;nop;nop;nop;nop;nop /* some no-ops for 750 boot to skip */
E 3
I 3
        .word   0			/* entry mask for dec monitor */
        nop;nop;nop;nop;nop;nop;nop;nop	/* some no-ops for 750 boot to skip */
E 3
	nop;nop;
D 8
/* get cpu type and find the first uba */
        mfpr    $SID,r0
D 3
        extzv   $24,$8,r0,r0            /* get cpu type */
E 3
I 3
        extzv   $24,$8,r0,r0		/* get cpu type */
E 3
        ashl    $2,r0,r1
D 3
        movab   physUBA,r2              /* get physUBA[cpu] */
E 3
I 3
        movab   physUBA,r2		/* get physUBA[cpu] */
E 3
        addl2   r1,r2
        movl    (r2),r9
D 3
        movab   physUMEM,r2             /* get physUMEM[cpu] */
E 3
I 3
        movab   physUMEM,r2		/* get physUMEM[cpu] */
E 3
        addl2   r1,r2
        movl    (r2),r10
/* if 780, init uba */
        cmpl    r0,$1
        bneq    2f
        movl    $UBAinit,UBA_CR(r9)
1:
        bbc     $pUBIC,UBA_CNFGR(r9),1b
2:
/* init rl11, and drive 0, don't check for any errors now */
        movw    $HL_RESET,HL_da(r10)
        movw    $HL_GSTAT+HL_GO,HL_cs(r10)
E 8
I 8
D 11
	movl	$MAJOR,r10		/* major("/dev/xx0a") */
E 11
I 11
	cvtbl	$MAJOR,r10		/* major("/dev/xx0a") */
E 11
	extzv	$18,$1,r1,r9		/* get UBA number from R1 */
	xorb2	$0x01,r9		/* complement bit */
	insv	r9,$24,$8,r10		/* set UBA number */
	insv	r3,$16,$8,r10		/* drive number */
D 12
	extzv	$12,$4,r5,r4		/* get partition from r5 */
	bicw2	$0xf000,r5		/* remove from r5 */
E 12
I 12
	extzv	$28,$4,r5,r4		/* get partition from r5 */
	bicl2	$0xf0000000,r5		/* remove from r5 */
E 12
	insv	r4,$8,$8,r10		/* set partition */
	movl	r5,r11			/* boot flags */
I 11

	movl	r2,r8			/* boot device CSR */
E 11
I 10
	brw	start0

/*
 * Leave space for pack label.
 */
pad:
	.space	LABELOFFSET - (pad - init)
packlabel:
	.space	d_end_

start0:
E 10
	movl	physUBA[r9],r9		/* UNIBUS adaptor address */
D 11
	movl	r2,r8			/* boot device CSR */
	movl	r3,r7			/* unit number */
	ashl	$8,r7,r7		/* shifted for HL_cs */
E 11
I 11
	ashl	$8,r3,r7		/* unit number, shifted for HL_cs */
E 11

/* init rl11, and drive, don't check for any errors now */
        movw    $HL_RESET,HL_da(r8)
        bisw3	r7,$HL_GSTAT,HL_cs(r8)
E 8
D 3

E 3
/* relocate to high core */
start:
D 3
        movl    r5,r11                  /* boot flags */
E 3
I 3
D 11
        movl    r5,r11			/* save boot flags */
E 11
E 3
        movl    $RELOC,sp
        moval   init,r6
        movc3   $end,(r6),(sp)
        jmp     *$RELOC+start2
/* now running relocated */
D 3
/* search for ``boot'' in root inode */
E 3
I 3
/* read in the boot program */
	.set	PROGSIZE,(BOOTSIZE*HLBPSECT)
E 3
start2:
D 3
        movl    $names+RELOC,r6
        movzbl  $ROOTINO,r0
nxti:
        clrw    *$bno		/* start with first block in inode */
        bsbw    iget
        tstb    (r6)
        beql    getfil		/* found correct inode! */
get1b:
        bsbw    rmblk		/* read inode from block now in memory */
        beql    start2
        movl    $buf,r7
nxtent:
        tstw    (r7)
        beql    dirchk
        cmpc3   $NAMSIZ,(r6),2(r7)
        bneq    dirchk
        movzwl  (r7),r0
        addl2   $NAMSIZ,r6
        brb     nxti
dirchk:
        acbl    $buf+BLKSIZ-1,$DIRSIZ,r7,nxtent 
        brb     get1b
/* found inode for desired file... read it in */
getfil:
        clrl    bufptr
getlop:
        bsbb    rmblk
        beql    clear
        addl2   $BLKSIZ,bufptr
        brb     getlop
clear:
        movl    *$size,r3
clrcor:
        clrq    (r3)
        acbl    $RELOC,$8,r3,clrcor
/* run loaded program */
        movl    $8,r10                  /* major("/dev/hl0a") */
        calls   $0,*$0
        brw     start2
/* iget: get inode block whose # is in r0 */
iget:
        addl3   $(INOBLK*(NBOO+NSUP))-1,r0,r8
        divl3   $INOBLK,r8,r4
        bsbw    rblk
        bicl2   $INOMSK,r8
        mull2   $INOSIZ,r8
        addl2   $buf,r8
        movc3   $time-inode,(r8),*$inode
        rsb
/* rmblk: read in bno into addr */
rmblk:
        movzwl  *$bno,r0
        addw2   $3,*$bno
        addl2   $addr,r0
/* this boot assumes only small files (<=10k bytes, ie. no indirect blocks) */
        extzv   $0,$24,(r0),r4
        bneq    rblk
        rsb
/* rblk: read disk block whose number is in r4 */
rblk:
        movzbw	$HL_RHDR+HL_GO,HL_cs(r10)
        bsbw    hlwait
        movzwl  HL_mp(r10),r0
        extzv   $7,$9,r0,r3             /* get current cylinder */
        mull2   $BLKSIZ/BPSECT,r4
        clrl    r5
        ediv	$HLST,r4,r0,r1          /* get desired cylinder */
        movzbl	$1,r5
        subl2   r0,r3
        bgeq    1f
        mnegl   r3,r3
        bisl2   $HL_DIR,r5              /* move towards the spindle */
E 3
I 3
D 4
	movw	$1,HL_da(r10)			/* seek to sector 1 */
        movw    $HL_SEEK+HL_GO,HL_cs(r10)
E 4
I 4
D 8
	movw	$1,HL_da(r10)			/* seek to cylinder 0 */
	movw    $HL_SEEK+HL_GO,HL_cs(r10)
E 8
I 8
	movw	$1,HL_da(r8)			/* seek to cylinder 0 */
	bisw3	r7,$HL_SEEK,HL_cs(r8)
E 8
E 4
E 3
1:
D 3
        insv    r3,$7,$9,r5
        clrl    r2
        ediv    $HLSECT,r1,r2,r1
        tstl    r2
        beql    1f
        bisl2   $HL_HS,r5
E 3
I 3
D 8
        movw    HL_cs(r10),r0
E 8
I 8
        movw    HL_cs(r8),r0
E 8
        bbc     $HL_pRDY,r0,1b
        bbs     $HL_pERR,r0,hlerr
D 4
	movw	$1,HL_da(r10)			/* read program */
E 4
I 4
	/* Rl has 256 byte sectors */
D 8
	movw	$2,HL_da(r10)			/* read program */
E 4
	movw	$-PROGSIZE/2,HL_wc(r10)
E 8
I 8
	movw	$2,HL_da(r8)			/* read program */
	movw	$-PROGSIZE/2,HL_wc(r8)
E 8
	clrl	r0
E 3
1:
D 3
        movl    r5,HL_da(r10)
	ashl	$7,r0,r5
        movw    $HL_SEEK+HL_GO,HL_cs(r10)
        bsbb    hlwait
	tstl	r2
	beql	1f
	bisl2	$0x40,r5
E 3
I 3
	bisl3	$0x80000000,r0,UBA_MAP(r9)
	addl2	$4,r9
	aobleq	$BOOTSIZE,r0,1b
D 8
	clrw	HL_ba(r10)
	movw	$HL_RCOM+HL_GO,HL_cs(r10)
E 8
I 8
	clrw	HL_ba(r8)
	bisw3	r7,$HL_RCOM,HL_cs(r8)
E 8
E 3
1:
D 3
	addl2	r1,r5
        ashl    $-9,bufptr,r0
        bisl3   $0x80000000,r0,UBA_MAP(r9)
        incl    r0
        bisl3   $0x80000000,r0,UBA_MAP+4(r9)
        clrw    HL_ba(r10)
	movw	r5,HL_da(r10)
        movw    $-BLKSIZ/2,HL_mp(r10)
        movw    $HL_RCOM+HL_GO,HL_cs(r10)
hlwait:         /* wait for controller ready */
E 3
D 8
        movw    HL_cs(r10),r0
E 8
I 8
        movw    HL_cs(r8),r0
E 8
D 3
        bbc     $HL_pRDY,r0,hlwait
E 3
I 3
        bbc     $HL_pRDY,r0,1b
E 3
D 8
        bbs     $HL_pERR,r0,hlerr
D 3
        bicpsw  $2
        rsb
E 3
I 3
D 4
        brw	done
E 4
I 4
	brw	done
E 8
I 8
        bbc     $HL_pERR,r0,done
E 8
E 4
E 3
hlerr:
D 3
        halt    /* ungraceful */
bufptr: .long  buf
names:  .byte   'b,'o,'o,'t,0,0,0,0,0,0,0,0,0,0
        .byte  0
E 3
I 3
        halt				/* ungraceful */
done:
        movl    $PROGSIZE,r3
clrcor:
        clrq    (r3)
        acbl    $RELOC,$8,r3,clrcor
/* run loaded program */
D 4
        movl    $8,r10			/* major("/dev/hl0a") */
E 4
I 4
D 8
        movl    $14,r10			/* major("/dev/hl0a") */
E 8
E 4
        calls   $0,*$0
        brw     start2
E 3
physUBA:
D 8
        .long   0
D 3
        .long   0x20006000      /* 11/780 */
        .long   0xf30000        /* 11/750 */
        .long   0xf26000        /* 11/7ZZ */
E 3
I 3
        .long   0x20006000		/* 11/780 */
        .long   0xf30000		/* 11/750 */
        .long   0xf26000		/* 11/730 */
E 3
physUMEM:
        .long   0
D 3
        .long   0x2013e000      /* 11/780 */
        .long   0xffe000        /* 11/750 */
        .long   0xffe000        /* 11/7ZZ */
E 3
I 3
        .long   0x2013e000		/* 11/780 */
        .long   0xffe000		/* 11/750 */
        .long   0xffe000		/* 11/730 */
E 8
I 8
	.long	0xf30000		/* uba0 */
	.long	0xf32000		/* uba1 */
E 8
E 3
end:
D 3
        .set    buf,RELOC-1536
        .set    inode,RELOC-512
        .set    mode,inode
        .set    nlink,mode+2
        .set    uid,nlink+2
        .set    gid,uid+2
        .set    size,gid+2
        .set    addr,size+4
        .set    time,addr+40
        .set    bno,time+12
E 3
E 1
