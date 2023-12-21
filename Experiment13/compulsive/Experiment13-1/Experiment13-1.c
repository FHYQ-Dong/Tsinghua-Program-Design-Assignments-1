#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./include/bool.h"
#include "./include/Date.h"
#include "./include/Student.h"
#include "./include/FileHandler.h"
#include "./include/args.h"

int main(int argc, char const *argv[]) {
    ARGS args = split_args(argc, argv);
    switch (args.command) {
        case COMMAND_HELP:
            print_usage();
            _exit(0);
        case COMMAND_SAVE: {
            int student_cnt; printf("Input the number of students: "); scanf("%d", &student_cnt);
            Student* students = (Student*)malloc(sizeof(Student) * student_cnt);
            memset(students, 0, sizeof(Student) * student_cnt);
            for (int i=0; i<student_cnt; ++i) {  
                int id, birthday; double score; char name[100]; char sex[7];
                scanf("%d %s %s %d %lf", &id, name, sex, &birthday, &score);
                students[i].id = id;
                strcpy(students[i].name, name);
                students[i].sex = atos(sex);
                students[i].birthday = itod(birthday);
                students[i].score = score;
            }
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
            int student_cnt; 
            FILE_CONDITION condition = load_cnt(&student_cnt, args.filename);
            if (condition != FILE_OK) {
                printf("Error: Cannot load from %s\n", args.filename);
                _exit(1);
            }
            Student* students = (Student*)malloc(sizeof(Student) * student_cnt);
            memset(students, 0, sizeof(Student) * student_cnt);
            condition = load(students, students + student_cnt, args.filename);
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
            free(students);
            _exit(0);
        }
        case COMMAND_EVEN: {
            int student_cnt; 
            FILE_CONDITION condition = load_cnt(&student_cnt, args.filename);
            if (condition != FILE_OK) {
                printf("Error: Cannot load from %s\n", args.filename);
                _exit(1);
            }
            Student* students = (Student*)malloc(sizeof(Student) * student_cnt);
            memset(students, 0, sizeof(Student) * student_cnt);
            condition = load(students, students + student_cnt, args.filename);
            if (condition != FILE_OK) {
                printf("Error: Cannot load from %s\n", args.filename);
                _exit(1);
            }
            printf("Even score: %lf\n", even_score(students, students + student_cnt));
            free(students);
            _exit(0);
        }
        case COMMAND_ALL: {
            int student_cnt; 
            FILE_CONDITION condition = load_cnt(&student_cnt, args.filename);
            if (condition != FILE_OK) {
                printf("Error: Cannot load from %s\n", args.filename);
                _exit(1);
            }
            Student* students = (Student*)malloc(sizeof(Student) * student_cnt);
            memset(students, 0, sizeof(Student) * student_cnt);
            condition = load(students, students + student_cnt, args.filename);
            if (condition != FILE_OK) {
                printf("Error: Cannot load from %s\n", args.filename);
                _exit(1);
            }
            print_student_info(students, students + student_cnt);
            free(students);
            _exit(0);
        }
    }
    return 0;
}