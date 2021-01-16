#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Comprador.h"
#include "Administrador.h"
#include "Venta.h"
#include "Clasico.h"
#include "Deportivo.h"
#include "Descapotable.h"
#include "Familiar.h"
#include "PickUp.h"
#include "Sedan.h"
#define ADMIN 3
#define COM 30
#define AUTOS 50
#define VEN 30

using namespace std;

Vehiculo personalizarVehiculo();


void comprasPredeterminadas(Venta[], int&);
void vehiculosStock(Vehiculo[], int&);
void mostrarStock(Vehiculo[], int&);
void menuEscogerAuto(Vehiculo[], int&, Comprador, Venta[], int&);
void superAdmin(Administrador&, int&);
int buscarAdministrador(Administrador[], int&);
void iniciarSesion(Administrador[], int&, Venta[], int&, Vehiculo[], int&, Vehiculo[], int&);
Administrador crearAdministrador();
void mostrarAdministradores(Administrador[], int&);
void menuSuperAdministrador(Administrador[], int&, Venta[], int&, Vehiculo[], int&);
void menuAdministradorNorm(Venta[], int&, Vehiculo[], int&, Vehiculo[], int&);
void menuComprador(Vehiculo[], Vehiculo[], int&, int&, Venta[], int&);
Comprador crearComprador();
Venta realizarCompra(Comprador&, Vehiculo[], int&, int&);

int main() {
    srand(time(NULL));
    Administrador* administradores = new Administrador[ADMIN];
    Comprador* compradores = new Comprador[COM];
    Vehiculo* vehiculos = new Vehiculo[AUTOS];
    Vehiculo* stock = new Vehiculo[AUTOS];
    Venta* ventas = new Venta[VEN];
    int respuesta;
    int nAdmin = 0, nAutos = 0, nVentas = 0, nStock = 0;
    
    superAdmin(administradores[nAdmin], nAdmin);
    vehiculosStock(stock, nStock);
    comprasPredeterminadas(ventas, nVentas);
	
    do{
        cout<<"\n\tMENU"<<endl;
        cout<<"1.- Administrador"<<endl;
        cout<<"2.- Comprador"<<endl;
        cout<<"3.- Salir"<<endl;
        cout<<"Como quieres ingresar: "<<endl;
        cin>>respuesta;

        switch (respuesta){
        case 1: // Administracion
            iniciarSesion(administradores, nAdmin, ventas, nVentas, vehiculos, nAutos, stock, nStock);            
            break;
        case 2: // Comprador
            menuComprador(vehiculos, stock, nAutos, nStock, ventas, nVentas);
            break;
        case 3: cout<<"Saliendo..."<<endl; break;        
        default: cout<<"Error"<<endl; break;
        }
    }
    while(respuesta != 3);
    return 0;
} //Fin del main

void comprasPredeterminadas(Venta ventas[], int&nVentas) {
	Vehiculo v[] = {
        Deportivo(5, "Manual", 15.4, "Monocasco de fibra", "ABS", "Trasera", "Independiente", 4, "Mazda", "Negro", 17, "Runflat", "MX-5 2020", 411000.00, "Deportivo", "V8", "Electrica", 3.9),
        Sedan(4, "Automatica", 19.3, "Espacial tabular", "ABS", "Trasera", "Eje rigido", 4, "Chevrolet", "Rojo", 18, "Runflat", "Aveo 2020", 209400.00, "Sedan", 366.5, 4),
        PicKup(6, "Automatica", 5, "De escalera", "Electronicos", "4x4", "McPherson", 4, "Toyota", "Dorado", 16, "Radial", "Tundra 2018", 500000.00, "PickUp", "Grande", "Amplia", 4, 980, 850, true ),
        Clasico(6, "Manual",9.45, "Monocasco", "Frenos de Tambor", "Traccion Delantera", "Suspencion Semirrigida", 4, "Dodge","Cafe Claro", 16, "Bajo Consumo", "Guayin 1981", 55000, "Clasico", "Vintage Post Gueraa", "Modificado", 2006),
        Descapotable(4,"Automatica", 12.5,  "McPherson", "Discos ventilados - Discos solidos", "total",  "Independiente", 4, "Audi", "Rojo", 12, "runflat", "A3 Cabrio 2020", 790900.0, "Descapotable", 4, "toldo de tela eletrico", "480.2" )
    };
    Comprador c[] = {
        Comprador("Juan Medina Valdez", "melval_3@gmail.com", 5521090368, "Contado"),
        Comprador("Alan Ramirez Lopez", "alopz2001@hotmail.com", 5561950700, "Credito"),
        Comprador("Martha Galvez Hernandez", "marthahrz54@gmail.com", 5561072507, "Contado"),
        Comprador("Camila Avila Perez", "camila205@hotmail.com", 5660394810, "Contado"),
        Comprador("Ivan Fernandez Mundo", "ivan_ferndz@gmail.com", 5595652501, "Credito")
    };
	Venta venta[] = {
		Venta(1, "Ricardo Flores Magon #43", 100508, 750000.0, v[0], c[0]),
        Venta(18, "Lomas iguanas #10", 100051, 350000.0, v[1], c[1]),
        Venta(1, "Colonia Centro #25", 100101, 800500.0, v[2], c[2]),
        Venta(24, "Rafael Vera de Cordoba #23", 100120, 550000.0, v[3], c[3]),
        Venta(36, "Calle las Hayas #17", 100100, 1250000.0, v[4], c[4])
	};
    for(int i = 0; i < 5; i++) {
        ventas[i] = venta[i];
        nVentas++;
    }
} 

