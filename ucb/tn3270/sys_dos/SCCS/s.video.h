h16626
s 00014/00002/00040
d D 3.2 88/03/28 12:23:56 bostic 5 4
c add Berkeley specific header
e
s 00000/00000/00042
d D 3.1 87/08/11 10:20:25 minshall 4 3
c New version numbering.
e
s 00002/00000/00040
d D 1.3 87/07/17 10:05:05 minshall 3 2
c Install sccs headers and copyright notices.
e
s 00002/00002/00038
d D 1.2 87/05/13 11:35:05 minshall 2 1
c Fixes (oops).
e
s 00040/00000/00000
d D 1.1 87/05/13 11:32:57 minshall 1 0
c date and time created 87/05/13 11:32:57 by minshall
e
u
U
t
T
I 1
/*
I 5
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
E 5
 * This is a header file describing the interface via int 10H to the
 * video subsystem.
I 3
D 5
 *
 * %W% (Berkeley) %G%
E 5
E 3
 */

#define	BIOS_VIDEO	0x10

typedef enum {
    SetMode = 0,
    SetCursorType,
    SetCursorPosition,
    ReadCursorPosition,
    ReadLightPenPosition,
    SelectActiveDisplayPage,
    ScrollActivePageUp,
    ScrollActivePageDown,
    ReadAttribute_Character,
D 2
    ReadAttribute_Character,
    ReadCharacterOnly,
E 2
I 2
    WriteAttribute_Character,
    WriteCharacterOnly,
E 2
    SetColorPalette,
    WriteDot,
    ReadDot,
    WriteTeletypeToActivePage,
    CurrentVideoState,
    Reserved16,
    Reserved17,
    Reserved18,
    WriteString
} VideoOperationsType;

typedef enum {
    bw_40x25 = 0,
    color_40x25,
    bw_80x25,
    color_80x25,
    color_320x200,
    bw_320x200,
    bw_640x200,
    internal_bw_80x25
} VideoModeType;
E 1
