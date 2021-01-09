#include <iostream>
#include "Vehiculo.h"

using namespace std;

class Descapotable : public Vehiculo
{
private:
   int pasajeros;
   string maletero;
   string capo;
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

    void setCapo(){
        int res;
        do {
            cout << "1.Tela-" << endl;
            cout << "2.-Lona" << endl;
            cout << "3.-Piel" << endl;
            cout << "4.-Fibra de carbono" << endl;
            cout << "5.-Fibra de vidrio" << endl;
            cout << "Elija el material del capo" << endl;
            cin>>res;

            switch (res) {
                case 1: capo = "Tela"; break;
                case 2: capo = "Lona"; break;
                case 3: capo = "Piel" ; break;
                case 4: capo = "Fibra de carbono"; break;
                case 5: capo = "Fibra de vidrio"; break;
                default: 
                res = 6;
                cout<<"Opcion no disponible"<<endl; 
                break;
            }
        }
        while(res == 6);
    }
    string getCapo(){ return capo; }

    void setMaletero( ) { 
        int res;
        do {
            cout << "1.-Neopreno" << endl;
            cout << "2.-Lona" << endl;
            cout << "3.-Piel" << endl;
            cout << "Elija el material del maletero" << endl;
            cin>>res;

            switch (res) {
                case 1: maletero = "Neopreno"; break;
                case 2: maletero = "Lona"; break;
                case 3: maletero = "Piel"; break;        
                default: 
                res = 4;
                cout<<"Opcion no  disponible"<<endl; 
                break;
            }
        }
        while(res == 4);
    }
    string getMaletero(){ return maletero; }
  
};
