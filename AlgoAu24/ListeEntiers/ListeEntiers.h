#pragma once
class ListeEntiers
{
	private:
		int *m_valeurs;
		int m_capacite;
		int m_nbElements;
	public:
		ListeEntiers(const int& p_capaciteMin = 23);
		ListeEntiers(const ListeEntiers& p_listeACopier);
		ListeEntiers(ListeEntiers&& p_listeADeplacer);
		~ListeEntiers();

		void ajouterFin(const int& p_valeur);
		void supprimerFin();
		void afficherListe();
		void ajouterDebut(const int& p_valeur);
		void inserer(const int& p_valeur, const int& p_indice);
		void supprimerDebut();
		void supprimer(const int& p_indice);
		void trier();
		int chercher(const int& p_valeur);
		bool estDansListe(const int& p_valeur);
		int obtenir(const int& p_indice);
		int nombreElements() const;
		int capacite() const;

		ListeEntiers& operator=(const ListeEntiers& p_listeACopier);
		ListeEntiers& operator=(ListeEntiers&& p_listeADeplacer);

		void parcourir(void(*p_fonction)(const int&));
		ListeEntiers concatener(const ListeEntiers& p_listeAConcatener);
		ListeEntiers concatener(ListeEntiers&& p_listeAConcatener);
};

