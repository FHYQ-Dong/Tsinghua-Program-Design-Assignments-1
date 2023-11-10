#include<stdio.h>
typedef int bool;
#define true 1
#define false 0
typedef struct Border {
    int c1, c2;
} Border;

int color[6] = {0, 1, 2, 3, 4, 5};
int country_color[6]; // A B C D E
Border border[8] = {
    {0, 0}, {1, 3}, {1, 4}, {1, 5},
    {2, 3}, {2, 4}, {3, 4}, {4, 5}
};
bool has_anser;

bool check() {
    for(int i=1; i<=7; ++i) if (country_color[border[i].c1] == country_color[border[i].c2]) return false;
    return true;
}

void fill_color(int n, int depth) { // n: 颜色数量
    if (has_anser) return;
    if (depth == 5) {
        if (check()) has_anser = true;
        return;
    }
    for(int i=1; i<=n; ++i) {
        if (has_anser) return;
        country_color[depth+1] = color[i];
        fill_color(n, depth+1);
    }
    return;
}

int main() {
    for(int i=1; i<=5; ++i) {
        has_anser = false;
        fill_color(i, 0);
        if (has_anser) {
            printf("%d\n", i);
            for(int j=1; j<=5; ++j) printf("%d ", country_color[j]);
            break;
        }
    }
    return 0;
}