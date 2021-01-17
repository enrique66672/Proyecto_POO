#include <iostream>
#include "Vehiculo.h"

using namespace std;

class Clasico : public Vehiculo{
	private:
		string categoria, clasificacion;
		int anioRegistro;
	public:
		Clasico() : Vehiculo(){
			categoria = "Personalizado";
			clasificacion =  "Reconstruidos";
			anioRegistro = 2021;
		}
		Clasico(int _numCilindros, string _transmision, float _consumo, string _chasis, string _frenos, string _traccion, string _suspension, int _puertas, string _marca, string _color, int _rines, string _llantas, string _modelo, long double _precio, string _tipoVehiculo, string _categoria, string _clasificacion, int _anioRegistro) : Vehiculo(_numCilindros, _transmision, _consumo, _chasis, _frenos, _traccion, _suspension, _puertas, _marca, _color, _rines, _llantas, _modelo, _precio, _tipoVehiculo) {
			categoria = _categoria;
			clasificacion = _clasificacion;
			anioRegistro = _anioRegistro;
		}

		string getCategoria(){return categoria; }
		string getClasificacion(){return clasificacion;}
		int getAnioRegistro(){ return anioRegistro; }
		
		friend Vehiculo personalizarVehiculo();

};
