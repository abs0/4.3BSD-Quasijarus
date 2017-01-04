h20674
s 00010/00000/00000
d D 4.1 83/05/03 13:47:59 sam 1 0
c date and time created 83/05/03 13:47:59 by sam
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

struct	group { /* see getgrent(3) */
	char	*gr_name;
	char	*gr_passwd;
	int	gr_gid;
	char	**gr_mem;
};

struct group *getgrent(), *getgrgid(), *getgrnam();
E 1
