// (C) 2020 Christopher Digno

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/linkedlist.h"

LinkedList *insert(LinkedList *head, char *data, int lnk_pos) {
    LinkedList *objbuf1 = (LinkedList *)malloc(DF_MEMSIZE);
    if (objbuf1 == NULL) {
        printf("System resources insufficient for heap \n");
    }
    else {
        strcpy(objbuf1->data, data);
        if (head == NULL) {
            head = objbuf1;
            objbuf1->next = NULL;
        }
        else {
            if (lnk_pos == 1) {
                objbuf1->next = head;
                head = objbuf1;
            }
            else if (lnk_pos == -1) {
                LinkedList *objbuf2 = head;
                while (objbuf2->next) {
                    objbuf2 = objbuf2->next;
                }
                objbuf2->next = objbuf1;
                objbuf1->next = NULL;
            }
            else {
                LinkedList *objbuf2 = head;
                for (int i = 2; i < lnk_pos; i++) {
                    objbuf2 = objbuf2->next;
                }
                objbuf1->next = objbuf2->next;
                objbuf2->next = objbuf1;

            }
        }
    }
    return head;
}

void testprint(LinkedList *head) {
    LinkedList *objbuf1 = head;
    if (!(head)) {
        printf("There are no similarities in those 2 files. \n");
    }
    else {
        for (int i = 1; objbuf1; i++) {
            printf("MATCH #%d: %s \n", i, objbuf1->data);
            objbuf1 = objbuf1->next;
        }
    }
}

LinkedList *deletel(LinkedList *head, int lnk_pos) {
    LinkedList *objbuf1 = head, *objbuf2;
    if (lnk_pos != 1) {
        for (int i = 2; i < lnk_pos; i++) {
            objbuf1 = objbuf1->next;
        }
        objbuf2 = objbuf1->next;
        objbuf1->next = objbuf2->next;
        free(objbuf2);
    }
    else {
        head = head->next;
        free(objbuf1);
    }
    return head;
}

LinkedList *memcleanup(LinkedList *head) {
    LinkedList *buffer;
    buffer = head;
    while (head) {
        head = head->next;
        free(buffer);
        buffer = head;
    }
    return head;
}