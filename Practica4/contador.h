//contador.h
//Defining Contador's Class

#ifndef CONTADOR_H
#define CONTADOR_H
#include <iostream>
#include <list>

class Contador{
	private:
		int valor_;
		int min_; //Valor minimo para valor_
		int max_; //Valor maximo para valor_
		std::list<int> cambios_;

	public:
		Contador(int valor=0,int min=0, int max=1000);
		
		void controlaRango();

		Contador operator=(const int &v);
		Contador operator=(const Contador &c);
		Contador operator++(void); //Pre -> ++x
		Contador operator++(int); //Pos -> x++
		Contador operator--(void); //Pre -> --x
		Contador operator--(int); //Pos -> x--
		Contador operator+(const int &v); //c + 10
		friend Contador operator+(int v,Contador c); //10 + c
		Contador operator-(const int &v); //c - 10
		friend Contador operator-(int v,Contador c); //10 - c
		bool undo(int n=1);
		inline int get() const {return valor_;}
};
#endif