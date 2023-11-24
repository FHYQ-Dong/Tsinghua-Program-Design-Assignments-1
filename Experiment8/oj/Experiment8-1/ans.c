#include <stdio.h>
#include<stdlib.h>

typedef struct Node {
    int idx;
    struct Node *next;
} Node;
typedef struct Loop {
    Node *head, *tail, *cur;
    int size;
    void (*init)(struct Loop *this, int _size);
} Loop;

int cnt = 40, ans = 0;

void _init_loop(Loop *this, int _size) {
    this->head = NULL;
    this->tail = NULL;
    this->cur = (Node*)malloc(sizeof(Node));
    this->size = _size;
    for(int i=this->size-1; i>=0; --i) {
        Node *tmp = (Node*)malloc(sizeof(Node));
        tmp->idx = i;
        tmp->next = this->head;
        this->head = tmp;
        if(i == this->size-1) this->tail = tmp;
        this->tail->next = this->head;
    }
    this->cur = this->head;
    return;
}

void get_ans_loop(Loop *people, int cnt, int *ans) {
    while(people->size > 1) {
        people->cur = people->cur->next;
        Node *tmp = people->cur->next;
        people->cur->next = tmp->next;
        free(tmp);
        people->cur = people->cur->next;
        --people->size;
    }
    *ans = people->cur->idx;
    free(people->cur);
    return;
}

int main() {
    scanf("%d", &cnt);
    Loop *people = (Loop*)malloc(sizeof(Loop));
    people->init = _init_loop;

    people->init(people, cnt);
    get_ans_loop(people, cnt, &ans);
    printf("%d\n", ans);
    return 0;
}