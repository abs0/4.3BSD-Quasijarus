h18337
s 00004/00004/00448
d D 7.2 86/08/28 20:59:22 karels 12 11
c changes for pack labels; use cpp, now are *.c
e
s 00001/00001/00451
d D 7.1 86/06/05 01:53:56 mckusick 11 10
c 4.3BSD release version
e
s 00001/00003/00451
d D 6.3 85/06/26 14:02:58 bloom 10 9
c sccsids aren't executable kirk
e
s 00009/00001/00445
d D 6.2 85/06/08 12:21:35 mckusick 9 8
c Add copyright
e
s 00000/00000/00446
d D 6.1 83/08/01 11:58:31 sam 8 7
c 4.2 distribution
e
s 00007/00004/00439
d D 4.6 83/08/01 11:58:00 sam 7 5
c must set r11 to insure boot asks for name
e
s 00000/00000/00443
d R 6.1 83/07/29 07:43:32 sam 6 5
c 4.2 distribution
e
s 00001/00001/00442
d D 4.5 83/06/29 04:50:41 sam 5 4
c must strip parity bit when reading from console
e
s 00076/00001/00367
d D 4.4 83/06/22 12:05:02 helge 4 3
c appended rad50 conversion table
e
s 00078/00076/00290
d D 4.3 83/06/19 22:45:29 helge 3 2
c works...!!
e
s 00194/00101/00172
d D 4.2 83/06/19 00:54:21 helge 2 1
c new version, rt-11 format instead of tp-format - untested
e
s 00273/00000/00000
d D 4.1 83/02/16 22:06:43 sam 1 0
c date and time created 83/02/16 22:06:43 by sam
e
u
U
t
T
I 1
D 2
/*	%M%	%I%	%E%	*/
E 2
I 2
D 3
/*	tuboot.s	4.1	83/02/16	*/
E 3
I 3
D 9
/*	%M%	%I%	%E%	*/
E 9
I 9
/*
D 11
 * Copyright (c) 1980 Regents of the University of California.
E 11
I 11
 * Copyright (c) 1980, 1986 Regents of the University of California.
E 11
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

D 10
#ifndef lint
_sccsid:.asciz	"%W% (Berkeley) %G%"
#endif not lint
E 10
I 10
/* "%W% (Berkeley) %G%" */
E 10
E 9
E 3
E 2

/*
 * VAX tu58 console cassette boot block
 *
D 3
 * Thomas Ferrin  27oct82
E 3
I 3
 * Helge Skrivervik CSRG/UCB 18jun83
E 3
 *
D 3
 * Reads a program from a tp directory on tape
 * and executes it.  Program must be stripped of
E 3
I 3
 * Reads a program from a rt-11 directory on tape
 * and executes it.  Programs must be stripped of
E 3
 * the header and is loaded ``bits as is''.
 * You can return to this loader via ``ret'' as
 * you are called ``calls $0,ent''.
I 2
D 3
 * 
 * Helge Skrivervik CSRG/UCB 18jun83
 * 	Changed to use rt-11 format directory & files
 *	instead of tp format
E 3
I 3
 * Error checking and recovery is almost nonexistant
 * due to the severe space constraints.
 *
 * NOTE: Any changes to this program are likely to
 *	 bring the size over 512 bytes ....
 *
 * Based on tp format bootstrap originally written by Thomas Ferrin.
 *
E 3
E 2
 */
I 3
	.set	CTABLE,0x400	/* where to load the rad50 cnv table */
E 3
	.set	RELOC,0x70000
D 3
/* a.out defines */
	.set	HDRSIZ,040	/* size of file header for VAX */
	.set	MAGIC,0410	/* file type id in header */
	.set	TSIZ,4		/* text size */
	.set	DSIZ,8		/* data size */
	.set	BSIZ,12		/* bss size */
	.set	TENT,024	/* task header entry loc */
E 3
D 2
/* tp directory definitions */
/*	.set	DIRBLK,8	/* tp directory starts at block 8 */
	.set	DIRBLK,1	/* tp directory starts at block 1 */
	.set	FILSIZ,38	/* tp direc offset for file size */
	.set	BNUM,44		/* tp dir offset for start block no. */
	.set	ENTSIZ,64	/* size of 1 TP dir entry, bytes */
	.set	PTHSIZ,32	/* size of TP path name, bytes */
