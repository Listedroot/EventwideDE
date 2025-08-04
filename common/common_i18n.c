#include "common_i18n.h"
#include <libintl.h>
#include <locale.h>
void common_i18n_init(const char *domain) {
    setlocale(LC_ALL, "");
    bindtextdomain(domain, "/usr/share/locale");
    textdomain(domain);
}
const char *common_i18n_translate(const char *msg) {
    return gettext(msg);
}
