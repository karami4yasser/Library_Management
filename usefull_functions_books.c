long set_id_livre();
livre  ligne_to_livre(char * ligne);
int check_in_data_book(char *titre,char *categorie);
void get_livres_data_and_add_by_ligne(char * ligne);
void get_livres_data_and_add(char * titre,char * categorie,char * nom_auteur,char * prenom_auteur);
void  get_livres_data_delete(char * titre,char * categorie);
void get_livres_data_and_update(char * titre,char * categorie,char * nom_auteur,char * prenom_auteur);
void book_function_after_cherche(int argc, char *argv[],char * titre,char * categorie,char * nom_auteur,char *prenom_auteur,char * id_adh);
void  livres_data_and_emp(char * nom,char * prenom,char * titre,char *categorie);
void  livres_data_and_rend(char * nom,char * prenom,char * titre,char *categorie);
void add_this_book(GtkWidget *widget,gpointer data);
void emp_this_book(GtkWidget *widget,gpointer data);
void rend_this_book(GtkWidget *widget,gpointer data);
void update_this_book(GtkWidget *widget,gpointer data);
void delete_this_book(GtkWidget *widget,gpointer data);
//////////////////////////////////////////////////////


void open_book_after_clicked_cherche(GtkWidget *widget,gpointer data)
{
    char * text =get_text_input(data);
    if(!strcmp(text,"")){printf("no_input");}
    else{
        int nombre_adherents=file_len("livres.txt");
       if(nombre_adherents==0){
            printf("aucune livre n est dispo");
        return ;}
    FILE * f=fopen("livres.txt","r");
    char ligne[900];
    while(fgets(ligne,900,f)!=NULL)
        {
        if(strstr(ligne,text)!=NULL){
                printf("%s",ligne);

                livre adh =ligne_to_livre(ligne);
                printf("%s/n",adh.id);
                printf("%s/n",adh.titre);
                printf("%s/n",adh.categorie);
                printf("%s/n",adh.nom_auteur);
                printf("%s/n",adh.prenom_auteur);
                printf("%s/n",adh.id_adherent);
book_function_after_cherche(0, 0,adh.titre,adh.categorie,adh.nom_auteur,adh.prenom_auteur,adh.id_adherent);
                break;}
        ;};
    fclose(f);
    fclose(f);}
}



/////////////////////////////////
void add_this_book(GtkWidget *widget,gpointer data)

{   char *ligne=get_text_input(data);
    static int ie=0;
    static char  titree[150];
    static char  categoriee[150];
    static char  nom_auteure[150];
    static char  prenom_auteure[150];


if(ie==2){strcpy(titree,ligne);printf("%s/",titree);
ie++;}

if(ie==5){strcpy(categoriee,ligne);printf("%s//",categoriee);
ie++;}
if(ie==8){strcpy(nom_auteure,ligne);printf("%s///",nom_auteure);ie++;}
if(ie==11){strcpy(prenom_auteure,ligne);printf("%s////",prenom_auteure);get_livres_data_and_add(titree,categoriee,nom_auteure,prenom_auteure);ie=-3;
int nombre_histo=file_len("history.txt");

        FILE * h=fopen("history.txt","a");
        fputs("un livre a ete ajouter:",h);fputs(" ",h);fputs(titree,h);fputs(" ",h);fputs(categoriee,h);fputs(" ",h);fputs(nom_auteure,h);fputs(" ",h);fputs(prenom_auteure,h);fputs("\n",h);fclose(h);fclose(h);}
else{ie++;};    //return ligne;



}
void update_this_book(GtkWidget *widget,gpointer data){ char *ligne=get_text_input(data);
    static int i=0;
    static char  nom[150];
    static char  prenom[150];
    static char  email[150];
    static char  adress[150];
if(i==3){strcpy(nom,ligne);printf("%s/",nom);
i++;}

if(i==6){strcpy(prenom,ligne);printf("%s//",prenom);
i++;}
if(i==9){strcpy(email,ligne);printf("%s///",email);i++;}
if(i==12){strcpy(adress,ligne);printf("%s////",adress);i++;get_adherents_data_and_add(nom,prenom,email,adress);i=-3;}
else{i++;};    //return ligne;



}

