h52822
s 00001/00000/00137
d D 1.12 85/10/18 18:41:54 mckusick 13 12
c one more field that needs to be initialized
e
s 00004/00002/00133
d D 1.11 83/01/22 01:04:26 mckusick 12 11
c sort dynamic files only within GLVL files on fchain
e
s 00001/00001/00134
d D 1.10 83/01/21 18:58:22 mckusick 11 10
c fix for prematurely removing temp files
e
s 00026/00035/00109
d D 1.9 82/08/29 21:32:57 mckusick 10 9
c remove restriction on files in dynamic structures
e
s 00012/00006/00132
d D 1.8 81/11/23 22:48:31 mckusic 9 8
c check for internal file table overflow
e
s 00003/00001/00135
d D 1.7 81/11/22 16:33:15 mckusic 8 7
c insure that temporary file names do not have unprintable names
e
s 00004/00004/00132
d D 1.6 81/06/10 00:38:00 mckusic 7 6
c move the text of error messages from ERROR to the functions
c which generate them.
e
s 00008/00008/00128
d D 1.5 81/06/08 00:39:53 mckusic 6 5
c do not try to close or deallocate buffers for tmp files which
c are initially opened for reading (and hence do not exist)
e
s 00016/00017/00120
d D 1.4 81/05/07 18:54:15 mckusic 5 4
c fix naming of temporary files
e
s 00006/00007/00131
d D 1.3 81/03/07 15:56:33 mckusic 4 3
c merge in onyx changes
e
s 00004/00000/00134
d D 1.2 81/01/10 17:21:04 mckusic 3 1
c flush and release buffers before closing files
e
s 00002/00000/00134
d R 1.2 81/01/09 13:53:38 mckusic 2 1
c release buffers before closing files
e
s 00134/00000/00000
d D 1.1 80/10/30 00:33:25 mckusick 1 0
c date and time created 80/10/30 00:33:25 by mckusick
e
u
U
t
T
I 1
/* Copyright (c) 1979 Regents of the University of California */

static char sccsid[] = "%Z%%M% %I% %G%";

#include "h00vars.h"
I 10
#include "libpc.h"
E 10
D 7
#include "h01errs.h"
E 7

/*
 * GETNAME - activate a file
 *
 * takes a name, name length, element size, and variable
 * level and returns a pointer to a file structure.
 *
 * a new file structure is initialized if necessary.
 * temporary names are generated, and given
 * names are blank trimmed.
 */

I 9
static char *tmpname = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

E 9
struct iorec *
D 4
GETNAME(filep, name, maxnamlen, datasize)
E 4
I 4
GETNAME(filep, name, namlim, datasize)
E 4

	register struct iorec	*filep;
	char			*name;
D 4
	int			maxnamlen;
	int			datasize;
E 4
I 4
	long			namlim;
	long			datasize;
