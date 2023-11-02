#include "jugador.h"
#include <fstream>
using namespace std;

int main(){

	string dni,nombre,apellidos,direccion,localidad,provincia,pais;
	int edad;
	list<Apuesta> x;

	cout<<"Introduzca el DNI del jugador: ";
	getline(cin,dni);

	cout<<"Introduzca su nombre: ";
	getline(cin,nombre);

	cout<<"Introduzca sus apellidos: ";
	getline(cin,apellidos);

	cout<<"Introduzca su edad: ";
	cin>>edad;
	getchar();

	cout<<"Introduzca su direccion: ";
	getline(cin,direccion);

	cout<<"Introduzca su provincia: ";
	getline(cin,provincia);

	cout<<"Introduzca su localidad: ";
	getline(cin,localidad);

	cout<<"Introduzca su pais: ";
	getline(cin,pais);

	Jugador j(dni,"01",nombre,apellidos,edad,direccion,localidad,provincia,pais);

	//Leemos el fichero correspondiente a este jugador
	j.setApuestas();

	//Asignamos la lista a nuestra variable
	x = j.getApuestas();

	return 0;
}