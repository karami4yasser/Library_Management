#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//#include "structures.c"

void  css_set(GtkCssProvider * cssProvider, GtkWidget *g_widget);
void back(GtkWidget *widget,gpointer data);
void rend_this_book(GtkWidget *widget,gpointer data);
adherent  ligne_to_adherent(char * ligne);
livre  ligne_to_livre(char * ligne);


void rend_livre_function(int argc, char *argv[] )
{

    GtkWidget *window;
    GtkWidget *layout;
    GtkWidget *image;
    GtkWidget *buttonsave;
    GtkWidget *buttonback;


    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window), 600, 500);
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
        gtk_window_set_title(GTK_WINDOW(window),"YAYALIB|RND_BOOK");
        gtk_window_set_keep_above(GTK_WINDOW(window),TRUE);
    gtk_window_set_icon_from_file(GTK_WINDOW(window),"icon.png",NULL);


    layout = gtk_layout_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER (window), layout);
    gtk_widget_show(layout);

    image = gtk_image_new_from_file("emp_livre.png");
    gtk_layout_put(GTK_LAYOUT(layout), image, 0, 0);

    buttonsave = gtk_button_new_with_label("");
    buttonback = gtk_button_new_with_label("");
    gtk_layout_put(GTK_LAYOUT(layout), buttonsave, 523, 106);
    gtk_layout_put(GTK_LAYOUT(layout), buttonback, 19, 21);
    g_signal_connect (G_OBJECT(buttonback), "clicked", G_CALLBACK(back), window);
    //g_signal_connect (G_OBJECT(buttonsave), "clicked", G_CALLBACK(add_this_book), NULL);

    //g_signal_connect_swapped(G_OBJECT(buttonback), "destroy",
    //G_CALLBACK(destroy), NULL);


    gtk_widget_set_size_request(buttonsave, 32, 32);
    gtk_widget_set_size_request(buttonback, 32, 32);




 GtkWidget * box_livre;
    box_livre=gtk_combo_box_text_new ();
    GtkWidget * box_adh;
    box_adh=gtk_combo_box_text_new ();
    adherent adh;
    livre liv;
    char ligne[900]="";
    char nom_prenom[700]="";
    char titre_cate[700]="";
    int nb_adh=file_len("adherents.txt");
    int nb_liv=file_len("livres.txt");
    FILE *f_adh=fopen("adherents.txt","r");
    FILE *f_liv=fopen("livres.txt","r");
    while(fgets(ligne,900,f_adh)!=NULL)
    {
        if(strstr(ligne,"0\n")==NULL)
        {    strcpy(nom_prenom,"");
             adh=ligne_to_adherent(ligne);

            strcat(nom_prenom,adh.nom);strcat(nom_prenom," ");strcat(nom_prenom,adh.prenom);
            gtk_combo_box_text_insert_text(GTK_COMBO_BOX_TEXT(box_adh),-1,nom_prenom);



        }
    };
      while(fgets(ligne,900,f_liv)!=NULL)
    {
        if(strstr(ligne,"NULL\n")==NULL)
        {    strcpy(titre_cate,"");
             liv=ligne_to_livre(ligne);

            strcat(titre_cate,liv.titre);strcat(titre_cate," ");strcat(titre_cate,liv.categorie);
            gtk_combo_box_text_insert_text(GTK_COMBO_BOX_TEXT(box_livre),-1,titre_cate);



        }
    };
    gtk_layout_put(GTK_LAYOUT(layout), box_adh, 370, 316);
    gtk_layout_put(GTK_LAYOUT(layout), box_livre, 370, 233);



    g_signal_connect (G_OBJECT(buttonsave), "clicked", G_CALLBACK(rend_this_book),box_adh);
    g_signal_connect (G_OBJECT(buttonsave), "clicked", G_CALLBACK(rend_this_book),box_livre);
    g_signal_connect (G_OBJECT(buttonsave), "clicked", G_CALLBACK(back),window);


















    g_signal_connect_swapped(G_OBJECT(window), "destroy",
    G_CALLBACK(gtk_main_quit), NULL);




    GtkCssProvider *cssprovider1;
    cssprovider1 = gtk_css_provider_new();
    gtk_css_provider_load_from_path(cssprovider1,"C:/Users/yasser/Desktop/yaya/frontcss/buttoncss.css",NULL);
    GtkCssProvider *cssprovider2;
    cssprovider2 = gtk_css_provider_new();
    gtk_css_provider_load_from_path(cssprovider2,"C:/Users/yasser/Desktop/yaya/frontcss/boxcss.css",NULL);
    css_set(cssprovider2, box_adh);
    css_set(cssprovider2, box_livre);
    css_set(cssprovider1, buttonsave);
    css_set(cssprovider1, buttonback);


    gtk_widget_show_all(window);

    gtk_main();

}