E 2
I 2
/* rt-11 directory definitions */
	.set	DIRBLK,6	/* rt-11 directory starts at block 6 */
	.set	FILSIZ,8	/* rt-11 direc entry offset for file size */
	.set	ENTSIZ,14	/* size of 1 rt-11 dir entry, bytes */
E 2
	.set	BLKSIZ,512	/* tape block size, bytes */
D 2
	.set	NUMDIR,24	/* no. of dir blocks on tape */
	.set	ENTBLK,8	/* no. of dir entries per tape block */
E 2
I 2
	.set	NUMDIR,2	/* no. of dir blocks on tape */
D 3
	.set	RT_FNSIZ,8	/* size of rad50 filename + 2 */
E 3
I 3
	.set	FNSIZ,8		/* size of rad50 filename + 2 */
E 3
	.set	NAME,2		/* direc entry offset for filename */
D 3
	.set	RT_STAT,1	/* direc entry offset for entry status */
E 3
I 3
	.set	STATUS,1	/* direc entry offset for entry status */
E 3
/* rt-11 directory entry status */
	.set	RT_ESEG,8	/* end of directory segment */
	.set	RT_NULL,2	/* empty entry */
	.set	RT_FILE,4	/* valid file entry */
E 2
/* processor registers and bits */
	.set	RXCS,32
	.set	RXDB,33
	.set	TXCS,34
	.set	TXDB,35
	.set	RXCS_DONE,0x80
	.set	TXCS_RDY,0x80
	.set	TXCS_pr,7	/* bit position of TXCS ready bit */
	.set	RXCS_pd,7	/* bit position of RXCS done bit */
/* console storage registers and bits */
	.set	CSRS,0x1c
	.set	CSRD,0x1d
	.set	CSTS,0x1e
	.set	CSTD,0x1f
/* TU commands and bits */
	.set	TU_BREAK,1
	.set	TU_INIT,4
	.set	TU_CONTINUE,16
	.set	TU_READY,7	/* bit position of CSRS ready bit */
	.set	TU_PACKETLEN,8	/* length of readcom block */
/* local stack variables */
D 2
	.set	tapa,-4		/* desired tape addr */
	.set	name,-8-PTHSIZ	/* operator-typed file name */
/* ===== */
E 2
I 2
D 7
	.set	ext,-4				/* file ext. */
	.set	name,-20			/* 12 bytes for full name */
D 3
	.set	rt_name,-20-RT_FNSIZ		/* rad50 file name */
E 3
I 3
	.set	rt_name,-20-FNSIZ		/* rad50 file name */
E 7
I 7
	.set	ext,-4			/* file ext. */
	.set	name,-20		/* 12 bytes for full name */
	.set	rt_name,-20-FNSIZ	/* rad50 file name */
/* reboot flags for boot */
	.set	RB_ASK,3		/* ask name and come up single user */
E 7
E 3
E 2

D 2
/* initialization */
E 2
I 2
/* 
 * Initialization.
 */
E 2
init:
	.word	0 		/* entry mask for dec monitor */
	nop;nop;nop;nop;nop	/* some no-ops for 750 boot rom to skip */
	nop;nop;nop;nop;nop 
	movl	$RELOC,fp	/* core loc to which to move this program */
D 3
	addl3	$name,fp,sp	/* set stack pointer; leave room for locals */
E 3
I 3
	addl3	$rt_name,fp,sp	/* set stack pointer; leave room for locals */
E 3
	clrl	r0
1:
	movc3	$end,(r0),(fp)	/* move boot up to relocated position */
	jmp	start+RELOC

start:
D 3
/* init tu58 */
E 3
	mtpr	$TU_BREAK,$CSTS		/* set break condition */
D 2
	clrl	r2		/* nulls */
	bsbw	xmit2		/* wait 2 character times */
	mfpr	$CSRD,r2	/* clear receive buffer */
E 2
I 2
	clrl	r2			/* nulls */
	bsbw	xmit2			/* wait 2 character times */
	mfpr	$CSRD,r2		/* clear receive buffer */
E 2
	movzwl	$TU_INIT|(TU_INIT<<8),r2	/* load 2 INIT opcodes */