void vehiculosStock(Vehiculo stock[], int&nStock) {
    Vehiculo autos[] = {
        Deportivo(4, "Manual", 15.4, "Monocasco de fibra", "ABS", "Trasera", "Independiente", 4, "Mazda", "Negro", 17, "Runflat", "MX-5 2020", 411000.00, "Deportivo", "V8", "Electrica", 3.9), 
        Deportivo(6, "Automatica", 17.9, "Monocasco de fibra","De carbono","Cuatro Ruedas", "Hidraulico", 2, "Mercedes", "Negro", 20, "Deportivas","AMG-GT 2018", 4000000.00, "Deportivo", "V12", "Electrohidraulica", 2.9),
        Deportivo(6, "Hibrida", 16.6, "Monocasco de fibra","De carbono","Trasera", "Aire", 4, "Ford", "Rojo", 20, "Deportivas","Mustang 2020", 1099900.00, "Deportivo", "V8", "Mecanica", 3.8),
        Deportivo(4, "Manual", 11.9, "Monocasco de fibra","De carbono","Delantera", "Hidraulico", 4, "Mercedes", "Gris", 20, "Deportivas","AMG-A-45 2017", 400000.00, "Deportivo", "V8", "Electrica", 4.2),
        Deportivo(6, "Automatica", 15.3, "Monocasco de fibra","De carbono","Cuatro Ruedas", "Hidraulico", 2, "Porsche", "Azul", 20, "Deportivas","911 Turbo 2018", 3478000.00, "Deportivo", "V12", "Electrohidraulica", 2.7),
        
        Sedan(4, "Automatica", 19.3, "Espacial tabular", "ABS", "Trasera", "Eje rigido", 4, "Chevrolet", "Rojo", 18, "Runflat", "Aveo 2020", 209400.00, "Sedan", 366.5, 4),
        Sedan(3, "Automatica", 15.7, "Escalar", "ABS", "Delantera", "Aire", 4, "Ford", "Rojo", 19, "Bajo perfil", "Figo 2020", 329000.00, "Sedan", 356.7, 4),
        Sedan(4, "Automatica", 18.3, "Monocasco", "ABS", "Trasera", "Hidraulica", 4, "Honda", "Rojo", 20, "All season", "Civic 2020", 358400.00, "Sedan", 480.2, 4),
        Sedan(4, "Automatica", 19.5, "Escalar", "ABS", "Trasera", "Eje rigido", 4, "Mazda", "Rojo", 18, "Runflat", "Mazda 2 Sedan 2020", 299400.00, "Sedan", 366.2, 4),
        Sedan(4, "Automatica", 16.8, "Espacial tabular", "ABS", "Delantera", "Eje rigido", 4, "Nissan", "Rojo", 18, "Runflat", "Aveo 2020", 209400.00, "Sedan", 369.8, 4),
        
        PicKup(4, "Automatica", 4.4, "Compacto", "Hidraulicos", "4x4", "Multilink", 4, "Ford", "Blanco", 14, "All seasons", "RAM700 2014", 445000.00, "PickUp", "Compacta", "Corta", 2, 1025, 82, true ),
        PicKup(6, "Automatica", 5, "Espacial tubular", "Hidraulicos", "4x4", "De doble horquilla", 4, "Chevrolet", "Gris Plata", 16, "Diagonal", "Tornado 2019", 600000.00, "PickUp", "Grande", "Amplia", 2, 1500, 90, false ),
        PicKup(4, "Manual", 5.26, "Monocasco", "Servofreno", "4x2", "Eje torsional", 2, "Nissan", "Rojo", 14, "Bajo rendimiento", "LT 2009", 245000.00, "PickUp", "Compacta", "Corta", 2, 750, 70, true ),
        PicKup(6, "Automatica", 5, "De escalera", "Electronicos", "4x4", "McPherson", 4, "Toyota", "Dorado", 16, "Radial", "Tundra 2018", 500000.00, "PickUp", "Grande", "Amplia", 4, 980, 850, true ),
        PicKup(6, "Automatica", 4, "Compacto", "Hidraulicos", "4x2", "De doble horquilla", 4, "MITSUBISHI", "Negro", 16, "Tubulares", "L200 2002", 438000.00, "PickUp", "Medio", "Amplia", 2, 1250, 69, false ),
        
        Clasico(4, "Manual",6.7, "Monocasco", "Frenos de Disco", "Traccion Trasera", "Suspencion Trasera", 2,"Volkswagen","Rojo", 15, "Bajo Consumo", "Volkswagen Sedan 1950", 200000, "Clasico", "Antiguo", "Restaurado", 2000),                                                        
        Clasico(8, "Manual",9.55, "Monocasco", "Frenos de Disco", "Traccion Trasera", "Suspencion Trasera", 4, "Ford","Negro", 17, "Radial", "Mustang 1966", 1070000, "Clasico", "Vintage Post Guerra", "Reconstruido", 1990),                                              
        Clasico(6, "Manual",8.73, "Monocasco ULSAB", "Frenos de Tambor", "Traccion Trasera", "Suspencion Eje Rigido", 2, "Chevrolet","Azul Marino", 16, "Diagonal", "Sedaneta 1953", 350000, "Clasico", "Antiguo", "Restaurado", 2005),                                                           
        Clasico(8, "Manual",11.45, "Espacial Tubular", "Frenos de Disco", "Traccion Trasera", "Suspencion Eje Rigido", 2, "Porsche","Amarillo", 14, "Runflat", "914 1972", 375000, "Clasico", "Antiguo", "Restaurado", 2011),                                                  
        Clasico(6, "Manual",9.45, "Monocasco", "Frenos de Tambor", "Traccion Delantera", "Suspencion Semirrigida", 4, "Dodge","Cafe Claro", 16, "Bajo Consumo", "Guayin 1981", 55000, "Clasico", "Vintage Post Gueraa", "Modificado", 2006),
        
        Familiar(4, "Manual", 15.5, "DOHC", "ABS", "Cuatro ruedas", "Manejo Suave",5, "Chevrolet", "Blanca", 16, "Bajo Consumo", "Trax 2021", 315600.0, "Familiar", 5, 424.7, 1606.0, "Electronico", "6 bolsas de aire" ),
        Familiar(4, "Automatica", 16.0, "Semirrigidas", "ABS", "Cuatro ruedas", "Manejo Suave",5, "Kia", "Rojo Rubi", 18, "Bajo Consumo", "Blazer 2021", 778200.8, "Familiar", 8, 450.95, 1803.3, "Electronico", "7 bolsas de aire" ),
        Familiar(6, "Manual", 14.5, "Rigido", "Disco/Tambor", "Trasera", "MacPherson",5, "Renault", "Rojo Rubi", 16, "Asimetricas", "Duster 2021", 291000.0, "Familiar", 5, 431.50, 1614.4, "Manual Estandar", "6 bolsas de aire" ),
        Familiar(4, "Manual", 17.5, "Rigida", "Disco/Tambor", "Trasera", "Manejo Suave",5, "Renault", "Negra", 17, "Bajo Consumo", "Captur 2021", 338700.0, "Familiar", 5, 447.20, 1712.3, "Manual Estandar", "6 bolsas de aire" ),
        Familiar(4, "Automatica", 14.5, "Semirrigida", "ABS", "Cuatro ruedas", "Manejo Suave",5, "Ford", "Azul Marino", 17, "Al seasons", "Expedition 2021", 1581000.0, "Familiar", 8, 457.20, 1812.3, "Electronico", "8 bolsas de aire" ),
        
        Descapotable(4,"Automatica", 12.5,  "McPherson", "Discos ventilados - Discos solidos", "total",  "Independiente", 4, "Audi", "Rojo", 12, "runflat", "A3 Cabrio 2020", 790900.0, "Descapotable", 4, "toldo de tela eletrico", "480.2" ),
        Descapotable(4,"Automatica", 13.2,  "Monocasco", "Disco ventilado", "trasera",  "Paralelogramo deformable", 2, "KTM", "Amarillo", 12, "asimetricas", "X-BOW Street 2011", 1664575.0, "Descapotable", 2, "toldo de tela eletrico", "350" ),
        Descapotable(4,"Automatica", 15.9,  "McPherson", "Discos ventilados ", "trasera",  "Resorte helicoidal", 2, "BMW", "Negro", 12, "runflat", "420i Cabrio 2018", 1189399.0, "Descapotable", 2, "toldo de tela eletrico", "300" ),
        Descapotable(4,"Automatica", 13.1,  "Monocasco", "Discos ventilados", "total",  "Independiente", 4, "VOLKSWAGEN", "Blanco", 12, "Asimetrica", "BEETLE CABRIO", 985000.0, "Descapotable", 4, "toldo de tela eletrico", "400" ),
        Descapotable(4,"Automatica", 12.0,  "Monocasco", "Discos ventilados", "traseros",  "Independiente", 4, "Ford", "Gris", 12, "all seasons","MUSTANG CONVERTIBLE", 850000.0, "Descapotable", 4, "toldo de tela eletrico", "420" )
    };
    
    for(int i = 0; i < 30; i++) {
        stock[i] = autos[i];
        nStock++;
    }
}

