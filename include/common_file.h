#ifndef COMMON_FILE_H
#define COMMON_FILE_H
int common_file_exists(const char *path);
char *common_file_read(const char *path);
int common_file_write(const char *path, const char *data);
#endif
