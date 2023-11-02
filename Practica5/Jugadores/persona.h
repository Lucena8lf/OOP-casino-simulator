//persona.h
//Defining Persona's class

#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>
#include <string>
using namespace std;

class Persona{
private:
	string _dni;
	string _nombre;
	string _apellidos;
	int _edad;
	string _direccion;
	string _localidad;
	string _provincia;
	string _pais;

public:
	Persona(string dni,string nombre="",string apellidos="",int edad=0,string direccion="",string localidad="",string provincia="",string pais=""); //Constructor
	
	inline void setDNI(string dni){_dni = dni;}
	inline string getDNI() const {return _dni;}
	
	inline void setNombre(string nombre){_nombre = nombre;}
	inline string getNombre() const {return _nombre;}

	inline void setApellidos(string apellidos){_apellidos = apellidos;}
	inline string getApellidos() const {return _apellidos;}
	
	bool setEdad(int edad);
	inline int getEdad() const {return _edad;}
	
	inline void setDireccion(string direccion){_direccion = direccion;}
	inline string getDireccion() const {return _direccion;}
	
	inline void setLocalidad(string localidad){_localidad = localidad;}
	inline string getLocalidad() const {return _localidad;}
	
	inline void setProvincia(string provincia){_provincia = provincia;}
	inline string getProvincia() const {return _provincia;}

	inline void setPais(string pais){_pais = pais;}
	inline string getPais() const {return _pais;}

	inline string getApellidosyNombre() const {return (_apellidos+", "+_nombre);}

	bool mayor();


};

#endif
