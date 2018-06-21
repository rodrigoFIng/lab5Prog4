#include "../include/Fecha.h"
#include "../include/Hora.h"
#include "../interfaces/IReserva.h"
#include "../interfaces/IUsuario.h"
#include "../interfaces/IPelicula.h"
#include "../interfaces/ICine.h"
#include "../include/Fabrica.h"
#include "../include/Reloj.h"
#include "../include/DatosPrueba.h"

#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//Fabrica
Fabrica *fabrica = Fabrica::getInstancia();
//controladores

/*
CUsuario *cu;
cu = CUsuario::getInstancia();
CCine *cc;
cc = CCine::getInstancia();
*/

//CReserva *cr = new CReserva(cu, cc);
IReserva *ir = fabrica->ObtenerIReserva();
IUsuario *iu = fabrica->ObtenerIUsuario();
IPelicula *ip = fabrica->ObtenerIPelicula();
ICine *ic = fabrica->ObtenerICine();

void iniciarSesion() {
cout << "//-------------------- Iniciar Sesion -----------------//\n\n";

	cout << "Ingrese su Nickname: ";
	string nick;
	cin >> nick;
	bool existe = iu->IngresarNickname(nick);
	if (!existe)
	{
		cout << "No hay ningun Usuario registrado con ese Nickname\n\n";
	} else {
		bool exito = false;
		bool cancela = false;
		while (!exito && !cancela) {
			cout << "\n1- Ingresar Contrasena nuevamente\n";
			cout << "2 - Cancelar Inicio de Sesion\n\n";
			cout << "Ingrese una opcion: ";
			int opcion = -1;
			cin >> opcion;

			switch (opcion) {
				case 1: {
					cout << "Ingrese su Contrasena: ";
					string pass;
					cin >> pass;
					exito = iu->IniciarSesion(pass, nick);
					if (exito)
					{
						cout << "Bienvenido, " << nick << "!\n\n";
					} else {
						cout << "Contrasena incorrecta\n\n";
					};
					break;
				};
				case 2: {
					cancela = true;
					break;
				};
			}
		};
	}
};

