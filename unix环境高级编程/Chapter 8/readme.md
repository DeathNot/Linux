# 第八章　进程控制
每个进程都有一个非负的整型表示唯一的进程ＩＤ，进程id可以复用，当一个进程终止后，其进程id就成为复用的候选者，通过延迟复用算法，使得新建进程id不同于最近终止进程的id。

专用进程介绍
```
ＩＤ为０的进程通常是调度进程，也被称为是交换进程
ＩＤ为１的进程是init进程
```
下面的函数返回进程的标识符
```c
# include <unistd.h>
pid_t getpid(void);      返回值：调用进程的进程ＩＤ
pid_t getppid(void);　　　返回值：调用进程的父进程ＩＤ
pid_t getuid(void);　　　返回值：调用进程的实际用户ＩＤ
pid_t geteuid(void);　　　返回值：调用进程的有效用户ＩＤ
pid_t getgid(void);　　返回值：调用进程的实际组ＩＤ
pid_t getegid(void);　　返回值：调用进程的有效组ＩＤ
```
fork函数
```c
#include <unistd.h>
pid_t fork(void); 返回值：子进程返回０，父进程返回子进程ＩＤ，出错返回－１
```
vfork函数
```c

```
