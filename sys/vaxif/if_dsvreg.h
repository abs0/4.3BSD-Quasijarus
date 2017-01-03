/*
 * Copyright (c) 1982, 1986 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 *	@(#)if_dsvreg.h	7.1 (Berkeley) 3/26/00
 */

/*
 * DEC DSV11 interface
 */
struct dsvdevice {
	u_short	reg_flag;
	u_short	reg_cmar;
	union {
		u_long	cmdr_l;
		u_short	cmdr_w[2];
	} u_cmdr;
#define	reg_cmdr	u_cmdr.cmdr_l
#define	reg_cmdrl	u_cmdr.cmdr_w[0]
#define	reg_cmdrh	u_cmdr.cmdr_w[1]
};

/* FLAG register bit descriptions */
#define	FLAG_SKSELFTST	0x8000		/* Skip self-test */
#define	FLAG_RSPAVAIL	0x4000		/* Response available */
#define	FLAG_CMDAVAIL	0x2000		/* Command available */
#define	FLAG_CMDLISTVAL	0x1000		/* Command list valid */
#define	FLAG_RUN	0x0400		/* Running */
#define	FLAG_RSET	0x0200		/* DSV11 reset */
#define	FLAG_INTE	0x0100		/* Interrupt enable */
#define	FLAG_DEVTYPE	0x00FF		/* DSV11 device type mask */
#define	FLAG_DEVTYPE_SHIFT	0

#define	FLAG_BITS	"\20\17RSPAVAIL\16CMDAVAIL\15CMDLISTVAL\13RUN\12RSET\11INTE"

/*
 * Structures in DSV11 command memory (command blocks)
 */
#define	CMDBLK_SIZE	32
#define	CMDBLK_SHIFT	5
#define	NCMDBLKS	64

/* The initialization block */
#define	INITBLK_OFF_LSTHEADS	0x00
#define	INITBLK_OFF_VECTOR	0x04

/* Command blocks */
#define	CMDBLK_OFF_LINKS	0x00
#define	CMDBLK_OFF_FUNC		0x04
#define	CMDBLK_OFF_BUFLEN	0x08
#define	CMDBLK_OFF_BUFADDR	0x0C
#define	CMDBLK_OFF_P1		0x10
#define	CMDBLK_OFF_P2		0x14

/*
 * Internal structure for the command block
 */
struct dsv_cmdblk {
	union {
		u_long	func_l;
		u_char	func_b[4];
	} u_func;
#define	cmd_func	u_func.func_l
#define	cmd_cmd		u_func.func_b[0]
#define	cmd_chan	u_func.func_b[1]
#define	cmd_cmdsts	u_func.func_b[2]
#define	cmd_complsts	u_func.func_b[3]
	union {
		u_long	buflen_l;
		u_short	buflen_w[2];
	} u_buflen;
#define	cmd_buflen	u_buflen.buflen_l
#define	cmd_bufused	u_buflen.buflen_w[0]
#define	cmd_bufsize	u_buflen.buflen_w[1]
	u_long	cmd_bufaddr;
	union {
		u_long	p_l;
		u_short	p_w[2];
		u_char	p_b[4];
	} u_p1, u_p2;
#define	cmd_p1		u_p1.p_l
#define	cmd_p1l		u_p1.p_w[0]
#define	cmd_p1h		u_p1.p_w[1]
#define	cmd_p1b0	u_p1.p_b[0]
#define	cmd_p1b1	u_p1.p_b[1]
#define	cmd_p1b2	u_p1.p_b[2]
#define	cmd_p1b3	u_p1.p_b[3]
#define	cmd_p2		u_p2.p_l
#define	cmd_p2l		u_p2.p_w[0]
#define	cmd_p2h		u_p2.p_w[1]
#define	cmd_p2b0	u_p2.p_b[0]
#define	cmd_p2b1	u_p2.p_b[1]
#define	cmd_p2b2	u_p2.p_b[2]
#define	cmd_p2b3	u_p2.p_b[3]
};

/* Command codes */
#define	CMD_DEVPARAM		0x00	/* Return Device Parameters */
#define	CMD_CHANPARAM		0x01	/* Return Channel Parameters */
#define	CMD_INITCHAN		0x10	/* Initialize Channel */
#define	CMD_CHGCHANPARAM	0x11	/* Change Channel Parameters */
#define	CMD_RSETCHAN		0x13	/* Reset Channel */
#define	CMD_XMIT		0x20	/* Transmit Data */
#define	CMD_RECV		0x30	/* Receive Data */
#define	CMD_UPDRPTMODEMSTS	0x40	/* Update and Report Modem Status */
#define	CMD_RPTSTSCHG		0x50	/* Report Status Change */
#define	CMD_MAINTMODE		0x7F	/* Maintenance Mode */

