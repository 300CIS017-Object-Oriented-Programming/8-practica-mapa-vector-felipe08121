//
// Created by felip on 29/10/2025.
//

#include "Torneo.h"


//Constructores, inicializadores y destructores:

Torneo::~Torneo() {

    for (auto it = jugadoresRegistrados.begin(); it != jugadoresRegistrados.end(); ++it) {
        delete it->second;
    }
    jugadoresRegistrados.clear();

    for (auto it = videojuegosDisponibles.begin(); it != videojuegosDisponibles.end(); ++it) {
        delete it->second;
    }
    videojuegosDisponibles.clear();

    cout << "Torneo destruido. Memoria liberada." << endl;


}





void Torneo::inicializarJugadores() {

    Jugador * jugadorInicial1 = new Jugador("felipe08121", 100);
    Jugador * jugadorInicial2 = new Jugador( "Oruga0107", 90);
    Jugador * jugadorInicial3 = new Jugador( "Chango0305", 85);

    this->jugadoresRegistrados["felipe08121"] = jugadorInicial1;
    this->jugadoresRegistrados["Oruga0107"] = jugadorInicial2;
    this->jugadoresRegistrados["Chango0305"] = jugadorInicial3;

}

void Torneo::inicializarVideojuegos() {

     Videojuego * videojuegoInicial1 = new Videojuego( "Genshin001", "Genshin Impact",
         "RPG", 2);
     Videojuego * videojuegoInicial2 = new Videojuego( "ZZZ08", "Zenless Zone Zero"
        , "Accion", 3);
     Videojuego * videojuegoInicial3 = new Videojuego ("Halo1", "Halo: Combat Evolve",
        "FPS", 3);

    this-> videojuegosDisponibles["Genshin001"] = videojuegoInicial1;
    this-> videojuegosDisponibles["ZZZ08"] = videojuegoInicial2;
    this-> videojuegosDisponibles["Halo1"] = videojuegoInicial3;
}

Torneo::Torneo() {
    cout << "=====================================================" << endl;
    cout << "============ Inicializando datos ====================" << endl;
    inicializarJugadores();
    inicializarVideojuegos();
    cout << "=========== Inicializacion finalizada ===============" << endl;
    cout << "=====================================================" << endl;
}

// Metodos:


void Torneo:: mostrarJugadoresInscritos() {

    cout << "================== Informacion de Jugadores inscritos ===================" << endl;

     for ( auto it = jugadoresRegistrados.begin(); it != jugadoresRegistrados.end(); ++it) {
         Jugador * jugadorTemporal = it->second;
         cout<< "Nombre: " << jugadorTemporal->getNickname() << endl;
     }

    cout << "================== =================================== ===================" << endl;
    cout << endl;

}

void Torneo::mostrarVideojuegosInscritos() {

    cout << "=================== Informacion de videojuegos inscritos ================" << endl;

    for ( auto it = videojuegosDisponibles.begin(); it != videojuegosDisponibles.end(); ++it) {

        it->second->mostrar();
    }
    cout << "================== =================================== ===================" << endl;
    cout << endl;

}


void Torneo::inscribirJugadorEnVideojuego() {
    //Inscribir jugador en un videojuego:
    string nickname;
    string codigoJuego;

    mostrarJugadoresInscritos();

    cout << "Ingrese el nickname del jugador: ";
    cin.ignore();
    getline(cin, nickname);

    if ( jugadoresRegistrados.find(nickname) == jugadoresRegistrados.end()) {
        cout << endl <<"Error: El jugador no esta registrado." << endl;
        return;
    }

    cout<< endl;
    mostrarVideojuegosInscritos();
    cout<< endl << "Ingrese el codigo del videojuego: ";
    getline( cin, codigoJuego);

    if (videojuegosDisponibles.find(codigoJuego)==videojuegosDisponibles.end()) {
        cout << endl << "Error: El videojuego no esta disponible." << endl;
        return;
    }

    Jugador * jugador = jugadoresRegistrados[nickname];
    Videojuego * videojuego = videojuegosDisponibles[ codigoJuego];

    if (jugador->isEstaIncsritoEn(videojuego)) {
        cout << endl << "Error: El jugador ya esta incrito en este videojuego." << endl;
        return;
    }

    jugador->agregarVideojuego(videojuego);
    cout << endl << "El juego se ha asociado con exito." << endl;


}

void Torneo::mostrarVideojuegosDeJugador() {

    string nickname;
    cout << endl << "====================================================" << endl;
    mostrarJugadoresInscritos();
    cout << "Ingrese el nickname del jugador: ";
    cin.ignore();
    getline(cin, nickname);


    auto it = jugadoresRegistrados.find(nickname);

    if (it == jugadoresRegistrados.end()) {
        cout<< endl << "Error: El jugador no esta registrado. " << endl;
        return;
    }

    jugadoresRegistrados[nickname]->mostrar();

}

