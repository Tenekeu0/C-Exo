#include <iostream>
#include <math.h>

void tempsO1(const int& p_operation) {
    float tempsExeution = 1 / p_operation;

    std::cout << "O(1) " << tempsExeution << " secondes\n";
}

void tempsOn(const int& p_operation, const int& n) {
    float tempsExeution = n / p_operation;

    std::cout << "O(n) avec n = " << n << ": " << tempsExeution << " secondes\n";
}

void tempsOn2(const int& p_operation, const int& n) {
    float tempsExeution = (n * n) / p_operation;

    std::cout << "O(n2) avec n = " << n << ": " << tempsExeution << " secondes\n";
}

void tempsOn3(const int& p_operation, const int& n) {
    float tempsExeution = (n * n * n) / p_operation;

    std::cout << "O(n3) avec n = " << n << ": " << tempsExeution << " secondes\n";
}

void tempsO2ExpoN(const int& p_operation, const int& n) {
    float tempsExeution = pow(n, 2) / p_operation;

    std::cout << "O(n^2) avec n = " << n << ": " << tempsExeution << " secondes\n";
}

void tempsOnExclama(const int& p_operation, const int& n) {
    // a voir avec le prof...
}

void tempsOnlogn(const int& p_operation, const int& n) {
    float tempsExeution = (n * log(n)) / p_operation;

    std::cout << "O(n log n) avec n = " << n << ": " << tempsExeution << " secondes\n";
}


int main()
{
    const int& Operation = 1000000;
    int tailleEntreeN[6] = { 10,100,1000,10000,100000,1000000 };

    for (int i = 0; i < 6; ++i) {
        tempsO1(Operation);
        tempsOn(Operation, tailleEntreeN[i]);
        tempsOn2(Operation, tailleEntreeN[i]);
        tempsOn3(Operation, tailleEntreeN[i]);
        tempsO2ExpoN(Operation, tailleEntreeN[i]);
        tempsOnlogn(Operation, tailleEntreeN[i]);
    }
}