E 4
{
I 4
	int		maxnamlen = namlim;
E 4
	struct iorec	*prev;
	struct iorec	*next;
	register int	cnt;
	struct iorec	locvar;
D 5
	extern char	*mktemp();
E 5

D 10
	if (filep->fblk >= MAXFILES || _actfile[filep->fblk] != filep) {
E 10
I 10
	if (filep->fblk < MAXFILES && _actfile[filep->fblk] == filep) {
		/* 
		 * Close and immediately reactivate the file.
		 */
D 11
		PFCLOSE(filep);
E 11
I 11
		PFCLOSE(filep, name != NULL);
E 11
		_actfile[filep->fblk] = filep;
		filep->funit &= (TEMP | FTEXT);
	} else {
E 10
		/*
D 10
		 * initialize a new filerecord
E 10
I 10
		 * Initialize a new file record.
E 10
		 */
		filep->funit = 0;
		if (datasize == 0) {
			filep->funit |= FTEXT;
			datasize = 1;
		}
		filep->fsize = datasize;
		filep->fbuf = 0;
		filep->lcount = 0;
		filep->llimit = 0x7fffffff;
		filep->fileptr = &filep->window[0];
I 13
		*filep->fname = NULL;
E 13
		/*
D 10
		 * check to see if file is global, or allocated in
E 10
I 10
		 * Check to see if file is global, or allocated in
E 10
		 * the stack by checking its address against the
		 * address of one of our routine's local variables.
		 */
		if (filep < &locvar)
			filep->flev = GLVL;
		else
			filep->flev = filep;
D 9
		do {
			if (++_filefre == MAXFILES)
				_filefre = PREDEF + 1;
		} while (_actfile[_filefre] != FILNIL);
E 9
I 9
		for (_filefre++; _filefre < MAXFILES; _filefre++)
			if (_actfile[_filefre] == FILNIL)
				goto gotone;
		for (_filefre = PREDEF + 1; _filefre < MAXFILES; _filefre++)
			if (_actfile[_filefre] == FILNIL)
				goto gotone;
		ERROR("File table overflow\n");
		return;
gotone:
E 9
		filep->fblk = _filefre;
		_actfile[_filefre] = filep;
		/*
D 10
		 * link the newrecord into the file chain
E 10
I 10
D 12
		 * Link the newrecord into the file chain.
E 12
I 12
		 * Link the new record into the file chain.
E 12
E 10
		 */
		prev = (struct iorec *)&_fchain;
		next = _fchain.fchain;
		while (filep->flev > next->flev) {
			prev = next;
			next = next->fchain;
		}
D 10
		filep->fchain = next;
		prev->fchain = filep;
	} else {
D 4
		if (filep->funit & FDEF) {
			filep->funit &= (TEMP | FTEXT);
		} else {
E 4
I 4
D 6
		if ((filep->funit & FDEF) == 0) {
E 6
I 6
		if ((filep->funit & FDEF) == 0 && filep->fbuf != NULL) {
E 10
I 10
		if (filep->flev == GLVL)
E 10
E 6
E 4
			/*
D 10
			 * have a previous buffer, close associated file
E 10
I 10
			 * Must order global files so that all dynamic files
			 * within a record are grouped together.
E 10
			 */
I 3
D 10
			if (filep->fblk > PREDEF) {
				fflush(filep->fbuf);
				setbuf(filep->fbuf, NULL);
E 10
I 10
D 12
			while (next != FILNIL && (struct iorec *)filep > next) {
E 12
I 12
			while ((next != FILNIL) &&
			       (next->flev == GLVL) &&
			       ((struct iorec *)filep > next)) {
E 12
				prev = next;
				next = next->fchain;
E 10
			}
E 3
D 10
			fclose(filep->fbuf);
			if (ferror(filep->fbuf)) {
D 7
				ERROR(ECLOSE, filep->pfname);
E 7
I 7
				ERROR("%s: Close failed\n", filep->pfname);
E 7
				return;
			}
			/*
			 * renamed temporary files are discarded
			 */
D 6
			if ((filep->funit & TEMP) &&
			    (name != NULL) &&
			    (unlink(filep->pfname))) {
				ERROR(EREMOVE, filep->pfname);
				return;
E 6
I 6
			if ((filep->funit & TEMP) && name != NULL) {
			    	if (unlink(filep->pfname)) {
D 7
					ERROR(EREMOVE, filep->pfname);
E 7
I 7
					PERROR("Could not remove ",
						filep->pfname);
E 7
					return;
				}
E 6
			}
D 4
			filep->funit &= (TEMP | FTEXT);
E 4
		}
I 4
		filep->funit &= (TEMP | FTEXT);
E 10
I 10
		filep->fchain = next;
		prev->fchain = filep;
E 10
E 4
	}
	/*
D 10
	 * get the filename associated with the buffer
E 10
I 10
	 * Get the filename associated with the buffer.
E 10
	 */
	if (name == NULL) {
		if (*filep->fname != NULL) {
			return(filep);
		}
		/*
D 10
		 * no name given and no previous name, so generate
D 6
		 * a new one of the form tmp.xxxxxx
E 6
I 6
		 * a new one of the form #tmp.xxxxxx
E 10
I 10
		 * No name given and no previous name, so generate
		 * a new one of the form #tmp.xxxxxx.
E 10
E 6
		 */
		filep->funit |= TEMP;
D 5
		name = mktemp("tmp.XXXXXX");
		maxnamlen = 10;
	} else {
		/*
		 * trim trailing blanks, and insure that the name 
		 * will fit into the file structure
		 */
		for (cnt = 0; cnt < maxnamlen; cnt++)
			if (name[cnt] == '\0' || name[cnt] == ' ')
				break;
		if (cnt >= NAMSIZ) {
			ERROR(ENAMESIZE, name);
			return;
		}
		maxnamlen = cnt;
		filep->funit &= ~TEMP;
E 5
I 5
D 6
		sprintf(filep->fname, "tmp.%c%d", 'a' + filep->fblk, getpid());
E 6
I 6
D 8
		sprintf(filep->fname, "#tmp.%c%d", 'a' + filep->fblk, getpid());
E 8
I 8
D 9
		sprintf(filep->fname, "#tmp.%c%d", filep->fblk <= 'z' - 'a' + 1
		    ? 'a' + filep->fblk : 'A' + filep->fblk - ('z' - 'a' + 1),
E 9
I 9
		sprintf(filep->fname, "#tmp.%c%d", tmpname[filep->fblk],
E 9
		    getpid());
E 8
E 6
		filep->pfname = &filep->fname[0];
		return(filep);
E 5
	}
I 5
	/*
D 10
	 * trim trailing blanks, and insure that the name 
	 * will fit into the file structure
E 10
I 10
	 * Trim trailing blanks, and insure that the name 
	 * will fit into the file structure.
E 10
	 */
	for (cnt = 0; cnt < maxnamlen; cnt++)
		if (name[cnt] == '\0' || name[cnt] == ' ')
			break;
	if (cnt >= NAMSIZ) {
D 7
		ERROR(ENAMESIZE, name);
E 7
I 7
		ERROR("%s: File name too long\n", name);
E 7
		return;
	}
	maxnamlen = cnt;
	filep->funit &= ~TEMP;
E 5
	/*
D 10
	 * put the new name into the structure
E 10
I 10
	 * Put the new name into the structure.
E 10
	 */
	for (cnt = 0; cnt < maxnamlen; cnt++)
		filep->fname[cnt] = name[cnt];
	filep->fname[cnt] = '\0';
	filep->pfname = &filep->fname[0];
	return(filep);
}
E 1
