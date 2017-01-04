h08243
s 00001/00003/00062
d D 5.4 87/10/22 17:40:05 bostic 17 16
c ANSI C; sprintf now returns an int.
e
s 00004/00000/00061
d D 5.3 86/03/15 17:53:43 donn 16 15
c Put '#ifndef lint' around getc()  and putc() to make life easier for
c lint.  Corresponding definitions were added to the lint library.
e
s 00000/00001/00061
d D 5.2 86/02/24 23:48:31 lepreau 15 14
c remove fseek: back to old version returning int
e
s 00008/00001/00054
d D 5.1 85/05/30 14:25:18 dist 14 13
c Add copyright
e
s 00009/00007/00046
d D 1.12 85/05/30 13:22:56 serge 13 12
c deleted _NFILE (use getdtablesize() instead)
e
s 00001/00001/00052
d D 1.11 85/01/08 09:34:23 ralph 12 11
c increase _NOFILE to 48 to match kernel
e
s 00007/00004/00046
d D 1.10 84/11/29 11:00:40 ralph 11 10
c fix putc(x,iop) so x is executed only once (as before).
e
s 00003/00002/00047
d D 1.9 84/11/21 12:18:13 ralph 10 9
c fix sign-extend problems in putc, getc macros
e
s 00004/00004/00045
d D 1.8 84/11/12 11:27:53 ralph 9 7
c fix lint errs, make code for putc more compact.
e
s 00004/00004/00045
d R 1.8 84/11/12 09:38:50 ralph 8 7
c fix lint errs, make code for putc more compact.
e
s 00004/00002/00045
d D 1.7 84/11/08 11:05:43 ralph 7 6
c putc(): don't call flsbuf until buffer full or '\n' if line buffering.
e
s 00001/00000/00046
d D 1.6 84/09/10 10:16:32 ralph 6 5
c added func declaration for gets
e
s 00001/00001/00045
d D 1.5 83/08/11 23:17:09 sam 5 4
c standardize sccs keyword lines
e
s 00003/00001/00043
d D 1.4 83/06/30 15:19:21 sam 4 3
c from sun
e
s 00001/00000/00043
d D 1.3 83/03/02 09:29:22 nicklin 3 2
c added char *sprintf();
e
s 00001/00000/00042
d D 1.2 82/10/05 22:44:12 mckusick 2 1
c utilize st_blksize field to optimize size of reads and writes
e
s 00042/00000/00000
d D 1.1 81/03/09 21:00:10 toy 1 0
c date and time created 81/03/09 21:00:10 by toy
e
u
U
t
T
I 1
D 5
/*	%W% (Berkeley) %G%	*/
E 5
I 5
D 14
/*	%M%	%I%	%E%	*/
E 14
I 14
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */

E 14
E 5
D 13
#define	BUFSIZ	1024
D 12
#define	_NFILE	20
E 12
I 12
#define	_NFILE	48
E 13
E 12
# ifndef FILE
I 13
#define	BUFSIZ	1024
E 13
extern	struct	_iobuf {
	int	_cnt;
D 13
	char	*_ptr;
	char	*_base;
E 13
I 13
	char	*_ptr;		/* should be unsigned char */
	char	*_base;		/* ditto */
E 13
I 2
	int	_bufsiz;
E 2
	short	_flag;
D 13
	char	_file;
} _iob[_NFILE];
# endif
E 13
I 13
	char	_file;		/* should be short */
} _iob[];
E 13

#define	_IOREAD	01
#define	_IOWRT	02
#define	_IONBF	04
#define	_IOMYBUF	010
#define	_IOEOF	020
#define	_IOERR	040
#define	_IOSTRG	0100
#define	_IOLBF	0200
#define	_IORW	0400
#define	NULL	0
#define	FILE	struct _iobuf
#define	EOF	(-1)

#define	stdin	(&_iob[0])
#define	stdout	(&_iob[1])
#define	stderr	(&_iob[2])
I 16
#ifndef lint
E 16
D 7
#define	getc(p)		(--(p)->_cnt>=0? *(p)->_ptr++&0377:_filbuf(p))
E 7
I 7
D 9
#define	getc(p)	(--(p)->_cnt >= 0 ? *(unsigned char *)(p)->_ptr++ : _filbuf(p))
E 9
I 9
D 10
#define	getc(p)		(--(p)->_cnt>=0? *(p)->_ptr++&0377:_filbuf(p))
E 10
I 10
#define	getc(p)		(--(p)->_cnt>=0? (int)(*(unsigned char *)(p)->_ptr++):_filbuf(p))
I 16
#endif not lint
E 16
E 10
E 9
E 7
#define	getchar()	getc(stdin)
I 16
#ifndef lint
E 16
D 7
#define putc(x,p) (--(p)->_cnt>=0? ((int)(*(p)->_ptr++=(unsigned)(x))):_flsbuf((unsigned)(x),p))
E 7
I 7
D 9
#define putc(x, p)	(--(p)->_cnt >= 0 ? (*(p)->_ptr++ = (x)) :\
	((p)->_flag&_IOLBF && -(p)->_cnt <= (p)->_bufsiz && (x)!='\n' ?\
		*(p)->_ptr++ = (x) : _flsbuf(x, p)))
E 9
I 9
D 11
#define putc(x, p)	(--(p)->_cnt >= 0 || ((p)->_flag & _IOLBF) &&\
		-(p)->_cnt <= (p)->_bufsiz && (x) != '\n' ?\
D 10
		(int)(*(p)->_ptr++ = (unsigned)(x)) : _flsbuf((unsigned)(x), p))
E 10
I 10
		(int)(*(unsigned char *)(p)->_ptr++ = (x)) :\
		_flsbuf((unsigned char)(x), p))
E 11
I 11
#define putc(x, p)	(--(p)->_cnt >= 0 ?\
	(int)(*(unsigned char *)(p)->_ptr++ = (x)) :\
	(((p)->_flag & _IOLBF) && -(p)->_cnt < (p)->_bufsiz ?\
		((*(p)->_ptr = (x)) != '\n' ?\
			(int)(*(unsigned char *)(p)->_ptr++) :\
			_flsbuf(*(unsigned char *)(p)->_ptr, p)) :\
		_flsbuf((unsigned char)(x), p)))
I 16
#endif not lint
E 16
E 11
E 10
E 9
E 7
#define	putchar(x)	putc(x,stdout)
#define	feof(p)		(((p)->_flag&_IOEOF)!=0)
#define	ferror(p)	(((p)->_flag&_IOERR)!=0)
#define	fileno(p)	((p)->_file)
I 13
#define	clearerr(p)	((p)->_flag &= ~(_IOERR|_IOEOF))
E 13

FILE	*fopen();
FILE	*fdopen();
FILE	*freopen();
I 13
FILE	*popen();
E 13
long	ftell();
I 13
D 15
long	fseek();
E 15
E 13
char	*fgets();
I 6
char	*gets();
E 6
I 3
D 4
char	*sprintf();
E 4
I 4
D 17
#ifdef vax
char	*sprintf();		/* too painful to do right */
#endif
E 17
I 17
int	sprintf();	/* here until everyone does it right */
E 17
I 13
# endif
E 13
E 4
E 3
E 1
