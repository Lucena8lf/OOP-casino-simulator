//guess.cc
//A program that generates a number between 1 and 10, then you have to guess it

#include <iostream>
#include <cstdlib>
#include <ctime>

int main(){

	int numb, adv;

	std::cout<<"Introduzca un numero en el rango [1-10]: ";
	std::cin>>adv;

	srand(time(NULL)); //Generamos la semilla
	numb = 1+(rand()%10);


	while(adv!=numb){
		if(adv>numb){
			std::cout<<"El numero introducido es mayor que el numero a adivinar.\n \nPor favor, intentelo de nuevo: ";
			std::cin>>adv;
		} else{
			std::cout<<"El numero introducido es menor que el numero a adivinar. \n \nPor favor, intentelo de nuevo: ";
			std::cin>>adv;
		}
}

	std::cout<<"Correcto!!"<<"\n";
	return 0;
}