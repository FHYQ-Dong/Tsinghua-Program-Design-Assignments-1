#include "Student.h"
#include <stdio.h>

bool cmp_score(const Student a, const Student b) { return a.score < b.score; }
bool cmp_id(const Student a, const Student b) { return a.id < b.id; }

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

Student* search_student(const Student* beg, const Student* end, int id) {
    if (beg >= end) return NULL;
    const Student *l = beg, *r = end - 1;
    while (l < r) {
        const Student* mid = l + (r - l) / 2;
        if (mid->id == id) return (Student*)mid;
        else if (mid->id < id) l = mid + 1;
        else r = mid - 1;
    }
    if (l->id == id) return (Student*)l;
    return NULL;
}

void print_student_info(const Student* beg, const Student* end) {
    printf("id\tname\tsex\tbirthday\tscore\n");
    printf("------------------------------------------------\n");
    for (const Student* p=beg; p<end; ++p) 
        printf("%d\t%s\t%s\t%s\t%.2lf\n", p->id, p->name, stoa(p->sex), dtos(p->birthday), p->score);
}