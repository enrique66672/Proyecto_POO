#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
#include <iostream>
#include "Usuario.h"
#include "Venta.h"
#include "Vehiculo.h"
#define MAX 30

using namespace std;

class Administrador : private Usuario {
	private:
		string id, password;
		Venta venta[MAX];
	public:
		Administrador() : Usuario(){
			id = "";
			password = "";
		}

		void setId(string _id, string _nombre) {
			id = _id;
			setNombre(_nombre);
		}
		string getId() { return id; }

		void setPassword(string _contra) { password = _contra; }
		string getPassword() { return password;	}

		string mostrarNombre() { return getNombre(); }
		
		friend Vehiculo personalizarVehiculo();
};

// Vehiculo personalizarVehiculo() {
//     Vehiculo* automovil;
//     string respuesta;
//     Entrada entrada;
//     int res;
// 	cout<<"Personalizar Automovil"<<endl;
//     cout<<"1.- Clasico"<<endl;
//     cout<<"2.- Deportivo"<<endl;
//     cout<<"3.- Descapotable"<<endl;
//     cout<<"4.- Familiar"<<endl;
//     cout<<"5.- PickUp"<<endl;
//     cout<<"6.- Sedan"<<endl;
//     cout<<"Tipo de vehiculo a crear: "<<endl;
//     cin>>res;
//     switch (res) {
//     case 1:
//         automovil = new Clasico();
//         automovil->setTipoVehiculo("Clasico");
//         cout<<"1.- Ford"<<endl;
//         cout<<"2.- Chevrolet"<<endl;
//         cout<<"3.- Dodge"<<endl;
//         cout<<"4.- VolksWagen"<<endl;
//         cout<<"5.- Mercedes Benz"<<endl;
//         cout<<"Elija la marca: "<<endl;
//         cin>>entrada.entero;
//         switch (entrada.entero) {
//         case 1: 
//             automovil->setMarca("Ford");
//             cout<<"1.- Manual"<<endl;
//             cout<<"2.- Automatica"<<endl;
//             cout<<"Tipo de tranmision: "<<endl;
//             cin>>entrada.entero;
//             switch(entrada.entero) {
//                 case 1: automovil->setTransmision("Manual"); break;
//                 case 2: automovil->setTransmision("Automatica"); break;
//                 default: cout<<"Opcion no disponible"<<endl; break;
//             }

//             break;
//         case 2: automovil->setMarca("Chevrolet"); break;
//         case 3: automovil->setMarca("Dodge"); break;
//         case 4: automovil->setMarca("VolksWagen"); break;
//         case 5: automovil->setMarca("Mercedes Benz"); break;        
//         default: cout<<"Marca no disponible"<<endl; break;
//         }
//         break;
//     case 2:
//         automovil = new Deportivo();
//         automovil->setTipoVehiculo("Deportivo");
//         cout<<"1.- Porsche"<<endl;
//         cout<<"2.- Mazda"<<endl;
//         cout<<"3.- BMW"<<endl;
//         cout<<"4.- Honda"<<endl;
//         cout<<"5.- Mercedes Benz"<<endl;
//         cout<<"6.- Ford"<<endl;
//         cout<<"Elija la marca: "<<endl;
//         cin>>entrada.entero;
//         switch (entrada.entero) {
//         case 1: automovil->setMarca("Porsche"); break;
//         case 2: automovil->setMarca("Mazda"); break;
//         case 3: automovil->setMarca("BMW"); break;
//         case 4: automovil->setMarca("Honda"); break;
//         case 5: automovil->setMarca("Mercedes Benz"); break;
//         case 6: automovil->setMarca("Ford"); break;
//         default: cout<<"Marca no disponible"<<endl; break;
//         }
//         break;
//     case 3:
//         automovil = new Descapotable();
//         automovil->setTipoVehiculo("Descapotable");
//         cout<<"1.- Fiat"<<endl;
//         cout<<"2.- Mazda"<<endl;
//         cout<<"3.- VolksWagen"<<endl;
//         cout<<"4.- Ford"<<endl;
//         cout<<"5.- Lotus Elise"<<endl;
//         cout<<"6.- Audi"<<endl;
//         cout<<"Elija la marca: "<<endl;
//         cin>>entrada.entero;
//         switch (entrada.entero) {
//         case 1: automovil->setMarca("Fiat"); break;
//         case 2: automovil->setMarca("Mazda"); break;
//         case 3: automovil->setMarca("VolksWagen"); break;
//         case 4: automovil->setMarca("Ford"); break;
//         case 5: automovil->setMarca("Lotus Elise"); break;
//         case 6: automovil->setMarca("Audi"); break;
//         default: cout<<"Marca no disponible"<<endl; break;
//         }
//         break;
//     case 4:
//         automovil = new Familiar();
//         automovil->setTipoVehiculo("Familiar");
//         cout<<"1.- Seat"<<endl;
//         cout<<"2.- Subaru"<<endl;
//         cout<<"3.- Peugeot"<<endl;
//         cout<<"4.- Kia"<<endl;
//         cout<<"Elija la marca: "<<endl;
//         cin>>entrada.entero;
//         switch (entrada.entero) {
//         case 1: automovil->setMarca("Seat"); break;
//         case 2: automovil->setMarca("Subaru"); break;
//         case 3: automovil->setMarca("Peugout"); break;
//         case 4: automovil->setMarca("Kia"); break;
//         default: cout<<"Marca no disponible"<<endl; break;
//         }
//         break;
//     case 5:
//         automovil = new PicKup();
//         automovil->setTipoVehiculo("PickUp");
//         cout<<"1.- Chevrolet"<<endl;
//         cout<<"2.- Ford"<<endl;
//         cout<<"3.- Mitsubishi"<<endl;
//         cout<<"4.- Nissan"<<endl;
//         cout<<"5.- Toyota"<<endl;
//         cout<<"Elija la marca: "<<endl;
//         cin>>entrada.entero;
//         switch (entrada.entero) {
//         case 1: automovil->setMarca("Chevrolet"); break;
//         case 2: automovil->setMarca("Ford"); break;
//         case 3: automovil->setMarca("Mitsubishi"); break;
//         case 4: automovil->setMarca("Nissan"); break;
//         case 5: automovil->setMarca("Toyota"); break;
//         default: cout<<"Marca no disponible"<<endl; break;
//         }
//         break;
//     case 6:
//         automovil = new Sedan();
//         automovil->setTipoVehiculo("Sedan");
//         cout<<"1.- Chevrolet"<<endl;
//         cout<<"2.- Ford"<<endl;
//         cout<<"3.- Honda"<<endl;
//         cout<<"4.- Hyundai"<<endl;
//         cout<<"5.- Mazda"<<endl;
//         cout<<"6.- Nissan"<<endl;
//         cout<<"Elija la marca: "<<endl;
//         cin>>entrada.entero;
//         switch (entrada.entero) {
//         case 1: automovil->setMarca("Chevrolet"); break;
//         case 2: automovil->setMarca("Ford"); break;
//         case 3: automovil->setMarca("Honda"); break;
//         case 4: automovil->setMarca("Hyundai"); break;
//         case 5: automovil->setMarca("Mazda"); break;
//         case 6: automovil->setMarca("Nissan"); break;
//         default: cout<<"Marca no disponible"<<endl; break;
//         }
//     default:
//         cout<<"Opcion no disponible"<<endl;
//         break;
//     }
// }
#endif
