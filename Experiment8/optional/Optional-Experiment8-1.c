#include <stdio.h>
#define true 1
#define false 0
typedef char bool;

int chick_feet[720+1], rabbit_feet[720+1], tmp_perm[6];
bool visit[6];
int cnt, rabbit_cnt, chick_cnt;

void all_permutation(int depth) {
    if (depth == 6) {
        int sum_chick = 0, sum_rabbit = 0;
        for (int i = 0; i < 3; i++) {
            sum_chick *= 10; sum_rabbit *= 10;
            sum_chick += tmp_perm[i]; sum_rabbit += tmp_perm[i+3];
        }
        chick_feet[++cnt] = sum_chick; rabbit_feet[cnt] = sum_rabbit;
        return;
    }
    for (int i = 0; i < 6; i++) {
        if (visit[i]) continue;
        visit[i] = 1;
        tmp_perm[depth] = i;
        all_permutation(depth+1);
        visit[i] = 0;
    }
    return;
}

int main() {
    all_permutation(0);
    for (int i=1; i<=cnt; i++) {
        if (!(chick_feet[i] / 100) || !(rabbit_feet[i] / 100)) continue;
        if (chick_feet[i] % 2 || rabbit_feet[i] % 4) continue;
        chick_cnt = chick_feet[i] / 2; rabbit_cnt = rabbit_feet[i] / 4;
        if (chick_cnt == rabbit_cnt) {
            printf("Chick: %d, Chick_feet: %d, Rabbit: %d, Rabbit_feet: %d\n", \
                chick_cnt, chick_feet[i], rabbit_cnt, rabbit_feet[i]);
        }
    }
    return 0;
}