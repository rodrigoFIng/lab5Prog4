#ifndef _DTTPELICULA_H
#define	_DTTPELICULA_H

#include "../interfaces/ICollectible.h"
#include <stdlib.h>
#include <string>

class DtPelicula : public ICollectible {
private:
	std::string titulo;
	std::string poster;
	std::string sinopsis;
	float puntajePromedio;
public:
	std::string getTitulo();
	void setTitulo(std::string titulo);
	std::string getPoster();
	void setPoster(std::string poster);
	std::string getSinopsis();
	void setSinopsis(std::string sinopsis);
	float getPuntajePromedio();
	void setPuntajePromedio(float puntajePromedio);
	DtPelicula(std::string titulo, std::string poster, std::string sinopsis, float puntajePromedio);
	~DtPelicula();
};
#endif//_DTPELICULA_H