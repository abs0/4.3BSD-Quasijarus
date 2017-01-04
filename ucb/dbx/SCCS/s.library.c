h58444
s 00097/00014/00650
d D 5.2 88/01/12 00:44:58 donn 10 9
c merge in latest Linton version
e
s 00008/00002/00656
d D 5.1 85/05/31 10:01:41 dist 9 8
c Add copyright
e
s 00001/00029/00657
d D 1.7 85/03/28 13:35:39 ralph 8 7
c remove local copy of sys_siglist.
e
s 00016/00000/00670
d D 1.6 85/03/01 20:24:11 linton 7 6
c update to version 3.0
e
s 00001/00003/00669
d D 1.5 84/06/23 11:41:03 sam 6 4
i 5
c merge linton branch delta trail
e
s 00058/00076/00614
d D 1.4.1.1 84/06/23 10:46:51 sam 5 4
c branch delta of linton changes from net.sources
e
s 00004/00002/00686
d D 1.4 83/08/13 15:38:54 sam 4 3
c standardize sccs keyword lines
e
s 00070/00018/00618
d D 1.3 83/08/07 18:22:37 linton 3 2
c modified pwait to ignore spurious returns from wait which refer 
c to ptraced processes, such processes are indicated through a call to 
c "ptraced(pid)" and removed from this special list with "unptraced(pid)"
e
s 00024/00024/00612
d D 1.2 83/08/07 16:48:46 linton 2 1
c formatting, pwait error handling
e
s 00636/00000/00000
d D 1.1 82/12/15 04:07:41 linton 1 0
c date and time created 82/12/15 04:07:41 by linton
e
u
U
f b 
t
T
I 1
D 4
/* Copyright (c) 1982 Regents of the University of California */
E 4
I 4
D 5
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif
E 4

E 5
D 2
/* static char sccsid[] = "@(#)library.c 1.1 9/2/82"; */
E 2
I 2
D 4
static char sccsid[] = "%Z%%M% %I% %G%";
E 4
I 4
D 9
/* Copyright (c) 1982 Regents of the University of California */
E 9
I 9
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 9
E 4
E 2

I 5
D 6
static char sccsid[] = "@(#)library.c 1.3 8/7/83";

static char rcsid[] = "$Header: library.c,v 1.3 84/03/27 10:21:12 linton Exp $";
E 6
I 6
D 9
static	char sccsid[] = "%W% (Berkeley) %G%";
E 9
I 9
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 9
E 6

I 7
D 10
static char rcsid[] = "$Header: library.c,v 1.5 84/12/26 10:39:52 linton Exp $";
E 10
I 10
static char rcsid[] = "$Header: library.c,v 1.2 87/03/25 20:50:14 donn Exp $";
E 10

E 7
E 5
/*
 * General purpose routines.
 */

#include <stdio.h>
#include <errno.h>
#include <signal.h>

#define public
#define private static
#define and &&
#define or ||
#define not !
#define ord(enumcon)	((int) enumcon)
#define nil(type)	((type) 0)

D 5
typedef enum { FALSE, TRUE } Boolean;
E 5
I 5
typedef int integer;
typedef enum { FALSE, TRUE } boolean;
E 5
typedef char *String;
typedef FILE *File;
typedef String Filename;

#undef FILE

D 5
/*
 * Definitions of standard C library routines that aren't in the
 * standard I/O library, but which are generally useful.
 */

extern long atol();		/* ascii to long */
extern double atof();		/* ascii to floating point */
extern char *mktemp();		/* make a temporary file name */

E 5
String cmdname;			/* name of command for error messages */
Filename errfilename;		/* current file associated with error */
short errlineno;		/* line number associated with error */

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

D 10
typedef int INTFUNC();
E 10
I 10
typedef int IntFunc();
E 10

I 10
IntFunc *onsyserr();

E 10
typedef struct {
D 10
    INTFUNC *func;
} ERRINFO;
E 10
I 10
    IntFunc *func;
} ErrInfo;
E 10

D 10
#define ERR_IGNORE ((INTFUNC *) 0)
#define ERR_CATCH  ((INTFUNC *) 1)
E 10
I 10
#define ERR_IGNORE ((IntFunc *) 0)
#define ERR_CATCH  ((IntFunc *) 1)
E 10

