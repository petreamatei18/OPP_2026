#include <iostream>
#include "Math.h"

int main() {
    std::cout << "Add(5, 5): " << Math::Add(5, 5) << "\n";
    std::cout << "Mul(2, 3, 4): " << Math::Mul(2, 3, 4) << "\n";

    int numere[] = {10, 20, 30, 40, 50};
    int suma_lista = Math::Add(5, numere);
    std::cout << "Suma lista array: " << suma_lista << "\n";

    char* rezultat = Math::Add("Salut ", "Lume");
    if (rezultat != nullptr) {
        std::cout << "String: " << rezultat << "\n";
        delete[] rezultat;
    }
    return 0;
}
