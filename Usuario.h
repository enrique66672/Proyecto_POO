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
		
		void setNombre(string name){ nombre = name; }
		string getNombre(){ return nombre; }
};
#endif
