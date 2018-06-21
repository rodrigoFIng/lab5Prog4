#ifndef CINE_H
#define	CINE_H

#include "../interfaces/ICollection.h"
#include "../include/Sala.h"
#include "DtSala.h"
#include "DtCine.h"

#include <stdlib.h>

using namespace std;

class Cine: public ICollectible{
private:
	int idCine;
	int precioEntrada;
	string direccion;
	ICollection *salas;
public:
	void setIdCine(int idCine);
	void setDireccion(string direccion);
	//void setSalas(DtSala *dtSala);
	int getIdCine();
	string getDireccion();
	int getPrecioEntrada() {return precioEntrada;};
	DtCine getInfoCine();
	ICollection* getSalas();
	Cine(int idCine, string direccion, int pe);
	~Cine();

	void addSala(Sala *s);
};
#endif 