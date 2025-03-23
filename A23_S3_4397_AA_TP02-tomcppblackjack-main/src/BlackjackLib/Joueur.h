#pragma once
#include"ListeChaineeCartes.h"
#include "Carte.h"


class Joueur
{

    public:
        Joueur();
        ~Joueur();
        // recevoir carte
        void hit(const Carte& p_nouvelleCarte);
        bool estBuste();
        int  calculerScore();
        bool verifierSiBlackjack();
        void perdrePartie();
        void perdreMise();
        void gagnerPartie();
        bool estPartieNulle();
        void gagnerAvecBlackjack();

        void renitialiserMise();
        void miseInitialeMise();
        void gagnerMise();
        int  obtenirSolde() const;
        bool verifierSonSolde() const;
        void viderMain();
        ListeChaineeCartes<Carte>& obtenirMain();

        bool estBuste() const;

    private:
        ListeChaineeCartes<Carte> m_main;
        int m_soldeInitiale;
        int m_mise;
        int m_nombreCartes = 7;
};

