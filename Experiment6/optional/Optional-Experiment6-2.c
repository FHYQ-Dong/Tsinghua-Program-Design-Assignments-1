#include<stdio.h>

int main() {
    int S[11] = {0}, k[11] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int n;
    scanf("%d", &n);
    for (int i=1; i<=n; ++i) {
        k[i] = k[i-1] * i;
        S[i] = S[i-1] + k[i];
    }
    printf("S(%d) = %d\n", n, S[n]);
    return 0;
}