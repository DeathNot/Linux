#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

char *env_init[] = { "USER=unknown", "PATH=/tmp", NULL};

int main(int argc, char *argv[]) {
  pid_t   pid;

  if ((pid = fork()) < 0) {
    printf("fork error!\n");
    exit(1);
  } else if (pid == 0) {
    if (execle("/home/li/Project/Linux/unix环境高级编程/Chapter 8/test", "test",
    "myarg1", "MY ARG2", (char *)0, env_init) < 0) {
      printf("execle error!\n");
      exit(1);
    }
  }

  if (waitpid(pid, NULL, 0) < 0) {
    printf("wait error!\n");
    exit(1);
  }

  if ((pid = fork()) < 0) {
    printf("fork error!\n");
    exit(1);
  } else if (pid == 0) {
    if (execlp("test", "test", "only 1 arg", (char *)0) < 0) {
      printf("execlp error!\n");
      exit(1);
    }
  }

  return 0;
}
