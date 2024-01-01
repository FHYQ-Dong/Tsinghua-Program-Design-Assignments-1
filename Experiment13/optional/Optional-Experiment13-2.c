#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

void insert(Node *head, int value) {
    Node *p = head;
    while (p->next != NULL) p = p->next;
    p->next = (Node *)malloc(sizeof(Node));
    p->next->next = NULL;
    p->next->value = value;
}

void del(Node *head, int value) {
    Node *p = head;
    while (p->next != NULL) {
        if (p->next->value == value) {
            Node *q = p->next;
            p->next = p->next->next;
            free(q);
            break;
        }
        p = p->next;
    }
}

int get_min(Node *head) {
    Node *p = head;
    int min = 0x7fffffff;
    while (p->next != NULL) {
        if (p->next->value < min) min = p->next->value;
        p = p->next;
    }
    printf("%d ", min);
    return min;
}

int main() {
    int n; scanf("%d", &n);
    Node *head = (Node *)malloc(sizeof(Node));
    head->next = NULL; head->value = -1;
    for (int i=1; i<=n; ++i) {
        int val; scanf("%d", &val);
        insert(head, val);
    }
    while (head->next != NULL) {
        int min = get_min(head);
        del(head, min);
    }
    return 0;
}