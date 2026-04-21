#include "Volvo.h"
Volvo::Volvo() {
    name = "Volvo"; fuelCapacity = 60; fuelConsumption = 8;
    speedRain = 70; speedSunny = 100; speedSnow = 40;
}
float Volvo::GetSpeed(Weather w) const {
    if (w == Weather::Rain) return speedRain;
    if (w == Weather::Sunny) return speedSunny;
    return speedSnow;
}
float Volvo::GetFuelCapacity() const { return fuelCapacity; }
float Volvo::GetFuelConsumption() const { return fuelConsumption; }
std::string Volvo::GetName() const { return name; }