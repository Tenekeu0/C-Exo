#include "MasterMind2Joueurs.h"
#include <iostream>

std::string MasterMind2Joueurs::GenererProposition() {
	std::string generePropo;
https://cplusplus.com/reference/cstdlib/rand/
	/* initialize random seed: */
	srand(time(0));

	for (int i = 0; i < getPiont();i++) {
		generePropo += getcouleur()[rand() % getcouleur().length()];
	}

	return generePropo;
}

int MasterMind2Joueurs::nombrePionBienPlace(const std::string& p_propos) {
	if (p_propos.empty()) {
		throw std::invalid_argument("Impossible d'etre vide");
	}

	int bienPlace = 0;
	for (int i = 0; i < getPiont();i++) {
		if (tolower(getPropositionADeviner()[i]) == tolower(p_propos[i])) {
			bienPlace++;
		}
	}
	return bienPlace;
}

int MasterMind2Joueurs::nombrePionMalPlace(const std::string& p_propos) {
	int malPlace = 0;
	if (p_propos.empty()) {
		throw std::invalid_argument("Impossible d'etre vide");
	}
	for (int i = 0; i < getPiont();++i) {
		if (tolower(getProposi()[i]) != tolower(p_propos[i])) {
			malPlace++;
		}
	}
	return malPlace;
}

void MasterMind2Joueurs::initierScore(int* p_Score) {
	for (int i = 0; i < getJoueur();i++) {
		p_Score[i] = 0;
	}
}

void MasterMind2Joueurs::afficherScoreFinal(int* p_score) {
	for (int i = 0; i < getJoueur(); ++i) {
		std::cout << "Score final du joueur " << i + 1 << " : " << p_score[i] << std::endl;
	}
}

int MasterMind2Joueurs::calculerScore(const int& p_pionBienPlace, const int& p_indexCoup) {
	int score = (int)(pow(10, p_pionBienPlace) / pow(1.1618, ((p_indexCoup + 1) - 1)));

	return score;
}

bool MasterMind2Joueurs::siVictoire(const int& p_pointBPlace) {
	return p_pointBPlace == this->getPiont();
}

void MasterMind2Joueurs::propositionModi(std::string p_propositionDonnee) {
	if (p_propositionDonnee.empty()) {
		throw std::invalid_argument("la proposition ne peut etre vide");
	}
	this->getProposi() = p_propositionDonnee;
}