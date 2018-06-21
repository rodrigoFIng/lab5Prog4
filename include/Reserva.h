#ifndef RESERVA_H
#define RESERVA_H

#include "CCine.h"
#include "Funcion.h"

#include <string>
#include <stdlib.h>

using namespace std;

//const float precioEntrada = 300;

const int MAX_RESERVAS = 100;

//class Funcion;

class Reserva: public ICollectible
{
friend class Debito;
friend class Credito;
private:
	//datos
	int cantAsientos;
	float costoTotal; //read-only

	//links
	Funcion *funcionReservada;

public:
	Reserva(int ca=0, int descuento=0) : cantAsientos(ca) {
		float precio = ca*precioEntrada();
		costoTotal = precio - descuento*precio/100;
		funcionReservada = NULL;
	};
	//constructor y destructor
	virtual ~Reserva();
	//getters
	int getCantAsientos();
	float getCostoTotal();
	Funcion* getFuncionReservada();
	string getTitulo() {return funcionReservada->getTitulo();};
	//setters
	void setCantAsientos(int cAsientos);
	void setFuncionReservada(Funcion *f);
	//operaciones
	virtual int getDescuento() = 0;
	virtual float calcularCostoTotal() =0;
	int precioEntrada() {
		/*
		CCine *cc = CCine::getInstance();
		return cc->getPrecioEntrada()
		*/
		return 100;
	};
	virtual void setBanco(string banco) {};
	virtual void setFinanciera(string financiera) {};
};

class Debito : public Reserva
{
private:
	//datos
	string banco;
public:
	//constructor y destructor
	Debito(string b, int ca=1) : Reserva(ca), banco(b) {};
	virtual ~Debito();
	//getters
	string getBanco();
	//setters
	void setBanco(string b);
	//operaciones
	int getDescuento();
	float calcularCostoTotal();
};

class Credito : public Reserva
{
private:
	//datos
	string financiera;
	int descuento; //read-only

	int descuentoFinanciera(string financiera) {
		if (financiera == "Oca")
		{
			return 15;
		} else if (financiera == "Creditel")
		{
			return 20;
		} else {
			return 0;
		};
	};
public:
	//constructor y destructor
	Credito(string f, int ca=1) : Reserva(ca, descuentoFinanciera(f)) {
		financiera = f;
		descuento = descuentoFinanciera(f);
	};
	virtual ~Credito();
	//getters
	string getFinanciera();
	int getDescuento();
	//setters
	void setFinanciera(string f);
	//operaciones
	float calcularCostoTotal();
};

#endif