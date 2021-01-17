#ifndef USUARIO_H
#define USUARIO_H
#include <iostream>

using namespace std;

class Usuario {
	private:
		string nombre;
	public:
		Usuario(){
			nombre = " ";
		}

		Usuario(string _nombre) {
			nombre = _nombre;
		}	
		
		void setNombre(string n){ nombre = n; }
		string getNombre(){ return nombre; }
};
#endif
