#include "Liste.h"
#include <iostream>

Liste::Liste(const Liste& p_listeACopier):
	m_nombreElements(p_listeACopier.m_nombreElements)
{
	for (int i = 0; i < this->m_nombreElements; ++i) {
		m_elements[i] = p_listeACopier.m_elements[i];
	}
	std::cout << "Ctor Copie Liste" << std::endl;
}

Liste::Liste(Liste&& p_rvalue):
	m_nombreElements(p_rvalue.m_nombreElements)
{
	for (int i = 0; i < this->m_nombreElements; ++i) {
		m_elements[i] = p_rvalue.m_elements[i];
	}
	std::cout << "Ctor affectation Liste" << std::endl;
}

Liste& Liste::operator=(const Liste& p_operateurCopiee)
{
	std::cout << "operateur Copie Liste" << std::endl;
	if (this != &p_operateurCopiee) {
		this->m_nombreElements = p_operateurCopiee.m_nombreElements;
		for (int i = 0; i < this->m_nombreElements; ++i) {
			this->m_elements[i] = p_operateurCopiee.m_elements[i];
		}
	}

	return *this;
}

Liste& Liste::operator=(Liste&& p_rvalue)
{
	std::cout << "operateur affectation Liste" << std::endl;
	if (this != &p_rvalue) {
		this->m_nombreElements = p_rvalue.m_nombreElements;
		for (int i = 0; i < this->m_nombreElements; ++i) {
			this->m_elements[i] = p_rvalue.m_elements[i];
		}
	}
	
	return *this;
}

Liste::Liste():m_nombreElements(20)
{
	std::cout << "Ctor defaut Liste" << std::endl;
}
Liste::~Liste() {
	std::cout << "destructeur Liste" << std::endl;
}

Liste::Liste(const int& p_nombreElements, int p_elements[])
	:m_nombreElements((p_nombreElements <= 20) ? p_nombreElements : 20)
{
	std::cout << "Ctor initialisation Liste" << std::endl;
	for (int i = 0; i < m_nombreElements; ++i) {
		m_elements[i] = p_elements[i];
	}
}

void Liste::ajouter(const int& p_elements)
{
	if (this->m_nombreElements >= 20) {
		throw std::invalid_argument("L'index invalid");
	}
	this->m_elements[this->m_nombreElements] = p_elements;
	++this->m_nombreElements;
}

void Liste::supprimer(const int& p_index)
{
	if (p_index < 0 || p_index >= m_nombreElements) {
		throw std::invalid_argument("L'index invalid");
	}
	for (int i = p_index; i < this->m_nombreElements -1; ++i) {
		m_elements[i] = m_elements[i + 1];
	}

	--this->m_nombreElements;
}

int Liste::obtenir(const int& p_index) const
{
	if (p_index < 0 || p_index >= m_nombreElements) {
		throw std::invalid_argument("L'index invalid");
	}

	return m_elements[p_index];
}

void Liste::definir(const int& p_index, const int& p_element)
{
	if (p_index < 0 || p_index >= m_nombreElements) {
		throw std::invalid_argument("L'index invalid");
	}
	this->m_elements[p_index] = p_element;
}

void Liste::afficherListe()
{
	for (int i = 0; i < m_nombreElements; ++i) {
		std::cout << m_elements[i] << std::endl;
	}
}

