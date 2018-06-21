#include "../include/DtFuncion.h"

DtFuncion::DtFuncion(int idCine, int idSala, int idFuncion, Fecha fecha, Hora horario) {
	this->idCine = idCine;
	this->idSala = idSala;
	this->idFuncion = idFuncion;
	this->fecha = fecha;
	this->horario = horario;
}

void DtFuncion::setIdCine(int idCine) {
	this->idCine = idCine;
}

void DtFuncion::setIdSala(int idSala) {
	this->idSala = idSala;
}

void DtFuncion::setIdFuncion(int idFuncion) {
	this->idFuncion = idFuncion;
}

void DtFuncion::setFecha(Fecha fecha) {
	this->fecha = fecha;
}

void DtFuncion::setHorario(Hora horario) {
	this->horario = horario;
}


int DtFuncion::getIdCine() {
	return this->idCine;
}

int DtFuncion::getIdSala() {
	return this->idSala;
}

int DtFuncion::getIdFuncion() {
	return this->idFuncion;
}

Fecha DtFuncion::getFecha() {
	return this->fecha;
}

Hora DtFuncion::getHorario() {
	return this->horario;
}


DtFuncion::~DtFuncion() {}

