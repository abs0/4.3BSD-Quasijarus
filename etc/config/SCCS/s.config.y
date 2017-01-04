h18007
s 00003/00001/00940
d D 5.11 04/03/20 02:16:01 msokolov 30 29
c add bva virtual bus support
e
s 00023/00002/00918
d D 5.10 04/03/06 21:34:49 msokolov 29 28
c introduce isadapter() function to tell if something is an adapter
c we have too many adapters now, need to centralise the list
e
s 00006/00005/00914
d D 5.9 04/03/02 17:49:25 msokolov 28 27
c redesign handling of VAXBI and peripheral nexus devices
e
s 00011/00006/00908
d D 5.8 88/06/18 13:43:00 bostic 27 26
c install approved copyright notice
e
s 00013/00014/00901
d D 5.7 88/05/21 16:40:46 karels 26 25
c pretend bi's connect to nexi; delete unnecessary keywords
e
s 00001/00000/00914
d D 5.6 87/10/28 15:55:58 mckusick 25 24
c initialize linked list pointer (4.3BSD/etc/96 alex@cca.cca.com)
e
s 00019/00010/00895
d D 5.5 87/10/22 11:07:57 bostic 24 23
c ANSI C; sprintf now returns an int.
e
s 00001/00001/00904
d D 5.4 87/10/14 18:24:15 bostic 23 22
c yyline is zero based
e
s 00011/00006/00894
d D 5.3 86/10/13 15:35:29 sam 22 21
c replace ancient sun support with tahoe support
e
s 00021/00000/00879
d D 5.2 86/04/18 14:24:56 karels 21 20
c add makeoptions (for uVaxII and other such needs)
e
s 00007/00001/00872
d D 5.1 85/05/08 11:59:01 dist 20 19
c Add copyright
e
s 00001/00000/00872
d D 1.19 84/12/04 10:38:56 karels 19 18
c implement swapsize
e
s 00008/00000/00864
d D 1.18 83/05/18 12:17:06 sam 18 17
c provide for dst on the other side of the world (from robert)
e
s 00439/00016/00425
d D 1.17 83/05/18 00:19:31 sam 17 16
c dynamically create swap configuration files
e
s 00177/00123/00264
d D 1.16 82/10/25 00:58:43 root 16 15
c lint and cleanup
e
s 00108/00119/00279
d D 1.15 82/10/24 23:13:50 root 15 14
c fixups
e
s 00032/00008/00366
d D 1.14 82/10/24 22:52:58 root 14 13
c fixes from sun
e
s 00028/00004/00346
d D 1.13 82/07/21 22:34:45 kre 13 12
c permit options to have values (viz: options name="value");
c allow number of pseudo-dev's to be specified (viz: pseu.. pty 16);
c fix nonsense timezone validity test.
e
s 00004/00004/00346
d D 1.12 82/07/13 22:02:10 kre 12 11
c make spec of timezones east of Greenwich rational
e
s 00010/00004/00340
d D 1.11 81/05/22 16:39:45 root 11 10
c allow arb number of VECTOR list entries
e
s 00009/00001/00335
d D 1.10 81/05/18 01:30:34 root 10 9
c implement - timezones
e
s 00002/00003/00334
d D 1.9 81/05/18 01:02:15 root 9 8
c hz not needed; always 60
e
s 00002/00001/00335
d D 1.8 81/04/28 01:53:25 root 8 7
c fix to PSEUDO-DEV production
e
s 00001/00001/00335
d D 1.7 81/04/02 23:22:37 root 7 6
c cd ..
e
s 00002/00002/00334
d D 1.6 81/04/02 17:45:20 toy 6 5
c Added quoated identifiers
e
s 00059/00011/00277
d D 1.5 81/03/31 16:37:14 toy 5 4
c 
e
s 00061/00014/00227
d D 1.4 81/03/06 21:36:57 toy 4 3
c Bill's changes + some of mine
e
s 00004/00001/00237
d D 1.3 81/02/26 01:44:15 wnj 3 2
c put away mikes stuff
e
s 00069/00010/00169
d D 1.2 81/02/25 18:29:14 toy 2 1
c Added connection to ?
e
s 00179/00000/00000
d D 1.1 81/02/24 21:11:42 toy 1 0
c date and time created 81/02/24 21:11:42 by toy
e
u
U
t
T
I 16
%union {
	char	*str;
	int	val;
I 17
	struct	file_list *file;
E 17
	struct	idlst *lst;
}

I 17
%token	AND
%token	ANY
%token	ARGS
%token	AT
%token	COMMA
%token	CONFIG
%token	CONTROLLER
%token	CPU
%token	CSR
%token	DEVICE
%token	DISK
%token	DRIVE
%token	DST
%token	DUMPS
%token	EQUALS
%token	FLAGS
%token	HZ
%token	IDENT
E 17
E 16
I 14
D 15
%token MACHINE
E 14
I 1
D 5
%token CPU IDENT CONFIG ANY DEVICE UBA MBA NEXUS CSR DRIVE VECTOR
D 4
%token CONTROLLER PSEUDO_DEVICE FLAGS ID SEMICOLON NUMBER OPTIONS TRACE
%token DISK SLAVE AT
E 4
I 4
%token CONTROLLER PSEUDO_DEVICE FLAGS ID SEMICOLON NUMBER FPNUMBER OPTIONS TRACE
%token DISK SLAVE AT HZ TIMEZONE DST MAXUSERS
E 5
I 5
%token CPU IDENT CONFIG ANY DEVICE UBA MBA NEXUS CSR DRIVE VECTOR OPTIONS
%token CONTROLLER PSEUDO_DEVICE FLAGS ID SEMICOLON NUMBER FPNUMBER TRACE
D 10
%token DISK SLAVE AT HZ TIMEZONE DST MAXUSERS MASTER COMMA
E 10
I 10
D 13
%token DISK SLAVE AT HZ TIMEZONE DST MAXUSERS MASTER COMMA MINUS
E 13
I 13
D 14
%token DISK SLAVE AT HZ TIMEZONE DST MAXUSERS MASTER COMMA MINUS EQUALS
E 14
I 14
%token DISK SLAVE AT HZ TIMEZONE DST MAXUSERS MASTER PRIORITY COMMA MINUS EQUALS
E 15
I 15
%token	MACHINE
D 17
%token	CPU IDENT CONFIG ANY DEVICE UBA MBA NEXUS CSR DRIVE VECTOR OPTIONS
D 16
%token	CONTROLLER PSEUDO_DEVICE FLAGS ID SEMICOLON NUMBER FPNUMBER TRACE
%token	DISK SLAVE AT HZ TIMEZONE DST MAXUSERS
%token	MASTER PRIORITY COMMA MINUS EQUALS
E 16
I 16
%token	CONTROLLER PSEUDO_DEVICE FLAGS SEMICOLON TRACE
%token	DISK SLAVE HZ TIMEZONE DST MAXUSERS
%token	MASTER PRIORITY COMMA MINUS EQUALS AT
E 17
I 17
%token	MAJOR
%token	MASTER
%token	MAXUSERS
D 26
%token	MBA
E 26
%token	MINOR
%token	MINUS
%token	NEXUS
I 28
%token	NODE
E 28
%token	ON
%token	OPTIONS
I 21
%token	MAKEOPTIONS
E 21
%token	PRIORITY
%token	PSEUDO_DEVICE
%token	ROOT
%token	SEMICOLON
%token	SIZE
%token	SLAVE
%token	SWAP
%token	TIMEZONE
%token	TRACE
D 26
%token	UBA
I 22
%token	VBA
E 26
E 22
%token	VECTOR
E 17

