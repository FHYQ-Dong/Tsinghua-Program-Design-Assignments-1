#include<stdio.h>
#include<stdlib.h>

int main() {
    printf("(!x && x!=0) == false\n");
    printf("(!(x==a) && (y==b) && 0) == false\n");
    printf("(-10<a<5 && b==c) == false\n");
    printf("(5>3 && 2 || 8<4-!0) == true\n");
    printf("(!4<y<5 && 5<b<6) == true\n");
    printf("(!x || x!=0) == true\n");
    printf("(3<x<5 || y>3 && y<2) == true\n");
    return 0;
}