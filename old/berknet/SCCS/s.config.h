h33293
s 00001/00001/00563
d D 4.4 83/01/05 13:42:45 mosher 5 4
c changed configuration for K (ucbvax) to know what to do with 'q' - dmm
e
s 00071/00162/00493
d D 4.3 82/10/03 00:52:17 comay 4 2
c configuration tables updated as of 10/02/82
e
s 00071/00162/00493
d R 4.3 82/10/02 10:38:47 comay 3 2
c configuration tables updated as of 10/02/82
e
s 00173/00094/00482
d D 4.2 82/09/20 23:57:19 mckusick 2 1
c update to 9/7/82 configuration
e
s 00576/00000/00000
d D 4.1 82/09/12 17:41:09 mckusick 1 0
c date and time created 82/09/12 17:41:09 by mckusick
e
u
U
t
T
I 1
/*	%W%	(Berkeley)	%G%	*/

/*
	These are machine-configuration dependent
	tables.  To add a machine, be sure to update all
	these tables, add the "ifdef" entry in "mach.h",
	and add config? to gothru() in sub.c.
I 2
D 4
	The tables must be consistent.
E 4
E 2
	For Berkeley, this file corresponds to the following network:

D 2
			C70
			 |
			 |
			 |
			 |
	IngVAX          ARPA----Onyx
	  |		 |
	  |		 |
	  |		 |
	  |		 |
	Ing70-----------CSVAX---Kim	A              B
	   		 |		|              |
		         |		|              |
	            	 |		|              |
	   		 |		|              |
	MathStat--------Cory------------C--------------D
			 |		|	       |
			 |		|	       |
			 |		|	       |
			 |		|	       |
	EECS40----------ESVAX		E-------F     SRC
	   		 |	       /|\
	   		 |     	      / | \
	   		 |	     /	|  \
	   		 |	    /	|   \
	VLSI------------Image	 Virus	Q    G
			 |
			 |
			 |
			CAD
E 2
I 2
D 4
		T H E   B E R K E L E Y   N E T W O R K
E 4
I 4
	The tables must be consistent.
E 4
E 2

D 2
	The tables must be consistent.
E 2
I 2
D 4
			   September 7 1982
E 4
E 2

I 2
D 4
                   INGVAX----i
                      |       
	   KIM-----\  |  /----ERNIE         /--earvax
                    \ | /                  /
           C70-----\ \ / /----CAD-----ESVAX
                   UCBVAX                  \
	  Onyx-----/ /|\ \----ARPA          \--medea----oz
                    / | \ 
  t----statvax-----/  |  \-------y
		      |                    
	              | /------jade(h)                         
		      |/                   
                 d----G----------c--------a
                      |          |
                      |          |
                      f     b----e----s
E 2

I 2

		M A C H I N E   G U I D E 

Name 	Char 	Run By		Type	Vers.	Default Mach.
----	----	------		----	----	-------------
A	a	CFO		11/70	V7	C
B	b	CFO		11/70	V7	E
C	c	CFO		11/70	V7	A
D	d	CFO		11/70	V7	G
E	e	CFO		11/70	V7	C
F	f	CFO		11/70	V7	G
G	g	CFO		VAX/780	V7	C
H(jade)	h	CFO		VAX/750	V7	G
ing70	i	CSSG		11/70	V7	INGVAX
INGVAX	j	Ingres Group 	VAX/780	V7	Ing70
ucbvax	k	CS network hub	VAX/750	V7	
oz	l	Brodersen	VAX/750	V7	medea
medea	m	EE-Signal Proc.	VAX/750	V7	ESVAX
KIM	n	Kim No-vax (RJF)VAX/780	V7	CSVAX
ESVAX	o	EECS-CE Res.	VAX/780	V7	CSVAX	
CAD	p	Newton CAD      VAX/780 V7      ESVAX
ARPAVAX	r	Fabry		VAX/780	V7	CSVAX	
SRC	s	CFO & SRC	11/45	V6	E
MathStat t	Math/Stat Dept	11/45	V7	statvax
C70     u       EECS            C70     V7      ARPAVAX
CSVAX	v	CS Research	VAX	V7	ARPAVAX
statvax w	Stat Dept	VAX/750	V7	UCBVAX
Onyx	x	CS Research	Onyx	V7	ARPAVAX
Cory	y	EECS Dept.	11/70	V7	UCBVAX
EARVAX	z	EECS Dept.	VAX/750	V7	ESVAX

(the following machines are not connected or do not exist yet)
Phonology ?	Linguistics	11/45	V6		?

(Letters used: A-P, R-Z (total of 25))
(Letters free: Q (total of 1))

The links between  A-C, C-E, C-G, G-D, G-F, G-CSVAX and CSVAX-ARPAVAX 
run at 9600 baud, all others run at 1200 Baud.

Files 200,000 to 500,000 bytes are only transmitted between midnight and 6AM.
There is a file-length limit of 500,000 bytes.
Larger files must be split up (use the split command).


Free Commands (log in as user "network", no password):

	bpq		news		vpq		yank
	epq		ps		w
	finger 		pstat		wc
	help		rcs		where
	lpq		rcslog		who
	netlog		rcsq		whom
	netq		trq		write		

In addition, the "lpr" command is free on the Ingres machines.
Sending mail between machines, and netlpr between the Computer Center machines
is free.  On the EARVAX, there are no free commands (but sending mail is free).
The netlpr command to Cory will allow the -c option to "epr" and "bpr",
and to the CSVAX will allow "vpr".

E 4
E 2
	For RAND, these tables are:

		VAX (C) ---------GRAPHICS (A)------- TP (B)

	For NOSC, these tables are:

		   FCCMM ------ ATTS ------ MSSF ------ CCMM
				/ \
			       /   \
			      /     \
			     /       \
		OT34 ---- GATE40    ING70
			    |
			    |
			   PWB



*/
# ifdef RAND
/* GRAPHICS = A */
char configA[] = {		/* to get to i, config[i] */
	'a','b','c',000,000,		/* a,b,c,d,e */
	000,000,000,000,000,		/* f,g,h,i,j */
	000,000,000,000,000,		/* k,l,m,n,o */
	000,000,000,000,000,		/* p,q,r,s,t */
	000,000,000,000,000,		/* u,v,w,x,y */
	000,0				/* z */
	};
