extern char	xstr[];
#line 1 "printf.c"







static char *sccsid = (&xstr[8189]);

static char *printf_id = (&xstr[8225]);



#line 1 "/usr/include/sys/types.h"























typedef	unsigned char	u_char;
typedef	unsigned short	u_short;
typedef	unsigned int	u_int;
typedef	unsigned long	u_long;
typedef	unsigned short	ushort;		


typedef	struct	_physadr { int r[1]; } *physadr;
typedef	struct	label_t	{
	int	val[14];
} label_t;

typedef	struct	_quad { long val[2]; } quad;
typedef	long	daddr_t;
typedef	char *	caddr_t;
typedef	long *	qaddr_t;	
typedef	u_long	ino_t;
typedef	long	swblk_t;
typedef	long	size_t;
typedef	long	time_t;
typedef	short	dev_t;
typedef	long	off_t;
typedef	u_short	uid_t;
typedef	u_short	gid_t;












typedef long	fd_mask;





typedef	struct fd_set {
	fd_mask	fds_bits[	(((256)+(( (sizeof(fd_mask) * 8		)	)-1))/( (sizeof(fd_mask) * 8		)	))];
} fd_set;







#line 14 "printf.c"

#line 1 "/usr/include/varargs.h"


typedef char *va_list;




#line 15 "printf.c"
 













static int width, sign, fill;

u_char *_p_dconv();


ex_printf(va_alist)
	int va_alist;
{
	va_list ap;
	register u_char *fmt;
	u_char fcode;
	int prec;
	int length,mask1,nbits,n;
	long int mask2, num;
	register u_char *bptr;
	u_char *ptr;
	u_char buf[134];

	 ap = (char *) &va_alist;
	fmt =  ((u_char * *)(ap += sizeof(u_char *)))[-1];
	for (;;) {
		
		while ((fcode = *fmt++)!='%') {
			
			if (fcode=='\0')
				return;
			ex_putchar(fcode);
		}
		
		length = 0;
		
		sign = 0;
		if (*fmt == '-') {
			sign++;
			fmt++;
		}
		
		
		fill = 1;
		if (*fmt == '0') {
			fill--;
			fmt++;
		}
		
		
		if (*fmt == '*') {
			width =  (( int *)(ap += sizeof( int)))[-1];
			if (width < 0) {
				width = -width;
				sign = !sign;
			}
			fmt++;
		}
		else {
			width = 0;
			while (*fmt>='0' && *fmt<='9')
				width = width * 10 + (*fmt++ - '0');
		}
		
		
		if (*fmt=='.') {
			if (*++fmt == '*') {
				prec =  (( int *)(ap += sizeof( int)))[-1];
				fmt++;
			}
			else {
				prec = 0;
				while (*fmt>='0' && *fmt<='9')
					prec = prec * 10 + (*fmt++ - '0');
			}
		}
		else
			prec = -1;
		
		









		switch (*fmt) {
			case 'L':
			case 'l':
				length = 2;
				
			case 'h':
			case 'H':
				length--;
				fmt++;
				break;
		}
		
		




		switch (fcode = *fmt++) {
			
			case 'c':
				buf[0] =  (( int *)(ap += sizeof( int)))[-1];
				ptr = bptr = &buf[0];
				if (buf[0] != '\0')
					ptr++;
				break;
			case 's':
				bptr =  ((u_char * *)(ap += sizeof(u_char *)))[-1];
				if (bptr==0)
					bptr = (&xstr[8250]);
				if (prec < 0)
					prec = 32767	;
				for (n=0; *bptr++ && n < prec; n++) ;
				ptr = --bptr;
				bptr -= n;
				break;
			case 'O':
				length = 1;
				fcode = 'o';
				
			case 'o':
			case 'X':
			case 'x':
				if (length > 0)
					num =  ((long *)(ap += sizeof(long)))[-1];
				else
					num = (unsigned) ((int *)(ap += sizeof(int)))[-1];
				if (fcode=='o') {
					mask1 = 0x7;
					mask2 = 0x1fffffffL;
					nbits = 3;
				}
				else {
					mask1 = 0xf;
					mask2 = 0x0fffffffL;
					nbits = 4;
				}
				n = (num!=0);
				bptr = buf + 11	 + 3;
				
				do
				    if (((int) num & mask1) < 10)
					*--bptr = ((int) num & mask1) + 060;
				    else
					*--bptr = ((int) num & mask1) + 0127;
				while (num = (num >> nbits) & mask2);
				
				if (fcode=='o') {
					if (n)
						*--bptr = '0';
				}
				else
					if (!sign && fill <= 0) {
						ex_putchar('0');
						ex_putchar(fcode);
						width -= 2;
					}
					else {
						*--bptr = fcode;
						*--bptr = '0';
					}
				ptr = buf + 11	 + 3;
				break;
			case 'D':
			case 'U':
			case 'I':
				length = 1;
				fcode = fcode + 'a' - 'A';
				
			case 'd':
			case 'i':
			case 'u':
				if (length > 0)
					num =  ((long *)(ap += sizeof(long)))[-1];
				else {
					n =  ((int *)(ap += sizeof(int)))[-1];
					if (fcode=='u')
						num = (unsigned) n;
					else
						num = (long) n;
				}
				if (n = (fcode != 'u' && num < 0))
					num = -num;
				
				bptr = _p_dconv(num, buf);
				if (n)
					*--bptr = '-';
				if (fill == 0)
					fill = -1;
				ptr = buf + 10	 + 1;
				break;
			default:
				


				ptr = bptr = &fcode;
				ptr++;
				break;
			}
			if (fcode != '\0')
				_p_emit(bptr,ptr);
	}
	;
}











u_char *
_p_dconv(value, buffer)
	long value;
	u_char *buffer;
{
	register u_char *bp;
	register int svalue;
	int n;
	long lval;
	
	bp = buffer;
	
	
	if (value == 0) {
		bp += 10	;
		*bp = '0';
		return(bp);
	}
	
	
	n = 0;
	while (value < 0) {
		value -= 1000000000  ;	
		n++;
	}
	while ((lval = value - 1000000000  ) >= 0) {
		value = lval;
		n++;
	}
	
	
	bp[1] = n + '0';
	





	bp += 10	 + 1;
	while (value > 32767	) {
		*--bp = (int)(value % 10) + '0';
		value /= 10;
	}
	
	
	svalue = value;
	while (svalue > 0) {
		*--bp = (svalue % 10) + '0';
		svalue /= 10;
	}
	
	
	if (buffer[1] != '0') {
		while (bp > buffer + 2)
			*--bp = '0';
		--bp;
	}
	return(bp);
}













_p_emit(s, send)
	register u_char *s;
	u_char *send;
{
	u_char cfill;
	register int alen;
	int npad;
	
	alen = send - s;
	if (alen > width)
		width = alen;
	cfill = fill>0? ' ': '0';
	
	
	if (*s == '-' && fill < 0) {
		ex_putchar(*s++);
		alen--;
		width--;
	}
	npad = width - alen;
	
	
	if (!sign)
		while (--npad >= 0)
			ex_putchar(cfill);
			
	
	while (--alen >= 0)
		ex_putchar(*s++);
		
	
	if (sign)
		while (--npad >= 0)
			ex_putchar(cfill);
}
