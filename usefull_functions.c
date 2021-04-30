
#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
///////////////////////////structures

void css_set(GtkCssProvider * cssProvider, GtkWidget *g_widget);
void printaa(GtkWidget *widget,gpointer data);
void back(GtkWidget *widget,gpointer data);
/////////////////////////////////////////
int file_len(const char * filename);
long set_id_adh();
adherent  ligne_to_adherent(char * ligne);
int check_in_data(char *nom,char *prenom);
void get_adherents_data_and_add_by_ligne(char * ligne);
void get_adherents_data_and_add(char * nom,char * prenom,char * email,char * adresse);
void  get_adherents_data_delete(char * nom,char * prenom);
void  get_adherents_data_update(char * nom,char * prenom,char * email,char * adresse);
void user_function_after_cherche(int argc, char *argv[],char * nom,char * prenom,char * email,char *adresse,char * nb);
void book_function_after_cherche(int argc, char *argv[],char * titre,char * categorie,char * nom_auteur,char *prenom_auteur,char * id_adh);
void  livres_data_and_emp(char * nom,char * prenom,char * titre,char *categorie);
void add_this(GtkWidget *widget,gpointer data);
void update_this(GtkWidget *widget,gpointer data);
void delete_this(GtkWidget *widget,gpointer data);
/////////////////////////////////////////////////


////////////////////////////////////////////////////////


char * get_text_input(GtkWidget *text_field){
        char *test;
        test=gtk_entry_get_text(GTK_ENTRY(text_field));
        return test;

    }
//////////////////////////////////////////////////////
void set_text_input(GtkWidget *text_field,gchar *text){
        gtk_entry_set_text(GTK_ENTRY(text_field),text);
    }

void open_user_after_clicked_cherche(GtkWidget *widget,gpointer data)
{
    char * text =get_text_input(data);
    if(!strcmp(text,"")){printf("no_input");}
    else{
        int nombre_adherents=file_len("adherents.txt");
       if(nombre_adherents==0){
            printf("aucune adh n est dispo");
        return ;}
    FILE * f=fopen("adherents.txt","r");
    char ligne[900];
    while(fgets(ligne,900,f)!=NULL)
        {
        if(strstr(ligne,text)!=NULL){
                printf("%s",ligne);

                adherent adh =ligne_to_adherent(ligne);
                printf("%s/n",adh.id);
                printf("%s/n",adh.nom);
                printf("%s/n",adh.prenom);
                printf("%s/n",adh.email);
                printf("%s/n",adh.adresse);
                printf("%s/n",adh.nb);
user_function_after_cherche(0, 0,adh.nom,adh.prenom,adh.email,adh.adresse,adh.nb);
                break;}
        ;};
    fclose(f);
    fclose(f);}
}



/////////////////////////////////
void add_this(GtkWidget *widget,gpointer data)

{   char *ligne=get_text_input(data);
     static ia=0;
     static char  noma[150];
     static char  prenoma[150];
    static char  emaila[150];
     static char  adressa[150];
if(ia==2){strcpy(noma,ligne);printf("%s/",noma);
ia++;}

if(ia==5){strcpy(prenoma,ligne);printf("%s//",prenoma);
ia++;}
if(ia==8){strcpy(emaila,ligne);printf("%s///",emaila);ia++;}
if(ia==11){strcpy(adressa,ligne);printf("%s////",adressa);get_adherents_data_and_add(noma,prenoma,emaila,adressa);ia=-3;}
else{ia++;};    //return ligne;



}
void update_this(GtkWidget *widget,gpointer data){
    char *ligne=get_text_input(data);
    static int i=0;
    static char  nom[150];
    static char  prenom[150];
    static char  email[150];
    static char  adress[150];
if(i==2){strcpy(nom,ligne);printf("%s/",nom);
i++;}

if(i==5){strcpy(prenom,ligne);printf("%s//",prenom);
i++;}
if(i==8){strcpy(email,ligne);printf("%s///",email);i++;}
if(i==11){strcpy(adress,ligne);printf("%s////",adress);i++;get_adherents_data_update(nom,prenom,email,adress);i=-3;
int nombre_histo=file_len("history.txt");

        FILE * h=fopen("history.txt","a");
        fputs("un adh a ete ajouter:",h);fputs(" ",h);fputs(nom,h);fputs(" ",h);fputs(prenom,h);fputs(" ",h);fputs(email,h);fputs(" ",h);fputs(adress,h);fputs("\n",h);fclose(h);fclose(h);}
else{i++;};    //return ligne;



}

