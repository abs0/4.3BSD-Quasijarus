h21490
s 00008/00002/00221
d D 5.1 85/05/31 10:02:26 dist 6 5
c Add copyright
e
s 00002/00000/00221
d D 1.4 85/03/01 20:24:29 linton 5 4
c update to version 3.0
e
s 00001/00003/00220
d D 1.3 84/06/23 11:41:14 sam 4 2
i 3
c merge linton branch delta trail
e
s 00003/00001/00220
d D 1.2.1.1 84/06/23 10:47:05 sam 3 2
c branch delta of linton changes from net.sources
e
s 00001/00001/00220
d D 1.2 82/12/15 04:20:29 linton 2 1
c fixed @(#) stuff
e
s 00221/00000/00000
d D 1.1 82/12/15 04:07:46 linton 1 0
c date and time created 82/12/15 04:07:46 by linton
e
u
U
f b 
t
T
I 1
D 6
/* Copyright (c) 1982 Regents of the University of California */
E 6
I 6
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 6

D 2
static char sccsid[] = "@(#)%Z%%M% %I% %G%";
E 2
I 2
D 3
static char sccsid[] = "%Z%%M% %I% %G%";
E 3
I 3
D 4
static char sccsid[] = "@(#)lists.c 1.2 12/15/82";

static char rcsid[] = "$Header: lists.c,v 1.3 84/03/27 10:21:21 linton Exp $";
E 4
I 4
D 6
static	char sccsid[] = "%W% (Berkeley) %G%";
E 6
I 6
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 6
E 4
E 3
E 2

I 5
static char rcsid[] = "$Header: lists.c,v 1.5 84/12/26 10:40:00 linton Exp $";

E 5
/*
 * General list definitions.
 *
 * The assumption is that the elements in a list are words,
 * usually pointers to the actual information.
 */

#include "defs.h"
#include "lists.h"

#ifndef public

typedef struct List *List;
typedef struct ListItem *ListItem;
typedef char *ListElement;

#define list_item(element) generic_list_item((ListElement) (element))
#define list_element(type, item) ((type) (item == nil ? nil : (item)->element))
#define list_head(list) ((list == nil) ? nil : (list)->head)
#define list_tail(list) ((list == nil) ? nil : (list)->tail)
#define list_next(item) ((item == nil) ? nil : (item)->next)
#define list_prev(item) ((item == nil) ? nil : (item)->prev)
#define list_size(list) (((list) == nil) ? 0 : (list)->nitems)

#define foreach(type, i, list) \
{ \
    register ListItem _item; \
 \
    _item = list_head(list); \
    while (_item != nil) { \
	i = list_element(type, _item); \
	_item = list_next(_item);

#define endfor \
    } \
}

/*
 * Iterate through two equal-sized lists.
 */

#define foreach2(type1, i, list1, type2, j, list2) \
{ \
    register ListItem _item1, _item2; \
 \
    _item1 = list_head(list1); \
    _item2 = list_head(list2); \
    while (_item1 != nil) { \
	i = list_element(type1, _item1); \
	j = list_element(type2, _item2); \
	_item1 = list_next(_item1); \
	_item2 = list_next(_item2);

#define list_islast() (_item == nil)
#define list_curitem(list) (_item == nil ? list_tail(list) : list_prev(_item))

/*
 * Representation should not be used outside except through macros.
 */

struct List {
    Integer nitems;
    ListItem head;
    ListItem tail;
};

struct ListItem {
    ListElement element;
    ListItem next;
    ListItem prev;
};

#endif

/*
 * Allocate and initialize a list.
 */

public List list_alloc()
{
    List list;

    list = new(List);
    list->nitems = 0;
    list->head = nil;
    list->tail = nil;
    return list;
}

/*
 * Create a list item from an object (represented as pointer or integer).
 */

public ListItem generic_list_item(element)
ListElement element;
{
    ListItem i;

    i = new(ListItem);
    i->element = element;
    i->next = nil;
    i->prev = nil;
    return i;
}

/*
 * Insert an item before the item in a list.
 */

public list_insert(item, after, list)
ListItem item;
ListItem after;
List list;
{
    ListItem a;

    checkref(list);
    list->nitems = list->nitems + 1;
    if (list->head == nil) {
	list->head = item;
	list->tail = item;
    } else {
	if (after == nil) {
	    a = list->head;
	} else {
	    a = after;
	}
	item->next = a;
	item->prev = a->prev;
	if (a->prev != nil) {
	    a->prev->next = item;
	} else {
	    list->head = item;
	}
	a->prev = item;
    }
}

/*
 * Append an item after the given item in a list.
 */

public list_append(item, before, list)
ListItem item;
ListItem before;
List list;
{
    ListItem b;

    checkref(list);
    list->nitems = list->nitems + 1;
    if (list->head == nil) {
	list->head = item;
	list->tail = item;
    } else {
	if (before == nil) {
	    b = list->tail;
	} else {
	    b = before;
	}
	item->next = b->next;
	item->prev = b;
	if (b->next != nil) {
	    b->next->prev = item;
	} else {
	    list->tail = item;
	}
	b->next = item;
    }
}

/*
 * Delete an item from a list.
 */

public list_delete(item, list)
ListItem item;
List list;
{
    checkref(item);
    checkref(list);
    assert(list->nitems > 0);
    if (item->next == nil) {
	list->tail = item->prev;
    } else {
	item->next->prev = item->prev;
    }
    if (item->prev == nil) {
	list->head = item->next;
    } else {
	item->prev->next = item->next;
    }
    list->nitems = list->nitems - 1;
}

/*
 * Concatenate one list onto the end of another.
 */

public List list_concat(first, second)
List first, second;
{
    List r;

    if (first == nil) {
	r = second;
    } else if (second == nil) {
	r = first;
    } else {
	second->head->prev = first->tail;
	first->tail->next = second->head;
	first->tail = second->tail;
	first->nitems = first->nitems + second->nitems;
	r = first;
    }
    return r;
}
E 1
