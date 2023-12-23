#pragma once
typedef struct Date {
    int year;
    int month;
    int day;
} Date;
Date atod(const char* date);
char* dtoa(const Date date);