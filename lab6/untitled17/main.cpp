#include "Circuit.h"
#include "Volvo.h"
#include "BMW.h"
#include "Seat.h"
#include "Fiat.h"
#include "RangeRover.h"

int main() {
    Circuit c;
    c.SetLength(100);             // Lungimea circuitului în km
    c.SetWeather(Weather::Rain);  // Condiții meteo: Ploaie

    // Adăugăm mașinile pe pistă (alocate dinamic)
    c.AddCar(new Volvo());
    c.AddCar(new BMW());
    c.AddCar(new Seat());
    c.AddCar(new Fiat());
    c.AddCar(new RangeRover());

    c.Race();                     // Simulăm cursa
    c.ShowFinalRanks();           // Afișăm câștigătorii
    c.ShowWhoDidNotFinish();      // Afișăm pierzătorii

    return 0;
}