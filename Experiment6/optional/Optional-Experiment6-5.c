#include<stdio.h>

int x, cnt, ans4, ans6;
int digit[6], alternative[121];

int abs(int x) {
    return x > 0 ? x : -x;
}
int min(int x, int y) {
    return x < y ? x : y;
}

void all_permutation(int ans, int depth) {
    if (depth == 5) {
        alternative[++cnt] = ans;
        return;
    }
    for(int i=1; i<=5; ++i) {
        if (digit[i] == -1) continue;
        int tmp = digit[i];
        digit[i] = -1;
        all_permutation(ans*10+tmp, depth+1);
        digit[i] = tmp;
    }
    return;
}

int main() {
    scanf("%d", &x);
    if (x <= 9999 || x>= 100000) {
        printf("Input Error\n");
        return 0;
    }
    for (int i=1; i<=5; ++i) {
        digit[i] = x % 10;
        x /= 10;
    }
    all_permutation(0, 0);
    ans4 = x; ans6 = x;
    for (int i=1; i<=cnt; ++i) {
        if (abs(ans4 - 40000) > abs(alternative[i] - 40000)) ans4 = alternative[i];
        if (abs(ans6 - 60000) > abs(alternative[i] - 60000)) ans6 = alternative[i];
    }
    printf("ans4 = %d\n", ans4);
    printf("ans6 = %d\n", ans6);
    return 0;
}