h34350
s 00002/00002/00092
d D 5.2 86/03/09 19:45:49 donn 9 8
c added LIBC_SCCS condition for sccs ids
e
s 00010/00001/00084
d D 5.1 85/05/30 10:41:02 dist 8 7
c Add copyright
e
s 00004/00004/00081
d D 4.7 84/12/04 12:20:29 karels 7 6
c update/generalize/fix error messages
e
s 00004/00000/00081
d D 4.6 82/12/19 12:36:21 sam 6 5
c update to reflect errno.h
e
s 00002/00000/00079
d D 4.5 82/05/02 14:43:02 sam 5 4
c make host errors distinct from network
e
s 00002/00000/00077
d D 4.4 82/04/01 10:32:44 root 4 3
c errors for links
e
s 00073/00044/00004
d D 4.3 82/02/11 12:04:59 root 3 2
c get rid of mpx stuff
e
s 00009/00000/00039
d D 4.2 81/09/25 13:01:04 ecc 2 1
c added bbnnet error messages
e
s 00039/00000/00000
d D 4.1 80/12/21 16:39:37 wnj 1 0
c date and time created 80/12/21 16:39:37 by wnj
e
u
U
t
T
I 1
D 3
/* %W% (Berkeley) %G% */
E 3
I 3
D 8
/* %W% (Berkeley) %E% */
E 8
I 8
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

D 9
#ifndef lint
E 9
I 9
#if defined(LIBC_SCCS) && !defined(lint)
E 9
static char sccsid[] = "%W% (Berkeley) %G%";
D 9
#endif not lint
E 9
I 9
#endif LIBC_SCCS and not lint
E 9

