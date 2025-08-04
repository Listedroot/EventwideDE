#include "common_process.h"
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
int common_process_kill(pid_t pid) {
    return kill(pid, SIGKILL);
}
pid_t common_process_fork(void) {
    return fork();
}
