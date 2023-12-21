#pragma once
typedef struct Date {
    int year;
    int month;
    int day;
} Date;
int dtoi(const Date date);
Date itod(const int date);