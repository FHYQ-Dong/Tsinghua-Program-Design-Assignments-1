#include<iostream>
#define true 1
#define false 0
#define AC 0
#define WA 1
#define ERROR -1
typedef struct Border {
    int c1, c2;
} Border;

int ansn = 3;
int user_n, user_color[6], buf;
Border border[8] = {
    {0, 0}, {1, 3}, {1, 4}, {1, 5},
    {2, 3}, {2, 4}, {3, 4}, {4, 5}
};


void close_file(FILE *f){
    if(f != NULL){
        fclose(f);
    }
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
    for(int i = 1; i <= 5; i++){
        if(fscanf(user_output, "%d", &user_color[i]) == EOF) {
            printf("Wrong Format\n");
            close_file(input);
            close_file(user_output);
            return WA;
        }
    }
    if(fscanf(user_output, "%d", &buf) != EOF) {
        printf("Wrong Format\n");
        close_file(input);
        close_file(user_output);
        return WA;
    }
    if (user_n != 3) {
        printf("Wrong Answer\n");
        close_file(input);
        close_file(user_output);
        return WA;
    }
    for(int i=1; i<=7; ++i) {
        if(user_color[border[i].c1] == user_color[border[i].c2]) {
            printf("Wrong Answer\n");
            close_file(input);
            close_file(user_output);
            return WA;
        }
    }
    printf("Accepted\n");
    close_file(input);
    close_file(user_output);
    return AC;
}