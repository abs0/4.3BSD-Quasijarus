h50210
s 00000/00002/00074
d D 1.34 2013/01/13 22:03:47 msokolov 34 33
c NS-glue-answers and cache-max-rdlength tunable settings are no more
e
s 00001/00001/00075
d D 1.33 2013/01/13 07:02:36 msokolov 33 32
c new ttl-limit-neg setting, ttl-bump-{CNAME,NS} changed to numbers
e
s 00001/00001/00075
d D 1.32 2013/01/06 07:03:35 msokolov 32 31
c MSDNS => FalconDNS
e
s 00001/00000/00075
d D 1.31 2011/12/23 07:42:58 msokolov 31 30
c compress-new-RR-types config setting
e
s 00004/00001/00071
d D 1.30 2011/12/22 05:52:13 msokolov 30 29
c ttl-limit tunable setting split into several
e
s 00004/00001/00068
d D 1.29 2011/12/20 19:48:14 msokolov 29 28
c track and report outcomes of TCP retry attempts (after getting UDP TC)
e
s 00001/00000/00068
d D 1.28 2011/12/18 08:27:19 msokolov 28 27
c cache-NS-tempfail tunable setting added
e
s 00002/00001/00066
d D 1.27 2011/12/17 08:24:36 msokolov 27 26
c workaround for the child exit race condition
e
s 00001/00001/00066
d D 1.26 2011/12/17 06:37:56 msokolov 26 25
c tcpqueue revamped
e
s 00001/00000/00066
d D 1.25 2011/12/15 02:55:22 msokolov 25 24
c sigchild_flag implemented
e
s 00007/00000/00059
d D 1.24 2011/12/14 20:45:51 msokolov 24 23
c globals and tunable settings for the outbound TCP service
e
s 00005/00000/00054
d D 1.23 2011/12/13 22:55:53 msokolov 23 22
c globals for tcpserv
e
s 00007/00000/00047
d D 1.22 2011/12/13 04:54:31 msokolov 22 21
c TC stats implemented
e
s 00002/00001/00045
d D 1.21 2011/12/11 03:35:55 msokolov 21 20
c preparations for cache s
e
s 00001/00000/00045
d D 1.20 2011/12/10 05:59:57 msokolov 20 19
c max_hash_chain tunable var added
e
s 00003/00000/00042
d D 1.19 2011/12/08 05:15:34 msokolov 19 18
c configurable policy settings for caching/glue corner cases
e
s 00001/00000/00041
d D 1.18 2011/12/07 23:14:21 msokolov 18 17
c fixed 'fromlen' bug in udpout.c
c created udpout-debug apparatus in the process of chasing after that bug
e
s 00004/00000/00037
d D 1.17 2011/12/04 17:29:28 msokolov 17 16
c tunable settings for the caching mechanism
e
s 00001/00000/00036
d D 1.16 2011/12/01 06:15:53 msokolov 16 15
c data structure changes in preparation for cache-created nodes
e
s 00002/00001/00034
d D 1.15 2011/11/12 19:16:05 msokolov 15 14
c askforns retries logic better thought through
e
s 00002/00000/00033
d D 1.14 2011/11/11 23:10:03 msokolov 14 13
c askforns timeout/retries tuning global variables added
e
s 00001/00000/00032
d D 1.13 2011/11/05 11:05:30 msokolov 13 12
c max-nested-queries setting implemented
e
s 00002/00000/00030
d D 1.12 2011/11/01 22:00:13 msokolov 12 11
c num_outbound_udp_sockets added
e
s 00001/00000/00029
d D 1.11 2011/11/01 03:32:18 msokolov 11 10
c compress-case-preserve setting implemented
e
s 00000/00001/00029
d D 1.10 2011/10/30 01:16:45 msokolov 10 9
c query processing shaping up
e
s 00002/00000/00028
d D 1.9 2011/10/29 05:43:06 msokolov 9 8
c query queues added
e
s 00002/00000/00026
d D 1.8 2011/09/12 06:13:42 msokolov 8 7
c nsanchor.c started
e
s 00002/00000/00024
d D 1.7 2011/09/07 07:00:07 msokolov 7 6
c echo-question setting implemented
e
s 00001/00000/00023
d D 1.6 2011/07/18 05:15:49 msokolov 6 5
c timesched mechanism implemented
e
s 00001/00000/00022
d D 1.5 2011/07/15 19:21:32 msokolov 5 4
c current_time added
e
s 00001/00001/00021
d D 1.4 2011/07/14 22:51:50 msokolov 4 3
c daemonization better thought through
e
s 00002/00001/00020
d D 1.3 2011/07/13 23:45:45 msokolov 3 2
c preparations for zone file reading
e
s 00001/00000/00020
d D 1.2 2011/07/13 19:23:17 msokolov 2 1
c we now read the class def file, although don't do anything with it yet
e
s 00020/00000/00000
d D 1.1 11/07/11 08:04:04 msokolov 1 0
c MSDNS project started, template compiles
e
u
U
t
T
I 1
/*
D 32
 * Michael Sokolov's Domain Name Server (MSDNS)
E 32
I 32
 * FalconDNS daemon by Michael Spacefalcon
E 32
 *
 * Global variables are defined here
 */

