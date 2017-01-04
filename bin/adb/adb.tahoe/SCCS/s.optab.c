h21219
s 00055/00000/00000
d D 1.1 86/02/25 16:04:46 sam 1 0
c date and time created 86/02/25 16:04:46 by sam
e
u
U
t
T
I 1
#ifndef lint
static	char sccsid[] = "%W% (Berkeley) %G%";
#endif

#include "defs.h"
#include "optab.h"

struct optab optab[] = {
#define OP(a,b,c,d,e,f,g,h,i) {a,b,c,d,e,f,g,h,i}
#include "instrs"
0};

STRING systab[SYSSIZ] = {
	"indir",	"exit",		"fork",		"read",
	"write",	"open",		"close",	"owait",
	"creat",	"link",		"unlink",	"execv",
	"chdir",	"otime",	"mknod",	"chmod",
	"chown",	"obreak",	"ostat",	"lseek",
	"getpid",	"mount",	"umount",	"osetuid",
	"getuid",	"ostime",	"ptrace",	"oalarm",
	"ofstat",	"opause",	"outime",	"ostty",
	"ogtty",	"access",	"onice",	"oftime",
	"sync",		"kill",		"stat",		"osetpgrp",
	"lstat",	"dup",		"pipe",		"otimes",
	"profil",	0,		"osetgid",	"getgid",
	"osig",		0,		0,		"acct",
	"ophys",	"olock",	"ioctl",	"reboot",
	"ompxchan",	"symlink",	"readlink",	"execve",
	"umask",	"chroot",	"fstat",	0,
	"getpagesize",	"mremap",	"vfork",	"ovread",
	"ovwrite",	"sbrk",		"sstk",		"mmap",
	"ovadvise",	"munmap",	"mprotect",	"madvise",
	"vhangup",	"ovlimit",	"mincore",	"getgroups",
	"setgroups",	"getpgrp",	"setpgrp",	"setitimer",
	"wait",		"swapon",	"getitimer",	"gethostname",
	"sethostname",	"getdtablesize","dup2",		"getdopt",
	"fcntl",	"select",	"setdopt",	"fsync",
	"setpriority",	"socket",	"connect",	"accept",
	"getpriority",	"send",		"recv",		"osocketaddr",
	"bind",		"setsockopt",	"listen",	"ovtimes",
	"sigvec",	"sigblock",	"sigsetmask",	"sigpause",
	"sigstack",	"recvmsg",	"sendmsg",	"vtrace",
	"gettimeofday",	"getrusage",	"getsockopt",	"resuba",
	"readv",	"writev",	"settimeofday",	"fchown",
	"fchmod",	"recvfrom",	"setreuid",	"setregid",
	"rename",	"truncate",	"ftruncate",	"flock",
	0,		"sendto",	"shutdown",	"socketpair",
	"mkdir",	"rmdir",	"utimes",	0,
	0,		"getpeername",	"gethostid",	"sethostid",
	"getrlimit",	"setrlimit",	"killpg",	0,
	"quota",	"qquota",	"getsockname",
};

STRING	regname[] = { "r0", "r1", "r2", "r3", "r4", "r5", "r6", "r7",
		"r8", "r9", "r10", "r11", "r12", "fp", "sp", "pc"};
E 1