%token	<str>	ID
%token	<val>	NUMBER
%token	<val>	FPNUMBER

%type	<str>	Save_id
%type	<str>	Opt_value
%type	<str>	Dev
%type	<lst>	Id_list
I 17
%type	<val>	optional_size
%type	<str>	device_name
%type	<val>	major_minor
%type	<val>	arg_device_spec
%type	<val>	root_device_spec
%type	<val>	dump_device_spec
%type	<file>	swap_device_spec
E 17

E 16
E 15
E 14
E 13
E 10
E 5
E 4
%{
I 14

E 14
D 20
/*	%M%	%I%	%E%	*/
E 20
I 20
/*
D 27
 * Copyright (c) 1980 Regents of the University of California.
E 27
I 27
 * Copyright (c) 1988 Regents of the University of California.
E 27
D 26
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 26
I 26
 * All rights reserved.
E 26
 *
I 26
 * Redistribution and use in source and binary forms are permitted
D 27
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 27
I 27
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
E 27
 *
E 26
 *	%W% (Berkeley) %G%
 */
E 20
I 14

E 14
#include "config.h"
I 17
#include <ctype.h>
E 17
#include <stdio.h>
D 15
	struct device cur;
I 5
	struct device *curp = NULL;
E 5
	char *temp_id;
I 13
	char *val_id;
E 15
I 15

struct	device cur;
struct	device *curp = 0;
char	*temp_id;
char	*val_id;
I 16
char	*malloc();
E 16

E 15
E 13
%}
%%
Configuration:
	Many_specs
I 17
		= { verifysystemspecs(); }
E 17
D 16
	;
E 16
I 16
		;
E 16

Many_specs:
	Many_specs Spec
D 16
	|
	;
E 16
I 16
		|
	/* lambda */
		;
E 16

Spec:
D 16
	Device_spec SEMICOLON  = { newdev(&cur); } |
	Config_spec SEMICOLON |
	TRACE SEMICOLON = { do_trace = ! do_trace; } |
	SEMICOLON |
E 16
I 16
	Device_spec SEMICOLON
	      = { newdev(&cur); } |
	Config_spec SEMICOLON
		|
	TRACE SEMICOLON
	      = { do_trace = !do_trace; } |
	SEMICOLON
		|
E 16
	error SEMICOLON
D 16
	;
E 16
I 16
		;
E 16

