h43181
s 00010/00005/00147
d D 5.6 88/06/29 20:34:14 bostic 14 13
c install approved copyright notice
e
s 00009/00003/00143
d D 5.5 88/03/14 17:21:29 bostic 13 12
c add Berkeley specific headers
e
s 00001/00000/00145
d D 5.4 87/05/22 11:38:27 bostic 12 11
c add image as alias for binary
e
s 00074/00048/00071
d D 5.3 86/02/03 14:41:01 minshall 11 10
c Changes from Steve Jacobson (from <csvsj@ucbopal>).
e
s 00001/00000/00118
d D 5.2 86/01/13 17:58:18 karels 10 9
c add disconnect alias for close (as help message points at it)
e
s 00007/00001/00111
d D 5.1 85/05/31 16:59:30 dist 9 8
c Add copyright
e
s 00001/00001/00111
d D 4.8 85/03/11 13:31:43 ralph 8 7
c minor fixes from ut-sally
e
s 00001/00003/00111
d D 4.7 83/07/26 21:34:09 sam 7 6
c linger purge
e
s 00003/00001/00111
d D 4.6 83/06/19 23:08:13 sam 6 5
c fix m* cmds and add linger control
e
s 00006/00002/00106
d D 4.5 83/03/29 11:25:00 sam 5 4
c from jsq@utexas-11 (mls, mdir and random cleanups after me)
e
s 00053/00043/00055
d D 4.4 83/03/23 10:26:11 sam 4 3
c merge of changes from jsq@utexas-11
e
s 00011/00005/00087
d D 4.3 83/03/01 02:12:20 sam 3 2
c add mget, mput, and glob to control the first two
e
s 00001/00001/00091
d D 4.2 83/01/15 17:20:53 sam 2 1
c connect -> open
e
s 00092/00000/00000
d D 4.1 83/01/15 16:52:37 sam 1 0
c date and time created 83/01/15 16:52:37 by sam
e
u
U
f b 
t
T
I 9
/*
D 11
 * Copyright (c) 1980 Regents of the University of California.
E 11
I 11
 * Copyright (c) 1985 Regents of the University of California.
E 11
D 13
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 13
I 13
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 14
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 14
I 14
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
E 14
E 13
 */

E 9
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 9
#endif
E 9
I 9
D 13
#endif not lint
E 13
I 13
#endif /* not lint */
E 13
E 9
I 4

E 4
#include "ftp_var.h"

/*
 * User FTP -- Command Tables.
 */
int	setascii(), setbell(), setbinary(), setdebug(), setform();
D 3
int	setmode(), setpeer(), setprompt(), setstruct(), settenex();
int	settrace(), settype(), setverbose();
E 3
I 3
D 4
int	setglob(), setmode(), setpeer(), setprompt(), setstruct();
E 4
I 4
D 6
int	setglob(), sethash(), setmode(), setpeer(), setport ();
E 6
I 6
D 7
int	setglob(), sethash(), setlinger(), setmode(), setpeer(), setport();
E 7
I 7
int	setglob(), sethash(), setmode(), setpeer(), setport();
E 7
E 6
int	setprompt(), setstruct();
E 4
int	settenex(), settrace(), settype(), setverbose();
E 3
int	disconnect();
D 4
int	cd(), lcd(), delete(), user();
D 3
int	ls(), get(), help(), put();
E 3
I 3
int	ls(), get(), mget(), help(), put(), mput();
E 4
I 4
int	cd(), lcd(), delete(), mdelete(), user();
D 5
int	ls(), get(), mget(), help(), append(), put(), mput();
E 5
I 5
int	ls(), mls(), get(), mget(), help(), append(), put(), mput();
E 5
E 4
E 3
int	quit(), renamefile(), status();
int	quote(), rmthelp(), shell();
D 11
int	pwd(), makedir(), removedir();
E 11
I 11
int	pwd(), makedir(), removedir(), setcr();
int	account(), doproxy(), reset(), setcase(), setntrans(), setnmap();
int	setsunique(), setrunique(), cdup(), macdef(), domacro();
E 11

