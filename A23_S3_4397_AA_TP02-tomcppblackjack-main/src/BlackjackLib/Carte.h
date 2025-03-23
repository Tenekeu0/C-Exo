#pragma once
#include <iostream>

enum Symbole {Coeur,Carreau,Trefle,Pique };

class Carte
{
    public:
        Carte(int p_valeur, Symbole p_symbole);
        Carte();
        ~Carte();
        static std::string symboleToString(Symbole p_symbole);
        std::string obtenirTypeCarte() const;
        Symbole obtenirSymbole() const;
        int ObtenirValeur() const;
        bool operator>(const Carte& p_autreCarte) const;
        static int comparerCartes(const Carte& p_carte1, const Carte& p_carte2);
    private:
        int m_valeur;
        Symbole m_symboleIndex;
};

