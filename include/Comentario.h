#ifndef COMENTARIO_H
#define COMENTARIO_H

#include "../interfaces/ICollectible.h"
#include "../interfaces/IDictionary.h"

#include <string>
using namespace std;

class Pelicula;
class Usuario;

class Comentario: public ICollectible
{
private:
	string texto;
	int nivel;
	Usuario *autor;
	IDictionary *respuestas;
public:
	//constructor y destructor
	Comentario(string textoNuevo, int nivelC =0);
	Comentario(Usuario *u, Pelicula *p, string txt);
	Comentario(Usuario *u, Comentario *c, string txt);
	~Comentario();
	//getters
	string getTexto();
	int getNivel();
	IDictionary* getRespuestas();
	//setters
	void setTexto(string txtNuevo);
	//operaciones
	void addRespuesta(Comentario * c);
};

#endif