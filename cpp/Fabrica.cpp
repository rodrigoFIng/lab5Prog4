#include "../include/Fabrica.h"
#include "../include/CUsuario.h"
#include "../include/CCine.h"
#include "../include/CPelicula.h"
#include "../include/CReserva.h"

Fabrica *Fabrica::Instancia = NULL;

Fabrica *Fabrica::getInstancia() {
	if (Instancia == NULL)
		Instancia = new Fabrica();
	return Instancia;
};



IUsuario* Fabrica::ObtenerIUsuario() 
{
	CUsuario *Cu = CUsuario::getInstancia();
	return Cu;
};

IReserva* Fabrica::ObtenerIReserva()
{
	CReserva *Cr = CReserva::getInstancia();
	return Cr;
};


ICine* Fabrica::ObtenerICine()
{
	CCine *Cc = CCine::getInstancia();
	return Cc;
}

IPelicula* Fabrica::ObtenerIPelicula()
{
	CPelicula *Cp = CPelicula::obtenerInstance();
	return Cp;
}


Fabrica::Fabrica()
{
}


Fabrica::~Fabrica()
{
}