/* TP = B */
char configB[] = {		/* to get to i, config[i] */
	'a','b','a',000,000,		/* a,b,c,d,e */
	000,000,000,000,000,		/* f,g,h,i,j */
	000,000,000,000,000,		/* k,l,m,n,o */
	000,000,000,000,000,		/* p,q,r,s,t */
	000,000,000,000,000,		/* u,v,w,x,y */
	000,0				/* z */
	};
/* VAX = C */
char configC[] = {		/* to get to i, config[i] */
	'a','a','c',000,000,		/* a,b,c,d,e */
	000,000,000,000,000,		/* f,g,h,i,j */
	000,000,000,000,000,		/* k,l,m,n,o */
	000,000,000,000,000,		/* p,q,r,s,t */
	000,000,000,000,000,		/* u,v,w,x,y */
	000,0				/* z */
	};
/* if machtype is
	M_CC		netlpr will do lpr w/o an acct.
			Will pre-encrypt the password.
	M_INGRES	will allow higher file lengths.
	M_OTHER		will give no unusual effects.
(when in doubt, machtype should be M_OTHER)
*/
char machtype[]= {
	M_OTHER,M_OTHER,M_OTHER,0,0,	/* a,b,c,d,e */
	0, 0, 0, 0, 0, 			/* f,g,h,i,j */
	0, 0, 0, 0, 0,			/* k,l,m,n,o */
	0, 0, 0, 0, 0,			/* p,q,r,s,t */
	0, 0, 0, 0, 0,			/* u,v,w,x,y */
	0, 0};				/* z */

/* this is basically the default machine for each local machine */
char remtable[] = {
	'b','a','a',000,000,		/* a,b,c,d,e */
	000,000,000,000,000,		/* f,g,h,i,j */
	000,000,000,000,000,		/* k,l,m,n,o */
	000,000,000,000,000,		/* p,q,r,s,t */
	000,000,000,000,000,		/* u,v,w,x,y */
	000,0				/* z */
	};
/* bad login names */
struct bstruct btable[] = {
	0,0 };
/* this table shows the correspondence between
   machine names like 'Cory' and their internal
   names, like 'y' */
static struct tt {
	char *bigname;
	char lname;
	} table[] = {
	"Graphics",	'a',
	"TP",		'b',
	"VAX",		'c',
	0, 		0
	};
/* end of Rand definitions */

# endif RAND

# ifdef NOSC
/* Naval Ocean Systems Center */

/* atts (a) */
char configA[] = {		/* to get to i, config[i] */
	'a',000,'m',000,000,		/* a,b,c,d,e */
	'f','g',000,'i',000,		/* f,g,h,i,j */
	000,000,'m',000,'g',		/* k,l,m,n,o */
	'g',000,000,000,000,		/* p,q,r,s,t */
	000,000,000,000,000,		/* u,v,w,x,y */
	000,0				/* z */
	};

/* ccmm (c) */
char configC[] = {		/* to get to i, config[i] */
	'm',000,'c',000,000,		/* a,b,c,d,e */
	'm','m',000,'m',000,		/* f,g,h,i,j */
	000,000,'m',000,'m',		/* k,l,m,n,o */
	'm',000,000,000,000,		/* p,q,r,s,t */
	000,000,000,000,000,		/* u,v,w,x,y */
	000,0				/* z */
	};

/* ccmm (f) */
char configF[] = {		/* to get to i, config[i] */
	'a',000,'c',000,000,		/* a,b,c,d,e */
	'f','a',000,'a',000,		/* f,g,h,i,j */
	000,000,'a',000,'a',		/* k,l,a,n,o */
	'a',000,000,000,000,		/* p,q,r,s,t */
	000,000,000,000,000,		/* u,v,w,x,y */
	000,0				/* z */
	};

/* mssf (m) */
char configM[] = {		/* to get to i, config[i] */
	'a',000,'c',000,000,		/* a,b,c,d,e */
	'a','a',000,'a',000,		/* f,g,h,i,j */
	000,000,'m',000,'a',		/* k,l,m,n,o */
	'a',000,000,000,000,		/* p,q,r,s,t */
	000,000,000,000,000,		/* u,v,w,x,y */
	000,0				/* z */
	};

