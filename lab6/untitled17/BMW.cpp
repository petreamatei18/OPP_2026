#include "BMW.h"
BMW::BMW() {
    name = "BMW"; fuelCapacity = 55; fuelConsumption = 12;
    speedRain = 80; speedSunny = 130; speedSnow = 50;
}
float BMW::GetSpeed(Weather w) const {
    if (w == Weather::Rain) return speedRain;
    if (w == Weather::Sunny) return speedSunny;
    return speedSnow;
}
float BMW::GetFuelCapacity() const { return fuelCapacity; }
float BMW::GetFuelConsumption() const { return fuelConsumption; }
std::string BMW::GetName() const { return name; }