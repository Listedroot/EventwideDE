#ifndef DESKTOP_UTILS_H
#define DESKTOP_UTILS_H
void desktop_log(const char *fmt, ...);
void desktop_log_error(const char *fmt, ...);
long desktop_get_time_ms(void);
void desktop_print_system_info(void);
#endif
