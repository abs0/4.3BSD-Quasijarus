h10144
s 00000/00000/00024
d D 2.1 81/07/01 11:11:02 kurt 2 1
c Release to Heidi Stettner
e
s 00024/00000/00000
d D 1.1 80/10/08 09:53:29 kas 1 0
c date and time created 80/10/08 09:53:29 by kas
e
u
U
f b 
t
T
I 1
/*
 * Declarations and constants specific to an installation.
 * UCB 11/70 Version 7.0
 */
 
/*
 * Sccs Id = "%W% %G%";
 */

#define APPEND				/* New mail to end of mail box */
#define	LOCAL		'y'		/* Local machine id */
#define	MAIL		"/bin/mail"	/* Name of mail sender */
#define DELIVERMAIL	"/etc/delivermail"
					/* Name of snazzy mail deliverer */
#define	VISUAL		"/usr/ucb/bin/vi"	/* Name of display editor */
#define	EDITOR		"/usr/ucb/bin/ex"	/* Name of text editor */
#define	SHELL		"/bin/csh"	/* Default shell interpreter */
#define	HELPFILE	"/usr/ucb/lib/Mail.help"
					/* Name of casual help file */
#define	THELPFILE	"/usr/ucb/lib/Mail.help.~"
					/* Name of casual tilde help */
#define	UIDMASK		0177777		/* Significant uid bits */
#define	MASTER		"/usr/ucb/lib/Mail.rc"
#define	UTIME				/* System implement utime(2) */
E 1