/*
 * Call a program.
 *
 * Four entries:
 *
 *	call, callv - call a program and wait for it, returning status
 *	back, backv - call a program and don't wait, returning process id
 *
 * The command's standard input and output are passed as FILE's.
 */


D 5
#define MAXNARGS 100    /* unchecked upper limit on max num of arguments */
E 5
I 5
#define MAXNARGS 1000    /* unchecked upper limit on max num of arguments */
E 5
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
	onsyserr(EACCES, ERR_IGNORE);
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
    if (s != nil(String) and *s != '\0') {
	call(sh, stdin, stdout, "-c", s, 0);
    } else {
	call(sh, stdin, stdout, 0);
    }
}

/*
 * Wait for a process the right way.  We wait for a particular
 * process and if any others come along in between, we remember them
 * in case they are eventually waited for.
 *
 * This routine is not very efficient when the number of processes
 * to be remembered is large.
I 3
 *
 * To deal with a kernel idiosyncrasy, we keep a list on the side
 * of "traced" processes, and do not notice them when waiting for
 * another process.
E 3
 */

typedef struct pidlist {
    int pid;
    int status;
    struct pidlist *next;
} Pidlist;

D 3
private Pidlist *pidlist, *pfind();
E 3
I 3
private Pidlist *pidlist, *ptrclist, *pfind();
E 3

I 3
public ptraced(pid)
int pid;
{
    Pidlist *p;

    p = alloc(1, Pidlist);
    p->pid = pid;
    p->next = ptrclist;
    ptrclist = p;
}

public unptraced(pid)
int pid;
{
    register Pidlist *p, *prev;

    prev = nil(Pidlist *);
    p = ptrclist;
    while (p != nil(Pidlist *) and p->pid != pid) {
	prev = p;
	p = p->next;
    }
    if (p != nil(Pidlist *)) {
	if (prev == nil(Pidlist *)) {
	    ptrclist = p->next;
	} else {
	    prev->next = p->next;
	}
	dispose(p);
    }
}

D 5
private Boolean isptraced(pid)
E 5
I 5
private boolean isptraced(pid)
E 5
int pid;
{
    register Pidlist *p;

    p = ptrclist;
    while (p != nil(Pidlist *) and p->pid != pid) {
	p = p->next;
    }
D 5
    return (Boolean) (p != nil(Pidlist *));
E 5
I 5
    return (boolean) (p != nil(Pidlist *));
E 5
}

