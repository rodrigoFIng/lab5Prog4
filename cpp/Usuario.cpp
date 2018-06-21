#include "../include/Usuario.h"
#include "../Integer.h"
#include "../collections/OrderedDictionary.h"

//Getter
string Usuario::getNickname() {
	return this->nickname;
}
string Usuario::getimagenPerfil() {
	return this->imagenPerfil;
}
string Usuario::getContrasena() {
	return this->contrasena;
}

ICollection* Usuario::getPuntajes() {
	return puntajes;
}

ICollection* Usuario::getReservas() {
	return reservas;
}

IDictionary* Usuario::getComentarios() {
	return comentarios;
}

//Setter
void Usuario::setNickname(string nickname) {
	this->nickname = nickname;
}
void Usuario::setimagenPerfil(string imgperfil) {
	this->imagenPerfil = imgperfil;
}
void Usuario::setContrasena(string pass) {
	this->contrasena = pass;
}

ICollection* Usuario::reservasRealizadas() {
	return reservas;
}

Usuario::Usuario(DtUsuario *du) 
{	
	this->contrasena = du->getContrasena();
	this->nickname = du->getNickname();
	this->imagenPerfil = du->getimagenPerfil();
}

void Usuario::addReserva(Reserva *r) {
	reservas->add(r);
}

Usuario::Usuario(string nickU, string passU, string imgU, bool adminU)
{
	nickname = nickU;
	contrasena = passU;
	imagenPerfil = imgU;
	admin = adminU;

	reservas = new List();
	puntajes = new List();
	comentarios = new OrderedDictionary();
}

Usuario::~Usuario()
{

}

void Usuario::addComentario(Comentario *c) {
	comentarios->add(new Integer(comentarios->getSize()+1), c);
}
