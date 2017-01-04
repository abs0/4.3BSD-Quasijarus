
# line 26 "ftpcmd.y"

#ifndef lint
static char sccsid[] = "@(#)ftpcmd.y	5.17 (Berkeley) 4/16/11";
#endif /* not lint */

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>

#include <netinet/in.h>

#include <arpa/ftp.h>

#include <stdio.h>
#include <signal.h>
#include <errno.h>
#include <ctype.h>
#include <pwd.h>
#include <setjmp.h>
#include <syslog.h>

extern	int errno;
extern	char *sys_errlist[];

extern	struct sockaddr_in data_dest;
extern	int logged_in;
extern	struct passwd *pw;
extern	int logging;
extern	int type;
extern	int form;
extern	int debug;
extern	int timeout;
extern  int pdata;
extern	char hostname[];
extern	int usedefault;
extern  int transflag;
extern  char tmpline[];
extern  char **guestdirs;
extern  int nguestdirs;
extern	int longlist;
extern	int chrooted;

static	int cmd_type;
static	int cmd_form;
static	int cmd_bytesz;
char cbuf[512];
char *fromname;

char	*index();
# define A 257
# define B 258
# define C 259
# define E 260
# define F 261
# define I 262
# define L 263
# define N 264
# define P 265
# define R 266
# define S 267
# define T 268
# define SP 269
# define CRLF 270
# define COMMA 271
# define STRING 272
# define NUMBER 273
# define USER 274
# define PASS 275
# define ACCT 276
# define REIN 277
# define QUIT 278
# define PORT 279
# define PASV 280
# define TYPE 281
# define STRU 282
# define MODE 283
# define RETR 284
# define STOR 285
# define APPE 286
# define MLFL 287
# define MAIL 288
# define MSND 289
# define MSOM 290
# define MSAM 291
# define MRSQ 292
# define MRCP 293
# define ALLO 294
# define REST 295
# define RNFR 296
# define RNTO 297
# define ABOR 298
# define DELE 299
# define CWD 300
# define LIST 301
# define NLST 302
# define SITE 303
# define STAT 304
# define HELP 305
# define NOOP 306
# define XMKD 307
# define XRMD 308
# define XPWD 309
# define XCUP 310
# define STOU 311
# define LEXERR 312
#define yyclearin yychar = -1
#define yyerrok yyerrflag = 0
extern int yychar;
extern short yyerrflag;
#ifndef YYMAXDEPTH
#define YYMAXDEPTH 150
#endif
#ifndef YYSTYPE
#define YYSTYPE int
#endif
YYSTYPE yylval, yyval;
# define YYERRCODE 256

# line 493 "ftpcmd.y"


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
	{ "PASV", PASV, ARGS, 1,	"(set server in passive mode)" },
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
	{ "ABOR", ABOR, ARGS, 1,	"(abort operation)" },
	{ "DELE", DELE, STR1, 1,	"<sp> file-name" },
	{ "CWD",  CWD,  OSTR, 1,	"[ <sp> directory-name]" },
	{ "XCWD", CWD,	OSTR, 1,	"[ <sp> directory-name ]" },
	{ "LIST", LIST, OSTR, 1,	"[ <sp> path-name ]" },
	{ "NLST", NLST, OSTR, 1,	"[ <sp> path-name ]" },
	{ "SITE", SITE, STR1, 0,	"(get site parameters)" },
	{ "STAT", STAT, OSTR, 0,	"(get server status)" },
	{ "HELP", HELP, OSTR, 1,	"[ <sp> <string> ]" },
	{ "NOOP", NOOP, ARGS, 1,	"" },
	{ "MKD",  XMKD, STR1, 1,	"<sp> path-name" },
	{ "XMKD", XMKD, STR1, 1,	"<sp> path-name" },
	{ "RMD",  XRMD, STR1, 1,	"<sp> path-name" },
	{ "XRMD", XRMD, STR1, 1,	"<sp> path-name" },
	{ "PWD",  XPWD, ARGS, 1,	"(return current directory)" },
	{ "XPWD", XPWD, ARGS, 1,	"(return current directory)" },
	{ "CDUP", XCUP, ARGS, 1,	"(change to parent directory)" },
	{ "XCUP", XCUP, ARGS, 1,	"(change to parent directory)" },
	{ "STOU", STOU, STR1, 1,	"<sp> file-name" },
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

