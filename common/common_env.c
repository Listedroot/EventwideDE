#include "common_env.h"
#include <stdlib.h>
const char *common_env_get(const char *key) {
    return getenv(key);
}
int common_env_set(const char *key, const char *value) {
    return setenv(key, value, 1);
}
