#include "PaquetCartes.h"
#include <string.h>
#include <sstream>

PaquetCartes::PaquetCartes()
{
    for (int i = Coeur; i <= Pique; ++i) {
        for (int j = 1; j <= 13; ++j) {

            Carte carte(j, static_cast<Symbole>(i));
            m_paquet.AjouterDebut(carte);
        }
    }
}

PaquetCartes::~PaquetCartes() = default;

void PaquetCartes::melangerPaquet()
{
    m_paquet.trie();
}

Carte PaquetCartes::DistribuerCarte()
{
    Carte carteDuDessus = m_paquet.obtenirIndice(0);
    m_paquet.supprimerDebut();
    return carteDuDessus;
}

int PaquetCartes::nombreCartesRestantes()
{
    return m_paquet.nombreElements();
}

bool PaquetCartes::paquetVide()
{
    return m_paquet.nombreElements() == 0;
}

void PaquetCartes::AjouterDefausse(const ListeChaineeCartes<Carte>& p_chaine)
{
    int nombreElements = p_chaine.nombreElements();

    for (int i = 0; i < nombreElements; ++i) {
        Carte carte = p_chaine.obtenirIndice(i);
        m_paquet.AjouterFin(carte);
    }
}
