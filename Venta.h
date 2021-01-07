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
		void MostrarVenta(int i) {
			
				cout<<"\t Datos de venta"<<endl;
				cout<< "Numero de factura: " << fac << endl;
				cout<<"Nombre del comprador: "<<venta[i].comprador.mostrarNombre()<<endl;
				cout<<"Direccion: "<<venta[i].direccion<<endl;
				cout<<"Telefono"<<venta[i].comprador.getTelefono();
				cout<<"Vehiculo Comprado: "<<venta[i].vehiculos.getMarca()<<endl;
				cout<<"Precio de Vehiculo: "<<venta[i].vehiculos.getPrecio()<<endl;
				cout<<"Tipo de Pago: "<<venta[i].comprador.getPago()<<endl;
			
		}
		
		void MostrarTicket(){
			cout<<"\t Ticket de Compra"<<endl;
			cout<<"Nombre del comprador: "<<comprador.mostrarNombre()<<endl;
			cout<<"Vehiculo Comprado: "<<vehiculos.getMarca()<<endl;
			cout<<"Numero de serie: "<<vehiculos.getNumeroSerie()<<endl<<endl;
			cout<<"Caracteristicas del vehiculo: "<<endl;
			cout<<"Tipo de vehiculo: "<<vehiculos.getTipoVehiculo()<<endl;
			cout<<"Modelo: "<<vehiculos.getModelo()<<endl;
			cout<<"Color: "<<vehiculos.getColor()<<endl;
			cout<<"Precio de Vehiculo: "<<vehiculos.getPrecio()<<endl;
			cout<<"Tipo de Pago: "<<comprador.getPago()<<endl;
		}

		double operator + (Vehiculo v2){
			double a;
			
			a = vehiculos[].getPrecio() + v2.getPrecio();
			
			return a;
		}
		void BuscarVentas(Venta ventas[]) {
			string fac;
			int indice = -1;
			int i = 0;
			bool encontrado = false;
			
			cout << "Ingrese la factura a buscar"; cin >> fac;
			
			while((i < N) && (!encontrado)) {
				if(fac == ventas[i].factura) {
					indice = i;
					encontrado = true;
				}
				i++;
			}
			if(encontrado == false) {
				cout<<"Factura no encontrada, revise si se ingreso correctamente"<<endl;
			}
			
			mostarVenta(indice);
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
