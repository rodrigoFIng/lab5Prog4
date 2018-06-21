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
	string fechaIngresada;
	cin >> fechaIngresada;
	reloj->modificarFecha(fechaIngresada);
};

void verFechaHora() {
cout << "//-------------------- Consultar Fecha y Hora -----------------//\n\n";

Reloj* reloj = Reloj::getInstance();
cout << "Fecha actual: " << reloj->consultarFecha() << endl;
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