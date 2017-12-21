#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int globvar = 6;

int main(int argc, char *argv[]) {
  int   var;
  pid_t pid;

  var = 88;
  printf("Before fork:\n");

  if ((pid = fork()) < 0) {
    printf("fork error!\n");
    exit(1);
  } else if(pid == 0) { //子进程
    globvar++;
    var++;
  } else {　//父进程
    sleep(2);　　//睡眠两秒使得子进程先执行
  }
  printf("pid = %ld, glob = %d, var = %d\n", (long)getpid(), globvar, var);
  return 0;
}
