#include "Car.h"
class BMW : public Car {
public:
    BMW();
    float GetSpeed(Weather w) const override;
    float GetFuelCapacity() const override;
    float GetFuelConsumption() const override;
    std::string GetName() const override;
};