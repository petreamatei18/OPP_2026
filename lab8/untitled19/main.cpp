#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <vector>

char toLower(char c) {
    if (c >= 'A' && c <= 'Z')
        return c + ('a' - 'A');
    return c;
}

int main() {
    // Citim fisierul
    std::ifstream fisier("input.txt");
    if (!fisier.is_open()) {
        std::cerr << "Eroare: fisierul nu a putut fi deschis!\n";
        return 1;
    }

    std::string text = "";
    std::string linie;
    while (std::getline(fisier, linie))
        text += linie + " ";
    fisier.close();

    // Impartim textul in cuvinte si numaram aparitiile
    std::map<std::string, int> frecventa;
    std::string separatori = " ,?!.";
    std::size_t start = 0;

    while (start < text.size()) {
        start = text.find_first_not_of(separatori, start);
        if (start == std::string::npos)
            break;

        std::size_t sfarsit = text.find_first_of(separatori, start);
        if (sfarsit == std::string::npos)
            sfarsit = text.size();

        std::string cuv = text.substr(start, sfarsit - start);

        // Convertim la litere mici
        for (int i = 0; i < (int)cuv.size(); i++)
            cuv[i] = toLower(cuv[i]);

        frecventa[cuv]++;
        start = sfarsit;
    }

    // Introducem perechile (aparitii, cuvant) in coada de prioritati
    std::priority_queue<std::pair<int, std::string>> coada;
    for (std::map<std::string, int>::iterator it = frecventa.begin();
         it != frecventa.end(); ++it)
        coada.push(std::make_pair(it->second, it->first));

    // Golim coada intr-un vector
    std::vector<std::pair<int, std::string>> rezultat;
    while (!coada.empty()) {
        rezultat.push_back(coada.top());
        coada.pop();
    }

    // Afisam rezultatele (in cadrul grupului, afisam invers pentru ordine alfabetica)
    std::cout << "Cuvintele sortate dupa frecventa:\n\n";
    for (int i = 0; i < (int)rezultat.size(); i++) {
        int j = i;
        while (j < (int)rezultat.size() && rezultat[j].first == rezultat[i].first)
            j++;
        for (int k = j - 1; k >= i; k--)
            std::cout << "    " << rezultat[k].second << " => " << rezultat[k].first << "\n";
        i = j - 1;
    }

    return 0;
}