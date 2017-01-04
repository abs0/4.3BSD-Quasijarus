h07206
s 00006/00001/00015
d D 5.1 85/05/31 16:54:21 dist 2 1
c Add copyright
e
s 00016/00000/00000
d D 1.1 83/04/27 22:36:24 baden 1 0
c date and time created 83/04/27 22:36:24 by baden
e
u
U
t
T
I 1
D 2
(setq SCCS-%M% "%W%	%G%")
E 2
;  FP interpreter/compiler
;  Copyright (c) 1982  Scott B. Baden
;  Berkeley, California
I 2
;
;  Copyright (c) 1982 Regents of the University of California.
;  All rights reserved.  The Berkeley software License Agreement
;  specifies the terms and conditions for redistribution.
;
(setq SCCS-%M% "%W% (Berkeley) %G%")
E 2

(declare (special
	  DynTraceFlg Measures TracedFns debug traceport level
	  piport poport ptport readtable infile outfile  newreadtable
	  char_num  fn_name  in_def
	  rsrvd  e_rsrvd  usr_fn_name in_buf  char_set
	  num_delim$  outfile builtins  wslen  stk  tkn timeIt))

(declare (macros t))

(eval-when (compile eval load)
  (or (get 'fpMacs 'loaded) (load 'fpMacs)))
E 1
