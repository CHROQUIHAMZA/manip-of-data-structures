#include"headerofall.h"

int main()
{
    printf("LISTE AVEC POINTEUR : \n\n");
    PTliste* liste=NULL;
    liste=creerliste();
    liste=inserer_debut(liste,4);
    printf("%d\n",taille_liste(liste));
    liste=insererbonneplace(liste,3);
    liste=insererbonneplace(liste,5);
    liste=insererbonneplace(liste,9);
    liste=insererbonneplace(liste,0);
    liste=insererbonneplace(liste,3);
    liste=insererbonneplace(liste,7);
    liste=insererbonneplace(liste,1);
    liste=insererbonneplace(liste,3);
    liste=insererbonneplace(liste,11);
    afficher(liste);
    liste=supprimerOccurence(liste,3);
    afficher(liste);
    liste=supprimertouteOccurence(liste,3);
    afficher(liste);
    return 0;
}
