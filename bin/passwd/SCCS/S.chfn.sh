h16565
s 00005/00509/00000
d D 4.9 85/03/24 15:05:16 mckusick 9 8
c subsummed by passwd
e
s 00051/00031/00458
d D 4.8 83/12/20 13:36:58 ralph 8 7
c update dbm passwd database directly.
e
s 00036/00010/00453
d D 4.7 83/12/02 17:31:38 ralph 7 6
c changed to rebuild passwd hash database.
e
s 00001/00000/00462
d D 4.6 83/07/10 17:53:35 sam 6 5
c beware of screwey user umasks
e
s 00002/00002/00460
d D 4.5 83/07/02 00:54:26 sam 5 4
c include fixes
e
s 00029/00048/00433
d D 4.4 83/06/10 23:33:23 sam 4 3
c do locking a la password
e
s 00173/00026/00308
d D 4.3 83/05/18 18:35:17 mckusick 3 2
c soiffer's latest round of changes
e
s 00285/00064/00049
d D 4.2 83/05/03 14:09:40 mckusick 2 1
c user friendly improvements by Neil Soiffer
e
s 00113/00000/00000
d D 4.1 80/10/01 17:25:26 bill 1 0
c date and time created 80/10/01 17:25:26 by bill
e
u
U
f b 
t
T
I 2
D 9
#ifndef lint
E 2
I 1
static char *sccsid = "%W% (Berkeley) %G%";
I 2
#endif lint

E 2
/*
D 2
 * chfn - change full name (or other info in gecos field)
E 2
I 2
 *	 changefinger - change finger entries
E 2
 */
#include <stdio.h>
#include <signal.h>
#include <pwd.h>
I 8
#include <ndbm.h>
E 8
I 4
D 5
#include <time.h>
#include <resource.h>
E 5
I 5
#include <sys/time.h>
#include <sys/resource.h>
E 5
#include <sys/file.h>
E 4
I 3
#include <ctype.h>
E 3

I 3
struct default_values {
	char *name;
	char *office_num;
	char *office_phone;
	char *home_phone;
};

I 7
char	temp[] = "/etc/ptmp";
D 8
char	temp_pag[] = "/etc/ptmp.pag";
char	temp_dir[] = "/etc/ptmp.dir";
E 8
E 7
E 3
char	passwd[] = "/etc/passwd";
D 7
char	temp[]	 = "/etc/ptmp";
E 7
I 7
D 8
char	passwd_pag[] = "/etc/passwd.pag";
char	passwd_dir[] = "/etc/passwd.dir";
E 8
E 7
struct	passwd *pwd;
D 2
struct	passwd *getpwent();
E 2
I 2
D 7
struct	passwd *getpwent(), *getpwnam(), *getpwuid();
E 2
int	endpwent();
E 7
char	*crypt();
char	*getpass();
D 2
char	*pw;
char	pwbuf[10];
E 2
D 4
char	buf[BUFSIZ];
E 4

I 2
D 3
#define MAX_STR 52
E 3
E 2
main(argc, argv)
D 2
char *argv[];
E 2
I 2
	int argc;
	char *argv[];
