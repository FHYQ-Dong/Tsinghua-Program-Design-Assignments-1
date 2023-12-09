#include <stdio.h>
#include <string.h>
#define scan(x) scanf("%d", &(x))
#define print(x) printf("%d ", x)
#define endl putchar('\n')

int del(int n, int* people) {
    int cnt = 1, idx = 1;
    while (people[idx] != idx) {
        if (cnt == 2) {
            people[idx] = people[people[idx]];
            idx = people[idx];
            cnt = 1;
        }
        else {
            ++cnt;
            idx = people[idx];
        }
    }
    return idx;
}

int main() {
    int people[51], n;
    scan(n);
    for (int i=1; i<=n; ++i) people[i] = i % n + 1;
    int res = del(n, people);
    print(res);
    return 0;
}