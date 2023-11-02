//ruleta.cc
//Developing Rulet's Methods

#include "ruleta.h"
#include <fstream>

Ruleta::Ruleta(Crupier c){
	srand(time(NULL)); //Generamos semilla
	setCrupier(c);
	bola_ = -1;
	banca_ = 1000000;
	nJug_=0;
	sumDin_=0;
	nBola_=0;
	sumBanca_=0;
}

bool Ruleta::setBanca(int banca){
	if(banca>=0){
		banca_ = banca;
		return true;
	} else{
		return false;
	}
}

bool Ruleta::setBola(int bola){
	if((bola>=0)&&(bola<=36)){
		bola_ = bola;
		return true;
	} else{
		return false;
	}
}

bool Ruleta::addJugador(Jugador j){

	list<Jugador>::iterator it; //Creamos iterador

	for(it=jugadores_.begin(); it!=jugadores_.end(); ++it){
		if((*it).getDNI()==j.getDNI()){
			cout<<"Error: el jugador ya esta registrado"<<endl;
			return false;
		}
	}

	jugadores_.push_back(j); //Añadimos el jugador al final de la lista

	ifstream fich1(j.getDNI() + ".txt",ios::in);
	ofstream fich2(j.getDNI() + ".txt",ios::out);

	//Comprobamos si existe
	if(fich1.is_open()){
		//El fichero existe
		return true;
		fich1.close();

	} else if(fich2.is_open()){
		//Creamos el fichero vacío
		return true;
		fich2.close();
	}
	return false;
}

int Ruleta::deleteJugador(string dni){

	if(jugadores_.empty()){ //Devuelve true si está vacía
		return -1;
	}

	int encontrado=-2;
	list<Jugador>::iterator it;

	for(it=jugadores_.begin(); it!=jugadores_.end(); ++it){

		if(((*it).getDNI())==dni){
			encontrado=1;
			it = jugadores_.erase(it);
		}
	}

	return encontrado;
}

int Ruleta::deleteJugador(Jugador j){

	if(jugadores_.empty()){ //Devueleve true si está vacía
		return -1;
	}

	int encontrado=-2;
	list<Jugador>::iterator it;

	for(it=jugadores_.begin(); it!=jugadores_.end(); ++it){

		if((*it).getDNI()==j.getDNI()){
			encontrado = 1;
			it = jugadores_.erase(it);
		}
	}

	return encontrado;
}

void Ruleta::escribeJugadores(){

	string nombreFich = "jugadores.txt";
	ofstream fich(nombreFich,ios::out);
	list<Jugador>::iterator it;

	if(fich.is_open()){

		for(it=jugadores_.begin();it!=jugadores_.end(); ++it){

			fich << (*it).getDNI();
			fich << ",";
			fich << (*it).getCodigo();
			fich << ",";
			fich << (*it).getNombre();
			fich << ",";
			fich << (*it).getApellidos();
			fich << ",";
			fich << (*it).getDireccion();
			fich << ",";
			fich << (*it).getLocalidad();
			fich << ",";
			fich << (*it).getProvincia();
			fich << ",";
			fich << (*it).getPais();
			fich << ",";
			fich << (*it).getDinero();
			fich << "\n";

			nJug_++;
		}

		fich.close();

	} else{
		cout<<"Error: no se pudo abrir el fichero ["<<nombreFich<<"]"<<endl;
	}
}

void Ruleta::leeJugadores(){

	string nombreFich = "jugadores.txt";
	ifstream fich(nombreFich,ios::in);
	string dni,codigo,nombre,apellidos,direccion,localidad,provincia,pais,dinero;

	//Borramos lista de jugadores
	jugadores_.clear();

	if(fich.is_open()){

		while(getline(fich,dni,',')){
			//Seguimos leyendo toda la linea hasta encontrar '\n'
			getline(fich,codigo,',');
			getline(fich,nombre,',');
			getline(fich,apellidos,',');
			getline(fich,direccion,',');
			getline(fich,localidad,',');
			getline(fich,provincia,',');
			getline(fich,pais,',');
			getline(fich,dinero,'\n');

			Jugador j(dni,codigo,nombre,apellidos,0,direccion,localidad,provincia,pais);
			j.setDinero(stoi(dinero));

			jugadores_.push_back(j);
		}

		fich.close();
	} else{
		cout<<"Error: no se pudo abrir el fichero ["<<nombreFich<<"]"<<endl;
	}
}

void Ruleta::giraRuleta(){

	cout<<"Girando ruleta..."<<endl;
	setBola(rand()%37);
	cout<<"El numero obtenido es: "<<getBola()<<endl;
	nBola_++;
}

