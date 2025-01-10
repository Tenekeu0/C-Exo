// ListeSimple.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "Liste.h"
#include "Collection.h"

int main()
{
    int tab[20] = { 1,2,3,4,5,6,7,8,9 };
    //Liste listeDefaut1, default2;
    Liste liste(10, tab);
    Collection& col = liste;

    col.ajouter(5);
    col.afficherListe();

    //Liste listeCopie(liste);
    //Liste listeAffecte = Liste();
    //liste = listeCopie;

    //listeDefaut1 = default2;
    //liste.ajouter(5);
    //liste.afficherListe();
    //liste.supprimer(2);
    //liste.afficherListe();
    //liste.definir(1,42);
    //liste.afficherListe();
    //liste.definir(9,42);
    //liste.afficherListe();
    //liste.supprimer(9);
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
