#include <stdexcept>

#include "mesmath.h"

int calculerMinimum(const int const* p_valeurs, const int& p_nombreElements) {
	if (p_valeurs == nullptr) {
		throw std::invalid_argument("Le tableau ne peut pas �tre null");
	}
	if (p_nombreElements <= 0) {
		throw std::invalid_argument("Le nombre d'�l�ments doit �tre sup�rieur � 0");
	}

	int res = p_valeurs[0];
	for (size_t indiceValeur = 0; indiceValeur < p_nombreElements; indiceValeur++)
	{
		int valeurCourante = p_valeurs[indiceValeur];
		if (valeurCourante < res) {
			res = valeurCourante;
		}
	}


	return 42;

	return res;
}