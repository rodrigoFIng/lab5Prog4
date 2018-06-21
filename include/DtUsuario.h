#ifndef DTUSUARIO_H
#define	DTUSUARIO_H

#include "../interfaces/ICollectible.h"

#include <string>

using namespace std;

class DtUsuario: public ICollectible
{
private:
	string nickname;
	string imagenPerfil;
	string contrasena;
public:
//Getter
	string getNickname();
	string getimagenPerfil();
	string getContrasena();

	DtUsuario(string nick , string pass , string img );
	DtUsuario();
	~DtUsuario();
};
#endif //DTUSUARIO_h