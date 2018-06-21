#ifndef FUNCION_H
#define FUNCION_H

#include "../interfaces/ICollection.h"
#include "../interfaces/ICollectible.h"
#include "Hora.h"
#include "Fecha.h"
#include "DtPelicula.h"
#include "../include/Pelicula.h"
//#include "Reserva.h"

#include <string>

using namespace std;

class Reserva;

class Funcion: public ICollectible {
	private: 
		int idCine, idSala, idFuncion, duracion;
		Fecha fecha;
		Hora horario;

		ICollection *Reservas;
		Pelicula *peli;

	public:
		Funcion();
		Funcion(int idc, int ids, int idf, Fecha f, Hora h, Pelicula *p, int dur =2);
		Funcion(int idf, Fecha f, Hora h, int dur =2, Pelicula *p =NULL, Sala *s =NULL);

		void setIdCine(int idCine);
		void setIdSala(int idSala);
		void setIdFuncion(int idFuncion);
		void setFecha(Fecha fecha);
		void setHorario(Hora horario);
		void setPeli(Pelicula *peli);

		void addReserva(Reserva *r);
		//void eliminarReserva(Reserva *r);
		int getIdFuncion();
		int getIdCine();
		int getIdSala();
		Fecha getFecha();
		Hora getHorario();
		Pelicula *getPeli();
		ICollection *getReservas();
		string getTitulo() {return peli->getTitulo();};

		bool comparar(string titulo);

		~Funcion();
};

#endif