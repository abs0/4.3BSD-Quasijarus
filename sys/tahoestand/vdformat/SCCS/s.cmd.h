h00738
s 00030/00000/00000
d D 1.1 86/07/05 17:37:32 sam 1 0
c date and time created 86/07/05 17:37:32 by sam
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

#define	QUIT	-1

typedef struct {
	int	cmd_token;
	char	*cmd_text;
	char	*cmd_help;
} cmd_text_element;

typedef struct {
	int	cmd_min;
	int	cmd_max;
} cmd_digit_element;

#define ismustmatch(c)	((((c)>' ')&&((c)<'a')) || (((c)>'z')&&((c)<='~')))
#define isupper(c)	(((c) >= 'A') && ((c) <= 'Z'))
#define islower(c)	(((c) >= 'a') && ((c) <= 'z'))
#define toupper(c)	(islower(c) ? ((c) & ~040) : c)
#define tolower(c)	(isupper(c) ? ((c) | 040) : c)


#define skipdigits(ptr)	while(is_digit(*ptr)) ptr++
#define skip_junk(ptr)	while(*ptr && !is_digit(*ptr) &&\
			    (*ptr != '-') && (*ptr != '~')) ptr++
#define is_digit(c)	(((c) >= '0') && ((c) <= '9'))
#define	finddigit(ptr)	while(*ptr && !is_digit(*ptr)) ptr++

#define trim_white(ptr) while((*ptr == ' ') || (*ptr == '\t')) ptr++

E 1
