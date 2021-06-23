#include <gtk/gtk.h>

#include "tedditor.h"

int
main (int argc, char *argv[])
{
    return g_application_run (G_APPLICATION (tedditor_new ()), argc, argv);
}