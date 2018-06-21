#include "../include/DtComentario.h"

//constructor y destructor
DtComentario::~DtComentario() {

};

DtComentario::DtComentario(string textoNuevo) {
	this->texto = textoNuevo;
}

//getters
string DtComentario::getTexto() {
	return this->texto;
};

//operacion
