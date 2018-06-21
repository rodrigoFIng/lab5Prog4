#include "../include/DtSala.h"

#include "../interfaces/ICollection.h"
#include "../interfaces/IIterator.h"

#include <stdlib.h>

using namespace std;

void DtSala::setIdSala(int idSala){
	this->idSala = idSala;
}

void DtSala::setCapacidad(int capacidad){
	this->capacidad = capacidad;
}

int DtSala::getCapacidad(){
	return capacidad;
}

int DtSala::getIdSala(){
	return idSala;
}

DtSala::DtSala(int idSala, int capacidad){
	this->idSala = idSala;
	this->capacidad = capacidad;
};

DtSala::~DtSala() {

}