I 11
char	accounthelp[] =	"send account command to remote server";
E 11
I 4
char	appendhelp[] =	"append to a file";
E 4
char	asciihelp[] =	"set ascii transfer type";
char	beephelp[] =	"beep when command completed";
char	binaryhelp[] =	"set binary transfer type";
I 11
char	casehelp[] =	"toggle mget upper/lower case id mapping";
E 11
char	cdhelp[] =	"change remote working directory";
I 11
char	cduphelp[] = 	"change remote working directory to parent directory";
E 11
char	connecthelp[] =	"connect to remote tftp";
I 11
char	crhelp[] =	"toggle carriage return stripping on ascii gets";
E 11
char	deletehelp[] =	"delete remote file";
char	debughelp[] =	"toggle/set debugging mode";
char	dirhelp[] =	"list contents of remote directory";
char	disconhelp[] =	"terminate ftp session";
I 11
char	domachelp[] = 	"execute macro";
E 11
char	formhelp[] =	"set file transfer format";
I 3
char	globhelp[] =	"toggle metacharacter expansion of local file names";
I 4
char	hashhelp[] =	"toggle printing `#' for each buffer transferred";
E 4
E 3
char	helphelp[] =	"print local help information";
char	lcdhelp[] =	"change local working directory";
I 6
D 7
char	lingerhelp[] =	"wait for other side when closing data connections";
E 7
E 6
char	lshelp[] =	"nlist contents of remote directory";
I 11
char	macdefhelp[] =  "define a macro";
E 11
I 4
char	mdeletehelp[] =	"delete multiple files";
I 5
char	mdirhelp[] =	"list contents of multiple remote directories";
E 5
E 4
I 3
char	mgethelp[] =	"get multiple files";
E 3
char	mkdirhelp[] =	"make directory on the remote machine";
I 5
char	mlshelp[] =	"nlist contents of multiple remote directories";
E 5
char	modehelp[] =	"set file transfer mode";
I 3
char	mputhelp[] =	"send multiple files";
I 11
char	nmaphelp[] =	"set templates for default file name mapping";
char	ntranshelp[] =	"set translation table for default file name mapping";
E 11
I 4
char	porthelp[] =	"toggle use of PORT cmd for each data connection";
E 4
E 3
char	prompthelp[] =	"force interactive prompting on multiple commands";
I 11
char	proxyhelp[] =	"issue command on alternate connection";
E 11
char	pwdhelp[] =	"print working directory on remote machine";
char	quithelp[] =	"terminate ftp session and exit";
char	quotehelp[] =	"send arbitrary ftp command";
char	receivehelp[] =	"receive file";
char	remotehelp[] =	"get help from remote server";
char	renamehelp[] =	"rename file";
char	rmdirhelp[] =	"remove directory on the remote machine";
I 11
char	runiquehelp[] = "toggle store unique for local files";
char	resethelp[] =	"clear queued command replies";
E 11
D 3
char	sendhelp[] =	"send file";
E 3
I 3
char	sendhelp[] =	"send one file";
E 3
char	shellhelp[] =	"escape to the shell";
char	statushelp[] =	"show current status";
char	structhelp[] =	"set file transfer structure";
I 11
char	suniquehelp[] = "toggle store unique on remote machine";
E 11
char	tenexhelp[] =	"set tenex file transfer type";
char	tracehelp[] =	"toggle packet tracing";
char	typehelp[] =	"set file transfer type";
char	userhelp[] =	"send new user information";
char	verbosehelp[] =	"toggle verbose mode";

