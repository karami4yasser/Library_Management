#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

///////////////////////
#include "structures.c"
#include "usefull_functions.c"
#include "usefull_functions_books.c"

///////////////////////


void gestion_adh(int argc, char *argv[] );
void gestion_liv(int argc, char *argv[] );
void gestion_emp(int argc, char *argv[] );
void open_user_after_clicked_cherche(GtkWidget *widget,gpointer data);
void open_book_after_clicked_cherche(GtkWidget *widget,gpointer data);




////////

//////////






void front_function(int argc, char *argv[] )
{

    GtkWidget *window;
    GtkWidget *layout;
    GtkWidget *imageback;
    GtkWidget *buttoncherche;
    GtkWidget *buttonadherent;
    GtkWidget *buttonlivre;
    GtkWidget *buttonemprunte;

    GtkWidget *textcherche;
    //////////////////////
    /////////////////////


    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    /////////////////////////////////////////////
    GdkGeometry hints;
    hints.max_width=600;
    hints.min_width=600;
    hints.max_height=500;
    hints.min_height=500;
    gtk_window_set_geometry_hints(GTK_WINDOW(window),window,
                                  &hints,
                                  (GdkWindowHints)(GDK_HINT_MIN_SIZE | GDK_HINT_MAX_SIZE));



    ////////////////////////////////////////////


    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_title(GTK_WINDOW(window),"YAYALIB|HOME");
    gtk_window_set_icon_from_file(GTK_WINDOW(window),"icon.png",NULL);

    layout = gtk_layout_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER (window), layout);
    gtk_widget_show(layout);

    imageback = gtk_image_new_from_file("home.png");
    gtk_layout_put(GTK_LAYOUT(layout), imageback, 0, 0);

    buttoncherche = gtk_button_new_with_label("");
    gtk_widget_set_size_request(buttoncherche, 16, 16);
    gtk_layout_put(GTK_LAYOUT(layout), buttoncherche, 513, 20);

    buttonadherent = gtk_button_new_with_label("");
    gtk_widget_set_size_request(buttonadherent, 136, 46);
    gtk_layout_put(GTK_LAYOUT(layout), buttonadherent, 24, 164);

    buttonlivre = gtk_button_new_with_label("");
    gtk_widget_set_size_request(buttonlivre, 136, 46);
    gtk_layout_put(GTK_LAYOUT(layout), buttonlivre, 24, 248);

    buttonemprunte = gtk_button_new_with_label("");
    gtk_widget_set_size_request(buttonemprunte, 136, 46);
    gtk_layout_put(GTK_LAYOUT(layout), buttonemprunte, 24, 332);


    textcherche =gtk_entry_new( );
    gtk_layout_put(GTK_LAYOUT(layout), textcherche, 349, 24);


/////////////////////////////////////

g_signal_connect (G_OBJECT(buttoncherche), "clicked", G_CALLBACK(open_user_after_clicked_cherche),textcherche);
g_signal_connect (G_OBJECT(buttoncherche), "clicked", G_CALLBACK(open_book_after_clicked_cherche),textcherche);


//////////////////////////////////////
g_signal_connect (G_OBJECT(buttonemprunte), "clicked", G_CALLBACK(gestion_emp), NULL);
g_signal_connect (G_OBJECT(buttonlivre), "clicked", G_CALLBACK(gestion_liv), NULL);
g_signal_connect (G_OBJECT(buttonadherent), "clicked", G_CALLBACK(gestion_adh), NULL);

    g_signal_connect_swapped(G_OBJECT(window), "destroy",
    G_CALLBACK(gtk_main_quit), NULL);




    GtkCssProvider *cssprovider1;
    cssprovider1 = gtk_css_provider_new();
    gtk_css_provider_load_from_path(cssprovider1,"C:/Users/yasser/Desktop/yaya/frontcss/buttoncss.css",NULL);
    GtkCssProvider *cssprovider2;
    cssprovider2 = gtk_css_provider_new();
    gtk_css_provider_load_from_path(cssprovider2,"C:/Users/yasser/Desktop/yaya/frontcss/textcss.css",NULL);
    css_set(cssprovider2, textcherche);
    css_set(cssprovider1, buttoncherche);
    css_set(cssprovider1, buttonlivre);
    css_set(cssprovider1, buttonadherent);
    css_set(cssprovider1, buttonemprunte);


    gtk_widget_show_all(window);

   gtk_main();
}





