#ifndef COMPRADOR_H
#define COMPRADOR_H
#include <iostream>
#include "Usuario.h"
#include "Vehiculo.h"

using namespace std;

class Comprador : private Usuario {
	private:
		string correo;
		long long telefono;
		string tipoPago;
		Vehiculo automovil;	
		
	public:	
		Comprador() : Usuario() {
			string correo = "";
			telefono = 0;
			string tipoPago = "";
		}
		void setPago(string _Pago){ tipoPago = _Pago; }
		string getPago(){ return tipoPago; }

		void setCorreo(string _Correo, string _nombre){ 
			correo = _Correo;	
			setNombre(_nombre);
		}
		void setTelefono(long long tel){ telefono = tel; }
		long long getTelefono(){ return telefono; }

		string mostrarNombre(){ return getNombre(); }
		
		friend Vehiculo personalizarVehiculo();
};
#endif
