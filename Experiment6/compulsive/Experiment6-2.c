#include<stdio.h>

int main() {
    int x;
    scanf("%d", &x);
    if (x % 2 == 0 || x <= 2) printf("Input Error");
    else {
        for (int i=1; i<=(x+1)/2; ++i) {
            for (int j=1; j<=(x - 2*i + 1) / 2; ++j) printf(" ");
            for (int j=1; j<=i*2-1; ++j) printf("*");
            printf("\n");
        }
        for(int i=(x+1)/2-1; i>=1; --i) {
            for (int j=1; j<=(x - 2*i + 1) / 2; ++j) printf(" ");
            for (int j=1; j<=i*2-1; ++j) printf("*");
            printf("\n");
        }
    }
    return 0;
}