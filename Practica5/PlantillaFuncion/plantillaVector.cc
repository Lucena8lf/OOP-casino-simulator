//plantillaVector.cc
//A program thats uses a function template

#include <iostream>
using namespace std;

template <class T>

void print_vector(T *v, const int n);

int main(){

	int i[5] = {0,2,4,6,8};
	float f[5] = {1.4,3.412,5.9,7.1,9.21};
	char c[9] = "Fernando";

	cout<<"Vector de int: "<<endl;
	print_vector(i,5);
	cout<<endl;
	cout<<"Vector de float: "<<endl;
	print_vector(f,5);
	cout<<endl;
	cout<<"Vector de char: "<<endl;
	print_vector(c,5);
	cout<<endl;

	return 0;
}

template <class T>
void print_vector(T *v, const int n){
	for(int i=0; i<n; i++){
		cout<<"v["<<i<<"]= "<<v[i]<<" ";
	}
}