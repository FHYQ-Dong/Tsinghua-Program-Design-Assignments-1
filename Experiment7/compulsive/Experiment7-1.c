#include<stdio.h>
#include<math.h>

double f(double x);
double S(double a, double b, double m);

int main() {
    int a = -1, b = 1;
    double m = 10000;
    printf("%.4lf",S(a, b, m));
    return 0;
}

double f(double x) {
    return exp(x * x * (-1));
}

double S(double a, double b, double m) {
    double h = (b - a) / m;
    double sum = 0;
    for (int i = 1; i < m; i++) sum += f(a + i * h);
    return (f(a) + f(b) + 2 * sum) * h / 2;
}