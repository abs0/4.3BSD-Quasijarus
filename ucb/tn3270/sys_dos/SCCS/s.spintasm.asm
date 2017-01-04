h46435
s 00012/00000/00220
d D 3.2 88/03/28 12:23:47 bostic 5 4
c add Berkeley specific header
e
s 00000/00000/00220
d D 3.1 87/08/11 10:20:27 minshall 4 3
c New version numbering.
e
s 00089/00070/00131
d D 1.3 87/05/20 12:24:12 minshall 3 2
c This version works.
e
s 00150/00015/00051
d D 1.2 87/05/19 16:13:14 minshall 2 1
c More and better.
e
s 00066/00000/00000
d D 1.1 87/05/19 14:08:02 minshall 1 0
c date and time created 87/05/19 14:08:02 by minshall
e
u
U
t
T
I 2
;
I 5
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
;
E 5
D 3
; The code in this file complete the spawn_int calls
E 3
I 3
; The code in this file complete the spint calls
E 3
;

D 3
spawn	struc
E 3
I 3
spint	struc
E 3
; union REGS
D 3
spawn_ax	dw	1
spawn_bx	dw	1
spawn_cx	dw	1
spawn_dx	dw	1
spawn_si	dw	1
spawn_di	dw	1
spawn_cflag	dw	1
E 3
I 3
spint_ax	dw	1
spint_bx	dw	1
spint_cx	dw	1
spint_dx	dw	1
spint_si	dw	1
spint_di	dw	1
spint_cflag	dw	1
E 3
; struct SREGS
D 3
spawn_es	dw	1
spawn_cs	dw	1
spawn_ss	dw	1
spawn_ds	dw	1
E 3
I 3
spint_es	dw	1
spint_cs	dw	1
spint_ss	dw	1
spint_ds	dw	1
E 3
; int intno
D 3
spawn_intno	dw	1
E 3
I 3
spint_intno	dw	1
E 3
; int done
D 3
spawn_done	dw	1
E 3
I 3
spint_done	dw	1
E 3
; int rc
D 3
spawn_rc	dw	1
E 3
I 3
spint_rc	dw	1
E 3
;
D 3
spawn	ends
E 3
I 3
spint	ends
E 3


ENTER	MACRO
	; Begin enter
	push	bp
	mov	bp,sp

	push	ax
	push	bx
	push	cx
	push	dx
	push	bp
	push	di
	push	si
	push	ds
	push	es
	pushf

D 3
	mov	cs:save_sp, sp
	mov	cs:save_ss, ss
E 3
I 3
	mov	cs:start_sp, sp
	mov	cs:start_ss, ss
E 3
	; End enter
	ENDM

LEAVE	MACRO
	; Begin leave
D 3
	mov	sp, cs:save_sp
	mov	ss, cs:save_ss
E 3
I 3
	cli
	mov	sp, cs:start_sp
	mov	ss, cs:start_ss
	sti
E 3

	popf
	pop	es
	pop	ds
	pop	si
	pop	di
	pop	bp
	pop	dx
	pop	cx
	pop	bx
	pop	ax

	mov	sp,bp
	pop	bp
	ret
	; End leave
	ENDM

GETREGS	MACRO	wherefrom
	mov	si, wherefrom
D 3
	mov	spawn_segment, ds
	mov	spawn_offset, si
E 3
I 3
	mov	spint_segment, ds
	mov	spint_offset, si
E 3

D 3
	mov	ax, spawn_ax[si]
	mov	bx, spawn_bx[si]
	mov	cx, spawn_cx[si]
	mov	dx, spawn_dx[si]
	; XXX mov	si, spawn_si[si]
	mov	di, spawn_di[si]
	mov	es, spawn_es[si]
E 3
I 3
	mov	ax, spint_ax[si]
	mov	bx, spint_bx[si]
	mov	cx, spint_cx[si]
	mov	dx, spint_dx[si]
	; XXX mov	si, spint_si[si]
	mov	di, spint_di[si]
	mov	es, spint_es[si]
E 3
	; Now, need to do DS, SI
D 3
	push	spawn_ds[si]
	mov	si, spawn_si[si]
E 3
I 3
	push	spint_ds[si]
	mov	si, spint_si[si]
E 3
	pop	ds
	ENDM


SETREGS	MACRO
	mov	cs:old_si, si
	mov	cs:old_ds, ds

D 3
	mov	ds, cs:spawn_segment
	mov	si, cs:spawn_offset
E 3
I 3
	mov	ds, cs:spint_segment
	mov	si, cs:spint_offset
E 3

D 3
	mov	spawn_ax[si], ax
	mov	spawn_bx[si], bx
	mov	spawn_cx[si], cx
	mov	spawn_dx[si], dx
E 3
I 3
	mov	spint_ax[si], ax
	mov	spint_bx[si], bx
	mov	spint_cx[si], cx
	mov	spint_dx[si], dx
E 3

D 3
	mov	spawn_si[si], si
	mov	spawn_di[si], di
E 3
I 3
	mov	spint_si[si], si
	mov	spint_di[si], di
E 3

D 3
	mov	spawn_cs[si], cs
	mov	spawn_ds[si], ds
	mov	spawn_es[si], es
	mov	spawn_ss[si], ss
