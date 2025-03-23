#include "JeuBlackJack.h"
#include <thread>
#include <iostream>
#include <string>

JeuBlackJack::JeuBlackJack()
{
}

JeuBlackJack::~JeuBlackJack() = default;

void JeuBlackJack::commencerPartie()
{
    if (debuterTour()) {
        std::cout << "Mise: 10$ " << std::endl;
        std::cout << "Solde: " + std::to_string(m_joueur.obtenirSolde()) + "$" << std::endl;
    }
    else {
        std::cout << "End votre solde est insuffisant " << std::endl;
        return;
    }

    distribuerCartes();

    std::cout << "Partages des cartes \n " << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Cartes reçues par le croupier" << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Cartes distrinuées par le croupier" << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Cartes reçues par le croupier" << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Cartes distrinuées par le croupier" << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Etat croupier" << std::endl;
    std::cout << "main: " << std::endl;
    for (int i = 0; i < m_defausse.nombreElements(); ++i) {
        std::string symbole = Carte::symboleToString(m_defausse.obtenirIndice(i).obtenirSymbole());
        std::cout << m_defausse.obtenirIndice(i).ObtenirValeur() << " de " << symbole << std::endl;
    }
    std::cout << m_croupier.calculerScore() << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Etat Jeu Joueur" << std::endl;
    std::cout << "main: " << std::endl;
    for (int i = 0; i < m_defausse.nombreElements(); ++i) {
        std::string symbole = Carte::symboleToString(m_defausse.obtenirIndice(i).obtenirSymbole());
        std::cout << m_defausse.obtenirIndice(i).ObtenirValeur() << " de " << symbole << std::endl;
    }
    std::cout << m_joueur.calculerScore() << std::endl;

    if (!m_joueur.verifierSiBlackjack()) {
        tourJoueur();
        if (!m_joueur.estBuste()) {
            tourCroupier();
        }
    }
    gagner();
    for (int i = 0; i < m_joueur.obtenirMain().nombreElements(); ++i) {
        m_defausse.AjouterDebut(m_joueur.obtenirMain().obtenirIndice(i));
    }

    for (int i = 0; i < m_croupier.obtenirMain().nombreElements(); ++i) {
        m_defausse.AjouterDebut(m_croupier.obtenirMain().obtenirIndice(i));
    }

    m_joueur.obtenirMain().vider();
    m_croupier.obtenirMain().vider();
}

void JeuBlackJack::menu()
{
    char choix;
    do {
        std::cout << "Voulez-vous rejouer ? o pour Oui et n pour Non: " << std::endl;
        std::cin >> choix;

        if (choix == 'o' || choix == 'O') {
            commencerPartie();
        }
        else if (choix == 'n' || choix == 'N') {
            std::cout << "Merci d'avoir joué " << std::endl;
            break;
        }
        else {
            std::cout << "Mauvais choix essayez de nouveau " << std::endl;
        }

    } while (true);
	
}

bool JeuBlackJack::debuterTour()
{
    bool reussi = true;

    if (m_jeuDeCartes.nombreCartesRestantes() == 52) {
        m_jeuDeCartes.melangerPaquet();
    }

    if (m_joueur.verifierSonSolde()) {
        m_joueur.miseInitialeMise();
    }
    else {
        reussi = false;
    }

    return reussi;
}

void JeuBlackJack::melangerCartes()
{
}

void JeuBlackJack::distribuerCartes()
{
    for (int i = 0; i < 2; ++i) {
        if (m_jeuDeCartes.nombreCartesRestantes() == 0) {
            m_jeuDeCartes.AjouterDefausse(m_defausse);
            m_defausse.vider();
            m_jeuDeCartes.melangerPaquet();
        }
        m_joueur.hit(m_jeuDeCartes.DistribuerCarte());
    }

    m_joueur.obtenirMain().trier(Carte::comparerCartes);
    if (m_jeuDeCartes.nombreCartesRestantes() == 0) {
        m_jeuDeCartes.AjouterDefausse(m_defausse);
        m_defausse.vider();
        m_jeuDeCartes.melangerPaquet();
    }
    m_croupier.hit(m_jeuDeCartes.DistribuerCarte());
}

void JeuBlackJack::tourJoueur()
{
    bool jStand = false;
    bool jBuste = false;

    while (!jStand && !jBuste) {

        jStand = demanderStand();

        // Si le joueur ne veut pas "stand", il reçoit une nouvelle carte
        if (!jStand) {
            std::cout << "Nouvelle carte" << std::endl;

            std::this_thread::sleep_for(std::chrono::seconds(1));

            if (m_jeuDeCartes.nombreCartesRestantes() == 0) {
                m_jeuDeCartes.AjouterDefausse(m_defausse);
                m_defausse.vider();
                m_jeuDeCartes.melangerPaquet();
            }
            Carte carteJoueur = m_jeuDeCartes.DistribuerCarte();
            m_joueur.hit(carteJoueur);
            m_joueur.obtenirMain().trier(Carte::comparerCartes);
        }

        std::this_thread::sleep_for(std::chrono::seconds(1));

        std::cout << "Etat Jeu Joueur" << std::endl;
        m_affichage.afficherEtatJeuJoueur(m_joueur);

        if (m_joueur.calculerScore() >= 21) {
            jBuste = true;
            jStand = true;
        }
    }
}

