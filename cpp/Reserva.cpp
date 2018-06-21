#include "../include/Reserva.h"
#include "../include/Funcion.h"

#include <string>
#include <stdlib.h>

using namespace std;

//-------------Reserva-------------//

//constructor y destructor
Reserva::~Reserva() {};
//getters
int Reserva::getCantAsientos() {
	return cantAsientos;
};
float Reserva::getCostoTotal() {
	return costoTotal;
};
Funcion* Reserva::getFuncionReservada() {
	return funcionReservada;
};
//setters
void Reserva::setCantAsientos(int ca) {
	cantAsientos = ca;
};
void Reserva::setFuncionReservada(Funcion *f) {
	funcionReservada = f;
};
//operaciones

//-------------Debito-------------//

//constructor y destructor
Debito::~Debito() {};
//getters
string Debito::getBanco() {
	return banco;
};
//setters
void Debito::setBanco(string b) {
	banco = b;
};
//operaciones
int Debito::getDescuento() {
	return 0;
};

float Debito::calcularCostoTotal() {
	costoTotal = getCantAsientos()*precioEntrada();
	return costoTotal;
};

//-------------Credito-------------//

//constructor y destructor
Credito::~Credito() {};
//getters
string Credito::getFinanciera() {
	return financiera;
};

int Credito::getDescuento() {
	return descuento;
};
//setters
void Credito::setFinanciera(string f) {
	financiera = f;
	descuento = descuentoFinanciera(f);
	calcularCostoTotal();
};
//operaciones
float Credito::calcularCostoTotal() {
	float precio = getCantAsientos()*precioEntrada();
	costoTotal = precio - descuento*precio/100;
	return costoTotal;
};