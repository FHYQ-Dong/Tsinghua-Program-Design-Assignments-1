#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char bool;
#define true 1
#define false 0
typedef char* string;

void readstr(string* c, int N) {
    for (int i = 0; i < N; i++) {
        c[i] = (string)malloc(100 * sizeof(char));
        memset(c[i], 0, 100 * sizeof(char));
        scanf("%s", c[i]);
    }
    return;
}

bool cmp(string a, string b) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] < b[i]) return true;
        if (a[i] > b[i]) return false;
        i++;
    }
    if (a[i] == '\0') return true;
    return false;
}

void swap(string* a, string* b) {
    string temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void qsortstr(string* begin, string* end, bool (*cmp)(string a, string b)) {
    if (begin >= end) return;
    string* pivot = begin;
    string* left = begin;
    string* right = end - 1;
    while (left < right) {
        while (left < right && cmp(*pivot, *right)) 
            right--;
        while (left < right && cmp(*left, *pivot)) 
            left++;
        if (left < right) swap(left, right);
    }
    swap(pivot, left);
    qsortstr(begin, left, cmp);
    qsortstr(left + 1, end, cmp);
    return;
}

int main() {
    int N; scanf("%d", &N);
    string* c = (string *)malloc(N * sizeof(string *));
    readstr(c, N);

    qsortstr(c, c + N, cmp);
    for (int i = 0; i < N; i++) printf("%s\n", c[i]);
    
    for (int i = 0; i < N; i++) free(c[i]);
    free(c);
    return 0;
}