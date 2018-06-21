#include "../include/DatosPrueba.h"
#include "../include/CUsuario.h"
#include "../include/CReserva.h"
#include "../include/CPelicula.h"
#include "../include/CCine.h"
#include "../include/Usuario.h"
#include "../include/Reserva.h"
#include "../include/Pelicula.h"
#include "../include/Cine.h"
#include "../include/Funcion.h"
#include "../include/Sala.h"
#include "../include/Comentario.h"
#include "../include/Puntaje.h"

void cargarDatos() {
	//Controladores
	CCine *cc = CCine::getInstancia();
	CPelicula *cp = CPelicula::obtenerInstance();
	CUsuario *cu = CUsuario::getInstancia();

	//Cines
	Cine *c1 = new Cine(1, "21 de Setiembre 6658", 300);
	Cine *c2 = new Cine(2, "Miguel Barreiro 4588", 250);
	cc->addCine(c1);
	cc->addCine(c2);

	//Salas
	Sala *s11 = new Sala(1, 1, 20);
	Sala *s12 = new Sala(1, 2, 60);
	Sala *s13 = new Sala(1, 3, 30);
	Sala *s21 = new Sala(2, 1, 200);
	Sala *s22 = new Sala(2, 2, 60);
	c1->addSala(s11);
	c1->addSala(s12);
	c1->addSala(s13);
	c2->addSala(s21);
	c2->addSala(s22);

	//Peliculas
	Pelicula *p1 = new Pelicula("The Vindicators 3", "/home/accion/posters/vindicators.png", "Tercera entrega de la saga de superheroes.");
	Pelicula *p2 = new Pelicula("Sangre de campeones", "/home/accion/posters/scampeones.png", "Documental");
	Pelicula *p3 = new Pelicula("El insulto", "/home/accion/posters/elinsulto.png", "Drama libanés");
	Pelicula *p4 = new Pelicula("La noche que no se repite", "/home/accion/posters/nr.png", "Tremenda pelicula uruguaya");
	cp->addPelicula(p1);
	cp->addPelicula(p2);
	cp->addPelicula(p3);
	cp->addPelicula(p4);

	//Funciones
	Funcion *f1 = new Funcion(1, Fecha(15, 6, 2018), Hora(14, 0), 2, p1, s11);
	new Funcion(2, Fecha(15, 6, 2018), Hora(16, 30), 2, p2, s11);
	new Funcion(1, Fecha(15, 6, 2018), Hora(14, 0), 2, p1, s21);
	new Funcion(1, Fecha(15, 6, 2018), Hora(22, 0), 2, p3, s13);

	//Usuarios
	Usuario *u1 = new Usuario("chachoElNumberOne", "jorgeP4", "/users/registered/chachoElNumberOne.png", false);
	Usuario *u2 = new Usuario("carmeBeiro2010", "carmela5688", "/users/registered/carmeBeiro2010.png", false);
	Usuario *u3 = new Usuario("ale_ulises", "p4eslomejor21", "/admin/registered/ale_ulises.png", true);
	cu->addUsuario(u1);
	cu->addUsuario(u2);
	cu->addUsuario(u3);

	//Financieras
	
	//Comentarios
	Comentario *com1 = new Comentario(u1, p1, "Es tremenda pelicula. La mejor parte es cuando aparecen Rick y Morty");
	Comentario *com2 = new Comentario(u2, com1, "Esta muy buena pero la mejor parte es cuando explota el planeta con los malos");
	new Comentario(u1, com2, "Callateee no cuentes el final!!");

	//Puntajes
	new Puntaje(9, u1, p1);
	new Puntaje(6, u2, p3);

	//Reservas
	Reserva *r1 = new Debito("BROU", 7);
	u1->getReservas()->add(r1);
	r1->setFuncionReservada(f1);
	f1->getReservas()->add(r1);
	Reserva *r2 = new Credito("Oca", 8);
	u2->getReservas()->add(r2);
	r2->setFuncionReservada(f1);
	f1->getReservas()->add(r2);
};