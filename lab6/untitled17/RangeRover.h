#ifndef RANGEROVER_H
#define RANGEROVER_H

#include "Car.h"

class RangeRover : public Car {
public:
    // Constructor pentru setarea specificațiilor de SUV
    RangeRover();

    // Suprascrierea metodelor pentru polimorfism
    float GetSpeed(Weather w) const override;
    float GetFuelCapacity() const override;
    float GetFuelConsumption() const override;
    std::string GetName() const override;
};

#endif