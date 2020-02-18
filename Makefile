

all: Scanner.o Instancia.o Menus.o Construtivos.o BuscasLocais.o Metaheuristicas.o Avaliador.o main.o
	$(CCC) -O3 Scanner.o Instancia.o Menus.o Construtivos.o BuscasLocais.o Metaheuristicas.o Avaliador.o main.o -o pcv

main.o: main.cpp
	$(CCC) -O3 -c main.cpp -o main.o
	
Instancia.o: Instancia.cpp
	$(CCC) -O3 -c Instancia.cpp -o Instancia.o

Menus.o: Menus.cpp
	$(CCC) -O3 -c Menus.cpp -o Menus.o
	
Scanner.o: Util/Scanner++/Scanner.cpp
	$(CCC) -O3 -c Util/Scanner++/Scanner.cpp -o Scanner.o

Construtivos.o: Construtivos.cpp
	$(CCC) -O3 -c Construtivos.cpp -o Construtivos.o

Avaliador.o: Avaliador.cpp
	$(CCC) -O3 -c Avaliador.cpp -o Avaliador.o

BuscasLocais.o: BuscasLocais.cpp
	$(CCC) -O3 -c BuscasLocais.cpp -o BuscasLocais.o

Metaheuristicas.o: Metaheuristicas.cpp
	$(CCC) -O3 -c Metaheuristicas.cpp -o Metaheuristicas.o

clean: 
	rm -f pcv
	rm -f *.o

# ---------------------------------------------------------------------
# Compiler selection 
# ---------------------------------------------------------------------

CCC = g++
CC  = gcc












