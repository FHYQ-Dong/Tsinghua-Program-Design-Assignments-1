#include <stdio.h>

typedef struct {
    long long numerator;
    unsigned long long denominator;
} Fraction;

long long lgcd(long long a, long long b) {
    long long t;
    while (b) {
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}
Fraction Fra_normalize(Fraction a) {
    if (a.denominator == 0) {
        a.numerator = 0;
        return a;
    }
    long long gcd;
    gcd = lgcd(a.numerator, a.denominator);
    a.numerator /= gcd;
    a.denominator /= gcd;
    return a;
}
Fraction Fra_add(Fraction a, Fraction b) {
    if (a.denominator == 0 || b.denominator == 0) {
        Fraction c;
        c.numerator = 0;
        c.denominator = 0;
        return c;
    }
    Fraction c;
    long long gcd;
    c.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
    c.denominator = a.denominator * b.denominator;
    return Fra_normalize(c);
}
Fraction Fra_sub(Fraction a, Fraction b) {
    if (a.denominator == 0 || b.denominator == 0) {
        Fraction c;
        c.numerator = 0;
        c.denominator = 0;
        return c;
    }
    Fraction c;
    long long gcd;
    c.numerator = a.numerator * b.denominator - b.numerator * a.denominator;
    c.denominator = a.denominator * b.denominator;
    return Fra_normalize(c);
}
double Fra_to_Double(Fraction a) {
    return (double)a.numerator / a.denominator;
}
int main() {
    Fraction ans = {0, 1}, tmp;
    for (int i=1; i<=10; ++i) {
        tmp.numerator = (i%2 ? 1 : -1);
        tmp.denominator = 2*i - 1;
        ans = Fra_add(ans, tmp);
    }
    ans.numerator *= 4;
    ans = Fra_normalize(ans);
    printf("%lld/%lld %lf", ans.numerator, ans.denominator, Fra_to_Double(ans));
    return 0;
}