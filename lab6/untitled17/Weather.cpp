#ifndef CAR_H
#define CAR_H

#include "Weather.h"
#include <string>

class Car {
protected:
    float fuelCapacity;    // Capacitate rezervor (litri)
    float fuelConsumption; // Consum (litri / 100km)
    float speedRain;       // Viteza medie pe ploaie (km/h)
    float speedSunny;      // Viteza medie pe soare (km/h)
    float speedSnow;       // Viteza medie pe zăpadă (km/h)
    std::string name;      // Numele mărcii

public:
    virtual ~Car() {}
    
    // Metode virtuale pure pentru obținerea specificațiilor
    virtual float GetSpeed(Weather w) const = 0;
    virtual float GetFuelCapacity() const = 0;
    virtual float GetFuelConsumption() const = 0;
    virtual std::string GetName() const = 0;
};

#endif