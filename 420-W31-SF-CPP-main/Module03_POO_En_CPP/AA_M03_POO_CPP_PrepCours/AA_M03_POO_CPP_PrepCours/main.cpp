// AA_M03_POO_CPP_PrepCours.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Televiseur.h"

void demo1();

int main()
{
	demo1();
}

Televiseur creerTeleviseur() {
	Televiseur t;
	return t;
}

void demo1() {
	std::cout << "Televiseur t1;" << std::endl;
	Televiseur t1;
	t1.allumer();

	std::cout << std::endl << "Televiseur t2();" << std::endl;
	Televiseur t2(); // Erreur classique : on ne met des parenth�ses que pour les constructeurs avec des param�tres
	//t2.allumer(); // expression must have class type but it has type "Televiseur (*)()


	std::cout << std::endl << "Televiseur t3(50, 16, false);" << std::endl;
	Televiseur t3(50, 16, false);

	std::cout << std::endl << "Televiseur t4 = Televiseur(50, 16, false);" << std::endl;
	Televiseur t4 = Televiseur(50, 16, false);

	{
		std::cout << std::endl << "Dans une nouvelle port�e" << std::endl;
		Televiseur tdansportee1;
	}

	std::cout << std::endl << "t3 = t4;" << std::endl;
	t3 = t4;

	std::cout << std::endl << "t3 = Televiseur(30, 16, false);" << std::endl;
	t3 = Televiseur(30, 16, false);

	std::cout << std::endl << "Televiseur t5 = creerTeleviseur();" << std::endl;
	Televiseur t5 = creerTeleviseur();

	std::cout << std::endl << "Actionnable& a1 = t3" << std::endl;
	Actionnable& a1 = t3;
	std::cout << "typeid(a1).name() : " << typeid(a1).name() << std::hex << " - 0x" << &a1 << std::endl;
	std::cout << "typeid(t3).name() : " << typeid(t3).name() << std::hex << " - 0x" << &t3 << std::endl;

	std::cout << std::endl << "On sort de la port�e de la fonction main : appel des destructeurs des variables locales" << std::endl;
}