h02152
s 00014/00002/00155
d D 3.2 88/03/28 12:34:25 bostic 8 7
c add Berkeley specific header
e
s 00000/00000/00157
d D 3.1 87/08/11 10:18:56 minshall 7 6
c New version numbering.
e
s 00002/00000/00155
d D 1.6 87/07/17 10:03:31 minshall 6 5
c Install sccs headers and copyright notices.
e
s 00001/00000/00154
d D 1.5 87/06/16 17:19:19 minshall 5 4
c Add SetPsModified().
e
s 00006/00003/00148
d D 1.4 87/05/25 16:31:27 minshall 4 3
c Set 'myjob' when setting online A.  Fix bug in IsOiaTWait.
c Add *OiaApiInhibited().
e
s 00143/00021/00008
d D 1.3 87/05/24 14:35:22 minshall 3 2
c New OIA.
e
s 00002/00000/00027
d D 1.2 87/05/22 11:55:08 minshall 2 1
c Move OIA into global storage.
e
s 00027/00000/00000
d D 1.1 87/05/11 13:12:02 minshall 1 0
c date and time created 87/05/11 13:12:02 by minshall
e
u
U
t
T
I 1
/*
I 8
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
 *
 *	%W% (Berkeley) %G%
 */

/*
E 8
 * This file describes the Operator Information Area in the 3270.
I 3
 *
 * Our OIA looks like that used by the 3270 PC and PC 3270 products.
I 6
D 8
 *
 * %W% (Berkeley) %G%
E 8
E 6
E 3
 */

I 2
#define	INCLUDED_OIA

E 2
D 3
#define	OIA_READY_3274	0xF4
#define	OIA_ONLINE_A	0xCC
#define	OIA_OWNERSHIP_MYJOB	0xCF
#define	OIA_OWNERSHIP_SYSTEM_OPERATOR	0xF0
#define	OIA_OWNERSHIP_UNOWNED		0xF1
#define	OIA_INSERT_ON	0x3a

E 3
typedef struct {
D 3
    unsigned char
	ready,			/* 01-01 Is 3274 ready? */
	online,			/* 02-02 Online in which mode (a, b) */
	ownership,		/* 03-03 Who owns us (job, operator, unowned) */
	test2_4[3],		/* 04-06 Rest of TEST string */
	reserved[2],		/* 07-08 */
	x,			/* 09-09 X - input inhibited */
	xnull,			/* 10-10 Space */
	xwhy[7],		/* 11-17 Why are we inhibited? */
	reserved2[14],		/* 18-31 */
	num[3],			/* 32-34 Numeric lock */
	upshift,		/* 35-35 Shift state */
	insert,			/* 36-36 Insert mode */
	apl[3];			/* 37-39 APL mode */
E 3
I 3
    char
	online_ownership,
	character_selection,
	shift_state,
	pss_group_1,
	highlight_group_1,
	color_group_1,
	insert,
	input_inhibited[5],
	pss_group_2,
	highlight_group_2,
	color_group_2,
	comm_error_reminder,
	printer_status,
	reserved_group_14,
	reserved_group_15,
	autokey_play_record_status,
	autokey_abort_pause_status,
	enlarge_state;
E 3
} OIA;
I 3

/* Bits in online_ownership */
#define	OIA_SETUP		0x80
#define	OIA_TEST		0x40
#define	OIA_SSCP_LU		0x20
#define	OIA_LU_LU		0x10
#define	OIA_UNOWNED		0x08
#define	OIA_SUBSYSTEM_READY	0x04

/* Bit in character_selection */
#define	OIA_EXTENDED_SELECT	0x80
#define	OIA_APL			0x40
#define	OIA_KANA		0x20
#define	OIA_ALPHA		0x10
#define	OIA_TEXT		0x08

/* Bits in shift_state */
#define	OIA_NUMERIC		0x80
#define	OIA_UPPER_SHIFT		0x40

/* Bits in pss_group_1, highlight_group_1, and color_group_1 */
#define	OIA_SELECTABLE		0x80
#define	OIA_FIELD_INHERIT	0x40

/* Bits in insert */
#define	OIA_INSERT_MODE		0x80

/* We define this to be a 'long' followed by a 'char' (5 bytes) */

#define	OIA_NON_RESETTABLE	0x80
#define	OIA_SECURITY_KEY	0x40
#define	OIA_MACHINE_CHECK	0x20
#define	OIA_COMM_CHECK		0x10
#define	OIA_PROGRAM_CHECK	0x08
#define	OIA_RETRY		0x04
#define	OIA_DEVICE_NOT_WORKING	0x02
#define	OIA_DEVICE_VERY_BUSY	0x01

#define	OIA_DEVICE_BUSY		  0x80
#define	OIA_TERMINAL_WAIT	  0x40
#define	OIA_MINUS_SYMBOL	  0x20
#define	OIA_MINUS_FUNCTION	  0x10
#define	OIA_TOO_MUCH_ENTERED	  0x08
#define	OIA_NOT_ENOUGH_ENTERED	  0x04
#define	OIA_WRONG_NUMBER	  0x02
#define	OIA_NUMERIC_FIELD	  0x01

