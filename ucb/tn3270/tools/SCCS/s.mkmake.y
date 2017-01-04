h52730
s 00010/00017/01068
d D 1.18 88/03/28 12:08:23 bostic 18 17
c add Berkeley specific headers
e
s 00004/00000/01081
d D 1.17 87/07/17 10:08:12 minshall 17 16
c Add sccs header
e
s 00022/00000/01059
d D 1.16 87/07/17 10:06:13 minshall 16 15
c Install sccs headers and copyright notices.
e
s 00006/00001/01053
d D 1.15 87/07/03 14:34:42 minshall 15 14
c Deal with backslashed quotes.
e
s 00003/00003/01051
d D 1.14 87/07/03 10:09:17 minshall 14 13
c Don't compress spaces too soon in expanding variables in a
c 'for' statement.
e
s 00018/00012/01036
d D 1.13 87/06/30 23:29:44 minshall 13 12
c Better and better.
e
s 00105/00028/00943
d D 1.12 87/06/30 20:49:48 minshall 12 11
c More fixes.
e
s 00074/00011/00897
d D 1.11 87/06/30 16:19:08 minshall 11 10
c Seems to do for commands reasonably well.
e
s 00027/00013/00881
d D 1.10 87/06/26 16:37:02 minshall 10 9
c More goodness
e
s 00045/00044/00849
d D 1.9 87/06/26 16:15:39 minshall 9 8
c Pretty good version, for now.
e
s 00109/00046/00784
d D 1.8 87/06/26 15:26:50 minshall 8 7
c Interim version.
e
s 00150/00020/00680
d D 1.7 87/06/24 17:43:19 minshall 7 6
c This version knows about for statements (though it doesn't
e
s 00023/00001/00677
d D 1.6 87/06/24 16:29:47 minshall 6 5
c Doesn't expand variables in real time.
e
s 00031/00006/00647
d D 1.5 87/06/22 09:15:06 minshall 5 4
c All but end of file.
e
s 00060/00056/00593
d D 1.4 87/06/21 23:45:42 minshall 4 3
c loops.
e
s 00090/00067/00559
d D 1.3 87/06/21 22:42:10 minshall 3 2
c another version.
e
s 00441/00121/00185
d D 1.2 87/06/21 09:34:49 minshall 2 1
c Before messing around a bit.
e
s 00306/00000/00000
d D 1.1 87/06/20 11:36:07 minshall 1 0
c date and time created 87/06/20 11:36:07 by minshall
e
u
U
t
T
I 1
%{
I 16

/*
D 18
 *	Copyright (c) 1984-1987 by the Regents of the
 *	University of California and by Gregory Glenn Minshall.
E 18
I 18
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
E 18
 *
D 18
 *	Permission to use, copy, modify, and distribute these
 *	programs and their documentation for any purpose and
 *	without fee is hereby granted, provided that this
 *	copyright and permission appear on all copies and
 *	supporting documentation, the name of the Regents of
 *	the University of California not be used in advertising
 *	or publicity pertaining to distribution of the programs
 *	without specific prior permission, and notice be given in
 *	supporting documentation that copying and distribution is
 *	by permission of the Regents of the University of California
 *	and by Gregory Glenn Minshall.  Neither the Regents of the
 *	University of California nor Gregory Glenn Minshall make
 *	representations about the suitability of this software
 *	for any purpose.  It is provided "as is" without
 *	express or implied warranty.
E 18
I 18
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
 *
 *	%W% (Berkeley) %G%
E 18
 */

E 16
typedef struct string {
    int
	hashval,
	length;
    char
	*string;
    struct string
	*next;
} string_t;

I 2
/*
 * The deal with these is that they exist on various lists.
 *
 * First off, they are on a temporary list during the time they
 * are in the active focus of the parser.
 *
 * Secondly, they live on one of three queues:
 *	1.  Variables
 *	2.  Targets
 *	3.  Actions
 * (and, we restrict any given one to live on one and only one such list)
 *
 * Also, they may live on the list of values for someone else's variable,
 * or as someone's dependancy.
 */

E 2
typedef struct same {
I 3
D 4
    unsigned int
	visit_time;			/* For loops */
E 4
E 3
D 2
    int
	myname,
	values,		/* If a variable, the values */
	action;		/* If a target, the action number */
    struct same
	*moretokens,
	*depends;
E 2
    string_t
D 2
	*string;
E 2
I 2
	*string;			/* My name */
    struct same
	*nexttoken,			/* Next pointer */
	*lasttoken,			/* Back pointer */
	*depend_list,			/* If target, dependancies */
	*action_list,			/* If target, actions */
D 8
	*value_list;			/* If variable, value list */
E 8
I 8
	*value_list,			/* If variable, value list */
	*shell_item;			/* If a shell variable, current value */
E 8
E 2
} same_t;

D 2
same_t
    *add_depends(),
    *assign(),
    *token_cat(),
    *token_item();
E 2
%}

%union {
    string_t *string;
    same_t *same;
I 2
    int	intval;
E 2
    }

I 5
%start makefile
I 7
D 8
%token <intval>	FOR IN DO DONE
E 8
E 7
E 5
D 2
%token <string> TOKEN
%token END_OF_FILE NL
E 2
I 2
%token <string> TOKEN QUOTED_STRING
D 7
%token <intval> MACRO_CHAR BREAK_CHAR WHITE_SPACE NL END_OF_FILE
%token <intval> ':' '=' '$' '{' '}'
E 2
%type <same> target assignment actions action tokens token
E 7
I 7
D 8
%token <intval> MACRO_CHAR WHITE_SPACE NL END_OF_FILE
%token <intval> ':' '=' '$' '{' '}' ';' '-' '@' '(' ')'
%type <same> target assignment actions action
%type <same> for_statement maybe_at_minus tokens token
E 7
I 2
%type <intval> special_chars white_space macro_char
E 8
I 8
%token <intval>	FOR IN DO DONE
%token <intval> MACRO_CHAR NL WHITE_SPACE
%token <intval> ':' '=' '$' '{' '}' ';' '-' '@' '(' ')' ' ' '\t'
D 9
%type <same> target assignment assign1 actions action command_list command list
%type <same> for_statement maybe_at_minus tokens token non_white_token
%type <same> maybe_tokens
E 9
I 9
%type <same> target target1 assignment assign1 actions action
D 13
%type <same> command_list command list
E 13
I 13
%type <same> command_list list list_element
E 13
D 11
%type <same> for_statement maybe_at_minus tokens token
E 11
I 11
D 12
%type <same> for_statement maybe_at_minus ignore_ws tokens token
E 12
I 12
%type <same> for_statement maybe_at_minus tokens token
E 12
E 11
%type <same> maybe_white_space
E 9
%type <intval> white_space macro_char
E 8
E 2
%%
I 2

E 2
D 8
makefile : lines END_OF_FILE;
E 8
I 8
makefile : lines;
E 8

lines : line
    | lines line
    ;

D 2
line : NL
    | target NL
    | assignment NL
    | actions NL
E 2
I 2
D 8
line : maybe_white_space NL
E 8
I 8
line : NL
E 8
    | assignment
    | target_action
E 2
    ;

D 2
target : tokens ':' tokens
E 2
I 2
D 13
assignment :
D 8
    token maybe_white_space '=' maybe_white_space tokens maybe_white_space NL
E 8
I 8
D 11
    assign1 tokens NL
E 11
I 11
D 12
    assign1 ignore_ws NL
E 12
I 12
    assign1 tokens NL
E 13
I 13
assignment : assign1 tokens NL
E 13
E 12
E 11
E 8
E 2
    {
D 2
	$$ = add_depends($1, $3);
E 2
I 2
D 8
	assign($1, $5);
E 8
I 8
	assign($1, $2);
E 8
E 2
    }
I 2
D 8
    | token maybe_white_space '=' maybe_white_space NL
E 8
I 8
    | assign1 NL
E 8
    {
D 3
	assign($1, same_copy(&null));
E 3
I 3
	assign($1, same_copy(null));
E 3
    }
E 2
    ;

I 8
D 9
assign1: non_white_token maybe_white_space '=' maybe_white_space
E 9
I 9
D 11
assign1: tokens maybe_white_space '=' maybe_white_space
E 11
I 11
assign1: token maybe_white_space '=' maybe_white_space
E 11
E 9
    ;

E 8
D 2
assignment : token '=' tokens
E 2
I 2
target_action: target actions
E 2
    {
D 2
	$$ = assign($1, $3);
E 2
I 2
	add_targets_actions($1, $2);
E 2
    }
I 2
    | target
    {
D 3
	add_targets_actions($1, same_copy(&null));
E 3
I 3
D 12
	add_targets_actions($1, same_copy(null));
E 12
I 12
	add_targets_actions($1, 0);
E 12
E 3
    }
E 2
    ;

I 2
D 13
target :
D 8
    tokens maybe_white_space ':' maybe_white_space tokens maybe_white_space NL
E 8
I 8
D 9
    non_white_token maybe_tokens ':' maybe_tokens NL
E 9
I 9
    target1 tokens NL
E 13
I 13
target : target1 tokens NL
E 13
E 9
E 8
    {
D 9
	$$ = add_depends($1, $5);
E 9
I 9
	$$ = add_depends($1, $2);
E 9
    }
I 9
    | target1 NL
    {
	$$ = add_depends($1, same_copy(null));
    }
E 9
D 8
    | tokens maybe_white_space ':' maybe_white_space NL
    {
D 3
	$$ = add_depends($1, same_copy(&null));
E 3
I 3
	$$ = add_depends($1, same_copy(null));
E 3
    }
E 8
    ;

I 9
target1: tokens maybe_white_space ':' maybe_white_space
I 12
    {
	$$ = ws_merge($1);
    }
E 12
    ;

E 9
E 2
actions: action
    | actions action
    {
D 2
	$$ = token_cat($1, $2);
E 2
I 2
D 13
	$$ = same_cat($1, $2);
E 13
I 13
	$$ = same_cat(same_cat($1, same_copy(newline)), $2);
E 13
E 2
    }
    ;

D 2
action:	'\t' tokens
E 2
I 2
D 8
action:	white_space tokens NL
E 8
I 8
action:	white_space command_list NL
E 8
E 2
    {
	$$ = $2;
    }
I 7
D 8
    | white_space for_statement NL
E 8
I 8
    | white_space for_statement do command_list semi_colon done NL
E 8
    {
D 10
	$$ = $2;
E 10
I 10
	$$ = do_command($2, $4);
E 10
    }
E 7
    ;

I 7
D 8
for_statement: maybe_at_minus FOR white_space token
		white_space IN white_space tokens maybe_white_space ';'
		maybe_white_space DO white_space '(' maybe_white_space
		tokens maybe_white_space ')' maybe_white_space ';'
		maybe_white_space DONE
E 8
I 8
D 9
for_statement: maybe_at_minus FOR white_space non_white_token
		white_space IN tokens semi_colon
E 9
I 9
for_statement: maybe_at_minus FOR white_space token
D 11
		in tokens semi_colon
E 11
I 11
D 12
		in ignore_ws semi_colon
E 12
I 12
		in tokens semi_colon
E 12
E 11
E 9
E 8
    {
D 8
	$$ = for_statement($1, $4, expand_variables($8, 0), $16);
E 8
I 8
D 9
	$$ = for_statement($1, $4, expand_variables($7, 0));
E 9
I 9
D 14
	$$ = for_statement($1, $4, expand_variables($6, 0));
E 14
I 14
	$$ = for_statement($1, $4, ws_merge(expand_variables($6, 0)));
E 14
E 9
E 8
    }
    ;

I 9
in:	white_space IN white_space
E 9
I 8
do:	white_space DO white_space
    ;

done:	white_space DONE
    ;

D 9
semi_colon:	maybe_white_space ';'
E 9
I 9
semi_colon:	';'
E 9
    ;

command_list: list
    | '(' list maybe_white_space ')'
    {
D 11
	$$ = $2;
E 11
I 11
	$$ = same_cat($2, same_copy(cwd_line));
E 11
    }
    ;

D 13
list: command
D 11
    {
	$$ = $1;
    }
E 11
D 9
    | list semi_colon command
E 9
I 9
D 10
    | list semi_colon white_space command
E 10
I 10
    | list semi_colon maybe_white_space command
E 13
I 13
list: token
    | list list_element
E 13
E 10
E 9
    {
D 9
	$$ = same_cat($1, same_cat(same_char('\n'), $3));
E 9
I 9
D 11
	$$ = same_cat($1, same_cat(same_char('\n'), $4));
E 11
I 11
D 13
	$$ = same_cat($1, same_cat(same_copy(newline), $4));
E 13
I 13
	$$ = same_cat($1, $2);
E 13
E 11
E 9
    }
I 13
    | list white_space list_element
    {
	$$ = same_cat($1, same_cat(same_copy(blank), $3));
    }
E 13
    ;

D 9
command: non_white_token maybe_tokens
    {
	$$ = same_cat($1, $2);
    }
E 9
I 9
D 13
command: tokens
E 13
I 13
list_element: token
    | semi_colon
    {
	$$ = same_copy(newline);
    }
E 13
E 9
    ;

E 8
maybe_at_minus: /* empty */
    {
	$$ = same_copy(null);
    }
    | '@'
    {
	char buffer[2];

	buffer[0] = $1;
	buffer[1] = 0;
	$$ = same_item(string_lookup(buffer));
    }
    | '-'
    {
	char buffer[2];

	buffer[0] = $1;
	buffer[1] = 0;
	$$ = same_item(string_lookup(buffer));
    }
    ;
I 8

I 11
D 12
ignore_ws: token
    | ignore_ws maybe_white_space token
    {
	$$ = same_cat($1, $3);
    }
    ;

E 12
E 11
D 9
maybe_tokens:
    {
	$$ = same_copy(null);
    }
    | tokens
    ;

E 9
E 8
E 7
tokens : token
D 9
    | tokens token
E 9
I 9
    | tokens maybe_white_space token
E 9
    {
D 2
	$$ = token_cat($1, $2);
E 2
I 2
D 9
	$$ = same_cat($1, $2);
E 9
I 9
	$$ = same_cat($1, same_cat($2, $3));
E 9
E 2
    }
    ;
I 2

E 2
D 8
token: TOKEN
E 8
I 8
D 9
token: non_white_token
    | white_space
E 9
I 9
token: TOKEN
E 9
E 8
    {
I 8
D 9
	$$ = same_char($1);
    }
    ;

non_white_token: TOKEN
    {
E 9
E 8
D 2
	$$ = token_item($1);
E 2
I 2
	$$ = same_item($1);
E 2
    }
I 2
    | QUOTED_STRING
    {
	$$ = same_item($1);
    }
    | '$' macro_char
    {
	char buffer[3];

	buffer[0] = '$';
	buffer[1] = $2;
	buffer[2] = 0;

	$$ = same_item(string_lookup(buffer));
    }
D 8
    | special_chars
E 8
I 8
D 9
    | '$' '$' non_white_token
E 9
I 9
D 12
    | '$' '$' token
E 12
I 12
    | '$' '$' TOKEN
E 12
E 9
E 8
    {
D 8
	char buffer[2];

	buffer[0] = $1;
	buffer[1] = 0;

	$$ = same_item(string_lookup(buffer));
E 8
I 8
D 12
	$$ = shell_variable($3);
E 12
I 12
	$$ = shell_variable(same_item($3));
E 12
E 8
    }
D 8
    | '$' '{' token '}'
E 8
I 8
    | MACRO_CHAR
E 8
    {
I 8
	$$ = same_char($1);
    }
D 9
    | '$' '{' non_white_token '}'
E 9
I 9
D 12
    | '$' '{' token '}'
E 12
I 12
    | '$' '{' TOKEN '}'
E 12
E 9
    {
E 8
D 5
	$$ = same_copy(value_of($3));
E 5
I 5
D 6
	$$ = value_of($3);
E 6
I 6
D 12
	$$ = variable($3);
E 12
I 12
	$$ = variable(same_item($3));
E 12
E 6
E 5
    }
I 12
    | '$' '(' TOKEN ')'
    {
	$$ = variable(same_item($3));
    }
    | '$' TOKEN
    {
	$$ = variable(same_item($2));
    }
E 12
I 7
    | '-'
    {
	$$ = same_char('-');
    }
    | '@'
    {
	$$ = same_char('@');
    }
E 7
E 2
    ;
I 2

macro_char: MACRO_CHAR
D 8
    | '$'
E 8
I 8
    | '@'
E 8
    ;

D 7
special_chars : BREAK_CHAR
    | MACRO_CHAR
E 7
I 7
D 8
special_chars : MACRO_CHAR
E 7
    | white_space
    ;

E 8
maybe_white_space:
D 9
    | white_space;
E 9
I 9
    {
	$$ = same_copy(null);
    }
    | white_space
    {
	$$ = same_char($1);
    }
    ;
E 9

white_space : WHITE_SPACE
    | white_space WHITE_SPACE
    ;
D 8

E 8
E 2
%%
#include <stdio.h>
I 12
#include <ctype.h>
E 12

static int last_char, last_saved = 0;
static int column = 0, lineno = 1;


D 2
static string_t *strings = 0;
E 2
I 2
static string_t
    *strings = 0;
I 8

E 8
E 2
static same_t
I 8
    *shell_variables = 0,
    *shell_special = 0,
E 8
D 2
    *variables = 0,
    *targets = 0,
    *actions = 0;
E 2
I 2
D 3
    variables = { 0 },
    targets = { 0 },
    actions = { 0 };
E 3
I 3
D 4
    *variables,
    *targets,
    *actions;
E 4
I 4
    *variables = 0,
    *targets = 0,
    *actions = 0;
E 4
E 3
E 2

I 2
static same_t
D 3
    null = { 0 },
    blank = { 0 },
    newline = { 0 };
E 3
I 3
    *null,
    *blank,
I 11
    *cwd_line,
E 11
    *newline;
E 3

E 2
extern char *malloc();

I 3
static unsigned int
	clock = -1;

struct {
    same_t *first;
    int next;
} visit_stack[20];		/* 20 maximum */

#define	visit(what,via) \
	(visit_stack[++clock].next = 0, visit_stack[clock].first = via = what)
D 4
#define	visited(via)	\
	(visit_stack[clock].next && (via == visit_stack[clock].first))
E 4
I 4
D 5
#define	visited(via)	(((via) == 0) \
E 5
I 5
#define	visited(via)	(visitcheck(via) || ((via) == 0) \
E 5
	|| (visit_stack[clock].next && (via == visit_stack[clock].first)))