void mostrarStock(Vehiculo stock[], int&nStock) {
    cout << endl;
	cout << "	MARCA	|		MODELO		|	COLOR	|	TIPO DE VEHICULO	" << endl;
	cout << "	--------|-------------------------------|-------------------------------|---------------" << endl;
	
        for(int i = 0; i < nStock; i++) {
            cout << i  + 1 << "\t" << stock[i].getMarca() << "\t" << stock[i].getTipoVehiculo() << "\t" << stock[i].getModelo() << "\t" << stock[i].getColor() << "\t" << stock[i].getPrecio() << endl; 
        }
				
	cout << "	--------|-------------------------------|-------------------------------|---------------" << endl;
}

void menuEscogerAuto(Vehiculo stock[], int&nStock, Comprador comprador, Venta ventas[], int&nVentas) {
    int res;
	char option;
    string dato1;
    do {
		cout << endl << endl;
		cout << "Acciones:" << endl << endl;
		cout << "> Escoger vehiculo (e)" << endl;
		cout << "> Regresar al menu (x)" << endl <<endl;
		cout << "Ir a: ";
		cin >> option;
		
		switch(option) {
			case 'e':
				//Funcion escoger auto o algo asi
				cout << "¿Que carro deseas comprar?" << endl; cin >> res;
                ventas[nVentas].AgregarVehiculo(stock[res-1]);
                ventas[nVentas].setComprador(comprador);
                if(comprador.getPago() == "Credito"){
                    do {
                        cout<<"1.- 3 Pagos"<<endl;
                        cout<<"2.- 6 Pagos"<<endl;
                        cout<<"3.- 12 Pagos"<<endl;
                        cout<<"Ingrese el plan de pagos: "<<endl;
                        cin>>res;
                        switch(res) {
                            case 1: ventas[nVentas].setPlazo(3); break;
                            case 2: ventas[nVentas].setPlazo(6); break;
                            case 3: ventas[nVentas].setPlazo(12); break;
                            default:
                            res = 5;
                            cout<<"Opcion no disponible"<<endl;
                            break;
                        }
                    }
                    while(res == 5);
                }
                else ventas[nVentas].setPlazo(1);
                cin.ignore();
                cout<<"Ingrese su direccion: "<<endl;
                getline(cin, dato1);
                ventas[nVentas].setDireccion(dato1);
                ventas[nVentas].setFactura();
                ventas[nVentas].MostrarTicket();
                cout<<"Total: $"<<ventas[nVentas].operator + ()<<endl;
                nVentas++;
				break;
				
			default: 
				cout << "Opcion no disponible" <<endl;
				// option = 'x';
				break;
		}
		
	} while (option != 'x');
}

