h57476
s 00001/00001/00172
d D 5.10 04/03/20 02:15:59 msokolov 24 23
c add bva virtual bus support
e
s 00001/00000/00172
d D 5.9 04/03/02 17:49:22 msokolov 23 22
c redesign handling of VAXBI and peripheral nexus devices
e
s 00010/00005/00162
d D 5.8 88/06/18 13:42:57 bostic 22 21
c install approved copyright notice
e
s 00008/00002/00159
d D 5.7 88/04/29 13:43:27 bostic 21 20
c add Berkeley specific header; original conception by Michael Toy
e
s 00000/00001/00161
d D 5.6 88/04/26 13:29:17 bostic 20 19
c PREFIX only used in main.c
e
s 00000/00001/00162
d D 5.5 87/10/22 10:53:29 bostic 19 18
c ANSI C; sprintf now returns an int.
e
s 00006/00002/00157
d D 5.4 86/10/13 15:35:26 sam 18 17
c replace ancient sun support with tahoe support
e
s 00002/00001/00157
d D 5.3 86/04/18 14:24:36 karels 17 16
c add makeoptions (for uVaxII and other such needs)
e
s 00001/00001/00157
d D 5.2 85/09/17 22:48:30 karels 16 15
c rename Makefile; allow files to be included multiple times
c to allow dependency disjunction; files may depend on options as well
c as devices, eliminating the need for corresponding pseudo-devices
e
s 00007/00001/00151
d D 5.1 85/05/08 11:58:49 dist 15 14
c Add copyright
e
s 00001/00001/00151
d D 1.14 84/08/20 21:43:49 mckusick 14 13
c update the comments
e
s 00011/00001/00141
d D 1.13 83/06/16 18:17:54 sam 13 12
c allow files to be marked config-dependent to get ${PARAMS}
e
s 00002/00001/00140
d D 1.12 83/05/18 12:17:48 sam 12 11
c new field for lyons' binary config stuff
e
s 00031/00002/00110
d D 1.11 83/05/18 00:19:21 sam 11 10
c dynamically create swap configuration files
e
s 00020/00014/00092
d D 1.10 82/10/25 00:58:29 root 10 9
c lint and cleanup
e
s 00003/00008/00103
d D 1.9 82/10/24 22:53:29 root 9 8
c get rid of bool, TRUE and FALSE
e
s 00085/00044/00026
d D 1.8 82/10/24 22:22:51 root 8 7
c machine and priority, also @ synonym for "at"
e
s 00009/00006/00061
d D 1.7 82/10/11 12:08:47 sam 7 6
c -p option to create profiling kernel
e
s 00001/00000/00066
d D 1.6 82/07/21 22:30:10 kre 6 5
c allow a value field for options
e
s 00006/00002/00060
d D 1.5 81/05/22 16:39:41 root 5 4
c allow arb number of VECTOR list entries
e
s 00004/00000/00058
d D 1.4 81/03/31 16:31:57 toy 4 3
c Added option structure
e
s 00010/00001/00048
d D 1.3 81/03/06 21:36:50 toy 3 2
c Bill's changes + some of mine
e
s 00001/00002/00048
d D 1.2 81/02/25 22:27:54 toy 2 1
c Made prefix right.
e
s 00050/00000/00000
d D 1.1 81/02/25 21:22:11 toy 1 0
c date and time created 81/02/25 21:22:11 by toy
e
u
U
t
T
I 8
D 15
/*	%M%	%I%	%E%	*/
E 15
I 15
/*
 * Copyright (c) 1980 Regents of the University of California.
D 21
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 21
I 21
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 22
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 22
I 22
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
E 22
E 21
 *
 *	%W% (Berkeley) %G%
 */
E 15

D 10
#define	machinename	machname

E 10
E 8
I 1
/*
D 8
 * %M%	%I%	%E%
 * Definitions that everybody needs to know
E 8
I 8
D 10
 * Definitions for config.
E 10
I 10
 * Config.
E 10
E 8
 */
I 11
#include <sys/types.h>

#define	NODEV	((dev_t)-1)

E 11
D 10

