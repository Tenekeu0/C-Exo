#include "Personne.h"
#include <iostream>

Personne::Personne()
{
}

Personne::Personne(std::string p_nom, std::string p_prenom, const int& p_age, const float& p_taille)
	: m_nom(p_nom),m_prenom(p_prenom),m_age(p_age),m_taille(p_taille)
{

	std::cout << "Ctor initialisation : "<< std::endl;
}

Personne::Personne(const Personne& p_objetACopier)
	: m_nom(p_objetACopier.m_nom),
	m_prenom(p_objetACopier.m_prenom),
	m_age(p_objetACopier.m_age),
	m_taille(p_objetACopier.m_taille)
{
	std::cout << "Ctor par copie : " << std::endl;
}

Personne::Personne(Personne&& p_rvalue)
: m_nom(p_rvalue.m_nom),
m_prenom(p_rvalue.m_prenom),
m_age(p_rvalue.m_age),
m_taille(p_rvalue.m_taille)
{
	std::cout << "Ctor par déplacement : " << std::endl;
}

Personne::~Personne()
{
	std::cout << "destructeur : " << std::endl;
}

Personne& Personne::operator=(const Personne& p_objetACopier)
{

	std::cout << "operateur par copie : " << std::endl;
	if (this != &p_objetACopier) {
		this->m_nom = p_objetACopier.m_nom;
		this->m_prenom = p_objetACopier.m_prenom;
		this->m_age = p_objetACopier.m_age;
		this->m_taille = p_objetACopier.m_taille;
	}
	return *this;
}

Personne& Personne::operator=(Personne&& p_rvalue)
{
	std::cout << "operateur d'affectation : " << std::endl;
	if (this != &p_rvalue) {
		this->m_nom = p_rvalue.m_nom;
		this->m_prenom = p_rvalue.m_prenom;
		this->m_age = p_rvalue.m_age;
		this->m_taille = p_rvalue.m_taille;
	}
	return *this;
}

std::string Personne::getNom() const
{
	return this->m_nom;
}

std::string Personne::getPrenom() const
{
	return this->m_prenom;
}

void Personne::setNom(std::string p_nom)
{
	if (p_nom == "") {
		throw std::invalid_argument(" ne peur être null");
	}
	this->m_nom = p_nom;
}

void Personne::setPrenom(std::string p_prenom)
{
	if (p_prenom == " ") {
		throw std::invalid_argument(" ne peur être null");
	}
	this->m_prenom = p_prenom;
}

float Personne::getTaille() const
{
	return this->m_taille;
}

void Personne::afficherPersonne()
{
	std::cout << "Nom: " << m_nom << " Prenom: " << m_prenom << " age: " << m_age << " taille " << m_taille << std::endl;
}

void Personne::feterAnniversaire()
{
	if (m_age < 0) {
		throw std::invalid_argument(" l'âge ne peut être négatif");
	}
	m_age++;
	std::cout << "l'age est de : " << m_age << std::endl;

}

void Personne::grandir()
{
	if (m_taille < 0) {
		throw std::invalid_argument(" la taille ne peut être négative");
	}
	m_taille++;
	std::cout << "la taille est de : " << m_taille << std::endl;

}

Personne Personne::pourAppelCtorAffectation(Personne&& p_personne) {

	return p_personne;

}