#include <arpa/telnet.h>

/*
 * getline - a hacked up version of fgets to ignore TELNET escape codes.
 */
char *
getline(s, n, iop)
	char *s;
	register FILE *iop;
{
	register c;
	register char *cs;

	cs = s;
/* tmpline may contain saved command from urgent mode interruption */
	for (c = 0; tmpline[c] != '\0' && --n > 0; ++c) {
		*cs++ = tmpline[c];
		if (tmpline[c] == '\n') {
			*cs++ = '\0';
			if (debug) {
				syslog(LOG_DEBUG, "FTPD: command: %s", s);
			}
			tmpline[0] = '\0';
			return(s);
		}
		if (c == 0) {
			tmpline[0] = '\0';
		}
	}
	while (--n > 0 && (c = getc(iop)) != EOF) {
		c = 0377 & c;
		while (c == IAC) {
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
		}
		*cs++ = c;
		if (c=='\n')
			break;
	}
	if (c == EOF && cs == s)
		return (NULL);
	*cs++ = '\0';
	if (debug) {
		syslog(LOG_DEBUG, "FTPD: command: %s", s);
	}
	return (s);
}

static int
toolong()
{
	time_t now;
	extern char *ctime();
	extern time_t time();

	reply(421,
	  "Timeout (%d seconds): closing control connection.", timeout);
	(void) time(&now);
	if (logging) {
		syslog(LOG_INFO,
			"FTPD: User %s timed out after %d seconds at %s",
			(pw ? pw -> pw_name : "unknown"), timeout, ctime(&now));
	}
	dologout(1);
}