void JeuBlackJack::tourCroupier()
{
    if (m_jeuDeCartes.nombreCartesRestantes() == 0) {
        m_jeuDeCartes.AjouterDefausse(m_defausse);
        m_defausse.vider();
        m_jeuDeCartes.melangerPaquet();
    }
    m_croupier.ajouterCarte(m_jeuDeCartes.DistribuerCarte());
    m_croupier.obtenirMain().trier(Carte::comparerCartes);

    std::cout << "Etat Croupier" << std::endl;

    m_affichage.afficherEtatJeuCroupier(m_croupier);

    while (m_croupier.calculerScore() < 17) {
        std::cout << "Le Croupier a une nouvelle carte" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));

        if (m_jeuDeCartes.nombreCartesRestantes() == 0) {
            m_jeuDeCartes.AjouterDefausse(m_defausse);
            m_defausse.vider();
            m_jeuDeCartes.melangerPaquet();
        }
        Carte carteCroupier = m_jeuDeCartes.DistribuerCarte();
        m_croupier.ajouterCarte(carteCroupier);
        m_croupier.obtenirMain().trier(Carte::comparerCartes);
        std::cout << "Etat Croupier" << std::endl;
        m_affichage.afficherEtatJeuCroupier(m_croupier);
    }
}

void JeuBlackJack::gagner()
{
    int resultat = etatJeu();

    switch (resultat) {
    case 0:
        std::cout << "Vous avez depasse 21. Le croupier a gagne !" << std::endl;
        m_joueur.perdrePartie();
        break;

    case 1:
        std::cout << "Le croupier a depasse 21. Vous avez gagne !" << std::endl;
        m_joueur.gagnerMise();
        break;

    case 2:
        std::cout << "Vous avez gagne !" << std::endl;
        m_joueur.gagnerMise();
        break;

    case 3:
        std::cout << "Le croupier a gagne !" << std::endl;
        m_joueur.perdrePartie();
        break;

    case 4:
        std::cout << "Egalite !" << std::endl;
       m_joueur.estPartieNulle(); // Récupérer la mise
        break;

    case 5:
        std::cout << "Vous avez un blackjack !" << std::endl;
        m_joueur.gagnerAvecBlackjack();
        break;

    case 6:
        std::cout << "Le croupier a un blackjack !" << std::endl;
        m_joueur.perdrePartie();
        break;

    case 7:
        std::cout << "Egalite! Vous avez tous les deux un blackjack." << std::endl;
        m_joueur.estPartieNulle(); // Récupérer la mise
        break;
    }

    std::cout << "Votre solde est de" + std::to_string(m_joueur.obtenirSolde()) + "$" << std::endl;
}

bool JeuBlackJack::demanderStand()
{
    std::string reponse;
    bool stand = false;

    std::cout << "Voulez-vous tirer une carte? (o/n) : ";
    std::cin >> reponse;

    if (reponse == "o" || reponse == "O") {
        stand = false;
    }
    else if (reponse == "n" || reponse == "N") {
        stand = true;
    }
    else {
        std::cout << "Veuillez entrer une reponse valide." << std::endl;
        return demanderStand();
    }

    return stand;
}

int JeuBlackJack::etatJeu()
{
    int resultat;
    int scoreJoueur = m_joueur.calculerScore();
    int scoreCroupier = m_croupier.calculerScore();

    if (m_joueur.verifierSiBlackjack() && m_croupier.verifierSiBlackjack()) {
        resultat = 7;
    }
    else if (m_joueur.verifierSiBlackjack()) {
        resultat = 5;
    }
    else if (m_croupier.verifierSiBlackjack()) {
        resultat = 6;
    }
    else if (m_joueur.estBuste()) {
        resultat = 0;
    }
    else if (m_croupier.estBuste()) {
        resultat = 1;
    }
    else if (scoreJoueur > scoreCroupier) {
        resultat = 2;
    }
    else if (scoreCroupier > scoreJoueur) {
        resultat = 3;
    }
    else {
        resultat = 4;
    }

    return resultat;
}
void JeuBlackJack::repriseCartesParticipants() {
    for (int i = 0; i < m_joueur.obtenirMain().nombreElements(); ++i) {
        m_defausse.AjouterDebut(m_joueur.obtenirMain().obtenirIndice(i));
    }

    for (int i = 0; i < m_croupier.obtenirMain().nombreElements(); ++i) {
        m_defausse.AjouterDebut(m_croupier.obtenirMain().obtenirIndice(i));
    }

    m_joueur.obtenirMain().vider();
    m_croupier.obtenirMain().vider();
}