Config_spec:
I 14
D 16
	MACHINE Save_id = {
E 16
I 16
	MACHINE Save_id
	    = {
E 16
		if (!strcmp($2, "vax")) {
			machine = MACHINE_VAX;
			machinename = "vax";
D 22
		} else if (!strcmp($2, "sun")) {
			machine = MACHINE_SUN;
			machinename = "sun";
E 22
I 22
		} else if (!strcmp($2, "tahoe")) {
			machine = MACHINE_TAHOE;
			machinename = "tahoe";
E 22
		} else
			yyerror("Unknown machine type");
D 16
		} |
E 14
D 3
	CPU ID NUMBER = { cpu_type = ns(sprintf(errbuf, "%s%d", $2, $3)); } |
E 3
I 3
D 6
	CPU Save_id NUMBER = {
E 6
I 6
	CPU Save_id = {
E 6
D 4
		    cpu_type = ns(sprintf(errbuf, "%s%d", $2, $3));
E 4
I 4
		    struct cputype *cp = malloc(sizeof (struct cputype));
D 6
		    cp->cpu_name = ns(sprintf(errbuf, "%s%d", $2, $3));
E 6
I 6
		    cp->cpu_name = ns($2);
E 6
		    cp->cpu_next = cputype;
		    cputype = cp;
E 4
		    free(temp_id);
		    } |
I 5
	OPTIONS Opt_list |
E 5
E 3
D 14
	IDENT ID { ident = ns($2); } |
E 14
I 14
	IDENT ID = { ident = ns($2); } |
E 14
D 4
	CONFIG Save_id ID = { mkconf(temp_id, $3); free(temp_id); }
E 4
I 4
	CONFIG Save_id ID = { mkconf(temp_id, $3); free(temp_id); } |
	HZ NUMBER = {
D 9
		hz = $2;
		if (hz != 50 && hz != 60)
		    yyerror("strange value for HZ");
E 9
I 9
		yyerror("HZ specification obsolete; delete");
		hz = 60;
E 9
		} |
	TIMEZONE NUMBER = { timezone = 60 * $2; check_tz(); } |
	TIMEZONE NUMBER DST = { timezone = 60 * $2; dst = 1; check_tz(); } |
	TIMEZONE FPNUMBER = { timezone = $2; check_tz(); } |
	TIMEZONE FPNUMBER DST = { timezone = $2; dst = 1; check_tz(); } |
I 10
D 12
	MINUS TIMEZONE NUMBER =
E 12
I 12
	TIMEZONE MINUS NUMBER =
E 12
	    { timezone = -60 * $3; check_tz(); } |
D 12
	MINUS TIMEZONE NUMBER DST =
E 12
I 12
	TIMEZONE MINUS NUMBER DST =
E 12
	    { timezone = -60 * $3; dst = 1; check_tz(); } |
D 12
	MINUS TIMEZONE FPNUMBER =
E 12
I 12
	TIMEZONE MINUS FPNUMBER =
E 12
	    { timezone = -$3; check_tz(); } |
D 12
	MINUS TIMEZONE FPNUMBER DST =
E 12
I 12
	TIMEZONE MINUS FPNUMBER DST =
E 12
	    { timezone = -$3; dst = 1; check_tz(); } |
E 10
	MAXUSERS NUMBER = { maxusers = $2; }
E 4
	;
E 16
I 16
	      } |
	CPU Save_id
	      = {
		struct cputype *cp =
		    (struct cputype *)malloc(sizeof (struct cputype));
		cp->cpu_name = ns($2);
		cp->cpu_next = cputype;
		cputype = cp;
		free(temp_id);
	      } |
	OPTIONS Opt_list
		|
I 21
	MAKEOPTIONS Mkopt_list
		|
E 21
	IDENT ID
	      = { ident = ns($2); } |
D 17
	CONFIG Save_id ID
	      = { mkconf(temp_id, $3); free(temp_id); } |
E 17
I 17
	System_spec
		|
E 17
	HZ NUMBER
	      = { yyerror("HZ specification obsolete; delete"); } |
	TIMEZONE NUMBER
	      = { timezone = 60 * $2; check_tz(); } |
I 18
	TIMEZONE NUMBER DST NUMBER
	      = { timezone = 60 * $2; dst = $4; check_tz(); } |
E 18
	TIMEZONE NUMBER DST
	      = { timezone = 60 * $2; dst = 1; check_tz(); } |
	TIMEZONE FPNUMBER
	      = { timezone = $2; check_tz(); } |
I 18
	TIMEZONE FPNUMBER DST NUMBER
	      = { timezone = $2; dst = $4; check_tz(); } |
E 18
	TIMEZONE FPNUMBER DST
	      = { timezone = $2; dst = 1; check_tz(); } |
	TIMEZONE MINUS NUMBER
	      = { timezone = -60 * $3; check_tz(); } |
I 18
	TIMEZONE MINUS NUMBER DST NUMBER
	      = { timezone = -60 * $3; dst = $5; check_tz(); } |
E 18
	TIMEZONE MINUS NUMBER DST
	      = { timezone = -60 * $3; dst = 1; check_tz(); } |
	TIMEZONE MINUS FPNUMBER
	      = { timezone = -$3; check_tz(); } |
I 18
	TIMEZONE MINUS FPNUMBER DST NUMBER
	      = { timezone = -$3; dst = $5; check_tz(); } |
E 18
	TIMEZONE MINUS FPNUMBER DST
	      = { timezone = -$3; dst = 1; check_tz(); } |
	MAXUSERS NUMBER
	      = { maxusers = $2; };
E 16

I 17
System_spec:
	  System_id System_parameter_list
		= { checksystemspec(*confp); }
	;
		
System_id:
	  CONFIG Save_id
		= { mkconf($2); }
	;

System_parameter_list:
	  System_parameter_list System_parameter
	| System_parameter
	;

System_parameter:
	  swap_spec
	| root_spec
	| dump_spec
	| arg_spec
	;
	
swap_spec:
	  SWAP optional_on swap_device_list
	;
	
swap_device_list:
	  swap_device_list AND swap_device
	| swap_device
	;
	
swap_device:
	  swap_device_spec optional_size
	      = { mkswap(*confp, $1, $2); }
	;

swap_device_spec:
	  device_name
		= {
			struct file_list *fl = newswap();

			if (eq($1, "generic"))
				fl->f_fn = $1;
			else {
				fl->f_swapdev = nametodev($1, 0, 'b');
				fl->f_fn = devtoname(fl->f_swapdev);
			}
			$$ = fl;
		}
	| major_minor
		= {
			struct file_list *fl = newswap();

			fl->f_swapdev = $1;
			fl->f_fn = devtoname($1);
			$$ = fl;
		}
	;

root_spec:
	  ROOT optional_on root_device_spec
		= {
			struct file_list *fl = *confp;

			if (fl && fl->f_rootdev != NODEV)
				yyerror("extraneous root device specification");
			else
				fl->f_rootdev = $3;
		}
	;

root_device_spec:
	  device_name
		= { $$ = nametodev($1, 0, 'a'); }
	| major_minor
	;

dump_spec:
	  DUMPS optional_on dump_device_spec
		= {
			struct file_list *fl = *confp;

			if (fl && fl->f_dumpdev != NODEV)
				yyerror("extraneous dump device specification");
			else
				fl->f_dumpdev = $3;
		}

	;

dump_device_spec:
	  device_name
		= { $$ = nametodev($1, 0, 'b'); }
	| major_minor
	;

arg_spec:
	  ARGS optional_on arg_device_spec
		= {
			struct file_list *fl = *confp;

			if (fl && fl->f_argdev != NODEV)
				yyerror("extraneous arg device specification");
			else
				fl->f_argdev = $3;
		}
	;

arg_device_spec:
	  device_name
		= { $$ = nametodev($1, 0, 'b'); }
	| major_minor
	;

major_minor:
	  MAJOR NUMBER MINOR NUMBER
		= { $$ = makedev($2, $4); }
	;

optional_on:
	  ON
	| /* empty */
	;

optional_size:
	  SIZE NUMBER
	      = { $$ = $2; }
	| /* empty */
	      = { $$ = 0; }
	;

device_name:
	  Save_id
		= { $$ = $1; }
	| Save_id NUMBER
		= {
			char buf[80];

			(void) sprintf(buf, "%s%d", $1, $2);
			$$ = ns(buf); free($1);
		}
	| Save_id NUMBER ID
		= {
			char buf[80];

			(void) sprintf(buf, "%s%d%s", $1, $2, $3);
			$$ = ns(buf); free($1);
		}
	;

E 17
I 5
Opt_list:
D 16
	Opt_list COMMA Option |
E 16
I 16
	Opt_list COMMA Option
		|
E 16
	Option
D 16
	;
E 16
I 16
		;
E 16

Option:
D 16
	Save_id = {
		    struct opt *op = malloc(sizeof (struct opt));
		    op->op_name = ns($1);
		    op->op_next = opt;
I 13
D 15
		    op->op_value = NULL;
E 15
I 15
		    op->op_value = 0;
E 15
E 13
		    opt = op;
		    free(temp_id);
I 13
	} |
	Save_id EQUALS Opt_value = {
		    struct opt *op = malloc(sizeof (struct opt));
		    op->op_name = ns($1);
		    op->op_next = opt;
		    op->op_value = ns($3);
		    opt = op;
		    free(temp_id);
		    free(val_id);
E 13
	}
	;
E 16
I 16
	Save_id
	      = {
		struct opt *op = (struct opt *)malloc(sizeof (struct opt));
		op->op_name = ns($1);
		op->op_next = opt;
		op->op_value = 0;
		opt = op;
		free(temp_id);
	      } |
	Save_id EQUALS Opt_value
	      = {
		struct opt *op = (struct opt *)malloc(sizeof (struct opt));
		op->op_name = ns($1);
		op->op_next = opt;
		op->op_value = ns($3);
		opt = op;
		free(temp_id);
		free(val_id);
	      } ;
E 16

I 13
Opt_value:
D 16
	ID = { $$ = val_id = ns($1); } |
	NUMBER = { char nb[16]; sprintf(nb, "%d", $1); $$ = val_id = ns(nb); }
	;
E 16
I 16
	ID
	      = { $$ = val_id = ns($1); } |
	NUMBER
D 24
	      = { char nb[16]; $$ = val_id = ns(sprintf(nb, "%d", $1)); };
E 24
I 24
	      = {
		char nb[16];
	        (void) sprintf(nb, "%d", $1);
		$$ = val_id = ns(nb);
	      } ;
E 24
E 16


E 13
E 5
Save_id:
D 16
	ID = { $$ = temp_id = ns($1); }
E 16
I 16
	ID
	      = { $$ = temp_id = ns($1); }
E 16
	;
I 21

Mkopt_list:
	Mkopt_list COMMA Mkoption
		|
	Mkoption
		;

Mkoption:
	Save_id EQUALS Opt_value
	      = {
		struct opt *op = (struct opt *)malloc(sizeof (struct opt));
		op->op_name = ns($1);
		op->op_next = mkopt;
		op->op_value = ns($3);
		mkopt = op;
		free(temp_id);
		free(val_id);
	      } ;
E 21

Dev:
D 16
	UBA  = { $$ = ns("uba"); } |
	MBA  = { $$ = ns("mba"); } |
	ID = { $$ = ns($1); }
E 16
I 16
D 26
	UBA
	      = { $$ = ns("uba"); } |
I 22
	VBA
	      = { $$ = ns("vba"); } |
E 22
	MBA
	      = { $$ = ns("mba"); } |
E 26
	ID
	      = { $$ = ns($1); }
E 16
	;

Device_spec:
D 16
	DEVICE Dev_name Dev_info Int_spec = {  cur.d_type = DEVICE; } |
I 5
	MASTER Dev_name Dev_info Int_spec = {  cur.d_type = MASTER; } |
E 5
	DISK Dev_name Dev_info Int_spec =
				{  cur.d_dk = 1; cur.d_type = DEVICE; } |
	CONTROLLER Dev_name Dev_info Int_spec = {  cur.d_type = CONTROLLER; } |
D 7
	PSEUDO_DEVICE Dev_name = { cur.d_type = PSEUDO_DEVICE ; }
E 7
I 7
D 8
	PSEUDO_DEVICE Init_dev Dev = { cur.d_type = PSEUDO_DEVICE ; }
E 8
I 8
D 13
	PSEUDO_DEVICE Init_dev Dev =
			{ cur.d_name = $3; cur.d_type = PSEUDO_DEVICE; }
E 13
I 13
	PSEUDO_DEVICE Init_dev Dev = {
			cur.d_name = $3;
			cur.d_type = PSEUDO_DEVICE;
		  } |
	PSEUDO_DEVICE Init_dev Dev NUMBER = {
			cur.d_name = $3;
			cur.d_type = PSEUDO_DEVICE;
			cur.d_slave = $4;
		}
E 13
E 8
E 7
	;
E 16
I 16
	DEVICE Dev_name Dev_info Int_spec
	      = { cur.d_type = DEVICE; } |
	MASTER Dev_name Dev_info Int_spec
	      = { cur.d_type = MASTER; } |
	DISK Dev_name Dev_info Int_spec
	      = { cur.d_dk = 1; cur.d_type = DEVICE; } |
	CONTROLLER Dev_name Dev_info Int_spec
	      = { cur.d_type = CONTROLLER; } |
	PSEUDO_DEVICE Init_dev Dev
	      = {
		cur.d_name = $3;
		cur.d_type = PSEUDO_DEVICE;
		} |
	PSEUDO_DEVICE Init_dev Dev NUMBER
	      = {
		cur.d_name = $3;
		cur.d_type = PSEUDO_DEVICE;
		cur.d_slave = $4;
		};
E 16

Dev_name:
D 16
	Init_dev Dev NUMBER =	{
			cur.d_name = $2;
			if (eq($2, "mba"))
D 15
			    seen_mba = TRUE;
E 15
I 15
			    seen_mba = 1;
E 15
			else if (eq($2, "uba"))
D 15
			    seen_uba = TRUE;
E 15
I 15
			    seen_uba = 1;
E 15
			cur.d_unit = $3;
		}
	;
E 16
I 16
	Init_dev Dev NUMBER
	      = {
		cur.d_name = $2;
		if (eq($2, "mba"))
			seen_mba = 1;
		else if (eq($2, "uba"))
			seen_uba = 1;
I 30
		else if (eq($2, "bva"))
			seen_bva = 1;
E 30
I 22
		else if (eq($2, "vba"))
			seen_vba = 1;
E 22
		cur.d_unit = $3;
		};
E 16

Init_dev:
D 2
	= {
		cur.d_name = "OHNO!!!";
		cur.d_type = DEVICE;
		cur.d_conn = NULL;
		cur.d_vec1 = cur.d_vec2 = NULL;
		cur.d_addr = cur.d_flags = cur.d_dk = 0;
		cur.d_slave = cur.d_drive = cur.d_unit = -1;
	}
E 2
I 2
D 16
	= { init_dev(&cur); }
E 2
	;
E 16
I 16
	/* lambda */
	      = { init_dev(&cur); };
E 16

Dev_info:
	Con_info Info_list
D 16
	|
	;
E 16
I 16
		|
	/* lambda */
		;
E 16

Con_info:
D 5
	AT Dev NUMBER = { cur.d_conn = connect($2, $3); } |
D 4
	AT NEXUS NUMBER = { cur.d_conn = -1; }
E 4
I 4
	AT NEXUS NUMBER = { check_nexus(&cur, $2); cur.d_conn = TO_NEXUS; }
E 5
I 5
D 16
	AT Dev NUMBER = {
E 16
I 16
	AT Dev NUMBER
	      = {
E 16
D 24
		if (eq(cur.d_name, "mba") || eq(cur.d_name, "uba"))
			yyerror(sprintf(errbuf,
D 16
				"%s must be connected to a nexus", cur.d_name));
E 16
I 16
			    "%s must be connected to a nexus", cur.d_name));
E 24
I 24
D 28
		if (eq(cur.d_name, "mba") || eq(cur.d_name, "uba")) {
E 28
I 28
D 29
		if (eq(cur.d_name, "mba") || eq(cur.d_name, "uba") ||
		    eq(cur.d_name, "vaxbi") || eq(cur.d_name, "xmi")) {
E 29
I 29
		if (isadapter(cur.d_name)) {
E 29
E 28
			(void) sprintf(errbuf,
				"%s must be connected to a nexus", cur.d_name);
			yyerror(errbuf);
		}
E 24
E 16
		cur.d_conn = connect($2, $3);
D 16
	} |
	AT NEXUS NUMBER = { check_nexus(&cur, $3); cur.d_conn = TO_NEXUS; }
E 5
E 4
	;
E 16
I 16
		} |
	AT NEXUS NUMBER
	      = { check_nexus(&cur, $3); cur.d_conn = TO_NEXUS; };
E 16
    
Info_list:
	Info_list Info
D 16
	|
	;
E 16
I 16
		|
	/* lambda */
		;
E 16

Info:
D 16
	CSR NUMBER = { cur.d_addr = $2; } |
	DRIVE NUMBER = { cur.d_drive = $2; } |
D 5
	SLAVE NUMBER = { cur.d_slave = $2; } |
E 5
I 5
	SLAVE NUMBER =
	{
D 15
		if (cur.d_conn != NULL && cur.d_conn != TO_NEXUS
E 15
I 15
		if (cur.d_conn != 0 && cur.d_conn != TO_NEXUS
E 15
		    && cur.d_conn->d_type == MASTER)
E 16
I 16
	CSR NUMBER
	      = { cur.d_addr = $2; } |
I 28
	NODE NUMBER
	      = { cur.d_node = $2; } |
E 28
	DRIVE NUMBER
	      = { cur.d_drive = $2; } |
	SLAVE NUMBER
	      = {
		if (cur.d_conn != 0 && cur.d_conn != TO_NEXUS &&
		    cur.d_conn->d_type == MASTER)
E 16
			cur.d_slave = $2;
		else
			yyerror("can't specify slave--not to master");
D 16
	} |
E 5
	FLAGS NUMBER = { cur.d_flags = $2; }
	;
E 16
I 16
		} |
	FLAGS NUMBER
	      = { cur.d_flags = $2; };
E 16

Int_spec:
D 11
	VECTOR Save_id = { cur.d_vec1 = $2; } |
	VECTOR Save_id ID = { cur.d_vec1 = $2; cur.d_vec2 = ns($3); } |
	;
E 11
I 11
D 14
	VECTOR Id_list = { cur.d_vec = $2; } | ;
E 14
I 14
D 16
	VECTOR Id_list = { cur.d_vec = $2; } |
	PRIORITY NUMBER = { cur.d_pri = $2; } |
	;
E 16
I 16
	VECTOR Id_list
	      = { cur.d_vec = $2; } |
	PRIORITY NUMBER
	      = { cur.d_pri = $2; } |
	/* lambda */
		;
E 16
E 14

Id_list:
D 16
	Save_id =
	    { struct idlst *a = (struct idlst *)malloc(sizeof(struct idlst));
	      a->id = $1; a->id_next = 0; $$ = a; } |
E 16
I 16
	Save_id
	      = {
		struct idlst *a = (struct idlst *)malloc(sizeof(struct idlst));
		a->id = $1; a->id_next = 0; $$ = a;
		} |
E 16
	Save_id Id_list =
D 16
	    { struct idlst *a = (struct idlst *)malloc(sizeof(struct idlst));
	      a->id = $1; a->id_next = $2; $$ = a; } ;
E 16
I 16
		{
		struct idlst *a = (struct idlst *)malloc(sizeof(struct idlst));
	        a->id = $1; a->id_next = $2; $$ = a;
		};

E 16
E 11
%%

yyerror(s)
D 15
char *s;
E 15
I 15
	char *s;
E 15
{
I 15

E 15
D 17
	fprintf(stderr, "config: %s at line %d\n", s, yyline);
E 17
I 17
D 23
	fprintf(stderr, "config: line %d: %s\n", yyline, s);
E 23
I 23
	fprintf(stderr, "config: line %d: %s\n", yyline + 1, s);
E 23
E 17
}

/*
D 15
 * ns:
 *	Return the passed string in a new space
E 15
I 15
 * return the passed string in a new space
E 15
 */
D 15

E 15
char *
ns(str)
D 15
register char *str;
E 15
I 15
	register char *str;
E 15
{
	register char *cp;

D 16
	cp = malloc(strlen(str)+1);
	strcpy(cp, str);
	return cp;
E 16
I 16
	cp = malloc((unsigned)(strlen(str)+1));
	(void) strcpy(cp, str);
	return (cp);
E 16
}

/*
D 15
 * newdev
 *	Add a device to the list
E 15
I 15
 * add a device to the list of devices
E 15
 */
D 15

E 15
newdev(dp)
D 15
register struct device *dp;
E 15
I 15
	register struct device *dp;
E 15
{
	register struct device *np;

	np = (struct device *) malloc(sizeof *np);
	*np = *dp;
I 25
	np->d_next = 0;
E 25
D 5
	np->d_next = dtab;
	dtab = np;
E 5
I 5
D 15
	if (curp == NULL)
E 15
I 15
	if (curp == 0)
E 15
		dtab = np;
	else
		curp->d_next = np;
	curp = np;
E 5
}

/*
D 15
 * mkconf
 *	Note that a configuration should be made
E 15
I 15
 * note that a configuration should be made
E 15
 */
D 15

E 15
D 17
mkconf(dev, sysname)
D 15
char *dev, *sysname;
E 15
I 15
	char *dev, *sysname;
E 17
I 17
mkconf(sysname)
	char *sysname;
E 17
E 15
{
D 17
	register struct file_list *fl;
E 17
I 17
	register struct file_list *fl, **flp;
E 17

	fl = (struct file_list *) malloc(sizeof *fl);
D 17
	fl->f_fn = ns(dev);
	fl->f_needs = ns(sysname);
D 15
	if (confp == NULL)
	    conf_list = fl;
E 15
I 15
	if (confp == 0)
		conf_list = fl;
E 17
I 17
	fl->f_type = SYSTEMSPEC;
	fl->f_needs = sysname;
	fl->f_rootdev = NODEV;
	fl->f_argdev = NODEV;
	fl->f_dumpdev = NODEV;
	fl->f_fn = 0;
	fl->f_next = 0;
	for (flp = confp; *flp; flp = &(*flp)->f_next)
		;
	*flp = fl;
	confp = flp;
}

struct file_list *
newswap()
{
	struct file_list *fl = (struct file_list *)malloc(sizeof (*fl));

	fl->f_type = SWAPSPEC;
	fl->f_next = 0;
	fl->f_swapdev = NODEV;
	fl->f_swapsize = 0;
	fl->f_needs = 0;
	fl->f_fn = 0;
	return (fl);
}

/*
 * Add a swap device to the system's configuration
 */
mkswap(system, fl, size)
	struct file_list *system, *fl;
	int size;
{
	register struct file_list **flp;
D 26
	char *cp, name[80];
E 26
I 26
	char name[80];
E 26

	if (system == 0 || system->f_type != SYSTEMSPEC) {
		yyerror("\"swap\" spec precedes \"config\" specification");
		return;
	}
	if (size < 0) {
		yyerror("illegal swap partition size");
		return;
	}
	/*
	 * Append swap description to the end of the list.
	 */
	flp = &system->f_next;
	for (; *flp && (*flp)->f_type == SWAPSPEC; flp = &(*flp)->f_next)
		;
	fl->f_next = *flp;
	*flp = fl;
I 19
	fl->f_swapsize = size;
E 19
	/*
	 * If first swap device for this system,
	 * set up f_fn field to insure swap
	 * files are created with unique names.
	 */
	if (system->f_fn)
		return;
	if (eq(fl->f_fn, "generic"))
		system->f_fn = ns(fl->f_fn);
E 17
E 15
	else
D 15
	    confp->f_next = fl;
E 15
I 15
D 17
		confp->f_next = fl;
E 15
	confp = fl;
E 17
I 17
		system->f_fn = ns(system->f_needs);
E 17
}

/*
D 15
 * Connect:
 *	Find the pointer to connect to the given device and number.
 *	returns NULL if no such device and prints an error message
E 15
I 15
 * find the pointer to connect to the given device and number.
 * returns 0 if no such device and prints an error message
E 15
 */
D 15

D 2
struct device *
connect(dev, num)
E 2
I 2
struct device *connect(dev, num)
E 2
register char *dev;
register int num;
E 15
I 15
struct device *
connect(dev, num)
	register char *dev;
	register int num;
E 15
{
	register struct device *dp;
I 2
	struct device *huhcon();
E 2

I 2
D 4
	if (num == -1)
E 4
I 4
	if (num == QUES)
E 4
D 15
	    return huhcon(dev);
E 2
	for (dp = dtab; dp != NULL; dp = dp->d_next)
D 4
		if ((num == dp->d_unit || num == -1)
		    && eq(dev, dp->d_name))
E 4
I 4
D 5
		if (num == dp->d_unit) && eq(dev, dp->d_name))
		    if (dp->d_type != CONTROLLER)
E 5
I 5
		if ((num == dp->d_unit) && eq(dev, dp->d_name))
		    if (dp->d_type != CONTROLLER && dp->d_type != MASTER)
E 5
		    {
E 15
I 15
		return (huhcon(dev));
	for (dp = dtab; dp != 0; dp = dp->d_next) {
		if ((num != dp->d_unit) || !eq(dev, dp->d_name))
			continue;
		if (dp->d_type != CONTROLLER && dp->d_type != MASTER) {
E 15
D 24
			yyerror(sprintf(errbuf,
			    "%s connected to non-controller", dev));
E 24
I 24
			(void) sprintf(errbuf,
			    "%s connected to non-controller", dev);
			yyerror(errbuf);
E 24
D 15
			return NULL;
		    }
		    else
E 4
			return dp;
E 15
I 15
			return (0);
		}
		return (dp);
	}
E 15
D 24
	yyerror(sprintf(errbuf, "%s %d not defined", dev, num));
E 24
I 24
	(void) sprintf(errbuf, "%s %d not defined", dev, num);
	yyerror(errbuf);
E 24
I 4
D 15
	return NULL;
E 15
I 15
	return (0);
E 15
E 4
I 2
}

/*
D 15
 * huhcon
 *	Connect to an unspecific thing
E 15
I 15
 * connect to an unspecific thing
E 15
 */
D 15

struct device *huhcon(dev)
register char *dev;
E 15
I 15
struct device *
huhcon(dev)
	register char *dev;
E 15
{
D 15
    register struct device *dp, *dcp;
    struct device rdev;
I 5
    int oldtype;
E 15
I 15
	register struct device *dp, *dcp;
	struct device rdev;
	int oldtype;
E 15
E 5

D 15
    /*
     * First make certain that there are some of these to wildcard on
     */
    for (dp = dtab; dp != NULL; dp = dp->d_next)
	if (eq(dp->d_name, dev))
	    break;
    if (dp == NULL)
    {
	yyerror(sprintf(errbuf, "no %s's to wildcard", dev));
	return NULL;
    }
I 5
    oldtype = dp->d_type;
E 5
    dcp = dp->d_conn;
    /*
     * Now see if there is already a wildcard entry for this device
I 4
     * (e.g. Search for a "uba ?")
E 4
     */
    for (; dp != NULL; dp = dp->d_next)
	if (eq(dev, dp->d_name) && dp->d_unit == -1)
	    break;
    /*
D 4
     * If there isn't, make one
E 4
I 4
     * If there isn't, make one becuase everything needs to be connected
     * to something.
E 4
     */
    if (dp == NULL)
    {
	dp = &rdev;
	init_dev(dp);
D 4
	dp->d_unit = -1;
E 4
I 4
	dp->d_unit = QUES;
E 4
	dp->d_name = ns(dev);
I 5
	dp->d_type = oldtype;
E 5
	newdev(dp);
D 5
	dp = dtab;
E 5
I 5
	dp = curp;
E 15
E 5
	/*
D 15
	 * Connect it to the same thing that other similar things are
	 * connected to, but make sure it is a wildcard unit
I 4
	 * (e.g. up connected to sc ?, here we make connect sc? to a uba?)
	 * If other things like this are on the NEXUS or if the aren't
	 * connected to anything, then make the same connection, else
	 * call ourself to connect to another unspecific device.
E 15
I 15
	 * First make certain that there are some of these to wildcard on
E 15
E 4
	 */
D 4
	if (dcp == -1 || dcp == NULL)
E 4
I 4
D 15
	if (dcp == TO_NEXUS || dcp == NULL)
E 4
	    dp->d_conn = dcp;
	else
D 4
	    dp->d_conn = connect(dcp->d_name, -1);
E 4
I 4
	    dp->d_conn = connect(dcp->d_name, QUES);
E 4
    }
    return dp;
E 15
I 15
	for (dp = dtab; dp != 0; dp = dp->d_next)
		if (eq(dp->d_name, dev))
			break;
	if (dp == 0) {
D 24
		yyerror(sprintf(errbuf, "no %s's to wildcard", dev));
E 24
I 24
		(void) sprintf(errbuf, "no %s's to wildcard", dev);
		yyerror(errbuf);
E 24
		return (0);
	}
	oldtype = dp->d_type;
	dcp = dp->d_conn;
	/*
	 * Now see if there is already a wildcard entry for this device
	 * (e.g. Search for a "uba ?")
	 */
	for (; dp != 0; dp = dp->d_next)
		if (eq(dev, dp->d_name) && dp->d_unit == -1)
			break;
	/*
	 * If there isn't, make one because everything needs to be connected
	 * to something.
	 */
	if (dp == 0) {
		dp = &rdev;
		init_dev(dp);
		dp->d_unit = QUES;
		dp->d_name = ns(dev);
		dp->d_type = oldtype;
		newdev(dp);
		dp = curp;
		/*
		 * Connect it to the same thing that other similar things are
		 * connected to, but make sure it is a wildcard unit
		 * (e.g. up connected to sc ?, here we make connect sc? to a
		 * uba?).  If other things like this are on the NEXUS or
		 * if they aren't connected to anything, then make the same
		 * connection, else call ourself to connect to another
		 * unspecific device.
		 */
		if (dcp == TO_NEXUS || dcp == 0)
			dp->d_conn = dcp;
		else
			dp->d_conn = connect(dcp->d_name, QUES);
	}
	return (dp);
E 15
}

I 4
D 15
/*
 * init_dev:
 *	Set up the fields in the current device to their
 *	default values.
 */

E 15
E 4
init_dev(dp)
D 15
register struct device *dp;
E 15
I 15
	register struct device *dp;
E 15
{
D 15
    dp->d_name = "OHNO!!!";
    dp->d_type = DEVICE;
    dp->d_conn = NULL;
D 11
    dp->d_vec1 = dp->d_vec2 = NULL;
E 11
I 11
    dp->d_vec = NULL;
E 11
D 14
    dp->d_addr = dp->d_flags = dp->d_dk = 0;
E 14
I 14
    dp->d_addr = dp->d_pri = dp->d_flags = dp->d_dk = 0;
E 14
D 4
    dp->d_slave = -1;
    dp->d_drive = dp->d_unit = -17;
E 4
I 4
    dp->d_slave = dp->d_drive = dp->d_unit = UNKNOWN;
E 15
I 15

	dp->d_name = "OHNO!!!";
	dp->d_type = DEVICE;
	dp->d_conn = 0;
	dp->d_vec = 0;
	dp->d_addr = dp->d_pri = dp->d_flags = dp->d_dk = 0;
D 28
	dp->d_slave = dp->d_drive = dp->d_unit = UNKNOWN;
E 28
I 28
	dp->d_node = dp->d_slave = dp->d_drive = dp->d_unit = UNKNOWN;
E 28
E 15
}

/*
D 15
 * Check_nexus:
 *	Make certain that this is a reasonable type of thing to put
 *	on the nexus.
E 15
I 15
 * make certain that this is a reasonable type of thing to connect to a nexus
E 15
 */
D 15

E 15
check_nexus(dev, num)
D 15
register struct device *dev;
int num;
E 15
I 15
	register struct device *dev;
	int num;
E 15
{
I 15

E 15
D 14
    if (!eq(dev->d_name, "uba") && !eq(dev->d_name, "mba"))
	yyerror("only uba's and mba's should be connected to the nexus");
    if (num != QUES)
	yyerror("can't give specific nexus numbers");
E 14
I 14
	switch (machine) {
I 15

E 15
	case MACHINE_VAX:
I 29
		/*
		 * With peripheral nexi, almost anything can now be connected
		 * to a VAX nexus.
		 */
E 29
D 26
		if (!eq(dev->d_name, "uba") && !eq(dev->d_name, "mba"))
			yyerror("only uba's and mba's should be connected to the nexus");
E 26
I 26
D 28
		if (!eq(dev->d_name, "uba") && !eq(dev->d_name, "mba") &&
		    !eq(dev->d_name, "bi"))
			yyerror("only uba's, mba's, and bi's should be connected to the nexus");
E 28
E 26
		if (num != QUES)
			yyerror("can't give specific nexus numbers");
		break;

D 22
	case MACHINE_SUN:
		if (!eq(dev->d_name, "mb"))
			yyerror("only mb's should be connected to the nexus");
E 22
I 22
	case MACHINE_TAHOE:
		if (!eq(dev->d_name, "vba")) 
			yyerror("only vba's should be connected to the nexus");
E 22
		break;
I 29
	}
}

isadapter(name)
	register char *name;
{
	switch (machine) {
	case MACHINE_VAX:
		if (eq(name, "uba") || eq(name, "mba") || eq(name, "vaxbi") ||
D 30
		    eq(name, "xmi"))
E 30
I 30
		    eq(name, "xmi") || eq(name, "bva"))
E 30
			return(1);
		else
			return(0);
	case MACHINE_TAHOE:
		if (eq(name, "vba"))
			return(1);
		else
			return(0);
E 29
	}
E 14
I 5
}

