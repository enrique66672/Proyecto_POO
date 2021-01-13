#include <iostream>
#include "Comprador.h"
#include "Administrador.h"
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

union Entrada {
    int entero;
    float flotante;
    double doble;
    long long numero;
    bool res;
};

Vehiculo personalizarVehiculo();
void escogerTransmision(Vehiculo&);
void escogerFrenos(Vehiculo&);
void escogerTraccion(Vehiculo&);
void escogerColor(Vehiculo&);
void escogerRines(Vehiculo&);
void escogerLlantas(Vehiculo&);

void iniciarCompra(void);
void vehiculosStock(Vehiculo[], int&);
void mostrarStock(Vehiculo[], int&);
void superAdmin(Administrador&, int&);
int buscarAdministrador(Administrador[], int&);
void iniciarSesion(Administrador[], int&, Venta[], int&, Vehiculo[], int&);
Administrador crearAdministrador();
void mostrarAdministradores(Administrador[], int&);
void menuSuperAdministrador(Administrador[], int&, Venta[], int&, Vehiculo[], int&);
void menuAdministradorNorm(Venta[], int&, Vehiculo[], int&);
void menuComprador(Vehiculo[], Vehiculo[], int&, int&, Venta[], int&);
Comprador crearComprador();
Venta realizarCompra(Comprador&, Vehiculo[], int&, int&);

int main() {
    Administrador* administradores = new Administrador[ADMIN];
    Comprador* compradores = new Comprador[COM];
    Vehiculo* vehiculos = new Vehiculo[AUTOS];
    Vehiculo* stock = new Vehiculo[AUTOS];
    Venta* ventas = new Venta[VEN];
    int respuesta, r;
    int nAdmin = 0, nAutos = 0, nVentas = 0, nStock = 0;
    string datos1, datos2;
    char option;
    
    superAdmin(administradores[nAdmin], nAdmin);
    vehiculosStock(stock, nStock);
	
    do{
        cout<<"\t\nMENU"<<endl;
        cout<<"1.- Administrador"<<endl;
        cout<<"2.- Comprador"<<endl;
        cout<<"3.- Salir"<<endl;
        cout<<"Como quieres ingresar: "<<endl;
        cin>>respuesta;

        switch (respuesta){
        case 1: // Administracion
            iniciarSesion(administradores, nAdmin, ventas, nVentas, vehiculos, nAutos);            
            break;
        case 2: // Comprador
            menuComprador(vehiculos, stock, nAutos, nStock, ventas, nVentas);
            break;
        case 3:
            cout<<"Saliendo..."<<endl;
            break;        
        default:
            cout<<"Error"<<endl;
            break;
        }
    }
    while(respuesta != 3);
    return 0;
} //Fin del main

void iniciarCompra() {
	Vehiculo* v = new Deportivo(5, "Manual", 15.4, "Monocasco de fibra", "ABS", "Trasera", "Independiente", 4, "Mazda", "Negro", 17, "Runflat", "MX-5 2020", 411000.00, "Deportivo", "V8", "Electrica", 3.9);
	Venta* venta[] = {
		new Venta(18,"ESIME CULHUACAN", 654988, 3500000,*v)
	};
	
} 

