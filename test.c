#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "pine.h"

#define LEN 48

int main(int argc, char ** argv){
  unsigned char data[LEN];
  unsigned char key[16];
  unsigned char iv[16];
  unsigned char output[LEN];
  unsigned char output_dec[LEN];
  memset(data, '\0', LEN);
  memcpy(data, "testinfo1234567890123456789012345678901234567890123", 48);
  memcpy(iv, "testiv123456789012", 16);
  memset(key, '\0', 16);
  if(encrypt_cbc_pine(key, data, output, LEN, iv) != 0){
    puts("Rut roh 1");
    return 1;
  }
  for(int i = 0; i < 3; ++i){
    for(int j = 0; j < 16; ++j){
      printf("0x%02hhx ", output[j + (16 * i)]);
    }
    puts("");
  }
  if(decrypt_cbc_pine(key, output, output_dec, LEN, iv) != 0){
    puts("Rut roh 2");
    return 1;
  }
  for(int i = 0; i < 3; ++i){
    for(int j = 0; j < 16; ++j){
      printf("%c ", output_dec[j + (16 * i)]);
    }
    puts("");
  }
  return 0;
}











