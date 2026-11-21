#include "kernel/types.h"
#include "user/user.h"

int
main(void)
{
  char buf[16];
  
  // 初始化为 'X'
  for(int i = 0; i < 16; i++) buf[i] = 'X';

  if (getprocname(buf, 16) < 0) {
    printf("getprocname failed\n");
    exit(1);
  }
  
  printf("Name bytes: ");
  for(int i = 0; i < 16; i++) {
    if (buf[i] == '\0') break;
    printf("%c", buf[i]);
  }
  printf("\n");
  
  printf("First byte ASCII: %d\n", buf[0]);
  
  exit(0);
}
