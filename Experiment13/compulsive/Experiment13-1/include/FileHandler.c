#include "FileHandler.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

FILE_CONDITION save(const Student* beg, const Student* end, const char* filename) {
    FILE* fp = fopen(filename, "wb");
    if (fp == NULL) return FILE_ERROR;
    fwrite((char*)beg, sizeof(Student), end - beg, fp);
    fclose(fp);
    return FILE_OK;
}

FILE_CONDITION load(Student** students, int* student_cnt, const char* filename) {
    struct stat buf;
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) return FILE_ERROR;
    fclose(fp);
    stat(filename, &buf);
    *student_cnt = buf.st_size / sizeof(Student);
    Student* stu = (Student*)malloc(sizeof(Student) * (*student_cnt));
    fp = fopen(filename, "rb");
    if (fp == NULL) return FILE_ERROR;
    fread((char*)stu, sizeof(Student), *student_cnt, fp);
    fclose(fp);
    *students = stu;
    return FILE_OK;
}