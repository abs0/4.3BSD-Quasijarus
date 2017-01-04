h24598
s 00010/00005/00083
d D 5.3 88/06/27 16:37:44 bostic 11 10
c install approved copyright notice
e
s 00008/00002/00080
d D 5.2 88/04/21 09:07:17 bostic 10 9
c add Berkeley specific header
e
s 00008/00001/00074
d D 5.1 85/05/30 09:47:15 dist 9 8
c Add copyright
e
s 00003/00003/00072
d D 4.8 85/03/27 09:45:29 karels 8 7
c add EOR
e
s 00003/00002/00072
d D 4.7 85/03/24 15:26:21 sam 7 6
c botched number of options
e
s 00016/00010/00058
d D 4.6 85/03/24 15:03:14 sam 6 5
c add qualifiers for ttype negotiation; fill in other options
e
s 00005/00002/00063
d D 4.5 85/03/24 13:06:05 sam 5 4
c add terminal type telnet option
e
s 00001/00001/00064
d D 4.4 82/03/16 21:31:08 root 4 3
c back to comments for sccs id
e
s 00001/00002/00064
d D 4.3 82/03/16 21:25:28 root 3 2
c set up sccsid's
e
s 00023/00018/00043
d D 4.2 82/03/01 11:50:12 sam 2 1
c fix up definitions of options
e
s 00061/00000/00000
d D 4.1 82/02/28 10:34:14 root 1 0
c date and time created 82/02/28 10:34:14 by root
e
u
U
t
T
I 1
D 3
/*	%M%	%I%	%E%	*/

E 3
I 3
D 4
static char sccsid[] = "%W% (Berkeley) %G%";
E 4
I 4
D 9
/*	%M%	%I%	%E%	*/
E 9
I 9
/*
 * Copyright (c) 1983 Regents of the University of California.
D 10
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 10
I 10
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 11
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 11
I 11
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
E 11
E 10
 *
 *	%W% (Berkeley) %G%
 */

E 9
E 4
E 3
/*
 * Definitions for the TELNET protocol.
 */
#define	IAC	255		/* interpret as command: */
#define	DONT	254		/* you are not to use option */
#define	DO	253		/* please, you use option */
#define	WONT	252		/* I won't use option */
#define	WILL	251		/* I will use option */
#define	SB	250		/* interpret as subnegotiation */
#define	GA	249		/* you may reverse the line */
#define	EL	248		/* erase the current line */
#define	EC	247		/* erase the current character */
#define	AYT	246		/* are you there */
#define	AO	245		/* abort output--but let prog finish */
#define	IP	244		/* interrupt process--permanently */
#define	BREAK	243		/* break */
#define	DM	242		/* data mark--for connect. cleaning */
#define	NOP	241		/* nop */
#define	SE	240		/* end sub negotiation */
I 8
#define EOR     239             /* end of record (transparent mode) */
E 8

#define SYNCH	242		/* for telfunc calls */

D 6
/* telnet options */
E 6
I 6
#ifdef TELCMDS
char *telcmds[] = {
	"SE", "NOP", "DMARK", "BRK", "IP", "AO", "AYT", "EC",
	"EL", "GA", "SB", "WILL", "WONT", "DO", "DONT", "IAC",
};
#endif
E 6

