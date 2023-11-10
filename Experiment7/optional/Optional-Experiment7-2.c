#include<stdio.h>

int main() {
    int a = 1800, b = 760, n = 10;
    int sum = 0;
    for(int i=0; i<n; i++) {
        sum += (a - i) * (b - i);
    }
    printf("%d", sum);
}