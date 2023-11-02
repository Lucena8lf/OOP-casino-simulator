//crupier.h
//Defining Crupier's class

#ifndef CRUPIER_H
#define CRUPIER_H
#include "persona.h"
using std::string;

class Crupier : public Persona{
	private:
		string _codigo;

	public:
		Crupier(string dni="",string codigo="",string nombre="",string apellidos="",int edad=0,string direccion="",string localidad="",string provincia="",string pais="");
		inline void setCodigo(string codigo){_codigo = codigo;}
		inline string getCodigo() const {return _codigo;}
};

#endif
