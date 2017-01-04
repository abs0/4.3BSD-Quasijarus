h34524
s 00000/00004/00295
d D 4.2 83/11/13 19:35:34 eric 19 18
m 
c Don't print "Cannot open /dev/console" without trying if #define DEBUG
e
s 00000/00000/00299
d D 4.1 83/07/25 19:07:09 eric 18 17
m 
c 4.2 release version
e
s 00001/00001/00298
d D 2.15 82/12/16 10:15:21 sam 17 16
m 
c port numbers now returned byte swapped
e
s 00044/00001/00255
d D 2.14 82/12/13 17:27:23 eric 16 15
x 15
m 085
c NEW-IPC: convert to 4.1c
e
s 00010/00000/00256
d D 2.13 82/11/21 15:31:32 eric 15 14
m 085
c First part of 4.1c conversion
e
s 00007/00006/00249
d D 2.12 82/11/02 20:03:35 eric 14 13
c fixes to clean up operation when not in LOG_IPC mode
e
s 00013/00013/00242
d D 2.11 82/10/13 21:27:37 eric 13 12
c make logging host selectable (LOG_HOST)
e
s 00001/00001/00254
d D 2.10 82/08/20 20:32:37 eric 12 11
c increase size of output buffer to 1000 characters
e
s 00064/00026/00191
d D 2.9 82/08/20 20:30:51 eric 11 10
c work under IPC using datagrams
e
s 00008/00000/00209
d D 2.8 81/10/17 15:59:48 eric 10 9
c throw away non-critical messages if /dev/log does not exist
e
s 00004/00000/00205
d D 2.7 81/09/24 09:33:07 eric 9 8
c add V6 compile flags
e
s 00007/00002/00198
d D 2.6 81/09/22 10:43:17 eric 8 7
c be better about breaking long entries into lines -- still
c doesn't really work right though.
e
s 00000/00000/00200
d D 2.5 81/05/17 20:14:28 eric 7 5
i 6
c be more careful about opening /dev/log
e
s 00013/00000/00180
d D 2.1.1.1 81/05/17 20:13:38 eric 6 2
c be more careful about opening /dev/log
e
s 00003/00000/00184
d D 2.4 81/02/28 11:52:36 eric 5 4
c add id keywords
e
s 00004/00000/00180
d D 2.3 81/02/28 11:51:19 eric 4 3
c set FIOCLEX mode on syslog file
e
s 00002/00002/00178
d D 2.2 81/02/07 20:33:24 eric 3 2
c change name from logmsg to syslog
e
s 00095/00225/00085
d D 2.1 81/01/04 19:02:31 eric 2 1
c conversion for VAX/V7 (mpx files)
e
s 00310/00000/00000
d D 1.1 81/01/02 23:44:11 eric 1 0
c date and time created 81/01/02 23:44:11 by eric
e
u
U
f b 
f i 
f v 
t
T
I 1
D 2
# include	<log.h>
E 2
I 2
# include	<syslog.h>
D 11
# include	<stdio.h>
E 11
I 6
# include	<sys/types.h>
# include	<sys/stat.h>
I 9
D 11
# ifndef V6
E 9
E 6
I 4
# include	<sys/ioctl.h>
I 9
# endif V6
E 11
I 11
# include	<sgtty.h>
D 13
# ifdef IPCSYSLOG
E 13
I 13
# ifdef LOG_IPC
E 13
D 16
# include	<net/in.h>
E 16
# include	<sys/socket.h>
I 16
#ifdef LOG_OLDIPC
# include	<net/in.h>
#else LOG_OLDIPC
# include	<netinet/in.h>
# include	<netdb.h>
#endif LOG_OLDIPC
E 16
D 13
# endif IPCSYSLOG
E 13
I 13
# endif LOG_IPC
E 13
E 11
E 9
E 4

I 5
D 11
static char	SccsId[] =	"%W%	%G%";
E 11
I 11
static char	SccsId[] =	"%W%	%Y%	%G%";
E 11


