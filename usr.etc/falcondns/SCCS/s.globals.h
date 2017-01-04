h16761
s 00000/00002/00071
d D 1.34 2013/01/13 22:03:49 msokolov 34 33
c NS-glue-answers and cache-max-rdlength tunable settings are no more
e
s 00001/00001/00072
d D 1.33 2013/01/13 07:02:37 msokolov 33 32
c new ttl-limit-neg setting, ttl-bump-{CNAME,NS} changed to numbers
e
s 00001/00001/00072
d D 1.32 2013/01/06 07:03:36 msokolov 32 31
c MSDNS => FalconDNS
e
s 00001/00000/00072
d D 1.31 2011/12/23 07:42:59 msokolov 31 30
c compress-new-RR-types config setting
e
s 00004/00001/00068
d D 1.30 2011/12/22 05:52:14 msokolov 30 29
c ttl-limit tunable setting split into several
e
s 00004/00001/00065
d D 1.29 2011/12/20 19:48:15 msokolov 29 28
c track and report outcomes of TCP retry attempts (after getting UDP TC)
e
s 00001/00000/00065
d D 1.28 2011/12/18 08:27:20 msokolov 28 27
c cache-NS-tempfail tunable setting added
e
s 00002/00001/00063
d D 1.27 2011/12/17 08:24:37 msokolov 27 26
c workaround for the child exit race condition
e
s 00001/00001/00063
d D 1.26 2011/12/17 06:37:57 msokolov 26 25
c tcpqueue revamped
e
s 00001/00000/00063
d D 1.25 2011/12/15 02:55:23 msokolov 25 24
c sigchild_flag implemented
e
s 00007/00000/00056
d D 1.24 2011/12/14 20:45:52 msokolov 24 23
c globals and tunable settings for the outbound TCP service
e
s 00005/00000/00051
d D 1.23 2011/12/13 22:55:54 msokolov 23 22
c globals for tcpserv
e
s 00007/00000/00044
d D 1.22 2011/12/13 04:54:32 msokolov 22 21
c TC stats implemented
e
s 00002/00001/00042
d D 1.21 2011/12/11 03:35:56 msokolov 21 20
c preparations for cache s
e
s 00001/00000/00042
d D 1.20 2011/12/10 05:59:58 msokolov 20 19
c max_hash_chain tunable var added
e
s 00003/00000/00039
d D 1.19 2011/12/08 05:15:35 msokolov 19 18
c configurable policy settings for caching/glue corner cases
e
s 00001/00000/00038
d D 1.18 2011/12/07 23:14:22 msokolov 18 17
c fixed 'fromlen' bug in udpout.c
c created udpout-debug apparatus in the process of chasing after that bug
e
s 00004/00000/00034
d D 1.17 2011/12/04 17:29:29 msokolov 17 16
c tunable settings for the caching mechanism
e
s 00001/00000/00033
d D 1.16 2011/12/01 06:15:54 msokolov 16 15
c data structure changes in preparation for cache-created nodes
e
s 00002/00001/00031
d D 1.15 2011/11/12 19:16:06 msokolov 15 14
c askforns retries logic better thought through
e
s 00002/00000/00030
d D 1.14 2011/11/11 23:10:04 msokolov 14 13
c askforns timeout/retries tuning global variables added
e
s 00001/00000/00029
d D 1.13 2011/11/05 11:05:32 msokolov 13 12
c max-nested-queries setting implemented
e
s 00002/00000/00027
d D 1.12 2011/11/01 22:00:14 msokolov 12 11
c num_outbound_udp_sockets added
e
s 00001/00000/00026
d D 1.11 2011/11/01 03:32:19 msokolov 11 10
c compress-case-preserve setting implemented
e
s 00000/00001/00026
d D 1.10 2011/10/30 01:16:47 msokolov 10 9
c query processing shaping up
e
s 00002/00000/00025
d D 1.9 2011/10/29 05:43:07 msokolov 9 8
c query queues added
e
s 00002/00000/00023
d D 1.8 2011/09/12 06:13:43 msokolov 8 7
c nsanchor.c started
e
s 00002/00000/00021
d D 1.7 2011/09/07 07:00:08 msokolov 7 6
c echo-question setting implemented
e
s 00001/00000/00020
d D 1.6 2011/07/18 05:15:49 msokolov 6 5
c timesched mechanism implemented
e
s 00001/00000/00019
d D 1.5 2011/07/15 19:21:33 msokolov 5 4
c current_time added
e
s 00001/00001/00018
d D 1.4 2011/07/14 22:51:51 msokolov 4 3
c daemonization better thought through
e
s 00002/00001/00017
d D 1.3 2011/07/13 23:45:46 msokolov 3 2
c preparations for zone file reading
e
s 00001/00000/00017
d D 1.2 2011/07/13 19:23:18 msokolov 2 1
c we now read the class def file, although don't do anything with it yet
e
s 00017/00000/00000
d D 1.1 11/07/11 08:04:05 msokolov 1 0
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
 * External declarations of global variables
 *
 *	%W% (IFCTF) %E%
 */

