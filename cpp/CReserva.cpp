#include "../include/CReserva.h"
#include "../include/CUsuario.h"
#include "../include/CCine.h"
#include "../include/Usuario.h"
#include "../include/Reserva.h"

#include <string>
#include <stdlib.h>
#include <iostream>

using namespace std;

CCine *cc;
CUsuario *cu;

//constructores y destructor
CReserva* CReserva::Instancia = NULL;

CReserva *CReserva::getInstancia() {
	if (Instancia == NULL)
		Instancia = new CReserva();
	return Instancia;
};

CReserva::~CReserva() {
	Instancia = NULL;
};

//getters
Reserva* CReserva::getReservaActual() {
	return reservaActual;
};
//setters
void CReserva::setReservaActual(Reserva *r) {
	reservaActual = r;
};
//operaciones
void CReserva::ingresarCantAsientos(int cantAsientosNuevo) {
	if (reservaActual != NULL)
	{
		reservaActual->setCantAsientos(cantAsientosNuevo);
	};
	cantAsientos = cantAsientosNuevo;
};

void CReserva::ingresarBanco(string banco) {
	reservaActual->setBanco(banco);
};

bool CReserva::ingresarFinanciera(string financiera) {
	reservaActual->setFinanciera(financiera);
	if (reservaActual->getDescuento() > 0)
	{
		return true;
	};
	return false;
};

int CReserva::verDescuento() {
	return reservaActual->getDescuento();
};

int CReserva::verCostoTotal() {
	return reservaActual->calcularCostoTotal();
};

void CReserva::confirmarReserva() {
	Reserva *ra = getReservaActual();
	Funcion *f = cc->getFuncionSeleccionada();
	Usuario *ua = cu->getUsuarioActual();

	ra->setFuncionReservada(f);
	ua->addReserva(ra);
	f->addReserva(ra);
};

void CReserva::cancelarReserva() {
	delete reservaActual;
	reservaActual = NULL;
};

void CReserva::crearCredito() {
	reservaActual = new Credito("f", cantAsientos);
};

void CReserva::crearDebito() {
	reservaActual = new Debito("b", cantAsientos);
};