/* ingres (i) proposed */
char configI[] = {		/* to get to i, config[i] */
	'a',000,'a',000,000,		/* a,b,c,d,e */
	'a','a',000,'i',000,		/* f,g,h,i,j */
	000,000,'a',000,'a',		/* k,l,m,n,o */
	'a',000,000,000,000,		/* p,q,r,s,t */
	000,000,000,000,000,		/* u,v,w,x,y */
	000,0				/* z */
	};

/* nosc-cc gateway 40 (g) */
char configG[] = {		/* to get to i, config[i] */
	'a',000,'a',000,000,		/* a,b,c,d,e */
	'a','g',000,'a',000,		/* f,g,h,i,j */
	000,000,'a',000,'g',		/* k,l,m,n,o */
	'p',000,000,000,000,		/* p,q,r,s,t */
	000,000,000,000,000,		/* u,v,w,x,y */
	000,0				/* z */
	};

/* ocean tech 34 (o) */
char configO[] = {		/* to get to i, config[i] */
	'g',000,'g',000,000,		/* a,b,c,d,e */
	'g','g',000,'g',000,		/* f,g,h,i,j */
	000,000,'g',000,'o',		/* k,l,m,n,o */
	'g',000,000,000,000,		/* p,q,r,s,t */
	000,000,000,000,000,		/* u,v,w,x,y */
	000,0				/* z */
	};

/* pwb at nosc (p) */
char configP[] = {		/* to get to i, config[i] */
	'g',000,'g',000,000,		/* a,b,c,d,e */
	'g','g',000,'g',000,		/* f,g,h,i,j */
	000,000,'g',000,'g',		/* k,l,m,n,o */
	'p',000,000,000,000,		/* p,q,r,s,t */
	000,000,000,000,000,		/* u,v,w,x,y */
	000,0				/* z */
	};

/* this table is used by netlpr to do lpr w/o an acct
   and by net and netdaemon to do pre-emption */
/* sub.c uses the table in initdaemon to check machine
   type - errormsg may be ignored */
char machtype[]= {
	M_CC, 0,M_OTHER, 0, 0,	   	/* a,b,c,d,e */
	M_OTHER,M_OTHER, 0,M_INGRES, 0,	/* f,g,h,i,j */
	0, 0,M_CC, 0,M_OTHER,		/* k,l,m,n,o */
	M_OTHER, 0, 0, 0, 0,		/* p,q,r,s,t */
	0, 0, 0, 0, 0,			/* u,v,w,x,y */
	0};				/* z */
/* this is basically the default machine for each local machine */
char remtable[] = {
	'm',000,'m',000,000,		/* a,b,c,d,e */
	'a','a',000,'a',000,		/* f,g,h,i,j */
	000,000,'a',000,'g',		/* k,l,m,n,o */
	'g',000,000,000,000,		/* p,q,r,s,t */
	000,000,000,000,000,		/* u,v,w,x,y */
	000,0				/* z */
	};
/* bad login names */
struct bstruct btable[] = {
	"op", 'a',
	0,0 };
/* this table shows the correspondence between
   machine names like 'Cory' and their internal
   names, like 'y' */
static struct tt {
	char *bigname;
	char lname;
	} table[] = {
	"ATTS",		'a',
	"CCMM",		'c',
	"FCCMM",	'f',
	"MSSF",		'm',
	"INGRES",	'i',
	"GATEWAY",	'g',
	"OT34",		'o',
	"PWB",		'p',
	0, 0 };

# endif NOSC

# ifdef BERKELEY
/* Berkeley definitions */

/* Computer Center A Machine (A) */
char configA[] = {		/* to get to i, config[i] */
	'a','c','c','c','c',		/* a,b,c,d,e */
D 2
	'c','c',000,'c','c',		/* f,g,h,i,j */
E 2
I 2
	'c','c','c','c','c',		/* f,g,h,i,j */
E 2
	'c','c','c','c','c',		/* k,l,m,n,o */
D 4
	'c','c','c','c','c',		/* p,q,r,s,t */
E 4
I 4
	'c',000,'c','c','c',		/* p,q,r,s,t */
E 4
	'c','c','c','c','c',		/* u,v,w,x,y */
	'c',0				/* z */
	};
/* Computer Center B Machine (B) */
char configB[] = {		/* to get to i, config[i] */
	'e','b','e','e','e',		/* a,b,c,d,e */
D 2
	'e','e',000,'e','e',		/* f,g,h,i,j */
E 2
I 2
	'e','e','e','e','e',		/* f,g,h,i,j */
E 2
	'e','e','e','e','e',		/* k,l,m,n,o */
D 4
	'e','e','e','e','e',		/* p,q,r,s,t */
E 4
I 4
	'e',000,'e','e','e',		/* p,q,r,s,t */
E 4
	'e','e','e','e','e',		/* u,v,w,x,y */
	'e',0				/* z */
	};
