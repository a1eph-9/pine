#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "pine.h"

int main(int argc, char ** argv){

  unsigned char data[16];
  unsigned char key[16];
  unsigned char iv[16] = {0};
  unsigned char output[16] = {0};
  unsigned char output_dec[16] = {0};
  int len = 16;
  pine_ctx ctx;
  memset(data, '\0', len);
  memset(key, '\0', 16);
  if(argc != 2 && argc != 3){
    return 1;
  }
  if(argc == 3){strncpy(key, argv[2], len);}
  strncpy(data, argv[1], len);
  pine_ctx_init_iv(&ctx, key, iv);
  for(int i = 0; i < len; ++i){
    printf("%c ", data[i]);
  }
  puts("");
  encrypt_ctr_pine(&ctx, data, output, len);
  for(int i = 0; i < len; ++i){
    printf("0x%hhx ", output[i]);
  }
  puts("");
  encrypt_ctr_pine(&ctx, output, output_dec, len);
  for(int i = 0; i < len; ++i){
    printf("%c ", output_dec[i]);
  }
  puts("");
  return 0;
}
