#include "../include/Puntaje.h"
#include "../include/Usuario.h"
#include "../include/Pelicula.h"

//constructor y destructor
Puntaje::Puntaje(int ptj, Usuario *u, Pelicula *p) {
	puntaje = ptj;
	usuario = u;
	pelicula = p;
	u->getPuntajes()->add(this);
	p->getPuntajes()->add(this);
};

Puntaje::~Puntaje() {

};

//getters
int Puntaje::getPuntaje() {
	return puntaje;
};

Usuario *Puntaje::getUsuario() {
	return usuario;
}

Pelicula *Puntaje::getPelicula() {
	return pelicula;
}


//setters
void Puntaje::setPuntaje(int ptj) {
	puntaje = ptj;
};

//operaciones