E 5
E 2
/*
D 3
**  LOGMSG -- print message on log file
E 3
I 3
**  SYSLOG -- print message on log file
E 3
**
**	This routine looks a lot like printf, except that it
**	outputs to the log file instead of the standard output.
**	Also, it prints the module name in front of lines,
**	and has some other formatting types (or will sometime).
**	Also, it adds a newline on the end of messages.
**
**	The output of this routine is intended to be read by
**	/etc/syslog, which will add timestamps.
**
**	Parameters:
**		pri -- the message priority.
**		fmt -- the format string.
D 2
**		p0 -- the first parameter (it will take others).
E 2
I 2
**		p0 -- the first of many parameters.
E 2
**
**	Returns:
**		none
**
**	Side Effects:
**		output to log.
D 2
**
**	Defines:
**		log
**		logcvt -- numeric output conversion.
**		LogFile -- the file descriptor for the log file.
**		LogTag -- the module name for printing.
**
**	Requires:
**		LogFile must be opened for the /dev/log file.
**
**	History:
**		9/25/79 (eric) written.
E 2
*/

I 8
D 12
# define MAXLINE	100
E 12
I 12
D 14
# define MAXLINE	1000
E 12
# define BUFSLOP	20
E 14
I 14
# define MAXLINE	1000		/* maximum line length */
# define BUFSLOP	20		/* space to allow for "extra stuff" */
# define NULL		0		/* manifest */
E 14

E 8
D 2
int	LogFile		2;
int	LogStat		0;
char	*LogTag;
E 2
I 2
D 11
FILE	*LogFile =	NULL;
E 11
I 11
D 14
int	LogFile =	-1;
E 11
int	LogStat	=	0;
D 11
char	*LogTag =	NULL;
E 11
I 11
char	*LogTag =	0;
E 11
I 10
int	LogMask =	LOG_DEBUG;
E 14
I 14
int	LogFile =	-1;		/* fd for log */
int	LogStat	=	0;		/* status bits, set by initlog */
char	*LogTag =	NULL;		/* string to tag the entry with */
int	LogMask =	LOG_DEBUG;	/* lowest priority to be logged */
E 14
E 10
E 2

D 3
logmsg(pri, fmt, p0)
E 3
I 3
D 11
syslog(pri, fmt, p0)
E 11
I 11
D 13
# ifdef IPCSYSLOG
E 13
I 13
# ifdef LOG_IPC
I 16
#ifndef LOG_OLDIPC
struct sockaddr_in	SyslogAddr;
#else LOG_OLDIPC
E 16
E 13
struct sockaddr_in	SyslogAddr =	{ AF_INET, LOG_PORT };
struct sockproto	SyslogProto =	{ PF_INET, IPPROTO_UDP };
I 16
#endif LOG_OLDIPC
E 16
D 13
static char		*LocalHost =	"localhost";
# endif IPCSYSLOG
E 13
I 13
static char		*SyslogHost =	LOG_HOST;
# endif LOG_IPC
E 13

syslog(pri, fmt, p0, p1, p2, p3, p4)
E 11
E 3
	int	pri;
	char	*fmt;
D 2
	char	*p0;
