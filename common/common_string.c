#include "common_string.h"
#include <string.h>
#include <stdlib.h>
char *common_string_duplicate(const char *s) {
    size_t len = strlen(s);
    char *copy = malloc(len+1);
    strcpy(copy, s);
    return copy;
}
void common_string_trim(char *s) {
    char *end;
    while (*s == ' ' || *s == '\t') ++s;
    end = s + strlen(s) - 1;
    while (end > s && (*end == ' ' || *end == '\t')) --end;
    *(end+1) = 0;
}