void vehiculosStock(Vehiculo stock[], int&nStock) {
    Vehiculo* autos[30] = {
        new Deportivo(4, "Manual", 15.4, "Monocasco de fibra", "ABS", "Trasera", "Independiente", 4, "Mazda", "Negro", 17, "Runflat", "MX-5 2020", 411000.00, "Deportivo", "V8", "Electrica", 3.9), 
        new Deportivo(6, "Automatica", 17.9, "Monocasco de fibra","De carbono","Cuatro Ruedas", "Hidraulico", 2, "Mercedes", "Negro", 20, "Deportivas","AMG-GT 2018", 4000000.00, "Deportivo", "V12", "Electrohidraulica", 2.9),
        new Deportivo(6, "Hibrida", 16.6, "Monocasco de fibra","De carbono","Trasera", "Aire", 4, "Ford", "Rojo", 20, "Deportivas","Mustang 2020", 1099900.00, "Deportivo", "V8", "Mecanica", 3.8),
        new Deportivo(4, "Manual", 11.9, "Monocasco de fibra","De carbono","Delantera", "Hidraulico", 4, "Mercedes", "Gris", 20, "Deportivas","AMG-A-45 2017", 400000.00, "Deportivo", "V8", "Electrica", 4.2),
        new Deportivo(6, "Automatica", 15.3, "Monocasco de fibra","De carbono","Cuatro Ruedas", "Hidraulico", 2, "Porsche", "Azul", 20, "Deportivas","911 Turbo 2018", 3478000.00, "Deportivo", "V12", "Electrohidraulica", 2.7),
        
        new Sedan(4, "Automatica", 19.3, "Espacial tabular", "ABS", "Trasera", "Eje rigido", 4, "Chevrolet", "Rojo", 18, "Runflat", "Aveo 2020", 209400.00, "Sedan", 366.5, 4),
        new Sedan(3, "Automatica", 15.7, "Escalar", "ABS", "Delantera", "Aire", 4, "Ford", "Rojo", 19, "Bajo perfil", "Figo 2020", 329000.00, "Sedan", 356.7, 4),
        new Sedan(4, "Automatica", 18.3, "Monocasco", "ABS", "Trasera", "Hidraulica", 4, "Honda", "Rojo", 20, "All season", "Civic 2020", 358400.00, "Sedan", 480.2, 4),
        new Sedan(4, "Automatica", 19.5, "Escalar", "ABS", "Trasera", "Eje rigido", 4, "Mazda", "Rojo", 18, "Runflat", "Mazda 2 Sedan 2020", 299400.00, "Sedan", 366.2, 4),
        new Sedan(4, "Automatica", 16.8, "Espacial tabular", "ABS", "Delantera", "Eje rigido", 4, "Nissan", "Rojo", 18, "Runflat", "Aveo 2020", 209400.00, "Sedan", 369.8, 4),
        
        new PicKup(4, "Automatica", 4.4, "Compacto", "Hidraulicos", "4x4", "Multilink", 4, "Ford", "Blanco", 14, "All seasons", "RAM700 2014", 445000.00, "PickUp", "Compacta", "Corta", 2, 1025, 82, true ),
        new PicKup(6, "Automatica", 5, "Espacial tubular", "Hidraulicos", "4x4", "De doble horquilla", 4, "Chevrolet", "Gris Plata", 16, "Diagonal", "Tornado 2019", 600000.00, "PickUp", "Grande", "Amplia", 2, 1500, 90, false ),
        new PicKup(4, "Manual", 5.26, "Monocasco", "Servofreno", "4x2", "Eje torsional", 2, "Nissan", "Rojo", 14, "Bajo rendimiento", "LT 2009", 245000.00, "PickUp", "Compacta", "Corta", 2, 750, 70, true ),
        new PicKup(6, "Automatica", 5, "De escalera", "Electronicos", "4x4", "McPherson", 4, "Toyota", "Dorado", 16, "Radial", "Tundra 2018", 500000.00, "PickUp", "Grande", "Amplia", 4, 980, 850, true ),
        new PicKup(6, "Automatica", 4, "Compacto", "Hidraulicos", "4x2", "De doble horquilla", 4, "MITSUBISHI", "Negro", 16, "Tubulares", "L200 2002", 438000.00, "PickUp", "Medio", "Amplia", 2, 1250, 69, false ),
        
        new Clasico(4, "Manual",6.7, "Monocasco", "Frenos de Disco", "Traccion Trasera", "Suspencion Trasera", 2,"Volkswagen","Rojo", 15, "Bajo Consumo", "Volkswagen Sedan 1950", 200000, "Clasico", "Antiguo", "Restaurado", 2000),                                                        
        new Clasico(8, "Manual",9.55, "Monocasco", "Frenos de Disco", "Traccion Trasera", "Suspencion Trasera", 4, "Ford","Negro", 17, "Radial", "Mustang 1966", 1070000, "Clasico", "Vintage Post Guerra", "Reconstruido", 1990),                                              
        new Clasico(6, "Manual",8.73, "Monocasco ULSAB", "Frenos de Tambor", "Traccion Trasera", "Suspencion Eje Rigido", 2, "Chevrolet","Azul Marino", 16, "Diagonal", "Sedaneta 1953", 350000, "Clasico", "Antiguo", "Restaurado", 2005),                                                           
        new Clasico(8, "Manual",11.45, "Espacial Tubular", "Frenos de Disco", "Traccion Trasera", "Suspencion Eje Rigido", 2, "Porsche","Amarillo", 14, "Runflat", "914 1972", 375000, "Clasico", "Antiguo", "Restaurado", 2011),                                                  
        new Clasico(6, "Manual",9.45, "Monocasco", "Frenos de Tambor", "Traccion Delantera", "Suspencion Semirrigida", 4, "Dodge","Cafe Claro", 16, "Bajo Consumo", "Guayin 1981", 55000, "Clasico", "Vintage Post Gueraa", "Modificado", 2006),
        
        new Familiar(4, "Manual", 15.5, "DOHC", "ABS", "Cuatro ruedas", "Manejo Suave",5, "Chevrolet", "Blanca", 16, "Bajo Consumo", "Trax 2021", 315600.0, "Familiar", 5, 424.7, 1606.0, "Electronico", "6 bolsas de aire" ),
        new Familiar(4, "Automatica", 16.0, "Semirrigidas", "ABS", "Cuatro ruedas", "Manejo Suave",5, "Kia", "Rojo Rubi", 18, "Bajo Consumo", "Blazer 2021", 778200.8, "Familiar", 8, 450.95, 1803.3, "Electronico", "7 bolsas de aire" ),
        new Familiar(6, "Manual", 14.5, "Rigido", "Disco/Tambor", "Trasera", "MacPherson",5, "Renault", "Rojo Rubi", 16, "Asimetricas", "Duster 2021", 291000.0, "Familiar", 5, 431.50, 1614.4, "Manual Estandar", "6 bolsas de aire" ),
        new Familiar(4, "Manual", 17.5, "Rigida", "Disco/Tambor", "Trasera", "Manejo Suave",5, "Renault", "Negra", 17, "Bajo Consumo", "Captur 2021", 338700.0, "Familiar", 5, 447.20, 1712.3, "Manual Estandar", "6 bolsas de aire" ),
        new Familiar(4, "Automatica", 14.5, "Semirrigida", "ABS", "Cuatro ruedas", "Manejo Suave",5, "Ford", "Azul Marino", 17, "Al seasons", "Expedition 2021", 1581000.0, "Familiar", 8, 457.20, 1812.3, "Electronico", "8 bolsas de aire" ),
        
        new Descapotable(4,"Automatica", 12.5,  "McPherson", "Discos ventilados - Discos solidos", "total",  "Independiente", 4, "Audi", "Rojo", 12, "runflat", "A3 Cabrio 2020", 790900.0, "Descapotable", 4, "toldo de tela eletrico", "480.2" ),
        new Descapotable(4,"Automatica", 13.2,  "Monocasco", "Disco ventilado", "trasera",  "Paralelogramo deformable", 2, "KTM", "Amarillo", 12, "asimetricas", "X-BOW Street 2011", 1664575.0, "Descapotable", 2, "toldo de tela eletrico", "350" ),
        new Descapotable(4,"Automatica", 15.9,  "McPherson", "Discos ventilados ", "trasera",  "Resorte helicoidal", 2, "BMW", "Negro", 12, "runflat", "420i Cabrio 2018", 1189399.0, "Descapotable", 2, "toldo de tela eletrico", "300" ),
        new Descapotable(4,"Automatica", 13.1,  "Monocasco", "Discos ventilados", "total",  "Independiente", 4, "VOLKSWAGEN", "Blanco", 12, "Asimetrica", "BEETLE CABRIO", 985000.0, "Descapotable", 4, "toldo de tela eletrico", "400" ),
        new Descapotable(4,"Automatica", 12.0,  "Monocasco", "Discos ventilados", "traseros",  "Independiente", 4, "Ford", "Gris", 12, "all seasons","MUSTANG CONVERTIBLE", 850000.0, "Descapotable", 4, "toldo de tela eletrico", "420" )
    };
    
    for(int i = 0; i < 30; i++) {
        stock[i] = *autos[i];
        nStock++;
    }
}

