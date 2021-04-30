#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "structures.c"

adherent  ligne_to_adherent(char * ligne);
livre  ligne_to_livre(char * ligne);

void emp_livre_function(int argc, char *argv[] );

void    css_set(GtkCssProvider * cssProvider, GtkWidget *g_widget);
void printaa(GtkWidget *widget,gpointer data);
void back(GtkWidget *widget,gpointer data);
void rend_livre_function(int argc, char *argv[] );
void open_user_after_clicked_cherche(GtkWidget *widget,gpointer data);
void open_book_after_clicked_cherche(GtkWidget *widget,gpointer data);




void gestion_emp(int argc, char *argv[] )
{

    GtkWidget *window;
    GtkWidget *layout;
    GtkWidget *imageback;
    GtkWidget *buttoncherche;
    GtkWidget *buttonemprant;
    GtkWidget *buttonretour;
    GtkWidget *buttonback;




    GtkWidget *textcherche;
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
    gtk_window_set_title(GTK_WINDOW(window),"YAYALIB|GESTION_EMP");
    gtk_window_set_icon_from_file(GTK_WINDOW(window),"icon.png",NULL);

    layout = gtk_layout_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER (window), layout);
    gtk_widget_show(layout);

    imageback = gtk_image_new_from_file("gestion_emp.png");
    gtk_layout_put(GTK_LAYOUT(layout), imageback, 0, 0);

    buttoncherche = gtk_button_new_with_label("");
    gtk_widget_set_size_request(buttoncherche, 16, 16);
    gtk_layout_put(GTK_LAYOUT(layout), buttoncherche, 513, 20);

    buttonemprant = gtk_button_new_with_label("");
    gtk_widget_set_size_request(buttonemprant, 136, 46);
    gtk_layout_put(GTK_LAYOUT(layout), buttonemprant, 25, 189);

    buttonretour = gtk_button_new_with_label("");
    gtk_widget_set_size_request(buttonretour, 136, 46);
    gtk_layout_put(GTK_LAYOUT(layout), buttonretour, 26, 302);

    buttonback = gtk_button_new_with_label("");
    gtk_widget_set_size_request(buttonback, 24, 24);
    gtk_layout_put(GTK_LAYOUT(layout), buttonback, 22, 74);



    textcherche =gtk_entry_new( );
    gtk_layout_put(GTK_LAYOUT(layout), textcherche, 349, 24);
/////////////////////////////////////
GtkWidget * box_livre;
    box_livre=gtk_combo_box_text_new();

    GtkWidget * box_adh;
    box_adh=gtk_combo_box_text_new();
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

            strcat(nom_prenom,adh.nom);strcat(nom_prenom," ");strcat(nom_prenom,adh.prenom);strcat(nom_prenom,"/");strcat(nom_prenom,adh.id);
            gtk_combo_box_text_insert_text(GTK_COMBO_BOX_TEXT(box_adh),-1,nom_prenom);



        }
    };
      while(fgets(ligne,900,f_liv)!=NULL)
    {
        if(strstr(ligne,"NULL\n")==NULL)
        {    strcpy(titre_cate,"");
             liv=ligne_to_livre(ligne);

            strcat(titre_cate,liv.titre);strcat(titre_cate," ");strcat(titre_cate,liv.categorie);strcat(titre_cate,"/");strcat(titre_cate,liv.id_adherent);
            gtk_combo_box_text_insert_text(GTK_COMBO_BOX_TEXT(box_livre),-1,titre_cate);



        }
    };
    gtk_layout_put(GTK_LAYOUT(layout), box_adh, 439, 189);
    gtk_layout_put(GTK_LAYOUT(layout), box_livre, 439, 302);

//////////////////////////////////////
g_signal_connect (G_OBJECT(buttoncherche), "clicked", G_CALLBACK(open_user_after_clicked_cherche),textcherche);
g_signal_connect (G_OBJECT(buttoncherche), "clicked", G_CALLBACK(open_book_after_clicked_cherche),textcherche);

g_signal_connect (G_OBJECT(buttonemprant), "clicked", G_CALLBACK(emp_livre_function), NULL);
g_signal_connect (G_OBJECT(buttonretour), "clicked", G_CALLBACK(rend_livre_function), NULL);
g_signal_connect (G_OBJECT(buttonback), "clicked", G_CALLBACK(back), window);


    //g_signal_connect_swapped(G_OBJECT(buttonback), "destroy",
    //G_CALLBACK(destroy), NULL);




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


    css_set(cssprovider1, buttonemprant);
        css_set(cssprovider1, buttonretour);



    gtk_widget_show_all(window);
    gtk_main();
}


///////////////////////////////////