E 2
{
D 2
	char		**pv;
E 2
D 8
	char		buf[300];
E 8
I 8
	char		buf[MAXLINE+BUFSLOP];
E 8
	register char	*b;
	char		*f;
	int		prec;
	int		len;
	register char	c;
	register char	*p;
	int		i;
	extern int	errno;
	extern int	sys_nerr;
	extern char	*sys_errlist[];
	extern char	*logcvt();
I 11
	char		outline[MAXLINE + 1];
E 11

D 2
	/* if we have no log, don't bother */
	if (LogFile < 0)
		return;
E 2
I 2
	/* if we have no log, open it */
D 11
	if (LogFile == NULL)
		openlog(NULL, 0);
E 11
I 11
	if (LogFile < 0)
		openlog(0, 0);
E 11
E 2

I 10
	/* see if we should just throw out this message */
	if (pri > LogMask)
		return;

E 10
D 8
	b = buf;
E 8
	f = fmt;
D 2
	pv = &p0;
	*b++ = '\n';
E 2

D 2
	while ((c = *f++) != '\0')
E 2
I 2
	while (*f != '\0')
E 2
	{
D 2
		/* output module name if new line */
		if (b[-1] == '\n')
E 2
I 2
		/* beginning of line */
I 8
		b = buf;
I 10

		/* insert priority code */
E 10
E 8
		if (pri > 0 && (LogStat & LOG_COOLIT) == 0)
E 2
		{
D 2
			/* output old line if any */
			if (b > &buf[1])
			{
				log_write(&buf[1], b - buf - 1);
				b = &buf[1];
			}

			/* arrange the priority stamp */
			if (pri > 0 && (LogStat & LOG_COOLIT) == 0)
			{
				*b++ = '<';
				*b++ = pri + '0';
				*b++ = '>';
			}

			/* output current process ID */
			if ((LogStat & LOG_PID) != 0)
			{
				for (p = logcvt(getpid(), 10, 5); *p != '\0'; )
					*b++ = *p++;
				*b++ = ' ';
			}

			/* and module name */
			if (LogTag != 0)
			{
				for (p = LogTag; *p != '\0'; )
					*b++ = *p++;
				*b++ = ':';
				*b++ = ' ';
			}
E 2
I 2
			*b++ = '<';
			*b++ = pri + '0';
			*b++ = '>';
E 2
		}

D 2
		/* output character directly if not interpolated */
		if (c != '%')
E 2
I 2
		/* output current process ID */
		if ((LogStat & LOG_PID) != 0)
E 2
		{
D 2
			*b++ = c;
			continue;
E 2
I 2
			sprintf(b, "%d ", getpid());
			b += strlen(b);
E 2
		}

D 2
		/* collect string length and precision */
		len = 0;
		while ((c = *f++) >= '0' && c <= '9')
			len = len * 10 + (c - '0');
		prec = 0;
		if (c == '.')
			while ((c = *f++) >= '0' && c <= '9')
				prec = prec * 10 + (c - '0');
		else
			prec = 250;
		
		/* compute output string */
		p = 0;
		switch (c)
E 2
I 2
		/* and module name */
D 11
		if (LogTag != NULL)
E 11
I 11
		if (LogTag != 0)
E 11
E 2
		{
D 2
		  case 'd':
			p = logcvt(*pv++, 10, len);
			break;
		
		  case 'D':
			i = *pv++;
			p = locv(i, *pv++);
			break;
		
		  case 'o':
			p = logcvt(*pv++, 8, len);
			break;
		
		  case 'x':
			p = logcvt(*pv++, 16, len);
			break;
		
		  case 'c':
			c = *pv++;
			break;
		
		  case 's':
			p = *pv++;
			if (p == 0)
				p = "<null>";
			break;

		  case 'm':
			if (errno < 0 || errno >= sys_nerr)
				p = "<unknown error>";
			else
				p = sys_errlist[errno];
			break;
		
		  default:
			break;
		
E 2
I 2
			for (p = LogTag; *p != '\0'; )
				*b++ = *p++;
			*b++ = ':';
			*b++ = ' ';
E 2
		}
D 2

		/* output string or character as appropriate */
		if (p != 0)
E 2
I 2
		while ((c = *f++) != '\0' && c != '\n')
E 2
		{
D 2
			for (i = 0; i < prec; i++)
E 2
I 2
			/* output character directly if not interpolated */
			if (c != '%')
E 2
			{
D 2
				if ((c = *p++) == '\0')
					break;
E 2
				*b++ = c;
I 2
				continue;
E 2
			}
D 2
			while (i < len)
				*b++ = ' ';
E 2
I 2
			c = *f++;
			switch (c)
			{
			  case 'm':	/* output error code */
				if (errno < 0 || errno > sys_nerr)
					sprintf(b, "error %d", errno);
				else
					sprintf(b, "%s", sys_errlist[errno]);
				break;

			  default:
				*b++ = '%';
				*b++ = c;
				*b = '\0';
				break;
			}
			b += strlen(b);
I 8
			if (b >= &buf[MAXLINE])
				break;
E 8
E 2
		}
D 2
		else if (c != '\0')
			*b++ = c;
	}
E 2
I 2
		if (c == '\0')
			f--;
E 2

D 2
	/* add trailing newline */
	if (b[-1] != '\n')
E 2
I 2
		/* add trailing newline */
E 2
		*b++ = '\n';
D 2
	
	/* output string */
	log_write(&buf[1], b - buf - 1);
E 2
I 2
		*b = '\0';
		
		/* output string */
D 11
		_doprnt(buf, &p0, LogFile);
		fflush(LogFile);
E 11
I 11
		sprintf(outline, buf, p0, p1, p2, p3, p4);
D 13
# ifdef IPCSYSLOG
E 13
I 13
# ifdef LOG_IPC
E 13
		if (LogStat & LOG_DGRAM)
		{
			register int r;

I 16
#ifndef LOG_OLDIPC
			r = sendto(LogFile, outline, strlen(outline), 0,
				   &SyslogAddr, sizeof SyslogAddr);
#else LOG_OLDIPC
E 16
I 15
#ifdef NVMUNIX
			r = sendto(LogFile, outline, strlen(outline),
				   &SyslogAddr, sizeof SyslogAddr);
#else NVMUNIX
E 15
			r = send(LogFile, &SyslogAddr, outline, strlen(outline));
I 16
#endif LOG_OLDIPC
E 16
I 15
#endif NVMUNIX
E 15
# ifdef EBUG
			if (r < 0)
				perror("syslog: send");
# endif EBUG
		}
		else
D 13
# endif IPCSYSLOG
E 13
I 13
# endif LOG_IPC
E 13
			write(LogFile, outline, strlen(outline));
E 11
	}
