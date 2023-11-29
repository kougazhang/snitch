#include <stdio.h>
#include <unistd.h> 


int main(void) {
  char *a[10] = {0,};
  a[0] = "";
  a[1] = "./hello_world_hello";
  int ret = execvp("touch", a);
  printf("%d\n", ret);
  return 0;
}

