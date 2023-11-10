#include<stdio.h>
#include<math.h>

int main() {
    double cnt;
    for(int i=1; i<=1000; ++i) cnt += log10((double)(i));
    printf("%.0lf", cnt);
    return 0;
}