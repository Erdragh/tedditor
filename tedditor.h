#ifndef __TEDDITOR_H
#define __TEDDITOR_H

#include <gtk/gtk.h>


#define TEDDITOR_TYPE (tedditor_get_type ())
G_DECLARE_FINAL_TYPE (Tedditor, tedditor, TEDDITOR, APP, GtkApplication)

Tedditor    *tedditor_new   (void);


#endif /* __TEDDITOR_H */