E 2
}
/*
D 2
**  LOG_WRITE -- write a line to the log file
E 2
I 2
**  OPENLOG -- open system log
E 2
**
D 2
**	This just does a physical write.
E 2
I 2
**	This happens automatically with reasonable defaults if you
**	do nothing.
E 2
**
**	Parameters:
D 2
**		buf -- the buffer address.
**		len -- the length.
E 2
I 2
**		ident -- the name to be printed as a header for
**			all messages.
**		logstat -- a status word, interpreted as follows:
**			LOG_PID -- log the pid with each message.
E 2
**
**	Returns:
D 2
**		none
E 2
I 2
**		0 -- success.
**		-1 -- failure; logging on /dev/console instead.
E 2
**
**	Side Effects:
D 2
**		none
**
**	Requires:
**		write (sys)
**
**	Called By:
**		log
E 2
I 2
**		Several global variables get set.
E 2
*/

D 2
static
log_write(buf, len)
	char	*buf;
	int	len;
E 2
I 2
openlog(ident, logstat)
	char *ident;
	int logstat;
E 2
{
D 2
	write(LogFile, buf, len);
E 2
I 2
	register int i;
	register int fd;
I 6
	struct stat st;
I 16
#ifndef LOG_OLDIPC
# ifdef LOG_IPC
	struct servent *sp;
	struct hostent *hp;
# endif LOG_IPC
#endif LOG_OLDIPC
E 16
E 6

	LogTag = ident;
	LogStat = logstat;

D 11
	if (LogFile != NULL)
E 11
I 11
	if (LogFile >= 0)
E 11
		return;
D 11
	LogFile = fopen("/dev/log", "w");
	if (LogFile == NULL)
E 11
I 11
D 13
# ifdef IPCSYSLOG
	SyslogAddr.sin_addr.s_addr = rhost(&LocalHost);
E 13
I 13
# ifdef LOG_IPC
I 16
#ifndef LOG_OLDIPC
	sp = getservbyname("syslog", "udp");
	hp = gethostbyname(SyslogHost);
	if (sp != NULL && hp != NULL)
	{
		bzero(&SyslogAddr, sizeof SyslogAddr);
		SyslogAddr.sin_family = AF_INET;
		LogFile = socket(AF_INET, SOCK_DGRAM, 0, 0);
		if (LogFile >= 0 && bind(LogFile, &SyslogAddr, sizeof SyslogAddr, 0) < 0)
		{
			close(LogFile);
			LogFile = -1;
		}
# ifdef EBUG
		if (LogFile < 0)
			perror("syslog: socket");
# endif EBUG
D 17
		SyslogAddr.sin_port = htons(sp->s_port);
E 17
I 17
		SyslogAddr.sin_port = sp->s_port;
E 17
		bcopy(hp->h_addr, (char *) &SyslogAddr.sin_addr, hp->h_length);
		LogStat |= LOG_DGRAM;
	}
#else LOG_OLDIPC
E 16
	SyslogAddr.sin_addr.s_addr = rhost(&SyslogHost);
I 15
#ifdef NVMUNIX
	LogFile = socket(AF_INET, SOCK_DGRAM, 0, 0);
	bind(LogFile, &SyslogProto, sizeof SyslogProto, 0);
#else NVMUNIX
E 15
E 13
	LogFile = socket(SOCK_DGRAM, &SyslogProto, 0, 0);
I 15
#endif NVMUNIX
E 15
# ifdef EBUG
	if (LogFile < 0)
		perror("syslog: socket");
# endif EBUG
	LogStat |= LOG_DGRAM;
I 16
#endif LOG_OLDIPC
E 16
D 13
# else IPCSYSLOG
E 13
I 13
# else LOG_IPC
E 13
	LogFile = open("/dev/log", 1);
D 13
# endif IPCSYSLOG
E 13
I 13
# endif LOG_IPC
E 13
	if (LogFile < 0)
E 11
	{
I 6
	  nolog:
E 6
		LogStat |= LOG_COOLIT;
I 11
		LogStat &= ~LOG_DGRAM;
E 11
I 10
		LogMask = LOG_CRIT;
E 10
D 11
		LogFile = fopen("/dev/console", "w");
		if (LogFile == NULL)
E 11
I 11
D 19
# ifdef EBUG
		LogFile = -1;
# else EBUG
E 19
		LogFile = open("/dev/console", 1);
D 19
# endif EBUG
E 19
		if (LogFile < 0)
E 11
		{
			perror("Cannot open /dev/console");
D 11
			LogFile = stderr;
E 11
I 11
			LogFile = 2;
E 11
		}
I 6
	}
D 11
	if (fstat(fileno(LogFile), &st) < 0)
E 11
I 11
D 13
# ifndef IPCSYSLOG
E 13
I 13
# ifndef LOG_IPC
E 13
	if (fstat(LogFile, &st) < 0)
E 11
		goto nolog;
	switch (st.st_mode & S_IFMT)
	{
	  case S_IFREG:
	  case S_IFDIR:
D 11
		fclose(LogFile);
E 11
I 11
		(void) close(LogFile);
E 11
		goto nolog;
E 6
	}
I 4

I 9
D 11
# ifndef V6
E 11
I 11
# ifdef FIOCLEX
E 11
E 9
	/* have it close automatically on exec */
D 11
	ioctl(fileno(LogFile), FIOCLEX, NULL);
I 9
# endif V6
E 11
I 11
	ioctl(LogFile, FIOCLEX, NULL);
# endif FIOCLEX
D 13
# endif IPCSYSLOG
E 13
I 13
# endif LOG_IPC
E 13
E 11
E 9
E 4
E 2
}
/*
D 2
**  LOGCVT -- output conversion for log
E 2
I 2
**  CLOSELOG -- close the system log
E 2
**
D 2
**	Converts a number to ascii for the log.  The number gets
**	left in a static buffer; a pointer is returned.
**
E 2
**	Parameters:
D 2
**		n -- the number to convert.
**		base -- the base to convert into.  If negative,
**			do an unsigned convert, else signed.
**		padn -- the number of characters to pad to.  If
**			negative, pad with zeros, else spaces.
E 2
I 2
**		none.
E 2
**
**	Returns:
D 2
**		a pointer to the converted string.
E 2
I 2
**		none.
E 2
**
**	Side Effects:
D 2
**		none
**
**	Requires:
**		none
**
**	Called By:
**		log
E 2
I 2
**		The system log is closed.
E 2
*/

