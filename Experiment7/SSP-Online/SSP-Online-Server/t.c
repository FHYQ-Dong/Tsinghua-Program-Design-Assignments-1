#include<stdio.h>
#include<stdlib.h>

void f(int *i, int *j) {
    *i = *i ^ *j;
    *j = *i ^ *j;
    *i = *i ^ *j;
    return;
}

int main() {
    int i = 1, j = 2;
    f(&i, &j);
    printf("%d %d\n", i, j);
    return 0;
}