Vehiculo personalizarVehiculo() {
    Vehiculo* automovil ; 
    int res;
    do{
        cout<<"1.- Clasico"<<endl;
        cout<<"2.- Deportivo"<<endl;
        cout<<"3.- Descapotable"<<endl;
        cout<<"4.- Familiar"<<endl;
        cout<<"5.- PickUp"<<endl;
        cout<<"6.- Sedan"<<endl;
        cout<<"Tipo de vehiculo a crear: "<<endl;
        cin>>res;
        switch (res) {
        case 1:
            automovil = new Clasico();
            automovil->tipoVehiculo = "Clasico";
            do{
                cout<<"1.- Ford"<<endl;
                cout<<"2.- Chevrolet"<<endl;
                cout<<"3.- Dodge"<<endl;
                cout<<"4.- VolksWagen"<<endl;
                cout<<"5.- Mercedes Benz"<<endl;
                cout<<"Elija la marca: "<<endl;
                cin>>res;
                switch (res) {
                case 1: 
                    automovil->marca = "Ford";
                    automovil->setTransmision();
                    automovil->setFrenos();
                    automovil->setTraccion();
                    automovil->setColor();
                    automovil->setRin();
                    automovil->setLlanta();
                    automovil->setPrecio();
                    automovil->setNumeroSerie();
                    break;
                case 2: 
                    automovil->marca = "Chevrolet"; 
                    automovil->setTransmision();
                    automovil->setFrenos();
                    automovil->setTraccion();
                    automovil->setColor();
                    automovil->setRin();
                    automovil->setLlanta();
                    automovil->setPrecio();
                    automovil->setNumeroSerie();
                    break;
                case 3: 
                    automovil->marca = "Dodge"; 
                    automovil->setTransmision();
                    automovil->setFrenos();
                    automovil->setTraccion();
                    automovil->setColor();
                    automovil->setRin();
                    automovil->setLlanta();
                    automovil->setPrecio();
                    automovil->setNumeroSerie();
                    break;
                case 4: 
                    automovil->marca = "VolksWagen";
                    automovil->setTransmision(); 
                    automovil->setFrenos();
                    automovil->setTraccion();
                    automovil->setColor();
                    automovil->setRin();
                    automovil->setLlanta();
                    automovil->setPrecio();
                    automovil->setNumeroSerie();
                    break;
                case 5: 
                    automovil->marca = "Mercedes Benz"; 
                    automovil->setTransmision();
                    automovil->setFrenos();
                    automovil->setTraccion();
                    automovil->setColor();
                    automovil->setRin();
                    automovil->setLlanta();
                    automovil->setPrecio();
                    automovil->setNumeroSerie();
                    break;  
                default: 
                    res = 0;
                    cout<<"Marca no disponible"<<endl; 
                    break;
                }
            }
            while(res == 0);
            break;

        case 2:
            Deportivo* dep;
            automovil = new Deportivo();
            automovil->tipoVehiculo = "Deportivo";

            do{
                cout<<"1.- Porsche"<<endl;
                cout<<"2.- Mazda"<<endl;
                cout<<"3.- BMW"<<endl;
                cout<<"4.- Honda"<<endl;
                cout<<"5.- Mercedes Benz"<<endl;
                cout<<"6.- Ford"<<endl;
                cout<<"Elija la marca: "<<endl;
                cin>>res;
    
                switch (res) {
                case 1: 
                    automovil->marca = "Porsche";
	    	  	    automovil->setTransmision();
                    automovil->setFrenos();
                    automovil->setTraccion();
                    automovil->setColor();
                    automovil->setRin();
                    automovil->setLlanta();
                    automovil->setPrecio();
                    automovil->setNumeroSerie();
                    dep = (Deportivo*)automovil;
                    dep->setMotor();
                    dep->setDireccion();
                    dep->setAceleracion();
                    automovil = (Vehiculo*)dep;
	    	  	    break;
                case 2: 
                    automovil->marca = "Mazda";
                	automovil->setTransmision();
                    automovil->setFrenos();
                    automovil->setTraccion();
                    automovil->setColor();
                    automovil->setRin();
                    automovil->setLlanta();
                    automovil->setPrecio();
                    automovil->setNumeroSerie();
                    dep = (Deportivo*)automovil;
                    dep->setMotor();
                    dep->setDireccion();
                    dep->setAceleracion();
                    automovil = (Vehiculo*)dep;
	    	  	    break;
                case 3: 
                    automovil->marca = "BMW";
                	automovil->setTransmision();
                    automovil->setFrenos();
                	automovil->setTraccion();
                    automovil->setColor();
                    automovil->setRin();
                    automovil->setLlanta();
                    automovil->setPrecio();
                    automovil->setNumeroSerie();
                    dep = (Deportivo*)automovil;
                    dep->setMotor();
                    dep->setDireccion();
                    dep->setAceleracion();
                    automovil = (Vehiculo*)dep;
	    	  	    break;
                case 4: 
                    automovil->marca = "Honda";
        	   	    automovil->setTransmision();
                	automovil->setFrenos();
                	automovil->setTraccion();
                    automovil->setColor();
                    automovil->setRin();
                    automovil->setLlanta();
                    automovil->setPrecio();
                    automovil->setNumeroSerie();
                    dep = (Deportivo*)automovil;
                    dep->setMotor();
                    dep->setDireccion();
                    dep->setAceleracion();
                    automovil = (Vehiculo*)dep;
	    	  	    break;
                case 5: 
                    automovil->marca = "Mercedes Benz";
	    	  	    automovil->setTransmision();
                	automovil->setFrenos();
                	automovil->setTraccion();
                    automovil->setColor();
                    automovil->setRin();
                    automovil->setLlanta();
                    automovil->setPrecio();
                    automovil->setNumeroSerie();
                    dep = (Deportivo*)automovil;
                    dep->setMotor();
                    dep->setDireccion();
                    dep->setAceleracion();
                    automovil = (Vehiculo*)dep;
	    	  	    break;
                case 6: 
                    automovil->marca = "Ford";
	    	  	    automovil->setTransmision();
                    automovil->setFrenos();
                    automovil->setTraccion();
                    automovil->setColor();
                    automovil->setRin();
                    automovil->setLlanta(); 
                    automovil->setPrecio();
                    automovil->setNumeroSerie();
                    dep = (Deportivo*)automovil;
                    dep->setMotor();
                    dep->setDireccion();
                    dep->setAceleracion();
                    automovil = (Vehiculo*)dep;
	    	  	    break;
                default: 
                    res = 0; 
                    cout<<"Marca no disponible"<<endl; 
                    break;
                }
            }
            while(res == 0);
            break;

        case 3:
            Descapotable* des;
            automovil = new Descapotable();
            automovil->tipoVehiculo = "Descapotable";
            do{
                cout<<"1.- Fiat"<<endl;
                cout<<"2.- Mazda"<<endl;
                cout<<"3.- VolksWagen"<<endl;
                cout<<"4.- Ford"<<endl;
                cout<<"5.- Lotus Elise"<<endl;
                cout<<"6.- Audi"<<endl;
                cout<<"Elija la marca: "<<endl;
                cin>>res;
                switch (res) {
                case 1: 
                    automovil->marca = "Fiat"; 
                    automovil->setTransmision();
                    automovil->setFrenos();
                    automovil->setTraccion();
                    automovil->setColor();
                    automovil->setRin();
                    automovil->setLlanta();
                    automovil->setPrecio();
                    automovil->setNumeroSerie();
                    des = (Descapotable*)automovil;
                    des->setCapo();
                    des->setMaletero();
                    automovil = (Vehiculo*)des;
                    break;
                case 2: 
                    automovil->marca = "Mazda"; 
                    automovil->setTransmision();
                    automovil->setFrenos();
                    automovil->setTraccion();
                    automovil->setColor();
                    automovil->setRin();
                    automovil->setLlanta();
                    automovil->setPrecio();
                    automovil->setNumeroSerie();
                    des = (Descapotable*)automovil;
                    des->setCapo();
                    des->setMaletero();
                    automovil = (Vehiculo*)des;
                    break;
                case 3: 
                    automovil->marca = "VolksWagen";
                    automovil->setTransmision();
                    automovil->setFrenos();
                    automovil->setTraccion();
                    automovil->setColor();
                    automovil->setRin();
                    automovil->setLlanta();
                    automovil->setPrecio();
                    automovil->setNumeroSerie();
                    des = (Descapotable*)automovil;
                    des->setCapo();
                    des->setMaletero();
                    automovil = (Vehiculo*)des;
                    break;
                case 4: 
                    automovil->marca = "Ford";
                    automovil->setTransmision();
                    automovil->setFrenos();
                    automovil->setTraccion();
                    automovil->setColor();
                    automovil->setRin();
                    automovil->setLlanta();
                    automovil->setPrecio();
                    automovil->setNumeroSerie();
                    des = (Descapotable*)automovil;
                    des->setCapo();
                    des->setMaletero();
                    automovil = (Vehiculo*)des;
                    break;
                case 5: 
                    automovil->marca = "Lotus Elise";
                    automovil->setTransmision();
                    automovil->setFrenos();
                    automovil->setTraccion();
                    automovil->setColor();
                    automovil->setRin();
                    automovil->setLlanta();
                    automovil->setPrecio();
                    automovil->setNumeroSerie();
                    des = (Descapotable*)automovil;
                    des->setCapo();
                    des->setMaletero();
                    automovil = (Vehiculo*)des;
                    break;
                case 6: 
                    automovil->marca = "Audi";
                    automovil->setTransmision();
                    automovil->setFrenos();
                    automovil->setTraccion();
                    automovil->setColor();
                    automovil->setRin();
                    automovil->setLlanta();
                    automovil->setPrecio();
                    automovil->setNumeroSerie();
                    des = (Descapotable*)automovil;
                    des->setCapo();
                    des->setMaletero();
                    automovil = (Vehiculo*)des;
                    break;
                default: 
                    res = 0;
                    cout<<"Marca no disponible"<<endl; 
                    break;
                }
            }
            while(res == 0);
            break;

        case 4:
            Familiar* fam;
            automovil = new Familiar();
            automovil->tipoVehiculo = "Familiar";
            
            do{
                cout<<"1.- Seat"<<endl;
                cout<<"2.- Subaru"<<endl;
                cout<<"3.- Peugeot"<<endl;
                cout<<"4.- Kia"<<endl;
                cout<<"Elija la marca: "<<endl;
                cin>>res;
                switch (res) {
                case 1: 
                    automovil->marca = "Seat";
                    automovil->setTransmision();
	    	  	    automovil->setFrenos();
                	automovil->setTraccion();
                	automovil->setColor();
                    automovil->setRin();
                    automovil->setLlanta();
                    automovil->setPrecio();
                    automovil->setNumeroSerie();
                    fam = (Familiar*)automovil;
                    fam->setNPasajeros();
                    fam->setDimensiones();
                    fam->setCapacidadCarga();
                    fam->setTipoEncendido();
                    fam->setSeguridad();
                    automovil = (Vehiculo*)fam;
                    break;
                case 2:
                    automovil->marca = "Subaru";
                    automovil->setTransmision();
        	   	    automovil->setFrenos();
                	automovil->setTraccion();
                	automovil->setColor();
                    automovil->setRin();
                    automovil->setLlanta();
                    automovil->setPrecio();
                    automovil->setNumeroSerie();
                    fam = (Familiar*)automovil;
                    fam->setNPasajeros();
                    fam->setDimensiones();
                    fam->setCapacidadCarga();
                    fam->setTipoEncendido();
                    fam->setSeguridad();
                    automovil = (Vehiculo*)fam;
                    break;
                case 3: 
                    automovil->marca = "Peugout";
	    	  	    automovil->setTransmision();
                    automovil->setFrenos();
                    automovil->setTraccion();
                    automovil->setColor();
                    automovil->setRin();
                    automovil->setLlanta();
                    automovil->setPrecio();
                    automovil->setNumeroSerie();
                    fam = (Familiar*)automovil;
                    fam->setNPasajeros();
                    fam->setDimensiones();
                    fam->setCapacidadCarga();
                    fam->setTipoEncendido();
                    fam->setSeguridad();
                    automovil = (Vehiculo*)fam;
                    break;
                case 4: 
                    automovil->marca = "Kia";
	    	  	    automovil->setTransmision();
                    automovil->setFrenos();
                    automovil->setTraccion();
                    automovil->setColor();
                    automovil->setRin();
                    automovil->setLlanta();
                    automovil->setPrecio();
                    automovil->setNumeroSerie();
                    fam = (Familiar*)automovil;
                    fam->setNPasajeros();
                    fam->setDimensiones();
                    fam->setCapacidadCarga();
                    fam->setTipoEncendido();
                    fam->setSeguridad();
                    automovil = (Vehiculo*)fam;
                    break;
                default: 
                    res = 0;
                    cout<<"Marca no disponible"<<endl; 
                    break;
                }
            }
            while(res == 0);
            break;

        case 5:
            PicKup* pic;
            automovil = new PicKup();
            automovil->tipoVehiculo = "PickUp";
            do{
                cout<<"1.- Chevrolet"<<endl;
                cout<<"2.- Ford"<<endl;
                cout<<"3.- Mitsubishi"<<endl;
                cout<<"4.- Nissan"<<endl;
                cout<<"5.- Toyota"<<endl;
                cout<<"Elija la marca: "<<endl;
                cin>>res;
                switch (res) {
                case 1: 
                    automovil->marca = "Chevrolet";
	    	  	    automovil->setTransmision();
                    automovil->setFrenos();
                    automovil->setTraccion();
                    automovil->setColor();
                    automovil->setRin();
                    automovil->setLlanta();
                    automovil->setPrecio();
                    automovil->setNumeroSerie();
                    pic = (PicKup*)automovil;
                    pic->setTamano();
                    pic->setCabinas();
                    pic->setPuertaDeCarga();
                    pic->setTipoCaja();
                    pic->setCapacidadDeCarga();
                    pic->SetLongCaja();
                    automovil = (Vehiculo*)pic;
	    	  	    break;
                case 2: 
                    automovil->marca = "Ford";
	    	  	    automovil->setTransmision();
                    automovil->setFrenos();
                    automovil->setTraccion();
                    automovil->setColor();
                    automovil->setRin();
                    automovil->setLlanta();
                    automovil->setPrecio();
                    automovil->setNumeroSerie();
                    pic = (PicKup*)automovil;
                    pic->setTamano();
                    pic->setCabinas();
                    pic->setPuertaDeCarga();
                    pic->setTipoCaja();
                    pic->setCapacidadDeCarga();
                    pic->SetLongCaja();
                    automovil = (Vehiculo*)pic;
	    	  	    break;
                case 3: 
                    automovil->marca = "Mitsubishi";
	    	  	    automovil->setTransmision();
                    automovil->setFrenos();
                    automovil->setTraccion();
                    automovil->setColor();
                    automovil->setRin();
                    automovil->setLlanta();
                    automovil->setPrecio();
                    automovil->setNumeroSerie();
                    pic = (PicKup*)automovil;
                    pic->setTamano();
                    pic->setCabinas();
                    pic->setPuertaDeCarga();
                    pic->setTipoCaja();
                    pic->setCapacidadDeCarga();
                    pic->SetLongCaja();
                    automovil = (Vehiculo*)pic;
	    	  	    break;
                case 4: 
                    automovil->marca = "Nissan";
	    	  	    automovil->setTransmision();
                    automovil->setFrenos();
                    automovil->setTraccion();
                    automovil->setColor();
                    automovil->setRin();
                    automovil->setLlanta();
                    automovil->setPrecio();
                    automovil->setNumeroSerie();
                    pic = (PicKup*)automovil;
                    pic->setTamano();
                    pic->setCabinas();
                    pic->setPuertaDeCarga();
                    pic->setTipoCaja();
                    pic->setCapacidadDeCarga();
                    pic->SetLongCaja();
                    automovil = (Vehiculo*)pic;
	    	  	    break;
                case 5: 
                    automovil->marca = "Toyota";
	    	  	    automovil->setTransmision();
                    automovil->setFrenos();
                    automovil->setTraccion();
                    automovil->setColor();
                    automovil->setRin();
                    automovil->setLlanta();
                    automovil->setPrecio();
                    automovil->setNumeroSerie();
                    pic = (PicKup*)automovil;
                    pic->setTamano();
                    pic->setCabinas();
                    pic->setPuertaDeCarga();
                    pic->setTipoCaja();
                    pic->setCapacidadDeCarga();
                    pic->SetLongCaja();
                    automovil = (Vehiculo*)pic;
	    	  	    break;
                default: 
                    res = 0;
                    cout<<"Marca no disponible"<<endl; 
                    break;
                }
            }
            while(res == 0);
            break;

        case 6:
            Sedan* sed;
            automovil = new Sedan();
            automovil->tipoVehiculo = "Sedan";

            do{
                cout<<"1.- Chevrolet"<<endl;
                cout<<"2.- Ford"<<endl;
                cout<<"3.- Honda"<<endl;
                cout<<"4.- Hyundai"<<endl;
                cout<<"5.- Mazda"<<endl;
                cout<<"6.- Nissan"<<endl;
                cout<<"Elija la marca: "<<endl;
                cin>>res;
                switch (res) {
                case 1: 
                    automovil->marca = "Chevrolet";
	    	  	    automovil->setTransmision();
                    automovil->setFrenos();
                    automovil->setTraccion();
                    automovil->setColor();
                    automovil->setRin();
                    automovil->setLlanta();
                    automovil->setPrecio();
                    automovil->setNumeroSerie();
                    sed = (Sedan*)automovil;
                    sed->setMaletero();
                    automovil = (Vehiculo*)sed;
	    	  	    break;
                case 2: 
                    automovil->marca = "Ford";
	    	  	    automovil->setTransmision();
                    automovil->setFrenos();
                    automovil->setTraccion();
                    automovil->setColor();
                    automovil->setRin();
                    automovil->setLlanta();
                    automovil->setPrecio();
                    automovil->setNumeroSerie();
                    sed = (Sedan*)automovil;
                    sed->setMaletero();
                    automovil = (Vehiculo*)sed; 
	    	  	    break;
                case 3: 
                    automovil->marca = "Honda";
	    	  	    automovil->setTransmision();
                    automovil->setFrenos();
                    automovil->setTraccion();
                    automovil->setColor();
                    automovil->setRin();
                    automovil->setLlanta();
                    automovil->setPrecio();
                    automovil->setNumeroSerie();
                    sed = (Sedan*)automovil;
                    sed->setMaletero();
                    automovil = (Vehiculo*)sed; 
	    	  	    break;
                case 4: 
                    automovil->marca = "Hyundai";
	    	  	    automovil->setTransmision();
                    automovil->setFrenos();
                    automovil->setTraccion();
                    automovil->setColor();
                    automovil->setRin();
                    automovil->setLlanta();
                    automovil->setPrecio();
                    automovil->setNumeroSerie();
                    sed = (Sedan*)automovil;
                    sed->setMaletero();
                    automovil = (Vehiculo*)sed;
	    	  	    break;
                case 5: 
                    automovil->marca = "Mazda";
	    	  	    automovil->setTransmision();
                    automovil->setFrenos();
                    automovil->setTraccion();
                    automovil->setColor();
                    automovil->setRin();
                    automovil->setLlanta();
                    automovil->setPrecio();
                    automovil->setNumeroSerie();
                    sed = (Sedan*)automovil;
                    sed->setMaletero();
                    automovil = (Vehiculo*)sed;
	    	  	    break;
                case 6: 
                    automovil->marca = "Nissan"; 
	    	  	    automovil->setTransmision();
                    automovil->setFrenos();
                    automovil->setTraccion();
                    automovil->setColor();
                    automovil->setRin();
                    automovil->setLlanta();
                    automovil->setPrecio();
                    automovil->setNumeroSerie();
                    sed = (Sedan*)automovil;
                    sed->setMaletero();
                    automovil = (Vehiculo*)sed;
	    	  	    break;
                default: 
                    res = 0;
                    cout<<"Marca no disponible"<<endl; 
                    break;
                }
            }
            while(res == 0);
            break; //<-
        default:
            res = 0;
            cout<<"Opcion no disponible"<<endl;
            break;
        }
    }
    while(res == 0);
    return *automovil;
}

