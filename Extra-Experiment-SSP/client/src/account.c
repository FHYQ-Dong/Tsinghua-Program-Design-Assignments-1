// src/account.c

#include "../include/account.h"

void get_username(string username, int length) {
    /*
    * @param username: the buffer to store the username
    * @param length: the length of the buffer
    * @description: get the username from console
    */
    while (1) {
        printf("Please input your username (maximum %d characters): ", length - 1);
        fgets(username, length, stdin);
        if (username[strlen(username) - 1] == '\n') {
            username[strlen(username) - 1] = '\0';
        }
        if (strlen(username) == 0) {
            printf("Username cannot be empty!\n");
            continue;
        }
        break;
    }
}

void get_passwd(string passwd, int length) {
    /*
    * @param passwd: the buffer to store the password
    * @param length: the length of the buffer
    * @description: get the password from console
    */
    printf("Please input your password (maximum %d characters): ", length - 1);
    char ch;
    int i = 0;
    while ((ch = getch()) != '\r') {
        if (ch == '\b') {
            if (i == 0) continue;
            printf("\b \b");
            passwd[--i] = '\0';
        }
        else if (i == length - 1) {
            printf("\nPassword too long!\n");
            exit(1);
        }
        else {
            printf("*");
            passwd[i++] = ch;
        }
    }
    putchar('\n');
}

void login_account(Account *account) {
    /*
    * @param account: the account to store the username and password
    * @description: login an account
    */
    get_username(account->username, MAX_ACCOUNT_LENGTH);
    get_passwd(account->passwd, MAX_ACCOUNT_LENGTH);
    hash_with_salt(account->passwd, strlen(account->passwd), account->passwd_hash);
}

void register_account(Account *account) {
    /*
    * @param account: the account to store the username and password
    * @description: register an account
    */
    get_username(account->username, MAX_ACCOUNT_LENGTH);
    get_passwd(account->passwd, MAX_ACCOUNT_LENGTH);
    hash_with_salt(account->passwd, strlen(account->passwd), account->passwd_hash);
}