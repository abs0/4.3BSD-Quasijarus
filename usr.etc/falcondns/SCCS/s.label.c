h54392
s 00002/00002/00238
d D 1.7 2013/01/06 08:30:35 msokolov 7 6
c preparations for librification:
c s/store_label_casepreserve/copy_label_casepreserve/
c s/store_label_can/copy_label_can/
e
s 00011/00000/00229
d D 1.6 2011/10/29 05:41:43 msokolov 6 5
c label_match_casesen() added, used for compression trees
e
s 00047/00000/00182
d D 1.5 2011/07/18 00:21:47 msokolov 5 4
c label and dname printing functions
e
s 00040/00000/00142
d D 1.4 2011/07/17 00:38:21 msokolov 4 3
c label case handling rethought slightly
e
s 00050/00000/00092
d D 1.3 2011/07/14 07:03:12 msokolov 3 2
c node_findchild()/node_addchild() magic implemented
e
s 00002/00000/00090
d D 1.2 2011/07/14 00:26:29 msokolov 2 1
c store_label_in_node: support root as well
e
s 00090/00000/00000
d D 1.1 2011/07/13 22:05:22 msokolov 1 0
c date and time created 2011/07/13 22:05:22 by msokolov
e
u
U
t
T
I 1
/*
 * Operations on individual domain labels
 */

#ifndef lint
static char sccsid[] = "%W% (IFCTF) %E%";
#endif

#include <sys/types.h>
#include <arpa/nameser.h>
I 5
#include <stdio.h>
E 5
#include "tree.h"

static u_char labuctab[256] = {
	'\000', '\001', '\002', '\003', '\004', '\005', '\006', '\007',
	'\010', '\011', '\012', '\013', '\014', '\015', '\016', '\017',
	'\020', '\021', '\022', '\023', '\024', '\025', '\026', '\027',
	'\030', '\031', '\032', '\033', '\034', '\035', '\036', '\037',
	'\040', '\041', '\042', '\043', '\044', '\045', '\046', '\047',
	'\050', '\051', '\052', '\053', '\054', '\055', '\056', '\057',
	'\060', '\061', '\062', '\063', '\064', '\065', '\066', '\067',
	'\070', '\071', '\072', '\073', '\074', '\075', '\076', '\077',
	'\100', '\101', '\102', '\103', '\104', '\105', '\106', '\107',
	'\110', '\111', '\112', '\113', '\114', '\115', '\116', '\117',
	'\120', '\121', '\122', '\123', '\124', '\125', '\126', '\127',
	'\130', '\131', '\132', '\133', '\134', '\135', '\136', '\137',
	'\140', '\101', '\102', '\103', '\104', '\105', '\106', '\107',
	'\110', '\111', '\112', '\113', '\114', '\115', '\116', '\117',
	'\120', '\121', '\122', '\123', '\124', '\125', '\126', '\127',
	'\130', '\131', '\132', '\173', '\174', '\175', '\176', '\177',
	'\200', '\201', '\202', '\203', '\204', '\205', '\206', '\207',
	'\210', '\211', '\212', '\213', '\214', '\215', '\216', '\217',
	'\220', '\221', '\222', '\223', '\224', '\225', '\226', '\227',
	'\230', '\231', '\232', '\233', '\234', '\235', '\236', '\237',
	'\240', '\241', '\242', '\243', '\244', '\245', '\246', '\247',
	'\250', '\251', '\252', '\253', '\254', '\255', '\256', '\257',
	'\260', '\261', '\262', '\263', '\264', '\265', '\266', '\267',
	'\270', '\271', '\272', '\273', '\274', '\275', '\276', '\277',
	'\300', '\301', '\302', '\303', '\304', '\305', '\306', '\307',
	'\310', '\311', '\312', '\313', '\314', '\315', '\316', '\317',
	'\320', '\321', '\322', '\323', '\324', '\325', '\326', '\327',
	'\330', '\331', '\332', '\333', '\334', '\335', '\336', '\337',
	'\340', '\341', '\342', '\343', '\344', '\345', '\346', '\347',
	'\350', '\351', '\352', '\353', '\354', '\355', '\356', '\357',
	'\360', '\361', '\362', '\363', '\364', '\365', '\366', '\367',
	'\370', '\371', '\372', '\373', '\374', '\375', '\376', '\377'};

