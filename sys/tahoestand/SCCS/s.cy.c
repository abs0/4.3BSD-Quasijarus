h08533
s 00009/00010/00275
d D 7.7 88/05/24 13:33:05 bostic 7 6
c change to dev(a,b,c,d) format
e
s 00014/00007/00271
d D 7.6 87/04/07 16:31:04 karels 6 5
c open needs returns!
e
s 00015/00009/00263
d D 7.5 87/04/02 16:29:02 karels 5 4
c fix error msgs
e
s 00113/00167/00159
d D 7.4 87/02/17 10:53:53 karels 4 3
c make it look like kernel driver
e
s 00113/00133/00213
d D 7.3 86/12/19 08:43:49 sam 3 2
c massive rework; fix access of files > 0
e
s 00005/00002/00341
d D 7.2 86/01/21 11:38:16 sam 2 1
c make things compile again after changing vdreg.h and creatng vbparam.h
e
s 00343/00000/00000
d D 7.1 86/01/12 18:04:58 sam 1 0
c date and time created 86/01/12 18:04:58 by sam
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/
D 3
/*	cy.c	Tahoe version 	Mar 1983.	*/
E 3

/*
 * Cypher tape driver. Stand alone version.
D 3
 *
E 3
 */
#include "../machine/pte.h"
#include "../machine/mtpr.h"

#include "param.h"
#include "inode.h"
#include "fs.h"

#include "saio.h"
D 4
#include "cyvar.h"
E 4

I 4
#define CYERROR
#include "../tahoevba/cyreg.h"
E 4
I 2
#include "../tahoevba/vbaparam.h"

I 4
/*
 * NB: this driver assumes unit 0 throughout.
 */
E 4
E 2
long	cystd[] = { 0xf4000, 0 };
I 2
#define	CYADDR(i)	(cystd[i] + (int)VBIOBASE)
E 2

D 3
struct scp	/* SYSTEM CONFIGURATION POINTER */
{
  char sysbus ;	/* width of system buss 0=8;1=16 */
  char nu1 ;
  char pt_scb[4] ;	/* pointer to ->SYSTEM CONFIGURATION BLOCK */
};
E 3
I 3
D 4
struct scp {
	char sysbus;		/* width of system bus 0=8;1=16 */
	char nu1;
	char pt_scb[4];
} *SCP;
E 4
I 4
struct	cyscp *cyscp[] = { (struct cyscp *)0xc06, (struct cyscp *)0 };
#define	CYSCP(i)	(cyscp[i])
E 4
E 3

D 3
struct scp * SCP;	/* absolute address - jumpered on the controller */
			/* set to 0xC06 for Tahoe */
E 3
I 3
D 4
struct scb {
	char sysblk[1];	/* 0x03 fixed value code */
	char nu2[1];
	char pt_ccb[4];
} scb;
E 3

D 3
struct scb	/* SYSTEM CONFIGUREATION BLOCK */
{
  char sysblk[1] ;	/* 0x03 fixed value code */
  char nu2[1] ;
  char pt_ccb[4] ;	/* pointer to ->CHANNEL CONTROL BLOCK */
}scb;
E 3
I 3
struct ccb {
	char ccw[1];		/* 0x11 normal; 0x09 clear non_vect interrupt */
	char gate[1];		/* This is "the" GATE */
	char pt_tpb[4];
} ccb;
E 3

D 3
struct ccb	/* CHANNEL CONTROL BLOCK */
{
  char ccw[1] ;		/* 0x11 normal; 0x09 clear non_vect interrupt */
  char gate[1] ;	/* This is "the" GATE */
  char pt_tpb[4] ;	/* pointer to ->TAPE OPERATION BLOCK or MOVE BLOCK */
}ccb;

