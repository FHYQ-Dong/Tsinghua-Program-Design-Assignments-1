#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Date.h"
#include "Student.h"
#include "bool.h"

const int MAXN = 1;

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