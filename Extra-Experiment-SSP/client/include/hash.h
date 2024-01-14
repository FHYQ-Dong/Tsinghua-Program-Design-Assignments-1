// include/hash.h

#pragma once
 
#include<string.h>
#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#pragma warning(disable:6386)

#define SHA256_BLOCK_SIZE 32 // SHA256 outputs a 32 byte digest

void sha256(const unsigned char *data, size_t len, unsigned char *out);
void hash_with_salt(const unsigned char *data, size_t len, unsigned char *out);