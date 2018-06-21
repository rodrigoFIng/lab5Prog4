#include "../include/Reloj.h"

#include <string>

Reloj* Reloj::Instancia = NULL;

Reloj* Reloj::getInstance() {
	if (Instancia == NULL)
		Instancia = new Reloj();
	return Instancia;
}

int Reloj::getDia() {
	return fecha[1]*10 + fecha[2];
}

int Reloj::getMes() {
	return fecha[4]*10 + fecha[5];
}

int Reloj::getAnio() {
	return fecha[7]*1000 + fecha[8]*100 + fecha[9]*10 + fecha[10];
}

int Reloj::getHora(){
	return fecha[12]*10 + fecha[13];
}

int Reloj::getMinuto(){
	return fecha[15]*10 + fecha[16];
}	

void Reloj::modificarFecha(string fecha){
	this->fecha = fecha;
}	

string Reloj::consultarFecha(){
	return fecha;
}

Reloj::Reloj(string f) {
	fecha = f;
}

Reloj::~Reloj() {Instancia = NULL;}
