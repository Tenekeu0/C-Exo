#pragma once

#include "ListeChaineeCartes.h"
#include "Carte.h"

class PaquetCartes {
public:
    PaquetCartes();

    ~PaquetCartes();

    void melangerPaquet();

    Carte DistribuerCarte();

    int nombreCartesRestantes();

    bool paquetVide();

    void AjouterDefausse(const ListeChaineeCartes<Carte>& p_chaine);

private:
    ListeChaineeCartes<Carte> m_paquet;

};