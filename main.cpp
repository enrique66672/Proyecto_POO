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
void pedirDatosAuto(Vehiculo automovil);

void vehiculosstock(Vehiculo[], int&);
void superAdmin(Administrador&, int&);
int buscarAdministrador(Administrador[], int&);
int iniciarSesion(Administrador[], int&);
Administrador crearAdministrador();
void mostrarAdministradores(Administrador[], int&);
void menuSuperAdministrador(Administrador[], int&);

int main() {
    Administrador* administradores = new Administrador[ADMIN];
    Comprador* compradores = new Comprador[COM];
    Vehiculo* vehiculos = new Vehiculo[AUTOS];
    int respuesta, r;
    int nAdmin = 0, nAutos = 0;
    Entrada entrada;
    string datos1, datos2;
    
    superAdmin(administradores[nAdmin], nAdmin);

    do{
        cout<<"\t\nMENU"<<endl;
        cout<<"1.- Administrador"<<endl;
        cout<<"2.- Comprador"<<endl;
        cout<<"3.- Salir"<<endl;
        cout<<"Como quieres ingresar: "<<endl;
        cin>>respuesta;

        switch (respuesta){
        case 1:
            entrada.entero = iniciarSesion(administradores, nAdmin);
            if(entrada.entero == 0) {
                menuSuperAdministrador(administradores, nAdmin);
            }
            if(entrada.entero != 0) {
                //Men√∫ de administrador normal
            }
            break;
        // case 2:
            // break;
        case 3:
            cout<<"Saliendo..."<<endl;
            // _sleep(100);
            break;        
        default:
            cout<<"Error"<<endl;
            break;
        }
    }
    while(respuesta != 3);
    return 0;
}
void automovilesStosck(Vehiculo autos[], int&nVehiculos) {
	Vehiculo* au[30];
	
	//Deportivo(int _numCilindros, string _transmision, float _consumo, string _chasis, string _frenos, string _traccion, string _suspension, int _puertas, string _marca, string _color, int _rines, string _llantas, string _modelo, double _precio, string _tipoVehiculo, string _tipoMotor, string _tipoDireccion, float _aceleracion)
	au[] = new Deportivo(6, "Automatica", 17.9, "Monocasco de fibra","De carbono","Cuatro Ruedas", "Hidraulico", 2, "Mercedes", "Negro", 20, "Deportivas","AMG-GT 2018", 4000000.00, "Deportivo", "V12", "Electrohidraulica", 2.9);
	au[] = new Deportivo(6, "Hibrida", 16.6, "Monocasco de fibra","De carbono","Trasera", "Aire", 4, "Ford", "Rojo", 20, "Deportivas","Mustang 2020", 1099900.00, "Deportivo", "V8", "Mecanica", 3.8);
	au[] = new Deportivo(4, "Manual", 11.9, "Monocasco de fibra","De carbono","Delantera", "Hidraulico", 4, "Mercedes", "Gris", 20, "Deportivas","AMG-A-45 2017", 400000.00, "Deportivo", "V8", "Electrica", 4.2);
	au[] = new Deportivo(6, "Automatica", 15.3, "Monocasco de fibra","De carbono","Cuatro Ruedas", "Hidraulico", 2, "Porsche", "Azul", 20, "Deportivas","911 Turbo 2018", 3478000.00, "Deportivo", "V12", "Electrohidraulica", 2.7);
	
	//Sedan(int _numCilindros, string _transmision, float _consumo, string _chasis, string _frenos, string _traccion, string _suspension, int _puertas, string _marca, string _color, int _rines, string _llantas, string _modelo, double _precio, string _tipoVehiculo, float _maletero, int _pasajeros)
	au[] = new Sedan(4, "Automatica", 19.3, "Espacial tabular", "ABS", "Trasera", "Eje rigido", 4, "Chevrolet", "Rojo", 18, "Runflat", "Aveo 2020", 209400.00, "Sedan", 366.5, 4);
	au[] = new Sedan(3, "Automatica", 15.7, "Escalar", "ABS", "Delantera", "Aire", 4, "Ford", "Rojo", 19, "Bajo perfil", "Figo 2020", 329000.00, "Sedan", 356.7, 4);
	au[] = new Sedan(4, "Automatica", 18.3, "Monocasco", "ABS", "Trasera", "Hidraulica", 4, "Honda", "Rojo", 20, "All season", "Civic 2020", 358400.00, "Sedan", 480.2, 4);
	au[] = new Sedan(4, "Automatica", 19.5, "Escalar", "ABS", "Trasera", "Eje rigido", 4, "Mazda", "Rojo", 18, "Runflat", "Mazda 2 Sedan 2020", 299400.00, "Sedan", 366.2, 4);
	au[] = new Sedan(4, "Automatica", 16.8, "Espacial tabular", "ABS", "Delantera", "Eje rigido", 4, "Nissan", "Rojo", 18, "Runflat", "Aveo 2020", 209400.00, "Sedan", 369.8, 4);
	
	
	//PicKup(int _numCilindros, string _transmision, float _consumo, string _chasis, string _frenos, string _traccion, string _suspension, int _puertas, string _marca, string _color, int _rines, string _llantas, string _modelo, double _precio, string _tipoVehiculo, string _tamano, string _tipoCaja, int _cabinas, int _capacidadCarga, int _longCaja, bool _puertaCarga)
	au[] = new PicKup(4, "Automatica", 4.4, "Compacto", "Hidraulicos", "4x4", "Multilink", 4, "Ford", "Blanco", 14, "All seasons", "RAM700 2014", 445000.00, "PickUp", "Compacta", "Corta", 2, 1025, 82, true ); 
	au[] = new PicKup(6, "Automatica", 5, "Espacial tubular", "Hidraulicos", "4x4", "De doble horquilla", 4, "Chevrolet", "Gris Plata", 16, "Diagonal", "Tornado 2019", 600000.00, "PickUp", "Grande", "Amplia", 2, 1500, 90, false ); 
	au[] = new PicKup(4, "Manual", 5.26, "Monocasco", "Servofreno", "4x2", "Eje torsional", 2, "Nissan", "Rojo", 14, "Bajo rendimiento", "LT 2009", 245000.00, "PickUp", "Compacta", "Corta", 2, 750, 70, true ); 
	au[] = new PicKup(6, "Automatica", 5, "De escalera", "Electronicos", "4x4", "McPherson", 4, "Toyota", "Dorado", 16, "Radial", "Tundra 2018", 500000.00, "PickUp", "Grande", "Amplia", 4, 980, 850, true ); 
	au[] = new PicKup(6, "Automatica", 4, "Compacto", "Hidraulicos", "4x2", "De doble horquilla", 4, "MITSUBISHI", "Negro", 16, "Tubulares", "L200 2002", 438000.00, "PickUp", "Medio", "Amplia", 2, 1250, 69, false );
	
	//Clasico(int _numCilindros, string _transmision, float _consumo, string _chasis, string _frenos, string _traccion, string _suspension, int _puertas, string _marca, string _color, int _rines, string _llantas, string _modelo, double _precio, string _tipoVehiculo, string _categoria, string _clasificacion, int _anioRegistro)
	au[]= new Clasico(4, "Manual",6.7, "Monocasco", "Frenos de Disco", "Traccion Trasera", "Suspencion Trasera", 2,"Volkswagen","Rojo", 15, "Bajo Consumo", "Volkswagen Sedan 1950", 200000, "Clasico", "Antiguo", "Restaurado", 2000);                                                            
	au[]= new Clasico(8, "Manual",9.55, "Monocasco", "Frenos de Disco", "Traccion Trasera", "Suspencion Trasera", 4, "Ford","Negro", 17, "Radial", "Mustang 1966", 1070000, "Clasico", "Vintage Post Guerra", "Reconstruido", 1990);                                                              
	au[]= new Clasico(6, "Manual",8.73, "Monocasco ULSAB", "Frenos de Tambor", "Traccion Trasera", "Suspencion Eje Rigido", 2, "Chevrolet","Azul Marino", 16, "Diagonal", "Sedaneta 1953", 350000, "Clasico", "Antiguo", "Restaurado", 2005);                                                              
	au[]= new Clasico(8, "Manual",11.45, "Espacial Tubular", "Frenos de Disco", "Traccion Trasera", "Suspencion Eje Rigido", 2, "Porsche","Amarillo", 14, "Runflat", "914 1972", 375000, "Clasico", "Antiguo", "Restaurado", 2011);                                                              
	au[]= new Clasico(6, "Manual",9.45, "Monocasco", "Frenos de Tambor", "Traccion Delantera", "Suspencion Semirrigida", 4, "Dodge","Cafe Claro", 16, "Bajo Consumo", "Guayin 1981", 55000, "Clasico", "Vintage Post Gueraa", "Modificado", 2006);
	
	//Familiar(int _numCilindros, string _transmision, float _consumo, string _chasis, string _frenos, string _traccion, string _suspension, int _puertas, string _marca, string _color, int _rines, string _llantas, string _modelo, double _precio, string _tipoVehiculo, int _pasajeros, float _dimensiones, float _capacidadCarga, string _tipoEncendido, string _seguridad)
	au[]= new Familiar(4, "Manual", 15.5, "DOHC", "ABS", "Cuatro ruedas", "Manejo Suave",5, "Chevrolet", "Blanca", 16, "Bajo Consumo", "Trax 2021", 315600.0, "Familiar", 5, 424.7, 1606.0, "Electronico", "6 bolsas de aire" );
	au[]= new Familiar(4, "Automatica", 16.0, "Semirrigidas", "ABS", "Cuatro ruedas", "Manejo Suave",5, "Kia", "Rojo Rubi", 18, "Bajo Consumo", "Blazer 2021", 778200.8, "Familiar", 8, 450.95, 1803.3, "Electronico", "7 bolsas de aire" );
	au[]= new Familiar(6, "Manual", 14.5, "Rigido", "Disco/Tambor", "Trasera", "MacPherson",5, "Renault", "Rojo Rubi", 16, "Asimetricas", "Duster 2021", 291000.0, "Familiar", 5, 431.50, 1614.4, "Manual Estandar", "6 bolsas de aire" );
	au[]= new Familiar(4, "Manual", 17.5, "Rigida", "Disco/Tambor", "Trasera", "Manejo Suave",5, "Renault", "Negra", 17, "Bajo Consumo", "Captur 2021", 338700.0, "Familiar", 5, 447.20, 1712.3, "Manual Estandar", "6 bolsas de aire" );
	au[]= new Familiar(4, "Automatica", 14.5, "Semirrigida", "ABS", "Cuatro ruedas", "Manejo Suave",5, "Ford", "Azul Marino", 17, "Al seasons", "Expedition 2021", 1581000.0, "Familiar", 8, 457.20, 1812.3, "Electronico", "8 bolsas de aire" );
	
	//Descapotable(int _numCilindros, string _transmision, float _consumo, string _chasis, string _frenos, string _traccion, string _suspension, int _puertas, string _marca, string _color, int _rines, string _llantas, string _modelo, double _precio, string _tipoVehiculo, int _pasajeros, string _capo, string _maletero)
	au[] = new Descapotable(4,"Automatica", 2,  "McPherson", "Discos ventilados - Discos sÛlidos", "total",  "Independiente", 4, "Audi", "Rojo", 12, "runflat", "A3 Cabrio 2020", 790900, "Descapotable", 4, "toldo de tela elÈctrico", 480.2 );
	au[] = new Descapotable(4,"Automatica", 3,  "Monocasco", "Disco ventilado", "trasera",  "Paralelogramo deformable", 2, "KTM", "Amarillo", 12, "asimetricas", "X-BOW Street 2011", 1664575, "Descapotable", 2, "toldo de tela elÈctrico", 350 );
	au[] = new Descapotable(4,"Automatica", 5,  "McPherson", "Discos ventilados ", "trasera",  "Resorte helicoidal", 2, "BMW", "Negro", 12, "runflat", "420i Cabrio 2018", 1189399, "Descapotable", 2, "toldo de tela elÈctrico", 300 );
	au[] = new Descapotable(4,"Automatica", 3,  "Monocasco", "Discos ventilados", "total",  "Independiente", 4, "VOLKSWAGEN", "balnco", 12, "Asimetrica", "BEETLE CABRIO", 985000, "Descapotable", 4, "toldo de tela elÈctrico", 400 );
	au[] = new Descapotable(4,"Automatica", 2,  "Monocasco", "Discos ventilados", "traseros",  "Independiente", 4, "Ford", "Gris", 12, "all seasons","MUSTANG CONVERTIBLE", 850000, "Descapotable", 4, "toldo de tela elÈctrico", 420 );
	
}
Vehiculo personalizarVehiculo() {
    Vehiculo* automovil ; //En el arreglo estan el total de autos por categoria
 
    string respuesta;
    Entrada entrada; //Union para ahorrar memoria
    int res;
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
            break;
        case 2: 
            automovil->setMarca("Chevrolet"); 
            escogerTransmision(*automovil);
            escogerFrenos(*automovil);
            escogerTraccion(*automovil);
            break;
        case 3: 
            automovil->setMarca("Dodge"); 
            escogerTransmision(*automovil);
            escogerFrenos(*automovil);
            escogerTraccion(*automovil);
            break;
        case 4: 
            automovil->setMarca("VolksWagen");
            escogerTransmision(*automovil); 
            escogerFrenos(*automovil);
            escogerTraccion(*automovil);
            break;
        case 5: 
            automovil->setMarca("Mercedes Benz"); 
            escogerTransmision(*automovil);
            escogerFrenos(*automovil);
            escogerTraccion(*automovil);
            break;  
        default: cout<<"Marca no disponible"<<endl; break;
        }
        break;

    case 2:
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
				break;
				
        case 2: automovil->setMarca("Mazda");
        		escogerTransmision(*automovil);
            	escogerFrenos(*automovil);
            	escogerTraccion(*automovil);
				break;
				
        case 3: automovil->setMarca("BMW");
        		escogerTransmision(*automovil);
            	escogerFrenos(*automovil);
            	escogerTraccion(*automovil);
				break;
				
        case 4: automovil->setMarca("Honda");
        		escogerTransmision(*automovil);
            	escogerFrenos(*automovil);
            	escogerTraccion(*automovil);
				break;
				
        case 5: automovil->setMarca("Mercedes Benz");
				escogerTransmision(*automovil);
            	escogerFrenos(*automovil);
            	escogerTraccion(*automovil);
				break;
				
        case 6: automovil->setMarca("Ford");
				escogerTransmision(*automovil);
            	escogerFrenos(*automovil);
            	escogerTraccion(*automovil); 
				break;
				
        default: cout<<"Marca no disponible"<<endl; break;
        
        }
        
        break;
        
    case 3:
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
			break;
        case 2: automovil->setMarca("Mazda"); 
		 	escogerTransmision(*automovil);
            escogerFrenos(*automovil);
            escogerTraccion(*automovil);
			break;
        case 3: automovil->setMarca("VolksWagen");
			escogerTransmision(*automovil);
            escogerFrenos(*automovil);
            escogerTraccion(*automovil);
			break;
        case 4: automovil->setMarca("Ford");
			escogerTransmision(*automovil);
            escogerFrenos(*automovil);
            escogerTraccion(*automovil);
			 break;
        case 5: automovil->setMarca("Lotus Elise");
			escogerTransmision(*automovil);
            escogerFrenos(*automovil);
            escogerTraccion(*automovil);
			break;
        case 6: automovil->setMarca("Audi");
			escogerTransmision(*automovil);
            escogerFrenos(*automovil);
            escogerTraccion(*automovil);
			break;
        default: cout<<"Marca no disponible"<<endl; break;
        }
        break;
        
    case 4:
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
				break;
        case 2: automovil->setMarca("Subaru");
        		escogerTransmision(*automovil);
            	escogerFrenos(*automovil);
            	escogerTraccion(*automovil);
				break;
        case 3: automovil->setMarca("Peugout"); 
				escogerTransmision(*automovil);
            	escogerFrenos(*automovil);
            	escogerTraccion(*automovil);
				break;
        case 4: automovil->setMarca("Kia"); 
				escogerTransmision(*automovil);
            	escogerFrenos(*automovil);
            	escogerTraccion(*automovil);
				break;
        default: cout<<"Marca no disponible"<<endl; break;
        }
        break;
        
    case 5:
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
			break;
        case 2: automovil->setMarca("Ford"); 
			escogerTransmision(*automovil); 
            escogerFrenos(*automovil);
            escogerTraccion(*automovil);
			break;
        case 3: automovil->setMarca("Mitsubishi"); 
			escogerTransmision(*automovil); 
            escogerFrenos(*automovil);
            escogerTraccion(*automovil);
			break;
        case 4: automovil->setMarca("Nissan"); 
			escogerTransmision(*automovil); 
            escogerFrenos(*automovil);
            escogerTraccion(*automovil);
			break;
        case 5: automovil->setMarca("Toyota"); 
			escogerTransmision(*automovil); 
            escogerFrenos(*automovil);
            escogerTraccion(*automovil);
			break;
        default: cout<<"Marca no disponible"<<endl; break;
        }
        break;
        
    case 6:
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
				break;
        case 2: automovil->setMarca("Ford");
				escogerTransmision(*automovil);
            	escogerFrenos(*automovil);
            	escogerTraccion(*automovil); 
				break;
        case 3: automovil->setMarca("Honda");
				escogerTransmision(*automovil);
            	escogerFrenos(*automovil);
            	escogerTraccion(*automovil); 
				break;
        case 4: automovil->setMarca("Hyundai"); 
				escogerTransmision(*automovil);
            	escogerFrenos(*automovil);
            	escogerTraccion(*automovil);
				break;
        case 5: automovil->setMarca("Mazda"); 
				escogerTransmision(*automovil);
            	escogerFrenos(*automovil);
            	escogerTraccion(*automovil);
				break;
        case 6: automovil->setMarca("Nissan"); 
				escogerTransmision(*automovil);
            	escogerFrenos(*automovil);
            	escogerTraccion(*automovil);
				break;
				
        default: cout<<"Marca no disponible"<<endl; break;
        }
    default:
        cout<<"Opcion no disponible"<<endl;
        break;
    }
    return *automovil;
}

