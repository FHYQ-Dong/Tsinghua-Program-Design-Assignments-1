#include"stdio.h"
#include"stdlib.h" // 解决调用system函数报implicit declaration of function 'system'的warning

void main() { 
   int a,b;
   char c=getchar();
   scanf("%d%d",&a,&b); 
   putchar(c);
   printf("%d,%d\n",a,b);
   system("pause");
   return;
}
 