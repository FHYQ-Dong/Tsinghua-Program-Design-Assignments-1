#include<stdio.h>

int cnt[10] = {0};

int main() {
    int a;
    scanf("%d", &a);
    while(a) {
        ++cnt[a % 10];
        a /= 10;
    }
    for(int i = 5; i <= 7; ++i) printf("%d ",cnt[i]);
    return 0;
}