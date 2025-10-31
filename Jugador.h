//
// Created by felip on 29/10/2025.
//

#ifndef INC_8_PRACTICA_MAPA_VECTOR_FELIPE08121_JUGADOR_H
#define INC_8_PRACTICA_MAPA_VECTOR_FELIPE08121_JUGADOR_H

#include "Videojuego.h"
#include <vector>
#include <algorithm>

using std::vector;

class Jugador {
private:
     string nickname;
     int nivelRanking;
     vector <Videojuego * > videojuegosInscritos;
public:

     //Constructores y destructores:
     Jugador();
     Jugador( string nickname, int nivelRanking );
     virtual ~Jugador();

     // gets y sets:

     string getNickname();
     void setNickname( string nickname);

     int getNivelRanking();
     void setNivelRanking( int nivelRanking );

     //Metodos:

     void mostrar();

     //Metodos añadidos:

     void agregarVideojuego(Videojuego * videojuego);
     bool isEstaIncsritoEn(Videojuego * videojuego);


};


#endif //INC_8_PRACTICA_MAPA_VECTOR_FELIPE08121_JUGADOR_H