E 3
public pwait(pid, statusp)
int pid, *statusp;
{
D 2
	Pidlist *p;
	int pnum, status;
E 2
I 2
    Pidlist *p;
    int pnum, status;
E 2

I 2
    p = pfind(pid);
    if (p != nil(Pidlist *)) {
	*statusp = p->status;
	dispose(p);
D 3
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
E 2
	p = pfind(pid);
D 2
	if (p != nil(Pidlist *)) {
	    *statusp = p->status;
	    dispose(p);
	    return;
E 2
I 2
	if (p == nil(Pidlist *)) {
	    panic("pwait: pid %d not found", pid);
E 2
	}
D 2
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
		*statusp = status;
	}
E 2
I 2
	*statusp = p->status;
	dispose(p);
E 3
    } else {
D 3
	*statusp = status;
E 3
I 3
	pnum = wait(&status);
	while (pnum != pid and pnum >= 0) {
	    if (not isptraced(pnum)) {
		p = alloc(1, Pidlist);
		p->pid = pnum;
		p->status = status;
		p->next = pidlist;
		pidlist = p;
	    }
	    pnum = wait(&status);
	}
	if (pnum < 0) {
	    p = pfind(pid);
	    if (p == nil(Pidlist *)) {
		panic("pwait: pid %d not found", pid);
	    }
	    *statusp = p->status;
	    dispose(p);
	} else {
	    *statusp = status;
	}
E 3
    }
E 2
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
	    pidlist = p->next;
	} else {
	    prev->next = p->next;
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
 * number of the error.  The routine "_mycerror" is a dummy which
 * is used to force the loader to get my version of cerror rather
 * than the usual one.
 */

extern int errno;
extern _mycerror();

/*
D 5
 * Default error handling.
E 5
I 5
 * Initialize error information, setting defaults for handling errors.
E 5
 */

D 5
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
E 5
I 5
D 10
private ERRINFO *errinfo;
E 10
I 10
private ErrInfo *errinfo;
E 10
E 5

I 5
private initErrInfo ()
{
    integer i;

D 10
    errinfo = alloc(sys_nerr, ERRINFO);
E 10
I 10
    errinfo = alloc(sys_nerr, ErrInfo);
E 10
    for (i = 0; i < sys_nerr; i++) {
	errinfo[i].func = ERR_CATCH;
    }
    errinfo[0].func = ERR_IGNORE;
    errinfo[EPERM].func = ERR_IGNORE;
    errinfo[ENOENT].func = ERR_IGNORE;
    errinfo[ESRCH].func = ERR_IGNORE;
    errinfo[EBADF].func = ERR_IGNORE;
    errinfo[ENOTTY].func = ERR_IGNORE;
    errinfo[EOPNOTSUPP].func = ERR_IGNORE;
}

E 5
public syserr()
{
D 10
    ERRINFO *e;
E 10
I 10
    register ErrInfo *e;
E 10

D 5
    e = &errinfo[errno];
    if (e->func == ERR_CATCH) {
	if (errno < sys_nerr) {
E 5
I 5
    if (errno < 0 or errno > sys_nerr) {
	fatal("errno %d", errno);
    } else {
D 10
	if (errinfo == nil(ERRINFO *)) {
E 10
I 10
	if (errinfo == nil(ErrInfo *)) {
E 10
	    initErrInfo();
	}
	e = &(errinfo[errno]);
	if (e->func == ERR_CATCH) {
E 5
	    fatal(sys_errlist[errno]);
D 5
	} else {
	    fatal("errno %d", errno);
E 5
I 5
	} else if (e->func != ERR_IGNORE) {
	    (*e->func)();
E 5
	}
D 5
    } else if (e->func != ERR_IGNORE) {
	(*e->func)();
E 5
    }
}

/*
D 5
 * Catcherrs only purpose is to get this module loaded and make
 * sure my cerror is loaded (only applicable when this is in a library).
E 5
I 5
 * Catcherrs' purpose is to initialize the errinfo table, get this module
 * loaded, and make sure my cerror is loaded (only applicable when this is
 * in a library).
E 5
 */

public catcherrs()
{
    _mycerror();
I 5
    initErrInfo();
I 7
}

/*
 * Turn off the error catching mechanism completely by having all errors
 * ignored.  This is most useful between a fork and an exec.
 */

public nocatcherrs()
{
    integer i;

    for (i = 0; i < sys_nerr; i++) {
	errinfo[i].func = ERR_IGNORE;
    }
E 7
E 5
}

/*
D 10
 * Change the action on receipt of an error.
E 10
I 10
 * Change the action on receipt of an error, returning the previous action.
E 10
 */

D 10
public onsyserr(n, f)
E 10
I 10
public IntFunc *onsyserr(n, f)
E 10
int n;
D 10
INTFUNC *f;
E 10
I 10
IntFunc *f;
E 10
{
I 5
D 10
    if (errinfo == nil(ERRINFO *)) {
E 10
I 10
    IntFunc *oldf;

    if (errinfo == nil(ErrInfo *)) {
E 10
	initErrInfo();
    }
I 10
    oldf = errinfo[n].func;
E 10
E 5
    errinfo[n].func = f;
I 10
    return oldf;
E 10
}

/*
 * Print the message associated with the given signal.
 * Like a "perror" for signals.
 */

I 10
#ifdef SIGWINCH
E 10
public int sys_nsig = NSIG;
I 10
#else not 4.3 BSD
/*
 * This table is correct for 4.2-like systems but will
 * be inadequate for System V (which is the sort of
 * Unix that needs it!).
 */
public String sys_siglist[] = {
    "no signal",
    "hangup",
    "interrupt",
    "quit",
    "illegal instruction",
    "trace trap",
    "IOT instruction",
    "EMT instruction",
    "floating point exception",
    "kill",
    "bus error",
    "segmentation violation",
    "bad argument to system call",
    "broken pipe",
    "alarm clock",
    "soft kill",
    "urgent I/O condition",
    "stop signal not from tty",
    "stop signal from tty",
    "continue",
    "child termination",
    "stop (tty input)",
    "stop (tty output)",
    "possible input/output",
    "exceeded CPU time limit",
    "exceeded file size limit"
};
public int sys_nsig = sizeof sys_siglist / sizeof sys_siglist[0];
#endif
E 10
D 8
public String sys_siglist[] = {
    "no signal",
    "hangup",
    "interrupt",
    "quit",
    "illegal instruction",
    "trace trap",
    "IOT instruction",
    "EMT instruction",
    "floating point exception",
    "kill",
    "bus error",
    "segmentation violation",
    "bad argument to system call",
    "broken pipe",
    "alarm clock",
    "soft kill",
    "urgent I/O condition",
    "stop signal not from tty",
    "stop signal from tty",
    "continue",
    "child termination",
    "stop (tty input)",
    "stop (tty output)",
    "possible input/output",
    "exceeded CPU time limit",
    "exceeded file size limit",
    nil(String)
};
E 8

D 5
public psig(s)
E 5
I 5
public psignal(s, n)
E 5
String s;
I 5
integer n;
E 5
{
D 5
    String c;
    int n;
E 5
I 5
    String msg;
    integer len;
I 8
    extern String sys_siglist[];
E 8
E 5

D 5
    c = "Unknown signal";
    if (errno < sys_nsig) {
	c = sys_errlist[errno];
E 5
I 5
    if (n >= 0 and n < sys_nsig) {
	msg = sys_siglist[n];
    } else {
	msg = "Unknown signal";
E 5
    }
D 5
    n = strlen(s);
    if (n > 0) {
	write(2, s, n);
E 5
I 5
    len = strlen(s);
    if (len > 0) {
	write(2, s, len);
E 5
	write(2, ": ", 2);
    }
D 5
    write(2, c, strlen(c));
E 5
I 5
    write(2, msg, strlen(msg));
E 5
    write(2, "\n", 1);
}

/*
 * Standard error handling routines.
 */

private short nerrs;
private short nwarnings;

/*
 * Main driver of error message reporting.
 */

/* VARARGS2 */
private errmsg(errname, shouldquit, s, a, b, c, d, e, f, g, h, i, j, k, l, m)
String errname;
D 5
Boolean shouldquit;
E 5
I 5
boolean shouldquit;
E 5
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
I 10
    fflush(stderr);
E 10
    if (shouldquit) {
	quit(1);
    }
}

/*
 * For when printf isn't sufficient for printing the error message ...
 */

public beginerrmsg()
{
    fflush(stdout);
    if (errfilename != nil(String)) {
	fprintf(stderr, "%s: ", errfilename);
    }
    if (errlineno > 0) {
	fprintf(stderr, "%d: ", errlineno);
    }
}

public enderrmsg()
{
    putc('\n', stderr);
I 10
    fflush(stderr);
E 10
    erecover();
}

/*
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

    nerrs++;
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
    errmsg("internal error", TRUE, s, a, b, c, d, e, f, g, h, i, j, k, l, m);
}

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

/*
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
register unsigned int n;
{
    if (src == nil(char *))
	panic("mov: nil source");
    if (dest == nil(char *))
	panic("mov: nil destination");
    if (n != 0) {
	for (; n != 0; n--) {
	    *dest++ = *src++;
	}
    } else {
	while ((*dest++ = *src++) != '\0');
    }
}
I 10

#ifdef IRIS /* or in general for 4.2 - System V C library interface */

public bcopy (fromaddr, toaddr, n)
char *fromaddr, *toaddr;
int n;
{
    blt(toaddr, fromaddr, n);
}

public bzero (addr, n)
char *addr;
int n;
{
    register char *p, *q;

    p = addr;
    q = p + n;
    while (p < q) {
	*p++ = '\0';
    }
}

#include <string.h>

public char *index (s, c)
char *s, c;
{
    return strchr(s, c);
}

public char *rindex (s, c)
char *s, c;
{
    return strrchr(s, c);
}

#endif
E 10
E 1