void verInfoPelicula() {
cout << "//-------------------- Ver Informacion de Pelicula -----------------//\n\n";
	bool salir = false;
	while(!salir){
		//listo Peliculas
		ICollection* dtPeliculas = ip->listarPeliculas();
		int i = 1;
		
		if (dtPeliculas->isEmpty()){
			cout << "No existen peliculas" << endl << endl;
			salir = true;
		}else{

		//Ver peliculas		
		for(IIterator* it = dtPeliculas->getIterator(); it->hasCurrent(); it->next()){
		DtPelicula *p = dynamic_cast<DtPelicula*>(it->getCurrent());
		cout << i << " - " << p->getTitulo() << endl;
		i++;
		}


		cout << i <<" - Salir al menu principal" << endl;
		cout << endl <<"Seleccionar opcion: ";
		int opcion;
		cin >> opcion;
		cout << endl;

		//Poster Sinopsis o Salir
		if (opcion > i || opcion <= 0)
				cout << "Opcion no valida" << endl << endl;
		else
			if (opcion == i){
			for(IIterator* it = dtPeliculas->getIterator(); it->hasCurrent(); it->next()){
				DtPelicula* dtPelicula = dynamic_cast<DtPelicula*>(it->getCurrent());
				dtPeliculas->remove(dtPelicula);
			}
			delete dtPeliculas;
			salir = true;
		}
		else {
			cout << "-------------";
			//Seteo pelicula seleccionada
			IIterator* it = dtPeliculas->getIterator();
			
			if (i > 1){
			for (int i = 1; i < opcion; i++)
				it->next();
			}

			DtPelicula *ps = dynamic_cast<DtPelicula*>(it->getCurrent());
			//guardo la pelicula seleccionada en CPelicula
			ip->setPeliculaSeleccionada(ps);		
			
			cout << "Poster: " << ip->verPosterPelicula(ps->getTitulo()) << endl;
			cout << "Sinopsis: " << ip->verSinopsisPelicula(ps->getTitulo()) << endl;
			cout << "1 - " <<"Salir al menu principal" << endl;
			cout << "2 - " <<"Ver informacion adicional" << endl << endl;
			cout << endl <<"Seleccionar opcion: ";
			cin >> opcion ;

			bool fin = false;

			while(!fin){
				cout << "Poster: " << ip->verPosterPelicula(ps->getTitulo()) << endl;
				cout << "Sinopsis: " << ip->verSinopsisPelicula(ps->getTitulo()) << endl;
				cout << "1 - " <<"Salir al menu principal" << endl;
				cout << "2 - " <<"Ver informacion adicional" << endl << endl;
				cout << endl <<"Seleccionar opcion: ";
				cin >> opcion ;
				
				switch (opcion) {
					case 1:{
						salir = true;
						fin = true;
						break;
					}
					case 2:{
						ICollection* dtCines = ip->infoAdicionalPelicula(ps->getTitulo());
						cout << "Cines disponibles:" << endl; 
						int j = 1;
						for(IIterator* it = dtCines->getIterator(); it->hasCurrent(); it->next()){
							DtCine* dtc = dynamic_cast<DtCine*>(it->getCurrent());
							cout << j << " - " << dtc->getDireccion();
							j++;
						}

						cout << j <<" - Salir al menu principal" << endl << endl;
						cout << endl <<"Seleccionar opcion: ";
						int opt;
						cin >> opt;
						
						while (opt > j || opt <= 0)
							cout << "Opcion no valida" << endl;
						if (opt == j)
							salir = true;
						else {
							ICollection* dtCines = ip->infoAdicionalPelicula(ip->getPeliculaSeleccionada()->getTitulo());
							//Seteo pelicula seleccionada
							IIterator* it = dtCines->getIterator();
							for (int j = 1; j <= opt; j++)
								it->next();

							DtCine *cs = dynamic_cast<DtCine*>(it->getCurrent());
							//guardo la pelicula seleccionada en CPelicula
							ic->setCineSeleccionado(cs);

							//Funciones para el Cine seleccionado					
							ICollection* dtFunciones = ic->listarFunciones();
							Reloj* reloj = Reloj::getInstance();

							cout << "Funciones:" <<endl;

							for(IIterator* it = dtFunciones->getIterator(); it->hasCurrent(); it->next()){
							DtFuncion* dtf = dynamic_cast<DtFuncion*>(it->getCurrent());
							
							int anio = dtf->getFecha().getAnio();
							int mes = dtf->getFecha().getMes();
							int dia = dtf->getFecha().getDia();


							if (anio > reloj->getAnio())
							
								cout << "- " << "Sala nro: '"<< dtf->getIdSala() << " - Funcion nro: " << dtf->getIdFuncion() << " - Fecha: " << anio << "/" << mes << "/" << dia << " - Hora: " << dtf->getHorario().getHoras() << "/" << dtf->getHorario().getMinutos()<< endl; 
							
							else if (anio == reloj->getAnio() && mes > reloj->getMes())
								cout << "- " << "Sala nro: '"<< dtf->getIdSala() << " - Funcion nro: " << dtf->getIdFuncion() << " - Fecha: " << anio << "/" << mes << "/" << dia << " - Hora: " << dtf->getHorario().getHoras() << "/" << dtf->getHorario().getMinutos()<< endl; 
							
							else if (mes == reloj->getMes() && dia >= reloj->getDia())
								cout << "- " << "Sala nro: '"<< dtf->getIdSala() << " - Funcion nro: " << dtf->getIdFuncion() << " - Fecha: " << anio << "/" << mes << "/" << dia << " - Hora: " << dtf->getHorario().getHoras() << "/" << dtf->getHorario().getMinutos()<< endl;
						}
						}
						fin = true;
						break;
					}
					default : {
						cout << "Opcion no valida\n\n";
						break;
					};
			}
			}

		}
		}
	}
};

