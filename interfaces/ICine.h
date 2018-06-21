#ifndef ICINE_H
#define	ICINE_H

//#include "../include/CCine.h"
#include <string>

#include "../include/Cine.h"
#include "../include/DtFuncion.h"
#include "../include/DtCine.h"
#include "../interfaces/ICollection.h"
#include "../include/Funcion.h"

using namespace std;

class ICine{
public: 
		//operaciones
	virtual void seleccionarCine(DtCine*) = 0;
	virtual void addCine(DtCine* dtCine) = 0;
	//set(DtFuncion)
	virtual ICollection *listarFunciones() = 0;
	virtual void seleccionarFuncion(DtFuncion*) = 0;
	//getters
	virtual Funcion *getFuncionSeleccionada() = 0;
	virtual Cine* getCineSeleccionado() =0;
	virtual string getDireccion(int idCine) =0;
	//setters
	virtual void setFuncionSeleccionada(Funcion*) = 0;
	virtual void setCineSeleccionado(Cine*) = 0;

	virtual void addSala(int idCine, int idSala, int capacidadSala) =0;
	virtual void addCine(Cine *c) =0;


	~ICine() {};
};

#endif