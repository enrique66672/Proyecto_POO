#include <iostream>
#include "Vehiculo.h"

using namespace std;

class Deportivo : public Vehiculo
{
private:
   string tipoMotor, tipoDireccion;
   float aceleracion;
public:
    Deportivo() : Vehiculo(){
        tipoMotor = "";
        tipoDireccion = "";
        aceleracion = 0;
    }
    Deportivo(int _numCilindros, string _transmision, float _consumo, string _chasis, string _frenos, string _traccion, string _suspension, int _puertas, string _marca, string _color, int _rines, string _llantas, string _modelo, double _precio, string _tipoVehiculo, string _tipoMotor, string _tipoDireccion, float _aceleracion) : Vehiculo(_numCilindros, _transmision, _consumo, _chasis, _frenos, _traccion, _suspension, _puertas, _marca, _color, _rines, _llantas, _modelo, _precio, _tipoVehiculo) {
        tipoMotor = _tipoMotor;
        tipoDireccion = _tipoDireccion;
        aceleracion = _aceleracion;
    }
    ~Deportivo() {}
    void setMotor(string _tipoMotor){ tipoMotor = _tipoMotor; }
    string getMotor(){ return tipoMotor; }

    void setDireccion(string _tipoDireccion){ tipoDireccion = _tipoDireccion; }
    string getDireccion(){ return tipoDireccion; }

    void setAceleracion(float _aceleracion){ aceleracion = _aceleracion; }
    float getAceleracion(){ return aceleracion; }
   
};

