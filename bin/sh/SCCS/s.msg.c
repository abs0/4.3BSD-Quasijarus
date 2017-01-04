h11464
s 00003/00003/00153
d D 4.5 87/01/11 15:01:40 sam 5 4
c purge old style initializations (from casey)
e
s 00002/00002/00154
d D 4.4 85/05/22 19:32:07 mckusick 4 3
c add SIGUSR1 and SIGUSR2
e
s 00018/00001/00138
d D 4.3 85/03/19 18:49:52 mckusick 3 2
c add the rest of the signals
e
s 00003/00001/00136
d D 4.2 83/08/11 20:19:47 sam 2 1
c standardize sccs keyword lines
e
s 00137/00000/00000
d D 4.1 82/05/07 19:38:22 mckusick 1 0
c date and time created 82/05/07 19:38:22 by mckusick
e
u
U
t
T
I 1
D 2
/*	%M%	%I%	%E%	*/
E 2
I 2
#ifndef lint
static char sccsid[] = "%W% %G%";
#endif
E 2

#
/*
 *	UNIX shell
 *
 *	S. R. Bourne
 *	Bell Telephone Laboratories
 *
 */


#include	"defs.h"
#include	"sym.h"

MSG		version = "\nVERSION sys137	DATE 1978 Nov 6 14:29:22\n";

/* error messages */
MSG	badopt		= "bad option(s)";
MSG	mailmsg		= "you have mail\n";
MSG	nospace		= "no space";
MSG	synmsg		= "syntax error";

MSG	badnum		= "bad number";
MSG	badparam	= "parameter not set";
MSG	badsub		= "bad substitution";
MSG	badcreate	= "cannot create";
MSG	illegal		= "illegal io";
MSG	restricted	= "restricted";
MSG	piperr		= "cannot make pipe";
MSG	badopen		= "cannot open";
MSG	coredump	= " - core dumped";
MSG	arglist		= "arg list too long";
MSG	txtbsy		= "text busy";
MSG	toobig		= "too big";
MSG	badexec		= "cannot execute";
MSG	notfound	= "not found";
MSG	badfile		= "bad file number";
MSG	badshift	= "cannot shift";
MSG	baddir		= "bad directory";
MSG	badtrap		= "bad trap";
MSG	wtfailed	= "is read only";
MSG	notid		= "is not an identifier";

/* built in names */
MSG	pathname	= "PATH";
MSG	homename	= "HOME";
MSG	mailname	= "MAIL";
MSG	fngname		= "FILEMATCH";
MSG	ifsname		= "IFS";
MSG	ps1name		= "PS1";
MSG	ps2name		= "PS2";

/* string constants */
MSG	nullstr		= "";
MSG	sptbnl		= " \t\n";
MSG	defpath		= ":/bin:/usr/bin";
MSG	colon		= ": ";
MSG	minus		= "-";
MSG	endoffile	= "end of file";
MSG	unexpected 	= " unexpected";
MSG	atline		= " at line ";
MSG	devnull		= "/dev/null";
MSG	execpmsg	= "+ ";
MSG	readmsg		= "> ";
MSG	stdprompt	= "$ ";
MSG	supprompt	= "# ";
MSG	profile		= ".profile";


/* tables */
D 5
SYSTAB reserved {
E 5
I 5
SYSTAB reserved = {
E 5
		{"in",		INSYM},
		{"esac",	ESSYM},
		{"case",	CASYM},
		{"for",		FORSYM},
		{"done",	ODSYM},
		{"if",		IFSYM},
		{"while",	WHSYM},
		{"do",		DOSYM},
		{"then",	THSYM},
		{"else",	ELSYM},
		{"elif",	EFSYM},
		{"fi",		FISYM},
		{"until",	UNSYM},
		{ "{",		BRSYM},
		{ "}",		KTSYM},
		{0,	0},
};

D 5
STRING	sysmsg[] {
E 5
I 5
STRING	sysmsg[] = {
E 5
		0,
		"Hangup",
		0,	/* Interrupt */
		"Quit",
		"Illegal instruction",
		"Trace/BPT trap",
		"IOT trap",
		"EMT trap",
		"Floating exception",
		"Killed",
		"Bus error",
		"Memory fault",
		"Bad system call",
		0,	/* Broken pipe */
		"Alarm call",
		"Terminated",
D 3
		"Signal 16",
E 3
I 3
		"Urgent condition",
		"Stopped",
		"Stopped from terminal",
		"Continued",
		"Child terminated",
		"Stopped on terminal input",
		"Stopped on terminal output",
		"Asynchronous I/O",
		"Exceeded cpu time limit",
		"Exceeded file size limit",
		"Virtual time alarm",
		"Profiling time alarm",
		"Window changed",
		"Signal 29",
D 4
		"Signal 30",
		"Signal 31",
E 4
I 4
		"User defined signal 1",
		"User defined signal 2",
E 4
		"Signal 32",
E 3
};
I 3
INT		num_sysmsg = (sizeof sysmsg / sizeof sysmsg[0]);
E 3

MSG		export = "export";
MSG		readonly = "readonly";
D 5
SYSTAB	commands {
E 5
I 5
SYSTAB	commands = {
E 5
		{"cd",		SYSCD},
		{"read",	SYSREAD},
/*
		{"[",		SYSTST},
*/
		{"set",		SYSSET},
		{":",		SYSNULL},
		{"trap",	SYSTRAP},
		{"login",	SYSLOGIN},
		{"wait",	SYSWAIT},
		{"eval",	SYSEVAL},
		{".",		SYSDOT},
		{readonly,	SYSRDONLY},
		{export,	SYSXPORT},
		{"chdir",	SYSCD},
		{"break",	SYSBREAK},
		{"continue",	SYSCONT},
		{"shift",	SYSSHFT},
		{"exit",	SYSEXIT},
		{"exec",	SYSEXEC},
		{"times",	SYSTIMES},
		{"umask",	SYSUMASK},
		{0,	0},
};
E 1
