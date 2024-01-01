#include <stdio.h>
#include <string.h>

int main() {
    char filename[100], str[100];
    scanf("%s", filename);
    FILE* fin = fopen(filename, "r");
    if (fin == NULL) {
        perror("Error");
        return 1;
    }
    if (fgets(str, 100, fin) != NULL) printf("%s\n%d", str, strlen(str));
    else perror("Error");
    fclose(fin);
    return 0;
}