E 4
#define	visit_next(via)	(visit_stack[clock].next = 1, (via) = (via)->nexttoken)
#define	visit_end()	(clock--)

E 3
D 2
main()
E 2
I 2
yyerror(s)
char *s;
E 2
{
D 2
#define	YYDEBUG
    extern int yydebug;
E 2
I 2
    fprintf(stderr, "line %d, character %d: %s\n", lineno, column, s);
    do_dump();
}
E 2

D 2
    return yyparse();
E 2
I 2
int
I 5
visitcheck(same)
same_t *same;
{
    if (same->string == 0) {
	yyerror("BUG - freed 'same' in use...");
	exit(1);
    }
    return 0;
}

int
E 5
string_hashof(string, length)
char *string;
int length;
{
    register int i = 0;

    while (length--) {
	i = (i<<3) + *string ^ ((i>>28)&0x7);
    }
    return i;
E 2
}

D 2
yyerror(s)
char *s;
E 2
I 2
int
string_same(s1, s2)
string_t
    *s1, *s2;
E 2
{
D 2
    fprintf(stderr, "line %d, column %d: %s\n", lineno, column, s);
E 2
I 2
    if ((s1->hashval == s2->hashval) && (s1->length == s2->length)
		&& (memcmp(s1->string, s2->string, s1->length) == 0)) {
	return 1;
    } else {
	return 0;
    }
E 2
}

