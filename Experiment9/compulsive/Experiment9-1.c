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

// Solution 1
Sheep* find_loop(Sheep s[], int n) {
    static Sheep mxSheep[102] = {-1, 0};
    mxSheep[101].weight = INF;
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=100; ++j) {
            if (mxSheep[j].weight <= s[i].weight) {
                mxSheep[j-1] = mxSheep[j];
                if (mxSheep[j+1].weight > s[i].weight) {
                    mxSheep[j] = s[i];
                    break;
                }
            }
        }
    }
    return mxSheep;
}

// Solution 2
Sheep* find_sort(Sheep s[], int n) {
    qsort_sheep(s+1, s+n+1);
    return s;
}

int main() {
    int n;
    Sheep s[(int)1e5+5];
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) scanf("%d", &s[i].weight), s[i].idx = i;
    if (n < 100) {
        printf("Error: n < 100\n");
        return 0;
    }

    // Solution 1
    Sheep* mxSheep = find_loop(s, n);
    printf("Answer1 :\nWeight\tIndex\n----------------\n");
    for (int i=100; i>=1; --i) printf("%d\t%d\n", mxSheep[i].weight, mxSheep[i].idx);

    // blank line
    printf("\n");

    // Solution 2
    mxSheep = find_sort(s, n);
    printf("Answer2 :\nWeight\tIndex\n----------------\n");
    for (int i=1; i<=100; ++i) printf("%d\t%d\n", mxSheep[i].weight, mxSheep[i].idx);

    return 0;
}