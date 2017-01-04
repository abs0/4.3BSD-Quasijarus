h06316
s 00000/00000/00029
d D 4.2 82/08/17 13:26:36 rrh 2 1
c Changed the data types for the sdb class characters to be unsigned
c characters; this fixed a bug that prevented the arguments to a function
c from being printed symbolically.  The fix was done globally; it is not
c known if the "fix" fixed other bugs
e
s 00029/00000/00000
d D 4.1 80/10/09 23:57:32 bill 1 0
c date and time created 80/10/09 23:57:32 by bill
e
u
U
t
T
I 1
/* "%Z%%M% %I% %G%" */
/*
 *	UNIX/vax debugger
 */

/* unix parameters */
#define DBNAME "adb\n"
#define LPRMODE "%R"
#define OFFMODE "+%R"
#define TXTRNDSIZ PAGSIZ

TYPE	long TXTHDR[8];
TYPE	long SYMV;

#ifndef vax
struct {short hiword; short loword;}; /* stupid fp-11 */
#endif

/* symbol table in a.out file */
struct symtab {
	char	symc[8];
	char	symf;
	char	sympad[3];
	SYMV	symv;
};
#define SYMTABSIZ (sizeof (struct symtab))

#define SYMCHK 057
#define SYMTYPE(symflg) (symflg&41 ? DSYM : NSYM)
E 1
