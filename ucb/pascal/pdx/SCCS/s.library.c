h26016
s 00023/00145/00416
d D 5.2 87/04/07 15:51:44 mckusick 3 2
c port for tahoe from Nir peleg of CCI
e
s 00008/00002/00553
d D 5.1 85/06/07 19:42:49 mckusick 2 1
c Add copyright
e
s 00555/00000/00000
d D 1.1 82/09/02 20:30:58 linton 1 0
c date and time created 82/09/02 20:30:58 by linton
e
u
U
t
T
I 1
D 2
/* Copyright (c) 1982 Regents of the University of California */
E 2
I 2
/*
 * Copyright (c) 1982 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 2

D 2
/* static char sccsid[] = "%Z%%M% %I% %G%"; */
E 2
I 2
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 2

/*
 * General purpose routines.
 */

#include <stdio.h>
#include <errno.h>
I 3
#include "defs.h"
E 3

#define public
#define private static
#define and &&
D 3
#define or ||
#define not !
#define ord(enumcon)	((int) enumcon)
E 3
#define nil(type)	((type) 0)

D 3
typedef enum { FALSE, TRUE } Boolean;
E 3
typedef char *String;
typedef FILE *File;
typedef String Filename;
I 3
typedef char Boolean;
E 3

#undef FILE

D 3
/*
 * Definitions of standard C library routines that aren't in the
 * standard I/O library, but which are generally useful.
 */

extern long atol();		/* ascii to long */
extern double atof();		/* ascii to floating point */
extern char *mktemp();		/* make a temporary file name */

E 3
String cmdname;			/* name of command for error messages */
Filename errfilename;		/* current file associated with error */
short errlineno;		/* line number associated with error */

D 3
/*
 * Definitions for doing memory allocation.
 */

extern char *malloc();

#define alloc(n, type)	((type *) malloc((unsigned) (n) * sizeof(type)))
#define dispose(p)	{ free((char *) p); p = 0; }

/*
 * Macros for doing freads + fwrites.
 */

#define get(fp, var)	fread((char *) &(var), sizeof(var), 1, fp)
#define put(fp, var)	fwrite((char *) &(var), sizeof(var), 1, fp)

/*
 * String definitions.
 */

extern String strcpy(), index(), rindex();
extern int strlen();

#define strdup(s)		strcpy(malloc((unsigned) strlen(s) + 1), s)
#define streq(s1, s2)	(strcmp(s1, s2) == 0)

E 3
typedef int INTFUNC();

typedef struct {
    INTFUNC *func;
} ERRINFO;

#define ERR_IGNORE ((INTFUNC *) 0)
#define ERR_CATCH  ((INTFUNC *) 1)

I 3
public INTFUNC *onsyserr();

E 3
/*
 * Call a program.
 *
D 3
 * Four entries:
E 3
I 3
 * Three entries:
E 3
 *
 *	call, callv - call a program and wait for it, returning status
D 3
 *	back, backv - call a program and don't wait, returning process id
E 3
I 3
 *	backv - call a program and don't wait, returning process id
E 3
 *
 * The command's standard input and output are passed as FILE's.
 */


#define MAXNARGS 100    /* unchecked upper limit on max num of arguments */
#define BADEXEC 127	/* exec fails */

#define ischild(pid)    ((pid) == 0)

/* VARARGS3 */
public int call(name, in, out, args)
String name;
File in;
File out;
String args;
{
    String *ap, *argp;
    String argv[MAXNARGS];

    argp = &argv[0];
    *argp++ = name;
    ap = &args;
    while (*ap != nil(String)) {
	*argp++ = *ap++;
    }
    *argp = nil(String);
    return callv(name, in, out, argv);
}

D 3
/* VARARGS3 */
public int back(name, in, out, args)
String name;
File in;
File out;
String args;
{
    String *ap, *argp;
    String argv[MAXNARGS];

    argp = &argv[0];
    *argp++ = name;
    ap = &args;
    while (*ap != nil(String)) {
	*argp++ = *ap++;
    }
    *argp = nil(String);
    return backv(name, in, out, argv);
}

E 3
public int callv(name, in, out, argv)
String name;
File in;
File out;
String *argv;
{
    int pid, status;

    pid = backv(name, in, out, argv);
    pwait(pid, &status);
    return status;
}

public int backv(name, in, out, argv)
String name;
File in;
File out;
String *argv;
{
    int pid;

    fflush(stdout);
    if (ischild(pid = fork())) {
	fswap(0, fileno(in));
	fswap(1, fileno(out));
D 3
	onsyserr(EACCES, ERR_IGNORE);
E 3
I 3
	(void) onsyserr(EACCES, ERR_IGNORE);
E 3
	execvp(name, argv);
	_exit(BADEXEC);
    }
    return pid;
}

/*
 * Swap file numbers so as to redirect standard input and output.
 */

private fswap(oldfd, newfd)
int oldfd;
int newfd;
{
    if (oldfd != newfd) {
	close(oldfd);
	dup(newfd);
	close(newfd);
    }
}