yylex()
{
	static int cpos, state;
	register char *cp;
	register struct tab *p;
	int n;
	char c;

	for (;;) {
		switch (state) {

		case CMD:
			(void) signal(SIGALRM, toolong);
			(void) alarm((unsigned) timeout);
			if (getline(cbuf, sizeof(cbuf)-1, stdin) == NULL) {
				reply(221, "You could at least say goodbye.");
				dologout(0);
			}
			(void) alarm(0);
			if (index(cbuf, '\r')) {
				cp = index(cbuf, '\r');
				cp[0] = '\n'; cp[1] = 0;
			}
			if (index(cbuf, ' '))
				cpos = index(cbuf, ' ') - cbuf;
			else
				cpos = index(cbuf, '\n') - cbuf;
			if (cpos == 0) {
				cpos = 4;
			}
			c = cbuf[cpos];
			cbuf[cpos] = '\0';
			upper(cbuf);
			p = lookup(cbuf);
			cbuf[cpos] = c;
			if (p != 0) {
				if (p->implemented == 0) {
					nack(p->name);
					longjmp(errcatch,0);
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
		yyerror((char *) 0);
		state = CMD;
		longjmp(errcatch,0);
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
	extern char *malloc(), *strcpy();

	p = malloc((unsigned) strlen(s) + 1);
	if (p == NULL)
		fatal("Ran out of memory.");
	(void) strcpy(p, s);
	return ((int)p);
}

help(s)
	char *s;
{
	register struct tab *c;
	register int width, NCMDS;

	width = 0, NCMDS = 0;
	for (c = cmdtab; c->name != NULL; c++) {
		int len = strlen(c->name) + 1;

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
			printf("   ");
			for (j = 0; j < columns; j++) {
				c = cmdtab + j * lines + i;
				printf("%s%c", c->name,
					c->implemented ? ' ' : '*');
				if (c + lines >= &cmdtab[NCMDS])
					break;
				w = strlen(c->name) + 1;
				while (w < width) {
					putchar(' ');
					w++;
				}
			}
			printf("\r\n");
		}
		(void) fflush(stdout);
		reply(214, "Direct comments to ftp-bugs@%s.", hostname);
		return;
	}
	upper(s);
	c = lookup(s);
	if (c == (struct tab *)0) {
		reply(502, "Unknown command %s.", s);
		return;
	}
	if (c->implemented)
		reply(214, "Syntax: %s %s", c->name, c->help);
	else
		reply(214, "%-*s\t%s; unimplemented.", width, c->name, c->help);
}
short yyexca[] ={
-1, 1,
	0, -1,
	-2, 0,
	};
# define YYNPROD 59
# define YYLAST 215
short yyact[]={

  29, 106, 150, 148, 146, 108, 144, 108, 125,  78,
  64,  89,  92,  62,  60, 107, 149, 147,   4,   5,
 145, 143,  28,   6,   7,   8,   9,  10,  12,  13,
  14, 102,  91,  90,  85,  84,  83,  82,  11, 142,
  30,  18,  19,  17,  20,  16,  15,  49,  48,  21,
  22,  23,  24,  25,  26,  27, 141, 140, 139, 138,
 137, 136, 135, 134, 133, 132, 129, 120, 118, 111,
 110, 127, 109, 103, 101, 128, 100,  87,  99,  96,
  95,  57,  56,  50,  46,  34, 105, 104,  98,  97,
  94,  93,  86,  81,  80,  79,  76,  77,  45,  38,
  37,  36,  35,  33,  32,  75,  31,  71, 126,  39,
  66,  73,  72,  67,  88,  68,  69,  74,  70,  65,
  63,  61, 131,  40,  41,  42,  43,  44,  59,   3,
  47,   2,   1,  51,  52,  53,  54,  55,   0,   0,
  58,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0, 112, 113, 114,
   0, 115,   0, 116, 117,   0,   0,   0,   0, 119,
   0, 121, 122,   0,   0, 123, 124,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0, 130 };
short yypact[]={

-1000,-256,-1000,-1000,-163,-165,-166,-185,-167,-168,
-169,-170,-1000,-1000,-1000,-1000,-1000,-1000,-171,-186,
-1000,-222,-187,-1000,-1000,-1000,-1000,-1000,-188,-189,
-1000,-258,-259,-263,-1000,-147,-154,-162,-264,-174,
-175,-176,-233,-235,-177,-261,-1000,-237,-1000,-260,
-1000,-178,-179,-190,-191,-180,-1000,-1000,-181,-192,
-1000,-194,-1000,-196,-240,-197,-182,-183,-1000,-268,
-198,-1000,-1000,-1000,-200,-1000,-1000,-1000,-201,-261,
-261,-261,-1000,-261,-1000,-261,-261,-202,-1000,-1000,
-1000,-261,-203,-261,-261,-1000,-1000,-261,-261,-1000,
-1000,-1000,-265,-1000,-193,-193,-266,-1000,-1000,-1000,
-1000,-1000,-205,-206,-207,-208,-209,-210,-1000,-211,
-1000,-212,-213,-214,-231,-250,-1000,-1000,-1000,-1000,
-1000,-1000,-1000,-1000,-1000,-1000,-1000,-1000,-1000,-1000,
-1000,-1000,-1000,-267,-251,-269,-254,-270,-255,-271,
-1000 };
short yypgo[]={

   0, 132, 131, 129, 128, 121, 120, 119, 118, 117,
 109,  77,  15, 108, 114 };
short yyr1[]={

   0,   1,   1,   1,   2,   2,   2,   2,   2,   2,
   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,
   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,
   2,   2,   2,   2,   3,   4,   5,  12,   6,  13,
  13,  13,   7,   7,   7,   7,   7,   7,   7,   7,
   8,   8,   8,   9,   9,   9,  11,  14,  10 };
short yyr2[]={

   0,   0,   2,   2,   4,   4,   4,   2,   4,   4,
   4,   4,   5,   5,   5,   3,   5,   3,   5,   5,
   4,   2,   3,   5,   2,   4,   2,   5,   5,   3,
   3,   5,   2,   2,   5,   1,   1,   1,  11,   1,
   1,   1,   1,   3,   1,   3,   1,   1,   3,   2,
   1,   1,   1,   1,   1,   1,   1,   1,   0 };
short yychk[]={

-1000,  -1,  -2,  -3, 274, 275, 279, 280, 281, 282,
 283, 294, 284, 285, 286, 302, 301, 299, 297, 298,
 300, 305, 306, 307, 308, 309, 310, 311, 278, 256,
 296, 269, 269, 269, 270, 269, 269, 269, 269, -10,
 -10, -10, -10, -10, -10, 269, 270, -10, 270, 269,
 270, -10, -10, -10, -10, -10, 270, 270, -10,  -4,
 272,  -5, 272,  -6, 273,  -7, 257, 260, 262, 263,
  -8, 261, 266, 265,  -9, 267, 258, 259, 273, 269,
 269, 269, 270, 269, 270, 269, 269, -11, -14, 272,
 270, 269, 272, 269, 269, 270, 270, 269, 269, 270,
 270, 270, 271, 270, 269, 269, 269, -12, 273, 270,
 270, 270, -11, -11, -11, -11, -11, -11, 270, -11,
 270, -11, -11, -11, -11, 273, -13, 264, 268, 259,
 -13, -12, 270, 270, 270, 270, 270, 270, 270, 270,
 270, 270, 270, 271, 273, 271, 273, 271, 273, 271,
 273 };
short yydef[]={

   1,  -2,   2,   3,   0,   0,   0,   0,   0,   0,
   0,   0,  58,  58,  58,  58,  58,  58,   0,   0,
  58,   0,   0,  58,  58,  58,  58,  58,   0,   0,
  58,   0,   0,   0,   7,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,  21,   0,  24,   0,
  26,   0,   0,   0,   0,   0,  32,  33,   0,   0,
  35,   0,  36,   0,   0,   0,  42,  44,  46,  47,
   0,  50,  51,  52,   0,  53,  54,  55,   0,   0,
   0,   0,  15,   0,  17,   0,   0,   0,  56,  57,
  22,   0,   0,   0,   0,  29,  30,   0,   0,   4,
   5,   6,   0,   8,   0,   0,   0,  49,  37,   9,
  10,  11,   0,   0,   0,   0,   0,   0,  20,   0,
  25,   0,   0,   0,   0,   0,  43,  39,  40,  41,
  45,  48,  12,  13,  14,  16,  18,  19,  23,  27,
  28,  31,  34,   0,   0,   0,   0,   0,   0,   0,
  38 };
#ifndef lint
static char yaccpar_sccsid[] = "@(#)yaccpar	4.1	(Berkeley)	2/11/83";
#endif not lint

#
# define YYFLAG -1000
# define YYERROR goto yyerrlab
# define YYACCEPT return(0)
# define YYABORT return(1)

/*	parser for yacc output	*/

#ifdef YYDEBUG
int yydebug = 0; /* 1 for debugging */
#endif
YYSTYPE yyv[YYMAXDEPTH]; /* where the values are stored */
int yychar = -1; /* current input token number */
int yynerrs = 0;  /* number of errors */
short yyerrflag = 0;  /* error recovery flag */

yyparse() {

	short yys[YYMAXDEPTH];
	short yyj, yym;
	register YYSTYPE *yypvt;
	register short yystate, *yyps, yyn;
	register YYSTYPE *yypv;
	register short *yyxi;

	yystate = 0;
	yychar = -1;
	yynerrs = 0;
	yyerrflag = 0;
	yyps= &yys[-1];
	yypv= &yyv[-1];

 yystack:    /* put a state and value onto the stack */

#ifdef YYDEBUG
	if( yydebug  ) printf( "state %d, char 0%o\n", yystate, yychar );
#endif
		if( ++yyps> &yys[YYMAXDEPTH] ) { yyerror( "yacc stack overflow" ); return(1); }
		*yyps = yystate;
		++yypv;
		*yypv = yyval;

 yynewstate:

	yyn = yypact[yystate];

	if( yyn<= YYFLAG ) goto yydefault; /* simple state */

	if( yychar<0 ) if( (yychar=yylex())<0 ) yychar=0;
	if( (yyn += yychar)<0 || yyn >= YYLAST ) goto yydefault;

	if( yychk[ yyn=yyact[ yyn ] ] == yychar ){ /* valid shift */
		yychar = -1;
		yyval = yylval;
		yystate = yyn;
		if( yyerrflag > 0 ) --yyerrflag;
		goto yystack;
		}

 yydefault:
	/* default state action */

	if( (yyn=yydef[yystate]) == -2 ) {
		if( yychar<0 ) if( (yychar=yylex())<0 ) yychar = 0;
		/* look through exception table */

		for( yyxi=yyexca; (*yyxi!= (-1)) || (yyxi[1]!=yystate) ; yyxi += 2 ) ; /* VOID */

		while( *(yyxi+=2) >= 0 ){
			if( *yyxi == yychar ) break;
			}
		if( (yyn = yyxi[1]) < 0 ) return(0);   /* accept */
		}

	if( yyn == 0 ){ /* error */
		/* error ... attempt to resume parsing */

		switch( yyerrflag ){

		case 0:   /* brand new error */

			yyerror( "syntax error" );
		yyerrlab:
			++yynerrs;

		case 1:
		case 2: /* incompletely recovered error ... try again */

			yyerrflag = 3;

			/* find a state where "error" is a legal shift action */

			while ( yyps >= yys ) {
			   yyn = yypact[*yyps] + YYERRCODE;
			   if( yyn>= 0 && yyn < YYLAST && yychk[yyact[yyn]] == YYERRCODE ){
			      yystate = yyact[yyn];  /* simulate a shift of "error" */
			      goto yystack;
			      }
			   yyn = yypact[*yyps];

			   /* the current yyps has no shift onn "error", pop stack */

#ifdef YYDEBUG
			   if( yydebug ) printf( "error recovery pops state %d, uncovers %d\n", *yyps, yyps[-1] );
#endif
			   --yyps;
			   --yypv;
			   }

			/* there is no state on the stack with an error shift ... abort */

	yyabort:
			return(1);


		case 3:  /* no shift yet; clobber input char */

#ifdef YYDEBUG
			if( yydebug ) printf( "error recovery discards char %d\n", yychar );
#endif

			if( yychar == 0 ) goto yyabort; /* don't discard EOF, quit */
			yychar = -1;
			goto yynewstate;   /* try again in the same state */

			}

		}

	/* reduction by production yyn */

#ifdef YYDEBUG
		if( yydebug ) printf("reduce %d\n",yyn);
#endif
		yyps -= yyr2[yyn];
		yypvt = yypv;
		yypv -= yyr2[yyn];
		yyval = yypv[1];
		yym=yyn;
			/* consult goto table to find next state */
		yyn = yyr1[yyn];
		yyj = yypgo[yyn] + *yyps + 1;
		if( yyj>=YYLAST || yychk[ yystate = yyact[yyj] ] != -yyn ) yystate = yyact[yypgo[yyn]];
		switch(yym){
			
case 2:
# line 99 "ftpcmd.y"
 {
			fromname = (char *) 0;
		} break;
case 4:
# line 106 "ftpcmd.y"
 {
			user((char *) yypvt[-1]);
			free((char *) yypvt[-1]);
		} break;
case 5:
# line 111 "ftpcmd.y"
 {
			pass((char *) yypvt[-1]);
			free((char *) yypvt[-1]);
		} break;
case 6:
# line 116 "ftpcmd.y"
 {
			usedefault = 0;
			if (pdata > 0) {
				(void) close(pdata);
			}
			pdata = -1;
			reply(200, "PORT command successful.");
		} break;
case 7:
# line 125 "ftpcmd.y"
 {
			passive();
		} break;
case 8:
# line 129 "ftpcmd.y"
 {
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
		} break;
case 9:
# line 160 "ftpcmd.y"
 {
			switch (yypvt[-1]) {

			case STRU_F:
				reply(200, "STRU F ok.");
				break;

			default:
				reply(504, "Unimplemented STRU type.");
			}
		} break;
case 10:
# line 172 "ftpcmd.y"
 {
			switch (yypvt[-1]) {

			case MODE_S:
				reply(200, "MODE S ok.");
				break;

			default:
				reply(502, "Unimplemented MODE type.");
			}
		} break;
case 11:
# line 184 "ftpcmd.y"
 {
			reply(202, "ALLO command ignored.");
		} break;
case 12:
# line 188 "ftpcmd.y"
 {
			if (yypvt[-3] && yypvt[-1] != NULL)
				retrieve((char *) 0, (char *) yypvt[-1]);
			if (yypvt[-1] != NULL)
				free((char *) yypvt[-1]);
		} break;
case 13:
# line 195 "ftpcmd.y"
 {
			if (yypvt[-3] && yypvt[-1] != NULL)
				store((char *) yypvt[-1], "w");
			if (yypvt[-1] != NULL)
				free((char *) yypvt[-1]);
		} break;
case 14:
# line 202 "ftpcmd.y"
 {
			if (yypvt[-3] && yypvt[-1] != NULL)
				store((char *) yypvt[-1], "a");
			if (yypvt[-1] != NULL)
				free((char *) yypvt[-1]);
		} break;
case 15:
# line 209 "ftpcmd.y"
 {
			longlist = 0;
			if (yypvt[-1])
				list(NULL, 0);
		} break;
case 16:
# line 215 "ftpcmd.y"
 {
			struct stat st;

			longlist = 0;
			if (yypvt[-3] && yypvt[-1] != NULL)
				list(yypvt[-1], 0);
			if (yypvt[-1] != NULL)
				free((char *) yypvt[-1]);
		} break;
case 17:
# line 225 "ftpcmd.y"
 {
			longlist = 1;
			if (yypvt[-1])
				list(NULL, 1);
		} break;
case 18:
# line 231 "ftpcmd.y"
 {
			struct stat st;

			longlist = 1;
			if (yypvt[-3] && yypvt[-1] != NULL)
				list(yypvt[-1], 1);
			if (yypvt[-1] != NULL)
				free((char *) yypvt[-1]);
		} break;
case 19:
# line 241 "ftpcmd.y"
 {
			if (yypvt[-3] && yypvt[-1] != NULL)
				delete((char *) yypvt[-1]);
			if (yypvt[-1] != NULL)
				free((char *) yypvt[-1]);
		} break;
case 20:
# line 248 "ftpcmd.y"
 {
			if (fromname) {
				renamecmd(fromname, (char *) yypvt[-1]);
				free(fromname);
				fromname = (char *) 0;
			} else {
				reply(503, "Bad sequence of commands.");
			}
			free((char *) yypvt[-1]);
		} break;
case 21:
# line 259 "ftpcmd.y"
 {
			reply(225, "ABOR command successful.");
		} break;
case 22:
# line 263 "ftpcmd.y"
 {
			if (yypvt[-1])
				cwd(pw->pw_dir);
		} break;
case 23:
# line 268 "ftpcmd.y"
 {
			if (yypvt[-3] && yypvt[-1] != NULL)
				cwd((char *) yypvt[-1]);
			if (yypvt[-1] != NULL)
				free((char *) yypvt[-1]);
		} break;
case 24:
# line 275 "ftpcmd.y"
 {
			help((char *) 0);
		} break;
case 25:
# line 279 "ftpcmd.y"
 {
			help((char *) yypvt[-1]);
		} break;
case 26:
# line 283 "ftpcmd.y"
 {
			reply(200, "NOOP command successful.");
		} break;
case 27:
# line 287 "ftpcmd.y"
 {
			if (yypvt[-3] && yypvt[-1] != NULL)
				makedir((char *) yypvt[-1]);
			if (yypvt[-1] != NULL)
				free((char *) yypvt[-1]);
		} break;
case 28:
# line 294 "ftpcmd.y"
 {
			if (yypvt[-3] && yypvt[-1] != NULL)
				removedir((char *) yypvt[-1]);
			if (yypvt[-1] != NULL)
				free((char *) yypvt[-1]);
		} break;
case 29:
# line 301 "ftpcmd.y"
 {
			if (yypvt[-1])
				pwd();
		} break;
case 30:
# line 306 "ftpcmd.y"
 {
			if (yypvt[-1])
				cwd("..");
		} break;
case 31:
# line 311 "ftpcmd.y"
 {
			if (yypvt[-3] && yypvt[-1] != NULL) {
				store((char *) yypvt[-1], "u");
			}
			if (yypvt[-1] != NULL)
				free((char *) yypvt[-1]);
		} break;
case 32:
# line 319 "ftpcmd.y"
 {
			reply(221, "Goodbye.");
			dologout(0);
		} break;
case 33:
# line 324 "ftpcmd.y"
 {
			yyerrok;
		} break;
case 34:
# line 330 "ftpcmd.y"
 {
			char *renamefrom();

			if (yypvt[-3] && yypvt[-1]) {
				fromname = renamefrom((char *) yypvt[-1]);
				if (fromname == (char *) 0 && yypvt[-1]) {
					free((char *) yypvt[-1]);
				}
			}
		} break;
case 38:
# line 353 "ftpcmd.y"
 {
			register char *a, *p;

			a = (char *)&data_dest.sin_addr;
			a[0] = yypvt[-10]; a[1] = yypvt[-8]; a[2] = yypvt[-6]; a[3] = yypvt[-4];
			p = (char *)&data_dest.sin_port;
			p[0] = yypvt[-2]; p[1] = yypvt[-0];
			data_dest.sin_family = AF_INET;
		} break;
case 39:
# line 365 "ftpcmd.y"
 {
		yyval = FORM_N;
	} break;
case 40:
# line 369 "ftpcmd.y"
 {
		yyval = FORM_T;
	} break;
case 41:
# line 373 "ftpcmd.y"
 {
		yyval = FORM_C;
	} break;
case 42:
# line 379 "ftpcmd.y"
 {
		cmd_type = TYPE_A;
		cmd_form = FORM_N;
	} break;
case 43:
# line 384 "ftpcmd.y"
 {
		cmd_type = TYPE_A;
		cmd_form = yypvt[-0];
	} break;
case 44:
# line 389 "ftpcmd.y"
 {
		cmd_type = TYPE_E;
		cmd_form = FORM_N;
	} break;
case 45:
# line 394 "ftpcmd.y"
 {
		cmd_type = TYPE_E;
		cmd_form = yypvt[-0];
	} break;
case 46:
# line 399 "ftpcmd.y"
 {
		cmd_type = TYPE_I;
	} break;
case 47:
# line 403 "ftpcmd.y"
 {
		cmd_type = TYPE_L;
		cmd_bytesz = 8;
	} break;
case 48:
# line 408 "ftpcmd.y"
 {
		cmd_type = TYPE_L;
		cmd_bytesz = yypvt[-0];
	} break;
case 49:
# line 414 "ftpcmd.y"
 {
		cmd_type = TYPE_L;
		cmd_bytesz = yypvt[-0];
	} break;
case 50:
# line 421 "ftpcmd.y"
 {
		yyval = STRU_F;
	} break;
case 51:
# line 425 "ftpcmd.y"
 {
		yyval = STRU_R;
	} break;
case 52:
# line 429 "ftpcmd.y"
 {
		yyval = STRU_P;
	} break;
case 53:
# line 435 "ftpcmd.y"
 {
		yyval = MODE_S;
	} break;
case 54:
# line 439 "ftpcmd.y"
 {
		yyval = MODE_B;
	} break;
case 55:
# line 443 "ftpcmd.y"
 {
		yyval = MODE_C;
	} break;
case 56:
# line 449 "ftpcmd.y"
 {
		if (yypvt[-0] && *((char *) yypvt[-0]) == '~' && !chrooted) {
			char *user, *tail, *buf;
			struct passwd *upw;
			extern char *malloc(), *index();

			user = ((char *) yypvt[-0]) + 1;
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
				free((char *) yypvt[-0]);
				yyval = (int) buf;
			} else
				yyval = yypvt[-0];
		} else
			yyval = yypvt[-0];
	} break;
case 58:
# line 483 "ftpcmd.y"
 {
		if (logged_in)
			yyval = 1;
		else {
			reply(530, "Please login with USER and PASS.");
			yyval = 0;
		}
	} break;
		}
		goto yystack;  /* stack new state and value */

	}
