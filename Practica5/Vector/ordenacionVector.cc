//OrdenacionVector.cc
//A program thats sorts a vector ascending and descending

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool orderDesc(const int &n1, const int &n2){return n1 > n2;}

int main(){

	int nEle, opc, ele;
	//vector<int>::size_type it;
	cout<<"Introduzca el numero de elementos que tendra su vector: ";
	cin>>nEle;

	vector <int> v(nEle);

	for(int i=0; i<nEle; i++){
		cout<<"v["<<i<<"]= ";
		cin>>ele;
		v[i]=ele;
		
	}


	cout<<"¿Como desea ordenar el vector?\n";
	cout<<"\t1.De forma ascendente\n";
	cout<<"\t2.De forma descendente\n";
	cin>>opc;

	switch(opc){
		case 1:
			sort(v.begin(),v.end());
			break;
		case 2:
			sort(v.begin(),v.end(),orderDesc);
			break;
	}

	cout<<"Vector ordenado:\n";
	/*for(it=0; it!=v.size(); ++it)
		cout<<v[it]<<" ";
	*/

	for(int i : v)
		cout<<i<<" ";

	cout<<endl;
}