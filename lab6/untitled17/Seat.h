#ifndef SEAT_H
#define SEAT_H

#include "Car.h"

class Seat : public Car {
public:
    // Constructorul implicit care inițializează atributele specifice mărcii
    Seat();

    // Redefinirea metodelor virtuale pure din clasa de bază (Polimorfism)
    float GetSpeed(Weather w) const override;
    float GetFuelCapacity() const override;
    float GetFuelConsumption() const override;
    std::string GetName() const override;
};

#endif