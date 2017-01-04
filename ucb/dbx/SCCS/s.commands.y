h65407
s 00003/00003/01088
d D 5.4 88/01/12 00:17:54 donn 19 18
c Fixes from Mike Hibler -- add $listwindow; fix build(O_LIST ...) parameter
c count.
e
s 00003/00007/01088
d D 5.3 85/05/31 11:32:49 dist 18 17
c Add copyright
e
s 00000/00000/01095
d D 5.2 85/05/31 11:31:32 dist 17 16
c Add copyright
e
s 00008/00000/01087
d D 5.1 85/05/31 11:30:43 dist 16 15
c Add copyright
e
s 00252/00242/00835
d D 1.14 85/03/01 20:19:13 linton 15 14
c update to version 3.0
e
s 00023/00022/01054
d D 1.13 84/08/12 16:24:09 sam 14 13
c cleanup a bunch of aliasing problems; put back linton's integer lists
e
s 00141/00049/00935
d D 1.12 84/08/12 13:21:23 sam 13 12
c add real aliases; rewrite lexical scanner
e
s 00001/00003/00983
d D 1.11 84/06/23 11:39:43 sam 12 10
i 11
c merge linton branch delta trail
e
s 00111/00035/00848
d D 1.9.1.1 84/06/23 10:44:55 sam 11 9
c branch delta of linton changes from net.sources
e
s 00027/00000/00883
d D 1.10 84/06/23 10:39:34 sam 10 9
c add re pattern search of source code
e
s 00019/00009/00864
d D 1.9 83/08/17 05:25:43 linton 9 8
c changed "use" to be all or nothing, the latter causing the current 
c sourcepath to be printed
e
s 00001/00001/00872
d D 1.8 83/07/07 23:08:50 linton 8 7
c added WHEREIS to list of keywords, fixing a problem which 
c made it so that one couldn't alias "whereis"
e
s 00012/00004/00861
d D 1.7 83/05/18 18:46:46 csvaf 7 6
c DEBUG command and actions
e
s 00003/00007/00862
d D 1.6 83/05/18 15:50:45 linton 6 5
c fixed problems with parsing first command-line argument to "run"
e
s 00013/00008/00856
d D 1.5 83/05/17 22:40:24 linton 5 4
c fixed syntax of "call" command for functions with no parameters, 
c changed run with no arguments to not reset the argument list thereby passing 
c the previous argument list
e
s 00006/00001/00858
d D 1.4 83/04/08 01:25:23 linton 4 3
c the "cont" command now has an optional argument to specify a 
c signal to start up the process with
e
s 00011/00000/00848
d D 1.3 83/02/20 17:54:16 linton 3 2
c changed type-renaming syntax from "type(expr)" to "expr \ type", 
c also added "<address>=<format>" command for printing a value in a particular format
e
s 00001/00001/00847
d D 1.2 82/12/15 04:23:41 linton 2 1
c fixed @(#) stuff
e
s 00848/00000/00000
d D 1.1 82/12/15 04:09:15 linton 1 0
c date and time created 82/12/15 04:09:15 by linton
e
u
U
f b 
t
T
I 18
%{

E 18
I 16
/*
D 18
 * Copyright (c) 1980 Regents of the University of California.
E 18
I 18
 * Copyright (c) 1983 Regents of the University of California.
E 18
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
D 18

E 16
I 1
%{
I 15

E 15
D 13

E 13
/* Copyright (c) 1982 Regents of the University of California */

D 2
static char sccsid[] = "@(#)%Z%%M% %I% %G%";
E 2
I 2
D 11
static char sccsid[] = "%Z%%M% %I% %G%";
E 11
I 11
D 12
static char sccsid[] = "@(#)commands.y 1.9 8/17/83";
E 11
E 2

I 11
static char rcsid[] = "$Header: commands.y,v 1.3 84/03/27 10:19:59 linton Exp $";
E 12
I 12
static	char sccsid[] = "%W% (Berkeley) %G%";
E 18
E 12

I 15
D 19
static char rcsid[] = "$Header: commands.y,v 1.5 84/12/26 10:38:41 linton Exp $";
E 19
I 19
static char rcsid[] = "$Header: commands.y,v 1.2 87/08/19 15:18:53 mike Exp $";
E 19

E 15
E 11
/*
 * Yacc grammar for debugger commands.
 */

#include "defs.h"
#include "symbols.h"
#include "operators.h"
#include "tree.h"
#include "process.h"
#include "source.h"
#include "scanner.h"
I 15
#include "keywords.h"
E 15
#include "names.h"
I 9
#include "lists.h"
I 13
D 15
#include <signal.h>
E 15
E 13
E 9

private String curformat = "X";

%}

%term
D 7
    ALIAS AND ASSIGN AT CALL CATCH CONT DELETE DIV DUMP
E 7
I 7
D 11
    ALIAS AND ASSIGN AT CALL CATCH CONT DEBUG DELETE DIV DUMP
E 11
I 11
    ALIAS AND ASSIGN AT CALL CATCH CONT DEBUG DELETE DIV DOWN DUMP
E 11
E 7
    EDIT FILE FUNC GRIPE HELP IF IGNORE IN LIST MOD NEXT NEXTI NIL NOT OR
D 11
    PRINT PSYM QUIT RUN SH SKIP SOURCE STATUS STEP STEPI
    STOP STOPI TRACE TRACEI
E 11
I 11
D 15
    PRINT PSYM QUIT RERUN RETURN RUN SH SKIP SOURCE STATUS STEP STEPI
    STOP STOPI TRACE TRACEI UP
E 11
    USE WHATIS WHEN WHERE WHEREIS WHICH
E 15
I 15
    PRINT PSYM QUIT RERUN RETURN RUN SET SH SKIP SOURCE STATUS STEP STEPI
    STOP STOPI TRACE TRACEI UNALIAS UNSET UP USE
    WHATIS WHEN WHERE WHEREIS WHICH
E 15

D 15
%term INT REAL NAME STRING
%term LFORMER RFORMER ABSTRACTION ARROW
E 15
I 15
%term INT CHAR REAL NAME STRING
%term ARROW
E 15

%right INT
%binary REDIRECT
%binary '<' '=' '>' '!' IN
%left '+' '-' OR
%left UNARYSIGN
%left '*' '/' DIV MOD AND
D 15
%left NOT '(' '[' '.' '^' ARROW
E 15
I 3
%left '\\'
I 15
%left NOT '(' '[' '.' '^' ARROW
E 15
E 3

%union {
    Name y_name;
    Symbol y_sym;
    Node y_node;
    Integer y_int;
    Operator y_op;
    long y_long;
I 15
    char y_char;
E 15
    double y_real;
    String y_string;
    Boolean y_bool;
    Cmdlist y_cmdlist;
I 9
    List y_list;
E 9
};

%type <y_op>	    trace stop
D 15
%type <y_long>	    INT count
E 15
I 15
%type <y_long>	    INT count signal
%type <y_char>	    CHAR
E 15
%type <y_real>	    REAL
%type <y_string>    STRING redirectout filename opt_filename mode
D 7
%type <y_name>	    ALIAS AND ASSIGN AT CALL CATCH CONT DELETE DIV DUMP
E 7
I 7
D 11
%type <y_name>	    ALIAS AND ASSIGN AT CALL CATCH CONT DEBUG DELETE DIV DUMP
E 11
I 11
%type <y_name>	    ALIAS AND ASSIGN AT CALL CATCH CONT
%type <y_name>	    DEBUG DELETE DIV DOWN DUMP
E 11
E 7
%type <y_name>	    EDIT FILE FUNC GRIPE HELP IF IGNORE IN LIST MOD
%type <y_name>	    NEXT NEXTI NIL NOT OR
D 11
%type <y_name>	    PRINT PSYM QUIT RUN SH SKIP SOURCE STATUS STEP STEPI
%type <y_name>	    STOP STOPI TRACE TRACEI
%type <y_name>	    USE WHATIS WHEN WHERE WHEREIS WHICH
E 11
I 11
D 15
%type <y_name>	    PRINT PSYM QUIT RERUN RETURN RUN SH SKIP SOURCE STATUS
E 15
I 15
%type <y_name>	    PRINT PSYM QUIT RERUN RETURN RUN SET SH SKIP SOURCE STATUS
E 15
%type <y_name>	    STEP STEPI STOP STOPI TRACE TRACEI
D 15
%type <y_name>	    UP USE WHATIS WHEN WHERE WHEREIS WHICH
E 15
I 15
%type <y_name>	    UNALIAS UNSET UP USE WHATIS WHEN WHERE WHEREIS WHICH
E 15
E 11
%type <y_name>	    name NAME keyword
D 11
%type <y_node>      symbol
E 11
I 11
%type <y_node>      opt_qual_symbol symbol
E 11
%type <y_node>	    command rcommand cmd step what where examine
D 5
%type <y_node>	    event opt_arglist opt_cond
E 5
I 5
%type <y_node>	    event opt_exp_list opt_cond
E 5
%type <y_node>	    exp_list exp term boolean_exp constant address
D 11
%type <y_node>	    alias_command list_command line_number
E 11
I 11
D 13
%type <y_node>	    integer_list alias_command list_command line_number
E 11
I 10
%type <y_node>	    search_command pattern
E 13
I 13
D 14
%type <y_node>	    int_list alias_command list_command line_number
E 14
I 14
%type <y_node>	    integer_list alias_command list_command line_number
E 14
D 15
%type <y_node>	    something search_command pattern
%type <y_node>	    signal_list signal
E 15
E 13
E 10
%type <y_cmdlist>   actions
I 9
D 15
%type <y_list>      sourcepath
E 15
I 15
%type <y_list>      sourcepath name_list
E 15
E 9

%%

input:
    input command_nl
I 13
D 15
{
	endshellmode();
	startaliasing();
}
E 15
E 13
|
    /* empty */
;
I 13
D 15

E 15
E 13
command_nl:
    command_line '\n'
I 13
D 15
{
	if (istty()) {
		printf("(%s) ", cmdname);
		fflush(stdout);
	}
}
E 15
E 13
|
    command_line ';'
D 15
|
    '\n'
E 15
I 13
{
D 15
	if (istty()) {
		printf("(%s) ", cmdname);
		fflush(stdout);
	}
E 15
I 15
	chkalias = true;
E 15
}
I 15
|
    '\n'
E 15
E 13
;

command_line:
    command
{
	if ($1 != nil) {
I 7
D 15
            if(debug_flag[2]) {dumptree(stderr,$1); fflush (stderr);}
E 7
	    eval($1);
E 15
I 15
	    topeval($1);
E 15
	}
I 13
D 15
	startaliasing();
E 15
E 13
}
|
    rcommand redirectout
{
	if ($1 != nil) {
	    if ($2 != nil) {
		setout($2);
I 7
D 15
                if(debug_flag[2]) {dumptree(stderr,$1); fflush (stderr);}
E 7
		eval($1);
E 15
I 15
		topeval($1);
E 15
		unsetout();
	    } else {
I 7
D 15
                if(debug_flag[2]) {dumptree(stderr,$1); fflush (stderr);}
E 7
		eval($1);
E 15
I 15
		topeval($1);
E 15
	    }
	}
I 13
D 15
	startaliasing();
E 15
E 13
}
;
redirectout:
    '>' shellmode NAME
{
	$$ = ident($3);
}
|
    /* empty */
{
	$$ = nil;
}
;

/*
 * Non-redirectable commands.
 */
command:
    alias_command
{
	$$ = $1;
}
|
D 13
    ASSIGN term '=' exp
E 13
I 13
D 15
    ASSIGN stopaliasing term '=' exp
E 15
I 15
    ASSIGN exp '=' exp
E 15
E 13
{
D 13
	$$ = build(O_ASSIGN, $2, $4);
E 13
I 13
D 15
	$$ = build(O_ASSIGN, $3, $5);
E 15
I 15
	$$ = build(O_ASSIGN, unrval($2), $4);
E 15
E 13
}
|
D 13
    CATCH INT
E 13
I 13
D 15
    CATCH
E 15
I 15
    CATCH signal
E 15
E 13
{
D 13
	$$ = build(O_CATCH, $2);
E 13
I 13
D 15
	$$ = build(O_CATCH, nil);
E 15
I 15
	$$ = build(O_CATCH, $2);
E 15
E 13
}
|
I 13
D 15
    CATCH stopaliasing signal_list
E 15
I 15
    CATCH
E 15
{
D 15
	$$ = build(O_CATCH, $3);
E 15
I 15
	$$ = build(O_CATCH, 0);
E 15
}
|
E 13
    CONT
{
D 4
	$$ = build(O_CONT);
E 4
I 4
D 9
	$$ = build(O_CONT, (long) 0);
E 9
I 9
	$$ = build(O_CONT, (long) DEFSIG);
E 9
}
|
D 15
    CONT INT
E 15
I 15
    CONT signal
E 15
{
	$$ = build(O_CONT, $2);
E 4
}
|
D 11
    DELETE INT
E 11
I 11
D 13
    DELETE integer_list
E 13
I 13
D 14
    DELETE int_list
E 14
I 14
    DELETE integer_list
E 14
E 13
E 11
{
	$$ = build(O_DELETE, $2);
}
|
I 11
    DOWN
{
	$$ = build(O_DOWN, build(O_LCON, (long) 1));
}
|
    DOWN INT
{
	$$ = build(O_DOWN, build(O_LCON, (long) $2));
}
|
E 11
    EDIT shellmode opt_filename
{
	$$ = build(O_EDIT, $3);
}
|
    FILE shellmode opt_filename
{
	$$ = build(O_CHFILE, $3);
}
|
    FUNC
{
	$$ = build(O_FUNC, nil);
}
|
D 11
    FUNC symbol
E 11
I 11
D 13
    FUNC opt_qual_symbol
E 13
I 13
D 15
    FUNC stopaliasing symbol
E 15
I 15
    FUNC opt_qual_symbol
E 15
E 13
E 11
{
D 13
	$$ = build(O_FUNC, $2);
E 13
I 13
D 15
	$$ = build(O_FUNC, $3);
E 15
I 15
	$$ = build(O_FUNC, $2);
E 15
E 13
}
|
    GRIPE
{
	$$ = build(O_GRIPE);
}
|
    HELP
{
	$$ = build(O_HELP);
}
|
D 13
    IGNORE INT
E 13
I 13
D 15
    IGNORE
E 15
I 15
    IGNORE signal
E 15
E 13
{
D 13
	$$ = build(O_IGNORE, $2);
E 13
I 13
D 15
	$$ = build(O_IGNORE, nil);
E 15
I 15
	$$ = build(O_IGNORE, $2);
E 15
E 13
}
|
I 13
D 15
    IGNORE stopaliasing signal_list
E 15
I 15
    IGNORE
E 15
{
D 15
	$$ = build(O_IGNORE, $3);
E 15
I 15
	$$ = build(O_IGNORE, 0);
E 15
}
|
E 13
    list_command
{
	$$ = $1;
}
|
D 13
    PSYM term
E 13
I 13
D 15
    PSYM stopaliasing term
E 15
I 15
    PSYM exp
E 15
E 13
{
D 13
	$$ = build(O_PSYM, $2);
E 13
I 13
D 15
	$$ = build(O_PSYM, $3);
E 15
I 15
	$$ = build(O_PSYM, unrval($2));
E 15
E 13
}
|
    QUIT
{
	if (not popinput()) {
	    quit(0);
	} else {
	    $$ = nil;
	}
}
|
I 11
    RETURN
{
	$$ = build(O_RETURN, nil);
}
|
D 13
    RETURN opt_qual_symbol
E 13
I 13
D 15
    RETURN stopaliasing opt_qual_symbol
E 15
I 15
    RETURN opt_qual_symbol
E 15
E 13
{
D 13
	$$ = build(O_RETURN, $2);
E 13
I 13
D 15
	$$ = build(O_RETURN, $3);
E 15
I 15
	$$ = build(O_RETURN, $2);
E 15
E 13
}
|
E 11
    runcommand
{
	run();
	/* NOTREACHED */
}
|
I 15
    SET name '=' exp
{
	$$ = build(O_SET, build(O_NAME, $2), $4);
}
|
    SET name
{
	$$ = build(O_SET, build(O_NAME, $2), nil);
}
|
    SET
{
	$$ = build(O_SET, nil, nil);
}
|
E 15
    SH
{
	shellline();
	$$ = nil;
}
|
    SOURCE shellmode filename
{
	$$ = build(O_SOURCE, $3);
}
|
    step
{
	$$ = $1;
}
|
    stop where opt_cond
{
	$$ = build($1, nil, $2, $3);
}
|
    stop what opt_cond
{
	$$ = build($1, $2, nil, $3);
}
|
    stop IF boolean_exp
{
	$$ = build($1, nil, nil, $3);
}
|
    trace what where opt_cond
{
	$$ = build($1, $2, $3, $4);
}
|
    trace where opt_cond
{
	$$ = build($1, nil, $2, $3);
}
|
    trace what opt_cond
{
	$$ = build($1, $2, nil, $3);
}
|
    trace opt_cond
{
	$$ = build($1, nil, nil, $2);
}
|
I 15
    UNALIAS name
{
	$$ = build(O_UNALIAS, build(O_NAME, $2));
}
|
    UNSET name
{
	$$ = build(O_UNSET, build(O_NAME, $2));
}
|
E 15
D 11
    WHATIS term
E 11
I 11
    UP
E 11
{
D 11
	$$ = build(O_WHATIS, $2);
E 11
I 11
	$$ = build(O_UP, build(O_LCON, (long) 1));
E 11
}
|
D 11
    WHEN event '{' actions '}'
E 11
I 11
    UP INT
E 11
{
D 11
	$$ = build(O_ADDEVENT, $2, $4);
E 11
I 11
	$$ = build(O_UP, build(O_LCON, (long) $2));
E 11
}
|
D 11
    WHEREIS symbol
{
	$$ = build(O_WHEREIS, $2);
}
|
    WHICH symbol
{
	$$ = build(O_WHICH, $2);
}
|
E 11
    USE shellmode sourcepath
{
I 9
	String dir;

E 9
	$$ = nil;
D 9
	if (list_size(sourcepath) == 0) {
	    list_append(list_item("."), nil, sourcepath);
E 9
I 9
	if (list_size($3) == 0) {
	    foreach (String, dir, sourcepath)
		printf("%s ", dir);
	    endfor
	    printf("\n");
	} else {
	    foreach (String, dir, sourcepath)
		list_delete(list_curitem(sourcepath), sourcepath);
	    endfor
	    sourcepath = $3;
E 9
	}
}
I 11
|
D 14
    WHATIS term
E 14
I 14
D 15
    WHATIS stopaliasing term
E 15
I 15
    WHATIS opt_qual_symbol
E 15
E 14
{
D 14
	$$ = build(O_WHATIS, $2);
E 14
I 14
D 15
	$$ = build(O_WHATIS, $3);
E 15
I 15
	$$ = build(O_WHATIS, $2);
E 15
E 14
}
|
D 14
    WHEN event '{' actions '}'
E 14
I 14
D 15
    WHEN stopaliasing event '{' actions '}'
E 15
I 15
    WHEN event '{' actions '}'
E 15
E 14
{
D 14
	$$ = build(O_ADDEVENT, $2, $4);
E 14
I 14
D 15
	$$ = build(O_ADDEVENT, $3, $5);
E 15
I 15
	$$ = build(O_ADDEVENT, $2, $4);
E 15
E 14
}
|
D 14
    WHEREIS symbol
E 14
I 14
D 15
    WHEREIS stopaliasing symbol
E 15
I 15
    WHEREIS name
E 15
E 14
{
D 14
	$$ = build(O_WHEREIS, $2);
E 14
I 14
D 15
	$$ = build(O_WHEREIS, $3);
E 15
I 15
	$$ = build(O_WHEREIS, build(O_SYM, lookup($2)));
E 15
E 14
}
|
D 14
    WHICH symbol
E 14
I 14
D 15
    WHICH stopaliasing symbol
E 15
I 15
    WHICH symbol
E 15
E 14
{
D 14
	$$ = build(O_WHICH, $2);
E 14
I 14
D 15
	$$ = build(O_WHICH, $3);
E 15
I 15
	$$ = build(O_WHICH, $2);
E 15
E 14
}
E 11
I 10
|
D 15
    search_command
E 15
I 15
    '/'
E 15
{
D 15
	$$ = $1;
E 15
I 15
	$$ = build(O_SEARCH,
	    build(O_LCON, (long) '/'),
	    build(O_SCON, strdup(scanner_linebuf))
	);
	gobble();
	insertinput("\n");
E 15
}
E 10
D 15
;
I 10


search_command:
    '/' pattern
{
	$$ = build(O_SEARCH, build(O_LCON, 1), $2);
}
E 15
|
D 15
    '?' pattern
E 15
I 15
    '?'
E 15
{
D 15
	$$ = build(O_SEARCH, build(O_LCON, 0), $2);
E 15
I 15
	$$ = build(O_SEARCH,
	    build(O_LCON, (long) '?'),
	    build(O_SCON, strdup(scanner_linebuf))
	);
	gobble();
	insertinput("\n");
E 15
}
;
D 15

pattern:
    STRING
{
	$$ = build(O_SCON, $1);
}
;

I 13
D 14
int_list:
E 14
I 14
integer_list:
E 14
    INT
{
D 14
	$$ = build(O_COMMA, build(O_LCON, $1), nil);
E 14
I 14
	$$ = build(O_LCON, $1);
E 14
}
|
D 14
    INT int_list
E 14
I 14
    INT integer_list
E 14
{
	$$ = build(O_COMMA, build(O_LCON, $1), $2);
}
;

signal_list:
     signal
{
	$$ = build(O_COMMA, $1, nil);
}
|
    signal signal_list
{
	$$ = build(O_COMMA, $1, $2);
}
;

E 15
signal:
    INT
{
D 15
	if ($1 < 1 || $1 > NSIG)
		error("Invalid signal %d.", $1);
	$$ = build(O_LCON, $1);
E 15
I 15
	$$ = $1;
E 15
}
|
D 15
    NAME
E 15
I 15
    name
E 15
{
D 15
	$$ = build(O_LCON, signalname(ident($1)));
E 15
I 15
	$$ = siglookup(ident($1));
E 15
}
;
D 15

E 15
E 13
E 10
runcommand:
D 6
    run shellmode arglist
E 6
I 6
D 11
    run { arginit(); } arglist
E 11
I 11
    run arglist
E 11
E 6
I 5
|
D 6
    RUN
{
	fflush(stdout);
}
E 6
I 6
    run
E 6
E 5
;
I 13
D 15

E 15
E 13
run:
D 6
    RUN
E 6
I 6
    RUN shellmode
E 6
{
I 11
	arginit();
E 11
	fflush(stdout);
D 6
	arginit();
E 6
}
I 11
|
    RERUN shellmode
{
	fflush(stdout);
}
E 11
;
arglist:
    arglist arg
|
D 5
    /* empty */
E 5
I 5
    arg
E 5
;
arg:
D 13
    NAME
E 13
I 13
D 15
     NAME
E 15
I 15
    NAME
E 15
E 13
{
	newarg(ident($1));
}
|
I 11
D 13
    STRING
E 13
I 13
D 15
     STRING
E 15
I 15
    STRING
E 15
E 13
{
	newarg($1);
}
|
E 11
    '<' NAME
{
	inarg(ident($2));
}
|
    '>' NAME
{
	outarg(ident($2));
}
;
step:
D 13
    STEP
E 13
I 13
D 15
    STEP stopaliasing
E 15
I 15
    STEP
E 15
E 13
{
	$$ = build(O_STEP, true, false);
}
|
D 13
    STEPI
E 13
I 13
D 15
    STEPI stopaliasing
E 15
I 15
    STEPI
E 15
E 13
{
	$$ = build(O_STEP, false, false);
}
|
D 13
    NEXT
E 13
I 13
D 15
    NEXT stopaliasing
E 15
I 15
    NEXT
E 15
E 13
{
	$$ = build(O_STEP, true, true);
}
|
D 13
    NEXTI
E 13
I 13
D 15
    NEXTI stopaliasing
E 15
I 15
    NEXTI
E 15
E 13
{
	$$ = build(O_STEP, false, true);
}
;
shellmode:
    /* empty */
{
	beginshellmode();
I 14
D 15
	stopaliasing();
E 15
E 14
}
;
sourcepath:
    sourcepath NAME
{
D 9
	list_append(list_item(ident($2)), nil, sourcepath);
E 9
I 9
	$$ = $1;
	list_append(list_item(ident($2)), nil, $$);
E 9
}
|
    /* empty */
{
D 9
	String dir;

	foreach (String, dir, sourcepath)
	    list_delete(list_curitem(sourcepath), sourcepath);
	endfor
E 9
I 9
	$$ = list_alloc();
E 9
}
;
event:
    where
|
    exp
;
actions:
    actions cmd ';'
{
	$$ = $1;
	cmdlist_append($2, $$);
}
|
    cmd ';'
{
	$$ = list_alloc();
	cmdlist_append($1, $$);
}
;
cmd:
    command
|
    rcommand
;

/*
 * Redirectable commands.
 */
rcommand:
D 13
    PRINT exp_list
E 13
I 13
D 15
    PRINT stopaliasing exp_list
E 15
I 15
    PRINT exp_list
E 15
E 13
{
D 13
	$$ = build(O_PRINT, $2);
E 13
I 13
D 15
	$$ = build(O_PRINT, $3);
E 15
I 15
	$$ = build(O_PRINT, $2);
E 15
E 13
}
|
    WHERE
{
	$$ = build(O_WHERE);
}
|
    examine
{
	$$ = $1;
}
|
D 11
    CALL term
E 11
I 11
D 13
    CALL term '(' opt_exp_list ')'
E 13
I 13
D 15
    CALL stopaliasing term '(' opt_exp_list ')'
E 15
I 15
    CALL term '(' opt_exp_list ')'
E 15
E 13
E 11
{
D 11
	$$ = $2;
E 11
I 11
D 13
	$$ = build(O_CALL, $2, $4);
E 13
I 13
D 15
	$$ = build(O_CALL, $3, $5);
E 15
I 15
	$$ = build(O_CALLPROC, $2, $4);
E 15
E 13
E 11
}
|
I 7
    DEBUG INT
{
 	$$ = build(O_DEBUG, $2);
}
|
I 15
    DEBUG '-' INT
{
	$$ = build(O_DEBUG, -$3);
}
|
    DUMP opt_qual_symbol
{
	$$ = build(O_DUMP, $2);
}
|
    DUMP '.'
{
	$$ = build(O_DUMP, nil);
}
|
E 15
E 7
    DUMP
{
D 15
	$$ = build(O_DUMP);
E 15
I 15
	$$ = build(O_DUMP, build(O_SYM, curfunc));
E 15
}
|
    STATUS
{
	$$ = build(O_STATUS);
}
;
alias_command:
D 13
    ALIAS name name
E 13
I 13
D 15
    alias name something
E 15
I 15
    ALIAS name name
E 15
E 13
{
D 13
	$$ = build(O_ALIAS, build(O_NAME, $2), build(O_NAME, $3));
E 13
I 13
D 15
	$$ = build(O_ALIAS, build(O_NAME, $2), $3);
E 15
I 15
	$$ = build(O_ALIAS, build(O_NAME, $2), build(O_NAME, $3));
E 15
E 13
}
|
D 13
    ALIAS name
E 13
I 13
D 15
    alias name
E 15
I 15
    ALIAS name STRING
E 15
E 13
{
I 15
	$$ = build(O_ALIAS, build(O_NAME, $2), build(O_SCON, $3));
}
|
    ALIAS name '(' name_list ')' STRING
{
	$$ = build(O_ALIAS,
	    build(O_COMMA, build(O_NAME, $2), (Node) $4),
	    build(O_SCON, $6)
	);
}
|
    ALIAS name
{
E 15
	$$ = build(O_ALIAS, build(O_NAME, $2), nil);
}
|
D 13
    ALIAS
E 13
I 13
D 15
    alias
E 15
I 15
    ALIAS
E 15
E 13
{
	$$ = build(O_ALIAS, nil, nil);
}
;
I 13
D 15

alias:
     ALIAS stopaliasing
;

stopaliasing:
    /* empty */
E 15
I 15
name_list:
    name_list ',' name
E 15
{
D 15
	stopaliasing();
E 15
I 15
	$$ = $1;
	list_append(list_item($3), nil, $$);
E 15
}
I 15
|
    name
{
	$$ = list_alloc();
	list_append(list_item($1), nil, $$);
}
E 15
;
D 15

E 15
E 13
trace:
D 13
    TRACE
E 13
I 13
D 15
    TRACE stopaliasing
E 15
I 15
    TRACE
E 15
E 13
{
	$$ = O_TRACE;
}
|
D 13
    TRACEI
E 13
I 13
D 15
    TRACEI stopaliasing
E 15
I 15
    TRACEI
E 15
E 13
{
	$$ = O_TRACEI;
}
;
stop:
D 13
    STOP
E 13
I 13
D 15
    STOP stopaliasing
E 15
I 15
    STOP
E 15
E 13
{
	$$ = O_STOP;
}
|
D 13
    STOPI
E 13
I 13
D 15
    STOPI stopaliasing
E 15
I 15
    STOPI
E 15
E 13
{
	$$ = O_STOPI;
}
;
what:
    exp
{
	$$ = $1;
}
|
    STRING ':' line_number
{
	$$ = build(O_QLINE, build(O_SCON, $1), $3);
}
;
where:
D 15
    IN term
E 15
I 15
    IN exp
E 15
{
D 15
	$$ = $2;
E 15
I 15
	$$ = unrval($2);
E 15
}
|
    AT line_number
{
D 15
	$$ = build(O_QLINE, build(O_SCON, cursource), $2);
E 15
I 15
	$$ = build(O_QLINE, build(O_SCON, strdup(cursource)), $2);
E 15
}
|
    AT STRING ':' line_number
{
	$$ = build(O_QLINE, build(O_SCON, $2), $4);
}
;
filename:
    NAME
{
	$$ = ident($1);
}
;
opt_filename:
    /* empty */
{
	$$ = nil;
}
|
    filename
{
	$$ = $1;
}
;
D 5
opt_arglist:
    /* empty */
E 5
I 5
opt_exp_list:
    exp_list
E 5
{
D 5
	$$ = nil;
E 5
I 5
	$$ = $1;
E 5
}
|
D 5
    '(' exp_list ')'
E 5
I 5
    /* empty */
E 5
{
D 5
	$$ = $2;
E 5
I 5
	$$ = nil;
E 5
}
;
list_command:
D 13
    LIST
E 13
I 13
D 15
    list
E 15
I 15
    LIST
E 15
E 13
{
	$$ = build(O_LIST,
	    build(O_LCON, (long) cursrcline),
D 19
	    build(O_LCON, (long) cursrcline + 9)
E 19
I 19
	    build(O_LCON, (long) cursrcline + srcwindowlen() - 1)
E 19
	);
}
|
D 13
    LIST line_number
E 13
I 13
D 15
    list line_number
E 15
I 15
    LIST line_number
E 15
E 13
{
	$$ = build(O_LIST, $2, $2);
}
|
D 13
    LIST line_number ',' line_number
E 13
I 13
D 15
    list line_number ',' line_number
E 15
I 15
    LIST line_number ',' line_number
E 15
E 13
{
	$$ = build(O_LIST, $2, $4);
}
|
D 11
    LIST symbol
E 11
I 11
D 13
    LIST opt_qual_symbol
E 13
I 13
D 15
    list symbol
E 15
I 15
    LIST opt_qual_symbol
E 15
E 13
E 11
{
D 13
	$$ = build(O_LIST, $2);
E 13
I 13
D 15
	$$ = build(O_LIST, $2, nil);
E 15
I 15
D 19
	$$ = build(O_LIST, $2);
E 19
I 19
	$$ = build(O_LIST, $2, $2);
E 19
E 15
E 13
}
;
I 11
D 13
integer_list:
    INT
{
	$$ = build(O_LCON, $1);
}
|
    INT integer_list
{
	$$ = build(O_COMMA, build(O_LCON, $1), $2);
}
E 13
I 13
D 15

list:
    LIST stopaliasing
E 15
I 15
integer_list:
    INT
{
	$$ = build(O_LCON, $1);
}
|
    INT integer_list
{
	$$ = build(O_COMMA, build(O_LCON, $1), $2);
}
E 15
E 13
;
I 13
D 15

E 15
E 13
E 11
line_number:
    INT
{
	$$ = build(O_LCON, $1);
}
|
    '$'
{
	$$ = build(O_LCON, (long) LASTLINE);
}
;
examine:
    address '/' count mode
{
	$$ = build(O_EXAMINE, $4, $1, nil, $3);
}
|
    address ',' address '/' mode
{
	$$ = build(O_EXAMINE, $5, $1, $3, 0);
}
|
D 14
    '/' count mode
E 14
I 14
D 15
    '/' stopaliasing count mode
E 14
{
D 14
	$$ = build(O_EXAMINE, $3, build(O_LCON, (long) prtaddr), nil, $2);
E 14
I 14
	$$ = build(O_EXAMINE, $4, build(O_LCON, (long) prtaddr), nil, $3);
E 14
}
I 3
|
E 15
    address '=' mode
{
	$$ = build(O_EXAMINE, $3, $1, nil, 0);
}
E 3
;
address:
D 14
    INT
E 14
I 14
D 15
    INT stopaliasing
E 15
I 15
    INT
E 15
E 14
{
	$$ = build(O_LCON, $1);
}
|
D 14
    '&' term
E 14
I 14
D 15
    '&' stopaliasing term
E 15
I 15
    '.'
E 15
E 14
{
D 14
	$$ = amper($2);
E 14
I 14
D 15
	$$ = amper($3);
E 15
I 15
	$$ = build(O_LCON, (long) prtaddr);
E 15
E 14
}
|
I 15
    '&' term
{
	$$ = amper($2);
}
|
E 15
    address '+' address
{
	$$ = build(O_ADD, $1, $3);
}
|
    address '-' address
{
	$$ = build(O_SUB, $1, $3);
}
|
    address '*' address
{
	$$ = build(O_MUL, $1, $3);
}
|
D 14
    '*' address %prec UNARYSIGN
E 14
I 14
D 15
    '*' stopaliasing address %prec UNARYSIGN
E 15
I 15
    '*' address %prec UNARYSIGN
E 15
E 14
{
D 14
	$$ = build(O_INDIR, $2);
E 14
I 14
D 15
	$$ = build(O_INDIR, $3);
E 15
I 15
	$$ = build(O_INDIR, $2);
E 15
E 14
}
|
D 14
    '(' exp ')'
E 14
I 14
D 15
    '(' stopaliasing exp ')'
E 15
I 15
    '-' address %prec UNARYSIGN
E 15
E 14
{
D 14
	$$ = $2;
E 14
I 14
D 15
	$$ = $3;
E 15
I 15
	$$ = build(O_NEG, $2);
E 15
E 14
}
I 15
|
    '(' exp ')'
{
	$$ = $2;
}
E 15
;
I 15
term:
    symbol
{
	$$ = $1;
}
|
    term '.' name
{
	$$ = unrval(dot($1, $3));
}
|
    term ARROW name
{
	$$ = unrval(dot($1, $3));
}
|
    term '[' exp_list ']'
{
	$$ = unrval(subscript($1, $3));
}
;
E 15
count:
    /* empty */
{
	$$ = 1;
}
|
    INT
{
	$$ = $1;
}
;
mode:
    name
{
	$$ = ident($1);
	curformat = $$;
}
|
    /* empty */
{
	$$ = curformat;
}
;
opt_cond:
    /* empty */
{
	$$ = nil;
}
|
    IF boolean_exp
{
	$$ = $2;
}
;
exp_list:
    exp
{
	$$ = build(O_COMMA, $1, nil);
}
|
    exp ',' exp_list
{
	$$ = build(O_COMMA, $1, $3);
}
;
exp:
D 15
    term
E 15
I 15
    symbol
E 15
{
	$$ = build(O_RVAL, $1);
}
|
D 15
    constant
E 15
I 15
    exp '[' exp_list ']'
E 15
{
D 15
	$$ = $1;
E 15
I 15
	$$ = subscript(unrval($1), $3);
E 15
I 3
}
|
I 15
    exp '.' name
{
	$$ = dot($1, $3);
}
|
    exp ARROW name
{
	$$ = dot($1, $3);
}
|
    '*' exp %prec UNARYSIGN
{
	$$ = build(O_INDIR, $2);
}
|
    exp '^' %prec UNARYSIGN
{
	$$ = build(O_INDIR, $1);
}
|
E 15
D 11
    exp '\\' symbol
E 11
I 11
    exp '\\' opt_qual_symbol
E 11
{
	$$ = build(O_TYPERENAME, $1, $3);
E 3
}
|
I 15
    exp '\\' '&' opt_qual_symbol %prec '\\'
{
	$$ = renameptr($1, $4);
}
|
    exp '(' opt_exp_list ')'
{
	$$ = build(O_CALL, unrval($1), $3);
}
|
    constant
{
	$$ = $1;
}
|
E 15
    '+' exp %prec UNARYSIGN
{
	$$ = $2;
}
|
    '-' exp %prec UNARYSIGN
{
	$$ = build(O_NEG, $2);
}
|
    '&' exp %prec UNARYSIGN
{
	$$ = amper($2);
}
|
    exp '+' exp
{
	$$ = build(O_ADD, $1, $3);
}
|
    exp '-' exp
{
	$$ = build(O_SUB, $1, $3);
}
|
    exp '*' exp
{
	$$ = build(O_MUL, $1, $3);
}
|
    exp '/' exp
{
	$$ = build(O_DIVF, $1, $3);
}
|
    exp DIV exp
{
	$$ = build(O_DIV, $1, $3);
}
|
    exp MOD exp
{
	$$ = build(O_MOD, $1, $3);
}
|
    exp AND exp
{
	$$ = build(O_AND, $1, $3);
}
|
    exp OR exp
{
	$$ = build(O_OR, $1, $3);
}
|
    exp '<' exp
{
	$$ = build(O_LT, $1, $3);
}
|
    exp '<' '=' exp
{
	$$ = build(O_LE, $1, $4);
}
|
    exp '>' exp
{
	$$ = build(O_GT, $1, $3);
}
|
    exp '>' '=' exp
{
	$$ = build(O_GE, $1, $4);
}
|
    exp '=' exp
{
	$$ = build(O_EQ, $1, $3);
}
|
    exp '=' '=' exp
{
	$$ = build(O_EQ, $1, $4);
}
|
    exp '<' '>' exp
{
	$$ = build(O_NE, $1, $4);
}
|
    exp '!' '=' exp
{
	$$ = build(O_NE, $1, $4);
}
|
    '(' exp ')'
{
	$$ = $2;
}
;
D 15
term:
    symbol
{
	$$ = $1;
}
|
    term '[' exp_list ']'
{
	$$ = subscript($1, $3);
}
|
    term '.' name
{
	$$ = dot($1, $3);
}
|
    term ARROW name
{
	$$ = dot($1, $3);
}
|
    '*' term %prec UNARYSIGN
{
	$$ = build(O_INDIR, $2);
}
|
    '*' '(' exp ')' %prec UNARYSIGN
{
	$$ = build(O_INDIR, $3);
}
|
    term '^' %prec UNARYSIGN
{
	$$ = build(O_INDIR, $1);
}
|
    '#' term %prec UNARYSIGN
{
	$$ = concrete($2);
}
|
I 11
    '#' '(' exp ')' %prec UNARYSIGN
{
	$$ = concrete($3);
}
|
E 11
D 5
    term '(' exp_list ')'
E 5
I 5
    term '(' opt_exp_list ')'
E 5
{
	$$ = build(O_CALL, $1, $3);
}
;
E 15
boolean_exp:
    exp
{
	chkboolean($1);
	$$ = $1;
}
;
constant:
    INT
{
	$$ = build(O_LCON, $1);
}
|
I 15
    CHAR
{
	$$ = build(O_CCON, $1);
}
|
E 15
    REAL
{
	$$ = build(O_FCON, $1);
}
|
    STRING
{
	$$ = build(O_SCON, $1);
}
;
I 11
opt_qual_symbol:
    symbol
{
	$$ = $1;
}
|
    opt_qual_symbol '.' name
{
	$$ = dot($1, $3);
}
;
E 11
symbol:
    name
{
D 15
	$$ = build(O_SYM, which($1));
E 15
I 15
	$$ = findvar($1);
	if ($$ == nil) {
	    $$ = build(O_SYM, which($1));
	}
E 15
}
I 11
|
    '.' name
{
	$$ = dot(build(O_SYM, program), $2);
}
E 11
;
name:
    NAME
{
	$$ = $1;
}
|
    keyword
{
	$$ = $1;
}
keyword:
D 7
    ALIAS | AND | ASSIGN | AT | CALL | CATCH | CONT | DELETE | DIV | DUMP |
    EDIT | FILE | FUNC | GRIPE | HELP | IGNORE | IN | LIST | MOD |
E 7
I 7
    ALIAS | AND | ASSIGN | AT | CALL | CATCH | CONT | DEBUG | DELETE | DIV | 
D 11
    DUMP | EDIT | FILE | FUNC | GRIPE | HELP | IGNORE | IN | LIST | MOD |
E 7
    NEXT | NEXTI | NIL | NOT | OR | PRINT | PSYM | QUIT | RUN |
    SH | SKIP | SOURCE | STATUS | STEP | STEPI |
    STOP | STOPI | TRACE | TRACEI |
E 11
I 11
    DOWN | DUMP | EDIT | FILE | FUNC | GRIPE | HELP | IGNORE | IN | LIST |
    MOD | NEXT | NEXTI | NIL | NOT | OR | PRINT | PSYM | QUIT |
D 15
    RERUN | RETURN | RUN | SH | SKIP | SOURCE | STATUS | STEP | STEPI |
    STOP | STOPI | TRACE | TRACEI | UP |
E 11
D 8
    USE | WHATIS | WHEN | WHERE | WHICH
E 8
I 8
    USE | WHATIS | WHEN | WHERE | WHEREIS | WHICH
I 13
;

something:
    NAME
{
	$$ = build(O_NAME, $1);
}
|
    keyword
{
	$$ = build(O_NAME, $1);
}
|
    STRING
{
	$$ = build(O_SCON, $1);
}
E 15
I 15
    RERUN | RETURN | RUN | SET | SH | SKIP | SOURCE | STATUS | STEP | STEPI |
    STOP | STOPI | TRACE | TRACEI | UNALIAS | UNSET | UP | USE |
    WHATIS | WHEN | WHERE | WHEREIS | WHICH
E 15
E 13
E 8
;
E 1
