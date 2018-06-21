#include "../include/Hora.h"

Hora::Hora(int horas, int minutos) {
	this->horas = horas;
	this->minutos = minutos;
}

int Hora::getHoras() {
	return this->horas;
}

int Hora::getMinutos() {
	return this->minutos;
}

Hora::~Hora() {}

