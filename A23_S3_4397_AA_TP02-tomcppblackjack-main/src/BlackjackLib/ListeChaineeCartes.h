#pragma once
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include <random>
#include <iostream>

template<typename T>
class ListeChaineeCartes;

template<typename T>
class Noeud
{
    friend class ListeChaineeCartes<T>;
    public:
        Noeud(): m_valeur(T()), m_suivant(nullptr) {}
        explicit Noeud(const T& p_valeur) : m_valeur(p_valeur), m_suivant(nullptr) {}

        T getValeur() {
            return m_valeur;
        }
    private:
        T m_valeur;
        Noeud* m_suivant;
};

template<typename T>
class ListeChaineeCartes
{
    public:
        ListeChaineeCartes() : m_tete(nullptr), m_queue(nullptr), m_nombreElement(0) {

        }

        ListeChaineeCartes(const ListeChaineeCartes<T>& p_listeACopier)
            : m_tete(nullptr), m_queue(nullptr), m_nombreElement(0) {

            Noeud<T>* temp = p_listeACopier.m_tete;
            while (temp != nullptr) {
                this->AjouterFin(temp.m_valeur);
                temp = temp->m_suivant;
            }
        }
        ListeChaineeCartes(ListeChaineeCartes<T>&& p_listeADeplacer)
            noexcept {
            this->m_tete = p_listeADeplacer.m_tete;
            this->m_queue = p_listeADeplacer.m_tete;
            this->m_nombreElement = p_listeADeplacer.m_nombreElement;
        }
        ~ListeChaineeCartes() {
            vider();
        }

        void trier(int (*p_fonctionTri)(const T&, const T&)) {
            if (m_nombreElement < 2) return;

            bool enchangee;
            do {
                enchangee = false;
                Noeud<T>* temp = m_tete;
                Noeud<T>* precedent = nullptr;

                while (temp && temp->m_suivant) {
                    if (p_fonctionTri(temp->m_valeur, temp->m_suivant->m_valeur) > 0) {

                        T tempValeur = temp->m_valeur;
                        temp->m_valeur = temp->m_suivant->m_valeur;
                        temp->m_suivant->m_valeur = tempValeur;
                        enchangee = true;
                    }

                    precedent = temp;
                    temp = temp->m_suivant;
                }
            } while (enchangee);
        }
        void trie() {
            // static_cast pour éviter un avertissement potentiel
            std::srand(static_cast<unsigned int>(std::time(nullptr))); 

            if (m_nombreElement < 2) return;

            Noeud<T> **tableauNoeuds = new Noeud<T>*[m_nombreElement];
            Noeud<T> *temp = m_tete;
            int index = 0;

            while (temp != nullptr) {
                tableauNoeuds[index++] = temp;
                temp = temp->m_suivant;
            }

            // std::random_device pour obtenir une graine plus aléatoire
            std::random_device rd;
            std::mt19937 gen(rd());

            for (int i = m_nombreElement - 1; i > 0; i--) {
                std::uniform_int_distribution<int> dis(0, i);
                int j = dis(gen);

                if (tableauNoeuds[i] != nullptr && tableauNoeuds[j] != nullptr) {
                    T tempValeur = tableauNoeuds[i]->m_valeur;
                    tableauNoeuds[i]->m_valeur = tableauNoeuds[j]->m_valeur;
                    tableauNoeuds[j]->m_valeur = tempValeur;
                }
                else {
                    std::cout << "test: " << std::endl;
                }
            }

            delete[] tableauNoeuds;
        }
        
        void AjouterAIndice(Noeud<T>* p_nouveauNoeud, const int& p_indice) {
            Noeud<T>* temp = m_tete;
            int count = 0;
            while (temp && count < p_indice - 1) {
                temp = temp->m_suivant;
                count++;
            }

            if (!temp) {
                delete p_nouveauNoeud;
                throw std::out_of_range("Indice invalide");
            }

            p_nouveauNoeud->m_suivant = temp->m_suivant;
            temp->m_suivant = p_nouveauNoeud;

            if (!p_nouveauNoeud->m_suivant) {
                m_queue = p_nouveauNoeud;
            }
        }

        void supprimerDebut() {
            if (!m_tete) return;

            Noeud<T>* temp = m_tete;
            m_tete = m_tete->m_suivant;
            delete temp;

            if (!m_tete) {
                m_queue = nullptr;
            }

            m_nombreElement--;
        }

