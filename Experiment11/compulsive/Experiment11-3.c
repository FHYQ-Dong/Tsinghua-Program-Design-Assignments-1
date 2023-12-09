#include <stdio.h>
typedef char bool;
typedef int* intp;
#define true 1
#define false 0 

void bsort(intp* begin, intp* end, bool (*cmp)(intp, intp)) {
    if (begin >= end) return;
    for (intp* i = begin; i < end; ++i) {
        for (intp* j = i+1; j < end; ++j) {
            if (cmp(*j, *i)) {
                intp t = *i;
                *i = *j;
                *j = t;
            }
        }
    }
    return;
}

bool cmp(intp a, intp b) { return *a < *b; }

int main() {
    int a[10];
    intp pa[10];
    for (int i=0; i<10; ++i) scanf("%d", &a[i]), pa[i] = &a[i];
    bsort(pa, pa+10, cmp);
    for (int i=0; i<10; ++i) printf("%d ", *pa[i]);
    printf("\n");
    for (int i=0; i<10; ++i) printf("%d ", pa[i]-a);
}