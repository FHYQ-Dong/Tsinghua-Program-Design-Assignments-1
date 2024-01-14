// main file for client

#include "include/account.h"
#include "include/hash.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	Account UserAccount = {{0}, {0}};
	login_account(&UserAccount);
	printf("The username is : %s\n", UserAccount.username);
	printf("The password is : %s\n", UserAccount.passwd);
	printf("The hash is : ");
	for (int i = 0; i < 32; i++)
		printf("%x", UserAccount.passwd_hash[i]);
	printf("\n");
	return 0;
}