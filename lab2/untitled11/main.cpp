#include <iostream>
#include "Student.h"
#include "Comparatii.h"

int main()
{
    Student s1, s2;

    s1.SetNume("Andrei");
    s1.SetMate(9); s1.SetEngleza(8); s1.SetIstorie(7);

    s2.SetNume("Bogdan");
    s2.SetMate(10); s2.SetEngleza(8); s2.SetIstorie(5);

    std::cout << "Comparatie Mate: " << ComparaMate(s1, s2) << "\n";
    std::cout << "Comparatie Nume: " << ComparaNume(s1, s2) << "\n";
    std::cout << "Media lui s1: " << s1.GetMedie() << "\n";

    return 0;
}
