#include "ListeString.h"
#include <iostream>

void ListeString::ajouterFin(const std::string& p_valeur) {
	if (m_nbElement >= m_capacite) {
		int nouvelleCapacite = m_capacite * 2;
		std::string* nouveauTableau = new std::string[nouvelleCapacite];
		for (int i = 0; i < m_nbElement; i++) {
			nouveauTableau[i] = m_valeurs[i];
		}
		delete[] m_valeurs;
		m_valeurs = nouveauTableau;
		m_capacite = nouvelleCapacite;
	}

	m_valeurs[m_nbElement] = p_valeur;
	m_nbElement++;
}

void ListeString::supprimerFin() {
	if (m_nbElement > 0) {
		m_nbElement--;
	}
	else {
		std::cout << "l'historique est vide" << std::endl;
	}
}

std::string ListeString::obtenir(const int& p_indice) const {
	if (p_indice >= 0 && p_indice < m_nbElement) {
		return m_valeurs[p_indice];
	}
	else {
		throw std::out_of_range("Index en dehors");
	}
}

int ListeString::nombreElements()const {
	return this->m_nbElement;
}

int ListeString::capacite()const {

	return this->m_capacite;
}

bool ListeString::vide() {
	return m_nbElement == 0;
}

std::string* ListeString::historique() {
	return m_valeurs;
}


ListeString::ListeString(int p_capacite) :
	m_valeurs(new std::string[p_capacite]),
	m_nbElement(0),
	m_capacite(p_capacite) {
	;
}

std::string& ListeString::operator[](int p_indice) {
	if (p_indice < 0 || p_indice >= this->m_nbElement) {
		throw std::invalid_argument("L'Indice est hors limite!\n");
	}

	return this->m_valeurs[p_indice];
}

ListeString::~ListeString() {
	delete[] m_valeurs;
	m_valeurs = nullptr;
}