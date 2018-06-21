#include "../include/CUsuario.h"
#include "../include/Fabrica.h"
//#include "../S"

#include <iostream>
#include <stdlib.h>
#include <string>
#include <typeinfo>
#include <stdexcept>
#include <exception>

CUsuario *CUsuario::Instancia = NULL;

CUsuario *CUsuario::getInstancia() {
	if (Instancia == NULL)
		Instancia = new CUsuario();
	return Instancia;
};


bool CUsuario::IngresarNickname(string nickname) {
	try {
		Usuario *u = ObtenerUsuario(nickname);
		if (u == NULL)
		{
			return false;
		} else {
			UsuarioActualTemp = u;
			return true;
		}
	}
	catch (out_of_range oor) {
		throw oor;
	}
	catch (exception e) {
		throw e;
	}

}

bool CUsuario::IniciarSesion(string contrasena, string nickname) {
	try {
		Usuario *u = UsuarioActualTemp;
		string c = u->getContrasena();
		if (c.compare(contrasena) == 0) {
			this->SetSesion(u);
			return true;
		}
		else {
			return false;
		}
	}
	catch (out_of_range oor) {
		throw oor;
	}
	catch (exception e) {
		throw e;
	}
}

bool CUsuario::CerrarSesion() {
	this->UsuarioActual = NULL;
	return true;
}

void CUsuario::SetSesion(Usuario *u) {
	this->UsuarioActual = u;
}

Usuario* CUsuario::getUsuarioActual() {
	try{
		return this->UsuarioActual;
	}
	catch (exception& e) {
		cout << "No existe usuario con sesion iniciada" << endl;
		throw e;
	}
}

void CUsuario::AgregarUsuario(DtUsuario *dt) {
	//Si es el primer usuario
	if (this->UsuariosRegistrados == NULL)
		this->UsuariosRegistrados = new List();
	Usuario *u = new Usuario(dt);
	this->UsuariosRegistrados->add(u);
}

Usuario* CUsuario::ObtenerUsuario(string NickName) {
	//Busco usuario para devolver 
	try {
		IIterator *iterator = this->UsuariosRegistrados->getIterator();
		//Cast de interface a Class Usuario
		Usuario *res = NULL;

		bool encontrado = false;
		while (iterator->hasCurrent() && !encontrado)
		{
			ICollectible *IC = iterator->getCurrent();
			Usuario *u = dynamic_cast<Usuario*>(IC);
			string Nick = u->getNickname();
			if ((Nick.compare(NickName)) == 0)
			{
				res = u;
				encontrado = true;
			};
			iterator->next();
		};
		return res;
	}
	catch (out_of_range& oor) {
		//No hay mas usuarios en la lista
		//throw oor;
		return NULL;
	}
	catch (exception& e) {
		throw e;
	}

}


void CUsuario::addUsuario(Usuario *u) {
	UsuariosRegistrados->add(u);
}


CUsuario::~CUsuario()
{
}
