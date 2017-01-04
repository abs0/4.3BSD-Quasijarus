h15702
s 00000/00000/00026
d D 2.1 81/07/01 11:11:06 kurt 2 1
c Release to Heidi Stettner
e
s 00026/00000/00000
d D 1.1 80/10/08 09:53:32 kas 1 0
c date and time created 80/10/08 09:53:32 by kas
e
u
U
f b 
t
T
I 1
/*
 * Declarations and constants specific to an installation.
 * Computer Center Unix A
 *
 * Note to fiddlers:  please, please, PLEASE note all changes
 * that you make here so that I can keep an up to date version.
 */
 
/*
 * Sccs Id = "%W% %G%";
 */

#define	LOCAL		'a'		/* Local machine id */
#define	MAIL		"/bin/mail"	/* Name of mail sender */
#define	UIDGID				/* Names and uids like cory */
#define	EDITOR		"/usr/bin/ex"	/* Name of text editor */
#define	VISUAL		"/usr/new/vi"	/* Name of display editor */
#define	SHELL		"/bin/csh"	/* Default shell */
#define	HELPFILE	"/usr/lib/Mail.help"
					/* Name of casual help file */
#define	THELPFILE	"/usr/lib/Mail.help.~"
					/* Name of casual tilde help */
#define	UIDMASK		0377		/* Significant uid bits */
#define	MASTER		"/usr/lib/Mail.rc"
#define	stat	_stat			/* Simulate version 7 */
#define	fstat	_fstat			/* Simulate version 7 */
E 1
