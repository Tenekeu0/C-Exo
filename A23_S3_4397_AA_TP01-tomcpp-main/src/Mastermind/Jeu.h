#pragma once
#include <string>
#include"ListeString.h"
class Jeu
{
	public:
		Jeu();
		Jeu(int p_nbrPiont, int p_nbrCoups, int p_nbrJoueur, std::string p_couleur);
		~Jeu();
		virtual bool siVictoire(const int& p_pointBPlace) = 0;
		virtual int nombrePionBienPlace(const std::string& p_propos) = 0;
		virtual int nombrePionMalPlace(const std::string& p_propos) = 0;
		virtual int calculerScore(const int& p_pionBienPlace, const int& indexCoup) = 0;
		virtual void initierScore(int* p_Score) = 0;
		virtual void propositionModif(std::string p_propositionDonnee);
		virtual int getPiont();
		virtual int getCoups();
		virtual int getJoueur();
		virtual std::string getPropositionADeviner();
		virtual bool getEtatPartie();
		virtual ListeString getHistorique();
		virtual std::string getProposi();
		virtual std::string getcouleur();
		virtual void setEtatPartie(bool p_etat);
		virtual void afficherTextEnCouleur(const std::string& p_CouleurRVBProposee, const std::string& p_couleurRelle) = 0;
		virtual std::string convertirEnCouleurRelle(const std::string & p_CouleurRelle) = 0;
	private:
		int m_nbrPiont;
		int m_nbrCoups;
		int m_nbrJoueur;
		bool m_etatPartie;
		std::string m_couleur;
		std::string m_propositionDonnee;
		ListeString m_histo;
};

