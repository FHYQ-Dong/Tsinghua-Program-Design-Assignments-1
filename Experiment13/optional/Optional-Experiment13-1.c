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
    int n; scanf("%d", &n);
    List list = create_list();
    for (int i=1; i<=n; ++i) {
        int idx, val;
        scanf("%d%d", &idx, &val);
        insert(&list, idx, val);
    }
    print_list(&list);
    int m; scanf("%d", &m);
    for (int i=1; i<=m; ++i) {
        int idx; scanf("%d", &idx);
        delete_by_index(&list, idx);
        print_list(&list);
    }
    return 0;
}