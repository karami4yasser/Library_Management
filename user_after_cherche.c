#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void  css_set(GtkCssProvider * cssProvider, GtkWidget *g_widget);
void printaa(GtkWidget *widget,gpointer data);
void back(GtkWidget *widget,gpointer data);

void delete_this(GtkWidget *widget,gpointer data);
void update_this(GtkWidget *widget,gpointer data);





void user_function_after_cherche(int argc, char *argv[],char *nom,char * prenom,char * email,char* adresse,char *nb)
{
    GtkWidget *window;
    GtkWidget *layout;
    GtkWidget *image;
    GtkWidget *buttonsave;
    GtkWidget *buttondelete;
    GtkWidget *buttonback;
    GtkWidget *textnom;
    GtkWidget *textprenom;
    GtkWidget *textadresse;
    GtkWidget *textemail;
    GtkWidget *textbook;


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
        gtk_window_set_title(GTK_WINDOW(window),"YAYALIB|USER");
                gtk_window_set_keep_above(GTK_WINDOW(window),TRUE);
                    gtk_window_set_icon_from_file(GTK_WINDOW(window),"icon.png",NULL);




    layout = gtk_layout_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER (window), layout);
    gtk_widget_show(layout);

    image = gtk_image_new_from_file("user.png");
    gtk_layout_put(GTK_LAYOUT(layout), image, 0, 0);

    buttonsave = gtk_button_new_with_label("");
    buttondelete = gtk_button_new_with_label("");
    buttonback = gtk_button_new_with_label("");
    gtk_layout_put(GTK_LAYOUT(layout), buttonsave, 523, 106);
    gtk_layout_put(GTK_LAYOUT(layout), buttondelete, 49, 441);
    gtk_layout_put(GTK_LAYOUT(layout), buttonback, 19, 21);
    g_signal_connect (G_OBJECT(buttonback), "clicked", G_CALLBACK(back), window);


    //g_signal_connect_swapped(G_OBJECT(buttonback), "destroy",
    //G_CALLBACK(destroy), NULL);


    gtk_widget_set_size_request(buttonsave, 32, 32);
    gtk_widget_set_size_request(buttonback, 32, 32);
    gtk_widget_set_size_request(buttondelete, 32, 32);
    textnom =gtk_entry_new( );
    textprenom =gtk_entry_new( );
    textadresse =gtk_entry_new( );
    textemail =gtk_entry_new( );
    textbook =gtk_entry_new( );
    gtk_layout_put(GTK_LAYOUT(layout), textnom, 370, 235);
    gtk_layout_put(GTK_LAYOUT(layout), textprenom, 370, 273);
    gtk_layout_put(GTK_LAYOUT(layout), textemail, 370,310 );
    gtk_layout_put(GTK_LAYOUT(layout), textadresse, 370, 350);
    gtk_layout_put(GTK_LAYOUT(layout), textbook, 370, 390);
    gtk_entry_set_text(GTK_ENTRY(textnom),nom);
    gtk_entry_set_text(GTK_ENTRY(textprenom),prenom);
    gtk_entry_set_text(GTK_ENTRY(textadresse),adresse);
    gtk_entry_set_text(GTK_ENTRY(textemail),email);
    gtk_entry_set_text(GTK_ENTRY(textbook),nb);


    ///////////////////////////// for espace
    GtkWidget * textspace;
    textspace =gtk_entry_new( );
    set_text_input(textspace," ");
    ////////////////////////////for default
    GtkWidget * textdefault;
    textdefault =gtk_entry_new( );
    set_text_input(textdefault,"defaulttt");
    //////////////////////////////
    GtkWidget* all_widgets[11];
    all_widgets[0]=textdefault;
    all_widgets[1]=textspace;
    all_widgets[2]=textnom;
    all_widgets[3]=textspace;
   all_widgets[4]=textprenom;
   all_widgets[5]=textspace;
    all_widgets[6]=textemail;
    all_widgets[7]=textspace;
    all_widgets[8]=textadresse;
    all_widgets[9]=textspace;
    all_widgets[10]=textdefault;
char full_name[900];
    strcat(full_name,get_text_input(textnom));strcat(full_name," ");strcat(full_name,get_text_input(textprenom));
    g_signal_connect (G_OBJECT(buttondelete), "clicked", G_CALLBACK(delete_this), full_name);
        g_signal_connect (G_OBJECT(buttondelete), "clicked", G_CALLBACK(back), window);

    printf("%s//////////////////////////////////////",full_name);



    g_signal_connect (G_OBJECT(buttonsave), "clicked", G_CALLBACK(update_this),(*all_widgets));
    g_signal_connect (G_OBJECT(buttonsave), "clicked", G_CALLBACK(update_this),*(all_widgets+1));
    g_signal_connect (G_OBJECT(buttonsave), "clicked", G_CALLBACK(update_this),*(all_widgets+2));
    g_signal_connect (G_OBJECT(buttonsave), "clicked", G_CALLBACK(update_this),*(all_widgets+3));
    g_signal_connect (G_OBJECT(buttonsave), "clicked", G_CALLBACK(update_this),*(all_widgets+4));
    g_signal_connect (G_OBJECT(buttonsave), "clicked", G_CALLBACK(update_this),*(all_widgets+5));
    g_signal_connect (G_OBJECT(buttonsave), "clicked", G_CALLBACK(update_this),*(all_widgets+6));
    g_signal_connect (G_OBJECT(buttonsave), "clicked", G_CALLBACK(update_this),*(all_widgets+7));
    g_signal_connect (G_OBJECT(buttonsave), "clicked", G_CALLBACK(update_this),*(all_widgets+8));
    g_signal_connect (G_OBJECT(buttonsave), "clicked", G_CALLBACK(update_this),*(all_widgets+9));
    g_signal_connect (G_OBJECT(buttonsave), "clicked", G_CALLBACK(update_this),*(all_widgets+10));
    g_signal_connect (G_OBJECT(buttonsave), "clicked", G_CALLBACK(update_this),*(all_widgets+10));



    g_signal_connect_swapped(G_OBJECT(window), "destroy",
    G_CALLBACK(gtk_main_quit), NULL);




    GtkCssProvider *cssprovider1;
    cssprovider1 = gtk_css_provider_new();
    gtk_css_provider_load_from_path(cssprovider1,"C:/Users/yasser/Desktop/yaya/frontcss/buttoncss.css",NULL);
    GtkCssProvider *cssprovider2;
    cssprovider2 = gtk_css_provider_new();
    gtk_css_provider_load_from_path(cssprovider2,"C:/Users/yasser/Desktop/yaya/frontcss/textcss.css",NULL);
    css_set(cssprovider2, textnom);
    css_set(cssprovider2, textprenom);
    css_set(cssprovider2, textemail);
    css_set(cssprovider2, textadresse);
    css_set(cssprovider2, textbook);
    css_set(cssprovider1, buttonsave);
    css_set(cssprovider1, buttondelete);
    css_set(cssprovider1, buttonback);


    gtk_widget_show_all(window);

    gtk_main();

}













