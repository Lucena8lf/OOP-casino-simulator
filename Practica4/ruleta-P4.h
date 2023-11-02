//ruleta.h
//Defining Rulet Class

#ifndef RULETA_H
#define RULETA_H
#include "jugador.h"
#include "crupier.h"


class Ruleta{
	private:
		int banca_;
		int bola_; //Numero en el rango [0-36]
		list<Jugador> jugadores_;
		Crupier crupier_; //Datos del crupier encargado de la ruleta
		
		int nJug_; //Numero de jugadores en la mesa
		int sumDin_;
		int nBola_;
		int sumBanca_;		

	public:
		Ruleta(Crupier c);
		inline int getBanca() const {return banca_;}
		inline int getBola() const {return bola_;}
		bool setBanca(int banca);
		bool setBola(int bola);
		inline Crupier getCrupier() const {return crupier_;}
		inline void setCrupier(Crupier crupier){crupier_=crupier;}
		inline list<Jugador> getJugadores() const {return jugadores_;}
		bool addJugador(Jugador j);
		int deleteJugador(string dni);
		int deleteJugador(Jugador j);
		void escribeJugadores();
		void leeJugadores();
		void giraRuleta();
		void getPremios();
		bool es_Rojo(int num);

		inline int getSumBanca() const {return sumBanca_;}
		inline int getNJug() const {return nJug_;}
		void getEstadoRuleta(int &nJug,int &sumDin,int &nBola,int &sumBanca);

};

#endif
