h34641
s 00009/00000/00101
d D 5.4 88/02/24 19:59:03 rick 4 3
c strip parity bit on input. get for buffer overflow
e
s 00030/00033/00071
d D 5.3 86/01/06 15:02:00 bloom 3 2
c more fixes from rick adams
e
s 00052/00025/00052
d D 5.2 85/01/22 14:09:07 ralph 2 1
c bug fixes and changes from Rick Adams
e
s 00077/00000/00000
d D 5.1 83/07/02 17:57:09 sam 1 0
c date and time created 83/07/02 17:57:09 by sam
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif

#include "uucp.h"
I 3
#include <ctype.h>
E 3

char Msync[2] = "\020";
D 2
/*******
 *	imsg(msg, fn)
 *	char *msg;
 *	int fn;
 *
 *	imsg  -  this is the initial read message routine -
E 2
I 2

/* to talk to both eunice and x.25 without also screwing up tcp/ip
 * we must adaptively  choose what character to end the msg with
 * 
 * The idea is that initially we send ....\000\n
 * Then, after they have sent us a message, we use the first character
 * they send.
 */

int seenend = 0;
char Mend = '\0';

/*
 *	this is the initial read message routine -
E 2
 *	used before a protocol is agreed upon.
 *
 *	return codes:
D 3
 *		EOF - no more messages
 *		0 - message returned
E 3
I 3
 *		FAIL - no more messages
 *		SUCCESS - message returned
E 3
 */

D 3
imsg(msg, fn)
register char *msg;
E 3
I 3
imsg(amsg, fn)
char *amsg;
E 3
register int fn;
{
D 3
	register int ret;
D 2
	DEBUG(7, "imsg %s>", "");
E 2
I 2
	char *amsg;
E 3
I 3
	register char *msg = amsg;
I 4
	register int nchars = 0;
E 4
	int foundsync = FAIL;
	char c;
E 3

D 3
	DEBUG(5, "imsg %s<", "sync");
E 2
	while ((ret = read(fn, msg, 1)) == 1) {
D 2
		*msg &= 0177;	/* Turn off parity bit (mhb5b!smb) */
		DEBUG(7, (*msg>037) ? "%c" : "\\%03o", *msg & 0377);
E 2
I 2
		*msg &= 0177;
		DEBUG(5, (*msg>037 && *msg<0177) ? "%c" : "\\%03o", *msg & 0377);
E 2
		if (*msg == Msync[0])
			break;
I 2
		fflush(stderr);
E 2
	}
D 2
	DEBUG(7, "%s\n", "<");
E 2
I 2
	DEBUG(5, ">got %s\n", ret == 1 ? "it" : "EOF");
E 2
	if (ret < 1)
D 2
		return(EOF);
E 2
I 2
		return EOF;
	amsg = msg;
resync:
	DEBUG(5, "imsg %s<", "input");
E 2
	while (read(fn, msg, 1) == 1) {
		*msg &= 0177;
D 2
		DEBUG(7, (*msg>037) ? "%c" : "\\%03o", *msg & 0377);
		if (*msg == '\n')
E 2
I 2
		DEBUG(5, (*msg>037 && *msg<0177) ? "%c" : "\\%03o", *msg & 0377);
		if (*msg == Msync[0]) {
			DEBUG(5, "%s\n", ">found sync");
E 3
I 3
	DEBUG(5, "imsg looking for SYNC<", CNULL);
	for (;;) {
		if (read(fn, &c, 1) != 1)
			return FAIL;
I 4
		DEBUG(9,"\t%o", c&0377);
E 4
		c &= 0177;
		if (c == '\n' || c == '\r')
			DEBUG(5, "%c", c);
		else 
			DEBUG(5, (isprint(c) || isspace(c)) ? "%c" : "\\%o",
				c & 0377);
I 4
		c &= 0177;
E 4
		if (c == Msync[0]) {
			DEBUG(5, ">\nimsg input<", CNULL);
E 3
			msg = amsg;
I 4
			nchars = 0;
E 4
D 3
			goto resync;
		}
		if (*msg == '\n' || *msg == '\0') {
E 3
I 3
			foundsync = SUCCESS;
			continue;
		} else if (foundsync != SUCCESS)
				continue;
		if (c == '\n' || c == '\0') {
E 3
			if (!seenend) {
D 3
				Mend = *msg;
E 3
I 3
				Mend = c;
E 3
				seenend++;
D 3
				DEBUG(6,"\nUsing \\%o as End of message char\n", Mend);
E 3
I 3
				DEBUG(9, "\nUsing \\%o as End of message char\n", Mend);
E 3
			}
E 2
			break;
D 2
		if (*msg == '\0')
			break;
E 2
I 2
		}
E 2
D 3
		msg++;
E 3
I 3
		*msg++ = c;
I 4
		/* MAXFULLNAME should really be passed in as a parameter */
		if (nchars++ > MAXFULLNAME) {
			DEBUG(1, "buffer overrun in imsg", CNULL);
			return FAIL;
		}
E 4
E 3
I 2
		fflush(stderr);
E 2
	}
	*msg = '\0';
D 2
	return(0);
E 2
I 2
D 3
	DEBUG(5, ">got %d\n", strlen(amsg));
	return 0;
E 3
I 3
	DEBUG(5, ">got %d characters\n", strlen(amsg));
	return foundsync;
E 3
E 2
}


D 2
/***
 *	omsg(type, msg, fn)
 *	char type, *msg;
 *	int fn;
 *
 *	omsg  -  this is the initial write message routine -
E 2
I 2
/*
 *	this is the initial write message routine -
E 2
 *	used before a protocol is agreed upon.
 *
 *	return code:  always 0
 */

omsg(type, msg, fn)
register char *msg;
char type;
int fn;
{
D 2
	char buf[BUFSIZ];
E 2
I 2
	char buf[MAXFULLNAME];
E 2
	register char *c;

	c = buf;
I 2
	*c = '\0';	/* avoid pdp 11/23,40 auto-incr stack trap bug */
E 2
	*c++ = Msync[0];
	*c++ = type;
	while (*msg)
		*c++ = *msg++;
	*c++ = '\0';
D 2
	write(fn, buf, strlen(buf) + 1);
	return(0);
E 2
I 2
	DEBUG(5, "omsg <%s>\n", buf);
	if (seenend) 
		c[-1] = Mend;
	else
		*c++ = '\n';
	write(fn, buf, (int)(c - buf));
	return 0;
E 2
}
E 1
