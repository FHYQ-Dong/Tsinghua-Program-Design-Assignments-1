#include<stdio.h>
#include<stdlib.h>
typedef struct Node Node;
typedef struct Num Num;

struct Node {
    int val;
    Node* next;
};
struct Num {
    int cnt;
    Node* head;
};

Num num[1001];

int main() {
    for (int i=1; i<=1000; ++i) {
        for (int j=1; i*j<=1000; ++j) {
            num[i*j].cnt++;
            Node* tmp = (Node*)malloc(sizeof(Node));
            tmp->val = i;
            tmp->next = num[i*j].head;
            num[i*j].head = tmp;
        }
    }
    for (int i=1; i<=1000; ++i) {
        if (num[i].cnt == 5) {
            printf("%d:", i);
            Node* tmp = num[i].head;
            while (tmp) {
                printf(" %d", tmp->val);
                tmp = tmp->next;
            }
            printf("\n");
        }
    }
    return 0;
}