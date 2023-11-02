//ordenacionJugadores.cc
//A program thats sorts a Jugador's vector

#include <vector>
#include <algorithm>
#include "jugador.h"

bool sortByDNIasc(const Jugador &jug1, const Jugador &jug2){return jug1.getDNI() < jug2.getDNI();}
bool sortByDNIdesc(const Jugador &jug1, const Jugador &jug2){return jug1.getDNI() > jug2.getDNI();}

int main(){

	int nJug;
	string dni;

	cout<<"Introduzca el numero de jugadores: \n";
	cin>>nJug;

	vector<Jugador> v;

	for(int i=0; i<nJug; i++){
		Jugador aux(to_string(1+(rand()%99999999)), to_string(i+1));
		v.push_back(aux);
	}

	cout<<"Jugadores: "<<endl;
	for(Jugador j : v){
		cout<<"\tCodigo: "<<j.getCodigo()<<endl;
		cout<<"\tDNI: "<<j.getDNI()<<endl;
		cout<<endl;
	}
	
	sort(v.begin(),v.end(),sortByDNIasc); //Ordenamos jugadores
	cout<<"Jugadores ordenados de manera ascendente por su DNI: \n";
	for(Jugador j : v){
		cout<<j.getDNI()<<" ";
	}

	cout<<endl;

	sort(v.begin(),v.end(),sortByDNIdesc);
	cout<<"Jugadores ordenados de manera descendente por su DNI: \n";
	for(Jugador j : v){
		cout<<j.getDNI()<<" ";
	}

	cout<<endl;

	return 0;
}