/* Command status */
#define	CMDSTS_ENDCMDLIST	0x20	/* End of Command List Detected */

/* Completion status */
#define	COMPLSTS_NORMAL		0x00	/* Normal completion */
#define	COMPLSTS_ABORTED	0x01	/* Command aborted on request */
#define	COMPLSTS_BADCMD		0x03	/* Unrecognized command */
#define	COMPLSTS_BADCHAN	0x04	/* Invalid channel */
#define	COMPLSTS_BADP1		0x05	/* Invalid P1 */
#define	COMPLSTS_BADP2		0x06	/* Invalid P2 */
#define	COMPLSTS_BADP3		0x07	/* Invalid P3 */
#define	COMPLSTS_BADP4		0x08	/* Invalid P4 */
#define	COMPLSTS_CMDOUTOFSEQ	0x09	/* Command out of sequence */
#define	COMPLSTS_BUFPAR		0x0A	/* Buffer error: parity error */
#define	COMPLSTS_BUFNXM		0x0B	/* Buffer error: NXM */
#define	COMPLSTS_CRCERR		0x0C	/* CRC error on receive */
#define	COMPLSTS_HDRCRCERR	0x0D	/* CRC error in header on receive */
#define	COMPLSTS_RECVBUFOVFLO	0x0E	/* Receive buffer overflow */
#define	COMPLSTS_MODEMSTSCHG	0x0F	/* Modem status change during xmit */
#define	COMPLSTS_MODEMTIMEOUT	0x10	/* Modem timeout */
#define	COMPLSTS_MSGCONTERR	0x11	/* Message contents error */
#define	COMPLSTS_RECVOVERRUN	0x12	/* Receive overrun occurred */
#define	COMPLSTS_RECVABORT	0x13	/* HDLC receive abort detected */

/*
 * P1 and P2 bit definitions for individual commands
 * Fields that take up a whole byte or the whole upper or lower half are
 * #defined here only for clarity, we actually access them through our struct.
 */

/* Return Channel Parameters command */
#define	CHANPARAM_P1_CABLE	0x0000000F	/* cable code */
#define	CHANPARAM_P1_CABLE_SHIFT	0
#define	CHANPARAM_P1_MAINTSW	0x00000030	/* maintenance switches */

/* Channel parameters for Initialize and Change */
#define	CHANPAR1_PROTO	0x0000000F	/* Channel Protocol */
#define	CHANPAR1_PROTO_SHIFT	0
#define	CHANPAR1_ERRCHK	0x000000F0	/* Error Check Type */
#define	CHANPAR1_ERRCHK_SHIFT	4
#define	CHANPAR1_RECVBPC	0x00000700	/* Receive Bits per Char */
#define	CHANPAR1_RECVBPC_SHIFT	8
#define	CHANPAR1_XMITBPC	0x00003800	/* Transmit Bits per Char */
#define	CHANPAR1_XMITBPC_SHIFT	11
#define	CHANPAR1_IDLESYNCFLAG	0x00004000	/* Idle with Sync/Flag */
#define	CHANPAR1_1STADDRCHAR	0x00FF0000	/* 1st Address Char */
#define	CHANPAR1_2NDADDRCHAR	0xFF000000	/* 2nd Address Char */

#define	CHANPAR2_RECVENAB	0x00000001	/* Receiver Enable */
#define	CHANPAR2_INTLOOP	0x00000002	/* Internal Loopback */
#define	CHANPAR2_PRIMSTAT	0x00000004	/* Primary Station */
#define	CHANPAR2_INTCLKENAB	0x00000008	/* Internal Clock Enable */
#define	CHANPAR2_INTCLKRATE	0x00000070	/* Internal Clock Rate */
#define	CHANPAR2_INTCLKRATE_SHIFT	4
#define	CHANPAR2_NUMSYNCS	0x00FF0000	/* Number of Syncs */
#define	CHANPAR2_DRIVER		0x0F000000	/* Cable Driver Select */
#define	CHANPAR2_DRIVER_SHIFT	24
#define	CHANPAR2_NRZI		0x10000000	/* NRZI */
#define	CHANPAR2_USEINTCLK	0x20000000	/* Clock TX from internal */

