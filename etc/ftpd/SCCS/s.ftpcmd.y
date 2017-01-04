h33855
s 00000/00001/00890
d D 5.17 11/04/16 00:35:55 msokolov 30 29
c added support for multiple guest accounts
e
s 00003/00035/00888
d D 5.16 05/01/12 07:31:08 msokolov 29 28
c EPS implemented
e
s 00005/00000/00918
d D 5.15 05/01/11 06:00:12 msokolov 28 27
c use compiled-in ls instead of /bin/ls
c in preparation for EPS with chroot
e
s 00006/00022/00912
d D 5.14 03/06/10 21:05:22 msokolov 27 26
c restore LIST/NLST <glob pattern> support, but make it sensible this time
e
s 00024/00014/00910
d D 5.13 03/06/10 16:45:02 msokolov 26 25
c handle ~-pathnames by hand, don't bring in glob
e
s 00043/00010/00881
d D 5.12 01/01/07 17:28:36 msokolov 25 24
c Added /etc/anonftp.allow support.
c While at it, removed support for changing users, which never worked right,
c and cleaned up / fixed / brought up to spec the handling of LIST/NLST and
c STOR/APPE/STOU. (STOU still not per RFC 959, sigh.)
e
s 00012/00005/00879
d D 5.11 88/06/18 13:46:46 bostic 24 23
c install approved copyright notice
e
s 00010/00004/00874
d D 5.10 88/03/14 17:27:47 bostic 23 22
c add Berkeley specific header
e
s 00002/00004/00876
d D 5.9 87/05/15 17:39:20 mckusick 22 21
c ftpd remotehelp output columnated improperly (from abe@j.cc.purdue.edu)
e
s 00029/00032/00851
d D 5.8 87/04/23 13:57:13 csvsj 21 20
c redo yacc grammer for RNFR and RNTO
e
s 00002/00000/00881
d D 5.7 86/05/28 15:25:06 mckusick 20 19
c return error code 530 when user is denied access
e
s 00021/00007/00860
d D 5.6 86/05/06 21:24:23 minshall 19 18
c Robustly filter telnet commands on the control connection 
c (from Steve Jacobson).
e
s 00012/00007/00855
d D 5.5 86/04/16 17:38:16 mckusick 18 17
c standardize the reply codes (from mcvax!dpk@seismo.CSS.GOV)
e
s 00062/00063/00800
d D 5.4 86/03/07 12:01:49 minshall 17 16
c Clean up for lint; add syslog.
e
s 00069/00012/00794
d D 5.3 86/02/03 14:32:36 minshall 16 15
c Steve Jacobson's changes (from <csvsj@ucbopal>).
e
s 00006/00007/00800
d D 5.2 85/06/06 11:10:46 dist 15 14
c Add copyright
e
s 00007/00000/00800
d D 5.1 85/06/06 11:08:49 dist 14 13
c Add copyright
e
s 00001/00001/00799
d D 4.13 85/03/12 11:35:20 ralph 13 12
c return null in getline() so dologout() is called rather than exit.
e
s 00002/00002/00798
d D 4.12 84/04/11 14:55:10 karels 12 11
c convert for inetd
e
s 00003/00003/00797
d D 4.11 83/06/22 14:33:03 sam 11 10
c do wtmp logging and cleanup some stuff
e
s 00003/00002/00797
d D 4.10 83/06/12 02:44:52 sam 10 9
c new signals == no libjobs
e
s 00029/00004/00770
d D 4.9 83/03/23 10:26:38 sam 9 8
c merge of changes from jsq@utexas-11
e
s 00002/00002/00772
d D 4.8 83/02/21 19:05:39 sam 8 7
c -C violates standard
e
s 00001/00001/00773
d D 4.7 83/02/02 16:25:03 sam 7 6
c 2 holes: disallow |'s in ls and dir; 2nd, provide forbidden user list
e
s 00007/00005/00767
d D 4.6 83/01/16 13:13:29 sam 6 5
c check user existence before requesting password
e
s 00002/00000/00770
d D 4.5 83/01/16 12:29:10 sam 5 4
c insure default address used even if some transfers supply PORT
e
s 00005/00007/00765
d D 4.4 83/01/16 12:10:07 sam 4 3
c restrict anonymous logins to machines with an ftp account
e
s 00004/00004/00768
d D 4.3 83/01/16 11:54:26 sam 3 2
c only execute /bin/ls so noone can place a dummy ls in the 
c path of the server and become root through its execution
e
s 00043/00032/00729
d D 4.2 83/01/15 16:58:39 sam 2 1
c watch out for glob failing; add -C so NLST comes 
c out columnized; fix help command not to print extra CR-NL
e
s 00761/00000/00000
d D 4.1 83/01/13 23:57:03 sam 1 0
c date and time created 83/01/13 23:57:03 by sam
e
u
U
f b 
t
T
I 14
D 15
#
# Copyright (c) 1980 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W% (Berkeley) %G%
#
E 15
I 15
/*
D 16
 * Copyright (c) 1980 Regents of the University of California.
E 16
I 16
 * Copyright (c) 1985 Regents of the University of California.
E 16
D 23
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 23
I 23
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 24
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 24
I 24
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
 *
 *	%W% (Berkeley) %G%
E 24
E 23
 */