/* Computer Center C Machine (C) */
char configC[] = {		/* to get to i, config[i] */
	'a','e','c','g','e',		/* a,b,c,d,e */
D 2
	'g','g',000,'g','g',		/* f,g,h,i,j */
E 2
I 2
	'g','g','g','g','g',		/* f,g,h,i,j */
E 2
	'g','g','g','g','g',		/* k,l,m,n,o */
D 4
	'g','e','g','e','g',		/* p,q,r,s,t */
E 4
I 4
	'g',000,'g','e','g',		/* p,q,r,s,t */
E 4
D 2
	'g','g','g','g','y',		/* u,v,w,x,y */
E 2
I 2
	'g','g','g','g','g',		/* u,v,w,x,y */
E 2
	'g',0				/* z */
	};
/* Computer Center D Machine (D) */
char configD[] = {		/* to get to i, config[i] */
	'g','g','g','d','g',		/* a,b,c,d,e */
D 2
	'g','g',000,'g','g',		/* f,g,h,i,j */
E 2
I 2
	'g','g','g','g','g',		/* f,g,h,i,j */
E 2
	'g','g','g','g','g',		/* k,l,m,n,o */
D 4
	'g','g','g','g','g',		/* p,q,r,s,t */
E 4
I 4
	'g',000,'g','g','g',		/* p,q,r,s,t */
E 4
	'g','g','g','g','g',		/* u,v,w,x,y */
	'g',0				/* z */
	};
/* Computer Center E Machine (E) */
char configE[] = {		/* to get to i, config[i] */
	'c','b','c','c','e',		/* a,b,c,d,e */
D 2
	'g','g',000,'g','g',		/* f,g,h,i,j */
	'g','g','g','g','g',		/* k,l,m,n,o */
	'g','e','g','s','g',		/* p,q,r,s,t */
	'g','g','g','g','c',		/* u,v,w,x,y */
	'g',0				/* z */
E 2
I 2
	'c','c','c','c','c',		/* f,g,h,i,j */
	'c','c','c','c','c',		/* k,l,m,n,o */
D 4
	'c','c','c','s','c',		/* p,q,r,s,t */
E 4
I 4
	'c',000,'c','s','c',		/* p,q,r,s,t */
E 4
	'c','c','c','c','c',		/* u,v,w,x,y */
	'c',0				/* z */
E 2
	};
/* Computer Center F Machine (F) */
char configF[] = {		/* to get to i, config[i] */
	'g','g','g','g','g',		/* a,b,c,d,e */
D 2
	'f','g',000,'g','g',		/* f,g,h,i,j */
E 2
I 2
	'f','g','g','g','g',		/* f,g,h,i,j */
E 2
	'g','g','g','g','g',		/* k,l,m,n,o */
D 4
	'g','g','g','g','g',		/* p,q,r,s,t */
E 4
I 4
	'g',000,'g','g','g',		/* p,q,r,s,t */
E 4
	'g','g','g','g','g',		/* u,v,w,x,y */
	'g',0				/* z */
	};
D 4
/* Computer Center G Machine (Comp Center VAX) */
E 4
I 4
/* Computer Center G Machine (G) */
E 4
char configG[] = {		/* to get to i, config[i] */
	'c','c','c','d','c',		/* a,b,c,d,e */
D 2
	'f','g',000,'k','k',		/* f,g,h,i,j */
E 2
I 2
	'f','g','h','k','k',		/* f,g,h,i,j */
E 2
	'k','k','k','k','k',		/* k,l,m,n,o */
D 2
	'k','c','k','c','k',		/* p,q,r,s,t */
E 2
I 2
D 4
	'k','k','k','c','k',		/* p,q,r,s,t */
E 2
	'k','k','k','k','c',		/* u,v,w,x,y */
E 4
I 4
	'k',000,'k','c','k',		/* p,q,r,s,t */
	'k','k','k','k','k',		/* u,v,w,x,y */
E 4
	'k',0				/* z */
	};
I 2
D 4
/* Computer Center Jade Machine (H) */
E 4
I 4
/* Computer Center H Machine (H) */
E 4
char configH[] = {		/* to get to i, config[i] */
	'g','g','g','g','g',		/* a,b,c,d,e */
	'g','g','h','g','g',		/* f,g,h,i,j */
	'g','g','g','g','g',		/* k,l,m,n,o */
D 4
	'g','g','g','g','g',		/* p,q,r,s,t */
E 4
I 4
	'g',000,'g','g','g',		/* p,q,r,s,t */
E 4
	'g','g','g','g','g',		/* u,v,w,x,y */
	'g',0				/* z */
	};
E 2
/* Project INGRES 11/70 (Ing70) */
char configI[] = {		/* to get to i, config[i] */
	'j','j','j','j','j',		/* a,b,c,d,e */
D 2
	'j','j',000,'i','j',		/* f,g,h,i,j */
E 2
I 2
	'j','j','j','i','j',		/* f,g,h,i,j */
E 2
	'j','j','j','j','j',		/* k,l,m,n,o */
D 4
	'j','j','j','j','j',		/* p,q,r,s,t */
E 4
I 4
	'j',000,'j','j','j',		/* p,q,r,s,t */
E 4
	'j','j','j','j','j',		/* u,v,w,x,y */
	'j',0				/* z */
	};
