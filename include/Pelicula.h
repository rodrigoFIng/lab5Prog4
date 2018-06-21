#ifndef PELICULA_H
#define PELICULA_H

#include "../collections/List.h"
#include "../interfaces/ICollectible.h"
#include "../interfaces/IDictionary.h"
#include "DtPelicula.h"
#include "DtComentario.h"
#include "DtCine.h"
#include "Cine.h"
#include "Puntaje.h"
#include "Comentario.h"

#include <string>
#include <iostream>

using namespace std;

class Pelicula: public ICollectible
{
private:
	//datos
	string titulo;
	string poster;
	string sinopsis;
	float puntajePromedio;
	//links
	ICollection* puntajes;
	ICollection* cines;
	IDictionary* comentarios;
public:
	//getters
	string getTitulo();
	string getPoster();
	string getSinopsis();
	float getPuntajePromedio();
	ICollection* getCines();
	ICollection* getPuntajes();
	IDictionary* getComentarios();
	//setters
	void setTitulo(string tituloNuevo);
	void setPoster(string posterNuevo);
	void setSinopsis(string sinopsisNuevo);
	//operaciones
	void calcularPuntajePromedio();
	void addComentario(Comentario *c);
	//constructores y destructores
	Pelicula(string tituloNuevo, string posterNuevo, string sinopsisNuevo);
	//Pelicula();
	virtual ~Pelicula();
};

#endif