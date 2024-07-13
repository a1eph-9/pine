#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "pine.h"

int main(int argc, char ** argv){

  unsigned char data[16];
  unsigned char key[16];
  unsigned char iv[16];
  unsigned char output[16];
  unsigned char output_dec[16];
  memset(data, '\0', 16);
  memset(key, '\0', 16);
  int len = 6;
  if(argc != 2 && argc != 3){
    return 1;
  }
  if(argc == 3){strncpy(key, argv[2], 16);}
  strncpy(data, argv[1], 16);
  rkey_t keys;
  round_key_gen(key, keys);
  encrypt_ctr_pine(key, data, output, len, iv);
  for(int i = 0; i < len; ++i){
    printf("0x%02hhx ", output[i]);
  }
  puts("");
  encrypt_ctr_pine(key, output, output_dec, len, iv);
  for(int i = 0; i < len; ++i){
    printf("%c ", output_dec[i]);
  }
  puts("");
  return 0;
}