E 3
I 3
	mov	spint_cs[si], cs
	mov	spint_ds[si], ds
	mov	spint_es[si], es
	mov	spint_ss[si], ss
E 3
	; now, need to do SI, DS
	mov	ax, old_si
D 3
	mov	spawn_si[si], ax
E 3
I 3
	mov	spint_si[si], ax
E 3
	mov	ax, old_ds
D 3
	mov	spawn_ds[si], ax
E 3
I 3
	mov	spint_ds[si], ax
E 3
	ENDM


E 2
I 1
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

I 2
D 3
save_sp		dw	1		; For use in our 'longjmp'
save_ss		dw	1		; For use in our 'longjmp'
E 3
I 3
start_sp	dw	1 dup (?)	; For use in our 'longjmp'
start_ss	dw	1 dup (?)	; For use in our 'longjmp'
E 3

D 3
spawn_segment	dw	1		; Segment of spawn control block
spawn_offset	dw	1		; Offset of spawn control block
E 3
I 3
spint_segment	dw	1 dup (?)	; Segment of spawn control block
spint_offset	dw	1 dup (?)	; Offset of spawn control block
E 3

D 3
old_si		dw	1		; SI of interrupt issuer (temporary)
old_ds		dw	1		; DS of interrupt issuer (temporary)
E 3
I 3
old_si		dw	1 dup (?)	; SI of interrupt issuer (temporary)
old_ds		dw	1 dup (?)	; DS of interrupt issuer (temporary)
E 3

D 3
issuer_sp	dw	1		; sp of person who called us (permanent)
E 3
I 3
issuer_ss	dw	1 dup (?)	; ss of person who called us (permanent)
issuer_sp	dw	1 dup (?)	; sp of person who called us (permanent)
E 3

I 3
int21_stack	db	100 dup (?)	; Stack for int21.

E 3
E 2
;
D 3
; int_spawn gets control on an interrupt.  It switches the stack
; and does a 'return' from start_spawn.
E 3
I 3
; _spint_int gets control on an interrupt.  It switches the stack
; and does a 'return' from _spint_start.
E 3
;
D 3
	public	_int_spawn
E 3
I 3
	public	__spint_int
E 3

D 3
_int_spawn	proc	near
E 3
I 3
__spint_int	proc	near
E 3
D 2
	push	bp
	mov	bp,sp
E 2
I 2
	mov	cs:issuer_sp, sp
I 3
	mov	cs:issuer_ss, ss
	sti
E 3
E 2

D 2
	mov	sp,bp
	pop	bp
	ret
E 2
I 2
	SETREGS

	LEAVE
E 2
D 3
_int_spawn	endp
E 3
I 3
__spint_int	endp
E 3

;
D 3
; start_spawn issues the dos interrupt after setting up the passed
; registers.  When control returns to it, it sets spawn->done to non-zero.
E 3
I 3
; _spint_start issues the dos interrupt after setting up the passed
; registers.  When control returns to it, it sets spint->done to non-zero.
E 3
;
D 3
	public	_start_spawn
E 3
I 3
	public	__spint_start
E 3

D 3
_start_spawn	proc	near
E 3
I 3
__spint_start	proc	near
E 3
D 2
	push	bp
	mov	bp,sp
E 2
I 2
	ENTER
E 2

D 2
	mov	sp,bp
	pop	bp
	ret
E 2
I 2
	GETREGS	4[bp]

I 3
	; Now, switch to a different (short) stack.  This is so
	; that our games won't mess up the stack int 21 (hardware and,
	; possibly, software) stores things on.

	cli
	mov	cs:int21_stack, cs
	mov	ss, cs:int21_stack
	mov	sp, offset int21_stack
	add	sp, (length int21_stack) - 4
	sti

E 3
	int	21H		; Issue DOS interrupt

	SETREGS

D 3
	mov	ds, cs:spawn_segment
	mov	si, cs:spawn_offset
	mov	spawn_done[si], 1	; We are done
E 3
I 3
	mov	ds, cs:spint_segment
	mov	si, cs:spint_offset
	mov	spint_done[si], 1	; We are done
E 3

	LEAVE
E 2
D 3
_start_spawn	endp
E 3
I 3
__spint_start	endp
E 3

;
D 3
; After int_spawn has faked a return from start_spawn, we come here to
E 3
I 3
; After _spint_int has faked a return from start_spawn, we come here to
E 3
; return to the interrupt issuer.
;
D 3
	public	_continue_spawn
E 3
I 3
	public	__spint_continue
E 3

D 3
_continue_spawn	proc	near
E 3
I 3
__spint_continue	proc	near
E 3
D 2
	push	bp
	mov	bp,sp
E 2
I 2
	ENTER
E 2

D 2
	mov	sp,bp
	pop	bp
	ret
E 2
I 2
	GETREGS	4[bp]

	mov	sp, cs:issuer_sp		; Restore SP
I 3
	mov	ss, cs:issuer_ss		; Restore SS
E 3

	iret
E 2
D 3
_continue_spawn	endp
E 3
I 3
__spint_continue	endp
E 3

_TEXT	ends

	end
E 1
