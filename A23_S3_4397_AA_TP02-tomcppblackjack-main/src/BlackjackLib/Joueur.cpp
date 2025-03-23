#include "Joueur.h"
#include <iostream>


Joueur::Joueur()
    : m_soldeInitiale(100), m_mise(0){}


Joueur::~Joueur(){}

void Joueur::renitialiserMise() {
    m_mise = 0;
}
void Joueur::hit(const Carte& p_nouvelleCarte)
{
    if (m_main.nombreElements() < m_nombreCartes)
        m_main.AjouterDebut(p_nouvelleCarte);
}


bool Joueur::estBuste()
{
    return calculerScore() > 21;
}

int Joueur::calculerScore()
{
    int scoreActuel = 0;
    int nombreAs = 0;

    // on va calculer le score en tenant compte des As
    for (int i = 0; i < m_main.nombreElements(); ++i) {
        int valeurCarte = m_main.obtenirIndice(i).ObtenirValeur();

        if (valeurCarte == 1) {
            // Cas d'un As
            nombreAs++;
            scoreActuel += 11; // je compte d'abord l'As comme 11
        }
        else if (valeurCarte >= 10) {
            //(valet, dame, roi)
            scoreActuel += 10;
        }
        else {
            scoreActuel += valeurCarte;
        }
    }

    // j'ajuste le score en tenant compte des As
    while (scoreActuel > 21 && nombreAs > 0) {
        scoreActuel -= 10;
        nombreAs--;
    }

    return scoreActuel;
}


bool Joueur::verifierSiBlackjack()
{
    return (m_main.nombreElements() == 2 && calculerScore() == 21);
}


void Joueur::perdrePartie()
{
    m_soldeInitiale -= m_mise;
}

void Joueur::perdreMise()
{
    m_mise = 0;
}


void Joueur::gagnerPartie()
{
    m_soldeInitiale += m_mise * 2; // Gain équivalent à la mise doublée
}


bool Joueur::estPartieNulle()
{
    return (m_nombreCartes == 2 && calculerScore() == 21);
}


void Joueur::miseInitialeMise()
{
    // La mise initiale est automatiquement de 10
    m_mise += 10;
    m_soldeInitiale -= 10;
    
}


void Joueur::gagnerMise()
{
    m_soldeInitiale += m_mise * 2; // Gain équivalent à la mise
}


void Joueur::gagnerAvecBlackjack()
{
    m_soldeInitiale += m_mise * 4; // Gain équivalent à la mise quatriple pour un blackjack
}


int Joueur::obtenirSolde() const
{
    return m_soldeInitiale;
}


bool Joueur::verifierSonSolde() const
{
    return (m_soldeInitiale >= 10);
}


void Joueur::viderMain()
{
    m_main.vider(); // Vider la main du joueur
    m_nombreCartes = 0;
}


ListeChaineeCartes<Carte>& Joueur::obtenirMain()
{
    return m_main;
}

//template class Joueur<Carte>;
