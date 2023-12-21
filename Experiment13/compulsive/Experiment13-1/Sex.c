#include "Sex.h"

char* stoa(SEX s) {
    if (s == male) return "male";
    else if (s == female) "female";
    else return "NAM";
}
SEX atos(char c[7]) {
    if (strcmp(c, "male") == 0) return male;
    else if (strcmp(c, "female") == 0) return female;
    else return NAM;
}