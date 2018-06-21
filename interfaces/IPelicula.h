#pragma once
#include "../interfaces/ICollection.h"
#include "../include/Pelicula.h"
class IPelicula
{
public:

	//Sobre pelicula
	virtual void agregarPelicula(DtPelicula *) =0;
	virtual Pelicula* obtenerPelicula(string) =0;
	virtual string verPosterPelicula(string) =0;
	virtual string verSinopsisPelicula(string) =0;
	virtual ICollection* infoAdicionalPelicula(string) =0;

	virtual ICollection* listarPeliculas() =0;
	virtual void eliminarPelicula(string) =0;

	virtual void addcomentario(int, string) =0;
	virtual bool puntuarPelicula(string, string, int) =0;
	virtual int mostrarPuntaje(string, string) =0;
	virtual void modificarPuntaje(string, string, int) =0;

	virtual Pelicula* getPeliculaSeleccionada() =0;

	IPelicula();
	~IPelicula();
};