D 2
	bsbw	xmit2		/* xmit 'em */
E 2
I 2
	bsbw	xmit2			/* xmit 'em */
E 2
1:
D 2
	mfpr	$CSRD,r7	/* get recv data */
E 2
I 2
	mfpr	$CSRD,r7		/* get recv data */
E 2
	cmpb	r7,$TU_CONTINUE		/* is it a continue flag? */
D 2
	bneq	1b		/* nope, look more */
E 2
I 2
	bneq	1b			/* nope, look more */
E 2

I 2
D 3
	clrq	rt_name(fp)		/* init rad50 filename */
E 3
E 2
	movab	name(fp),r4		/* start of filename storage */
I 3
	clrq	(r4)			/* init name field */
	clrq	name+8(fp)
	clrq	rt_name(fp)		/* init rad50 filename */
E 3
	movzbl	$'=,r0			/* prompt character */
	bsbw	putc			/* output char to main console */

D 3
/* read in a file name */
E 3
I 3
/* 
 * Read in a file name from console. 
 */
E 3
	movl	r4,r1			/* loc at which to store file name */
nxtc:
	bsbw	getc			/* get input char's in file name */
	cmpb	r0,$012			/* terminator ? */
	beql	nullc
	movb	r0,(r1)+
	brb	nxtc
nullc:
D 3
	subl3	r4,r1,r9		/* size of path name */
E 3
I 3
	cmpl	r4,r1
E 3
D 2
	beql	start			/* dumb operator */
	clrb	(r1)+
	incl	r9
E 2
I 2
	beql	start			/* restart if empty string */
	clrb	(r1)			/* add null byte at end */
D 3
	incl	r9			/* and fix length */
E 3
E 2

D 2
/* user-specified tp filename has been stored at name(fp) */
/* read in entire tp directory contents into low core */
E 2
I 2
/*
D 3
 * user-specified filename has been stored at name(fp) 
 * read in entire directory contents into low core 
E 3
I 3
 * User-specified filename has been stored at name(fp),
 * read the entire directory contents into low core.
E 3
 */
E 2
dirred:
D 2
	movl	$DIRBLK,tapa(fp)	/* tp directory starts at block DIRBLK */
E 2
I 2
	movl	$DIRBLK,r10		/* directory starts at block DIRBLK */
E 2
	movl	$(NUMDIR*BLKSIZ),r6	/* no. bytes in total dir */
I 2
	clrl	r11			/* start address */
E 2
	bsbw	taper			/* read no. bytes indicated */
I 2
/*
 * Read in the character conversion table which reside in block 1
D 3
 * (the second block) on the cassette.
E 3
I 3
 * (the second block) on the cassette. Place it after the directory
 * on low core (from 0x400).
E 3
 */
D 3
	movl	$1,r10			/* start block */
E 3
I 3
	movl	$1,r10			/* block number */
E 3
	movl	$BLKSIZ,r6		/* read one block */
D 3
	movl	0x400,r11		/* place it after the directory */
E 3
	bsbw	taper
E 2

D 2
/* search entire directory for user-specified file name */
	clrl	r5			/* dir buff loc = 0 */
nxtdir:
	cmpc3	r9,(r5),(r4)		/* see if dir entry matches filename */
E 2
I 2
/*
 * Convert the ascii filename to rad50.
I 3
 * R4 still points to name(fp)
E 3
 */
D 3
	movab	name(fp),r4		/* ptr to ascii name */
E 3
	movl	$6,r3			/* max length of filename */
1:
	cmpb	$'.,(r4)+		/* look for '.' */
I 3
	beql	1f
E 3
	sobgtr	r3,1b
I 3
	incl	r4			/* point past '.' if ext is present */
1:
E 3
	clrb	-1(r4)			/* end name with null */
	movl	$3,r3			/* max length of extension */
	movab	ext(fp),r5		/* place extension here */
1:
	movb	(r4)+,(r5)+
	beql	1f			/* the string is null terminated */
	sobgtr	r3,1b
1:
	movab	name(fp),r4
	movab	rt_name(fp),r5		/* ptr to rad50 name */
	bsbw	rad50			/* convert filename */
	movab	ext(fp),r4
	movab	rt_name+4(fp),r5
	bsbw	rad50			/* convert extension */