void delete_this(GtkWidget *widget,gpointer data){
    printf("%s",data);
    get_adherents_data_delete(data,"");
    int nombre_histo=file_len("history.txt");

        FILE * h=fopen("history.txt","a");
        fputs("un adh a ete supprimer:",h);fputs(" ",h);fputs(data,h);fputs("\n",h);fclose(h);fclose(h);
    //printf("succ");
}
///////////////////////////////////////////////
long set_id_adh(){
time_t t;
srand((unsigned) time(&t));
FILE * f=fopen("adherents.txt","r");
char id[20];
long i=rand();
itoa(i,id,10);


char ligne[900];
 while(fgets(ligne,900,f)!=NULL)
        {
        if(strstr(ligne,id)!=NULL){
                i=rand();
                itoa(i,id,10);
        };

        };
return i;}
//////////////////////////////////////////
int file_len(const char * filename){
    FILE * f=NULL;
    if(fopen(filename,"r")==NULL){
    f=fopen(filename,"w");
    fclose(f);
    };
    f=fopen(filename,"r");
    int len= 0;
    char ligne[50];
    while(fgets(ligne,50,f)!=NULL){
        len+=1;
    };
    fclose(f);
    return len;

};
/////////////////////////////////////////






/////////////////////////////////////////

adherent  ligne_to_adherent(char * ligne){
    char * token = strtok(ligne, " ");
        adherent  adh;
       int compteur=0;
       while( token != NULL ) {
            if(compteur==0){
                    strcpy(adh.id,token);

                    };
            if(compteur==1){
                    strcpy(adh.nom,token);

                    };
             if(compteur==2){
             strcpy(adh.prenom,token);};

             if(compteur==3){

                    strcpy(adh.email,token);

                    };
             if(compteur==4){
                    strcpy(adh.adresse,token);

                    };
              if(compteur==5){
                    strcpy(adh.nb,token);
                    compteur=-1;
                                       };

      token = strtok(NULL, " ");
      compteur+=1;
   };
   return adh;}
////////////////////////////////////////
//////////////////////////////////////////
void get_adherents_data()
{
    int nombre_adherents=file_len("adherents.txt");
    FILE * f=fopen("adherents.txt","r");
    if(nombre_adherents==0){
            printf("aucune adh n est dispo");
        return ;
    }
    adherent adherents[nombre_adherents];
    char ligne[900];
    int i=0;
    while(fgets(ligne,900,f)!=NULL)
        {
            adherents[i]=ligne_to_adherent(ligne);
            i+=1;
    };
    fclose(f);
    };
///////////////////////////////////////
void get_adherents_data_and_add(char * nom,char * prenom,char * email,char * adresse)
{
    int i=check_in_data(nom,prenom);
    if(i==0){
    int nombre_adherents=file_len("adherents.txt");//ici juste pour l erreur
    char id[20];
    itoa(set_id_adh(),id,10);

    FILE * f=fopen("adherents.txt","a");
    fputs(id,f);fputs(" ",f);fputs(nom,f);fputs(" ",f);fputs(prenom,f);fputs(" ",f);fputs(email,f);fputs(" ",f);fputs(adresse,f);fputs(" ",f);fputs("0",f);
    fputs("\n",f);

    fclose(f);}else{return;};
    }
///////////////////////////////////////////////////
void get_adherents_data_and_add_by_ligne(char * ligne){
static int i=0;
if(i==0){//printf("%s",ligne);
//adherent adh =ligne_to_adherent(ligne);
static int j=0;
if(j==1){printf("%s/",ligne);}
else{j++;}
//printf("%s/",adh.nom);
//printf("%s/",adh.prenom);
;}else{i++;};

}

////////////////////////////////////////////

