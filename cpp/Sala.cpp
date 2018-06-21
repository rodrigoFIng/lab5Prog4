#include "../include/Sala.h"

#include "../include/DtFuncion.h"
#include "../interfaces/ICollection.h"
#include "../interfaces/IIterator.h"
#include "../collections/List.h"
#include "../include/Funcion.h"

void Sala::setIdSala(int idSala){
	this->idSala = idSala;
}

void Sala::setCapacidad(int capacidad){
	this->capacidad = capacidad;
}

ICollection* Sala::getFunciones(){
	ICollection* dtFunciones = new List();

	for(IIterator* it = funciones->getIterator(); it->hasCurrent(); it->next()){
	Funcion *f = dynamic_cast<Funcion*>(it->getCurrent());
	DtFuncion *dtFuncion = new DtFuncion(f->getIdCine(), f->getIdSala(), f->getIdFuncion(), f->getFecha(), f->getHorario());
	
	dtFunciones->add(dtFuncion);
	}

	return dtFunciones;
}

int Sala::getIdCine() {
	return idCine;
}

int Sala::getIdSala() {
	return idSala;
}

/*
void Sala::addFunciones(DtFuncion dtFuncion, Pelicula *p){
	//Si es el primer usuario
	if (this->funciones == NULL)
		this->funciones = new List();
	Funcion *f = new Funcion(dtFuncion.getIdCine(), dtFuncion.getIdSala(), dtFuncion.getIdFuncion(), 
							dtFuncion.getFecha(), dtFuncion.getHorario(), p);
	this->funciones->add(f);
}*/

int Sala::getCapacidad(){
	return capacidad;
}

Sala::Sala(int idc, int ids, int cap){
	this->idSala = ids;
	this->capacidad = cap;
	this->funciones = new List();
	idCine = idc;
};

Sala::~Sala() {
	
}