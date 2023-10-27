#include<stdio.h>
#define true 1
#define false 0
typedef int bool;
typedef struct Result Result;

struct Result {
    double res;
    bool err;
};

Result One_Result(double r, bool e) {
    Result tmp;
    tmp.res = r;
    tmp.err = e;
    return tmp;
}

Result operate(Result x, Result y, char op) {
    if (x.err || y.err) return One_Result(0, true);
    double a = x.res, b = y.res;
    if (op == '/' && b == 0) return One_Result(0, true);
    switch (op) {
        case '+': return One_Result(a + b, false);
        case '-': return One_Result(a - b, false);
        case '*': return One_Result(a * b, false);
        case '/': return One_Result(a / b, false);
    }
}

Result a, b, c, d;
char op;

int main() {
    scanf("%c %lf %lf %lf %lf", &op, &a.res, &b.res, &c.res, &d.res);
    Result res = operate(operate(operate(a, b, op), c, op), d, op);
    if(res.err) printf("input error\n");
    else printf("%lf\n", res.res);
    return 0;
}