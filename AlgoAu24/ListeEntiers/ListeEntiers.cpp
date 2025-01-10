#include <iostream>
#include "ListeEntiers.h"

ListeEntiers::ListeEntiers(const int& p_capaciteMin)
    :m_valeurs(new int[m_capacite]), 
    m_capacite(p_capaciteMin),
    m_nbElements(0)
{
    if (this->m_nbElements < 1) {
        noexcept("le nombre d'element ne peut etre negatif");
    }
    std::cout << "ctor initialisation"<< std::endl;
}

ListeEntiers::ListeEntiers(const ListeEntiers& p_listeACopier)
    :m_valeurs(nullptr),
    m_nbElements(p_listeACopier.m_nbElements), 
    m_capacite(p_listeACopier.m_capacite)
{
    std::cout << "ctor copie" << std::endl;
    if (p_listeACopier.m_nbElements < 1) {
        noexcept("le nombre d'element ne peut etre negatif");
    }
    this->m_valeurs = new int[this->m_capacite];
    for (int i = 0; i < this->m_nbElements; ++i)
    {
        this->m_valeurs[i] = p_listeACopier.m_valeurs[i];
    }
}

ListeEntiers::ListeEntiers(ListeEntiers&& p_listeADeplacer)
    :m_valeurs(p_listeADeplacer.m_valeurs),
    m_nbElements(p_listeADeplacer.m_nbElements),
    m_capacite(p_listeADeplacer.m_capacite)
{
    std::cout << "ctor deplacement" << std::endl;
    if (this->m_nbElements < 1) {
        noexcept("le nombre d'element ne peut etre negatif");
    }
    p_listeADeplacer.m_valeurs = nullptr;
    p_listeADeplacer.m_capacite = 0;
    p_listeADeplacer.m_nbElements = 0;

}

ListeEntiers::~ListeEntiers()
{
    std::cout << "destructeur" << std::endl;
    if (this->m_valeurs) {
        delete[] this->m_valeurs;
        m_valeurs = nullptr;
    }
}

void ListeEntiers::ajouterFin(const int& p_valeur)
{
    if (this->m_capacite == this->m_nbElements) {
        this->m_capacite *= 2;
        int* nouveauTableau = new int[this->m_capacite];
        for (int i = 0; i < this->m_nbElements; ++i) {
            nouveauTableau[i] = this->m_valeurs[i];
        }
        delete[] this->m_valeurs;
        this->m_valeurs = nouveauTableau;
    }
    this->m_valeurs[this->m_nbElements] = p_valeur;
    ++this->m_nbElements;
}

void ListeEntiers::supprimerFin()
{
    --this->m_nbElements;
}

void ListeEntiers::afficherListe()
{
    std::cout << "les elements de la liste sont:" << std::endl;
    for (int i = 0; i < this->m_nbElements; ++i) {
        std::cout << this->m_valeurs[i] << std::endl;
    }
}

void ListeEntiers::ajouterDebut(const int& p_valeur)
{
    if (this->m_nbElements == this->m_capacite) {
        this->m_capacite *= 2;
        int* nouveauTableau = new int[this->m_capacite];
        for (int i = 0; i < this->m_nbElements; ++i) {
            nouveauTableau[i] = this->m_valeurs[i];
        }
        delete[] this->m_valeurs;
        this->m_valeurs = nouveauTableau;
    }
    for (int i = this->m_nbElements; i >= 1; --i) {
        this->m_valeurs[i] = this->m_valeurs[i - 1];
    }
    this->m_valeurs[0] = p_valeur;
    ++this->m_nbElements;
}

void ListeEntiers::inserer(const int& p_valeur, const int& p_indice)
{
    if (p_indice < 0 || p_indice > this->m_nbElements) {
        throw new std::invalid_argument("l'indice ne peut etre negatif ni sup au nombre d'element");
    }
    this->m_valeurs[p_indice] = p_valeur;
}

void ListeEntiers::supprimerDebut()
{
    for (int i = 0; i < this->m_nbElements; ++i) {
        this->m_valeurs[i] = this->m_valeurs[i + 1];
    }
    --this->m_nbElements;
}

void ListeEntiers::supprimer(const int& p_indice)
{
    if (p_indice < 0 || p_indice > this->m_nbElements) {
        throw new std::invalid_argument("l'indice ne peut etre negatif ni sup au nombre d'element");
    }
    for (int i = p_indice; i < this->m_nbElements; ++i) {
        this->m_valeurs[i] = this->m_valeurs[i + 1];
    }
    --this->m_nbElements;
}

