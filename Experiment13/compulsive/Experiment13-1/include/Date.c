#include "Date.h"
#include <stdio.h>
Date atod(const char* date) {
    Date d;
    sscanf(date, "%d-%d-%d", &d.year, &d.month, &d.day);
    return d;
}
char* dtoa(const Date date) {
    static char str[11];
    sprintf(str, "%04d-%02d-%02d", date.year, date.month, date.day);
    return str;
}