D 8
#define eq(a,b) (strcmp(a,b) == 0)
D 2
#define PREFIX "_unix/"
#define path(file) "_unix/file"
E 2
D 7
#define TRUE 1
#define FALSE 0
#define DRIVER 1
#define NORMAL 2
#define INVISIBLE 3
E 7
I 7
#define TRUE		1
#define FALSE		0
E 8
I 8
/*
 * Structures representing objects in config's world.
 */
E 8
E 7

I 3
D 7
#define TO_NEXUS -1
E 7
I 7
D 8
#define DRIVER		1
#define NORMAL		2
#define INVISIBLE	3
#define	PROFILING	4
E 7

E 8
I 7
#define TO_NEXUS	-1

E 10
E 7
E 3
struct file_list {
I 11
	struct	file_list *f_next;	
E 11
D 8
	char *f_fn;
	int f_type;
	char *f_next;
	char *f_needs;
E 8
I 8
	char	*f_fn;			/* the name */
D 12
	int	f_type;			/* see below */
E 12
I 12
D 13
	short	f_type;			/* see below */
E 13
I 13
	u_char	f_type;			/* see below */
	u_char	f_flags;		/* see below */
E 13
	short	f_special;		/* requires special make rule */
E 12
D 11
	struct	file_list *f_next;	
E 11
	char	*f_needs;
I 11
	/*
	 * Random values:
	 *	swap space parameters for swap areas
	 *	root device, etc. for system specifications
	 */
	union {
		struct {		/* when swap specification */
			dev_t	fuw_swapdev;
			int	fuw_swapsize;
		} fuw;
		struct {		/* when system specification */
			dev_t	fus_rootdev;
			dev_t	fus_argdev;
			dev_t	fus_dumpdev;
		} fus;
	} fun;
#define	f_swapdev	fun.fuw.fuw_swapdev
#define	f_swapsize	fun.fuw.fuw_swapsize
#define	f_rootdev	fun.fus.fus_rootdev
#define	f_argdev	fun.fus.fus_argdev
#define	f_dumpdev	fun.fus.fus_dumpdev
E 11
E 8
};
I 13

/*
 * Types.
 */
E 13
I 8
#define DRIVER		1
#define NORMAL		2
#define	INVISIBLE	3
#define	PROFILING	4
I 11
#define	SYSTEMSPEC	5
#define	SWAPSPEC	6
I 13

/*
 * Attributes (flags).
 */
#define	CONFIGDEP	1
E 13
E 11
E 8

I 5
struct	idlst {
D 8
	char *id;
	struct idlst *id_next;
E 8
I 8
	char	*id;
	struct	idlst *id_next;
E 8
};

E 5
D 8
typedef char bool;
E 8
I 8
D 9
typedef	char bool;
E 8

E 9
struct device {
D 8
	int d_type;			/* CONTROLLER, DEVICE, UBA or MBA */
	struct device *d_conn;		/* What it is connected to */
	char *d_name;			/* Name of device (e.g. rk11) */
D 5
	char *d_vec1;			/* First interrupt vector */
	char *d_vec2;			/* Second interrupt vector */
E 5
I 5
	struct idlist *d_vec;		/* Interrupt vectors */
E 5
	int d_addr;			/* Address of csr */
	int d_unit;			/* Unit number */
	int d_drive;			/* Drive number */
	int d_slave;			/* Slave number */
E 8
I 8
D 18
	int	d_type;			/* CONTROLLER, DEVICE, UBA or MBA */
E 18
I 18
	int	d_type;			/* CONTROLLER, DEVICE, bus adaptor */
E 18
	struct	device *d_conn;		/* what it is connected to */
	char	*d_name;		/* name of device (e.g. rk11) */
D 10
	struct	idlist *d_vec;		/* interrupt vectors */
E 10
I 10
	struct	idlst *d_vec;		/* interrupt vectors */
E 10
	int	d_pri;			/* interrupt priority */
	int	d_addr;			/* address of csr */
I 23
	int	d_node;			/* VAXBI/XMI node */
E 23
	int	d_unit;			/* unit number */
	int	d_drive;		/* drive number */
	int	d_slave;		/* slave number */
E 8
I 3
#define QUES	-1	/* -1 means '?' */
#define	UNKNOWN -2	/* -2 means not set yet */
E 3
D 8
	bool d_dk;			/* if init 1 set to number for iostat */
	int d_flags;			/* Flags for device init */
	struct device *d_next;		/* Next one in list */
E 8
I 8
D 9
	bool	d_dk;			/* if init 1 set to number for iostat */
E 9
I 9
	int	d_dk;			/* if init 1 set to number for iostat */
E 9
	int	d_flags;		/* nlags for device init */
	struct	device *d_next;		/* Next one in list */
E 8
};
I 10
#define TO_NEXUS	(struct device *)-1
I 18
#define TO_VBA		(struct device *)-2
E 18
E 10

