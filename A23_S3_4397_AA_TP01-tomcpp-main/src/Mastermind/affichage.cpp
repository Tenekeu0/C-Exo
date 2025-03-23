#include "affichage.h"
#include "Jeu.h"
#include "MasterMind2Joueurs.h"
#include <iostream>

void affichage::afficherScoreEtape(const int p_score) {
    std::cout << "Score de l'etape : " << p_score << std::endl;
}
int nombreJoueurs;

bool validerChaine(const std::string& p_chaineRecu, const std::string& p_couleursPossible, const int& p_nbPions) {
    if (p_chaineRecu.empty() || p_couleursPossible.empty() || p_nbPions < 0) {
        throw std::invalid_argument("Parametres invalides.");
    }

    int nbBonChar = 0;

    for (char c : p_chaineRecu) {
        if (p_couleursPossible.find(c) != std::string::npos) {
            nbBonChar++;
        }
    }

    return nbBonChar == p_nbPions;
}

bool verifierFinDePartie(int p_indexCoup, int p_nbCoup, bool p_codeTrouve) {
    if (p_indexCoup < 0 || p_nbCoup < 0) {
        throw std::invalid_argument("L'index du coup ou le nombre de coups ne peut pas être inferieur à 0.");
    }

    return (p_indexCoup + 1) == p_nbCoup || p_codeTrouve;
}

