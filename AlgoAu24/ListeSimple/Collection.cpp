#include <iostream>
#include "Collection.h"

Collection::Collection()
{
	std::cout << "Ctor defaut Collection" << std::endl;
}

Collection::Collection(const Collection& p_objetACopier) :
	m_nombreElements(p_objetACopier.m_nombreElements)
{
	for (int i = 0; i < this->m_nombreElements; ++i) {
		m_elements[i] = p_objetACopier.m_elements[i];
	}
	std::cout << "Ctor copier Collection" << std::endl;

}

Collection::Collection(Collection&& p_objetADeplacer):
	m_nombreElements(p_objetADeplacer.m_nombreElements)
{
	std::cout << "Ctor deplacement Collection" << std::endl;
	for (int i = 0; i < this->m_nombreElements; ++i) {
		m_elements[i] = p_objetADeplacer.m_elements[i];
	}
}

Collection::~Collection()
{
	std::cout << "destructeur Collection" << std::endl;
}
