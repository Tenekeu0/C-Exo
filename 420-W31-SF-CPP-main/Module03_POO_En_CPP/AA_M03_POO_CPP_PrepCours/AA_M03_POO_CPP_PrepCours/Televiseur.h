#pragma

#include "Actionable.h"

class Televiseur : public Actionnable {
public:
	// Ctor par défaut
	Televiseur();
	// Ctor par copie
	Televiseur(const Televiseur& p_objetACopier);
	// Ctor par déplacement
	Televiseur(Televiseur&& p_rvalue);
	// Ctor d'initialisation avec un paramètre qui a une valeur par défaut
	Televiseur(int p_canalActuel, int p_volume, bool p_estAllume = false);
	
	// Destructeur. Il n'y a jamais de paramètres
	~Televiseur();

	// Opérateur d'affectation
	Televiseur& operator=(const Televiseur& p_objetAAffecter);
	Televiseur& operator=(Televiseur&& p_objetAAffecter);

	void volume(const int& p_volume);
	int volume() const;

	void changerCanal(const int& p_canal);
	int canal() const;

	virtual bool estAllume() const;
	virtual void allumer();
	virtual void eteindre();
protected:
	
private:
	int m_canalActuel;
	int m_volume;
	bool m_estAllume;
};
