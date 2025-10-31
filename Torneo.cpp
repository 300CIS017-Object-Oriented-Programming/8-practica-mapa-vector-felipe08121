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

    cout << endl <<"Iniciando inicializacion...................." << endl;
    cout << "[0/2] Inicializacion de Jugadores y videojuegos iniciada." << endl;
    inicializarJugadores();
    cout << "[1/2] Inicializacion de jugadores terminada." << endl;
    inicializarVideojuegos();
    cout << "[2/2] Inicializacion de juegos terminada." << endl;

    cout << endl <<"Iniciando asociacion...................." << endl;
    cout << "[0/6] Asociacion de jugadores a videojuegos iniciada." << endl;
    Jugador * jugador1 = jugadoresRegistrados["felipe08121"];
    Jugador * jugador2 = jugadoresRegistrados["Chango0305"];
    Jugador * jugador3 = jugadoresRegistrados["Oruga0107"];

    Videojuego * videojuego1 = videojuegosDisponibles["Genshin001"];
    Videojuego * videojuego2 = videojuegosDisponibles["ZZZ08"];
    Videojuego * videojuego3 = videojuegosDisponibles["Halo1"];

    //felipe08121:
      jugador1->agregarVideojuego(videojuego1);
      cout << "[1/6] El juego se ha asociado con exito." << endl;
      jugador1->agregarVideojuego(videojuego2);
      cout << "[2/6] El juego se ha asociado con exito." << endl;
      jugador1->agregarVideojuego(videojuego3);
      cout << "[3/6] El juego se ha asociado con exito." << endl;
    //Chango0305:
      jugador2->agregarVideojuego(videojuego3);
      cout << "[4/6] El juego se ha asociado con exito." << endl;

    //Oruga0107:
      jugador3->agregarVideojuego(videojuego1);
      cout << "[5/6] El juego se ha asociado con exito." << endl;
      jugador3->agregarVideojuego(videojuego3);
      cout << "[6/6] El juego se ha asociado con exito." << endl;

    cout << endl <<"=========== Inicializacion finalizada ===============" << endl;
    cout << "=====================================================" << endl;
}

// Metodos:


void Torneo:: mostrarJugadoresInscritos() {

    cout << "================== Informacion de Jugadores inscritos ===================" << endl;

     for ( auto it = jugadoresRegistrados.begin(); it != jugadoresRegistrados.end(); ++it) {
         Jugador * jugadorTemporal = it->second;
         cout<< "Nickname: " << jugadorTemporal->getNickname() << "   ---  Nivel de habilidad: "<< jugadorTemporal->getNivelRanking() <<endl;
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

void Torneo::inscribirJugador() {
    string nickname;
    int nivelRanking;

    cout << "Ingrese el nickname: ";
    cin.ignore();
    getline(cin,nickname);

    if (jugadoresRegistrados.find(nickname) != jugadoresRegistrados.end()) {

        cout << endl << "Error: El jugador ya esta registrado. " << endl;
        return;
    }


    cout << endl << "Ingrese su nivel de habilidad: ";
    cin >> nivelRanking;


    if( nivelRanking < 1 || nivelRanking >100) {
        cout << endl << "Error: Nivel de habilidad invalido, por favor intente otra vez. " << endl;
        return;
    }

    Jugador * nuevoJugador = new Jugador(nickname, nivelRanking );
    jugadoresRegistrados[nickname] = nuevoJugador;

    cout << endl << "----> Jugador creado Exitosamente. " << endl;

}


void Torneo:: registrarVideojuego() {
    string codigo;
    string nombre;
    string genero;
    int nivelDificultad;

    cout << "Ingrese el nombre del videojuego: ";
    cin.ignore();
    getline(cin, nombre);

    cout << endl <<"Ingrese el codigo del videojuego: ";
    getline(cin, codigo);

    if ( videojuegosDisponibles.find(codigo) != videojuegosDisponibles.end()) {
        cout << endl << "Error: Ya hay un videojuego registrado con este codigo, intente otra vez." <<endl;
        return;
    }

    cout << endl <<"Ingrese el genero del videojuego: " ;
    getline(cin, genero);

    cout << endl <<"Ingrese el nivel de dificultada del videojuego: " ;
    cin >> nivelDificultad;

    if (nivelDificultad < 1 || nivelDificultad >5) {
        cout << endl << "Error: Nivel de dificultad invalido, intente otra vez. " << endl;
    }

    Videojuego * videojuegoNuevo = new Videojuego(codigo, nombre, genero, nivelDificultad);
    videojuegosDisponibles[codigo] = videojuegoNuevo;

    cout << endl << "----> Videojuego creado exitosamente. " << endl;
}


void Torneo::mostrarRankingJugadores() {

     if (jugadoresRegistrados.empty()) {
         cout << endl << "No hay jugadores registrados actualmente. " << endl;
         return;
     }

    //Vector temporal:
    vector < Jugador * > ranking;

    for ( auto it = jugadoresRegistrados.begin(); it !=  jugadoresRegistrados.end(); ++it) {
        ranking.push_back(it->second);
    }

    sort(ranking.begin(), ranking.end(), [](Jugador* a, Jugador * b) {
        return a->getNivelRanking() > b->getNivelRanking();
    });

    cout << endl << "======================= Ranking de Juegadores  =======================" << endl;
    cout << "Posicion\tNickname\t\tNivel de Ranking " << endl;
    cout << "======================= =======================  =====================" << endl;

    for (int i = 0; i < ranking.size(); i++) {
        cout << (i+1) << ".\t\t"
        << ranking[i]->getNickname()<< "\t\t\t"
        << ranking[i]->getNivelRanking()<< endl;
    }

    cout << "======================= =======================  =====================" << endl;


}


void Torneo::actualizarRankingDeJugador(){
    string nickname;
    int nuevoNivel;

    mostrarJugadoresInscritos();

    cout << "Ingrese el Nickname del jugador: " ;
    cin.ignore();
    getline(cin, nickname);

    if (jugadoresRegistrados.find(nickname) == jugadoresRegistrados.end()) {
        cout << endl << "Error: El Nickname del jugador no existe, intente otra vez. " << endl;
        return;
    }

    cout << "Ingrese el nuevo nivel del Ranking: ";
    cin >> nuevoNivel;

    if (nuevoNivel < 1 || nuevoNivel > 100 ) {
        cout << endl << "Error: Nuevo nivel invalido, por favor intente otra vez. " << endl;
        return;
    }

    jugadoresRegistrados[nickname]->setNivelRanking( nuevoNivel );
    cout << "Nickname del jugador: " << jugadoresRegistrados[nickname]->getNickname( ) << " Nuevo nivel en el Ranking --------> "
    << jugadoresRegistrados[nickname]->getNivelRanking( );


}

void Torneo:: mostrarJuegosJugadores() {

    for (auto it  = jugadoresRegistrados.begin();  it != jugadoresRegistrados.end(); ++it) {

        cout << endl << "============== Jugador y sus videojuegos Inscritos =============" << endl;
        cout << "======================= =======================  =====================" << endl;
        it -> second -> mostrar();
    }
        cout << "======================= =======================  =====================" << endl;
}

