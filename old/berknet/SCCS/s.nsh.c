h24358
s 00021/00013/00092
d D 4.3 83/05/20 03:49:34 comay 3 2
c fixed security problem and updated free commands
e
s 00001/00003/00104
d D 4.2 82/10/02 22:50:03 comay 2 1
c uses variable "Bsh" instead of /bin/sh to execute commands
e
s 00107/00000/00000
d D 4.1 82/09/12 17:31:57 mckusick 1 0
c date and time created 82/09/12 17:31:57 by mckusick
e
u
U
t
T
I 1
static char sccsid[] = "%W%	(Berkeley)	%G%";

# include "defs.h"
D 2
# define FREELPR
E 2
/*
	nsh -c "comand to be executed"

	This pseudo-shell is executed over the network
	as the login shell of an acount "network", no passwd.
	It will only execute certain allowed commands.

	has these exit codes:
		EX_USAGE = 	wrong # arguments to nsh
		9 = 		command you execute may not take arguments
		10= 		the execl failed
		EX_UNAVAILABLE= could not find full path name for the command

	count is the # of arguments (= argc) allowed.
	a count of 0 turns off the command
*/

struct {
	char *app;
	char count;
	char *full;
	char *full1;
	} st[] = {
/* I assume these are the same for RAND */
	"mmail",	20,	"/usr/net/bin/mmail",	"/usr/net/bin/mmail",
	"mwrite",	20,	"/usr/net/bin/mwrite",	"/usr/net/bin/mwrite",
	"prmail",	20,	"/usr/net/bin/prmail",	"/usr/net/bin/prmail",
# ifndef NFREECMD
D 3
	"bpq",		20,	"/usr/bin/bpq",		"/bin/bpq",
	"epq",		20,	"/usr/bin/epq",		"/bin/epq",
E 3
	"finger",	20,	"/usr/ucb/finger",	"/usr/bin/finger",
D 3
	"help",		20,	"/bin/help",	"/usr/bin/help",
	"lpq",		20,	"/usr/bin/lpq",		"/bin/lpq",
E 3
I 3
	"lpq",		20,	"/usr/ucb/lpq",		"/usr/bin/lpq",
E 3
# ifdef FREELPR
D 3
	"lpr",		20,	"/usr/bin/lpr",		"/bin/lpr",
E 3
I 3
	"lpr",		20,	"/usr/ucb/lpr",		"/usr/bin/lpr",
E 3
# endif
	"netlog",	20,	"/usr/bin/netlog",	"/usr/ucb/netlog",
D 2
	"vpr",		20,	"/usr/ucb/vpr",		"/usr/ucb/vpr",
E 2
	"netq",		20,	"/usr/bin/netq",	"/usr/ucb/netq",
D 3
	"news",		20,	"/usr/bin/news",	"/usr/ucb/news",
E 3
	"ps",		20,	"/bin/ps",		"/usr/bin/ps",
D 3
	"pstat",	20,	"/usr/bin/pstat",	"/bin/pstat",
	"rcs",		20,	"/usr/bin/rcs",		"/bin/rcs",
	"rcslog",	1,	"/usr/bin/rcslog",	"/bin/rcslog",
	"rcsq",		20,	"/usr/bin/rcsq",	"/bin/rcsq",
	"trq",		20,	"/usr/bin/trq",		"/bin/trq",
E 3
I 3
	"pstat",	20,	"/etc/pstat",		"/usr/bin/pstat",
E 3
	"vpq",		20,	"/usr/ucb/vpq",		"/usr/bin/vpq",
	"w",		20,	"/usr/ucb/w",		"/usr/bin/w",
	"wc",		20,	"/usr/bin/wc",		"/bin/wc",
D 3
	"where",	20,	"/usr/bin/where",	"/bin/where",
E 3
	"who",		20,	"/bin/who",		"/usr/bin/who",
	"whom",		20,	"/usr/ucb/whom",	"/usr/bin/whom",
D 3
	"write",	20,	"/usr/bin/write",	"/bin/write",
E 3
	"yank",		20,	"/usr/ucb/yank",	"/usr/bin/yank",
# endif
	0, 		0,		0,		0
	};
/* nsh -c cmd */
main(argc,argv)
  char **argv; {
	char *s, buf[500];
	int i, flg = 0;
	if(argc != 3){
		fprintf(stderr,"Wrong number of arguments to nsh.\n");
		exit(EX_USAGE);
	}
I 3
	s = argv[2];
	while (*s)
		if (*s == ';'
		 || *s == '|'
		 || *s == '&'
		 || *s == '?'
		 || *s == '*'
		 || *s == '['
		 || *s == '~'
		 || *s == '{'
		 || *s == '<'
		 || *s == '>'
		 || *s == '$'
		 || *s == '`') {
			fprintf(stderr, "Illegal shell metacharacter in command.\n");
			exit(9);
		} else
			++s;
E 3
	s = argv[2];
	while(*s && *s != ' ')s++;
	if(*s == ' ')flg++;
	*s = 0;
	if((i = mlookup(argv[2])) < 0){
		fprintf(stderr,
		"Command '%s' is not allowed if logged in as 'network'.\n",
			argv[2]);
		exit(11);
	}
	if(st[i].count == 0){
		fprintf(stderr,
		"The command '%s' is not allowed to have arguments.\n",argv[2]);
		exit(9);
		}
	if(stat(st[i].full,buf) >= 0)
		strcpy(buf,st[i].full);
	else strcpy(buf,st[i].full1);
	if(flg && st[i].count > 1){  /* some cmds don't allow parms */
		*s = ' ';
		strcat(buf,s);
		}
	/*
	fprintf(stderr,"%s\n",buf);
	*/
D 2
	execl("/bin/sh","sh","-c",buf,0);
E 2
I 2
	execl(Bsh,"sh","-c",buf,0);
E 2
	fprintf(stderr,"Execute of shell failed.\n");
	exit(EX_UNAVAILABLE);
	}
mlookup(s)
  char *s; {
	int i;
	for(i = 0; st[i].app; i++)
		if(strcmp(st[i].app,s) == 0 || strcmp(st[i].full,s) == 0
		 || strcmp(st[i].full1,s) == 0)return(i);
	return(-1);
	}
E 1