///////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
void  get_adherents_data_delete(char * nom,char * prenom)
{   int nombre_adherents=file_len("adherents.txt");
       if(nombre_adherents==0){
            printf("aucune adh n est dispo");
        return ;}
    FILE * f=fopen("adherents.txt","r");
    data list[nombre_adherents];
    char ligne[900]="";
    char this_adh_ligne[900]="";
    char full_name[700]="";
    int i=0;
    strcat(full_name,nom);strcat(full_name," ");strcat(full_name,prenom);
    printf("/n%s/n",full_name);
    while(fgets(ligne,900,f)!=NULL)
        {

        if(strstr(ligne,full_name)==NULL){
                strcpy(list[i].ligne,ligne);
                //printf("%s",list[i].ligne);

                }else{strcpy(list[i].ligne,"NULL");};i++;}
                 fclose(f);
                 fclose(f);
                 i=0;

                 f=fopen("adherents.txt","w");
                 fclose(f);
                 fclose(f);
                f=fopen("adherents.txt","a");
                 for(i;i<nombre_adherents;i++){
                    if(strcmp(list[i].ligne,"NULL"))
                    {
                        fputs(list[i].ligne,f);

                    }
                 };

                 fclose(f);
                 fclose(f);
};
//////////////////////////////////////////
void  get_adherents_data_update(char * nom,char * prenom,char * email,char * adresse)
{

while(1){
        int j=0;
    if(j==0){int nombre_adherents=file_len("adherents.txt");
       if(nombre_adherents==0){
            printf("aucune adh n est dispo");
        return ;}
    FILE * f=fopen("adherents.txt","r");
    data list[nombre_adherents];
    char ligne[900];
    char full_name[800]="";
    int i=0;
    strcat(full_name,nom);strcat(full_name," ");strcat(full_name,prenom);
    printf("/n%s/n",full_name);
    while(fgets(ligne,900,f)!=NULL)
        {
        if(strstr(ligne,full_name)==NULL){
                strcpy(list[i].ligne,ligne);
                //printf("%s",list[i].ligne);

                }else{strcpy(list[i].ligne,"NULL");};i++;}
                 fclose(f);
                 fclose(f);
                 i=0;
                 f=fopen("adherents.txt","w");
                 fclose(f);
                 fclose(f);
                f=fopen("adherents.txt","a");
                 for(i;i<nombre_adherents;i++){
                    if(strcmp(list[i].ligne,"NULL"))
                    {
                        fputs(list[i].ligne,f);

                    }
                 };
                 fclose(f);
                 fclose(f);j=1;};
if(j==1){get_adherents_data_and_add(nom,prenom,email,adresse);break;};}

}

////////////////////////////////////////////////////
char  find_adh(char* nom)
{ int nombre_adherents=file_len("adherents.txt");
       if(nombre_adherents==0){
            printf("aucune adh n est dispo");
        return ;}
    FILE * f=fopen("adherents.txt","r");
    char ligne[900];
    while(fgets(ligne,900,f)!=NULL)
        {
        if(strstr(ligne,nom)!=NULL){
                strcat(ligne,"\o");
                printf("%s",ligne);
                return ligne;


        }
        ;}

        strcpy(ligne,"NULL");
        return ligne;
        }



/////////////////////////////////////////////////////////
int check_in_data(char *nom,char *prenom){
int nombre_adherents=file_len("adherents.txt");
       if(nombre_adherents==0){
            printf("aucune adh n est dispo");
        return 0;}
    FILE * f=fopen("adherents.txt","r");
    char ligne[900];
    char full_name[700]="";
    strcat(full_name,nom);strcat(full_name," ");strcat(full_name,prenom);
    //printf("%s/",full_name);
    while(fgets(ligne,900,f)!=NULL)
        {
        if(strstr(ligne,full_name)!=NULL){
                fclose(f);
        fclose(f);
                return 1;}; } ;fclose(f);fclose(f);return 0;}


////////////////////////////////////////////////////////
////////////////////////////////////////////////////////


     void printaa(GtkWidget *widget,gpointer data){
    printf("aaa");

}
void back(GtkWidget *widget,gpointer data){
    gtk_widget_destroy (data);
}


void css_set(GtkCssProvider * cssProvider, GtkWidget *g_widget) {

        GtkStyleContext *context = gtk_widget_get_style_context(g_widget);

        gtk_style_context_add_provider (context,
                GTK_STYLE_PROVIDER(cssProvider),
                GTK_STYLE_PROVIDER_PRIORITY_USER);
        }