void delete_this_book(GtkWidget *widget,gpointer data){
    printf("%s",data);
    get_livres_data_delete(data,"");
    int nombre_histo=file_len("history.txt");

        FILE * h=fopen("history.txt","a");
        fputs("un livre a ete supprimer:",h);fputs(" ",h);fputs(data,h);fputs("\n",h);fclose(h);fclose(h);


    //printf("succ");
}
///////////////////////////////////////////////
long set_id_livre(){
time_t t;
srand((unsigned) time(&t));
FILE * f=fopen("livres.txt","r");
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

/////////////////////////////////////////






/////////////////////////////////////////

livre  ligne_to_livre(char * ligne){
    char * token = strtok(ligne, " ");
        livre  adh;
       int compteur=0;
       while( token != NULL ) {
            if(compteur==0){
                    strcpy(adh.id,token);

                    };
            if(compteur==1){
                    strcpy(adh.titre,token);

                    };
             if(compteur==2){
             strcpy(adh.categorie,token);};

             if(compteur==3){

                    strcpy(adh.nom_auteur,token);

                    };
             if(compteur==4){
                    strcpy(adh.prenom_auteur,token);

                    };
              if(compteur==5){
                    strcpy(adh.id_adherent,token);
                    compteur=-1;
                                       };

      token = strtok(NULL, " ");
      compteur+=1;
   };
   return adh;}
////////////////////////////////////////
//////////////////////////////////////////
void get_livres_data()
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
            //adherents[i]=ligne_to_adherent(ligne);
            i+=1;
    };
    fclose(f);
    };
///////////////////////////////////////
void get_livres_data_and_add(char * titre,char * categorie,char * nom_auteur,char * prenom_auteur)
{
    int i=check_in_data_book(titre,categorie);
    if(i==0){
    int nombre_livres=file_len("livres.txt");//ici juste pour l erreur
    char id[20];
    itoa(set_id_livre(),id,10);

    FILE * f=fopen("livres.txt","a");
    fputs(id,f);fputs(" ",f);fputs(titre,f);fputs(" ",f);fputs(categorie,f);fputs(" ",f);fputs(nom_auteur,f);fputs(" ",f);fputs(prenom_auteur,f);fputs(" ",f);fputs("NULL",f);
    fputs("\n",f);

    fclose(f);}else{return;};
    }