E 8
E 3
char	*sys_errlist[] = {
	"Error 0",
D 3
	"Not owner",
	"No such file or directory",
	"No such process",
	"Interrupted system call",
	"I/O error",
	"No such device or address",
	"Arg list too long",
	"Exec format error",
	"Bad file number",
	"No children",
	"No more processes",
	"Not enough core",
	"Permission denied",
	"Bad address",
	"Block device required",
	"Mount device busy",
	"File exists",
	"Cross-device link",
	"No such device",
	"Not a directory",
	"Is a directory",
	"Invalid argument",
	"File table overflow",
	"Too many open files",
	"Not a typewriter",
	"Text file busy",
	"File too large",
	"No space left on device",
	"Illegal seek",
	"Read-only file system",
	"Too many links",
	"Broken pipe",
	"Argument too large",
	"Result too large",
I 2
	/* bbnnet errors */
	"User status available (not an error)",
	"Open attempted when net not initialized",
	"Too many net connections",
	"No more net buffer space",
	"Error from network",
	"Error in raw link or protocol range",
	"Unable to open connection",
	"Unable to send on raw connection",
E 3
I 3
	"Not owner",				/* 1 - EPERM */
	"No such file or directory",		/* 2 - ENOENT */
	"No such process",			/* 3 - ESRCH */
	"Interrupted system call",		/* 4 - EINTR */
	"I/O error",				/* 5 - EIO */
	"No such device or address",		/* 6 - ENXIO */
	"Arg list too long",			/* 7 - E2BIG */
	"Exec format error",			/* 8 - ENOEXEC */
	"Bad file number",			/* 9 - EBADF */
	"No children",				/* 10 - ECHILD */
	"No more processes",			/* 11 - EAGAIN */
D 7
	"Not enough core",			/* 12 - ENOMEM */
E 7
I 7
	"Not enough memory",			/* 12 - ENOMEM */
E 7
	"Permission denied",			/* 13 - EACCES */
	"Bad address",				/* 14 - EFAULT */
	"Block device required",		/* 15 - ENOTBLK */
D 7
	"Mount device busy",			/* 16 - EBUSY */
E 7
I 7
	"Device busy",				/* 16 - EBUSY */
E 7
	"File exists",				/* 17 - EEXIST */
	"Cross-device link",			/* 18 - EXDEV */
	"No such device",			/* 19 - ENODEV */
	"Not a directory",			/* 20 - ENOTDIR */
	"Is a directory",			/* 21 - EISDIR */
	"Invalid argument",			/* 22 - EINVAL */
	"File table overflow",			/* 23 - ENFILE */
	"Too many open files",			/* 24 - EMFILE */
D 7
	"Not a typewriter",			/* 25 - ENOTTY */
E 7
I 7
	"Inappropriate ioctl for device",	/* 25 - ENOTTY */
E 7
	"Text file busy",			/* 26 - ETXTBSY */
	"File too large",			/* 27 - EFBIG */
	"No space left on device",		/* 28 - ENOSPC */
	"Illegal seek",				/* 29 - ESPIPE */
	"Read-only file system",		/* 30 - EROFS */
	"Too many links",			/* 31 - EMLINK */
	"Broken pipe",				/* 32 - EPIPE */

/* math software */
	"Argument too large",			/* 33 - EDOM */
	"Result too large",			/* 34 - ERANGE */

/* non-blocking and interrupt i/o */
	"Operation would block",		/* 35 - EWOULDBLOCK */
	"Operation now in progress",		/* 36 - EINPROGRESS */
	"Operation already in progress",	/* 37 - EALREADY */

/* ipc/network software */

	/* argument errors */
	"Socket operation on non-socket",	/* 38 - ENOTSOCK */
	"Destination address required",		/* 39 - EDESTADDRREQ */
	"Message too long",			/* 40 - EMSGSIZE */
	"Protocol wrong type for socket",	/* 41 - EPROTOTYPE */
D 7
	"Protocol not available",		/* 42 - ENOPROTOOPT */
E 7
I 7
	"Option not supported by protocol",	/* 42 - ENOPROTOOPT */
E 7
	"Protocol not supported",		/* 43 - EPROTONOSUPPORT */
	"Socket type not supported",		/* 44 - ESOCKTNOSUPPORT */
	"Operation not supported on socket",	/* 45 - EOPNOTSUPP */
	"Protocol family not supported",	/* 46 - EPFNOSUPPORT */
	"Address family not supported by protocol family",
						/* 47 - EAFNOSUPPORT */
	"Address already in use",		/* 48 - EADDRINUSE */
	"Can't assign requested address",	/* 49 - EADDRNOTAVAIL */

	/* operational errors */
	"Network is down",			/* 50 - ENETDOWN */
	"Network is unreachable",		/* 51 - ENETUNREACH */
	"Network dropped connection on reset",	/* 52 - ENETRESET */
	"Software caused connection abort",	/* 53 - ECONNABORTED */
	"Connection reset by peer",		/* 54 - ECONNRESET */
	"No buffer space available",		/* 55 - ENOBUFS */
	"Socket is already connected",		/* 56 - EISCONN */
	"Socket is not connected",		/* 57 - ENOTCONN */
	"Can't send after socket shutdown",	/* 58 - ESHUTDOWN */
	"Too many references: can't splice",	/* 59 - ETOOMANYREFS */
	"Connection timed out",			/* 60 - ETIMEDOUT */
	"Connection refused",			/* 61 - EREFUSED */
I 4
	"Too many levels of symbolic links",	/* 62 - ELOOP */
	"File name too long",			/* 63 - ENAMETOOLONG */
I 5
	"Host is down",				/* 64 - EHOSTDOWN */
	"Host is unreachable",			/* 65 - EHOSTUNREACH */
I 6
	"Directory not empty",			/* 66 - ENOTEMPTY */
	"Too many processes",			/* 67 - EPROCLIM */
	"Too many users",			/* 68 - EUSERS */
	"Disc quota exceeded",			/* 69 - EDQUOT */
E 6
E 5
E 4
E 3
E 2
};
int	sys_nerr = { sizeof sys_errlist/sizeof sys_errlist[0] };
E 1
