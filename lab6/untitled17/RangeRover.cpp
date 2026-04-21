#include "RangeRover.h"

RangeRover::RangeRover() {
    name = "RangeRover";
    fuelCapacity = 90.0f;    // Rezervor generos pentru autonomie
    fuelConsumption = 14.5f;  // Consum ridicat, specific motoarelor mari
    
    // Performanță optimizată pentru condiții dificile
    speedRain = 70.0f;
    speedSunny = 105.0f;
    speedSnow = 65.0f;       // Viteză superioară pe zăpadă față de restul flotei
}

float RangeRover::GetSpeed(Weather w) const {
    if (w == Weather::Rain) return speedRain;
    if (w == Weather::Sunny) return speedSunny;
    return speedSnow; // Weather::Snow
}

float RangeRover::GetFuelCapacity() const {
    return fuelCapacity;
}

float RangeRover::GetFuelConsumption() const {
    return fuelConsumption;
}

std::string RangeRover::GetName() const {
    return name;
}