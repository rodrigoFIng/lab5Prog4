#include "../include/Pelicula.h"
#include "../collections/List.h"
#include "../collections/OrderedDictionary.h"

//getters
string Pelicula::getTitulo() {
	return titulo;
}

string Pelicula::getPoster() {
	return poster;
}

string Pelicula::getSinopsis() {
	return sinopsis;
}

float Pelicula::getPuntajePromedio() {
	return puntajePromedio;
}

ICollection* Pelicula::getCines() {
	try {
		IIterator *iterator = this->cines->getIterator();
		//Largo lista cines
		int largo = this->cines->getSize();

		ICollectible *IC = iterator->getCurrent();
		Cine *c = dynamic_cast<Cine*>(IC);
		DtCine *dtc = new DtCine(c->getIdCine(), c->getDireccion(), c->getPrecioEntrada());

		ICollection *lista = new List();
		lista->add(dtc);
		int i = 0;

		while (i <= largo)
		{
			iterator->next();
			IC = iterator->getCurrent();
			c = dynamic_cast<Cine*>(IC);
			dtc = new DtCine(c->getIdCine(), c->getDireccion(), c->getPrecioEntrada());
			lista->add(dtc);
			i++;
		}
		return lista;
	}
	catch (out_of_range& oor) {
		//No hay mas usuarios en la lista
		throw oor;
	}
	catch (exception& e) {
		throw e;
	}
}

ICollection* Pelicula::getPuntajes(){
	return this->puntajes;
}

IDictionary* Pelicula::getComentarios() {
	/*try {
		IIterator *iterator = this->comentarios->getIterator();
		//Largo lista cines
		int largo = this->comentarios->getSize();

		ICollectible *IC = iterator->getCurrent();
		Comentario *com = dynamic_cast<Comentario*>(IC);
		DtComentario *dtc = new DtComentario(com->getTexto());

		ICollection *lista = new List();
		lista->add(dtc);
		int i = 0;

		while (i <= largo)
		{
			iterator->next();
			IC = iterator->getCurrent();
			com = dynamic_cast<Comentario*>(IC);
			dtc = new DtComentario(com->getTexto());
			lista->add(dtc);
			i++;
		}
		return lista;
	}
	catch (out_of_range& oor) {
		//No hay mas usuarios en la lista
		throw oor;
	}
	catch (exception& e) {
		throw e;
	}*/

	return comentarios;
}

//setters
void Pelicula::setTitulo(string tituloNuevo) {
	titulo = tituloNuevo;
}

void Pelicula::setPoster(string posterNuevo) {
	poster = posterNuevo;
}

void Pelicula::setSinopsis(string sinopsisNuevo) {
	sinopsis = sinopsisNuevo;
}

//operaciones

void Pelicula::calcularPuntajePromedio() {
	try {
		IIterator *iterator = this->puntajes->getIterator();
		//Largo lista puntajes
		int largo = this->puntajes->getSize();
		int promedio = 0;

		ICollectible *IC = iterator->getCurrent();
		//Si llega a contador es porque hay elemento en la lista
		int contador = 1;
		Puntaje *pu = dynamic_cast<Puntaje*>(IC);
		promedio = pu->getPuntaje();

		while (contador <= largo)
		{
			iterator->next();
			IC = iterator->getCurrent();
			contador++;
			pu = dynamic_cast<Puntaje*>(IC);
			promedio = (promedio + pu->getPuntaje()) / contador;
		}
	}
	catch (out_of_range& oor) {
		//No hay mas usuarios en la lista
		throw oor;
	}
	catch (exception& e) {
		throw e;
	}
}

//Constructores


Pelicula::Pelicula(string tituloNuevo, string posterNuevo, string sinopsisNuevo){
	titulo = tituloNuevo;
	poster = posterNuevo;
	sinopsis = sinopsisNuevo;
	puntajes = new List();
	cines = new List();
	comentarios = new OrderedDictionary();
}


Pelicula::~Pelicula(){
}
