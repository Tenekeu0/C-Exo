#pragma once
#include <string>

class Personne
{
	private:
		std::string m_nom;
		std::string m_prenom;
		int m_age;
		float m_taille;
	public:
		Personne();
		Personne(std::string p_nom,std::string p_prenom, const int& p_age, const float& p_taille);
		Personne(const Personne& p_objetACopier);
		Personne(Personne&& p_rvalue);
		~ Personne();
		Personne& operator=(const Personne& p_objetACopier);
		Personne& operator=(Personne&& p_rvalue);
		std::string getNom() const;
		std::string getPrenom() const;
		void setNom(std::string p_nom);
		void setPrenom(std::string p_prenom);
		float getTaille() const;
		void afficherPersonne();
		void feterAnniversaire();
		void grandir();
		Personne pourAppelCtorAffectation(Personne&& p_personne);
};