struct cmd cmdtab[] = {
D 4
	{ "!",		shellhelp,	0,	shell },
	{ "ascii",	asciihelp,	0,	setascii },
	{ "bell",	beephelp,	0,	setbell },
	{ "binary",	binaryhelp,	0,	setbinary },
	{ "bye",	quithelp,	0,	quit },
	{ "cd",		cdhelp,		0,	cd },
	{ "close",	disconhelp,	0,	disconnect },
D 2
	{ "connect",	connecthelp,	0,	setpeer },
E 2
	{ "delete",	deletehelp,	0,	delete },
	{ "debug",	debughelp,	0,	setdebug },
	{ "dir",	dirhelp,	1,	ls },
	{ "form",	formhelp,	0,	setform },
	{ "get",	receivehelp,	1,	get },
I 3
	{ "glob",	globhelp,	0,	setglob },
E 3
	{ "help",	helphelp,	0,	help },
	{ "lcd",	lcdhelp,	0,	lcd },
	{ "ls",		lshelp,		1,	ls },
D 3
	{ "mode",	modehelp,	0,	setmode },
E 3
I 3
	{ "mget",	mgethelp,	1,	mget },
E 3
	{ "mkdir",	mkdirhelp,	0,	makedir },
I 3
	{ "mode",	modehelp,	0,	setmode },
	{ "mput",	mputhelp,	1,	mput },
E 3
I 2
	{ "open",	connecthelp,	0,	setpeer },
E 2
	{ "prompt",	prompthelp,	0,	setprompt },
	{ "put",	sendhelp,	1,	put },
	{ "pwd",	pwdhelp,	0,	pwd },
	{ "quit",	quithelp,	0,	quit },
	{ "quote",	quotehelp,	1,	quote },
	{ "recv",	receivehelp,	1,	get },
	{ "remotehelp",	remotehelp,	0,	rmthelp },
	{ "rename",	renamehelp,	0,	renamefile },
	{ "rmdir",	rmdirhelp,	0,	removedir },
	{ "send",	sendhelp,	1,	put },
	{ "status",	statushelp,	0,	status },
	{ "struct",	structhelp,	0,	setstruct },
	{ "tenex",	tenexhelp,	0,	settenex },
	{ "trace",	tracehelp,	0,	settrace },
	{ "type",	typehelp,	0,	settype },
	{ "user",	userhelp,	0,	user },
	{ "verbose",	verbosehelp,	0,	setverbose },
	{ "?",		helphelp,	0,	help },
	0
E 4
I 4
D 11
	{ "!",		shellhelp,	0,	0,	shell },
D 5
	{ "append",	appendhelp,	1,	1,	append },
E 5
I 5
	{ "append",	appendhelp,	1,	1,	put },
E 5
	{ "ascii",	asciihelp,	0,	1,	setascii },
	{ "bell",	beephelp,	0,	0,	setbell },
	{ "binary",	binaryhelp,	0,	1,	setbinary },
	{ "bye",	quithelp,	0,	0,	quit },
	{ "cd",		cdhelp,		0,	1,	cd },
	{ "close",	disconhelp,	0,	1,	disconnect },
	{ "delete",	deletehelp,	0,	1,	delete },
	{ "debug",	debughelp,	0,	0,	setdebug },
	{ "dir",	dirhelp,	1,	1,	ls },
I 10
	{ "disconnect",	disconhelp,	0,	1,	disconnect },
E 10
	{ "form",	formhelp,	0,	1,	setform },
	{ "get",	receivehelp,	1,	1,	get },
	{ "glob",	globhelp,	0,	0,	setglob },
	{ "hash",	hashhelp,	0,	0,	sethash },
	{ "help",	helphelp,	0,	0,	help },
	{ "lcd",	lcdhelp,	0,	0,	lcd },
I 6
D 7
	{ "linger",	lingerhelp,	0,	0,	setlinger },
E 7
E 6
	{ "ls",		lshelp,		1,	1,	ls },
	{ "mdelete",	mdeletehelp,	1,	1,	mdelete },
I 5
	{ "mdir",	mdirhelp,	1,	1,	mls },
E 5
	{ "mget",	mgethelp,	1,	1,	mget },
	{ "mkdir",	mkdirhelp,	0,	1,	makedir },
I 5
	{ "mls",	mlshelp,	1,	1,	mls },
E 5
	{ "mode",	modehelp,	0,	1,	setmode },
	{ "mput",	mputhelp,	1,	1,	mput },
	{ "open",	connecthelp,	0,	0,	setpeer },
	{ "prompt",	prompthelp,	0,	0,	setprompt },
	{ "sendport",	porthelp,	0,	0,	setport },
	{ "put",	sendhelp,	1,	1,	put },
	{ "pwd",	pwdhelp,	0,	1,	pwd },
	{ "quit",	quithelp,	0,	0,	quit },
	{ "quote",	quotehelp,	1,	1,	quote },
	{ "recv",	receivehelp,	1,	1,	get },
	{ "remotehelp",	remotehelp,	0,	1,	rmthelp },
	{ "rename",	renamehelp,	0,	1,	renamefile },
	{ "rmdir",	rmdirhelp,	0,	1,	removedir },
	{ "send",	sendhelp,	1,	1,	put },
	{ "status",	statushelp,	0,	0,	status },
	{ "struct",	structhelp,	0,	1,	setstruct },
	{ "tenex",	tenexhelp,	0,	1,	settenex },
	{ "trace",	tracehelp,	0,	0,	settrace },
	{ "type",	typehelp,	0,	1,	settype },
	{ "user",	userhelp,	0,	1,	user },
	{ "verbose",	verbosehelp,	0,	0,	setverbose },
	{ "?",		helphelp,	0,	0,	help },
E 11
I 11
	{ "!",		shellhelp,	0,	0,	0,	shell },
	{ "$",		domachelp,	1,	0,	0,	domacro },
	{ "account",	accounthelp,	0,	1,	1,	account},
	{ "append",	appendhelp,	1,	1,	1,	put },
	{ "ascii",	asciihelp,	0,	1,	1,	setascii },
	{ "bell",	beephelp,	0,	0,	0,	setbell },
	{ "binary",	binaryhelp,	0,	1,	1,	setbinary },
	{ "bye",	quithelp,	0,	0,	0,	quit },
	{ "case",	casehelp,	0,	0,	1,	setcase },
	{ "cd",		cdhelp,		0,	1,	1,	cd },
	{ "cdup",	cduphelp,	0,	1,	1,	cdup },
	{ "close",	disconhelp,	0,	1,	1,	disconnect },
	{ "cr",		crhelp,		0,	0,	0,	setcr },
	{ "delete",	deletehelp,	0,	1,	1,	delete },
	{ "debug",	debughelp,	0,	0,	0,	setdebug },
	{ "dir",	dirhelp,	1,	1,	1,	ls },
	{ "disconnect",	disconhelp,	0,	1,	1,	disconnect },
	{ "form",	formhelp,	0,	1,	1,	setform },
	{ "get",	receivehelp,	1,	1,	1,	get },
	{ "glob",	globhelp,	0,	0,	0,	setglob },
	{ "hash",	hashhelp,	0,	0,	0,	sethash },
	{ "help",	helphelp,	0,	0,	1,	help },
I 12
	{ "image",	binaryhelp,	0,	1,	1,	setbinary },
E 12
	{ "lcd",	lcdhelp,	0,	0,	0,	lcd },
	{ "ls",		lshelp,		1,	1,	1,	ls },
	{ "macdef",	macdefhelp,	0,	0,	0,	macdef },
	{ "mdelete",	mdeletehelp,	1,	1,	1,	mdelete },
	{ "mdir",	mdirhelp,	1,	1,	1,	mls },
	{ "mget",	mgethelp,	1,	1,	1,	mget },
	{ "mkdir",	mkdirhelp,	0,	1,	1,	makedir },
	{ "mls",	mlshelp,	1,	1,	1,	mls },
	{ "mode",	modehelp,	0,	1,	1,	setmode },
	{ "mput",	mputhelp,	1,	1,	1,	mput },
	{ "nmap",	nmaphelp,	0,	0,	1,	setnmap },
	{ "ntrans",	ntranshelp,	0,	0,	1,	setntrans },
	{ "open",	connecthelp,	0,	0,	1,	setpeer },
	{ "prompt",	prompthelp,	0,	0,	0,	setprompt },
	{ "proxy",	proxyhelp,	0,	0,	1,	doproxy },
	{ "sendport",	porthelp,	0,	0,	0,	setport },
	{ "put",	sendhelp,	1,	1,	1,	put },
	{ "pwd",	pwdhelp,	0,	1,	1,	pwd },
	{ "quit",	quithelp,	0,	0,	0,	quit },
	{ "quote",	quotehelp,	1,	1,	1,	quote },
	{ "recv",	receivehelp,	1,	1,	1,	get },
	{ "remotehelp",	remotehelp,	0,	1,	1,	rmthelp },
	{ "rename",	renamehelp,	0,	1,	1,	renamefile },
	{ "reset",	resethelp,	0,	1,	1,	reset },
	{ "rmdir",	rmdirhelp,	0,	1,	1,	removedir },
	{ "runique",	runiquehelp,	0,	0,	1,	setrunique },
	{ "send",	sendhelp,	1,	1,	1,	put },
	{ "status",	statushelp,	0,	0,	1,	status },
	{ "struct",	structhelp,	0,	1,	1,	setstruct },
	{ "sunique",	suniquehelp,	0,	0,	1,	setsunique },
	{ "tenex",	tenexhelp,	0,	1,	1,	settenex },
	{ "trace",	tracehelp,	0,	0,	0,	settrace },
	{ "type",	typehelp,	0,	1,	1,	settype },
	{ "user",	userhelp,	0,	1,	1,	user },
	{ "verbose",	verbosehelp,	0,	0,	0,	setverbose },
	{ "?",		helphelp,	0,	0,	1,	help },
E 11
	{ 0 },
E 4
};

D 8
int	NCMDS = sizeof (cmdtab) / sizeof (cmdtab[0]);
E 8
I 8
int	NCMDS = (sizeof (cmdtab) / sizeof (cmdtab[0])) - 1;
E 8
E 1
