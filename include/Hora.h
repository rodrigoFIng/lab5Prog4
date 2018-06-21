#ifndef HORA_H
#define HORA_H

#include <string>

using namespace std;

class Hora {
	private:
		int horas, minutos;
	public:
		Hora() {};
		Hora(int horas, int minutos);

		int getHoras();
		int getMinutos();

		~Hora();
};


#endif