#include<stdio.h>
#define true 1
#define false 0
typedef int bool;
#define AC 0
#define WA 1
#define ERROR -1

int ans[3][3] = {4, 18, 78, \
                 8, 11, 81, \
                 12, 4, 84};
int user_input[4][3];

void close_file(FILE *f){
    if(f != NULL){
        fclose(f);
    }
}

int readline(FILE *f, int line) {
    int buf[3];
    for(int i=0; i<3; ++i) {
        if(fscanf(f, "%d", &buf[i]) == EOF) {
            return EOF;
        }
    }
    user_input[line][0] = buf[0];
    user_input[line][1] = buf[1];
    user_input[line][2] = buf[2];
    return 0;
}

bool checkline(int x, int y) {
    for(int i=0; i<3; ++i) {
        if(ans[x][i] != user_input[y][i]) return false;
    }
    return true;
}

bool check() {
    for(int i=0; i<3; ++i) {
        if(!checkline(i, 0) && !checkline(i, 1) && !checkline(i, 2)) {
            printf("WA\n");
            return WA;
            
        }
    }
    printf("AC\n");
    return AC;
}

int main(int argc, char *args[]) {
    FILE *input = NULL, *user_output = NULL;
    int result;
    if(argc != 3){
        printf("Usage: spj x.in x.out\n");
        return ERROR;
    }
    input = fopen(args[1], "r");
    user_output = fopen(args[2], "r");
    if(input == NULL || user_output == NULL){
        printf("Failed to open output file\n");
        close_file(input);
        close_file(user_output);
        return ERROR;
    }
    
    for(int i=0; i<3; i++) {
        if (readline(user_output, i) == EOF) {
            printf("Wrong format\n");
            close_file(input);
            close_file(user_output);
            return WA;
        }
    }
    if (readline(user_output, 3) != EOF) {
        printf("Wrong format\n");
        close_file(input);
        close_file(user_output);
        return WA;
    }
    return check();
}