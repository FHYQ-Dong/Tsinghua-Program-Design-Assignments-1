#include<stdio.h>

int get_all_apples(int cur_child) { // 递归地求分给第 i 个孩子之前还剩下多少苹果
    if (cur_child == 5) return 11;
    else return (1 + (cur_child + 1) * get_all_apples(cur_child + 1)) / cur_child; // 通过手算得到递归式
}

void split_apples(int cur_apples) { // 分苹果
    for (int i=1; i<=4; ++i) {
        int nth_child_apples = (cur_apples + 1) / (i+1); // 第 i 个孩子分到的苹果数
        printf("The %dth child gets %d apples.\n", i, nth_child_apples);
        cur_apples -= nth_child_apples;
    }
    printf("The last child gets %d apples.\n", cur_apples); // 最后一个孩子分到的苹果数需要单独处理
    return;
}

int main() {
    int all_apples = get_all_apples(1);
    printf("The total number of apples is %d.\n", all_apples);
    split_apples(all_apples);
    return 0;
}