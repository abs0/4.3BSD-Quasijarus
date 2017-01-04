h53532
s 00047/00000/00000
d D 7.1 04/02/06 21:36:31 msokolov 1 0
c date and time created 04/02/06 21:36:31 by msokolov
e
u
U
t
T
I 1
/*
 * Interface to KA6xx ROM console I/O routines for standalone system
 *
 * KA6xx boards all implement standard console IPRs when used with the normal
 * serial console, but BSD supports VAXstation configurations on these CPUs as
 * well.  We can save a lot of space in the standalone system by calling the
 * console I/O routines in the ROM instead of carrying our own QVSS and QDSS
 * code.  The ROM entry points we use exist on KA630 and up, though the
 * earliest manual I have that documents them is the one for KA655.
 *
 * Code adapted from Ultrix V4.2 (where it is used for KA650 only).
 *
 *	%W% (Berkeley) %G%
 */

/*
 * We must fake a descriptor for the ka650 console output.
 * descriptor format:
 *		length of output string (always 1)
 *		address of buf (where output char will be stuffed)
 * buf:
 *		where we stuff the output char
 * 
 * We pass the address of the "descriptor" to the console output routine
 */
	.data
desc:	.long	1,buf
buf:	.long
	.text

#define get_character		0x20040008
#define output_message		0x2004000c

	.globl _c6xxgetc
_c6xxgetc:
	.word	0
	clrl	r0			# clear timeout
	jsb	*$get_character		# Get a character
	ret

	.globl _c6xxputc
_c6xxputc:
	.word	0
	movl	4(ap),buf		# Put character to output in desc
	movab	desc,r0			# Put desc address in r0
	jsb     *$output_message	# Echo the character
	ret
E 1
