#include "wm_config.h"
#include <stdio.h>
#include <string.h>

static char theme[64] = "Classy";
static int border_width = 2;
static int snap_distance = 10;

void wm_config_load(void) {
    FILE *f = fopen("~/.eventwidede_wmrc", "r");
    if (f) {
        fgets(theme, sizeof(theme), f);
        fscanf(f, "%d", &border_width);
        fscanf(f, "%d", &snap_distance);
        fclose(f);
    }
}

const char *wm_config_get_theme(void) { return theme; }
int wm_config_get_border_width(void) { return border_width; }
int wm_config_get_snap_distance(void) { return snap_distance; }
