#include <iostream>
#include "Vehiculo.h"

using namespace std;

class PicKup: public Vehiculo{
	private:
		string tamano, tipoCaja;
		int cabinas, capacidadDeCarga, longCaja;
		bool puertaDeCarga;
	public:
		PicKup() : Vehiculo(){
			tamano = "";
			cabinas = 0;
			puertaDeCarga = NULL;
			tipoCaja = "";
			capacidadDeCarga = 0;
			longCaja = 0;
		}
		PicKup(int _numCilindros, string _transmision, float _consumo, string _chasis, string _frenos, string _traccion, string _suspension, int _puertas, string _marca, string _color, int _rines, string _llantas, string _modelo, double _precio, string _tipoVehiculo, string _tamano, string _tipoCaja, int _cabinas, int _capacidadCarga, int _longCaja, bool _puertaCarga) : Vehiculo(_numCilindros, _transmision, _consumo, _chasis, _frenos, _traccion, _suspension, _puertas, _marca, _color, _rines, _llantas, _modelo, _precio, _tipoVehiculo) {
			tamano = _tamano;
			cabinas = _cabinas;
			puertaDeCarga = _puertaCarga;
			tipoCaja = _tipoCaja;
			capacidadDeCarga = _capacidadCarga;
			longCaja = _longCaja;
		}
		~PicKup() {}

		void setTamano(){ 
			int res;
			do {
				cout << "Elija el tamaño de la caja" << endl;
				cout << "1.- Chica" << endl;
				cout << "2.- Mediana" << endl;
				cout << "3.- Grande" << endl;
				cin>>res;

				switch (res){
					case 1: tamano = "Chica"; break;
					case 2: tamano = "Mediana"; break;
					case 3: tamano = "Grande"; break;			
					default: 
					res = 4;
					cout<<"Opcion no disponible"<<endl; 
					break;
				}
			}
			while(res == 4);
		}
		string getTamano(){ return tamano; }
		
		void setCabinas(){ 
			int res;
			do {
				cout << "Elija el numero de cabinas" << endl;
				cout << "1" << endl;
				cout << "2" << endl;
				cin>>res;
				if (res == 1) cabinas = 1;
				else if (res == 2) cabinas = 2;
				else{	
					res = 3;
					cout << "Opcion invalida" << endl;
				}
			} while (res == 3);
		 }
		int getCabinas(){ return cabinas; }
		
		void setPuertaDeCarga(){ 
			int res;
			do{
				cout << "Quiere puerta de carga 1 = SI / 0 = NO" << endl; 
				cin>>res;
	
				if (res == 1) puertaDeCarga = true;
				else if (res == 0) puertaDeCarga = false;
				else{
					res = -1;
					cout << "Opcion no valida" << endl;
				}
			} while (res == -1);			
		}
		bool getPuertasDeCarga(){ return puertaDeCarga; }
		
		void setTipoCaja(){ 
			int res;

			do{
			
				cout << "1.- Metal" <<endl;
				cout << "2.- Fibra de vidrio" <<endl;
				cout << "3.- fibra de carbono" <<endl;
				cout << "Elija el tipo de caja" <<endl;
				cin>>res;
				switch (res){
					case 1: tipoCaja = "Metal"; break;
					case 2: tipoCaja = "Fibra de vidrio "; break;
					case 3: tipoCaja = "Fibra de carbono"; break;
					default: 
						res = 4; 
						cout<<"Opcion no disponible"<<endl;
						break;
				}
			} while(res == 4);
		}
		string getTipoCaja(){ return tipoCaja; }
		
		void setCapacidadDeCarga(){ 
			int res;
			
			do{
				cout << "Que capacidad de carga quieres la Pick up  " <<endl;
				cout << "Coloca la capacidad desde 1000 a maximo 5000 Kilos" << endl;
				cin>>res;
				capacidadDeCarga = res;
			} while(res < 1000 && res > 5000);
		}
		int GetCapacidadDeCarga(){ return capacidadDeCarga; }
		
		void SetLongCaja(){
			int res;

			do {
				cout << "Ingrese la longitud de la caja en decimetros cubicos de un minimo de 3500 hasta 7000 " << endl;
				cin>>res;	
				capacidadDeCarga = res;
			} while(res < 3500 && res > 7000);
		}
        int GetLongCaja(){ return longCaja; }
				
};
