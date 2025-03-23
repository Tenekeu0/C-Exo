#pragma once

template<typename T>
class Noeud
{
	public:
		Noeud(const T& p_valeur);

	private:
		T m_valeur;
		Noeud* m_suivant; 
};