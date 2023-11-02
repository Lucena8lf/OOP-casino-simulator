//jugador.cc
//Developing of Player's Class Methods

#include <iostream>
#include <fstream>
#include <string>
#include "jugador.h"
using namespace std;

Jugador::Jugador(string dni,string codigo,string nombre,string apellidos,int edad,string direccion,string localidad,string provincia,string pais) : Persona(dni,nombre,apellidos,edad,direccion,localidad,provincia,pais){
	setDNI(dni);
	setCodigo(codigo);
	dinero_=1000;
}

void Jugador::setApuestas(){
	//Borramos las apuestas actuales
	apuestas_.clear();

	//Declaramos fichero
	ifstream fich(getDNI()+".txt");

	//Declaramos variables que nos encontraremos en el fichero
	string valor,tipo,cantidad;	

	if(fich.is_open()){

		//Leemos fichero con getline definiendo los delimitadores
		while(getline(fich,tipo,',')){
			getline(fich,valor,',');
			getline(fich,cantidad,'\n');

			//Asignamos los datos leidos a una nueva variable
			// la cual agregaremos a la lista
			Apuesta x = {stoi(tipo),valor,stoi(cantidad)};
			apuestas_.push_back(x);

			cout<<"tipo= "<<tipo<<" valor= "<<valor<<" cantidad= "<<cantidad<<endl;
		}
	} else{
		cout<<"Error: no se pudo abrir el fichero."<<endl;
	}

	fich.close();
}

