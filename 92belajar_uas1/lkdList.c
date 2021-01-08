#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct List {
    char data[256];
    struct List *next;
};
typedef struct List List;
typedef char *ldata_t;
typedef int lpos_t;

void ListInsert(List **head, ldata_t data, lpos_t ins_pos) {
    List *buffer1 = (List *)malloc(sizeof(List));
    if (!buffer1) {
        printf("Maaf, memori tidak bisa dialokasikan (sad computer noises)\n");
        return;
    }
    strcpy(buffer1->data, data);
    if (!(*head)) {
        *head = buffer1;
        buffer1->next = NULL;
    }
    else {
        List *buffer2 = *head;
        if (ins_pos == 1) {
            buffer1->next = *head;
            *head = buffer1;
        }
        else if (ins_pos == -1) { // append mode
            while (buffer2->next) {
                buffer2 = buffer2->next;
            }
            buffer2->next = buffer1;
            buffer1->next = NULL;
        }
        else {
            for (lpos_t i = 2; i < ins_pos; i++) {
                buffer2 = buffer2->next;
            }
            buffer1->next = buffer2->next;
            buffer2->next = buffer1;
        }
    }
}

void ListDelete(List **head, lpos_t del_pos) {
    List *buffer1 = *head, *buffer2;
    if (del_pos != 1) {
        for (lpos_t i = 2; i < del_pos; i++) {
            buffer1 = buffer1->next;
        }
        buffer2 = buffer1->next;
        buffer1->next = buffer2->next;
        free(buffer2);
    }
    else {
        *head = (*head)->next;
        free(buffer1);
    }
}

void ListPrint(List *head) {
    List *printbuf = head;
    if (!head) {
        printf("List Empty\n");
    }
    else {
        for (lpos_t i = 0; printbuf; i++) {
            printf("%s\n", printbuf->data);
            printbuf = printbuf->next;
        }
    }
}

void ListClean(List **head) {
    List *buffer = *head;
    while (*head) {
        *head = (*head)->next;
        free(buffer);
        buffer = *head;
    }
}

void ListAppend(List **head, ldata_t data) {
    ListInsert(head, data, -1);
}

void ListPrepend(List **head, ldata_t data) {
    ListInsert(head, data, 1);
}

int main() {
    List *lhead = NULL;
    ListAppend(&lhead, "Wanjir");
    ListAppend(&lhead, "Wadidaw");
    ListPrepend(&lhead, "Aduhhh");
    ListPrint(lhead);
    ListDelete(&lhead, 1);
    ListPrint(lhead);
    ListClean(&lhead);
    ListPrint(lhead);
}