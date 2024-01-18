// include/account.h

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "hash.h"
#pragma warning(disable: 4996)

#define MAX_ACCOUNT_LENGTH 51
#define MAX_PASSWD_LENGTH 51
typedef char* string;

typedef int LOGIN_TYPE;
#define LOGIN 0
#define REGISTER 1

typedef struct Account {
    char username[MAX_ACCOUNT_LENGTH];
    char passwd[MAX_PASSWD_LENGTH];
    unsigned char passwd_hash[SHA256_BLOCK_SIZE];

    void (*login_account)(struct Account *account);
    void (*register_account)(struct Account *account);
} Account;

Account new_Account();