#pragma once

#include <iostream>
#include"PaquetCartes.h"
#include"Joueur.h"
#include"Croupier.h"
#include"Affichage.h"

class JeuBlackJack
{
	public:
		JeuBlackJack();
		~JeuBlackJack();
		void commencerPartie();

		void menu();
		bool debuterTour();
		void melangerCartes();
		void distribuerCartes();
		void tourJoueur();
		void tourCroupier();
		void gagner();
		void repriseCartesParticipants();
	private:
		PaquetCartes m_jeuDeCartes;
		ListeChaineeCartes<Carte> m_defausse;
		Croupier m_croupier;
		Joueur m_joueur;

		Affichage m_affichage;

		bool demanderStand();
		int etatJeu();
};

