#include "Number.h"
#include <cstdio>

int main() {
    // Instanțierea obiectelor cu baze diferite
    Number n1("10110010", 2);
    Number n2("734", 8);
    Number n3("FF", 16);

    printf("n1 are %d cifre si este scris in baza %d\n", n1.GetDigitsCount(), n1.GetBase());

    // Demonstrarea operatorului de indexare
    for (int tr = 0; tr < n1.GetDigitsCount(); tr++) {
        printf("n1[%d]=%c\n", tr, n1[tr]);
    }

    n1.Print();
    n2.Print();

    // Expresie aritmetică complexă: rezultatul n1 va fi convertit la baza 16
    n1 = (n2 + n3 - n1) + n1;
    n1.SwitchBase(2);
    n1.Print();

    // Utilizarea operatorilor relaționali
    if (n1 > n2) printf("n1 este mai mare decat n2\n");
    else printf("n2 este mai mare decat n1\n");

    // Demonstrarea constructorului de conversie și a operatorului +=
    Number n4 = 12345;
    n1 = 255;
    n4 += n1;
    n4.Print();

    // Atribuire din șir de caractere și utilizarea operatorilor unari de decrementare
    n4 = "13579";
    n4.Print();
    --n4; // Eliminare prima cifră
    n4.Print();
    n4--; // Eliminare ultima cifră
    n4.Print();

    return 0;
}