#include<stdio.h>

int main() {
    for(int i=1; i<100; i++) {
        for(int j=1; j+i<100; j++) {
            if (((100-i-j) % 3 == 0) && (5*i + 3*j + (100-i-j)/3 == 100)) {
                printf("%d %d %d\n", i, j, 100-i-j);
            }
        }
    }
    return 0;
}