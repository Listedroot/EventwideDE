#include "taskbar_volume.h"
#include <gtk/gtk.h>
#include <alsa/asoundlib.h>
static GtkWidget *volume_btn = NULL;
static long get_volume() {
    long min, max, vol = 0;
    snd_mixer_t *handle;
    snd_mixer_selem_id_t *sid;
    snd_mixer_open(&handle, 0);
    snd_mixer_attach(handle, "default");
    snd_mixer_selem_register(handle, NULL, NULL);
    snd_mixer_load(handle);
    snd_mixer_selem_id_malloc(&sid);
    snd_mixer_selem_id_set_index(sid, 0);
    snd_mixer_selem_id_set_name(sid, "Master");
    snd_mixer_elem_t* elem = snd_mixer_find_selem(handle, sid);
    if (elem) {
        snd_mixer_selem_get_playback_volume_range(elem, &min, &max);
        snd_mixer_selem_get_playback_volume(elem, SND_MIXER_SCHN_FRONT_LEFT, &vol);
    }
    snd_mixer_close(handle);
    return vol;
}
static void update_volume(GtkWidget *btn) {
    char buf[32];
    snprintf(buf, sizeof(buf), "Vol: %ld", get_volume());
    gtk_button_set_label(GTK_BUTTON(btn), buf);
}
void taskbar_volume_init(GtkWidget *parent) {
    volume_btn = gtk_button_new_with_label("");
    update_volume(volume_btn);
    gtk_box_pack_end(GTK_BOX(parent), volume_btn, FALSE, FALSE, 0);
    g_timeout_add_seconds(2, (GSourceFunc)update_volume, volume_btn);
}
