//jugador.h
//Defining Player's Class

#ifndef JUGADOR_H
#define JUGADOR_H
#include <list>
#include "persona.h"


struct Apuesta{
	int tipo;
	string valor;
	int cantidad;
};


class Jugador : public Persona{

	private:
		int dinero_;
		string codigo_;
		list<Apuesta> apuestas_;

	public:
		Jugador(string dni,string codigo,string nombre="",string apellidos="",int edad=0,string direccion="",string localidad="",string provincia="",string pais="");
		inline string getCodigo() const {return codigo_;}
		inline void setCodigo(string codigo){codigo_ = codigo;}
		inline int getDinero() const {return dinero_;}
		inline void setDinero(int dinero){dinero_ = dinero;}
		inline list<Apuesta> getApuestas() const {return apuestas_;}
		void setApuestas();

};

#endif