void superAdmin(Administrador&admin, int&nAdmin) {
    admin.setId("ad0001", "Administrador");
    admin.setPassword("admin1234");
    nAdmin++;
}

int buscarAdministrador(Administrador admin[], int&nAdmin){
    string nom;
    int indice = -1;
    bool encontrado = false;
    cout<<"Ingrese el nombre: "<<endl;
    getline(cin, nom);

    for(int i = 0; i <= nAdmin; i++) {
        if(nom == admin[i].mostrarNombre()) {
            encontrado = true;
            indice = i;
        }
    }
    if(!encontrado) cout<<"No existe un administrador con el nombre "<<nom<<endl;
    
    return indice;
}

void iniciarSesion(Administrador admin[], int&nAdmin, Venta v[], int&nVentas, Vehiculo automovil[], int&nAutos, Vehiculo stock[], int&nStock) {
    string datos1, datos2;
    int indice = -1, res;
    cin.ignore();
    indice = buscarAdministrador(admin, nAdmin);

    if(indice != -1) {
        cout<<"Ingrese Id: "<<endl;
        getline(cin, datos1);
        cout<<"Ingrese contrasena: "<<endl;
        getline(cin, datos2);

        if((indice == 0) && (datos1 == admin[indice].getId()) && (datos2 == admin[indice].getPassword())) {
            cout<<"Acceso como Super Administrador"<<endl;
            menuSuperAdministrador(admin, nAdmin, v, nVentas, automovil, nAutos);
        }
        else if((datos1 == admin[indice].getId()) && (datos2 == admin[indice].getPassword())) {
            cout<<"Acceso consedido"<<endl;
            menuAdministradorNorm(v, nVentas, automovil, nAutos, stock, nStock);
        }
        else{
            cout<<"Acceso denegado"<<endl;
        }
    }
}

