#include<stdio.h>
#include<stdlib.h>

int ans[50+1];
int n;

int GoDown_loop(int x) {
    ans[1] = 1; ans[2] = 2; ans[3] = 4;
    for(int i = 4; i <= x; i++) ans[i] = ans[i-1] + ans[i-2] + ans[i-3];
    return ans[x];
}

int main() {
    scanf("%d", &n);
    GoDown_loop(n);
    printf("%d\n", ans[n]);
    return 0;
}