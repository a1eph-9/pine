#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "pine.h"

int main(int argc, char ** argv){

  unsigned char data[16];
  unsigned char key[16];
  unsigned char output[16];
  unsigned char output_dec[16];
  memset(data, '\0', 16);
  memset(key, '\0', 16);
  if(argc != 2 && argc != 3){
    return 1;
  }
  if(argc == 3){strncpy(key, argv[2], 16);}
  strncpy(data, argv[1], 16);
  encrypt_pine(key, data, output);
  for(int i = 0; i < 16; ++i){
    printf("0x%02hhx ", output[i]);
  }
  puts("");
  decrypt_pine(key, output, output_dec);
  for(int i = 0; i < 16; ++i){
    printf("%c ", output_dec[i]);
  }
  puts("");
  return 0;
}