///////////////////////////////////////////////////
void get_livres_data_and_add_by_ligne(char * ligne){
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

///////////////////////////////////////////
void  get_livres_data_delete(char * titre,char * categorie)
{   int nombre_adherents=file_len("livres.txt");
       if(nombre_adherents==0){
            printf("aucune liv n est dispo");
        return ;}
    FILE * f=fopen("livres.txt","r");
    data list[nombre_adherents];
    char ligne[900]="";
    char full_name[700]="";
    int i=0;
    strcat(full_name,titre);strcat(full_name," ");strcat(full_name,categorie);
    printf("///////n%s/n/////////",full_name);
    while(fgets(ligne,900,f)!=NULL)
        {
        if(strstr(ligne,full_name)==NULL){
                strcpy(list[i].ligne,ligne);
                //printf("%s",list[i].ligne);

                }else{strcpy(list[i].ligne,"NULL");};i++;}
                 fclose(f);
                 fclose(f);
                 i=0;
                 f=fopen("livres.txt","w");
                 fclose(f);
                 fclose(f);
                f=fopen("livres.txt","a");
                 for(i;i<nombre_adherents;i++){
                    if(strcmp(list[i].ligne,"NULL"))
                    {
                        fputs(list[i].ligne,f);

                    }
                 };
                 fclose(f);
                 fclose(f);

};
////



//////////////////////////////////////////
void  get_livres_data_update(char * titre,char * categorie,char * nom_auteur,char * prenom_auteur)
{   get_livres_data_delete(titre,categorie);
get_livres_data_and_add(titre,categorie,nom_auteur,prenom_auteur);

}

////////////////////////////////////////////////////
char  find_livre(char* nom)
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
int check_in_data_book(char *titre,char *categorie){
int nombre_adherents=file_len("livres.txt");
       if(nombre_adherents==0){
            printf("aucune adh n est dispo");
        return 0;}
    FILE * f=fopen("livres.txt","r");
    char ligne[900];
    char full_name[700]="";
    strcat(full_name,titre);strcat(full_name," ");strcat(full_name,categorie);
    printf("%s/",full_name);
    while(fgets(ligne,900,f)!=NULL)
        {
        if(strstr(ligne,full_name)!=NULL){
                fclose(f);
        fclose(f);
                return 1;}; } ;fclose(f);fclose(f);return 0;}

                ////////////////////////////////////////////


void  livres_data_and_emp(char * nom,char * prenom,char * titre,char *categorie)
{
int nombre_adherents=file_len("adherents.txt");
       if(nombre_adherents==0){
            printf("aucune adh n est dispo");
        return ;}
     int nombre_livres=file_len("livres.txt");
       if(nombre_livres==0){
            printf("aucune livre n est dispo");
        return ;};

    FILE * f=fopen("adherents.txt","r");
    FILE * f2=fopen("livres.txt","r");
    data list[nombre_adherents];
    data list2[nombre_livres];
    char ligne[900]="";
    char ligne2[900]="";
    char ligne_adh[900]="";
    char ligne_book[900]="";
    char full_name[700]="";
    char full_deta[700]="";
    int i=0;
    int j=0;
    int k=0;
    strcat(full_name,nom);strcat(full_name," ");strcat(full_name,prenom);
    strcat(full_deta,titre);strcat(full_deta," ");strcat(full_deta,categorie);
    //printf("%d/%d",nombre_adherents,nombre_livres);
    //printf("%s/%s",full_name,full_deta);
    while(fgets(ligne,900,f)!=NULL)
        {
        if(strstr(ligne,full_name)==NULL){
                strcpy(list[i].ligne,ligne);
                //printf("%s",list[i].ligne);

                }else{strcpy(list[i].ligne,"NULL");strcpy(ligne_adh,ligne);printf("this%s",ligne_adh);};i++;}
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

                 i=0;
        while(fgets(ligne2,900,f2)!=NULL)
        {
        if(strstr(ligne2,full_deta)==NULL){
                strcpy(list2[i].ligne,ligne2);
                //printf("%s",list[i].ligne);

                }else{strcpy(list2[i].ligne,"NULL");strcpy(ligne_book,ligne2);printf("this%s",ligne_book);};i++;}
                 fclose(f2);
                 fclose(f2);
                 i=0;
                 f2=fopen("livres.txt","w");
                 fclose(f2);
                 fclose(f2);
                f2=fopen("livres.txt","a");
                 for(i;i<nombre_livres;i++){
                    if(strcmp(list2[i].ligne,"NULL"))
                    {
                        fputs(list2[i].ligne,f2);

                    }
                 };

                 fclose(f);fclose(f2);fclose(f);fclose(f2);

            adherent adh=ligne_to_adherent(ligne_adh);
            livre liv=ligne_to_livre(ligne_book);

 FILE * fa=fopen("adherents.txt","a");
    FILE * fb=fopen("livres.txt","a");

            if(strcmp(adh.nb,"3\n")==0 || strcmp(liv.id_adherent,"NULL\n")!=0){
                  fputs(adh.id,fa);fputs(" ",fa);fputs(adh.nom,fa);fputs(" ",fa);fputs(adh.prenom,fa);fputs(" ",fa);fputs(adh.email,fa);fputs(" ",fa);fputs(adh.adresse,fa);fputs(" ",fa);fputs("3\n",fa);
    fputs(liv.id,fb);fputs(" ",fb);fputs(liv.titre,fb);fputs(" ",fb);fputs(liv.categorie,fb);fputs(" ",fb);fputs(liv.nom_auteur,fb);fputs(" ",fb);fputs(liv.prenom_auteur,fb);fputs(" ",fb);fputs(liv.id_adherent,fb);

printf("no please");return;};
             if(strcmp(adh.nb,"0\n")==0){

    fputs(adh.id,fa);fputs(" ",fa);fputs(adh.nom,fa);fputs(" ",fa);fputs(adh.prenom,fa);fputs(" ",fa);fputs(adh.email,fa);fputs(" ",fa);fputs(adh.adresse,fa);fputs(" ",fa);fputs("1\n",fa);
    fputs(liv.id,fb);fputs(" ",fb);fputs(liv.titre,fb);fputs(" ",fb);fputs(liv.categorie,fb);fputs(" ",fb);fputs(liv.nom_auteur,fb);fputs(" ",fb);fputs(liv.prenom_auteur,fb);fputs(" ",fb);fputs(adh.id,fb);fputs("\n",fb);

    fclose(fa);fclose(fb);

    };
    if(strcmp(adh.nb,"1\n")==0){

    fputs(adh.id,fa);fputs(" ",fa);fputs(adh.nom,fa);fputs(" ",fa);fputs(adh.prenom,fa);fputs(" ",fa);fputs(adh.email,fa);fputs(" ",fa);fputs(adh.adresse,fa);fputs(" ",fa);fputs("2\n",fa);
    fputs(liv.id,fb);fputs(" ",fb);fputs(liv.titre,fb);fputs(" ",fb);fputs(liv.categorie,fb);fputs(" ",fb);fputs(liv.nom_auteur,fb);fputs(" ",fb);fputs(liv.prenom_auteur,fb);fputs(" ",fb);fputs(adh.id,fb);fputs("\n",fb);

    fclose(fa);fclose(fb);};
    if(strcmp(adh.nb,"2\n")==0){

    fputs(adh.id,fa);fputs(" ",fa);fputs(adh.nom,fa);fputs(" ",fa);fputs(adh.prenom,fa);fputs(" ",fa);fputs(adh.email,fa);fputs(" ",fa);fputs(adh.adresse,fa);fputs(" ",fa);fputs("3\n",fa);
    fputs(liv.id,fb);fputs(" ",fb);fputs(liv.titre,fb);fputs(" ",fb);fputs(liv.categorie,fb);fputs(" ",fb);fputs(liv.nom_auteur,fb);fputs(" ",fb);fputs(liv.prenom_auteur,fb);fputs(" ",fb);fputs(adh.id,fb);fputs("\n",fb);

    fclose(fa);fclose(fb);};

}











void emp_this_book(GtkWidget *widget,gpointer data)

{   char *ligne=gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(data));


    static int ie=0;
    static char  nom_prenom[150];
    static char  titre_categoriee[150];
if(ie==0){strcpy(nom_prenom,ligne);printf("%s/",nom_prenom);
ie++;}

if(ie==2){strcpy(titre_categoriee,ligne);printf("%s//",titre_categoriee);livres_data_and_emp(nom_prenom,"",titre_categoriee,"");
ie=0;}
else{ie++;}}
//livres_data_and_emp(nom,prenom,titree,categoriee)
//int nombre_histo=file_len("history.txt");

        //FILE * h=fopen("history.txt","a");
        //fputs("le livre ",h);fputs(" ",h);fputs(titree,h);fputs(" ",h);fputs(categoriee,h);fputs(" ",h);fputs("est emprnt par ",h);fputs(" ",h);fputs(nom,h);fputs(" ",h);fputs(prenom,h);fputs("\n",h);fclose(h);fclose(h);
