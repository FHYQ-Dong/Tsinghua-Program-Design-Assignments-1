#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int idx;
    struct Node *next;
} Node;

int main() {
    int n; scanf("%d", &n);
    Node *head = (Node *)malloc(sizeof(Node)), *cur;
    head->idx = 1; head->next = NULL; cur = head;
    for (int i=2; i<=n; ++i) {
        Node *p = (Node *)malloc(sizeof(Node));
        p->idx = i; p->next = NULL;
        cur->next = p; cur = p;
    }
    cur->next = head; cur = head;
    for (int i=1; i<=n-2; ++i) {
        cur = cur->next;
        Node *tmp = cur->next;
        cur->next = tmp->next;
        free(tmp);
        cur = cur->next;
    }
    printf("%d %d\n", cur->idx, cur->next->idx);
    return 0;
}