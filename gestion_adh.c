#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/////////////////////
//////////////////////
static void user_add_secces (GtkWidget *wid, GtkWidget *win)
{
  GtkWidget *dialog = NULL;

  dialog = gtk_message_dialog_new (GTK_WINDOW (win), GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_CLOSE, "USER ADDED");
  gtk_window_set_position (GTK_WINDOW (dialog), GTK_WIN_POS_CENTER);
  gtk_dialog_run (GTK_DIALOG (dialog));
  gtk_widget_destroy (win);
}

//char * find_adh(char* nom);
void    css_set(GtkCssProvider *, GtkWidget *);
void back(GtkWidget *widget,gpointer data);
void user_function(int argc, char *argv[] );
void user_function_after_cherche(int argc, char *argv[],char * nom,char * prenom,char * email,char *adresse,char * nb);
void open_user_after_clicked_cherche(GtkWidget *widget,gpointer data);

void gestion_adh(int argc, char *argv[] )
{

    GtkWidget *window;
    GtkWidget *layout;
    GtkWidget *imageback;
    GtkWidget *buttoncherche;
    GtkWidget *buttonajouteradherent;
        GtkWidget *buttonback;


    GtkWidget *textcherche;
    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
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
        gtk_window_set_title(GTK_WINDOW(window),"YAYALIB|GESTION_ADH");
            gtk_window_set_icon_from_file(GTK_WINDOW(window),"icon.png",NULL);


    layout = gtk_layout_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER (window), layout);
    gtk_widget_show(layout);

    imageback = gtk_image_new_from_file("gestion_adh.png");
    gtk_layout_put(GTK_LAYOUT(layout), imageback, 0, 0);

    buttoncherche = gtk_button_new_with_label("");
    gtk_widget_set_size_request(buttoncherche, 16, 16);
    gtk_layout_put(GTK_LAYOUT(layout), buttoncherche, 513, 20);

    buttonajouteradherent = gtk_button_new_with_label("");
    gtk_widget_set_size_request(buttonajouteradherent, 180, 46);
    gtk_layout_put(GTK_LAYOUT(layout), buttonajouteradherent, 5, 234);

    buttonback = gtk_button_new_with_label("");
    gtk_widget_set_size_request(buttonback, 24, 24);
    gtk_layout_put(GTK_LAYOUT(layout), buttonback, 22, 74);


    textcherche =gtk_entry_new( );
    gtk_layout_put(GTK_LAYOUT(layout), textcherche, 349, 24);
/////////////////////////////////////


//////////////////////////////////////
g_signal_connect (G_OBJECT(buttoncherche), "clicked", G_CALLBACK(open_user_after_clicked_cherche),textcherche);
g_signal_connect (G_OBJECT(buttonajouteradherent), "clicked", G_CALLBACK(user_function), NULL);
g_signal_connect (G_OBJECT(buttonback), "clicked", G_CALLBACK(back), window);



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
    css_set(cssprovider1, buttonback);

    css_set(cssprovider1, buttonajouteradherent);


    gtk_widget_show_all(window);
    gtk_main();
}


///////////////////////////////////

