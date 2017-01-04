h06954
s 00000/00000/00073
d D 4.2 83/04/26 01:19:31 mckusick 2 1
c 
e
s 00073/00000/00000
d D 4.1 83/04/26 01:18:13 mckusick 1 0
c date and time created 83/04/26 01:18:13 by mckusick
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W%	(Berkeley)	%G%";
#endif not lint

#include "stdio.h"
#include "lrnref.h"

char *
getlesson()
{
	register char *p;
	char ans[80], line[200];
	int isnum, found, fd[2];
	FILE *fp;

	sprintf(ans, "%s/%s/L%s", direct, sname, level);
	if (access(ans, 04) == 0)		/* there is a file */
		return(level);
	isnum = 1;
	for (p=level; *p; p++)		/* accept:  (digit|dot)*anychar  */
		if (*p != '.' && (*p < '0' || *p > '9') && *(p+1) != '\0')
			isnum = 0;
	if (isnum) {
		strcpy(line, level);
		p = level;
		while (*p != '.' && *p >= '0' && *p <= '9')
			p++;
		*p = '\0';
		strcat(level, ".1a");
		sprintf(ans, "%s/%s/L%s", direct, sname, level);
		if (access(ans, 04) == 0) {	/* there is a file */
			printf("There is no lesson %s; trying lesson %s instead.\n\n", line, level);
			return(level);
		}
		printf("There is no lesson %s.\n", line);
		return(0);
	}
	/* fgrep through lessons for one containing the string in 'level' */
	pipe(fd);
	if (fork() == 0) {
		close(fd[0]);
		dup2(fd[1], 1);
		sprintf(ans,"cd %s/%s ; fgrep '%s' L?.* L??.* L???.*", direct, sname, level);
		execl("/bin/csh", "csh", "-cf", ans, 0);
		perror("/bin/csh");
		fprintf(stderr, "Getlesson:  can't do %s\n", ans);
	}
	close(fd[1]);
	fp = fdopen(fd[0], "r");
	found = 0;
	while (fgets(line, 200, fp) != NULL) {
		for (p=line; *p != ':'; p++) ;
		p++;
		if (*p == '#')
			continue;
		else {
			found = 1;
			break;
		}
	}
	/*fclose(fp);*/
	if (found) {
		*--p = '\0';
		strcpy(level, &line[1]);
		sprintf(ans, "%s/%s/L%s", direct, sname, level);
		if (access(ans, 04) == 0) {	/* there is a file */
			printf("Trying lesson %s.\n\n", level);
			return(level);
		}
	}
	printf("There is no lesson containing \"%s\".\n", level);
	return(0);
}
E 1
