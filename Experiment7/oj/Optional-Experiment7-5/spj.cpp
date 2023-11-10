#include<iostream>
#define true 1
#define false 0
#define AC 0
#define WA 1
#define ERROR -1

int user_n, user_matrix[3][3][8], buf;

void close_file(FILE *f){
    if(f != NULL){
        fclose(f);
    }
}

bool check_matrix(int k) {
    for(int i=0; i<3; ++i) {
        int sum = 0;
        for(int j=0; j<3; ++j) sum += user_matrix[i][j][k];
        if (sum != 15) return false;
    }
    for(int i=0; i<3; ++i) {
        int sum = 0;
        for(int j=0; j<3; ++j) sum += user_matrix[j][i][k];
        if (sum != 15) return false;
    }
    if (user_matrix[0][0][k] + user_matrix[1][1][k] + user_matrix[2][2][k] != 15) return false;
    if (user_matrix[0][2][k] + user_matrix[1][1][k] + user_matrix[2][0][k] != 15) return false;
    return true;
}

bool check() {
    for(int i=0; i<8; ++i) {
        if(check_matrix(i) == false) {
            printf("Wrong Answer\n");
            return WA;
        }
    }
    printf("Accepted\n");
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
    if(fscanf(user_output, "%d", &user_n) == EOF) {
        printf("Wrong Format\n");
        close_file(input);
        close_file(user_output);
        return WA;
    }
    if (user_n != 8) {
        printf("Wrong Answer\n");
        close_file(input);
        close_file(user_output);
        return WA;
    }
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 3; k++) {
                if (fscanf(user_output, "%d", &user_matrix[j][k][i]) == EOF) {
                    printf("Wrong Format\n");
                    close_file(input);
                    close_file(user_output);
                    return WA;
                }
            }
        }
    }
    if(fscanf(user_output, "%d", &buf) != EOF) {
        printf("Wrong Format\n");
        close_file(input);
        close_file(user_output);
        return WA;
    }
    return check();
}