void mostrarStock(Vehiculo stock[], int&nStock) {
	char option;
    
    // Tabla de stock
    cout << endl;
	cout << "	MARCA	|		MODELO		|	COLOR	|	TIPO DE VEHICULO	" << endl;
	cout << "	--------|-------------------------------|-------------------------------|---------------" << endl;
	
        for(int i = 0; i < nStock; i++) {
            cout << "\t" << stock[i].getMarca() << "\t" << stock[i].getTipoVehiculo() << "\t" << stock[i].getModelo() << "\t" << stock[i].getColor() << "\t" << stock[i].getPrecio() << endl; 
        }
				
		cout << "	--------|-------------------------------|-------------------------------|---------------" << endl;
		

    
    // Menu para escoger y volver a menu
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
				cout << "Hola mundo";
				break;
				
			default: 
				cout << "Regresando al menu" <<endl;
				option = 'x';
				break;
		}
		
	} while (option != 'x');
}

Vehiculo personalizarVehiculo() {
    Vehiculo* automovil ; //En el arreglo estan el total de autos por categoria
    string respuesta;
    Entrada entrada; //Union para ahorrar memoria
    int res; // Colocar do{} while();
    cout<<"1.- Clasico"<<endl;
    cout<<"2.- Deportivo"<<endl;
    cout<<"3.- Descapotable"<<endl;
    cout<<"4.- Familiar"<<endl;
    cout<<"5.- PickUp"<<endl;
    cout<<"6.- Sedan"<<endl;
    cout<<"Tipo de vehiculo a crear: "<<endl;
    cin>>entrada.entero;
    switch (entrada.entero) {
    case 1:
        automovil = new Clasico();
        automovil->setTipoVehiculo("Clasico");
        cout<<"1.- Ford"<<endl;
        cout<<"2.- Chevrolet"<<endl;
        cout<<"3.- Dodge"<<endl;
        cout<<"4.- VolksWagen"<<endl;
        cout<<"5.- Mercedes Benz"<<endl;
        cout<<"Elija la marca: "<<endl;
        cin>>entrada.entero;
        switch (entrada.entero) {
        case 1: 
            automovil->setMarca("Ford");
            escogerTransmision(*automovil);
            escogerFrenos(*automovil);
            escogerTraccion(*automovil);
            escogerColor(*automovil);
            escogerRines(*automovil);
            escogerLlantas(*automovil);
            automovil->setPrecio();
            automovil->setNumeroSerie();
            break;
        case 2: 
            automovil->setMarca("Chevrolet"); 
            escogerTransmision(*automovil);
            escogerFrenos(*automovil);
            escogerTraccion(*automovil);
            escogerColor(*automovil);
            escogerRines(*automovil);
            escogerLlantas(*automovil);
            automovil->setPrecio();
            automovil->setNumeroSerie();
            break;
        case 3: 
            automovil->setMarca("Dodge"); 
            escogerTransmision(*automovil);
            escogerFrenos(*automovil);
            escogerTraccion(*automovil);
            escogerColor(*automovil);
            escogerRines(*automovil);
            escogerLlantas(*automovil);
            automovil->setPrecio();
            automovil->setNumeroSerie();
            break;
        case 4: 
            automovil->setMarca("VolksWagen");
            escogerTransmision(*automovil); 
            escogerFrenos(*automovil);
            escogerTraccion(*automovil);
            escogerColor(*automovil);
            escogerRines(*automovil);
            escogerLlantas(*automovil);
            automovil->setPrecio();
            automovil->setNumeroSerie();
            break;
        case 5: 
            automovil->setMarca("Mercedes Benz"); 
            escogerTransmision(*automovil);
            escogerFrenos(*automovil);
            escogerTraccion(*automovil);
            escogerColor(*automovil);
            escogerRines(*automovil);
            escogerLlantas(*automovil);
            automovil->setPrecio();
            automovil->setNumeroSerie();
            break;  
        default: cout<<"Marca no disponible"<<endl; break;
        }
        break;

    case 2:
        Deportivo* dep;
        automovil = new Deportivo();
        automovil->setTipoVehiculo("Deportivo");
        
        cout<<"1.- Porsche"<<endl;
        cout<<"2.- Mazda"<<endl;
        cout<<"3.- BMW"<<endl;
        cout<<"4.- Honda"<<endl;
        cout<<"5.- Mercedes Benz"<<endl;
        cout<<"6.- Ford"<<endl;
        cout<<"Elija la marca: "<<endl;
        cin>>entrada.entero;
        
        switch (entrada.entero) {
        case 1: automovil->setMarca("Porsche");
			escogerTransmision(*automovil);
            escogerFrenos(*automovil);
            escogerTraccion(*automovil);
            escogerColor(*automovil);
            escogerRines(*automovil);
            escogerLlantas(*automovil);
            automovil->setPrecio();
            automovil->setNumeroSerie();
            dep = (Deportivo*)automovil;
            dep->setMotor();
            dep->setDireccion();
            dep->setAceleracion();
            automovil = (Vehiculo*)dep;
			break;
				
        case 2: automovil->setMarca("Mazda");
        	escogerTransmision(*automovil);
            escogerFrenos(*automovil);
            escogerTraccion(*automovil);
            escogerColor(*automovil);
            escogerRines(*automovil);
            escogerLlantas(*automovil);
            automovil->setPrecio();
            automovil->setNumeroSerie();
            dep = (Deportivo*)automovil;
            dep->setMotor();
            dep->setDireccion();
            dep->setAceleracion();
            automovil = (Vehiculo*)dep;
			break;
				
        case 3: automovil->setMarca("BMW");
        	escogerTransmision(*automovil);
        	escogerFrenos(*automovil);
        	escogerTraccion(*automovil);
            escogerColor(*automovil);
            escogerRines(*automovil);
            escogerLlantas(*automovil);
            automovil->setPrecio();
            automovil->setNumeroSerie();
            dep = (Deportivo*)automovil;
            dep->setMotor();
            dep->setDireccion();
            dep->setAceleracion();
            automovil = (Vehiculo*)dep;
			break;
				
        case 4: automovil->setMarca("Honda");
    		escogerTransmision(*automovil);
        	escogerFrenos(*automovil);
        	escogerTraccion(*automovil);
            escogerColor(*automovil);
            escogerRines(*automovil);
            escogerLlantas(*automovil);
            automovil->setPrecio();
            automovil->setNumeroSerie();
            dep = (Deportivo*)automovil;
            dep->setMotor();
            dep->setDireccion();
            dep->setAceleracion();
            automovil = (Vehiculo*)dep;
			break;
				
        case 5: automovil->setMarca("Mercedes Benz");
			escogerTransmision(*automovil);
        	escogerFrenos(*automovil);
        	escogerTraccion(*automovil);
            escogerColor(*automovil);
            escogerRines(*automovil);
            escogerLlantas(*automovil);
            automovil->setPrecio();
            automovil->setNumeroSerie();
            dep = (Deportivo*)automovil;
            dep->setMotor();
            dep->setDireccion();
            dep->setAceleracion();
            automovil = (Vehiculo*)dep;
			break;
				
        case 6: automovil->setMarca("Ford");
			escogerTransmision(*automovil);
            escogerFrenos(*automovil);
            escogerTraccion(*automovil);
            escogerColor(*automovil);
            escogerRines(*automovil);
            escogerLlantas(*automovil);
            automovil->setPrecio();
            automovil->setNumeroSerie(); 
            dep = (Deportivo*)automovil;
            dep->setMotor();
            dep->setDireccion();
            dep->setAceleracion();
            automovil = (Vehiculo*)dep;
			break;
				
        default: cout<<"Marca no disponible"<<endl; break;
        
        }
        
        break;
        
    case 3:
        Descapotable* des;
        automovil = new Descapotable();
        automovil->setTipoVehiculo("Descapotable");
        
        cout<<"1.- Fiat"<<endl;
        cout<<"2.- Mazda"<<endl;
        cout<<"3.- VolksWagen"<<endl;
        cout<<"4.- Ford"<<endl;
        cout<<"5.- Lotus Elise"<<endl;
        cout<<"6.- Audi"<<endl;
        cout<<"Elija la marca: "<<endl;
        cin>>entrada.entero;
        switch (entrada.entero) {
        case 1: automovil->setMarca("Fiat"); 
		 	escogerTransmision(*automovil);
            escogerFrenos(*automovil);
            escogerTraccion(*automovil);
            escogerColor(*automovil);
            escogerRines(*automovil);
            escogerLlantas(*automovil);
            automovil->setPrecio();
            automovil->setNumeroSerie();
            des = (Descapotable*)automovil;
            des->setCapo();
            des->setMaletero();
            automovil = (Vehiculo*)des;
			break;
        case 2: automovil->setMarca("Mazda"); 
		 	escogerTransmision(*automovil);
            escogerFrenos(*automovil);
            escogerTraccion(*automovil);
            escogerColor(*automovil);
            escogerRines(*automovil);
            escogerLlantas(*automovil);
            automovil->setPrecio();
            automovil->setNumeroSerie();
            des = (Descapotable*)automovil;
            des->setCapo();
            des->setMaletero();
            automovil = (Vehiculo*)des;
			break;
        case 3: automovil->setMarca("VolksWagen");
			escogerTransmision(*automovil);
            escogerFrenos(*automovil);
            escogerTraccion(*automovil);
            escogerColor(*automovil);
            escogerRines(*automovil);
            escogerLlantas(*automovil);
            automovil->setPrecio();
            automovil->setNumeroSerie();
            des = (Descapotable*)automovil;
            des->setCapo();
            des->setMaletero();
            automovil = (Vehiculo*)des;
			break;
        case 4: automovil->setMarca("Ford");
			escogerTransmision(*automovil);
            escogerFrenos(*automovil);
            escogerTraccion(*automovil);
            escogerColor(*automovil);
            escogerRines(*automovil);
            escogerLlantas(*automovil);
            automovil->setPrecio();
            automovil->setNumeroSerie();
            des = (Descapotable*)automovil;
            des->setCapo();
            des->setMaletero();
            automovil = (Vehiculo*)des;
			 break;
        case 5: automovil->setMarca("Lotus Elise");
			escogerTransmision(*automovil);
            escogerFrenos(*automovil);
            escogerTraccion(*automovil);
            escogerColor(*automovil);
            escogerRines(*automovil);
            escogerLlantas(*automovil);
            automovil->setPrecio();
            automovil->setNumeroSerie();
            des = (Descapotable*)automovil;
            des->setCapo();
            des->setMaletero();
            automovil = (Vehiculo*)des;
			break;
        case 6: automovil->setMarca("Audi");
			escogerTransmision(*automovil);
            escogerFrenos(*automovil);
            escogerTraccion(*automovil);
            escogerColor(*automovil);
            escogerRines(*automovil);
            escogerLlantas(*automovil);
            automovil->setPrecio();
            automovil->setNumeroSerie();
            des = (Descapotable*)automovil;
            des->setCapo();
            des->setMaletero();
            automovil = (Vehiculo*)des;
			break;
        default: cout<<"Marca no disponible"<<endl; break;
        }
        break;
        
    case 4:
        Familiar* fam;
        automovil = new Familiar();
        automovil->setTipoVehiculo("Familiar");
        cout<<"1.- Seat"<<endl;
        cout<<"2.- Subaru"<<endl;
        cout<<"3.- Peugeot"<<endl;
        cout<<"4.- Kia"<<endl;
        cout<<"Elija la marca: "<<endl;
        cin>>entrada.entero;
        switch (entrada.entero) {
        case 1: automovil->setMarca("Seat");
			escogerTransmision(*automovil);
        	escogerFrenos(*automovil);
        	escogerTraccion(*automovil);
            escogerColor(*automovil);
            escogerRines(*automovil);
            escogerLlantas(*automovil); 
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
        case 2: automovil->setMarca("Subaru");
    		escogerTransmision(*automovil);
        	escogerFrenos(*automovil);
        	escogerTraccion(*automovil);
            escogerColor(*automovil);
            escogerRines(*automovil);
            escogerLlantas(*automovil);
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
        case 3: automovil->setMarca("Peugout"); 
			escogerTransmision(*automovil);
        	escogerFrenos(*automovil);
        	escogerTraccion(*automovil);
            escogerColor(*automovil);
            escogerRines(*automovil);
            escogerLlantas(*automovil);
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
        case 4: automovil->setMarca("Kia"); 
			escogerTransmision(*automovil);
            escogerFrenos(*automovil);
            escogerTraccion(*automovil);
            escogerColor(*automovil);
            escogerRines(*automovil);
            escogerLlantas(*automovil);
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
        default: cout<<"Marca no disponible"<<endl; break;
        }
        break;
        
    case 5:
        PicKup* pic;
        automovil = new PicKup();
        automovil->setTipoVehiculo("PickUp");
        cout<<"1.- Chevrolet"<<endl;
        cout<<"2.- Ford"<<endl;
        cout<<"3.- Mitsubishi"<<endl;
        cout<<"4.- Nissan"<<endl;
        cout<<"5.- Toyota"<<endl;
        cout<<"Elija la marca: "<<endl;
        cin>>entrada.entero;
        switch (entrada.entero) {
        case 1: automovil->setMarca("Chevrolet");
			escogerTransmision(*automovil); 
            escogerFrenos(*automovil);
            escogerTraccion(*automovil);
            escogerColor(*automovil);
            escogerRines(*automovil);
            escogerLlantas(*automovil);
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
        case 2: automovil->setMarca("Ford"); 
			escogerTransmision(*automovil); 
            escogerFrenos(*automovil);
            escogerTraccion(*automovil);
            escogerColor(*automovil);
            escogerRines(*automovil);
            escogerLlantas(*automovil);
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
        case 3: automovil->setMarca("Mitsubishi"); 
			escogerTransmision(*automovil); 
            escogerFrenos(*automovil);
            escogerTraccion(*automovil);
            escogerColor(*automovil);
            escogerRines(*automovil);
            escogerLlantas(*automovil);
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
        case 4: automovil->setMarca("Nissan"); 
			escogerTransmision(*automovil); 
            escogerFrenos(*automovil);
            escogerTraccion(*automovil);
            escogerColor(*automovil);
            escogerRines(*automovil);
            escogerLlantas(*automovil);
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
        case 5: automovil->setMarca("Toyota"); 
			escogerTransmision(*automovil); 
            escogerFrenos(*automovil);
            escogerTraccion(*automovil);
            escogerColor(*automovil);
            escogerRines(*automovil);
            escogerLlantas(*automovil);
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
        default: cout<<"Marca no disponible"<<endl; break;
        }
        break;
        
    case 6:
        Sedan* sed;
        automovil = new Sedan();
        automovil->setTipoVehiculo("Sedan");
        cout<<"1.- Chevrolet"<<endl;
        cout<<"2.- Ford"<<endl;
        cout<<"3.- Honda"<<endl;
        cout<<"4.- Hyundai"<<endl;
        cout<<"5.- Mazda"<<endl;
        cout<<"6.- Nissan"<<endl;
        cout<<"Elija la marca: "<<endl;
        cin>>entrada.entero;
        switch (entrada.entero) {
        case 1: automovil->setMarca("Chevrolet");
			escogerTransmision(*automovil);
        	escogerFrenos(*automovil);
        	escogerTraccion(*automovil);
            escogerColor(*automovil);
            escogerRines(*automovil);
            escogerLlantas(*automovil); 
            automovil->setPrecio();
            automovil->setNumeroSerie();
            sed = (Sedan*)automovil;
            sed->setMaletero();
            automovil = (Vehiculo*)sed;
			break;
        case 2: automovil->setMarca("Ford");
			escogerTransmision(*automovil);
        	escogerFrenos(*automovil);
        	escogerTraccion(*automovil);
            escogerColor(*automovil);
            escogerRines(*automovil);
            escogerLlantas(*automovil);
            automovil->setPrecio();
            automovil->setNumeroSerie();
            sed = (Sedan*)automovil;
            sed->setMaletero();
            automovil = (Vehiculo*)sed; 
			break;
        case 3: automovil->setMarca("Honda");
			escogerTransmision(*automovil);
        	escogerFrenos(*automovil);
        	escogerTraccion(*automovil);
            escogerColor(*automovil);
            escogerRines(*automovil);
            escogerLlantas(*automovil);
            automovil->setPrecio();
            automovil->setNumeroSerie();
            sed = (Sedan*)automovil;
            sed->setMaletero();
            automovil = (Vehiculo*)sed; 
			break;
        case 4: automovil->setMarca("Hyundai"); 
			escogerTransmision(*automovil);
            escogerFrenos(*automovil);
            escogerTraccion(*automovil);
            escogerColor(*automovil);
            escogerRines(*automovil);
            escogerLlantas(*automovil);
            automovil->setPrecio();
            automovil->setNumeroSerie();
            sed = (Sedan*)automovil;
            sed->setMaletero();
            automovil = (Vehiculo*)sed;
			break;
        case 5: automovil->setMarca("Mazda"); 
			escogerTransmision(*automovil);
        	escogerFrenos(*automovil);
        	escogerTraccion(*automovil);
            escogerColor(*automovil);
            escogerRines(*automovil);
            escogerLlantas(*automovil);
            automovil->setPrecio();
            automovil->setNumeroSerie();
            sed = (Sedan*)automovil;
            sed->setMaletero();
            automovil = (Vehiculo*)sed;
			break;
        case 6: automovil->setMarca("Nissan"); 
			escogerTransmision(*automovil);
        	escogerFrenos(*automovil);
        	escogerTraccion(*automovil);
            escogerColor(*automovil);
            escogerRines(*automovil);
            escogerLlantas(*automovil);
            automovil->setPrecio();
            automovil->setNumeroSerie();
            sed = (Sedan*)automovil;
            sed->setMaletero();
            automovil = (Vehiculo*)sed;
			break;
				
        default: cout<<"Marca no disponible"<<endl; break;
        }
    default:
        entrada.entero = 7;
        cout<<"Opcion no disponible"<<endl;
        break;
    }
    return *automovil;
}

