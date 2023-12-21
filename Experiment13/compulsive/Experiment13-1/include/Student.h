#pragma once
#include "bool.h"
#include "Date.h"
#include "Sex.h"

typedef struct {
    int id;
    char name[100];
    double score;
    Date birthday;
    SEX sex;
} Student;

bool cmp_score(const Student a, const Student b);
bool cmp_id(const Student a, const Student b);

double even_score(const Student* beg, const Student* end);

void sort_student(Student* beg, Student* end, bool (*cmp)(const Student, const Student));

Student* search_student(const Student* beg, const Student* end, int id);

void print_student_info(const Student* beg, const Student* end);