#include <stdio.h>
#include <stdlib.h>

int main() {
    int n; scanf("%d", &n);
    int** a = (int**)malloc(sizeof(int*) * (n+1));
    for (int i=1; i<=n; ++i) {
        *(a+i) = (int*)malloc(sizeof(int) * (n+1));
        for (int j=1; j<=n; ++j) scanf("%d", *(a+i)+j);
    }

    /* Zig-Zag
        * 二维数组 a 从 a[1][1] 开始使用
        * 以下枚举 i 的意义是枚举这样一条左上-右下对角线，在这条线上的元素 a[x][y] 满足 x+y=i
    */ 
    for (int i=2; i<=n+1; ++i) { // 左上三角：j 为每个元素的横坐标
        if (i%2 == 1) for (int j=1; j<=i-1; ++j) printf("%d ", a[j][i-j]);
        else for (int j=i-1; j>=1; --j) printf("%d ", a[j][i-j]);
    }
    for (int i=n+2; i<=2*n; ++i) { // 右下三角：j 为每个元素的纵坐标
        if (i%2 == 1) for (int j=n; i-j<=n; --j) printf("%d ", a[i-j][j]);
        else for (int j=i-n; j<=n; ++j) printf("%d ", a[i-j][j]);
    }
    return 0;
}