void escogerTransmision(Vehiculo&v) {
    int res;
    do{
        cout<<"1.- Manual"<<endl;
        cout<<"2.- Automatica"<<endl;
        cout<<"Tipo de tranmision: "<<endl;
        cin>>res;
        switch(res) {
            case 1: v.setTransmision("Manual"); break;
            case 2: v.setTransmision("Automatica"); break;
            default: 
            res = 3; 
            cout<<"Opcion no disponible"<<endl; 
            break;
        }
    }
    while(res == 3);
}

void escogerFrenos(Vehiculo&v) {
    int res;
    do {
        cout<<"1.- Disco"<<endl;
        cout<<"2.- Tambor"<<endl;
        cout<<"3.- ABS"<<endl;
        cout<<"Tipo de frenos: "<<endl;
        cin>>res;
        switch(res) {
            case 1: v.setFrenos("Disco"); break;
            case 2: v.setFrenos("Tambor"); break;
            case 3: v.setFrenos("ABS"); break;
            default: 
            res = 4;
            cout<<"Opcion no disponible"<<endl; 
            break;
        }
    }
    while(res == 4);
}

void escogerTraccion(Vehiculo&v) {
    int res;
    do {
        if(v.getTipoVehiculo() == "PickUp" || v.getTipoVehiculo() == "Familiar") {
            cout<<"1.- Delantera"<<endl;
            cout<<"2.- 4x4"<<endl;
            cout<<"Tipo de traccion: "<<endl;
            cin>>res;
            switch(res) {
                case 1: v.setTraccion("Delantera"); break;
                case 2: v.setTraccion("4x4"); break;
                default: 
                res = 3;
                cout<<"Opcion no disponible"<<endl; 
                break;
            }
        }
        else {
            cout<<"1.- Delantera"<<endl;
            cout<<"2.- Tracera"<<endl;
            cout<<"Tipo de traccion: "<<endl;
            cin>>res;
            switch(res) {
                case 1: v.setTraccion("Delantera"); break;
                case 2: v.setTraccion("Tracera"); break;
                default: 
                res = 3;
                cout<<"Opcion no disponible"<<endl; 
                break;
            }
        }
    } 
    while(res == 3);
}

