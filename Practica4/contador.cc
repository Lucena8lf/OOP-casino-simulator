//contador.cc
//Developing Contador's Methods

#include "contador.h"

void Contador::controlaRango(){
	if(valor_>max_)
		valor_ = max_;
	else if(valor_<min_)
		valor_ = min_;

	cambios_.push_back(valor_);

}

Contador::Contador(int valor,int min,int max){
	if((valor < min) || (valor > max) || (min > max)){
		valor = 0;
		min = 0;
		max = 1000;
	}

	valor_ = valor;
	min_ = min;
	max_ = max;
	cambios_.push_back(valor_); //Añadimos el nuevo valor a la lista
}

Contador Contador::operator=(const int &v){
	valor_ = v;
	controlaRango(); //Controlamos el valor asignado
	return *this;
}

Contador Contador::operator=(const Contador &c){
	valor_ = c.valor_;
	min_ = c.min_;
	max_ = c.max_;
	cambios_.push_back(valor_);

	return *this;
}

Contador Contador::operator++(void){ //Pre -> ++x
	valor_++;
	controlaRango();
	return *this;
}

Contador Contador::operator++(int){ //Pos -> x++
	//Hacemos copia del objeto
	Contador temp = *this;
	valor_++;
	controlaRango();
	return temp;
}

Contador Contador::operator--(void){ //Pre -> --x
	valor_--;
	controlaRango();
	return *this;
}

Contador Contador::operator--(int){ //Pos -> x--
	//Hacemos copia del objeto
	Contador temp = *this;
	valor_--;
	controlaRango();
	return temp;
}

Contador Contador::operator+(const int &v){
	valor_ += v;
	controlaRango();
	return *this;
	/*
	if(temp.valor_ > max_){
		temp.valor_ = max_;
		return temp;
	} else
		return temp;
	*/

	 /*Aquí tomamos de partida que la que llama al operador es un objeto
	   de tipo Contador, por ello ponemos "valor_", el cual se refiere al valor
	   del objeto el cual llama al operador. 
	   Ej: c + 10 
	   */
}

Contador operator+(int v, Contador c){
	Contador temp = c;
	temp.valor_ = (v + c.valor_);
	temp.controlaRango();
	return temp;
}

Contador Contador::operator-(const int &v){
	valor_ -= v;
	controlaRango();
	return *this;
}

Contador operator-(int v, Contador c){
	Contador temp = c;
	temp.valor_ = (v - c.valor_);
	temp.controlaRango();
	return temp;
}

bool Contador::undo(int n){

	int nveces=0;
	//Comprobamos si n esta fuera de rango
	if(n>=int(cambios_.size()) || n<1)
		return false;

	std::list<int>::iterator it;

	cambios_.reverse(); //Invertimos la lista de cambios

	for(it=cambios_.begin();it!=cambios_.end();++it){
		if(n == nveces)
			valor_ = (*it);
		nveces++;
	}
	return true;
}