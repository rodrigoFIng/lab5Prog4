#ifndef CRESERVA_H
#define CRESERVA_H

#include "../include/CUsuario.h"
#include "../include/CCine.h"
#include "../include/Reserva.h"
#include "../interfaces/IReserva.h"

class CReserva: public IReserva
{
private:
	//instancia
	static CReserva *Instancia;

	//datos
	int cantAsientos;

	//links

	Reserva *reservaActual;

	//constructor
	CReserva() {
		cantAsientos = 1;
		reservaActual = NULL;
	};
public:
	//destructor
	~CReserva();
	//getters
	Reserva* getReservaActual();
	//setters
	void setReservaActual(Reserva *r);
	//operaciones
	void ingresarCantAsientos(int cantAsientosNuevo);
	void ingresarBanco(string banco);
	bool ingresarFinanciera(string financiera);
	int verDescuento();
	int verCostoTotal();
	void confirmarReserva();
	void cancelarReserva();
	void crearCredito();
	void crearDebito();

	static CReserva* getInstancia();
	
};

#endif