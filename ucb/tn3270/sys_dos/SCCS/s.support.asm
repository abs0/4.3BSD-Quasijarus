h10107
s 00013/00000/00026
d D 3.2 88/03/28 12:23:50 bostic 5 4
c add Berkeley specific header
e
s 00000/00000/00026
d D 3.1 87/08/11 10:20:27 minshall 4 3
c New version numbering.
e
s 00004/00022/00022
d D 1.3 87/07/15 14:14:43 minshall 3 2
c New function.
e
s 00003/00003/00041
d D 1.2 87/05/20 12:24:49 minshall 2 1
c Null change.
e
s 00044/00000/00000
d D 1.1 87/05/18 15:09:52 minshall 1 0
c date and time created 87/05/18 15:09:52 by minshall
e
u
U
t
T
I 5
;
; Copyright (c) 1988 Regents of the University of California.
; All rights reserved.
;
; Redistribution and use in source and binary forms are permitted
; provided that this notice is preserved and that due credit is given
; to the University of California at Berkeley. The name of the University
; may not be used to endorse or promote products derived from this
; software without specific prior written permission. This software
; is provided ``as is'' without express or implied warranty.
;
;	%W% (Berkeley) %G%

E 5
I 1
D 3
; $Header: /lapis_d/minshall/src/misc/minshall/src/netsys/RCS/support.asm,v 1.5 87/01/14 11:29:19 minshall Exp $


E 3
_TEXT	segment	byte public 'CODE'
_TEXT	ends

_DATA	segment	word public 'DATA'
_DATA	ends

CONST	segment	word public 'CONST'
CONST	ends

_BSS	segment word public 'BSS'
_BSS	ends

DGROUP	group	CONST, _BSS, _DATA

	assume	cs:_TEXT, ds:DGROUP, ss:DGROUP, es:DGROUP

_TEXT	segment
I 3
	public	_iret_subr
E 3

D 2
	public	dirconio
E 2
I 2
D 3
	public	_dirconio
E 2

D 2
dirconio	proc	near
E 2
I 2
_dirconio	proc	near
E 2
	push	bp
	mov	bp,sp

	mov	ah,01H		; test input
	int	16H
	mov	ax,0ffffH	; nothing read
	jz	dirconiodone
	mov	ah,00H		; consume the input
	int	16H

dirconiodone:

	mov	sp,bp
	pop	bp
	ret
D 2
dirconio	endp
E 2
I 2
_dirconio	endp
E 3
I 3
_iret_subr	proc	far
	iret
_iret_subr	endp
E 3
E 2

_TEXT	ends

	end
E 1
