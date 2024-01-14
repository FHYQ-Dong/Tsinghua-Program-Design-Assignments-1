// include/account.h

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "hash.h"
#pragma warning(disable:4996)

#define MAX_ACCOUNT_LENGTH 51
typedef char* string;

typedef struct {
    char username[MAX_ACCOUNT_LENGTH];
    char passwd[MAX_ACCOUNT_LENGTH];
    unsigned char passwd_hash[SHA256_BLOCK_SIZE];
} Account;

void get_username(string username, int length);
void get_passwd(string passwd, int length);
void login_account(Account *account);
void register_account(Account *account);