label_match(l1, l2)
	register u_char *l1, *l2;
{
	int len;
	register int i;

	len = *l1++;
	if (len != *l2++)
		return(0);
	for (i = 0; i < len; i++)
		if (labuctab[*l1++] != labuctab[*l2++])
			return(0);
	return(1);
}

I 6
label_match_casesen(l1, l2)
	register u_char *l1, *l2;
{
	register int len;

	len = *l1++;
	if (len != *l2++)
		return(0);
	return(!bcmp(l1, l2, len));
}

E 6
label_match_can(ext, ref)
	register u_char *ext, *ref;
{
	int len;
	register int i;

	len = *ext++;
	if (len != *ref++)
		return(0);
	for (i = 0; i < len; i++)
		if (labuctab[*ext++] != *ref++)
			return(0);
	return(1);
}

I 4
label_match_node(ext, n)
	register u_char *ext;
	register struct node *n;
{
	int len;
	register int i;

	len = *ext++;
	if (len != n->n_labellen)
		return(0);
	for (i = 0; i < len; i++)
		if (labuctab[*ext++] != n->n_label_uc[i])
			return(0);
	return(1);
}

E 4
store_label_in_node(lab, n)
	register u_char *lab;
	struct node *n;
{
	register u_char *dp;
	register int len;

	len = *lab++;
	n->n_labellen = len;
I 2
	if (!len)
		return;
E 2
	bcopy(lab, n->n_label_cp, len);
	dp = n->n_label_uc;
I 4
	while (len--)
		*dp++ = labuctab[*lab++];
}

D 7
store_label_casepreserve(lab, dest)
E 7
I 7
copy_label_casepreserve(lab, dest)
E 7
	register u_char *lab, *dest;
{
	register int len;

	len = *lab++;
	*dest++ = len;
	bcopy(lab, dest, len);
}

D 7
store_label_can(lab, dest)
E 7
I 7
copy_label_can(lab, dest)
E 7
	register u_char *lab;
	u_char *dest;
{
	register u_char *dp;
	register int len;

	len = *lab++;
	dp = dest;
	*dp++ = len;
E 4
	while (len--)
		*dp++ = labuctab[*lab++];
}
I 3

/*
 * Hash function taken from 4.3BSD ndbm.
 */
static  int hitab[16]
 = {    61, 57, 53, 49, 45, 41, 37, 33,
	29, 25, 21, 17, 13,  9,  5,  1,
};
static  long hltab[64]
 = {
	06100151277L,06106161736L,06452611562L,05001724107L,
	02614772546L,04120731531L,04665262210L,07347467531L,
	06735253126L,06042345173L,03072226605L,01464164730L,
	03247435524L,07652510057L,01546775256L,05714532133L,
	06173260402L,07517101630L,02431460343L,01743245566L,
	00261675137L,02433103631L,03421772437L,04447707466L,
	04435620103L,03757017115L,03641531772L,06767633246L,
	02673230344L,00260612216L,04133454451L,00615531516L,
	06137717526L,02574116560L,02304023373L,07061702261L,
	05153031405L,05322056705L,07401116734L,06552375715L,
	06165233473L,05311063631L,01212221723L,01052267235L,
	06000615237L,01075222665L,06330216006L,04402355630L,
	01451177262L,02000133436L,06025467062L,07121076461L,
	03123433522L,01010635225L,01716177066L,05161746527L,
	01736635071L,06243505026L,03637211610L,01756474365L,
	04723077174L,03642763134L,05750130273L,03655541561L,
};

long
label_hash(label)
	u_char *label;
{
	register int s, c;
	register u_char *cp;
	register long hashl;
	register int hashi;

	hashl = 0;
	hashi = 0;
	cp = label;
	s = *cp++;
	while (--s >= 0) {
		c = labuctab[*cp++];
		hashi += hitab[c&017];
		hashl += hltab[hashi&63];
		hashi += hitab[c>>4];
		hashl += hltab[hashi&63];
	}
	return (hashl);
I 5
}

static char labchartab[256] = {
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};

void
print_label(lab, f)
	register u_char *lab;
	register FILE *f;
{
	register int c, i;
	int lablen;

	lablen = *lab++;
	if (!lablen) {
		putc('.', f);
		return;
	}
	for (i = 0; i < lablen; i++) {
		c = *lab++;
		switch (labchartab[c]) {
		case 1:
			putc('\\', f);
			/*FALLTHRU*/
		case 0:
			putc(c, f);
			break;
		default:
			fprintf(f, "\\%03d", c);
		}
	}
E 5
}
E 3
E 1