void escogerTransmision(Vehiculo&v) {
    int res;
    cout<<"1.- Manual"<<endl;
    cout<<"2.- Automatica"<<endl;
    cout<<"Tipo de tranmision: "<<endl;
    cin>>res;
    switch(res) {
        case 1: v.setTransmision("Manual"); break;
        case 2: v.setTransmision("Automatica"); break;
        default: cout<<"Opcion no disponible"<<endl; break;
    }
}

void escogerFrenos(Vehiculo&v) {
    int res;
    cout<<"1.- Disco"<<endl;
    cout<<"2.- Tambor"<<endl;
    cout<<"3.- ABS"<<endl;
    cout<<"Tipo de frenos: "<<endl;
    cin>>res;
    switch(res) {
        case 1: v.setFrenos("Disco"); break;
        case 2: v.setFrenos("Tambor"); break;
        case 3: v.setFrenos("ABS"); break;
        default: cout<<"Opcion no disponible"<<endl; break;
    }
}

void escogerTraccion(Vehiculo&v) {
    int res;

    if(v.getTipoVehiculo() == "PickUp" || v.getTipoVehiculo() == "Familiar") {
        cout<<"1.- Delantera"<<endl;
        cout<<"2.- 4x4"<<endl;
        cout<<"Tipo de frenos: "<<endl;
        cin>>res;
        switch(res) {
            case 1: v.setTraccion("Delantera"); break;
            case 2: v.setTraccion("4x4"); break;
            default: cout<<"Opcion no disponible"<<endl; break;
        }
    }
    else {
        cout<<"1.- Delantera"<<endl;
        cout<<"2.- Tracera"<<endl;
        cout<<"Tipo de frenos: "<<endl;
        cin>>res;
        switch(res) {
            case 1: v.setTraccion("Delantera"); break;
            case 2: v.setTraccion("Tracera"); break;
            default: cout<<"Opcion no disponible"<<endl; break;
        }
    }
    
}

