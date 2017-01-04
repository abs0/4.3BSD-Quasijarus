h47798
s 00001/00000/00046
d D 5.2 85/07/30 16:40:15 jerry 11 10
c implement namelist
e
s 00007/00001/00039
d D 5.1 85/06/07 23:35:57 kre 10 9
c Add copyright
e
s 00005/00005/00035
d D 1.8 85/06/04 20:51:38 libs 9 8
c update error messages.
e
s 00001/00001/00039
d D 1.7 85/05/02 22:05:53 libs 8 7
c F_ERSYS may also be opening more than system max. no. of files.
e
s 00002/00001/00038
d D 1.6 85/02/14 22:27:37 libs 7 5
c Improve error messages.
e
s 00002/00001/00038
d R 1.6 85/02/14 22:23:41 libs 6 5
c Improve error messages.
e
s 00001/00000/00038
d D 1.5 83/01/10 13:51:46 dlw 5 4
c added 123. DLW
e
s 00001/00001/00037
d D 1.4 81/02/27 16:11:51 dlw 4 3
c fixed declaration for f_nerr. DLW
e
s 00003/00000/00035
d D 1.3 81/02/27 13:45:28 dlw 3 2
c added def for F_MAXERR. DLW
e
s 00002/00000/00033
d D 1.2 81/02/18 21:44:21 dlw 2 1
c added include errno.h to get system error codes. DLW
e
s 00033/00000/00000
d D 1.1 81/02/18 18:02:14 dlw 1 0
c date and time created 81/02/18 18:02:14 by dlw
e
u
U
t
T
I 1
/*
D 10
char id_f_errno[] = "%W%";
E 10
I 10
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 10
 *
I 10
 *	%W% (Berkeley) %G%
 */

/*
E 10
 * f77 I/O error definitions
 */

I 2
#include	<errno.h>

E 2
extern int errno;
I 3
extern int f_nerr;
E 3

#define F_ER		100	/* base offset of f77 error numbers */

#define F_ERFMT		100	/* error in format */
#define F_ERUNIT	101	/* illegal unit number */
D 9
#define F_ERNOFIO	102	/* formatted io not allowed */
#define F_ERNOUIO	103	/* unformatted io not allowed */
#define F_ERNODIO	104	/* direct io not allowed */
#define F_ERNOSIO	105	/* sequential io not allowed */
E 9
I 9
#define F_ERNOFIO	102	/* formatted i/o not allowed */
#define F_ERNOUIO	103	/* unformatted i/o not allowed */
#define F_ERNODIO	104	/* direct i/o not allowed */
#define F_ERNOSIO	105	/* sequential i/o not allowed */
E 9
#define F_ERNOBKSP	106	/* can't backspace file */
#define F_ERBREC	107	/* off beginning of record */
#define F_ERSTAT	108	/* can't stat file */
#define F_ERREPT	109	/* no * after repeat count */
#define F_EREREC	110	/* off end of record */
#define F_ERTRUNC	111	/* truncation failed */
#define F_ERLIO		112	/* incomprehensible list input */
#define F_ERSPACE	113	/* out of free space */
#define F_ERNOPEN	114	/* unit not connected */
D 7
#define F_ERRDCHR	115	/* read unexpected character */
E 7
I 7
#define F_ERRICHR	115	/* invalid data for integer format term */
E 7
D 9
#define F_ERLOGIF	116	/* blank logical input field */
E 9
I 9
#define F_ERLOGIF	116	/* invalid data for logical format term */
E 9
#define F_ERNEWF	117	/* 'new' file exists */
#define F_EROLDF	118	/* can't find 'old' file */
D 8
#define F_ERSYS		119	/* unknown system error */
E 8
I 8
#define F_ERSYS		119	/* opening too many files or unknown system error */
E 8
#define F_ERSEEK	120	/* requires seek ability */
#define F_ERARG		121	/* illegal argument */
#define F_ERNREP	122	/* negative repeat count */
I 5
#define F_ERILLOP	123	/* illegal operation for channel or device */
I 7
#define F_ERRFCHR	124	/* invalid data for d,e,f, or g format term */
I 11
#define F_ERNMLIST	125	/* illegal input for namelist */
E 11
E 7
E 5
I 3

D 4
#define F_MAXERR	(f_nerr - F_ER)
E 4
I 4
#define F_MAXERR	(f_nerr + F_ER)
E 4
E 3
E 1
