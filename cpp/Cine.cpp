#include "../include/Cine.h"
#include "../include/Sala.h"
#include "../include/DtSala.h"
#include "../interfaces/ICollection.h"
#include "../collections/List.h"
#include "../interfaces/IIterator.h"

#include <string>
#include <stdlib.h>

using namespace std;

void Cine::setIdCine(int idCine){
	this->idCine = idCine;
}

void Cine::setDireccion(string direccion){
	this->direccion = direccion;
}

int Cine::getIdCine(){
	return idCine;
}

string Cine::getDireccion(){
	return direccion;
}

DtCine Cine::getInfoCine(){
	return DtCine(idCine, direccion, precioEntrada);
}

ICollection* Cine::getSalas(){
	ICollection* dtSalas = new List();

	for(IIterator* it = salas->getIterator(); it->hasCurrent(); it->next()){
	Sala *s = dynamic_cast<Sala*>(it->getCurrent());
	DtSala* dtSala = new DtSala(s->getIdSala(), s->getCapacidad());
	
	dtSalas->add(dtSala);

	}
	return dtSalas;
	
}

/*
void Cine::setSalas(DtSala *dtSala){
	//Si es el primer usuario
	if (this->salas == NULL)
		this->salas = new List();
	Sala *s = new Sala(dt, dtSala->getIdSala(), dtSala->getCapacidad());
	this->salas->add(s);
}*/

Cine::Cine(int idCine, string direccion, int pe){
	this->idCine = idCine;
	this->direccion = direccion;
	precioEntrada = pe;
	this->salas = new List();
}

Cine::~Cine() {
	
}

void Cine::addSala(Sala *s) {
	salas->add(s);
}