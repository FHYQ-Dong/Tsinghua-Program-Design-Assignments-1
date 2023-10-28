#include<stdio.h>
#define true 1
#define false 0
typedef int bool;

bool is_prime[105];

void ertosthenes() {
    for (int i = 2; i <= 100; i++) {
        is_prime[i] = true;
    }
    for (int i = 2; i <= 100; i++) {
        if (is_prime[i]) {
            for (int j = i * 2; j <= 100; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return;
}

int main() {
    ertosthenes();
    for(int i=2; i<=100; ++i) {
        if(is_prime[i] && is_prime[i+2]) {
            printf("%d %d\n", i, i+2);
        }
    }
    return 0;
}