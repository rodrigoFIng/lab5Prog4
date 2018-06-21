#include "../include/DtCine.h"
#include <string>

using namespace std;

void DtCine::setIdCine(int idCine) {
	this->idCine = idCine;
}

void DtCine::setDireccion(std::string direccion) {
	this->direccion = direccion;
}

int DtCine::getIdCine() {
	return 1;
}

std::string DtCine::getDireccion() {
	return direccion;
}

DtCine::DtCine(int idCine, std::string direccion, int pe) {
	this->idCine = idCine;
	this->direccion = direccion;
	precioEntrada = pe;
}

DtCine::~DtCine() 
{
}