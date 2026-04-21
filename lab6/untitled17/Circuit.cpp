#include "Circuit.h"
#include <iostream>
#include <algorithm>

Circuit::Circuit() : length(0), weather(Weather::Sunny) {}

Circuit::~Circuit() {
    for (Car* c : cars) delete c;
}

void Circuit::SetLength(float l) { length = l; }

void Circuit::SetWeather(Weather w) { weather = w; }

void Circuit::AddCar(Car* c) { cars.push_back(c); }

void Circuit::Race() {
    for (Car* c : cars) {
        float speed = c->GetSpeed(weather);
        float maxDistance = (c->GetFuelCapacity() / c->GetFuelConsumption()) * 100.0f;
        
        Result r;
        r.name = c->GetName();
        if (maxDistance >= length) {
            r.finished = true;
            r.time = length / speed;
        } else {
            r.finished = false;
            r.time = -1; // Indicator pentru DNF
        }
        results.push_back(r);
    }
    
    // Sortăm rezultatele bazat pe timp (cei care au terminat primii)
    std::sort(results.begin(), results.end(), [](const Result& a, const Result& b) {
        if (a.finished && b.finished) return a.time < b.time;
        return a.finished > b.finished; // Cei care termină sunt înaintea celor DNF
    });
}

void Circuit::ShowFinalRanks() {
    std::cout << "--- Clasament Final ---" << std::endl;
    int rank = 1;
    for (const auto& r : results) {
        if (r.finished) {
            std::cout << rank++ << ". " << r.name << " - Timp: " << r.time << " ore" << std::endl;
        }
    }
}

void Circuit::ShowWhoDidNotFinish() {
    std::cout << "--- Masini care nu au terminat (DNF) ---" << std::endl;
    for (const auto& r : results) {
        if (!r.finished) {
            std::cout << "- " << r.name << " (Ramas fara combustibil)" << std::endl;
        }
    }
}