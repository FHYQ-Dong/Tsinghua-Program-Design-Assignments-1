#include <stdio.h>
typedef enum {Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday} Weekday;
char *WeekdayName[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

int main() {
    Weekday oneDay; scanf("%d", &oneDay);
    printf("%s\n", WeekdayName[oneDay-1]);
    return 0;
}