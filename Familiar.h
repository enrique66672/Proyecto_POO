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
		void setNPasajeros() {
			int res;
			do {
				cout<<"1.- 4 asientos"<<endl;
				cout<<"2.- 6 asientos"<<endl;
				cout<<"Cuantos asientos quieres"<<endl;
				cin>>res;
				switch(res) {
					case 1: pasajeros = 4; break;
					case 2: pasajeros = 6; break;
					default: 
					res = 3;
					cout<<"Opcion no disponible"<<endl;
					break;
				}
			}
			while(res == 3);
		}
		int getNPasajeros(){ return pasajeros; }
		
		void setDimensiones() {
			switch(pasajeros) {
				case 4: dimensiones = (float) 4 + (rand() % 10) / 100; break;
				case 6: dimensiones = (float) 5 + (rand() % 10) / 100; break;
			}
		}
		float getDimensiones(){ return dimensiones; }
		
		void setCapacidadCarga() {
			switch(pasajeros) {
				case 4: capacidadCarga = (float) 400 + (rand() % 2000)/10;
				case 6: capacidadCarga = (float) 600 + (rand() % 2000)/10;
			}
		}
		float getCapacidadCarga() { return capacidadCarga; }
		
		void setTipoEncendido() {
			int res;
			do {
				cout<<"1.- Boton"<<endl;
				cout<<"2.- Llave"<<endl;
				cout<<"Elije tipo de encendido"<<endl;
				cin>>res;
				switch(res) {
					case 1: tipoEncendido = "Boton"; break;
					case 2: tipoEncendido = "Llave"; break;
					default:
					res = 3;
					cout<<"Opcion no disponible"<<endl;
					break;
				}
			}
			while(res == 3);
		}
		string getTipoEncendido(){ return tipoEncendido; }
		
		void setSeguridad() { //Bolsas aire
			int res;
			do {
				cout<<"1.- 4 bolsas de aire"<<endl;
				cout<<"2.- 8 bolsas de aire"<<endl;
				cout<<"Cuantas bolsas de aire elige: "<<endl;
				cin>>res;
				switch(res) {
					case 1: seguridad = 4; break;
					case 2: seguridad = 8; break;
					default:
					res = 3;
					cout<<"Opcion no disponible"<<endl;
					break;
				}
			}
			while(res == 3);
		}
		string getSeguridad(){ return seguridad; }	

		friend Vehiculo personalizarVehiculo();	
		
};
