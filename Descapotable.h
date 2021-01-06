#include <iostream>
#include "Vehiculo.h"

using namespace std;

class Descapotable : public Vehiculo
{
private:
   int pasajeros;
   string capo, maletero;
public:
    Descapotable() : Vehiculo(){
        pasajeros = 0;
        capo = "";
        maletero = "";
    }
    Descapotable(int _numCilindros, string _transmision, float _consumo, string _chasis, string _frenos, string _traccion, string _suspension, int _puertas, string _marca, string _color, int _rines, string _llantas, string _modelo, double _precio, string _tipoVehiculo, int _pasajeros, string _capo, string _maletero) : Vehiculo(_numCilindros, _transmision, _consumo, _chasis, _frenos, _traccion, _suspension, _puertas, _marca, _color, _rines, _llantas, _modelo, _precio, _tipoVehiculo) {
        pasajeros = _pasajeros;
        capo = _capo;
        maletero = _maletero;
    }
    ~Descapotable() {}
    // void setPasajero(int _pasajeros){ pasajeros = _pasajeros; }
    int getPasajeros(){ return pasajeros; }

    void setCapo(string _capo){ capo = _capo; }
    string getCapo(){ return capo; }

    void setMaletero(string _maletero ){ maletero = _maletero; }
    string getMaletero(){ return maletero; }
  
};
