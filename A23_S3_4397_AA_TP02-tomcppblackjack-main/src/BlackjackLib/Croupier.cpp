#include "Croupier.h"

Croupier::Croupier() = default;

Croupier::~Croupier() = default;

void Croupier::ajouterCarte(const Carte& p_carte) {
    m_main.AjouterDebut(p_carte);
}

void Croupier::distribuerCarte(Joueur& p_joueur) {
    //Carte nouvelleCarte = m_deck->DistribuerCarte();
    //this->hit(nouvelleCarte
}

int Croupier::calculerScore() const {
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

bool Croupier::verifierSiBlackjack() {
    return (m_main.nombreElements() == 2 && calculerScore() == 21);
}

bool Croupier::estBuste() const {
    return calculerScore() > 21;
}

void Croupier::viderMain() {
    Joueur joueur;
    joueur.viderMain();
}

ListeChaineeCartes<Carte>& Croupier::obtenirMain() {
    return this->m_main;
}