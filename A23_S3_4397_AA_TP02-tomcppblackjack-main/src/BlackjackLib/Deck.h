#pragma once
#include "ListeChaineeCartes.h"
#include "Carte.h"
// inspiré d'un travail précedemment fait

class Deck
{
    public:
        Deck();
        ~Deck();
        void MelangerCartes();
        Carte DistribuerCarte();
        //void AjouterCarte(const ListeChaineeCartes<Carte>& p_carteAAjouter);
    private:
        ListeChaineeCartes<Carte> m_Deck;
};