void ListeEntiers::trier()
{
    // pas certain de ça.
    int valeurTemp = this->m_valeurs[0];
    for (int i = 0; i < this->m_nbElements; ++i) {
        if (this->m_valeurs[i] > valeurTemp) {
            this->m_valeurs[i + 1] = this->m_valeurs[i];
            this->m_valeurs[i] = valeurTemp;
        }
    }
}

int ListeEntiers::chercher(const int& p_valeur)
{
    int elementTrouve = -1;
    for (int i = 0; i < this->m_nbElements; ++i) {
        if (this->m_valeurs[i] == p_valeur) {
            elementTrouve = i + 1;
        }
    }
    return elementTrouve;
}

bool ListeEntiers::estDansListe(const int& p_valeur)
{
    bool estPresent = false;
    for (int i = 0; i < this->m_nbElements; ++i) {
        if (this->m_valeurs[i] == p_valeur) {
            estPresent = true;
        }
    }
    return estPresent;
}

int ListeEntiers::obtenir(const int& p_indice)
{
    if (p_indice < 0 || p_indice >= this->m_nbElements) {
        throw new std::invalid_argument("le nombre d'element ne peut etre negatif ou sup au nombre d'element");
    }
    int valeurAIndice = 0;
    for (int i = 0; i < this->m_nbElements; ++i) {
        if (p_indice == i) {
            valeurAIndice = this->m_valeurs[i];
        }
    }
    return valeurAIndice;
}

int ListeEntiers::nombreElements() const
{
    return this->m_nbElements;
}

int ListeEntiers::capacite() const
{
    return this->m_capacite;
}

ListeEntiers& ListeEntiers::operator=(const ListeEntiers& p_listeACopier) {
    std::cout << "operateur copie" << std::endl;
    if (this != &p_listeACopier) {
        if (this->m_capacite < p_listeACopier.m_capacite) {
            int* new_valeurs = new int[p_listeACopier.m_capacite];
            delete[] this->m_valeurs;
            this->m_valeurs = new_valeurs;
            this->m_capacite = p_listeACopier.m_capacite;
        }
        for (int i = 0; i < p_listeACopier.m_nbElements; ++i) {
            this->m_valeurs[i] = p_listeACopier.m_valeurs[i];
        }
        this->m_nbElements = p_listeACopier.m_nbElements;
    }
    return *this;
}


ListeEntiers& ListeEntiers::operator=(ListeEntiers&& p_listeADeplacer) {
    std::cout << "operateur deplacement" << std::endl;
    if (this != &p_listeADeplacer) {
        delete[] this->m_valeurs;
        this->m_valeurs = p_listeADeplacer.m_valeurs;
        this->m_capacite = p_listeADeplacer.m_capacite;
        this->m_nbElements = p_listeADeplacer.m_nbElements;

        p_listeADeplacer.m_valeurs = nullptr;
        p_listeADeplacer.m_capacite = 0;
        p_listeADeplacer.m_nbElements = 0;
    }
    return *this;
}


void ListeEntiers::parcourir(void(*p_fonction)(const int&))
{
    for (int i = 0; i < this->m_nbElements; ++i) {
        (*p_fonction)(this->m_valeurs[i * 2]);
        //p_fonction(this->m_valeurs[i * 2]);
    }
}

ListeEntiers ListeEntiers::concatener(const ListeEntiers& p_listeAConcatener)
{
    int* nouveauTab = new int[this->m_nbElements + p_listeAConcatener.m_nbElements];
    for (int i = 0; i < this->m_nbElements; ++i) {
        nouveauTab[i] = this->m_valeurs[i];
    }
    for (int i = 0; i < p_listeAConcatener.m_nbElements; ++i) {
        nouveauTab[this->m_nbElements + i] = p_listeAConcatener.m_valeurs[i];
    }
    ListeEntiers nouvelleList(this->m_nbElements + p_listeAConcatener.m_nbElements);

    if (nouveauTab) {

        delete[] nouveauTab;
        nouveauTab = nullptr;

    }

    return nouvelleList;
}

ListeEntiers ListeEntiers::concatener(ListeEntiers&& p_listeAConcatener)
{
    //ListeEntiers(p_listeAConcatener);

    int* nouveauTab = new int[this->m_nbElements + p_listeAConcatener.m_nbElements];
    for (int i = 0; i < this->m_nbElements; ++i) {
        nouveauTab[i] = this->m_valeurs[i];
    }
    for (int i = 0; i < p_listeAConcatener.m_nbElements; ++i) {
        nouveauTab[this->m_nbElements + i] = p_listeAConcatener.m_valeurs[i];
    }
    ListeEntiers nouvelleList(this->m_nbElements + p_listeAConcatener.m_nbElements);

    if (nouveauTab) {

        delete[] nouveauTab;
        nouveauTab = nullptr;

    }

    return nouvelleList;
}