/*
 * Search entire directory for user-specified file name.
 */

	movab	rt_name(fp),r4		/* search for this file */
D 3
	movl	$10,r5			/* dir buff loc = 0, point to first */
					/* file entry */
	movzwl	-2(r5),r3		/* r3 = block # where files begin */
E 3
I 3
	movl	$10,r5			/* point to first file entry */
	movzwl	-2(r5),r10		/* r10 = block # where files begin */
E 3
2:
	cmpc3	$6,NAME(r5),(r4)	/* see if dir entry matches filename */
E 2
	beql	fndfil			/* found match */
D 2
	acbl	$NUMDIR*BLKSIZ-1,$ENTSIZ,r5,nxtdir
					/* see if done with tp dir */
E 2
I 2
1:
D 3
	addw2	FILSIZ(r5),r3		/* add file length to block pointer */
E 3
I 3
	addw2	FILSIZ(r5),r10		/* add file length to block pointer */
E 3
	addl2	$ENTSIZ,r5		/* move to next entry */
D 3
#	cpmb	RT_STAT(r5),$RT_NULL	/* check if deleted file */
#	beql	1b
	cmpb	RT_STAT(r5),$RT_ESEG	/* check if end of segment */
E 3
I 3
D 12
#	cpmb	STATUS(r5),$RT_NULL	/* check if deleted file */
#	beql	1b /* not really necessary since deleted entries will fail */
E 12
I 12
/*	cpmb	STATUS(r5),$RT_NULL	/* check if deleted file */
/*	beql	1b /* not really necessary since deleted entries will fail */
E 12
		   /* to compare anyway */
	cmpb	STATUS(r5),$RT_ESEG	/* check if end of segment */
E 3
	bneq	2b
E 2
	brw	start			/* entry not in directory; start over */

D 2
/* found desired tp dir entry */
E 2
I 2
/* 
 * Found desired directory entry 
 */
E 2
fndfil:
D 2
	movzwl	BNUM(r5),tapa(fp)	/* start block no., 2 bytes */
	addl2	$DIRBLK-1,tapa(fp)	/* skip boot block(s) */
	movzwl	FILSIZ(r5),r6		/* low 2 bytes file size */
	insv	FILSIZ-1(r5),$16,$8,r6	/* file size, high byte */
	cmpl	r6,$RELOC-512		/* check if file fits below stack */
	blss	filok 			/* file o.k. */
	brw	start			/* file too large */
E 2
I 2
D 3
	movl	r3,r10			/* start block no., 2 bytes */
E 3
I 3
					/* start block no., 2 bytes in r10 */
E 3
	movzwl	FILSIZ(r5),r6		/* file size (blocks) */
	mull2	$BLKSIZ,r6		/* file size (bytes) */
D 3
#	cmpl	r6,$RELOC-512		/* check if file fits below stack */
#	blss	filok
#	brw	start			/* file too large */
E 3
I 3
	cmpl	r6,$RELOC-512		/* check if file fits below stack */
	blss	filok
	brw	start			/* file too large */
E 3
E 2

D 2
/* time to read in desired file from tape */
E 2
I 2
/* 
 * Read in desired file from tape.
 */
E 2
filok:
	movl	r6,r5			/* start of bss space */
I 2
	clrl	r11			/* start address */
E 2
	bsbb	taper
D 2
	bsbb	rew
E 2
I 2
D 3
#	bsbb	rew
E 3
E 2

D 2
/* clear core */
E 2
I 2
/* 
 * Clear core.
 */
E 2
	subl3	r5,$RELOC-4,r0		/* no. bytes to clear */
1:
	clrb	(r5)+
	sobgtr	r0,1b

D 2
/* time to jump to start of file & execute */
E 2
I 2
/* 
 * Jump to start of file & execute.
 */
E 2
D 3
	addl3	$20,fp,ap
E 3
I 3
	addl3	$20,fp,ap		/* ?? */
E 3
	clrl	r5
I 7
	movl	$RB_ASK,r11
E 7
	calls	$0,(r5)
bad:
	brw	start

D 3
/* rewind tape */
I 2
#ifdef notdef
E 2
rew:
D 2
	movb	$5,readcom+2	/* position opcode */
	clrl	tapa(fp)	/* block 0 */
	clrl	r6		/* 0 bytes */
