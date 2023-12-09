#include <stdio.h>

char *a = "HAPPYNEWYEAR";
char b[] = "happynewyear";

int main() {
    int i = 8;
    printf("%c%c%s%s\n", *a, b[0], b+5, &a[5]); 
    /*
        * 输出: HhnewyearNEWYEAR
        * %c ---> *a : char *a 的第一个字符
        * %c ---> b[0] : char b[] 的第一个字符
        * %s ---> b+5 : char b[] 的第六个字符开始的字符串
        * %s ---> &a[5] : char *a 的第六个字符开始的字符串
    */
    while (*(a+i)) putchar(*(a+i++));
    /*
        * 输出: NEWYEAR
        * 因为 char *a 的结尾字符为 '\0', 所以 *(a+i) 为 '\0' 时, 循环结束。
        * i 初始值为 8, *(a+i++) 依次为 a[8], a[9], ...
    */
    return 0;
}