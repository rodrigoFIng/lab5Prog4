#include "../include/DtPelicula.h"


std::string DtPelicula::getTitulo() {
	return titulo;
}

void DtPelicula::setTitulo(std::string titulo) {
	this->titulo = titulo;
}

std::string DtPelicula::getPoster() {
	return poster;
}

void DtPelicula::setPoster(std::string poster) {
	this->poster = poster;
}

std::string DtPelicula::getSinopsis() {
	return sinopsis;
}

void DtPelicula::setSinopsis(std::string sinopsis) {
	this->sinopsis = sinopsis;
}

float DtPelicula::getPuntajePromedio() {
	return puntajePromedio;
}

void DtPelicula::setPuntajePromedio(float puntajePromedio) {
	this->puntajePromedio = puntajePromedio;
}

DtPelicula::DtPelicula(std::string titulo, std::string poster, std::string sinopsis, float puntajePromedio) {
	this->titulo = titulo;
	this->poster = poster;
	this->sinopsis = sinopsis;
	this->puntajePromedio = puntajePromedio;
}

DtPelicula::~DtPelicula() {
}