struct config {
D 8
	char *c_dev;
	char *s_sysname;
E 8
I 8
	char	*c_dev;
	char	*s_sysname;
E 8
};

I 8
/*
 * Config has a global notion of which machine type is
 * being used.  It uses the name of the machine in choosing
 * files and directories.  Thus if the name of the machine is ``vax'',
D 14
 * it will build from ``makefile.vax'' and use ``../vax/asm.sed''
E 14
I 14
D 16
 * it will build from ``makefile.vax'' and use ``../vax/inline''
E 16
I 16
 * it will build from ``Makefile.vax'' and use ``../vax/inline''
E 16
E 14
 * in the makerules, etc.
 */
int	machine;
char	*machinename;
#define	MACHINE_VAX	1
D 18
#define	MACHINE_SUN	2
E 18
I 18
#define	MACHINE_TAHOE	2
E 18

/*
 * For each machine, a set of CPU's may be specified as supported.
 * These and the options (below) are put in the C flags in the makefile.
 */
E 8
D 3
char *cpu_type, *ident, *ns(), *malloc(), *tc(), *qu();
E 3
I 3
struct cputype {
D 8
	char *cpu_name;
	struct cputype *cpu_next;
E 8
I 8
	char	*cpu_name;
	struct	cputype *cpu_next;
E 8
} *cputype;
I 8

/*
 * A set of options may also be specified which are like CPU types,
 * but which may also specify values for the options.
I 17
 * A separate set of options may be defined for make-style options.
E 17
 */
E 8
I 4
struct opt {
D 8
	char *op_name;
I 6
	char *op_value;
E 6
	struct cputype *op_next;
E 8
I 8
	char	*op_name;
	char	*op_value;
D 10
	struct	cputype *op_next;
E 10
I 10
	struct	opt *op_next;
E 10
E 8
D 17
} *opt;
E 17
I 17
} *opt, *mkopt;
E 17
E 4
D 8
char *ident, *ns(), *malloc(), *tc(), *qu();
E 3
bool do_trace, seen_mba, seen_uba;
struct device *connect();
struct device *dtab;
char errbuf[80];
int yyline;
struct file_list *ftab, *conf_list, *confp;
I 2
char *PREFIX;
I 3
int hz, timezone, hadtz, maxusers, dst;
E 8
I 8

D 10
char	*ident, *ns(), *malloc(), *tc(), *qu();
E 10
I 10
char	*ident;
char	*ns();
char	*tc();
char	*qu();
char	*get_word();
char	*path();
char	*raise();

E 10
D 9
bool	do_trace;
E 9
I 9
int	do_trace;
E 9

I 10
char	*index();
char	*rindex();
char	*malloc();
char	*strcpy();
char	*strcat();
D 19
char	*sprintf();
E 19

E 10
#if MACHINE_VAX
D 9
bool	seen_mba, seen_uba;
E 9
I 9
D 24
int	seen_mba, seen_uba;
E 24
I 24
int	seen_mba, seen_uba, seen_bva;
E 24
I 18
#endif
#if MACHINE_TAHOE
int	seen_vba;
E 18
E 9
#endif

struct	device *connect();
struct	device *dtab;
I 11
dev_t	nametodev();
char	*devtoname();
E 11

char	errbuf[80];
int	yyline;

D 11
struct	file_list *ftab, *conf_list, *confp;
E 11
I 11
struct	file_list *ftab, *conf_list, **confp;
E 11
D 20
char	*PREFIX;
E 20

D 10
int	hz, timezone, hadtz;
E 10
I 10
int	timezone, hadtz;
E 10
int	dst;
E 8
I 7
int	profiling;
I 8

int	maxusers;

#define eq(a,b)	(!strcmp(a,b))
D 9

#define TRUE	1
#define FALSE	0
E 9
E 8
E 7
E 3
E 2
E 1
