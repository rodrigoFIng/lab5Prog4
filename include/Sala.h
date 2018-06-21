#ifndef SALA_H
#define	SALA_H

#include "../interfaces/ICollection.h"
#include "../interfaces/ICollectible.h"
#include "DtFuncion.h"
//#include "Pelicula.h"

#include <string>
#include <stdlib.h>

using namespace std;

class Sala: public ICollectible{
private:
	int idCine, idSala;
	int capacidad;
	ICollection *funciones;
public:
	void setIdSala(int idSala);
	void setCapacidad(int capacidad);
	//void addFunciones(DtFuncion, Pelicula *);
	int getIdSala();
	int getIdCine();
	int getCapacidad();
	ICollection* getFunciones();
	Sala(int idc, int ids, int cap);
	~Sala();
};
#endif