void crearReserva() {

cout << "//-------------------- Crear Reserva -----------------//\n\n";

	verInfoPelicula();

	cout << "Ingrese la cantidad de asientos a reservar: ";
	int cantAsientos;
	cin >> cantAsientos;
	ir->ingresarCantAsientos(cantAsientos);

	cout << "\n1- Credito\n";
	cout << "2- Debito\n\n";
	cout << "Ingrese forma de pago: ";
	int opcionPago;
	cin >> opcionPago;
	cout << endl;

	switch (opcionPago) {
		case 1: {
				//paga con credito
				ir->crearCredito();

				cout << "Ingrese el nombre de la Financiera: ";
				string financiera;
				cin >> financiera;
				bool tieneDescuento = ir->ingresarFinanciera(financiera);
				if (tieneDescuento)
				{
					int descuento = ir->verDescuento();
					cout << "Descuento: " << descuento << "%\n";
				};
			break;
			};
		case 2: {
				//paga con debito
				ir->crearDebito();

				cout << "Ingrese el nombre del Banco: ";
				string banco;
				cin >> banco;
				ir->ingresarBanco(banco);
			break;
			};
	};
	cout << "Costo Total: " << ir->verCostoTotal() << endl << endl;
	cout << "1- Confirmar\n";
	cout << "0- Cancelar\n\n";
	cout << "Desea confirmar su Reserva?: ";
	int opcionConfirmar;
	cin >> opcionConfirmar;
	switch (opcionConfirmar) {
		case 1: {
			//confirma la reserva
				ir->confirmarReserva();
				cout << "Reserva creada!!\n\n";
			break;
			};
		case 0: {
				//cancela la reserva
				ir->cancelarReserva();
				cout << "Reserva cancelada.\n\n";
			break;
			};
	};
};

void altaCine() {
cout << "//-------------------- Alta Cine -----------------//\n\n";
	bool salir = false;
	string direccion;
	int cantSalas;
	while(!salir){
		cout << "Ingrese la direccion del cine: " ;
		cin >> direccion;
	
		DtCine* dtCine = new DtCine(0, direccion);

		cout << "ingrese cantidad de salas a ingresar: ";
		cin >> cantSalas;

		int capacidad;
		ICollection* dtSalas = new List();

		for (int idSala = 1; idSala <= cantSalas; idSala++){
		cout << "Ingrese la capacidad de la sala " << idSala << ": ";
		cin >> capacidad;
		DtSala* dtSala = new DtSala(idSala, capacidad);
		dtSalas->add(dtSala);
		}

		
		bool fin = false;
		int opcion = 0;
		while(!fin){
			cout << "1 - Confirmar ";
			cout << endl;
			cout << "2 - Cancelar e ingresar un nuevo cine";
			cout << endl;
			cout << "3 - Cancelar e ir al menu principal";
			cout << endl;
			cout << "Ingresar opcion: ";
			cout << "------------------------------------------";
			cout << endl;
			cin >> opcion;
			cout << endl;
			cout << "------------------------------------------";

			switch (opcion) {
				case 1:{
					ic->addCine(dtCine);
					ic->setSalas(dtSalas, dtCine);
					fin = true;
					break;
				}
				case 2:{
					for(IIterator* it = dtSalas->getIterator(); it->hasCurrent(); it->next()){
						DtSala* dtSala = dynamic_cast<DtSala*>(it->getCurrent());
						dtSalas->remove(dtSala);
					}
					delete dtSalas;
					delete dtCine;
					fin = true;
					break;
				}
				case 3:{
					fin = true;
					salir = true;
				}
				default:{
					cout << "Opcion no valida" << endl << endl;
					break;
				}
			}
		}
	}
};

void altaFuncion() {
cout << "//-------------------- Alta Funcion -----------------//\n\n";
};

void puntuarPelicula() {
cout << "//-------------------- Puntuar Pelicula -----------------//\n\n";

	
};

void comentarPelicula() {
cout << "//-------------------- Comentar Pelicula -----------------//\n\n";
};

void verComsYPtjPelicula() {
cout << "//-------------------- Ver Comentarios y Puntaje de Pelicula -----------------//\n\n";
};

