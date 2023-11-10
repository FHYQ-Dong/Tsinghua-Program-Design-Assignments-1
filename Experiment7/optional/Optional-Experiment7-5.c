#include<stdio.h>
#include<stdlib.h>
#define true 1
#define false 0
typedef int bool;
typedef struct ans ans;

struct ans {
    int value[3][3];
    ans* next;
};

int matrix[3][3];
int cnt;
ans head;

bool check() {
    for (int i=0; i<3; ++i) {
        int sum = 0;
        for (int j=0; j<3; ++j) sum += matrix[i][j];
        if (sum != 15) return false;
    }
    for (int i=0; i<3; ++i) {
        int sum = 0;
        for (int j=0; j<3; ++j) sum += matrix[j][i];
        if (sum != 15) return false;
    }
    if (matrix[0][0] + matrix[1][1] + matrix[2][2] != 15) return false;
    if (matrix[0][2] + matrix[1][1] + matrix[2][0] != 15) return false;
    return true;
}

void all_permutation(int depth) {
    if (depth == 10) {
        if (check()) {
            ans* tmp = (ans*)malloc(sizeof(ans));
            for(int i=0; i<3; ++i) for(int j=0; j<3; ++j) tmp->value[i][j] = matrix[i][j];
            tmp->next = head.next;
            head.next = tmp;
            ++cnt;
        }
        return;
    }
    for(int i=0; i<3; ++i) {
        for(int j=0; j<3; ++j) {
            if (matrix[i][j] == 0) {
                matrix[i][j] = depth;
                all_permutation(depth+1);
                matrix[i][j] = 0;
            }
        }
    }
    return;
}

int main() {
    all_permutation(1);
    ans* tmp = head.next;
    printf("%d\n", cnt);
    while(tmp != NULL) {
        for(int i=0; i<3; ++i) {
            for(int j=0; j<3; ++j) printf("%d ", tmp->value[i][j]);
            printf("\n");
        }
        printf("\n");
        tmp = tmp->next;
    }
    return 0;
}