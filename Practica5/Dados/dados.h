//dados.h
//dados.cc's prototype

#ifndef DADOS_H
#define DADOS_H
#include <iostream>
using namespace std;

class Dados{

private:
	int d1_;
	int d2_;
	int l1; //Contabiliza el numero de lanzamientos
	int l2;
	int sum1; //Suma de todos los lanzamientos de los dados
	int sum2;
	int v1_[5]; //Vectores para almacenar los 5 ultimos lanzamientos
	int v2_[5];

public:
	Dados(); //Constructor
	void lanzamiento();
	inline int getDado1() const { return d1_; }
	inline int getDado2() const { return d2_; }
	bool setDado1(int val);
	bool setDado2(int val);
	inline int getSuma() const { return (d1_ + d2_); }
	int getDiferencia();
	inline int getLanzamientos1() const { return l1; };
	inline int getLanzamientos2() const { return l2; };
	float getMedia1();
	float getMedia2();
	void getUltimos1(int v1[5]);
	void getUltimos2(int v2[5]);

	friend ostream &operator <<(ostream &stream, Dados &d);
	friend istream &operator >>(istream &stream, Dados &d);

};

#endif