//}
//else{ie++;};    //return ligne;







void  livres_data_and_rend(char * nom,char * prenom,char * titre,char *categorie)
{
int nombre_adherents=file_len("adherents.txt");
       if(nombre_adherents==0){
            printf("aucune adh n est dispo");
        return ;}
     int nombre_livres=file_len("livres.txt");
       if(nombre_livres==0){
            printf("aucune livre n est dispo");
        return ;};

    FILE * f=fopen("adherents.txt","r");
    FILE * f2=fopen("livres.txt","r");
    data list[nombre_adherents];
    data list2[nombre_livres];
    char ligne[900]="";
    char ligne2[900]="";
    char ligne_adh[900]="";
    char ligne_book[900]="";
    char full_name[700]="";
    char full_deta[700]="";
    int i=0;
    int j=0;
    int k=0;
    strcat(full_name,nom);strcat(full_name," ");strcat(full_name,prenom);
    strcat(full_deta,titre);strcat(full_deta," ");strcat(full_deta,categorie);
    //printf("%d/%d",nombre_adherents,nombre_livres);
    //printf("%s/%s",full_name,full_deta);
    while(fgets(ligne,900,f)!=NULL)
        {
        if(strstr(ligne,full_name)==NULL){
                strcpy(list[i].ligne,ligne);
                //printf("%s",list[i].ligne);

                }else{strcpy(list[i].ligne,"NULL");strcpy(ligne_adh,ligne);printf("this%s",ligne_adh);};i++;}
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

                 i=0;
        while(fgets(ligne2,900,f2)!=NULL)
        {
        if(strstr(ligne2,full_deta)==NULL){
                strcpy(list2[i].ligne,ligne2);
                //printf("%s",list[i].ligne);

                }else{strcpy(list2[i].ligne,"NULL");strcpy(ligne_book,ligne2);printf("this%s",ligne_book);};i++;}
                 fclose(f2);
                 fclose(f2);
                 i=0;
                 f2=fopen("livres.txt","w");
                 fclose(f2);
                 fclose(f2);
                f2=fopen("livres.txt","a");
                 for(i;i<nombre_livres;i++){
                    if(strcmp(list2[i].ligne,"NULL"))
                    {
                        fputs(list2[i].ligne,f2);

                    }
                 };

                 fclose(f);fclose(f2);fclose(f);fclose(f2);

            adherent adh=ligne_to_adherent(ligne_adh);
            livre liv=ligne_to_livre(ligne_book);

 FILE * fa=fopen("adherents.txt","a");
    FILE * fb=fopen("livres.txt","a");
    char id_with[200]="";
    strcat(id_with,adh.id);strcat(id_with,"\n");

            if(strcmp(adh.nb,"0\n")==0 || strcmp(liv.id_adherent,"NULL\n")==0  || strcmp(id_with,liv.id_adherent)!=0){
                  fputs(adh.id,fa);fputs(" ",fa);fputs(adh.nom,fa);fputs(" ",fa);fputs(adh.prenom,fa);fputs(" ",fa);fputs(adh.email,fa);fputs(" ",fa);fputs(adh.adresse,fa);fputs(" ",fa);fputs(adh.nb,fa);
    fputs(liv.id,fb);fputs(" ",fb);fputs(liv.titre,fb);fputs(" ",fb);fputs(liv.categorie,fb);fputs(" ",fb);fputs(liv.nom_auteur,fb);fputs(" ",fb);fputs(liv.prenom_auteur,fb);fputs(" ",fb);fputs(liv.id_adherent,fb);

      printf("no please");return;};
             if(strcmp(adh.nb,"1\n")==0){

    fputs(adh.id,fa);fputs(" ",fa);fputs(adh.nom,fa);fputs(" ",fa);fputs(adh.prenom,fa);fputs(" ",fa);fputs(adh.email,fa);fputs(" ",fa);fputs(adh.adresse,fa);fputs(" ",fa);fputs("0\n",fa);
    fputs(liv.id,fb);fputs(" ",fb);fputs(liv.titre,fb);fputs(" ",fb);fputs(liv.categorie,fb);fputs(" ",fb);fputs(liv.nom_auteur,fb);fputs(" ",fb);fputs(liv.prenom_auteur,fb);fputs(" ",fb);fputs("NULL\n",fb);

    fclose(fa);fclose(fb);

    };
    if(strcmp(adh.nb,"2\n")==0){

    fputs(adh.id,fa);fputs(" ",fa);fputs(adh.nom,fa);fputs(" ",fa);fputs(adh.prenom,fa);fputs(" ",fa);fputs(adh.email,fa);fputs(" ",fa);fputs(adh.adresse,fa);fputs(" ",fa);fputs("1\n",fa);
    fputs(liv.id,fb);fputs(" ",fb);fputs(liv.titre,fb);fputs(" ",fb);fputs(liv.categorie,fb);fputs(" ",fb);fputs(liv.nom_auteur,fb);fputs(" ",fb);fputs(liv.prenom_auteur,fb);fputs(" ",fb);fputs("NULL\n",fb);

    fclose(fa);fclose(fb);};
    if(strcmp(adh.nb,"3\n")==0){

    fputs(adh.id,fa);fputs(" ",fa);fputs(adh.nom,fa);fputs(" ",fa);fputs(adh.prenom,fa);fputs(" ",fa);fputs(adh.email,fa);fputs(" ",fa);fputs(adh.adresse,fa);fputs(" ",fa);fputs("2\n",fa);
    fputs(liv.id,fb);fputs(" ",fb);fputs(liv.titre,fb);fputs(" ",fb);fputs(liv.categorie,fb);fputs(" ",fb);fputs(liv.nom_auteur,fb);fputs(" ",fb);fputs(liv.prenom_auteur,fb);fputs(" ",fb);fputs("NULL\n",fb);

    fclose(fa);fclose(fb);};

}




void rend_this_book(GtkWidget *widget,gpointer data)

{   char *ligne=gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(data));


    static int ie=0;
    static char  nom_prenom[150];
    static char  titre_categoriee[150];
if(ie==0){strcpy(nom_prenom,ligne);printf("%s/",nom_prenom);
ie++;}

if(ie==2){strcpy(titre_categoriee,ligne);printf("%s//",titre_categoriee);livres_data_and_rend(nom_prenom,"",titre_categoriee,"");
ie=0;}
else{ie++;}}