/*
 * Invoke a shell on a command line.
 */

#define DEF_SHELL	"csh"

public shell(s)
String s;
{
    extern String getenv();
    String sh;

    if ((sh = getenv("SHELL")) == nil(String)) {
	sh = DEF_SHELL;
    }
    call(sh, stdin, stdout, "-c", s, 0);
}

/*
 * Wait for a process the right way.  We wait for a particular
 * process and if any others come along in between, we remember them
 * in case they are eventually waited for.
 *
 * This routine is not very efficient when the number of processes
 * to be remembered is large.
 */

typedef struct pidlist {
    int pid;
    int status;
    struct pidlist *next;
} Pidlist;

private Pidlist *pidlist, *pfind();

public pwait(pid, statusp)
int pid, *statusp;
{
	Pidlist *p;
	int pnum, status;

	p = pfind(pid);
	if (p != nil(Pidlist *)) {
	    *statusp = p->status;
	    dispose(p);
	    return;
	}
	while ((pnum = wait(&status)) != pid && pnum >= 0) {
	    p = alloc(1, Pidlist);
	    p->pid = pnum;
	    p->status = status;
	    p->next = pidlist;
	    pidlist = p;
	}
	if (pnum < 0) {
	    p = pfind(pid);
	    if (p == nil(Pidlist *)) {
		panic("pwait: pid %d not found", pid);
	    }
	    *statusp = p->status;
	    dispose(p);
	} else {
D 3
		*statusp = status;
E 3
I 3
	    *statusp = status;
E 3
	}
I 3
#ifdef tahoe
	chkret(p, status);
#endif
E 3
}

/*
 * Look for the given process id on the pidlist.
 *
 * Unlink it from list if found.
 */

private Pidlist *pfind(pid)
int pid;
{
    register Pidlist *p, *prev;

    prev = nil(Pidlist *);
    for (p = pidlist; p != nil(Pidlist *); p = p->next) {
	if (p->pid == pid) {
	    break;
	}
	prev = p;
    }
    if (p != nil(Pidlist *)) {
	if (prev == nil(Pidlist *)) {
D 3
		pidlist = p->next;
E 3
I 3
	    pidlist = p->next;
E 3
	} else {
D 3
		prev->next = p->next;
E 3
I 3
	    prev->next = p->next;
E 3
	}
    }
    return p;
}

/*
 * System call error handler.
 *
 * The syserr routine is called when a system call is about to
 * set the c-bit to report an error.  Certain errors are caught
 * and cause the process to print a message and immediately exit.
 */

extern int sys_nerr;
extern char *sys_errlist[];
 
/*
 * Before calling syserr, the integer errno is set to contain the
D 3
 * number of the error.  The routine "_mycerror" is a dummy which
 * is used to force the loader to get my version of cerror rather
 * than the usual one.
E 3
I 3
 * number of the error.
E 3
 */

extern int errno;
D 3
extern _mycerror();
E 3

/*
 * default error handling
 */

private ERRINFO errinfo[] ={
/* no error */	ERR_IGNORE,
/* EPERM */	ERR_IGNORE,
/* ENOENT */	ERR_IGNORE,
/* ESRCH */	ERR_IGNORE,
/* EINTR */	ERR_CATCH,
/* EIO */	ERR_CATCH,
/* ENXIO */	ERR_CATCH,
/* E2BIG */	ERR_CATCH,
/* ENOEXEC */	ERR_CATCH,
/* EBADF */	ERR_IGNORE,
/* ECHILD */	ERR_CATCH,
/* EAGAIN */	ERR_CATCH,
/* ENOMEM */	ERR_CATCH,
/* EACCES */	ERR_CATCH,
/* EFAULT */	ERR_CATCH,
/* ENOTBLK */	ERR_CATCH,
/* EBUSY */	ERR_CATCH,
/* EEXIST */	ERR_CATCH,
/* EXDEV */	ERR_CATCH,
/* ENODEV */	ERR_CATCH,
/* ENOTDIR */	ERR_CATCH,
/* EISDIR */	ERR_CATCH,
/* EINVAL */	ERR_CATCH,
/* ENFILE */	ERR_CATCH,
/* EMFILE */	ERR_CATCH,
/* ENOTTY */	ERR_IGNORE,
/* ETXTBSY */	ERR_CATCH,
/* EFBIG */	ERR_CATCH,
/* ENOSPC */	ERR_CATCH,
/* ESPIPE */	ERR_CATCH,
/* EROFS */	ERR_CATCH,
/* EMLINK */	ERR_CATCH,
/* EPIPE */	ERR_CATCH,
/* EDOM */	ERR_CATCH,
/* ERANGE */	ERR_CATCH,
/* EQUOT */	ERR_CATCH,
};

public syserr()
{
    ERRINFO *e;

    e = &errinfo[errno];
    if (e->func == ERR_CATCH) {
	if (errno < sys_nerr) {
	    panic(sys_errlist[errno]);
	} else {
	    panic("errno %d", errno);
	}
    } else if (e->func != ERR_IGNORE) {
	(*e->func)();
    }
}

