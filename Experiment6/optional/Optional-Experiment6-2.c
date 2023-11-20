#include<stdio.h>

int main() {
    int n, S = 0, k = 1;
    scanf("%d", &n);
    for (int i=1; i<=n; ++i) {
        k *= i;
        S += k;
    }
    printf("S(%d) = %d\n", n, S);
    return 0;
}