Administrador crearAdministrador() {
    Administrador a;
    int res;
    string datos1, datos2;
    cin.ignore();

    do {
        cout<<"Ingrese su nombre: "<<endl;
        getline(cin, datos1);
        cout<<"Ingrese id: "<<endl;
        getline(cin, datos2);
        a.setId(datos2, datos1);
        cout<<"Ingrese su contrasena: "<<endl;
        getline(cin, datos1);
        a.setPassword(datos1);
        cout<<"Nombre: "<<a.mostrarNombre()<<"\nId: "<<a.getId()<<"\nContrasena: "<<a.getPassword()<<endl;
        cout<<"La informacion es correcta: (1 = Si, 0 = No)"<<endl;
        cin>>res;
    }
    while(res != 1);

    return a;
}

void mostrarAdministradores(Administrador admin[], int&nAdmin) {
    if(nAdmin > 0) {
        for(int i = 1; i < nAdmin; i++) {
            cout<<"Nombre: "<<admin[i].mostrarNombre()<<endl;
            cout<<"Id: "<<admin[i].getId()<<endl;
        }
    }
}

void menuSuperAdministrador(Administrador admin[], int&nAdmin, Venta v[], int&nVentas, Vehiculo automovil[], int&nAutos){
    int res;
    do{
        cout<<"\n\nOpciones de super administrador"<<endl;
        cout<<"1.- Agregar un administrador"<<endl;
        cout<<"2.- Mostrar los administradores"<<endl;
        cout<<"3.- Crear automoviles para stock"<<endl;
        cout<<"4.- Visualizar venta"<<endl;
        cout<<"5.- Visualizar ventas"<<endl;
        cout<<"6.- Mostrar total vendido"<<endl;
        cout<<"7.- Regresar al menu principal"<<endl;
        cout<<"Ingrese respuesta"<<endl;
        cin>>res;

        switch(res) {
            case 1:
                admin[nAdmin] = crearAdministrador();
                nAdmin++;
                cout<<"Administrador creado"<<endl;
                break;
            case 2:
                mostrarAdministradores(admin, nAdmin);
                break;
            case 3: 
                automovil[nAutos] = personalizarVehiculo();
                nAutos++;
                break;
            case 4: v[0].BuscarVentas(v); break;
            case 5: v[0].MostrarVentas(v , nVentas); break;
            case 6: cout << "Total de ventas: " << +v << endl; break;
            case 7: break;
            default: cout<<"Opcion no establecida"<<endl; break;
        }
    }
    while(res != 7);
}

