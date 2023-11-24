#include <stdio.h>

int main() {
    int animal_cnt = 0, feet_cnt = 0;
    scanf("%d%d", &animal_cnt, &feet_cnt);
    int rabbit_cnt = 0, chicken_cnt = 0;

    if (feet_cnt % 2 == 1) {
        printf("No answer.\n");
        return 0;
    }
    rabbit_cnt = (feet_cnt - 2 * animal_cnt) / 2; // 抬起两只脚
    chicken_cnt = animal_cnt - rabbit_cnt;
    if (rabbit_cnt < 0 || chicken_cnt < 0) {
        printf("No answer.\n");
        return 0;
    }
    printf("Rabbit: %d\nChicken: %d\n", rabbit_cnt, chicken_cnt);
    return 0;
}