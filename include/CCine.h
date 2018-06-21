#ifndef CCINE_H
#define CCINE_H

#include "Cine.h"
#include "../include/DtCine.h"
#include "DtFuncion.h"
#include "Funcion.h"
#include "../interfaces/ICollection.h"
#include "../interfaces/ICine.h"
#include "../collections/List.h"

#include <string>
#include <stdlib.h>

using namespace std;

//class Funcion;

class CCine: public ICine
{
private:
	//datos
	//links
	Funcion *funcionSeleccionada;
	Cine *cineSeleccionado;
	ICollection *cinesRegistrados;

	static CCine *Instancia;
	CCine() {
		funcionSeleccionada = NULL;
		cineSeleccionado = NULL;
		cinesRegistrados = new List();
	};
public:
	//operaciones
	void seleccionarCine(DtCine* dtCine);
	void addCine(DtCine* dtCine);
	void addSala(int idc, int ids, int capacidadSala);
	void addCine(Cine *c);
	//set(DtFuncion)
	ICollection *listarFunciones();
	void seleccionarFuncion(DtFuncion* dtFuncion);
	//getters
	Funcion* getFuncionSeleccionada(); 
	Cine *getCineSeleccionado();
	string getDireccion(int idCine);
	//setters
	void setFuncionSeleccionada(Funcion * fs);
	void setCineSeleccionado(Cine*);
	ICollection* getCinesRegistrados();
	void setSalas(ICollection*, DtCine*);
	//constructores y destructor
	static CCine *getInstancia();
	~CCine();
};

#endif