void menuAdministradorNorm(Venta v[], int&nVentas, Vehiculo automovil[], int&nAutos, Vehiculo stock[], int&nStock){
    int res;

    do{
        cout<<"Opciones de administrador"<<endl;
        cout<<"1.- Visualizar ventas"<<endl;
        cout<<"2.- Visualizar una venta"<<endl;
        cout<<"3.- Mostrar Vehiculos existente"<<endl;
        cout<<"4.- Mostrar total vendido"<<endl;
        cout<<"5.- Regresar al inicio"<<endl;
        cout<<"Ingrese respuesta"<<endl;
        cin>>res;
        switch(res) {
            case 1:
                v[0].MostrarVentas(v , nVentas);
                break;
            case 2:
                v[0].BuscarVentas(v);
                break;
            case 3: 
                mostrarStock(stock, nStock);
                break;
            case 4:
                cout << "Total de ventas: " << +v << endl; // Revisar si se puede mejorar
                break;
            case 5: break;
            default: cout<<"Opcion no establecida"<<endl; break;
        }
    }
    while(res != 5);
}

void menuComprador(Vehiculo automovil[], Vehiculo stock[], int&nAutos, int&nStock, Venta venta[], int&nVentas) {
	Comprador comp;
    int contCom = 0;
    comp = crearComprador();
    char resp;
	do {
		cout << "\t>>>> BIENVENIDO <<<<" << endl << endl;
		cout << "Acciones:" << endl << endl;
		cout << "> Ando viendo gracias (y)" << endl;
		cout << "> Personalizar vehiculo (d)" << endl;
		cout << "> Salir (g)" << endl <<endl;
		cout << "Ir a: ";
		cin >> resp;
		
		switch(resp) {
			case 'y'://Visualizar catalogo 
				cout << "\t>>>>Vehiculos en stock<<<<" << endl << endl;
				mostrarStock(stock, nStock);
                menuEscogerAuto(stock, nStock, comp, venta, nVentas);
				break;
			case 'd': //Poner lo de personalizar7
                cout<<"Personalizar el Vehiculo"<<endl;
     	        automovil[nAutos] = personalizarVehiculo();
                nAutos++;
                contCom++;
                
                do{
                    cout<<"Deseas agregar al carrito (Si) = y, (No) = n "<<endl;
                    cin>>resp;
                    if(resp == 'n') {
                        venta[nVentas] = realizarCompra(comp, automovil, nAutos, contCom); //Cambiar objeto por arreglo de objetos
                        nVentas++;
                    }
                    else if(resp == 'y') {
                        automovil[nAutos] = personalizarVehiculo();
                        nAutos++;
                        contCom++;
                    }
                    else resp = 'c';
                }
                while(resp == 'y');
				break;
			default: 
				cout << "Regresando al menu" <<endl;
				resp = 'g';
				break;
		}
	} while (resp != 'g');
}

