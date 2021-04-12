// linkedlist.h
// linked list implementation
// (C) 2020 Christopher Digno

#pragma once

#define DF_MEMSIZE sizeof(LinkedList)

struct LinkedList{
    char data[80];
    struct LinkedList *next;
};

typedef struct LinkedList LinkedList;

LinkedList *insert(LinkedList *head, char* data, int lnk_pos);
void testprint(LinkedList *head);
LinkedList *deletel(LinkedList *head, int lnk_pos);
LinkedList *memcleanup(LinkedList *head);