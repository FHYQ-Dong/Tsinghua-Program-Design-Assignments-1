#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char buf, *str;
    int len = 0;
    while ((buf = getchar()) != EOF) {
        if (buf == '#') break;
        str = (char *)realloc(str, (len+1)*sizeof(char));
        str[len++] = buf;
    }
    str = (char *)realloc(str, (len+1)*sizeof(char));
    str[len] = '\0';
    for (int i=0; i<len; ++i) str[i] = str[i] > 'a' && str[i] < 'z' ? str[i] - 'a' + 'A' : str[i];
    
    FILE* fin = fopen("upper.txt", "w");
    if (fin == NULL) return 1;
    fprintf(fin, "%s", str);
    fclose(fin);

    FILE* fout = fopen("upper.txt", "r");
    if (fout == NULL) return 1;
    fscanf(fout, "%s", str);
    printf("%s", str);
    fclose(fout);
    return 0;
}