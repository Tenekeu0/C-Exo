#pragma once
#include <ostream>
class ListeString
{
	public:
		ListeString(int p_capacite = 1);
		//ListeString(int p_capacite, int m_nbElement);
		~ListeString();

		virtual void ajouterFin(const std::string& p_valeur);
		virtual void supprimerFin();
		virtual std::string obtenir(const int& p_indice) const;
		virtual int nombreElements() const;
		virtual int capacite() const;
		virtual std::string* historique();
		virtual bool vide();
		std::string& operator[](int p_indice);

	private:
		std::string* m_valeurs;
		int m_capacite;
		int m_nbElement;
};