/* Project INGRES VAX (IngVAX) */
char configJ[] = {		/* to get to i, config[i] */
	'k','k','k','k','k',		/* a,b,c,d,e */
D 2
	'k','k',000,'i','k',		/* f,g,h,i,j */
E 2
I 2
D 4
	'k','k','k','i','k',		/* f,g,h,i,j */
E 4
I 4
	'k','k','k','i','j',		/* f,g,h,i,j */
E 4
E 2
	'k','k','k','k','k',		/* k,l,m,n,o */
D 4
	'k','k','k','k','k',		/* p,q,r,s,t */
E 4
I 4
	'k',000,'k','k','k',		/* p,q,r,s,t */
E 4
	'k','k','k','k','k',		/* u,v,w,x,y */
	'k',0				/* z */
	};
/* UUCP gateway VAX (ucbvax) */
char configK[] = {		/* to get to i, config[i] */
	'g','g','g','g','g',		/* a,b,c,d,e */
D 2
	'g','g',000,'j','j',		/* f,g,h,i,j */
E 2
I 2
	'g','g','g','j','j',		/* f,g,h,i,j */
E 2
	'k','p','p','n','p',		/* k,l,m,n,o */
D 2
	'p','g','r','g','w',		/* p,q,r,s,t */
	'u','v','w','x','p',		/* u,v,w,x,y */
E 2
I 2
D 4
	'p',000,'r','g','w',		/* p,q,r,s,t */
E 4
I 4
D 5
	'p',000,'r','g','t',		/* p,q,r,s,t */
E 5
I 5
	'p','g','r','g','t',		/* p,q,r,s,t */
E 5
E 4
	'u','v','w','x','y',		/* u,v,w,x,y */
E 2
	'p',0				/* z */
	};
/* Brodersen EECS VLSI VAX (VLSI) */
char configL[] = {		/* to get to i, config[i] */
	'm','m','m','m','m',		/* a,b,c,d,e */
D 2
	'm','m',000,'m','m',		/* f,g,h,i,j */
E 2
I 2
	'm','m','m','m','m',		/* f,g,h,i,j */
E 2
	'm','l','m','m','m',		/* k,l,m,n,o */
D 4
	'm','m','m','m','m',		/* p,q,r,s,t */
E 4
I 4
	'm',000,'m','m','m',		/* p,q,r,s,t */
E 4
	'm','m','m','m','m',		/* u,v,w,x,y */
	'm',0				/* z */
	};
D 4
/* Sakrison's Image Project 11/40 (Image) */
E 4
I 4
/* Sakrison's Image Project VAX (Image) */
E 4
char configM[] = {		/* to get to i, config[i] */
	'o','o','o','o','o',		/* a,b,c,d,e */
D 2
	'o','o',000,'o','o',		/* f,g,h,i,j */
E 2
I 2
	'o','o','o','o','o',		/* f,g,h,i,j */
E 2
	'o','l','m','o','o',		/* k,l,m,n,o */
D 4
	'o','o','o','o','o',		/* p,q,r,s,t */
E 4
I 4
	'o',000,'o','o','o',		/* p,q,r,s,t */
E 4
	'o','o','o','o','o',		/* u,v,w,x,y */
	'o',0				/* z */
	};
/* Fatemans Applied Math VAX (Kim) */
char configN[] = {		/* to get to i, config[i] */
	'k','k','k','k','k',		/* a,b,c,d,e */
D 2
	'k','k',000,'k','k',		/* f,g,h,i,j */
E 2
I 2
	'k','k','k','k','k',		/* f,g,h,i,j */
E 2
	'k','k','k','n','k',		/* k,l,m,n,o */
D 4
	'k','k','k','k','k',		/* p,q,r,s,t */
E 4
I 4
	'k',000,'k','k','k',		/* p,q,r,s,t */
E 4
	'k','k','k','k','k',		/* u,v,w,x,y */
	'k',0				/* z */
	};
/* Pfeister - Pollack - Sangiovanni Optimization VAX (ESVAX) */
char configO[] = {		/* to get to i, config[i] */
D 2
	'y','y','y','p','y',		/* a,b,c,d,e */
	'g','g',000,'p','p',		/* f,g,h,i,j */
E 2
I 2
	'p','p','p','p','p',		/* a,b,c,d,e */
	'p','p','p','p','p',		/* f,g,h,i,j */
E 2
	'p','m','m','p','o',		/* k,l,m,n,o */
D 2
	'p','y','p','y','p',		/* p,q,r,s,t */
	'p','p','p','p','y',		/* u,v,w,x,y */
E 2
I 2
D 4
	'p','p','p','p','p',		/* p,q,r,s,t */
E 4
I 4
	'p',000,'p','p','p',		/* p,q,r,s,t */
E 4
	'p','p','p','p','p',		/* u,v,w,x,y */
E 2
	'z',0				/* z */
	};
