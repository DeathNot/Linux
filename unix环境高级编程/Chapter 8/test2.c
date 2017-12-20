#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int globvar = 6;

int main(int argc, char **argv) {
  int   var;
  pid_t pid;

  var = 88;
  printf("Before vfork:\n");
  if ((pid = vfork()) < 0) {
    printf("vfork error!\n");
    exit(1);
  } else if (pid == 0) {
    globvar++;
    var++;
    _exit(0);
  }
  printf("pid = %ld, glob = %d, var = %d\n", (long)getpid(), globvar, var);
  return 0;
}
