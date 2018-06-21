#ifndef DTSALA_H
#define DTSALA_H

#include "../interfaces/ICollectible.h"

#include <string>
#include <stdlib.h>

using namespace std;

class DtSala: public ICollectible{
private:
	int idSala;
	int capacidad;
public:
	void setIdSala(int idSala);
	void setCapacidad(int capacidad);
	int getIdSala();
	int getCapacidad();
	DtSala(int idSala, int capacidad);
	~DtSala();
};

#endif