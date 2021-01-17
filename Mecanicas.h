#ifndef MECANICAS_H
#define MECANICAS_H
#include<iostream>
#include<time.h>
#include<stdlib.h>

using namespace std;

class Mecanicas {
	protected:
		int numSerie, numCilindros;
		float potenciaMaxima, velocidadMaxima, consumo;
		string transmision, chasis, frenos, traccion, suspension;

		float valorPotenciaMax(){
			if ((numCilindros > 700) && (numCilindros < 1000) && (traccion == "Delantera" || traccion == "Tracera")){
				return (float) 450 + rand() % 250;
			}
			else if ((numCilindros >= 1000) && (numCilindros < 1500) && (traccion == "Tracera" || traccion == "Tracera")){
				return (float) 600 + rand() % 250;
			}
			else if ((numCilindros > 700) && (numCilindros < 1000) && traccion == "4x4"){
				return 1.8 * (450 + rand() % 250);
			}
			else if((numCilindros > 1000) && (numCilindros < 1500) && traccion == "4x4"){
				return 1.5 * (600 + rand() % 250);
			}
			else return 0;
		}	
		
		float velocidadMax(){
			if((numCilindros > 700) && (numCilindros < 1000) && (traccion == "Delantera" || traccion == "Trasera")){
				return (float) 160 + rand() % 40;
			}
			else if((numCilindros >= 1000) && (numCilindros < 1500) && (traccion == "Tracera" || traccion == "Tracera")){
				return (float) 180 + rand() % 70;
			}
			else if ((numCilindros > 700) && (numCilindros < 1000) && traccion == "4x4"){
				return (float) 150 + rand() % 50;
			}
			else if((numCilindros > 1000) && (numCilindros < 1500) && traccion == "4x4"){
				return (float) 170 + rand() % 50;
			}
			else return 0;
		}

	public:
		Mecanicas() {
			numCilindros = 0;
			numSerie = 0;
			potenciaMaxima = 0;
			velocidadMaxima = 0;
			consumo = 0;
			transmision = "";
			chasis = "";
			frenos = "";
			traccion = "";
			suspension = "";
		}
		Mecanicas(int _numCilindros, string _transmision, float _consumo, string _chasis, string _frenos, string _traccion, string _suspension){
			numCilindros = _numCilindros;
			transmision = _transmision;
			consumo = _consumo;
			chasis = _chasis;
			frenos = _frenos;
			traccion = _traccion;
			suspension = _suspension;
			numSerie = 100000 + rand() % (999999-100000);
			potenciaMaxima = valorPotenciaMax();
			velocidadMaxima = velocidadMax();
		}

};
#endif
