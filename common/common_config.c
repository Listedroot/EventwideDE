#include "common_config.h"
#include <stdio.h>
#include <string.h>
static char config_path[256] = "~/.eventwidede_config";
void common_config_set_path(const char *path) { strncpy(config_path, path, sizeof(config_path)-1); }
const char *common_config_get_path(void) { return config_path; }
int common_config_get(const char *key, char *value, int value_size) {
    FILE *f = fopen(config_path, "r");
    if (!f) return 0;
    char line[256];
    while (fgets(line, sizeof(line), f)) {
        char k[128], v[128];
        if (sscanf(line, "%127[^=]=%127s", k, v) == 2 && strcmp(k, key) == 0) {
            strncpy(value, v, value_size-1);
            fclose(f);
            return 1;
        }
    }
    fclose(f);
    return 0;
}
int common_config_set(const char *key, const char *value) {
    FILE *f = fopen(config_path, "a");
    if (!f) return 0;
    fprintf(f, "%s=%s\n", key, value);
    fclose(f);
    return 1;
}
