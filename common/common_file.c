#include "common_file.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int common_file_exists(const char *path) {
    FILE *f = fopen(path, "r");
    if (f) { fclose(f); return 1; }
    return 0;
}
char *common_file_read(const char *path) {
    FILE *f = fopen(path, "r");
    if (!f) return NULL;
    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    rewind(f);
    char *buf = malloc(size+1);
    fread(buf, 1, size, f);
    buf[size] = 0;
    fclose(f);
    return buf;
}
int common_file_write(const char *path, const char *data) {
    FILE *f = fopen(path, "w");
    if (!f) return 0;
    fputs(data, f);
    fclose(f);
    return 1;
}
