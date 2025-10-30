#include <iostream>
#include <string>
#include "Torneo.h"


using std::cout;
using std::cin;
using std::endl;


void menu() {

cout << endl;
cout << "1. Mostrar jugadores disponibles. " << endl;
cout << "2. Mostrar Juegos disponibles. " << endl;
cout << "3. Mostrar los videojuegos de un jugador. " << endl;
cout << "4. Asociar un jugador a un VideoJuego. " << endl;
cout << "-1. Salir. " << endl;
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



            default: {
                cout<< "Ingrese una opcion correcta." << endl ;
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

