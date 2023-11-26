#include <stdio.h>

int main() {
    char id_str[19]; scanf("%s", id_str);
    int id[18], weight[18] = {-1,7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2}, sum = 0;

    for (int i=0; i<=16; ++i) id[i+1] = id_str[i] - '0';
    for (int i=1; i<=17; ++i) {
        sum += (id[i] * weight[i]) % 11;
        sum %= 11;
    }
    
    int chk = (12 - sum) % 11;
    if (chk == 10) {
        if (id_str[17] == 'X') printf("Right\n");
        else printf("Wrong\nCorrect: X\n");
    }
    else {
        if (id_str[17] == chk + '0') printf("Right\n");
        else printf("Wrong\nCorrect: %d\n", chk);
    }
    return 0;
}