// void pedirDatosAuto(Vehiculo automovil) {
//     automovil.setNumCilindros();
//     automovil.setTransmision();
//     automovil.setChasis();
//     automovil.setFrenos();
//     automovil.setTraccion();
//     automovil.setSuspension();
//     automovil.setMarca();
//     automovil.setColor();
//     automovil.setRin();
//     automovil.setLlanta();
//     automovil.setModelo();
//     automovil.setPrecio();
//     automovil.setTipoVehiculo()
// }


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

int iniciarSesion(Administrador admin[], int&nAdmin) {
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
            // //Men√∫ de administrador normal + poder agregar otro administrador
            // cout<<"1.- Agregar un administrador"<<endl;
            // cin>>res;
            // switch(res) {
            //     case 1:
            //         admin[nAdmin] = crearAdministrador();
            //         nAdmin++;
            //         cout<<"Administrador creado"<<endl;
            //         break;
            //     default:
            //         cout<<"Opcion no establecida"<<endl;
            //         break;
            // }
        }
        else if((datos1 == admin[indice].getId()) && (datos2 == admin[indice].getPassword())) {
            cout<<"Acceso consedido"<<endl;
        }
        else{
            cout<<"Acceso denegado"<<endl;
        }
    }
    
    return indice;
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

void menuSuperAdministrador(Administrador admin[], int&nAdmin){
    Entrada entrada;
    do{
        cout<<"Opciones de super administrador"<<endl;
        cout<<"1.- Agregar un administrador"<<endl;
        cout<<"2.- Mostrar los administradores"<<endl;
        cout<<"3.- Regresar al menu principal"<<endl;
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
            case 3: break;
            default:
                cout<<"Opcion no establecida"<<endl;
                break;
        }
    }
    while(entrada.entero != 3);
}
