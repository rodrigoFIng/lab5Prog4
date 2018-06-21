#include "../interfaces/IUsuario.h"
#include "../interfaces/IReserva.h"
#include "../interfaces/ICine.h"
#include "../interfaces/IPelicula.h"

class Fabrica
{
private:
	static Fabrica *Instancia;
	Fabrica();
public:

	IUsuario* ObtenerIUsuario();
	IReserva* ObtenerIReserva();
	ICine* ObtenerICine();
	IPelicula* ObtenerIPelicula();
	

	static Fabrica *getInstancia();
	~Fabrica();
};

