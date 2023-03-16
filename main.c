 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

typedef struct candidat{
int ncni;
char nom[25];
char prenom[25];
int age;
} candidat;

candidat c;

typedef struct bacc{
    int ncni;
    float moyenne;
    char seriebacc;
    float notemath;
    float notephys;
} bacc;
  bacc b;
typedef struct choix{
int ncni;
char choix2;
char choix3;
} choix;
choix ch;

char rep='n';

int rech(int ncnirech)
{
    FILE *f=fopen("candidat.txt","r");
    do
    {
        fscanf(f,"\n%d ;\n%s ;\n%s ;\n%d ",&c.ncni,&c.nom,&c.prenom,&c.age);
        /*fflush(stdin);*/
        if(c.ncni == ncnirech)
        {
            fclose(f);
            return 1;
        }

    }while(!feof(f));
fclose(f);
}

int rec(int ncnirech)
{
    FILE *ba=fopen("baccalaureat.txt","r");
    do
    {
        fscanf(ba,"\n%d ;\n%f ;\n%s ;\n%f ;\n%f ",&b.ncni,&b.moyenne,&b.seriebacc,&b.notemath,&b.notephys);
        fflush(stdin);
        if(b.ncni == ncnirech)
        {
            fclose(ba);
            return 1;
        }

    }while(!feof(ba));
fclose(ba);
}

int reche(int ncnirech)
{
    FILE *c=fopen("choix.txt","r");
    do
    {
        fscanf(c,"\n%d ;\n%s ;\n%s ",&ch.ncni,&ch.choix2,&ch.choix3);
        fflush(stdin);
        if(ch.ncni == ncnirech)
        {
            fclose(c);
            return 1;
        }

    }while(!feof(c));
fclose(c);
}


int saisircandidat(void){
FILE *f=fopen("candidat.txt","a");
if(f==NULL)
{
    printf("impossible d ouvrir le fichier !");
    exit(1);
}
do
{
 system("cls");
 printf("entrer le numero de cni du candidat:\n");
 scanf("%d",&c.ncni);
 printf("entrer le nom du candidat:\n");
 scanf("%s",&c.nom);
 printf("entrer le prenom du candidat:\n");
 scanf("%s",&c.prenom);
 printf("entrer son age:\n");
 scanf("%d",&c.age);
 fprintf(f,"\n%d ,\n%s ,\n%s ,\n%d ",c.ncni,c.nom,c.prenom,c.age);
 printf("\n voulez vous continuer o/n:");
 scanf("%s",&rep);
}while(rep=='o'||rep=='O');
fclose(f);
}
int saisirBacc(void){

FILE *ba;
ba=fopen("baccalaureat.txt","a");
if(ba==NULL){
    printf("error:'ce fichier est impossible d ouvrir' ");
    exit(1);
}else
{

do{
    system("cls");
    printf("entrer le numero de votre cni:\n");
    scanf("%d",&b.ncni);
    printf("entrer la moyenne obtenue au Bacc:\n");
    scanf("%f",&b.moyenne);
    printf("entrer votre serie(A,C,D,E,F...):\n");
    scanf("%s",&b.seriebacc);
    printf("entrer votre note de math au dit bacc:\n");
    scanf("%f",&b.notemath);
    printf("entrer votre note de physique au dit bacc:\n");
    scanf("%f",&b.notephys);
    fprintf(ba,"\n%d ,\n%f ,\n%s ,\n%f ,\n%f ",b.ncni,b.moyenne,b.seriebacc,b.notemath,b.notephys);
    printf("voulez vous continuer oui(o) ou non(n):\n");
    scanf("%s",&rep);
}while(rep=='o'||rep=='O');
fclose(ba);
}
}

