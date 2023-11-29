#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char *cmd= malloc(32*sizeof(char));
  cmd = "hello=world";
  int ret = putenv(cmd);
  return ret;
}

