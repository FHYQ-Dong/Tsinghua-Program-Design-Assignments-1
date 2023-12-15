#include <stdio.h>
int main(int argc, char* argv[]) {
    char **p = NULL;
    for (p=argv; argc--; ++p) 
        printf("%c%s", **p, *p); 
        /*
            * *argv[] = {"test.exe", "FINAL", "EXAM"};
            * 1. p = argv[0] = "test.exe" 
            *   **p = p[0][0] = 't', *p = p[0] = "test.exe";
            * 2. p = argv[1] = "FINAL":
            *   **p = p[1][0] = 'F', *p = p[1] = "FINAL";
            * 3. p = argv[2] = "EXAM":
            *   **p = p[2][0] = 'E', *p = p[2] = "EXAM";
        */
       // result = ttest.exeFFINALEEXAM
    return 0;
}