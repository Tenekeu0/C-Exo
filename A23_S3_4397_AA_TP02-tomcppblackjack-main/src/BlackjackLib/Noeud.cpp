#include "Noeud.h"

template<typename T>
Noeud<T>::Noeud(const T& p_valeur):m_valeur(p_valeur), m_suivant(nullptr) {
}