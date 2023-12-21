#include "Student.h"
#include <stdio.h>

bool cmp(const Student a, const Student b) { return a.score > b.score; }

double even_score(const Student* beg, const Student* end) {
    double sum = 0;
    for (const Student* i = beg; i < end; ++i) {
        sum += i->score;
    }
    return sum / (end - beg);
}

void sort_student(Student* beg, Student* end, bool (*cmp)(const Student, const Student)) {
    if (beg >= end) return;
    Student* l = beg, * r = end - 1;
    Student mid = *l;
    while (l < r) {
        while (l < r && cmp(mid, *r)) --r;
        *l = *r;
        while (l < r && cmp(*l, mid)) ++l;
        *r = *l;
    }
    *l = mid;
    sort_student(beg, l, cmp);
    sort_student(l + 1, end, cmp);
}

void print_student_info(const Student* beg, const Student* end) {
    printf("id\tname\tsex\tbirthday\tscore\n");
    printf("------------------------------------------------\n");
    for (const Student* p=beg; p<end; ++p) 
        printf("%d\t%s\t%s\t%d\t%.2lf\n", p->id, p->name, stoa(p->sex), dtoi(p->birthday), p->score);
}