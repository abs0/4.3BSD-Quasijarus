h23938
s 00007/00000/00000
d D 4.1 83/05/03 13:48:24 sam 1 0
c date and time created 83/05/03 13:48:24 by sam
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

typedef char *va_list;
# define va_dcl int va_alist;
# define va_start(list) list = (char *) &va_alist
# define va_end(list)
# define va_arg(list,mode) ((mode *)(list += sizeof(mode)))[-1]
E 1
