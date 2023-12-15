#include <stdio.h>
#include <stdlib.h>

int column_index(int i, int n, int N) { return i+n <= N ? i+n : (i+n)%N; }

int get_sum(int a[10][10], int n) {
    int sum = 0;
    for (int i=0; i<10; ++i) sum += *(*(a+i) + column_index(i, n, 10));
    return sum;
}

int main() {
    int a[10][10] = {0};
    for (int i = 0; i < 100; ++i) *(*a+i) = i;
    int n; scanf("%d", &n);
    printf("%d\n", get_sum(a, n));
    return 0;
}