Comprador crearComprador() {
    Comprador c;
    string dato1, dato2;
    int res;
    long long tel;
    cin.ignore();
    cout<<"Ingrese su nombre: "<<endl;
    getline(cin, dato1);
    cout<<"Ingrese su correo: "<<endl;
    getline(cin, dato2);
    c.setCorreo(dato2, dato1);
    do{
        cout<<"1.- Credito"<<endl;
        cout<<"2.- Contado"<<endl;
        cout<<"Ingrese su forma de pago: "<<endl;
        cin>>res;
        switch(res){
            case 1: c.setPago("Credito"); break;
            case 2: c.setPago("Contado"); break;
            default: res = 3; cout<<"Opcion no disponible"<<endl; break;
        }
    }
    while(res == 3);
    cout<<"Ingrese su telefono: "<<endl;
    cin>>tel;
    c.setTelefono(tel);

    return c;
}

Venta realizarCompra(Comprador&comp, Vehiculo vehiculo[], int&nAutos, int&contCom) {
    Venta v;
    int res;
    string dato1;

    v.setComprador(comp);
    if(comp.getPago() == "Credito"){
        do {
            cout<<"1.- 3 Pagos"<<endl;
            cout<<"2.- 6 Pagos"<<endl;
            cout<<"3.- 12 Pagos"<<endl;
            cout<<"Ingrese el plan de pagos: "<<endl;
            cin>>res;
            switch(res) {
                case 1: v.setPlazo(3); break;
                case 2: v.setPlazo(6); break;
                case 3: v.setPlazo(12); break;
                default:
                res = 5;
                cout<<"Opcion no disponible"<<endl;
                break;
            }
        }
        while(res == 5);
    }
    else v.setPlazo(1);
    cin.ignore();
    cout<<"Ingrese su dirección: "<<endl;
    getline(cin, dato1);
    v.setDireccion(dato1);
    v.setFactura();
    for(int i = (nAutos - contCom); i < nAutos; i++) v.AgregarVehiculo(vehiculo[i]);
    v.MostrarTicket();
    cout<<"Total de compra es: $"<<+v<<endl;
    
    return v;
}
