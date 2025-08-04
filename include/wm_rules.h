#ifndef WM_RULES_H
#define WM_RULES_H
void wm_rules_init(void);
int wm_rules_get_workspace(const char *class_name);
int wm_rules_is_always_on_top(const char *class_name);
int wm_rules_is_floating(const char *class_name);
#endif
