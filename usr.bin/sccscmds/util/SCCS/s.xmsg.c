h24471
s 00001/00001/00045
d D 1.2 88/12/22 12:57:22 sam 2 1
c purge uses of alloca
e
s 00046/00000/00000
d D 1.1 88/12/22 12:55:42 sam 1 0
c date and time created 88/12/22 12:55:42 by sam
e
u
U
t
T
I 1
# include	"errno.h"
# include	"../hdr/macros.h"
SCCSID(@(#)xmsg	2.1);
/*
	Call fatal with an appropriate error message
	based on errno.  If no good message can be made up, it makes
	up a simple message.
	The second argument is a pointer to the calling functions
	name (a string); it's used in the manufactured message.
*/


xmsg(file,func)
char *file, *func;
{
	register char *str;
	extern int errno;
	extern char Error[];

	switch (errno) {
	case ENFILE:
		str = "no file (ut3)";
		break;
	case ENOENT:
		sprintf(str = Error,"`%s' nonexistent (ut4)",file);
		break;
	case EACCES:
D 2
		str = alloca(size(file));
E 2
I 2
		str = malloc(size(file));
E 2
		copy(file,str);
		file = str;
		sprintf(str = Error,"directory `%s' unwritable (ut2)",
			dname(file));
		break;
	case ENOSPC:
		str = "no space! (ut10)";
		break;
	case EFBIG:
		str = "write error (ut8)";
		break;
	default:
		sprintf(str = Error,"errno = %d, function = `%s' (ut11)",errno,
			func);
		break;
	}
	return(fatal(str));
}
E 1
