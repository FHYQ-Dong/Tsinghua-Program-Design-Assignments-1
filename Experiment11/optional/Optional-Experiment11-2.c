#include <stdio.h>

void swap(int *a, int *b) { int t = *a; *a = *b; *b = t; }

void kablek(int num) {
    int digit[4];
    for (int i=0; i<4; ++i) {
        digit[i] = num % 10;
        num /= 10;
    }
    for (int i=0; i<4; ++i) for (int j=0; j<4; ++j) if (digit[j]>digit[i]) swap(&digit[i], &digit[j]);
    int min_num = 1000*digit[0] + 100*digit[1] + 10*digit[2] + digit[3], max_num = 1000*digit[3] + 100*digit[2] + 10*digit[1] + digit[0];
    int diff = max_num - min_num;
    printf("%d-%d=%d\n", max_num, min_num, diff);

    if (diff == 6174) return;
    else kablek(diff);
    return;
}

int main() {
    int a; scanf("%d", &a);
    if (a < 1000 || a > 9999) {
        printf("error\n");
        return 0;
    }
    if (a % 1111 == 0) {
        printf("error\n");
        return 0;
    }
    kablek(a);
    return 0;
}