/*
 * Check the timezone to make certain it is sensible
 */

check_tz()
{
D 13
	if (timezone > 24 * 60)
E 13
I 13
	if (abs(timezone) > 12 * 60)
E 13
		yyerror("timezone is unreasonable");
	else
D 15
		hadtz = TRUE;
E 15
I 15
		hadtz = 1;
I 17
}

/*
 * Check system specification and apply defaulting
 * rules on root, argument, dump, and swap devices.
 */
checksystemspec(fl)
	register struct file_list *fl;
{
	char buf[BUFSIZ];
	register struct file_list *swap;
	int generic;

	if (fl == 0 || fl->f_type != SYSTEMSPEC) {
		yyerror("internal error, bad system specification");
		exit(1);
	}
	swap = fl->f_next;
	generic = swap && swap->f_type == SWAPSPEC && eq(swap->f_fn, "generic");
	if (fl->f_rootdev == NODEV && !generic) {
		yyerror("no root device specified");
		exit(1);
	}
	/*
	 * Default swap area to be in 'b' partition of root's
	 * device.  If root specified to be other than on 'a'
	 * partition, give warning, something probably amiss.
	 */
	if (swap == 0 || swap->f_type != SWAPSPEC) {
		dev_t dev;

		swap = newswap();
		dev = fl->f_rootdev;
		if (minor(dev) & 07) {
D 24
			sprintf(buf, 
E 24
I 24
			(void) sprintf(buf, 
E 24
"Warning, swap defaulted to 'b' partition with root on '%c' partition",
				(minor(dev) & 07) + 'a');
			yyerror(buf);
		}
		swap->f_swapdev =
		   makedev(major(dev), (minor(dev) &~ 07) | ('b' - 'a'));
		swap->f_fn = devtoname(swap->f_swapdev);
		mkswap(fl, swap, 0);
	}
	/*
	 * Make sure a generic swap isn't specified, along with
	 * other stuff (user must really be confused).
	 */
	if (generic) {
		if (fl->f_rootdev != NODEV)
			yyerror("root device specified with generic swap");
		if (fl->f_argdev != NODEV)
			yyerror("arg device specified with generic swap");
		if (fl->f_dumpdev != NODEV)
			yyerror("dump device specified with generic swap");
		return;
	}
	/*
	 * Default argument device and check for oddball arrangements.
	 */
	if (fl->f_argdev == NODEV)
		fl->f_argdev = swap->f_swapdev;
	if (fl->f_argdev != swap->f_swapdev)
		yyerror("Warning, arg device different than primary swap");
	/*
	 * Default dump device and warn if place is not a
	 * swap area or the argument device partition.
	 */
	if (fl->f_dumpdev == NODEV)
		fl->f_dumpdev = swap->f_swapdev;
	if (fl->f_dumpdev != swap->f_swapdev && fl->f_dumpdev != fl->f_argdev) {
		struct file_list *p = swap->f_next;

		for (; p && p->f_type == SWAPSPEC; p = p->f_next)
			if (fl->f_dumpdev == p->f_swapdev)
				return;
D 24
		sprintf(buf, "Warning, orphaned dump device, %s",
E 24
I 24
		(void) sprintf(buf, "Warning, orphaned dump device, %s",
E 24
			"do you know what you're doing");
		yyerror(buf);
	}
}

/*
 * Verify all devices specified in the system specification
 * are present in the device specifications.
 */
verifysystemspecs()
{
	register struct file_list *fl;
	dev_t checked[50], *verifyswap();
	register dev_t *pchecked = checked;

	for (fl = conf_list; fl; fl = fl->f_next) {
		if (fl->f_type != SYSTEMSPEC)
			continue;
		if (!finddev(fl->f_rootdev))
			deverror(fl->f_needs, "root");
		*pchecked++ = fl->f_rootdev;
		pchecked = verifyswap(fl->f_next, checked, pchecked);
#define	samedev(dev1, dev2) \
	((minor(dev1) &~ 07) != (minor(dev2) &~ 07))
		if (!alreadychecked(fl->f_dumpdev, checked, pchecked)) {
			if (!finddev(fl->f_dumpdev))
				deverror(fl->f_needs, "dump");
			*pchecked++ = fl->f_dumpdev;
		}
		if (!alreadychecked(fl->f_argdev, checked, pchecked)) {
			if (!finddev(fl->f_argdev))
				deverror(fl->f_needs, "arg");
			*pchecked++ = fl->f_argdev;
		}
	}
}

/*
 * Do as above, but for swap devices.
 */
dev_t *
verifyswap(fl, checked, pchecked)
	register struct file_list *fl;
	dev_t checked[];
	register dev_t *pchecked;
{

	for (;fl && fl->f_type == SWAPSPEC; fl = fl->f_next) {
		if (eq(fl->f_fn, "generic"))
			continue;
		if (alreadychecked(fl->f_swapdev, checked, pchecked))
			continue;
		if (!finddev(fl->f_swapdev))
			fprintf(stderr,
			   "config: swap device %s not configured", fl->f_fn);
		*pchecked++ = fl->f_swapdev;
	}
	return (pchecked);
}

/*
 * Has a device already been checked
 * for it's existence in the configuration?
 */
alreadychecked(dev, list, last)
	dev_t dev, list[];
	register dev_t *last;
{
	register dev_t *p;

	for (p = list; p < last; p++)
		if (samedev(*p, dev))
			return (1);
	return (0);
}

deverror(systemname, devtype)
	char *systemname, *devtype;
{

	fprintf(stderr, "config: %s: %s device not configured\n",
		systemname, devtype);
}

/*
 * Look for the device in the list of
 * configured hardware devices.  Must
 * take into account stuff wildcarded.
 */
I 26
/*ARGSUSED*/
E 26
finddev(dev)
	dev_t dev;
{

	/* punt on this right now */
	return (1);
E 17
E 15
E 5
E 4
E 2
}
E 1
