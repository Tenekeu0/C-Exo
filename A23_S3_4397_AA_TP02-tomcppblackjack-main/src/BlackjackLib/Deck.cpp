
#include "Deck.h"
#include <algorithm> 
#include <random>
#include "ListeChaineeCartes.h"


Deck::Deck(){
}


Deck::~Deck(){
}


void Deck::MelangerCartes()
{
    auto debut = m_Deck.obtenirTete();

    auto fin = m_Deck.obtenirQueue();

    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(debut, fin, gen);
}



Carte Deck::DistribuerCarte()
{
    if (!m_Deck.estVide()) {
        Carte carteDistribuee;
        m_Deck.supprimerAIndice(0);
        return carteDistribuee;
    }
    else {
        throw std::out_of_range("Le tas de carte est vide");
    }
}


//void Deck::AjouterCarte(const ListeChaineeCartes<Carte>& p_carteAAjouter)
//{
//    m_Deck.AjouterDebut(p_carteAAjouter);
//}

