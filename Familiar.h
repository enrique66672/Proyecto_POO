#include <iostream>
#include "Vehiculo.h"
using namespace std;

class Familiar: public Vehiculo{
	private:
		int pasajeros;
		float dimensiones, capacidadCarga;
		string tipoEncendido, seguridad;
	public:
		Familiar() : Vehiculo(){
			pasajeros = 0;
			dimensiones = 0.0;
			capacidadCarga = 0.0;
			tipoEncendido = "";
			seguridad = "";
		}
		Familiar(int _numCilindros, string _transmision, float _consumo, string _chasis, string _frenos, string _traccion, string _suspension, int _puertas, string _marca, string _color, int _rines, string _llantas, string _modelo, double _precio, string _tipoVehiculo, int _pasajeros, float _dimensiones, float _capacidadCarga, string _tipoEncendido, string _seguridad) : Vehiculo(_numCilindros, _transmision, _consumo, _chasis, _frenos, _traccion, _suspension, _puertas, _marca, _color, _rines, _llantas, _modelo, _precio, _tipoVehiculo) {
			pasajeros = _pasajeros;
			dimensiones = _dimensiones;
			capacidadCarga = _capacidadCarga;
			tipoEncendido = _tipoEncendido;
			seguridad =  _seguridad;
		}
		~Familiar() {}
		void setNPasajeros(int _pasajeros){ pasajeros = _pasajeros; }
		int getNPasajeros(){ return pasajeros; }
		
		void setDimensiones(float _dimensiones){ dimensiones = _dimensiones; }
		float getDimensiones(){ return dimensiones; }
		
		void setCapacidadCarga(float _capacidadCarga){ capacidadCarga = _capacidadCarga; }
		float getCapacidadCarga() { return capacidadCarga; }
		
		void setTipoEncendido(string _tipoEncendido){ tipoEncendido = _tipoEncendido; }
		string getTipoEncendido(){ return tipoEncendido; }
		
		void setSeguridad(string _seguridad){ seguridad = _seguridad; }
		string getSeguridad(){ return seguridad; }		
		
};

