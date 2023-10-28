#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define true 1
#define false 0
typedef int bool;

bool* ertosthenes(bool *is_prime, int N) {
    for (int i = 2; i <= N; i++) {
        if (is_prime[i]) {
            for (int j = i * 2; j <= N; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

int main() {
    int N;
    scanf("%d", &N);

    if (N % 2 == 1 || N < 4) {
        printf("Input Error");
        return 0;
    }

    int* is_prime = (int*)malloc(sizeof(int) * (N + 1));

    for (int i = 0; i <= N; ++i) is_prime[i] = true;
    is_prime = ertosthenes(is_prime, N);

    for (int i = 2; i <= N; ++i) {
        if(is_prime[i] && is_prime[N-i]) {
            printf("%d=%d+%d\n", N, i, N-i);
            return 0;
        }
    }
    return 0;
}