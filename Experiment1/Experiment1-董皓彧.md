# Experiment1-董皓彧

**环境：**

```txt
Visual Stdio Code 1.82.2
gcc.exe (x86_64-win32-seh-rev0, Built by MinGW-W64 project) 8.1.0
```

## 必做题

### 所有编译错误：

- 代码：

  ```c
  #include “stdio.h”;
  main()
  { int a,b;
     c=getchar()
     scanf("%d%d",&a,&b); 
     putchar(c);
     printf("%d,%d\n",a,b) 
     system(“pause”);
  }
  
  ```
- 详细信息：

  ```txt
  Error: [line:1, column:1] 应输入文件名
  Error: [line:1, column:10] #include expects "FILENAME" or <FILENAME>
  Error: [line:4, column:4] 'c' undeclared (first use in this function)
  Error: [line:4, column:4] 未定义标识符 'c'
  Error: [line:4, column:15] expected ';' before 'scanf'
  Error: [line:5, column:4] 应输入';'
  Error: [line:7, column:25] expected ';' before 'system'
  Error: [line:8, column:4] 应输入';'
  Error: [line:8, column:11] stray '\342' in program
  Error: [line:8, column:11] 无法识别的标记
  Error: [line:8, column:11] 无法识别的标记
  Error: [line:8, column:12] stray '\200' in program
  Error: [line:8, column:13] stray '\234' in program
  Error: [line:8, column:19] stray '\342' in program
  Error: [line:8, column:20] stray '\200' in program
  Error: [line:8, column:21] stray '\235' in program
  Warning: [line:2, column:1] return type defaults to 'int' [-Wimplicit-int]
  Warning: [line:4, column:6] implicit declaration of function 'getchar' [-Wimplicit-function-declaration]
  Warning: [line:6, column:4] implicit declaration of function 'putchar' [-Wimplicit-function-declaration]
  Warning: [line:7, column:4] implicit declaration of function 'printf' [-Wimplicit-function-declaration]
  ```
- 运行截图：

  ![image-20231005205754174](C:\Users\FHYQ-Dong\AppData\Roaming\Typora\typora-user-images\image-20231005205754174.png)



### 正确代码：

- 代码：

  ```c
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
  
  ```
- 输入：

  ```txt
  a
  11 12
  ```
- 输出：

  ```txt
  a11,12
  ```
- 运行截图：

  ![image-20231005205304370](C:\Users\FHYQ-Dong\AppData\Roaming\Typora\typora-user-images\image-20231005205304370.png)



## 选做题

### 练习3-1：

- 题目：

  ```txt
  填入正确的头文件名
  ```
- 代码：

  ```c
  #include<stdio.h>
  #include<math.h>
  
  void main() {
      double a, b, z;
      printf("input a and b: ");
      scanf("%lf, %lf", &a, &b);
      z = exp(a*a + b*b);
      printf("z=%lf\n", z);
      return;
  }
  
  ```
- 输入：

  ```txt
  input a and b: 1, 2
  ```
- 输出：

  ```txt
  z=148.413159
  ```
- 运行截图：

  ![image-20231005205353421](C:\Users\FHYQ-Dong\AppData\Roaming\Typora\typora-user-images\image-20231005205353421.png)



### 练习3-2：

- 题目

  ```txt
  如果要求变量 x, y, c, d的值分别为20, 30, X, Y, 则正确的数据输入格式是什么?
  ```
- 代码：

  ```c
  #include<stdio.h>
  
  void main() {
      int x, y;
      char c, d;
      scanf("%d%d", &x, &y);
      scanf("%c%c", &c, &d);
      printf("x=%d, y=%d\nc=%c, d=%c", x, y, c, d);
      return;
  }
  
  ```
- 输入：

  ```txt
  20 30XY
  ```
- 输出：

  ```txt
  x=20, y=30
  c=X, d=Y
  ```
- 运行截图：

  ![image-20231005205445690](C:\Users\FHYQ-Dong\AppData\Roaming\Typora\typora-user-images\image-20231005205445690.png)



### 练习3-7：

- 题目

  ```txt
  编写一个C程序，将从键盘输入的小写字母转换为大写字母后输出
  ```
- 代码：

  ```c
  #include<stdio.h>
  
  void main() {
      char c;
      scanf("%c", &c);
      printf("%c\n", c - 32);
      return;
  }
  
  ```
- 输入：

  ```txt
  a
  ```
- 输出：

  ```txt
  A
  ```
- 运行截图：

  ![image-20231005205538562](C:\Users\FHYQ-Dong\AppData\Roaming\Typora\typora-user-images\image-20231005205538562.png)
