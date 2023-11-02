//persona.cc
//A program that develops metods of Persona's class

#include "persona.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
using namespace std;

Persona::Persona(string dni,string nombre,string apellidos,int edad,string direccion,string localidad,string provincia,string pais){
	//En el cuerpo no hay que poner valores solo las declaraciones de todos los parametros
	
	//Los modificamos
	setDNI(dni);
	setNombre(nombre);
	setApellidos(apellidos);
	setEdad(edad);
	setDireccion(direccion);
	setLocalidad(localidad);
	setProvincia(provincia);
	setPais(pais);
}

bool Persona::setEdad(int edad){
	if(edad>=0){
		_edad = edad;
		return true;
	} else{
		return false;
	}
}

bool Persona::mayor(){
	if(_edad>=18){
		cout<<"Es mayor de edad."<<endl;
		return true;
	} else{
		cout<<"NO es mayor de edad."<<endl;
		return false;
	}
}
