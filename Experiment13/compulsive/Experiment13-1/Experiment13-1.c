#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./include/bool.h"
#include "./include/Date.h"
#include "./include/Student.h"
#include "./include/FileHandler.h"
#include "./include/args.h"

void read_student(Student* student) {
    int id, birthday; double score; char name[100]; char sex[7];
    scanf("%d", &id); scanf("%s", name); scanf("%s", sex); scanf("%d", &birthday); scanf("%lf", &score);
    student->id = id;
    strcpy(student->name, name);
    student->sex = atos(sex);
    student->birthday = itod(birthday);
    student->score = score;
}

int main(int argc, char const *argv[]) {
    ARGS args = split_args(argc, argv);
    switch (args.command) {

        case COMMAND_HELP: {
            print_usage();
            _exit(0);
        }

        case COMMAND_SAVE: {
            int student_cnt; printf("Input the number of students: "); scanf("%d", &student_cnt);
            Student* students = (Student*)malloc(sizeof(Student) * student_cnt);
            memset(students, 0, sizeof(Student) * student_cnt);
            printf("Input the students' info: \n");
            printf("id\tname\tsex\tbirthday\tscore\n");
            printf("------------------------------------------------\n");
            for (int i=0; i<student_cnt; ++i) read_student(students + i);
            sort_student(students, students + student_cnt, cmp_score);
            FILE_CONDITION condition = save(students, students + student_cnt, args.filename);
            if (condition != FILE_OK) {
                printf("Error: Cannot save to %s\n", args.filename);
                _exit(1);
            }
            free(students);
            printf("Saved to %s\n", args.filename);
            _exit(0);
        }

        case COMMAND_SEARCH: {
            Student* students = NULL; int student_cnt;
            FILE_CONDITION condition;
            condition = load(&students, &student_cnt, args.filename);
            if (condition != FILE_OK) {
                printf("Error: Cannot load from %s\n", args.filename);
                _exit(1);
            }
            sort_student(students, students + student_cnt, cmp_id);
            int id;
            while (true) {
                printf("Input the id (-1 for quit): "); scanf("%d", &id);
                if (id == -1) break;
                Student* student = search_student(students, students + student_cnt, id);
                if (student == NULL) printf("Not found\n");
                else print_student_info(student, student + 1);
            }
            free(students); students = NULL;
            _exit(0);
        }

        case COMMAND_EVEN: {
            Student* students = NULL; int student_cnt;
            FILE_CONDITION condition;
            condition = load(&students, &student_cnt, args.filename);
            if (condition != FILE_OK) {
                printf("Error: Cannot load from %s\n", args.filename);
                _exit(1);
            }
            printf("Even score: %lf\n", even_score(students, students + student_cnt));
            free(students); students = NULL;
            _exit(0);
        }
        case COMMAND_ALL: {
            Student* students = NULL; int student_cnt;
            FILE_CONDITION condition;
            condition = load(&students, &student_cnt, args.filename);
            if (condition != FILE_OK) {
                printf("Error: Cannot load from %s\n", args.filename);
                _exit(1);
            }
            print_student_info(students, students + student_cnt);
            free(students); students = NULL;
            _exit(0);
        }
    }
    return 0;
}