#pragma once
#include "Jeu.h"
#include "MasterMind2Joueurs.h"
#include "ListeString.h"
class affichage
{
public:
	virtual void afficherScoreEtape(const int p_score);
	virtual void afficherMenuJeu();
	virtual void afficherMenuJeu2Joueurs();
	virtual void afficherMenuJeu1Joueur();
	virtual void affichageJeu();
	virtual void afficherPionBienEtMalPlace(const int& p_pionsBienPlace);
};

