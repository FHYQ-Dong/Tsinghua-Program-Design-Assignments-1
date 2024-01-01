#include <stdio.h>

typedef struct {
    char name[9];
    char sex;
    int score[3];
} STU;

void f(STU *a) { // a 是指针，函数内可以直接修改 main() 中变量的值
    STU b = {"huang", 'm', 81, 92}, *p = &b;
    *a = *p;
    a->sex = 'f';
    a->score[2] = a->score[0] + a->score[1];
}

int main() {
    STU c = {"Qian", 'f', 93, 97}, *d = &c;
    f(&c); // 无论 c 是什么，统一修改为 void f() 中的 b.
    printf("%s, %c, %d, %d, %d\n", d->name, d->sex, d->score[0], d->score[1], d->score[2]);
    return 0;
}