E 2
I 2
	movb	$5,readcom+2		/* position opcode */
	clrl	r10			/* block 0 */
	clrl	r6			/* 0 bytes */
E 2
	bsbb	taper
D 2
	movb	$2,readcom+2	/* read opcode */
E 2
I 2
	movb	$2,readcom+2		/* read opcode */
E 2
	rsb
I 2
#endif
E 2

D 2
/* read (r6) bytes from tapa(fp) into loc 0 */
E 2
I 2
/* read (r6) bytes from (r10) into loc (r11) */
E 3
I 3
/* 
 * Read (r6) bytes from block (r10) 
 * into loc (r11).
 */
E 3
E 2
taper:
D 2
	clrl	r8		/* initialize checksum */
	movab	readcom,r0	/* read command packet addr */
E 2
I 2
	clrl	r8			/* initialize checksum */
	movab	readcom,r0		/* read command packet addr */
E 2
	movzbl	$TU_PACKETLEN/2,r1	/* size of readcom block */
1:
D 2
	movzwl	(r0)+,r2	/* get 2 chars from block */
	bsbb	xmit		/* xmit and update ckecksum */
	sobgtr	r1,1b		/* loop if more */
E 2
I 2
	movzwl	(r0)+,r2		/* get 2 chars from block */
	bsbb	xmit			/* xmit and update ckecksum */
	sobgtr	r1,1b			/* loop if more */
E 2

D 3
	/* now do variable part of packet */
E 3
I 3
/* 
 * Now do variable part of packet. 
 */
E 3
D 2
	movl	r6,r2		/* byte count */
E 2
I 2
	movl	r6,r2			/* byte count */
E 2
	bsbb	xmit
D 2
	movzwl	tapa(fp),r2	/* starting block number */
E 2
I 2
	movl	r10,r2			/* starting block number */
E 2
	bsbb	xmit
D 2
	movzwl	r8,r2		/* accumulated ckecksum */
E 2
I 2
	movzwl	r8,r2			/* accumulated ckecksum */
E 2
	bsbb	xmit

D 3
	/* collect read packet from device */
D 2
	clrl	r0		/* starting addr */
E 2
I 2
	movl	r11,r0			/* starting addr */
E 3
I 3
/* 
 * Collect read packet from device. 
 */
E 3
E 2
1:
D 2
	bsbb	recv2		/* get 2 packet characters */
	decb	r2		/* data packet? */
	bneq	1f		/* branch on end of data */
	movzbl	r1,r8		/* get byte count of packet */
E 2
I 2
	bsbb	recv2			/* get 2 packet characters */
	decb	r2			/* data packet? */
	bneq	1f			/* branch on end of data */
	movzbl	r1,r8			/* get byte count of packet */
E 2

D 3
	/* read data into memory */
E 3
I 3
/* 
 * Read data into memory.
 */
E 3
2:
D 2
	bsbb	recv1		/* get a char */
	movb	r1,(r0)+	/* stuff into memory */
	sobgtr	r8,2b		/* loop if more */
	bsbb	recv2		/* skip checksum */
	brb	1b		/* read next packet */
E 2
I 2
	bsbb	recv1			/* get a char */
D 3
	movb	r1,(r0)+		/* stuff into memory */
E 3
I 3
	movb	r1,(r11)+		/* stuff into memory */
E 3
	sobgtr	r8,2b			/* loop if more */
	bsbb	recv2			/* skip checksum */
	brb	1b			/* read next packet */
E 2

D 3
	/* end of data xfer; check for errors */
E 3
I 3
/* 
 * End of data xfer; check for errors.
 */
E 3
1:
D 2
	subl2	r6,r0		/* all bytes xfered? */
	bneq	9f		/* nope, error */
	bsbb	recv2		/* get success code */
	tstl	r1		/* error in read? */
	blss	9f		/* branch if status error */
E 2
I 2
D 3
	subl2	r6,r0			/* all bytes xfered? */
	bneq	9f			/* nope, error */
E 3
	bsbb	recv2			/* get success code */
	tstl	r1			/* error in read? */
	blss	9f			/* branch if status error */
E 2
	movl	$5,r0
1:
D 2
	bsbb	recv2		/* discard 10 bytes */