D 2
same_t *
add_depends(list1, list2)
same_t
    *list1,
    *list2;
E 2
I 2
string_t *
string_lookup(string)
char *string;
E 2
{
I 2
    string_t ours;
    string_t *ptr;

    ours.length = strlen(string);
    ours.hashval = string_hashof(string, ours.length);
    ours.string = string;

    for (ptr = strings; ptr; ptr = ptr->next) {
	if (string_same(&ours, ptr)) {
	    return ptr;
	}
    }
    if ((ptr = (string_t *)malloc(sizeof *ptr)) == 0) {
	fprintf(stderr, "No space to add string *%s*!\n", string);
	exit(1);
    }
    ptr->hashval = ours.hashval;
    ptr->length = ours.length;
    if ((ptr->string = malloc(ours.length+1)) == 0) {
	fprintf(stderr, "No space to add literal *%s*!\n", string);
	exit(1);
    }
    memcpy(ptr->string, string, ours.length+1);
    ptr->next = strings;
    strings = ptr;
    return ptr;
E 2
}

I 12
#define	same_singleton(s)	((s)->nexttoken == (s))

E 12
same_t *
D 2
assign(variable, value)
E 2
I 2
same_search(list, token)
E 2
same_t
D 2
    *variable,
    *value;
E 2
I 2
    *list,
    *token;
