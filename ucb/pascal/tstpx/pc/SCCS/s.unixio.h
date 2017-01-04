h34545
s 00026/00000/00000
d D 1.1 81/06/17 00:40:19 mckusick 1 0
c date and time created 81/06/17 00:40:19 by mckusick
e
u
U
t
T
I 1
(* Copyright (c) 1979 Regents of the University of California *)

const
sccsid = '%Z%%M% %I% %G%';

type
fileptr = record
	cnt :integer
	end;

function TELL(
var	fptr :text)
{returns} :fileptr;

  external;

procedure SEEK(
 var	fptr :text;
 var	cnt :fileptr);

  external;

procedure APPEND(
 var	fptr :text);

   external;
E 1
