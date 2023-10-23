#include<stdio.h>

int main() {
    int x1, x2; // 32-bit 整数 2^31-1 
    unsigned y; // 32-bit 无符号整数 2^32-1
    char c1, c2; // 8-bit 字符 根据以下部分代码增加变量c2

    x1 = 65535; // 2^16-1 < 2^31-1
    x2 = x1 + 5; // 2^16-1 + 5 < 2^31-1
    printf("enter y:\n"); // 揣摩原来代码的意图：输入y的值
    scanf("%d", &y); // 获取输入的值
    c1 = 97; c2 = 'A'; c2 = c2 + 32; // c1='a', c2=65, c2=65+32=97='a'

    printf("x1=%d, x2=%d, y=%d, c1=%c, c2=%c\n", x1, x2, y+15, c1, c2); // 输出x1, x2, y+15, c1, c2的值

    return 0;
}   
 