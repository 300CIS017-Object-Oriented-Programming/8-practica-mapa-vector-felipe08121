//
// Created by felip on 29/10/2025.
//

#include "Jugador.h"


//Contructores y destructores:
Jugador::Jugador() {
    this-> nickname = "Sin nickname.";
    this-> nivelRanking = -1; // -1 significa sin nivel de ranking.
    videojuegosInscritos = {};
}

Jugador::Jugador(string nickname, int nivelRanking) {
    this-> nickname = nickname;
    this-> nivelRanking = nivelRanking;
    videojuegosInscritos = {};
}

Jugador::~Jugador(){

    for ( int i = 0; i < videojuegosInscritos.size(); i++) {
        if (videojuegosInscritos[i] != NULL) {
            delete videojuegosInscritos[i];
            videojuegosInscritos[i] = NULL;
        }
    }

    videojuegosInscritos.clear();

}

// gets y sets:

string Jugador::getNickname() {
    return nickname;
}
void Jugador::setNickname( string nickname) {
    this-> nickname = nickname;
}


int Jugador::getNivelRanking() {
    return nivelRanking;
}
void Jugador::setNivelRanking( int nivelRanking ) {
    this->nivelRanking = nivelRanking;
}

// Metodos:

void Jugador::mostrar() {
    int promedio = 0;
    int contador = 0;

    cout << endl << "========= Datos del jugador =========" << endl;
    cout << "Nickname: " << nickname << endl;
    cout << "Nivel del Ranking: " << nivelRanking << endl;

    if (videojuegosInscritos.empty()) {
        cout << endl <<"Este jugador no esta inscrito en ningun videojuego. " << endl;
    }

    else {
        for (int i = 0; i < videojuegosInscritos.size(); i++) {
            if ( videojuegosInscritos[i] != NULL) {
                cout << "--------- Video juego #" << i+1 << " ---------"<< endl;
                videojuegosInscritos[i]->mostrar();
                promedio += videojuegosInscritos[i]->getNivelDificultad();
                contador++;
            }
        }

    }

    cout << "------- >_< Promedio de las dificultades de los videojuegos del jugador: " << promedio/contador
    << " >_< -------"<< endl;

    cout << endl << "========= =============== =========" << endl;
}