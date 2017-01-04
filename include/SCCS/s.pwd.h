h35063
s 00004/00000/00015
d R 4.2 83/12/02 16:31:31 ralph 2 1
c new getpwnam and getpwuid which need ndbm.h
e
s 00015/00000/00000
d D 4.1 83/05/03 13:48:10 sam 1 0
c date and time created 83/05/03 13:48:10 by sam
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

struct	passwd { /* see getpwent(3) */
	char	*pw_name;
	char	*pw_passwd;
	int	pw_uid;
	int	pw_gid;
	int	pw_quota;
	char	*pw_comment;
	char	*pw_gecos;
	char	*pw_dir;
	char	*pw_shell;
};

struct passwd *getpwent(), *getpwuid(), *getpwnam();
E 1
