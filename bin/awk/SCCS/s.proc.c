h63296
s 00003/00001/00086
d D 4.3 83/08/11 20:10:01 sam 3 2
c standardize keyword lines
e
s 00002/00001/00085
d D 4.2 83/02/09 14:07:15 sam 2 1
c merge from sun
e
s 00086/00000/00000
d D 4.1 82/05/07 19:24:45 mckusick 1 0
c date and time created 82/05/07 19:24:45 by mckusick
e
u
U
t
T
I 1
D 3
/*	%M%	%I%	%E%	*/
E 3
I 3
#ifndef lint
static char sccsid[] = "%W% %G%";
#endif
E 3

#include "awk.h"
#define NULL 0
struct xx
{	int token;
	char *name;
	char *pname;
} proc[] = {
	{ PROGRAM, "program", NULL},
	{ BOR, "boolop", " || "},
	{ AND, "boolop", " && "},
	{ NOT, "boolop", " !"},
	{ NE, "relop", " != "},
	{ EQ, "relop", " == "},
	{ LE, "relop", " <= "},
	{ LT, "relop", " < "},
	{ GE, "relop", " >= "},
	{ GT, "relop", " > "},
	{ ARRAY, "array", NULL},
	{ INDIRECT, "indirect", "$("},
	{ SUBSTR, "substr", "substr"},
	{ INDEX, "sindex", "sindex"},
	{ SPRINTF, "asprintf", "sprintf "},
	{ ADD, "arith", " + "},
	{ MINUS, "arith", " - "},
	{ MULT, "arith", " * "},
	{ DIVIDE, "arith", " / "},
	{ MOD, "arith", " % "},
	{ UMINUS, "arith", " -"},
	{ PREINCR, "incrdecr", "++"},
	{ POSTINCR, "incrdecr", "++"},
	{ PREDECR, "incrdecr", "--"},
	{ POSTDECR, "incrdecr", "--"},
	{ CAT, "cat", " "},
	{ PASTAT, "pastat", NULL},
	{ PASTAT2, "dopa2", NULL},
	{ MATCH, "matchop", " ~ "},
	{ NOTMATCH, "matchop", " !~ "},
	{ PRINTF, "aprintf", "printf"},
	{ PRINT, "print", "print"},
	{ SPLIT, "split", "split"},
	{ ASSIGN, "assign", " = "},
	{ ADDEQ, "assign", " += "},
	{ SUBEQ, "assign", " -= "},
	{ MULTEQ, "assign", " *= "},
	{ DIVEQ, "assign", " /= "},
	{ MODEQ, "assign", " %= "},
	{ IF, "ifstat", "if("},
	{ WHILE, "whilestat", "while("},
	{ FOR, "forstat", "for("},
	{ IN, "instat", "instat"},
	{ NEXT, "jump", "next"},
	{ EXIT, "jump", "exit"},
	{ BREAK, "jump", "break"},
	{ CONTINUE, "jump", "continue"},
	{ FNCN, "fncn", "fncn"},
	{ GETLINE, "getline", "getline"},
	{ 0, ""},
};
#define SIZE	LASTTOKEN - FIRSTTOKEN
char *table[SIZE];
char *names[SIZE];
main()
{	struct xx *p;
	int i;
	printf("#include \"awk.def\"\n");
	printf("obj nullproc();\n");
	for(p=proc;p->token!=0;p++)
		if(p==proc || strcmp(p->name, (p-1)->name))
			printf("extern obj %s();\n",p->name);
	for(p=proc;p->token!=0;p++)
		table[p->token-FIRSTTOKEN]=p->name;
	printf("obj (*proctab[%d])() = {\n", SIZE);
	for(i=0;i<SIZE;i++)
		if(table[i]==0) printf("/*%s*/\tnullproc,\n",tokname(i+FIRSTTOKEN));
		else printf("/*%s*/\t%s,\n",tokname(i+FIRSTTOKEN),table[i]);
	printf("};\n");
	printf("char *printname[%d] = {\n", SIZE);
	for(p=proc; p->token!=0; p++)
		names[p->token-FIRSTTOKEN] = p->pname;
	for(i=0; i<SIZE; i++)
D 2
		printf("/*%s*/\t\"%s\",\n",tokname(i+FIRSTTOKEN),names[i]);
E 2
I 2
		printf("/*%s*/\t\"%s\",\n",tokname(i+FIRSTTOKEN),
						names[i]?names[i]:"");
E 2
	printf("};\n");
	exit(0);
}
E 1