void escogerColor(Vehiculo&v) {
    int res;
    do {
        cout<<"1.- Negro"<<endl;
        cout<<"2.- Blanco"<<endl;
        cout<<"3.- Plomo"<<endl;
        cout<<"4.- Rojo"<<endl;
        cout<<"5.- Azul"<<endl;
        cout<<"6.- Plata"<<endl;
        cout<<"Color de automovil: "<<endl;
        cin>>res;
        switch(res) {
            case 1: v.setColor("Negro"); break;
            case 2: v.setColor("Blanco"); break;
            case 3: v.setColor("Plomo"); break;
            case 4: v.setColor("Rojo"); break;
            case 5: v.setColor("Azul"); break;
            case 6: v.setColor("Plata"); break;
            default: 
            res = 7;
            cout<<"Opcion no disponible"<<endl; 
            break;
        }
    }
    while(res == 7);
}

void escogerRines(Vehiculo&v) {
    int res;
    do {
        if(v.getTipoVehiculo() == "Clasico" || v.getTipoVehiculo() == "Sedan" || v.getTipoVehiculo() == "Familiar") {
            cout<<"1.- 13 in"<<endl;
            cout<<"2.- 14 in"<<endl;
            cout<<"3.- 15 in"<<endl;
            cout<<"Tamanio de Rines: "<<endl;
            cin>>res;
            switch(res) {
                case 1: v.setRin(13); break;
                case 2: v.setRin(14); break;
                case 3: v.setRin(15); break;
                default: 
                res = 4;
                cout<<"Opcion no disponible"<<endl; 
                break;
            }
        }
        else if(v.getTipoVehiculo() == "Deportivo" || v.getTipoVehiculo() == "Descapotable" || v.getTipoVehiculo() == "PickUp") {
            cout<<"1.- 16 in"<<endl;
            cout<<"2.- 17 in"<<endl;
            cout<<"Tamanio de Rines: "<<endl;
            cin>>res;
            switch(res) {
                case 1: v.setRin(16); break;
                case 2: v.setRin(17); break;
                default: 
                res = 4;
                cout<<"Opcion no disponible"<<endl; 
                break;
            }
        }
    }
    while(res == 4);
}

