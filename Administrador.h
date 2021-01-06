#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
#include <iostream>
#include "Usuario.h"
#include "Venta.h"
#include "Vehiculo.h"
#define MAX 30

using namespace std;

class Administrador : private Usuario {
	private:
		string id, password;
		Venta venta[MAX];
	public:
		Administrador() : Usuario(){
			id = "";
			password = "";
		}

		void setId(string _id, string _nombre) {
			id = _id;
			setNombre(_nombre);
		}
		string getId() { return id; }

		void setPassword(string _contra) { password = _contra; }
		string getPassword() { return password;	}

		string mostrarNombre() { return getNombre(); }
		
		friend Vehiculo personalizarVehiculo();
};
#endif
