
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "JeuBlackJack.h"

#include "MaClasse.h"

int main()
{
    MaClasse mc;
    std::cout << "mc.vrai() = " << ((mc.vrai()) ? "vrai" : "faux") << std::endl;
    
    JeuBlackJack blackjack;

    blackjack.menu();
    //JeuBlackJack* jeuBlackJack = new JeuBlackJack();
    //jeuBlackJack->menu();
}
