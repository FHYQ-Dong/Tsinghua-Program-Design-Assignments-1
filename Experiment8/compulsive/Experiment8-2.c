#include<stdio.h>
#include<time.h>
#include<Windows.h>
#include<stdlib.h>

int ans[50+1];
int n;

double run_time;
LARGE_INTEGER time_start, time_over;	//开始时间，结束时间
double dqFreq;		//计时器频率
LARGE_INTEGER f;

int GoDown_recurrence(int x) {
    if(!ans[x]) ans[x] = GoDown_recurrence(x-1) + GoDown_recurrence(x-2) + GoDown_recurrence(x-3);
    return ans[x];
}

int GoDown_loop(int x) {
    for(int i = 4; i <= x; i++) ans[i] = ans[i-1] + ans[i-2] + ans[i-3];
    return ans[x];
}

void timer_init() {
    QueryPerformanceFrequency(&f);
    dqFreq=(double)f.QuadPart;
    QueryPerformanceCounter(&time_start);
}

void solve_recurrence() {
    memset(ans, 0, sizeof(ans));
    ans[1] = 1; ans[2] = 2; ans[3] = 4;
    timer_init();

    QueryPerformanceCounter(&time_start);	//计时开始
    printf("Answer_recurrence: %d\n", GoDown_recurrence(n));
    QueryPerformanceCounter(&time_over);	//计时结束
    run_time=1000*(time_over.QuadPart-time_start.QuadPart)/dqFreq;
    printf("Time_recurrence: %lfms\n", run_time);
    return;
}

void solve_loop() {
    memset(ans, 0, sizeof(ans));
    ans[1] = 1; ans[2] = 2; ans[3] = 4;
    timer_init();
    QueryPerformanceCounter(&time_start);	//计时开始
    printf("Answer_loop: %d\n", GoDown_loop(n));
    QueryPerformanceCounter(&time_over);	//计时结束
    run_time=1000*(time_over.QuadPart-time_start.QuadPart)/dqFreq;
    printf("Time_loop: %lfms\n", run_time);
    return;
}

int main() {
    scanf("%d", &n);
    solve_recurrence();
    solve_loop();
    return 0;
}