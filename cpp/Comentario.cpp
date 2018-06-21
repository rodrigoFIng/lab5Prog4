#include "../include/Comentario.h"
#include "../include/Usuario.h"
#include "../include/Pelicula.h"
#include "../interfaces/IDictionary.h"
#include "../collections/OrderedDictionary.h"
#include "../Integer.h"

//constructor y destructor
Comentario::~Comentario() {

};

Comentario::Comentario(string texto, int nivelC) {
	this->texto = texto;
	nivel = nivelC;
	autor = NULL;
	respuestas = new OrderedDictionary();
};

Comentario::Comentario(Usuario *u, Pelicula *p, string txt) {
	texto = txt;
	nivel = 0;
	respuestas = new OrderedDictionary();
	u->getComentarios()->add(new Integer(u->getComentarios()->getSize()+1), this);
	p->getComentarios()->add(new Integer(p->getComentarios()->getSize()+1), this);
	autor = u;
};

Comentario::Comentario(Usuario *u, Comentario *c, string txt) {
	texto = txt;
	nivel = c->getNivel()+1;
	respuestas = new OrderedDictionary();
	u->getComentarios()->add(new Integer(u->getComentarios()->getSize()+1), this);
	c->getRespuestas()->add(new Integer(c->getRespuestas()->getSize()+1), this);
	autor = u;
};

//getters
string Comentario::getTexto() {
	return texto;
};

int Comentario::getNivel() {
	return nivel;
};

IDictionary* Comentario::getRespuestas() {
	return respuestas;
}

//setters
void Comentario::setTexto(string txtNuevo) {
	texto = txtNuevo;
};

//operacion

void Comentario::addRespuesta(Comentario *c) {
	respuestas->add(new Integer(respuestas->getSize()+1), c);
}