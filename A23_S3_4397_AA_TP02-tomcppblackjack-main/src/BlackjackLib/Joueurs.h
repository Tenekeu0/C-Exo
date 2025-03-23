#pragma once

template<class T>
class Joueurs {

public:
    Joueurs();

    virtual ~Participant();

    Joueurs(const Joueurs<T>& p_objetACopier);

    Joueurs(const Joueurs<T>&& p_objetADeplacer);

    void InitialiserPaquet() = 0; 

    void ajouterCarte(int p_carte) = 0;

    int calculerScore() const = 0;

    bool verifierBlackjack() = 0;

    bool aBuste() = 0;

    void viderMain() = 0;

    int* getCarte();

    int getNbCarte();

    int getCapaciteCarte();

    int getProchaineCarte();

    bool estJoueur() const;

private:
    int* m_carte;
    int m_nbCartes;
    int m_capaciteMaxCartes;
    int m_prochaineCarte;
};