#ifndef lint
static char sccsid[] = "%W% (IFCTF) %E%";
#endif

#include <sys/types.h>

D 4
int debug;
E 4
I 4
int debug, initdone;
E 4
char *msdns_directory;
struct class *class_array[255], *class_list;
int classes_needing_fileread, class_fileread_inprogress;
I 2
D 3
struct zone *global_zone_list;
E 3
I 3
int zones_needing_fileread, zone_fileread_inprogress;
struct zone *global_zone_list, *zone_fileread_roundrobin;
I 8
struct ns_anchor *nsanchor_fileread_queue;
int nsanchor_fileread_inprogress;
E 8
E 3
E 2

fd_set select_for_read, select_for_write, select_for_except;
int select_max_fd;
struct selectloop_desc *select_desc;
I 5
time_t current_time;
I 6
struct timesched *timesched_head;
I 9
struct query *queryqueue_head, **queryqueue_tail = &queryqueue_head;
I 25
D 27
int sigchild_flag;
E 27
I 27
int zonexfer_children, sigchild_flag;
E 27
E 25
D 10
struct query *querycompl_head, **querycompl_tail = &querycompl_head;
E 10
E 9
I 7

I 24
/* tunable settings */
I 30
int allow_aa_queries;
E 30
E 24
I 14
D 15
int askforns_retries = 2;
E 15
I 15
int askforns_retries_perserver = 3;
int askforns_retries_total = 10;
E 15
int askforns_timeout = 1;
I 17
D 34
int cache_max_rdlength = 1024;
E 34
I 21
int cache_sweep_interval = 3600;
I 27
int child_race_timer = 30;
E 27
E 21
E 17
E 14
I 11
int compress_case_preserve;
I 31
int compress_new_types;
E 31
E 11
int echo_question = 1;
I 20
int max_hash_chain = 5;
E 20
I 13
int max_nested_queries = 10;
I 19
int norec_allow_cached_ans = 1;
int norec_allow_cached_ref = 1;
D 34
int nsglue_answers;
E 34
I 28
int tempfail_cache_dur = 120;
E 28
E 19
I 17
int ttl_bump_cname, ttl_bump_ns;
D 30
int ttl_limit = 86400 * 7;
E 30
I 30
int ttl_limit_data = 86400 * 7;
I 33
int ttl_limit_ncache = 86400 * 2;
E 33
int ttl_limit_ns = 86400 * 14;
D 33
int ttl_limit_nsneg = 86400 * 2;
E 33
E 30
int ttl_sensible_min = 10;
E 17
E 13
I 12

int num_outbound_udp_sockets;
I 18
int udpout_debug;
E 18
I 16
D 21
struct node *cache_node_list;
E 21
I 21
struct node *cache_node_list, *cache_sweep_ptr;
I 22

I 24
/* TCP/AXFR server */
E 24
I 23
int tcpserv_max_conn = 30;
int tcpserv_active_conn;
int tcpserv_max_idle = 60;
int tcpserv_send_timeout = 60;
I 24
/* outbound TCP service */
D 26
struct tcpqueue *tcpqueue_head, **tcpqueue_tail = &tcpqueue_head;
E 26
I 26
struct tcpqueue *tcpqueue_active, *tcpqueue_waitq;
E 26
int tcpqueue_outstanding, tcpqueue_limit = 3;
int outbound_tcp_timeout = 120;
E 24

I 24
/* truncation stats */
E 24
E 23
int stats_incoming_udp_tc;
D 29
int stats_incoming_tcp_tc;
E 29
I 29
int stats_tcpretry_success;
int stats_tcpretry_fail;
int stats_tcpretry_tcagain;
int stats_tcpretry_badecho;
E 29
int stats_outgoing_udp_tc;
int stats_outgoing_tcp_tc;
int stats_local_ar_tc;
int stats_fwd_ar_tc;
E 22
E 21
E 16
E 12
E 7
E 6
E 5
E 1
