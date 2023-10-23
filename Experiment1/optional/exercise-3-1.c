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
 