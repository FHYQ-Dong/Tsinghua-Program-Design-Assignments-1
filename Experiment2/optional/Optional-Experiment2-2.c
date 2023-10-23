#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXN 100005 // 最长明文长度 

char opt; // 操作 e:加密 d:解密
int K; // 密钥
int c_int[MAXN], m_int[MAXN]; // 密文整数数组, 明文整数数组。// 担心溢出，所以用整数数组
char C[MAXN], M[MAXN]; // 密文, 明文

int my_atoi(char c) { // 字符转整数
    return c - '0';
}

char my_itoa(int n) { // 整数转字符
    return n + '0';
}

void encrypt() { // 加密
    int len = strlen(M); // 明文长度
    for(int i=0; i<len; ++i) {
        m_int[i] = my_atoi(M[i]);
        c_int[i] = (m_int[i] + K) % ('~' - '0');
        C[i] = my_itoa(c_int[i]);
    }
    return;
}

void decrypt() { // 解密
    int len = strlen(C); // 密文长度
    for(int i=0; i<len; ++i) {
        c_int[i] = my_atoi(C[i]);
        m_int[i] = (c_int[i] - K) % ('~' - '0');
        while(m_int[i] < 0) m_int[i] += ('~' - '0'); // 防止负数
        M[i] = my_itoa(m_int[i]);
    }
    return;
}

int main() {
    printf("enter your option(e:encrypt d:decrypt):\n");
    scanf("%c", &opt); // 获取操作

    if(opt == 'e') {
        printf("enter your string to be encrypted(max:100000 characters):\n"); 
        scanf("%s", &M);
        printf("enter your key:\n");
        scanf("%d", &K); // 获取密钥

        encrypt(); // 加密

        printf("the encrypted string is:\n%s", C); // 输出密文
        return 0;
    }

    else if(opt == 'd'){
        printf("enter your string to be decrypted(max:100000 characters):\n"); 
        scanf("%s", &C); // 获取密文
        printf("enter your key:\n");
        scanf("%d", &K); // 获取密钥

        decrypt(); // 解密

        printf("the decrypted string is:\n%s", M); // 输出明文
        return 0;
    }

    else {
        printf("invalid option! Please enter 'e' or 'd'.\n");
        return 1;
    }

    return 0;
}
 