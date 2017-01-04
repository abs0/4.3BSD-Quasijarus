h04645
s 00001/00001/00114
d D 4.3 86/05/15 17:58:40 bloom 3 2
c updates from John Kunze
e
s 00031/00014/00084
d D 4.2 83/04/25 23:59:03 mckusick 2 1
c 
e
s 00098/00000/00000
d D 4.1 83/02/24 12:56:03 mckusick 1 0
c date and time created 83/02/24 12:56:03 by mckusick
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W%	(Berkeley)	%G%";
#endif not lint

# include "stdio.h"
# include "lrnref.h"
# define SAME 0

struct keys {
	char *k_wd;
	int k_val;
} keybuff[] = {
	{"ready",	READY},
	{"answer",	READY},
	{"#print",	PRINT},
	{"#copyin",	COPYIN},
	{"#uncopyin",	UNCOPIN},
	{"#copyout",	COPYOUT},
	{"#uncopyout",	UNCOPOUT},
	{"#pipe",	PIPE},
	{"#unpipe",	UNPIPE},
	{"#succeed",	SUCCEED},
	{"#fail",	FAIL},
	{"bye",		BYE},
	{"chdir",	CHDIR},
	{"cd",		CHDIR},
	{"learn",	LEARN},
	{"#log",	LOG},
	{"yes",		YES},
	{"no",		NO},
I 2
	{"again",	AGAIN},
E 2
	{"#mv",		MV},
	{"#user",	USER},
	{"#next",	NEXT},
	{"skip",	SKIP},
D 2
	{"#where",	WHERE},
E 2
I 2
	{"where",	WHERE},
E 2
	{"#match",	MATCH},
	{"#bad",	BAD},
	{"#create",	CREATE},
	{"#cmp",	CMP},
D 2
	{"#goto",	GOTO},
E 2
I 2
D 3
	{"xyzzy",	XYZZY},
E 3
I 3
	{"hint",	HINT},
E 3
E 2
	{"#once",	ONCE},
	{"#",		NOP},
	{NULL,		0}
};

int *action(s)
char *s;
{
	struct keys *kp;
	for (kp=keybuff; kp->k_wd; kp++)
		if (strcmp(kp->k_wd, s) == SAME)
			return(&(kp->k_val));
	return(NULL);
}

# define NW 100
# define NWCH 800
struct whichdid {
	char *w_less;
	int w_seq;
} which[NW];
int nwh = 0;
char whbuff[NWCH];
char *whcp = whbuff;
I 2
static struct whichdid *pw;
E 2

setdid(lesson, sequence)
char *lesson;
I 2
int sequence;
E 2
{
D 2
	struct whichdid *pw;
	for(pw=which; pw < which+nwh; pw++)
		if (strcmp(pw->w_less, lesson) == SAME)
			{
			pw->w_seq = sequence;
			return;
			}
	pw=which+nwh++;
E 2
I 2
	if (already(lesson)) {
		pw->w_seq = sequence;
		return;
	}
	pw = which+nwh++;
E 2
	if (nwh >= NW) {
D 2
		fprintf(stderr, "nwh>=NW\n");
E 2
I 2
		fprintf(stderr, "Setdid:  too many lessons\n");
		tellwhich();
E 2
		wrapup(1);
	}
	pw->w_seq = sequence;
	pw->w_less = whcp;
	while (*whcp++ = *lesson++);
	if (whcp >= whbuff + NWCH) {
D 2
		fprintf(stderr, "lesson name too long\n");
E 2
I 2
		fprintf(stderr, "Setdid:  lesson names too long\n");
		tellwhich();
E 2
		wrapup(1);
	}
}

D 2
already(lesson, sequence)
E 2
I 2
unsetdid(lesson)
E 2
char *lesson;
{
D 2
	struct whichdid *pw;
E 2
I 2
	if (!already(lesson))
		return;
	nwh = pw - which;	/* pretend the rest have not been done */
	whcp = pw->w_less;
}

already(lesson)
char *lesson;
{
E 2
	for (pw=which; pw < which+nwh; pw++)
		if (strcmp(pw->w_less, lesson) == SAME)
			return(1);
	return(0);
I 2
}

tellwhich()
{
	for (pw=which; pw < which+nwh; pw++)
		printf("%3d lesson %7s sequence %3d\n",
			pw-which, pw->w_less, pw->w_seq);
E 2
}
E 1
