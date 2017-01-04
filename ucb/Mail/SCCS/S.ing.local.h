h15203
s 00000/00000/00030
d D 2.1 81/07/01 11:11:22 kurt 2 1
c Release to Heidi Stettner
e
s 00030/00000/00000
d D 1.1 80/10/08 09:53:43 kas 1 0
c date and time created 80/10/08 09:53:43 by kas
e
u
U
f b 
t
T
I 1
/*
 * Declarations and constants specific to an installation.
 * Ingres 11/70 version 6.
 */
 
/*
 * Sccs Id = "%W% %G%";
 */

#define	LOCAL		'i'		/* Local machine id */
#define	MAIL		"/bin/mail"	/* Name of mail sender */
#define	DELIVERMAIL	"/etc/delivermail"
					/* Preferred mail deliverer */
#define	EDITOR		"/usr/bin/ex"	/* Name of text editor */
#define	VISUAL		"/usr/bin/vi"	/* Name of display editor */
#define	SHELL		"/bin/sh"	/* Standard shell */
#define	HELPFILE	"/usr/lib/Mail.help"
					/* Name of casual help file */
#define	THELPFILE	"/usr/lib/Mail.help.~"
					/* Name of casual tilde help */
#define	UIDMASK		0377		/* Significant uid bits */
#define	MASTER		"/usr/lib/Mail.rc"
#define	CANLOCK				/* Mailbox locking protocol works */
#define	stat	_stat			/* Simulate version 7 */
#define	fstat	_fstat			/* Simulate version 7 */

/*
 * Machine dependent type declarations.
 */

E 1
