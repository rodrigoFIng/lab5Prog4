all: principal

# Objetivos que no son archivos.
.PHONY: all clean_bin

# directorios
HDIR    = include
CPPDIR  = cpp
ODIR    = obj

MODULOS = Usuario Sala Reserva Puntaje Hora Funcion Fecha Cine Comentario \
DtUsuario DtSala DtPelicula DtFuncion DtCine DtComentario \
CReserva CUsuario CPelicula CCine \
IReserva IUsuario IPelicula ICine \
List ListIterator ListNode OrderedDictionary OrderedDictionaryEntry \
ICollectible ICollection IDictionary IIterator IKey OrderedKey \
Fabrica Reloj \
Integer String \
Pelicula DatosPrueba \

# lista de archivos, con directorio y extensión
HS   = $(MODULOS:%=$(HDIR)/%.h)
CPPS = $(MODULOS:%=$(CPPDIR)/%.cpp)
OS   = $(MODULOS:%=$(ODIR)/%.o)

PRINCIPAL=principal
EJECUTABLE=principal

FUENTES = cpp/Usuario.cpp include/Usuario.h \
cpp/Reserva.cpp include/Reserva.h \
cpp/Pelicula.cpp include/Pelicula.h \
cpp/Cine.cpp include/Cine.h \
cpp/CReserva.cpp include/CReserva.h \
cpp/CUsuario.cpp include/CUsuario.h \
cpp/CPelicula.cpp include/CPelicula.h \
cpp/CCine.cpp include/CCine.h \
interfaces/IReserva.cpp interfaces/IReserva.h \
principal.cpp

# compilador
CC = g++
# opciones de compilación
CCFLAGS = -Wall -Werror -I$(HDIR) -g
# se debe remover o agregar la directiva -DNDEBUG para que las llamadas a 
# `assert' tengan  efecto o no.

$(ODIR)/$(PRINCIPAL).o:$(PRINCIPAL).cpp
	$(CC) $(CCFLAGS) -c $< -o $@

# cada .o depende de su .cpp
# $@ se expande para tranformarse en el objetivo
# $< se expande para tranformarse en la primera dependencia
$(ODIR)/%.o: $(CPPDIR)/%.cpp $(HDIR)/%.h
	$(CC) $(CCFLAGS) -c $< -o $@

$(ODIR)/%.o: collections/%.cpp collections/%.h
	$(CC) $(CCFLAGS) -c $< -o $@

$(ODIR)/%.o: interfaces/%.cpp interfaces/%.h
	$(CC) $(CCFLAGS) -c $< -o $@

$(ODIR)/%.o: %.cpp %.h
	$(CC) $(CCFLAGS) -c $< -o $@

# $^ se expande para tranformarse en todas las dependencias
$(EJECUTABLE): $(ODIR)/$(PRINCIPAL).o $(OS)
	$(CC) $(CCFLAGS) $^ -o $@

rebuild:
	make clean
	make

zip: $(FUENTES) Makefile
	rm -f 21_lab0.tar.gz
	tar -cvf 21_lab0.tar $(FUENTES) Makefile
	gzip 21_lab0.tar

# borra binarios
clean_bin:
	rm -f $(EJECUTABLE) $(ODIR)/$(PRINCIPAL).o $(OS)

# borra binarios, resultados de ejecución y comparación, y copias de respaldo
clean:clean_bin
	@rm -f *~ $(HDIR)/*~ $(CPPDIR)/*~ 

check-syntax:
	gcc -o nul -S ${CHK_SOURCES}