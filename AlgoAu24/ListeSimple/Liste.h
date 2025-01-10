#pragma once
#include "Collection.h"

class Liste: public Collection
{
private:
	int m_nombreElements;
	int m_elements[20];

public:
	Liste(const Liste& p_listeACopier);
	Liste(Liste&& p_rvalueDeplacement); 
	Liste& operator = (const Liste& p_operateurCopiee);
	Liste& operator = (Liste&& p_rvalue);
	Liste();
	~Liste();
	Liste(const int& p_nombreElements, int p_element[]);
	virtual void ajouter(const int& p_elements) override;
	virtual void supprimer(const int& p_index) override;
	virtual int obtenir(const int& p_index) const override;
	virtual void definir(const int& p_index, const int& p_element) override;

	virtual void afficherListe() override;
};

