#ifndef RELOJ_H
#define RELOJ_H

#include <string>

using namespace std;

class Reloj {
	private:
		string fecha;
		static Reloj *Instancia;
		Reloj(string f ="01/01/2000 00:00");
	public:
		void modificarFecha(string);
		string consultarFecha();

		int getDia();
		int getMes();
		int getAnio();
		int getHora();
		int getMinuto();

		static Reloj* getInstance();
		~Reloj();
};

#endif