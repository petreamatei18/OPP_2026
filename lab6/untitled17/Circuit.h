#ifndef CIRCUIT_H
#define CIRCUIT_H

#include "Car.h"
#include "Weather.h"
#include <vector>

class Circuit {
    float length;
    Weather weather;
    std::vector<Car*> cars;
    
    struct Result {
        std::string name;
        float time;
        bool finished;
    };
    std::vector<Result> results;

public:
    Circuit();
    ~Circuit();
    void SetLength(float l);
    void SetWeather(Weather w);
    void AddCar(Car* c);
    void Race();
    void ShowFinalRanks();
    void ShowWhoDidNotFinish();
};

#endif