#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)*time(NULL)%(int)(1e9+7));
    char in_path[] = "0.in";
    for (int i=1; i<=9; ++i){
        in_path[0] = i + '0';
        FILE *fout = fopen(in_path, "w");
        int n = rand() % 10000 + 100;
        fprintf(fout, "%d\n", n);
        for (int i=0; i<n; ++i) fprintf(fout, "%d ", rand() % 100000 + 1);
        fclose(fout);
    }
    return 0;
}