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