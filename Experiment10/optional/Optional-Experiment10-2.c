#include <stdio.h>
#include <string.h>

int aton(const char s[]) {
    int res = 0, tmp = 0;
    int p = 0;
    while(s[p]) {
        if (s[p] == '.') {
            res = (res << 8) + tmp;
            tmp = 0;
        }
        else tmp = tmp * 10 + (s[p] - '0');
        ++p;
    }
    return (res << 8) + tmp;
}

int main() {
    char s[100];
    scanf("%s", s);
    printf("%d", aton(s));
    return 0;
}