void Ruleta::getPremios(){

	sumDin_ = 0;

	list<Apuesta> apuestas;
	int jtipo,jcantidad;
	string jvalor;

	list<Jugador>::iterator it; //Declaramos iterador para la lista de jugadores
	list<Apuesta>::iterator itAp; //Declaramos iterador para la lista de apuestas de cada jugador

	sumDin_+=banca_;

	for(it=jugadores_.begin(); it!=jugadores_.end(); ++it){

		(*it).setApuestas();
		apuestas = (*it).getApuestas();
		for(itAp=apuestas.begin(); itAp!=apuestas.end(); ++itAp){

			jtipo = (*itAp).tipo;
			jvalor = (*itAp).valor;
			jcantidad = (*itAp).cantidad;

			sumDin_+=jcantidad;

			switch(jtipo){
				int din;
				case 1: //Apuesta sencilla
					if((stoi(jvalor))==getBola()){ //Gana
						din = -(jcantidad*35);
						(*it).setDinero((*it).getDinero()-din);
						setBanca(getBanca()+din);

						cout<<"El jugador ["<<(*it).getCodigo()<<"] ha ganado: "<<-din<<endl;
					} else{ //Pierde
						din=jcantidad;
						(*it).setDinero((*it).getDinero()-jcantidad);
						setBanca(getBanca()+jcantidad);

						cout<<"El jugador ["<<(*it).getCodigo()<<"] ha perdido: "<<din<<endl;
					}

					sumBanca_+=din;
					break;

				case 2: //Apuesta color
					if(getBola()==0){ //Pierde
						din=jcantidad;
						(*it).setDinero((*it).getDinero()-jcantidad);
						setBanca(getBanca()+jcantidad);

						cout<<"El jugador ["<<(*it).getCodigo()<<"] ha perdido: "<<din<<endl;
					} else if((es_Rojo(getBola()) && jvalor=="rojo")||(!es_Rojo(getBola())&&jvalor=="negro")){ //Gana
						
							din = -jcantidad;
							(*it).setDinero((*it).getDinero()-din);
							setBanca(getBanca()+din);

							cout<<"El jugador ["<<(*it).getCodigo()<<"] ha ganado: "<<-din<<endl;
					} else{ //Pierde
						din=jcantidad;
						(*it).setDinero((*it).getDinero()-jcantidad);
						setBanca(getBanca()+jcantidad);

						cout<<"El jugador ["<<(*it).getCodigo()<<"] ha perdido: "<<din<<endl;
					}

					sumBanca_+=din;
					break;

				case 3: //Apuesta par o impar
					if(getBola()==0){ //Pierde

						din=jcantidad;
						(*it).setDinero((*it).getDinero()-jcantidad);
						setBanca(getBanca()+jcantidad);

						cout<<"El jugador ["<<(*it).getCodigo()<<"] ha perdido: "<<din<<endl;
					} else if((getBola()%2==0 && jvalor=="par")||(getBola()%2!=0 && jvalor=="impar")){ //Gana

						din = -jcantidad;
						(*it).setDinero((*it).getDinero()-din);
						setBanca(getBanca()+din);

						cout<<"El jugador ["<<(*it).getCodigo()<<"] ha ganado: "<<-din<<endl;
					} else{ //Pierde

						din=jcantidad;
						(*it).setDinero((*it).getDinero()-jcantidad);
						setBanca(getBanca()+jcantidad);

						cout<<"El jugador ["<<(*it).getCodigo()<<"] ha perdido: "<<din<<endl;
					}

					sumBanca_+=din;
					break;

				case 4: //Apuesta alto o bajo
					if(getBola()==0){ //Pierde
						din=jcantidad;
						(*it).setDinero((*it).getDinero()-jcantidad);
						setBanca(getBanca()+jcantidad);

						cout<<"El jugador ["<<(*it).getCodigo()<<"] ha perdido: "<<din<<endl;
					} else if((getBola()>0 && getBola()<19 && jvalor=="bajo")||(getBola()>19 && getBola()<37 && jvalor=="alto")){ //Gana
						din = -jcantidad;
						(*it).setDinero((*it).getDinero()-din);
						setBanca(getBanca()+din);
						cout<<"El jugador ["<<(*it).getCodigo()<<"] ha ganado: "<<-din<<endl;
					} else{ //Pierde
						din=jcantidad;
						(*it).setDinero((*it).getDinero()-jcantidad);
						setBanca(getBanca()+jcantidad);
						cout<<"El jugador ["<<(*it).getCodigo()<<"] ha perdido: "<<din<<endl;
					}

					sumBanca_+=din;
					break;

		}
	}

	}
}

bool Ruleta::es_Rojo(int num){

	int nRojo[18]={1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36};

	for(int i=0; i<18; i++){
		if(num==nRojo[i])
			return true;
	}
	return false;
}

void Ruleta::getEstadoRuleta(int &nJug,int &sumDin,int &nBola,int &sumBanca){
	
	nJug_ = nJug;
	sumDin_ = sumDin;
	nBola_ = nBola;
	sumBanca_ = sumBanca;

}

