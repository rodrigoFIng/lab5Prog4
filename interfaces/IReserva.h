#ifndef IRESERVA_H
#define IRESERVA_H

#include <string>

using namespace std;

class IReserva
{
public:
	//constructor y destructor
	virtual ~IReserva() {};
	//getters
	//setters
	//operaciones
	virtual void ingresarCantAsientos(int cantAsientos) =0;
	virtual void ingresarBanco(string banco) =0;
	virtual bool ingresarFinanciera(string financiera) =0;
	virtual int verDescuento() =0;
	virtual int verCostoTotal() =0;
	virtual void confirmarReserva() =0;
	virtual void cancelarReserva() =0;
	virtual void crearCredito() =0;
	virtual void crearDebito() =0;
};

#endif