void eliminarPelicula() {
cout << "//-------------------- Eliminar Pelicula -----------------//\n\n";
	try{
		//if (iu->esAdmin()) {
			//Listar peliculas
			ICollection *pelis = ip->listarPeliculas();

			if (pelis == NULL) 
				cout << "No hay peliculas registradas" << endl;
			else {
				int list_num = 0;
				for (IIterator *it = pelis->getIterator(); it->hasCurrent(); it->next()) {
					list_num++;
					DtPelicula *p = dynamic_cast<DtPelicula *>(it->getCurrent());
					cout << list_num << "- " << p->getTitulo() << endl;
				}
				int sel = 0;
				cout << endl;

				bool fin_sel = false;
				while (!fin_sel){
					cout << "Seleccione pelicula a eliminar: ";
					cin >> sel;

					if  (sel < 1 || sel > list_num) {
						cout << endl;
						throw invalid_argument("Seleccion incorrecta");
						cout << endl;
					} else {
						IIterator *it2 = pelis->getIterator();

						for (int i=1; i<sel ; i++) {
								it2->next();
						}
						DtPelicula *p2 = dynamic_cast<DtPelicula *>(it2->getCurrent());
						cout << endl;
						cout << "Pelicula a eliminar: " << p2->getTitulo() << endl << endl;
						cout << "1- Confirmar" << endl;
						cout << "2- Salir" << endl;
						cout << endl;

						bool fin_sel2 = false;
						int sel2;
						while (!fin_sel2) {
							cout << "Seleccion: ";
							cin >> sel2;
							cout << endl;

							if (sel2 == 2) {      // Desea salir del caso
								fin_sel = true;
								fin_sel2 = true;
							} else 
							if (sel2 == 1) {      // Desea eliminar pelicula
								ip->eliminarPelicula(p2->getTitulo());
								fin_sel = true;
								fin_sel2 = true;
								cout << "Pelicula eliminada correctamente." << endl;
								cout << endl;
							} else {
								throw invalid_argument("Seleccion incorrecta");
								cout << endl;
							}
						}
					}
				}    
			}
		//} else {
		//	cout << "No es administrador." << endl << endl;
		//}
	}
	catch(exception& e) {
		cout << "Problema al eliminar Pelicula: " << e.what() << endl << endl;
	}
};

void verReservas() {
cout << "//-------------------- Ver Reservas -----------------//\n\n";
	/*ICollection* reservas = iu->getUsuarioActual()->reservasRealizadas();

	if (reservas == NULL)
		cout << "No existen reservas" << endl;
	else {
		for(IIterator* it = reservas->getIterator(); it->hasCurrent(); it->next()){
			Reserva *r = dynamic_cast<Reserva*>(it->getCurrent());
			cout <<  "Titulo: "<< r->getTitulo() << endl;

			Funcion* f = r->getFuncionReservada();
			Fecha fecha = f->getFecha();
			cout <<  "Fecha: " << fecha.getDia() << "/" << fecha.getMes() << "/" << fecha.getAnio()<< endl;
			Hora hora = f->getHorario();
			cout <<  "Hora: " << hora.getHoras() << ":" << hora.getMinutos() << endl;
		
			cout <<  "Precio: " << r->getCostoTotal() << endl;
			cout <<  "Cantidad de asientos: " << r->getCantAsientos() << endl;
		
			//Credito o debito?
			Debito *debito = dynamic_cast<Debito*>(r);
			if (debito != NULL)		
				cout <<  "Tipo de compra: Debito" << endl;
			else cout <<  "Tipo de compra: Credito" << endl;

			int idCine = f->getIdCine();
			cout <<  "Cine:" << ic->getDireccion(idCine) << endl << endl;
		}
	}*/
	ICollection* reservas = iu->getUsuarioActual()->reservasRealizadas();

	if (reservas == NULL)
		cout << "No existen reservas" << endl;
	else {
		for(IIterator* it = reservas->getIterator(); it->hasCurrent(); it->next()){
			Reserva *r = dynamic_cast<Reserva*>(it->getCurrent());
			cout <<  "Titulo: "<< r->getTitulo() << endl;

			Funcion* f = r->getFuncionReservada();
			Fecha fecha = f->getFecha();
			cout <<  "Fecha: " << fecha.getDia() << "/" << fecha.getMes() << "/" << fecha.getAnio()<< endl;
			Hora hora = f->getHorario();
			cout <<  "Hora: " << hora.getHoras() << ":" << hora.getMinutos() << endl;
		
			cout <<  "Precio: " << r->getCostoTotal() << endl;
			cout <<  "Cantidad de asientos: " << r->getCantAsientos() << endl;
		
			//Credito o debito?
			Debito *debito = dynamic_cast<Debito*>(r);
			if (debito != NULL)		
				cout <<  "Tipo de compra: Debito" << endl;
			else cout <<  "Tipo de compra: Credito" << endl;

			int idCine = f->getIdCine();
			cout <<  "Cine:" << ic->getDireccion(idCine) << endl << endl;
		}
	}
};

