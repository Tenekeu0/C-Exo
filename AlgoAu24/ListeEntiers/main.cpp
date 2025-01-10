#include <iostream>
#include "ListeEntiers.h"

int main()
{
    std::cout << "Hello World!\n";
    ListeEntiers listeVide;
    ListeEntiers l3(listeVide); // Ctor par copie

    ListeEntiers l8 = listeVide;// ctor par copie
    ListeEntiers l2;
    l2 = listeVide; // Oper par copie

    listeVide.ajouterDebut(59);
    listeVide.ajouterDebut(10);
    listeVide.ajouterDebut(38);
    listeVide.ajouterDebut(77);
    listeVide.inserer(134, 1);
    listeVide.afficherListe();
    std::cout << listeVide.obtenir(3) << std::endl;

    listeVide.concatener(l2);

    ListeEntiers l4(std::move(listeVide)); // Ctor par déplacement
    ListeEntiers l7(ListeEntiers()); // Ctor par déplacement
    ListeEntiers l5;
    l5 = std::move(l3); // Opérateur par déplacement
    //l5 = ListeEntiers(); // Opérateur par déplacement
}