I 6
/* telnet options */
E 6
#define TELOPT_BINARY	0	/* 8-bit data path */
#define TELOPT_ECHO	1	/* echo */
D 2
#define	TELOPT_RCP	2
#define	TELOPT_SGA	3
#define	TELOPT_NAME	4
#define	TELOPT_STATUS	5
#define	TELOPT_TM	6
#define	TELOPT_RCTE	7
#define TELOPT_NAOL 	8
#define TELOPT_NAOP 	9
#define TELOPT_NAOCRD	10
#define TELOPT_NAOHTS	11
#define TELOPT_NAOHTD	12
#define TELOPT_NAOFFD	13
#define TELOPT_NAOVTS	14
#define TELOPT_NAOVTD	15
#define TELOPT_NAOLFD	16
#define TELOPT_XASCII	17
#define TELOPT_EXOPL	255
E 2
I 2
#define	TELOPT_RCP	2	/* prepare to reconnect */
#define	TELOPT_SGA	3	/* suppress go ahead */
#define	TELOPT_NAMS	4	/* approximate message size */
#define	TELOPT_STATUS	5	/* give status */
#define	TELOPT_TM	6	/* timing mark */
#define	TELOPT_RCTE	7	/* remote controlled transmission and echo */
#define TELOPT_NAOL 	8	/* negotiate about output line width */
#define TELOPT_NAOP 	9	/* negotiate about output page size */
#define TELOPT_NAOCRD	10	/* negotiate about CR disposition */
#define TELOPT_NAOHTS	11	/* negotiate about horizontal tabstops */
#define TELOPT_NAOHTD	12	/* negotiate about horizontal tab disposition */
#define TELOPT_NAOFFD	13	/* negotiate about formfeed disposition */
#define TELOPT_NAOVTS	14	/* negotiate about vertical tab stops */
#define TELOPT_NAOVTD	15	/* negotiate about vertical tab disposition */
#define TELOPT_NAOLFD	16	/* negotiate about output LF disposition */
#define TELOPT_XASCII	17	/* extended ascic character set */
#define	TELOPT_LOGOUT	18	/* force logout */
#define	TELOPT_BM	19	/* byte macro */
#define	TELOPT_DET	20	/* data entry terminal */
#define	TELOPT_SUPDUP	21	/* supdup protocol */
I 5
D 6
/* 22-23 are assigned */
E 6
I 6
#define	TELOPT_SUPDUPOUTPUT 22	/* supdup output */
#define	TELOPT_SNDLOC	23	/* send location */
E 6
#define	TELOPT_TTYPE	24	/* terminal type */
I 6
#define	TELOPT_EOR	25	/* end or record */
E 6
E 5
#define TELOPT_EXOPL	255	/* extended-options-list */
E 2

D 6
#ifdef TELCMDS
char *telcmds[] = {
	"SE", "NOP", "DMARK", "BRK", "IP", "AO", "AYT", "EC",
	"EL", "GA", "SB", "WILL", "WONT", "DO", "DONT", "IAC",
};
#endif

E 6
#ifdef TELOPTS
D 5
char *telopts[] = {
E 5
I 5
D 7
#define	NTELOPTS	25
E 7
I 7
#define	NTELOPTS	(1+TELOPT_EOR)
E 7
char *telopts[NTELOPTS] = {
E 5
	"BINARY", "ECHO", "RCP", "SUPPRESS GO AHEAD", "NAME",
	"STATUS", "TIMING MARK", "RCTE", "NAOL", "NAOP",
	"NAOCRD", "NAOHTS", "NAOHTD", "NAOFFD", "NAOVTS",
D 2
	"NAOVTD", "NAOLFD", "EXTEND ASCII",
E 2
I 2
	"NAOVTD", "NAOLFD", "EXTEND ASCII", "LOGOUT", "BYTE MACRO",
D 5
	"DATA ENTRY TERMINAL", "SUPDUP"
E 5
I 5
D 6
	"DATA ENTRY TERMINAL", "SUPDUP", "#22", "#23", "TTYPE",
E 6
I 6
D 8
	"DATA ENTRY TERMINAL", "SUPDUP", "SUPDUP OUTPUT", "SEND LOCATION",
D 7
	"TERMINAL TYPE", "END OF RECORD",
E 7
I 7
	    "TERMINAL TYPE",
	"END OF RECORD",
E 8
I 8
	"DATA ENTRY TERMINAL", "SUPDUP", "SUPDUP OUTPUT",
	"SEND LOCATION", "TERMINAL TYPE", "END OF RECORD",
E 8
E 7
E 6
E 5
E 2
};
#endif
I 6

/* sub-option qualifiers */
#define	TELQUAL_IS	0	/* option is... */
#define	TELQUAL_SEND	1	/* send option */
E 6
E 1