E 15
E 14
I 1
/*
 * Grammar for FTP commands.
 * See RFC 765.
 */

%{

#ifndef lint
D 12
static char sccsid[] = "%W% %E%";
E 12
I 12
D 23
static	char sccsid[] = "%W% (Berkeley) %G%";
E 12
#endif
E 23
I 23
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 23

#include <sys/types.h>
I 25
#include <sys/stat.h>
E 25
#include <sys/socket.h>

#include <netinet/in.h>

I 10
#include <arpa/ftp.h>

E 10
#include <stdio.h>
I 9
#include <signal.h>
I 25
#include <errno.h>
E 25
E 9
#include <ctype.h>
#include <pwd.h>
#include <setjmp.h>
I 17
#include <syslog.h>
E 17
D 10
#include "ftp.h"
E 10

I 25
extern	int errno;
extern	char *sys_errlist[];

E 25
extern	struct sockaddr_in data_dest;
extern	int logged_in;
extern	struct passwd *pw;
D 30
extern	int guest;
E 30
extern	int logging;
extern	int type;
extern	int form;
extern	int debug;
I 9
extern	int timeout;
I 16
extern  int pdata;
E 16
E 9
extern	char hostname[];
D 26
extern	char *globerr;
E 26
I 5
extern	int usedefault;
I 16
D 25
extern	int unique;
E 25
extern  int transflag;
extern  char tmpline[];
I 25
extern  char **guestdirs;
extern  int nguestdirs;
I 28
extern	int longlist;
I 29
extern	int chrooted;
E 29
E 28
E 25
E 16
E 5
D 26
char	**glob();
E 26

static	int cmd_type;
static	int cmd_form;
static	int cmd_bytesz;
I 16
char cbuf[512];
I 21
char *fromname;
E 21
E 16

D 4
static	struct passwd nobody = { "?", "?" };

E 4
char	*index();
%}

%token
	A	B	C	E	F	I
	L	N	P	R	S	T

	SP	CRLF	COMMA	STRING	NUMBER

	USER	PASS	ACCT	REIN	QUIT	PORT
	PASV	TYPE	STRU	MODE	RETR	STOR
	APPE	MLFL	MAIL	MSND	MSOM	MSAM
	MRSQ	MRCP	ALLO	REST	RNFR	RNTO
	ABOR	DELE	CWD	LIST	NLST	SITE
	STAT	HELP	NOOP	XMKD	XRMD	XPWD
D 16
	XCUP
E 16
I 16
	XCUP	STOU
E 16

	LEXERR

%start	cmd_list

%%

cmd_list:	/* empty */
	|	cmd_list cmd
I 21
		= {
			fromname = (char *) 0;
		}
	|	cmd_list rcmd
E 21
	;

