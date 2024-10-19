#include"headerofall.h"


//creer la pile
PTpile *creerpile()
{
    //declarer un pointeur de type ptpile
    PTpile *NE ;
    //allouer la memoire pour la pile
    NE=(PTpile*)malloc(sizeof(PTpile));
    //verifier si l'allocation dynamique reussite
    if(!NE)
    {
        printf("ERROR");
        exit(-1);
    }
    //initialisation de la pile
    NE->suivant=NULL;
    return (PTpile*)(NE);
}

/*-----------------------------------------*/

//vider une pile
PTpile *razepile(PTpile *mapile)
{
    //declarer un poiteur que va contenir les cellules à supprimer
    PTpile *temp ;
    //boucle pour supprimer les elements de la pile
    while(mapile)
    {
        temp=mapile;
        mapile=mapile->suivant;
        free(temp);
    }//fin while
    return(PTpile*)(mapile);
}
//verifier si la pile est vide
int pile_vide(PTpile *mapile)
{
    return (int)(mapile==NULL);
}
//empiler une element
PTpile *empiler(PTpile *mapile,int donnee)
{
    PTpile *NE =creerpile();//creer un nouveau element
    NE->entier=donnee;//remplier le champs donnee
    //verifier si la pile est vide
    if(pile_vide(mapile))
    {
        mapile=NE;
    }//fin if
    else
    {
        NE->suivant=mapile;
        mapile=NE;
    }//fin else
    return (PTpile*)(mapile);
}

/*-----------------------------------------*/

//depiler un element de la pile
PTpile *depiler(PTpile *mapile)
{
    //declarer un element qui contenir l'element supprimer
    PTpile *temp ;
    //verifier si la pile est vide
    if(pile_vide(mapile))
    {
        printf("Pile vide");
        return (PTpile*)(NULL);
    }
    //supprimer la tete de la pile
    temp=mapile;
    mapile=mapile->suivant;
    free(temp);
    return(PTpile*)(mapile);
}

/*-----------------------------------------*/

//savoir la taille de la file
int taille_pile(PTpile*mapile)
{
    //une pile auxiliare
    PTpile *aux ;
    int taille =0 , a;
    //verifier si la pile est vide
    if(pile_vide(mapile))
    {
        return (int)(0);
    }//fin if

    else
    {
        //depiler dans la 2 eme pile
         while(!pile_vide(mapile))
         {
             a=mapile->entier;
             mapile=depiler(mapile);
             aux=empiler(aux,a);
             taille++;

         }//fin while
         //empiler les elements dans la pile originale
          while(!pile_vide(aux))
         {
             a=aux->entier;
             aux=depiler(aux);
             mapile=empiler(mapile,a);

         }//fin while

    }
    return (int)(taille);
}

/*-----------------------------------------*/

PTpile* afficher_pile(PTpile *mapile)
{

    PTpile *aux=NULL ;
    if(pile_vide(mapile))
        printf("pile vide");
    while(mapile)
    {
        printf("\n%d",mapile->entier);
        aux=empiler(aux,mapile->entier);
        mapile=depiler(mapile);

    }
    while(aux)
    {

        mapile=empiler(mapile,aux->entier);
        aux=depiler(aux);

    }
    return (PTpile*)(mapile)
}
PTpile*insererbonneplacepile(PTpile*P,int val)
{
    PTpile*NE=creerpile(),*temp=NULL,*temp1=NULL;
    NE->entier=val;
    if(!P) return(PTpile*)(NE);
    if(P->entier>=val)
    {
        NE->suivant=P;
        return(PTpile*)(NE);
    }
    while(P)
    {
        if(P->entier<val)
        {
            temp1=P;
            P=P->suivant;
            temp1->suivant=temp;
            temp=temp1;
        }
        else
        {
            break;
        }
    }
    NE->suivant=P;
    P=NE;
     while(temp)
    {


            temp1=temp;
            temp=temp->suivant;
            temp1->suivant=P;
            P=temp1;
    }
    return(PTpile*)(P);
}
