#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef enum {false, true} bool;
typedef enum {NAM, male, female} SEX;
const int MAXN = 1;

char* stoa(SEX s) {
    if (s == male) return "male";
    else if (s == female) "female";
    else return "NAM";
}
SEX atos(char c[7]) {
    if (strcmp(c, "male") == 0) return male;
    else if (strcmp(c, "female") == 0) return female;
    else return NAM;
}

typedef struct Date {
    int year;
    int month;
    int day;
} Date;
int dtoi(const Date date) { return date.year * 10000 + date.month * 100 + date.day; }
Date itod(const int date) {
    Date d;
    d.year = date / 10000;
    d.month = date % 10000 / 100;
    d.day = date % 100;
    return d;
}

typedef struct {
    int id;
    char name[100];
    double score;
    Date birthday;
    SEX sex;
} Student;

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

int main() {
    Student* students = (Student*)malloc(sizeof(Student) * MAXN);
    memset(students, 0, sizeof(Student) * MAXN);
    for (int i=0; i<MAXN; ++i) {  
        int id, birthday; double score; char name[100]; char sex[7];
        scanf("%d %s %s %d %lf", &id, name, sex, &birthday, &score);
        students[i].id = id;
        strcpy(students[i].name, name);
        students[i].sex = atos(sex);
        students[i].birthday = itod(birthday);
        students[i].score = score;
    }
    printf("even score: %.2lf\n", even_score(students, students + MAXN));
    sort_student(students, students + MAXN, cmp);
    print_student_info(students, students + MAXN);
    return 0;
}