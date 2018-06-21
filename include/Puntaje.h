#ifndef PUNTAJE_H
#define PUNTAJE_H

#include "../interfaces/ICollectible.h"
//#include "Usuario.h"
//#include "Pelicula.h"

class Usuario;
class Pelicula;

class Puntaje: public ICollectible
{
private:
	//datos
	int puntaje;
	//links
	Usuario *usuario;
	Pelicula *pelicula;
public:
	//constructor y destructor
	Puntaje(int ptj, Usuario *u, Pelicula *p);
	virtual ~Puntaje();
	//getters
	int getPuntaje();
	Usuario *getUsuario();
	Pelicula *getPelicula();
	//setters
	void setPuntaje(int ptj);
	//operaciones
};

#endif