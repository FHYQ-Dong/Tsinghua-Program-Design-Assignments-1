#include <stdio.h>

double calc_S(int n) {
    int S = 0, sub_S = 0;
    for(int k=1; k<=n; ++k) {
        sub_S += k * k;
        S += sub_S * k;
    }
    return S;
}

double calc_NS(int n) {
    return (double)(n) * (n+1) * (n+2) * (8*n*n + 11*n + 1) / 120;
}

int main() {
    int n = 50;
    double S = calc_S(n), NS = calc_NS(n);
    if (S>NS) puts("1");
    else if (S<NS) puts("-1");
    else puts("0");
    return 0;
}