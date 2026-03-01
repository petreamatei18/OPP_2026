#include "Comparatii.h"
#include <cstring>

int ComparaNume(Student s1, Student s2)
{
    int r = strcmp(s1.GetNume(), s2.GetNume());
    if (r == 0) return 0;
    if (r > 0) return 1;
    return -1;
}

int ComparaMate(Student s1, Student s2)
{
    if (s1.GetMate() == s2.GetMate()) return 0;
    if (s1.GetMate() > s2.GetMate()) return 1;
    return -1;
}

int ComparaEngleza(Student s1, Student s2)
{
    if (s1.GetEngleza() == s2.GetEngleza()) return 0;
    if (s1.GetEngleza() > s2.GetEngleza()) return 1;
    return -1;
}

int ComparaIstorie(Student s1, Student s2)
{
    if (s1.GetIstorie() == s2.GetIstorie()) return 0;
    if (s1.GetIstorie() > s2.GetIstorie()) return 1;
    return -1;
}

int ComparaMedie(Student s1, Student s2)
{
    if (s1.GetMedie() == s2.GetMedie()) return 0;
    if (s1.GetMedie() > s2.GetMedie()) return 1;
    return -1;
}