int saisirChoix(void){

FILE *c=fopen("choix.txt","a");
if(c==NULL)
{
    printf("erreur ce fichier est impossible a ouvrir");
    exit(-1);
}
do
{
    printf("entrer le numero de votre cni:\n");
    scanf("%d",&ch.ncni);
    printf("entrer votre filiere numero 2:\n");
    scanf("%s",&ch.choix2);
    printf("entrer votre filiere numero 3:\n");
    scanf("%s",&ch.choix3);
    fprintf(c,"\n%d ,\n%s ,\n%s ",ch.ncni,ch.choix2,ch.choix3);
    printf("voulez vous continuer: oui(o) ou non(n) \n");
    scanf("%s",&rep);
}while(rep=='o'||rep=='O');
fclose(c);
}


void ajoutercandidat(){
system("cls");
int s=0;
s=saisircandidat();
}
  void ajouterbacc(){
      system("cls");
  int m=0;
  m=saisirBacc();
  }
void ajouterchoix(){
    system("cls");
int n=0;
n=saisirChoix();
}
void modifiercandidat(){
    int ncni;
    char rep='n';
    FILE *f,*f1;
    printf("entrer le numero de cni du candidat a modifier:\n");
    scanf("%d",&ncni);
    fflush(stdin);
    if(rech(ncni)==1)
    {
        printf("\n voulez vous vraiment modifier (o/n)? \n");
        rep=getch();
        fflush(stdin);
        if(rep=='o'||rep=='O'){
    f=fopen("candidat.txt","r");
    f1=fopen("candidat1.txt","a");
    do
    {
        fscanf(f,"\n%d ;\n%s ;\n%s ;\n%d ",&c.ncni,&c.nom,&c.prenom,&c.age);

        if(ncni==c.ncni)
        {
            printf("vous allez modifier ceci:\n");
            printf("\n ncni:%d",c.ncni);
            printf("\n nom:%s",c.nom);
            printf("\n prenom:%s",c.prenom);
            printf("\n age:%d",c.age);
            printf("\n\n\n");
            c.ncni=ncni;
            printf("entrer le nouveau nom :\n");
            scanf("%s",&c.nom);
            fflush(stdin);
            printf("entrer le nouveau prenom :\n");
            scanf("%s",&c.prenom);
            fflush(stdin);
            printf("entrer votre nouvel age :\n");
            scanf("%d",&c.age);
            fflush(stdin);
            printf("\n modification reussie !\n");
        }
    fprintf(f1,"\n%d ,\n%s ,\n%s ,\n%d ",c.ncni,c.nom,c.prenom,c.age);
    fclose(f);
    fclose(f1);
    remove("candidat.txt");
    rename("candidat1.txt","candidat.txt");
    break;

    }while(!feof(f));


}
        else
         {
             printf("\n la modification a ete annulee !\n");
         }
}
    else
    {
        printf("\n ce numero n existe pas !\n");
    }
}
void modifierbacc(){

    int cni=0;
    char rep='n';
    FILE *ba,*ba1;

    printf("entrer le numero de cni du candidat:\n");
    scanf("%s",&cni);
    fflush(stdin);
    if(rec(cni)==1)
    {
      printf("\n voulez-vous vraiment modifier (o/n)? \n ");
      scanf("%s",&rep);
      fflush(stdin);
    ba=fopen("baccalaureat.txt","r");
    ba1=fopen("baccalaureat1.txt","a");
    if(rep=='o'||rep=='O'){
    do
    {
        fscanf(ba,"\n%d ;\n%f ;\n%s ;\n%f ;\n%f ",&b.ncni,&b.moyenne,&b.seriebacc,&b.notemath,&b.notephys);
        if(cni==b.ncni)
        {
            printf("vous allez modifier ceci:\n");
            printf("\n ncni=%d",b.ncni);
            printf("\n moyenne=%f",b.moyenne);
            printf("\n seriebacc=%s",b.seriebacc);
            printf("\n notemath=%f",b.notemath);
            printf("\n notephys=%f",b.notephys);
            b.ncni=cni;
            printf("\n saisissez votre moyenne :");
            scanf("%f",&b.moyenne);
            fflush(stdin);
            printf("\n saisissez votre serie :");
            scanf("%s",&b.seriebacc);
            fflush(stdin);
            printf("\n saisissez votre note de math :");
            scanf("%f",&b.notemath);
            fflush(stdin);
            printf("\n saisissez votre note de physique :");
            scanf("%f",&b.notephys);
            fflush(stdin);
            fprintf(ba,"\n%d ,\n%f ,\n%s ,\n%f ,\n%f ",b.ncni,b.moyenne,b.seriebacc,b.notemath,b.notephys);
            printf("\n\n");
            printf("\t\t modification reussie !");
        }
        fclose(ba);
        fclose(ba1);
        remove("baccalaureat.txt");
        rename("baccalaureat1.txt","baccalaureat.txt");
        break;
    }while(!feof(ba));
    }
    else
    {
        printf("\n\t modification annulee !");
    }

    }
    else
    {
        printf("\n\t ce numero n existe pas !");
    }


}

