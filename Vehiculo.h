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
	void setNumeroSerie() { numSerie = 100000 + rand() % (999999-100000); }
	int getNumeroSerie(){ return numSerie; }
	float getPotenciaMax(){ return potenciaMaxima; }
	float getVelocidadMaxima(){ return velocidadMaxima; }

	void setTipoVehiculo(string tipo) { 
		tipoVehiculo = tipo; 
		setNumCilindros();
	}
	string getTipoVehiculo() { return tipoVehiculo; }

	void setNumCilindros(){ 
		if(tipoVehiculo == "Familiar") numCilindros = 6;
		else if(tipoVehiculo == "PickUp") numCilindros = 8;
		else numCilindros = 4; //Deportivo, Descapotable, Clasico, Sedan
	}
	int getNumCilindros(){ return numCilindros; }

	void setTransmision(string t) { transmision = t; }
	void setTransmision() {
		int res;
	    do{
	        cout<<"1.- Manual"<<endl;
	        cout<<"2.- Automatica"<<endl;
	        cout<<"Tipo de tranmision: "<<endl;
	        cin>>res;
	        switch(res) {
	            case 1: transmision = "Manual"; break;
	            case 2: transmision = "Automatica"; break;
	            default: 
	            res = 3; 
	            cout<<"Opcion no disponible"<<endl; 
	            break;
	        }
	    }
	    while(res == 3);
	}
	string getTransmision(){ return transmision; }

	void setConsumo() {
		if(tipoVehiculo == "Sedan") consumo = (130 + rand() % 50) / 10; 
		else if(tipoVehiculo == "Clasico") consumo = (120 + rand() % 50) / 10;
		else if(tipoVehiculo == "Familiar") consumo = (90 + rand() % 20) / 10;
		else if(tipoVehiculo == "PickUp") consumo = (70 + rand() % 50) / 10;
		else consumo = (100 + rand() % 50) / 10; //Deportivo y Descapotable	
	}
	float getConsumo(){ return consumo; }
	
	// void setChasis(string ch){ chasis = ch; }
	void setChasis(string tipoV) {
		if(tipoVehiculo == "PickUp") chasis = "Independiente";
		else chasis = "Autoportante"; //Clasico, Deportivo, Descapotable, Familiar, Sedan
	}
	string getChasis(){ return chasis; }

	void setFrenos(string fr){ frenos = fr; }
	void setFrenos() {
		int res;
	    do {
	        cout<<"1.- Disco"<<endl;
	        cout<<"2.- Tambor"<<endl;
	        cout<<"3.- ABS"<<endl;
	        cout<<"Tipo de frenos: "<<endl;
	        cin>>res;
	        switch(res) {
	            case 1: frenos = "Disco"; break;
	            case 2: frenos = "Tambor"; break;
	            case 3: frenos = "ABS"; break;
	            default: 
	            res = 4;
	            cout<<"Opcion no disponible"<<endl; 
	            break;
	        }
	    }
	    while(res == 4);
	}
	string getFrenos(){ return frenos; }

	void setTraccion(string tra){ traccion = tra; }
	void setTraccion() {
		int res;
	    do {
	        if(tipoVehiculo == "PickUp" || tipoVehiculo == "Familiar") {
	            cout<<"1.- Delantera"<<endl;
	            cout<<"2.- 4x4"<<endl;
	            cout<<"Tipo de traccion: "<<endl;
	            cin>>res;
	            switch(res) {
	                case 1: traccion = "Delantera"; break;
	                case 2: traccion = "4x4"; break;
	                default: 
	                res = 3;
	                cout<<"Opcion no disponible"<<endl; 
	                break;
	            }
	        }
	        else {
	            cout<<"1.- Delantera"<<endl;
	            cout<<"2.- Tracera"<<endl;
	            cout<<"Tipo de traccion: "<<endl;
	            cin>>res;
	            switch(res) {
	                case 1: traccion = "Delantera"; break;
	                case 2: traccion = "Tracera"; break;
	                default: 
	                res = 3;
	                cout<<"Opcion no disponible"<<endl; 
	                break;
	            }
	        }
	    } 
	    while(res == 3);
	}
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
	void setColor() {
		int res;
	    do {
	        cout<<"1.- Negro"<<endl;
	        cout<<"2.- Blanco"<<endl;
	        cout<<"3.- Plomo"<<endl;
	        cout<<"4.- Rojo"<<endl;
	        cout<<"5.- Azul"<<endl;
	        cout<<"6.- Plata"<<endl;
	        cout<<"Color de automovil: "<<endl;
	        cin>>res;
	        switch(res) {
	            case 1: color = "Negro"; break;
	            case 2: color = "Blanco"; break;
	            case 3: color = "Plomo"; break;
	            case 4: color = "Rojo"; break;
	            case 5: color = "Azul"; break;
	            case 6: color = "Plata"; break;
	            default: 
	            res = 7;
	            cout<<"Opcion no disponible"<<endl; 
	            break;
	        }
	    }
	    while(res == 7);
	}
	string getColor(){ return color; }

	void setRin(int r){ rines = r; }
	void setRin() {
		int res;
	    do {
	        if(tipoVehiculo == "Clasico" || tipoVehiculo == "Sedan" || tipoVehiculo == "Familiar") {
	            cout<<"1.- 13 in"<<endl;
	            cout<<"2.- 14 in"<<endl;
	            cout<<"3.- 15 in"<<endl;
	            cout<<"Tamanio de Rines: "<<endl;
	            cin>>res;
	            switch(res) {
	                case 1: rines = 13; break;
	                case 2: rines = 14; break;
	                case 3: rines = 15; break;
	                default: 
	                res = 4;
	                cout<<"Opcion no disponible"<<endl; 
	                break;
	            }
	        }
	        else if(tipoVehiculo == "Deportivo" || tipoVehiculo == "Descapotable" || tipoVehiculo == "PickUp") {
	            cout<<"1.- 16 in"<<endl;
	            cout<<"2.- 17 in"<<endl;
	            cout<<"Tamanio de Rines: "<<endl;
	            cin>>res;
	            switch(res) {
	                case 1: rines = 16; break;
	                case 2: rines = 17; break;
	                default: 
	                res = 4;
	                cout<<"Opcion no disponible"<<endl; 
	                break;
	            }
	        }
	    }
	    while(res == 4);
	}
	int getRin(){ return rines; }

	void setLlanta(string llan){ llantas = llan; }
	void setLlanta() {
		int res;
	    do {
	        cout << "1.- Bajo consumo " << endl;
	        cout << "2.- Runflat " << endl;
	        cout << "3.- Bajo perfil " << endl;
	        cout << "4.- Tubulares " << endl;
	        cout << "5.- Diagonal " << endl;
	        cout << "6.- Radial " << endl;
	        cout << "7.- All seasons " << endl;
	        cout << "8.- Asimetricas " << endl;
	        cout << "9.- Direccionales " << endl;
	        cout << "Elija su tipo de llanta " << endl;
	        cin>>res;
	
			//Revisar porque no jala la opcion del sedan jeje
	        switch (res){
	            case 1: llantas = "Bajo consumo"; break;
	            case 2: llantas = "Runflat"; break;
	            case 3: llantas = "Bajo perfil"; break;
	            case 4: llantas = "Tubulares"; break;
	            case 5: llantas = "Diagonal"; break;
	            case 6: llantas = "Radial"; break;
	            case 7: llantas = "All seasons"; break;
	            case 8: llantas = "Asimetricas"; break;
	            case 9: llantas = "Direccionales"; break;
	            default: 
	            	res = 10;
	            	cout<<"Opcion no disponible"<<endl; 
	            	break;
	        }
	    }
	    while(res == 10);
	}
	string getLlantas(){ return llantas; }

	void setModelo(string _modelo) { modelo = _modelo; }
	string getModelo(){ return modelo; }

	void setPrecio(double _precio) { precio = _precio; }
	void setPrecio(){
		if(tipoVehiculo == "Sedan") precio = (250 + rand() % 250) * 1000 ;
		else if(tipoVehiculo == "Clasico") precio = (100 + rand() % 200) * 1000;
		else if(tipoVehiculo == "Familiar") precio = (500 + rand() % 1000) * 1000;
		else if(tipoVehiculo == "PickUp") precio = (400 + rand() % 800) * 1000;
		else precio = (100 + rand() % 200) * 1000; //Descapotable y Deportivo	
	}
	double getPrecio() { return precio; }

};
#endif
