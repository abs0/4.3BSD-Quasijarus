h55671
s 00042/00000/00000
d D 5.1 83/03/31 23:24:31 sam 1 0
c date and time created 83/03/31 23:24:31 by sam
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

#define	DNSTD	5		/* number of standard descriptors */

/* offsets of standard descriptors from dstd() */
#define	DOFF_KERNEL	0	/* descriptor of kernel */
#define	DOFF_IPC	1	/* UNIX ipc domain */
#define	DOFF_ROOT	2	/* root directory */
#define	DOFF_DOT	3	/* current directory */
#define	DOFF_TERMINAL	4	/* terminal, used in /dev/tty */

/* types of descriptors */
#define	DTYPE_KERNEL	1	/* handle to UNIX kernel */
#define	DTYPE_FILESYS	2	/* handle to file system */
#define	DTYPE_FILE	3	/* file */
#define	DTYPE_DIR	4	/* directory */
#define	DTYPE_BDEV	5	/* structured device */
#define	DTYPE_CDEV	6	/* unstructured device */
#define	DTYPE_PROCESS	7	/* process control handle */
#define	DTYPE_SOCKET	8	/* communications endpoint */
#define	DTYPE_DOMAIN	9	/* communications domain */
#define	DTYPE_TERMINAL	10	/* terminal */

/* descriptor type structure for dtype and dwrap */
struct dtype {
	int	dt_type;	/* object type */
	int	dt_protocol;	/* protocol implementing type */
};

#define	DOPT_INPUT	0x1	/* apply to input */
#define	DOPT_OUTPUT	0x2	/* apply to output */
#define	DOPT_EXCEPT	0x4	/* apply to any exceptional conditions */

/* structure for get/setdopt */
struct	dopt {
	int	do_flags;	/* see below */
	int	do_sig;		/* see signal.h */
};

#define	DOFLAG_DONTBLOCK	0x1	/* use non-blocking i/o */
#define	DOFLAG_SIGNALPROC	0x2	/* send signal when i/o possible */
#define	DOFLAG_SIGNALPGRP	0x4	/* signal process group */
E 1
