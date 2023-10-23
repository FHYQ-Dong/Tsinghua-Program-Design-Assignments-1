# Experiment3-董皓彧

**环境：**

```
Visual Studio Code 1.83.0
gcc version 8.1.0 (x86_64-win32-seh-rev0, Built by MinGW-W64 project)
cmake version 3.27.7
```

## 必做题

### 必做题1

- 代码：

  ```c
  #include<stdio.h>
  #include<stdbool.h>
  
  void printSizeOf() {
      // short, int, long, unsigned short,unsigned int, unsigned long, char, bool, double
      printf("size of short: %d\n", sizeof(short));
      printf("size of int: %d\n", sizeof(int));
      printf("size of long: %d\n", sizeof(long));
      printf("size of unsigned short: %d\n", sizeof(unsigned short));
      printf("size of unsigned int: %d\n", sizeof(unsigned int));
      printf("size of unsigned long: %d\n", sizeof(unsigned long));
      printf("size of char: %d\n", sizeof(char));
      printf("size of bool: %d\n", sizeof(bool));
      printf("size of double: %d\n", sizeof(double));
      return;
  }
  
  void testFloat() {
      float a = 1.0, history = 1.0;
      int i = 1;
      
      for(i=1; a!=0; i++) {
          history = a;
          a /= 10;
      }
      printf("float 能保留的最小精度为：%d\n", i-1);
      printf("此时 float a = %.61f\n", history);
      return;
  }
  
  int main() {
      // print size of each type;
      printSizeOf();
  
      printf("\n");
  
      // test float
      testFloat();
      return 0;
  }
  ```

- 输出：

  ```txt
  size of short: 2
  size of int: 4
  size of long: 4
  size of unsigned short: 2
  size of unsigned int: 4
  size of unsigned long: 4
  size of char: 1
  size of bool: 1
  size of double: 8
  
  float 能保留的最小精度为：46
  此时 float a = 0.0000000000000000000000000000000000000000000014012984643248171
  ```

- 运行截图：

  ![image-20231013203817112](C:\Users\FHYQ-Dong\AppData\Roaming\Typora\typora-user-images\image-20231013203817112.png)

  

### 必做题2

- 代码：

  ```c
  #include<stdio.h>
  #define SIZE_OF_MAP 15
  
  int main() {
      int a = 0, b = 0;
      char c = '0', d = '0';
  
      printf("enter two number representing the ascii of two char: ");
      scanf("%d %d", &a, &b);
  
      if(a < 0 || a > 127 || b < 0 || b > 127) {
          printf("invalid input\n");
          return 0;
      }
      else {
          c = a; d = b;
          for(int i = 0; i < SIZE_OF_MAP; i++) {
              for(int j = 0; j < SIZE_OF_MAP; j++) {
                  if(i == j || i + j == SIZE_OF_MAP - 1) printf("%c", c);
                  else printf("%c", d);
              }
              printf("\n");
          }
      }
      return 0;
  }
  ```

- 输入：

  ```txt
  enter two number representing the ascii of two char: 65 97
  ```

- 输出：

  ```txt
  AaaaaaaaaaaaaaA
  aAaaaaaaaaaaaAa
  aaAaaaaaaaaaAaa
  aaaAaaaaaaaAaaa
  aaaaAaaaaaAaaaa
  aaaaaAaaaAaaaaa
  aaaaaaAaAaaaaaa
  aaaaaaaAaaaaaaa
  aaaaaaAaAaaaaaa
  aaaaaAaaaAaaaaa
  aaaaAaaaaaAaaaa
  aaaAaaaaaaaAaaa
  aaAaaaaaaaaaAaa
  aAaaaaaaaaaaaAa
  AaaaaaaaaaaaaaA
  ```

- 运行截图：

  ![image-20231013203932636](C:\Users\FHYQ-Dong\AppData\Roaming\Typora\typora-user-images\image-20231013203932636.png)

  

### 必做题3

