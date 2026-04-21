#include <iostream>
#include <cstdio>
#include "Tree.h"

// Definirea Literalilor (User-Defined Literals)
// Conversie Kelvin -> Celsius
constexpr float operator"" _Kelvin(unsigned long long int k) {
    return static_cast<float>(k) - 273.15f;
}

constexpr float operator"" _Kelvin(long double k) {
    return static_cast<float>(k) - 273.15f;
}

// Conversie Fahrenheit -> Celsius
constexpr float operator"" _Fahrenheit(unsigned long long int f) {
    return (static_cast<float>(f) - 32.0f) / 1.8f;
}

constexpr float operator"" _Fahrenheit(long double f) {
    return (static_cast<float>(f) - 32.0f) / 1.8f;
}

// Funcție de comparare pentru metoda find
bool CompareValues(const int& a, const int& b) {
    return a == b;
}

int main() {
    // 1. Testarea Literalilor
    float tempK = 300_Kelvin;
    float tempF = 120_Fahrenheit;

    printf("Temperaturi convertite in Celsius:\n");
    printf("300 Kelvin = %.2f C\n", tempK);
    printf("120 Fahrenheit = %.2f C\n\n", tempF);

    // 2. Testarea Clasei Tree
    Tree<int> myTree;

    // Adăugare rădăcină
    auto root = myTree.add_node(nullptr, 100);

    // Adăugare copii direct la rădăcină
    auto n1 = myTree.add_node(root, 50);
    auto n2 = myTree.add_node(root, 200);

    // Inserare la un index specific (între n1 și n2)
    myTree.insert(root, 1, 150);

    // Adăugare nepot (copil pentru n1)
    myTree.add_node(n1, 25);

    printf("Statistici Arbore:\n");
    printf("Numar total de descendenti de la radacina: %d\n", myTree.count(nullptr));

    // Căutare
    auto found = myTree.find(nullptr, CompareValues, 150);
    if (found) {
        printf("Nodul cu valoarea 150 a fost gasit.\n");
    }

    // Sortare copii rădăcină (descrescător implicit prin operator< în logică)
    printf("Sortam copiii radacinii...\n");
    myTree.sort(root);

    return 0;
}