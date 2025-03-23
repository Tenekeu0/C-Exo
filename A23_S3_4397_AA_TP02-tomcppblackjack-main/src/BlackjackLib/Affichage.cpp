#include "Affichage.h"
#include "Joueur.h"
#include "Croupier.h"
#include <iostream>

void Affichage::afficherCarte(const Carte& carte) {
    std::string symbole = Carte::symboleToString(carte.obtenirSymbole());
    std::cout << carte.ObtenirValeur() << " de " << symbole << std::endl;
}

void Affichage::afficherMessage(const std::string& message) {
    std::cout << message << std::endl;
}

void Affichage::afficherMain(const ListeChaineeCartes<Carte>& main) {
    std::cout << "main: " << std::endl;
    for (int i = 0; i < main.nombreElements(); ++i) {
        afficherCarte(main.obtenirIndice(i));
    }
}

void Affichage::afficherScore(int score) {
    std::cout << "score: " << score << std::endl;
}

void Affichage::afficherEtatJeuJoueur(Joueur& joueur) {
    afficherMain(joueur.obtenirMain());
    afficherScore(joueur.calculerScore());
}

void Affichage::afficherEtatJeuCroupier(Croupier& croupier) {
    afficherMain(croupier.obtenirMain());
    afficherScore(croupier.calculerScore());
}


bool Affichage::demanderStand() {
    std::string reponse;
    bool stand = false;

    std::cout << "Voulez-vous rejouer ? y pour Oui et n pour Non: ";
    std::cin >> reponse;

    if (reponse == "y" || reponse == "Y") {
        stand = false;
    }
    else if (reponse == "n" || reponse == "N") {
        stand = true;
    }
    else {
        std::cout << "Mauvais choix essayez de nouveau" << std::endl;
        return demanderStand();
    }

    return stand;
}