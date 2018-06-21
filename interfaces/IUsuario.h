#ifndef _IUSUARIO_H
#define	_IUSUARIO_H

#include <string>
#include "../include/DtUsuario.h"
#include "../include/Usuario.h"

class IUsuario 
{
public:
	virtual bool IngresarNickname(string) = 0;

	virtual bool IniciarSesion(string contrasena, string nickname) = 0;

	virtual bool CerrarSesion() = 0;

	virtual void SetSesion(Usuario *) = 0;

	//virtual Usuario* getUsuarioActual() = 0;

	virtual void AgregarUsuario(DtUsuario *) = 0;

	//virtual DtUsuario*  ObtenerUsuario(string) = 0;

	~IUsuario() {};
};

#endif //IUSUARIO_H
