#ifndef _DTCINE_H
#define	_DTCINE_H

#include "../interfaces/ICollectible.h"
#include <string>

class DtCine : public ICollectible {
private:
	int idCine;
	int precioEntrada;
	std::string direccion;
public:
	void setIdCine(int idCine);
	void setDireccion(std::string direccion);
	int getIdCine();
	std::string getDireccion();
	int getPrecioEntrada() {return precioEntrada;};
	DtCine(int idCine, std::string direccion, int pe);
	~DtCine();
};
#endif
