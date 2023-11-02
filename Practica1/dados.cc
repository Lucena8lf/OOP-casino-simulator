//dados.cc
//Functions used in problem of "Dados"

#include "dados.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
using namespace std;

Dados::Dados(){ //Constructor

	srand(time(NULL)); //Generamos semilla

	d1_ = d2_ = 1;
	sum1=0;
	sum2=0;
	l1=0;
	l2=0;

} 

void Dados::lanzamiento(){

	 d1_ = (rand()%6)+1;
	 
	 d2_ = (rand()%6)+1;

	 l1++; //Se lanzan ambos dados
	 l2++;

	 sum1+=d1_;
	 sum2+=d2_;

	 for(int i=0; i<4; i++){
	 	v1_[4-i] = v1_[3-i];
	 }
	 v1_[0] = d1_;

	 for(int i=0; i<4; i++){
	 	v2_[4-i] = v2_[3-i];
	 }
	 v2_[0] = d2_;
}

bool Dados::setDado1(int val1){

	if((val1>=1) && (val1<=6)){
		d1_ = val1;
		l1++;
		sum1+=d1_;
		for(int i=0; i<4; i++){
	 	v1_[4-i] = v1_[3-i];
		 }
		 v1_[0] = d1_;
		return true;
	} else{
		return false;
	}
}

bool Dados::setDado2(int val2){

	if((val2>=1) && (val2<=6)){
		d2_ = val2;
		l2++;
		sum2+=d2_;
		for(int i=0; i<4; i++){
	 	v2_[4-i] = v2_[3-i];
	 	}
	 	v2_ [0] = d2_;
		return true;
	} else{
		return false;
	}
}

int Dados::getDiferencia(){

	//Devolveremos la diferencia en valor absoluto
	if(d1_ > d2_)
		return (d1_ - d2_);
	else
		return (d2_ - d1_);

}

float Dados::getMedia1(){
	if(l1>0){
	return (float)sum1/(float)l1;
	} else{
	return 0;
	}
}

float Dados::getMedia2(){
	if(l2>0){
	return (float)sum2/(float)l2;
	} else{
	return 0;
	}
}

void Dados::getUltimos1(int v1[5]){

	for(int i=0; i<5; i++){
		v1[i]=v1_[i];
		cout<<"v1["<<i<<"]= "<<v1[i]<<endl;
	}
}

void Dados::getUltimos2(int v2[5]){

	for(int i=0; i<5; i++){
		v2[i]=v2_[i];
		cout<<"v2["<<i<<"]= "<<v2[i]<<endl;
	}
}