/* Newton's CAD machine (VAX 11/780) */
char configP[] = {		/* to get to i, config[i] */
	'k','k','k','k','k',		/* a,b,c,d,e */
D 2
	'k','k',000,'k','k',		/* f,g,h,i,j */
E 2
I 2
	'k','k','k','k','k',		/* f,g,h,i,j */
E 2
	'k','o','o','k','o',		/* k,l,m,n,o */
D 4
	'p','k','k','k','k',		/* p,q,r,s,t */
E 4
I 4
	'p',000,'k','k','k',		/* p,q,r,s,t */
E 4
D 2
	'k','k','k','k','o',		/* u,v,w,x,y */
E 2
I 2
	'k','k','k','k','k',		/* u,v,w,x,y */
E 2
	'o',0				/* z */
	};
D 4
/* Computer Center Q Machine (Q) */
char configQ[] = {		/* to get to i, config[i] */
D 2
	'e','e','e','e','e',		/* a,b,c,d,e */
	'e','e',000,'e','e',		/* f,g,h,i,j */
	'e','e','e','e','e',		/* k,l,m,n,o */
	'e','q','e','e','e',		/* p,q,r,s,t */
	'e','e','e','e','e',		/* u,v,w,x,y */
	'e',0				/* z */
E 2
I 2
	'k','k','k','k','k',		/* a,b,c,d,e */
	'k','k','k','k','k',		/* f,g,h,i,j */
	'k','k','k','k','k',		/* k,l,m,n,o */
	'k','q','k','k','k',		/* p,q,r,s,t */
	'k','k','k','k','k',		/* u,v,w,x,y */
	'k',0				/* z */
E 2
	};
E 4
/* Fabry's ARPA support VAX - ARPAVAX */
char configR[] = {		/* to get to i, config[i] */
	'k','k','k','k','k',		/* a,b,c,d,e */
D 2
	'k','k',000,'k','k',		/* f,g,h,i,j */
E 2
I 2
	'k','k','k','k','k',		/* f,g,h,i,j */
E 2
	'k','k','k','k','k',		/* k,l,m,n,o */
D 4
	'k','k','r','k','k',		/* p,q,r,s,t */
E 4
I 4
	'k',000,'r','k','k',		/* p,q,r,s,t */
E 4
	'k','k','k','k','k',		/* u,v,w,x,y */
	'k',0				/* z */
	};
/* Survey Research Center 11/40 (SRC) */
char configS[] = {		/* to get to i, config[i] */
	'e','e','e','e','e',		/* a,b,c,d,e */
D 2
	'e','e',000,'e','e',		/* f,g,h,i,j */
E 2
I 2
	'e','e','e','e','e',		/* f,g,h,i,j */
E 2
	'e','e','e','e','e',		/* k,l,m,n,o */
D 4
	'e','e','e','s','e',		/* p,q,r,s,t */
E 4
I 4
	'e',000,'e','s','e',		/* p,q,r,s,t */
E 4
	'e','e','e','e','e',		/* u,v,w,x,y */
	'e',0				/* z */
	};
/* Math-Stat Departement machine 11-45 (MathStat) */
char configT[] = {		/* to get to i, config[i] */
D 2
	'y','y','y','y','y',		/* a,b,c,d,e */
	'y','y',000,'y','y',		/* f,g,h,i,j */
	'y','y','y','y','y',		/* k,l,m,n,o */
	'y','y','y','y','t',		/* p,q,r,s,t */
	'y','y','w','y','y',		/* u,v,w,x,y */
	'y',0				/* z */
E 2
I 2
D 4
	'w','w','w','w','w',		/* a,b,c,d,e */
	'w','w','w','w','w',		/* f,g,h,i,j */
	'w','w','w','w','w',		/* k,l,m,n,o */
	'w','w','w','w','t',		/* p,q,r,s,t */
	'w','w','w','w','w',		/* u,v,w,x,y */
	'w',0				/* z */
E 4
I 4
	'k','k','k','k','k',		/* a,b,c,d,e */
	'k','k','k','k','k',		/* f,g,h,i,j */
	'k','k','k','k','k',		/* k,l,m,n,o */
	'k',000,'k','k','t',		/* p,q,r,s,t */
	'k','k','k','k','k',		/* u,v,w,x,y */
	'k',0				/* z */
E 4
E 2
	};
/* ARPANET gateway (ucbc70) */
char configU[] = {		/* to get to i, config[i] */
	'k','k','k','k','k',		/* a,b,c,d,e */
D 2
	'k','k',000,'k','k',		/* f,g,h,i,j */
E 2
I 2
	'k','k','k','k','k',		/* f,g,h,i,j */
E 2
	'k','k','k','k','k',		/* k,l,m,n,o */
D 4
	'k','k','k','k','k',		/* p,q,r,s,t */
E 4
I 4
	'k',000,'k','k','k',		/* p,q,r,s,t */
E 4
	'u','k','k','k','k',		/* u,v,w,x,p */
	'k',0				/* z */
	};
/* EECS Research (Fateman - Ernie) VAX (CSVAX) */
char configV[] = {		/* to get to i, config[i] */
	'k','k','k','k','k',		/* a,b,c,d,e */
D 2
	'k','k',000,'k','k',		/* f,g,h,i,j */
E 2
I 2
	'k','k','k','k','k',		/* f,g,h,i,j */
E 2
	'k','k','k','k','k',		/* k,l,m,n,o */
D 4
	'k','k','k','k','k',		/* p,q,r,s,t */
E 4
I 4
	'k',000,'k','k','k',		/* p,q,r,s,t */
E 4
D 2
	'k','v','k','k','k',		/* u,v,w,x,z */
E 2
I 2
	'k','v','k','k','k',		/* u,v,w,x,p */
E 2
	'k',0				/* z */
	};
