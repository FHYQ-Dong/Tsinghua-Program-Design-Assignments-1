#include<stdio.h>

int main() {

    printf("Please type in a digital:\n");
    char c = getchar(), endl = getchar();

    if(c>='0' && c<='9') {
        printf("The ascii of the given character is: %d\n", c);
        printf("The character before the given character is: %c\n", c-1);
        printf("The character after the given character is: %c\n", c+1);
        return 0;
    }
    else {
        printf("The given character is not >=0 and <=9");
        return 1;
    }

}
 