void modifierchoix(){
int cnni;
FILE *c,*c1;
char rep='n';
printf("entrer le numero de cni du candidat :\n");
scanf("%d",&cnni);
fflush(stdin);
if(reche(cnni)==1)
{
    printf("voulez-vous vraiment modifier ce fichier (o/n) :\n");
    scanf("%s",&rep);
    fflush(stdin);
    c=fopen("choix.txt","r");
    c1=fopen("choix1.txt","a");
    if(rep=='o'||rep=='O')
    {
        do{
                fscanf(c,"\n%d ;\n%s ;\n%s ",&ch.ncni,&ch.choix2,&ch.choix3);
                if(cnni==ch.ncni){
            ch.ncni=cnni;
            printf("\n entrer votre second choix :");
            scanf("%s",&ch.choix2);
            fflush(stdin);
            printf("\n entrer votre troisieme choix :");
            scanf("%s",&ch.choix3);
            fflush(stdin);
            fprintf(c,"\n%d ,\n%s ,\n%s ",ch.ncni,ch.choix2,ch.choix3);
            printf("\n\n\n\t\t modification reussie !");
                }
                fclose(c);
                fclose(c1);
                remove("choix.txt");
                rename("choix1.txt","choix.txt");
                break;
        }while(!feof(c));
    }
    else
    {
        printf("\n modification annulee ! ");
    }
}
else
{
    printf("\n ce numero de cni n existe pas !");
}

}


void supprimercandidat(){
int num;
    char rep='n';
    FILE *f,*f1;
    printf("entrer le numero de cni du candidat a supprimer:\n");
    scanf("%d",&num);
    fflush(stdin);
    if(rech(num)==1)
    {
        printf("\n voulez vous vraiment supprimer (o/n)? \n");
        rep=getch();
        fflush(stdin);
        if(rep=='o'||rep=='O')
        {
    f=fopen("candidat.txt","r");
    f1=fopen("candidat1.txt","a");
    do
    {
        fscanf(f,"\n%d ;\n%s ;\n%s ;\n%d ",&c.ncni,&c.nom,&c.prenom,&c.age);
        if(num!=c.ncni)
        {
            fprintf(f1,"\n%d ,\n%s ,\n%s ,\n%d ",c.ncni,c.nom,c.prenom,c.age);
        }
    }while(!feof(f));
    fclose(f1);
    fclose(f);
    remove("candidat.txt");
    rename("candidat1.txt","candidat.txt");
    printf("\n\n\t\t suppression effectuee avec succees !");
        }
    }else
    {
        printf("\n ce numero n existe pas !");
    }
}

