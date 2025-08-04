#include "wm_rules.h"
#include <gtk/gtk.h>

void wm_rules_init(void) {
    // Window rules (e.g., always-on-top, workspace assignment)
}
typedef struct {
    const char *class_name;
    int workspace;
    int always_on_top;
    int floating;
} WMRule;

static WMRule rules[] = {
    {"Terminal", 1, 0, 0},
    {"Calculator", 2, 1, 1},
    {"Browser", 1, 0, 0},
    {NULL, 0, 0, 0}
};

int wm_rules_get_workspace(const char *class_name) {
    for (int i = 0; rules[i].class_name; ++i) {
        if (strcmp(rules[i].class_name, class_name) == 0)
            return rules[i].workspace;
    }
    return 0;
}

int wm_rules_is_always_on_top(const char *class_name) {
    for (int i = 0; rules[i].class_name; ++i) {
        if (strcmp(rules[i].class_name, class_name) == 0)
            return rules[i].always_on_top;
    }
    return 0;
}

int wm_rules_is_floating(const char *class_name) {
    for (int i = 0; rules[i].class_name; ++i) {
        if (strcmp(rules[i].class_name, class_name) == 0)
            return rules[i].floating;
    }
    return 0;
}

void wm_rules_init(void) {}
