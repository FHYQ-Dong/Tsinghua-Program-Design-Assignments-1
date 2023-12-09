#include <stdio.h>
#include <string.h>
#define MAXN 100001
typedef char bool;
#define true 1
#define false 0

void qsort(char *begin, char *end, bool (*cmp)(char, char)) {
    if (begin >= end) return;
    char *pivot = begin;
    char *left = begin, *right = end;
    while (left < right) {
        while (left < right && !cmp(*right, *pivot)) --right;
        while (left < right && cmp(*left, *pivot)) ++left;
        if (left < right) {
            char temp = *left;
            *left = *right;
            *right = temp;
        }
    }
    char temp = *left;
    *left = *pivot;
    *pivot = temp;
    qsort(begin, left-1, cmp);
    qsort(left+1, end, cmp);
    return;
}

bool cmp(char a, char b) { return a > b; }

int main() {
    char s[MAXN], t[MAXN];
    scanf("%s", s); scanf("%s", t);
    int lengthS = strlen(s), lengthT = strlen(t);
    if (lengthS != lengthT) {
        printf("0");
        return 0;
    }
    else {
        qsort(s, s+lengthS-1, cmp);
        qsort(t, t+lengthT-1, cmp);
        for (int i = 0; i < lengthS; ++i) {
            if (s[i] != t[i]) {
                printf("0");
                return 0;
            }
        }
        printf("1");
    }
    return 0;
}