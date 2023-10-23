#include<stdio.h>
#define MAXTIME 100005 // 最长时间
typedef struct Sheeps Sheeps;

struct Sheeps {
    int cntChild, cntAdult, cntAll; // 目前小羊和大羊的数量 (单位：对)
    int Value;
};

Sheeps aSheep(int _cntChild, int _cntAdult, int _cntAll, int _Value) { // "构造函数"
    struct Sheeps tmp;
    tmp.cntChild = _cntChild;
    tmp.cntAll = _cntAll;
    tmp.cntAdult = _cntAdult;
    tmp.Value = _Value;
    return tmp;
}

Sheeps dp_sheeps[MAXTIME];

int main() {
    dp_sheeps[1] = aSheep(1, 0, 1, 10);
    for(int i=2; i<=6; ++i) {
        dp_sheeps[i].cntAdult = dp_sheeps[i-1].cntAdult + dp_sheeps[i-1].cntChild;
        dp_sheeps[i].cntChild = dp_sheeps[i-1].cntAdult;
        dp_sheeps[i].cntAll = dp_sheeps[i].cntAdult + dp_sheeps[i].cntChild;
        dp_sheeps[i].Value = 10 * dp_sheeps[i].cntAll;
    }
    
    printf("Time\tAll\tAdult\tChild\tValue\n");
    printf("-------------------------------------\n");
    for(int i=1; i<=6; ++i) {
        printf("%d\t%d\t%d\t%d\t%d\n", i, dp_sheeps[i].cntAll, dp_sheeps[i].cntAdult, dp_sheeps[i].cntChild, dp_sheeps[i].Value);
    }
    return 0;
}