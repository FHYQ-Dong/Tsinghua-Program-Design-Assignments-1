    #include <stdio.h>
    #include <string.h>
    typedef char bool;
    #define true 1
    #define false 0

    int main() {
        char sA[50], sB[50];
        bool found = false;
        scanf("%s", sA); scanf("%s", sB);
        int lengthA = strlen(sA), lengthB = strlen(sB);
        for (int i=0; i<lengthA; ++i) {
            bool flag = true;
            for (int j=0; j<lengthB; ++j) {
                if (i+j >= lengthA) {
                    flag = false;
                    break;
                }
                if (sB[j] == '?') continue;
                else {
                    if (sA[i+j] != sB[j]) {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag) {
                printf("%d ", i);
                found = true;
            }
        }
        if (!found) printf("No match found");
        return 0;
    }