void escogerLlantas(Vehiculo&v){
    int res;
    do {
        cout << "1.- Bajo consumo " << endl;
        cout << "2.- Runflat " << endl;
        cout << "3.- Bajo perfil " << endl;
        cout << "4.- Tubulares " << endl;
        cout << "5.- Diagonal " << endl;
        cout << "6.- Radial " << endl;
        cout << "7.- All seasons " << endl;
        cout << "8.- Asimetricas " << endl;
        cout << "9.- Direccionales " << endl;
        cout << "Elija su tipo de llanta " << endl;
        cin>>res;

		//Revisar porque no jala la opcion del sedan jeje
        switch (res){
            case 1: v.setLlanta("Bajo consumo"); break;
            case 2: v.setLlanta("Runflat"); break;
            case 3: v.setLlanta("Bajo perfil"); break;
            case 4: v.setLlanta("Tubulares"); break;
            case 5: v.setLlanta("Diagonal"); break;
            case 6: v.setLlanta("Radial"); break;
            case 7: v.setLlanta("All seasons"); break;
            case 8: v.setLlanta("Asimetricas"); break;
            case 9: v.setLlanta("Direccionales"); break;
            default: 
            res = 10;
            cout<<"Opcion no disponible"<<endl; 
            break;
        }
    }
    while(res == 10);
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

void iniciarSesion(Administrador admin[], int&nAdmin, Venta v[], int&nVentas, Vehiculo automovil[], int&nAutos) {
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
            menuAdministradorNorm(v, nVentas, automovil, nAutos);
        }
        else{
            cout<<"Acceso denegado"<<endl;
        }
    }
}