/* Reset Channel command */
#define	RSETCHAN_SHUTDOWN	0x00000000	/* Shut down channel */
#define	RSETCHAN_ABTXMITRECV	0x00000001	/* Abort all xmits and recvs */
#define	RSETCHAN_ABTXMIT	0x00000002	/* Abort all xmits */

/* Modem status bytes, appear in P1 for many commands */
#define	MODEMCTL_RL	0x01	/* CCITT 140 (Remote Loopback) */
#define	MODEMCTL_DTR	0x02	/* CCITT 108/2 (Data Terminal Ready) */
#define	MODEMCTL_DSRS	0x04	/* CCITT 111 (Data Signaling Rate Selector) */
#define	MODEMCTL_LL	0x08	/* CCITT 141 (Local Loopback) */
#define	MODEMCTL_RTS	0x10	/* CCITT 105 (Request To Send) */
#define	MODEMCTL_VALID	0x80

#define	MODEMSTS_VALID		0x01
#define	MODEMSTS_RTSLOOP	0x02	/* RTS looped back by H3199 */
#define	MODEMSTS_TI		0x04	/* CCITT 142 (Test Indicator) */
#define	MODEMSTS_DTRLOOP	0x08	/* DTR looped back by H3199 */
#define	MODEMSTS_CTS		0x10	/* CCITT 106 (Clear To Send) */
#define	MODEMSTS_CD		0x20	/* CCITT 109 (Carrier Detect) */
#define	MODEMSTS_RI		0x40	/* CCITT 125 (Ring Indicator) */
#define	MODEMSTS_DSR		0x80	/* CCITT 107 (Data Set Ready) */

#define	MODEMSTS_BITS	"\20\10DSR\7RI\6CD\5CTS\4DTRLOOP\3TI\2RTSLOOP"

/*
 * Codes and magic numbers
 */

/* Device type codes */
#define	DEVTYPE_DSV11	0x02

/* Attached cable codes */
#define	CABLE_NONE	0x0
#define	CABLE_V35	0x1		/* V.35 */
#define	CABLE_UNBAL	0x2		/* unbalanced pair */
#define	CABLE_BAL	0x4		/* balanced pair */
#define	CABLE_LOOPBACK	0xF		/* H3199 loopback connector */

/* Cable driver selections */
#define	DRIVER_AUTO	0x0		/* auto select based on cable */
#define	DRIVER_V35	CABLE_V35
#define	DRIVER_UNBAL	CABLE_UNBAL
#define	DRIVER_BAL	CABLE_BAL

/* Channel protocols */
#define	PROTO_DDCMP	0
#define	PROTO_BASICHDLC	1		/* Basic HDLC (always 1-byte addr) */
#define	PROTO_EXTHDLC	2		/* Extended HDLC (addr extension) */
#define	PROTO_BISYNC	4

/* Error check types */
#define	ERRCHK_CRCCCITT1	0	/* CRC-CCITT preset to all 1s */
#define	ERRCHK_CRCCCITT0	1	/* CRC-CCITT preset to all 0s */
#define	ERRCHK_LRCVRCODD	2	/* LRC/VRC odd */
#define	ERRCHK_CRC16		3	/* CRC-16 */
#define	ERRCHK_VRCODD		4	/* VRC odd */
#define	ERRCHK_VRCEVEN		5	/* VRC even */
#define	ERRCHK_LRCVRCEVEN	6	/* LRC/VRC even */
#define	ERRCHK_NONE		7

/* Bits per character */
#define	BITSPERCHAR_8	0		/* 8 bits per char */
#define	BITSPERCHAR_5	5		/* 5 bits per char */
#define	BITSPERCHAR_6	6		/* 6 bits per char */
#define	BITSPERCHAR_7	7		/* 7 bits per char */

/* Internal clock rates */
#define	CLKRATE_AUTO	0	/* auto select based on protocol and cable */
#define	CLKRATE_DISABLE	1
#define	CLKRATE_9766	2
#define	CLKRATE_19531	3
#define	CLKRATE_39062	4
#define	CLKRATE_78125	5
#define	CLKRATE_156250	6
#define	CLKRATE_312500	7

struct	dsv_buf {
	struct hdlc_header db_head;	/* header */
	char	db_data[ETHERMTU];	/* packet data */
};
