//crupier.cc
////A program that develops metods of Crupier's class

#include "crupier.h"
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

Crupier::Crupier(string dni,string codigo,string nombre,string apellidos,int edad,string direccion,string localidad,string provincia,string pais) : Persona(dni,nombre,apellidos,edad,direccion,localidad,provincia,pais){
	//Recordar no poner el tipo de dato al llamar al constructor de Persona();
	setCodigo(codigo);
}