#include "desktop_utils.h"
#include <stdio.h>
#include <stdarg.h>
#include <time.h>

void desktop_log(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    printf("[%02d:%02d:%02d] ", t->tm_hour, t->tm_min, t->tm_sec);
    vprintf(fmt, args);
    printf("\n");
    va_end(args);
}

void desktop_log_error(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    fprintf(stderr, "[ERROR] ");
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "\n");
    va_end(args);
}

long desktop_get_time_ms(void) {
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    return ts.tv_sec * 1000 + ts.tv_nsec / 1000000;
}

void desktop_print_system_info(void) {
    printf("EventwideDE running on: %s\n", getenv("DESKTOP_SESSION"));
}
