#include "FileHandler.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int string_len;

string_len write_line(FILE* fp, const char* str) {
    string_len len = strlen(str);
    fwrite(str, sizeof(char), len, fp);
    fwrite("\n", sizeof(char), 1, fp);
    return len;
}

string_len write_student(FILE* fp, const Student student) {
    string_len len = 0;
    len += write_line(fp, student.id);
    len += write_line(fp, student.name);
    len += write_line(fp, (int)(student.sex)-'0');
    char date[11]; strcpy(date, itoa(dtoi(student.birthday), date, 10));
    len += write_line(fp, date);
    len += write_line(fp, student.score);
}

FILE_CONDITION save(const Student* beg, const Student* end, const char* filename) {
    FILE* fp = fopen(filename, "wb");
    if (fp == NULL) return FILE_ERROR;
    char c = end - beg + '0';
    fwrite(c, sizeof(int), 1, fp);
    fwrite("\n", sizeof(char), 1, fp);
    for (const Student *p=beg; p<end; ++p) {

    }
    fwrite(beg, sizeof(Student), end - beg, fp);
    fclose(fp);
    return FILE_OK;
}

FILE_CONDITION load(Student* beg, Student* end, const char* filename) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) return FILE_ERROR;
    int buf;
    fread(&buf, sizeof(int), 1, fp);
    fread(beg, sizeof(Student), end - beg, fp);
    fclose(fp);
    return FILE_OK;
}

FILE_CONDITION load_cnt(int* cnt, const char* filename) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) return FILE_ERROR;
    fread(cnt, sizeof(int), 1, fp);
    fclose(fp);
    return FILE_OK;
}