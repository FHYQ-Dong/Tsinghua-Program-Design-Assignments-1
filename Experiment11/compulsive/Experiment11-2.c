#include <stdio.h>
#include <string.h>
#define s(x) scanf("%d", &(x))
#define p(x) printf("%d ", x)

int del(int n, int *people[]) {
    int cnt = 1, idx = 1;
    while (people[idx] != -1) {
        if (idx == 3) {
            int idx_tmp = people[idx];
            people[idx] = -1;
            idx = idx_tmp;
        }
        else {
            ++cnt;
            idx = people[idx];
        }
    }
    return idx;
}

int main() {
    int* people[51], n;
    s(n);
    for (int i=1; i<=n; ++i) people[i] = &people[i % n + 1];
    int res = del(n, people);
    p(res);
    return 0;
}