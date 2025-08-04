#ifndef COMMON_PROCESS_H
#define COMMON_PROCESS_H
#include <sys/types.h>
#include <unistd.h>
int common_process_kill(pid_t pid);
pid_t common_process_fork(void);
#endif
