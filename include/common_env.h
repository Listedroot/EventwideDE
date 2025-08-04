#ifndef COMMON_ENV_H
#define COMMON_ENV_H
const char *common_env_get(const char *key);
int common_env_set(const char *key, const char *value);
#endif