/* Statistics VAX 11/780 (ucbstatvax) */
char configW[] = {		/* to get to i, config[i] */
	'k','k','k','k','k',		/* a,b,c,d,e */
D 2
	'k','k',000,'k','k',		/* f,g,h,i,j */
E 2
I 2
	'k','k','k','k','k',		/* f,g,h,i,j */
E 2
	'k','k','k','k','k',		/* k,l,m,n,o */
D 4
	'k','k','k','k','t',		/* p,q,r,s,t */
E 4
I 4
	'k',000,'k','k','k',		/* p,q,r,s,t */
E 4
	'k','k','w','k','k',		/* u,v,w,x,p */
	'k',0				/* z */
	};
D 4
/* CS Research Onyx Computer */
E 4
I 4
/* Undergraduate Computing Facility Onyx Computer */
E 4
char configX[] = {		/* to get to i, config[i] */
	'k','k','k','k','k',		/* a,b,c,d,e */
D 2
	'k','k',000,'k','k',		/* f,g,h,i,j */
E 2
I 2
	'k','k','k','k','k',		/* f,g,h,i,j */
E 2
	'k','k','k','k','k',		/* k,l,m,n,o */
D 4
	'k','k','k','k','k',		/* p,q,r,s,t */
E 4
I 4
	'k',000,'k','k','k',		/* p,q,r,s,t */
E 4
	'k','k','k','x','k',		/* u,v,w,x,y */
	'k',0				/* z */
	};
/* EECS Instructional 11/70 (199 Cory) (Cory) */
char configY[] = {		/* to get to i, config[i] */
D 2
	'c','c','c','c','c',		/* a,b,c,d,e */
	'c','c',000,'o','o',		/* f,g,h,i,j */
	'o','o','o','o','o',		/* k,l,m,n,o */
	'o','c','o','c','t',		/* p,q,r,s,t */
	'o','o','o','o','y',		/* u,v,w,x,y */
	'o',0				/* z */
E 2
I 2
	'k','k','k','k','k',		/* a,b,c,d,e */
	'k','k','k','k','k',		/* f,g,h,i,j */
	'k','k','k','k','k',		/* k,l,m,n,o */
D 4
	'k','k','k','k','k',		/* p,q,r,s,t */
E 4
I 4
	'k',000,'k','k','k',		/* p,q,r,s,t */
E 4
	'k','k','k','k','y',		/* u,v,w,x,y */
	'k',0				/* z */
E 2
	};
/* EECS Departmental 11/40  (EECS40) */
char configZ[] = {		/* to get to i, config[i] */
	'o','o','o','o','o',		/* a,b,c,d,e */
D 2
	'o','o',000,'o','o',		/* f,g,h,i,j */
E 2
I 2
	'o','o','o','o','o',		/* f,g,h,i,j */
E 2
	'o','o','o','o','o',		/* k,l,m,n,o */
D 4
	'o','o','o','o','o',		/* p,q,r,s,t */
E 4
I 4
	'o',000,'o','o','o',		/* p,q,r,s,t */
E 4
	'o','o','o','o','o',		/* u,v,w,x,y */
	'z',0				/* z */
	};
/* if machtype is
	M_CC		netlpr will do lpr w/o an acct.
			Will pre-encrypt the password.
	M_INGRES	will allow higher file lengths.
	M_OTHER		will give no unusual effects.
(when in doubt, machtype should be M_OTHER)
*/
char machtype[]= {
	M_CC, M_CC, M_CC, M_CC, M_CC,			/* a,b,c,d,e */
D 2
	M_CC, M_CC, 0, M_INGRES, M_INGRES,		/* f,g,h,i,j */
E 2
I 2
	M_CC, M_CC, M_CC, M_INGRES, M_INGRES,		/* f,g,h,i,j */
E 2
	M_OTHER, M_OTHER, M_OTHER, M_OTHER, M_OTHER,	/* k,l,m,n,o */
D 2
	M_OTHER, M_OTHER, M_OTHER, M_OTHER, M_OTHER,	/* p,q,r,s,t */
E 2
I 2
D 4
	M_OTHER, M_OTHER, M_OTHER, M_CC, M_OTHER,	/* p,q,r,s,t */
E 4
I 4
	M_OTHER, 0, M_OTHER, M_OTHER, M_OTHER,		/* p,q,r,s,t */
E 4
E 2
	M_OTHER, M_OTHER, M_OTHER, M_OTHER, M_OTHER,	/* u,v,w,x,y */
	M_OTHER, 0};					/* z */

