#include "../include/CCine.h"

#include "../include/Funcion.h"
#include "../include/Sala.h"
#include "../include/CPelicula.h"
#include "../include/DtFuncion.h"
#include "../include/Fabrica.h"

#include <iostream>
#include <string>

using namespace std;

CCine *CCine::Instancia = NULL;

CCine *CCine::getInstancia() {
	if (Instancia == NULL)
		Instancia = new CCine();
	return Instancia;
};


//operaciones
void CCine::seleccionarCine(DtCine* dtCine){
	try{
		int idCineDt = dtCine->getIdCine();
		IIterator *iterator = this->cinesRegistrados->getIterator();
		ICollectible *IC = iterator->getCurrent();
		Cine *cine = dynamic_cast<Cine*>(IC);

		while (idCineDt != cine->getIdCine())
			{
				iterator->next();
				IC = iterator->getCurrent();
				cine = dynamic_cast<Cine*>(IC);
			}

		this->cineSeleccionado = cine;	
	}
	catch (out_of_range& oor) {
		//No hay mas usuarios en la lista
		throw oor;
	}
	catch (exception& e) {
		throw e;
	}
}

ICollection* CCine::listarFunciones(){
	//lista
	ICollection* dtFunciones = new List();	
	//pelicula seleccionada
	Fabrica *fabrica = Fabrica::getInstancia();
	IPelicula *ip = fabrica->ObtenerIPelicula();
	string pelicula = ip->getPeliculaSeleccionada()->getTitulo();
	//salas del cine
	ICollection* salas = this->getCineSeleccionado()->getSalas();
	//recorro las salas
	for(IIterator* its = salas->getIterator(); its->hasCurrent(); its->next()){
		ICollectible *IC = its->getCurrent();
		Sala *s = dynamic_cast<Sala*>(IC);
		//recorro las funciones de sala s
		for(IIterator* itf= s->getFunciones()->getIterator(); itf->hasCurrent(); itf->next()){
			IC = itf->getCurrent();
			Funcion *f = dynamic_cast<Funcion*>(IC);
			string peliculaFuncion = f->getPeli()->getTitulo();
			if (peliculaFuncion.compare(pelicula) == 0){
				DtFuncion *dtFuncion = new DtFuncion(f->getIdCine(), f->getIdSala(), f->getIdFuncion(), f->getFecha(), f->getHorario());
				dtFunciones->add(dtFuncion);
			}
		}
	}
	return dtFunciones;
}

void CCine::addSala(int idc, int ids, int capacidadSala) {
	cineSeleccionado->addSala(new Sala(idc, ids, capacidadSala));
}

void CCine::addCine(Cine *c) {
	cinesRegistrados->add(c);
};

void CCine::seleccionarFuncion(DtFuncion* dtFuncion){
	//idFuncion de dtFuncion
	int idFuncionDt = dtFuncion->getIdFuncion();

	//funciones del cine seleccionado
	ICollection* salas = this->getCineSeleccionado()->getSalas();
	
	IIterator* its = salas->getIterator();
	bool funcionEncontrada = false;
	//recorro las salas
	while (its->hasCurrent() && !funcionEncontrada){
		ICollection *funciones = dynamic_cast<Sala*>(its)->getFunciones();
		IIterator* itf = funciones->getIterator();
	//recorro las funciones
		while(itf->hasCurrent() && !funcionEncontrada){
			ICollectible* IC = itf->getCurrent();
			Funcion *f = dynamic_cast<Funcion*>(IC);
			if (idFuncionDt == f->getIdFuncion()){
				this->funcionSeleccionada = f;
				funcionEncontrada = true;
			}
			else itf->next();
		}
		its->next();
	}
}

//getters
Funcion* CCine::getFuncionSeleccionada() {
	return funcionSeleccionada;
};

Cine *CCine::getCineSeleccionado() {
	return cineSeleccionado;
};

string CCine::getDireccion(int idCine) {
	IIterator *it = cinesRegistrados->getIterator();
	bool encontrado = false;
	string s = "";
	while (it->hasCurrent() && !encontrado)
	{
		ICollectible *ic = it->getCurrent();
		Cine *c = dynamic_cast<Cine*>(ic);
		int i = c->getIdCine();
		if (i == idCine)
		{
			s = c->getDireccion();
			encontrado = true;
		};
		it->next();
	};
	return s;
};
//setters
void CCine::setFuncionSeleccionada(Funcion *fs) {
	funcionSeleccionada = fs;
};

void CCine::setCineSeleccionado(Cine *cs) {
	cineSeleccionado = cs;
};

void CCine::addCine(DtCine* dtCine){
		//Si es el primer usuario
	if (this->cinesRegistrados == NULL)
		this->cinesRegistrados = new List();
	Cine *c = new Cine(dtCine->getIdCine(), dtCine->getDireccion(), dtCine->getPrecioEntrada());
	this->cinesRegistrados->add(c);
};

//constructores y destructor


CCine::~CCine() {
};