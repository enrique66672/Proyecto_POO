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
		int factura;
		string direccion;
		Comprador comprador;
		Vehiculo vehiculos [MAX];
		long double total;	
	public:
		Venta(int _plazo, string _direccion, int _factura, long double _total, Vehiculo _vehiculo, Comprador _comprador) {
			plazo = _plazo;
			direccion = _direccion;
			factura = _factura;
			total = _total;
			vehiculos[0] = _vehiculo;
			comprador = _comprador;
			N = 1;
		}
		
		Venta(){
			plazo = 0;
			direccion = "";
			factura = 0;
			total = 0.0;
			N = 0;
		}
		
		void setPlazo(int _plazo){ plazo = _plazo; }
		int getPlazo(){ return plazo; }
		
		void setDireccion(string _direccion){ direccion= _direccion; }
		string getDireccion(){ return direccion; }
		
		void setFactura(){
    		srand(time(NULL));
			factura = 100000 + rand()% (999999 - 100000);
		}
		int getFactura(){ return factura; }

		void setComprador(Comprador comp){ comprador = comp; }
		
		void AgregarVehiculo(Vehiculo v){
			vehiculos[N] = v;
			N++;
		}
		void MostrarVenta(Venta ventas[], int i) {
			cout<<"\t\n Datos de venta"<<endl;
			cout<< "Numero de factura: " <<factura<< endl;
			cout<<"Nombre del comprador: "<<ventas[i].comprador.mostrarNombre()<<endl;
			cout<<"Direccion: "<<ventas[i].direccion<<endl;
			cout<<"Telefono: "<<ventas[i].comprador.getTelefono()<<endl;
			for(int j = 0; j < N; j++) {
				cout<<"Vehiculo Comprado: "<<ventas[i].vehiculos[j].getMarca()<<endl;
				cout<<"Precio de Vehiculo: "<<ventas[i].vehiculos[j].getPrecio()<<endl;
			}
			cout<<"Tipo de Pago: "<<ventas[i].comprador.getPago()<<endl;
		}
		
		void MostrarTicket(){
			cout<<"\t Ticket de Compra"<<endl;
			cout<<"Nombre del comprador: "<<comprador.mostrarNombre()<<endl;
			for(int i = 0; i < N; i++) {
				cout<<"Vehiculo Comprado: "<<vehiculos[i].getMarca()<<endl;
				cout<<"Numero de serie: "<<vehiculos[i].getNumeroSerie()<<endl<<endl;
				cout<<"Caracteristicas del vehiculo: "<<endl;
				cout<<"Tipo de vehiculo: "<<vehiculos[i].getTipoVehiculo()<<endl;
				cout<<"Modelo: "<<vehiculos[i].getModelo()<<endl;
				cout<<"Color: "<<vehiculos[i].getColor()<<endl;
				cout<<"Precio de Vehiculo: "<<vehiculos[i].getPrecio()<<endl; // Checar la salida del precio
				cout<<"Tipo de Pago: "<<comprador.getPago()<<endl;
			}			
		}

		long double totalVentas (Venta v[], int&nVentas){
			total = 0;
			for (int i = 0; i < nVentas ; i++){
				for (int j = 0; j < N; j++){
					total += (long double) v[i].vehiculos[j].getPrecio();
				}				
			}
			return total;
		}
		long double operator + (){ // uso de getTotal
			total = 0;
			for(int i = 0; i < N; i++) {
				total += vehiculos[i].getPrecio();
			}
			return total;
		}
		void BuscarVentas(Venta ventas[]) {
			int fac;
			int indice = -1;
			int i = 0;
			bool encontrado = false;
			cout << "Ingrese la factura a buscar"<<endl; cin >> fac;
			
			while((i < N) && (!encontrado)) {
				if(fac == ventas[i].factura) {
					indice = i;
					encontrado = true;
				}
				i++;
			}
			if(encontrado == false) cout<<"Factura no encontrada, revise si se ingreso correctamente"<<endl;
			else MostrarVenta(ventas, indice);
		}
		
		void MostrarVentas(Venta v[], int&nVentas) {
			cout<<"Todas las ventas"<<endl;
			cout<<"Num: "<<nVentas<<endl;
			cout<<"+--------------+---------------+---------------+----------------+------------+-------------------------+----------------------------+------------+"<<endl;
			cout<<"| num. Factura | Tipo Vehiculo |     Marca     |     Modelo     |   Precio   |        Comprador        |         Direccion          |  Telefono  |"<<endl;
			cout<<"+--------------+---------------+---------------+----------------+------------+-------------------------+----------------------------+------------+"<<endl;
			for(int i = 0; i < nVentas; i++) {
				for(int j = 0; j < v[i].N; j++){
					cout<<"|    "<<v[i].getFactura()<<"    |";
					cout<<" "<<v[i].vehiculos[j].getTipoVehiculo()<<" |";
					cout<<"    "<<v[i].vehiculos[j].getMarca()<<" |";
					cout<<" "<<v[i].vehiculos[j].getModelo()<<"|";
					cout<<"  $"<<v[i].vehiculos[j].getPrecio()<<"   |";
					cout<<" "<<v[i].comprador.mostrarNombre()<<" |";
					cout<<" "<<v[i].direccion<<" |";
					cout<<" "<<v[i].comprador.getTelefono()<<" |"<<endl;
				}
				cout<<"+--------------+---------------+---------------+----------------+------------+-------------------------+----------------------------+------------+"<<endl;
			}
		}
};
#endif
