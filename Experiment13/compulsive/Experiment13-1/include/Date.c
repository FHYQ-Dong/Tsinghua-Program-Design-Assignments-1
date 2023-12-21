#include "Date.h"
int dtoi(const Date date) { return date.year * 10000 + date.month * 100 + date.day; }
Date itod(const int date) {
    Date d;
    d.year = date / 10000;
    d.month = date % 10000 / 100;
    d.day = date % 100;
    return d;
}