//
// Created by felip on 29/10/2025.
//

#ifndef INC_8_PRACTICA_MAPA_VECTOR_FELIPE08121_TORNEO_H
#define INC_8_PRACTICA_MAPA_VECTOR_FELIPE08121_TORNEO_H

#include "Jugador.h"
#include "Videojuego.h"
#include <unordered_map>

using std::unordered_map;
using std::pair;

class Torneo {
private:
        unordered_map<string, Jugador * > jugadoresRegistrados;
        unordered_map<string, Videojuego * > videojuegosDisponibles;



public:
//Constructores, destructores e inicializadores:
      Torneo();
      void inicializarJugadores();
      void inicializarVideojuegos();
      virtual ~Torneo();
//Metodos:
    void inscribirJugadorEnVideojuego();
    void mostrarVideojuegosDeJugador();

    void inscribirJugador();
    void registrarVideojuego();

    void mostrarJugadoresInscritos();
    void mostrarVideojuegosInscritos();

//Extras:

    void mostrarRankingJugadores();
    void actualizarRankingDeJugador();
    void mostrarJuegosJugadores();

};




#endif //INC_8_PRACTICA_MAPA_VECTOR_FELIPE08121_TORNEO_H