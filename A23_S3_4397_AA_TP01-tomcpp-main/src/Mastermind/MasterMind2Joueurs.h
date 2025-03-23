#pragma once
#include "Jeu.h"
#include <string>
class MasterMind2Joueurs :public Jeu
{
	public:
		MasterMind2Joueurs(int p_nbrPiont, int p_nbrCoups, int p_nbrJoueur, std::string p_couleur)
			: Jeu(p_nbrPiont, p_nbrCoups, p_nbrJoueur, p_couleur) {
		}
		MasterMind2Joueurs();
		virtual int nombrePionBienPlace(const std::string& p_propos);
		virtual int nombrePionMalPlace(const std::string& p_propos);
		virtual void initierScore(int* p_Score);
		virtual int calculerScore(const int& p_pionBienPlace, const int& p_indexCoup);
		virtual bool siVictoire(const int& p_pointBPlace);
		virtual void propositionModi(std::string p_propositionDonnee);
		virtual std::string GenererProposition();
		virtual void afficherScoreFinal(int* p_score);
		virtual void afficherTextEnCouleur(const std::string& p_CouleurRVBProposee, const std::string& p_couleurRelle);
		virtual std::string convertirEnCouleurRelle(const std::string& p_CouleurRelle);
};
