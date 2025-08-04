#ifndef COMMON_CONFIG_H
#define COMMON_CONFIG_H
int common_config_get(const char *key, char *value, int value_size);
int common_config_set(const char *key, const char *value);
void common_config_set_path(const char *path);
const char *common_config_get_path(void);
#endif
