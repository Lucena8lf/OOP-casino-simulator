//juego.cc
//Main program's game

#include "dados.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
using namespace std;

int main(){

	Dados d; //Declaramos el objeto

	int opc;

	do{

		cout<<"Escoja una opcion:"<<endl;
		cout<<"\t1.Lanzar los dados"<<endl;
		cout<<"\t2.Ver valor del Dado 1"<<endl;
		cout<<"\t3.Ver valor del Dado 2"<<endl;
		cout<<"\t4.Setear un dado"<<endl;
		cout<<"\t5.Sumar los dos dados"<<endl;
		cout<<"\t6.Obtener diferencia de los dados"<<endl;
		cout<<"\t7.Obtener el numero de lanzamientos de los dados"<<endl;
		cout<<"\t8.Obtener la media de cada dado"<<endl;
		cout<<"\t9.Ver los 5 ultimos valores de cada dado"<<endl;
		cout<<"\t0.Salir"<<endl;

		cin>>opc;

		switch(opc){

			case 1:
					d.lanzamiento();
					cout<<"Dados lanzados con exito."<<endl;
					cout<<"\n";

					break;

			case 2:
					cout<<"Dado 1: "<<d.getDado1()<<endl;
					cout<<"\n";
					break;

			case 3:
					cout<<"Dado 2: "<<d.getDado2()<<endl;
					cout<<"\n";
					break;

			case 4:
					int opcSet;

					cout<<"\tElija el dado que quiere setear"<<endl;
					cout<<"\t\t1.Setear Dado 1"<<endl;
					cout<<"\t\t2.Setear Dado 2"<<endl;

					cout<<"\t"; 
					cin>>opcSet;

					switch(opcSet){

						case 1:
								int val1;

								cout<<"\t\tIntroduzca el valor para el Dado 1: ";
								cin>>val1;

								if(d.setDado1(val1) == true){
									cout<<"\t\tDado 1 seteado con exito."<<endl;
									cout<<"\n";
								} else{
									cout<<"\t\tError: el valor asignado dado no es correcto.\n"<<endl;
									cout<<"\n";
								}

								break;

						case 2:
								int val2;

								cout<<"\t\tIntroduzca el valor para el Dado 2: ";
								cin>>val2;

								if(d.setDado2(val2) == true){
									cout<<"\t\tDado 2 seteado con exito."<<endl;
									cout<<"\n";
								} else{
									cout<<"\t\tError: el valor del dado no es correcto.\n"<<endl;
									cout<<"\n";
								}
						
								break;

					}

					break;


			case 5:
					cout<<"Suma: "<<d.getSuma()<<endl;
					cout<<"\n";

					break;

			case 6:
					cout<<"Diferencia: "<<d.getDiferencia()<<endl;
					cout<<"\n";

					break;

			case 7:
					cout<<"Lanzamientos del Dado 1: "<<d.getLanzamientos1()<<endl;
					cout<<"Lanzamientos del Dado 2: "<<d.getLanzamientos2()<<endl;
					cout<<"\n";

					break;

			case 8:
					cout<<"Media del Dado 1: "<<d.getMedia1()<<endl;
					cout<<"Media del Dado 2: "<<d.getMedia2()<<endl;
					cout<<"\n";

					break;

			case 9:
					int v1[5],v2[5];

					cout<<"Ultimos 5 lanzamientos del Dado 1: "<<endl;
					d.getUltimos1(v1);

					cout<<"Ultimos 5 lanzamientos del Dado 2: "<<endl;
					d.getUltimos2(v2);

					break;

			//default:
				//cout<<"Por favor, introduzca una opcion valida."<<endl;
		}

	}while(opc!=0);


	return 0;
}
