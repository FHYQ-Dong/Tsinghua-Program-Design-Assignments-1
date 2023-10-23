#include<stdio.h>
#include<stdlib.h>

typedef int bool;
#define true 1
#define false 0

int cnt15, cnt10, cnt5;
bool flag;

int main() {
    for(cnt15=98; cnt15>0; --cnt15) {
        for(cnt10=99-cnt15; cnt10>0; --cnt10) {
            cnt5 = 100 - cnt15 - cnt10;
            if(cnt15*15 + cnt10*10 + cnt5*5 == 1000) {
                flag = true;
                goto end;
            }
        }
    }
end:
    if(flag) printf("%d只母鸡, %d只公鸡, %d只小鸡\n", cnt15, cnt10, cnt5);
    else printf("无解\n");
    return 0;
}
