#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char beg, end;
    char s[150];
    memset(s, 0, sizeof(s));
    scanf("%c\n%c\n", &beg, &end);
    fgets(s, 150, stdin); // get a line
    
    char* his = NULL;
    for (char* p = s; *p != '\0'; ++p) {
        if (*p == beg) his = p;
        if (*p == end) {
            if (his == NULL) {
                printf("Error: no matching '%c' for '%c' at %d\n", beg, end, p-s);
                return 0;
            }
            for (char* q = his+1; q < p; ++q) printf("%c", *q);
            printf("\n");
            his = NULL;
        }
    }
    return 0;
}