#include<stdio.h>

int main() {
    int a, digit[20] = {0}, len = 0;
    scanf("%d", &a);
    while(a) {
        ++len;
        digit[len] = a % 10;
        a /= 10;
    }
    printf("length: %d\n", len);
    printf("digits: ");
    for(int i = len; i >= 1; --i) printf("%d ", digit[i]);
    printf("\n");
    printf("reverse: ");
    for(int i = 1; i <= len; ++i) printf("%d ", digit[i]);
    return 0;
}