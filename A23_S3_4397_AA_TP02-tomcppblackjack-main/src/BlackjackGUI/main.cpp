#include <iostream>

#include <Window/Window.h>

#include <direct.h>

#include "demo01/Demo01.h"
#include "MaClasse.h"

int main()
{
    MaClasse mc;
    std::cout << "mc.vrai() = " << ((mc.vrai()) ? "vrai" : "faux") << std::endl;

    std::cout << "Path: " << _getcwd(0, NULL) << std::endl;
    Demo01 demo01;

    demo01.show();
}
