h48611
s 00002/00002/00120
d D 1.2 2011/12/28 04:42:54 msokolov 2 1
c s/store/copy/
e
s 00122/00000/00000
d D 1.1 2011/12/27 02:01:51 msokolov 1 0
c beginning of libmsdns
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

/*
 * Per RFC 1035, a domain name label may legally contain ANY binary octets,
 * but those octets which correspond to ASCII letters are to be compared
 * in a case-insensitive manner.  The following table maps lowercase ASCII
 * letters to uppercase while leaving all other possible binary octets
 * undisturbed.
 */

u_char dns_label_uc_table[256] = {
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

/*
 * The table bore the shorter name labuctab before libmsdns was
 * factored out of the core MSDNS daemon.
 */
#define	labuctab	dns_label_uc_table

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

label_match_casesen(l1, l2)
	register u_char *l1, *l2;
{
	register int len;

	len = *l1++;
	if (len != *l2++)
		return(0);
	return(!bcmp(l1, l2, len));
}

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

D 2
store_label_casepreserve(lab, dest)
E 2
I 2
copy_label_casepreserve(lab, dest)
E 2
	register u_char *lab, *dest;
{
	register int len;

	len = *lab++;
	*dest++ = len;
	bcopy(lab, dest, len);
}

D 2
store_label_can(lab, dest)
E 2
I 2
copy_label_can(lab, dest)
E 2
	register u_char *lab;
	u_char *dest;
{
	register u_char *dp;
	register int len;

	len = *lab++;
	dp = dest;
	*dp++ = len;
	while (len--)
		*dp++ = labuctab[*lab++];
}
E 1
