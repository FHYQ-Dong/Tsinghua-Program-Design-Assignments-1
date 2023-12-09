#include <stdio.h>
#include <string.h>
#define MAXN 100001
typedef char bool;
#define true 1
#define false 0

bool is_vowel(char c) { return c=='a' || c=='e' || c=='i' || c=='o' || c=='u'; }

void swap(char *a, char *b) { char t = *a; *a = *b; *b = t; }

int main() {
    char s[MAXN];
    scanf("%s", s);
    int length = strlen(s);
    int l=0, r=length-1;
    while (l<r) {
        while (l<r && !is_vowel(s[l])) ++l;
        while (l<r && !is_vowel(s[r])) --r;
        if (l<r) swap(&s[l], &s[r]);
        ++l; --r;
    }
    printf("%s", s);
    return 0;
}