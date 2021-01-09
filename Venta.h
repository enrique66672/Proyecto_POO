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
		void MostrarVenta(Venta ventas[], int i) {
			cout<<"\t Datos de venta"<<endl;
			cout<< "Numero de factura: " <<factura<< endl;
			cout<<"Nombre del comprador: "<<ventas[i].comprador.mostrarNombre()<<endl;
			cout<<"Direccion: "<<ventas[i].direccion<<endl;
			cout<<"Telefono"<<ventas[i].comprador.getTelefono();
			for(int j = 0; j <= N; j++) {
				cout<<"Vehiculo Comprado: "<<ventas[i].vehiculos[j].getMarca()<<endl;
				cout<<"Precio de Vehiculo: "<<ventas[i].vehiculos[j].getPrecio()<<endl;
			}
			cout<<"Tipo de Pago: "<<ventas[i].comprador.getPago()<<endl;
		}
		
		void MostrarTicket(){
			for(int i = 0; i <= N; i++) {
				cout<<"\t Ticket de Compra"<<endl;
				cout<<"Nombre del comprador: "<<comprador.mostrarNombre()<<endl;
				cout<<"Vehiculo Comprado: "<<vehiculos[i].getMarca()<<endl;
				cout<<"Numero de serie: "<<vehiculos[i].getNumeroSerie()<<endl<<endl;
				cout<<"Caracteristicas del vehiculo: "<<endl;
				cout<<"Tipo de vehiculo: "<<vehiculos[i].getTipoVehiculo()<<endl;
				cout<<"Modelo: "<<vehiculos[i].getModelo()<<endl;
				cout<<"Color: "<<vehiculos[i].getColor()<<endl;
				cout<<"Precio de Vehiculo: "<<vehiculos[i].getPrecio()<<endl;
				cout<<"Tipo de Pago: "<<comprador.getPago()<<endl;
			}			
		}

		double operator + (){
			double a = 0;
			for (int i = 0; i < N ; i++){
				a += vehiculos[i].getPrecio();				
			}
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
			
			MostrarVenta(ventas, indice);
		}
		
		void MostrarVentas(Venta v[], int&nVentas) {
			cout<<"Todas las ventas"<<endl;
			cout<<"Marca\tModelo\tPrecio\tComprador\tDireccion"<<endl;
			for(int i = 0; i < N; i++) {
				for(int j = 0; j < v[i].N; j++){
					cout<<v[i].vehiculos[j].getMarca()<<"\t";
					cout<<v[i].vehiculos[j].getModelo()<<"\t";
					cout<<v[i].vehiculos[j].getPrecio()<<"\t";
					cout<<v[i].comprador.mostrarNombre()<<"\t";
					cout<<v[i].direccion;
				}
			}
		}
};
#endif
