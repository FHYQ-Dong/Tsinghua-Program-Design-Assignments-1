#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tagNode {
    int index, value;
    struct tagNode *prev;
    struct tagNode *next;
} Node, *PNode;
typedef struct tagList {
    PNode head;
    int length;
} List;

List insert(List *list, int index, int value) {
    PNode p = list->head;
    while (p->next != NULL && p->next->index < index) p = p->next;
    if (p->next != NULL && p->next->index == index) {
        p->next->value = value;
        return *list;
    }
    PNode q = (PNode)malloc(sizeof(Node));
    memset(q, 0, sizeof(Node));
    q->index = index;
    q->value = value;
    q->prev = p;
    q->next = p->next;
    p->next = q;
    if (q->next != NULL) q->next->prev = q;
    return *list;
}

void delete_by_index(List *list, int index) {
    PNode p = list->head;
    while (p->next != NULL && p->next->index < index) p = p->next;
    if (p->next == NULL || p->next->index > index) return;
    PNode q = p->next;
    p->next = q->next;
    if (q->next != NULL) q->next->prev = p;
    free(q);
}

List create_list() {
    List list;
    PNode p = (PNode)malloc(sizeof(Node));
    memset(p, 0, sizeof(Node));
    list.head = p;
    list.length = 0;
    return list;
}

void print_list(List *list) {
    PNode p = list->head->next;
    while (p != NULL) {
        printf("(%d, %d) ", p->index, p->value);
        p = p->next;
    }
    printf("\n");
}

int main() {
    List list = create_list();
    insert(&list, 1, 1);
    insert(&list, 2, 2);
    insert(&list, 3, 3);
    insert(&list, 4, 4);
    insert(&list, 5, 5);
    print_list(&list);
    delete_by_index(&list, 3);
    print_list(&list);
    return 0;
}