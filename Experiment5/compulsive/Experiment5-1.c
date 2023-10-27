#include<stdio.h>
#define true 1
#define false 0
typedef int bool;

bool check_tri(int x, int y, int z) {
    if (x + y > z && x + z > y && y + z > x) {
        return true;
    }
    return false;
}

int main() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if(check_tri(a, b, c)) {
        if (a==b && a==c) printf("Equilateral triangle\n");
        else if (a==b || a==c || b==c) printf("Isosceles triangle\n");
        else printf("Triangle\n");
    }
    else printf("Not triangle\n");
    return 0;
}