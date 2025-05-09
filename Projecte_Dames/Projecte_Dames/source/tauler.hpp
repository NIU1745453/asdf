#ifndef TAULER_H
#define TAULER_H


#include "posicio.hpp"
#include "Fitxa.h"
#include <fstream>

using namespace std;

class Tauler
{
public:
	Tauler() : m_nPosicions(0) {};
	void setNPosicions(int nPos) { m_nPosicions = nPos; }
	int getNPosicions() { return m_nPosicions; }
	void inicialitza(const string& nomFitxer); //inicialitzaem el fitxer segons un document de text

	void actualitzaMovimentsValids();//actualiza los movimientos validos de las fitxas del tablero

	void getPosicionsPossibles(const Posicio& origen, int& nPosicions, Posicio posicionsPossibles[]);//creo que la funcion del tipo fitxa es igual a esta
	/* El m�tode retorna a l�array posicionsPossibles totes les posicions on es podria moure la pe�a
que ocupa la posici� origen, tenint en compte tots els passos de qualsevol moviment v�lid de la
pe�a. nPosicions indica el n� total de posicions possibles.
Posicions possibles de la posici� �b2�:[�a3�,�d4�,�f6�,�d8�,�h8�]*/

	bool posicioExistent(const Posicio& origen, int& nPosicions, Posicio posicionsPossibles[]);
	/*comprova que la posicio que s'ha pasat existeix dins de l'array de posicionsPossibles*/

	//Moviment camiViable(Posicio& posActual);

	bool mouFitxa(const Posicio& origen, const Posicio& desti);
	/*
	Mou la pe�a que ocupa la posici� del par�metre origen a la posici� del par�metre desti.
		Ha de comprovar que la posici� dest� estigui dins dels moviments v�lids de la pe�a.
		Si no ho est� no fa el moviment i retorna false.
	A part de moure la pe�a de la posici� origen a la posici� dest� ha de fer el seg�ent:
		Eliminar del tauler totes les peces que es matin fent el moviment.
		Si la pe�a arriba al final del tauler, convertir-la en una dama.
		Si el moviment no ha matat una pe�a contr�ria quan hi ha altres moviments que s� permeten
		fer-ho o el moviment no ha matat el m�xim de peces contr�ries possibles, bufar una pe�a del
		jugador (eliminar la pe�a del tauler) , seguint els criteris que s�han explicat a les regles del joc.
	*/
	//void eliminaFitxa(const Posicio& origen);
	//elimina la fitxa del tauler

	//void toDama(const Posicio& origen);
	//Comprova que la posicio introduida sigui la correcta per a convertir una fitxa en Dama



	string toString() const;
	/*Genera un string amb l�estat actual del tauler de joc en el format que especifiquem a continuaci�
	8: _ X _ D _ _ _ X
	7: _ _ _ _ _ _ X _
	6: _ _ _ _ _ _ _ _
	5: R _ _ _ _ _ _ _
	4: _ _ _ _ _ _ _ O
	3: _ _ O _ _ _ O _
	2: _ O _ _ _ _ _ X
	1: O _ O _ D _ _ _
	   A B C D E F G H
	creo q ya se como se hace
	*/

private:
	Fitxa m_tauler[N_FILES][N_COLUMNES];
	int m_nPosicions;
	Posicio m_posicionsPossibles[10];
};

//void escriuTauler(const string& nomFitxer, char tauler[N_FILES][N_COLUMNES]);


#endif 