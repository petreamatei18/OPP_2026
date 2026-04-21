#include "Seat.h"

// Inițializarea constantelor de performanță în constructor
Seat::Seat() {
    name = "Seat";
    fuelCapacity = 50.0f;    // Capacitate medie a rezervorului
    fuelConsumption = 7.5f;   // Consum mixt (litri la 100km)
    
    // Viteze medii adaptate în funcție de condițiile meteorologice
    speedRain = 75.0f;
    speedSunny = 115.0f;
    speedSnow = 45.0f;
}

// Returnează viteza corespunzătoare stării vremii primite ca argument
float Seat::GetSpeed(Weather w) const {
    switch (w) {
        case Weather::Rain:  return speedRain;
        case Weather::Sunny: return speedSunny;
        case Weather::Snow:  return speedSnow;
        default:             return 0.0f;
    }
}

float Seat::GetFuelCapacity() const {
    return fuelCapacity;
}

float Seat::GetFuelConsumption() const {
    return fuelConsumption;
}

std::string Seat::GetName() const {
    return name;
}