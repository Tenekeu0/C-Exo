#pragma once
#include "Joueur.h"
#include "ListeChaineeCartes.h"
#include "Carte.h"


class Croupier : public Joueur
{
    public:
        Croupier();
        ~Croupier();
        void ajouterCarte(const Carte& p_carte);
        int calculerScore() const;
        void distribuerCarte(Joueur& p_joueur);
        void viderMain();
        bool verifierSiBlackjack();
        bool estBuste() const;
        ListeChaineeCartes<Carte>& obtenirMain();

    private:
        ListeChaineeCartes<Carte> m_main;
};

