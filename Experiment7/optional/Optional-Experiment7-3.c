#include<stdio.h>
typedef int bool;
#define true 1
#define false 0

int a[3628800+1];
int cnt, times2, times3;
bool visit[10];

void bsort(int* a, int n) {
    int i, j, temp;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(a[j] > a[j+1]) {
                temp = a[j+1];
                a[j+1] = a[j];
                a[j] = temp;
            }
        }
    }
    return;
}

bool check(int x, int y) {
    int digitx[6], digity[6];
    for(int i = 0; i < 6; i++) {
        digitx[i] = x % 10;
        digity[i] = y % 10;
        x /= 10; y /= 10;
    }
    bsort(digitx, 6); bsort(digity, 6);
    for(int i = 0; i < 6; i++) if(digitx[i] != digity[i]) return false;
    return true;
}

void all_permutation(int ans, int depth) {
    if (depth == 6 && ans >= 100000) {
        a[++cnt] = ans;
        return;
    }
    for(int i=0; i<10; i++) {
        if(!visit[i]) {
            visit[i] = true;
            all_permutation(ans*10+i, depth+1);
            visit[i] = false;
        }
    }
    return;
}

int main() {
    all_permutation(0, 0);
    for(int i=1; i<=cnt; ++i) {
        times2 = a[i] * 2; times3 = a[i] * 3;
        if (times2 > 9999999 || times3 > 9999999) continue;
        if (check(a[i], times2) && check(a[i], times3)) {
            printf("%d\n", a[i]);
        }
    }
    return 0;
}