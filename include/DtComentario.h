#ifndef _DTCOMENTARIO_H
#define	_DTCOMENTARIO_H
#include "../interfaces/ICollectible.h"
#include <string>
#include <iostream>

using namespace std;

class DtComentario : public ICollectible
{
private:
	string texto;
public:
	//constructor y destructor
	DtComentario(string textoNuevo);
	~DtComentario();
	//getters
	string getTexto();
};

#endif

