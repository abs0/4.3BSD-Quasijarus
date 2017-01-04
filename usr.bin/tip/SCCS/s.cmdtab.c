h06833
s 00003/00003/00034
d D 5.4 87/12/22 13:49:51 bostic 10 9
c make ANSI C compatible
e
s 00002/00001/00035
d D 5.3 86/05/05 11:01:38 sam 9 8
c add ~^Y to stop local side only (a la rlogin)
e
s 00002/00001/00034
d D 5.2 85/11/29 19:17:09 donn 8 7
c Added '~$' escape -- send output of local command to remote host.
e
s 00007/00001/00028
d D 5.1 85/04/30 12:39:10 dist 7 6
c Add copyright
e
s 00009/00010/00020
d D 4.6 83/06/25 01:13:37 sam 6 5
c so much...clean up after ralph's merge of wendel and mo code;
c purge VMUNIX include since changes for signals make it no longer portable 
c to systems other than 4.2; fix ventel for no echo strapping; do setjmps 
c instead of assuming interrupted system calls; purge lcmd, if people use 
e
s 00004/00003/00026
d D 4.5 83/06/15 13:52:12 ralph 5 4
c changes for local info, parity, vadic auto dialers
e
s 00004/00001/00025
d D 4.4 81/11/29 22:49:43 sam 4 3
c reformatting
e
s 00003/00002/00023
d D 4.3 81/05/31 15:03:13 sam 3 2
c added break command from decvax!shannon
e
s 00001/00000/00024
d D 4.2 81/05/26 10:02:53 sam 2 1
c add in ~. synonym for ~^D (shannon)
e
s 00024/00000/00000
d D 4.1 81/05/09 16:45:12 root 1 0
c date and time created 81/05/09 16:45:12 by root
e
u
U
t
T
I 7
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 7
I 1
D 6
/*	%M%	%I%	%E%	*/
E 6
I 6
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 7
#endif
E 7
I 7
#endif not lint
E 7

E 6
#include "tip.h"

D 5
extern int shell(), getfl(), sendfile(), chdirectory(),
E 5
I 5
D 6
extern int shell(), lcmd(), getfl(), sendfile(), chdirectory(),
E 5
	finish(), help(), pipefile(), consh(), variable(),
D 3
	cu_take(), cu_put(), dollar();
E 3
I 3
D 4
	cu_take(), cu_put(), dollar(), genbrk();
E 4
I 4
	cu_take(), cu_put(), dollar(), genbrk(), suspend();
E 6
I 6
extern	int shell(), getfl(), sendfile(), chdirectory();
D 8
extern	int finish(), help(), pipefile(), consh(), variable();
E 8
I 8
extern	int finish(), help(), pipefile(), pipeout(), consh(), variable();
E 8
extern	int cu_take(), cu_put(), dollar(), genbrk(), suspend();
E 6
E 4
E 3

D 6
esctable_t etable[] =
{
D 5
	{ '!',	NORM,	"shell",			 shell },
E 5
I 5
	{ '%',	NORM,	"shell",			 shell },
	{ '!',	NORM,	"local command",		 lcmd },
E 6
I 6
esctable_t etable[] = {
	{ '!',	NORM,	"shell",			 shell },
E 6
E 5
	{ '<',	NORM,	"receive file from remote host", getfl },
	{ '>',	NORM,	"send file to remote host",	 sendfile },
	{ 't',	NORM,	"take file from remote UNIX",	 cu_take },
	{ 'p',	NORM,	"put file to remote UNIX",	 cu_put },
	{ '|',	NORM,	"pipe remote file",		 pipefile },
I 8
	{ '$',	NORM,	"pipe local command to remote host", pipeout },
E 8
#ifdef CONNECT
D 5
	{ '%',  NORM,	"connect program to remote host",consh },
E 5
I 5
	{ 'C',  NORM,	"connect program to remote host",consh },
E 5
#endif
	{ 'c',	NORM,	"change directory",		 chdirectory },
I 2
	{ '.',	NORM,	"exit from tip",		 finish },
E 2
D 10
	{CTRL(d),NORM,	"exit from tip",		 finish },
I 4
D 6
#ifdef SIGTSTP
E 6
D 9
	{CTRL(z),NORM,	"suspend tip",			 suspend },
E 9
I 9
	{CTRL(y),NORM,	"suspend tip (local+remote)",	 suspend },
	{CTRL(z),NORM,	"suspend tip (local only)",	 suspend },
E 10
I 10
	{CTRL('d'),NORM,"exit from tip",		 finish },
	{CTRL('y'),NORM,"suspend tip (local+remote)",	 suspend },
	{CTRL('z'),NORM,"suspend tip (local only)",	 suspend },
E 10
E 9
D 6
#endif
E 6
E 4
	{ 's',	NORM,	"set variable",			 variable },
D 3
	{ '?',	NORM,	"get this summary",		 help},
E 3
I 3
	{ '?',	NORM,	"get this summary",		 help },
	{ '#',	NORM,	"send break",			 genbrk },
E 3
	{ 0, 0, 0 }
};
E 1
