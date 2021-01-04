#ifndef VENTA_H
#define VENTA_H
#include <iostream>
#include "Vehiculo.h"
#include "Comprador.h"
#define MAX 30
using namespace std;

class Venta{
	private:
		int plazo;
		int N;
		string direccion, factura;
		Comprador comprador;
		Vehiculo vehiculos [MAX];
		double total;	
	public:
		Venta(){
			plazo = 0;
			direccion = "";
			factura = "";
			total = 0.0;
			N = 0;
		}	
		
		void setPlazo(int _plazo){ plazo = _plazo; }
		int getPlazo(){ return plazo; }
		
		void setDireccion(string _direccion){ direccion= _direccion; }
		string getDireccion(){ return direccion; }
		
		void setFactura(string _factura){ factura= _factura; }
		string getFactura(){ return factura; }		
		
		void setTotal(double _total){ total= _total; }
		double getTotal(){ return total; }

		void setComprador(Comprador comp){ comprador = comp; }
		
		void AgregarVehiculo(Vehiculo v){
			vehiculos[N] = v;
			N++;
		}
		void MostrarVenta(Vehiculo v, int i) {
			v.getColor();
		}
		
		void MostrarTicket(Vehiculo v, Comprador c){
			cout<<"\t Ticket de Compra"<<endl;
			cout<<"Nombre del comprador: "<<c.mostrarNombre()<<endl;
			cout<<"Tipo de Pago: "<<c.getPago()<<endl;
			cout<<"Vehiculo Comprado: "<<v.getMarca()<<endl;
			cout<<"Numero de seire: "<<v.getNumeroSerie()<<endl;
			cout<<"Caracteristicas del vehiculo: "<<endl;
			cout<<"Modelo: "<<v.getModelo()<<endl;
			cout<<"Color: "<<v.getColor()<<endl;
			cout<<"Precio de Vehiculo: "<<v.getPrecio()<<endl;
		}

		double operator + (Vehiculo v2){
			return 0;
		}
		int BuscarVentas(string fac) {
			int indice = -1;
			int i = 0;
			bool encontrado = false;

			while((i < N) && (!encontrado)) {
				if(fac == getFactura()) {
					indice = i;
					encontrado = true;
				}
				i++;
			}
			if(encontrado == false) {
				cout<<"Factura no encontrada, revise si se ingreso correctamente"<<endl;
			}
			return indice;
		}
		void MostrarVentas(Comprador c) {
			cout<<"Todas las ventas"<<endl;
			cout<<"Marca\tModelo\tPrecio\tComprador\tDireccion"<<endl;
			for(int i = 0; i < N; i++) {
				cout<<vehiculos[i].getMarca()<<"\t";
				cout<<vehiculos[i].getModelo()<<"\t";
				cout<<vehiculos[i].getPrecio()<<"\t";
				cout<<c.mostrarNombre()<<"\t";
				cout<<getDireccion()<<endl;
			}
		}
};
#endif