struct tpb	/* TAPE OPERATIONS PARAMETER BLOCK */
{
  long cmd ;		/* COMMAND (input) */
  char control[2] ;	/* CONTROL (input) */
  short count ;		/* RETURN COUNT (output) */
  short size ;		/* BUFFER SIZE (input/output) */
  short rec_over ;	/* RECORDS/OVERRUN (input/output) */
  char pt_data[4] ;	/* pointer to ->SOURCE/DEST (input) */
  char status[2] ;	/* STATUS (output) */
  char pt_link[4] ;	/* pointer to ->INTERRUPT/PARAMETER BLOCK (input) */
E 3
I 3
struct tpb {
	long cmd;		/* COMMAND (input) */
	char control[2];	/* CONTROL (input) */
	short count;		/* RETURN COUNT (output) */
	short size;		/* BUFFER SIZE (input/output) */
	short rec_over;	/* RECORDS/OVERRUN (input/output) */
	char pt_data[4];	/* pointer to ->SOURCE/DEST (input) */
	char status[2];	/* STATUS (output) */
	char pt_link[4];
E 3
} tpb;

D 3
struct tpb cycool	/* tape parameter block to clear interrupts */
= {
	0L,		/* command */
	0,0,		/* control */
	0,		/* count */
	0,		/* size */
	0,		/* rec_over */
	0,0,0,0,	/* pt_data */
	0,0,		/* status */
	0,0,0,0		/* pt_link */
} ;	
int cyblksiz = 1024;	/* foreign tape size as found in open routine */
long cyblock;		/* next block number for i/o */
E 3
I 3
struct	tpb cycool;		/* tape parameter block to clear interrupts */
E 4
I 4
struct	cyscp *SCP;
struct	cyscb scb;
struct	cyccb ccb;
struct	cytpb tpb;
struct	cytpb cycool;		/* tape parameter block to clear interrupts */
#ifdef notdef
E 4
int	cyblocksize = 1024;	/* foreign tape size as found in open routine */
I 4
#endif
int	cybufsize;		/* controller buffer size */
E 4
long	cyblock;		/* next block number for i/o */

E 3
/*
 * Reset the controller.
 */
cyopen(io)
	register struct iob *io;
{
D 3
	register ctlradr;
E 3
I 3
	register ctlradr = CYADDR(0);
I 7
	register int skip;
E 7
E 3

D 2
	ctlradr = cystd[0] + (int)IOBASE;
E 2
I 2
D 3
	ctlradr = CYADDR(0);
E 3
E 2
D 4
	SCP = (struct scp *)0xc06;		/* absolute - for setup */
	TM_RESET(ctlradr,0xff);	/* reset the controller */
E 4
I 4
D 6
	if (io->i_unit != 0)
		_stop("Only 1 cypher supported\n");
E 6
I 6
D 7
	if (io->i_unit != 0) {
		printf("Only 1 cypher supported\n");
		return (ENXIO);
	}
E 7
I 7
	if ((u_int)io->i_adapt)
		return (EADAPT);
	if ((u_int)io->i_ctlr)
		return (ECTLR);
E 7
E 6
	SCP = CYSCP(0);				/* absolute - for setup */
	CY_RESET(ctlradr);			/* reset the controller */
E 4
	/*
	 * Initialize the system configuration pointer
	 */
D 4
	SCP->sysbus = 1;			/* system width = 16 bits. */
E 4
I 4
	SCP->csp_buswidth = 1;			/* system width = 16 bits. */
	SCP->csp_unused = 0;
E 4
	/* initialize the pointer to the system configuration block */
D 4
	set_pointer((long)&scb.sysblk[0],(char *)SCP->pt_scb);
E 4
I 4
	cyldmba(SCP->csp_scb, (caddr_t)&scb);
E 4
	/*
	 * Initialize the system configuration block.
	 */
D 4
	scb.sysblk[0] = 0x3;		/* fixed value */
E 4
I 4
	scb.csb_fixed = CSB_FIXED;		/* fixed value */
E 4
	/* initialize the pointer to the channel control block */
D 4
	set_pointer((long)&ccb.ccw[0],(char *)scb.pt_ccb);
E 4
I 4
	cyldmba(scb.csb_ccb, (caddr_t)&ccb);
E 4
	/*
	 * Initialize the channel control block.
	 */
D 4
	ccb.ccw[0] = 0x11;		/* normal interrupts */
E 4
I 4
	ccb.cbcw = CBCW_IE;		/* normal interrupts */
E 4
	/* initialize the pointer to the tape parameter block */
D 4
	set_pointer((long)&tpb,(char *)ccb.pt_tpb);
E 4
I 4
	cyldmba(ccb.cbtpb, (caddr_t)&tpb);
E 4
	/*
D 4
	 * set the command to be NO_OP.
E 4
I 4
	 * set the command to be CY_NOP.
E 4
	 */
D 4
	tpb.cmd = NO_OP;
	tpb.control[0] = CW_BL;		/* TPB not used on first attention */
	tpb.control[1] = CW_16bits;
	ccb.gate[0] = GATE_CLOSED;	
	TM_ATTENTION(ctlradr, 0xff);	/* execute! */
E 4
I 4
	tpb.tpcmd = CY_NOP;
	/*
	 * TPB not used on first attention
	 */
	tpb.tpcontrol = CYCW_LOCK | CYCW_16BITS;
	ccb.cbgate = GATE_CLOSED;	
	CY_GO(ctlradr);			/* execute! */
E 4
	cywait(10*1000);
	/*
D 4
	 * set the command to be CONFIGURE.
E 4
I 4
	 * set the command to be CY_CONFIGURE.
	 * NO interrupt on completion.
E 4
	 */
D 4
	tpb.cmd = CONFIG;
	tpb.control[0] = CW_BL;		/* NO interrupt on completion */
	tpb.control[1] = CW_16bits;
	tpb.status[0] = tpb.status[1] = 0;
	ccb.gate[0] = GATE_CLOSED;	
	TM_ATTENTION(ctlradr, 0xff);	/* execute! */
E 4
I 4
	tpb.tpcmd = CY_CONFIG;
	tpb.tpcontrol = CYCW_LOCK | CYCW_16BITS;
	tpb.tpstatus = 0;
	ccb.cbgate = GATE_CLOSED;	
	CY_GO(ctlradr);			/* execute! */
E 4
	cywait(10*1000);
D 3
	uncache (&tpb.status[1]) ;
E 3
I 3
D 4
	uncache(&tpb.status[1]);
E 3
	if (tpb.status[1] & CS_ERm) {
E 4
I 4
	uncache(&tpb.tpstatus);
	if (tpb.tpstatus & CYS_ERR) {
E 4
D 3
	   printf("Cypher initialization error!\n");
	   cy_decode_error(tpb.status[1]&CS_ERm);
	   _stop("");
E 3
I 3
		printf("Cypher initialization error!\n");
D 4
		(void) cy_decode_error(tpb.status[1]&CS_ERm);
E 4
I 4
D 5
		cy_print_error(tpb.tpstatus);
E 5
I 5
		cy_print_error(tpb.tpcmd, tpb.tpstatus);
E 5
E 4
D 6
		_stop("");
E 6
I 6
		return (ENXIO);
E 6
E 3
	}
D 3
	if(cycmd(io,REWD_TA) == -1)
E 3
I 3
D 4
	if (cycmd(io, REWD_TA) == -1)
E 4
I 4
	uncache(&tpb.tpcount);
	cybufsize = tpb.tpcount;
D 6
	if (cycmd(io, CY_REW) == -1)
E 4
E 3
		_stop("Rewind failed!\n");
E 6
I 6
	if (cycmd(io, CY_REW) == -1) {
		printf("cy%d: Rewind failed!\n", io->i_unit);
		return (ENXIO);
	}
E 6
D 3
	while(io->i_boff > 0) {
		if(cycmd(io,SPAC_FM) == -1)
E 3
I 3
D 7
	while (io->i_boff > 0) {
E 7
I 7
	for (skip = io->i_part; skip--;)
E 7
D 4
		if (cycmd(io, SRFM_FD) == -1)
E 4
I 4
D 6
		if (cycmd(io, CY_FSF) == -1)
E 4
E 3
			_stop("cy: seek failure!\n");
E 6
I 6
		if (cycmd(io, CY_FSF) == -1) {
			printf("cy%d: seek failure!\n", io->i_unit);
			return (ENXIO);
		}
E 6
D 7
		io->i_boff--;
	}
E 7
I 4
#ifdef notdef
E 4
#ifdef NOBLOCK
	if (io->i_flgs & F_READ) {
D 3
		if((cyblksiz = cycmd(io,READ_FO)) == -1)
			_stop("Read foriegn tape failed!\n");
		if(cycmd(io,REWD_TA) == -1)
			_stop("Rewind after read failed\n");
E 3
I 3
D 4
		cyblocksize = cycmd(io, READ_FO);
E 4
I 4
		cyblocksize = cycmd(io, CY_READFORN);
E 4
		if (cyblocksize == -1)
			_stop("Read foreign tape failed\n");
		cyblock++;		/* XXX force backspace record */
D 4
		if (cycmd(io, SPACE) == -1)
E 4
I 4
		if (cycmd(io, CY_SFORW) == -1)
E 4
			_stop("Backspace after read foreign failed\n");
E 3
	}
#endif
I 4
#endif
I 6
	return (0);
E 6
E 4
}

D 3
/* if tape was open for writing write a file mark */
E 3
cyclose(io)
	register struct iob *io;
{
D 3
	if (io->i_flgs & F_WRITE) cycmd(io,WRITE_FMARK);
	cycmd(io,REWD_TA);
	cyblock = 0;
E 3
I 3

D 4
	if (io->i_flgs & F_WRITE)	/* if writing, write file mark */
		cycmd(io, WRIT_FM);
	cycmd(io, REWD_TA);
E 4
I 4
	if (io->i_flgs & F_WRITE) {	/* if writing, write file marks */
		cycmd(io, CY_WEOF);
		cycmd(io, CY_WEOF);
	}
	cycmd(io, CY_REW);
E 4
E 3
}

D 3
cystrategy(io,func)
E 3
I 3
cystrategy(io, func)
E 3
	register struct iob *io;
D 3
	register long	func;
E 3
I 3
	register func;
E 3
{
I 5
	register count;
E 5

#ifndef NOBLOCK
D 3
	if ((func != SPACE) && (func != REWD_TA) && (io->i_bn != cyblock)) {
		cycmd(io,SPACE);
E 3
I 3
D 4
	if (func != SPACE && func != REWD_TA && io->i_bn != cyblock) {
		cycmd(io, SPACE);
E 3
		tpb.rec_over = 0;
E 4
I 4
	if (func != CY_SFORW && func != CY_REW && io->i_bn != cyblock) {
		cycmd(io, CY_SFORW);
		tpb.tprec = 0;
E 4
	}
D 3
	if(func==READ || func==WRITE) {
E 3
I 3
	if (func == READ || func == WRITE) {
E 3
		struct iob liob;
		register struct iob *lio = &liob;
D 5
		register count;
E 5

		liob = *io;
D 3
		while(lio->i_cc > 0) {
			if((count = cycmd(lio, func)) == 0)
				return(-1);
E 3
I 3
		while (lio->i_cc > 0) {
D 5
			if ((count = cycmd(lio, func)) == 0)
E 5
I 5
			if ((count = cycmd(lio, func)) == 0) {
				printf("cy%d: I/O error bn %d\n",
				    io->i_unit, io->i_bn);
E 5
				return (-1);
I 5
			}
E 5
E 3
			lio->i_cc -= count;
			lio->i_ma += count;
		}
D 3
		return(io->i_cc);
E 3
I 3
		return (io->i_cc);
E 3
	}
#endif
D 3
	return(cycmd(io, func));
E 3
I 3
D 5
	return (cycmd(io, func));
E 5
I 5
	count = cycmd(io, func);
	if (count == -1)
		printf("cy%d: I/O error bn %d\n", io->i_unit, io->i_bn);
	return (count);
E 5
E 3
}

D 3
cycmd(io,func)
E 3
I 3
cycmd(io, func)
E 3
	register struct iob *io;
D 3
	long	func;
E 3
I 3
	long func;
E 3
{
D 3
	register ctlradr;
E 3
I 3
	register ctlradr = CYADDR(0);
	int timeout = 0;
I 4
	int err;
E 4
E 3
	short j;

D 2
	ctlradr = cystd[0] + (int)IOBASE;
E 2
I 2
D 3
	ctlradr = CYADDR(0);
E 3
E 2
D 4
	cywait(9000); 
D 3
	if (func == READ) func = READ_TA;
	else if (func == WRITE) func = WRIT_TA;
	else if (func == WRITE_FMARK) func = WRIT_FM;
	tpb.cmd = func;
	uncache(&ccb.gate[0]);
	while(ccb.gate[0] == GATE_CLOSED)
		uncache(&ccb.gate[0]);
	ccb.gate[0] = GATE_CLOSED;
E 3
	tpb.control[0] = CW_BL;
	tpb.control[1] = CW_16bits;
	tpb.status[0] = tpb.status[1] = 0;
	tpb.count = 0;
D 3
	set_pointer((long)&tpb,(char *)ccb.pt_tpb);
	switch (func) 
	{
	case READ_TA:
		if (io->i_cc > cyblksiz)
			tpb.size = TM_SHORT(cyblksiz);
		else tpb.size = TM_SHORT(io->i_cc);
E 3
I 3
	set_pointer((long)&tpb, (char *)ccb.pt_tpb);
	tpb.cmd = func;
E 4
I 4
	cywait(9000); 			/* shouldn't be needed */
D 7
	tpb.tpcontrol = CYCW_LOCK | CYCW_16BITS;
E 7
I 7
#define	PACKUNIT(unit)	(((unit&1)<<11)|((unit&2)<<9)|((unit&4)>>2))
	tpb.tpcontrol = CYCW_LOCK | CYCW_16BITS | PACKUNIT(io->i_unit);
E 7
	tpb.tpstatus = 0;
	tpb.tpcount = 0;
	cyldmba(ccb.cbtpb, (caddr_t)&tpb);
	tpb.tpcmd = func;
E 4
	switch (func) {
	case READ:
I 4
#ifdef notdef
E 4
		if (io->i_cc > cyblocksize)
D 4
			tpb.size = TM_SHORT(cyblocksize);
E 4
I 4
			tpb.tpsize = htoms(cyblocksize);
E 4
		else
D 4
			tpb.size = TM_SHORT(io->i_cc);
E 3
		set_pointer((long)io->i_ma,(char *)tpb.pt_data);
D 3
		cyblock += 1;
E 3
I 3
		tpb.cmd = READ_TA;
E 4
I 4
#endif
		tpb.tpsize = htoms(io->i_cc);
		cyldmba(tpb.tpdata, io->i_ma);
		tpb.tpcmd = CY_RCOM;
E 4
		cyblock++;
E 3
		break;
D 3
	case WRIT_TA:
E 3
I 3
	case WRITE:
D 4
		tpb.cmd = WRIT_TA;
E 3
		tpb.size = TM_SHORT(io->i_cc);
D 3
		set_pointer((long)io->i_ma,(char *)tpb.pt_data);
		cyblock += 1;
E 3
I 3
		set_pointer((long)io->i_ma, (char *)tpb.pt_data);
E 4
I 4
		tpb.tpcmd = CY_WCOM;
		tpb.tpsize = htoms(io->i_cc);
		cyldmba(tpb.tpdata, io->i_ma);
E 4
		cyblock++;
E 3
		break;
D 4
	case SPACE:
E 4
I 4
	case CY_SFORW:
E 4
		if ((j = io->i_bn - cyblock) < 0) {
			j = -j;
D 4
			tpb.control[1] |= CW_R;
E 4
I 4
			tpb.tpcontrol |= CYCW_REV;
E 4
			cyblock -= j;
D 3
		}
		else
E 3
I 3
		} else
E 3
			cyblock += j;
D 4
		tpb.rec_over = TM_SHORT(j);
E 4
I 4
		tpb.tprec = htoms(j);
E 4
I 3
		timeout = 60*5;
E 3
		break;
I 3
D 4
	case SRFM_FD:
		tpb.rec_over = TM_SHORT(1);
E 4
I 4
	case CY_FSF:
		tpb.tprec = htoms(1);
E 4
		/* fall thru... */
E 3
D 4
	case REWD_TA:
E 4
I 4
	case CY_REW:
E 4
		cyblock = 0;
I 3
		timeout = 60*5;
E 3
		break;
	}
I 3
D 4
	ccb.gate[0] = GATE_CLOSED;
E 3
	TM_ATTENTION(ctlradr, 0xff);	/* execute! */
E 4
I 4
	ccb.cbgate = GATE_CLOSED;
	CY_GO(ctlradr);			/* execute! */
E 4
D 3
	if (func == REWD_TA || func == SPACE) {
		cywait(60*5*1000);
	}
	else cywait(10*1000);
E 3
I 3
	if (timeout == 0)
		timeout = 10;
	cywait(timeout*1000);
E 3
	/*
	 * First we clear the interrupt and close the gate.
	 */
	mtpr(PADC, 0);
D 4
	ccb.gate[0] = GATE_CLOSED;
D 3
	set_pointer((int)&cycool,(char *)ccb.pt_tpb);
E 3
I 3
	set_pointer((int)&cycool, (char *)ccb.pt_tpb);
E 3
	cycool.cmd = NO_OP;	/* no operation */
	cycool.control[0] = CW_BL;	/* No INTERRUPTS */
	cycool.control[1] = 0;
D 3
	TM_ATTENTION(ctlradr,0xff);	/* cool it ! */
E 3
I 3
	TM_ATTENTION(ctlradr, 0xff);	/* cool it ! */
E 4
I 4
	ccb.cbgate = GATE_CLOSED;
	cyldmba(ccb.cbtpb, (caddr_t)&cycool);
	cycool.tpcontrol = CYCW_LOCK;	/* No INTERRUPTS */
	CY_GO(ctlradr);
E 4
E 3
	cywait(20000); 
D 3
	uncache (&tpb.status[1] ) ; 
	if (tpb.status[1] & CS_ERm) {
		cy_decode_error(tpb.status[1]&CS_ERm);
		return -1;
E 3
I 3
D 4
	uncache(&tpb.status[1]); 
	if (tpb.status[1] & CS_ERm && cy_decode_error(tpb.status[1]&CS_ERm)) {
E 4
I 4
	uncache(&tpb.tpstatus); 
D 5
	if (err = (tpb.tpstatus & CYS_ERR) &&
E 5
I 5
	if ((err = (tpb.tpstatus & CYS_ERR)) &&
E 5
	    err != CYER_FM && (err != CYER_STROBE || tpb.tpcmd != CY_RCOM)) {
D 5
		cy_print_error(tpb.tpstatus);
E 5
I 5
		cy_print_error(tpb.tpcmd, tpb.tpstatus);
E 5
E 4
		io->i_error = EIO;
		return (-1);
E 3
	}
D 3
	uncache (&tpb.count);
	return((long)TM_SHORT(tpb.count));
E 3
I 3
D 4
	uncache(&tpb.count);
	return ((int)TM_SHORT(tpb.count));
E 4
I 4
	uncache(&tpb.tpcount);
	return ((int)htoms(tpb.tpcount));
E 4
E 3
}
D 7
	
E 7
I 7

E 7
D 3


E 3
D 4
cyprint_error(message)
D 3
register char	*message;
E 3
I 3
	char *message;
E 4
I 4
D 5
cy_print_error(status)
	int status;
E 5
I 5
cy_print_error(op, status)
	int op, status;
E 5
E 4
E 3
{
I 4
	register char *message;
E 4
I 3

E 3
D 4
	printf("cy0: %s.\n", message);
E 4
I 4
	if ((status & CYS_ERR) < NCYERROR)
		message = cyerror[status & CYS_ERR];
	else
		message = "unknown error";
D 5
	printf("cy0: %s, status=%b.\n", message, status, CYS_BITS);
E 5
I 5
	printf("cy0: cmd %x %s, status=%b.\n", op, message, status, CYS_BITS);
E 5
E 4
}
D 3

/*
*/
E 3

D 4
cy_decode_error(status)
D 3
register int	status;
E 3
I 3
	int status;
E 3
{
	switch(status) {
	case ER_TO1:
	case ER_TO2:
	case ER_TO3:
	case ER_TO4:
	case ER_TO5:
		cyprint_error("Drive timed out during transfer");
		break;
	case ER_TO6:	
		cyprint_error("Non-existant system memory reference");
		break;
	case ER_DIAG:
	case ER_JUMP:
		cyprint_error("Controller micro diagnostics failed");
		break;
	case ER_HARD:
D 3
		cyprint_error("Unrecoverble media error");
E 3
I 3
		cyprint_error("Unrecoverable media error");
E 3
		break;
	case ER_TOF:
		if (tpb.cmd == WRIT_TA)
			cyprint_error("Unsatisfactory media");
I 3
		else
			return (0);	/* short read */
E 3
		break;
	case ER_FIFO:
		cyprint_error("Data transfer over run");
		break;
	case ER_TRN:
		cyprint_error("Drive is not ready");
		break;
	case ER_PRO:
		cyprint_error("Tape is write protected");
		break;
	case ER_PSUM:
		cyprint_error("Checksum error in controller proms");
		break;
	case ER_PARI:
		cyprint_error("Unrecoverable tape parity error");
		break;
	case ER_BLAN:
		cyprint_error("Blank tape found where data was expected");
		break;
	case ER_ER:
D 3
		cyprint_error("Unrecoverble hardware error");
E 3
I 3
		cyprint_error("Unrecoverable hardware error");
		break;
	case ER_FMAR:		/* file mark */
		return (0);
E 3
	default:
I 3
		printf("cy: unknown error: status %x.\n", status);
E 3
		break;
	}
I 3
	return (-1);
E 3
}

E 4
D 3

long 
E 3
cywait(timeout)
D 3
	long timeout;
E 3
I 3
	register timeout;
E 3
{
D 3
	long dummy;
E 3
D 7

E 7
D 3
	uncache (&ccb.gate[0]) ;
	while (ccb.gate[0] != GATE_OPEN) {
		uncache (&ccb.gate[0]) ;
E 3
I 3
	do {
E 3
		DELAY(1000);
D 3
		if (--timeout == 0) {
			cyprint_error("Transfer timeout");
			_stop("");
		}
	}
E 3
I 3
D 4
		uncache(&ccb.gate[0]);
	} while (ccb.gate[0] != GATE_OPEN && --timeout > 0);
E 4
I 4
		uncache(&ccb.cbgate);
	} while (ccb.cbgate != GATE_OPEN && --timeout > 0);
E 4
	if (timeout <= 0)
		_stop("cy: Transfer timeout");
E 3
}

/*
D 4
 *  Set a TAPEMASTER pointer (first parameter), into the
 *  4 bytes array pointed by the second parameter.
E 4
I 4
 * Load a 20 bit pointer into a Tapemaster pointer.
E 4
 */
D 4
set_pointer(pointer,dest)
D 3
long pointer;
char * dest;
E 3
I 3
	long pointer;
	char * dest;
E 4
I 4
cyldmba(reg, value)
	register caddr_t reg;
	caddr_t value;
E 4
E 3
{
I 4
	register int v = (int)value;
E 4
I 3

E 3
D 4
	*dest++ = pointer & 0xff;		/* low byte - offset */
	*dest++ = (pointer >> 8) & 0xff;	/* high byte - offset */
	*dest++ = 0; 
	*dest   = (pointer & 0xf0000) >> 12;	/* base */
E 4
I 4
	*reg++ = v;
	*reg++ = v >> 8;
	*reg++ = 0;
	*reg = (v&0xf0000) >> 12;
E 4
}
E 1
