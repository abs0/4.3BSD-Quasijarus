h34271
s 00001/00002/00166
d D 4.2 86/03/04 13:47:27 mckusick 3 1
c Force the initialization of fd in all cases (from Keith Muller)
e
s 00167/00000/00000
d R 4.2 86/08/02 06:31:37 mckusick 2 1
c Force the initialization of fd in all cases (from Keith Muller)
e
s 00168/00000/00000
d D 4.1 83/05/06 23:47:27 tut 1 0
c date and time created 83/05/06 23:47:27 by tut
e
u
U
t
T
I 1
#ifndef lint
static char *sccsid = "%W% (Berkeley) %G%";
#endif

#include <stdio.h>
#include <assert.h>

main(argc, argv)
char *argv[];
{
	/* Make inverted file indexes.  Reads a stream from mkey which
	 * gives record pointer items and keys.  Generates set of files
	 *	a. NHASH pointers to file b.
	 *	b. lists of record numbers.
	 *	c. record pointer items.
	 *
	 *  these files are named xxx.ia, xxx.ib, xxx.ic;
	 *  where xxx is taken from arg1.
	 *  If the files exist they are updated.
	 */

	FILE *fa, *fb, *fc, *fta, *ftb, *ftc, *fd;
	int nhash = 256;
	int appflg = 1;
	int keepkey = 0, pipein = 0;
	char nma[100], nmb[100], nmc[100], com[100], nmd[100];
	char tmpa[20], tmpb[20], tmpc[20];
	char *remove = NULL;
	int chatty = 0, docs, hashes, fp[2], fr, fw, pfork, pwait, status;
	int i,j,k;
	long keys;
	int iflong =0;
	char *sortdir;

	sortdir = (access("/crp/tmp", 06)==0) ? "/crp/tmp" : "/usr/tmp";
	while (argv[1][0] == '-')
	{
		switch(argv[1][1])
		{
		case 'h': /* size of hash table */
			nhash = atoi (argv[1]+2); 
			break;
		case 'n': /* new, don't append */
			appflg=0; 
			break;
		case 'a': /* append to old file */
			appflg=1; 
			break;
		case 'v': /* verbose output */
			chatty=1; 
			break;
		case 'd': /* keep keys on file .id for check on searching */
			keepkey=1; 
			break;
		case 'p': /* pipe into sort (saves space, costs time)*/
			pipein = 1; 
			break;
		case 'i': /* input is on file, not stdin */
			close(0);
			if (open(argv[2], 0) != 0)
				err("Can't read input %s", argv[2]);
			if (argv[1][2]=='u') /* unlink */
				remove = argv[2];
			argc--; 
			argv++;
			break;
		}
		argc--;
		argv++;
	}
	strcpy (nma, argc >= 2 ? argv[1] : "Index");
	strcpy (nmb, nma);
	strcpy (nmc, nma);
	strcpy (nmd, nma);
	strcat (nma, ".ia");
	strcat (nmb, ".ib");
	strcat (nmc, ".ic");
	strcat (nmd, ".id");

	sprintf(tmpa, "junk%di", getpid());
	if (pipein)
	{
		pipe(fp); 
		fr=fp[0]; 
		fw=fp[1];
		if ( (pfork=fork()) == 0)
		{
			close(fw);
			close(0);
			_assert(dup(fr)==0);
			close(fr);
			execl("/bin/sort", "sort", "-T", sortdir, "-o", tmpa, 0);
			execl("/usr/bin/sort", "sort", "-T", sortdir, "-o", tmpa, 0);
			_assert(0);
		}
		_assert(pfork!= -1);
		close(fr);
		fta = fopen("/dev/null", "w");
		close(fta->_file);
		fta->_file = fw;
	}
	else /* use tmp file */
	{
		fta = fopen(tmpa, "w");
		_assert (fta != NULL);
	}
	fb = 0;
	if (appflg )
	{
		if (fb = fopen(nmb, "r"))
		{
			sprintf(tmpb, "junk%dj", getpid());
			ftb = fopen(tmpb, "w");
			if (ftb==NULL)
				err("Can't get scratch file %s",tmpb);
			nhash = recopy(ftb, fb, fopen(nma, "r"));
			fclose(ftb);
		}
		else
			appflg=0;
	}
	fc = fopen(nmc,  appflg ? "a" : "w");
D 3
	if (keepkey)
		fd = keepkey ? fopen(nmd, "w") : 0;
E 3
I 3
	fd = keepkey ? fopen(nmd, "w") : 0;
E 3
	docs = newkeys(fta, stdin, fc, nhash, fd, &iflong);
	fclose(stdin);
	if (remove != NULL)
		unlink(remove);
	fclose(fta);
	if (pipein)
	{
		pwait = wait(&status);
		printf("pfork %o pwait %o status %d\n",pfork,pwait,status);
		_assert(pwait==pfork);
		_assert(status==0);
	}
	else
	{
		sprintf(com, "sort -T %s %s -o %s", sortdir, tmpa, tmpa);
		system(com);
	}
	if (appflg)
	{
		sprintf(tmpc, "junk%dk", getpid());
		sprintf(com, "mv %s %s", tmpa, tmpc);
		system(com);
		sprintf(com, "sort -T %s  -m %s %s -o %s", sortdir,
		tmpb, tmpc, tmpa);
		system(com);
	}
	fta = fopen(tmpa, "r");
	fa = fopen(nma, "w");
	fb = fopen(nmb, "w");
	whash(fta, fa, fb, nhash, iflong, &keys, &hashes);
	fclose(fta);
# ifndef D1
	unlink(tmpa);
# endif
	if (appflg)
	{
		unlink(tmpb);
		unlink(tmpc);
	}
	if (chatty)

		printf ("%ld key occurrences,  %d hashes, %d docs\n",
		keys, hashes, docs);
}
E 1
