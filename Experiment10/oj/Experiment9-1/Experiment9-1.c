#include <stdio.h>
#define INF 0x7fffffff

typedef struct Sheep {
    int weight, idx;
} Sheep;

void swap_sheep(Sheep *a, Sheep *b) {
    Sheep tmp = *a; *a = *b; *b = tmp;
}
int max(int a, int b) {
    return a > b ? a : b;
}


void qsort_sheep(Sheep *beg, Sheep *end) { // big-endian
    if (beg >= end) return;
    Sheep *l = beg, *r = end - 1, *p = beg;
    while (l < r) {
        while (l < r && r->weight <= p->weight) r--;
        while (l < r && l->weight >= p->weight) l++;
        if (l < r) swap_sheep(l, r);
    }
    swap_sheep(p, l);
    qsort_sheep(beg, l);
    qsort_sheep(l + 1, end);
}

// Solution 2
Sheep* find_sort(Sheep s[], int n) {
    qsort_sheep(s+1, s+n+1);
    return s;
}

int main() {
    // char in_path[100] = "11.in", out_path[] = "11.out";
    // for (int i=1; i<=9; ++i){
        // in_path[0] = i + '0'; out_path[0] = i + '0';
        // FILE *fin = stdin; //fopen(in_path, "r");
        // FILE *fout = stdout; //fopen(out_path, "w");
        int n;
        Sheep s[(int)1e5+5];
        scanf("%d", &n);
        for(int i=1; i<=n; ++i) {
            scanf("%d", &s[i].weight);
            s[i].idx = i;
        }
        if (n < 100) {
            printf("Error\n");
            return 0;
        }

        // Solution 2

        Sheep* mxSheep = find_sort(s, n);
        for (int i=1; i<=100; ++i) printf("%d %d\n", mxSheep[i].weight, mxSheep[i].idx);
        // fclose(fin); fclose(fout);
    // }
    return 0;
}