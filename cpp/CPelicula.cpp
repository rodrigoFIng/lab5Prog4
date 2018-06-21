#include "../include/CPelicula.h"
#include "../include/CUsuario.h"
#include "../include/Usuario.h"
#include "../Integer.h"

CPelicula* CPelicula::Instance = NULL;

void CPelicula::agregarPelicula(DtPelicula *dtp) {
	Pelicula *Pe = new Pelicula(dtp->getTitulo(), dtp->getPoster(), dtp->getSinopsis());
	if (this->Peliculas == NULL)
	{
		this->Peliculas = new List();
		this->DtPeliculas = new List();
	}
//Nivelo List Pelicula y DtPelicula
	this->Peliculas->add(Pe);
	this->DtPeliculas->add(dtp);
}

Pelicula* CPelicula::obtenerPelicula(string titulo) {
	try {
		IIterator *iterator = this->Peliculas->getIterator();
		ICollectible *IC = iterator->getCurrent();
		//Cast de interface a Class Pelicula
		Pelicula *p = dynamic_cast<Pelicula*>(IC);
		string titulo_aux = p->getTitulo();

		while (titulo_aux.compare(titulo) != 0)
		{
			iterator->next();
			IC = iterator->getCurrent();
			p = dynamic_cast<Pelicula*>(IC);
			titulo_aux = p->getTitulo();
		}
		return p;
	}
	catch (out_of_range& oor) {
		//No hay mas usuarios en la lista
		throw oor;
	}
	catch (exception& e) {
		throw e;
	}
}

string CPelicula::verPosterPelicula(string titulo) {
	Pelicula *p = this->obtenerPelicula(titulo);
	string poster = p->getPoster();
	return poster;
}

string CPelicula::verSinopsisPelicula(string titulo) {
	Pelicula *p = this->obtenerPelicula(titulo);
	string Sinopsis = p->getSinopsis();
	return Sinopsis;
}

ICollection* CPelicula::infoAdicionalPelicula(string titulo) 
{

	try 
	{
		Pelicula *p = this->obtenerPelicula(titulo);
		int largo = p->getCines()->getSize();
		IIterator *iterator = p->getCines()->getIterator();
		ICollectible *IC = iterator->getCurrent();
		//Lista para retornar
		ICollection *lista = new List();
		lista->add(IC);
		int i = 0;

		while (i <= largo)
		{
			iterator->next();
			IC = iterator->getCurrent();
			lista->add(IC);
			i++;
		}

		return lista;
	}
	catch (out_of_range& oor) 
	{
		//No hay mas usuarios en la lista
		throw oor;
	}
	catch (exception& e)
	{
		throw e;
	}
}

ICollection* CPelicula::listarPeliculas() {
	return this->DtPeliculas;
}

void CPelicula::eliminarPelicula(string titulo) 
{

}

CPelicula* CPelicula::obtenerInstance() {
	if (Instance == NULL)
		Instance = new CPelicula();
	return Instance;
}

void CPelicula::addcomentario(int pos, string comentario) {
	Pelicula *p = peliculaSeleccionada;
	CUsuario *cu = CUsuario::getInstancia();
	Usuario *u = cu->getUsuarioActual();
	if (pos == 0)
	{
		new Comentario(u, p, comentario);
		//p->getComentarios()->add(new Integer(p->getComentarios()->getSize()+1), com);
	}
	else
	{
		IIterator *iterator = p->getComentarios()->getIterator();
		ICollectible *IC = iterator->getCurrent();
		//Casteo de Abstract a Comentario
		Comentario *com = dynamic_cast<Comentario*>(IC);

		//empiezo a recorrer los comentarios hasta la pos
		for (int pos_aux = 1; pos_aux <= p->getComentarios()->getSize(); pos_aux++)
			iterator->next();

		IC = iterator->getCurrent();
		com = dynamic_cast<Comentario*>(IC);
		new Comentario(u, com, comentario);
	}

}

bool CPelicula::puntuarPelicula(string titulo, string nombre, int puntaje) {

	try {
		Pelicula *p = this->obtenerPelicula(titulo);
		//empiezo a recorrer los puntajes
		IIterator *iterator = p->getPuntajes()->getIterator();
		ICollectible *IC = iterator->getCurrent();
		//Casteo de Abstract a Puntaje
		Puntaje *pu = dynamic_cast<Puntaje*>(IC);

		while (pu->getUsuario()->getNickname().compare(nombre) != 0)
		{
			iterator->next();
			IC = iterator->getCurrent();
			pu = dynamic_cast<Puntaje*>(IC);
		}
		//Siempre llega si lo encuentra, sino se va al catch
		return false;
	}
	catch (out_of_range& oor)
	{
		throw oor;
	}
	catch (exception& e)
	{
		throw e;
	}
}

int CPelicula::mostrarPuntaje(string titulo, string nombre) {
	try {
		Pelicula *p = this->obtenerPelicula(titulo);
		//empiezo a recorrer los puntajes
		IIterator *iterator = p->getPuntajes()->getIterator();
		ICollectible *IC = iterator->getCurrent();
		//Casteo de Abstract a Puntaje
		Puntaje *pu = dynamic_cast<Puntaje*>(IC);

		while (pu->getUsuario()->getNickname().compare(nombre) != 0)
		{
			iterator->next();
			IC = iterator->getCurrent();
			pu = dynamic_cast<Puntaje*>(IC);
		}
		//Siempre llega si lo encuentra, sino se va al catch
		return pu->getPuntaje();
	}
	catch (out_of_range& oor)
	{
		throw oor;
	}
	catch (exception& e)
	{
		throw e;
	}
}

void CPelicula::modificarPuntaje(string titulo, string nombre, int puntaje) {
	try {
		Pelicula *p = this->obtenerPelicula(titulo);
		//empiezo a recorrer los puntajes
		IIterator *iterator = p->getPuntajes()->getIterator();
		ICollectible *IC = iterator->getCurrent();
		//Casteo de Abstract a Puntaje
		Puntaje *pu = dynamic_cast<Puntaje*>(IC);

		while (pu->getUsuario()->getNickname().compare(nombre) != 0)
		{
			iterator->next();
			IC = iterator->getCurrent();
			pu = dynamic_cast<Puntaje*>(IC);
		}
		//Siempre llega si lo encuentra, sino se va al catch
		pu->setPuntaje(puntaje);
	}
	catch (out_of_range& oor)
	{
		throw oor;
	}
	catch (exception& e)
	{
		throw e;
	}
}

//peliculaSeleccionada
void CPelicula::setPeliculaSeleccionada(Pelicula *ps) {
	peliculaSeleccionada = ps;
}

CPelicula::CPelicula()
{
	peliculaSeleccionada = NULL;
	Peliculas = new List();
	DtPeliculas = new List();
}


CPelicula::~CPelicula()
{
}

void CPelicula::addPelicula(Pelicula *p) {
	Peliculas->add(p);
}