void supprimerbacc()
{
      int nucni=0;
    char rep='n';
    FILE *ba,*ba1;

    printf("entrer le numero de cni du candidat:\n");
    scanf("%s",&nucni);
    fflush(stdin);
    if(rec(nucni)==1)
    {
      printf("\n voulez-vous vraiment supprimer (o/n)? \n ");
      scanf("%s",&rep);
      fflush(stdin);
    ba=fopen("baccalaureat.txt","r");
    ba1=fopen("baccalaureat1.txt","a");
    if(rep=='o'||rep=='O'){
    do
    {
        fscanf(ba,"\n%d ;\n%f ;\n%s ;\n%f ;\n%f ",&b.ncni,&b.moyenne,&b.seriebacc,&b.notemath,&b.notephys);
        if(nucni!=b.ncni)
        {
            fprintf(ba1,"\n%d ,\n%f ,\n%s ,\n%f ,\n%f ",b.ncni,b.moyenne,b.seriebacc,b.notemath,b.notephys);
        }
    }while(!feof(ba));

    fclose(ba1);
    fclose(ba);
    remove("baccalaurerat.txt");
    rename("baccalaureat1.txt","baccalaureat.txt");
    printf("\n\n\t\t suppression effectue avec succees !");

    }
    }
    else
    {
        printf("\n\n\t\t ce numero n existe pas !");
    }

}

void supprimerchoix()
{

 int nucnni;
FILE *c,*c1;
char rep='n';
printf("entrer le numero de cni du candidat :\n");
scanf("%d",&nucnni);
fflush(stdin);
if(reche(nucnni)==1)
{
    printf("voulez-vous vraiment supprimer ce fichier (o/n) :\n");
    scanf("%s",&rep);
    fflush(stdin);
    c=fopen("choix.txt","r");
    c1=fopen("choix1.txt","a");
    if(rep=='o'||rep=='O')
    {
        do{
                fscanf(c,"\n%d ;\n%s ;\n%s ",&ch.ncni,&ch.choix2,&ch.choix3);
                if(nucnni!=ch.ncni)
                {
                    fprintf(c1,"\n%d ,\n%s ,\n%s ",ch.ncni,ch.choix2,ch.choix3);
                }
        }while(!feof(c));
 fclose(c1);
 fclose(c);
 remove("choix.txt");
 rename("choix1.txt","choix.txt");
 printf("\n\n\t\t suppression effectuee avec sucees !");
    }
}else{
printf("\n\n\t\t ce numero n existe pas !");
}
}

int main()
{
    system("color 5B");
  int choix;

  do
  {
      printf("\t\t*****************projet de l ue 1031****************\t\n\n\n");
      printf("1-)AJOUTER UN CANDIDAT;\n");
      printf("2-)AJOUTER UN LES INFORMATIONS SUR SON BACC;\n");
      printf("3-)AJOUTER LES AUTRES FILIERES EN CAS DE REJET;\n");
      printf("4-)MODIFIER LES INFORMATIONS RELATIVES AU CANDIDAT;\n");
      printf("5-)MODIFIER LES INFORMATIONS RELATIVES AU BACCALAUREAT;\n");
      printf("6-)MODIFIER LES INFORMATIONS RELATIVES AU CHOIX;\n");
      printf("7-)SUPPRESSION D UN CANDIDAT;\n");
      printf("8-)SUPPRESSION D UN BACC;\n");
      printf("9-)SUPPRESION D UN CHOIX DE FILIERE;\n");
      printf("10-)QUITTER");
      printf("\n\n\n");

      printf("\t\t ENTRER VOTRE CHOIX :\n");
      scanf("%d",&choix);

      switch(choix){
      case 1:
          system("cls");
          ajoutercandidat();
          break;
      case 2:
          system("cls");
          ajouterbacc();
          break;
      case 3:
          system("cls");
          ajouterchoix();
          break;
      case 4:
          system("cls");
          modifiercandidat();
          break;
      case 5:
           system("cls");
          modifierbacc();
          break;
      case 6:
           system("cls");
          modifierchoix();
          break;
      case 7:
          system("cls");
          supprimercandidat();
          break;
      case 8:
        system("cls");
        supprimerbacc();
        break;
      case 9:
        system("cls");
        supprimerchoix();
        break;
      case 10:
        system("cls");
        break;
      }

  }while(choix!=10);
}