E 2
{
D 2
}
E 2
I 2
    same_t *ptr;
E 2

I 2
D 3
    for (ptr = list; ptr; ptr = ptr->nexttoken) {
E 3
I 3
    ptr = list;
    for (visit(list, ptr); !visited(ptr); visit_next(ptr)) {
E 3
	string_t *string;
E 2

I 2
	string = ptr->string;
	if (string_same(string, token->string)) {
I 3
	    visit_end();
E 3
	    return ptr;
	}
    }
I 3
    visit_end();
E 3
    return 0;
}

E 2
same_t *
D 2
token_cat(tokens, token)
E 2
I 2
same_cat(list, tokens)
E 2
same_t
D 2
    *tokens,
    *token;
E 2
I 2
    *list,
    *tokens;
E 2
{
D 2
    same_t *ptr;
E 2
I 2
    same_t *last;
E 2

I 8
    if (tokens == 0) {
	return list;
    }
E 8
D 2
    if (tokens->moretokens == 0) {
	tokens->moretokens = token;
E 2
I 2
D 4
    last = tokens->lasttoken;
    tokens->lasttoken = list->lasttoken;
    list->lasttoken = last;
E 2
D 3
    } else {
D 2
	for (ptr = tokens; ptr->moretokens; ptr = ptr->moretokens) {
	    ;
	}
	ptr->moretokens = token;
E 2
I 2
	list->lasttoken = tokens;
E 2
    }
D 2
    return tokens;
E 2
I 2
    if (list->nexttoken == 0) {
	list->nexttoken = tokens;
    } else {
	tokens->lasttoken->nexttoken = tokens;
    }
E 3
I 3
    tokens->lasttoken->nexttoken = tokens;
    last->nexttoken = list;

E 3
    return list;
E 4
I 4
    if (list) {
	last = tokens->lasttoken;
	tokens->lasttoken = list->lasttoken;
	list->lasttoken = last;
	tokens->lasttoken->nexttoken = tokens;
	last->nexttoken = list;
	return list;
    } else {
	return tokens;
    }
E 4
E 2
}

same_t *
D 2
token_item(string)
E 2
I 2
same_item(string)
E 2
string_t *string;
{
    same_t *ptr;

    if ((ptr = (same_t *)malloc(sizeof *ptr)) == 0) {
	fprintf(stderr, "No more space for tokens!\n");
	exit(1);
    }
D 2

E 2
I 2
    memset((char *)ptr, 0, sizeof *ptr);
I 3
    ptr->nexttoken = ptr->lasttoken = ptr;
E 3
E 2
    ptr->string = string;
D 2
    ptr->moretokens = 0;
E 2
    return ptr;
}

