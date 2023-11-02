//jugador-ppal.cc
//Program's main

#include "ruleta.h"
#include <fstream>

int main(){

	Crupier c;
	Ruleta r(c); //Declaramos objeto de tipo "Ruleta"

	int opc;
	int nJug=0;
	int sumDin=0;
	int nBola=0;
	int sumBanca=0;

	do{
		cout<<endl;
		cout<<"Elija una opcion: "<<endl;
		cout<<"\t1.Cargar los jugadores del fichero 'jugadores.txt'"<<endl;
		cout<<"\t2.Guardar los jugadores en 'jugadores.txt'"<<endl;
		cout<<"\t3.Ver estado de la ruleta y dinero de jugadores y banca"<<endl;
		cout<<"\t4.Girar la ruleta y ver ganacias de jugadores y banca"<<endl;
		cout<<"\t5.Eliminar un jugador de la mesa"<<endl;
		cout<<"\t6.Añadir un jugador a la mesa"<<endl;
		cout<<"\t0.Salir"<<endl;

		cin>>opc;

		switch(opc){
			case 1: //Cargar jugadores del fichero
				cout<<"Cargando jugadores..."<<endl;
				r.leeJugadores();
				cout<<"Jugadores cargados con exito."<<endl;
				break;

			case 2: //Guardar jugadores en el fichero
				cout<<"Guardando jugadores..."<<endl;
				r.escribeJugadores();
				cout<<"Jugadores guardados con exito."<<endl;
				break;

			case 3: //Ver estado de la ruleta
			{
				cout<<"Dinero de la banca: "<<r.getBanca()<<endl;

				list<Jugador> jugadores_;
				list<Jugador>::iterator it; //Iterador

				jugadores_ = r.getJugadores();

				for(it=jugadores_.begin(); it!=jugadores_.end(); ++it){
					cout<<"Dinero del jugador ["<<(*it).getCodigo()<<"]: "<<(*it).getDinero()<<endl;
				}
			}
				break;

			case 4: //Girar la ruleta
				r.giraRuleta();
				cout<<"--------------------"<<endl;
				r.getPremios(); //Obtenemos premios para cada jugador
				cout<<"--------------------"<<endl;

				if(r.getSumBanca()>0)
					cout<<"La banca ha ganado: "<<r.getSumBanca()<<endl;
				else if(r.getSumBanca()<0)
					cout<<"La banca ha perdido: "<<r.getSumBanca()<<endl;
				else
					cout<<"La banca no ha tenido ganancias ni perdidas."<<endl;

				break;

			case 5: //Eliminar un jugador
			{
				string dni;
				cout<<"Introduzca el DNI del jugador que desea eliminar: ";
				getchar();
				getline(cin,dni);

				if(r.deleteJugador(dni)==-1)
					cout<<"Error: la mesa no tiene jugadores actualmente."<<endl;
				else if(r.deleteJugador(dni)==-2)
					cout<<"Error: no hay un jugador con ese DNI en la mesa."<<endl;
				else
					cout<<"Eliminando jugador..."<<endl;

			}
			break;

			case 6: //Añadir un jugador
			{
			string dni;
			getchar();
			cout<<"Introduzca el DNI del nuevo jugador: ";
			getline(cin,dni);
			
			Jugador j(dni,"jugador"+to_string(r.getNJug()+1)); //Creamos jugador

			string res;
			cout<<"Con el DNI es suficiente para jugar. ¿Desea agregar mas datos del jugador?  (Y/N)"<<endl;
			getline(cin,res);
			
			if(res=="Y" || res=="y"){
				string nom,apell,dir,loc,pro,pai;
				int edad;

				getchar();
				cout<<"Introduzca su nombre: ";
				getline(cin,nom);
		
				getchar();
				cout<<"Introduzca sus apellidos: ";
				getline(cin,apell);
				
				cout<<"Introduzca su edad: ";
				cin>>edad;

				getchar();
				cout<<"Introduzca su direccion: ";
				getline(cin,dir);
				
				getchar();
				cout<<"Introduzca su localidad: ";
				getline(cin,loc);
				
				getchar();
				cout<<"Introduzca su provincia: ";
				getline(cin,pro);
				
				getchar();
				cout<<"Introduzca su pais: ";
				getline(cin,pai);
				

				j.setNombre(nom);
				j.setApellidos(apell);
				j.setEdad(edad);
				j.setDireccion(dir);
				j.setLocalidad(loc);
				j.setProvincia(pro);
				j.setPais(pai);

				
			}

				if(r.addJugador(j)==true)
					cout<<"Jugador añadido con exito."<<endl;
				else
					cout<<"Error: ya existia un jugador con ese DNI."<<endl;

			}
			break;

		}
	} while(opc!=0);

	return 0;
}