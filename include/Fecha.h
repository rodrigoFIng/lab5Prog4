#ifndef FECHA_H
#define FECHA_H

#include <string>

using namespace std;

class Fecha {
	private:
		int dia, mes, anio;
	public:
		Fecha() {};
		Fecha(int dia, int mes, int anio);

		int getDia();
		int getMes();
		int getAnio();

		~Fecha();
};



#endif