- 代码：

  ```c
  #include<stdio.h>
  #define MAXTIME 100005 // 最长时间
  
  struct Sheeps {
      int cntChild, cntAdult, cntAll; // 目前小羊和大羊的数量 (单位：对)
      int Value;
  };
  
  struct Sheeps aSheep(int _cntChild, int _cntAdult, int _cntAll, int _Value) { // "构造函数"
      struct Sheeps tmp;
      tmp.cntChild = _cntChild;
      tmp.cntAll = _cntAll;
      tmp.cntAdult = _cntAdult;
      tmp.Value = _Value;
      return tmp;
  }
  
  struct Sheeps dp_sheeps[MAXTIME];
  
  int main() {
      dp_sheeps[1] = aSheep(1, 0, 1, 10);
      for(int i=2; i<=6; ++i) {
          dp_sheeps[i].cntAdult = dp_sheeps[i-1].cntAdult + dp_sheeps[i-1].cntChild;
          dp_sheeps[i].cntChild = dp_sheeps[i-1].cntAdult;
          dp_sheeps[i].cntAll = dp_sheeps[i].cntAdult + dp_sheeps[i].cntChild;
          dp_sheeps[i].Value = 10 * dp_sheeps[i].cntAll;
      }
      
      printf("Time\tAll\tAdult\tChild\tValue\n");
      for(int i=1; i<=6; ++i) {
          printf("%d\t%d\t%d\t%d\t%d\n", i, dp_sheeps[i].cntAll, dp_sheeps[i].cntAdult, dp_sheeps[i].cntChild, dp_sheeps[i].Value);
      }
      return 0;
  }
  ```

- 输出：

  ```txt
  Time    All     Adult   Child   Value
  1       1       0       1       10
  2       1       1       0       10
  3       2       1       1       20
  4       3       2       1       30
  5       5       3       2       50
  6       8       5       3       80
  ```

- 运行截图：

  ![image-20231013204052474](C:\Users\FHYQ-Dong\AppData\Roaming\Typora\typora-user-images\image-20231013204052474.png)



## 选做题

- 目录结构：

  ```txt
  Optional-Exercise3
  │  CMakeLists.txt
  │  Optional-Exercise3-1.c
  │  Optional-Exercise3-1.c.bak
  │  Optional-Exercise3-1.exe
  │
  └─include
          CMakeLists.txt
          Map.c
          Map.h
          PhoneNum.c
          PhoneNum.h
  ```

- 代码：见压缩包中的 `Optional-Exercise3.tar.gz`

- 输入0：

  ```txt
  > Please input the number of phone numbers:
  3
  ```

- 输出0：

  ```txt
  无，输入0是以下多个输出的前提
  ```

- 输入1：

  ```txt
  > Please choose a option (i: insert, s: search, q:quit, l:list):
  i
  Please input the name:
  AAA
  Please input the phone number:
  11111111111
  ```

- 输出1：

  ```txt
  Insert successfully
  ```

- 输入2：

  ```txt
  > Please choose a option (i: insert, s: search, q:quit, l:list):
  i
  Please input the name:
  BBB
  Please input the phone number:
  22222222222
  ```

- 输出2：

  ```txt
  Insert successfully
  ```

- 输入3：

  ```txt
  > Please choose a option (i: insert, s: search, q:quit, l:list):
  s
  Please input the name:
  AAA
  ```

- 输出3：

  ```txt
  --------------------
  Name    Phone Number
  AAA     11111111111
  ```

- 输入4：

  ```txt
  > Please choose a option (i: insert, s: search, q:quit, l:list):
  i
  Please input the name:
  CCC
  Please input the phone number:
  33333333333
  ```

- 输出4：

  ```txt
  Insert successfully
  ```

- 输入5：

  ```txt
  > Please choose a option (i: insert, s: search, q:quit, l:list):
  s
  Please input the name:
  BBB
  ```

- 输出5：

  ```txt
  --------------------
  Name    Phone Number
  BBB     22222222222
  ```

- 输入6：

  ```txt
  > Please choose a option (i: insert, s: search, q:quit, l:list):
  s
  Please input the name:
  CCC
  ```

- 输出6：

  ```txt
  --------------------
  Name    Phone Number
  CCC     33333333333
  ```

- 输入7：

  ```txt
  > Please choose a option (i: insert, s: search, q:quit, l:list):
  i
  ```

- 输出7：

  ```
  The phone number list is full
  ```

- 输入8：

  ```txt
  > Please choose a option (i: insert, s: search, q:quit, l:list):
  s
  Please input the name:
  DDD
  ```

- 输出8：

  ```
  Not found
  ```

- 输入9：

  ```txt
  > Please choose a option (i: insert, s: search, q:quit, l:list):
  l
  ```

- 输出9：

  ```
  --------------------
  Name    Phone Number
  AAA     11111111111
  BBB     22222222222
  CCC     33333333333
  ```

- 输入10：

  ```txt
  > Please choose a option (i: insert, s: search, q:quit):
  q
  ```

- 输出10：

  ```txt
  无，程序退出
  ```

  ![image-20231013205732458](C:\Users\FHYQ-Dong\AppData\Roaming\Typora\typora-user-images\image-20231013205732458.png)

  ![image-20231013205711726](C:\Users\FHYQ-Dong\AppData\Roaming\Typora\typora-user-images\image-20231013205711726.png)