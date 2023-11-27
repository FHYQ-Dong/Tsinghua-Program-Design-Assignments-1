#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double drand() {
    return (double)(rand()) / rand();
}

int main() {
    srand(time(NULL)*time(NULL)%(int)(1e9+7));
    char in_path[] = "10.in";
    // for (int i=1; i<=9; ++i){
        // in_path[0] = i + '0';
        FILE *fout = fopen(in_path, "w");
        int n = rand() % 10 + 1;
        fprintf(fout, "%d\n", n);
        for (int i=1; i<=n; ++i) {
            for (int j=1; j<=n+1; ++j) {
                fprintf(fout, "%.6lf ", drand());
            }
            fprintf(fout, "\n");
        }
        fclose(fout);
    // }
    return 0;
}