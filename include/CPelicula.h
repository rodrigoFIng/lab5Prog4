#ifndef _CPELICULA_H
#define	_CPELICULA_H

#include <string>
#include "DtPelicula.h"
#include "DtCine.h"
#include "../interfaces/ICollection.h"
#include "../collections/List.h"
#include "Pelicula.h"
#include "../interfaces/IPelicula.h"
using namespace std;

class CPelicula : public IPelicula
{
private:
	Pelicula *peliculaSeleccionada;
	ICollection* Peliculas;
	ICollection* DtPeliculas;
	static CPelicula* Instance;
	CPelicula();
public:

	//Sobre pelicula
	void agregarPelicula(DtPelicula *);
	Pelicula* obtenerPelicula(string);
	string verPosterPelicula(string);
	string verSinopsisPelicula(string);	
	ICollection* infoAdicionalPelicula(string);

	ICollection* listarPeliculas();
	void eliminarPelicula(string);

	void addcomentario(int, string);
	bool puntuarPelicula(string, string, int);
	int mostrarPuntaje(string, string);
	void modificarPuntaje(string, string, int);

	//peliculaSeleccionada
	Pelicula* getPeliculaSeleccionada() {return peliculaSeleccionada;};
	void setPeliculaSeleccionada(Pelicula *ps);

	static CPelicula* obtenerInstance();

	void addPelicula(Pelicula *p);
	
	~CPelicula();
};
#endif//CPELICULA_H

