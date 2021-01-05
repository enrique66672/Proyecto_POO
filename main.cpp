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
                //Menú de administrador normal
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
            // //Menú de administrador normal + poder agregar otro administrador
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