E 2
I 2
	bsbb	recv2			/* discard 10 bytes */
E 2
	sobgtr	r0,1b
	rsb

D 3
	/* fatal error */
E 3
I 3
/* Fatal error */
E 3
9:
	movab	ermsg,r1
1:
	movb	(r1)+,r0
	beql	bad
	bsbb	putc
	brb	1b

D 3
	/* update checksum in r8 and xmit 2 characters */
E 3
I 3
/* 
 * Update checksum in r8 and xmit 2 characters.
 */
E 3
xmit:
D 2
	addw2	r2,r8		/* update checksum */
	bcc	xmit2		/* branch if no overflow */
	incw	r8		/* add  in carry */
E 2
I 2
	addw2	r2,r8			/* update checksum */
D 3
	bcc	xmit2			/* branch if no overflow */
	incw	r8			/* add  in carry */
E 3
I 3
	adwc	$0,r8			/* add  in carry */
E 3
E 2

D 3
	/* send the 2 characters contained in r2 */
E 3
I 3
/* send the 2 characters contained in r2 */
E 3
xmit2:
D 2
	bsbb	1f		/* xmit one of 'em */
	ashl	$-8,r2,r2	/* get next char */
				/* fall into... */
E 2
I 2
	bsbb	1f			/* xmit one of 'em */
	ashl	$-8,r2,r2		/* get next char */
					/* fall into... */
E 2
1:
D 2
	mfpr	$CSTS,r7	/* get xmit status */
	bbc	$TU_READY,r7,1b	/* loop until ready */
	mtpr	r2,$CSTD	/* send char */
E 2
I 2
	mfpr	$CSTS,r7		/* get xmit status */
	bbc	$TU_READY,r7,1b		/* loop until ready */
	mtpr	r2,$CSTD		/* send char */
E 2
	rsb

D 3
	/* receive 2 characters, return in r2 and r1 */
E 3
I 3
/* 
 * Receive 2 characters, return in r2 and r1.
 */
E 3
recv2:
D 2
	bsbb	recv1		/* recv one of 'em */
				/* fall into... */
E 2
I 2
	bsbb	recv1			/* recv one of 'em */
					/* fall into... */
E 2

D 3
	/* receive 1 character */
E 3
I 3
/* 
 * Receive 1 character.
 */
E 3
recv1:
D 2
	movzbl	r1,r2		/* save previous byte */
E 2
I 2
	movzbl	r1,r2			/* save previous byte */
E 2
1:
D 2
	mfpr	$CSRS,r7	/* get recv status */
	bbc	$TU_READY,r7,1b	/* loop until ready */
	mfpr	$CSRD,r1	/* get char */
	blss	9b		/* branch on recv error */
E 2
I 2
	mfpr	$CSRS,r7		/* get recv status */
	bbc	$TU_READY,r7,1b		/* loop until ready */
	mfpr	$CSRD,r1		/* get char */
D 4
#	blss	9b			/* branch on recv error */
E 4
I 4
	blss	9b			/* branch on recv error */
E 4
E 2
	rsb

getc:
	mfpr	$RXCS,r0
	bbc	$RXCS_pd,r0,getc	/* receiver ready ? */
	mfpr	$RXDB,r0
D 2
	extzv	$0,$7,r0,r0
E 2
I 2
D 5
	movzbl	r0,r0
E 5
I 5
	extzv	$0,$7,r0,r0
E 5
E 2
	cmpb	r0,$015
	bneq	putc			/* echo and return */
	bsbb	putc			/* carriage return */
D 2
	movb	$0,r0
	bsbb	putc			/* delay */
E 2
I 2
D 12
#	movb	$0,r0
#	bsbb	putc			/* delay */
E 12
I 12
/*	movb	$0,r0	*/
/*	bsbb	putc	*/		/* delay */
E 12
E 2
	movb	$012,r0			/* send line feed and return */
putc:
	mfpr	$TXCS,r2
	bbc	$TXCS_pr,r2,putc	/* transmitter ready ? */
D 2
	extzv	$0,$7,r0,r0
E 2
	mtpr	r0,$TXDB
	rsb

I 2
/*
 * Convert the filename given from the console
 * to radix 50 (rt-11) format.
 */
rad50:
D 3
	movl	$0x400,r6		/* address of conversion table */