template<typename T>
T saisirAvecMessage(const std::string& message) {
    T valeur;
    while (true) {
        std::cout << message;
        if (std::cin >> valeur) {
            break;
        }
        else {
            std::cout << "Entree invalide. Veuillez entrer une valeur valide." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return valeur;
}

int saisirNombreJoueur() {
    return saisirAvecMessage<int>("Entrez le nombre de joueurs (1 ou 2) : ");
}

int saisirChoix() {
    return saisirAvecMessage<int>("Entrez un choix : ");
}

std::string saisirSecret() {
    return saisirAvecMessage<std::string>("Entrez la proposition a deviner : ");
}

std::string saisirProposition(int p_indexCoup, int p_nbPions) {
    std::string msgProposition = "Proposition " + std::to_string(p_indexCoup + 1) + " : ";
    std::string proposition = saisirAvecMessage<std::string>(msgProposition);

    while (proposition.length() > p_nbPions || proposition.length() < p_nbPions) {
        proposition = saisirAvecMessage<std::string>(msgProposition);
    }

    return proposition;
}

std::string saisirCouleur() {
    return saisirAvecMessage<std::string>("Entrez les couleurs du jeu : ");
}

int saisieNombrePion() {
    return saisirAvecMessage<int>("Entrez un nombre de pions (entier positif) : ");
}

int saisirNombreCoups() {
    return saisirAvecMessage<int>("Entrez un nombre de coups maximum (entier positif) : ");
}

void affichage::afficherMenuJeu2Joueurs() {
    std::cout << "Faites un choix : " << std::endl;
    std::cout << "Entrez 1 pour continuer" << std::endl;
    std::cout << "Entrez 2 pour Terminer" << std::endl;
}

void affichage::afficherMenuJeu1Joueur() {
    std::cout << "Faites un choix : " << std::endl;
    std::cout << "Entrez 1 pour Historique" << std::endl;
    std::cout << "Entrez 2 pour Revenir en arriere" << std::endl;
    std::cout << "Entrez 3 pour Continuer" << std::endl;
    std::cout << "Entrez 4 pour Terminer" << std::endl;
}

void affichage::afficherPionBienEtMalPlace(const int& p_pionsBienPlace) {
    //std::cout << "Bien placé(s) : " << std::to_string(p_pionsBienPlace) << " - Mal placé(s) : "
       // << std::to_string(jeu->getPiont() - p_pionsBienPlace) << std::endl;
}

void affichage::affichageJeu() {
    //Source: Déroulement inspiré d'un travail précedemment fait
    // Initialisation des jeux
    int nombrePions = saisieNombrePion();
    int nombreCoups = saisirNombreCoups();
    int nombreJoueurs = saisirNombreJoueur();
    std::string couleurs = saisirCouleur();

    MasterMind2Joueurs jeu(nombrePions, nombreCoups, nombreJoueurs, couleurs);
    ListeString liste;
    int scoreJoueur[2] = { 0, 0 };

    // Boucle principale du jeu
    while (!jeu.getEtatPartie()) {

        if (jeu.getJoueur() == 1) {
            jeu.propositionModif(jeu.GenererProposition());
        }
        else {

            std::string combinaisonSecrete;
            bool couleurValide = false;

            while (!couleurValide) {
                combinaisonSecrete = saisirSecret();
                couleurValide = validerChaine(combinaisonSecrete, jeu.getcouleur(), jeu.getPiont());

                if (!couleurValide) {
                    std::cout << "Saisie invalide : la combinaison secrète doit contenir exactement "
                        << jeu.getPiont() << " caracteres valides parmi ";
                    std::cout << jeu.convertirEnCouleurRelle(jeu.getcouleur()) << std::endl;
                }
            }

            jeu.propositionModif(combinaisonSecrete);
        }

        int indexCoup = 0;
        bool combTrouve = false;

        // Boucle de proposition et de vérification
        while (!combTrouve && indexCoup < jeu.getCoups() && !jeu.getEtatPartie()) { 
            // Saisir la proposition de l'utilisateur
            std::string proposition = saisirProposition(indexCoup, jeu.getPiont());
            liste.ajouterFin(proposition);

            int pionBienPlace = jeu.nombrePionBienPlace(proposition);
            int pionMalPlace = jeu.nombrePionMalPlace(proposition);

            std::cout << "Bien place(s) : " << pionBienPlace << " - Mal place(s) : " << pionMalPlace << std::endl;

            int score = jeu.calculerScore(pionBienPlace,indexCoup);
            scoreJoueur[jeu.getJoueur() - 1] += score;

            combTrouve = jeu.siVictoire(pionBienPlace);

            if (combTrouve) {
                std::cout << "Felicitations, vous avez gagne !" << std::endl;
            }

            if (verifierFinDePartie(indexCoup, jeu.getCoups(), combTrouve)) {
                std::cout << "Partie Terminee !" << std::endl;
            }

            // Afficher le menu du jeu et obtenir le choix de l'utilisateur
            if (jeu.getJoueur() == 2) {
                afficherMenuJeu2Joueurs();
            }
            else {
                afficherMenuJeu1Joueur();
            }
            int choixMenu = saisirChoix();

            // Traiter le choix de l'utilisateur
            if (jeu.getJoueur() == 2) {
                switch (choixMenu) {
                case 1:
                    indexCoup++;
                    break;
                case 2:
                    jeu.setEtatPartie(true);
                    break;
                default:
                    break;
                }
            }
            else {
                // Traiter du cas d'un joeur
                if (jeu.getJoueur() == 1) {
                    bool retourArrierePremierTour = false;
                    while (choixMenu == 1 || choixMenu == 2) {
                        switch (choixMenu) {
                        case 1:
                            std::cout << "Votre historique de coups : " << std::endl;
                            for (int i = 0; i < liste.nombreElements();++i) {
                                std::cout << "votre proposition " << i + 1 << " ";
                                std::cout << jeu.convertirEnCouleurRelle(liste.historique()[i]) << std::endl;
                            }
                        break;
                        case 2:
                            if (liste.vide()) {
                                std::cout << "Vous etes deja au debut de la partie" << std::endl;
                            }
                            else {
                                scoreJoueur[(jeu.getJoueur() + 1) % jeu.getJoueur()] -= jeu.calculerScore(indexCoup + 1, pionBienPlace);
                                liste.supprimerFin();

                                if (indexCoup != 0) {
                                    indexCoup--;
                                }
                                else {
                                    retourArrierePremierTour = true;
                                }
                            }
                            break;
                        }
                        if (jeu.getJoueur() == 2) {
                            afficherMenuJeu2Joueurs();
                        }
                        else {
                            afficherMenuJeu1Joueur();
                        }
                        choixMenu = saisirChoix();
                    }

                    if (choixMenu == 3) {
                        if (!retourArrierePremierTour) {
                            indexCoup++;
                        }
                    }
                    else {
                        jeu.setEtatPartie(true);
                    }
                }
            }
        }
    }

    jeu.afficherScoreFinal(scoreJoueur);
}
