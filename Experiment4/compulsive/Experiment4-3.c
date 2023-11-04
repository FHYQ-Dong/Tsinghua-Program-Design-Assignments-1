#include<stdio.h>
#include<stdlib.h>
#define true 1
#define false 0
typedef int bool;

bool a = false, b = false, c = false; // false: 不是泄密者

bool argument_a(bool b, bool honest) { // b: a的谈论对象, honest: a说的话的真假
    return honest ? b==1 : b==0;
}
bool argument_b(bool c, bool honest) { // c: b的谈论对象, honest: b说的话的真假
    return honest ? c==1 : c==0;
}
bool argument_c(bool argv_b, bool honest) { // argv_b: b的谈论对象, honest: c说的话的真假
    return honest ? argument_b(argv_b, false) : argument_b(argv_b, true);
}

void init(int x) {
    a = x == 1;
    b = x == 2;
    c = x == 3;
    return;
}

bool check() {
    for(int ha=0; ha<=1; ++ha) {
        for(int hb=0; hb<=1; ++hb) {
            for(int hc=0; hc<=1; ++hc) {
                if (argument_a(b, ha) && argument_b(c, hb) && argument_c(c, hc)) {
                    printf("若甲说%s话, 乙说%s话, 丙说%s话, 则:\n", ha?"真":"假", hb?"真":"假", hc?"真":"假");
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    bool flag = false;
    for(int i=1; i<=3; ++i) {
        init(i);
        if(check()) {
            printf("可能的泄密者是%s\n", i==1?"甲":i==2?"乙":"丙");
            flag = true;
        }
    }
    if(!flag) printf("没有泄密者\n");
    return 0;
}