/*
D 3
 * Catcherrs only purpose is to get this module loaded and make
 * sure my cerror is loaded (only applicable when this is in a library).
 */

public catcherrs()
{
    _mycerror();
}

/*
E 3
 * Change the action on receipt of an error.
 */

D 3
public onsyserr(n, f)
E 3
I 3
public INTFUNC *onsyserr(n, f)
E 3
int n;
INTFUNC *f;
{
I 3
    INTFUNC *g = errinfo[n].func;

E 3
    errinfo[n].func = f;
I 3
    return(g);
E 3
}

/*
D 3
 * Standard error handling routines.
 */

private short nerrs;
private short nwarnings;

/*
E 3
 * Main driver of error message reporting.
 */

/* VARARGS2 */
private errmsg(errname, shouldquit, s, a, b, c, d, e, f, g, h, i, j, k, l, m)
String errname;
Boolean shouldquit;
String s;
{
    fflush(stdout);
    if (shouldquit and cmdname != nil(String)) {
	fprintf(stderr, "%s: ", cmdname);
    }
    if (errfilename != nil(Filename)) {
	fprintf(stderr, "%s: ", errfilename);
    }
    if (errlineno > 0) {
	fprintf(stderr, "%d: ", errlineno);
    }
    if (errname != nil(String)) {
	fprintf(stderr, "%s: ", errname);
    }
    fprintf(stderr, s, a, b, c, d, e, f, g, h, i, j, k, l, m);
    putc('\n', stderr);
    if (shouldquit) {
	quit(1);
    }
}

/*
D 3
 * The messages are listed in increasing order of seriousness.
 *
 * First are warnings.
 */

/* VARARGS1 */
public warning(s, a, b, c, d, e, f, g, h, i, j, k, l, m)
String s;
{
    nwarnings++;
    errmsg("warning", FALSE, s, a, b, c, d, e, f, g, h, i, j, k, l, m);
}

/*
E 3
 * Errors are a little worse, they mean something is wrong,
 * but not so bad that processing can't continue.
 *
 * The routine "erecover" is called to recover from the error,
 * a default routine is provided that does nothing.
 */

/* VARARGS1 */
public error(s, a, b, c, d, e, f, g, h, i, j, k, l, m)
String s;
{
    extern erecover();

D 3
    nerrs++;
E 3
    errmsg(nil(String), FALSE, s, a, b, c, d, e, f, g, h, i, j, k, l, m);
    erecover();
}

/*
 * Non-recoverable user error.
 */

/* VARARGS1 */
public fatal(s, a, b, c, d, e, f, g, h, i, j, k, l, m)
String s;
{
    errmsg("fatal error", TRUE, s, a, b, c, d, e, f, g, h, i, j, k, l, m);
}

/*
 * Panics indicate an internal program error.
 */

/* VARARGS1 */
public panic(s, a, b, c, d, e, f, g, h, i, j, k, l, m)
String s;
{
    errmsg("panic", TRUE, s, a, b, c, d, e, f, g, h, i, j, k, l, m);
}

D 3
short numerrors()
{
    short r;

    r = nerrs;
    nerrs = 0;
    return r;
}

short numwarnings()
{
    short r;

    r = nwarnings;
    nwarnings = 0;
    return r;
}

E 3
/*
D 3
 * Recover from an error.
 *
 * This is the default routine which we aren't using since we have our own.
 *
public erecover()
{
}
 *
 */

/*
 * Default way to quit from a program is just to exit.
 *
public quit(r)
int r;
{
    exit(r);
}
 *
 */

/*
E 3
 * Compare n-byte areas pointed to by s1 and s2
 * if n is 0 then compare up until one has a null byte.
 */

public int cmp(s1, s2, n)
register char *s1, *s2;
register unsigned int n;
{
    if (s1 == nil(char *) || s2 == nil(char *)) {
	panic("cmp: nil pointer");
    }
    if (n == 0) {
	while (*s1 == *s2++) {
	    if (*s1++ == '\0') {
		return(0);
	    }
	}
	return(*s1 - *(s2-1));
    } else {
	for (; n != 0; n--) {
	    if (*s1++ != *s2++) {
		return(*(s1-1) - *(s2-1));
	    }
	}
	return(0);
    }
}

/*
 * Move n bytes from src to dest.
 * If n is 0 move until a null is found.
 */

public mov(src, dest, n)
register char *src, *dest;
D 3
register unsigned int n;
E 3
I 3
register int n;
E 3
{
D 3
    if (src == nil(char *))
E 3
I 3
    if (src == nil(char *)) {
E 3
	panic("mov: nil source");
D 3
    if (dest == nil(char *))
E 3
I 3
    }
    if (dest == nil(char *)) {
E 3
	panic("mov: nil destination");
I 3
    }
E 3
    if (n > 0) {
	for (; n != 0; n--) {
	    *dest++ = *src++;
	}
    } else {
	while ((*dest++ = *src++) != '\0');
    }
}
E 1
