#pragma once
typedef enum{FILE_OK, FILE_ERROR} FILE_CONDITION;
#include "Student.h"

FILE_CONDITION save(const Student* beg, const Student* end, const char* filename);
FILE_CONDITION load(Student** students, int* student_cnt, const char* filename);