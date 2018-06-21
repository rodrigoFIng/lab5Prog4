#ifndef USUARIO_H
#define	USUARIO_H

#include "../interfaces/ICollectible.h"
#include "../interfaces/ICollection.h"
#include "../interfaces/IDictionary.h"
#include "DtUsuario.h"
#include "Reserva.h"

#include <string>

using namespace std;

class Usuario: public ICollectible
{
private:
	string nickname;
	string imagenPerfil;
	string contrasena;
	bool admin;

	ICollection *reservas;
	ICollection *puntajes;
	IDictionary *comentarios;
public:
//Getter
	string getNickname();
	string getimagenPerfil();
	string getContrasena();
	ICollection* getPuntajes();
	ICollection* getReservas();
	IDictionary* getComentarios();
//Setter
	void setNickname(string);
	void setimagenPerfil(string);
	void setContrasena(string);

	Usuario(DtUsuario *du);
	void addReserva(Reserva *r);
	ICollection* reservasRealizadas();
	Usuario(string nickU, string passU, string imgU, bool adminU =false);
	~Usuario();

	void addComentario(Comentario *c);
};
#endif //USUARIO_H

