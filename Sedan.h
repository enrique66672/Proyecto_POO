#include <iostream>
#include "Vehiculo.h"

using namespace std;

class Sedan : public Vehiculo {
private:
    float maletero;
    int pasajeros;
public:
    Sedan() : Vehiculo(){
        // maletero = 0.0;
        // pasajeros = 5;
    }
    Sedan(int _numCilindros, string _transmision, float _consumo, string _chasis, string _frenos, string _traccion, string _suspension, int _puertas, string _marca, string _color, int _rines, string _llantas, string _modelo, double _precio, string _tipoVehiculo, float _maletero, int _pasajeros) : Vehiculo(_numCilindros, _transmision, _consumo, _chasis, _frenos, _traccion, _suspension, _puertas, _marca, _color, _rines, _llantas, _modelo, _precio, _tipoVehiculo) {
        // maletero = _maletero;
        // pasajeros = _pasajeros;
    }
    ~Sedan() {}
    void setMaletero() { maletero = (float) 350 + (rand() % 1500)/10; }
    float getMaletero() { return maletero; }
    int getPasajeros() { return pasajeros; }
};