E 2
{
D 2
	char *p;
	int i;
	char saltc[2];
	long salt;
	int u,fi,fo;
	int insist;
	int ok, flags;
	int c;
	int pwlen;
E 2
I 2
	int user_uid;
D 4
	int num_bytes, fi, fo;
E 4
D 3
	char replacement[4*MAX_STR];
E 3
I 3
	char replacement[4*BUFSIZ];
I 4
	int fd;
E 4
E 3
E 2
	FILE *tf;
I 8
	DBM *dp;
E 8

D 2
	insist = 0;
	if (argc != 3) {
		printf("Usage: chfn user full-name\n");
		goto bex;
	}
	if (index(argv[2], ':') || index(argv[2], '\n')) {
		printf("Illegal character in new string\n");
E 2
I 2
	if (argc > 2) {
		printf("Usage: changefinger [user]\n");
E 2
		exit(1);
	}
D 2
	while((pwd=getpwent()) != NULL){
		if(strcmp(pwd->pw_name,argv[1]) == 0){
			u = getuid();
			if(u!=0 && u != pwd->pw_uid){
				printf("Permission denied.\n");
				goto bex;
				}
			break;
			}
E 2
I 2
	/*
	 * Error check to make sure the user (foolishly) typed their own name.
	 */
	user_uid = getuid();
	if ((argc == 2) && (user_uid != 0)) {
		pwd = getpwnam(argv[1]);
		if (pwd == NULL) {
			printf("%s%s%s%s%s%s%s%s",
				"There is no account for ", argv[1],
				" on this machine.\n", 
				"You probably mispelled your login name;\n",
				"only root is allowed to change another",
				" person's finger entry.\n",
				"Note:  you do not need to type your login",
				" name as an argument.\n");
			exit(1);
E 2
		}
D 2
	endpwent();
	signal(SIGHUP, 1);
	signal(SIGINT, 1);
	signal(SIGQUIT, 1);
	signal(SIGTSTP, 1);

E 2
I 2
		if (pwd->pw_uid != user_uid) {
			printf("%s%s",
				"You are not allowed to change another",
D 3
				" person's password entry.\n");
E 3
I 3
				" person's finger entry.\n");
E 3
			exit(1);
		}
	}
	/*
	 * If root is changing a finger entry, then find the uid that
	 * corresponds to the user's login name.
	 */
	if ((argc == 2) && (user_uid == 0)) {
		pwd = getpwnam(argv[1]);
		if (pwd == NULL) {
			printf("There is no account for %s on this machine\n", 
				pwd->pw_name);
			exit(1);
		}
		user_uid = pwd->pw_uid;
	}
I 3
	if (argc == 1) {
		pwd = getpwuid(user_uid);
		if (pwd == NULL) {
			fprintf(stderr, "No passwd file entry!?\n");
			exit(1);
		}
	}
E 3
	/*
	 * Collect name, room number, school phone, and home phone.
	 */
D 3
	get_info(replacement);
E 3
I 3
	get_info(pwd->pw_gecos, replacement);

E 3
D 4
	/*
	 * Update the entry in the password file.
	 */
	while (access(temp, 0) >= 0) {
		printf("Password file busy -- waiting for it to be free.\n");
		sleep(10);
	}
E 4
	(void) signal(SIGHUP, SIG_IGN);
	(void) signal(SIGINT, SIG_IGN);
	(void) signal(SIGQUIT, SIG_IGN);
	(void) signal(SIGTSTP, SIG_IGN);
I 6
	(void) umask(0);
E 6
D 4
	/*
	 * Race condition -- the locking mechinism is not my idea (ns)
	 */
E 2
D 3
	if(access(temp, 0) >= 0) {
E 3
I 3
	if (access(temp, 0) >= 0) {
E 3
D 2
		printf("Temporary file busy -- try again\n");
		goto bex;
E 2
I 2
		printf("It's not your day!  Password file is busy again.\n");
		printf("Try again later.\n");
E 4
I 4
	if ((fd = open(temp, O_CREAT|O_EXCL|O_RDWR, 0644)) < 0) {
		printf("Temporary file busy -- try again\n");
E 4
		exit(1);
E 2
	}
D 3
	if((tf=fopen(temp,"w")) == NULL) {
E 3
I 3
D 4
	if ((tf=fopen(temp,"w")) == NULL) {
E 3
		printf("Cannot create temporary file\n");
D 2
		goto bex;
E 2
I 2
		exit(1);
E 2
	}
D 2

/*
 *	copy passwd to temp, replacing matching lines
 *	with new shell.
 */

E 2
I 2
	/*
	 * There is another race condition here:  if the passwd file
	 * has changed since the error checking at the beginning of the program,
	 * then user_uid may not be in the file.  Of course, the uid might have
	 * been changed, but this is not supposed to happen.
	 */
	if (getpwuid(user_uid) == NULL) {
		printf("%s%d%s\n", "Passwd file has changed. Uid ", user_uid,
			" is no longer in the file!?");
E 4
I 4
	if ((tf = fdopen(fd, "w")) == NULL) {
		printf("Absurd fdopen failure - seek help\n");
E 4
		goto out;
	}
I 8
	if ((dp = ndbmopen(passwd, O_RDWR, 0644)) == NULL) {
		fprintf(stderr, "Warning: dbminit failed: ");
		perror(passwd);
	} else if (flock(dp->db_dirf, LOCK_EX) < 0) {
		perror("Warning: lock failed");
		ndbmclose(dp);
		dp = NULL;
	}
E 8
I 4
	unlimit(RLIMIT_CPU);
	unlimit(RLIMIT_FSIZE);
E 4
	/*
D 4
	 * copy passwd to temp, replacing matching line
	 * with new finger entry (gecos field).
E 4
I 4
	 * Copy passwd to temp, replacing matching lines
	 * with new gecos field.
E 4
	 */
E 2
D 3
	while((pwd=getpwent()) != NULL) {
D 2
		if(strcmp(pwd->pw_name,argv[1]) == 0) {
			u = getuid();
			if(u != 0 && u != pwd->pw_uid) {
				printf("Permission denied.\n");
				goto out;
			}
			pwd->pw_gecos = argv[2];
E 2
I 2
		if(pwd->pw_uid == user_uid) {
E 3
I 3
D 4
	while ((pwd=getpwent()) != NULL) {
		if (pwd->pw_uid == user_uid) {
E 4
I 4
	while ((pwd = getpwent()) != NULL) {
D 8
		if (pwd->pw_uid == user_uid)
E 8
I 8
		if (pwd->pw_uid == user_uid) {
E 8
E 4
E 3
			pwd->pw_gecos = replacement;
I 8
			replace(dp, pwd);
		}
E 8
E 2
D 4
		}
E 4
		fprintf(tf,"%s:%s:%d:%d:%s:%s:%s\n",
			pwd->pw_name,
			pwd->pw_passwd,
			pwd->pw_uid,
			pwd->pw_gid,
			pwd->pw_gecos,
			pwd->pw_dir,
			pwd->pw_shell);
	}
D 2
	endpwent();
	fclose(tf);

/*
 *	copy temp back to passwd file
 */

E 2
I 2
	(void) endpwent();
D 4
	(void) fclose(tf);
	/*
	 * Copy temp back to password file.
	 */
E 2
	if((fi=open(temp,0)) < 0) {
		printf("Temp file disappeared!\n");
		goto out;
E 4
I 4
D 7
	if (rename(temp, passwd) < 0) {
		fprintf(stderr, "chfn: "); perror("rename");
  out:
		(void) unlink(temp);
		exit(1);
E 4
	}
E 7
D 4
	if((fo=creat(passwd, 0644)) < 0) {
		printf("Cannot recreat passwd file.\n");
		goto out;
	}
D 2
	while((u=read(fi,buf,sizeof(buf))) > 0) write(fo,buf,u);

E 2
I 2
	while((num_bytes=read(fi,buf,sizeof(buf))) > 0)
		(void) write(fo,buf,num_bytes);
E 2
out:
D 2
	unlink(temp);
E 2
I 2
	(void) unlink(temp);
E 4
I 4
	(void) fclose(tf);
D 7
	exit(0);
E 7
I 7
D 8
	if (makedb(temp) < 0)
		fprintf(stderr, "chfn: mkpasswd failed\n");
	else if (rename(temp_pag, passwd_pag) < 0)
		fprintf(stderr, "chfn: "), perror(temp_pag);
	else if (rename(temp_dir, passwd_dir) < 0)
		fprintf(stderr, "chfn: "), perror(temp_dir);
	else if (rename(temp, passwd) < 0)
E 8
I 8
	ndbmclose(dp);
	if (rename(temp, passwd) < 0) {
E 8
		fprintf(stderr, "chfn: "), perror("rename");
D 8
	else
		exit(0);
out:
	unlink(temp_pag);
	unlink(temp_dir);
	unlink(temp);
	exit(1);
E 8
I 8
	out:
		(void) unlink(temp);
		exit(1);
	}
	exit(0);
E 8
E 7
}

unlimit(lim)
{
	struct rlimit rlim;

	rlim.rlim_cur = rlim.rlim_max = RLIM_INFINITY;
	(void) setrlimit(lim, &rlim);
I 7
}

D 8
makedb(file)
	char *file;
E 8
I 8
/*
 * Replace the password entry in the dbm data base with pwd.
 */
replace(dp, pwd)
	DBM *dp;
	struct passwd *pwd;
E 8
{
D 8
	int status, pid, w;
E 8
I 8
	datum key, content;
	register char *cp, *tp;
	char buf[BUFSIZ];
E 8

D 8
	if ((pid = vfork()) == 0) {
		execl("/etc/mkpasswd", "mkpasswd", file, 0);
		_exit(127);
	}
	while ((w = wait(&status)) != pid && w != -1)
		;
	if (w == -1 || status != 0)
		status = -1;
	return(status);
E 8
I 8
	if (dp == NULL)
		return;

	cp = buf;
#define	COMPACT(e)	tp = pwd->pw_/**/e; while (*cp++ = *tp++);
	COMPACT(name);
	COMPACT(passwd);
	*(int *)cp = pwd->pw_uid; cp += sizeof (int);
	*(int *)cp = pwd->pw_gid; cp += sizeof (int);
	*(int *)cp = pwd->pw_quota; cp += sizeof (int);
	COMPACT(comment);
	COMPACT(gecos);
	COMPACT(dir);
	COMPACT(shell);
	content.dptr = buf;
	content.dsize = cp - buf;
	key.dptr = pwd->pw_name;
	key.dsize = strlen(pwd->pw_name);
	dbmstore(dp, key, content, DB_REPLACE);
	key.dptr = (char *)&pwd->pw_uid;
	key.dsize = sizeof (int);
	dbmstore(dp, key, content, DB_REPLACE);
E 8
E 7
E 4
}
D 3

E 3
I 3

E 3
/*
 * Get name, room number, school phone, and home phone.
 */
D 3
get_info(answer)
E 3
I 3
get_info(gecos_field, answer)
	char *gecos_field;
E 3
	char *answer;
{
	char *strcpy(), *strcat();
D 3
	char in_str[MAX_STR];
	answer[0] = '\0';
E 3
I 3
	char in_str[BUFSIZ];
	struct default_values *defaults, *get_defaults();
E 3
E 2

I 3
	answer[0] = '\0';
	defaults = get_defaults(gecos_field);
	printf("Default values are printed inside of of '[]'.\n");
	printf("To accept the default, type <return>.\n");
	printf("To have a blank entry, type the word 'none'.\n");
E 3
D 2
bex:
	exit(1);
E 2
I 2
	/*
	 * Get name.
	 */
	do {
D 3
		printf("\nName: ");
		(void) fgets(in_str, MAX_STR, stdin);
E 3
I 3
		printf("\nName [%s]: ", defaults->name);
		(void) fgets(in_str, BUFSIZ, stdin);
		if (special_case(in_str, defaults->name)) 
			break;
E 3
	} while (illegal_input(in_str));
	(void) strcpy(answer, in_str);
	/*
	 * Get room number.
	 */
	do {
D 3
		printf("Room number (Exs: 597E or 197C): ");
		(void) fgets(in_str, MAX_STR, stdin);
E 3
I 3
		printf("Room number (Exs: 597E or 197C) [%s]: ",
			defaults->office_num);
		(void) fgets(in_str, BUFSIZ, stdin);
		if (special_case(in_str, defaults->office_num))
			break;
E 3
	} while (illegal_input(in_str) || illegal_building(in_str));
	(void) strcat(strcat(answer, ","), in_str);
	/*
	 * Get office phone number.
D 3
	 * Remove hyphens and 642 or x2 prefixes if present.
E 3
I 3
	 * Remove hyphens and 642, x2, or 2 prefixes if present.
E 3
	 */
	do {
D 3
		printf("Office Phone (Ex: 1632): ");
		(void) fgets(in_str, MAX_STR, stdin);
E 3
I 3
		printf("Office Phone (Ex: 1632) [%s]: ",
			defaults->office_phone);
		(void) fgets(in_str, BUFSIZ, stdin);
		if (special_case(in_str, defaults->office_phone))
			break;
E 3
		remove_hyphens(in_str);
		if ((strlen(in_str) == 8) && (strcmpn(in_str, "642", 3) == 0))
			(void) strcpy(in_str, in_str+3);
		if ((strlen(in_str) == 7) && (strcmpn(in_str, "x2", 2) == 0))
			(void) strcpy(in_str, in_str+2);
D 3
	} while ((illegal_input(in_str)) || wrong_length(in_str, 4));
E 3
I 3
		if ((strlen(in_str) == 6) && (in_str[0] == '2'))
			(void) strcpy(in_str, in_str+1);
	} while (illegal_input(in_str) || not_all_digits(in_str)
		 || wrong_length(in_str, 4));
E 3
	(void) strcat(strcat(answer, ","), in_str);
	/*
	 * Get home phone number.
	 * Remove hyphens if present.
	 */
	do {
D 3
		printf("Home Phone (Ex: 9875432): ");
		(void) fgets(in_str, MAX_STR, stdin);
E 3
I 3
		printf("Home Phone (Ex: 9875432) [%s]: ", defaults->home_phone);
		(void) fgets(in_str, BUFSIZ, stdin);
		if (special_case(in_str, defaults->home_phone))
			break;
E 3
		remove_hyphens(in_str);
D 3
	} while (illegal_input(in_str));
E 3
I 3
	} while (illegal_input(in_str) || not_all_digits(in_str));
E 3
	(void) strcat(strcat(answer, ","), in_str);
}
D 3

E 3
I 3

E 3
/*
 * Prints an error message if a ':' or a newline is found in the string.
 * A message is also printed if the input string is too long.
 * The password file uses :'s as seperators, and are not allowed in the "gcos"
D 3
 * field.  Newlines serve a delimiters between users in the password file,
E 3
I 3
 * field.  Newlines serve as delimiters between users in the password file,
E 3
 * and so, those too, are checked for.  (I don't think that it is possible to
 * type them in, but better safe than sorry)
 *
 * Returns '1' if a colon or newline is found or the input line is too long.
 */
illegal_input(input_str)
	char *input_str;
{
	char *index();
	char *ptr;
	int error_flag = 0;
	int length = strlen(input_str);

	if (index(input_str, ':')) {
		printf("':' is not allowed.\n");
		error_flag = 1;
	}
	if (input_str[length-1] != '\n') {
		/* the newline and the '\0' eat up two characters */
		printf("Maximum number of characters allowed is %d\n",
D 3
			MAX_STR-2);
E 3
I 3
			BUFSIZ-2);
E 3
		/* flush the rest of the input line */
		while (getchar() != '\n')
			/* void */;
		error_flag = 1;
	}
	/*
	 * Delete newline by shortening string by 1.
	 */
	input_str[length-1] = '\0';
	/*
	 * Don't allow control characters, etc in input string.
	 */
	for (ptr=input_str; *ptr != '\0'; ptr++) {
		if ((int) *ptr < 040) {
			printf("Control characters are not allowed.\n");
			error_flag = 1;
			break;
		}
	}
	return(error_flag);
}

/*
 * Removes '-'s from the input string.
 */
remove_hyphens(str)
	char *str;
{
	char *hyphen, *index(), *strcpy();

	while ((hyphen=index(str, '-')) != NULL) {
		(void) strcpy(hyphen, hyphen+1);
	}
}

/*
I 3
 *  Checks to see if 'str' contains only digits (0-9).  If not, then
 *  an error message is printed and '1' is returned.
 */
not_all_digits(str)
	char *str;
{
	char *ptr;

	for (ptr=str; *ptr != '\0'; ++ptr) {
		if (!isdigit(*ptr)) {
			printf("Phone numbers can only contain digits.\n");
			return(1);
		}
	}
	return(0);
}

/*
E 3
 * Returns 1 when the length of the input string is not zero or equal to n.
 * Prints an error message in this case.
 */
wrong_length(str, n)
	char *str;
	int n;
{
I 3

E 3
	if ((strlen(str) != 0) && (strlen(str) != n)) {
		printf("The phone number should be %d digits long.\n", n);
		return(1);
	}
	return(0);
}

/*
 * Make sure that building is 'E' or 'C'.
 * Error correction is done if building is 'e', 'c', "evans", or "cory".
 * Correction changes "str".
 * The finger program determines the building by looking at the last
 * character.  Currently, finger only allows that character to be 'E' or 'C'.
 *
 * Returns 1 if incorrect room format.
 * 
 * Note: this function assumes that the newline has been removed from str.
 */
illegal_building(str)
	char *str;
{
	int length = strlen(str);
	char *last_ch, *ptr;

	/*
	 * Zero length strings are acceptable input.
	 */
	if (length == 0)
		return(0);
	/*
	 * Delete "vans" and "ory".
	 */
	if (strcmpn(str+length-4, "vans", 4) == 0) {
		length -= 4;
		str[length] = '\0';
	}
	if (strcmpn(str+length-3, "ory", 3) == 0) {
		length -= 3;
		str[length] = '\0';
	}
	last_ch = str+length-1;
	/*
	 * Now change e to E or c to C.
	 */
	if (*last_ch == 'e')
		*last_ch = 'E';
	if (*last_ch == 'c')
		*last_ch = 'C';
	/*
	 * Delete any spaces before the E or C.
	 */
	for (ptr=last_ch-1; ptr>str; ptr--) {
		if (*ptr != ' ')
			break;
	}
	(void) strcpy(ptr+1, last_ch);
	/*
	 * Make sure building is evans or cory.
	 */
	if ((*last_ch != 'E') && (*last_ch != 'C')) {
		printf("%s%s%s",
			"The finger program requires that your",
			" office be in Cory or Evans.\n",
			"Enter this as (for example) 597E or 197C.\n");
		return(1);
	}
	return(0);
I 3
}

/* get_defaults picks apart "str" and returns a structure points.
 * "str" contains up to 4 fields separated by commas.
 * Any field that is missing is set to blank.
 */
struct default_values 
*get_defaults(str)
	char *str;
{
	struct default_values *answer;
	char *malloc(), *index();

	answer = (struct default_values *)
		malloc((unsigned)sizeof(struct default_values));
	if (answer == (struct default_values *) NULL) {
		fprintf(stderr,
			"\nUnable to allocate storage in get_defaults!\n");
		exit(1);
	}
	/*
	 * Values if no corresponding string in "str".
	 */
	answer->name = str;
	answer->office_num = "";
	answer->office_phone = "";
	answer->home_phone = "";
	str = index(answer->name, ',');
	if (str == 0) 
		return(answer);
	*str = '\0';
	answer->office_num = str + 1;
	str = index(answer->office_num, ',');
	if (str == 0) 
		return(answer);
	*str = '\0';
	answer->office_phone = str + 1;
	str = index(answer->office_phone, ',');
	if (str == 0) 
		return(answer);
	*str = '\0';
	answer->home_phone = str + 1;
	return(answer);
}

/*
 *  special_case returns true when either the default is accepted
 *  (str = '\n'), or when 'none' is typed.  'none' is accepted in
 *  either upper or lower case (or any combination).  'str' is modified
 *  in these two cases.
 */
int special_case(str,default_str)
	char *str;
	char *default_str;
{
	static char word[] = "none\n";
	char *ptr, *wordptr;

	/*
	 *  If the default is accepted, then change the old string do the 
	 *  default string.
	 */
	if (*str == '\n') {
		(void) strcpy(str, default_str);
		return(1);
	}
	/*
	 *  Check to see if str is 'none'.  (It is questionable if case
	 *  insensitivity is worth the hair).
	 */
	wordptr = word-1;
	for (ptr=str; *ptr != '\0'; ++ptr) {
		++wordptr;
		if (*wordptr == '\0')	/* then words are different sizes */
			return(0);
		if (*ptr == *wordptr)
			continue;
		if (isupper(*ptr) && (tolower(*ptr) == *wordptr))
			continue;
		/*
		 * At this point we have a mismatch, so we return
		 */
		return(0);
	}
	/*
	 * Make sure that words are the same length.
	 */
	if (*(wordptr+1) != '\0')
		return(0);
	/*
	 * Change 'str' to be the null string
	 */
	*str = '\0';
	return(1);
E 3
E 2
}
E 9
I 9
#!/bin/sh
#
#	%W% (Berkeley) %G%
#
echo 'Use "passwd -f"'
E 9
E 1
