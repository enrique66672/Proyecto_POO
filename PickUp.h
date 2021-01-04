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
		void setTamano(string _tamano){ tamano = _tamano; }
		string getTamano(){ return tamano; }
		
		void setCabinas(int _cabinas){ cabinas = _cabinas; }
		int getCabinas(){ return cabinas; }
		
		void setPuertaDeCarga(bool _puertaCarga){ puertaDeCarga = _puertaCarga; }
		bool getPuertasDeCarga(){ return puertaDeCarga; }
		
		void setTipoCaja(string _tipoCaja){ tipoCaja = _tipoCaja; }
		string getTipoCaja(){ return tipoCaja; }
		
		void setCapacidadDeCarga(int _capacidadCarga){ capacidadDeCarga = _capacidadCarga;}
		int GetCapacidadDeCarga(){ return capacidadDeCarga; }
		
		void SetLongCaja(int _longCaja){ longCaja = _longCaja; }
        int GetLongCaja(){ return longCaja; }
				
};