void cerrarSesion() {
cout << "//-------------------- Cerrar Sesion -----------------//\n\n";
iu->CerrarSesion();
cout << "Se ha cerrado sesion correctamente " << endl << endl;
};

void setFechaHora() {
cout << "//-------------------- Establecer Fecha y Hora -----------------//\n\n";
	
	Reloj* reloj = Reloj::getInstance();
	cout << "Ingresar fecha con el formato [dd/mm/aaaa hh:mm]: ";
	char* fechaIngresada = new char[17];
	char a;
	for(int i = 0; i <= 17; i++){
		if (i != 11){
			cin >> a;
			fechaIngresada[i] = a;
		}//char vacio que jode
		else fechaIngresada[i] = ' ';
	}
	fechaIngresada[11] = ' ';
	cout << endl;
	reloj->modificarFecha(fechaIngresada);
};

void verFechaHora() {
cout << "//-------------------- Consultar Fecha y Hora -----------------//\n\n";

Reloj* reloj = Reloj::getInstance();
cout << "Fecha actual: ";
reloj->consultarFecha(); 
cout << endl;
};

void cerrarSistema() {
cout << "//-------------------- Cerrar Sistema -----------------//\n\n";
};

int main()
{
	cout << "\nBienvenido!\n\n";

	bool salir = false;

	while (!salir) {
		cout << " 1- Iniciar Sesion\n";
		cout << " 2- Crear Reserva\n";
		cout << " 3- Alta Cine\n";
		cout << " 4- Alta Funcion\n";
		cout << " 5- Puntuar Pelicula\n";
		cout << " 6- Comentar Pelicula\n";
		cout << " 7- Ver Informacion de Pelicula\n";
		cout << " 8- Ver Comentarios y Puntaje de Pelicula\n";
		cout << " 9- Eliminar Pelicula\n";
		cout << "10- Ver Reservas\n";
		cout << "11- Cerrar Sesion\n";
		cout << "12- Establecer Fecha y Hora\n";
		cout << "13- Consultar Fecha y Hora\n";
		cout << "14- Cargar Datos de Prueba\n";
		cout << " 0- Salir\n\n";

		cout << "Seleccione una opcion: ";
		int opcion = -1;
		cin >> opcion;
		cout << endl;

		switch (opcion) {
			case 1: {
				iniciarSesion();
				break;
			};
			case 2: {
				crearReserva();
				break;
			};
			case 3: {
				altaCine();
				break;
			};
			case 4: {
				altaFuncion();
				break;
			};
			case 5: {
				puntuarPelicula();
				break;
			};
			case 6: {
				comentarPelicula();
				break;
			};
			case 7: {
				verInfoPelicula();
				break;
			};
			case 8: {
				verComsYPtjPelicula();
				break;
			};
			case 9: {
				eliminarPelicula();
				break;
			};
			case 10: {
				verReservas();
				break;
			};
			case 11: {
				cerrarSesion();
				break;
			};
			case 12: {
				setFechaHora();
				break;
			};
			case 13: {
				verFechaHora();
				break;
			};
			case 14: {
				cargarDatos();
				break;
			};
			case 0: {
				cerrarSistema();
				salir = true;
				break;
			};
			default : {
				cout << "Opcion no valida\n\n";
				break;
			};
		}
	};
	
	cout << "FIN.\n\n";

return 0;
}