#include "recherche.h"

int recherche::rechercheDansTab(int p_tab[], int p_capacite, int m_valeurAchercher)
{
	int valeurARetourner = 0;
	for (int i = 0; i < p_capacite; ++i) {
		valeurARetourner = p_tab[i] == m_valeurAchercher ? i : -1;
	}
	return valeurARetourner;
}
