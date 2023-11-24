#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    FILE *fout = fopen("input.txt", "w");
    int n = rand() % 400 + 100;
    fprintf(fout, "%d\n", n);
    for (int i=0; i<n; ++i) {
        fprintf(fout, "%d ", rand() % 10000 + 1);
    }
    return 0;
}