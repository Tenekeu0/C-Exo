

//#include "ListeChaineeCartes.h"
//#include "Noeud.h"
//#include "Carte.h"

//template<typename T>
//ListeChaineeCartes<T>::ListeChaineeCartes(): m_tete(nullptr), m_queue(nullptr), m_nombreElement(0) {
//
//}
//
////template<typename T>
////ListeChaineeCartes<T>::ListeChaineeCartes(const ListeChaineeCartes<T>& p_listeACopier)
////    : m_tete(nullptr), m_queue(nullptr), m_nombreElement(0) {
////
////    Noeud<T>* temp = p_listeACopier.m_tete;
////    while (temp != nullptr) {
////        this->AjouterFin(temp); // TODO Err possible
////        temp = temp->m_suivant;
////    }
////}
//template<typename T>
//void ListeChaineeCartes<T>::trie() {
//    std::srand(std::time(nullptr));
//
//    if (m_nombreElement < 2) return;
//
//    Noeud<T>** tableauNoeuds = new Noeud<T> *[m_nombreElement];
//    Noeud<T>* temp = m_tete;
//    int index = 0;
//
//    while (temp != nullptr) {
//        tableauNoeuds[index++] = temp;
//        temp = temp->m_suivant;
//    }
//
//     https://www.geeksforgeeks.org/shuffle-a-given-array-using-fisher-yates-shuffle-algorithm/
//    for (int i = m_nombreElement - 1; i > 0; i--) {
//        int j = std::rand() % (i + 1);
//
//        T tempValeur = tableauNoeuds[i]->valeur;
//        tableauNoeuds[i]->m_valeur = tableauNoeuds[j]->m_valeur;
//        tableauNoeuds[j]->m_valeur = tempValeur;
//    }
//
//    delete[] tableauNoeuds;
//}
//
//template<typename T>
//ListeChaineeCartes<T>::ListeChaineeCartes(ListeChaineeCartes<T>&& p_listeADeplacer)
//    : m_tete(p_listeADeplacer.m_tete), 
//    m_queue(p_listeADeplacer.m_queue),
//    m_nombreElement(p_listeADeplacer.m_nombreElement) 
//{
//    p_listeADeplacer.m_tete = nullptr;
//    p_listeADeplacer.m_queue = nullptr;
//    p_listeADeplacer.m_nombreElement = 0;
//}
//
//
//template<typename T>
//ListeChaineeCartes<T>::~ListeChaineeCartes() {
//    Noeud<T>* courant = m_tete;
//    while (courant != nullptr) {
//        Noeud<T>* suivant = courant->m_suivant;
//        delete courant;
//        courant = suivant;
//    }
//}
//
//template<typename T>
//void ListeChaineeCartes<T>::trier(int (*p_fonctionTri)(const T&, const T&)) {
//
//}
//template<typename T>
//void ListeChaineeCartes<T>::AjouterAIndice(const T& p_valeur, const int& p_indice) {
//    Noeud<T>* nouveauNoeud = new Noeud<T>(p_valeur);
//    if (p_indice > m_nombreElement || p_indice < 0) {
//        throw std::invalid_argument("L'indice est au delà de la liste");
//    }
//    if (m_nombreElement == 0) {
//        m_tete = nouveauNoeud;
//        m_queue = nouveauNoeud;
//    }
//    if (p_indice == 0) {
//        ajouterDebut(nouveauNoeud);
//    }
//    else if (p_indice == m_nombreElement) {
//        ajouterFin(nouveauNoeud);
//    }
//    else {
//        Noeud* noeudPrecedent = m_tete;
//        for (int i = 0; i < p_indice - 1; i++) {
//            noeudPrecedent = noeudPrecedent->suivant;
//        }
//        nouveauNoeud->suivant = noeudPrecedent->suivant;
//        noeudPrecedent->suivant = nouveauNoeud;
//        m_nombreElement++;
//    }
//}
//
//template<typename T>
//void ListeChaineeCartes<T>::supprimerDebut() {
//    if (m_tete) {
//        Noeud* temp = m_tete;
//        m_tete = m_tete->suivant;
//        delete temp;
//        m_nombreElement--;
//        if (!m_tete) {
//            m_queue = nullptr;
//        }
//    }
//}
//
//template<typename T>
//void ListeChaineeCartes<T>::supprimerFin() {
//    if (m_tete) {
//        if (m_tete == m_queue) {
//            delete m_tete;
//            m_tete = nullptr;
//            m_queue = nullptr;
//            m_nombreElement--;
//        }
//        else {
//            Noeud* precedent = nullptr;
//            Noeud* courant = m_tete;
//
//            while (courant->suivant) {
//                precedent = courant;
//                courant = courant->suivant;
//            }
//
//            delete courant;
//            precedent->m_suivant = nullptr;
//            m_queue = precedent;
//            m_nombreElement--;
//        }
//    }
//}
//
//template<typename T>
//void ListeChaineeCartes<T>::supprimerAIndice(const int& p_indice) {
//    if (m_tete == 1) {
//        m_queue = m_tete;
//        delete m_queue;
//        m_queue = nullptr;
//        m_tete--;
//    }
//    else if (m_nombreElement == 0) {
//        m_queue = nullptr;
//        m_tete = nullptr;
//    }
//    else if (p_indice == 0) {
//        supprimerDebut();
//    }
//    else if (p_indice == m_nombreElement) {
//        supprimerFin();
//    }
//    else {
//        Noeud<T>* noeudPrecedent = m_tete;
//        for (int i = 0; i < p_indice - 1; i++) {
//            noeudPrecedent = noeudPrecedent->m_suivant;
//        }
//        Noeud<T>* noeudASupprimer = noeudPrecedent->m_suivant;
//        noeudPrecedent->m_suivant = noeudASupprimer->m_suivant;
//        delete noeudASupprimer;
//        m_nombreElement--;
//    }
//}
//
//template<typename T>
//Noeud<T>* ListeChaineeCartes<T>::obtenirTete() const {
//    return m_tete;
//}
//template<typename T>
//Noeud<T>* ListeChaineeCartes<T>::obtenirQueue() const {
//    return m_queue;
//}
//template<typename T>
//T ListeChaineeCartes<T>::obtenirIndice(const int &p_indice) const{
//    if (p_indice < 0 || p_indice >= m_nombreElement) {
//        throw std::out_of_range("Indice hors limites");
//    }
//    Noeud<T>* noeudDeIndice = m_tete;
//    for (int i = 0; i < p_indice; i++) {
//        noeudDeIndice = noeudDeIndice->suivant;
//    }
//    return noeudDeIndice->m_valeur;
//}
//
//template<typename T>
//void ListeChaineeCartes <T> ::AjouterDebut(const T& p_nouveauNoeud) {
//    Noeud<T>* nouveauNoeud = new Noeud<T>(p_nouveauNoeud);
//    m_tete = nouveauNoeud;
//
//    m_nombreElement++;
//}
//
//template<typename T>
//void ListeChaineeCartes<T>::AjouterFin(const T& p_carte) {
//
//    Noeud<T>* nouveauNoeud = new Noeud<T>(p_carte);
//
//    if (m_queue) {
//        m_queue->m_suivant = nouveauNoeud;
//    }
//    else {
//        m_tete = nouveauNoeud;
//    }
//    m_queue = nouveauNoeud;
//    m_nombreElement++;
//}
//
//template<typename T>
//int ListeChaineeCartes<T>::obtenirPremierElement() {
//    if (!m_tete) {
//        throw std::out_of_range("la liste est vide");
//    }
//    return m_tete->m_valeur;
//}
//
//template<typename T>
//bool ListeChaineeCartes<T>::estVide() {
//    return m_tete == nullptr;
//}
//
//template<typename T>
//void ListeChaineeCartes<T>::vider() {
//    while (m_tete) {
//        Noeud* temp = m_tete;
//        m_tete = m_tete->suivant;
//        delete temp;
//    }
//    m_queue = nullptr;
//    m_tete = nullptr;
//    m_nombreElement = 0;
//}
//
//template<typename T>
//int ListeChaineeCartes<T>::nombreElements() const {
//    return m_nombreElement;
//}
//
//template<typename T>
//void ListeChaineeCartes<T>::parcourir(void (*p_fonction)(const int&)) {
//    Noeud* noeudCourant = m_tete;
//    while (noeudCourant != nullptr) {
//        p_fonction(noeudCourant->m_valeur);
//        noeudCourant = noeudCourant->m_suivant;
//    }
//}
//
