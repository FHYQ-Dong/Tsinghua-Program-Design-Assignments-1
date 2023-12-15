#include <stdio.h>
#include <stdlib.h>

int column_index(int i, int n, int N) { return i+n <= N ? i+n : (i+n)%N; }

int get_sum(int a[11][11], int n) {
    int sum = 0;
    for (int i=1; i<=10; ++i) sum += *(*(a+i) + column_index(i, n, 10));
    return sum;
}

int main() {
    int a[11][11] = {0};
    for (int i=1; i<=10; ++i) for (int j=1; j<=10; ++j) *(*(a+i)+j) = (i-1)*10 + (j-1);
    for (int n=0; n<10; ++n) printf("%d\n", get_sum(a, n));
    return 0;
}