#include <iostream>
#include <string>
#include "Torneo.h"


using std::cout;
using std::cin;
using std::endl;


void menu() {

cout << endl;
cout << endl <<"================= Menu del Torneo de eSports ================= " << endl <<endl;
cout << "1. Mostrar jugadores disponibles. " << endl;
cout << "2. Mostrar Juegos disponibles. " << endl;
cout << "3. Mostrar los videojuegos de un jugador. " << endl;
cout << "4. Asociar un jugador a un VideoJuego. " << endl;
cout << "5. Registrar un nuevo jugador. " << endl;
cout << "6. Registrar un videojuego nuevo. "<< endl;
cout << "7. Ver Ranking de jugadores (ordenado de mayor a menor). " << endl;
cout << "8. Actualizar el Nivel del Ranking de un jugador. " << endl;
cout << "9. Mostrar una lista de todos los jugadores y sus juegos inscritos. " << endl;
cout << "-1. Salir. " << endl;
cout << "================= ==================== ======================== " << endl;
cout << "Elija la opcion que desea escoger: ";



}




void menuSwitch(Torneo &torneoMenu) {
int opcion;



    do {
        menu();
        cin >> opcion;

        switch (opcion) {

            case -1: {
                cout << "Saliendo..... " << endl;
                break;
            }

            case 1:{
                torneoMenu.mostrarJugadoresInscritos();
                break;

            }

            case 2: {
                torneoMenu.mostrarVideojuegosInscritos();
                break;
            }


            case 3: {
                torneoMenu.mostrarVideojuegosDeJugador();
                break;
            }

            case 4: {
                torneoMenu.inscribirJugadorEnVideojuego();
                break;
            }

            case 5: {
                torneoMenu.inscribirJugador();
                break;
            }

            case 6: {
                torneoMenu.registrarVideojuego();
                break;
            }

            case 7: {
                torneoMenu.mostrarRankingJugadores();
                break;
            }

            case 8: {
                torneoMenu.actualizarRankingDeJugador();
                break;
            }


            case 9: {
                torneoMenu.mostrarJuegosJugadores();
                break;
            }

            default: {
                cout<< "Ingrese una opcion correcta." << endl ;
                break;
            }
        }
    }
while (opcion != -1);
}


int main() {

    Torneo torneo;

    menuSwitch(torneo);
    cout << endl << "Ha salido del menu del torneo. " << endl;

    return 0;
}