D 4
extern int debug;
E 4
I 4
extern int debug, initdone;
E 4
extern char *msdns_directory;
extern char default_msdns_directory[];
extern struct class *class_array[255], *class_list;
extern int classes_needing_fileread, class_fileread_inprogress;
I 2
D 3
extern struct zone *global_zone_list;
E 3
I 3
extern int zones_needing_fileread, zone_fileread_inprogress;
extern struct zone *global_zone_list, *zone_fileread_roundrobin;
I 8
extern struct ns_anchor *nsanchor_fileread_queue;
extern int nsanchor_fileread_inprogress;
E 8
E 3
E 2

extern fd_set select_for_read, select_for_write, select_for_except;
extern int select_max_fd;
extern struct selectloop_desc *select_desc;
I 5
extern time_t current_time;
I 6
extern struct timesched *timesched_head;
I 9
extern struct query *queryqueue_head, **queryqueue_tail;
I 25
D 27
extern int sigchild_flag;
E 27
I 27
extern int zonexfer_children, sigchild_flag;
E 27
E 25
D 10
extern struct query *querycompl_head, **querycompl_tail;
E 10
E 9
I 7

I 24
/* tunable settings */
I 30
extern int allow_aa_queries;
E 30
E 24
I 14
D 15
extern int askforns_retries;
E 15
I 15
extern int askforns_retries_perserver;
extern int askforns_retries_total;
E 15
extern int askforns_timeout;
I 17
D 34
extern int cache_max_rdlength;
E 34
I 21
extern int cache_sweep_interval;
I 27
extern int child_race_timer;
E 27
E 21
E 17
E 14
I 11
extern int compress_case_preserve;
I 31
extern int compress_new_types;
E 31
E 11
extern int echo_question;
I 20
extern int max_hash_chain;
E 20
I 13
extern int max_nested_queries;
I 19
extern int norec_allow_cached_ans;
extern int norec_allow_cached_ref;
D 34
extern int nsglue_answers;
E 34
I 28
extern int tempfail_cache_dur;
E 28
E 19
I 17
extern int ttl_bump_cname, ttl_bump_ns;
D 30
extern int ttl_limit;
E 30
I 30
extern int ttl_limit_data;
I 33
extern int ttl_limit_ncache;
E 33
extern int ttl_limit_ns;
D 33
extern int ttl_limit_nsneg;
E 33
E 30
extern int ttl_sensible_min;
E 17
E 13
I 12

extern int num_outbound_udp_sockets;
I 18
extern int udpout_debug;
E 18
I 16
D 21
extern struct node *cache_node_list;
E 21
I 21
extern struct node *cache_node_list, *cache_sweep_ptr;
I 22

I 24
/* TCP/AXFR server */
E 24
I 23
extern int tcpserv_max_conn;
extern int tcpserv_active_conn;
extern int tcpserv_max_idle;
extern int tcpserv_send_timeout;
I 24
/* outbound TCP service */
D 26
extern struct tcpqueue *tcpqueue_head, **tcpqueue_tail;
E 26
I 26
extern struct tcpqueue *tcpqueue_active, *tcpqueue_waitq;
E 26
extern int tcpqueue_outstanding, tcpqueue_limit;
extern int outbound_tcp_timeout;
E 24

I 24
/* truncation stats */
E 24
E 23
extern int stats_incoming_udp_tc;
D 29
extern int stats_incoming_tcp_tc;
E 29
I 29
extern int stats_tcpretry_success;
extern int stats_tcpretry_fail;
extern int stats_tcpretry_tcagain;
extern int stats_tcpretry_badecho;
E 29
extern int stats_outgoing_udp_tc;
extern int stats_outgoing_tcp_tc;
extern int stats_local_ar_tc;
extern int stats_fwd_ar_tc;
E 22
E 21
E 16
E 12
E 7
E 6
E 5
E 1