I 2
same_t *
same_copy(same)
same_t *same;
{
D 3
    same_t *head;
E 3
I 3
    same_t *head, *copy;
E 3

D 4
    head = same_item(same->string);
D 3
    for (same = same->nexttoken; same; same = same->nexttoken) {
E 3
I 3
    for (copy = same->nexttoken; copy != same; copy = copy->nexttoken) {
E 4
I 4
    head = 0;
    for (visit(same, copy); !visited(copy); visit_next(copy)) {
E 4
E 3
	same_t *ptr;

D 3
	ptr = same_item(same->string);
E 3
I 3
	ptr = same_item(copy->string);
E 3
D 4
	same_cat(head, ptr);
E 4
I 4
	head = same_cat(head, ptr);
E 4
    }
I 4
    visit_end();
E 4
    return head;
}

I 12

same_t *
same_merge(t1, t2)
same_t
    *t1,
    *t2;
{
    if (same_singleton(t1) && same_singleton(t2)) {
	int length = strlen(t1->string->string)+strlen(t2->string->string);
	char *buffer = malloc(length+1);
	same_t *value;

	if (buffer == 0) {
	    yyerror("No space to merge strings in same_merge!");
	    exit(1);
	}
	strcpy(buffer, t1->string->string);
	strcat(buffer, t2->string->string);
	value = same_item(string_lookup(buffer));
	free(buffer);
	return value;
    } else {
	yyerror("Internal error - same_merge with non-singletons");
	exit(1);
    }
}


E 12
void
D 3
same_free(token)
same_t *token;
E 3
I 3
same_free(list)
same_t *list;
E 3
{
D 3
    same_t *ptr;
E 3
I 3
    same_t *token, *ptr;
E 3

I 12
    if (list == 0) {
	return;
    }

E 12
D 3
    while (token) {
E 3
I 3
    token = list;
    do {
E 3
	ptr = token->nexttoken;
I 5
	token->string = 0;
E 5
	(void) free((char *)token);
	token = ptr;
D 3
    }
E 3
I 3
    } while (token != list);
E 3
}

D 7
void
E 7
I 7
same_t *
E 7
D 3
same_unlink(token, base)
E 3
I 3
same_unlink(token)
E 3
same_t
D 3
    *token,
    *base;
E 3
I 3
    *token;
E 3
{
I 7
    same_t *tmp;

E 7
I 4
    if (token == 0) {
D 7
	return;
E 7
I 7
	return 0;
E 7
    }
I 7
    if ((tmp = token->nexttoken) == token) {
	tmp = 0;
    }
E 7
E 4
D 3
    if (token->lasttoken) {
	token->lasttoken->nexttoken = token->nexttoken;
    }
    if (token->nexttoken) {
	token->nexttoken->lasttoken = token->lasttoken;
    }
    if (base->nexttoken == token) {
	base->nexttoken = token->nexttoken;
    }
    if (base->lasttoken == token) {
	base->lasttoken = token->lasttoken;
    }
E 3
I 3
    token->lasttoken->nexttoken = token->nexttoken;
    token->nexttoken->lasttoken = token->lasttoken;
I 4
    token->nexttoken = token->lasttoken = token;
I 7
    return tmp;
E 7
E 4
E 3
D 5
    (void) free((char *) token);
E 5
}

I 11
void
same_replace(old, new)
same_t
    *old,
    *new;
{
    new->lasttoken->nexttoken = old->nexttoken;
    old->nexttoken->lasttoken = new->lasttoken;
    new->lasttoken = old->lasttoken;
    /* rather than
     * old->lasttoken->nexttoken = new
     * we update in place (for the case where there isn't anything else)
     */
    *old = *new;
}


E 11
same_t *
I 7
same_char(ch)
char ch;
{
    char buffer[2];

    buffer[0] = ch;
    buffer[1] = 0;

    return same_item(string_lookup(buffer));
}

I 11

E 11
D 12
same_t *
E 7
add_target(target)
E 12
I 12
void
add_target(target, actions)
E 12
same_t
D 12
    *target;
E 12
I 12
    *target,
    *actions;
E 12
{
    same_t *ptr;

D 3
    if ((ptr = same_search(&targets, target)) == 0) {
	same_cat(&targets, target);
E 3
I 3
    if ((ptr = same_search(targets, target)) == 0) {
D 4
	same_cat(targets, target);
E 4
I 4
	targets = same_cat(targets, target);
D 12
	return target;
E 12
I 12
	ptr = target;
E 12
E 4
E 3
    } else {
D 4
	same_cat(ptr->action_list, target->action_list);
	same_cat(ptr->depend_list, target->depend_list);
E 4
I 4
D 12
	ptr->action_list = same_cat(ptr->action_list, target->action_list);
E 12
	ptr->depend_list = same_cat(ptr->depend_list, target->depend_list);
D 12
	return ptr;
E 12
E 4
    }
I 12
    if (actions) {
	if (ptr->action_list) {
	    same_free(ptr->action_list);
	}
	ptr->action_list = same_copy(actions);
    }
E 12
D 4
    return 0;
E 4
}

I 11

E 11
same_t *
add_targets_actions(target, actions)
same_t
    *target,
    *actions;
{
D 3
    same_t *next;
E 3
I 3
D 4
    same_t *traverse;
E 4
I 4
D 5
    same_t *ptr, *original = target;
E 5
I 5
    same_t *ptr;
E 5
E 4
E 3

D 3
    while (target) {
	next = target->lasttoken;
	target->lasttoken = target->lasttoken = 0;
	target->action_list = actions;
	add_target(target);
	target= next;
E 3
I 3
D 4
    for (visit(target, traverse); !visited(traverse); visit_next(traverse)) {
	if (target->action_list) {
	    same_cat(target->action_list, actions);
	} else {
	    target->action_list = actions;
	}
	add_target(traverse);
E 4
I 4
    if (target == 0) {
	return 0;
E 4
E 3
    }
I 3
D 4
    visit_end();
E 4
I 4
    do {
D 12
	target->action_list = same_cat(target->action_list,
						same_copy(actions));
E 12
D 5
	ptr = target->nexttoken;
E 5
I 5
D 7
	if ((ptr = target->nexttoken) == target) {
	    ptr = 0;
	}
E 5
	same_unlink(target);
E 7
I 7
	ptr = same_unlink(target);
E 7
D 12
	add_target(target);
E 12
I 12
	add_target(target, actions);
E 12
	target = ptr;
D 5
    } while (target != original);
E 5
I 5
    } while (target);
E 5

    same_free(actions);
E 4
E 3
    return 0;
}

same_t *
add_depends(target, depends)
same_t
    *target,
    *depends;
{
    same_t *original = target;

D 3
    same_cat(depends, blank);			/* Separator */
E 3
I 3
D 4
    same_cat(depends, same_copy(blank));			/* Separator */
E 4
I 4
    depends = same_cat(depends, same_copy(blank));	/* Separator */
E 4
E 3

D 3
    while (target) {
	target->depend_list = depends;
	target = target->nexttoken;
E 3
I 3
    for (visit(original, target); !visited(target); visit_next(target)) {
D 4
	if (target->depend_list) {
	    same_cat(target->depend_list, depends);
	} else {
	    target->depend_list = depends;
	}
E 4
I 4
	target->depend_list = same_cat(target->depend_list, same_copy(depends));
E 4
E 3
    }
I 3
    visit_end();
I 4
    same_free(depends);
E 4

E 3
    return original;
}


/*
 * We know that variable is a singleton
 */

void
assign(variable, value)
same_t
    *variable,
    *value;
{
    same_t *ptr;

D 3
    if ((ptr = same_search(&variables, variable)) != 0) {
E 3
I 3
    if ((ptr = same_search(variables, variable)) != 0) {
E 3
	same_free(ptr->value_list);
D 3
	same_unlink(ptr, &variables);
E 3
I 3
D 7
	same_unlink(ptr);
E 7
I 7
D 12
	(void) same_unlink(ptr);
E 12
I 12
	variables = same_unlink(ptr);
E 12
E 7
I 4
	same_free(ptr);
E 4
E 3
    }
    variable->value_list = value;
D 3
    same_cat(&variables, variable);
E 3
I 3
D 4
    same_cat(variables, variable);
E 4
I 4
    variables = same_cat(variables, variable);
E 4
E 3
}

same_t *
value_of(variable)
same_t *variable;
{
D 3
    same_t *ptr = same_search(&variables, variable);
E 3
I 3
    same_t *ptr = same_search(variables, variable);
E 3

    if (ptr == 0) {
D 3
	return &null;
E 3
I 3
D 4
	return null;
E 4
I 4
	return same_copy(null);
E 4
E 3
    } else {
D 4
	return ptr->value_list;
E 4
I 4
	return same_copy(ptr->value_list);
E 4
    }
I 6
}

I 7

E 7
same_t *
I 7
expand_variables(token, free)
same_t *token;
int	free;
{
    same_t *head = 0;

    if (!free) {
	token = same_copy(token);		/* Get our private copy */
    }

    while (token) {
	char *string = token->string->string;
	same_t *tmp = same_unlink(token);

D 14
	if ((string[0] == '$') && (string[1] == '{')) {/* '}' Expand time */
E 14
I 14
	if ((string[0] == '$') && (string[1] == '{')) {	/* Expand time */
E 14
	    int len = strlen(string);

	    string[len-1] = 0;
	    head = same_cat(head, expand_variables(
			value_of(same_item(string_lookup(string+2))), 1));
	    string[len-1] = '}';
D 12
	} else {
E 12
I 12
D 14
	} else if (!isspace(string[0])) {
E 14
I 14
	} else {
E 14
E 12
	    head = same_cat(head, token);
	}
	token = tmp;
    }
    return head;
}

I 12

E 12
same_t *
I 12
ws_merge(list)
same_t *list;
{
    same_t *newlist = 0, *item;
    int what = 0;

    while (list) {
	switch (what) {
	case 0:
	    if (isspace(list->string->string[0])) {
		;
	    } else {
		item = same_item(list->string);
		what = 1;
	    }
	    break;
	case 1:
	    if (isspace(list->string->string[0])) {
		newlist = same_cat(newlist, item);
		item = 0;
		what = 0;
	    } else {
		item = same_merge(item, same_item(list->string));
		what = 1;
	    }
	    break;
	}
	list = same_unlink(list);
    }
    return same_cat(newlist, item);
}


same_t *
E 12
E 7
variable(var_name)
same_t *var_name;
{
    int length = strlen(var_name->string->string);
    same_t *resolved;
    char *newname;

    if ((newname = malloc(length+1+3)) == 0) {
	fprintf("Out of space for a variable name.\n");
	exit(1);
    }
    newname[0] = '$';
    newname[1] = '{';
    strcpy(newname+2, var_name->string->string);
    strcat(newname, "}");
    resolved = same_item(string_lookup(newname));
    free(newname);

    return resolved;
E 6
}

I 8

E 8
I 7
same_t *
D 8
for_statement(special, variable, list, commands)
E 8
I 8
D 10
shell_variable(name)
same_t *name;
E 10
I 10
shell_variable(var_name)
same_t *var_name;
E 10
{
D 10
    same_t *shell;
E 10
I 10
    int length = strlen(var_name->string->string);
    same_t *resolved;
    char *newname;
E 10

D 10
    if ((shell = same_search(shell_variables, name)) == 0) {
	char buffer[100];
	sprintf(buffer, "Unknown shell variable %s.", name->string->string);
	yyerror(buffer);
E 10
I 10
    if ((newname = malloc(length+1+2)) == 0) {
	fprintf("Out of space for a variable name.\n");
E 10
	exit(1);
    }
D 10
    return same_copy(shell->shell_item);
E 10
I 10
    newname[0] = '$';
    newname[1] = '$';
    strcpy(newname+2, var_name->string->string);
    resolved = same_item(string_lookup(newname));
    free(newname);

    return resolved;
E 10
}

same_t *
for_statement(special, variable, list)
E 8
same_t
    *special,
    *variable,
D 8
    *list,
    *commands;
E 8
I 8
    *list;
E 8
{
D 8
    return same_cat(special, same_cat(variable, same_cat(list, commands)));
E 8
I 8
D 10
    shell_special = special;
E 10
I 10
    variable->shell_item = special;
E 10
    variable->value_list = list;
D 10
    shell_variables = variable;
    return same_copy(null);
E 10
I 10
    return variable;
}

same_t *
do_command(forlist, commands)
same_t
    *forlist,
    *commands;
{
D 11
    return same_cat(forlist, commands);
E 11
I 11
    same_t
	*special,
	*command_list = 0,
	*new_commands,
	*tmp,
	*shell_item,
	*value_list = forlist->value_list;
    char
	*tmpstr,
	*variable_name = forlist->string->string;

    special = forlist->shell_item;
    if (same_unlink(forlist->shell_item) != 0) {
	yyerror("Unexpected second item in special part of do_command");
	exit(1);
    }

    while ((shell_item = value_list) != 0) {
	value_list = same_unlink(shell_item);
	/* Visit each item in commands.  For each shell variable which
	 * matches ours, replace it with ours.
	 */
	new_commands = same_copy(commands);
	for (visit(new_commands, tmp); !visited(tmp); visit_next(tmp)) {
	    tmpstr = tmp->string->string;
	    if ((tmpstr[0] == '$') && (tmpstr[1] == '$')) {
		if (strcmp(tmpstr+2, variable_name) == 0) {
		    same_replace(tmp, same_copy(shell_item));
		}
	    }
	}
	visit_end();
	command_list = same_cat(command_list, new_commands);
    }
    return same_cat(command_list, same_copy(newline));
E 11
E 10
E 8
}
E 7

I 7

E 7
E 2
int
Getchar()
{
    if (last_saved) {
	last_saved = 0;
	return last_char;
    } else {
	int c;
	c = getchar();
	switch (c) {
	case '\n':
	    lineno++;
	    column = 0;
	    break;
	default:
	    column++;
	}
	return c;
    }
}

D 2
int
hashof(string, length)
char *string;
int length;
{
    register int i = 0;
E 2

I 7
int
token_type(string)
char *string;
{
    switch (string[0]) {
    case 'f':
	if (strcmp(string, "for") == 0) {
	    return FOR;
	}
	break;
    case 'd':
	if (string[1] == 'o') {
	    if (strcmp(string, "do") == 0) {
		return DO;
	    } else if (strcmp(string, "done") == 0) {
		return DONE;
	    }
	}
	break;
    case 'i':
	if (strcmp(string, "in") == 0) {
	    return IN;
	}
	break;
    default:
	break;
    }
    return TOKEN;
}


E 7
D 2
    while (length--) {
	i = (i<<3) + *string ^ ((i>>28)&0x7);
    }
    return i;
}

string_t *
lookup(string)
char *string;
{
    int hashval;
    int length = strlen(string);
    string_t *ptr;

    hashval = hashof(string, length);

    for (ptr = strings; ptr; ptr = ptr->next) {
	if ((ptr->hashval == hashval) && (ptr->length == length)) {
	    if (memcmp(string, ptr->string, length) == 0) {
		return ptr;
	    }
	}
    }
    if ((ptr = (string_t *)malloc(sizeof *ptr)) == 0) {
	fprintf(stderr, "No space to add string *%s*!\n", string);
	exit(1);
    }
    ptr->hashval = hashval;
    ptr->length = length;
    if ((ptr->string = malloc(length+1)) == 0) {
	fprintf(stderr, "No space to add literal *%s*!\n", string);
	exit(1);
    }
    memcpy(ptr->string, string, length+1);
    ptr->next = strings;
    strings = ptr;
    return ptr;
}


E 2
yylex()
{
#define	ret_token(c)	if (bufptr != buffer) { \
			    save(c); \
			    *bufptr = 0; \
			    bufptr = buffer; \
D 2
			    yylval.string = lookup(buffer); \
E 2
I 2
			    yylval.string = string_lookup(buffer); \
E 2
D 7
			    return TOKEN; \
E 7
I 7
			    return token_type(buffer); \
E 7
			}
#define	save(c)	{ last_char = c; last_saved = 1; }
I 2
#if	defined(YYDEBUG)
E 2
#define	Return(c)	if (yydebug) { \
			    printf("[%d]", c); \
			    fflush(stdout); \
			} \
I 2
			yyval.intval = c; \
E 2
			return c;
I 2
#else	/* defined(YYDEBUG) */
#define	Return(y,c)	{ yylval.intval = c; return y; }
#endif	/* defined(YYDEBUG) */
E 2

D 2
    static char buffer[100], *bufptr = buffer;
E 2
I 2

    static char buffer[500], *bufptr = buffer;
E 2
    static int eof_found = 0;
    int c;

    if (eof_found != 0) {
	eof_found++;
	if (eof_found > 2) {
	    fprintf(stderr, "End of file ignored.\n");
	    exit(1);
	}
D 2
	Return(END_OF_FILE);
E 2
I 2
D 8
	Return(END_OF_FILE,0);
E 8
I 8
	Return(EOF,0);
E 8
E 2
    }
    while ((c = Getchar()) != EOF) {
	switch (c) {
	case '#':
	    ret_token(c);
	    while (((c = Getchar()) != EOF) && (c != '\n')) {
		;
	    }
	    save(c);
	    break;
D 2
	case ' ':
	    ret_token(' ');
	    break;
E 2
I 2
D 7
	case '@':
E 7
	case '<':
	case '?':
	    ret_token(c);
	    Return(MACRO_CHAR, c);
D 7
	case '-':
	case '(':
	case ')':
	case ';':
	    ret_token(c);
	    Return(BREAK_CHAR, c);
E 7
E 2
	case '\t':
I 2
	case ' ':
E 2
	    ret_token(c);
D 2
	    if (column == 1) {
		Return(c);
	    }
	    break;
E 2
I 2
	    Return(WHITE_SPACE, c);
I 7
	case '-':
	case '@':
E 7
E 2
	case ':':
I 7
	case ';':
E 7
	case '=':
I 2
	case '$':
	case '{':
	case '}':
I 7
	case '(':
	case ')':
E 7
E 2
	    ret_token(c);
D 2
	    Return(c);
E 2
I 2
	    Return(c,c);
	case '\'':
	case '"':
D 15
	    {
E 15
I 15
	    if (bufptr != buffer) {
		if (bufptr[-1] == '\\') {
		    bufptr[-1] = c;
		}
		break;
	    } else {
E 15
		int newc;

		ret_token(c);
		*bufptr++ = c;
		while (((newc = Getchar()) != EOF) && (newc != c)) {
		    *bufptr++ = newc;
		}
		*bufptr++ = c;
		*bufptr = 0;
		bufptr = buffer;
		yylval.string = string_lookup(buffer);
		return QUOTED_STRING;
	    }
E 2
	case '\n':
	    if (bufptr != buffer) {
		if (bufptr[-1] == '\\') {
		    bufptr--;
D 2
		    break;
E 2
I 2
		    if ((c = Getchar()) != '\t') {
			yyerror("continuation line doesn't begin with a tab");
			save(c);
		    }
		    ret_token(c);
		    Return(WHITE_SPACE, c);
E 2
		}
	    }
	    ret_token(c);
D 2
	    Return(NL);
E 2
I 2
	    Return(NL, 0);
E 2
	default:
	    *bufptr++ = c;
	    break;
	}
    }

    eof_found = 1;

    ret_token(' ');
D 2
    Return(END_OF_FILE);
E 2
I 2
D 8
    Return(END_OF_FILE, 0);
E 8
I 8
    Return(EOF, 0);
E 8
E 2
}
I 2

I 17
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif	/* not lint */

E 17
main()
{
#define	YYDEBUG
    extern int yydebug;

I 3
    null = same_item(string_lookup(""));
    newline = same_item(string_lookup("\n"));
    blank = same_item(string_lookup(" "));
I 11
    cwd_line = same_cat(same_copy(newline),
			same_cat(same_item(string_lookup("cd ${CWD}")),
				 same_copy(newline)));
E 11
E 3

D 3
    null.string = string_lookup("");
    newline.string = string_lookup("\n");
    blank.string = string_lookup(" ");
E 3
I 3
D 4
    variables = same_item(string_lookup("variables"));
    targets = same_item(string_lookup("targets"));
    actions = same_item(string_lookup("actions"));
E 3

E 4
D 9
    return yyparse();
E 9
I 9
    yyparse();

    do_dump();
I 11

    return 0;
E 11
E 9
}

#if	defined(YYDEBUG)
I 5
dump_same(same)
same_t *same;
{
    same_t *same2;

    for (visit(same, same2); !visited(same2); visit_next(same2)) {
	printf(same2->string->string);
    }
    visit_end();
}
I 9
#endif	/* YYDEBUG */
E 9

E 5
do_dump()
{
    string_t *string;
    same_t *same, *same2;

    if (yydebug > 1) {
	printf("strings...\n");
	for (string = strings; string; string = string->next) {
	    printf("\t%s\n", string->string);
	}
    }

D 9
    printf("variables...\n");
E 9
I 9
    printf("# variables...\n");
E 9
D 3
    for (same = variables.nexttoken; same; same = same->nexttoken) {
E 3
I 3
D 4
    for (same = variables->nexttoken; same != variables;
						same = same->nexttoken) {
E 4
I 4
    for (visit(variables, same); !visited(same); visit_next(same)) {
E 4
E 3
D 9
	printf("\t%s =\t", same->string->string);
E 9
I 9
	printf("%s =\t", same->string->string);
E 9
D 3
	for (same2 = same->value_list; same2; same2 = same2->nexttoken) {
E 3
I 3
	for (visit(same->value_list, same2); !visited(same2);
						visit_next(same2)) {
E 3
D 11
	    printf(same2->string->string);
E 11
I 11
D 12
	    printf("%s ", same2->string->string);
E 12
I 12
	    printf(same2->string->string);
E 12
E 11
	}
I 3
	visit_end();
E 3
	printf("\n");
    }
I 4
    visit_end();
E 4

D 9
    printf("targets...\n");
E 9
I 9
D 13
    printf("#targets...\n");
E 13
I 13
    printf("\n\n#targets...\n");
E 13
E 9
D 3
    for (same = targets.nexttoken; same; same = same->nexttoken) {
E 3
I 3
D 4
    for (same = targets->nexttoken; same != targets; same = same->nexttoken) {
E 4
I 4
    for (visit(targets, same); !visited(same); visit_next(same)) {
E 4
E 3
D 9
	printf("\t%s :\t", same->string->string);
E 9
I 9
D 12
	printf("%s :\t", same->string->string);
E 12
I 12
D 13
	printf("%s:\t", same->string->string);
E 13
I 13
	printf("\n%s:\t", same->string->string);
E 13
E 12
E 9
D 3
	for (same2 = same->depend_list; same2; same2 = same2->nexttoken) {
E 3
I 3
	for (visit(same->depend_list, same2); !visited(same2);
						visit_next(same2)) {
E 3
	    printf(same2->string->string);
	}
I 3
	visit_end();
E 3
D 4
	if (same->action_list) {
	    printf("\n\t\t");
D 3
	    for (same2 = same->action_list; same2; same2 = same2->nexttoken) {
E 3
I 3
	    for (visit(same->action_list, same2); !visited(same2);
						visit_next(same2)) {
E 3
		printf(same2->string->string);
		if (same2->string->string[0] == '\n') {
		    printf("\t\t");
		}
E 4
I 4
D 9
	printf("\n\t\t");
E 9
I 9
	printf("\n\t");
E 9
	for (visit(same->action_list, same2); !visited(same2);
					    visit_next(same2)) {
	    printf(same2->string->string);
	    if (same2->string->string[0] == '\n') {
D 9
		printf("\t\t");
E 9
I 9
		printf("\t");
E 9
E 4
	    }
I 3
D 4
	    visit_end();
E 3
	    printf("\n");
E 4
	}
I 4
	visit_end();
	printf("\n");
E 4
    }
I 4
    visit_end();
E 4
}
D 9
#endif	/* YYDEBUG */
E 9
E 2
E 1
