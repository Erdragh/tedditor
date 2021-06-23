#ifndef __TEDDITORWIN_H
#define __TEDDITORWIN_H

#include <gtk/gtk.h>
#include "tedditor.h"


#define TEDDITOR_WINDOW_TYPE (tedditor_window_get_type ())
G_DECLARE_FINAL_TYPE (TedditorWindow, tedditor_window, TEDDITOR, APP_WINDOW, GtkApplicationWindow)

TedditorWindow  *tedditor_window_new    (Tedditor *app);
void             tedditor_window_open   (TedditorWindow *win,
                                         GFile          *file);


#endif /* __TEDDITORWIN_H */