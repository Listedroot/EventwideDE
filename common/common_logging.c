#include "common_logging.h"
#include <stdio.h>
#include <time.h>
void common_log(const char *msg) {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    printf("[%02d:%02d:%02d] %s\n", tm->tm_hour, tm->tm_min, tm->tm_sec, msg);
}
void common_log_error(const char *msg) {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    fprintf(stderr, "[ERROR %02d:%02d:%02d] %s\n", tm->tm_hour, tm->tm_min, tm->tm_sec, msg);
}
