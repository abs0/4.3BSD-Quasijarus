h00555
s 00000/00000/00022
d D 2.1 81/07/01 11:11:32 kurt 2 1
c Release to Heidi Stettner
e
s 00022/00000/00000
d D 1.1 80/10/08 09:53:53 kas 1 0
c date and time created 80/10/08 09:53:53 by kas
e
u
U
f b 
t
T
I 1
/*
 * Declarations and constants specific to an installation.
 * Unix Version 6.
 */
 
/*
 * Sccs Id = "%W% %G%";
 */

#define	LOCAL		'i'		/* Local machine id */
#define	MAIL		"/bin/mail"	/* Name of mail sender */
#define	EDITOR		"/usr/bin/ex"	/* Name of text editor */
#define	VISUAL		"/usr/bin/vi"	/* Name of display editor */
#define	SHELL		"/bin/sh"	/* Standard shell */
#define	HELPFILE	"/usr/lib/Mail.help"
					/* Name of casual help file */
#define	THELPFILE	"/usr/lib/Mail.help.~"
					/* Name of casual tilde help */
#define	UIDMASK		0377		/* Significant uid bits */
#define	MASTER		"/usr/lib/Mail.rc"
#define	stat		_stat		/* Simulate version 7 */
#define	fstat		_fstat		/* Simulate version 7 */
E 1
