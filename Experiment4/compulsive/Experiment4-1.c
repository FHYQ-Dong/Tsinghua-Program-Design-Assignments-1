#include<stdio.h>
#include<math.h>
#define pi acos(-1)

void print_exp() {
    double x = 0;
    scanf("%lf", &x);
    double tmp = exp(-0.5 * x * x);
    printf("f(x) = %lf\n", (1/sqrt(2 * pi)) * tmp);
    return;
}

void printf_sin_cos() {
    double x = 0, y = 0;
    scanf("%lf %lf", &x, &y);
    printf("f(x, y) = %lf\n", (double)(1)/3 * sin(x*x + y*y) * cos(x+y));
    return;
}

int main() {
    print_exp();
    printf_sin_cos();
    return 0;
}