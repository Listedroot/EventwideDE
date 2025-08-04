#include "common_exec.h"
#include <unistd.h>
#include <stdlib.h>
int common_exec(const char *cmd) {
    return system(cmd);
}
