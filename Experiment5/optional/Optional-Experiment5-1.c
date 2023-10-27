#include<stdio.h>

int ihour, iminute;
char shour, sminute;
const char spell_20[21][15] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", 
                "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", 
                "seventeen", "eighteen", "nineteen", "twenty"};
const char spell_50[6][10] = {"0", "0", "twenty", "thirty", "forty", "fifty"};

void print_hour() {
    if(ihour <= 20) {
        printf("%s", spell_20[ihour]);
    }
    else {
        printf("%s %s", spell_50[ihour / 10], spell_20[ihour % 10]);
    }
    return;
}

void print_minute() {
    if(iminute <= 20) {
        printf("%s", spell_20[iminute]);
    }
    else {
        switch (iminute % 10) {
            case 0: printf("%s", spell_50[iminute / 10]); break;
            default: printf("%s %s", spell_50[iminute / 10], spell_20[iminute % 10]);
        }
    }
    return;
}

void print_time() {
    if(iminute == 0) {
        print_hour();
        printf(" o'clock\n");
    }
    else {
        print_hour();
        printf(" ");
        print_minute();
        printf("\n");
    }
}

int main() {
    scanf("%d\t%d", &ihour, &iminute);
    print_time();
    return 0;
}