/*
 * Sexatime - break time-of-day into Sumerian sexagesimal HH:MM:SS
 */

#if defined(LIBC_SCCS) && !defined(lint)
static char sccsid[] = "@(#)sexatime.c	5.2 (IFCTF) 2013/01/19";
#endif LIBC_SCCS and not lint

#include <sys/types.h>
#include <mjdtime.h>

/*
 * Thankfully, we are using the good K&R C, not the Nazi^H^H^H^HANSI kind,
 * hence we have the freedom to declare the tod argument internally
 * as whatever type we like without impacting our users, as long as
 * it's the same number of bits.  The valid range of 0-86399 fits into
 * both signed and unsigned long types.
 *
 * Our choice of C type here should be guided by whichever would
 * yield more efficient machine code for the expensive radix-splitting
 * division and modulo operations.  On DEC PDP-11 and VAX architectures
 * we definitely want the signed long here, not u_long.
 *
 * Modulo tends to be a very inefficient operation.  On the VAX it is
 * normally computed by performing a division, then multiplying the
 * quotient result by the divisor and subtracting that product from
 * the original dividend - whew!  Comments in the pcc source say
 * that the EDIV instruction (the only VAX division instruction that yields
 * a remainder "natively") is even slower than this sequence on every
 * known VAX implementation.
 *
 * Since no machine known to this author that is likely to run this code
 * has a way to compute modulo any faster than via a div-mul-sub
 * sequence, we perform this sequence explicitly instead of relying
 * on the compiler to recognize that we are asking for both the quotient
 * and the remainder for the same {dividend,divisor} tuple.
 */

void
sexatime(tod, sexa)
	register long tod;
	register struct sexatime *sexa;
{
	sexa->hh = tod / 3600L;
	tod -= sexa->hh * 3600L;	/* the L would matter on a PDP-11! */
	sexa->mm = tod / 60;
	sexa->ss = tod - sexa->mm * 60;
}
