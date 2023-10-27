#include<stdio.h>
#include<math.h>
#define true 1
#define false 0
typedef int bool;
typedef struct Tower Tower;

struct Tower {
    double x, y;
    double radius;
    int height;
};
Tower tower[5];

Tower One_Tower(double x, double y, double r, int h) {
    Tower tmp;
    tmp.x = x;
    tmp.y = y;
    tmp.radius = r;
    tmp.height = h;
    return tmp;
}

bool on_tower(Tower t, double x, double y) {
    if (pow(x - t.x, 2) + pow(y - t.y, 2) <= pow(t.radius, 2)) return true;
    return false;
}

int main() {
    tower[1] = One_Tower(2.0, 2.0, 1.0, 10); tower[2] = One_Tower(-2.0, 2.0, 1.0, 9);
    tower[3] = One_Tower(-2.0, -2.0, 1.0, 8); tower[4] = One_Tower(2.0, -2.0, 1.0, 7);
    double x, y;
    scanf("%lf%lf", &x, &y);
    for(int i=1; i<=4; ++i) {
        if(on_tower(tower[i], x, y)) {
            printf("height: %d\n", tower[i].height);
            return 0;
        }
    }
    printf("height: 0\n");
    return 0;
}