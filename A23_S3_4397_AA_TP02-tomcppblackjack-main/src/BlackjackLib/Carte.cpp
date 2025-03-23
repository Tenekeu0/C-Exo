#include "Carte.h"
#include <string>


Carte::Carte(int p_valeur, Symbole p_symbole)
    : m_valeur(p_valeur), m_symboleIndex(p_symbole)
{
}

Carte::~Carte() = default;

std::string Carte::obtenirTypeCarte() const
{
    std::string nomCarte = "";
    if (m_valeur >= 2 && m_valeur <= 10) {

        nomCarte = std::to_string(m_valeur);
    }
    else if (m_valeur >= 11 && m_valeur <= 13) {

        if (m_valeur == 11) {
            nomCarte = "Valet";
        }
        else if (m_valeur == 12) {
            nomCarte = "Dame";
        }
        else {
            nomCarte = "Roi";
        }
    }
    else if (m_valeur == 1) {

        nomCarte = "As";
    }
    else {
        nomCarte = "Carte Invalide";
    }

    return nomCarte;
}


Symbole Carte::obtenirSymbole() const
{
    return m_symboleIndex;
}


int Carte::ObtenirValeur() const
{
    return m_valeur;
}

std::string Carte::symboleToString(Symbole p_symbole) {
    switch (p_symbole) {
    case Coeur:
        return "Coeur";
    case Carreau:
        return "Carreau";
    case Trefle:
        return "Trefle";
    case Pique:
        return "Pique";
    default:
        return "Inconnu";
    }
}
bool Carte::operator>(const Carte& p_autreCarte) const {
    if (this->ObtenirValeur() == p_autreCarte.ObtenirValeur()) {
        return static_cast<int>(this->obtenirSymbole()) > static_cast<int>(p_autreCarte.obtenirSymbole());
    }
    return this->ObtenirValeur() > p_autreCarte.ObtenirValeur();
}

    int Carte::comparerCartes(const Carte& p_carte1, const Carte& p_carte2) {
    if (p_carte1 > p_carte2) {
        return 1;
    }
    else if (p_carte2 > p_carte1) {
        return -1;
    }
    return 0;
}
