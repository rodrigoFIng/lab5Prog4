#ifndef DTFUNCION_H
#define DTFUNCION_H

#include <string>
#include "Hora.h"
#include "Fecha.h"

#include "../interfaces/ICollectible.h"

using namespace std;

class DtFuncion: public ICollectible {
	private: 
		int idCine, idSala, idFuncion;
		Fecha fecha;
		Hora horario;
	public:
		DtFuncion(int idCine, int idSala, int idFuncion, Fecha fecha, Hora horario);

		void setIdCine(int idCine);
		void setIdSala(int idSala);
		void setIdFuncion(int idFuncion);
		void setFecha (Fecha fecha);
		void setHorario (Hora horario);

		int getIdCine();
		int getIdSala();
		int getIdFuncion();
		Fecha getFecha();
		Hora getHorario();

		~DtFuncion();
};

#endif