cmd:		USER SP username CRLF
		= {
D 29
			extern struct passwd *getpwnam();

I 16
D 25
			logged_in = 0;
E 16
D 4
			if (strcmp($3, "ftp") == 0 ||
			    strcmp($3, "anonymous") == 0) {
E 4
I 4
D 6
			if ((strcmp($3, "ftp") == 0 ||
			    strcmp($3, "anonymous") == 0) &&
			    (pw = getpwnam("ftp")) != NULL) {
E 4
				guest = 1;
D 4
				pw = getpwnam("ftp");
E 4
				reply(331,
E 6
I 6
D 17
			if (strcmp($3, "ftp") == 0 ||
			  strcmp($3, "anonymous") == 0) {
E 17
I 17
			if (strcmp((char *) $3, "ftp") == 0 ||
E 25
I 25
			/*
			 * RFC 959 allows us to change users, but doesn't
			 * require us to. We used to support this, but it never
			 * worked right and now we have to block it altogether.
			 * Unfortunately, RFC 959 doesn't give a reply code to
			 * use for this. 503 seems the most logical to me, but
			 * the tables don't allow it. I settled for 500.
			 */
			if (logged_in) {
				reply(500, "Changing USER is not supported.");
			} else if (strcmp((char *) $3, "ftp") == 0 ||
E 25
			  strcmp((char *) $3, "anonymous") == 0) {
E 17
				if ((pw = getpwnam("ftp")) != NULL) {
					guest = 1;
					reply(331,
E 6
				  "Guest login ok, send ident as password.");
I 6
				}
I 16
				else {
					reply(530, "User %s unknown.", $3);
				}
E 16
E 6
D 7
			} else {
E 7
I 7
D 17
			} else if (checkuser($3)) {
E 17
I 17
			} else if (checkuser((char *) $3)) {
E 17
E 7
				guest = 0;
D 17
				pw = getpwnam($3);
E 17
I 17
				pw = getpwnam((char *) $3);
E 17
D 16
				reply(331, "Password required for %s.", $3);
E 16
I 16
				if (pw == NULL) {
					reply(530, "User %s unknown.", $3);
				}
				else {
				    reply(331, "Password required for %s.", $3);
				}
I 20
			} else {
				reply(530, "User %s access denied.", $3);
E 20
E 16
			}
E 29
I 29
			user((char *) $3);
E 29
D 4
			free($3);
E 4
D 16
			if (pw == NULL)
D 4
				pw = &nobody;
E 4
I 4
				reply(530, "User %s unknown.", $3);
E 16
D 17
			free($3);
E 17
I 17
			free((char *) $3);
E 17
E 4
		}
	|	PASS SP password CRLF
		= {
D 17
			pass($3);
			free($3);
E 17
I 17
			pass((char *) $3);
			free((char *) $3);
E 17
		}
	|	PORT SP host_port CRLF
		= {
I 5
			usedefault = 0;
I 16
			if (pdata > 0) {
				(void) close(pdata);
			}
			pdata = -1;
E 16
E 5
D 17
			ack($1);
E 17
I 17
D 18
			ack((char *) $1);
E 18
I 18
			reply(200, "PORT command successful.");
E 18
E 17
		}
I 16
	|	PASV CRLF
		= {
			passive();
		}
E 16
	|	TYPE SP type_code CRLF
		= {
			switch (cmd_type) {

			case TYPE_A:
				if (cmd_form == FORM_N) {
					reply(200, "Type set to A.");
					type = cmd_type;
					form = cmd_form;
				} else
					reply(504, "Form must be N.");
				break;

			case TYPE_E:
				reply(504, "Type E not implemented.");
				break;

			case TYPE_I:
				reply(200, "Type set to I.");
				type = cmd_type;
				break;

			case TYPE_L:
				if (cmd_bytesz == 8) {
					reply(200,
					    "Type set to L (byte size 8).");
					type = cmd_type;
				} else
					reply(504, "Byte size must be 8.");
			}
		}
	|	STRU SP struct_code CRLF
		= {
			switch ($3) {

			case STRU_F:
				reply(200, "STRU F ok.");
				break;

			default:
D 18
				reply(502, "Unimplemented STRU type.");
E 18
I 18
				reply(504, "Unimplemented STRU type.");
E 18
			}
		}
	|	MODE SP mode_code CRLF
		= {
			switch ($3) {

			case MODE_S:
				reply(200, "MODE S ok.");
				break;

			default:
				reply(502, "Unimplemented MODE type.");
			}
		}
	|	ALLO SP NUMBER CRLF
		= {
D 17
			ack($1);
E 17
I 17
D 18
			ack((char *) $1);
E 18
I 18
			reply(202, "ALLO command ignored.");
E 18
E 17
		}
	|	RETR check_login SP pathname CRLF
		= {
D 2
			if ($2)
E 2
I 2
			if ($2 && $4 != NULL)
E 2
D 17
				retrieve(0, $4);
E 17
I 17
				retrieve((char *) 0, (char *) $4);
E 17
D 2
			free($4);
E 2
I 2
			if ($4 != NULL)
D 17
				free($4);
E 17
I 17
				free((char *) $4);
E 17
E 2
		}
	|	STOR check_login SP pathname CRLF
		= {
D 2
			if ($2)
E 2
I 2
			if ($2 && $4 != NULL)
E 2
D 17
				store($4, "w");
E 17
I 17
				store((char *) $4, "w");
E 17
D 2
			free($4);
E 2
I 2
			if ($4 != NULL)
D 17
				free($4);
E 17
I 17
				free((char *) $4);
E 17
E 2
		}
	|	APPE check_login SP pathname CRLF
		= {
D 2
			if ($2)
E 2
I 2
			if ($2 && $4 != NULL)
E 2
D 17
				store($4, "a");
E 17
I 17
				store((char *) $4, "a");
E 17
D 2
			free($4);
E 2
I 2
			if ($4 != NULL)
D 17
				free($4);
E 17
I 17
				free((char *) $4);
E 17
E 2
		}
	|	NLST check_login CRLF
		= {
I 28
			longlist = 0;
E 28
			if ($2)
D 2
				retrieve("ls", "");
E 2
I 2
D 3
				retrieve("ls -C", "");
E 3
I 3
D 8
				retrieve("/bin/ls -C", "");
E 8
I 8
D 27
				retrieve("/bin/ls", "");
E 27
I 27
				list(NULL, 0);
E 27
E 8
E 3
E 2
		}
	|	NLST check_login SP pathname CRLF
		= {
D 2
			if ($2)
				retrieve("ls %s", $4);
			free($4);
E 2
I 2
D 25
			if ($2 && $4 != NULL)
D 3
				retrieve("ls -C %s", $4);
E 3
I 3
D 8
				retrieve("/bin/ls -C %s", $4);
E 8
I 8
D 17
				retrieve("/bin/ls %s", $4);
E 17
I 17
				retrieve("/bin/ls %s", (char *) $4);
E 25
I 25
			struct stat st;

I 28
			longlist = 0;
E 28
D 27
			if ($2 && $4 != NULL) {
				if (guest && guestdirs != NULL
				    && guest_check_pathname($4))
					reply(550, "%s: %s.", $4,
					      sys_errlist[EACCES]);
				else if (lstat($4, &st))
					reply(550, "%s: %s.", $4,
					      sys_errlist[errno]);
				else retrieve("/bin/ls -- %s", (char *) $4);
			}
E 27
I 27
			if ($2 && $4 != NULL)
				list($4, 0);
E 27
E 25
E 17
E 8
E 3
			if ($4 != NULL)
D 17
				free($4);
E 17
I 17
				free((char *) $4);
E 17
E 2
		}
	|	LIST check_login CRLF
		= {
I 28
			longlist = 1;
E 28
			if ($2)
D 2
				retrieve("ls -l", "");
E 2
I 2
D 3
				retrieve("ls -lg", "");
E 3
I 3
D 27
				retrieve("/bin/ls -lg", "");
E 27
I 27
				list(NULL, 1);
E 27
E 3
E 2
		}
	|	LIST check_login SP pathname CRLF
		= {
D 2
			if ($2)
				retrieve("ls -l %s", $4);
			free($4);
E 2
I 2
D 25
			if ($2 && $4 != NULL)
D 3
				retrieve("ls -lg %s", $4);
E 3
I 3
D 17
				retrieve("/bin/ls -lg %s", $4);
E 17
I 17
				retrieve("/bin/ls -lg %s", (char *) $4);
E 25
I 25
			struct stat st;

I 28
			longlist = 1;
E 28
D 27
			if ($2 && $4 != NULL) {
				if (guest && guestdirs != NULL
				    && guest_check_pathname($4))
					reply(550, "%s: %s.", $4,
					      sys_errlist[EACCES]);
				else if (lstat($4, &st))
					reply(550, "%s: %s.", $4,
					      sys_errlist[errno]);
				else retrieve("/bin/ls -lg -- %s", (char *) $4);
			}
E 27
I 27
			if ($2 && $4 != NULL)
				list($4, 1);
E 27
E 25
E 17
E 3
			if ($4 != NULL)
D 17
				free($4);
E 17
I 17
				free((char *) $4);
E 17
E 2
		}
	|	DELE check_login SP pathname CRLF
		= {
D 2
			if ($2)
E 2
I 2
			if ($2 && $4 != NULL)
E 2
D 17
				delete($4);
E 17
I 17
				delete((char *) $4);
E 17
D 2
			free($4);
E 2
I 2
			if ($4 != NULL)
D 17
				free($4);
E 17
I 17
				free((char *) $4);
E 17
E 2
		}
I 21
	|	RNTO SP pathname CRLF
		= {
			if (fromname) {
				renamecmd(fromname, (char *) $3);
				free(fromname);
				fromname = (char *) 0;
			} else {
				reply(503, "Bad sequence of commands.");
			}
			free((char *) $3);
		}
E 21
I 16
	|	ABOR CRLF
		= {
D 17
			ack($1);
E 17
I 17
D 18
			ack((char *) $1);
E 18
I 18
			reply(225, "ABOR command successful.");
E 18
E 17
		}
E 16
	|	CWD check_login CRLF
		= {
			if ($2)
				cwd(pw->pw_dir);
		}
	|	CWD check_login SP pathname CRLF
		= {
D 2
			if ($2)
E 2
I 2
			if ($2 && $4 != NULL)
E 2
D 17
				cwd($4);
E 17
I 17
				cwd((char *) $4);
E 17
D 2
			free($4);
E 2
I 2
			if ($4 != NULL)
D 17
				free($4);
E 17
I 17
				free((char *) $4);
E 17
E 2
		}
D 21
	|	rename_cmd
E 21
	|	HELP CRLF
		= {
D 17
			help(0);
E 17
I 17
			help((char *) 0);
E 17
		}
	|	HELP SP STRING CRLF
		= {
D 17
			help($3);
E 17
I 17
			help((char *) $3);
E 17
		}
	|	NOOP CRLF
		= {
D 17
			ack($1);
E 17
I 17
D 18
			ack((char *) $1);
E 18
I 18
			reply(200, "NOOP command successful.");
E 18
E 17
		}
	|	XMKD check_login SP pathname CRLF
		= {
D 2
			if ($2)
				do_mkdir($4);
			free($4);
E 2
I 2
			if ($2 && $4 != NULL)
D 17
				makedir($4);
E 17
I 17
				makedir((char *) $4);
E 17
			if ($4 != NULL)
D 17
				free($4);
E 17
I 17
				free((char *) $4);
E 17
E 2
		}
	|	XRMD check_login SP pathname CRLF
		= {
D 2
			if ($2)
				do_rmdir($4);
			free($4);
E 2
I 2
			if ($2 && $4 != NULL)
D 17
				removedir($4);
E 17
I 17
				removedir((char *) $4);
E 17
			if ($4 != NULL)
D 17
				free($4);
E 17
I 17
				free((char *) $4);
E 17
E 2
		}
	|	XPWD check_login CRLF
		= {
			if ($2)
D 2
				do_pwd();
E 2
I 2
				pwd();
E 2
		}
	|	XCUP check_login CRLF
		= {
			if ($2)
				cwd("..");
		}
I 16
	|	STOU check_login SP pathname CRLF
		= {
			if ($2 && $4 != NULL) {
D 25
				unique++;
D 17
				store($4, "w");
E 17
I 17
				store((char *) $4, "w");
E 17
				unique = 0;
E 25
I 25
				store((char *) $4, "u");
E 25
			}
			if ($4 != NULL)
D 17
				free($4);
E 17
I 17
				free((char *) $4);
E 17
		}
E 16
	|	QUIT CRLF
		= {
			reply(221, "Goodbye.");
D 11
			exit(0);
E 11
I 11
			dologout(0);
E 11
		}
	|	error CRLF
		= {
			yyerrok;
		}
	;

I 21
rcmd:		RNFR check_login SP pathname CRLF
		= {
			char *renamefrom();

			if ($2 && $4) {
				fromname = renamefrom((char *) $4);
				if (fromname == (char *) 0 && $4) {
					free((char *) $4);
				}
			}
		}
	;
		
E 21
username:	STRING
	;

password:	STRING
	;

byte_size:	NUMBER
	;

host_port:	NUMBER COMMA NUMBER COMMA NUMBER COMMA NUMBER COMMA 
		NUMBER COMMA NUMBER
		= {
			register char *a, *p;

			a = (char *)&data_dest.sin_addr;
			a[0] = $1; a[1] = $3; a[2] = $5; a[3] = $7;
			p = (char *)&data_dest.sin_port;
			p[0] = $9; p[1] = $11;
I 6
			data_dest.sin_family = AF_INET;
E 6
		}
	;

form_code:	N
	= {
		$$ = FORM_N;
	}
	|	T
	= {
		$$ = FORM_T;
	}
	|	C
	= {
		$$ = FORM_C;
	}
	;

type_code:	A
	= {
		cmd_type = TYPE_A;
		cmd_form = FORM_N;
	}
	|	A SP form_code
	= {
		cmd_type = TYPE_A;
		cmd_form = $3;
	}
	|	E
	= {
		cmd_type = TYPE_E;
		cmd_form = FORM_N;
	}
	|	E SP form_code
	= {
		cmd_type = TYPE_E;
		cmd_form = $3;
	}
	|	I
	= {
		cmd_type = TYPE_I;
	}
	|	L
	= {
		cmd_type = TYPE_L;
		cmd_bytesz = 8;
	}
	|	L SP byte_size
	= {
		cmd_type = TYPE_L;
		cmd_bytesz = $3;
	}
	/* this is for a bug in the BBN ftp */
	|	L byte_size
	= {
		cmd_type = TYPE_L;
		cmd_bytesz = $2;
	}
	;

struct_code:	F
	= {
		$$ = STRU_F;
	}
	|	R
	= {
		$$ = STRU_R;
	}
	|	P
	= {
		$$ = STRU_P;
	}
	;

mode_code:	S
	= {
		$$ = MODE_S;
	}
	|	B
	= {
		$$ = MODE_B;
	}
	|	C
	= {
		$$ = MODE_C;
	}
	;

pathname:	pathstring
	= {
I 18
D 26
		/*
		 * Problem: this production is used for all pathname
		 * processing, but only gives a 550 error reply.
		 * This is a valid reply in some cases but not in others.
		 */
E 18
D 17
		if ($1 && strncmp($1, "~", 1) == 0) {
			$$ = (int)*glob($1);
E 17
I 17
		if ($1 && strncmp((char *) $1, "~", 1) == 0) {
			$$ = (int)*glob((char *) $1);
E 17
D 2
			if (globerr != NULL)
E 2
I 2
			if (globerr != NULL) {
E 2
				reply(550, globerr);
I 2
				$$ = NULL;
			}
E 2
D 17
			free($1);
E 17
I 17
			free((char *) $1);
E 26
I 26
D 29
		if ($1 && *((char *) $1) == '~') {
E 29
I 29
		if ($1 && *((char *) $1) == '~' && !chrooted) {
E 29
			char *user, *tail, *buf;
			struct passwd *upw;
			extern char *malloc(), *index();

			user = ((char *) $1) + 1;
			tail = index(user, '/');
			if (tail)
				*tail = '\0';
			upw = *user ? getpwnam(user) : pw;
			if (tail)
				*tail = '/';
			if (upw) {
				buf = malloc(strlen(upw->pw_dir) +
						(tail ? strlen(tail) : 0) + 1);
				if (buf == NULL)
					fatal("Ran out of memory.");
				strcpy(buf, upw->pw_dir);
				if (tail)
					strcat(buf, tail);
				free((char *) $1);
				$$ = (int) buf;
			} else
				$$ = $1;
E 26
E 17
		} else
			$$ = $1;
	}
	;

pathstring:	STRING
D 21
	;

rename_cmd:	rename_from rename_to
	= {
		if ($1 && $2)
D 17
			renamecmd($1, $2);
E 17
I 17
			renamecmd((char *) $1, (char *) $2);
E 17
		else
			reply(503, "Bad sequence of commands.");
		if ($1)
D 17
			free($1);
E 17
I 17
			free((char *) $1);
E 17
		if ($2)
D 17
			free($2);
E 17
I 17
			free((char *) $2);
E 17
	}
	;

rename_from:	RNFR check_login SP pathname CRLF
	= {
		char *from = 0, *renamefrom();

D 2
		if ($2)
E 2
I 2
		if ($2 && $4)
E 2
D 17
			from = renamefrom($4);
E 17
I 17
			from = renamefrom((char *) $4);
E 17
D 2
		if (from == 0)
E 2
I 2
		if (from == 0 && $4)
E 2
D 17
			free($4);
E 17
I 17
			free((char *) $4);
E 17
		$$ = (int)from;
	}
	;

rename_to:	RNTO SP pathname CRLF
	= {
		$$ = $3;
	}
E 21
	;

check_login:	/* empty */
	= {
		if (logged_in)
			$$ = 1;
		else {
			reply(530, "Please login with USER and PASS.");
			$$ = 0;
		}
	}
	;

%%

extern jmp_buf errcatch;

#define	CMD	0	/* beginning of command */
#define	ARGS	1	/* expect miscellaneous arguments */
#define	STR1	2	/* expect SP followed by STRING */
#define	STR2	3	/* expect STRING */
#define	OSTR	4	/* optional STRING */

struct tab {
	char	*name;
	short	token;
	short	state;
	short	implemented;	/* 1 if command is implemented */
	char	*help;
};

struct tab cmdtab[] = {		/* In order defined in RFC 765 */
	{ "USER", USER, STR1, 1,	"<sp> username" },
	{ "PASS", PASS, STR1, 1,	"<sp> password" },
	{ "ACCT", ACCT, STR1, 0,	"(specify account)" },
	{ "REIN", REIN, ARGS, 0,	"(reinitialize server state)" },
	{ "QUIT", QUIT, ARGS, 1,	"(terminate service)", },
	{ "PORT", PORT, ARGS, 1,	"<sp> b0, b1, b2, b3, b4" },
D 16
	{ "PASV", PASV, ARGS, 0,	"(set server in passive mode)" },
E 16
I 16
	{ "PASV", PASV, ARGS, 1,	"(set server in passive mode)" },
E 16
	{ "TYPE", TYPE, ARGS, 1,	"<sp> [ A | E | I | L ]" },
	{ "STRU", STRU, ARGS, 1,	"(specify file structure)" },
	{ "MODE", MODE, ARGS, 1,	"(specify transfer mode)" },
	{ "RETR", RETR, STR1, 1,	"<sp> file-name" },
	{ "STOR", STOR, STR1, 1,	"<sp> file-name" },
	{ "APPE", APPE, STR1, 1,	"<sp> file-name" },
	{ "MLFL", MLFL, OSTR, 0,	"(mail file)" },
	{ "MAIL", MAIL, OSTR, 0,	"(mail to user)" },
	{ "MSND", MSND, OSTR, 0,	"(mail send to terminal)" },
	{ "MSOM", MSOM, OSTR, 0,	"(mail send to terminal or mailbox)" },
	{ "MSAM", MSAM, OSTR, 0,	"(mail send to terminal and mailbox)" },
	{ "MRSQ", MRSQ, OSTR, 0,	"(mail recipient scheme question)" },
	{ "MRCP", MRCP, STR1, 0,	"(mail recipient)" },
	{ "ALLO", ALLO, ARGS, 1,	"allocate storage (vacuously)" },
	{ "REST", REST, STR1, 0,	"(restart command)" },
	{ "RNFR", RNFR, STR1, 1,	"<sp> file-name" },
	{ "RNTO", RNTO, STR1, 1,	"<sp> file-name" },
D 16
	{ "ABOR", ABOR, ARGS, 0,	"(abort operation)" },
E 16
I 16
	{ "ABOR", ABOR, ARGS, 1,	"(abort operation)" },
E 16
	{ "DELE", DELE, STR1, 1,	"<sp> file-name" },
	{ "CWD",  CWD,  OSTR, 1,	"[ <sp> directory-name]" },
	{ "XCWD", CWD,	OSTR, 1,	"[ <sp> directory-name ]" },
	{ "LIST", LIST, OSTR, 1,	"[ <sp> path-name ]" },
	{ "NLST", NLST, OSTR, 1,	"[ <sp> path-name ]" },
	{ "SITE", SITE, STR1, 0,	"(get site parameters)" },
	{ "STAT", STAT, OSTR, 0,	"(get server status)" },
	{ "HELP", HELP, OSTR, 1,	"[ <sp> <string> ]" },
	{ "NOOP", NOOP, ARGS, 1,	"" },
I 16
	{ "MKD",  XMKD, STR1, 1,	"<sp> path-name" },
E 16
	{ "XMKD", XMKD, STR1, 1,	"<sp> path-name" },
I 16
	{ "RMD",  XRMD, STR1, 1,	"<sp> path-name" },
E 16
	{ "XRMD", XRMD, STR1, 1,	"<sp> path-name" },
I 16
	{ "PWD",  XPWD, ARGS, 1,	"(return current directory)" },
E 16
	{ "XPWD", XPWD, ARGS, 1,	"(return current directory)" },
I 16
	{ "CDUP", XCUP, ARGS, 1,	"(change to parent directory)" },
E 16
	{ "XCUP", XCUP, ARGS, 1,	"(change to parent directory)" },
I 16
	{ "STOU", STOU, STR1, 1,	"<sp> file-name" },
E 16
	{ NULL,   0,    0,    0,	0 }
};

struct tab *
lookup(cmd)
	char *cmd;
{
	register struct tab *p;

	for (p = cmdtab; p->name != NULL; p++)
		if (strcmp(cmd, p->name) == 0)
			return (p);
	return (0);
}

D 10
#include "../telnet/telnet.h"
E 10
I 10
#include <arpa/telnet.h>
E 10

/*
 * getline - a hacked up version of fgets to ignore TELNET escape codes.
 */
char *
getline(s, n, iop)
	char *s;
	register FILE *iop;
{
	register c;
D 16
	register char *cs;
E 16
I 16
D 17
	register char *cs, ch;
E 17
I 17
	register char *cs;
D 19
	char ch;
E 19
E 17
E 16

	cs = s;
I 19
/* tmpline may contain saved command from urgent mode interruption */
E 19
D 16
	while (--n > 0 && (c = getc(iop)) >= 0) {
E 16
I 16
	for (c = 0; tmpline[c] != '\0' && --n > 0; ++c) {
		*cs++ = tmpline[c];
		if (tmpline[c] == '\n') {
			*cs++ = '\0';
			if (debug) {
D 17
				fprintf(stderr, "FTPD: command: %s", s);
E 17
I 17
				syslog(LOG_DEBUG, "FTPD: command: %s", s);
E 17
			}
			tmpline[0] = '\0';
			return(s);
		}
		if (c == 0) {
			tmpline[0] = '\0';
		}
	}
D 19
	while (--n > 0 && read(fileno(iop),&ch,1) >= 0) {
		c = 0377 & ch;
E 19
I 19
	while (--n > 0 && (c = getc(iop)) != EOF) {
		c = 0377 & c;
E 19
E 16
		while (c == IAC) {
D 16
			c = getc(iop);	/* skip command */
			c = getc(iop);	/* try next char */
E 16
I 16
D 17
			read(fileno(iop),&ch,1);	/* skip command */
			read(fileno(iop),&ch,1);	/* try next char */
E 17
I 17
D 19
			(void) read(fileno(iop),&ch,1);	/* skip command */
			(void) read(fileno(iop),&ch,1);	/* try next char */
E 17
			c = 0377 & ch;
E 19
I 19
			switch (c = 0377 & getc(iop)) {
			case WILL:
			case WONT:
				c = 0377 & getc(iop);
				printf("%c%c%c", IAC, WONT, c);
				(void) fflush(stdout);
				break;
			case DO:
			case DONT:
				c = 0377 & getc(iop);
				printf("%c%c%c", IAC, DONT, c);
				(void) fflush(stdout);
				break;
			default:
				break;
			}
			c = 0377 & getc(iop); /* try next character */
E 19
E 16
		}
		*cs++ = c;
		if (c=='\n')
			break;
	}
D 19
	if (c < 0 && cs == s)
E 19
I 19
	if (c == EOF && cs == s)
E 19
D 12
		return (NULL);
E 12
I 12
D 13
		exit(1);
E 13
I 13
		return (NULL);
E 13
E 12
	*cs++ = '\0';
D 2
	fprintf(stderr, "FTPD: command: '%s'\n", s);
E 2
I 2
D 9
	fprintf(stderr, "FTPD: command: %s", s);
	if (c != '\n')
		putc('\n', stderr);
E 2
	fflush(stderr);
E 9
I 9
	if (debug) {
D 17
		fprintf(stderr, "FTPD: command: %s", s);
		if (c != '\n')
			putc('\n', stderr);
		fflush(stderr);
E 17
I 17
		syslog(LOG_DEBUG, "FTPD: command: %s", s);
E 17
	}
E 9
	return (s);
}

I 9
static int
toolong()
{
D 17
	long now;
E 17
I 17
	time_t now;
E 17
	extern char *ctime();
I 17
	extern time_t time();
E 17

	reply(421,
	  "Timeout (%d seconds): closing control connection.", timeout);
D 17
	time(&now);
E 17
I 17
	(void) time(&now);
E 17
	if (logging) {
D 17
		fprintf(stderr,
E 17
I 17
		syslog(LOG_INFO,
E 17
			"FTPD: User %s timed out after %d seconds at %s",
			(pw ? pw -> pw_name : "unknown"), timeout, ctime(&now));
D 17
		fflush(stderr);
E 17
	}
D 11
	exit(1);
E 11
I 11
	dologout(1);
E 11
}

E 9
yylex()
{
D 16
	static char cbuf[512];
E 16
	static int cpos, state;
	register char *cp;
	register struct tab *p;
	int n;
	char c;

	for (;;) {
		switch (state) {

		case CMD:
I 9
D 17
			signal(SIGALRM, toolong);
			alarm(timeout);
E 17
I 17
			(void) signal(SIGALRM, toolong);
			(void) alarm((unsigned) timeout);
E 17
E 9
			if (getline(cbuf, sizeof(cbuf)-1, stdin) == NULL) {
				reply(221, "You could at least say goodbye.");
D 11
				exit(0);
E 11
I 11
				dologout(0);
E 11
			}
I 9
D 17
			alarm(0);
E 17
I 17
			(void) alarm(0);
E 17
E 9
			if (index(cbuf, '\r')) {
				cp = index(cbuf, '\r');
				cp[0] = '\n'; cp[1] = 0;
			}
			if (index(cbuf, ' '))
				cpos = index(cbuf, ' ') - cbuf;
			else
I 16
				cpos = index(cbuf, '\n') - cbuf;
			if (cpos == 0) {
E 16
				cpos = 4;
I 16
			}
E 16
			c = cbuf[cpos];
			cbuf[cpos] = '\0';
			upper(cbuf);
			p = lookup(cbuf);
			cbuf[cpos] = c;
			if (p != 0) {
				if (p->implemented == 0) {
					nack(p->name);
D 17
					longjmp(errcatch);
E 17
I 17
					longjmp(errcatch,0);
E 17
					/* NOTREACHED */
				}
				state = p->state;
				yylval = (int) p->name;
				return (p->token);
			}
			break;

		case OSTR:
			if (cbuf[cpos] == '\n') {
				state = CMD;
				return (CRLF);
			}
			/* FALL THRU */

		case STR1:
			if (cbuf[cpos] == ' ') {
				cpos++;
				state = STR2;
				return (SP);
			}
			break;

		case STR2:
			cp = &cbuf[cpos];
			n = strlen(cp);
			cpos += n - 1;
			/*
			 * Make sure the string is nonempty and \n terminated.
			 */
			if (n > 1 && cbuf[cpos] == '\n') {
				cbuf[cpos] = '\0';
				yylval = copy(cp);
				cbuf[cpos] = '\n';
				state = ARGS;
				return (STRING);
			}
			break;

		case ARGS:
			if (isdigit(cbuf[cpos])) {
				cp = &cbuf[cpos];
				while (isdigit(cbuf[++cpos]))
					;
				c = cbuf[cpos];
				cbuf[cpos] = '\0';
				yylval = atoi(cp);
				cbuf[cpos] = c;
				return (NUMBER);
			}
			switch (cbuf[cpos++]) {

			case '\n':
				state = CMD;
				return (CRLF);

			case ' ':
				return (SP);

			case ',':
				return (COMMA);

			case 'A':
			case 'a':
				return (A);

			case 'B':
			case 'b':
				return (B);

			case 'C':
			case 'c':
				return (C);

			case 'E':
			case 'e':
				return (E);

			case 'F':
			case 'f':
				return (F);

			case 'I':
			case 'i':
				return (I);

			case 'L':
			case 'l':
				return (L);

			case 'N':
			case 'n':
				return (N);

			case 'P':
			case 'p':
				return (P);

			case 'R':
			case 'r':
				return (R);

			case 'S':
			case 's':
				return (S);

			case 'T':
			case 't':
				return (T);

			}
			break;

		default:
			fatal("Unknown state in scanner.");
		}
D 17
		yyerror();
E 17
I 17
		yyerror((char *) 0);
E 17
		state = CMD;
D 17
		longjmp(errcatch);
E 17
I 17
		longjmp(errcatch,0);
E 17
	}
}

upper(s)
	char *s;
{
	while (*s != '\0') {
		if (islower(*s))
			*s = toupper(*s);
		s++;
	}
}

copy(s)
	char *s;
{
	char *p;
D 17
	extern char *malloc();
E 17
I 17
	extern char *malloc(), *strcpy();
E 17

D 17
	p = malloc(strlen(s) + 1);
E 17
I 17
	p = malloc((unsigned) strlen(s) + 1);
E 17
	if (p == NULL)
		fatal("Ran out of memory.");
D 17
	strcpy(p, s);
E 17
I 17
	(void) strcpy(p, s);
E 17
	return ((int)p);
}

help(s)
	char *s;
{
	register struct tab *c;
	register int width, NCMDS;

	width = 0, NCMDS = 0;
	for (c = cmdtab; c->name != NULL; c++) {
D 22
		int len = strlen(c->name);
E 22
I 22
		int len = strlen(c->name) + 1;
E 22

D 22
		if (c->implemented == 0)
			len++;
E 22
		if (len > width)
			width = len;
		NCMDS++;
	}
	width = (width + 8) &~ 7;
	if (s == 0) {
		register int i, j, w;
		int columns, lines;

		lreply(214,
	  "The following commands are recognized (* =>'s unimplemented).");
		columns = 76 / width;
		if (columns == 0)
			columns = 1;
		lines = (NCMDS + columns - 1) / columns;
		for (i = 0; i < lines; i++) {
D 18
			printf("    ");
E 18
I 18
			printf("   ");
E 18
			for (j = 0; j < columns; j++) {
				c = cmdtab + j * lines + i;
				printf("%s%c", c->name,
					c->implemented ? ' ' : '*');
D 2
				if (c + lines >= &cmdtab[NCMDS]) {
					printf("\r\n");
E 2
I 2
				if (c + lines >= &cmdtab[NCMDS])
E 2
					break;
D 2
				}
E 2
D 22
				w = strlen(c->name);
E 22
I 22
				w = strlen(c->name) + 1;
E 22
				while (w < width) {
					putchar(' ');
					w++;
				}
			}
			printf("\r\n");
		}
D 17
		fflush(stdout);
E 17
I 17
		(void) fflush(stdout);
E 17
		reply(214, "Direct comments to ftp-bugs@%s.", hostname);
		return;
	}
	upper(s);
	c = lookup(s);
	if (c == (struct tab *)0) {
D 18
		reply(504, "Unknown command %s.", s);
E 18
I 18
		reply(502, "Unknown command %s.", s);
E 18
		return;
	}
	if (c->implemented)
		reply(214, "Syntax: %s %s", c->name, c->help);
	else
		reply(214, "%-*s\t%s; unimplemented.", width, c->name, c->help);
}
E 1
