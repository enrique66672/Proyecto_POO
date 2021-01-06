/*Documentar*/

#ifndef VEHICULO_H
#define VEHICULO_H
#include <iostream>
#include "Mecanicas.h"
#include "Exterior.h"

using namespace std;

class Vehiculo : protected Exterior, protected Mecanicas{
private:
	string modelo;
	string tipoVehiculo;
	double precio;
public:
	Vehiculo() : Mecanicas(), Exterior(){
		modelo = "Personalizado";
		precio = 0;
		tipoVehiculo = " ";
	}
	Vehiculo(int _numCilindros, string _transmision, float _consumo, string _chasis, string _frenos, string _traccion, string _suspension, int _puertas, string _marca, string _color, int _rines, string _llantas, string _modelo, double _precio, string _tipoVehiculo) : Mecanicas(_numCilindros, _transmision, _consumo, _chasis, _frenos, _traccion, _suspension), Exterior(_puertas, _marca, _color, _rines, _llantas){
		modelo = _modelo;
		precio = _precio;
		tipoVehiculo = _tipoVehiculo;
	}
	~Vehiculo() {}
	int getNumeroSerie(){ return numSerie; }
	float getPotenciaMax(){ return potenciaMaxima; }
	float getVelocidadMaxima(){ return velocidadMaxima; }

	void setNumCilindros(){ 
		switch(tipoVehiculo) {
			case "Deportivo":
			case "Descapotable":
			case "Clasico":
			case "Sedan": numCilindros = 4; break;
			case "Familiar": numCilindros = 6; break;
			case "PickUp": numCilindros = 8; break;
		}
	}
	int getNumCilindros(){ return numCilindros; }

	void setTransmision(string t){ transmision = t; }
	string getTransmision(){ return transmision; }

	void setConsumo() {
		switch(tipoVehiculo) {
			case "Sedan": consumo = (130 + rand() % 50) / 10; break;
			case "Clasico": consumo = (120 + rand() % 50) / 10; break;
			case "Descapotable":
			case "Deportivo": consumo = (100 + rand() % 50) / 10; break;
			case "Familiar": consumo = (90 + rand() % 20) / 10; break;
			case "PickUp": consumo = (70 + rand() % 50) / 10; break;
		}	
	}
	float getConsumo(){ return consumo; }
	
	// void setChasis(string ch){ chasis = ch; }
	void setChasis() {
		switch(tipoVehiculo) {
			case "Sedan":
			case "Familiar":
			case "Deportivo":
			case "Descapotable":
			case "Clasico": chasis = "Autoportante"; break;
			case "PickUp": chasis = "Independiente"; break;
		}
	}
	string getChasis(){ return chasis; }

	void setFrenos(string fr){ frenos = fr; }
	string getFrenos(){ return frenos; }

	void setTraccion(string tra){ traccion = tra; }
	string getTraccion(){ return traccion; }

	// void setSuspension(string sus){ suspension = sus; }
	void setSuspension() {
		string suspensiones[3] = {"Independiente", "Rigida", "Semirrigida"};
		int k = rand() % 2;
		switch(k) {
			case 0: suspension = suspensiones[0]; break;
			case 1: suspension = suspensiones[1]; break;
			case 2: suspension = suspensiones[2]; break;
		}
	}
	string getSuspension(){ return suspension; }

	void setPuertas(int cabinas) {
		if(tipoVehiculo == "Deportivo" || tipoVehiculo == "Descapotable") puertas = 2;
		else if(tipoVehiculo == "Sedan" || tipoVehiculo == "Clasico" || tipoVehiculo == "Familiar") puertas = 4;
		else if(tipoVehiculo == "PickUp") {
			if(cabinas == 1) puertas = 2;
			if(cabinas == 2) puertas = 4;
		}
	}
	int getPuertas(){ return puertas; }

	void setMarca(string marc){ marca = marc; }
	string getMarca(){ return marca; }

	void setColor(string col){ color = col; }
	string getColor(){ return color; }

	void setRin(int r){ rines = r; }
	int getRin(){ return rines; }

	void setLlanta(string llan){ llantas = llan; }
	string getLlantas(){ return llantas; }

	void setModelo(string _modelo) { modelo = _modelo; }
	string getModelo(){ return modelo; }

	void setPrecio(double _precio) { precio = _precio; }
	void setPrecio(){
		switch(tipoVehiculo) {
			case "Sedan": precio = (250 + rand() % 250) * 1000 ; break;
			case "Clasico": precio = (100 + rand() % 200) * 1000; break;
			case "Descapotable":
			case "Deportivo": precio = (750 + rand() % 450) * 1000; break;
			case "Familiar": precio = (500 + rand() % 1000) * 1000; break;
			case "PickUp": precio = (400 + rand() % 800) * 1000; break;
		}		
	}
	double getPrecio() { return precio; }

	void setTipoVehiculo(string tipo) { 
		tipoVehiculo = tipo; 
		setNumCilindros();
	}
	string getTipoVehiculo() { return tipoVehiculo; }
};
#endif
