#include<stdio.h>

int main() {
    int black[4] = {0}, white[4] = {0};
    char children[7] = {'0', 'A', 'B', 'C', 'D', 'E', 'F'};
    int cnt_all = 0;
    printf("总方案数: %d\n", 20);
    for (int i=1; i<=6; ++i) {
        for (int j=i+1; j<=6; ++j) {
            for(int k=j+1; k<=6; ++k) {
                black[1] = i; black[2] = j; black[3] = k;
                int cnt_white = 0;
                for (int m=1; m<=6; ++m) {
                    if (m == i || m == j || m == k) continue;
                    white[++cnt_white] = m;
                }
                printf("第%d种方案: 黑帽子: %c%c%c, 白帽子: %c%c%c\n", ++cnt_all, children[black[1]], children[black[2]], children[black[3]], children[white[1]], children[white[2]], children[white[3]]);
            }
        }
    }
    return 0;
}