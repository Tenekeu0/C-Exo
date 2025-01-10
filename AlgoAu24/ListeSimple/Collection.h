#pragma once
class Collection
{
	private:
		int m_nombreElements;
		int m_elements[20];
	public:
		virtual void ajouter(const int& p_element) = 0;
		virtual void supprimer(const int& p_index) = 0;
		virtual int obtenir(const int& p_index) const = 0;
		virtual void definir(const int& p_index, const int& p_element) = 0;
		virtual void afficherListe() = 0;

		Collection();
		Collection(const Collection& p_objetACopier);
		Collection(Collection&& p_objetADeplacer);
		~Collection();
};

