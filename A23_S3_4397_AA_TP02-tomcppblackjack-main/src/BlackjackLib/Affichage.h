#pragma once

#include "Affichage.h"
#include "Carte.h"
#include "ListeChaineeCartes.h"
#include "Joueur.h"
#include "Croupier.h"

class Affichage{
public:
    bool demanderStand();

    void afficherCarte(const Carte& carte);

    void afficherMain(const ListeChaineeCartes<Carte>& main);

    void afficherScore(int score);

    void afficherMessage(const std::string& message);

    void afficherEtatJeuJoueur(Joueur& joueur);

    void afficherEtatJeuCroupier(Croupier& croupier);
};
