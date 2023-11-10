#include<iostream>
#define true 1
#define false 0
#define AC 0
#define WA 1
#define ERROR -1

int ans1 = 142857, ans2 = 285714;
int user_input1, user_input2, user_input3;

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
    if(fscanf(user_output, "%d",&user_input1) == EOF || fscanf(user_output, "%d",&user_input2) == EOF) {
        printf("Wrong Format\n");
        close_file(input);
        close_file(user_output);
        return WA;
    }
    if(fscanf(user_output, "%d",&user_input3) != EOF) {
        printf("Wrong Format\n");
        close_file(input);
        close_file(user_output);
        return WA;
    }
    if ((user_input1 == ans1 && user_input2 == ans2) || (user_input1 == ans2 && user_input2 == ans1)) {
        printf("Accepted\n");
        close_file(input);
        close_file(user_output);
        return AC;
    }
    printf("Wrong Answer\n");
    close_file(input);
    close_file(user_output);
    return WA;
}