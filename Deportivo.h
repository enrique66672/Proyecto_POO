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
    void setMotor(){ 
        int res;
        do {
            cout << "1.- Boxer" << endl;
            cout << "2.- A dos tiempos" << endl;
            cout << "3.- A cuatro tiempos" << endl;
            cout << "4.- V6" << endl;
            cout << "5.- V8" << endl;
            cout << "Elija el motor de su deportivo: " << endl;
            cin>>res;

            switch (res){
                case 1: tipoMotor = "Boxer"; break;
                case 2: tipoMotor = "A dos tiempos"; break;
                case 3: tipoMotor = "A cuatro tiempos"; break;
                case 4: tipoMotor = "V6"; break;
                case 5: tipoMotor = "V8"; break;
                default: 
                res = 6;
                cout<<"Opcion no disponible"<<endl; 
                break;
            }
        }
        while(res == 6);
    }
    string getMotor(){ return tipoMotor; }

    void setDireccion(){ 
        int res;
        do {
            cout << "1.- Electrica" << endl;
            cout << "2.- Mecanica" << endl;
            cout << "3.- Hidraulica" << endl;
            cout << "Elija la direccion que quiere: " << endl;
            cin>>res;
            switch (res){
                case 1: tipoDireccion = "Electrica"; break;
                case 2: tipoDireccion = "Mecanica"; break;
                case 3: tipoDireccion = "Hidraulica"; break;
                default: 
                res = 4;
                cout<<"Opcion no disponible"<<endl; 
                break;
            }
        }
        while(res == 4);
    }
    string getDireccion(){ return tipoDireccion; }

    void setAceleracion() { aceleracion = (35 + rand() % 15)/10; }
    float getAceleracion(){ return aceleracion; }
   
    friend Vehiculo personalizarVehiculo();

};

