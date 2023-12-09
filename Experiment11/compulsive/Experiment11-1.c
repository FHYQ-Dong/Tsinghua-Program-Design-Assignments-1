#include <stdio.h>
typedef char bool;
#define true 1
#define false 0

void qsort(int* begin, int *end, bool (*cmp)(int, int)) {
    if (begin >= end) return;
    int *l = begin, *r = end-1, *p = begin;
    while (l < r) {
        while (l < r && cmp(*p, *r)) --r;
        while (l < r && cmp(*l, *p)) ++l;
        if (l < r) {
            int t = *l;
            *l = *r;
            *r = t;
        }
    }
    int t = *l;
    *l = *p;
    *p = t;
    qsort(begin, l, cmp);
    qsort(l+1, end, cmp);
    return;
}

bool cmp(int a, int b) { return a < b; }

void merge(int* source1, int* source2, int* dest) {
    int *p1 = source1, *p2 = source2, *p = dest;
    while (p1 < source1+10 && p2 < source2+10) {
        if (*p1 < *p2) *(p++) = *(p1++);
        else *(p++) = *(p2++);
    }
    while (p1 < source1+10) *(p++) = *(p1++);
    while (p2 < source2+10) *(p++) = *(p2++);
    return;
}

int main() {
    int a[10], b[10], res[20];
    for (int i=0; i<10; ++i) scanf("%d", &a[i]);
    for (int i=0; i<10; ++i) scanf("%d", &b[i]);
    qsort(a, a+10, cmp); qsort(b, b+10, cmp);
    merge(a, b, res);
    for (int i=0; i<20; ++i) printf("%d ", res[i]);
    return 0;
}