#define	OIA_OP_UNAUTHORIZED	    0x80
#define	OIA_OP_UNAUTHORIZED_MIN	    0x40
#define	OIA_INVALID_DEAD_KEY_COMBO  0x20
#define	OIA_WRONG_PLACE		    0x10

#define	OIA_MESSAGE_PENDING	      0x80
#define	OIA_PARTITION_WAIT	      0x40
#define	OIA_SYSTEM_WAIT		      0x20
#define	OIA_HARDWARE_MISMATCH	      0x10
#define	OIA_LOGICAL_TERM_NOT_CONF     0x08


#define	OIA_AUTOKEY_INHIBIT	        0x80
#define	OIA_API_INHIBIT		        0x40

/* Bits in pss_group_2 */
#define	OIA_PS_SELECTED		0x80
#define	OIA_PC_DISPLAY_DISABLE	0x40

/* Bits in highlight_group_2 and color_group_2 */
#define	OIA_SELECTED		0x80

/* Bits in comm_error_reminder */
#define	OIA_COMM_ERROR		0x80
#define	OIA_RTM			0x40

/* Bits in printer_status */
#define	OIA_PRINT_NOT_CUSTOM	0x80
#define	OIA_PRINTER_MALFUNCTION	0x40
#define	OIA_PRINTER_PRINTING	0x20
#define	OIA_ASSIGN_PRINTER	0x10
#define	OIA_WHAT_PRINTER	0x08
#define	OIA_PRINTER_ASSIGNMENT	0x04

/* Bits in autokey_play_record_status */
#define	OIA_PLAY		0x80
#define	OIA_RECORD		0x40

/* Bits in autokey_abort_pause_status */
#define	OIA_RECORDING_OVERFLOW	0x80
#define	OIA_PAUSE		0x40

/* Bits in enlarge_state */
#define	OIA_WINDOW_IS_ENLARGED	0x80

/* Define functions to set and read the oia */

D 4
#define	SetOiaOnlineA(oia) \
	/* Nothing defined for this */
E 4
I 4
#define	SetOiaOnlineA(oia) SetOiaMyJob((oia))		/* Side-effect */
E 4
#define	ResetOiaOnlineA(oia) \
	/* Nothing defined for this */

#define	IsOiaReady3274(oia)	((oia)->online_ownership&OIA_SUBSYSTEM_READY)
#define	ResetOiaReady3274(oia)	(oia)->online_ownership &= ~OIA_SUBSYSTEM_READY
#define	SetOiaReady3274(oia)	(oia)->online_ownership |= OIA_SUBSYSTEM_READY

#define	IsOiaMyJob(oia)		((oia)->online_ownership&OIA_LU_LU)
#define	ResetOiaMyJob(oia)	(oia)->online_ownership &= ~OIA_LU_LU
#define	SetOiaMyJob(oia)	(oia)->online_ownership |= OIA_LU_LU

#define	IsOiaInsert(oia)	((oia)->online_ownership&OIA_INSERT_MODE)
#define	ResetOiaInsert(oia)	(oia)->online_ownership &= ~OIA_INSERT_MODE
#define	SetOiaInsert(oia)	(oia)->online_ownership |= OIA_INSERT_MODE

#define	IsOiaSystemLocked(oia)	((oia)->input_inhibited[3]&OIA_SYSTEM_WAIT)
#define	ResetOiaSystemLocked(oia) \
				(oia)->input_inhibited[3] &= ~OIA_SYSTEM_WAIT
#define	SetOiaSystemLocked(oia)	(oia)->input_inhibited[3] |= OIA_SYSTEM_WAIT

D 4
#define	IsOiaTWait(oia)		((oia)->input_inhibited[1]&OIA_TERMINAL_WAIT))
E 4
I 4
#define	IsOiaTWait(oia)		((oia)->input_inhibited[1]&OIA_TERMINAL_WAIT)
E 4
#define	ResetOiaTWait(oia)	(oia)->input_inhibited[1] &= ~OIA_TERMINAL_WAIT
#define	SetOiaTWait(oia)	(oia)->input_inhibited[1] |= OIA_TERMINAL_WAIT
I 4

#define	IsOiaApiInhibit(oia)	((oia)->input_inhibited[4] &   OIA_API_INHIBIT)
#define	ResetOiaApiInhibit(oia)	((oia)->input_inhibited[4] &= ~OIA_API_INHIBIT)
#define	SetOiaApiInhibit(oia)	((oia)->input_inhibited[4] |=  OIA_API_INHIBIT)
E 4

/* A macro to let the world know that someone has modified the OIA. */
#define	SetOiaModified()	oia_modified = 1
I 5
#define	SetPsModified()		ps_modified = 1
E 5
E 3
E 1
