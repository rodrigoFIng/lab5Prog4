#include "../include/Funcion.h"
#include "../include/Fecha.h"
#include "../include/Hora.h"
#include "../include/Reserva.h"

Funcion::Funcion() {
	this->Reservas = new List();
}

Funcion::Funcion(int idc, int ids, int idf, Fecha f, Hora h, Pelicula *p, int dur) {
	this->idCine = idc;
	this->idSala = ids;
	this->idFuncion = idf;
	this->fecha = f;
	this->horario = h;
	duracion = dur;
	this->peli = p;
	this->Reservas = new List();
}

Funcion::Funcion(int idf, Fecha f, Hora h, int dur, Pelicula *p, Sala *s) {
	idCine = s->getIdCine();
	idSala = s->getIdSala();
	idFuncion = idf;
	fecha = f;
	horario = h;
	duracion = dur;
	peli = p;
	Reservas = new List();
	s->getFunciones()->add(this);
}

void Funcion::setIdCine(int idCine) {
	this->idCine = idCine;
}

void Funcion::setIdSala(int idSala) {
	this->idSala = idSala;
}

void Funcion::setIdFuncion(int idFuncion) {
	this->idFuncion = idFuncion;
}

void Funcion::setFecha(Fecha fecha) {
	this->fecha = fecha;
}

void Funcion::setHorario(Hora horario) {
	this->horario = horario;
}

void Funcion::setPeli(Pelicula *peli) {
	this->peli = peli;
}


void Funcion::addReserva(Reserva *r) {
	this->Reservas->add(r);
}

int Funcion::getIdCine() {
	return this->idCine;
}

int Funcion::getIdSala() {
	return this->idSala;
}

int Funcion::getIdFuncion() {
	return this->idFuncion;
}

Fecha Funcion::getFecha() {
	return this->fecha;
}

Hora Funcion::getHorario() {
	return this->horario;
}

Pelicula *Funcion::getPeli() {
	return this->peli;
}

ICollection *Funcion::getReservas() {
	return this->Reservas;
}


bool Funcion::comparar(string titulo) {
	return titulo == peli->getTitulo();
}


Funcion::~Funcion() {}