Administrador crearAdministrador() {
    Administrador* a = new Administrador();
    Entrada entrada;
    string datos1, datos2;
    cin.ignore();

    do {
        cout<<"Ingrese su nombre: "<<endl;
        getline(cin, datos1);
        cout<<"Ingrese id: "<<endl;
        getline(cin, datos2);
        a->setId(datos2, datos1);
        cout<<"Ingrese su contrasena: "<<endl;
        getline(cin, datos1);
        a->setPassword(datos1);
        cout<<"Nombre: "<<a->mostrarNombre()<<"\nId: "<<a->getId()<<"\nContrasena: "<<a->getPassword()<<endl;
        cout<<"La informacion es correcta: (1 = Si, 0 = No)"<<endl;
        cin>>entrada.entero;
    }
    while(entrada.entero != 1);

    return *a;
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
    Entrada entrada;
    do{
        cout<<"Opciones de super administrador"<<endl;
        cout<<"1.- Agregar un administrador"<<endl;
        cout<<"2.- Mostrar los administradores"<<endl;
        cout<<"3.- Crear automoviles para stock"<<endl;
        cout<<"4.- Visualizar venta"<<endl;
        cout<<"5.- Visualizar ventas"<<endl;
        cout<<"6.- Mostrar total vendido"<<endl;
        cout<<"7.- Regresar al menu principal"<<endl;
        cout<<"Ingrese respuesta"<<endl;
        cin>>entrada.entero;

        switch(entrada.entero) {
            case 1:
                admin[nAdmin] = crearAdministrador();
                nAdmin++;
                cout<<"Administrador creado"<<endl;
                break;
            case 2:
                mostrarAdministradores(admin, nAdmin);
                break;
            case 3: 
            automovil[nAutos] = personalizarVehiculo(); // Debe retornar un vehiculo 
            nAutos++;
            break;
            case 4: v[0].BuscarVentas(v); break;
            case 5: v[0].MostrarVentas(v , nVentas); break;
            case 6: cout << "Total de ventas: " << v[0].operator+() << endl; break;
            case 7: break;
            default:
                cout<<"Opcion no establecida"<<endl;
                break;
        }
    }
    while(entrada.entero != 7);
}

