#include <sys/param.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>

u_char tcpoutblk[35] = {0, 33, 0x55, 0xAA, 0, 0,
			0, 1, 0, 0, 0, 0, 0, 0,
			4, 'i', 'v', 'a', 'n',
			6, 'H', 'a', 'r', 'h', 'a', 'n',
			3, 'O', 'R', 'G', 0,
			0, 1, 0, 1};
u_char respbuf[65535];
int resplen;

int s;
struct sockaddr_in sin;
int rptcount;

dump_resp(dumpsize)
{
	register int off;

	for (off = 0; off < dumpsize; off++) {
		printf(" %02X", respbuf[off]);
		if ((off & 15) == 15 || off == dumpsize-1)
			putchar('\n');
	}
}

try(attempt_num)
{
	register int cc;
	u_short resplen_nbo;

	printf("Beginning to send query #%d\n", attempt_num);
	cc = write(s, tcpoutblk, sizeof tcpoutblk);
	if (cc != sizeof tcpoutblk) {
		printf("tried to write %d bytes, write syscall returned %d\n",
			sizeof tcpoutblk, cc);
		exit(1);
	}
	printf("wrote %d bytes successfully, will try to read resplen\n", cc);
	cc = read(s, &resplen_nbo, 2);
	if (cc != 2) {
		printf("resplen read returned %d\n", cc);
		exit(1);
	}
	resplen = ntohs(resplen_nbo);
	printf("received response length of %d, will now try to read that\n",
		resplen);
	cc = read(s, respbuf, resplen);
	if (cc != resplen) {
		printf("read returned %d\n", cc);
		exit(1);
	}
	printf("response received successfully\n");
	dump_resp(MIN(resplen, 256));
}

main(argc, argv)
	char **argv;
{
	int i;

	if (argc != 4) {
		fprintf(stderr, "usage: %s ipaddr port repeat-count\n",
			argv[0]);
		exit(1);
	}
	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = inet_addr(argv[1]);
	if (sin.sin_addr.s_addr == INADDR_NONE) {
		fprintf(stderr, "%s: %s is not a valid IP address\n",
			argv[0], argv[1]);
		exit(1);
	}
	sin.sin_port = htons(atoi(argv[2]));
	rptcount = atoi(argv[3]);

	s = socket(PF_INET, SOCK_STREAM, 0);
	if (s < 0) {
		perror("socket");
		exit(1);
	}
	if (connect(s, &sin, sizeof sin) < 0) {
		perror("connect");
		exit(1);
	}
	for (i = 0; i < rptcount; i++)
		try(i);
	exit(0);
}