        void ValiderIndice(const int& p_indice) {
            if (p_indice < 0) {
                throw std::out_of_range("Indice invalide");
            }
        }
        void Inserer(const T& p_val, const int& p_indice) {
            ValiderIndice(p_indice);

            Noeud<T>* nouveauNoeud = new Noeud<T>(p_val);

            if (p_indice == 0) {
                InsererAuDebut(nouveauNoeud);
            }
            else {
                AjouterAIndice(nouveauNoeud, p_indice);
            }

            m_nombreElement++;
        }
        void supprimerFin() {
            if (!m_tete) return;

            if (m_tete == m_queue) {
                delete m_tete;
                m_tete = nullptr;
                m_queue = nullptr;
                return;
            }

            Noeud<T>* temp = m_tete;

            while (temp->m_suivant != m_queue) {
                temp->m_suivant = temp->m_suivant;
            }

            delete m_queue;
            m_queue = temp;
            m_queue->m_suivant = nullptr;

            m_nombreElement--;
        }


        void supprimerAIndice(const int& p_indice) {
            if (m_nombreElement == 1) {
                m_queue = m_tete;
                delete m_queue;
                m_queue = nullptr;
                m_tete--;
            }
            else if (m_nombreElement == 0) {
                m_queue = nullptr;
                m_tete = nullptr;
            }
            else if (p_indice == 0) {
                supprimerDebut();
            }
            else if (p_indice == m_nombreElement) {
                supprimerFin();
            }
            else {
                Noeud<T>* noeudPrecedent = m_tete;
                for (int i = 0; i < p_indice - 1; i++) {
                    noeudPrecedent = noeudPrecedent->m_suivant;
                }
                Noeud<T>* noeudASupprimer = noeudPrecedent->m_suivant;
                noeudPrecedent->m_suivant = noeudASupprimer->m_suivant;
                delete noeudASupprimer;
                m_nombreElement--;
            }
        }

        Noeud<T>* obtenirTete() const {
            return m_tete;
        }

        Noeud<T>* obtenirQueue() const {
            return m_queue;
        }

        T obtenirIndice(const int& p_indice) const {
            if (p_indice < 0 || p_indice >= m_nombreElement) {
                throw std::out_of_range("Indice hors limites");
            }
            Noeud<T>* noeudDeIndice = m_tete;
            for (int i = 0; i < p_indice; i++) {
                noeudDeIndice = noeudDeIndice->m_suivant;
            }
            return noeudDeIndice->m_valeur;
        }


        void AjouterDebut(const T p_val) {
            Inserer(p_val, 0);
        }

        void InsererAuDebut(Noeud<T>* p_nouveauNoeud) {
            p_nouveauNoeud->m_suivant = m_tete;
            m_tete = p_nouveauNoeud;

            if (!m_queue) {
                m_queue = m_tete;
            }
        }
        void AjouterFin(const T& p_carte) {

            Noeud<T>* nouveauNoeud = new Noeud<T>(p_carte);

            if (m_queue) {
                m_queue->m_suivant = nouveauNoeud;
            }
            else {
                m_tete = nouveauNoeud;
            }
            m_queue = nouveauNoeud;
            m_nombreElement++;
        }


        int obtenirPremierElement() {
            if (!m_tete) {
                throw std::out_of_range("la liste est vide");
            }
            return m_tete->m_valeur;
        }


        bool estVide() {
            return m_tete == nullptr;
        }


        void vider() {
            Noeud<T>* temp = m_tete;

            while (temp) {
                Noeud<T>* suivant = temp->m_suivant;
                delete temp;
                temp = suivant;
            }

            m_tete = nullptr;
            m_queue = nullptr;
            m_nombreElement = 0;
        }


        int nombreElements() const {
            return m_nombreElement;
        }

        ListeChaineeCartes& operator+=(ListeChaineeCartes&& p_listeAAjouter) {
            this->m_queue->m_suivant = p_listeAAjouter.m_tete;

            p_listeAAjouter.m_tete = nullptr;
            p_listeAAjouter.m_queue = nullptr;

            return *this;
        }
        void parcourir(void (*p_fonction)(const int&)) {
            Noeud<T>* noeudCourant = m_tete;
            while (noeudCourant != nullptr) {
                p_fonction(noeudCourant->m_valeur);
                noeudCourant = noeudCourant->m_suivant;
            }
        }

    private:

        Noeud<T>* m_tete;
        Noeud<T>* m_queue;
        int m_nombreElement{};
};

