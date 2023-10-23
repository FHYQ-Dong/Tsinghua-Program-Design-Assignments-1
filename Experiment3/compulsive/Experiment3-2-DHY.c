#include<stdio.h>
#define SIZE_OF_MAP 15

int main() {
    int a = 0, b = 0;
    char c = '0', d = '0';

    printf("enter two number representing the ascii of two char: ");
    scanf("%d %d", &a, &b);

    if(a < 0 || a > 127 || b < 0 || b > 127) {
        printf("invalid input\n");
        return 0;
    }
    else {
        c = a; d = b;
        for(int i = 0; i < SIZE_OF_MAP; i++) {
            for(int j = 0; j < SIZE_OF_MAP; j++) {
                if(i == j || i + j == SIZE_OF_MAP - 1) printf("%c", c);
                else printf("%c", d);
            }
            printf("\n");
        }
    }
    return 0;
}