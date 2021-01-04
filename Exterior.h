#ifndef EXTERIOR_H
#define EXTERIOR_H
#include<iostream>

using namespace std;

class Exterior {
	protected:
		int puertas, rines;
		string marca, color, llantas;
	public:
		Exterior() {
			puertas = 0;
			rines = 0;
			marca = "";
			color = "";
			llantas = "";
		}
		Exterior(int _puertas, string _marca, string _color, int _rines, string _llantas){
			puertas = _puertas;
			marca = _marca;
			color = _color;
			rines = _rines;
			llantas = _llantas;
		}
};
#endif
