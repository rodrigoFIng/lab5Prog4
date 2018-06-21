#ifndef CUSUARIO_H
#define CUSUARIO_H

#include <string>
#include "Usuario.h"
#include "DtUsuario.h"
#include "../interfaces/ICollection.h"
#include "../collections/List.h"
#include "../collections/ListIterator.h"
#include "../interfaces/IUsuario.h"


class CUsuario: public IUsuario
{
private:
	Usuario *UsuarioActualTemp;
	Usuario *UsuarioActual;
	ICollection *UsuariosRegistrados;

	static CUsuario *Instancia;
	CUsuario() {
		UsuarioActualTemp = NULL;
		UsuarioActual = NULL;
		UsuariosRegistrados = new List();
	};

public:
	bool IngresarNickname(string);

	bool IniciarSesion(string contrasena, string nickname);

	bool CerrarSesion();

	void SetSesion(Usuario *u);

	Usuario *getUsuarioActual();

	void AgregarUsuario(DtUsuario *dt);

	Usuario *ObtenerUsuario(string);

	void addUsuario(Usuario *u);

	static CUsuario *getInstancia();

	~CUsuario();


};
#endif