void menuAdministradorNorm(Venta v[], int&nVentas, Vehiculo automovil[], int&nAutos){
    Entrada entrada;
    do{
        cout<<"Opciones de super administrador"<<endl;
        cout<<"1.- Visualizar ventas"<<endl;
        cout<<"2.- Visualizar una venta"<<endl;
        cout<<"3.- Mostrar Vehiculos existente"<<endl;
        cout<<"4.- Mostrar total vendido"<<endl;
        cout<<"5.- Regresar al inicio"<<endl;
        cout<<"Ingrese respuesta"<<endl;
        cin>>entrada.entero;
        switch(entrada.entero) {
            case 1:
                v[0].MostrarVentas(v , nVentas);
                break;
            case 2:
                v[0].BuscarVentas(v);
                break;
            case 3: 
               // vehiculosStock();
                break;
            case 4:
                cout << "Total de ventas: " << v[0].operator+() << endl;
                break;
            case 5:
                cout<<"Y volvemos a la normalidad"<<endl;
                break;
            default:
                cout<<"Opcion no establecida"<<endl;
                break;
        }
    }
    while(entrada.entero != 5);
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
    Comprador* c = new Comprador();
    string dato1, dato2;
    int res;
    long long tel;
    cin.ignore();
    cout<<"Ingrese su nombre: "<<endl;
    getline(cin, dato1);
    cout<<"Ingrese su correo: "<<endl;
    getline(cin, dato2);
    c->setCorreo(dato2, dato1);
    do{
        cout<<"1.- Credito"<<endl;
        cout<<"2.- Contado"<<endl;
        cout<<"Ingrese su forma de pago: "<<endl;
        cin>>res;
        switch(res){
            case 1: c->setPago("Credito"); break;
            case 2: c->setPago("Contado"); break;
            default: res = 3; cout<<"Opcion no disponible"<<endl; break;
        }
    }
    while(res == 3);
    cout<<"Ingrese su telefono: "<<endl;
    cin>>tel;
    c->setTelefono(tel);

    return *c;
}

Venta realizarCompra(Comprador&comp, Vehiculo vehiculo[], int&nAutos, int&contCom) {
    int res;
    string dato1;
    Venta* v = new Venta();
    v->setComprador(comp);
    if(comp.getPago() == "Credito"){
            do {
                cout<<"1.- 3 Pagos"<<endl;
                cout<<"2.- 6 Pagos"<<endl;
                cout<<"3.- 12 Pagos"<<endl;
                cout<<"Ingrese el plan de pagos: "<<endl;
                cin>>res;
                switch(res) {
                    case 1: v->setPlazo(3); break;
                    case 2: v->setPlazo(6); break;
                    case 3: v->setPlazo(12); break;
                    default:
                    res = 5;
                    cout<<"Opcion no disponible"<<endl;
                    break;
                }
            }
    while(res == 5);
    }
    else v->setPlazo(1);
    cin.ignore();
    cout<<"Ingrese su dirección: "<<endl;
    getline(cin, dato1);
    v->setDireccion(dato1);
    v->setFactura();
    for(int i = (nAutos - contCom); i < nAutos; i++) v->AgregarVehiculo(vehiculo[i]);
    v->MostrarTicket();
    cout<<"$"<<v->operator + ();
    
    return *v;
}
