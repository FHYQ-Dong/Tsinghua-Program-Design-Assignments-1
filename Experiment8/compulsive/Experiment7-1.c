#include <stdio.h>
#include <Windows.h>

typedef struct Node {
    int idx;
    struct Node *next;
} Node;
typedef struct Loop {
    Node *head, *tail, *cur;
    int size;
    void (*init)(struct Loop *this, int _size);
} Loop;

double run_time;
LARGE_INTEGER time_start, time_over;	//开始时间，结束时间
double dqFreq;		//计时器频率
LARGE_INTEGER f;
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

void get_ans_recurrence(Loop *people, int cur_alive, int *ans) {
    if (cur_alive == 1) {
        *ans = people->cur->idx;
        free(people->cur);
        return;
    }
    people->cur = people->cur->next;
    Node *tmp = people->cur->next;
    people->cur->next = tmp->next;
    free(tmp);
    people->cur = people->cur->next;
    --people->size;
    get_ans_recurrence(people, cur_alive-1, ans);
    return;
}

void timer_init() {
    QueryPerformanceFrequency(&f);
    dqFreq=(double)f.QuadPart;
    QueryPerformanceCounter(&time_start);
}

int main() {
    Loop *people = (Loop*)malloc(sizeof(Loop));
    people->init = _init_loop;
    timer_init();

    people->init(people, cnt);
    QueryPerformanceCounter(&time_start);	//计时开始
    get_ans_loop(people, cnt, &ans);
    QueryPerformanceCounter(&time_over);	//计时结束
    printf("Answer_loop: %d\n", ans);
    run_time=1000*(time_over.QuadPart-time_start.QuadPart)/dqFreq;
    printf("Time_loop: %lfms\n", run_time);


    people->init(people, cnt);
    QueryPerformanceCounter(&time_start);	//计时开始
    get_ans_recurrence(people, cnt, &ans);
    QueryPerformanceCounter(&time_over);	//计时结束
    printf("Answer_recurrence: %d\n", ans);
    run_time=1000*(time_over.QuadPart-time_start.QuadPart)/dqFreq;
    printf("Time_recurrence: %lfms\n", run_time);
    return 0;
}