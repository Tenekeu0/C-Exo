#include "MasterMind2Joueurs.h"
#include <iostream>

MasterMind2Joueurs::MasterMind2Joueurs() {

}
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
		if (toupper(getPropositionADeviner()[i]) == toupper(p_propos[i])) {
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
	for (int i = 0; i < getPiont();i++) {
		if (toupper(getProposi()[i]) != toupper(p_propos[i])) {
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
	this->getPropositionADeviner() = p_propositionDonnee;
}
// Source:
// https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797
//https://en.wikipedia.org/wiki/ANSI_escape_code
void MasterMind2Joueurs::afficherTextEnCouleur(const std::string& p_CouleurRVBProposee, const std::string& p_couleurRelle) {

	std::string couleur = "\033[0;" + p_couleurRelle + "m";
	std::string renitialiserCouleur = "\033[0m";

	std::cout << couleur << p_CouleurRVBProposee << renitialiserCouleur;
}
std::string MasterMind2Joueurs::convertirEnCouleurRelle(const std::string& p_CouleurRelle) {
	std::string result;
	for (char lettre : p_CouleurRelle) {
		switch (toupper(lettre)) {
		case 'R':
			afficherTextEnCouleur("R", "31");
			break;
		case 'V':
			afficherTextEnCouleur("V", "32");
			break;
		case 'B':
			afficherTextEnCouleur("B", "34");
			break;
		case 'O':
			afficherTextEnCouleur("O", "33");
			break;
		case 'Y':
			afficherTextEnCouleur("Y", "93");
			break;
		case 'M':
			afficherTextEnCouleur("M", "35");
			break;
		case 'C':
			afficherTextEnCouleur("C", "36");
			break;
		case 'P':
			afficherTextEnCouleur("P", "95");
			break;
		case 'G':
			afficherTextEnCouleur("G", "92");
			break;
		case 'W':
			afficherTextEnCouleur("W", "97");
			break;
		default:
			// s'il n'y a pas de couleur correspondante on garde la lettre ici
			result += lettre;
			break;
		}
	}
	return result;
}