#include "../include/DtUsuario.h"

//Getter
string DtUsuario::getNickname() {
	return this->nickname;
}
string DtUsuario::getimagenPerfil() {
	return this->imagenPerfil;
}
string DtUsuario::getContrasena() {
	return this->contrasena;
}

DtUsuario::DtUsuario(string nick, string pass, string img) 
{	
	this->contrasena = pass;
	this->nickname = nick;
	this->imagenPerfil = img;
}

DtUsuario::~DtUsuario()
{

}