1:
E 3
I 3
	clrw	r1
E 3
	bsbb	getb50			/* get next ascii byte, exit if null */
	mull3	$03100,r0,r1
	bsbb	getb50
	mull3	$050,r0,r2
	addl2	r2,r1
	bsbb	getb50
	addl2	r0,r1			/* last byte, just add it in */
	movw	r1,(r5)+		/* save result */
D 3
	brb	1b
E 3
I 3
	brb	rad50
E 3

getb50:
	movzbl	(r4)+,r0		/* get next ascii byte */
	beql	1f			/* if zero: end of string */
D 3
	addl2	r6,r0			/* calculate conversion table address */
	movzbl	(r0),r0			/* and get the r50 byte from the table*/
E 3
I 3
	movzbl	CTABLE(r0),r0		/* and get the r50 byte from the table*/
E 3
	rsb
1:
	tstl	(sp)+			/* we're through, get back to where */
					/* rad50 was called */
	movw	r1,(r5)			/* but first save the result */
	rsb

E 2
	.align	2
readcom:
D 2
	.byte	2	/* command packet flag */
	.byte	10	/* number of bytes in message */
	.byte	2	/* tu read opcode */
	.byte	0	/* modifier */
	.byte	0	/* unit number */
	.byte	0	/* switches */
	.word	0	/* sequence number */
			/* byte count and block number follow */
E 2
I 2
	.byte	2			/* command packet flag */
	.byte	10			/* number of bytes in message */
	.byte	2			/* tu read opcode */
	.byte	0			/* modifier */
	.byte	0			/* unit number */
	.byte	0			/* switches */
	.word	0			/* sequence number */
					/* byte count and block number follow */
E 2

ermsg:
D 3
	.asciz	"tu58 err\r\n"
E 3
I 3
D 7
	.asciz	"tu err\r\n"
E 7
I 7
	.asciz	"tuerr\r\n"
E 7
E 3
end:
I 4

/*
 * Ascii to rad 50 conversion table,
 * stored on the second block on the cassette
 *
 * NOTE: Always make sure this table ends up
 * starting at byte 512!!!!
 */
	.align	2
	.data	2
	.long	0x1d1d1d1d
	.long	0x1d1d1d1d
	.long	0x1d1d1d1d
	.long	0x1d1d1d1d
	.long	0x1d1d1d1d
	.long	0x1d1d1d1d
	.long	0x1d1d1d1d
	.long	0x1d1d1d1d
	.long	0x1d1d1d00
	.long	0x1d1d1d1b
	.long	0x1d1d1d1d
	.long	0x1d1c1d1d
	.long	0x21201f1e
	.long	0x25242322
	.long	0x1d1d2726
	.long	0x1d1d1d1d
	.long	0x302011d
	.long	0x7060504
	.long	0xb0a0908
	.long	0xf0e0d0c
	.long	0x13121110
	.long	0x17161514
	.long	0x1d1a1918
	.long	0x1d1d1d1d
	.long	0x302011d
	.long	0x7060504
	.long	0xb0a0908
	.long	0xf0e0d0c
	.long	0x13121110
	.long	0x17161514
	.long	0x1d1a1918
	.long	0x1d1d1d1d
	.long	0x1d1d1d1d
	.long	0x1d1d1d1d
	.long	0x1d1d1d1d
	.long	0x1d1d1d1d
	.long	0x1d1d1d1d
	.long	0x1d1d1d1d
	.long	0x1d1d1d1d
	.long	0x1d1d1d1d
	.long	0x1d1d1d00
	.long	0x1d1d1d1b
	.long	0x1d1d1d1d
	.long	0x1d1c1d1d
	.long	0x21201f1e
	.long	0x25242322
	.long	0x1d1d2726
	.long	0x1d1d1d1d
	.long	0x302011d
	.long	0x7060504
	.long	0xb0a0908
	.long	0xf0e0d0c
	.long	0x13121110
	.long	0x17161514
	.long	0x1d1a1918
	.long	0x1d1d1d1d
	.long	0x302011d
	.long	0x7060504
	.long	0xb0a0908
	.long	0xf0e0d0c
	.long	0x13121110
	.long	0x17161514
	.long	0x1d1a1918
	.long	0x1d1d1d
	.data
E 4
E 1