D 2
static char *
logcvt(n, base, padn)
	int	n;
	int	base;
	int	padn;
E 2
I 2
closelog()
E 2
{
D 2
	static char	buf[50];
	register char	*p;
	register int	x;
	int		neg;
	register int	b;
	int		i;
	char		padchar;

	b = base;
	x = n;
	p = &buf[sizeof buf - 1];
	*p-- = '\0';
	padchar = ' ';
	if (padn < 0)
	{
		padchar = '0';
		padn = -padn;
	}
	if (padn > sizeof buf - 2)
		padn = sizeof buf - 2;

	/* compute sign of result */
	neg = 0;
	if (x < 0 && b > 0)
	{
		neg++;
		x = -x;
	}
	else if (b < 0)
		b = -b;

	/* compute ascii string equivalent of x */
	do
	{
		i = x % b;
		if (i > 9)
			i = i - 10 + 'A';
		else
			i = i + '0';
		x /= b;
		*p-- = i;
		padn--;
	} while (x > 0);

	/* insert minus sign as appropriate */
	if (neg)
	{
		*p-- = '-';
		padn--;
	}

	/* pad result to correct length */
	while (padn-- > 0)
		*p-- = padchar;
	
	/* return result */
	return (++p);
E 2
I 2
D 11
	fclose(LogFile);
	LogFile = NULL;
E 11
I 11
	(void) close(LogFile);
	LogFile = -1;
E 11
E 2
}
E 1