/* this is basically the default machine for each local machine */
char remtable[] = {
	'c','e','g','g','c',		/* a,b,c,d,e */
D 2
	'g','k',000,'j','k',		/* f,g,h,i,j */
	'v','o','o','k','p',		/* k,l,m,n,o */
	'k','e','k','e','w',		/* p,q,r,s,t */
	'k','k','k','k','o',		/* u,v,w,x,y */
E 2
I 2
	'g','k','g','j','k',		/* f,g,h,i,j */
D 4
	'v','m','o','k','p',		/* k,l,m,n,o */
	'k','k','k','e','w',		/* p,q,r,s,t */
E 4
I 4
	'u','m','o','k','p',		/* k,l,m,n,o */
	'k',000,'k','e','k',		/* p,q,r,s,t */
E 4
	'k','k','k','k','k',		/* u,v,w,x,y */
E 2
	'o',0				/* z */
	};
/* bad login names */
struct bstruct btable[] = {
	"op", 'a',
	0,0 };
/* this table shows the correspondence between
   machine names like 'Cory' and their internal names, like 'y' */
static struct tt {
	char *bigname;
	char lname;
	} table[] = {
	"A",		'a',
	"ucbcfo-a",	'a',
I 4
	"cfo-a",	'a',
E 4
	"B",		'b',
	"ucbcfo-b",	'b',
I 4
	"cfo-b",	'b',
E 4
	"C",		'c',
	"ucbcfo-c",	'c',
I 4
	"cfo-c",	'c',
E 4
	"D",		'd',
	"ucbcfo-d",	'd',
I 4
	"cfo-d",	'd',
E 4
	"E",		'e',
	"ucbcfo-e",	'e',
I 4
	"cfo-e",	'e',
E 4
	"F",		'f',
	"ucbcfo-f",	'f',
I 4
	"cfo-f",	'f',
E 4
	"G",		'g',
	"ucbcfo-g",	'g',
I 4
	"cfo-g",	'g',
	"H",		'h',
	"ucbcfo-h",	'h',
	"cfo-h",	'h',
E 4
I 2
	"ucbjade",	'h',
	"jade",		'h',
E 2
D 4
	"H",		'h',
E 4
D 2
	"ucbcfo-h",	'h',
E 2
	"Ing70",	'i',
D 4
	"ucbing70",	'i',
I 2
	"I",		'i',
E 4
I 4
	"ucberl70",	'i',
	"erl70",	'i',
E 4
E 2
	"IngVAX",	'j',
	"ucbingres",	'j',
I 2
D 4
	"J",		'j',
E 4
I 4
	"ingres",	'j',
E 4
E 2
	"ucbvax",	'k',
D 4
	"UCBVAX",	'k',
D 2
	"VLSI",		'l',
	"ucbvlsi",	'l',
E 2
I 2
	"K",		'k',
	"OZ",		'l',
E 4
I 4
	"vax",		'k',
E 4
	"ucboz",	'l',
D 4
	"L",		'l',
E 2
	"Image",	'm',
	"ucbimage",	'm',
E 4
I 4
	"oz",		'l',
	"VLSI",		'l',
E 4
I 2
	"ucbmedea",	'm',
	"medea",	'm',
D 4
	"M",		'm',
E 4
I 4
	"Image",	'm',
E 4
E 2
	"Kim",		'n',
	"ucbkim",	'n',
I 2
D 4
	"N",		'n',
E 4
I 4
	"kim",		'n',
E 4
E 2
	"ESVAX",	'o',
D 4
	"ucbopt",	'o',
I 2
	"O",		'o',
E 2
	"CAD",		'p',
E 4
I 4
	"ucbesvax",	'o',
E 4
	"ucbcad",	'p',
I 2
D 4
	"P",		'p',
E 2
	"Q",		'q',
E 4
I 4
	"ucbcoke",	'p',
	"coke",		'p',
	"cad",		'p',
E 4
D 2
	"ucbcfo-q",	'q',
E 2
	"ARPAVAX",	'r',
	"ucbarpa",	'r',
I 2
D 4
	"R",		'r',
E 4
I 4
	"arpa",		'r',
E 4
E 2
	"SRC",		's',
	"ucbsrc",	's',
I 2
D 4
	"S",		's',
E 4
E 2
	"MathStat",	't',
	"ucbmathstat",	't',
I 2
D 4
	"T",		't',
E 4
E 2
	"ucbc70",	'u',
D 4
	"C70",		'u',
I 2
	"U",		'u',
E 4
I 4
	"c70",		'u',
E 4
E 2
	"CSVAX",	'v',
	"ucbernie",	'v',
I 2
D 4
	"V",		'v',
E 4
I 4
	"ernie",	'v',
E 4
E 2
	"ucbstatvax",	'w',
D 4
	"StatVax",	'w',
I 2
	"W",		'w',
E 4
I 4
	"statvax",	'w',
E 4
E 2
	"ucbonyx",	'x',
D 4
	"Onyx",		'x',
I 2
	"X",		'x',
E 4
I 4
	"onyx",		'x',
E 4
E 2
	"Cory",		'y',
	"ucbcory",	'y',
I 2
D 4
	"Y",		'y',
	"EARVAX", 	'z',
E 2
	"EECS40", 	'z',
	"ucbeecs40", 	'z',
I 2
	"ucbear", 	'z',
	"Z",	 	'z',
E 4
I 4
	"ucbear",	'z',
	"ear",		'z',
	"earvax",	'z',
	"EECS40",	'z',
E 4
E 2
	0, 		0
	};
# endif
E 1
