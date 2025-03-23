#include "Jeu.h"
#include <stdexcept>


Jeu::Jeu(int p_nbPions, int p_nbCoups, int p_nbJoueur, std::string p_couleur) :
	m_nbrPiont(p_nbPions),
	m_nbrCoups(p_nbCoups),
	m_nbrJoueur(p_nbJoueur),
	m_couleur(p_couleur),
	m_histo(p_nbCoups)
{
	if (m_nbrPiont <= 0) {
		throw std::invalid_argument("Le nombre de pions ne peut etre égal ou inferieur à 0");
	}
	if (m_nbrJoueur <= 0 || m_nbrJoueur > 2) {
		throw std::invalid_argument("Le nombre de joueurs ne peut etre égal ou inferieur à 0 ou supérieur à 2");
	}
	if (m_nbrCoups <= 0) {
		throw std::invalid_argument("Le nombre de coups ne peut etre égal ou inferieur à 0");
	}
	if (m_couleur.empty()) {
		throw std::invalid_argument("La couleur ne peut etre vide");
	}
	this->m_etatPartie = false;
}

Jeu::Jeu() {
	;
}

std::string Jeu::getcouleur() {
	return this->m_couleur;
}

int Jeu::getCoups() {
	return this->m_nbrCoups;
}

int Jeu::getJoueur() {
	return this->m_nbrJoueur;
}

int Jeu::getPiont() {
	return this->m_nbrPiont;
}
ListeString Jeu::getHistorique() {
	return m_histo;
}

std::string Jeu::getProposi() {
	return m_propositionDonnee;
}

void Jeu::propositionModif(std::string p_propositionDonnee) {
	if (p_propositionDonnee.empty()) {
		throw std::invalid_argument("la proposition ne peut etre vide");
	}
	this->m_propositionDonnee = p_propositionDonnee;
}

void Jeu::setEtatPartie(bool p_etat) {
	this->m_etatPartie = p_etat;
}

std::string Jeu::getPropositionADeviner() {
	return m_propositionDonnee;
}

bool Jeu::getEtatPartie() {
	return m_etatPartie;
}

Jeu::~Jeu() {

}