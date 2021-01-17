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
		
	public:	
		Comprador() : Usuario() {
			string correo = "";
			telefono = 0;
			string tipoPago = "";
		}

		Comprador(string _nombre, string _correo, long long _telefono, string _tipoPago) : Usuario(_nombre){
			correo = _correo;
			telefono = _telefono;
			tipoPago = _tipoPago;
		}
		
		void setPago(string _pago){ tipoPago = _pago; }
		string getPago(){ return tipoPago; }

		void setCorreo(string _correo, string _nombre){ ´
			correo = _correo;	
			setNombre(_nombre);
		}
		string getCorreo(){ return correo; }
		
		void setTelefono(long long tel){ telefono = tel; }
		long long getTelefono(){ return telefono; }

		string mostrarNombre(){ return getNombre(); }
		
};
#endif
