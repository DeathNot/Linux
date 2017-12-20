#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  pid_t   pid;

  if ((pid = fork()) < 0) {
    printf("fork error!\n");
    exit(1);
  } else if (pid == 0) {  //第一个子进程
    if ((pid = fork()) < 0) {
      printf("fork error!\n");
      exit(1);
    } else if (pid > 0) {   //第二个子进程的父进程，即第一个子进程
      exit(0);
    }
    sleep(10);
    printf("second child, parent pid = %ld\n", (long)getppid());
    exit(0);
  }

  if (waitpid(pid, NULL, 0) != pid) {
    printf("waitpid error!\n");
    exit(1);
  }

  return 0;
}
